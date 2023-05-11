/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/commands/authentication_commands_gen.h --output build/opt/mongo/db/commands/authentication_commands_gen.cpp src/mongo/db/commands/authentication_commands.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/commands/authentication_commands_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData AuthenticateReply::kDbnameFieldName;
constexpr StringData AuthenticateReply::kUserFieldName;


AuthenticateReply::AuthenticateReply() : _dbname(mongo::idl::preparsedValue<decltype(_dbname)>()), _user(mongo::idl::preparsedValue<decltype(_user)>()), _hasDbname(false), _hasUser(false) {
    // Used for initialization only
}
AuthenticateReply::AuthenticateReply(std::string dbname, std::string user) : _dbname(std::move(dbname)), _user(std::move(user)), _hasDbname(true), _hasUser(true) {
    // Used for initialization only
}


AuthenticateReply AuthenticateReply::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<AuthenticateReply>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void AuthenticateReply::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kDbnameBit = 0;
    const size_t kUserBit = 1;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kDbnameFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kDbnameBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDbnameBit);

                _hasDbname = true;
                _dbname = element.str();
            }
        }
        else if (fieldName == kUserFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kUserBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUserBit);

                _hasUser = true;
                _user = element.str();
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kDbnameBit]) {
            ctxt.throwMissingField(kDbnameFieldName);
        }
        if (!usedFields[kUserBit]) {
            ctxt.throwMissingField(kUserFieldName);
        }
    }

}


void AuthenticateReply::serialize(BSONObjBuilder* builder) const {
    invariant(_hasDbname && _hasUser);

    builder->append(kDbnameFieldName, _dbname);

    builder->append(kUserFieldName, _user);

}


BSONObj AuthenticateReply::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData AuthenticateCommand::kDbNameFieldName;
constexpr StringData AuthenticateCommand::kMechanismFieldName;
constexpr StringData AuthenticateCommand::kUserFieldName;
constexpr StringData AuthenticateCommand::kCommandName;

mongo::AuthorizationContract AuthenticateCommand::kAuthorizationContract = AuthorizationContract(std::initializer_list<AccessCheckEnum>{}, std::initializer_list<Privilege>{});

const std::vector<StringData> AuthenticateCommand::_knownBSONFields {
    AuthenticateCommand::kMechanismFieldName,
    AuthenticateCommand::kUserFieldName,
    AuthenticateCommand::kCommandName,
};
const std::vector<StringData> AuthenticateCommand::_knownOP_MSGFields {
    AuthenticateCommand::kDbNameFieldName,
    AuthenticateCommand::kMechanismFieldName,
    AuthenticateCommand::kUserFieldName,
    AuthenticateCommand::kCommandName,
};

AuthenticateCommand::AuthenticateCommand() : _mechanism(mongo::idl::preparsedValue<decltype(_mechanism)>()), _hasMechanism(false), _hasDbName(false) {
    // Used for initialization only
}
AuthenticateCommand::AuthenticateCommand(std::string mechanism) : _mechanism(std::move(mechanism)), _hasMechanism(true), _hasDbName(true) {
    // Used for initialization only
}


AuthenticateCommand AuthenticateCommand::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<AuthenticateCommand>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void AuthenticateCommand::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<3> usedFields;
    const size_t kMechanismBit = 0;
    const size_t kUserBit = 1;
    const size_t kDbNameBit = 2;
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
        else if (fieldName == kUserFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kUserBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUserBit);

                _user = element.str();
            }
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
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

}

AuthenticateCommand AuthenticateCommand::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto object = mongo::idl::preparsedValue<AuthenticateCommand>();
    object.parseProtected(ctxt, request);
    return object;
}
void AuthenticateCommand::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<3> usedFields;
    const size_t kMechanismBit = 0;
    const size_t kUserBit = 1;
    const size_t kDbNameBit = 2;
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
        else if (fieldName == kUserFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kUserBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUserBit);

                _user = element.str();
            }
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
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

}

void AuthenticateCommand::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasMechanism && _hasDbName);

    builder->append("authenticate"_sd, 1);
    builder->append(kMechanismFieldName, _mechanism);

    if (_user.is_initialized()) {
        builder->append(kUserFieldName, _user.get());
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest AuthenticateCommand::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasMechanism && _hasDbName);

        builder->append("authenticate"_sd, 1);
        builder->append(kMechanismFieldName, _mechanism);

        if (_user.is_initialized()) {
            builder->append(kUserFieldName, _user.get());
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj AuthenticateCommand::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData LogoutCommand::kDbNameFieldName;
constexpr StringData LogoutCommand::kCommandName;

const std::vector<StringData> LogoutCommand::_knownBSONFields {
    LogoutCommand::kCommandName,
};
const std::vector<StringData> LogoutCommand::_knownOP_MSGFields {
    LogoutCommand::kDbNameFieldName,
    LogoutCommand::kCommandName,
};

LogoutCommand::LogoutCommand() : _hasDbName(false) {
    // Used for initialization only
}


LogoutCommand LogoutCommand::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<LogoutCommand>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void LogoutCommand::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kDbNameBit = 0;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kDbNameFieldName) {
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
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

}

LogoutCommand LogoutCommand::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto object = mongo::idl::preparsedValue<LogoutCommand>();
    object.parseProtected(ctxt, request);
    return object;
}
void LogoutCommand::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<1> usedFields;
    const size_t kDbNameBit = 0;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kDbNameFieldName) {
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
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

}

void LogoutCommand::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    builder->append("logout"_sd, 1);
    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest LogoutCommand::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        builder->append("logout"_sd, 1);
        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj LogoutCommand::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
