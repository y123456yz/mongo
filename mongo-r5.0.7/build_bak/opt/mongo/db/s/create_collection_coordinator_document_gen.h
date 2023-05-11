/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/s/create_collection_coordinator_document_gen.h --output build/opt/mongo/db/s/create_collection_coordinator_document_gen.cpp src/mongo/db/s/create_collection_coordinator_document.idl
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
#include "mongo/crypto/sha256_block.h"
#include "mongo/db/keypattern.h"
#include "mongo/db/namespace_string.h"
#include "mongo/db/s/forwardable_operation_metadata.h"
#include "mongo/db/s/sharding_ddl_coordinator_gen.h"
#include "mongo/db/timeseries/timeseries_global_options.h"
#include "mongo/idl/basic_types.h"
#include "mongo/idl/basic_types_gen.h"
#include "mongo/idl/idl_parser.h"
#include "mongo/rpc/op_msg.h"
#include "mongo/s/catalog/type_collection.h"
#include "mongo/s/chunk_version.h"
#include "mongo/s/database_version.h"
#include "mongo/s/request_types/sharded_ddl_commands_gen.h"
#include "mongo/s/shard_id.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/util/uuid.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {

/**
 * Current create collection coordinator's operation state.
 */
enum class CreateCollectionCoordinatorPhaseEnum : std::int32_t {
    kUnset ,
    kCommit ,
};
static constexpr uint32_t kNumCreateCollectionCoordinatorPhaseEnum = 2;

CreateCollectionCoordinatorPhaseEnum CreateCollectionCoordinatorPhase_parse(const IDLParserErrorContext& ctxt, StringData value);
StringData CreateCollectionCoordinatorPhase_serializer(CreateCollectionCoordinatorPhaseEnum value);

/**
 * Object with neccessary fields to create a collection
 */
class CreateCollectionCoordinatorDocument {
public:
    static constexpr auto kCreateCollectionRequestFieldName = "CreateCollectionRequest"_sd;
    static constexpr auto kShardingDDLCoordinatorMetadataFieldName = "ShardingDDLCoordinatorMetadata"_sd;
    static constexpr auto kCollationFieldName = "collation"_sd;
    static constexpr auto kDatabaseVersionFieldName = "databaseVersion"_sd;
    static constexpr auto kForwardableOpMetadataFieldName = "forwardableOpMetadata"_sd;
    static constexpr auto kIdFieldName = "_id"_sd;
    static constexpr auto kInitialSplitPointsFieldName = "initialSplitPoints"_sd;
    static constexpr auto kNumInitialChunksFieldName = "numInitialChunks"_sd;
    static constexpr auto kPhaseFieldName = "phase"_sd;
    static constexpr auto kPresplitHashedZonesFieldName = "presplitHashedZones"_sd;
    static constexpr auto kRecoveredFromDiskFieldName = "recoveredFromDisk"_sd;
    static constexpr auto kSessionFieldName = "session"_sd;
    static constexpr auto kShardKeyFieldName = "shardKey"_sd;
    static constexpr auto kTimeseriesFieldName = "timeseries"_sd;
    static constexpr auto kUniqueFieldName = "unique"_sd;

    CreateCollectionCoordinatorDocument();

    static CreateCollectionCoordinatorDocument parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Commong metadata for all sharding DDL coordinator.
     */
    const mongo::ShardingDDLCoordinatorMetadata& getShardingDDLCoordinatorMetadata() const { return _shardingDDLCoordinatorMetadata; }
    mongo::ShardingDDLCoordinatorMetadata& getShardingDDLCoordinatorMetadata() { return _shardingDDLCoordinatorMetadata; }
    void setShardingDDLCoordinatorMetadata(mongo::ShardingDDLCoordinatorMetadata value) & {  _shardingDDLCoordinatorMetadata = std::move(value);  }

    const  mongo::ShardingDDLCoordinatorId& getId() const { return _shardingDDLCoordinatorMetadata.getId(); }
     bool getRecoveredFromDisk() const { return _shardingDDLCoordinatorMetadata.getRecoveredFromDisk(); }
    const  boost::optional<mongo::ForwardableOperationMetadata>& getForwardableOpMetadata() const { return _shardingDDLCoordinatorMetadata.getForwardableOpMetadata(); }
    const  boost::optional<mongo::DatabaseVersion>& getDatabaseVersion() const { return _shardingDDLCoordinatorMetadata.getDatabaseVersion(); }
    const  boost::optional<mongo::ShardingDDLSession>& getSession() const { return _shardingDDLCoordinatorMetadata.getSession(); }
    /**
     * All the parameters sent by the router.
     */
    const mongo::CreateCollectionRequest& getCreateCollectionRequest() const { return _createCollectionRequest; }
    mongo::CreateCollectionRequest& getCreateCollectionRequest() { return _createCollectionRequest; }
    void setCreateCollectionRequest(mongo::CreateCollectionRequest value) & {  _createCollectionRequest = std::move(value);  }

    /**
     * The index specification document to use as the shard key.
     */
    const  boost::optional<mongo::BSONObj>& getShardKey() const { return _createCollectionRequest.getShardKey(); }
    /**
     * Whether the shard key index should enforce a unique constraint.
     */
    const  boost::optional<bool> getUnique() const { return _createCollectionRequest.getUnique(); }
    /**
     * The number of chunks to create initially when sharding an empty collection with a hashed shard key.
     */
    const  boost::optional<std::int64_t> getNumInitialChunks() const { return _createCollectionRequest.getNumInitialChunks(); }
    /**
     * True if the chunks should be pre-split based on the existing zones when sharding a collection with hashed shard key.
     */
    const  boost::optional<bool> getPresplitHashedZones() const { return _createCollectionRequest.getPresplitHashedZones(); }
    /**
     * A specific set of points to create initial splits at, currently used only by mapReduce.
     */
    const  boost::optional<std::vector<mongo::BSONObj>>& getInitialSplitPoints() const { return _createCollectionRequest.getInitialSplitPoints(); }
    /**
     * The options to create the time-series collection with.
     */
    const  boost::optional<mongo::TimeseriesOptions>& getTimeseries() const { return _createCollectionRequest.getTimeseries(); }
    /**
     * The collation to use for the shard key index.
     */
    const  boost::optional<mongo::BSONObj>& getCollation() const { return _createCollectionRequest.getCollation(); }
    /**
     * Coordinator phase.
     */
    mongo::CreateCollectionCoordinatorPhaseEnum getPhase() const { return _phase; }
    void setPhase(mongo::CreateCollectionCoordinatorPhaseEnum value) & {  _phase = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::ShardingDDLCoordinatorMetadata _shardingDDLCoordinatorMetadata;
    mongo::CreateCollectionRequest _createCollectionRequest;
    mongo::CreateCollectionCoordinatorPhaseEnum _phase{mongo::CreateCollectionCoordinatorPhaseEnum::kUnset};
};

}  // namespace mongo
