/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/commands/user_management_commands_gen.h --output build/opt/mongo/db/commands/user_management_commands_gen.cpp src/mongo/db/commands/user_management_commands.idl
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
#include "mongo/db/auth/address_restriction.h"
#include "mongo/db/auth/address_restriction_gen.h"
#include "mongo/db/auth/auth_types_gen.h"
#include "mongo/db/auth/privilege.h"
#include "mongo/db/auth/privilege_format.h"
#include "mongo/db/auth/role_name.h"
#include "mongo/db/auth/role_name_or_string.h"
#include "mongo/db/auth/umc_info_command_arg.h"
#include "mongo/db/auth/user_name.h"
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
 * Response for dropAllUsersFromDatabase command
 */
class DropAllUsersFromDatabaseReply {
public:
    static constexpr auto kCountFieldName = "n"_sd;

    DropAllUsersFromDatabaseReply();
    DropAllUsersFromDatabaseReply(std::int32_t count);

    static DropAllUsersFromDatabaseReply parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Number of users dropped from database
     */
    std::int32_t getCount() const { return _count; }
    void setCount(std::int32_t value) & {  _count = std::move(value); _hasCount = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    std::int32_t _count;
    bool _hasCount : 1;
};

/**
 * Response for dropAllRolesFromDatabase command
 */
class DropAllRolesFromDatabaseReply {
public:
    static constexpr auto kCountFieldName = "n"_sd;

    DropAllRolesFromDatabaseReply();
    DropAllRolesFromDatabaseReply(std::int32_t count);

    static DropAllRolesFromDatabaseReply parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Number of roles dropped from database
     */
    std::int32_t getCount() const { return _count; }
    void setCount(std::int32_t value) & {  _count = std::move(value); _hasCount = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    std::int32_t _count;
    bool _hasCount : 1;
};

/**
 * Reply from usersInfo command
 */
class UsersInfoReply {
public:
    static constexpr auto kUsersFieldName = "users"_sd;

    UsersInfoReply();
    UsersInfoReply(std::vector<mongo::BSONObj> users);

    static UsersInfoReply parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Users descriptions
     */
    const std::vector<mongo::BSONObj>& getUsers() const& { return _users; }
    void getUsers() && = delete;
    void setUsers(std::vector<mongo::BSONObj> value) & {  _users = std::move(value); _hasUsers = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    std::vector<mongo::BSONObj> _users;
    bool _hasUsers : 1;
};

/**
 * Reply from rolesInfo command
 */
class RolesInfoReply {
public:
    static constexpr auto kRolesFieldName = "roles"_sd;
    static constexpr auto kUserFragmentFieldName = "userFragment"_sd;

    RolesInfoReply();

    static RolesInfoReply parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Users descriptions
     */
    const boost::optional<std::vector<mongo::BSONObj>>& getRoles() const& { return _roles; }
    void getRoles() && = delete;
    void setRoles(boost::optional<std::vector<mongo::BSONObj>> value) & {  _roles = std::move(value);  }

    /**
     * Roles as user document fragment
     */
    const boost::optional<mongo::BSONObj>& getUserFragment() const& { return _userFragment; }
    void getUserFragment() && = delete;
    void setUserFragment(boost::optional<mongo::BSONObj> value) & {  _userFragment = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    boost::optional<std::vector<mongo::BSONObj>> _roles;
    boost::optional<mongo::BSONObj> _userFragment;
};

/**
 * Reply from _getUserCacheGeneration command
 */
class GetUserCacheGenerationReply {
public:
    static constexpr auto kCacheGenerationFieldName = "cacheGeneration"_sd;

    GetUserCacheGenerationReply();
    GetUserCacheGenerationReply(mongo::OID cacheGeneration);

    static GetUserCacheGenerationReply parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Cache generation
     */
    const mongo::OID& getCacheGeneration() const { return _cacheGeneration; }
    void setCacheGeneration(mongo::OID value) & {  _cacheGeneration = std::move(value); _hasCacheGeneration = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::OID _cacheGeneration;
    bool _hasCacheGeneration : 1;
};

/**
 * Data for umcTransaction failpoint
 */
class UMCTransactionFailPoint {
public:
    static constexpr auto kCommitDelayMSFieldName = "commitDelayMS"_sd;

