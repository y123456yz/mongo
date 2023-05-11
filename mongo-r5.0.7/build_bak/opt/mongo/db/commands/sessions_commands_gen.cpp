/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/commands/sessions_commands_gen.h --output build/opt/mongo/db/commands/sessions_commands_gen.cpp src/mongo/db/commands/sessions_commands.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/commands/sessions_commands_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData EndSessionsFromClient::kCommandParameterFieldName;
constexpr StringData EndSessionsFromClient::kDbNameFieldName;
constexpr StringData EndSessionsFromClient::kCommandName;

mongo::AuthorizationContract EndSessionsFromClient::kAuthorizationContract = AuthorizationContract(std::initializer_list<AccessCheckEnum>{AccessCheckEnum::kGetSingleUser,AccessCheckEnum::kLookupUser}, std::initializer_list<Privilege>{});

const std::vector<StringData> EndSessionsFromClient::_knownBSONFields {
    EndSessionsFromClient::kCommandName,
};
const std::vector<StringData> EndSessionsFromClient::_knownOP_MSGFields {
    EndSessionsFromClient::kDbNameFieldName,
    EndSessionsFromClient::kCommandName,
};

EndSessionsFromClient::EndSessionsFromClient(const std::vector<mongo::LogicalSessionFromClient> commandParameter) : _commandParameter(std::move(commandParameter)), _hasDbName(false) {
    // Used for initialization only
}


EndSessionsFromClient EndSessionsFromClient::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto localCmdType = mongo::idl::preparsedValue<std::vector<mongo::LogicalSessionFromClient>>();
    EndSessionsFromClient object(localCmdType);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void EndSessionsFromClient::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kDbNameBit = 0;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
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

    {
        if (MONGO_likely(ctxt.checkAndAssertType(commandElement, Array))) {
        }
        std::uint32_t expectedFieldNumber{0};
        const IDLParserErrorContext arrayCtxt(kCommandParameterFieldName, &ctxt);
        std::vector<mongo::LogicalSessionFromClient> values;

        const BSONObj arrayObject = commandElement.Obj();
        for (const auto& arrayElement : arrayObject) {
            const auto arrayFieldName = arrayElement.fieldNameStringData();
            std::uint32_t fieldNumber;

            Status status = NumberParser{}(arrayFieldName, &fieldNumber);
            if (status.isOK()) {
                if (fieldNumber != expectedFieldNumber) {
                    arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                }

                if (arrayCtxt.checkAndAssertType(arrayElement, Object)) {
                    IDLParserErrorContext tempContext(kCommandParameterFieldName, &ctxt);
                    const auto localObject = arrayElement.Obj();
                    values.emplace_back(mongo::LogicalSessionFromClient::parse(tempContext, localObject));
                }
            }
            else {
                arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
            }
            ++expectedFieldNumber;
        }
        _commandParameter = std::move(values);
    }
}

EndSessionsFromClient EndSessionsFromClient::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto localCmdType = mongo::idl::preparsedValue<std::vector<mongo::LogicalSessionFromClient>>();
    EndSessionsFromClient object(localCmdType);
    object.parseProtected(ctxt, request);
    return object;
}
void EndSessionsFromClient::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<1> usedFields;
    const size_t kDbNameBit = 0;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
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

    {
        if (MONGO_likely(ctxt.checkAndAssertType(commandElement, Array))) {
        }
        std::uint32_t expectedFieldNumber{0};
        const IDLParserErrorContext arrayCtxt(kCommandParameterFieldName, &ctxt);
        std::vector<mongo::LogicalSessionFromClient> values;

        const BSONObj arrayObject = commandElement.Obj();
        for (const auto& arrayElement : arrayObject) {
            const auto arrayFieldName = arrayElement.fieldNameStringData();
            std::uint32_t fieldNumber;

            Status status = NumberParser{}(arrayFieldName, &fieldNumber);
            if (status.isOK()) {
                if (fieldNumber != expectedFieldNumber) {
                    arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                }

                if (arrayCtxt.checkAndAssertType(arrayElement, Object)) {
                    IDLParserErrorContext tempContext(kCommandParameterFieldName, &ctxt);
                    const auto localObject = arrayElement.Obj();
                    values.emplace_back(mongo::LogicalSessionFromClient::parse(tempContext, localObject));
                }
            }
            else {
                arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
            }
            ++expectedFieldNumber;
        }
        _commandParameter = std::move(values);
    }
}

void EndSessionsFromClient::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kCommandParameterFieldName));
        for (const auto& item : _commandParameter) {
            BSONObjBuilder subObjBuilder(arrayBuilder.subobjStart());
            item.serialize(&subObjBuilder);
        }
    }
    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest EndSessionsFromClient::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        {
            BSONArrayBuilder arrayBuilder(builder->subarrayStart(kCommandParameterFieldName));
            for (const auto& item : _commandParameter) {
                BSONObjBuilder subObjBuilder(arrayBuilder.subobjStart());
                item.serialize(&subObjBuilder);
            }
        }
        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj EndSessionsFromClient::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData RefreshSessionsFromClient::kCommandParameterFieldName;
