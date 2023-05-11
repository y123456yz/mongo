/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/s/request_types/reshard_collection_gen.h --output build/opt/mongo/s/request_types/reshard_collection_gen.cpp src/mongo/s/request_types/reshard_collection.idl
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
#include "mongo/idl/basic_types_gen.h"
#include "mongo/idl/idl_parser.h"
#include "mongo/rpc/op_msg.h"
#include "mongo/s/resharding/common_types_gen.h"
#include "mongo/s/shard_id.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/util/uuid.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {

/**
 * The public reshardCollection command on mongos.
 */
class ReshardCollection {
public:
    using Reply = void;
    static constexpr auto kCommandParameterFieldName = "reshardCollection"_sd;
    static constexpr auto k_presetReshardedChunksFieldName = "_presetReshardedChunks"_sd;
    static constexpr auto kCollationFieldName = "collation"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kKeyFieldName = "key"_sd;
    static constexpr auto kNumInitialChunksFieldName = "numInitialChunks"_sd;
    static constexpr auto kUniqueFieldName = "unique"_sd;
    static constexpr auto kZonesFieldName = "zones"_sd;
    static constexpr auto kCommandName = "reshardCollection"_sd;

    explicit ReshardCollection(const mongo::NamespaceString commandParameter);
    explicit ReshardCollection(const mongo::NamespaceString commandParameter, mongo::BSONObj key);

    static ReshardCollection parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static ReshardCollection parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
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
     * The zones for the new shard key.
     */
    const boost::optional<std::vector<mongo::ReshardingZoneType>>& getZones() const& { return _zones; }
    void getZones() && = delete;
    void setZones(boost::optional<std::vector<mongo::ReshardingZoneType>> value) & {  _zones = std::move(value);  }

    /**
     * Mapping of chunk ranges. This is only for testing purposes.
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
 * The internal reshardCollection command on the config server.
 */
class ConfigsvrReshardCollection {
public:
    using Reply = void;
    static constexpr auto kCommandParameterFieldName = "_configsvrReshardCollection"_sd;
    static constexpr auto k_presetReshardedChunksFieldName = "_presetReshardedChunks"_sd;
    static constexpr auto kCollationFieldName = "collation"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kKeyFieldName = "key"_sd;
    static constexpr auto kNumInitialChunksFieldName = "numInitialChunks"_sd;
    static constexpr auto kUniqueFieldName = "unique"_sd;
    static constexpr auto kZonesFieldName = "zones"_sd;
    static constexpr auto kCommandName = "_configsvrReshardCollection"_sd;

    explicit ConfigsvrReshardCollection(const mongo::NamespaceString commandParameter);
    explicit ConfigsvrReshardCollection(const mongo::NamespaceString commandParameter, mongo::BSONObj key);

    static ConfigsvrReshardCollection parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static ConfigsvrReshardCollection parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
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

}  // namespace mongo
