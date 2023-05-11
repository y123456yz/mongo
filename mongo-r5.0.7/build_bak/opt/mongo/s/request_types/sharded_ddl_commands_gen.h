/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/s/request_types/sharded_ddl_commands_gen.h --output build/opt/mongo/s/request_types/sharded_ddl_commands_gen.cpp src/mongo/s/request_types/sharded_ddl_commands.idl
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
#include "mongo/db/timeseries/timeseries_gen.h"
#include "mongo/db/timeseries/timeseries_global_options.h"
#include "mongo/idl/basic_types.h"
#include "mongo/idl/basic_types_gen.h"
#include "mongo/idl/idl_parser.h"
#include "mongo/rpc/op_msg.h"
#include "mongo/s/catalog/type_collection.h"
#include "mongo/s/chunk_version.h"
#include "mongo/s/database_version_gen.h"
#include "mongo/s/resharding/common_types_gen.h"
#include "mongo/s/shard_id.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/util/uuid.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {

/**
 * Response for the create database command
 */
class ConfigsvrCreateDatabaseResponse {
public:
    static constexpr auto kDatabaseVersionFieldName = "databaseVersion"_sd;

    ConfigsvrCreateDatabaseResponse();
    ConfigsvrCreateDatabaseResponse(mongo::DatabaseVersionBase databaseVersion);

    static ConfigsvrCreateDatabaseResponse parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * The version of the newly-created or already existing database
     */
    const mongo::DatabaseVersionBase& getDatabaseVersion() const { return _databaseVersion; }
    mongo::DatabaseVersionBase& getDatabaseVersion() { return _databaseVersion; }
    void setDatabaseVersion(mongo::DatabaseVersionBase value) & {  _databaseVersion = std::move(value); _hasDatabaseVersion = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::DatabaseVersionBase _databaseVersion;
    bool _hasDatabaseVersion : 1;
};

/**
 * Request for the rename collection command
 */
class RenameCollectionRequest {
public:
    static constexpr auto kDropTargetFieldName = "dropTarget"_sd;
    static constexpr auto kStayTempFieldName = "stayTemp"_sd;
    static constexpr auto kToFieldName = "to"_sd;

    RenameCollectionRequest();
    RenameCollectionRequest(mongo::NamespaceString to);

    static RenameCollectionRequest parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * The new namespace for the collection being renamed.
     */
    const mongo::NamespaceString& getTo() const { return _to; }
    void setTo(mongo::NamespaceString value) & {  _to = std::move(value); _hasTo = true; }

    /**
     * If true, mongod will drop the target of renameCollection prior to renaming the collection.
     */
    bool getDropTarget() const { return _dropTarget; }
    void setDropTarget(bool value) & {  _dropTarget = std::move(value);  }

    /**
     * If true, the original collection will remain temp if it was temp before the rename.
     */
    bool getStayTemp() const { return _stayTemp; }
    void setStayTemp(bool value) & {  _stayTemp = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::NamespaceString _to;
    bool _dropTarget{false};
    bool _stayTemp{false};
    bool _hasTo : 1;
};

/**
 * Response for the rename collection command
 */
class RenameCollectionResponse {
public:
    static constexpr auto kCollectionVersionFieldName = "collectionVersion"_sd;

    RenameCollectionResponse();
    RenameCollectionResponse(mongo::ChunkVersion collectionVersion);

    static RenameCollectionResponse parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Latest version of the collection
     */
    const mongo::ChunkVersion& getCollectionVersion() const { return _collectionVersion; }
    void setCollectionVersion(mongo::ChunkVersion value) & {  _collectionVersion = std::move(value); _hasCollectionVersion = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::ChunkVersion _collectionVersion;
    bool _hasCollectionVersion : 1;
};

/**
 * All the parameters sent by the router.
 */
class CreateCollectionRequest {
public:
    static constexpr auto kCollationFieldName = "collation"_sd;
    static constexpr auto kInitialSplitPointsFieldName = "initialSplitPoints"_sd;
    static constexpr auto kNumInitialChunksFieldName = "numInitialChunks"_sd;
    static constexpr auto kPresplitHashedZonesFieldName = "presplitHashedZones"_sd;
    static constexpr auto kShardKeyFieldName = "shardKey"_sd;
    static constexpr auto kTimeseriesFieldName = "timeseries"_sd;
    static constexpr auto kUniqueFieldName = "unique"_sd;

