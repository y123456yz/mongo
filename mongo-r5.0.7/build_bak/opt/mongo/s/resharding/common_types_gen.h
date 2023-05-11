/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/s/resharding/common_types_gen.h --output build/opt/mongo/s/resharding/common_types_gen.cpp src/mongo/s/resharding/common_types.idl
 */

#pragma once

#include <algorithm>
#include <boost/optional.hpp>
#include <cstdint>
#include <string>
#include <tuple>
#include <vector>

#include "mongo/base/data_range.h"
#include "mongo/base/string_data.h"
#include "mongo/bson/bsonobj.h"
#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/bson/simple_bsonobj_comparator.h"
#include "mongo/db/keypattern.h"
#include "mongo/db/namespace_string.h"
#include "mongo/idl/basic_types.h"
#include "mongo/idl/basic_types_gen.h"
#include "mongo/idl/idl_parser.h"
#include "mongo/rpc/op_msg.h"
#include "mongo/s/shard_id.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/util/uuid.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {

/**
 * The current state of a resharding operation on the coordinator.
 */
enum class CoordinatorStateEnum : std::int32_t {
    kUnused ,
    kInitializing ,
    kPreparingToDonate ,
    kCloning ,
    kApplying ,
    kBlockingWrites ,
    kAborting ,
    kCommitting ,
    kDone ,
};
static constexpr uint32_t kNumCoordinatorStateEnum = 9;

CoordinatorStateEnum CoordinatorState_parse(const IDLParserErrorContext& ctxt, StringData value);
StringData CoordinatorState_serializer(CoordinatorStateEnum value);

/**
 * The current state of a donor shard for a resharding operation.
 */
enum class DonorStateEnum : std::int32_t {
    kUnused ,
    kPreparingToDonate ,
    kDonatingInitialData ,
    kDonatingOplogEntries ,
    kPreparingToBlockWrites ,
    kError ,
    kBlockingWrites ,
    kDone ,
};
static constexpr uint32_t kNumDonorStateEnum = 8;

DonorStateEnum DonorState_parse(const IDLParserErrorContext& ctxt, StringData value);
StringData DonorState_serializer(DonorStateEnum value);

/**
 * The current state of a recipient shard for a resharding operation.
 */
enum class RecipientStateEnum : std::int32_t {
    kUnused ,
    kAwaitingFetchTimestamp ,
    kCreatingCollection ,
    kCloning ,
    kApplying ,
    kError ,
    kStrictConsistency ,
    kDone ,
};
static constexpr uint32_t kNumRecipientStateEnum = 8;

RecipientStateEnum RecipientState_parse(const IDLParserErrorContext& ctxt, StringData value);
StringData RecipientState_serializer(RecipientStateEnum value);

/**
 * The status of the current or most recent resharding operation.
 */
enum class ReshardingOperationStatusEnum : std::int32_t {
    kSuccess ,
    kFailure ,
    kCanceled ,
    kRunning ,
    kInactive ,
};
static constexpr uint32_t kNumReshardingOperationStatusEnum = 5;

ReshardingOperationStatusEnum ReshardingOperationStatus_parse(const IDLParserErrorContext& ctxt, StringData value);
StringData ReshardingOperationStatus_serializer(ReshardingOperationStatusEnum value);

/**
 * Immutable metadata shared across all node types for a resharding operation.
 */
class CommonReshardingMetadata {
public:
    static constexpr auto kReshardingKeyFieldName = "reshardingKey"_sd;
    static constexpr auto kReshardingUUIDFieldName = "_id"_sd;
    static constexpr auto kSourceNssFieldName = "ns"_sd;
    static constexpr auto kSourceUUIDFieldName = "ui"_sd;
    static constexpr auto kTempReshardingNssFieldName = "tempNs"_sd;

    CommonReshardingMetadata();
    CommonReshardingMetadata(mongo::UUID reshardingUUID, mongo::NamespaceString sourceNss, mongo::UUID sourceUUID, mongo::NamespaceString tempReshardingNss, mongo::KeyPattern reshardingKey);

    static CommonReshardingMetadata parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * A unique identifier for the resharding operation.
     */
    const mongo::UUID& getReshardingUUID() const { return _reshardingUUID; }
    void setReshardingUUID(mongo::UUID value) & {  _reshardingUUID = std::move(value); _hasReshardingUUID = true; }

    /**
     * The namespace of the collection being resharded.
     */
    const mongo::NamespaceString& getSourceNss() const { return _sourceNss; }
    void setSourceNss(mongo::NamespaceString value) & {  _sourceNss = std::move(value); _hasSourceNss = true; }

    /**
     * The UUID of the original collection being resharded.
     */
    const mongo::UUID& getSourceUUID() const { return _sourceUUID; }
    void setSourceUUID(mongo::UUID value) & {  _sourceUUID = std::move(value); _hasSourceUUID = true; }

