/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/auth/sasl_commands_gen.h --output build/opt/mongo/db/auth/sasl_commands_gen.cpp src/mongo/db/auth/sasl_commands.idl
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
#include "mongo/db/auth/sasl_payload.h"
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
namespace auth {

/**
 * Response for saslStart and saslContinue commands
 */
class SaslReply {
public:
    static constexpr auto kConversationIdFieldName = "conversationId"_sd;
    static constexpr auto kDoneFieldName = "done"_sd;
    static constexpr auto kPayloadFieldName = "payload"_sd;

    SaslReply();
    SaslReply(std::int32_t conversationId, bool done, mongo::auth::SaslPayload payload);

    static SaslReply parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Unique identifier for this SASL authentication session
     */
    std::int32_t getConversationId() const { return _conversationId; }
    void setConversationId(std::int32_t value) & {  _conversationId = std::move(value); _hasConversationId = true; }

    /**
     * Whether or not the authentication has completed
     */
    bool getDone() const { return _done; }
    void setDone(bool value) & {  _done = std::move(value); _hasDone = true; }

    /**
     * SASL payload
     */
    const mongo::auth::SaslPayload& getPayload() const { return _payload; }
    void setPayload(mongo::auth::SaslPayload value) & {  _payload = std::move(value); _hasPayload = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    std::int32_t _conversationId;
    bool _done;
    mongo::auth::SaslPayload _payload;
    bool _hasConversationId : 1;
    bool _hasDone : 1;
    bool _hasPayload : 1;
};

/**
 * Begin a SASL based authentication session
 */
class SaslStartCommand {
public:
    using Reply = mongo::auth::SaslReply;
    static constexpr auto kAutoAuthorizeFieldName = "autoAuthorize"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kMechanismFieldName = "mechanism"_sd;
    static constexpr auto kOptionsFieldName = "options"_sd;
    static constexpr auto kPayloadFieldName = "payload"_sd;
    static constexpr auto kCommandName = "saslStart"_sd;

    static AuthorizationContract kAuthorizationContract;

    SaslStartCommand();
    SaslStartCommand(std::string mechanism, mongo::auth::SaslPayload payload);

    static SaslStartCommand parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static SaslStartCommand parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;


    /**
     * SASL mechanism used for authentication
     */
    const StringData getMechanism() const& { return _mechanism; }
    void getMechanism() && = delete;
    void setMechanism(StringData value) & { auto _tmpValue = value.toString();  _mechanism = std::move(_tmpValue); _hasMechanism = true; }

    /**
     * Automatically authorized user once authenticated
     */
    bool getAutoAuthorize() const { return _autoAuthorize; }
    void setAutoAuthorize(bool value) & {  _autoAuthorize = std::move(value);  }

    /**
     * SASL mechanism specific options
     */
    const boost::optional<mongo::BSONObj>& getOptions() const& { return _options; }
    void getOptions() && = delete;
    void setOptions(boost::optional<mongo::BSONObj> value) & {  _options = std::move(value);  }

    /**
     * Initial client message for SASL exchange
     */
    const mongo::auth::SaslPayload& getPayload() const { return _payload; }
    void setPayload(mongo::auth::SaslPayload value) & {  _payload = std::move(value); _hasPayload = true; }

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
    bool _autoAuthorize{true};
    boost::optional<mongo::BSONObj> _options;
    mongo::auth::SaslPayload _payload;
    std::string _dbName;
    bool _hasMechanism : 1;
    bool _hasPayload : 1;
    bool _hasDbName : 1;
};

/**
 * Continue a SASL based authentication session
 */
class SaslContinueCommand {
public:
    using Reply = mongo::auth::SaslReply;
    static constexpr auto kConversationIdFieldName = "conversationId"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kPayloadFieldName = "payload"_sd;
    static constexpr auto kCommandName = "saslContinue"_sd;

    static AuthorizationContract kAuthorizationContract;

    SaslContinueCommand();
    SaslContinueCommand(std::int32_t conversationId, mongo::auth::SaslPayload payload);

    static SaslContinueCommand parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static SaslContinueCommand parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;


    /**
     * Unique identifier for this SASL authentication session
     */
    std::int32_t getConversationId() const { return _conversationId; }
    void setConversationId(std::int32_t value) & {  _conversationId = std::move(value); _hasConversationId = true; }

    /**
     * SASL payload
     */
    const mongo::auth::SaslPayload& getPayload() const { return _payload; }
    void setPayload(mongo::auth::SaslPayload value) & {  _payload = std::move(value); _hasPayload = true; }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;



    std::int32_t _conversationId;
    mongo::auth::SaslPayload _payload;
    std::string _dbName;
    bool _hasConversationId : 1;
    bool _hasPayload : 1;
    bool _hasDbName : 1;
};


template <typename Derived>
class SaslStartCmdVersion1Gen : public TypedCommand<Derived> {
    using _TypedCommandInvocationBase = typename TypedCommand<Derived>::InvocationBase;

public:
    using Request = SaslStartCommand;
    using Reply = mongo::auth::SaslReply;

    virtual ~SaslStartCmdVersion1Gen() = default;

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

template <typename Derived>
class SaslContinueCmdVersion1Gen : public TypedCommand<Derived> {
    using _TypedCommandInvocationBase = typename TypedCommand<Derived>::InvocationBase;

public:
    using Request = SaslContinueCommand;
    using Reply = mongo::auth::SaslReply;

    virtual ~SaslContinueCmdVersion1Gen() = default;

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
}  // namespace auth
}  // namespace mongo
