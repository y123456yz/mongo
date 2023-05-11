/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/commands/generic_gen.h --output build/opt/mongo/db/commands/generic_gen.cpp src/mongo/db/commands/generic.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/commands/generic_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

/**
 * Severity level to log message at
 */
namespace  {
constexpr StringData kMessageSeverity_kSevere = "severe"_sd;
constexpr StringData kMessageSeverity_kError = "error"_sd;
constexpr StringData kMessageSeverity_kWarning = "warning"_sd;
constexpr StringData kMessageSeverity_kInfo = "info"_sd;
constexpr StringData kMessageSeverity_kLog = "log"_sd;
constexpr StringData kMessageSeverity_kDebug = "debug"_sd;
}  // namespace 

MessageSeverityEnum MessageSeverity_parse(const IDLParserErrorContext& ctxt, StringData value) {
    if (value == kMessageSeverity_kSevere) {
        return MessageSeverityEnum::kSevere;
    }
    if (value == kMessageSeverity_kError) {
        return MessageSeverityEnum::kError;
    }
    if (value == kMessageSeverity_kWarning) {
        return MessageSeverityEnum::kWarning;
    }
    if (value == kMessageSeverity_kInfo) {
        return MessageSeverityEnum::kInfo;
    }
    if (value == kMessageSeverity_kLog) {
        return MessageSeverityEnum::kLog;
    }
    if (value == kMessageSeverity_kDebug) {
        return MessageSeverityEnum::kDebug;
    }
    ctxt.throwBadEnumValue(value);
}

StringData MessageSeverity_serializer(MessageSeverityEnum value) {
    if (value == MessageSeverityEnum::kSevere) {
        return kMessageSeverity_kSevere;
    }
    if (value == MessageSeverityEnum::kError) {
        return kMessageSeverity_kError;
    }
    if (value == MessageSeverityEnum::kWarning) {
        return kMessageSeverity_kWarning;
    }
    if (value == MessageSeverityEnum::kInfo) {
        return kMessageSeverity_kInfo;
    }
    if (value == MessageSeverityEnum::kLog) {
        return kMessageSeverity_kLog;
    }
    if (value == MessageSeverityEnum::kDebug) {
        return kMessageSeverity_kDebug;
    }
    MONGO_UNREACHABLE;
    return StringData();
}

constexpr StringData LogMessageCommand::kCommandParameterFieldName;
constexpr StringData LogMessageCommand::kDbNameFieldName;
constexpr StringData LogMessageCommand::kDebugLevelFieldName;
constexpr StringData LogMessageCommand::kExtraFieldName;
constexpr StringData LogMessageCommand::kSeverityFieldName;
constexpr StringData LogMessageCommand::kCommandName;

const std::vector<StringData> LogMessageCommand::_knownBSONFields {
    LogMessageCommand::kDebugLevelFieldName,
    LogMessageCommand::kExtraFieldName,
    LogMessageCommand::kSeverityFieldName,
    LogMessageCommand::kCommandName,
};
const std::vector<StringData> LogMessageCommand::_knownOP_MSGFields {
    LogMessageCommand::kDbNameFieldName,
    LogMessageCommand::kDebugLevelFieldName,
    LogMessageCommand::kExtraFieldName,
    LogMessageCommand::kSeverityFieldName,
    LogMessageCommand::kCommandName,
};

LogMessageCommand::LogMessageCommand(const std::string commandParameter) : _commandParameter(std::move(commandParameter)), _hasDbName(false) {
    // Used for initialization only
}

void LogMessageCommand::validateDebugLevel(IDLParserErrorContext& ctxt, const std::int32_t value)
{
    if (!(value >= 1)) {
        throwComparisonError<std::int32_t>(ctxt, "debugLevel", ">="_sd, value, 1);
    }
    if (!(value <= 5)) {
        throwComparisonError<std::int32_t>(ctxt, "debugLevel", "<="_sd, value, 5);
    }
}

void LogMessageCommand::validateDebugLevel(const std::int32_t value)
{
    if (!(value >= 1)) {
        throwComparisonError<std::int32_t>("debugLevel", ">="_sd, value, 1);
    }
    if (!(value <= 5)) {
        throwComparisonError<std::int32_t>("debugLevel", "<="_sd, value, 5);
    }
}