    /**
     * The namespace of the temporary resharding collection that exists on recipient shards.
     */
    const mongo::NamespaceString& getTempReshardingNss() const { return _tempReshardingNss; }
    void setTempReshardingNss(mongo::NamespaceString value) & {  _tempReshardingNss = std::move(value); _hasTempReshardingNss = true; }

    /**
     * The index specification document to use as the new shard key.
     */
    const mongo::KeyPattern& getReshardingKey() const { return _reshardingKey; }
    void setReshardingKey(mongo::KeyPattern value) & {  _reshardingKey = std::move(value); _hasReshardingKey = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::UUID _reshardingUUID;
    mongo::NamespaceString _sourceNss;
    mongo::UUID _sourceUUID;
    mongo::NamespaceString _tempReshardingNss;
    mongo::KeyPattern _reshardingKey;
    bool _hasReshardingUUID : 1;
    bool _hasSourceNss : 1;
    bool _hasSourceUUID : 1;
    bool _hasTempReshardingNss : 1;
    bool _hasReshardingKey : 1;
};

/**
 * Not meant to be used directly. Only use internal fields.
 */
class AbortReason {
public:
    static constexpr auto kAbortReasonFieldName = "abortReason"_sd;

    AbortReason();

    static AbortReason parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * The error that caused the node to abort the resharding operation. In this case, the node may be a donor shard, recipient shard, or the coordinator itself.
     */
    const boost::optional<mongo::BSONObj>& getAbortReason() const& { return _abortReason; }
    void getAbortReason() && = delete;
    void setAbortReason(boost::optional<mongo::BSONObj> value) & {  _abortReason = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    boost::optional<mongo::BSONObj> _abortReason;
};

/**
 * Mutable state for a donor shard tracked both locally by a donor shard and remotely by the resharding coordinator.
 */
class DonorShardContext {
public:
    static constexpr auto kAbortReasonStructFieldName = "AbortReason"_sd;
    static constexpr auto kAbortReasonFieldName = "abortReason"_sd;
    static constexpr auto kBytesToCloneFieldName = "bytesToClone"_sd;
    static constexpr auto kDocumentsToCloneFieldName = "documentsToClone"_sd;
    static constexpr auto kMinFetchTimestampFieldName = "minFetchTimestamp"_sd;
    static constexpr auto kStateFieldName = "state"_sd;

    DonorShardContext();

    static DonorShardContext parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Not meant to be used directly. Only use internal fields.
     */
    const mongo::AbortReason& getAbortReasonStruct() const { return _abortReasonStruct; }
    mongo::AbortReason& getAbortReasonStruct() { return _abortReasonStruct; }
    void setAbortReasonStruct(mongo::AbortReason value) & {  _abortReasonStruct = std::move(value);  }

    /**
     * The error that caused the node to abort the resharding operation. In this case, the node may be a donor shard, recipient shard, or the coordinator itself.
     */
    const  boost::optional<mongo::BSONObj>& getAbortReason() const { return _abortReasonStruct.getAbortReason(); }
    mongo::DonorStateEnum getState() const { return _state; }
    void setState(mongo::DonorStateEnum value) & {  _state = std::move(value);  }

    /**
     * Timestamp after which this donor shard has guaranteed that oplog entries contain recipient shard information.
     */
    const boost::optional<mongo::Timestamp>& getMinFetchTimestamp() const& { return _minFetchTimestamp; }
    void getMinFetchTimestamp() && = delete;
    void setMinFetchTimestamp(boost::optional<mongo::Timestamp> value) & {  _minFetchTimestamp = std::move(value);  }

    /**
     * Number of bytes on this donor shard in the collection being resharded.
     */
    const boost::optional<std::int64_t> getBytesToClone() const& { return _bytesToClone; }
    void getBytesToClone() && = delete;
    void setBytesToClone(boost::optional<std::int64_t> value) & {  _bytesToClone = std::move(value);  }

    /**
     * Number of documents on this donor shard in the collection being resharded.
     */
    const boost::optional<std::int64_t> getDocumentsToClone() const& { return _documentsToClone; }
    void getDocumentsToClone() && = delete;
    void setDocumentsToClone(boost::optional<std::int64_t> value) & {  _documentsToClone = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::AbortReason _abortReasonStruct;
    mongo::DonorStateEnum _state{mongo::DonorStateEnum::kUnused};
    boost::optional<mongo::Timestamp> _minFetchTimestamp;
    boost::optional<std::int64_t> _bytesToClone;
    boost::optional<std::int64_t> _documentsToClone;
};

/**
 * Used for tracking donor min fetch timestamp
 */
class DonorShardFetchTimestamp {
public:
    static constexpr auto kMinFetchTimestampFieldName = "minFetchTimestamp"_sd;
    static constexpr auto kShardIdFieldName = "shardId"_sd;