    CreateCollectionRequest();

    static CreateCollectionRequest parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * The index specification document to use as the shard key.
     */
    const boost::optional<mongo::BSONObj>& getShardKey() const& { return _shardKey; }
    void getShardKey() && = delete;
    void setShardKey(boost::optional<mongo::BSONObj> value) & {  _shardKey = std::move(value);  }

    /**
     * Whether the shard key index should enforce a unique constraint.
     */
    const boost::optional<bool> getUnique() const& { return _unique; }
    void getUnique() && = delete;
    void setUnique(boost::optional<bool> value) & {  _unique = std::move(value);  }

    /**
     * The number of chunks to create initially when sharding an empty collection with a hashed shard key.
     */
    const boost::optional<std::int64_t> getNumInitialChunks() const& { return _numInitialChunks; }
    void getNumInitialChunks() && = delete;
    void setNumInitialChunks(boost::optional<std::int64_t> value) & {  _numInitialChunks = std::move(value);  }

    /**
     * True if the chunks should be pre-split based on the existing zones when sharding a collection with hashed shard key.
     */
    const boost::optional<bool> getPresplitHashedZones() const& { return _presplitHashedZones; }
    void getPresplitHashedZones() && = delete;
    void setPresplitHashedZones(boost::optional<bool> value) & {  _presplitHashedZones = std::move(value);  }

    /**
     * A specific set of points to create initial splits at, currently used only by mapReduce.
     */
    const boost::optional<std::vector<mongo::BSONObj>>& getInitialSplitPoints() const& { return _initialSplitPoints; }
    void getInitialSplitPoints() && = delete;
    void setInitialSplitPoints(boost::optional<std::vector<mongo::BSONObj>> value) & {  _initialSplitPoints = std::move(value);  }

    /**
     * The options to create the time-series collection with.
     */
    const boost::optional<mongo::TimeseriesOptions>& getTimeseries() const& { return _timeseries; }
    void getTimeseries() && = delete;
    void setTimeseries(boost::optional<mongo::TimeseriesOptions> value) & {  _timeseries = std::move(value);  }

    /**
     * The collation to use for the shard key index.
     */
    const boost::optional<mongo::BSONObj>& getCollation() const& { return _collation; }
    void getCollation() && = delete;
    void setCollation(boost::optional<mongo::BSONObj> value) & {  _collation = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    boost::optional<mongo::BSONObj> _shardKey;
    boost::optional<bool> _unique;
    boost::optional<std::int64_t> _numInitialChunks;
    boost::optional<bool> _presplitHashedZones;
    boost::optional<std::vector<mongo::BSONObj>> _initialSplitPoints;
    boost::optional<mongo::TimeseriesOptions> _timeseries;
    boost::optional<mongo::BSONObj> _collation;
};

/**
 * Response of the create collection command
 */
class CreateCollectionResponse {
public:
    static constexpr auto kCollectionUUIDFieldName = "collectionUUID"_sd;
    static constexpr auto kCollectionVersionFieldName = "collectionVersion"_sd;

    CreateCollectionResponse();
    CreateCollectionResponse(mongo::ChunkVersion collectionVersion);

    static CreateCollectionResponse parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * UUID of the created collection
     */
    const boost::optional<mongo::UUID>& getCollectionUUID() const& { return _collectionUUID; }
    void getCollectionUUID() && = delete;
    void setCollectionUUID(boost::optional<mongo::UUID> value) & {  _collectionUUID = std::move(value);  }

    /**
     * Latest version of the collection
     */
    const mongo::ChunkVersion& getCollectionVersion() const { return _collectionVersion; }
    void setCollectionVersion(mongo::ChunkVersion value) & {  _collectionVersion = std::move(value); _hasCollectionVersion = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    boost::optional<mongo::UUID> _collectionUUID;
    mongo::ChunkVersion _collectionVersion;
    bool _hasCollectionVersion : 1;
};

/**
 * Parameters sent for the set allow migrations command
 */
class SetAllowMigrationsRequest {
public:
    static constexpr auto kAllowMigrationsFieldName = "allowMigrations"_sd;

