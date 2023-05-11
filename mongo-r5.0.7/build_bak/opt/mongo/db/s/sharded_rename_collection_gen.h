/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/s/sharded_rename_collection_gen.h --output build/opt/mongo/db/s/sharded_rename_collection_gen.cpp src/mongo/db/s/sharded_rename_collection.idl
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
 * The current state of a rename collection operation on the coordinator.
 */
enum class RenameCollectionCoordinatorPhaseEnum : std::int32_t {
    kUnset ,
    kCheckPreconditions ,
    kFreezeMigrations ,
    kBlockCrudAndRename ,
    kRenameMetadata ,
    kUnblockCRUD ,
    kSetResponse ,
};
static constexpr uint32_t kNumRenameCollectionCoordinatorPhaseEnum = 7;

RenameCollectionCoordinatorPhaseEnum RenameCollectionCoordinatorPhase_parse(const IDLParserErrorContext& ctxt, StringData value);
StringData RenameCollectionCoordinatorPhase_serializer(RenameCollectionCoordinatorPhaseEnum value);

/**
 * The current state of a rename collection operation on a participant.
 */
enum class RenameCollectionParticipantPhaseEnum : std::int32_t {
    kUnset ,
    kBlockCRUDAndSnapshotRangeDeletions ,
    kRenameLocalAndRestoreRangeDeletions ,
    kDeleteFromRangeDeletions ,
    kUnblockCRUD ,
};
static constexpr uint32_t kNumRenameCollectionParticipantPhaseEnum = 5;

RenameCollectionParticipantPhaseEnum RenameCollectionParticipantPhase_parse(const IDLParserErrorContext& ctxt, StringData value);
StringData RenameCollectionParticipantPhase_serializer(RenameCollectionParticipantPhaseEnum value);

/**
 * Represents a rename collection operation on the coordinator shard.
 */
class RenameCollectionCoordinatorDocument {
public:
    static constexpr auto kRenameCollectionRequestFieldName = "RenameCollectionRequest"_sd;
    static constexpr auto kShardingDDLCoordinatorMetadataFieldName = "ShardingDDLCoordinatorMetadata"_sd;
    static constexpr auto kDatabaseVersionFieldName = "databaseVersion"_sd;
    static constexpr auto kDropTargetFieldName = "dropTarget"_sd;
    static constexpr auto kForwardableOpMetadataFieldName = "forwardableOpMetadata"_sd;
    static constexpr auto kIdFieldName = "_id"_sd;
    static constexpr auto kOptShardedCollInfoFieldName = "optShardedCollInfo"_sd;
    static constexpr auto kPhaseFieldName = "phase"_sd;
    static constexpr auto kRecoveredFromDiskFieldName = "recoveredFromDisk"_sd;
    static constexpr auto kSessionFieldName = "session"_sd;
    static constexpr auto kSourceUUIDFieldName = "sourceUUID"_sd;
    static constexpr auto kStayTempFieldName = "stayTemp"_sd;
    static constexpr auto kTargetIsShardedFieldName = "targetIsSharded"_sd;
    static constexpr auto kTargetUUIDFieldName = "targetUUID"_sd;
    static constexpr auto kToFieldName = "to"_sd;

    RenameCollectionCoordinatorDocument();

    static RenameCollectionCoordinatorDocument parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
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
     * Request for the rename collection command
     */
    const mongo::RenameCollectionRequest& getRenameCollectionRequest() const { return _renameCollectionRequest; }
    mongo::RenameCollectionRequest& getRenameCollectionRequest() { return _renameCollectionRequest; }
    void setRenameCollectionRequest(mongo::RenameCollectionRequest value) & {  _renameCollectionRequest = std::move(value);  }

    /**
     * The new namespace for the collection being renamed.
     */
    const  mongo::NamespaceString& getTo() const { return _renameCollectionRequest.getTo(); }
    /**
     * If true, mongod will drop the target of renameCollection prior to renaming the collection.
     */
     bool getDropTarget() const { return _renameCollectionRequest.getDropTarget(); }
    /**
     * If true, the original collection will remain temp if it was temp before the rename.
     */
     bool getStayTemp() const { return _renameCollectionRequest.getStayTemp(); }
    mongo::RenameCollectionCoordinatorPhaseEnum getPhase() const { return _phase; }
    void setPhase(mongo::RenameCollectionCoordinatorPhaseEnum value) & {  _phase = std::move(value);  }

    /**
     * Indicates whether the target collection (to override) is sharded or not.
     */
    bool getTargetIsSharded() const { return _targetIsSharded; }
    void setTargetIsSharded(bool value) & {  _targetIsSharded = std::move(value);  }

    /**
     * CollectionType of the collection currently being renamed (if sharded).
     */
    const boost::optional<mongo::CollectionType>& getOptShardedCollInfo() const& { return _optShardedCollInfo; }
    void getOptShardedCollInfo() && = delete;
    void setOptShardedCollInfo(boost::optional<mongo::CollectionType> value) & {  _optShardedCollInfo = std::move(value);  }

