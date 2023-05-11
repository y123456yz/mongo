/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/s/resharding/recipient_document_gen.h --output build/opt/mongo/db/s/resharding/recipient_document_gen.cpp src/mongo/db/s/resharding/recipient_document.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/s/resharding/recipient_document_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData ReshardingRecipientMetrics::kDocumentCopyFieldName;
constexpr StringData ReshardingRecipientMetrics::kOperationRuntimeFieldName;
constexpr StringData ReshardingRecipientMetrics::kOplogApplicationFieldName;


ReshardingRecipientMetrics::ReshardingRecipientMetrics()  {
    // Used for initialization only
}


ReshardingRecipientMetrics ReshardingRecipientMetrics::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ReshardingRecipientMetrics>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ReshardingRecipientMetrics::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<3> usedFields;
    const size_t kOperationRuntimeBit = 0;
    const size_t kDocumentCopyBit = 1;
    const size_t kOplogApplicationBit = 2;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kOperationRuntimeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kOperationRuntimeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kOperationRuntimeBit);

                IDLParserErrorContext tempContext(kOperationRuntimeFieldName, &ctxt);
                const auto localObject = element.Obj();
                _operationRuntime = mongo::ReshardingMetricsTimeInterval::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kDocumentCopyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kDocumentCopyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDocumentCopyBit);

                IDLParserErrorContext tempContext(kDocumentCopyFieldName, &ctxt);
                const auto localObject = element.Obj();
                _documentCopy = mongo::ReshardingMetricsTimeInterval::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kOplogApplicationFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kOplogApplicationBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kOplogApplicationBit);

                IDLParserErrorContext tempContext(kOplogApplicationFieldName, &ctxt);
                const auto localObject = element.Obj();
                _oplogApplication = mongo::ReshardingMetricsTimeInterval::parse(tempContext, localObject);
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
    }

}


void ReshardingRecipientMetrics::serialize(BSONObjBuilder* builder) const {
    if (_operationRuntime.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kOperationRuntimeFieldName));
        _operationRuntime.get().serialize(&subObjBuilder);
    }

    if (_documentCopy.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kDocumentCopyFieldName));
        _documentCopy.get().serialize(&subObjBuilder);
    }

    if (_oplogApplication.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kOplogApplicationFieldName));
        _oplogApplication.get().serialize(&subObjBuilder);
    }

}


BSONObj ReshardingRecipientMetrics::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData ReshardingRecipientDocument::kCommonReshardingMetadataFieldName;
constexpr StringData ReshardingRecipientDocument::kCloneTimestampFieldName;
constexpr StringData ReshardingRecipientDocument::kDonorShardsFieldName;
constexpr StringData ReshardingRecipientDocument::kMetricsFieldName;
constexpr StringData ReshardingRecipientDocument::kMinimumOperationDurationMillisFieldName;
constexpr StringData ReshardingRecipientDocument::kMutableStateFieldName;
constexpr StringData ReshardingRecipientDocument::kReshardingKeyFieldName;
constexpr StringData ReshardingRecipientDocument::kReshardingUUIDFieldName;
constexpr StringData ReshardingRecipientDocument::kSourceNssFieldName;
constexpr StringData ReshardingRecipientDocument::kSourceUUIDFieldName;
constexpr StringData ReshardingRecipientDocument::kStartConfigTxnCloneTimeFieldName;
constexpr StringData ReshardingRecipientDocument::kTempReshardingNssFieldName;


ReshardingRecipientDocument::ReshardingRecipientDocument() : _mutableState(mongo::idl::preparsedValue<decltype(_mutableState)>()), _minimumOperationDurationMillis(mongo::idl::preparsedValue<decltype(_minimumOperationDurationMillis)>()), _hasMutableState(false), _hasDonorShards(false), _hasMinimumOperationDurationMillis(false) {
    // Used for initialization only
}
ReshardingRecipientDocument::ReshardingRecipientDocument(mongo::RecipientShardContext mutableState, std::vector<mongo::DonorShardFetchTimestamp> donorShards, std::int64_t minimumOperationDurationMillis) : _mutableState(std::move(mutableState)), _donorShards(std::move(donorShards)), _minimumOperationDurationMillis(std::move(minimumOperationDurationMillis)), _hasMutableState(true), _hasDonorShards(true), _hasMinimumOperationDurationMillis(true) {
    // Used for initialization only
}