LogMessageCommand LogMessageCommand::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto localCmdType = mongo::idl::preparsedValue<std::string>();
    LogMessageCommand object(localCmdType);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void LogMessageCommand::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<4> usedFields;
    const size_t kExtraBit = 0;
    const size_t kSeverityBit = 1;
    const size_t kDebugLevelBit = 2;
    const size_t kDbNameBit = 3;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kExtraFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kExtraBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kExtraBit);

                _extra = element.Obj();
            }
        }
        else if (fieldName == kSeverityFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kSeverityBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSeverityBit);

                IDLParserErrorContext tempContext(kSeverityFieldName, &ctxt);
                _severity = MessageSeverity_parse(tempContext, element.valueStringData());
            }
        }
        else if (fieldName == kDebugLevelFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberInt))) {
                if (MONGO_unlikely(usedFields[kDebugLevelBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDebugLevelBit);

                {
                    auto value = element._numberInt();
                    validateDebugLevel(value);
                    _debugLevel = std::move(value);
                }
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
        if (!usedFields[kSeverityBit]) {
            _severity = mongo::MessageSeverityEnum::kLog;
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    {
        if (MONGO_likely(ctxt.checkAndAssertType(commandElement, String))) {
            _commandParameter = commandElement.str();
        }
        else {
            ctxt.throwMissingField(kCommandParameterFieldName);
        }
    }
}

LogMessageCommand LogMessageCommand::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto localCmdType = mongo::idl::preparsedValue<std::string>();
    LogMessageCommand object(localCmdType);
    object.parseProtected(ctxt, request);
    return object;
}
void LogMessageCommand::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<4> usedFields;
    const size_t kExtraBit = 0;
    const size_t kSeverityBit = 1;
    const size_t kDebugLevelBit = 2;
    const size_t kDbNameBit = 3;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kExtraFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kExtraBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kExtraBit);

                _extra = element.Obj();
            }
        }
        else if (fieldName == kSeverityFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kSeverityBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSeverityBit);

                IDLParserErrorContext tempContext(kSeverityFieldName, &ctxt);
                _severity = MessageSeverity_parse(tempContext, element.valueStringData());
            }
        }
        else if (fieldName == kDebugLevelFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberInt))) {
                if (MONGO_unlikely(usedFields[kDebugLevelBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDebugLevelBit);

                {
                    auto value = element._numberInt();
                    validateDebugLevel(value);
                    _debugLevel = std::move(value);
                }
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
        if (!usedFields[kSeverityBit]) {
            _severity = mongo::MessageSeverityEnum::kLog;
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    {
        if (MONGO_likely(ctxt.checkAndAssertType(commandElement, String))) {
            _commandParameter = commandElement.str();
        }
        else {
            ctxt.throwMissingField(kCommandParameterFieldName);
        }
    }
}

void LogMessageCommand::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    builder->append(kCommandParameterFieldName, _commandParameter);
    if (_extra.is_initialized()) {
        builder->append(kExtraFieldName, _extra.get());
    }

    {
        builder->append(kSeverityFieldName, ::mongo::MessageSeverity_serializer(_severity));
    }

    if (_debugLevel.is_initialized()) {
        builder->append(kDebugLevelFieldName, _debugLevel.get());
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest LogMessageCommand::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        builder->append(kCommandParameterFieldName, _commandParameter);
        if (_extra.is_initialized()) {
            builder->append(kExtraFieldName, _extra.get());
        }

        {
            builder->append(kSeverityFieldName, ::mongo::MessageSeverity_serializer(_severity));
        }

        if (_debugLevel.is_initialized()) {
            builder->append(kDebugLevelFieldName, _debugLevel.get());
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj LogMessageCommand::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData Ping::kDbNameFieldName;
constexpr StringData Ping::kCommandName;

mongo::AuthorizationContract Ping::kAuthorizationContract = AuthorizationContract(std::initializer_list<AccessCheckEnum>{}, std::initializer_list<Privilege>{});

const std::vector<StringData> Ping::_knownBSONFields {
    Ping::kCommandName,
};
const std::vector<StringData> Ping::_knownOP_MSGFields {
    Ping::kDbNameFieldName,
    Ping::kCommandName,
};

Ping::Ping() : _hasDbName(false) {
    // Used for initialization only
}


Ping Ping::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<Ping>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void Ping::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
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

Ping Ping::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto object = mongo::idl::preparsedValue<Ping>();
    object.parseProtected(ctxt, request);
    return object;
}
void Ping::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
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

void Ping::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    builder->append("ping"_sd, 1);
    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest Ping::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        builder->append("ping"_sd, 1);
        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj Ping::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