    DonorShardFetchTimestamp();
    DonorShardFetchTimestamp(mongo::ShardId shardId);

    static DonorShardFetchTimestamp parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * A shard identifier.
     */
    const mongo::ShardId& getShardId() const { return _shardId; }
    void setShardId(mongo::ShardId value) & {  _shardId = std::move(value); _hasShardId = true; }

    /**
     * Timestamp after which this donor shard has guaranteed that oplog entries contain recipient shard information.
     */
    const boost::optional<mongo::Timestamp>& getMinFetchTimestamp() const& { return _minFetchTimestamp; }
    void getMinFetchTimestamp() && = delete;
    void setMinFetchTimestamp(boost::optional<mongo::Timestamp> value) & {  _minFetchTimestamp = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::ShardId _shardId;
    boost::optional<mongo::Timestamp> _minFetchTimestamp;
    bool _hasShardId : 1;
};

/**
 * Mutable state for a recipient shard tracked both locally by a recipient shard and remotely by the resharding coordinator.
 */
class RecipientShardContext {
public:
    static constexpr auto kAbortReasonStructFieldName = "AbortReason"_sd;
    static constexpr auto kAbortReasonFieldName = "abortReason"_sd;
    static constexpr auto kStateFieldName = "state"_sd;

    RecipientShardContext();

    static RecipientShardContext parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Not meant to be used directly. Only use internal fields.
     */
    const mongo::AbortReason& getAbortReasonStruct() const { return _abortReasonStruct; }
    mongo::AbortReason& getAbortReasonStruct() { return _abortReasonStruct; }
    void setAbortReasonStruct(mongo::AbortReason value) & {  _abortReasonStruct = std::move(value);  }

    /**
     * The error that caused the node to abort the resharding operation. In this case, the node may be a donor shard, recipient shard, or the coordinator itself.
     */
    const  boost::optional<mongo::BSONObj>& getAbortReason() const { return _abortReasonStruct.getAbortReason(); }
    mongo::RecipientStateEnum getState() const { return _state; }
    void setState(mongo::RecipientStateEnum value) & {  _state = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::AbortReason _abortReasonStruct;
    mongo::RecipientStateEnum _state{mongo::RecipientStateEnum::kUnused};
};

/**
 * Not meant to be used directly. Only use internal fields.
 */
class ReshardingApproxCopySize {
public:
    static constexpr auto kApproxBytesToCopyFieldName = "approxBytesToCopy"_sd;
    static constexpr auto kApproxDocumentsToCopyFieldName = "approxDocumentsToCopy"_sd;

    ReshardingApproxCopySize();

    static ReshardingApproxCopySize parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    const boost::optional<std::int64_t> getApproxDocumentsToCopy() const& { return _approxDocumentsToCopy; }
    void getApproxDocumentsToCopy() && = delete;
    void setApproxDocumentsToCopy(boost::optional<std::int64_t> value) & {  _approxDocumentsToCopy = std::move(value);  }

    const boost::optional<std::int64_t> getApproxBytesToCopy() const& { return _approxBytesToCopy; }
    void getApproxBytesToCopy() && = delete;
    void setApproxBytesToCopy(boost::optional<std::int64_t> value) & {  _approxBytesToCopy = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    boost::optional<std::int64_t> _approxDocumentsToCopy;
    boost::optional<std::int64_t> _approxBytesToCopy;
};

/**
 * Identifier for a shard involved in a particular resharding operation.
 */
class ReshardingSourceId {
public:
    static constexpr auto kReshardingUUIDFieldName = "reshardingUUID"_sd;
    static constexpr auto kShardIdFieldName = "shardId"_sd;

    ReshardingSourceId();
    ReshardingSourceId(mongo::UUID reshardingUUID, mongo::ShardId shardId);

    static ReshardingSourceId parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Identifier for a resharding operation.
     */
    const mongo::UUID& getReshardingUUID() const { return _reshardingUUID; }
    void setReshardingUUID(mongo::UUID value) & {  _reshardingUUID = std::move(value); _hasReshardingUUID = true; }

    /**
     * A shard identifier.
     */
    const mongo::ShardId& getShardId() const { return _shardId; }
    void setShardId(mongo::ShardId value) & {  _shardId = std::move(value); _hasShardId = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::UUID _reshardingUUID;
    mongo::ShardId _shardId;
    bool _hasReshardingUUID : 1;
    bool _hasShardId : 1;
};

/**
 * Object describing a zone for the collection being resharded using the new shard key.
 */
class ReshardingZoneType {
public:
    static constexpr auto kMaxFieldName = "max"_sd;
    static constexpr auto kMinFieldName = "min"_sd;
    static constexpr auto kZoneFieldName = "zone"_sd;

