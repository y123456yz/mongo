/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/s/resharding_test_commands_gen.h --output build/opt/mongo/db/s/resharding_test_commands_gen.cpp src/mongo/db/s/resharding_test_commands.idl
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
#include "mongo/s/shard_id.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/util/uuid.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {

/**
 * The 'testReshardCloneCollection' command.
 */
class TestReshardCloneCollection {
public:
    using Reply = void;
    static constexpr auto kCommandParameterFieldName = "testReshardCloneCollection"_sd;
    static constexpr auto kAtClusterTimeFieldName = "atClusterTime"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kOutputNsFieldName = "outputNs"_sd;
    static constexpr auto kShardIdFieldName = "shardId"_sd;
    static constexpr auto kShardKeyFieldName = "shardKey"_sd;
    static constexpr auto kUuidFieldName = "uuid"_sd;
    static constexpr auto kCommandName = "testReshardCloneCollection"_sd;

    explicit TestReshardCloneCollection(const mongo::NamespaceString commandParameter);
    explicit TestReshardCloneCollection(const mongo::NamespaceString commandParameter, mongo::Timestamp atClusterTime, mongo::NamespaceString outputNs, mongo::BSONObj shardKey, mongo::ShardId shardId, mongo::UUID uuid);

    static TestReshardCloneCollection parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static TestReshardCloneCollection parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const mongo::NamespaceString& getCommandParameter() const { return _commandParameter; }

    /**
     * The snapshot time to clone the collection from the donor shards at.
     */
    const mongo::Timestamp& getAtClusterTime() const { return _atClusterTime; }
    void setAtClusterTime(mongo::Timestamp value) & {  _atClusterTime = std::move(value); _hasAtClusterTime = true; }

    /**
     * The namespace to write the cloned contents into.
     */
    const mongo::NamespaceString& getOutputNs() const { return _outputNs; }
    void setOutputNs(mongo::NamespaceString value) & {  _outputNs = std::move(value); _hasOutputNs = true; }

    /**
     * The new shard key pattern.
     */
    const mongo::BSONObj& getShardKey() const { return _shardKey; }
    void setShardKey(mongo::BSONObj value) & {  _shardKey = std::move(value); _hasShardKey = true; }

    /**
     * "The recipient shard to act as when cloning the collection from the donor shards."
     */
    const mongo::ShardId& getShardId() const { return _shardId; }
    void setShardId(mongo::ShardId value) & {  _shardId = std::move(value); _hasShardId = true; }

    /**
     * The source collection's UUID.
     */
    const mongo::UUID& getUuid() const { return _uuid; }
    void setUuid(mongo::UUID value) & {  _uuid = std::move(value); _hasUuid = true; }

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

    mongo::Timestamp _atClusterTime;
    mongo::NamespaceString _outputNs;
    mongo::BSONObj _shardKey;
    mongo::ShardId _shardId;
    mongo::UUID _uuid;
    std::string _dbName;
    bool _hasAtClusterTime : 1;
    bool _hasOutputNs : 1;
    bool _hasShardKey : 1;
    bool _hasShardId : 1;
    bool _hasUuid : 1;
    bool _hasDbName : 1;
};

}  // namespace mongo
