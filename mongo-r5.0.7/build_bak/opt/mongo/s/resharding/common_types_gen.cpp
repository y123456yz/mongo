/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/s/resharding/common_types_gen.h --output build/opt/mongo/s/resharding/common_types_gen.cpp src/mongo/s/resharding/common_types.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/s/resharding/common_types_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

/**
 * The current state of a resharding operation on the coordinator.
 */
namespace  {
constexpr StringData kCoordinatorState_kUnused = "unused"_sd;
constexpr StringData kCoordinatorState_kInitializing = "initializing"_sd;
constexpr StringData kCoordinatorState_kPreparingToDonate = "preparing-to-donate"_sd;
constexpr StringData kCoordinatorState_kCloning = "cloning"_sd;
constexpr StringData kCoordinatorState_kApplying = "applying"_sd;
constexpr StringData kCoordinatorState_kBlockingWrites = "blocking-writes"_sd;
constexpr StringData kCoordinatorState_kAborting = "aborting"_sd;
constexpr StringData kCoordinatorState_kCommitting = "committing"_sd;
constexpr StringData kCoordinatorState_kDone = "done"_sd;
}  // namespace 

CoordinatorStateEnum CoordinatorState_parse(const IDLParserErrorContext& ctxt, StringData value) {
    if (value == kCoordinatorState_kUnused) {
        return CoordinatorStateEnum::kUnused;
    }
    if (value == kCoordinatorState_kInitializing) {
        return CoordinatorStateEnum::kInitializing;
    }
    if (value == kCoordinatorState_kPreparingToDonate) {
        return CoordinatorStateEnum::kPreparingToDonate;
    }
    if (value == kCoordinatorState_kCloning) {
        return CoordinatorStateEnum::kCloning;
    }
    if (value == kCoordinatorState_kApplying) {
        return CoordinatorStateEnum::kApplying;
    }
    if (value == kCoordinatorState_kBlockingWrites) {
        return CoordinatorStateEnum::kBlockingWrites;
    }
    if (value == kCoordinatorState_kAborting) {
        return CoordinatorStateEnum::kAborting;
    }
    if (value == kCoordinatorState_kCommitting) {
        return CoordinatorStateEnum::kCommitting;
    }
    if (value == kCoordinatorState_kDone) {
        return CoordinatorStateEnum::kDone;
    }
    ctxt.throwBadEnumValue(value);
}

StringData CoordinatorState_serializer(CoordinatorStateEnum value) {
    if (value == CoordinatorStateEnum::kUnused) {
        return kCoordinatorState_kUnused;
    }
    if (value == CoordinatorStateEnum::kInitializing) {
        return kCoordinatorState_kInitializing;
    }
    if (value == CoordinatorStateEnum::kPreparingToDonate) {
        return kCoordinatorState_kPreparingToDonate;
    }
    if (value == CoordinatorStateEnum::kCloning) {
        return kCoordinatorState_kCloning;
    }
    if (value == CoordinatorStateEnum::kApplying) {
        return kCoordinatorState_kApplying;
    }
    if (value == CoordinatorStateEnum::kBlockingWrites) {
        return kCoordinatorState_kBlockingWrites;
    }
    if (value == CoordinatorStateEnum::kAborting) {
        return kCoordinatorState_kAborting;
    }
    if (value == CoordinatorStateEnum::kCommitting) {
        return kCoordinatorState_kCommitting;
    }
    if (value == CoordinatorStateEnum::kDone) {
        return kCoordinatorState_kDone;
    }
    MONGO_UNREACHABLE;
    return StringData();
}

/**
 * The current state of a donor shard for a resharding operation.
 */
namespace  {
constexpr StringData kDonorState_kUnused = "unused"_sd;
constexpr StringData kDonorState_kPreparingToDonate = "preparing-to-donate"_sd;
constexpr StringData kDonorState_kDonatingInitialData = "donating-initial-data"_sd;
constexpr StringData kDonorState_kDonatingOplogEntries = "donating-oplog-entries"_sd;
constexpr StringData kDonorState_kPreparingToBlockWrites = "preparing-to-block-writes"_sd;
constexpr StringData kDonorState_kError = "error"_sd;
constexpr StringData kDonorState_kBlockingWrites = "blocking-writes"_sd;
constexpr StringData kDonorState_kDone = "done"_sd;
}  // namespace 

