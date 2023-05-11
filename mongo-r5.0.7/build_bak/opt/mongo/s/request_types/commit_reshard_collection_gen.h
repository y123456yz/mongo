/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/s/request_types/commit_reshard_collection_gen.h --output build/opt/mongo/s/request_types/commit_reshard_collection_gen.cpp src/mongo/s/request_types/commit_reshard_collection.idl
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
 * The public commitReshardCollection command on mongos.
 */
class CommitReshardCollection {
public:
    using Reply = void;
    static constexpr auto kCommandParameterFieldName = "commitReshardCollection"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kCommandName = "commitReshardCollection"_sd;

    explicit CommitReshardCollection(const mongo::NamespaceString commandParameter);

    static CommitReshardCollection parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static CommitReshardCollection parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
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
 * The internal commitReshardCollection command on the config server.
 */
class ConfigsvrCommitReshardCollection {
public:
    using Reply = void;
    static constexpr auto kCommandParameterFieldName = "_configsvrCommitReshardCollection"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kCommandName = "_configsvrCommitReshardCollection"_sd;

    explicit ConfigsvrCommitReshardCollection(const mongo::NamespaceString commandParameter);

    static ConfigsvrCommitReshardCollection parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static ConfigsvrCommitReshardCollection parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
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
 * The internal commitReshardCollection command on the shard server.
 */
class ShardsvrCommitReshardCollection {
public:
    using Reply = void;
    static constexpr auto kCommandParameterFieldName = "_shardsvrCommitReshardCollection"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kReshardingUUIDFieldName = "reshardingUUID"_sd;
    static constexpr auto kCommandName = "_shardsvrCommitReshardCollection"_sd;

    explicit ShardsvrCommitReshardCollection(const mongo::NamespaceString commandParameter);
    explicit ShardsvrCommitReshardCollection(const mongo::NamespaceString commandParameter, mongo::UUID reshardingUUID);

    static ShardsvrCommitReshardCollection parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static ShardsvrCommitReshardCollection parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const mongo::NamespaceString& getCommandParameter() const { return _commandParameter; }

    /**
     * The UUID for this resharding operation
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
