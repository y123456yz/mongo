/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/s/request_types/set_allow_migrations_gen.h --output build/opt/mongo/s/request_types/set_allow_migrations_gen.cpp src/mongo/s/request_types/set_allow_migrations.idl
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
 * internal setAllowMigrations command for config server
 */
class ConfigsvrSetAllowMigrations {
public:
    using Reply = void;
    static constexpr auto kCommandParameterFieldName = "_configsvrSetAllowMigrations"_sd;
    static constexpr auto kAllowMigrationsFieldName = "allowMigrations"_sd;
    static constexpr auto kCollectionUUIDFieldName = "collectionUUID"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kCommandName = "_configsvrSetAllowMigrations"_sd;

    explicit ConfigsvrSetAllowMigrations(const mongo::NamespaceString commandParameter);
    explicit ConfigsvrSetAllowMigrations(const mongo::NamespaceString commandParameter, bool allowMigrations);

    static ConfigsvrSetAllowMigrations parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static ConfigsvrSetAllowMigrations parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const mongo::NamespaceString& getCommandParameter() const { return _commandParameter; }

    /**
     * The new allowMigrations flag state to be set.
     */
    bool getAllowMigrations() const { return _allowMigrations; }
    void setAllowMigrations(bool value) & {  _allowMigrations = std::move(value); _hasAllowMigrations = true; }

    /**
     * The uuid of the collection.
     */
    const boost::optional<mongo::UUID>& getCollectionUUID() const& { return _collectionUUID; }
    void getCollectionUUID() && = delete;
    void setCollectionUUID(boost::optional<mongo::UUID> value) & {  _collectionUUID = std::move(value);  }

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

    bool _allowMigrations;
    boost::optional<mongo::UUID> _collectionUUID;
    std::string _dbName;
    bool _hasAllowMigrations : 1;
    bool _hasDbName : 1;
};

/**
 * user faced setAllowMigrations command
 */
class SetAllowMigrations {
public:
    using Reply = void;
    static constexpr auto kCommandParameterFieldName = "setAllowMigrations"_sd;
    static constexpr auto kSetAllowMigrationsRequestFieldName = "SetAllowMigrationsRequest"_sd;
    static constexpr auto kAllowMigrationsFieldName = "allowMigrations"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kCommandName = "setAllowMigrations"_sd;

    explicit SetAllowMigrations(const mongo::NamespaceString commandParameter);

    static SetAllowMigrations parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static SetAllowMigrations parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const mongo::NamespaceString& getCommandParameter() const { return _commandParameter; }

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


    mongo::NamespaceString _commandParameter;

    mongo::SetAllowMigrationsRequest _setAllowMigrationsRequest;
    std::string _dbName;
    bool _hasDbName : 1;
};

}  // namespace mongo
