/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/s/resharding/coordinator_document_gen.h --output build/opt/mongo/db/s/resharding/coordinator_document_gen.cpp src/mongo/db/s/resharding/coordinator_document.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/s/resharding/coordinator_document_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData DonorShardEntry::kIdFieldName;
constexpr StringData DonorShardEntry::kMutableStateFieldName;


DonorShardEntry::DonorShardEntry() : _id(mongo::idl::preparsedValue<decltype(_id)>()), _mutableState(mongo::idl::preparsedValue<decltype(_mutableState)>()), _hasId(false), _hasMutableState(false) {
    // Used for initialization only
}
DonorShardEntry::DonorShardEntry(mongo::ShardId id, mongo::DonorShardContext mutableState) : _id(std::move(id)), _mutableState(std::move(mutableState)), _hasId(true), _hasMutableState(true) {
    // Used for initialization only
}


DonorShardEntry DonorShardEntry::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<DonorShardEntry>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void DonorShardEntry::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kIdBit = 0;
    const size_t kMutableStateBit = 1;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIdBit);

                _hasId = true;
                _id = element.str();
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
        else {
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kIdBit]) {
            ctxt.throwMissingField(kIdFieldName);
        }
        if (!usedFields[kMutableStateBit]) {
            ctxt.throwMissingField(kMutableStateFieldName);
        }
    }

}


void DonorShardEntry::serialize(BSONObjBuilder* builder) const {
    invariant(_hasId && _hasMutableState);

    {
        builder->append(kIdFieldName, _id.toString());
    }

    {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kMutableStateFieldName));
        _mutableState.serialize(&subObjBuilder);
    }

}


BSONObj DonorShardEntry::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData RecipientShardEntry::kIdFieldName;
constexpr StringData RecipientShardEntry::kMutableStateFieldName;


RecipientShardEntry::RecipientShardEntry() : _id(mongo::idl::preparsedValue<decltype(_id)>()), _mutableState(mongo::idl::preparsedValue<decltype(_mutableState)>()), _hasId(false), _hasMutableState(false) {
    // Used for initialization only
}
RecipientShardEntry::RecipientShardEntry(mongo::ShardId id, mongo::RecipientShardContext mutableState) : _id(std::move(id)), _mutableState(std::move(mutableState)), _hasId(true), _hasMutableState(true) {
    // Used for initialization only
}


RecipientShardEntry RecipientShardEntry::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<RecipientShardEntry>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void RecipientShardEntry::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kIdBit = 0;
    const size_t kMutableStateBit = 1;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIdBit);

                _hasId = true;
                _id = element.str();
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
        else {
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kIdBit]) {
            ctxt.throwMissingField(kIdFieldName);
        }
        if (!usedFields[kMutableStateBit]) {
            ctxt.throwMissingField(kMutableStateFieldName);
        }
    }

}


void RecipientShardEntry::serialize(BSONObjBuilder* builder) const {
    invariant(_hasId && _hasMutableState);

    {
        builder->append(kIdFieldName, _id.toString());
    }

    {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kMutableStateFieldName));
        _mutableState.serialize(&subObjBuilder);
    }

}


BSONObj RecipientShardEntry::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData ReshardingCoordinatorMetrics::kOperationRuntimeFieldName;


ReshardingCoordinatorMetrics::ReshardingCoordinatorMetrics()  {
    // Used for initialization only
}


ReshardingCoordinatorMetrics ReshardingCoordinatorMetrics::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ReshardingCoordinatorMetrics>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ReshardingCoordinatorMetrics::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kOperationRuntimeBit = 0;
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


void ReshardingCoordinatorMetrics::serialize(BSONObjBuilder* builder) const {
    if (_operationRuntime.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kOperationRuntimeFieldName));
        _operationRuntime.get().serialize(&subObjBuilder);
    }

}


