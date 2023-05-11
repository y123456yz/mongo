/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/s/request_types/cleanup_reshard_collection_gen.h --output build/opt/mongo/s/request_types/cleanup_reshard_collection_gen.cpp src/mongo/s/request_types/cleanup_reshard_collection.idl
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
#include "mongo/db/namespace_string.h"
#include "mongo/idl/basic_types.h"
#include "mongo/idl/basic_types_gen.h"
#include "mongo/idl/idl_parser.h"
#include "mongo/rpc/op_msg.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/util/uuid.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {

/**
 * The public cleanupReshardCollection command on mongos.
 */
class CleanupReshardCollection {
public:
    using Reply = void;
    static constexpr auto kCommandParameterFieldName = "cleanupReshardCollection"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kCommandName = "cleanupReshardCollection"_sd;

    explicit CleanupReshardCollection(const mongo::NamespaceString commandParameter);

    static CleanupReshardCollection parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static CleanupReshardCollection parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const mongo::NamespaceString& getCommandParameter() const { return _commandParameter; }

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

    std::string _dbName;
    bool _hasDbName : 1;
};

/**
 * The internal cleanupReshardCollection command on the config server.
 */
class ConfigsvrCleanupReshardCollection {
public:
    using Reply = void;
    static constexpr auto kCommandParameterFieldName = "_configsvrCleanupReshardCollection"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kCommandName = "_configsvrCleanupReshardCollection"_sd;

    explicit ConfigsvrCleanupReshardCollection(const mongo::NamespaceString commandParameter);

    static ConfigsvrCleanupReshardCollection parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static ConfigsvrCleanupReshardCollection parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const mongo::NamespaceString& getCommandParameter() const { return _commandParameter; }

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

    std::string _dbName;
    bool _hasDbName : 1;
};

/**
 * The internal cleanupReshardCollection command on the shard server.
 */
class ShardsvrCleanupReshardCollection {
public:
    using Reply = void;
    static constexpr auto kCommandParameterFieldName = "_shardsvrCleanupReshardCollection"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kReshardingUUIDFieldName = "reshardingUUID"_sd;
    static constexpr auto kCommandName = "_shardsvrCleanupReshardCollection"_sd;

    explicit ShardsvrCleanupReshardCollection(const mongo::NamespaceString commandParameter);
    explicit ShardsvrCleanupReshardCollection(const mongo::NamespaceString commandParameter, mongo::UUID reshardingUUID);

    static ShardsvrCleanupReshardCollection parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static ShardsvrCleanupReshardCollection parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const mongo::NamespaceString& getCommandParameter() const { return _commandParameter; }

    /**
     * Identifier for a resharding operation.
     */
    const mongo::UUID& getReshardingUUID() const { return _reshardingUUID; }
    void setReshardingUUID(mongo::UUID value) & {  _reshardingUUID = std::move(value); _hasReshardingUUID = true; }

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

    mongo::UUID _reshardingUUID;
    std::string _dbName;
    bool _hasReshardingUUID : 1;
    bool _hasDbName : 1;
};

}  // namespace mongo
