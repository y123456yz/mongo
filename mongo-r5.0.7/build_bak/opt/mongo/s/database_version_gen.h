/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/s/database_version_gen.h --output build/opt/mongo/s/database_version_gen.cpp src/mongo/s/database_version.idl
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
 * A (UUID, Timestamp, int) object that uniquely identifies an incarnation of a database in a cluster and reflects changes to the database's primary shard
 */
class DatabaseVersionBase {
public:
    static constexpr auto kLastModFieldName = "lastMod"_sd;
    static constexpr auto kTimestampFieldName = "timestamp"_sd;
    static constexpr auto kUuidFieldName = "uuid"_sd;

    DatabaseVersionBase();
    DatabaseVersionBase(std::int32_t lastMod);

    static DatabaseVersionBase parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * a unique identifier to distinguish different incarnations of this database. It is optional for parsing purposes and it will be removed in 5.2.
     */
    const boost::optional<mongo::UUID>& getUuid() const& { return _uuid; }
    void getUuid() && = delete;
    void setUuid(boost::optional<mongo::UUID> value) & {  _uuid = std::move(value);  }

    /**
     * Uniquely identifies to distinguish different incarnations of this database It is optional for parsing purposes, because in versions of MongoDB prior to 5.0, this value wasn't being written.
     */
    const boost::optional<mongo::Timestamp>& getTimestamp() const& { return _timestamp; }
    void getTimestamp() && = delete;
    void setTimestamp(boost::optional<mongo::Timestamp> value) & {  _timestamp = std::move(value);  }

    /**
     * an integer which is bumped whenever the database's primary shard changes
     */
    std::int32_t getLastMod() const { return _lastMod; }
    void setLastMod(std::int32_t value) & {  _lastMod = std::move(value); _hasLastMod = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    boost::optional<mongo::UUID> _uuid;
    boost::optional<mongo::Timestamp> _timestamp;
    std::int32_t _lastMod;
    bool _hasLastMod : 1;
};

}  // namespace mongo
