/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/s/resharding/recipient_document_gen.h --output build/opt/mongo/db/s/resharding/recipient_document_gen.cpp src/mongo/db/s/resharding/recipient_document.idl
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
 * Contains metrics about the resharding operation on a recipient.
 */
class ReshardingRecipientMetrics {
public:
    static constexpr auto kDocumentCopyFieldName = "documentCopy"_sd;
    static constexpr auto kOperationRuntimeFieldName = "operationRuntime"_sd;
    static constexpr auto kOplogApplicationFieldName = "oplogApplication"_sd;

    ReshardingRecipientMetrics();

    static ReshardingRecipientMetrics parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * The time interval of the entire resharding operation on this recipient.
     */
    const boost::optional<mongo::ReshardingMetricsTimeInterval>& getOperationRuntime() const& { return _operationRuntime; }
    void getOperationRuntime() && = delete;
    void setOperationRuntime(boost::optional<mongo::ReshardingMetricsTimeInterval> value) & {  _operationRuntime = std::move(value);  }

    /**
     * The time interval that it takes to clone documents on this recipient.
     */
    const boost::optional<mongo::ReshardingMetricsTimeInterval>& getDocumentCopy() const& { return _documentCopy; }
    void getDocumentCopy() && = delete;
    void setDocumentCopy(boost::optional<mongo::ReshardingMetricsTimeInterval> value) & {  _documentCopy = std::move(value);  }

    /**
     * The time interval that it takes to apply oplog entries on this recipient.
     */
    const boost::optional<mongo::ReshardingMetricsTimeInterval>& getOplogApplication() const& { return _oplogApplication; }
    void getOplogApplication() && = delete;
    void setOplogApplication(boost::optional<mongo::ReshardingMetricsTimeInterval> value) & {  _oplogApplication = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    boost::optional<mongo::ReshardingMetricsTimeInterval> _operationRuntime;
    boost::optional<mongo::ReshardingMetricsTimeInterval> _documentCopy;
    boost::optional<mongo::ReshardingMetricsTimeInterval> _oplogApplication;
};

/**
 * Represents a resharding operation on the recipient shard.
 */
class ReshardingRecipientDocument {
public:
    static constexpr auto kCommonReshardingMetadataFieldName = "CommonReshardingMetadata"_sd;
    static constexpr auto kCloneTimestampFieldName = "cloneTimestamp"_sd;
    static constexpr auto kDonorShardsFieldName = "donorShards"_sd;
    static constexpr auto kMetricsFieldName = "metrics"_sd;
    static constexpr auto kMinimumOperationDurationMillisFieldName = "minimumOperationDurationMillis"_sd;
    static constexpr auto kMutableStateFieldName = "mutableState"_sd;
    static constexpr auto kReshardingKeyFieldName = "reshardingKey"_sd;
    static constexpr auto kReshardingUUIDFieldName = "_id"_sd;
    static constexpr auto kSourceNssFieldName = "ns"_sd;
    static constexpr auto kSourceUUIDFieldName = "ui"_sd;
    static constexpr auto kStartConfigTxnCloneTimeFieldName = "startConfigTxnCloneTime"_sd;
    static constexpr auto kTempReshardingNssFieldName = "tempNs"_sd;

    ReshardingRecipientDocument();
    ReshardingRecipientDocument(mongo::RecipientShardContext mutableState, std::vector<mongo::DonorShardFetchTimestamp> donorShards, std::int64_t minimumOperationDurationMillis);

    static ReshardingRecipientDocument parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
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
     * The timestamp for the snapshot read while cloning from the donors.
     */
    const boost::optional<mongo::Timestamp>& getCloneTimestamp() const& { return _cloneTimestamp; }
    void getCloneTimestamp() && = delete;
    void setCloneTimestamp(boost::optional<mongo::Timestamp> value) & {  _cloneTimestamp = std::move(value);  }

    const mongo::RecipientShardContext& getMutableState() const { return _mutableState; }
    mongo::RecipientShardContext& getMutableState() { return _mutableState; }
    void setMutableState(mongo::RecipientShardContext value) & {  _mutableState = std::move(value); _hasMutableState = true; }

    /**
     * The list of donor shards that report to this recipient.
     */
    const std::vector<mongo::DonorShardFetchTimestamp>& getDonorShards() const& { return _donorShards; }
    void getDonorShards() && = delete;
    void setDonorShards(std::vector<mongo::DonorShardFetchTimestamp> value) & {  _donorShards = std::move(value); _hasDonorShards = true; }

    std::int64_t getMinimumOperationDurationMillis() const { return _minimumOperationDurationMillis; }
    void setMinimumOperationDurationMillis(std::int64_t value) & {  _minimumOperationDurationMillis = std::move(value); _hasMinimumOperationDurationMillis = true; }

    const boost::optional<mongo::Date_t>& getStartConfigTxnCloneTime() const& { return _startConfigTxnCloneTime; }
    void getStartConfigTxnCloneTime() && = delete;
    void setStartConfigTxnCloneTime(boost::optional<mongo::Date_t> value) & {  _startConfigTxnCloneTime = std::move(value);  }

    /**
     * Metrics related to this recipient.
     */
    const boost::optional<mongo::ReshardingRecipientMetrics>& getMetrics() const& { return _metrics; }
    void getMetrics() && = delete;
    void setMetrics(boost::optional<mongo::ReshardingRecipientMetrics> value) & {  _metrics = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::CommonReshardingMetadata _commonReshardingMetadata;
    boost::optional<mongo::Timestamp> _cloneTimestamp;
    mongo::RecipientShardContext _mutableState;
    std::vector<mongo::DonorShardFetchTimestamp> _donorShards;
    std::int64_t _minimumOperationDurationMillis;
    boost::optional<mongo::Date_t> _startConfigTxnCloneTime;
    boost::optional<mongo::ReshardingRecipientMetrics> _metrics;
    bool _hasMutableState : 1;
    bool _hasDonorShards : 1;
    bool _hasMinimumOperationDurationMillis : 1;
};

}  // namespace mongo