DonorStateEnum DonorState_parse(const IDLParserErrorContext& ctxt, StringData value) {
    if (value == kDonorState_kUnused) {
        return DonorStateEnum::kUnused;
    }
    if (value == kDonorState_kPreparingToDonate) {
        return DonorStateEnum::kPreparingToDonate;
    }
    if (value == kDonorState_kDonatingInitialData) {
        return DonorStateEnum::kDonatingInitialData;
    }
    if (value == kDonorState_kDonatingOplogEntries) {
        return DonorStateEnum::kDonatingOplogEntries;
    }
    if (value == kDonorState_kPreparingToBlockWrites) {
        return DonorStateEnum::kPreparingToBlockWrites;
    }
    if (value == kDonorState_kError) {
        return DonorStateEnum::kError;
    }
    if (value == kDonorState_kBlockingWrites) {
        return DonorStateEnum::kBlockingWrites;
    }
    if (value == kDonorState_kDone) {
        return DonorStateEnum::kDone;
    }
    ctxt.throwBadEnumValue(value);
}

StringData DonorState_serializer(DonorStateEnum value) {
    if (value == DonorStateEnum::kUnused) {
        return kDonorState_kUnused;
    }
    if (value == DonorStateEnum::kPreparingToDonate) {
        return kDonorState_kPreparingToDonate;
    }
    if (value == DonorStateEnum::kDonatingInitialData) {
        return kDonorState_kDonatingInitialData;
    }
    if (value == DonorStateEnum::kDonatingOplogEntries) {
        return kDonorState_kDonatingOplogEntries;
    }
    if (value == DonorStateEnum::kPreparingToBlockWrites) {
        return kDonorState_kPreparingToBlockWrites;
    }
    if (value == DonorStateEnum::kError) {
        return kDonorState_kError;
    }
    if (value == DonorStateEnum::kBlockingWrites) {
        return kDonorState_kBlockingWrites;
    }
    if (value == DonorStateEnum::kDone) {
        return kDonorState_kDone;
    }
    MONGO_UNREACHABLE;
    return StringData();
}

/**
 * The current state of a recipient shard for a resharding operation.
 */
namespace  {
constexpr StringData kRecipientState_kUnused = "unused"_sd;
constexpr StringData kRecipientState_kAwaitingFetchTimestamp = "awaiting-fetch-timestamp"_sd;
constexpr StringData kRecipientState_kCreatingCollection = "creating-collection"_sd;
constexpr StringData kRecipientState_kCloning = "cloning"_sd;
constexpr StringData kRecipientState_kApplying = "applying"_sd;
constexpr StringData kRecipientState_kError = "error"_sd;
constexpr StringData kRecipientState_kStrictConsistency = "strict-consistency"_sd;
constexpr StringData kRecipientState_kDone = "done"_sd;
}  // namespace 

RecipientStateEnum RecipientState_parse(const IDLParserErrorContext& ctxt, StringData value) {
    if (value == kRecipientState_kUnused) {
        return RecipientStateEnum::kUnused;
    }
    if (value == kRecipientState_kAwaitingFetchTimestamp) {
        return RecipientStateEnum::kAwaitingFetchTimestamp;
    }
    if (value == kRecipientState_kCreatingCollection) {
        return RecipientStateEnum::kCreatingCollection;
    }
    if (value == kRecipientState_kCloning) {
        return RecipientStateEnum::kCloning;
    }
    if (value == kRecipientState_kApplying) {
        return RecipientStateEnum::kApplying;
    }
    if (value == kRecipientState_kError) {
        return RecipientStateEnum::kError;
    }
    if (value == kRecipientState_kStrictConsistency) {
        return RecipientStateEnum::kStrictConsistency;
    }
    if (value == kRecipientState_kDone) {
        return RecipientStateEnum::kDone;
    }
    ctxt.throwBadEnumValue(value);
}