    ReshardingZoneType();
    ReshardingZoneType(std::string zone, mongo::BSONObj min, mongo::BSONObj max);

    static ReshardingZoneType parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * The zone name.
     */
    const StringData getZone() const& { return _zone; }
    void getZone() && = delete;
    void setZone(StringData value) & { auto _tmpValue = value.toString();  _zone = std::move(_tmpValue); _hasZone = true; }

    /**
     * The min key of the chunk range assigned to the zone.
     */
    const mongo::BSONObj& getMin() const { return _min; }
    void setMin(mongo::BSONObj value) & {  _min = std::move(value); _hasMin = true; }

    /**
     * The max key of the chunk range assigned to the zone.
     */
    const mongo::BSONObj& getMax() const { return _max; }
    void setMax(mongo::BSONObj value) & {  _max = std::move(value); _hasMax = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    std::string _zone;
    mongo::BSONObj _min;
    mongo::BSONObj _max;
    bool _hasZone : 1;
    bool _hasMin : 1;
    bool _hasMax : 1;
};

/**
 * ReshardedChunk
 */
class ReshardedChunk {
public:
    static constexpr auto kMaxFieldName = "max"_sd;
    static constexpr auto kMinFieldName = "min"_sd;
    static constexpr auto kRecipientShardIdFieldName = "recipientShardId"_sd;

    ReshardedChunk();
    ReshardedChunk(mongo::ShardId recipientShardId, mongo::BSONObj min, mongo::BSONObj max);

    static ReshardedChunk parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * The id of the recipient shard.
     */
    const mongo::ShardId& getRecipientShardId() const { return _recipientShardId; }
    void setRecipientShardId(mongo::ShardId value) & {  _recipientShardId = std::move(value); _hasRecipientShardId = true; }

    /**
     * The min key of the chunk range.
     */
    const mongo::BSONObj& getMin() const { return _min; }
    void setMin(mongo::BSONObj value) & {  _min = std::move(value); _hasMin = true; }

    /**
     * The max key of the chunk range.
     */
    const mongo::BSONObj& getMax() const { return _max; }
    void setMax(mongo::BSONObj value) & {  _max = std::move(value); _hasMax = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::ShardId _recipientShardId;
    mongo::BSONObj _min;
    mongo::BSONObj _max;
    bool _hasRecipientShardId : 1;
    bool _hasMin : 1;
    bool _hasMax : 1;
};

/**
 * Contains the start and stop time of a resharding operation phase.
 */
class ReshardingMetricsTimeInterval {
public:
    static constexpr auto kStartFieldName = "start"_sd;
    static constexpr auto kStopFieldName = "stop"_sd;

    ReshardingMetricsTimeInterval();

    static ReshardingMetricsTimeInterval parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * The start timestamp.
     */
    const boost::optional<mongo::Date_t>& getStart() const& { return _start; }
    void getStart() && = delete;
    void setStart(boost::optional<mongo::Date_t> value) & {  _start = std::move(value);  }

    /**
     * The stop timestamp.
     */
    const boost::optional<mongo::Date_t>& getStop() const& { return _stop; }
    void getStop() && = delete;
    void setStop(boost::optional<mongo::Date_t> value) & {  _stop = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    boost::optional<mongo::Date_t> _start;
    boost::optional<mongo::Date_t> _stop;
};

/**
 * A struct representing the information needed for a resharding pipeline to determine which documents belong to a particular shard.
 */
class DocumentSourceReshardingOwnershipMatchSpec {
public:
    static constexpr auto kRecipientShardIdFieldName = "recipientShardId"_sd;
    static constexpr auto kReshardingKeyFieldName = "reshardingKey"_sd;

    DocumentSourceReshardingOwnershipMatchSpec();
    DocumentSourceReshardingOwnershipMatchSpec(mongo::ShardId recipientShardId, mongo::KeyPattern reshardingKey);

    static DocumentSourceReshardingOwnershipMatchSpec parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * The id of the recipient shard.
     */
    const mongo::ShardId& getRecipientShardId() const { return _recipientShardId; }
    void setRecipientShardId(mongo::ShardId value) & {  _recipientShardId = std::move(value); _hasRecipientShardId = true; }

    /**
     * The index specification document to use as the new shard key.
     */
    const mongo::KeyPattern& getReshardingKey() const { return _reshardingKey; }
    void setReshardingKey(mongo::KeyPattern value) & {  _reshardingKey = std::move(value); _hasReshardingKey = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::ShardId _recipientShardId;
    mongo::KeyPattern _reshardingKey;
    bool _hasRecipientShardId : 1;
    bool _hasReshardingKey : 1;
};

}  // namespace mongo