    SetAllowMigrationsRequest();
    SetAllowMigrationsRequest(bool allowMigrations);

    static SetAllowMigrationsRequest parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * If false balancer rounds should be disabled and migrations commit prohibited.
     */
    bool getAllowMigrations() const { return _allowMigrations; }
    void setAllowMigrations(bool value) & {  _allowMigrations = std::move(value); _hasAllowMigrations = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    bool _allowMigrations;
    bool _hasAllowMigrations : 1;
};

/**
 * The internal createCollection command for a shard.
 */
class ShardsvrCreateCollection {
public:
    using Reply = void;
    static constexpr auto kCreateCollectionRequestFieldName = "CreateCollectionRequest"_sd;
    static constexpr auto kCollationFieldName = "collation"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kInitialSplitPointsFieldName = "initialSplitPoints"_sd;
    static constexpr auto kNumInitialChunksFieldName = "numInitialChunks"_sd;
    static constexpr auto kPresplitHashedZonesFieldName = "presplitHashedZones"_sd;
    static constexpr auto kShardKeyFieldName = "shardKey"_sd;
    static constexpr auto kTimeseriesFieldName = "timeseries"_sd;
    static constexpr auto kUniqueFieldName = "unique"_sd;
    static constexpr auto kCommandName = "_shardsvrCreateCollection"_sd;

    explicit ShardsvrCreateCollection(const NamespaceString nss);

    static ShardsvrCreateCollection parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static ShardsvrCreateCollection parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const NamespaceString& getNamespace() const { return _nss; }

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

    mongo::CreateCollectionRequest _createCollectionRequest;
    std::string _dbName;
    bool _hasDbName : 1;
};

/**
 * Command to create a collection on participant shards, when called, assumes the primary shard is under the critical section for that namespace.
 */
class ShardsvrCreateCollectionParticipant {
public:
    using Reply = void;
    static constexpr auto kCollectionUUIDFieldName = "collectionUUID"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kIdIndexFieldName = "idIndex"_sd;
    static constexpr auto kIndexesFieldName = "indexes"_sd;
    static constexpr auto kOptionsFieldName = "options"_sd;
    static constexpr auto kCommandName = "_shardsvrCreateCollectionParticipant"_sd;

    explicit ShardsvrCreateCollectionParticipant(const NamespaceString nss);
    ShardsvrCreateCollectionParticipant(const NamespaceString nss, std::vector<mongo::BSONObj> indexes, mongo::BSONObj options, mongo::BSONObj idIndex);

    static ShardsvrCreateCollectionParticipant parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static ShardsvrCreateCollectionParticipant parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const NamespaceString& getNamespace() const { return _nss; }

    /**
     * Collection indexes.
     */
    const std::vector<mongo::BSONObj>& getIndexes() const& { return _indexes; }
    void getIndexes() && = delete;
    void setIndexes(std::vector<mongo::BSONObj> value) & {  _indexes = std::move(value); _hasIndexes = true; }

    /**
     * Collection options.
     */
    const mongo::BSONObj& getOptions() const { return _options; }
    void setOptions(mongo::BSONObj value) & {  _options = std::move(value); _hasOptions = true; }

    /**
     * Collection uuid.
     */
    const boost::optional<mongo::UUID>& getCollectionUUID() const& { return _collectionUUID; }
    void getCollectionUUID() && = delete;
    void setCollectionUUID(boost::optional<mongo::UUID> value) & {  _collectionUUID = std::move(value);  }

    /**
     * Id index.
     */
    const mongo::BSONObj& getIdIndex() const { return _idIndex; }
    void setIdIndex(mongo::BSONObj value) & {  _idIndex = std::move(value); _hasIdIndex = true; }

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