StringData RecipientState_serializer(RecipientStateEnum value) {
    if (value == RecipientStateEnum::kUnused) {
        return kRecipientState_kUnused;
    }
    if (value == RecipientStateEnum::kAwaitingFetchTimestamp) {
        return kRecipientState_kAwaitingFetchTimestamp;
    }
    if (value == RecipientStateEnum::kCreatingCollection) {
        return kRecipientState_kCreatingCollection;
    }
    if (value == RecipientStateEnum::kCloning) {
        return kRecipientState_kCloning;
    }
    if (value == RecipientStateEnum::kApplying) {
        return kRecipientState_kApplying;
    }
    if (value == RecipientStateEnum::kError) {
        return kRecipientState_kError;
    }
    if (value == RecipientStateEnum::kStrictConsistency) {
        return kRecipientState_kStrictConsistency;
    }
    if (value == RecipientStateEnum::kDone) {
        return kRecipientState_kDone;
    }
    MONGO_UNREACHABLE;
    return StringData();
}

/**
 * The status of the current or most recent resharding operation.
 */
namespace  {
constexpr StringData kReshardingOperationStatus_kSuccess = "success"_sd;
constexpr StringData kReshardingOperationStatus_kFailure = "failure"_sd;
constexpr StringData kReshardingOperationStatus_kCanceled = "canceled"_sd;
constexpr StringData kReshardingOperationStatus_kRunning = "running"_sd;
constexpr StringData kReshardingOperationStatus_kInactive = "inactive"_sd;
}  // namespace 

ReshardingOperationStatusEnum ReshardingOperationStatus_parse(const IDLParserErrorContext& ctxt, StringData value) {
    if (value == kReshardingOperationStatus_kSuccess) {
        return ReshardingOperationStatusEnum::kSuccess;
    }
    if (value == kReshardingOperationStatus_kFailure) {
        return ReshardingOperationStatusEnum::kFailure;
    }
    if (value == kReshardingOperationStatus_kCanceled) {
        return ReshardingOperationStatusEnum::kCanceled;
    }
    if (value == kReshardingOperationStatus_kRunning) {
        return ReshardingOperationStatusEnum::kRunning;
    }
    if (value == kReshardingOperationStatus_kInactive) {
        return ReshardingOperationStatusEnum::kInactive;
    }
    ctxt.throwBadEnumValue(value);
}

StringData ReshardingOperationStatus_serializer(ReshardingOperationStatusEnum value) {
    if (value == ReshardingOperationStatusEnum::kSuccess) {
        return kReshardingOperationStatus_kSuccess;
    }
    if (value == ReshardingOperationStatusEnum::kFailure) {
        return kReshardingOperationStatus_kFailure;
    }
    if (value == ReshardingOperationStatusEnum::kCanceled) {
        return kReshardingOperationStatus_kCanceled;
    }
    if (value == ReshardingOperationStatusEnum::kRunning) {
        return kReshardingOperationStatus_kRunning;
    }
    if (value == ReshardingOperationStatusEnum::kInactive) {
        return kReshardingOperationStatus_kInactive;
    }
    MONGO_UNREACHABLE;
    return StringData();
}

constexpr StringData CommonReshardingMetadata::kReshardingKeyFieldName;
constexpr StringData CommonReshardingMetadata::kReshardingUUIDFieldName;
constexpr StringData CommonReshardingMetadata::kSourceNssFieldName;
constexpr StringData CommonReshardingMetadata::kSourceUUIDFieldName;
constexpr StringData CommonReshardingMetadata::kTempReshardingNssFieldName;


