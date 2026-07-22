// Copyright (c) MongoDB, Inc.
// SPDX-License-Identifier: SSPL-1.0


#include "mongo/db/update/update_object_node.h"

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/update/field_checker.h"
#include "mongo/db/update/modifier_table.h"
#include "mongo/db/update/update_array_node.h"
#include "mongo/db/update/update_leaf_node.h"
#include "mongo/db/update/update_object_node_knobs_gen.h"
#include "mongo/util/str.h"
#include "mongo/util/string_map.h"

#include <memory>
#include <string_view>

#include <boost/optional.hpp>

namespace mongo {

namespace {

/**
 * A temporary, per-apply() index that resolves the update's target fields under a single object
 * Element in one pass instead of a linear findFirstChildNamed() scan per field.
 *
 * Applying a modifier update resolves each target field via getChild() ->
 * mutablebson::Element::findFirstChildNamed(), which is an O(n) scan of the object's child chain.
 * When many fields under the same wide object are updated in one command, this becomes O(n^2). This
 * cache scans the object's children once and records, for each target field, the corresponding
 * child Element (or that it is absent), turning the per-field lookups into O(1).
 *
 * The index is "target-only": it is seeded from exactly the set of field names this update touches
 * at this level, so its size is bounded by the number of updated fields, not by the document's fan
 * out. The single-pass scan also stops as soon as every target has been located.
 *
 * Notes on correctness:
 *  - Only field names that are update targets are indexed. A lookup for any other field name returns
 *    boost::none so the caller falls back to the normal scan; this makes the cache safe to consult
 *    unconditionally and robust to future call sites.
 *  - The first Element seen for a given field name is recorded, preserving the "first match wins"
 *    semantics of findFirstChildNamed() for (degenerate) documents with duplicate field names.
 *  - A target that does not exist in the document is recorded as a non-ok Element, which is a
 *    definitive "absent" answer (equivalent to what findFirstChildNamed() would return). Because the
 *    scan only stops early once all targets are found, any target that exists is always located.
 *  - Keys are owned std::strings, so the index does not depend on the stability of the document's
 *    field-name storage as fields are created/removed during the update.
 *  - Values are mutablebson::Element (a (Document*, RepIdx) pair). RepIdx values remain valid even
 *    if the underlying element vector reallocates, and in-place value changes do not move elements,
 *    so recorded entries stay valid across sibling updates.
 *  - The cache is bound to the exact object Element it was built from; callers verify identity (see
 *    getChild()) before consulting it.
 */
class ChildLookupCache {
public:
    ChildLookupCache(mutablebson::Element parent, const std::vector<std::string_view>& targetFields)
        : _parent(parent) {
        invariant(parent.ok() && parent.getType() == BSONType::object);

        // Seed the index with every target field, initially marked absent (a non-ok Element).
        const auto absent = parent.getDocument().end();
        _index.reserve(targetFields.size());
        for (auto&& name : targetFields) {
            _index.try_emplace(std::string{name}, absent);
        }

        // Single pass over the object's children, filling in the targets we find. Stop once every
        // distinct target has been located so we do not scan the rest of a wide object needlessly.
        size_t remaining = _index.size();
        for (auto child = parent.leftChild(); child.ok() && remaining > 0;
             child = child.rightSibling()) {
            auto it = _index.find(child.getFieldName());
            if (it != _index.end() && !it->second.ok()) {
                it->second = child;
                --remaining;
            }
        }
    }

    const mutablebson::Element& parent() const {
        return _parent;
    }