    std::vector<mongo::BSONObj> _indexes;
    mongo::BSONObj _options;
    boost::optional<mongo::UUID> _collectionUUID;
    mongo::BSONObj _idIndex;
    std::string _dbName;
    bool _hasIndexes : 1;
    bool _hasOptions : 1;
    bool _hasIdIndex : 1;
    bool _hasDbName : 1;
};

/**
 * Internal command sent to the primary shard of a database to drop it.
 */
class ShardsvrDropDatabase {
public:
    using Reply = void;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kCommandName = "_shardsvrDropDatabase"_sd;

    ShardsvrDropDatabase();

    static ShardsvrDropDatabase parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static ShardsvrDropDatabase parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;


    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;



    std::string _dbName;
    bool _hasDbName : 1;
};

/**
 * Internal command sent to participants shards to drop a database.
 */
class ShardsvrDropDatabaseParticipant {
public:
    using Reply = void;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kCommandName = "_shardsvrDropDatabaseParticipant"_sd;

    ShardsvrDropDatabaseParticipant();

    static ShardsvrDropDatabaseParticipant parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static ShardsvrDropDatabaseParticipant parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;


    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;



    std::string _dbName;
    bool _hasDbName : 1;
};

/**
 * Parser for the _shardsvrDropCollection command
 */
class ShardsvrDropCollection {
public:
    using Reply = void;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kCommandName = "_shardsvrDropCollection"_sd;

    explicit ShardsvrDropCollection(const NamespaceString nss);

    static ShardsvrDropCollection parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static ShardsvrDropCollection parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const NamespaceString& getNamespace() const { return _nss; }

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

    std::string _dbName;
    bool _hasDbName : 1;
};

/**
 * Parser for the _shardsvrDropCollectionParticipant command
 */
class ShardsvrDropCollectionParticipant {
public:
    using Reply = void;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kCommandName = "_shardsvrDropCollectionParticipant"_sd;

    explicit ShardsvrDropCollectionParticipant(const NamespaceString nss);

    static ShardsvrDropCollectionParticipant parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static ShardsvrDropCollectionParticipant parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const NamespaceString& getNamespace() const { return _nss; }

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

    std::string _dbName;
    bool _hasDbName : 1;
};

/**
 * Internal renameCollection command for a shard.
 */
class ShardsvrRenameCollection {
public:
    using Reply = void;
    static constexpr auto kRenameCollectionRequestFieldName = "RenameCollectionRequest"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kDropTargetFieldName = "dropTarget"_sd;
    static constexpr auto kStayTempFieldName = "stayTemp"_sd;
    static constexpr auto kToFieldName = "to"_sd;
    static constexpr auto kCommandName = "_shardsvrRenameCollection"_sd;

    explicit ShardsvrRenameCollection(const NamespaceString nss);

    static ShardsvrRenameCollection parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static ShardsvrRenameCollection parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
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
    std::string _dbName;
    bool _hasDbName : 1;
};

/**
 * Internal setAllowMigrations command for a shard.
 */
class ShardsvrSetAllowMigrations {
public:
    using Reply = void;
    static constexpr auto kSetAllowMigrationsRequestFieldName = "SetAllowMigrationsRequest"_sd;
    static constexpr auto kAllowMigrationsFieldName = "allowMigrations"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kCommandName = "_shardsvrSetAllowMigrations"_sd;

    explicit ShardsvrSetAllowMigrations(const NamespaceString nss);

    static ShardsvrSetAllowMigrations parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static ShardsvrSetAllowMigrations parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const NamespaceString& getNamespace() const { return _nss; }

    /**
     * Parameters sent for the set allow migrations command
     */
    const mongo::SetAllowMigrationsRequest& getSetAllowMigrationsRequest() const { return _setAllowMigrationsRequest; }
    mongo::SetAllowMigrationsRequest& getSetAllowMigrationsRequest() { return _setAllowMigrationsRequest; }
    void setSetAllowMigrationsRequest(mongo::SetAllowMigrationsRequest value) & {  _setAllowMigrationsRequest = std::move(value);  }

    /**
     * If false balancer rounds should be disabled and migrations commit prohibited.
     */
     bool getAllowMigrations() const { return _setAllowMigrationsRequest.getAllowMigrations(); }
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