CommonReshardingMetadata::CommonReshardingMetadata() : _reshardingUUID(mongo::idl::preparsedValue<decltype(_reshardingUUID)>()), _sourceNss(mongo::idl::preparsedValue<decltype(_sourceNss)>()), _sourceUUID(mongo::idl::preparsedValue<decltype(_sourceUUID)>()), _tempReshardingNss(mongo::idl::preparsedValue<decltype(_tempReshardingNss)>()), _reshardingKey(mongo::idl::preparsedValue<decltype(_reshardingKey)>()), _hasReshardingUUID(false), _hasSourceNss(false), _hasSourceUUID(false), _hasTempReshardingNss(false), _hasReshardingKey(false) {
    // Used for initialization only
}
CommonReshardingMetadata::CommonReshardingMetadata(mongo::UUID reshardingUUID, mongo::NamespaceString sourceNss, mongo::UUID sourceUUID, mongo::NamespaceString tempReshardingNss, mongo::KeyPattern reshardingKey) : _reshardingUUID(std::move(reshardingUUID)), _sourceNss(std::move(sourceNss)), _sourceUUID(std::move(sourceUUID)), _tempReshardingNss(std::move(tempReshardingNss)), _reshardingKey(std::move(reshardingKey)), _hasReshardingUUID(true), _hasSourceNss(true), _hasSourceUUID(true), _hasTempReshardingNss(true), _hasReshardingKey(true) {
    // Used for initialization only
}


CommonReshardingMetadata CommonReshardingMetadata::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<CommonReshardingMetadata>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void CommonReshardingMetadata::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<5> usedFields;
    const size_t kReshardingUUIDBit = 0;
    const size_t kSourceNssBit = 1;
    const size_t kSourceUUIDBit = 2;
    const size_t kTempReshardingNssBit = 3;
    const size_t kReshardingKeyBit = 4;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kReshardingUUIDFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kReshardingUUIDBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kReshardingUUIDBit);

                _hasReshardingUUID = true;
                _reshardingUUID = UUID(uassertStatusOK(UUID::parse(element)));
            }
        }
        else if (fieldName == kSourceNssFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kSourceNssBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSourceNssBit);

                _hasSourceNss = true;
                _sourceNss = NamespaceString(element.valueStringData());
            }
        }
        else if (fieldName == kSourceUUIDFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kSourceUUIDBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSourceUUIDBit);

                _hasSourceUUID = true;
                _sourceUUID = UUID(uassertStatusOK(UUID::parse(element)));
            }
        }
        else if (fieldName == kTempReshardingNssFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kTempReshardingNssBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTempReshardingNssBit);

                _hasTempReshardingNss = true;
                _tempReshardingNss = NamespaceString(element.valueStringData());
            }
        }
        else if (fieldName == kReshardingKeyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kReshardingKeyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kReshardingKeyBit);

                _hasReshardingKey = true;
                const BSONObj localObject = element.Obj();
                _reshardingKey = KeyPattern::fromBSON(localObject);
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
    }

}


void CommonReshardingMetadata::serialize(BSONObjBuilder* builder) const {
    invariant(_hasReshardingUUID && _hasSourceNss && _hasSourceUUID && _hasTempReshardingNss && _hasReshardingKey);

    {
        ConstDataRange tempCDR = _reshardingUUID.toCDR();
        builder->append(kReshardingUUIDFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    {
        builder->append(kSourceNssFieldName, _sourceNss.toString());
    }

    {
        ConstDataRange tempCDR = _sourceUUID.toCDR();
        builder->append(kSourceUUIDFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    {
        builder->append(kTempReshardingNssFieldName, _tempReshardingNss.toString());
    }

    {
        const BSONObj localObject = _reshardingKey.toBSON();
        builder->append(kReshardingKeyFieldName, localObject);
    }

}


BSONObj CommonReshardingMetadata::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData AbortReason::kAbortReasonFieldName;


AbortReason::AbortReason()  {
    // Used for initialization only
}


AbortReason AbortReason::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<AbortReason>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void AbortReason::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kAbortReasonBit = 0;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kAbortReasonFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kAbortReasonBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAbortReasonBit);

                const BSONObj localObject = element.Obj();
                _abortReason = BSONObj::getOwned(localObject);
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


void AbortReason::serialize(BSONObjBuilder* builder) const {
    if (_abortReason.is_initialized()) {
        builder->append(kAbortReasonFieldName, _abortReason.get());
    }

}


BSONObj AbortReason::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData DonorShardContext::kAbortReasonStructFieldName;
constexpr StringData DonorShardContext::kAbortReasonFieldName;
constexpr StringData DonorShardContext::kBytesToCloneFieldName;
constexpr StringData DonorShardContext::kDocumentsToCloneFieldName;
constexpr StringData DonorShardContext::kMinFetchTimestampFieldName;
constexpr StringData DonorShardContext::kStateFieldName;


DonorShardContext::DonorShardContext()  {
    // Used for initialization only
}


DonorShardContext DonorShardContext::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<DonorShardContext>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void DonorShardContext::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<6> usedFields;
    const size_t kAbortReasonBit = 0;
    const size_t kStateBit = 1;
    const size_t kMinFetchTimestampBit = 2;
    const size_t kBytesToCloneBit = 3;
    const size_t kDocumentsToCloneBit = 4;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kAbortReasonFieldName) {
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

                IDLParserErrorContext tempContext(kStateFieldName, &ctxt);
                _state = DonorState_parse(tempContext, element.valueStringData());
            }
        }
        else if (fieldName == kMinFetchTimestampFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, bsonTimestamp))) {
                if (MONGO_unlikely(usedFields[kMinFetchTimestampBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMinFetchTimestampBit);

                _minFetchTimestamp = element.timestamp();
            }
        }
        else if (fieldName == kBytesToCloneFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kBytesToCloneBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kBytesToCloneBit);

                _bytesToClone = element._numberLong();
            }
        }
        else if (fieldName == kDocumentsToCloneFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kDocumentsToCloneBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDocumentsToCloneBit);

                _documentsToClone = element._numberLong();
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
        if (!usedFields[kStateBit]) {
            _state = mongo::DonorStateEnum::kUnused;
        }
    }

}