constexpr StringData RefreshSessionsFromClient::kDbNameFieldName;
constexpr StringData RefreshSessionsFromClient::kCommandName;

mongo::AuthorizationContract RefreshSessionsFromClient::kAuthorizationContract = AuthorizationContract(std::initializer_list<AccessCheckEnum>{AccessCheckEnum::kGetSingleUser,AccessCheckEnum::kLookupUser}, std::initializer_list<Privilege>{});

const std::vector<StringData> RefreshSessionsFromClient::_knownBSONFields {
    RefreshSessionsFromClient::kCommandName,
};
const std::vector<StringData> RefreshSessionsFromClient::_knownOP_MSGFields {
    RefreshSessionsFromClient::kDbNameFieldName,
    RefreshSessionsFromClient::kCommandName,
};

RefreshSessionsFromClient::RefreshSessionsFromClient(const std::vector<mongo::LogicalSessionFromClient> commandParameter) : _commandParameter(std::move(commandParameter)), _hasDbName(false) {
    // Used for initialization only
}


RefreshSessionsFromClient RefreshSessionsFromClient::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto localCmdType = mongo::idl::preparsedValue<std::vector<mongo::LogicalSessionFromClient>>();
    RefreshSessionsFromClient object(localCmdType);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void RefreshSessionsFromClient::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kDbNameBit = 0;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
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

    {
        if (MONGO_likely(ctxt.checkAndAssertType(commandElement, Array))) {
        }
        std::uint32_t expectedFieldNumber{0};
        const IDLParserErrorContext arrayCtxt(kCommandParameterFieldName, &ctxt);
        std::vector<mongo::LogicalSessionFromClient> values;

        const BSONObj arrayObject = commandElement.Obj();
        for (const auto& arrayElement : arrayObject) {
            const auto arrayFieldName = arrayElement.fieldNameStringData();
            std::uint32_t fieldNumber;

            Status status = NumberParser{}(arrayFieldName, &fieldNumber);
            if (status.isOK()) {
                if (fieldNumber != expectedFieldNumber) {
                    arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                }

                if (arrayCtxt.checkAndAssertType(arrayElement, Object)) {
                    IDLParserErrorContext tempContext(kCommandParameterFieldName, &ctxt);
                    const auto localObject = arrayElement.Obj();
                    values.emplace_back(mongo::LogicalSessionFromClient::parse(tempContext, localObject));
                }
            }
            else {
                arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
            }
            ++expectedFieldNumber;
        }
        _commandParameter = std::move(values);
    }
}

RefreshSessionsFromClient RefreshSessionsFromClient::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto localCmdType = mongo::idl::preparsedValue<std::vector<mongo::LogicalSessionFromClient>>();
    RefreshSessionsFromClient object(localCmdType);
    object.parseProtected(ctxt, request);
    return object;
}
void RefreshSessionsFromClient::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<1> usedFields;
    const size_t kDbNameBit = 0;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
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

    {
        if (MONGO_likely(ctxt.checkAndAssertType(commandElement, Array))) {
        }
        std::uint32_t expectedFieldNumber{0};
        const IDLParserErrorContext arrayCtxt(kCommandParameterFieldName, &ctxt);
        std::vector<mongo::LogicalSessionFromClient> values;

        const BSONObj arrayObject = commandElement.Obj();
        for (const auto& arrayElement : arrayObject) {
            const auto arrayFieldName = arrayElement.fieldNameStringData();
            std::uint32_t fieldNumber;

            Status status = NumberParser{}(arrayFieldName, &fieldNumber);
            if (status.isOK()) {
                if (fieldNumber != expectedFieldNumber) {
                    arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                }

                if (arrayCtxt.checkAndAssertType(arrayElement, Object)) {
                    IDLParserErrorContext tempContext(kCommandParameterFieldName, &ctxt);
                    const auto localObject = arrayElement.Obj();
                    values.emplace_back(mongo::LogicalSessionFromClient::parse(tempContext, localObject));
                }
            }
            else {
                arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
            }
            ++expectedFieldNumber;
        }
        _commandParameter = std::move(values);
    }
}

void RefreshSessionsFromClient::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kCommandParameterFieldName));
        for (const auto& item : _commandParameter) {
            BSONObjBuilder subObjBuilder(arrayBuilder.subobjStart());
            item.serialize(&subObjBuilder);
        }
    }
    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest RefreshSessionsFromClient::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        {
            BSONArrayBuilder arrayBuilder(builder->subarrayStart(kCommandParameterFieldName));
            for (const auto& item : _commandParameter) {
                BSONObjBuilder subObjBuilder(arrayBuilder.subobjStart());
                item.serialize(&subObjBuilder);
            }
        }
        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj RefreshSessionsFromClient::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