    /**
     * ID of the collection getting renamed.
     */
    const boost::optional<mongo::UUID>& getSourceUUID() const& { return _sourceUUID; }
    void getSourceUUID() && = delete;
    void setSourceUUID(boost::optional<mongo::UUID> value) & {  _sourceUUID = std::move(value);  }

    /**
     * ID of the existing collection getting dropped.
     */
    const boost::optional<mongo::UUID>& getTargetUUID() const& { return _targetUUID; }
    void getTargetUUID() && = delete;
    void setTargetUUID(boost::optional<mongo::UUID> value) & {  _targetUUID = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::ShardingDDLCoordinatorMetadata _shardingDDLCoordinatorMetadata;
    mongo::RenameCollectionRequest _renameCollectionRequest;
    mongo::RenameCollectionCoordinatorPhaseEnum _phase{mongo::RenameCollectionCoordinatorPhaseEnum::kUnset};
    bool _targetIsSharded{false};
    boost::optional<mongo::CollectionType> _optShardedCollInfo;
    boost::optional<mongo::UUID> _sourceUUID;
    boost::optional<mongo::UUID> _targetUUID;
};

/**
 * Represents a rename collection operation on a participant shard.
 */
class RenameCollectionParticipantDocument {
public:
    static constexpr auto kRenameCollectionRequestFieldName = "RenameCollectionRequest"_sd;
    static constexpr auto kDropTargetFieldName = "dropTarget"_sd;
    static constexpr auto kForwardableOpMetadataFieldName = "forwardableOpMetadata"_sd;
    static constexpr auto kFromNssFieldName = "_id"_sd;
    static constexpr auto kPhaseFieldName = "phase"_sd;
    static constexpr auto kSourceUUIDFieldName = "sourceUUID"_sd;
    static constexpr auto kStayTempFieldName = "stayTemp"_sd;
    static constexpr auto kTargetUUIDFieldName = "targetUUID"_sd;
    static constexpr auto kToFieldName = "to"_sd;

    RenameCollectionParticipantDocument();
    RenameCollectionParticipantDocument(mongo::NamespaceString fromNss, mongo::ForwardableOperationMetadata forwardableOpMetadata, mongo::UUID sourceUUID);

    static RenameCollectionParticipantDocument parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Request for the rename collection command
     */
    const mongo::RenameCollectionRequest& getRenameCollectionRequest() const { return _renameCollectionRequest; }
    mongo::RenameCollectionRequest& getRenameCollectionRequest() { return _renameCollectionRequest; }
    void setRenameCollectionRequest(mongo::RenameCollectionRequest value) & {  _renameCollectionRequest = std::move(value);  }

    /**
     * The new namespace for the collection being renamed.
     */
    const  mongo::NamespaceString& getTo() const { return _renameCollectionRequest.getTo(); }
    /**
     * If true, mongod will drop the target of renameCollection prior to renaming the collection.
     */
     bool getDropTarget() const { return _renameCollectionRequest.getDropTarget(); }
    /**
     * If true, the original collection will remain temp if it was temp before the rename.
     */
     bool getStayTemp() const { return _renameCollectionRequest.getStayTemp(); }
    const mongo::NamespaceString& getFromNss() const { return _fromNss; }
    void setFromNss(mongo::NamespaceString value) & {  _fromNss = std::move(value); _hasFromNss = true; }

    mongo::RenameCollectionParticipantPhaseEnum getPhase() const { return _phase; }
    void setPhase(mongo::RenameCollectionParticipantPhaseEnum value) & {  _phase = std::move(value);  }

    const mongo::ForwardableOperationMetadata& getForwardableOpMetadata() const { return _forwardableOpMetadata; }
    void setForwardableOpMetadata(mongo::ForwardableOperationMetadata value) & {  _forwardableOpMetadata = std::move(value); _hasForwardableOpMetadata = true; }

    /**
     * ID of the collection getting renamed.
     */
    const mongo::UUID& getSourceUUID() const { return _sourceUUID; }
    void setSourceUUID(mongo::UUID value) & {  _sourceUUID = std::move(value); _hasSourceUUID = true; }

    /**
     * ID of the existing collection getting dropped.
     */
    const boost::optional<mongo::UUID>& getTargetUUID() const& { return _targetUUID; }
    void getTargetUUID() && = delete;
    void setTargetUUID(boost::optional<mongo::UUID> value) & {  _targetUUID = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::RenameCollectionRequest _renameCollectionRequest;
    mongo::NamespaceString _fromNss;
    mongo::RenameCollectionParticipantPhaseEnum _phase{mongo::RenameCollectionParticipantPhaseEnum::kUnset};
    mongo::ForwardableOperationMetadata _forwardableOpMetadata;
    mongo::UUID _sourceUUID;
    boost::optional<mongo::UUID> _targetUUID;
    bool _hasFromNss : 1;
    bool _hasForwardableOpMetadata : 1;
    bool _hasSourceUUID : 1;
};

/**
 * Internal command sent to shard participating in a rename collection procedure
 */
class ShardsvrRenameCollectionParticipant {
public:
    using Reply = void;
    static constexpr auto kRenameCollectionRequestFieldName = "RenameCollectionRequest"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kDropTargetFieldName = "dropTarget"_sd;
    static constexpr auto kSourceUUIDFieldName = "sourceUUID"_sd;
    static constexpr auto kStayTempFieldName = "stayTemp"_sd;
    static constexpr auto kTargetUUIDFieldName = "targetUUID"_sd;
    static constexpr auto kToFieldName = "to"_sd;
    static constexpr auto kCommandName = "_shardsvrRenameCollectionParticipant"_sd;