void DonorShardContext::serialize(BSONObjBuilder* builder) const {
    {
        _abortReasonStruct.serialize(builder);
    }

    {
        builder->append(kStateFieldName, ::mongo::DonorState_serializer(_state));
    }

    if (_minFetchTimestamp.is_initialized()) {
        builder->append(kMinFetchTimestampFieldName, _minFetchTimestamp.get());
    }

    if (_bytesToClone.is_initialized()) {
        builder->append(kBytesToCloneFieldName, _bytesToClone.get());
    }

    if (_documentsToClone.is_initialized()) {
        builder->append(kDocumentsToCloneFieldName, _documentsToClone.get());
    }

}


BSONObj DonorShardContext::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData DonorShardFetchTimestamp::kMinFetchTimestampFieldName;
constexpr StringData DonorShardFetchTimestamp::kShardIdFieldName;


DonorShardFetchTimestamp::DonorShardFetchTimestamp() : _shardId(mongo::idl::preparsedValue<decltype(_shardId)>()), _hasShardId(false) {
    // Used for initialization only
}
DonorShardFetchTimestamp::DonorShardFetchTimestamp(mongo::ShardId shardId) : _shardId(std::move(shardId)), _hasShardId(true) {
    // Used for initialization only
}


DonorShardFetchTimestamp DonorShardFetchTimestamp::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<DonorShardFetchTimestamp>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void DonorShardFetchTimestamp::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kShardIdBit = 0;
    const size_t kMinFetchTimestampBit = 1;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kShardIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kShardIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kShardIdBit);

                _hasShardId = true;
                _shardId = element.str();
            }
        }
        else if (fieldName == kMinFetchTimestampFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, bsonTimestamp))) {
                if (MONGO_unlikely(usedFields[kMinFetchTimestampBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMinFetchTimestampBit);

                _minFetchTimestamp = element.timestamp();
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
        if (!usedFields[kShardIdBit]) {
            ctxt.throwMissingField(kShardIdFieldName);
        }
    }

}


void DonorShardFetchTimestamp::serialize(BSONObjBuilder* builder) const {
    invariant(_hasShardId);

    {
        builder->append(kShardIdFieldName, _shardId.toString());
    }

    if (_minFetchTimestamp.is_initialized()) {
        builder->append(kMinFetchTimestampFieldName, _minFetchTimestamp.get());
    }

}


BSONObj DonorShardFetchTimestamp::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData RecipientShardContext::kAbortReasonStructFieldName;
constexpr StringData RecipientShardContext::kAbortReasonFieldName;
constexpr StringData RecipientShardContext::kStateFieldName;


RecipientShardContext::RecipientShardContext()  {
    // Used for initialization only
}


RecipientShardContext RecipientShardContext::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<RecipientShardContext>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void RecipientShardContext::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<3> usedFields;
    const size_t kAbortReasonBit = 0;
    const size_t kStateBit = 1;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kAbortReasonFieldName) {
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

                IDLParserErrorContext tempContext(kStateFieldName, &ctxt);
                _state = RecipientState_parse(tempContext, element.valueStringData());
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
        if (!usedFields[kStateBit]) {
            _state = mongo::RecipientStateEnum::kUnused;
        }
    }

}