ReshardingRecipientDocument ReshardingRecipientDocument::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ReshardingRecipientDocument>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ReshardingRecipientDocument::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<12> usedFields;
    const size_t kReshardingUUIDBit = 0;
    const size_t kSourceNssBit = 1;
    const size_t kSourceUUIDBit = 2;
    const size_t kTempReshardingNssBit = 3;
    const size_t kReshardingKeyBit = 4;
    const size_t kCloneTimestampBit = 5;
    const size_t kMutableStateBit = 6;
    const size_t kDonorShardsBit = 7;
    const size_t kMinimumOperationDurationMillisBit = 8;
    const size_t kStartConfigTxnCloneTimeBit = 9;
    const size_t kMetricsBit = 10;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kReshardingUUIDFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kReshardingUUIDBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kReshardingUUIDBit);

                _commonReshardingMetadata.setReshardingUUID(UUID(uassertStatusOK(UUID::parse(element))));
            }
        }
        else if (fieldName == kSourceNssFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kSourceNssBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSourceNssBit);

                _commonReshardingMetadata.setSourceNss(NamespaceString(element.valueStringData()));
            }
        }
        else if (fieldName == kSourceUUIDFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kSourceUUIDBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSourceUUIDBit);

                _commonReshardingMetadata.setSourceUUID(UUID(uassertStatusOK(UUID::parse(element))));
            }
        }
        else if (fieldName == kTempReshardingNssFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kTempReshardingNssBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTempReshardingNssBit);

                _commonReshardingMetadata.setTempReshardingNss(NamespaceString(element.valueStringData()));
            }
        }
        else if (fieldName == kReshardingKeyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kReshardingKeyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kReshardingKeyBit);

                const BSONObj localObject = element.Obj();
                _commonReshardingMetadata.setReshardingKey(KeyPattern::fromBSON(localObject));
            }
        }
        else if (fieldName == kCloneTimestampFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, bsonTimestamp))) {
                if (MONGO_unlikely(usedFields[kCloneTimestampBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCloneTimestampBit);

                _cloneTimestamp = element.timestamp();
            }
        }
        else if (fieldName == kMutableStateFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kMutableStateBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMutableStateBit);

                _hasMutableState = true;
                IDLParserErrorContext tempContext(kMutableStateFieldName, &ctxt);
                const auto localObject = element.Obj();
                _mutableState = mongo::RecipientShardContext::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kDonorShardsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kDonorShardsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDonorShardsBit);

                _hasDonorShards = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kDonorShardsFieldName, &ctxt);
            std::vector<mongo::DonorShardFetchTimestamp> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, Object)) {
                        IDLParserErrorContext tempContext(kDonorShardsFieldName, &ctxt);
                        const auto localObject = arrayElement.Obj();
                        values.emplace_back(mongo::DonorShardFetchTimestamp::parse(tempContext, localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _donorShards = std::move(values);
        }
        else if (fieldName == kMinimumOperationDurationMillisFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kMinimumOperationDurationMillisBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMinimumOperationDurationMillisBit);

                _hasMinimumOperationDurationMillis = true;
                _minimumOperationDurationMillis = element._numberLong();
            }
        }
        else if (fieldName == kStartConfigTxnCloneTimeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Date))) {
                if (MONGO_unlikely(usedFields[kStartConfigTxnCloneTimeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStartConfigTxnCloneTimeBit);

                _startConfigTxnCloneTime = element.date();
            }
        }
        else if (fieldName == kMetricsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kMetricsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMetricsBit);

                IDLParserErrorContext tempContext(kMetricsFieldName, &ctxt);
                const auto localObject = element.Obj();
                _metrics = mongo::ReshardingRecipientMetrics::parse(tempContext, localObject);
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
        if (!usedFields[kReshardingUUIDBit]) {
            ctxt.throwMissingField(kReshardingUUIDFieldName);
        }
        if (!usedFields[kSourceNssBit]) {
            ctxt.throwMissingField(kSourceNssFieldName);
        }
        if (!usedFields[kSourceUUIDBit]) {
            ctxt.throwMissingField(kSourceUUIDFieldName);
        }
        if (!usedFields[kTempReshardingNssBit]) {
            ctxt.throwMissingField(kTempReshardingNssFieldName);
        }
        if (!usedFields[kReshardingKeyBit]) {
            ctxt.throwMissingField(kReshardingKeyFieldName);
        }
        if (!usedFields[kMutableStateBit]) {
            ctxt.throwMissingField(kMutableStateFieldName);
        }
        if (!usedFields[kDonorShardsBit]) {
            ctxt.throwMissingField(kDonorShardsFieldName);
        }
        if (!usedFields[kMinimumOperationDurationMillisBit]) {
            ctxt.throwMissingField(kMinimumOperationDurationMillisFieldName);
        }
    }

}


void ReshardingRecipientDocument::serialize(BSONObjBuilder* builder) const {
    invariant(_hasMutableState && _hasDonorShards && _hasMinimumOperationDurationMillis);

    {
        _commonReshardingMetadata.serialize(builder);
    }

    if (_cloneTimestamp.is_initialized()) {
        builder->append(kCloneTimestampFieldName, _cloneTimestamp.get());
    }

    {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kMutableStateFieldName));
        _mutableState.serialize(&subObjBuilder);
    }

    {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kDonorShardsFieldName));
        for (const auto& item : _donorShards) {
            BSONObjBuilder subObjBuilder(arrayBuilder.subobjStart());
            item.serialize(&subObjBuilder);
        }
    }

    builder->append(kMinimumOperationDurationMillisFieldName, _minimumOperationDurationMillis);

    if (_startConfigTxnCloneTime.is_initialized()) {
        builder->append(kStartConfigTxnCloneTimeFieldName, _startConfigTxnCloneTime.get());
    }

    if (_metrics.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kMetricsFieldName));
        _metrics.get().serialize(&subObjBuilder);
    }

}


BSONObj ReshardingRecipientDocument::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
