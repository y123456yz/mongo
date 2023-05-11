/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/repl/optime_base_gen.h --output build/opt/mongo/db/repl/optime_base_gen.cpp src/mongo/db/repl/optime_base.idl
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
namespace repl {

/**
 * A document that stores the logical time-related fields in an oplog entry. Should never be used directly in server code. Instead, create an instance of OpTime.
 */
class OpTimeBase {
public:
    static constexpr auto kTermFieldName = "t"_sd;
    static constexpr auto kTimestampFieldName = "ts"_sd;

    OpTimeBase();
    OpTimeBase(mongo::Timestamp timestamp);

    static OpTimeBase parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * The time when the oplog entry was created
     */
    const mongo::Timestamp& getTimestamp() const { return _timestamp; }
    void setTimestamp(mongo::Timestamp value) & {  _timestamp = std::move(value); _hasTimestamp = true; }

    /**
     * The term of the primary that created the oplog entry
     */
    const boost::optional<std::int64_t> getTerm() const& { return _term; }
    void getTerm() && = delete;
    void setTerm(boost::optional<std::int64_t> value) & {  _term = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::Timestamp _timestamp;
    boost::optional<std::int64_t> _term;
    bool _hasTimestamp : 1;
};

}  // namespace repl
}  // namespace mongo