void RecipientShardContext::serialize(BSONObjBuilder* builder) const {
    {
        _abortReasonStruct.serialize(builder);
    }

    {
        builder->append(kStateFieldName, ::mongo::RecipientState_serializer(_state));
    }

}


BSONObj RecipientShardContext::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData ReshardingApproxCopySize::kApproxBytesToCopyFieldName;
constexpr StringData ReshardingApproxCopySize::kApproxDocumentsToCopyFieldName;


ReshardingApproxCopySize::ReshardingApproxCopySize()  {
    // Used for initialization only
}


ReshardingApproxCopySize ReshardingApproxCopySize::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ReshardingApproxCopySize>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ReshardingApproxCopySize::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kApproxDocumentsToCopyBit = 0;
    const size_t kApproxBytesToCopyBit = 1;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kApproxDocumentsToCopyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kApproxDocumentsToCopyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kApproxDocumentsToCopyBit);

                _approxDocumentsToCopy = element._numberLong();
            }
        }
        else if (fieldName == kApproxBytesToCopyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kApproxBytesToCopyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kApproxBytesToCopyBit);

                _approxBytesToCopy = element._numberLong();
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


void ReshardingApproxCopySize::serialize(BSONObjBuilder* builder) const {
    if (_approxDocumentsToCopy.is_initialized()) {
        builder->append(kApproxDocumentsToCopyFieldName, _approxDocumentsToCopy.get());
    }

    if (_approxBytesToCopy.is_initialized()) {
        builder->append(kApproxBytesToCopyFieldName, _approxBytesToCopy.get());
    }

}


BSONObj ReshardingApproxCopySize::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData ReshardingSourceId::kReshardingUUIDFieldName;
constexpr StringData ReshardingSourceId::kShardIdFieldName;


ReshardingSourceId::ReshardingSourceId() : _reshardingUUID(mongo::idl::preparsedValue<decltype(_reshardingUUID)>()), _shardId(mongo::idl::preparsedValue<decltype(_shardId)>()), _hasReshardingUUID(false), _hasShardId(false) {
    // Used for initialization only
}
ReshardingSourceId::ReshardingSourceId(mongo::UUID reshardingUUID, mongo::ShardId shardId) : _reshardingUUID(std::move(reshardingUUID)), _shardId(std::move(shardId)), _hasReshardingUUID(true), _hasShardId(true) {
    // Used for initialization only
}


ReshardingSourceId ReshardingSourceId::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ReshardingSourceId>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ReshardingSourceId::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kReshardingUUIDBit = 0;
    const size_t kShardIdBit = 1;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kReshardingUUIDFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kReshardingUUIDBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kReshardingUUIDBit);

                _hasReshardingUUID = true;
                _reshardingUUID = UUID(uassertStatusOK(UUID::parse(element)));
            }
        }
        else if (fieldName == kShardIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kShardIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kShardIdBit);

                _hasShardId = true;
                _shardId = element.str();
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kReshardingUUIDBit]) {
            ctxt.throwMissingField(kReshardingUUIDFieldName);
        }
        if (!usedFields[kShardIdBit]) {
            ctxt.throwMissingField(kShardIdFieldName);
        }
    }

}


