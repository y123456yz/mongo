/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/s/resharding/donor_document_gen.h --output build/opt/mongo/db/s/resharding/donor_document_gen.cpp src/mongo/db/s/resharding/donor_document.idl
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
 * Contains metrics about the resharding operation on a donor.
 */
class ReshardingDonorMetrics {
public:
    static constexpr auto kCriticalSectionFieldName = "criticalSection"_sd;
    static constexpr auto kOperationRuntimeFieldName = "operationRuntime"_sd;

    ReshardingDonorMetrics();

    static ReshardingDonorMetrics parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * The time interval of the entire resharding operation on this donor.
     */
    const boost::optional<mongo::ReshardingMetricsTimeInterval>& getOperationRuntime() const& { return _operationRuntime; }
    void getOperationRuntime() && = delete;
    void setOperationRuntime(boost::optional<mongo::ReshardingMetricsTimeInterval> value) & {  _operationRuntime = std::move(value);  }

    /**
     * The time interval of the resharding critical section on this donor.
     */
    const boost::optional<mongo::ReshardingMetricsTimeInterval>& getCriticalSection() const& { return _criticalSection; }
    void getCriticalSection() && = delete;
    void setCriticalSection(boost::optional<mongo::ReshardingMetricsTimeInterval> value) & {  _criticalSection = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    boost::optional<mongo::ReshardingMetricsTimeInterval> _operationRuntime;
    boost::optional<mongo::ReshardingMetricsTimeInterval> _criticalSection;
};

/**
 * Represents a resharding operation on the donor shard.
 */
class ReshardingDonorDocument {
public:
    static constexpr auto kCommonReshardingMetadataFieldName = "CommonReshardingMetadata"_sd;
    static constexpr auto kMetricsFieldName = "metrics"_sd;
    static constexpr auto kMutableStateFieldName = "mutableState"_sd;
    static constexpr auto kRecipientShardsFieldName = "recipientShards"_sd;
    static constexpr auto kReshardingKeyFieldName = "reshardingKey"_sd;
    static constexpr auto kReshardingUUIDFieldName = "_id"_sd;
    static constexpr auto kSourceNssFieldName = "ns"_sd;
    static constexpr auto kSourceUUIDFieldName = "ui"_sd;
    static constexpr auto kTempReshardingNssFieldName = "tempNs"_sd;

    ReshardingDonorDocument();
    ReshardingDonorDocument(mongo::DonorShardContext mutableState, std::vector<mongo::ShardId> recipientShards);

    static ReshardingDonorDocument parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
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
    const mongo::DonorShardContext& getMutableState() const { return _mutableState; }
    mongo::DonorShardContext& getMutableState() { return _mutableState; }
    void setMutableState(mongo::DonorShardContext value) & {  _mutableState = std::move(value); _hasMutableState = true; }

    /**
     * The list of recipient shards that are replicating from this donor.
     */
    const std::vector<mongo::ShardId>& getRecipientShards() const& { return _recipientShards; }
    void getRecipientShards() && = delete;
    void setRecipientShards(std::vector<mongo::ShardId> value) & {  _recipientShards = std::move(value); _hasRecipientShards = true; }

    /**
     * Metrics related to this donor.
     */
    const boost::optional<mongo::ReshardingDonorMetrics>& getMetrics() const& { return _metrics; }
    void getMetrics() && = delete;
    void setMetrics(boost::optional<mongo::ReshardingDonorMetrics> value) & {  _metrics = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::CommonReshardingMetadata _commonReshardingMetadata;
    mongo::DonorShardContext _mutableState;
    std::vector<mongo::ShardId> _recipientShards;
    boost::optional<mongo::ReshardingDonorMetrics> _metrics;
    bool _hasMutableState : 1;
    bool _hasRecipientShards : 1;
};

}  // namespace mongo
