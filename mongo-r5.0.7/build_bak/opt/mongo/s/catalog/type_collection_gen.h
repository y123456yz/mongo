/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/s/catalog/type_collection_gen.h --output build/opt/mongo/s/catalog/type_collection_gen.cpp src/mongo/s/catalog/type_collection.idl
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
 * Represents the layout and contents of documents contained in the config server's config.collections collection.
 */
class CollectionTypeBase {
public:
    static constexpr auto kNoBalanceFieldName = "noBalance"_sd;
    static constexpr auto kNssFieldName = "_id"_sd;
    static constexpr auto kPermitMigrationsFieldName = "permitMigrations"_sd;
    static constexpr auto kPre22CompatibleEpochFieldName = "lastmodEpoch"_sd;
    static constexpr auto kPre50CompatibleAllowMigrationsFieldName = "allowMigrations"_sd;
    static constexpr auto kPre50CompatibleDefaultCollationFieldName = "defaultCollation"_sd;
    static constexpr auto kPre50CompatibleDroppedFieldName = "dropped"_sd;
    static constexpr auto kPre50CompatibleKeyPatternFieldName = "key"_sd;
    static constexpr auto kPre50CompatibleUuidFieldName = "uuid"_sd;
    static constexpr auto kReshardingFieldsFieldName = "reshardingFields"_sd;
    static constexpr auto kTimeseriesFieldsFieldName = "timeseriesFields"_sd;
    static constexpr auto kTimestampFieldName = "timestamp"_sd;
    static constexpr auto kUniqueFieldName = "unique"_sd;
    static constexpr auto kUpdatedAtFieldName = "lastmod"_sd;

    CollectionTypeBase();
    CollectionTypeBase(mongo::NamespaceString nss, mongo::Date_t updatedAt);

    static CollectionTypeBase parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * The full namespace (with the database prefix).
     */
    const mongo::NamespaceString& getNss() const { return _nss; }
    void setNss(mongo::NamespaceString value) & {  _nss = std::move(value); _hasNss = true; }

            /**
             * Uniquely identifies this incarnation of the collection. Only changes in case of drop and create, or shard key refine.
    It is optional for parsing purposes, because in versions of MongoDB prior to 2.2, this value wasn't being written. In such cases, it will default to an all-zero OID.
             */
    const boost::optional<mongo::OID>& getPre22CompatibleEpoch() const& { return _pre22CompatibleEpoch; }
    void getPre22CompatibleEpoch() && = delete;
    void setPre22CompatibleEpoch(boost::optional<mongo::OID> value) & {  _pre22CompatibleEpoch = std::move(value);  }

    /**
     * Contains the time of when the collection was either created, or if dropped = true, when it was dropped.
     */
    const mongo::Date_t& getUpdatedAt() const { return _updatedAt; }
    void setUpdatedAt(mongo::Date_t value) & {  _updatedAt = std::move(value); _hasUpdatedAt = true; }

            /**
             * Uniquely identifies this incarnation of the collection. Only changes in case of drop and create, or shard key refine. This field will store the ClusterTime of the Config Server when the collection was created or it's shard key last refined. Because timestamps are comparable, we are able to define a total order in time in the collection. This field will replace Epoch, which are not comparable.
    It is optional for parsing purposes, because in versions of MongoDB prior to 5.0, this value wasn't being written.
             */
    const boost::optional<mongo::Timestamp>& getTimestamp() const& { return _timestamp; }
    void getTimestamp() && = delete;
    void setTimestamp(boost::optional<mongo::Timestamp> value) & {  _timestamp = std::move(value);  }

            /**
             * The UUID that will be used to create the local collection on each of the shards which have chunks.
    It is optional for parsing purposes, because in versions of MongoDB prior to 5.0, this value would be missing for entries where 'dropped' is set to true, because dropped collections' entries were being written as dropped with certain fields missing instead of deleted.
             */
    const boost::optional<mongo::UUID>& getPre50CompatibleUuid() const& { return _pre50CompatibleUuid; }
    void getPre50CompatibleUuid() && = delete;
    void setPre50CompatibleUuid(boost::optional<mongo::UUID> value) & {  _pre50CompatibleUuid = std::move(value);  }

