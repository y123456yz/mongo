/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/auth/sasl_commands_gen.h --output build/opt/mongo/db/auth/sasl_commands_gen.cpp src/mongo/db/auth/sasl_commands.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/auth/sasl_commands_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {
namespace auth {

constexpr StringData SaslReply::kConversationIdFieldName;
constexpr StringData SaslReply::kDoneFieldName;
constexpr StringData SaslReply::kPayloadFieldName;


SaslReply::SaslReply() : _conversationId(mongo::idl::preparsedValue<decltype(_conversationId)>()), _done(mongo::idl::preparsedValue<decltype(_done)>()), _payload(mongo::idl::preparsedValue<decltype(_payload)>()), _hasConversationId(false), _hasDone(false), _hasPayload(false) {
    // Used for initialization only
}
SaslReply::SaslReply(std::int32_t conversationId, bool done, mongo::auth::SaslPayload payload) : _conversationId(std::move(conversationId)), _done(std::move(done)), _payload(std::move(payload)), _hasConversationId(true), _hasDone(true), _hasPayload(true) {
    // Used for initialization only
}


SaslReply SaslReply::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<SaslReply>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void SaslReply::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<3> usedFields;
    const size_t kConversationIdBit = 0;
    const size_t kDoneBit = 1;
    const size_t kPayloadBit = 2;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kConversationIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberInt))) {
                if (MONGO_unlikely(usedFields[kConversationIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kConversationIdBit);

                _hasConversationId = true;
                _conversationId = element._numberInt();
            }
        }
        else if (fieldName == kDoneFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kDoneBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDoneBit);

                _hasDone = true;
                _done = element.boolean();
            }
        }
        else if (fieldName == kPayloadFieldName) {
            if (MONGO_unlikely(usedFields[kPayloadBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kPayloadBit);

            _hasPayload = true;
            _payload = auth::SaslPayload::parseFromBSON(element);
        }
        else {
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kConversationIdBit]) {
            ctxt.throwMissingField(kConversationIdFieldName);
        }
        if (!usedFields[kDoneBit]) {
            ctxt.throwMissingField(kDoneFieldName);
        }
        if (!usedFields[kPayloadBit]) {
            ctxt.throwMissingField(kPayloadFieldName);
        }
    }

}


void SaslReply::serialize(BSONObjBuilder* builder) const {
    invariant(_hasConversationId && _hasDone && _hasPayload);

    builder->append(kConversationIdFieldName, _conversationId);

    builder->append(kDoneFieldName, _done);

    {
        _payload.serializeToBSON(kPayloadFieldName, builder);
    }

}


BSONObj SaslReply::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData SaslStartCommand::kAutoAuthorizeFieldName;
constexpr StringData SaslStartCommand::kDbNameFieldName;
constexpr StringData SaslStartCommand::kMechanismFieldName;
constexpr StringData SaslStartCommand::kOptionsFieldName;
constexpr StringData SaslStartCommand::kPayloadFieldName;
constexpr StringData SaslStartCommand::kCommandName;

mongo::AuthorizationContract SaslStartCommand::kAuthorizationContract = AuthorizationContract(std::initializer_list<AccessCheckEnum>{}, std::initializer_list<Privilege>{});

const std::vector<StringData> SaslStartCommand::_knownBSONFields {
    SaslStartCommand::kAutoAuthorizeFieldName,
    SaslStartCommand::kMechanismFieldName,
    SaslStartCommand::kOptionsFieldName,
    SaslStartCommand::kPayloadFieldName,
    SaslStartCommand::kCommandName,
};
const std::vector<StringData> SaslStartCommand::_knownOP_MSGFields {
    SaslStartCommand::kAutoAuthorizeFieldName,
    SaslStartCommand::kDbNameFieldName,
    SaslStartCommand::kMechanismFieldName,
    SaslStartCommand::kOptionsFieldName,
    SaslStartCommand::kPayloadFieldName,
    SaslStartCommand::kCommandName,
};

SaslStartCommand::SaslStartCommand() : _mechanism(mongo::idl::preparsedValue<decltype(_mechanism)>()), _payload(mongo::idl::preparsedValue<decltype(_payload)>()), _hasMechanism(false), _hasPayload(false), _hasDbName(false) {
    // Used for initialization only
}
SaslStartCommand::SaslStartCommand(std::string mechanism, mongo::auth::SaslPayload payload) : _mechanism(std::move(mechanism)), _payload(std::move(payload)), _hasMechanism(true), _hasPayload(true), _hasDbName(true) {
    // Used for initialization only
}


