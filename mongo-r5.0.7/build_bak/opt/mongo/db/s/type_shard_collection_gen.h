/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/s/type_shard_collection_gen.h --output build/opt/mongo/db/s/type_shard_collection_gen.cpp src/mongo/db/s/type_shard_collection.idl
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
#include "mongo/db/timeseries/timeseries_global_options.h"
#include "mongo/idl/basic_types.h"
#include "mongo/idl/basic_types_gen.h"
#include "mongo/idl/idl_parser.h"
#include "mongo/rpc/op_msg.h"
#include "mongo/s/chunk_version.h"
#include "mongo/s/resharding/type_collection_fields_gen.h"
#include "mongo/s/shard_id.h"
#include "mongo/s/type_collection_timeseries_fields_gen.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/util/uuid.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {

/**
 * Represents the layout and contents of documents contained in the shard server's config.cache.collections collection.
 */
class ShardCollectionTypeBase {
public:
    static constexpr auto kDefaultCollationFieldName = "defaultCollation"_sd;
    static constexpr auto kEnterCriticalSectionCounterFieldName = "enterCriticalSectionCounter"_sd;
    static constexpr auto kEpochFieldName = "epoch"_sd;
    static constexpr auto kKeyPatternFieldName = "key"_sd;
    static constexpr auto kLastRefreshedCollectionVersionFieldName = "lastRefreshedCollectionVersion"_sd;
    static constexpr auto kNssFieldName = "_id"_sd;
    static constexpr auto kPre50CompatibleAllowMigrationsFieldName = "allowMigrations"_sd;
    static constexpr auto kRefreshingFieldName = "refreshing"_sd;
    static constexpr auto kReshardingFieldsFieldName = "reshardingFields"_sd;
    static constexpr auto kTimeseriesFieldsFieldName = "timeseriesFields"_sd;
    static constexpr auto kTimestampFieldName = "timestamp"_sd;
    static constexpr auto kUniqueFieldName = "unique"_sd;
    static constexpr auto kUuidFieldName = "uuid"_sd;

    ShardCollectionTypeBase();
    ShardCollectionTypeBase(mongo::NamespaceString nss, mongo::OID epoch, mongo::UUID uuid, mongo::KeyPattern keyPattern, bool unique);

    static ShardCollectionTypeBase parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * The full namespace (with the database prefix).
     */
    const mongo::NamespaceString& getNss() const { return _nss; }
    void setNss(mongo::NamespaceString value) & {  _nss = std::move(value); _hasNss = true; }

    /**
     * Uniquely identifies this instance of the collection, in case of drop/create or shard key refine.
     */
    const mongo::OID& getEpoch() const { return _epoch; }
    void setEpoch(mongo::OID value) & {  _epoch = std::move(value); _hasEpoch = true; }

            /**
             * Uniquely identifies this incarnation of the collection. Only changes in case of drop and create, or shard key refine. This field will store the ClusterTime of the Config Server when the collection was created or it's shard key last refined. Because timestamps are comparable, we are able to define a total order in time in the collection. This field will replace Epoch, which are not comparable.
    It is optional for parsing purposes, because in versions of MongoDB prior to 5.0, this value wasn't being written.
             */
    const boost::optional<mongo::Timestamp>& getTimestamp() const& { return _timestamp; }
    void getTimestamp() && = delete;
    void setTimestamp(boost::optional<mongo::Timestamp> value) & {  _timestamp = std::move(value);  }

    /**
     * The UUID that will be used to create the local collection on each of the shards which have chunks.
     */
    const mongo::UUID& getUuid() const { return _uuid; }
    void setUuid(mongo::UUID value) & {  _uuid = std::move(value); _hasUuid = true; }

    /**
     * Sharding key. If collection is dropped, this is no longer required.
     */
    const mongo::KeyPattern& getKeyPattern() const { return _keyPattern; }
    void setKeyPattern(mongo::KeyPattern value) & {  _keyPattern = std::move(value); _hasKeyPattern = true; }

    /**
     * Optional collection default collation. If missing or set to the empty BSON, implies simple collation.
     */
    const mongo::BSONObj& getDefaultCollation() const { return _defaultCollation; }
    void setDefaultCollation(mongo::BSONObj value) & {  _defaultCollation = std::move(value);  }