BSONObj ReshardingCoordinatorMetrics::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData ReshardingCoordinatorDocument::kAbortReasonStructFieldName;
constexpr StringData ReshardingCoordinatorDocument::kCommonReshardingMetadataFieldName;
constexpr StringData ReshardingCoordinatorDocument::kReshardingApproxCopySizeStructFieldName;
constexpr StringData ReshardingCoordinatorDocument::kAbortReasonFieldName;
constexpr StringData ReshardingCoordinatorDocument::kActiveFieldName;
constexpr StringData ReshardingCoordinatorDocument::kApproxBytesToCopyFieldName;
constexpr StringData ReshardingCoordinatorDocument::kApproxDocumentsToCopyFieldName;
constexpr StringData ReshardingCoordinatorDocument::kCloneTimestampFieldName;
constexpr StringData ReshardingCoordinatorDocument::kDonorShardsFieldName;
constexpr StringData ReshardingCoordinatorDocument::kMetricsFieldName;
constexpr StringData ReshardingCoordinatorDocument::kNumInitialChunksFieldName;
constexpr StringData ReshardingCoordinatorDocument::kPresetReshardedChunksFieldName;
constexpr StringData ReshardingCoordinatorDocument::kRecipientShardsFieldName;
constexpr StringData ReshardingCoordinatorDocument::kReshardingKeyFieldName;
constexpr StringData ReshardingCoordinatorDocument::kReshardingUUIDFieldName;
constexpr StringData ReshardingCoordinatorDocument::kSourceNssFieldName;
constexpr StringData ReshardingCoordinatorDocument::kSourceUUIDFieldName;
constexpr StringData ReshardingCoordinatorDocument::kStateFieldName;
constexpr StringData ReshardingCoordinatorDocument::kTempReshardingNssFieldName;
constexpr StringData ReshardingCoordinatorDocument::kZonesFieldName;


ReshardingCoordinatorDocument::ReshardingCoordinatorDocument() : _state(mongo::idl::preparsedValue<decltype(_state)>()), _hasState(false), _hasDonorShards(false), _hasRecipientShards(false) {
    // Used for initialization only
}
ReshardingCoordinatorDocument::ReshardingCoordinatorDocument(mongo::CoordinatorStateEnum state, std::vector<mongo::DonorShardEntry> donorShards, std::vector<mongo::RecipientShardEntry> recipientShards) : _state(std::move(state)), _donorShards(std::move(donorShards)), _recipientShards(std::move(recipientShards)), _hasState(true), _hasDonorShards(true), _hasRecipientShards(true) {
    // Used for initialization only
}


