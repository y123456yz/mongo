/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/s/drop_collection_coordinator_document_gen.h --output build/opt/mongo/db/s/drop_collection_coordinator_document_gen.cpp src/mongo/db/s/drop_collection_coordinator_document.idl
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
#include "mongo/db/namespace_string.h"
#include "mongo/db/s/forwardable_operation_metadata.h"
#include "mongo/db/s/sharding_ddl_coordinator_gen.h"
#include "mongo/idl/basic_types.h"
#include "mongo/idl/basic_types_gen.h"
#include "mongo/idl/idl_parser.h"
#include "mongo/rpc/op_msg.h"
#include "mongo/s/catalog/type_collection.h"
#include "mongo/s/database_version.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/util/uuid.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {

/**
 * The current state of a drop collection operation on the coordinator.
 */
enum class DropCollectionCoordinatorPhaseEnum : std::int32_t {
    kUnset ,
    kFreezeCollection ,
    kDropCollection ,
};
static constexpr uint32_t kNumDropCollectionCoordinatorPhaseEnum = 3;

DropCollectionCoordinatorPhaseEnum DropCollectionCoordinatorPhase_parse(const IDLParserErrorContext& ctxt, StringData value);
StringData DropCollectionCoordinatorPhase_serializer(DropCollectionCoordinatorPhaseEnum value);

/**
 * Represents a drop collection operation on the coordinator shard.
 */
class DropCollectionCoordinatorDocument {
public:
    static constexpr auto kShardingDDLCoordinatorMetadataFieldName = "ShardingDDLCoordinatorMetadata"_sd;
    static constexpr auto kCollInfoFieldName = "collInfo"_sd;
    static constexpr auto kDatabaseVersionFieldName = "databaseVersion"_sd;
    static constexpr auto kForwardableOpMetadataFieldName = "forwardableOpMetadata"_sd;
    static constexpr auto kIdFieldName = "_id"_sd;
    static constexpr auto kPhaseFieldName = "phase"_sd;
    static constexpr auto kRecoveredFromDiskFieldName = "recoveredFromDisk"_sd;
    static constexpr auto kSessionFieldName = "session"_sd;

    DropCollectionCoordinatorDocument();

    static DropCollectionCoordinatorDocument parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
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
    mongo::DropCollectionCoordinatorPhaseEnum getPhase() const { return _phase; }
    void setPhase(mongo::DropCollectionCoordinatorPhaseEnum value) & {  _phase = std::move(value);  }

    /**
     * Information of the collection to drop, used only for sharded collection.
     */
    const boost::optional<mongo::CollectionType>& getCollInfo() const& { return _collInfo; }
    void getCollInfo() && = delete;
    void setCollInfo(boost::optional<mongo::CollectionType> value) & {  _collInfo = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::ShardingDDLCoordinatorMetadata _shardingDDLCoordinatorMetadata;
    mongo::DropCollectionCoordinatorPhaseEnum _phase{mongo::DropCollectionCoordinatorPhaseEnum::kUnset};
    boost::optional<mongo::CollectionType> _collInfo;
};

}  // namespace mongo