    UMCTransactionFailPoint();

    static UMCTransactionFailPoint parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    std::int32_t getCommitDelayMS() const { return _commitDelayMS; }
    void setCommitDelayMS(std::int32_t value) & { validateCommitDelayMS(value); _commitDelayMS = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    void validateCommitDelayMS(const std::int32_t value);
    void validateCommitDelayMS(IDLParserErrorContext& ctxt, const std::int32_t value);

private:
    std::int32_t _commitDelayMS{0};
};

/**
 * Create a user
 */
class CreateUserCommand {
public:
    using Reply = void;
    static constexpr auto kCommandParameterFieldName = "createUser"_sd;
    static constexpr auto kAuthenticationRestrictionsFieldName = "authenticationRestrictions"_sd;
    static constexpr auto kCustomDataFieldName = "customData"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kDigestPasswordFieldName = "digestPassword"_sd;
    static constexpr auto kMechanismsFieldName = "mechanisms"_sd;
    static constexpr auto kPwdFieldName = "pwd"_sd;
    static constexpr auto kRolesFieldName = "roles"_sd;
    static constexpr auto kWriteConcernFieldName = "writeConcern"_sd;
    static constexpr auto kCommandName = "createUser"_sd;

    explicit CreateUserCommand(const std::string commandParameter);
    explicit CreateUserCommand(const std::string commandParameter, std::vector<mongo::RoleNameOrString> roles);

    static CreateUserCommand parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static CreateUserCommand parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const StringData getCommandParameter() const& { return _commandParameter; }
    void getCommandParameter() && = delete;

    /**
     * Initial user password
     */
    const boost::optional<StringData> getPwd() const& { return boost::optional<StringData>{_pwd}; }
    void getPwd() && = delete;
    void setPwd(boost::optional<StringData> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get().toString();
        
        _pwd = std::move(_tmpValue);
    } else {
        _pwd = boost::none;
    }
      }

    /**
     * Any arbitrary data
     */
    const boost::optional<mongo::BSONObj>& getCustomData() const& { return _customData; }
    void getCustomData() && = delete;
    void setCustomData(boost::optional<mongo::BSONObj> value) & {  _customData = std::move(value);  }

    /**
     * Initial roles to grant to the user
     */
    const std::vector<mongo::RoleNameOrString>& getRoles() const& { return _roles; }
    void getRoles() && = delete;
    void setRoles(std::vector<mongo::RoleNameOrString> value) & {  _roles = std::move(value); _hasRoles = true; }

    /**
     * True if the server should digest the password, false for pre-digested
     */
    bool getDigestPassword() const { return _digestPassword; }
    void setDigestPassword(bool value) & {  _digestPassword = std::move(value);  }

    /**
     * The level of write concern for the creation operation
     */
    const boost::optional<mongo::BSONObj>& getWriteConcern() const& { return _writeConcern; }
    void getWriteConcern() && = delete;
    void setWriteConcern(boost::optional<mongo::BSONObj> value) & {  _writeConcern = std::move(value);  }

    /**
     * Authentication restrictions to enforce on the user
     */
    const boost::optional<std::vector<mongo::Address_restriction>>& getAuthenticationRestrictions() const& { return _authenticationRestrictions; }
    void getAuthenticationRestrictions() && = delete;
    void setAuthenticationRestrictions(boost::optional<std::vector<mongo::Address_restriction>> value) & {  _authenticationRestrictions = std::move(value);  }

