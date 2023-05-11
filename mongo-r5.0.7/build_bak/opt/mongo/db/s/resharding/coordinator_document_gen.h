/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/s/resharding/coordinator_document_gen.h --output build/opt/mongo/db/s/resharding/coordinator_document_gen.cpp src/mongo/db/s/resharding/coordinator_document.idl
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
#include "mongo/idl/idl_parser.h"
#include "mongo/rpc/op_msg.h"
#include "mongo/s/resharding/common_types_gen.h"
#include "mongo/s/shard_id.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/util/uuid.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {

/**
 * Represents a donor shard for a particular resharding operation on the coordinator.
 */
class DonorShardEntry {
public:
    static constexpr auto kIdFieldName = "id"_sd;
    static constexpr auto kMutableStateFieldName = "mutableState"_sd;

    DonorShardEntry();
    DonorShardEntry(mongo::ShardId id, mongo::DonorShardContext mutableState);

    static DonorShardEntry parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    const mongo::ShardId& getId() const { return _id; }
    void setId(mongo::ShardId value) & {  _id = std::move(value); _hasId = true; }

    const mongo::DonorShardContext& getMutableState() const { return _mutableState; }
    mongo::DonorShardContext& getMutableState() { return _mutableState; }
    void setMutableState(mongo::DonorShardContext value) & {  _mutableState = std::move(value); _hasMutableState = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::ShardId _id;
    mongo::DonorShardContext _mutableState;
    bool _hasId : 1;
    bool _hasMutableState : 1;
};

/**
 * Represents a recipient shard for a particular resharding operation on the coordinator.
 */
class RecipientShardEntry {
public:
    static constexpr auto kIdFieldName = "id"_sd;
    static constexpr auto kMutableStateFieldName = "mutableState"_sd;

    RecipientShardEntry();
    RecipientShardEntry(mongo::ShardId id, mongo::RecipientShardContext mutableState);

    static RecipientShardEntry parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    const mongo::ShardId& getId() const { return _id; }
    void setId(mongo::ShardId value) & {  _id = std::move(value); _hasId = true; }

    const mongo::RecipientShardContext& getMutableState() const { return _mutableState; }
    mongo::RecipientShardContext& getMutableState() { return _mutableState; }
    void setMutableState(mongo::RecipientShardContext value) & {  _mutableState = std::move(value); _hasMutableState = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::ShardId _id;
    mongo::RecipientShardContext _mutableState;
    bool _hasId : 1;
    bool _hasMutableState : 1;
};

/**
 * Contains metrics about the resharding operation on the coordinator.
 */
class ReshardingCoordinatorMetrics {
public:
    static constexpr auto kOperationRuntimeFieldName = "operationRuntime"_sd;

    ReshardingCoordinatorMetrics();

    static ReshardingCoordinatorMetrics parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * The time interval of the entire resharding operation on the coordinator.
     */
    const boost::optional<mongo::ReshardingMetricsTimeInterval>& getOperationRuntime() const& { return _operationRuntime; }
    void getOperationRuntime() && = delete;
    void setOperationRuntime(boost::optional<mongo::ReshardingMetricsTimeInterval> value) & {  _operationRuntime = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    boost::optional<mongo::ReshardingMetricsTimeInterval> _operationRuntime;
};

/**
 * Represents a resharding operation on the coordinator.
 */
class ReshardingCoordinatorDocument {
public:
    static constexpr auto kAbortReasonStructFieldName = "AbortReason"_sd;
    static constexpr auto kCommonReshardingMetadataFieldName = "CommonReshardingMetadata"_sd;
    static constexpr auto kReshardingApproxCopySizeStructFieldName = "ReshardingApproxCopySize"_sd;
    static constexpr auto kAbortReasonFieldName = "abortReason"_sd;
    static constexpr auto kActiveFieldName = "active"_sd;
    static constexpr auto kApproxBytesToCopyFieldName = "approxBytesToCopy"_sd;
    static constexpr auto kApproxDocumentsToCopyFieldName = "approxDocumentsToCopy"_sd;
    static constexpr auto kCloneTimestampFieldName = "cloneTimestamp"_sd;
    static constexpr auto kDonorShardsFieldName = "donorShards"_sd;
    static constexpr auto kMetricsFieldName = "metrics"_sd;
    static constexpr auto kNumInitialChunksFieldName = "numInitialChunks"_sd;
    static constexpr auto kPresetReshardedChunksFieldName = "presetReshardedChunks"_sd;
    static constexpr auto kRecipientShardsFieldName = "recipientShards"_sd;
    static constexpr auto kReshardingKeyFieldName = "reshardingKey"_sd;
    static constexpr auto kReshardingUUIDFieldName = "_id"_sd;
    static constexpr auto kSourceNssFieldName = "ns"_sd;
    static constexpr auto kSourceUUIDFieldName = "ui"_sd;
    static constexpr auto kStateFieldName = "state"_sd;
    static constexpr auto kTempReshardingNssFieldName = "tempNs"_sd;
    static constexpr auto kZonesFieldName = "zones"_sd;

    ReshardingCoordinatorDocument();
    ReshardingCoordinatorDocument(mongo::CoordinatorStateEnum state, std::vector<mongo::DonorShardEntry> donorShards, std::vector<mongo::RecipientShardEntry> recipientShards);

    static ReshardingCoordinatorDocument parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Immutable metadata shared across all node types for a resharding operation.
     */
    const mongo::CommonReshardingMetadata& getCommonReshardingMetadata() const { return _commonReshardingMetadata; }
    mongo::CommonReshardingMetadata& getCommonReshardingMetadata() { return _commonReshardingMetadata; }
    void setCommonReshardingMetadata(mongo::CommonReshardingMetadata value) & {  _commonReshardingMetadata = std::move(value);  }

