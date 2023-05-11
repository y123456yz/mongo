/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/repl/repl_set_test_egress_gen.h --output build/opt/mongo/db/repl/repl_set_test_egress_gen.cpp src/mongo/db/repl/repl_set_test_egress.idl
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
 * Result of attempting to connect to cluster member
 */
class ReplSetTestEgressReply {
public:
    static constexpr auto kTargetFieldName = "target"_sd;

    ReplSetTestEgressReply();
    ReplSetTestEgressReply(std::string target);

    static ReplSetTestEgressReply parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Actual member connected to
     */
    const StringData getTarget() const& { return _target; }
    void getTarget() && = delete;
    void setTarget(StringData value) & { auto _tmpValue = value.toString();  _target = std::move(_tmpValue); _hasTarget = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    std::string _target;
    bool _hasTarget : 1;
};

/**
 * Attempt to connect to a cluster member
 */
class ReplSetTestEgress {
public:
    using Reply = void;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kTargetFieldName = "target"_sd;
    static constexpr auto kTimeoutSecsFieldName = "timeoutSecs"_sd;
    static constexpr auto kCommandName = "replSetTestEgress"_sd;

    ReplSetTestEgress();

    static ReplSetTestEgress parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static ReplSetTestEgress parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;


    /**
     * Member address to connect and authenticate to, empty to select random member
     */
    const boost::optional<StringData> getTarget() const& { return boost::optional<StringData>{_target}; }
    void getTarget() && = delete;
    void setTarget(boost::optional<StringData> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get().toString();
        
        _target = std::move(_tmpValue);
    } else {
        _target = boost::none;
    }
      }

    /**
     * Maximum amount of time to wait for connection (seconds)
     */
    std::int32_t getTimeoutSecs() const { return _timeoutSecs; }
    void setTimeoutSecs(std::int32_t value) & { validateTimeoutSecs(value); _timeoutSecs = std::move(value);  }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    void validateTimeoutSecs(const std::int32_t value);
    void validateTimeoutSecs(IDLParserErrorContext& ctxt, const std::int32_t value);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;



    boost::optional<std::string> _target;
    std::int32_t _timeoutSecs{5};
    std::string _dbName;
    bool _hasDbName : 1;
};

}  // namespace repl
}  // namespace mongo
