/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/commands/generic_gen.h --output build/opt/mongo/db/commands/generic_gen.cpp src/mongo/db/commands/generic.idl
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
#include "mongo/db/commands.h"
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
 * Severity level to log message at
 */
enum class MessageSeverityEnum : std::int32_t {
    kSevere ,
    kError ,
    kWarning ,
    kInfo ,
    kLog ,
    kDebug ,
};
static constexpr uint32_t kNumMessageSeverityEnum = 6;

MessageSeverityEnum MessageSeverity_parse(const IDLParserErrorContext& ctxt, StringData value);
StringData MessageSeverity_serializer(MessageSeverityEnum value);

/**
 * Log a message on the server
 */
class LogMessageCommand {
public:
    using Reply = void;
    static constexpr auto kCommandParameterFieldName = "logMessage"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kDebugLevelFieldName = "debugLevel"_sd;
    static constexpr auto kExtraFieldName = "extra"_sd;
    static constexpr auto kSeverityFieldName = "severity"_sd;
    static constexpr auto kCommandName = "logMessage"_sd;

    explicit LogMessageCommand(const std::string commandParameter);

    static LogMessageCommand parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static LogMessageCommand parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const StringData getCommandParameter() const& { return _commandParameter; }
    void getCommandParameter() && = delete;

    /**
     * Structured data to include with log message
     */
    const boost::optional<mongo::BSONObj>& getExtra() const& { return _extra; }
    void getExtra() && = delete;
    void setExtra(boost::optional<mongo::BSONObj> value) & {  _extra = std::move(value);  }

    /**
     * Severity of log message
     */
    mongo::MessageSeverityEnum getSeverity() const { return _severity; }
    void setSeverity(mongo::MessageSeverityEnum value) & {  _severity = std::move(value);  }

    /**
     * When using 'debug' severity, what level of debug is to be used?
     */
    const boost::optional<std::int32_t> getDebugLevel() const& { return _debugLevel; }
    void getDebugLevel() && = delete;
    void setDebugLevel(boost::optional<std::int32_t> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get();
        validateDebugLevel(_tmpValue);
        _debugLevel = std::move(_tmpValue);
    } else {
        _debugLevel = boost::none;
    }
      }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    void validateDebugLevel(const std::int32_t value);
    void validateDebugLevel(IDLParserErrorContext& ctxt, const std::int32_t value);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;


    std::string _commandParameter;

    boost::optional<mongo::BSONObj> _extra;
    mongo::MessageSeverityEnum _severity{mongo::MessageSeverityEnum::kLog};
    boost::optional<std::int32_t> _debugLevel;
    std::string _dbName;
    bool _hasDbName : 1;
};

/**
 * Parser for the 'ping' command.
 */
class Ping {
public:
    using Reply = mongo::OkReply;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kCommandName = "ping"_sd;

    static AuthorizationContract kAuthorizationContract;

    Ping();

    static Ping parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static Ping parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;


    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;



    std::string _dbName;
    bool _hasDbName : 1;
};


template <typename Derived>
class PingCmdVersion1Gen : public TypedCommand<Derived> {
    using _TypedCommandInvocationBase = typename TypedCommand<Derived>::InvocationBase;

public:
    using Request = Ping;
    using Reply = mongo::OkReply;

    virtual ~PingCmdVersion1Gen() = default;

    virtual const std::set<std::string>& apiVersions() const final {
        return kApiVersions1;
    }
    virtual const std::set<std::string>& deprecatedApiVersions() const final {
        return kNoApiVersions;
    }
    const AuthorizationContract* getAuthorizationContract() const final { return &Request::kAuthorizationContract; } 

    class InvocationBaseGen : public _TypedCommandInvocationBase {
    public:
        using _TypedCommandInvocationBase::_TypedCommandInvocationBase;
        virtual Reply typedRun(OperationContext* opCtx) = 0;
        void doCheckAuthorization(OperationContext* opCtx) const final {}
    };
};
}  // namespace mongo