    /**
     * A unique identifier for the resharding operation.
     */
    const  mongo::UUID& getReshardingUUID() const { return _commonReshardingMetadata.getReshardingUUID(); }
    /**
     * The namespace of the collection being resharded.
     */
    const  mongo::NamespaceString& getSourceNss() const { return _commonReshardingMetadata.getSourceNss(); }
    /**
     * The UUID of the original collection being resharded.
     */
    const  mongo::UUID& getSourceUUID() const { return _commonReshardingMetadata.getSourceUUID(); }
    /**
     * The namespace of the temporary resharding collection that exists on recipient shards.
     */
    const  mongo::NamespaceString& getTempReshardingNss() const { return _commonReshardingMetadata.getTempReshardingNss(); }
    /**
     * The index specification document to use as the new shard key.
     */
    const  mongo::KeyPattern& getReshardingKey() const { return _commonReshardingMetadata.getReshardingKey(); }
    /**
     * Not meant to be used directly. Only use internal fields.
     */
    const mongo::ReshardingApproxCopySize& getReshardingApproxCopySizeStruct() const { return _reshardingApproxCopySizeStruct; }
    mongo::ReshardingApproxCopySize& getReshardingApproxCopySizeStruct() { return _reshardingApproxCopySizeStruct; }
    void setReshardingApproxCopySizeStruct(mongo::ReshardingApproxCopySize value) & {  _reshardingApproxCopySizeStruct = std::move(value);  }

    const  boost::optional<std::int64_t> getApproxDocumentsToCopy() const { return _reshardingApproxCopySizeStruct.getApproxDocumentsToCopy(); }
    const  boost::optional<std::int64_t> getApproxBytesToCopy() const { return _reshardingApproxCopySizeStruct.getApproxBytesToCopy(); }
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
    mongo::CoordinatorStateEnum getState() const { return _state; }
    void setState(mongo::CoordinatorStateEnum value) & {  _state = std::move(value); _hasState = true; }

    /**
     * The timestamp for the snapshot read while cloning from the donors.
     */
    const boost::optional<mongo::Timestamp>& getCloneTimestamp() const& { return _cloneTimestamp; }
    void getCloneTimestamp() && = delete;
    void setCloneTimestamp(boost::optional<mongo::Timestamp> value) & {  _cloneTimestamp = std::move(value);  }

    /**
     * The list of all donor shards for this resharding operation.
     */
    const std::vector<mongo::DonorShardEntry>& getDonorShards() const& { return _donorShards; }
    void getDonorShards() && = delete;
    void setDonorShards(std::vector<mongo::DonorShardEntry> value) & {  _donorShards = std::move(value); _hasDonorShards = true; }

    /**
     * The list of all recipient shards for this resharding operation.
     */
    const std::vector<mongo::RecipientShardEntry>& getRecipientShards() const& { return _recipientShards; }
    void getRecipientShards() && = delete;
    void setRecipientShards(std::vector<mongo::RecipientShardEntry> value) & {  _recipientShards = std::move(value); _hasRecipientShards = true; }

    /**
     * The zones associated with the new shard key.
     */
    const boost::optional<std::vector<mongo::ReshardingZoneType>>& getZones() const& { return _zones; }
    void getZones() && = delete;
    void setZones(boost::optional<std::vector<mongo::ReshardingZoneType>> value) & {  _zones = std::move(value);  }

    /**
     * The number of chunks the new collection should have after resharding.
     */
    const boost::optional<std::int64_t> getNumInitialChunks() const& { return _numInitialChunks; }
    void getNumInitialChunks() && = delete;
    void setNumInitialChunks(boost::optional<std::int64_t> value) & {  _numInitialChunks = std::move(value);  }

    /**
     * Mapping of chunk ranges to be used as the initial split output. This is only for testing purposes.
     */
    const boost::optional<std::vector<mongo::ReshardedChunk>>& getPresetReshardedChunks() const& { return _presetReshardedChunks; }
    void getPresetReshardedChunks() && = delete;
    void setPresetReshardedChunks(boost::optional<std::vector<mongo::ReshardedChunk>> value) & {  _presetReshardedChunks = std::move(value);  }

    /**
     * Dummy field that always has the same value (true) to have a unique index on in order to prevent multiple resharding operations from being active at the same time.
     */
    bool getActive() const { return _active; }
    void setActive(bool value) & {  _active = std::move(value);  }

    /**
     * Metrics related to the coordinator.
     */
    const boost::optional<mongo::ReshardingCoordinatorMetrics>& getMetrics() const& { return _metrics; }
    void getMetrics() && = delete;
    void setMetrics(boost::optional<mongo::ReshardingCoordinatorMetrics> value) & {  _metrics = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::CommonReshardingMetadata _commonReshardingMetadata;
    mongo::ReshardingApproxCopySize _reshardingApproxCopySizeStruct;
    mongo::AbortReason _abortReasonStruct;
    mongo::CoordinatorStateEnum _state;
    boost::optional<mongo::Timestamp> _cloneTimestamp;
    std::vector<mongo::DonorShardEntry> _donorShards;
    std::vector<mongo::RecipientShardEntry> _recipientShards;
    boost::optional<std::vector<mongo::ReshardingZoneType>> _zones;
    boost::optional<std::int64_t> _numInitialChunks;
    boost::optional<std::vector<mongo::ReshardedChunk>> _presetReshardedChunks;
    bool _active{true};
    boost::optional<mongo::ReshardingCoordinatorMetrics> _metrics;
    bool _hasState : 1;
    bool _hasDonorShards : 1;
    bool _hasRecipientShards : 1;
};

}  // namespace mongo