ReshardingCoordinatorDocument ReshardingCoordinatorDocument::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ReshardingCoordinatorDocument>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ReshardingCoordinatorDocument::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<20> usedFields;
    const size_t kReshardingUUIDBit = 0;
    const size_t kSourceNssBit = 1;
    const size_t kSourceUUIDBit = 2;
    const size_t kTempReshardingNssBit = 3;
    const size_t kReshardingKeyBit = 4;
    const size_t kApproxDocumentsToCopyBit = 5;
    const size_t kApproxBytesToCopyBit = 6;
    const size_t kAbortReasonBit = 7;
    const size_t kStateBit = 8;
    const size_t kCloneTimestampBit = 9;
    const size_t kDonorShardsBit = 10;
    const size_t kRecipientShardsBit = 11;
    const size_t kZonesBit = 12;
    const size_t kNumInitialChunksBit = 13;
    const size_t kPresetReshardedChunksBit = 14;
    const size_t kActiveBit = 15;
    const size_t kMetricsBit = 16;
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
        else if (fieldName == kApproxDocumentsToCopyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kApproxDocumentsToCopyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kApproxDocumentsToCopyBit);

                _reshardingApproxCopySizeStruct.setApproxDocumentsToCopy(boost::optional<std::int64_t>(element._numberLong()));
            }
        }
        else if (fieldName == kApproxBytesToCopyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kApproxBytesToCopyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kApproxBytesToCopyBit);

                _reshardingApproxCopySizeStruct.setApproxBytesToCopy(boost::optional<std::int64_t>(element._numberLong()));
            }
        }
        else if (fieldName == kAbortReasonFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kAbortReasonBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAbortReasonBit);

                const BSONObj localObject = element.Obj();
                _abortReasonStruct.setAbortReason(boost::optional<mongo::BSONObj>(BSONObj::getOwned(localObject)));
            }
        }
        else if (fieldName == kStateFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kStateBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStateBit);

                _hasState = true;
                IDLParserErrorContext tempContext(kStateFieldName, &ctxt);
                _state = CoordinatorState_parse(tempContext, element.valueStringData());
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
            std::vector<mongo::DonorShardEntry> values;

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
                        values.emplace_back(mongo::DonorShardEntry::parse(tempContext, localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _donorShards = std::move(values);
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
            std::vector<mongo::RecipientShardEntry> values;

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
                        IDLParserErrorContext tempContext(kRecipientShardsFieldName, &ctxt);
                        const auto localObject = arrayElement.Obj();
                        values.emplace_back(mongo::RecipientShardEntry::parse(tempContext, localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _recipientShards = std::move(values);
        }
        else if (fieldName == kZonesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kZonesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kZonesBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kZonesFieldName, &ctxt);
            std::vector<mongo::ReshardingZoneType> values;

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
                        IDLParserErrorContext tempContext(kZonesFieldName, &ctxt);
                        const auto localObject = arrayElement.Obj();
                        values.emplace_back(mongo::ReshardingZoneType::parse(tempContext, localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _zones = std::move(values);
        }
        else if (fieldName == kNumInitialChunksFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kNumInitialChunksBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNumInitialChunksBit);

                _numInitialChunks = element._numberLong();
            }
        }
        else if (fieldName == kPresetReshardedChunksFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kPresetReshardedChunksBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPresetReshardedChunksBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kPresetReshardedChunksFieldName, &ctxt);
            std::vector<mongo::ReshardedChunk> values;

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
                        IDLParserErrorContext tempContext(kPresetReshardedChunksFieldName, &ctxt);
                        const auto localObject = arrayElement.Obj();
                        values.emplace_back(mongo::ReshardedChunk::parse(tempContext, localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _presetReshardedChunks = std::move(values);
        }
        else if (fieldName == kActiveFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kActiveBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kActiveBit);

                _active = element.boolean();
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
                _metrics = mongo::ReshardingCoordinatorMetrics::parse(tempContext, localObject);
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
        if (!usedFields[kStateBit]) {
            ctxt.throwMissingField(kStateFieldName);
        }
        if (!usedFields[kDonorShardsBit]) {
            ctxt.throwMissingField(kDonorShardsFieldName);
        }
        if (!usedFields[kRecipientShardsBit]) {
            ctxt.throwMissingField(kRecipientShardsFieldName);
        }
        if (!usedFields[kActiveBit]) {
            _active = true;
        }
    }

}


void ReshardingCoordinatorDocument::serialize(BSONObjBuilder* builder) const {
    invariant(_hasState && _hasDonorShards && _hasRecipientShards);

    {
        _commonReshardingMetadata.serialize(builder);
    }

    {
        _reshardingApproxCopySizeStruct.serialize(builder);
    }

    {
        _abortReasonStruct.serialize(builder);
    }

    {
        builder->append(kStateFieldName, ::mongo::CoordinatorState_serializer(_state));
    }

    if (_cloneTimestamp.is_initialized()) {
        builder->append(kCloneTimestampFieldName, _cloneTimestamp.get());
    }

    {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kDonorShardsFieldName));
        for (const auto& item : _donorShards) {
            BSONObjBuilder subObjBuilder(arrayBuilder.subobjStart());
            item.serialize(&subObjBuilder);
        }
    }

    {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kRecipientShardsFieldName));
        for (const auto& item : _recipientShards) {
            BSONObjBuilder subObjBuilder(arrayBuilder.subobjStart());
            item.serialize(&subObjBuilder);
        }
    }

    if (_zones.is_initialized()) {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kZonesFieldName));
        for (const auto& item : _zones.get()) {
            BSONObjBuilder subObjBuilder(arrayBuilder.subobjStart());
            item.serialize(&subObjBuilder);
        }
    }

    if (_numInitialChunks.is_initialized()) {
        builder->append(kNumInitialChunksFieldName, _numInitialChunks.get());
    }

    if (_presetReshardedChunks.is_initialized()) {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kPresetReshardedChunksFieldName));
        for (const auto& item : _presetReshardedChunks.get()) {
            BSONObjBuilder subObjBuilder(arrayBuilder.subobjStart());
            item.serialize(&subObjBuilder);
        }
    }

    builder->append(kActiveFieldName, _active);

    if (_metrics.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kMetricsFieldName));
        _metrics.get().serialize(&subObjBuilder);
    }

}


BSONObj ReshardingCoordinatorDocument::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
