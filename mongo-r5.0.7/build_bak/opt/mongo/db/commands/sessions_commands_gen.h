/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/commands/sessions_commands_gen.h --output build/opt/mongo/db/commands/sessions_commands_gen.cpp src/mongo/db/commands/sessions_commands.idl
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
#include "mongo/crypto/sha256_block.h"
#include "mongo/db/commands.h"
#include "mongo/db/logical_session_id_gen.h"
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
 * Parser for the endSessions command
 */
class EndSessionsFromClient {
public:
    using Reply = mongo::OkReply;
    static constexpr auto kCommandParameterFieldName = "endSessionsFromClient"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kCommandName = "endSessions"_sd;

    static AuthorizationContract kAuthorizationContract;

    explicit EndSessionsFromClient(const std::vector<mongo::LogicalSessionFromClient> commandParameter);

    static EndSessionsFromClient parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static EndSessionsFromClient parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const std::vector<mongo::LogicalSessionFromClient>& getCommandParameter() const& { return _commandParameter; }
    void getCommandParameter() && = delete;

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;


    std::vector<mongo::LogicalSessionFromClient> _commandParameter;

    std::string _dbName;
    bool _hasDbName : 1;
};

/**
 * Parser for the refreshSessions command
 */
class RefreshSessionsFromClient {
public:
    using Reply = mongo::OkReply;
    static constexpr auto kCommandParameterFieldName = "refreshSessionsFromClient"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kCommandName = "refreshSessions"_sd;

    static AuthorizationContract kAuthorizationContract;

    explicit RefreshSessionsFromClient(const std::vector<mongo::LogicalSessionFromClient> commandParameter);

    static RefreshSessionsFromClient parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static RefreshSessionsFromClient parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const std::vector<mongo::LogicalSessionFromClient>& getCommandParameter() const& { return _commandParameter; }
    void getCommandParameter() && = delete;

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;


    std::vector<mongo::LogicalSessionFromClient> _commandParameter;

    std::string _dbName;
    bool _hasDbName : 1;
};


template <typename Derived>
class EndSessionsCmdVersion1Gen : public TypedCommand<Derived> {
    using _TypedCommandInvocationBase = typename TypedCommand<Derived>::InvocationBase;

public:
    using Request = EndSessionsFromClient;
    using Reply = mongo::OkReply;

    virtual ~EndSessionsCmdVersion1Gen() = default;

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
    };
};

template <typename Derived>
class RefreshSessionsCmdVersion1Gen : public TypedCommand<Derived> {
    using _TypedCommandInvocationBase = typename TypedCommand<Derived>::InvocationBase;

public:
    using Request = RefreshSessionsFromClient;
    using Reply = mongo::OkReply;

    virtual ~RefreshSessionsCmdVersion1Gen() = default;

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
    };
};
}  // namespace mongo