SaslStartCommand SaslStartCommand::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<SaslStartCommand>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void SaslStartCommand::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<5> usedFields;
    const size_t kMechanismBit = 0;
    const size_t kAutoAuthorizeBit = 1;
    const size_t kOptionsBit = 2;
    const size_t kPayloadBit = 3;
    const size_t kDbNameBit = 4;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kMechanismFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kMechanismBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMechanismBit);

                _hasMechanism = true;
                _mechanism = element.str();
            }
        }
        else if (fieldName == kAutoAuthorizeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kAutoAuthorizeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAutoAuthorizeBit);

                _autoAuthorize = element.trueValue();
            }
        }
        else if (fieldName == kOptionsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kOptionsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kOptionsBit);

                const BSONObj localObject = element.Obj();
                _options = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kPayloadFieldName) {
            if (MONGO_unlikely(usedFields[kPayloadBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kPayloadBit);

            _hasPayload = true;
            _payload = auth::SaslPayload::parseFromBSON(element);
        }
        else if (fieldName == kDbNameFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kDbNameBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDbNameBit);

                _hasDbName = true;
                _dbName = element.str();
            }
        }
        else {
            if (!mongo::isGenericArgument(fieldName)) {
                ctxt.throwUnknownField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kMechanismBit]) {
            ctxt.throwMissingField(kMechanismFieldName);
        }
        if (!usedFields[kAutoAuthorizeBit]) {
            _autoAuthorize = true;
        }
        if (!usedFields[kPayloadBit]) {
            ctxt.throwMissingField(kPayloadFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

}

SaslStartCommand SaslStartCommand::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto object = mongo::idl::preparsedValue<SaslStartCommand>();
    object.parseProtected(ctxt, request);
    return object;
}
void SaslStartCommand::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<5> usedFields;
    const size_t kMechanismBit = 0;
    const size_t kAutoAuthorizeBit = 1;
    const size_t kOptionsBit = 2;
    const size_t kPayloadBit = 3;
    const size_t kDbNameBit = 4;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kMechanismFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kMechanismBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMechanismBit);

                _hasMechanism = true;
                _mechanism = element.str();
            }
        }
        else if (fieldName == kAutoAuthorizeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kAutoAuthorizeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAutoAuthorizeBit);

                _autoAuthorize = element.trueValue();
            }
        }
        else if (fieldName == kOptionsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kOptionsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kOptionsBit);

                const BSONObj localObject = element.Obj();
                _options = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kPayloadFieldName) {
            if (MONGO_unlikely(usedFields[kPayloadBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kPayloadBit);

            _hasPayload = true;
            _payload = auth::SaslPayload::parseFromBSON(element);
        }
        else if (fieldName == kDbNameFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kDbNameBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDbNameBit);

                _hasDbName = true;
                _dbName = element.str();
            }
        }
        else {
            if (!mongo::isGenericArgument(fieldName)) {
                ctxt.throwUnknownField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kMechanismBit]) {
            ctxt.throwMissingField(kMechanismFieldName);
        }
        if (!usedFields[kAutoAuthorizeBit]) {
            _autoAuthorize = true;
        }
        if (!usedFields[kPayloadBit]) {
            ctxt.throwMissingField(kPayloadFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

}

void SaslStartCommand::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasMechanism && _hasPayload && _hasDbName);

    builder->append("saslStart"_sd, 1);
    builder->append(kMechanismFieldName, _mechanism);

    builder->append(kAutoAuthorizeFieldName, _autoAuthorize);

    if (_options.is_initialized()) {
        builder->append(kOptionsFieldName, _options.get());
    }

    {
        _payload.serializeToBSON(kPayloadFieldName, builder);
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest SaslStartCommand::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasMechanism && _hasPayload && _hasDbName);

        builder->append("saslStart"_sd, 1);
        builder->append(kMechanismFieldName, _mechanism);

        builder->append(kAutoAuthorizeFieldName, _autoAuthorize);

        if (_options.is_initialized()) {
            builder->append(kOptionsFieldName, _options.get());
        }

        {
            _payload.serializeToBSON(kPayloadFieldName, builder);
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj SaslStartCommand::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData SaslContinueCommand::kConversationIdFieldName;
constexpr StringData SaslContinueCommand::kDbNameFieldName;
constexpr StringData SaslContinueCommand::kPayloadFieldName;
constexpr StringData SaslContinueCommand::kCommandName;

mongo::AuthorizationContract SaslContinueCommand::kAuthorizationContract = AuthorizationContract(std::initializer_list<AccessCheckEnum>{}, std::initializer_list<Privilege>{});

const std::vector<StringData> SaslContinueCommand::_knownBSONFields {
    SaslContinueCommand::kConversationIdFieldName,
    SaslContinueCommand::kPayloadFieldName,
    SaslContinueCommand::kCommandName,
};
const std::vector<StringData> SaslContinueCommand::_knownOP_MSGFields {
    SaslContinueCommand::kConversationIdFieldName,
    SaslContinueCommand::kDbNameFieldName,
    SaslContinueCommand::kPayloadFieldName,
    SaslContinueCommand::kCommandName,
};

SaslContinueCommand::SaslContinueCommand() : _conversationId(mongo::idl::preparsedValue<decltype(_conversationId)>()), _payload(mongo::idl::preparsedValue<decltype(_payload)>()), _hasConversationId(false), _hasPayload(false), _hasDbName(false) {
    // Used for initialization only
}
SaslContinueCommand::SaslContinueCommand(std::int32_t conversationId, mongo::auth::SaslPayload payload) : _conversationId(std::move(conversationId)), _payload(std::move(payload)), _hasConversationId(true), _hasPayload(true), _hasDbName(true) {
    // Used for initialization only
}


SaslContinueCommand SaslContinueCommand::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<SaslContinueCommand>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void SaslContinueCommand::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<3> usedFields;
    const size_t kConversationIdBit = 0;
    const size_t kPayloadBit = 1;
    const size_t kDbNameBit = 2;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kConversationIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberInt))) {
                if (MONGO_unlikely(usedFields[kConversationIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kConversationIdBit);

                _hasConversationId = true;
                _conversationId = element._numberInt();
            }
        }
        else if (fieldName == kPayloadFieldName) {
            if (MONGO_unlikely(usedFields[kPayloadBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kPayloadBit);

            _hasPayload = true;
            _payload = auth::SaslPayload::parseFromBSON(element);
        }
        else if (fieldName == kDbNameFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kDbNameBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDbNameBit);

                _hasDbName = true;
                _dbName = element.str();
            }
        }
        else {
            if (!mongo::isGenericArgument(fieldName)) {
                ctxt.throwUnknownField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kConversationIdBit]) {
            ctxt.throwMissingField(kConversationIdFieldName);
        }
        if (!usedFields[kPayloadBit]) {
            ctxt.throwMissingField(kPayloadFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

}

SaslContinueCommand SaslContinueCommand::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto object = mongo::idl::preparsedValue<SaslContinueCommand>();
    object.parseProtected(ctxt, request);
    return object;
}
void SaslContinueCommand::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<3> usedFields;
    const size_t kConversationIdBit = 0;
    const size_t kPayloadBit = 1;
    const size_t kDbNameBit = 2;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kConversationIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberInt))) {
                if (MONGO_unlikely(usedFields[kConversationIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kConversationIdBit);

                _hasConversationId = true;
                _conversationId = element._numberInt();
            }
        }
        else if (fieldName == kPayloadFieldName) {
            if (MONGO_unlikely(usedFields[kPayloadBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kPayloadBit);

            _hasPayload = true;
            _payload = auth::SaslPayload::parseFromBSON(element);
        }
        else if (fieldName == kDbNameFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kDbNameBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDbNameBit);

                _hasDbName = true;
                _dbName = element.str();
            }
        }
        else {
            if (!mongo::isGenericArgument(fieldName)) {
                ctxt.throwUnknownField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kConversationIdBit]) {
            ctxt.throwMissingField(kConversationIdFieldName);
        }
        if (!usedFields[kPayloadBit]) {
            ctxt.throwMissingField(kPayloadFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

}

void SaslContinueCommand::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasConversationId && _hasPayload && _hasDbName);

    builder->append("saslContinue"_sd, 1);
    builder->append(kConversationIdFieldName, _conversationId);

    {
        _payload.serializeToBSON(kPayloadFieldName, builder);
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest SaslContinueCommand::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasConversationId && _hasPayload && _hasDbName);

        builder->append("saslContinue"_sd, 1);
        builder->append(kConversationIdFieldName, _conversationId);

        {
            _payload.serializeToBSON(kPayloadFieldName, builder);
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj SaslContinueCommand::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace auth
}  // namespace mongo