void ReshardingSourceId::serialize(BSONObjBuilder* builder) const {
    invariant(_hasReshardingUUID && _hasShardId);

    {
        ConstDataRange tempCDR = _reshardingUUID.toCDR();
        builder->append(kReshardingUUIDFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    {
        builder->append(kShardIdFieldName, _shardId.toString());
    }

}


BSONObj ReshardingSourceId::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData ReshardingZoneType::kMaxFieldName;
constexpr StringData ReshardingZoneType::kMinFieldName;
constexpr StringData ReshardingZoneType::kZoneFieldName;


ReshardingZoneType::ReshardingZoneType() : _zone(mongo::idl::preparsedValue<decltype(_zone)>()), _min(mongo::idl::preparsedValue<decltype(_min)>()), _max(mongo::idl::preparsedValue<decltype(_max)>()), _hasZone(false), _hasMin(false), _hasMax(false) {
    // Used for initialization only
}
ReshardingZoneType::ReshardingZoneType(std::string zone, mongo::BSONObj min, mongo::BSONObj max) : _zone(std::move(zone)), _min(std::move(min)), _max(std::move(max)), _hasZone(true), _hasMin(true), _hasMax(true) {
    // Used for initialization only
}


ReshardingZoneType ReshardingZoneType::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ReshardingZoneType>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ReshardingZoneType::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<3> usedFields;
    const size_t kZoneBit = 0;
    const size_t kMinBit = 1;
    const size_t kMaxBit = 2;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kZoneFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kZoneBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kZoneBit);

                _hasZone = true;
                _zone = element.str();
            }
        }
        else if (fieldName == kMinFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kMinBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMinBit);

                _hasMin = true;
                const BSONObj localObject = element.Obj();
                _min = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kMaxFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kMaxBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMaxBit);

                _hasMax = true;
                const BSONObj localObject = element.Obj();
                _max = BSONObj::getOwned(localObject);
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
        if (!usedFields[kZoneBit]) {
            ctxt.throwMissingField(kZoneFieldName);
        }
        if (!usedFields[kMinBit]) {
            ctxt.throwMissingField(kMinFieldName);
        }
        if (!usedFields[kMaxBit]) {
            ctxt.throwMissingField(kMaxFieldName);
        }
    }

}


void ReshardingZoneType::serialize(BSONObjBuilder* builder) const {
    invariant(_hasZone && _hasMin && _hasMax);

    builder->append(kZoneFieldName, _zone);

    builder->append(kMinFieldName, _min);

    builder->append(kMaxFieldName, _max);

}


BSONObj ReshardingZoneType::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData ReshardedChunk::kMaxFieldName;
constexpr StringData ReshardedChunk::kMinFieldName;
constexpr StringData ReshardedChunk::kRecipientShardIdFieldName;


ReshardedChunk::ReshardedChunk() : _recipientShardId(mongo::idl::preparsedValue<decltype(_recipientShardId)>()), _min(mongo::idl::preparsedValue<decltype(_min)>()), _max(mongo::idl::preparsedValue<decltype(_max)>()), _hasRecipientShardId(false), _hasMin(false), _hasMax(false) {
    // Used for initialization only
}
ReshardedChunk::ReshardedChunk(mongo::ShardId recipientShardId, mongo::BSONObj min, mongo::BSONObj max) : _recipientShardId(std::move(recipientShardId)), _min(std::move(min)), _max(std::move(max)), _hasRecipientShardId(true), _hasMin(true), _hasMax(true) {
    // Used for initialization only
}


ReshardedChunk ReshardedChunk::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ReshardedChunk>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ReshardedChunk::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<3> usedFields;
    const size_t kRecipientShardIdBit = 0;
    const size_t kMinBit = 1;
    const size_t kMaxBit = 2;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kRecipientShardIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kRecipientShardIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRecipientShardIdBit);

                _hasRecipientShardId = true;
                _recipientShardId = element.str();
            }
        }
        else if (fieldName == kMinFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kMinBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMinBit);

                _hasMin = true;
                const BSONObj localObject = element.Obj();
                _min = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kMaxFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kMaxBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMaxBit);

                _hasMax = true;
                const BSONObj localObject = element.Obj();
                _max = BSONObj::getOwned(localObject);
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kRecipientShardIdBit]) {
            ctxt.throwMissingField(kRecipientShardIdFieldName);
        }
        if (!usedFields[kMinBit]) {
            ctxt.throwMissingField(kMinFieldName);
        }
        if (!usedFields[kMaxBit]) {
            ctxt.throwMissingField(kMaxFieldName);
        }
    }

}