    /**
     * Uniqueness of the sharding key.
     */
    bool getUnique() const { return _unique; }
    void setUnique(bool value) & {  _unique = std::move(value); _hasUnique = true; }

    /**
     * Set by primaries and used by shard secondaries to safely refresh chunk metadata. Indicates whether the chunks collection is current being updated, which means read results won't provide a complete view of the chunk metadata.
     */
    const boost::optional<bool> getRefreshing() const& { return _refreshing; }
    void getRefreshing() && = delete;
    void setRefreshing(boost::optional<bool> value) & {  _refreshing = std::move(value);  }

    /**
     * Set by primaries and used by shard secondaries to safely refresh chunk metadata. Indicates the collection version of the last complete chunk metadata refresh, and is used to indicate if a refresh occurred if the value is different than when the caller last checked -- because 'refreshing' will be false both before and after a refresh occurs.
     */
    const boost::optional<mongo::ChunkVersion>& getLastRefreshedCollectionVersion() const& { return _lastRefreshedCollectionVersion; }
    void getLastRefreshedCollectionVersion() && = delete;
    void setLastRefreshedCollectionVersion(boost::optional<mongo::ChunkVersion> value) & {  _lastRefreshedCollectionVersion = std::move(value);  }

    /**
     * Currently just an OpObserver signal, thus otherwise ignored.
     */
    const boost::optional<std::int32_t> getEnterCriticalSectionCounter() const& { return _enterCriticalSectionCounter; }
    void getEnterCriticalSectionCounter() && = delete;
    void setEnterCriticalSectionCounter(boost::optional<std::int32_t> value) & {  _enterCriticalSectionCounter = std::move(value);  }

    /**
     * Resharding-related fields. Only set when this collection is either the original collection undergoing a resharding operation or this collection is the temporary resharding collection.
     */
    const boost::optional<mongo::TypeCollectionReshardingFields>& getReshardingFields() const& { return _reshardingFields; }
    void getReshardingFields() && = delete;
    void setReshardingFields(boost::optional<mongo::TypeCollectionReshardingFields> value) & {  _reshardingFields = std::move(value);  }

            /**
             * Whether this collection allows chunks to move. It is required by almost all DDL operations in order to guarantee that the set of shards, which comprise a collection will not change.
    If the flag is not present it defaults to true.
    It must be optional and not present when running in FCV 4.4, because binaries prior to 5.0 use strict parsing and will fail.
             */
    const boost::optional<bool> getPre50CompatibleAllowMigrations() const& { return _pre50CompatibleAllowMigrations; }
    void getPre50CompatibleAllowMigrations() && = delete;
    void setPre50CompatibleAllowMigrations(boost::optional<bool> value) & {  _pre50CompatibleAllowMigrations = std::move(value);  }

    /**
     * Time-series collection fields. Only set when this is a time-series buckets collection.
     */
    const boost::optional<mongo::TypeCollectionTimeseriesFields>& getTimeseriesFields() const& { return _timeseriesFields; }
    void getTimeseriesFields() && = delete;
    void setTimeseriesFields(boost::optional<mongo::TypeCollectionTimeseriesFields> value) & {  _timeseriesFields = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::NamespaceString _nss;
    mongo::OID _epoch;
    boost::optional<mongo::Timestamp> _timestamp;
    mongo::UUID _uuid;
    mongo::KeyPattern _keyPattern;
    mongo::BSONObj _defaultCollation{BSONObj()};
    bool _unique;
    boost::optional<bool> _refreshing;
    boost::optional<mongo::ChunkVersion> _lastRefreshedCollectionVersion;
    boost::optional<std::int32_t> _enterCriticalSectionCounter;
    boost::optional<mongo::TypeCollectionReshardingFields> _reshardingFields;
    boost::optional<bool> _pre50CompatibleAllowMigrations;
    boost::optional<mongo::TypeCollectionTimeseriesFields> _timeseriesFields;
    bool _hasNss : 1;
    bool _hasEpoch : 1;
    bool _hasUuid : 1;
    bool _hasKeyPattern : 1;
    bool _hasUnique : 1;
};

}  // namespace mongo
