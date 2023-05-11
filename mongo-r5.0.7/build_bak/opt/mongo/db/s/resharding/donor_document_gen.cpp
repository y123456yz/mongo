/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/s/resharding/donor_document_gen.h --output build/opt/mongo/db/s/resharding/donor_document_gen.cpp src/mongo/db/s/resharding/donor_document.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/s/resharding/donor_document_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData ReshardingDonorMetrics::kCriticalSectionFieldName;
constexpr StringData ReshardingDonorMetrics::kOperationRuntimeFieldName;


ReshardingDonorMetrics::ReshardingDonorMetrics()  {
    // Used for initialization only
}


ReshardingDonorMetrics ReshardingDonorMetrics::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ReshardingDonorMetrics>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ReshardingDonorMetrics::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kOperationRuntimeBit = 0;
    const size_t kCriticalSectionBit = 1;
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
        else if (fieldName == kCriticalSectionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCriticalSectionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCriticalSectionBit);

                IDLParserErrorContext tempContext(kCriticalSectionFieldName, &ctxt);
                const auto localObject = element.Obj();
                _criticalSection = mongo::ReshardingMetricsTimeInterval::parse(tempContext, localObject);
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


void ReshardingDonorMetrics::serialize(BSONObjBuilder* builder) const {
    if (_operationRuntime.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kOperationRuntimeFieldName));
        _operationRuntime.get().serialize(&subObjBuilder);
    }

    if (_criticalSection.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kCriticalSectionFieldName));
        _criticalSection.get().serialize(&subObjBuilder);
    }

}


BSONObj ReshardingDonorMetrics::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData ReshardingDonorDocument::kCommonReshardingMetadataFieldName;
constexpr StringData ReshardingDonorDocument::kMetricsFieldName;
constexpr StringData ReshardingDonorDocument::kMutableStateFieldName;
constexpr StringData ReshardingDonorDocument::kRecipientShardsFieldName;
constexpr StringData ReshardingDonorDocument::kReshardingKeyFieldName;
constexpr StringData ReshardingDonorDocument::kReshardingUUIDFieldName;
constexpr StringData ReshardingDonorDocument::kSourceNssFieldName;
constexpr StringData ReshardingDonorDocument::kSourceUUIDFieldName;
constexpr StringData ReshardingDonorDocument::kTempReshardingNssFieldName;


ReshardingDonorDocument::ReshardingDonorDocument() : _mutableState(mongo::idl::preparsedValue<decltype(_mutableState)>()), _hasMutableState(false), _hasRecipientShards(false) {
    // Used for initialization only
}
ReshardingDonorDocument::ReshardingDonorDocument(mongo::DonorShardContext mutableState, std::vector<mongo::ShardId> recipientShards) : _mutableState(std::move(mutableState)), _recipientShards(std::move(recipientShards)), _hasMutableState(true), _hasRecipientShards(true) {
    // Used for initialization only
}


ReshardingDonorDocument ReshardingDonorDocument::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ReshardingDonorDocument>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ReshardingDonorDocument::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<9> usedFields;
    const size_t kReshardingUUIDBit = 0;
    const size_t kSourceNssBit = 1;
    const size_t kSourceUUIDBit = 2;
    const size_t kTempReshardingNssBit = 3;
    const size_t kReshardingKeyBit = 4;
    const size_t kMutableStateBit = 5;
    const size_t kRecipientShardsBit = 6;
    const size_t kMetricsBit = 7;
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
        else if (fieldName == kMutableStateFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kMutableStateBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMutableStateBit);

                _hasMutableState = true;
                IDLParserErrorContext tempContext(kMutableStateFieldName, &ctxt);
                const auto localObject = element.Obj();
                _mutableState = mongo::DonorShardContext::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kRecipientShardsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kRecipientShardsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRecipientShardsBit);

                _hasRecipientShards = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kRecipientShardsFieldName, &ctxt);
            std::vector<mongo::ShardId> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, String)) {
                        values.emplace_back(arrayElement.str());
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _recipientShards = std::move(values);
        }
        else if (fieldName == kMetricsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kMetricsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMetricsBit);

                IDLParserErrorContext tempContext(kMetricsFieldName, &ctxt);
                const auto localObject = element.Obj();
                _metrics = mongo::ReshardingDonorMetrics::parse(tempContext, localObject);
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
        if (!usedFields[kRecipientShardsBit]) {
            ctxt.throwMissingField(kRecipientShardsFieldName);
        }
    }

}


void ReshardingDonorDocument::serialize(BSONObjBuilder* builder) const {
    invariant(_hasMutableState && _hasRecipientShards);

    {
        _commonReshardingMetadata.serialize(builder);
    }

    {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kMutableStateFieldName));
        _mutableState.serialize(&subObjBuilder);
    }

    {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kRecipientShardsFieldName));
        for (const auto& item : _recipientShards) {
            arrayBuilder.append(item.toString());
        }
    }

    if (_metrics.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kMetricsFieldName));
        _metrics.get().serialize(&subObjBuilder);
    }

}


BSONObj ReshardingDonorDocument::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
