/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/s/collection_critical_section_document_gen.h --output build/opt/mongo/db/s/collection_critical_section_document_gen.cpp src/mongo/db/s/collection_critical_section_document.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/s/collection_critical_section_document_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData CollectionCriticalSectionDocument::kAdditionalInfoFieldName;
constexpr StringData CollectionCriticalSectionDocument::kBlockReadsFieldName;
constexpr StringData CollectionCriticalSectionDocument::kNssFieldName;
constexpr StringData CollectionCriticalSectionDocument::kReasonFieldName;


CollectionCriticalSectionDocument::CollectionCriticalSectionDocument() : _nss(mongo::idl::preparsedValue<decltype(_nss)>()), _reason(mongo::idl::preparsedValue<decltype(_reason)>()), _blockReads(mongo::idl::preparsedValue<decltype(_blockReads)>()), _hasNss(false), _hasReason(false), _hasBlockReads(false) {
    // Used for initialization only
}
CollectionCriticalSectionDocument::CollectionCriticalSectionDocument(mongo::NamespaceString nss, mongo::BSONObj reason, bool blockReads) : _nss(std::move(nss)), _reason(std::move(reason)), _blockReads(std::move(blockReads)), _hasNss(true), _hasReason(true), _hasBlockReads(true) {
    // Used for initialization only
}


CollectionCriticalSectionDocument CollectionCriticalSectionDocument::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<CollectionCriticalSectionDocument>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void CollectionCriticalSectionDocument::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<4> usedFields;
    const size_t kNssBit = 0;
    const size_t kReasonBit = 1;
    const size_t kBlockReadsBit = 2;
    const size_t kAdditionalInfoBit = 3;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kNssFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kNssBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNssBit);

                _hasNss = true;
                _nss = NamespaceString(element.valueStringData());
            }
        }
        else if (fieldName == kReasonFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kReasonBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kReasonBit);

                _hasReason = true;
                _reason = element.Obj();
            }
        }
        else if (fieldName == kBlockReadsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kBlockReadsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kBlockReadsBit);

                _hasBlockReads = true;
                _blockReads = element.boolean();
            }
        }
        else if (fieldName == kAdditionalInfoFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kAdditionalInfoBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAdditionalInfoBit);

                _additionalInfo = element.Obj();
            }
        }
        else {
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kNssBit]) {
            ctxt.throwMissingField(kNssFieldName);
        }
        if (!usedFields[kReasonBit]) {
            ctxt.throwMissingField(kReasonFieldName);
        }
        if (!usedFields[kBlockReadsBit]) {
            ctxt.throwMissingField(kBlockReadsFieldName);
        }
    }

}


void CollectionCriticalSectionDocument::serialize(BSONObjBuilder* builder) const {
    invariant(_hasNss && _hasReason && _hasBlockReads);

    {
        builder->append(kNssFieldName, _nss.toString());
    }

    builder->append(kReasonFieldName, _reason);

    builder->append(kBlockReadsFieldName, _blockReads);

    if (_additionalInfo.is_initialized()) {
        builder->append(kAdditionalInfoFieldName, _additionalInfo.get());
    }

}


BSONObj CollectionCriticalSectionDocument::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