    explicit ShardsvrRenameCollectionParticipant(const NamespaceString nss);
    ShardsvrRenameCollectionParticipant(const NamespaceString nss, mongo::UUID sourceUUID);

    static ShardsvrRenameCollectionParticipant parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static ShardsvrRenameCollectionParticipant parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const NamespaceString& getNamespace() const { return _nss; }

    /**
     * Request for the rename collection command
     */
    const mongo::RenameCollectionRequest& getRenameCollectionRequest() const { return _renameCollectionRequest; }
    mongo::RenameCollectionRequest& getRenameCollectionRequest() { return _renameCollectionRequest; }
    void setRenameCollectionRequest(mongo::RenameCollectionRequest value) & {  _renameCollectionRequest = std::move(value);  }

    /**
     * The new namespace for the collection being renamed.
     */
    const  mongo::NamespaceString& getTo() const { return _renameCollectionRequest.getTo(); }
    /**
     * If true, mongod will drop the target of renameCollection prior to renaming the collection.
     */
     bool getDropTarget() const { return _renameCollectionRequest.getDropTarget(); }
    /**
     * If true, the original collection will remain temp if it was temp before the rename.
     */
     bool getStayTemp() const { return _renameCollectionRequest.getStayTemp(); }
    /**
     * ID of the collection getting renamed.
     */
    const mongo::UUID& getSourceUUID() const { return _sourceUUID; }
    void setSourceUUID(mongo::UUID value) & {  _sourceUUID = std::move(value); _hasSourceUUID = true; }

    /**
     * ID of the existing collection getting dropped.
     */
    const boost::optional<mongo::UUID>& getTargetUUID() const& { return _targetUUID; }
    void getTargetUUID() && = delete;
    void setTargetUUID(boost::optional<mongo::UUID> value) & {  _targetUUID = std::move(value);  }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;


    NamespaceString _nss;

    mongo::RenameCollectionRequest _renameCollectionRequest;
    mongo::UUID _sourceUUID;
    boost::optional<mongo::UUID> _targetUUID;
    std::string _dbName;
    bool _hasSourceUUID : 1;
    bool _hasDbName : 1;
};

/**
 * Parser for the _shardsvrRenameCollectionParticipantUnblock command
 */
class ShardsvrRenameCollectionUnblockParticipant {
public:
    using Reply = void;
    static constexpr auto kRenameCollectionRequestFieldName = "RenameCollectionRequest"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kDropTargetFieldName = "dropTarget"_sd;
    static constexpr auto kSourceUUIDFieldName = "sourceUUID"_sd;
    static constexpr auto kStayTempFieldName = "stayTemp"_sd;
    static constexpr auto kToFieldName = "to"_sd;
    static constexpr auto kCommandName = "_shardsvrRenameCollectionParticipantUnblock"_sd;

    explicit ShardsvrRenameCollectionUnblockParticipant(const NamespaceString nss);
    ShardsvrRenameCollectionUnblockParticipant(const NamespaceString nss, mongo::UUID sourceUUID);

    static ShardsvrRenameCollectionUnblockParticipant parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static ShardsvrRenameCollectionUnblockParticipant parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const NamespaceString& getNamespace() const { return _nss; }

    /**
     * Request for the rename collection command
     */
    const mongo::RenameCollectionRequest& getRenameCollectionRequest() const { return _renameCollectionRequest; }
    mongo::RenameCollectionRequest& getRenameCollectionRequest() { return _renameCollectionRequest; }
    void setRenameCollectionRequest(mongo::RenameCollectionRequest value) & {  _renameCollectionRequest = std::move(value);  }

    /**
     * The new namespace for the collection being renamed.
     */
    const  mongo::NamespaceString& getTo() const { return _renameCollectionRequest.getTo(); }
    /**
     * If true, mongod will drop the target of renameCollection prior to renaming the collection.
     */
     bool getDropTarget() const { return _renameCollectionRequest.getDropTarget(); }
    /**
     * If true, the original collection will remain temp if it was temp before the rename.
     */
     bool getStayTemp() const { return _renameCollectionRequest.getStayTemp(); }
    /**
     * ID of the collection getting renamed.
     */
    const mongo::UUID& getSourceUUID() const { return _sourceUUID; }
    void setSourceUUID(mongo::UUID value) & {  _sourceUUID = std::move(value); _hasSourceUUID = true; }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;


    NamespaceString _nss;

    mongo::RenameCollectionRequest _renameCollectionRequest;
    mongo::UUID _sourceUUID;
    std::string _dbName;
    bool _hasSourceUUID : 1;
    bool _hasDbName : 1;
};

}  // namespace mongo