    mongo::SetAllowMigrationsRequest _setAllowMigrationsRequest;
    std::string _dbName;
    bool _hasDbName : 1;
};

/**
 * Internal command for renaming collection metadata on the CSRS
 */
class ConfigsvrRenameCollectionMetadata {
public:
    using Reply = void;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kOptFromCollectionFieldName = "optFromCollection"_sd;
    static constexpr auto kToFieldName = "to"_sd;
    static constexpr auto kCommandName = "_configsvrRenameCollectionMetadata"_sd;

    explicit ConfigsvrRenameCollectionMetadata(const NamespaceString nss);
    ConfigsvrRenameCollectionMetadata(const NamespaceString nss, mongo::NamespaceString to);

    static ConfigsvrRenameCollectionMetadata parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static ConfigsvrRenameCollectionMetadata parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const NamespaceString& getNamespace() const { return _nss; }

    /**
     * The new namespace for the collection being renamed.
     */
    const mongo::NamespaceString& getTo() const { return _to; }
    void setTo(mongo::NamespaceString value) & {  _to = std::move(value); _hasTo = true; }

    /**
     * Information of the source collection to rename, used only for sharded collection.
     */
    const boost::optional<mongo::CollectionType>& getOptFromCollection() const& { return _optFromCollection; }
    void getOptFromCollection() && = delete;
    void setOptFromCollection(boost::optional<mongo::CollectionType> value) & {  _optFromCollection = std::move(value);  }

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

    mongo::NamespaceString _to;
    boost::optional<mongo::CollectionType> _optFromCollection;
    std::string _dbName;
    bool _hasTo : 1;
    bool _hasDbName : 1;
};

/**
 * The internal reshardCollection command on the shard.
 */
class ShardsvrReshardCollection {
public:
    using Reply = void;
    static constexpr auto kCommandParameterFieldName = "_shardsvrReshardCollection"_sd;
    static constexpr auto k_presetReshardedChunksFieldName = "_presetReshardedChunks"_sd;
    static constexpr auto kCollationFieldName = "collation"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kKeyFieldName = "key"_sd;
    static constexpr auto kNumInitialChunksFieldName = "numInitialChunks"_sd;
    static constexpr auto kUniqueFieldName = "unique"_sd;
    static constexpr auto kZonesFieldName = "zones"_sd;
    static constexpr auto kCommandName = "_shardsvrReshardCollection"_sd;

    explicit ShardsvrReshardCollection(const mongo::NamespaceString commandParameter);
    explicit ShardsvrReshardCollection(const mongo::NamespaceString commandParameter, mongo::BSONObj key);

    static ShardsvrReshardCollection parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static ShardsvrReshardCollection parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const mongo::NamespaceString& getCommandParameter() const { return _commandParameter; }

    /**
     * The index specification document to use as the new shard key.
     */
    const mongo::BSONObj& getKey() const { return _key; }
    void setKey(mongo::BSONObj value) & {  _key = std::move(value); _hasKey = true; }

    /**
     * Whether the shard key index should enforce a unique constraint.
     */
    const boost::optional<bool> getUnique() const& { return _unique; }
    void getUnique() && = delete;
    void setUnique(boost::optional<bool> value) & {  _unique = std::move(value);  }

    /**
     * The number of chunks to create initially.
     */
    const boost::optional<std::int64_t> getNumInitialChunks() const& { return _numInitialChunks; }
    void getNumInitialChunks() && = delete;
    void setNumInitialChunks(boost::optional<std::int64_t> value) & {  _numInitialChunks = std::move(value);  }

    /**
     * The collation to use for the shard key index.
     */
    const boost::optional<mongo::BSONObj>& getCollation() const& { return _collation; }
    void getCollation() && = delete;
    void setCollation(boost::optional<mongo::BSONObj> value) & {  _collation = std::move(value);  }

    /**
     * The zones associated with the new shard key.
     */
    const boost::optional<std::vector<mongo::ReshardingZoneType>>& getZones() const& { return _zones; }
    void getZones() && = delete;
    void setZones(boost::optional<std::vector<mongo::ReshardingZoneType>> value) & {  _zones = std::move(value);  }

