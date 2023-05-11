/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/s/commands/cluster_commands_gen.h --output build/opt/mongo/s/commands/cluster_commands_gen.cpp src/mongo/s/commands/cluster_commands.idl
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
#include "mongo/db/timeseries/timeseries_gen.h"
#include "mongo/db/timeseries/timeseries_global_options.h"
#include "mongo/idl/basic_types.h"
#include "mongo/idl/basic_types_gen.h"
#include "mongo/idl/idl_parser.h"
#include "mongo/idl/server_parameter.h"
#include "mongo/idl/server_parameter_with_storage.h"
#include "mongo/rpc/op_msg.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/util/uuid.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {

/**
 * A struct representing the 'multicast' command's arguments
 */
class ClusterMulticast {
public:
    static constexpr auto kConcurrencyFieldName = "concurrency"_sd;
    static constexpr auto kDbFieldName = "$db"_sd;
    static constexpr auto kMulticastFieldName = "multicast"_sd;
    static constexpr auto kTimeoutFieldName = "timeout"_sd;

    ClusterMulticast();
    ClusterMulticast(mongo::BSONObj multicast, std::string db);

    static ClusterMulticast parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    const mongo::BSONObj& getMulticast() const { return _multicast; }
    void setMulticast(mongo::BSONObj value) & {  _multicast = std::move(value); _hasMulticast = true; }

    const StringData getDb() const& { return _db; }
    void getDb() && = delete;
    void setDb(StringData value) & { auto _tmpValue = value.toString();  _db = std::move(_tmpValue); _hasDb = true; }

    const boost::optional<std::int32_t> getConcurrency() const& { return _concurrency; }
    void getConcurrency() && = delete;
    void setConcurrency(boost::optional<std::int32_t> value) & {  _concurrency = std::move(value);  }

    const boost::optional<std::int32_t> getTimeout() const& { return _timeout; }
    void getTimeout() && = delete;
    void setTimeout(boost::optional<std::int32_t> value) & {  _timeout = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::BSONObj _multicast;
    std::string _db;
    boost::optional<std::int32_t> _concurrency;
    boost::optional<std::int32_t> _timeout;
    bool _hasMulticast : 1;
    bool _hasDb : 1;
};

/**
 * The public shardCollection command on mongos
 */
class ShardCollection {
public:
    static constexpr auto kCollationFieldName = "collation"_sd;
    static constexpr auto kKeyFieldName = "key"_sd;
    static constexpr auto kNumInitialChunksFieldName = "numInitialChunks"_sd;
    static constexpr auto kPresplitHashedZonesFieldName = "presplitHashedZones"_sd;
    static constexpr auto kShardCollectionFieldName = "shardCollection"_sd;
    static constexpr auto kShardcollectionFieldName = "shardcollection"_sd;
    static constexpr auto kTimeseriesFieldName = "timeseries"_sd;
    static constexpr auto kUniqueFieldName = "unique"_sd;

    ShardCollection();
    ShardCollection(mongo::BSONObj key);

    static ShardCollection parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * The namespace of the collection to shard in the form <database>.<collection>.
     */
    const boost::optional<mongo::NamespaceString>& getShardCollection() const& { return _shardCollection; }
    void getShardCollection() && = delete;
    void setShardCollection(boost::optional<mongo::NamespaceString> value) & {  _shardCollection = std::move(value);  }

    /**
     * Same as the previous field, but refers to the deprecated version of this command's name
     */
    const boost::optional<mongo::NamespaceString>& getShardcollection() const& { return _shardcollection; }
    void getShardcollection() && = delete;
    void setShardcollection(boost::optional<mongo::NamespaceString> value) & {  _shardcollection = std::move(value);  }

    /**
     * The index specification document to use as the shard key.
     */
    const mongo::BSONObj& getKey() const { return _key; }
    void setKey(mongo::BSONObj value) & {  _key = std::move(value); _hasKey = true; }

    /**
     * Whether the shard key index should enforce a unique constraint
     */
    bool getUnique() const { return _unique; }
    void setUnique(bool value) & {  _unique = std::move(value);  }

    /**
     * The number of chunks to create initially when sharding an empty collection with a hashed shard key.
     */
    std::int64_t getNumInitialChunks() const { return _numInitialChunks; }
    void setNumInitialChunks(std::int64_t value) & {  _numInitialChunks = std::move(value);  }

    /**
     * True if the chunks should be pre-split based on the existing zones when sharding a collection with hashed shard key
     */
    bool getPresplitHashedZones() const { return _presplitHashedZones; }
    void setPresplitHashedZones(bool value) & {  _presplitHashedZones = std::move(value);  }

    /**
     * The collation to use for the shard key index.
     */
    const boost::optional<mongo::BSONObj>& getCollation() const& { return _collation; }
    void getCollation() && = delete;
    void setCollation(boost::optional<mongo::BSONObj> value) & {  _collation = std::move(value);  }

    /**
     * The options to create the time-series collection with.
     */
    const boost::optional<mongo::TimeseriesOptions>& getTimeseries() const& { return _timeseries; }
    void getTimeseries() && = delete;
    void setTimeseries(boost::optional<mongo::TimeseriesOptions> value) & {  _timeseries = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    boost::optional<mongo::NamespaceString> _shardCollection;
    boost::optional<mongo::NamespaceString> _shardcollection;
    mongo::BSONObj _key;
    bool _unique{false};
    std::int64_t _numInitialChunks{0};
    bool _presplitHashedZones{false};
    boost::optional<mongo::BSONObj> _collation;
    boost::optional<mongo::TimeseriesOptions> _timeseries;
    bool _hasKey : 1;
};

constexpr auto kKillSessionsMaxConcurrencyDefault = 100;

extern int gKillSessionsMaxConcurrency;
constexpr auto kKillSessionsPerHostTimeoutMSDefault = 60000;

extern int gKillSessionsPerHostTimeoutMS;
}  // namespace mongo
