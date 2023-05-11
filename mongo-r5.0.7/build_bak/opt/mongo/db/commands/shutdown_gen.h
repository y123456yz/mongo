/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/commands/shutdown_gen.h --output build/opt/mongo/db/commands/shutdown_gen.cpp src/mongo/db/commands/shutdown.idl
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
 * Shutdown the database
 */
class ShutdownRequest {
public:
    using Reply = void;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kForceFieldName = "force"_sd;
    static constexpr auto kTimeoutSecsFieldName = "timeoutSecs"_sd;
    static constexpr auto kCommandName = "shutdown"_sd;

    ShutdownRequest();

    static ShutdownRequest parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static ShutdownRequest parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;


    /**
     * True if we want to step down a primary node immediately
     */
    bool getForce() const { return _force; }
    void setForce(bool value) & {  _force = std::move(value);  }

    /**
     * Time permitted for stepdown and quiesce mode
     */
    std::int64_t getTimeoutSecs() const { return _timeoutSecs; }
    void setTimeoutSecs(std::int64_t value) & {  _timeoutSecs = std::move(value);  }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;



    bool _force{false};
    std::int64_t _timeoutSecs{15};
    std::string _dbName;
    bool _hasDbName : 1;
};

}  // namespace mongo