    /**
     * "Mapping of chunk ranges to be used as the initial split output. This is only for  testing purposes."
     */
    const boost::optional<std::vector<mongo::ReshardedChunk>>& get_presetReshardedChunks() const& { return __presetReshardedChunks; }
    void get_presetReshardedChunks() && = delete;
    void set_presetReshardedChunks(boost::optional<std::vector<mongo::ReshardedChunk>> value) & {  __presetReshardedChunks = std::move(value);  }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;


    mongo::NamespaceString _commandParameter;

    mongo::BSONObj _key;
    boost::optional<bool> _unique;
    boost::optional<std::int64_t> _numInitialChunks;
    boost::optional<mongo::BSONObj> _collation;
    boost::optional<std::vector<mongo::ReshardingZoneType>> _zones;
    boost::optional<std::vector<mongo::ReshardedChunk>> __presetReshardedChunks;
    std::string _dbName;
    bool _hasKey : 1;
    bool _hasDbName : 1;
};

/**
 * Parser for the _shardsvrRefineCollectionShardKey command
 */
class ShardsvrRefineCollectionShardKey {
public:
    using Reply = void;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kNewShardKeyFieldName = "newShardKey"_sd;
    static constexpr auto kCommandName = "_shardsvrRefineCollectionShardKey"_sd;

    explicit ShardsvrRefineCollectionShardKey(const NamespaceString nss);
    ShardsvrRefineCollectionShardKey(const NamespaceString nss, mongo::KeyPattern newShardKey);

    static ShardsvrRefineCollectionShardKey parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static ShardsvrRefineCollectionShardKey parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const NamespaceString& getNamespace() const { return _nss; }

    /**
     * The index specification document to use as the new shard key.
     */
    const mongo::KeyPattern& getNewShardKey() const { return _newShardKey; }
    void setNewShardKey(mongo::KeyPattern value) & {  _newShardKey = std::move(value); _hasNewShardKey = true; }

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

    mongo::KeyPattern _newShardKey;
    std::string _dbName;
    bool _hasNewShardKey : 1;
    bool _hasDbName : 1;
};

/**
 * The internal createDatabase command on the config server
 */
class ConfigsvrCreateDatabase {
public:
    using Reply = mongo::ConfigsvrCreateDatabaseResponse;
    static constexpr auto kCommandParameterFieldName = "_configsvrCreateDatabase"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kEnableShardingFieldName = "enableSharding"_sd;
    static constexpr auto kPrimaryShardIdFieldName = "primaryShardId"_sd;
    static constexpr auto kCommandName = "_configsvrCreateDatabase"_sd;

    explicit ConfigsvrCreateDatabase(const std::string commandParameter);

    static ConfigsvrCreateDatabase parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static ConfigsvrCreateDatabase parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const StringData getCommandParameter() const& { return _commandParameter; }
    void getCommandParameter() && = delete;

    /**
     * If set, indicates to the system which shard should be used as the primary for the database (if not already created). Otherwise, the system will use the balancer in order to select a primary.
     */
    const boost::optional<StringData> getPrimaryShardId() const& { return boost::optional<StringData>{_primaryShardId}; }
    void getPrimaryShardId() && = delete;
    void setPrimaryShardId(boost::optional<StringData> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get().toString();
        
        _primaryShardId = std::move(_tmpValue);
    } else {
        _primaryShardId = boost::none;
    }
      }

    /**
     * May only be set to 'true'. If set, indicates to the config server that it must turn on the 'enableSharding' bit for that database.
     */
    const boost::optional<bool> getEnableSharding() const& { return _enableSharding; }
    void getEnableSharding() && = delete;
    void setEnableSharding(boost::optional<bool> value) & {  _enableSharding = std::move(value);  }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;


    std::string _commandParameter;

    boost::optional<std::string> _primaryShardId;
    boost::optional<bool> _enableSharding;
    std::string _dbName;
    bool _hasDbName : 1;
};

}  // namespace mongo
