/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/ops/delete_request_gen.h --output build/opt/mongo/db/ops/delete_request_gen.cpp src/mongo/db/ops/delete_request.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/ops/delete_request_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData DeleteRequest::kCollationFieldName;
constexpr StringData DeleteRequest::kFromMigrateFieldName;
constexpr StringData DeleteRequest::kGodFieldName;
constexpr StringData DeleteRequest::kHintFieldName;
constexpr StringData DeleteRequest::kIsExplainFieldName;
constexpr StringData DeleteRequest::kLegacyRuntimeConstantsFieldName;
constexpr StringData DeleteRequest::kLetFieldName;
constexpr StringData DeleteRequest::kMultiFieldName;
constexpr StringData DeleteRequest::kNsStringFieldName;
constexpr StringData DeleteRequest::kProjFieldName;
constexpr StringData DeleteRequest::kQueryFieldName;
constexpr StringData DeleteRequest::kReturnDeletedFieldName;
constexpr StringData DeleteRequest::kSortFieldName;
constexpr StringData DeleteRequest::kStmtIdFieldName;
constexpr StringData DeleteRequest::kYieldPolicyFieldName;


DeleteRequest::DeleteRequest() : _nsString(mongo::idl::preparsedValue<decltype(_nsString)>()), _hint(mongo::idl::preparsedValue<decltype(_hint)>()), _query(mongo::idl::preparsedValue<decltype(_query)>()), _proj(mongo::idl::preparsedValue<decltype(_proj)>()), _sort(mongo::idl::preparsedValue<decltype(_sort)>()), _collation(mongo::idl::preparsedValue<decltype(_collation)>()), _hasNsString(false), _hasHint(false), _hasQuery(false), _hasProj(false), _hasSort(false), _hasCollation(false) {
    // Used for initialization only
}
DeleteRequest::DeleteRequest(mongo::NamespaceString nsString, mongo::BSONObj hint, mongo::BSONObj query, mongo::BSONObj proj, mongo::BSONObj sort, mongo::BSONObj collation) : _nsString(std::move(nsString)), _hint(std::move(hint)), _query(std::move(query)), _proj(std::move(proj)), _sort(std::move(sort)), _collation(std::move(collation)), _hasNsString(true), _hasHint(true), _hasQuery(true), _hasProj(true), _hasSort(true), _hasCollation(true) {
    // Used for initialization only
}