    /**
     * List of valid authentication mechanisms for the user
     */
    const boost::optional<std::vector<StringData>> getMechanisms() const& { if (_mechanisms.is_initialized()) {
        return transformVector(_mechanisms.get());
    } else {
        return boost::none;
    }
     }
    void getMechanisms() && = delete;
    void setMechanisms(boost::optional<std::vector<StringData>> value) & { if (value.is_initialized()) {
        auto _tmpValue = transformVector(value.get());
        
        _mechanisms = std::move(_tmpValue);
    } else {
        _mechanisms = boost::none;
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


    std::string _commandParameter;

    boost::optional<std::string> _pwd;
    boost::optional<mongo::BSONObj> _customData;
    std::vector<mongo::RoleNameOrString> _roles;
    bool _digestPassword{true};
    boost::optional<mongo::BSONObj> _writeConcern;
    boost::optional<std::vector<mongo::Address_restriction>> _authenticationRestrictions;
    boost::optional<std::vector<std::string>> _mechanisms;
    std::string _dbName;
    bool _hasRoles : 1;
    bool _hasDbName : 1;
};

/**
 * Modify a user
 */
class UpdateUserCommand {
public:
    using Reply = void;
    static constexpr auto kCommandParameterFieldName = "updateUser"_sd;
    static constexpr auto kAuthenticationRestrictionsFieldName = "authenticationRestrictions"_sd;
    static constexpr auto kCustomDataFieldName = "customData"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kDigestPasswordFieldName = "digestPassword"_sd;
    static constexpr auto kMechanismsFieldName = "mechanisms"_sd;
    static constexpr auto kPwdFieldName = "pwd"_sd;
    static constexpr auto kRolesFieldName = "roles"_sd;
    static constexpr auto kWriteConcernFieldName = "writeConcern"_sd;
    static constexpr auto kCommandName = "updateUser"_sd;

    explicit UpdateUserCommand(const std::string commandParameter);

    static UpdateUserCommand parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static UpdateUserCommand parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const StringData getCommandParameter() const& { return _commandParameter; }
    void getCommandParameter() && = delete;

    /**
     * New user password
     */
    const boost::optional<StringData> getPwd() const& { return boost::optional<StringData>{_pwd}; }
    void getPwd() && = delete;
    void setPwd(boost::optional<StringData> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get().toString();
        
        _pwd = std::move(_tmpValue);
    } else {
        _pwd = boost::none;
    }
      }

    /**
     * Any arbitrary data
     */
    const boost::optional<mongo::BSONObj>& getCustomData() const& { return _customData; }
    void getCustomData() && = delete;
    void setCustomData(boost::optional<mongo::BSONObj> value) & {  _customData = std::move(value);  }

    /**
     * New set of roles for the user
     */
    const boost::optional<std::vector<mongo::RoleNameOrString>>& getRoles() const& { return _roles; }
    void getRoles() && = delete;
    void setRoles(boost::optional<std::vector<mongo::RoleNameOrString>> value) & {  _roles = std::move(value);  }

    /**
     * True if the server should digest the password, false for pre-digested
     */
    bool getDigestPassword() const { return _digestPassword; }
    void setDigestPassword(bool value) & {  _digestPassword = std::move(value);  }

    /**
     * The level of write concern for the update operation
     */
    const boost::optional<mongo::BSONObj>& getWriteConcern() const& { return _writeConcern; }
    void getWriteConcern() && = delete;
    void setWriteConcern(boost::optional<mongo::BSONObj> value) & {  _writeConcern = std::move(value);  }

    /**
     * Authentication restrictions to enforce on the user
     */
    const boost::optional<std::vector<mongo::Address_restriction>>& getAuthenticationRestrictions() const& { return _authenticationRestrictions; }
    void getAuthenticationRestrictions() && = delete;
    void setAuthenticationRestrictions(boost::optional<std::vector<mongo::Address_restriction>> value) & {  _authenticationRestrictions = std::move(value);  }

    /**
     * List of valid authentication mechanisms for the user
     */
    const boost::optional<std::vector<StringData>> getMechanisms() const& { if (_mechanisms.is_initialized()) {
        return transformVector(_mechanisms.get());
    } else {
        return boost::none;
    }
     }
    void getMechanisms() && = delete;
    void setMechanisms(boost::optional<std::vector<StringData>> value) & { if (value.is_initialized()) {
        auto _tmpValue = transformVector(value.get());
        
        _mechanisms = std::move(_tmpValue);
    } else {
        _mechanisms = boost::none;
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


    std::string _commandParameter;

    boost::optional<std::string> _pwd;
    boost::optional<mongo::BSONObj> _customData;
    boost::optional<std::vector<mongo::RoleNameOrString>> _roles;
    bool _digestPassword{true};
    boost::optional<mongo::BSONObj> _writeConcern;
    boost::optional<std::vector<mongo::Address_restriction>> _authenticationRestrictions;
    boost::optional<std::vector<std::string>> _mechanisms;
    std::string _dbName;
    bool _hasDbName : 1;
};

/**
 * Drop a single user
 */
class DropUserCommand {
public:
    using Reply = void;
    static constexpr auto kCommandParameterFieldName = "dropUser"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kCommandName = "dropUser"_sd;

    explicit DropUserCommand(const std::string commandParameter);

    static DropUserCommand parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static DropUserCommand parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const StringData getCommandParameter() const& { return _commandParameter; }
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


    std::string _commandParameter;

    std::string _dbName;
    bool _hasDbName : 1;
};

/**
 * Drop all users in the database
 */
class DropAllUsersFromDatabaseCommand {
public:
    using Reply = mongo::DropAllUsersFromDatabaseReply;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kCommandName = "dropAllUsersFromDatabase"_sd;

    DropAllUsersFromDatabaseCommand();

    static DropAllUsersFromDatabaseCommand parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static DropAllUsersFromDatabaseCommand parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
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

/**
 * Grant additional roles to a user
 */
class GrantRolesToUserCommand {
public:
    using Reply = void;
    static constexpr auto kCommandParameterFieldName = "grantRolesToUser"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kRolesFieldName = "roles"_sd;
    static constexpr auto kCommandName = "grantRolesToUser"_sd;

    explicit GrantRolesToUserCommand(const std::string commandParameter);
    explicit GrantRolesToUserCommand(const std::string commandParameter, std::vector<mongo::RoleNameOrString> roles);

    static GrantRolesToUserCommand parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static GrantRolesToUserCommand parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const StringData getCommandParameter() const& { return _commandParameter; }
    void getCommandParameter() && = delete;

    /**
     * Roles to grant to the user
     */
    const std::vector<mongo::RoleNameOrString>& getRoles() const& { return _roles; }
    void getRoles() && = delete;
    void setRoles(std::vector<mongo::RoleNameOrString> value) & {  _roles = std::move(value); _hasRoles = true; }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;


    std::string _commandParameter;

    std::vector<mongo::RoleNameOrString> _roles;
    std::string _dbName;
    bool _hasRoles : 1;
    bool _hasDbName : 1;
};

/**
 * Revoke previously assigned roles from a user
 */
class RevokeRolesFromUserCommand {
public:
    using Reply = void;
    static constexpr auto kCommandParameterFieldName = "revokeRolesFromUser"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kRolesFieldName = "roles"_sd;
    static constexpr auto kCommandName = "revokeRolesFromUser"_sd;

    explicit RevokeRolesFromUserCommand(const std::string commandParameter);
    explicit RevokeRolesFromUserCommand(const std::string commandParameter, std::vector<mongo::RoleNameOrString> roles);

    static RevokeRolesFromUserCommand parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static RevokeRolesFromUserCommand parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const StringData getCommandParameter() const& { return _commandParameter; }
    void getCommandParameter() && = delete;

    /**
     * Roles to revoke from the user
     */
    const std::vector<mongo::RoleNameOrString>& getRoles() const& { return _roles; }
    void getRoles() && = delete;
    void setRoles(std::vector<mongo::RoleNameOrString> value) & {  _roles = std::move(value); _hasRoles = true; }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;


    std::string _commandParameter;

    std::vector<mongo::RoleNameOrString> _roles;
    std::string _dbName;
    bool _hasRoles : 1;
    bool _hasDbName : 1;
};

/**
 * Create a new role
 */
class CreateRoleCommand {
public:
    using Reply = void;
    static constexpr auto kCommandParameterFieldName = "createRole"_sd;
    static constexpr auto kAuthenticationRestrictionsFieldName = "authenticationRestrictions"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kPrivilegesFieldName = "privileges"_sd;
    static constexpr auto kRolesFieldName = "roles"_sd;
    static constexpr auto kCommandName = "createRole"_sd;

    explicit CreateRoleCommand(const std::string commandParameter);
    explicit CreateRoleCommand(const std::string commandParameter, std::vector<mongo::Privilege> privileges, std::vector<mongo::RoleNameOrString> roles);

    static CreateRoleCommand parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static CreateRoleCommand parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const StringData getCommandParameter() const& { return _commandParameter; }
    void getCommandParameter() && = delete;

    /**
     * Actions explicitly granted to this role
     */
    const std::vector<mongo::Privilege>& getPrivileges() const& { return _privileges; }
    void getPrivileges() && = delete;
    void setPrivileges(std::vector<mongo::Privilege> value) & {  _privileges = std::move(value); _hasPrivileges = true; }

    /**
     * Roles to inherit additional privileges from
     */
    const std::vector<mongo::RoleNameOrString>& getRoles() const& { return _roles; }
    void getRoles() && = delete;
    void setRoles(std::vector<mongo::RoleNameOrString> value) & {  _roles = std::move(value); _hasRoles = true; }

    /**
     * Authentication restrictions to enforce on the user
     */
    const boost::optional<std::vector<mongo::Address_restriction>>& getAuthenticationRestrictions() const& { return _authenticationRestrictions; }
    void getAuthenticationRestrictions() && = delete;
    void setAuthenticationRestrictions(boost::optional<std::vector<mongo::Address_restriction>> value) & {  _authenticationRestrictions = std::move(value);  }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;


    std::string _commandParameter;

    std::vector<mongo::Privilege> _privileges;
    std::vector<mongo::RoleNameOrString> _roles;
    boost::optional<std::vector<mongo::Address_restriction>> _authenticationRestrictions;
    std::string _dbName;
    bool _hasPrivileges : 1;
    bool _hasRoles : 1;
    bool _hasDbName : 1;
};

/**
 * Update an existing role
 */
class UpdateRoleCommand {
public:
    using Reply = void;
    static constexpr auto kCommandParameterFieldName = "updateRole"_sd;
    static constexpr auto kAuthenticationRestrictionsFieldName = "authenticationRestrictions"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kPrivilegesFieldName = "privileges"_sd;
    static constexpr auto kRolesFieldName = "roles"_sd;
    static constexpr auto kCommandName = "updateRole"_sd;

    explicit UpdateRoleCommand(const std::string commandParameter);

    static UpdateRoleCommand parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static UpdateRoleCommand parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const StringData getCommandParameter() const& { return _commandParameter; }
    void getCommandParameter() && = delete;

    /**
     * Actions explicitly granted to this role
     */
    const boost::optional<std::vector<mongo::Privilege>>& getPrivileges() const& { return _privileges; }
    void getPrivileges() && = delete;
    void setPrivileges(boost::optional<std::vector<mongo::Privilege>> value) & {  _privileges = std::move(value);  }

    /**
     * Roles to inherit additional privileges from
     */
    const boost::optional<std::vector<mongo::RoleNameOrString>>& getRoles() const& { return _roles; }
    void getRoles() && = delete;
    void setRoles(boost::optional<std::vector<mongo::RoleNameOrString>> value) & {  _roles = std::move(value);  }

    /**
     * Authentication restrictions to enforce on the user
     */
    const boost::optional<std::vector<mongo::Address_restriction>>& getAuthenticationRestrictions() const& { return _authenticationRestrictions; }
    void getAuthenticationRestrictions() && = delete;
    void setAuthenticationRestrictions(boost::optional<std::vector<mongo::Address_restriction>> value) & {  _authenticationRestrictions = std::move(value);  }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;


    std::string _commandParameter;

    boost::optional<std::vector<mongo::Privilege>> _privileges;
    boost::optional<std::vector<mongo::RoleNameOrString>> _roles;
    boost::optional<std::vector<mongo::Address_restriction>> _authenticationRestrictions;
    std::string _dbName;
    bool _hasDbName : 1;
};

/**
 * Grants privileges to a role
 */
class GrantPrivilegesToRoleCommand {
public:
    using Reply = void;
    static constexpr auto kCommandParameterFieldName = "grantPrivilegesToRole"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kPrivilegesFieldName = "privileges"_sd;
    static constexpr auto kCommandName = "grantPrivilegesToRole"_sd;

    explicit GrantPrivilegesToRoleCommand(const std::string commandParameter);
    explicit GrantPrivilegesToRoleCommand(const std::string commandParameter, std::vector<mongo::Privilege> privileges);

    static GrantPrivilegesToRoleCommand parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static GrantPrivilegesToRoleCommand parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const StringData getCommandParameter() const& { return _commandParameter; }
    void getCommandParameter() && = delete;

    /**
     * Privileges to grant to this role
     */
    const std::vector<mongo::Privilege>& getPrivileges() const& { return _privileges; }
    void getPrivileges() && = delete;
    void setPrivileges(std::vector<mongo::Privilege> value) & {  _privileges = std::move(value); _hasPrivileges = true; }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;


    std::string _commandParameter;

    std::vector<mongo::Privilege> _privileges;
    std::string _dbName;
    bool _hasPrivileges : 1;
    bool _hasDbName : 1;
};

/**
 * Grants privileges to a role
 */
class RevokePrivilegesFromRoleCommand {
public:
    using Reply = void;
    static constexpr auto kCommandParameterFieldName = "revokePrivilegesFromRole"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kPrivilegesFieldName = "privileges"_sd;
    static constexpr auto kCommandName = "revokePrivilegesFromRole"_sd;

    explicit RevokePrivilegesFromRoleCommand(const std::string commandParameter);
    explicit RevokePrivilegesFromRoleCommand(const std::string commandParameter, std::vector<mongo::Privilege> privileges);

    static RevokePrivilegesFromRoleCommand parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static RevokePrivilegesFromRoleCommand parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const StringData getCommandParameter() const& { return _commandParameter; }
    void getCommandParameter() && = delete;

    /**
     * Privileges to revoke from this role
     */
    const std::vector<mongo::Privilege>& getPrivileges() const& { return _privileges; }
    void getPrivileges() && = delete;
    void setPrivileges(std::vector<mongo::Privilege> value) & {  _privileges = std::move(value); _hasPrivileges = true; }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;


    std::string _commandParameter;

    std::vector<mongo::Privilege> _privileges;
    std::string _dbName;
    bool _hasPrivileges : 1;
    bool _hasDbName : 1;
};

/**
 * Grant roles to a role
 */
class GrantRolesToRoleCommand {
public:
    using Reply = void;
    static constexpr auto kCommandParameterFieldName = "grantRolesToRole"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kRolesFieldName = "roles"_sd;
    static constexpr auto kCommandName = "grantRolesToRole"_sd;

    explicit GrantRolesToRoleCommand(const std::string commandParameter);
    explicit GrantRolesToRoleCommand(const std::string commandParameter, std::vector<mongo::RoleNameOrString> roles);

    static GrantRolesToRoleCommand parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static GrantRolesToRoleCommand parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const StringData getCommandParameter() const& { return _commandParameter; }
    void getCommandParameter() && = delete;

    /**
     * Roles to grant to this role
     */
    const std::vector<mongo::RoleNameOrString>& getRoles() const& { return _roles; }
    void getRoles() && = delete;
    void setRoles(std::vector<mongo::RoleNameOrString> value) & {  _roles = std::move(value); _hasRoles = true; }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;


    std::string _commandParameter;

    std::vector<mongo::RoleNameOrString> _roles;
    std::string _dbName;
    bool _hasRoles : 1;
    bool _hasDbName : 1;
};

/**
 * Revoke roles from a role
 */
class RevokeRolesFromRoleCommand {
public:
    using Reply = void;
    static constexpr auto kCommandParameterFieldName = "revokeRolesFromRole"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kRolesFieldName = "roles"_sd;
    static constexpr auto kCommandName = "revokeRolesFromRole"_sd;

    explicit RevokeRolesFromRoleCommand(const std::string commandParameter);
    explicit RevokeRolesFromRoleCommand(const std::string commandParameter, std::vector<mongo::RoleNameOrString> roles);

    static RevokeRolesFromRoleCommand parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static RevokeRolesFromRoleCommand parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const StringData getCommandParameter() const& { return _commandParameter; }
    void getCommandParameter() && = delete;

    /**
     * Roles to revoke from this role
     */
    const std::vector<mongo::RoleNameOrString>& getRoles() const& { return _roles; }
    void getRoles() && = delete;
    void setRoles(std::vector<mongo::RoleNameOrString> value) & {  _roles = std::move(value); _hasRoles = true; }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;


    std::string _commandParameter;

    std::vector<mongo::RoleNameOrString> _roles;
    std::string _dbName;
    bool _hasRoles : 1;
    bool _hasDbName : 1;
};

/**
 * Drops a single role.  Before deleting the role completely it must remove it from any users or roles that reference it.  If any errors occur in the middle of that process it's possible to be left in a state where the role has been removed from some user/roles but otherwise still exists.
 */
class DropRoleCommand {
public:
    using Reply = void;
    static constexpr auto kCommandParameterFieldName = "dropRole"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kCommandName = "dropRole"_sd;

    explicit DropRoleCommand(const std::string commandParameter);

    static DropRoleCommand parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static DropRoleCommand parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const StringData getCommandParameter() const& { return _commandParameter; }
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


    std::string _commandParameter;

    std::string _dbName;
    bool _hasDbName : 1;
};

/**
 * Drops all roles from the given database.  Before deleting the roles completely it must remove them from any users or other roles that reference them.  If any errors occur in the middle of that process it's possible to be left in a state where the roles have been removed from some user/roles but otherwise still exist.
 */
class DropAllRolesFromDatabaseCommand {
public:
    using Reply = mongo::DropAllRolesFromDatabaseReply;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kCommandName = "dropAllRolesFromDatabase"_sd;

    DropAllRolesFromDatabaseCommand();

    static DropAllRolesFromDatabaseCommand parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static DropAllRolesFromDatabaseCommand parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
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

/**
 * Returns information about users.
 */
class UsersInfoCommand {
public:
    using Reply = mongo::UsersInfoReply;
    static constexpr auto kCommandParameterFieldName = "usersInfo"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kFilterFieldName = "filter"_sd;
    static constexpr auto kShowAuthenticationRestrictionsFieldName = "showAuthenticationRestrictions"_sd;
    static constexpr auto kShowCredentialsFieldName = "showCredentials"_sd;
    static constexpr auto kShowPrivilegesFieldName = "showPrivileges"_sd;
    static constexpr auto kCommandName = "usersInfo"_sd;

    explicit UsersInfoCommand(const mongo::auth::UsersInfoCommandArg commandParameter);

    static UsersInfoCommand parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static UsersInfoCommand parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const mongo::auth::UsersInfoCommandArg& getCommandParameter() const { return _commandParameter; }

    /**
     * Set the field to true to show the user’s full set of privileges, including expanded information for the inherited roles. If viewing all users, you cannot specify this field.
     */
    bool getShowPrivileges() const { return _showPrivileges; }
    void setShowPrivileges(bool value) & {  _showPrivileges = std::move(value);  }

    /**
     * Set the field to true to display the user’s password hash.
     */
    bool getShowCredentials() const { return _showCredentials; }
    void setShowCredentials(bool value) & {  _showCredentials = std::move(value);  }

    /**
     * Set the field to true to show the user’s authentication restrictions. If viewing all users, you cannot specify this field.
     */
    bool getShowAuthenticationRestrictions() const { return _showAuthenticationRestrictions; }
    void setShowAuthenticationRestrictions(bool value) & {  _showAuthenticationRestrictions = std::move(value);  }

    /**
     * A document that specifies $match stage conditions to return information for users that match the filter conditions.
     */
    const boost::optional<mongo::BSONObj>& getFilter() const& { return _filter; }
    void getFilter() && = delete;
    void setFilter(boost::optional<mongo::BSONObj> value) & {  _filter = std::move(value);  }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;


    mongo::auth::UsersInfoCommandArg _commandParameter;

    bool _showPrivileges{false};
    bool _showCredentials{false};
    bool _showAuthenticationRestrictions{false};
    boost::optional<mongo::BSONObj> _filter;
    std::string _dbName;
    bool _hasDbName : 1;
};

/**
 * returns information about roles.
 */
class RolesInfoCommand {
public:
    using Reply = mongo::RolesInfoReply;
    static constexpr auto kCommandParameterFieldName = "rolesInfo"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kShowAuthenticationRestrictionsFieldName = "showAuthenticationRestrictions"_sd;
    static constexpr auto kShowBuiltinRolesFieldName = "showBuiltinRoles"_sd;
    static constexpr auto kShowPrivilegesFieldName = "showPrivileges"_sd;
    static constexpr auto kCommandName = "rolesInfo"_sd;

    explicit RolesInfoCommand(const mongo::auth::RolesInfoCommandArg commandParameter);

    static RolesInfoCommand parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static RolesInfoCommand parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const mongo::auth::RolesInfoCommandArg& getCommandParameter() const { return _commandParameter; }

    /**
     * Set the field to true to show the user’s full set of privileges, including expanded information for the inherited roles. If viewing all roles, you cannot specify this field.
     */
    const mongo::auth::ParsedPrivilegeFormat& getShowPrivileges() const { return _showPrivileges; }
    void setShowPrivileges(mongo::auth::ParsedPrivilegeFormat value) & {  _showPrivileges = std::move(value);  }

    /**
     * When the rolesInfo field is set to 1, set showBuiltinRoles to true to include built-in roles in the output. Otherwise the output for rolesInfo: 1 displays only user-defined roles.
     */
    bool getShowBuiltinRoles() const { return _showBuiltinRoles; }
    void setShowBuiltinRoles(bool value) & {  _showBuiltinRoles = std::move(value);  }

    /**
     * Set the field to true to show the user’s authentication restrictions. If viewing all users, you cannot specify this field.
     */
    bool getShowAuthenticationRestrictions() const { return _showAuthenticationRestrictions; }
    void setShowAuthenticationRestrictions(bool value) & {  _showAuthenticationRestrictions = std::move(value);  }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;


    mongo::auth::RolesInfoCommandArg _commandParameter;

    mongo::auth::ParsedPrivilegeFormat _showPrivileges{false};
    bool _showBuiltinRoles{false};
    bool _showAuthenticationRestrictions{false};
    std::string _dbName;
    bool _hasDbName : 1;
};

/**
 * Invalidate the user cache
 */
class InvalidateUserCacheCommand {
public:
    using Reply = void;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kCommandName = "invalidateUserCache"_sd;

    InvalidateUserCacheCommand();

    static InvalidateUserCacheCommand parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static InvalidateUserCacheCommand parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
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

/**
 * Returns the current user cache generation
 */
class GetUserCacheGenerationCommand {
public:
    using Reply = mongo::GetUserCacheGenerationReply;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kCommandName = "_getUserCacheGeneration"_sd;

    GetUserCacheGenerationCommand();

    static GetUserCacheGenerationCommand parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static GetUserCacheGenerationCommand parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
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

/**
 * Internal command used by mongorestore for updating user/role data
 */
class MergeAuthzCollectionsCommand {
public:
    using Reply = void;
    static constexpr auto kDbFieldName = "db"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kDropFieldName = "drop"_sd;
    static constexpr auto kTempRolesCollectionFieldName = "tempRolesCollection"_sd;
    static constexpr auto kTempUsersCollectionFieldName = "tempUsersCollection"_sd;
    static constexpr auto kCommandName = "_mergeAuthzCollections"_sd;

    MergeAuthzCollectionsCommand();
    MergeAuthzCollectionsCommand(std::string db);

    static MergeAuthzCollectionsCommand parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static MergeAuthzCollectionsCommand parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;


    /**
     * Temporary users collection name
     */
    const StringData getTempUsersCollection() const& { return _tempUsersCollection; }
    void getTempUsersCollection() && = delete;
    void setTempUsersCollection(StringData value) & { auto _tmpValue = value.toString();  _tempUsersCollection = std::move(_tmpValue);  }

    /**
     * Temporary roles collection name
     */
    const StringData getTempRolesCollection() const& { return _tempRolesCollection; }
    void getTempRolesCollection() && = delete;
    void setTempRolesCollection(StringData value) & { auto _tmpValue = value.toString();  _tempRolesCollection = std::move(_tmpValue);  }

    /**
     * Database name
     */
    const StringData getDb() const& { return _db; }
    void getDb() && = delete;
    void setDb(StringData value) & { auto _tmpValue = value.toString();  _db = std::move(_tmpValue); _hasDb = true; }

    /**
     * Drop temp collections when complete
     */
    bool getDrop() const { return _drop; }
    void setDrop(bool value) & {  _drop = std::move(value);  }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;



    std::string _tempUsersCollection{""};
    std::string _tempRolesCollection{""};
    std::string _db;
    bool _drop{false};
    std::string _dbName;
    bool _hasDb : 1;
    bool _hasDbName : 1;
};

}  // namespace mongo
