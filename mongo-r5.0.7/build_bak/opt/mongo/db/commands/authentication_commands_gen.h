/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/commands/authentication_commands_gen.h --output build/opt/mongo/db/commands/authentication_commands_gen.cpp src/mongo/db/commands/authentication_commands.idl
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
 * Response for MONGODB-X509 authenticate command
 */
class AuthenticateReply {
public:
    static constexpr auto kDbnameFieldName = "dbname"_sd;
    static constexpr auto kUserFieldName = "user"_sd;

    AuthenticateReply();
    AuthenticateReply(std::string dbname, std::string user);

    static AuthenticateReply parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Name of the database the user is authenticating to
     */
    const StringData getDbname() const& { return _dbname; }
    void getDbname() && = delete;
    void setDbname(StringData value) & { auto _tmpValue = value.toString();  _dbname = std::move(_tmpValue); _hasDbname = true; }

    /**
     * Username
     */
    const StringData getUser() const& { return _user; }
    void getUser() && = delete;
    void setUser(StringData value) & { auto _tmpValue = value.toString();  _user = std::move(_tmpValue); _hasUser = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    std::string _dbname;
    std::string _user;
    bool _hasDbname : 1;
    bool _hasUser : 1;
};

/**
 * Begin a X509 based authentication session
 */
class AuthenticateCommand {
public:
    using Reply = mongo::AuthenticateReply;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kMechanismFieldName = "mechanism"_sd;
    static constexpr auto kUserFieldName = "user"_sd;
    static constexpr auto kCommandName = "authenticate"_sd;

    static AuthorizationContract kAuthorizationContract;

    AuthenticateCommand();
    AuthenticateCommand(std::string mechanism);

    static AuthenticateCommand parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static AuthenticateCommand parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;


    /**
     * Mechanism used for authentication. Should be 'MONGODB-X509'.
     */
    const StringData getMechanism() const& { return _mechanism; }
    void getMechanism() && = delete;
    void setMechanism(StringData value) & { auto _tmpValue = value.toString();  _mechanism = std::move(_tmpValue); _hasMechanism = true; }

    /**
     * The user attempting to authenticate
     */
    const boost::optional<StringData> getUser() const& { return boost::optional<StringData>{_user}; }
    void getUser() && = delete;
    void setUser(boost::optional<StringData> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get().toString();
        
        _user = std::move(_tmpValue);
    } else {
        _user = boost::none;
    }
      }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;



    std::string _mechanism;
    boost::optional<std::string> _user;
    std::string _dbName;
    bool _hasMechanism : 1;
    bool _hasDbName : 1;
};

/**
 * Deauthenticate from the current database
 */
class LogoutCommand {
public:
    using Reply = void;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kCommandName = "logout"_sd;

    LogoutCommand();

    static LogoutCommand parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static LogoutCommand parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
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
class AuthenticateCmdVersion1Gen : public TypedCommand<Derived> {
    using _TypedCommandInvocationBase = typename TypedCommand<Derived>::InvocationBase;

public:
    using Request = AuthenticateCommand;
    using Reply = mongo::AuthenticateReply;

    virtual ~AuthenticateCmdVersion1Gen() = default;

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