    /**
     * If 'field' is one of this update's target fields, returns the resolved child Element (a non-ok
     * Element if the field is absent from the document). Otherwise returns boost::none to indicate
     * the caller should fall back to a normal lookup.
     */
    boost::optional<mutablebson::Element> tryGetChild(std::string_view field) const {
        if (auto it = _index.find(field); it != _index.end()) {
            return it->second;
        }
        return boost::none;
    }

private:
    mutablebson::Element _parent;
    StringMap<mutablebson::Element> _index;
};

/**
 * Gets the child of 'element' named 'field', if it exists. Otherwise returns a non-ok element.
 *
 * When 'childCache' is non-null and was built for exactly 'element', the cached target-field index
 * is used to avoid the O(n) findFirstChildNamed() scan. The cache is only consulted for object
 * elements (array children are addressed by numeric index, not field name) and only for the exact
 * object it was built from; a field that was not indexed as a target falls back to the normal scan.
 * This is safe even if the caller's current element has been advanced elsewhere.
 */
mutablebson::Element getChild(mutablebson::Element element,
                              std::string_view field,
                              const ChildLookupCache* childCache = nullptr) {
    if (element.getType() == BSONType::object) {
        if (childCache && element == childCache->parent()) {
            if (auto cached = childCache->tryGetChild(field)) {
                return *cached;
            }
        }
        return element[field];
    } else if (element.getType() == BSONType::array) {
        auto indexFromField = str::parseUnsignedBase10Integer(field);
        if (indexFromField) {
            return element.findNthChild(*indexFromField);
        }
    }
    return element.getDocument().end();
}

/**
 * Applies 'child' to the child of 'applyParams->element' named 'field' (which will create it, if it
 * does not exist). If 'applyParams->pathToCreate' is created, then 'applyParams->pathToCreate' is
 * moved to the end of 'applyParams->pathTaken', and 'applyParams->element' is advanced to the end
 * of 'applyParams->pathTaken'. Updates 'applyResult' based on whether 'child' was a noop or
 * affected indexes.
 */
void applyChild(const UpdateNode& child,
                std::string_view field,
                UpdateExecutor::ApplyParams* applyParams,
                UpdateNode::UpdateNodeApplyParams* updateNodeApplyParams,
                UpdateExecutor::ApplyResult* applyResult,
                const ChildLookupCache* childCache = nullptr) {

    auto pathTakenSizeBefore = updateNodeApplyParams->pathTaken->fieldRef().numParts();

    // A non-ok value for childElement will indicate that we need to append 'field' to the
    // 'pathToCreate' FieldRef.
    auto childElement = applyParams->element.getDocument().end();
    invariant(!childElement.ok());
    if (!updateNodeApplyParams->pathToCreate->empty()) {
        // We're already traversing a path with elements that don't exist yet, so we will definitely
        // need to append.
    } else {
        // This is the field-location lookup that dominates wide-document multi-field updates; use
        // the field-name index when available. The subsequent getChild() calls below only run when
        // a child created new path components, so they intentionally bypass the cache (the newly
        // created elements are not indexed).
        childElement = getChild(applyParams->element, field, childCache);
    }

    if (childElement.ok()) {
        // The path we've traversed so far already exists in our document, and 'childElement'
        // represents the Element indicated by the 'field' name or index, which we indicate by
        // updating the 'pathTaken' FieldRef.
        updateNodeApplyParams->pathTaken->append(
            field,
            applyParams->element.getType() == BSONType::array
                ? RuntimeUpdatePath::ComponentType::kArrayIndex
                : RuntimeUpdatePath::ComponentType::kFieldName);
    } else {
        // We are traversing path components that do not exist in our document. Any update modifier
        // that creates new path components (i.e., any modifiers that return true for
        // allowCreation()) will need to create this component, so we append it to the
        // 'pathToCreate' FieldRef. If the component cannot be created, pathsupport::createPathAt()
        // will provide a sensible PathNotViable UserError.
        childElement = applyParams->element;
        updateNodeApplyParams->pathToCreate->appendPart(field);
    }

    auto childApplyParams = *applyParams;
    childApplyParams.element = childElement;
    UpdateNode::UpdateNodeApplyParams childUpdateNodeApplyParams = *updateNodeApplyParams;
    auto childApplyResult = child.apply(childApplyParams, childUpdateNodeApplyParams);

    applyResult->noop = applyResult->noop && childApplyResult.noop;
    applyResult->containsDotsAndDollarsField =
        applyResult->containsDotsAndDollarsField || childApplyResult.containsDotsAndDollarsField;

    // Pop 'field' off of 'pathToCreate' or 'pathTaken'.
    if (!updateNodeApplyParams->pathToCreate->empty()) {
        updateNodeApplyParams->pathToCreate->removeLastPart();
    } else {
        updateNodeApplyParams->pathTaken->popBack();
    }

    // If the child is an internal node, it may have created 'pathToCreate' and moved 'pathToCreate'
    // to the end of 'pathTaken'. We should advance 'element' to the end of 'pathTaken'.
    if (updateNodeApplyParams->pathTaken->size() > pathTakenSizeBefore) {
        for (size_t i = pathTakenSizeBefore; i < updateNodeApplyParams->pathTaken->size(); ++i) {
            applyParams->element = getChild(
                applyParams->element, updateNodeApplyParams->pathTaken->fieldRef().getPart(i));
            invariant(applyParams->element.ok());
        }
    } else if (!updateNodeApplyParams->pathToCreate->empty()) {

        // If the child is a leaf node, it may have created 'pathToCreate' without moving
        // 'pathToCreate' to the end of 'pathTaken'. We should move 'pathToCreate' to the end of
        // 'pathTaken' and advance 'element' to the end of 'pathTaken'.
        childElement =
            getChild(applyParams->element, updateNodeApplyParams->pathToCreate->getPart(0));
        if (childElement.ok()) {
            applyParams->element = childElement;
            updateNodeApplyParams->pathTaken->append(
                updateNodeApplyParams->pathToCreate->getPart(0),
                applyParams->element.getType() == BSONType::array
                    ? RuntimeUpdatePath::ComponentType::kArrayIndex
                    : RuntimeUpdatePath::ComponentType::kFieldName);

            // Either the path was fully created or not created at all.
            for (size_t i = 1; i < updateNodeApplyParams->pathToCreate->numParts(); ++i) {
                const BSONType parentType = applyParams->element.getType();
                applyParams->element =
                    getChild(applyParams->element, updateNodeApplyParams->pathToCreate->getPart(i));
                invariant(applyParams->element.ok());
                updateNodeApplyParams->pathTaken->append(
                    updateNodeApplyParams->pathToCreate->getPart(i),
                    parentType == BSONType::array ? RuntimeUpdatePath::ComponentType::kArrayIndex
                                                  : RuntimeUpdatePath::ComponentType::kFieldName);
            }

            updateNodeApplyParams->pathToCreate->clear();
        }
    }
}

BSONObj makeBSONForOperator(const std::vector<std::pair<std::string, BSONObj>>& updatesForOp) {
    BSONObjBuilder bob;
    for (const auto& [path, value] : updatesForOp)
        bob << path << value.firstElement();
    return bob.obj();
}

}  // namespace

// static
StatusWith<bool> UpdateObjectNode::parseAndMerge(
    UpdateObjectNode* root,
    modifiertable::ModifierType type,
    BSONElement modExpr,
    const boost::intrusive_ptr<ExpressionContext>& expCtx,
    const std::map<std::string_view, std::unique_ptr<ExpressionWithPlaceholder>>& arrayFilters,
    std::set<std::string>& foundIdentifiers) {
    FieldRef fieldRef;
    if (type != modifiertable::ModifierType::MOD_RENAME) {
        // General case: Create a path in the tree according to the path specified in the field name
        // of the "modExpr" element.
        fieldRef.parse(modExpr.fieldNameStringData());
    } else {
        // Special case: For $rename modifiers, we add two nodes to the tree:
        // 1) a ConflictPlaceholderNode at the path specified in the field name of the "modExpr"
        //    element and
        auto status = parseAndMerge(root,
                                    modifiertable::ModifierType::MOD_CONFLICT_PLACEHOLDER,
                                    modExpr,
                                    expCtx,
                                    arrayFilters,
                                    foundIdentifiers);
        if (!status.isOK()) {
            return status;
        }

        // 2) a RenameNode at the path specified by the value of the "modExpr" element, which must
        //    be a string value.
        if (BSONType::string != modExpr.type()) {
            return Status(ErrorCodes::BadValue,
                          str::stream()
                              << "The 'to' field for $rename must be a string: " << modExpr);
        }

        fieldRef.parse(modExpr.valueStringData());
    }

    // Check that the path is updatable.
    auto status = fieldchecker::isUpdatable(fieldRef);
    if (!status.isOK()) {
        return status;
    }

    // Check that there is at most one positional ($) part of the path and it is not in the first
    // position.
    size_t positionalIndex;
    size_t positionalCount;
    bool positional = fieldchecker::isPositional(fieldRef, &positionalIndex, &positionalCount);

    if (positional && positionalCount > 1) {
        return Status(ErrorCodes::BadValue,
                      str::stream() << "Too many positional (i.e. '$') elements found in path '"
                                    << fieldRef.dottedField() << "'");
    }

    if (positional && positionalIndex == 0) {
        return Status(
            ErrorCodes::BadValue,
            str::stream()
                << "Cannot have positional (i.e. '$') element in the first position in path '"
                << fieldRef.dottedField() << "'");
    }

    // Construct and initialize the leaf node.
    auto leaf = modifiertable::makeUpdateLeafNode(type);
    invariant(leaf);
    status = leaf->init(modExpr, expCtx);
    if (!status.isOK()) {
        return status;
    }

    // Create UpdateInternalNodes along the path.
    UpdateInternalNode* current = static_cast<UpdateInternalNode*>(root);
    for (FieldIndex i = 0; i < fieldRef.numParts() - 1; ++i) {
        auto fieldIsArrayFilterIdentifier =
            fieldchecker::isArrayFilterIdentifier(fieldRef.getPart(i));

        std::string childName;
        if (fieldIsArrayFilterIdentifier) {
            auto status = parseArrayFilterIdentifier(
                fieldRef.getPart(i), i, fieldRef, arrayFilters, foundIdentifiers);
            if (!status.isOK()) {
                return status.getStatus();
            }
            childName = status.getValue();
        } else {
            childName = std::string{fieldRef.getPart(i)};
        }

        auto child = current->getChild(childName);
        auto childShouldBeArrayNode =
            fieldchecker::isArrayFilterIdentifier(fieldRef.getPart(i + 1));
        if (child) {
            if ((childShouldBeArrayNode && child->type != UpdateNode::Type::Array) ||
                (!childShouldBeArrayNode && child->type != UpdateNode::Type::Object)) {
                return Status(ErrorCodes::ConflictingUpdateOperators,
                              str::stream() << "Updating the path '" << fieldRef.dottedField()
                                            << "' would create a conflict at '"
                                            << fieldRef.dottedSubstring(0, i + 1) << "'");
            }
        } else {
            std::unique_ptr<UpdateInternalNode> ownedChild;
            if (childShouldBeArrayNode) {
                ownedChild = std::make_unique<UpdateArrayNode>(arrayFilters);
            } else {
                ownedChild = std::make_unique<UpdateObjectNode>();
            }
            child = ownedChild.get();
            current->setChild(std::move(childName), std::move(ownedChild));
        }
        current = static_cast<UpdateInternalNode*>(child);
    }

    // Add the leaf node to the end of the path.
    auto fieldIsArrayFilterIdentifier =
        fieldchecker::isArrayFilterIdentifier(fieldRef.getPart(fieldRef.numParts() - 1));

    std::string childName;
    if (fieldIsArrayFilterIdentifier) {
        auto status = parseArrayFilterIdentifier(fieldRef.getPart(fieldRef.numParts() - 1),
                                                 fieldRef.numParts() - 1,
                                                 fieldRef,
                                                 arrayFilters,
                                                 foundIdentifiers);
        if (!status.isOK()) {
            return status.getStatus();
        }
        childName = status.getValue();
    } else {
        childName = std::string{fieldRef.getPart(fieldRef.numParts() - 1)};
    }

    if (current->getChild(childName)) {
        return Status(ErrorCodes::ConflictingUpdateOperators,
                      str::stream()
                          << "Updating the path '" << fieldRef.dottedField()
                          << "' would create a conflict at '" << fieldRef.dottedField() << "'");
    }
    current->setChild(std::move(childName), std::move(leaf));

    return positional;
}

// static
StatusWith<std::string> UpdateObjectNode::parseArrayFilterIdentifier(
    std::string_view field,
    size_t position,
    const FieldRef& fieldRef,
    const std::map<std::string_view, std::unique_ptr<ExpressionWithPlaceholder>>& arrayFilters,
    std::set<std::string>& foundIdentifiers) {
    dassert(fieldchecker::isArrayFilterIdentifier(field));

    if (position == 0) {
        return Status(ErrorCodes::BadValue,
                      str::stream() << "Cannot have array filter identifier (i.e. '$[<id>]') "
                                       "element in the first position in path '"
                                    << fieldRef.dottedField() << "'");
    }

    auto identifier = field.substr(2, field.size() - 3);

    if (!identifier.empty() && arrayFilters.find(identifier) == arrayFilters.end()) {
        return Status(ErrorCodes::BadValue,
                      str::stream() << "No array filter found for identifier '" << identifier
                                    << "' in path '" << fieldRef.dottedField() << "'");
    }

    if (!identifier.empty()) {
        foundIdentifiers.emplace(std::string{identifier});
    }

    return std::string{identifier};
}

// static
std::unique_ptr<UpdateNode> UpdateObjectNode::createUpdateNodeByMerging(
    const UpdateObjectNode& leftNode, const UpdateObjectNode& rightNode, FieldRef* pathTaken) {
    auto mergedNode = std::make_unique<UpdateObjectNode>();

    mergedNode->_children =
        createUpdateNodeMapByMerging(leftNode._children, rightNode._children, pathTaken);

    // The "positional" field ("$" notation) lives outside of the _children map, so we merge it
    // separately.
    mergedNode->_positionalChild = copyOrMergeAsNecessary(
        leftNode._positionalChild.get(), rightNode._positionalChild.get(), pathTaken, "$");

    // In Clang-3.9, we can just return mergedNode directly, but in 3.7, we need a std::move
    return std::move(mergedNode);
}

UpdateNode* UpdateObjectNode::getChild(const std::string& field) const {
    if (fieldchecker::isPositionalElement(field)) {
        return _positionalChild.get();
    }

    auto child = _children.find(field);
    if (child == _children.end()) {
        return nullptr;
    }
    return child->second.get();
}

void UpdateObjectNode::setChild(std::string field, std::unique_ptr<UpdateNode> child) {
    if (fieldchecker::isPositionalElement(field)) {
        invariant(!_positionalChild);
        _positionalChild = std::move(child);
    } else {
        invariant(_children.find(field) == _children.end());
        _children[std::move(field)] = std::move(child);
    }
}

BSONObj UpdateObjectNode::serialize(
    const query_shape::SerializationOptions& opts = query_shape::SerializationOptions{}) const {
    // Map from operator name to list of (path, update) pairs.
    std::map<std::string, std::vector<std::pair<std::string, BSONObj>>> operatorOrientedUpdates;

    BSONObjBuilder bob;

    for (const auto& [pathPrefix, child] : _children) {
        auto path = FieldRef(pathPrefix);
        child->produceSerializationMap(&path, &operatorOrientedUpdates, opts);
    }

    for (const auto& [op, updates] : operatorOrientedUpdates)
        bob << op << makeBSONForOperator(updates);

    return bob.obj();
}

UpdateExecutor::ApplyResult UpdateObjectNode::apply(
    ApplyParams applyParams, UpdateNodeApplyParams updateNodeApplyParams) const {
    bool applyPositional = _positionalChild.get();
    if (applyPositional) {
        uassert(ErrorCodes::BadValue,
                "The positional operator did not find the match needed from the query.",
                !applyParams.matchedField.empty());
    }

    auto applyResult = ApplyResult::noopResult();

    // When many fields under the same wide object are updated in one command, resolving each target
    // field with a linear findFirstChildNamed() scan is O(n^2). Build a one-time index over just
    // this update's target fields so each lookup is O(1). This only pays off past a threshold, and
    // only applies to object elements (array children are addressed by numeric index, not field
    // name). The index is seeded from the fields this node actually touches (its children, plus the
    // positional match), so its size is bounded by the update size rather than the document fan out.
    boost::optional<ChildLookupCache> childCache;
    // Read the runtime-tunable threshold once so a concurrent setParameter cannot change the
    // decision partway through this apply(). A value of 0 disables the index; a very large value
    // also effectively disables it.
    const auto childLookupCacheThreshold = gUpdateObjectNodeChildLookupCacheThreshold.load();
    if (childLookupCacheThreshold > 0 &&
        _children.size() >= static_cast<size_t>(childLookupCacheThreshold) &&
        applyParams.element.ok() && applyParams.element.getType() == BSONType::object) {
        std::vector<std::string_view> targetFields;
        targetFields.reserve(_children.size() + (applyPositional ? 1 : 0));
        for (const auto& pair : _children) {
            targetFields.push_back(pair.first);
        }
        if (applyPositional) {
            targetFields.push_back(applyParams.matchedField);
        }
        childCache.emplace(applyParams.element, targetFields);
    }
    const ChildLookupCache* childCachePtr = childCache ? childCache.get_ptr() : nullptr;

    for (const auto& pair : _children) {
        // If this child has the same field name as the positional child, they must be merged and
        // applied.
        if (applyPositional && pair.first == applyParams.matchedField) {

            // Check if we have stored the result of merging the positional child with this child.
            auto mergedChild = _mergedChildrenCache.find(pair.first);
            if (mergedChild == _mergedChildrenCache.end()) {
                // The full path to the merged field is required for error reporting. In order to
                // modify the 'pathTaken' FieldRef, we need a (mutable) copy of it.
                FieldRef pathTakenFieldRefCopy(updateNodeApplyParams.pathTaken->fieldRef());
                for (size_t i = 0; i < updateNodeApplyParams.pathToCreate->numParts(); ++i) {
                    pathTakenFieldRefCopy.appendPart(
                        updateNodeApplyParams.pathToCreate->getPart(i));
                }
                pathTakenFieldRefCopy.appendPart(applyParams.matchedField);
                auto insertResult = _mergedChildrenCache.emplace(
                    std::make_pair(pair.first,
                                   UpdateNode::createUpdateNodeByMerging(
                                       *_positionalChild, *pair.second, &pathTakenFieldRefCopy)));
                for (FieldIndex i = 0; i < updateNodeApplyParams.pathToCreate->numParts() + 1;
                     ++i) {
                    pathTakenFieldRefCopy.removeLastPart();
                }
                invariant(insertResult.second);
                mergedChild = insertResult.first;
            }

            applyChild(*mergedChild->second.get(),
                       pair.first,
                       &applyParams,
                       &updateNodeApplyParams,
                       &applyResult,
                       childCachePtr);

            applyPositional = false;
            continue;
        }

        // If 'matchedField' is alphabetically before the current child, we should apply the
        // positional child now.
        if (applyPositional && applyParams.matchedField < pair.first) {
            applyChild(*_positionalChild.get(),
                       applyParams.matchedField,
                       &applyParams,
                       &updateNodeApplyParams,
                       &applyResult,
                       childCachePtr);
            applyPositional = false;
        }

        // Apply the current child.
        applyChild(*pair.second,
                   pair.first,
                   &applyParams,
                   &updateNodeApplyParams,
                   &applyResult,
                   childCachePtr);
    }

    // 'matchedField' is alphabetically after all children, so we apply it now.
    if (applyPositional) {
        applyChild(*_positionalChild.get(),
                   applyParams.matchedField,
                   &applyParams,
                   &updateNodeApplyParams,
                   &applyResult,
                   childCachePtr);
    }

    return applyResult;
}

}  // namespace mongo