DeleteRequest DeleteRequest::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<DeleteRequest>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void DeleteRequest::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<15> usedFields;
    const size_t kNsStringBit = 0;
    const size_t kHintBit = 1;
    const size_t kQueryBit = 2;
    const size_t kProjBit = 3;
    const size_t kSortBit = 4;
    const size_t kCollationBit = 5;
    const size_t kLetBit = 6;
    const size_t kLegacyRuntimeConstantsBit = 7;
    const size_t kStmtIdBit = 8;
    const size_t kMultiBit = 9;
    const size_t kGodBit = 10;
    const size_t kFromMigrateBit = 11;
    const size_t kIsExplainBit = 12;
    const size_t kReturnDeletedBit = 13;
    const size_t kYieldPolicyBit = 14;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kNsStringFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kNsStringBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNsStringBit);

                _hasNsString = true;
                _nsString = NamespaceString(element.valueStringData());
            }
        }
        else if (fieldName == kHintFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kHintBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kHintBit);

                _hasHint = true;
                _hint = element.Obj();
            }
        }
        else if (fieldName == kQueryFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kQueryBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kQueryBit);

                _hasQuery = true;
                _query = element.Obj();
            }
        }
        else if (fieldName == kProjFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kProjBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kProjBit);

                _hasProj = true;
                _proj = element.Obj();
            }
        }
        else if (fieldName == kSortFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kSortBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSortBit);

                _hasSort = true;
                _sort = element.Obj();
            }
        }
        else if (fieldName == kCollationFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCollationBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollationBit);

                _hasCollation = true;
                _collation = element.Obj();
            }
        }
        else if (fieldName == kLetFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kLetBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLetBit);

                _let = element.Obj();
            }
        }
        else if (fieldName == kLegacyRuntimeConstantsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kLegacyRuntimeConstantsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLegacyRuntimeConstantsBit);

                IDLParserErrorContext tempContext(kLegacyRuntimeConstantsFieldName, &ctxt);
                const auto localObject = element.Obj();
                _legacyRuntimeConstants = mongo::LegacyRuntimeConstants::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kStmtIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberInt))) {
                if (MONGO_unlikely(usedFields[kStmtIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStmtIdBit);

                _stmtId = element._numberInt();
            }
        }
        else if (fieldName == kMultiFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kMultiBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMultiBit);

                _multi = element.boolean();
            }
        }
        else if (fieldName == kGodFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kGodBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kGodBit);

                _god = element.boolean();
            }
        }
        else if (fieldName == kFromMigrateFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kFromMigrateBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kFromMigrateBit);

                _fromMigrate = element.boolean();
            }
        }
        else if (fieldName == kIsExplainFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kIsExplainBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIsExplainBit);

                _isExplain = element.boolean();
            }
        }
        else if (fieldName == kReturnDeletedFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kReturnDeletedBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kReturnDeletedBit);

                _returnDeleted = element.boolean();
            }
        }
        else if (fieldName == kYieldPolicyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kYieldPolicyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kYieldPolicyBit);

                _yieldPolicy = PlanYieldPolicy::parseFromBSON(element.valueStringData());
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kNsStringBit]) {
            ctxt.throwMissingField(kNsStringFieldName);
        }
        if (!usedFields[kHintBit]) {
            ctxt.throwMissingField(kHintFieldName);
        }
        if (!usedFields[kQueryBit]) {
            ctxt.throwMissingField(kQueryFieldName);
        }
        if (!usedFields[kProjBit]) {
            ctxt.throwMissingField(kProjFieldName);
        }
        if (!usedFields[kSortBit]) {
            ctxt.throwMissingField(kSortFieldName);
        }
        if (!usedFields[kCollationBit]) {
            ctxt.throwMissingField(kCollationFieldName);
        }
        if (!usedFields[kStmtIdBit]) {
            _stmtId = kUninitializedStmtId;
        }
        if (!usedFields[kMultiBit]) {
            _multi = false;
        }
        if (!usedFields[kGodBit]) {
            _god = false;
        }
        if (!usedFields[kFromMigrateBit]) {
            _fromMigrate = false;
        }
        if (!usedFields[kIsExplainBit]) {
            _isExplain = false;
        }
        if (!usedFields[kReturnDeletedBit]) {
            _returnDeleted = false;
        }
        if (!usedFields[kYieldPolicyBit]) {
            _yieldPolicy = PlanYieldPolicy::YieldPolicy::NO_YIELD;
        }
    }

}


void DeleteRequest::serialize(BSONObjBuilder* builder) const {
    invariant(_hasNsString && _hasHint && _hasQuery && _hasProj && _hasSort && _hasCollation);

    {
        builder->append(kNsStringFieldName, _nsString.toString());
    }

    builder->append(kHintFieldName, _hint);

    builder->append(kQueryFieldName, _query);

    builder->append(kProjFieldName, _proj);

    builder->append(kSortFieldName, _sort);

    builder->append(kCollationFieldName, _collation);

    if (_let.is_initialized()) {
        builder->append(kLetFieldName, _let.get());
    }

    if (_legacyRuntimeConstants.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kLegacyRuntimeConstantsFieldName));
        _legacyRuntimeConstants.get().serialize(&subObjBuilder);
    }

    builder->append(kStmtIdFieldName, _stmtId);

    builder->append(kMultiFieldName, _multi);

    builder->append(kGodFieldName, _god);

    builder->append(kFromMigrateFieldName, _fromMigrate);

    builder->append(kIsExplainFieldName, _isExplain);

    builder->append(kReturnDeletedFieldName, _returnDeleted);

    {
        builder->append(kYieldPolicyFieldName, ::mongo::PlanYieldPolicy::serializeYieldPolicy(_yieldPolicy));
    }

}


BSONObj DeleteRequest::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
