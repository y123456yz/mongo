/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/drop_database_gen.h --output build/opt/mongo/db/drop_database_gen.cpp src/mongo/db/drop_database.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/drop_database_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData DropDatabase::kCommandParameterFieldName;
constexpr StringData DropDatabase::kDbNameFieldName;
constexpr StringData DropDatabase::kCommandName;

mongo::AuthorizationContract DropDatabase::kAuthorizationContract = AuthorizationContract(std::initializer_list<AccessCheckEnum>{}, std::initializer_list<Privilege>{Privilege(ResourcePattern::forAuthorizationContract(MatchTypeEnum::kMatchExactNamespace), ActionSet{ActionType::dropDatabase})});

const std::vector<StringData> DropDatabase::_knownBSONFields {
    DropDatabase::kCommandName,
};
const std::vector<StringData> DropDatabase::_knownOP_MSGFields {
    DropDatabase::kDbNameFieldName,
    DropDatabase::kCommandName,
};

DropDatabase::DropDatabase(const std::int64_t commandParameter) : _commandParameter(std::move(commandParameter)), _hasDbName(false) {
    // Used for initialization only
}


DropDatabase DropDatabase::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto localCmdType = mongo::idl::preparsedValue<std::int64_t>();
    DropDatabase object(localCmdType);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void DropDatabase::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
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
        if (MONGO_likely(ctxt.checkAndAssertTypes(commandElement, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
            _commandParameter = commandElement.safeNumberLong();
        }
        else {
            ctxt.throwMissingField(kCommandParameterFieldName);
        }
    }
}

DropDatabase DropDatabase::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto localCmdType = mongo::idl::preparsedValue<std::int64_t>();
    DropDatabase object(localCmdType);
    object.parseProtected(ctxt, request);
    return object;
}
void DropDatabase::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
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
        if (MONGO_likely(ctxt.checkAndAssertTypes(commandElement, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
            _commandParameter = commandElement.safeNumberLong();
        }
        else {
            ctxt.throwMissingField(kCommandParameterFieldName);
        }
    }
}

void DropDatabase::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    builder->append(kCommandParameterFieldName, _commandParameter);
    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest DropDatabase::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        builder->append(kCommandParameterFieldName, _commandParameter);
        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj DropDatabase::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