    /**
     * Legacy (pre 5.0 only) field, which indicates that the collection is dropped
     */
    const boost::optional<bool> getPre50CompatibleDropped() const& { return _pre50CompatibleDropped; }
    void getPre50CompatibleDropped() && = delete;
    void setPre50CompatibleDropped(boost::optional<bool> value) & {  _pre50CompatibleDropped = std::move(value);  }

            /**
             * The shard key pattern for the collection.
    It is optional for parsing purposes, because in versions of MongoDB prior to 5.0, this value would be missing for entries where 'dropped' is set to true, because dropped collections' entries were being written as dropped with certain fields missing instead of deleted.
             */
    const boost::optional<mongo::KeyPattern>& getPre50CompatibleKeyPattern() const& { return _pre50CompatibleKeyPattern; }
    void getPre50CompatibleKeyPattern() && = delete;
    void setPre50CompatibleKeyPattern(boost::optional<mongo::KeyPattern> value) & {  _pre50CompatibleKeyPattern = std::move(value);  }

            /**
             * Optional collection default collation. If missing or set to the empty BSON, implies simple collation.
    It is optional for serialisation purposes, because in versions of MongoDB prior to 5.0, this value must be missing for the default (empty BSON) collation.
             */
    const boost::optional<mongo::BSONObj>& getPre50CompatibleDefaultCollation() const& { return _pre50CompatibleDefaultCollation; }
    void getPre50CompatibleDefaultCollation() && = delete;
    void setPre50CompatibleDefaultCollation(boost::optional<mongo::BSONObj> value) & {  _pre50CompatibleDefaultCollation = std::move(value);  }

    /**
     * Uniqueness of the sharding key.
     */
    bool getUnique() const { return _unique; }
    void setUnique(bool value) & {  _unique = std::move(value);  }

    /**
     * Consulted by the Balancer only and indicates whether this collection should be considered for balancing or not.
     */
    bool getNoBalance() const { return _noBalance; }
    void setNoBalance(bool value) & {  _noBalance = std::move(value);  }

    /**
     * Resharding-related fields. Only set when this collection is either the original collection undergoing a resharding operation or this collection is the temporary resharding collection.
     */
    const boost::optional<mongo::TypeCollectionReshardingFields>& getReshardingFields() const& { return _reshardingFields; }
    void getReshardingFields() && = delete;
    void setReshardingFields(boost::optional<mongo::TypeCollectionReshardingFields> value) & {  _reshardingFields = std::move(value);  }

            /**
             * Whether this collection allows chunks to move. It is required by almost all DDL operations in order to guarantee that the set of shards, which comprise a collection will not change.
    If the flag is not present it defaults to true.
    It is optional for serialisation purposes, because in versions of MongoDB prior to 5.0, this value would be missing.
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

    /**
     * DEPRECATED flag that determines wether this collection allows chunks to move. This will only prevent migration from committing and new balancer rounds, this flag will not be loaded by shards.
     */
    const boost::optional<bool> getPermitMigrations() const& { return _permitMigrations; }
    void getPermitMigrations() && = delete;
    void setPermitMigrations(boost::optional<bool> value) & {  _permitMigrations = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::NamespaceString _nss;
    boost::optional<mongo::OID> _pre22CompatibleEpoch;
    mongo::Date_t _updatedAt;
    boost::optional<mongo::Timestamp> _timestamp;
    boost::optional<mongo::UUID> _pre50CompatibleUuid;
    boost::optional<bool> _pre50CompatibleDropped;
    boost::optional<mongo::KeyPattern> _pre50CompatibleKeyPattern;
    boost::optional<mongo::BSONObj> _pre50CompatibleDefaultCollation;
    bool _unique{false};
    bool _noBalance{false};
    boost::optional<mongo::TypeCollectionReshardingFields> _reshardingFields;
    boost::optional<bool> _pre50CompatibleAllowMigrations;
    boost::optional<mongo::TypeCollectionTimeseriesFields> _timeseriesFields;
    boost::optional<bool> _permitMigrations;
    bool _hasNss : 1;
    bool _hasUpdatedAt : 1;
};

}  // namespace mongo