void ReshardedChunk::serialize(BSONObjBuilder* builder) const {
    invariant(_hasRecipientShardId && _hasMin && _hasMax);

    {
        builder->append(kRecipientShardIdFieldName, _recipientShardId.toString());
    }

    builder->append(kMinFieldName, _min);

    builder->append(kMaxFieldName, _max);

}


BSONObj ReshardedChunk::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData ReshardingMetricsTimeInterval::kStartFieldName;
constexpr StringData ReshardingMetricsTimeInterval::kStopFieldName;


ReshardingMetricsTimeInterval::ReshardingMetricsTimeInterval()  {
    // Used for initialization only
}


ReshardingMetricsTimeInterval ReshardingMetricsTimeInterval::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ReshardingMetricsTimeInterval>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ReshardingMetricsTimeInterval::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kStartBit = 0;
    const size_t kStopBit = 1;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kStartFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Date))) {
                if (MONGO_unlikely(usedFields[kStartBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStartBit);

                _start = element.date();
            }
        }
        else if (fieldName == kStopFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Date))) {
                if (MONGO_unlikely(usedFields[kStopBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStopBit);

                _stop = element.date();
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


void ReshardingMetricsTimeInterval::serialize(BSONObjBuilder* builder) const {
    if (_start.is_initialized()) {
        builder->append(kStartFieldName, _start.get());
    }

    if (_stop.is_initialized()) {
        builder->append(kStopFieldName, _stop.get());
    }

}


BSONObj ReshardingMetricsTimeInterval::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData DocumentSourceReshardingOwnershipMatchSpec::kRecipientShardIdFieldName;
constexpr StringData DocumentSourceReshardingOwnershipMatchSpec::kReshardingKeyFieldName;


DocumentSourceReshardingOwnershipMatchSpec::DocumentSourceReshardingOwnershipMatchSpec() : _recipientShardId(mongo::idl::preparsedValue<decltype(_recipientShardId)>()), _reshardingKey(mongo::idl::preparsedValue<decltype(_reshardingKey)>()), _hasRecipientShardId(false), _hasReshardingKey(false) {
    // Used for initialization only
}
DocumentSourceReshardingOwnershipMatchSpec::DocumentSourceReshardingOwnershipMatchSpec(mongo::ShardId recipientShardId, mongo::KeyPattern reshardingKey) : _recipientShardId(std::move(recipientShardId)), _reshardingKey(std::move(reshardingKey)), _hasRecipientShardId(true), _hasReshardingKey(true) {
    // Used for initialization only
}


DocumentSourceReshardingOwnershipMatchSpec DocumentSourceReshardingOwnershipMatchSpec::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<DocumentSourceReshardingOwnershipMatchSpec>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void DocumentSourceReshardingOwnershipMatchSpec::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kRecipientShardIdBit = 0;
    const size_t kReshardingKeyBit = 1;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kRecipientShardIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kRecipientShardIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRecipientShardIdBit);

                _hasRecipientShardId = true;
                _recipientShardId = element.str();
            }
        }
        else if (fieldName == kReshardingKeyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kReshardingKeyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kReshardingKeyBit);

                _hasReshardingKey = true;
                const BSONObj localObject = element.Obj();
                _reshardingKey = KeyPattern::fromBSON(localObject);
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kRecipientShardIdBit]) {
            ctxt.throwMissingField(kRecipientShardIdFieldName);
        }
        if (!usedFields[kReshardingKeyBit]) {
            ctxt.throwMissingField(kReshardingKeyFieldName);
        }
    }

}


void DocumentSourceReshardingOwnershipMatchSpec::serialize(BSONObjBuilder* builder) const {
    invariant(_hasRecipientShardId && _hasReshardingKey);

    {
        builder->append(kRecipientShardIdFieldName, _recipientShardId.toString());
    }

    {
        const BSONObj localObject = _reshardingKey.toBSON();
        builder->append(kReshardingKeyFieldName, localObject);
    }

}


BSONObj DocumentSourceReshardingOwnershipMatchSpec::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
