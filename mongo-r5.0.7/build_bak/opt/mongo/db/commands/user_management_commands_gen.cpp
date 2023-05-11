/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/commands/user_management_commands_gen.h --output build/opt/mongo/db/commands/user_management_commands_gen.cpp src/mongo/db/commands/user_management_commands.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/commands/user_management_commands_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData DropAllUsersFromDatabaseReply::kCountFieldName;


DropAllUsersFromDatabaseReply::DropAllUsersFromDatabaseReply() : _count(mongo::idl::preparsedValue<decltype(_count)>()), _hasCount(false) {
    // Used for initialization only
}
DropAllUsersFromDatabaseReply::DropAllUsersFromDatabaseReply(std::int32_t count) : _count(std::move(count)), _hasCount(true) {
    // Used for initialization only
}


DropAllUsersFromDatabaseReply DropAllUsersFromDatabaseReply::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<DropAllUsersFromDatabaseReply>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void DropAllUsersFromDatabaseReply::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kCountBit = 0;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kCountFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberInt))) {
                if (MONGO_unlikely(usedFields[kCountBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCountBit);

                _hasCount = true;
                _count = element._numberInt();
            }
        }
        else {
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kCountBit]) {
            ctxt.throwMissingField(kCountFieldName);
        }
    }

}


void DropAllUsersFromDatabaseReply::serialize(BSONObjBuilder* builder) const {
    invariant(_hasCount);

    builder->append(kCountFieldName, _count);

}


BSONObj DropAllUsersFromDatabaseReply::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData DropAllRolesFromDatabaseReply::kCountFieldName;


DropAllRolesFromDatabaseReply::DropAllRolesFromDatabaseReply() : _count(mongo::idl::preparsedValue<decltype(_count)>()), _hasCount(false) {
    // Used for initialization only
}
DropAllRolesFromDatabaseReply::DropAllRolesFromDatabaseReply(std::int32_t count) : _count(std::move(count)), _hasCount(true) {
    // Used for initialization only
}


DropAllRolesFromDatabaseReply DropAllRolesFromDatabaseReply::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<DropAllRolesFromDatabaseReply>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void DropAllRolesFromDatabaseReply::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kCountBit = 0;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kCountFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberInt))) {
                if (MONGO_unlikely(usedFields[kCountBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCountBit);

                _hasCount = true;
                _count = element._numberInt();
            }
        }
        else {
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kCountBit]) {
            ctxt.throwMissingField(kCountFieldName);
        }
    }

}


void DropAllRolesFromDatabaseReply::serialize(BSONObjBuilder* builder) const {
    invariant(_hasCount);

    builder->append(kCountFieldName, _count);

}


BSONObj DropAllRolesFromDatabaseReply::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData UsersInfoReply::kUsersFieldName;


UsersInfoReply::UsersInfoReply() : _hasUsers(false) {
    // Used for initialization only
}
UsersInfoReply::UsersInfoReply(std::vector<mongo::BSONObj> users) : _users(std::move(users)), _hasUsers(true) {
    // Used for initialization only
}


UsersInfoReply UsersInfoReply::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<UsersInfoReply>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void UsersInfoReply::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kUsersBit = 0;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kUsersFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kUsersBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUsersBit);

                _hasUsers = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kUsersFieldName, &ctxt);
            std::vector<mongo::BSONObj> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, Object)) {
                        const BSONObj localObject = arrayElement.Obj();
                        values.emplace_back(BSONObj::getOwned(localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _users = std::move(values);
        }
        else {
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kUsersBit]) {
            ctxt.throwMissingField(kUsersFieldName);
        }
    }

}


void UsersInfoReply::serialize(BSONObjBuilder* builder) const {
    invariant(_hasUsers);

    {
        builder->append(kUsersFieldName, _users);
    }

}


BSONObj UsersInfoReply::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData RolesInfoReply::kRolesFieldName;
constexpr StringData RolesInfoReply::kUserFragmentFieldName;


RolesInfoReply::RolesInfoReply()  {
    // Used for initialization only
}


RolesInfoReply RolesInfoReply::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<RolesInfoReply>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void RolesInfoReply::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kRolesBit = 0;
    const size_t kUserFragmentBit = 1;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kRolesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kRolesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRolesBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kRolesFieldName, &ctxt);
            std::vector<mongo::BSONObj> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, Object)) {
                        const BSONObj localObject = arrayElement.Obj();
                        values.emplace_back(BSONObj::getOwned(localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _roles = std::move(values);
        }
        else if (fieldName == kUserFragmentFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kUserFragmentBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUserFragmentBit);

                const BSONObj localObject = element.Obj();
                _userFragment = BSONObj::getOwned(localObject);
            }
        }
        else {
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
    }

}


void RolesInfoReply::serialize(BSONObjBuilder* builder) const {
    if (_roles.is_initialized()) {
        builder->append(kRolesFieldName, _roles.get());
    }

    if (_userFragment.is_initialized()) {
        builder->append(kUserFragmentFieldName, _userFragment.get());
    }

}


BSONObj RolesInfoReply::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData GetUserCacheGenerationReply::kCacheGenerationFieldName;


GetUserCacheGenerationReply::GetUserCacheGenerationReply() : _cacheGeneration(mongo::idl::preparsedValue<decltype(_cacheGeneration)>()), _hasCacheGeneration(false) {
    // Used for initialization only
}
GetUserCacheGenerationReply::GetUserCacheGenerationReply(mongo::OID cacheGeneration) : _cacheGeneration(std::move(cacheGeneration)), _hasCacheGeneration(true) {
    // Used for initialization only
}


GetUserCacheGenerationReply GetUserCacheGenerationReply::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<GetUserCacheGenerationReply>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void GetUserCacheGenerationReply::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kCacheGenerationBit = 0;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kCacheGenerationFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, jstOID))) {
                if (MONGO_unlikely(usedFields[kCacheGenerationBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCacheGenerationBit);

                _hasCacheGeneration = true;
                _cacheGeneration = element.OID();
            }
        }
        else {
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kCacheGenerationBit]) {
            ctxt.throwMissingField(kCacheGenerationFieldName);
        }
    }

}


void GetUserCacheGenerationReply::serialize(BSONObjBuilder* builder) const {
    invariant(_hasCacheGeneration);

    builder->append(kCacheGenerationFieldName, _cacheGeneration);

}


BSONObj GetUserCacheGenerationReply::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData UMCTransactionFailPoint::kCommitDelayMSFieldName;


UMCTransactionFailPoint::UMCTransactionFailPoint()  {
    // Used for initialization only
}

void UMCTransactionFailPoint::validateCommitDelayMS(IDLParserErrorContext& ctxt, const std::int32_t value)
{
    if (!(value >= 0)) {
        throwComparisonError<std::int32_t>(ctxt, "commitDelayMS", ">="_sd, value, 0);
    }
}

void UMCTransactionFailPoint::validateCommitDelayMS(const std::int32_t value)
{
    if (!(value >= 0)) {
        throwComparisonError<std::int32_t>("commitDelayMS", ">="_sd, value, 0);
    }
}


UMCTransactionFailPoint UMCTransactionFailPoint::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<UMCTransactionFailPoint>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void UMCTransactionFailPoint::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kCommitDelayMSBit = 0;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kCommitDelayMSFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberInt))) {
                if (MONGO_unlikely(usedFields[kCommitDelayMSBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCommitDelayMSBit);

                {
                    auto value = element._numberInt();
                    validateCommitDelayMS(value);
                    _commitDelayMS = std::move(value);
                }
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kCommitDelayMSBit]) {
            _commitDelayMS = 0;
        }
    }

}


void UMCTransactionFailPoint::serialize(BSONObjBuilder* builder) const {
    builder->append(kCommitDelayMSFieldName, _commitDelayMS);

}


BSONObj UMCTransactionFailPoint::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData CreateUserCommand::kCommandParameterFieldName;
constexpr StringData CreateUserCommand::kAuthenticationRestrictionsFieldName;
constexpr StringData CreateUserCommand::kCustomDataFieldName;
constexpr StringData CreateUserCommand::kDbNameFieldName;
constexpr StringData CreateUserCommand::kDigestPasswordFieldName;
constexpr StringData CreateUserCommand::kMechanismsFieldName;
constexpr StringData CreateUserCommand::kPwdFieldName;
constexpr StringData CreateUserCommand::kRolesFieldName;
constexpr StringData CreateUserCommand::kWriteConcernFieldName;
constexpr StringData CreateUserCommand::kCommandName;

const std::vector<StringData> CreateUserCommand::_knownBSONFields {
    CreateUserCommand::kAuthenticationRestrictionsFieldName,
    CreateUserCommand::kCustomDataFieldName,
    CreateUserCommand::kDigestPasswordFieldName,
    CreateUserCommand::kMechanismsFieldName,
    CreateUserCommand::kPwdFieldName,
    CreateUserCommand::kRolesFieldName,
    CreateUserCommand::kWriteConcernFieldName,
    CreateUserCommand::kCommandName,
};
const std::vector<StringData> CreateUserCommand::_knownOP_MSGFields {
    CreateUserCommand::kAuthenticationRestrictionsFieldName,
    CreateUserCommand::kCustomDataFieldName,
    CreateUserCommand::kDbNameFieldName,
    CreateUserCommand::kDigestPasswordFieldName,
    CreateUserCommand::kMechanismsFieldName,
    CreateUserCommand::kPwdFieldName,
    CreateUserCommand::kRolesFieldName,
    CreateUserCommand::kWriteConcernFieldName,
    CreateUserCommand::kCommandName,
};

CreateUserCommand::CreateUserCommand(const std::string commandParameter) : _commandParameter(std::move(commandParameter)), _hasRoles(false), _hasDbName(false) {
    // Used for initialization only
}
CreateUserCommand::CreateUserCommand(const std::string commandParameter, std::vector<mongo::RoleNameOrString> roles) : _commandParameter(std::move(commandParameter)), _roles(std::move(roles)), _hasRoles(true), _hasDbName(true) {
    // Used for initialization only
}


CreateUserCommand CreateUserCommand::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto localCmdType = mongo::idl::preparsedValue<std::string>();
    CreateUserCommand object(localCmdType);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void CreateUserCommand::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<8> usedFields;
    const size_t kPwdBit = 0;
    const size_t kCustomDataBit = 1;
    const size_t kRolesBit = 2;
    const size_t kDigestPasswordBit = 3;
    const size_t kWriteConcernBit = 4;
    const size_t kAuthenticationRestrictionsBit = 5;
    const size_t kMechanismsBit = 6;
    const size_t kDbNameBit = 7;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kPwdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kPwdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPwdBit);

                _pwd = element.str();
            }
        }
        else if (fieldName == kCustomDataFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCustomDataBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCustomDataBit);

                _customData = element.Obj();
            }
        }
        else if (fieldName == kRolesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kRolesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRolesBit);

                _hasRoles = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kRolesFieldName, &ctxt);
            std::vector<mongo::RoleNameOrString> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    values.emplace_back(RoleNameOrString::parseFromBSON(arrayElement));
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _roles = std::move(values);
        }
        else if (fieldName == kDigestPasswordFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kDigestPasswordBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDigestPasswordBit);

                _digestPassword = element.trueValue();
            }
        }
        else if (fieldName == kWriteConcernFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kWriteConcernBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kWriteConcernBit);

                _writeConcern = element.Obj();
            }
        }
        else if (fieldName == kAuthenticationRestrictionsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kAuthenticationRestrictionsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAuthenticationRestrictionsBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kAuthenticationRestrictionsFieldName, &ctxt);
            std::vector<mongo::Address_restriction> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, Object)) {
                        IDLParserErrorContext tempContext(kAuthenticationRestrictionsFieldName, &ctxt);
                        const auto localObject = arrayElement.Obj();
                        values.emplace_back(mongo::Address_restriction::parse(tempContext, localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _authenticationRestrictions = std::move(values);
        }
        else if (fieldName == kMechanismsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kMechanismsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMechanismsBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kMechanismsFieldName, &ctxt);
            std::vector<std::string> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, String)) {
                        values.emplace_back(arrayElement.str());
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _mechanisms = std::move(values);
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
        if (!usedFields[kRolesBit]) {
            ctxt.throwMissingField(kRolesFieldName);
        }
        if (!usedFields[kDigestPasswordBit]) {
            _digestPassword = true;
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

CreateUserCommand CreateUserCommand::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto localCmdType = mongo::idl::preparsedValue<std::string>();
    CreateUserCommand object(localCmdType);
    object.parseProtected(ctxt, request);
    return object;
}
void CreateUserCommand::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<8> usedFields;
    const size_t kPwdBit = 0;
    const size_t kCustomDataBit = 1;
    const size_t kRolesBit = 2;
    const size_t kDigestPasswordBit = 3;
    const size_t kWriteConcernBit = 4;
    const size_t kAuthenticationRestrictionsBit = 5;
    const size_t kMechanismsBit = 6;
    const size_t kDbNameBit = 7;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kPwdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kPwdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPwdBit);

                _pwd = element.str();
            }
        }
        else if (fieldName == kCustomDataFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCustomDataBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCustomDataBit);

                _customData = element.Obj();
            }
        }
        else if (fieldName == kRolesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kRolesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRolesBit);

                _hasRoles = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kRolesFieldName, &ctxt);
            std::vector<mongo::RoleNameOrString> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    values.emplace_back(RoleNameOrString::parseFromBSON(arrayElement));
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _roles = std::move(values);
        }
        else if (fieldName == kDigestPasswordFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kDigestPasswordBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDigestPasswordBit);

                _digestPassword = element.trueValue();
            }
        }
        else if (fieldName == kWriteConcernFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kWriteConcernBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kWriteConcernBit);

                _writeConcern = element.Obj();
            }
        }
        else if (fieldName == kAuthenticationRestrictionsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kAuthenticationRestrictionsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAuthenticationRestrictionsBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kAuthenticationRestrictionsFieldName, &ctxt);
            std::vector<mongo::Address_restriction> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, Object)) {
                        IDLParserErrorContext tempContext(kAuthenticationRestrictionsFieldName, &ctxt);
                        const auto localObject = arrayElement.Obj();
                        values.emplace_back(mongo::Address_restriction::parse(tempContext, localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _authenticationRestrictions = std::move(values);
        }
        else if (fieldName == kMechanismsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kMechanismsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMechanismsBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kMechanismsFieldName, &ctxt);
            std::vector<std::string> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, String)) {
                        values.emplace_back(arrayElement.str());
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _mechanisms = std::move(values);
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
        if (!usedFields[kRolesBit]) {
            ctxt.throwMissingField(kRolesFieldName);
        }
        if (!usedFields[kDigestPasswordBit]) {
            _digestPassword = true;
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

void CreateUserCommand::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasRoles && _hasDbName);

    builder->append(kCommandParameterFieldName, _commandParameter);
    if (_pwd.is_initialized()) {
        builder->append(kPwdFieldName, _pwd.get());
    }

    if (_customData.is_initialized()) {
        builder->append(kCustomDataFieldName, _customData.get());
    }

    {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kRolesFieldName));
        for (const auto& item : _roles) {
            item.serializeToBSON(&arrayBuilder);
        }
    }

    builder->append(kDigestPasswordFieldName, _digestPassword);

    if (_writeConcern.is_initialized()) {
        builder->append(kWriteConcernFieldName, _writeConcern.get());
    }

    if (_authenticationRestrictions.is_initialized()) {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kAuthenticationRestrictionsFieldName));
        for (const auto& item : _authenticationRestrictions.get()) {
            BSONObjBuilder subObjBuilder(arrayBuilder.subobjStart());
            item.serialize(&subObjBuilder);
        }
    }

    if (_mechanisms.is_initialized()) {
        builder->append(kMechanismsFieldName, _mechanisms.get());
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest CreateUserCommand::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasRoles && _hasDbName);

        builder->append(kCommandParameterFieldName, _commandParameter);
        if (_pwd.is_initialized()) {
            builder->append(kPwdFieldName, _pwd.get());
        }

        if (_customData.is_initialized()) {
            builder->append(kCustomDataFieldName, _customData.get());
        }

        {
            BSONArrayBuilder arrayBuilder(builder->subarrayStart(kRolesFieldName));
            for (const auto& item : _roles) {
                item.serializeToBSON(&arrayBuilder);
            }
        }

        builder->append(kDigestPasswordFieldName, _digestPassword);

        if (_writeConcern.is_initialized()) {
            builder->append(kWriteConcernFieldName, _writeConcern.get());
        }

        if (_authenticationRestrictions.is_initialized()) {
            BSONArrayBuilder arrayBuilder(builder->subarrayStart(kAuthenticationRestrictionsFieldName));
            for (const auto& item : _authenticationRestrictions.get()) {
                BSONObjBuilder subObjBuilder(arrayBuilder.subobjStart());
                item.serialize(&subObjBuilder);
            }
        }

        if (_mechanisms.is_initialized()) {
            builder->append(kMechanismsFieldName, _mechanisms.get());
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj CreateUserCommand::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData UpdateUserCommand::kCommandParameterFieldName;
constexpr StringData UpdateUserCommand::kAuthenticationRestrictionsFieldName;
constexpr StringData UpdateUserCommand::kCustomDataFieldName;
constexpr StringData UpdateUserCommand::kDbNameFieldName;
constexpr StringData UpdateUserCommand::kDigestPasswordFieldName;
constexpr StringData UpdateUserCommand::kMechanismsFieldName;
constexpr StringData UpdateUserCommand::kPwdFieldName;
constexpr StringData UpdateUserCommand::kRolesFieldName;
constexpr StringData UpdateUserCommand::kWriteConcernFieldName;
constexpr StringData UpdateUserCommand::kCommandName;

const std::vector<StringData> UpdateUserCommand::_knownBSONFields {
    UpdateUserCommand::kAuthenticationRestrictionsFieldName,
    UpdateUserCommand::kCustomDataFieldName,
    UpdateUserCommand::kDigestPasswordFieldName,
    UpdateUserCommand::kMechanismsFieldName,
    UpdateUserCommand::kPwdFieldName,
    UpdateUserCommand::kRolesFieldName,
    UpdateUserCommand::kWriteConcernFieldName,
    UpdateUserCommand::kCommandName,
};
const std::vector<StringData> UpdateUserCommand::_knownOP_MSGFields {
    UpdateUserCommand::kAuthenticationRestrictionsFieldName,
    UpdateUserCommand::kCustomDataFieldName,
    UpdateUserCommand::kDbNameFieldName,
    UpdateUserCommand::kDigestPasswordFieldName,
    UpdateUserCommand::kMechanismsFieldName,
    UpdateUserCommand::kPwdFieldName,
    UpdateUserCommand::kRolesFieldName,
    UpdateUserCommand::kWriteConcernFieldName,
    UpdateUserCommand::kCommandName,
};

UpdateUserCommand::UpdateUserCommand(const std::string commandParameter) : _commandParameter(std::move(commandParameter)), _hasDbName(false) {
    // Used for initialization only
}


UpdateUserCommand UpdateUserCommand::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto localCmdType = mongo::idl::preparsedValue<std::string>();
    UpdateUserCommand object(localCmdType);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void UpdateUserCommand::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<8> usedFields;
    const size_t kPwdBit = 0;
    const size_t kCustomDataBit = 1;
    const size_t kRolesBit = 2;
    const size_t kDigestPasswordBit = 3;
    const size_t kWriteConcernBit = 4;
    const size_t kAuthenticationRestrictionsBit = 5;
    const size_t kMechanismsBit = 6;
    const size_t kDbNameBit = 7;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kPwdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kPwdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPwdBit);

                _pwd = element.str();
            }
        }
        else if (fieldName == kCustomDataFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCustomDataBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCustomDataBit);

                _customData = element.Obj();
            }
        }
        else if (fieldName == kRolesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kRolesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRolesBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kRolesFieldName, &ctxt);
            std::vector<mongo::RoleNameOrString> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    values.emplace_back(RoleNameOrString::parseFromBSON(arrayElement));
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _roles = std::move(values);
        }
        else if (fieldName == kDigestPasswordFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kDigestPasswordBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDigestPasswordBit);

                _digestPassword = element.trueValue();
            }
        }
        else if (fieldName == kWriteConcernFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kWriteConcernBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kWriteConcernBit);

                _writeConcern = element.Obj();
            }
        }
        else if (fieldName == kAuthenticationRestrictionsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kAuthenticationRestrictionsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAuthenticationRestrictionsBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kAuthenticationRestrictionsFieldName, &ctxt);
            std::vector<mongo::Address_restriction> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, Object)) {
                        IDLParserErrorContext tempContext(kAuthenticationRestrictionsFieldName, &ctxt);
                        const auto localObject = arrayElement.Obj();
                        values.emplace_back(mongo::Address_restriction::parse(tempContext, localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _authenticationRestrictions = std::move(values);
        }
        else if (fieldName == kMechanismsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kMechanismsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMechanismsBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kMechanismsFieldName, &ctxt);
            std::vector<std::string> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, String)) {
                        values.emplace_back(arrayElement.str());
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _mechanisms = std::move(values);
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
        if (!usedFields[kDigestPasswordBit]) {
            _digestPassword = true;
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

UpdateUserCommand UpdateUserCommand::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto localCmdType = mongo::idl::preparsedValue<std::string>();
    UpdateUserCommand object(localCmdType);
    object.parseProtected(ctxt, request);
    return object;
}
void UpdateUserCommand::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<8> usedFields;
    const size_t kPwdBit = 0;
    const size_t kCustomDataBit = 1;
    const size_t kRolesBit = 2;
    const size_t kDigestPasswordBit = 3;
    const size_t kWriteConcernBit = 4;
    const size_t kAuthenticationRestrictionsBit = 5;
    const size_t kMechanismsBit = 6;
    const size_t kDbNameBit = 7;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kPwdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kPwdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPwdBit);

                _pwd = element.str();
            }
        }
        else if (fieldName == kCustomDataFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCustomDataBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCustomDataBit);

                _customData = element.Obj();
            }
        }
        else if (fieldName == kRolesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kRolesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRolesBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kRolesFieldName, &ctxt);
            std::vector<mongo::RoleNameOrString> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    values.emplace_back(RoleNameOrString::parseFromBSON(arrayElement));
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _roles = std::move(values);
        }
        else if (fieldName == kDigestPasswordFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kDigestPasswordBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDigestPasswordBit);

                _digestPassword = element.trueValue();
            }
        }
        else if (fieldName == kWriteConcernFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kWriteConcernBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kWriteConcernBit);

                _writeConcern = element.Obj();
            }
        }
        else if (fieldName == kAuthenticationRestrictionsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kAuthenticationRestrictionsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAuthenticationRestrictionsBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kAuthenticationRestrictionsFieldName, &ctxt);
            std::vector<mongo::Address_restriction> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, Object)) {
                        IDLParserErrorContext tempContext(kAuthenticationRestrictionsFieldName, &ctxt);
                        const auto localObject = arrayElement.Obj();
                        values.emplace_back(mongo::Address_restriction::parse(tempContext, localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _authenticationRestrictions = std::move(values);
        }
        else if (fieldName == kMechanismsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kMechanismsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMechanismsBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kMechanismsFieldName, &ctxt);
            std::vector<std::string> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, String)) {
                        values.emplace_back(arrayElement.str());
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _mechanisms = std::move(values);
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
        if (!usedFields[kDigestPasswordBit]) {
            _digestPassword = true;
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

void UpdateUserCommand::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    builder->append(kCommandParameterFieldName, _commandParameter);
    if (_pwd.is_initialized()) {
        builder->append(kPwdFieldName, _pwd.get());
    }

    if (_customData.is_initialized()) {
        builder->append(kCustomDataFieldName, _customData.get());
    }

    if (_roles.is_initialized()) {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kRolesFieldName));
        for (const auto& item : _roles.get()) {
            item.serializeToBSON(&arrayBuilder);
        }
    }

    builder->append(kDigestPasswordFieldName, _digestPassword);

    if (_writeConcern.is_initialized()) {
        builder->append(kWriteConcernFieldName, _writeConcern.get());
    }

    if (_authenticationRestrictions.is_initialized()) {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kAuthenticationRestrictionsFieldName));
        for (const auto& item : _authenticationRestrictions.get()) {
            BSONObjBuilder subObjBuilder(arrayBuilder.subobjStart());
            item.serialize(&subObjBuilder);
        }
    }

    if (_mechanisms.is_initialized()) {
        builder->append(kMechanismsFieldName, _mechanisms.get());
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest UpdateUserCommand::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        builder->append(kCommandParameterFieldName, _commandParameter);
        if (_pwd.is_initialized()) {
            builder->append(kPwdFieldName, _pwd.get());
        }

        if (_customData.is_initialized()) {
            builder->append(kCustomDataFieldName, _customData.get());
        }

        if (_roles.is_initialized()) {
            BSONArrayBuilder arrayBuilder(builder->subarrayStart(kRolesFieldName));
            for (const auto& item : _roles.get()) {
                item.serializeToBSON(&arrayBuilder);
            }
        }

        builder->append(kDigestPasswordFieldName, _digestPassword);

        if (_writeConcern.is_initialized()) {
            builder->append(kWriteConcernFieldName, _writeConcern.get());
        }

        if (_authenticationRestrictions.is_initialized()) {
            BSONArrayBuilder arrayBuilder(builder->subarrayStart(kAuthenticationRestrictionsFieldName));
            for (const auto& item : _authenticationRestrictions.get()) {
                BSONObjBuilder subObjBuilder(arrayBuilder.subobjStart());
                item.serialize(&subObjBuilder);
            }
        }

        if (_mechanisms.is_initialized()) {
            builder->append(kMechanismsFieldName, _mechanisms.get());
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj UpdateUserCommand::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData DropUserCommand::kCommandParameterFieldName;
constexpr StringData DropUserCommand::kDbNameFieldName;
constexpr StringData DropUserCommand::kCommandName;

const std::vector<StringData> DropUserCommand::_knownBSONFields {
    DropUserCommand::kCommandName,
};
const std::vector<StringData> DropUserCommand::_knownOP_MSGFields {
    DropUserCommand::kDbNameFieldName,
    DropUserCommand::kCommandName,
};

DropUserCommand::DropUserCommand(const std::string commandParameter) : _commandParameter(std::move(commandParameter)), _hasDbName(false) {
    // Used for initialization only
}


DropUserCommand DropUserCommand::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto localCmdType = mongo::idl::preparsedValue<std::string>();
    DropUserCommand object(localCmdType);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void DropUserCommand::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
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
        if (MONGO_likely(ctxt.checkAndAssertType(commandElement, String))) {
            _commandParameter = commandElement.str();
        }
        else {
            ctxt.throwMissingField(kCommandParameterFieldName);
        }
    }
}

DropUserCommand DropUserCommand::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto localCmdType = mongo::idl::preparsedValue<std::string>();
    DropUserCommand object(localCmdType);
    object.parseProtected(ctxt, request);
    return object;
}
void DropUserCommand::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
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
        if (MONGO_likely(ctxt.checkAndAssertType(commandElement, String))) {
            _commandParameter = commandElement.str();
        }
        else {
            ctxt.throwMissingField(kCommandParameterFieldName);
        }
    }
}

void DropUserCommand::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    builder->append(kCommandParameterFieldName, _commandParameter);
    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest DropUserCommand::serialize(const BSONObj& commandPassthroughFields) const {
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

BSONObj DropUserCommand::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData DropAllUsersFromDatabaseCommand::kDbNameFieldName;
constexpr StringData DropAllUsersFromDatabaseCommand::kCommandName;

const std::vector<StringData> DropAllUsersFromDatabaseCommand::_knownBSONFields {
    DropAllUsersFromDatabaseCommand::kCommandName,
};
const std::vector<StringData> DropAllUsersFromDatabaseCommand::_knownOP_MSGFields {
    DropAllUsersFromDatabaseCommand::kDbNameFieldName,
    DropAllUsersFromDatabaseCommand::kCommandName,
};

DropAllUsersFromDatabaseCommand::DropAllUsersFromDatabaseCommand() : _hasDbName(false) {
    // Used for initialization only
}


DropAllUsersFromDatabaseCommand DropAllUsersFromDatabaseCommand::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<DropAllUsersFromDatabaseCommand>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void DropAllUsersFromDatabaseCommand::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
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

DropAllUsersFromDatabaseCommand DropAllUsersFromDatabaseCommand::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto object = mongo::idl::preparsedValue<DropAllUsersFromDatabaseCommand>();
    object.parseProtected(ctxt, request);
    return object;
}
void DropAllUsersFromDatabaseCommand::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
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

void DropAllUsersFromDatabaseCommand::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    builder->append("dropAllUsersFromDatabase"_sd, 1);
    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest DropAllUsersFromDatabaseCommand::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        builder->append("dropAllUsersFromDatabase"_sd, 1);
        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj DropAllUsersFromDatabaseCommand::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData GrantRolesToUserCommand::kCommandParameterFieldName;
constexpr StringData GrantRolesToUserCommand::kDbNameFieldName;
constexpr StringData GrantRolesToUserCommand::kRolesFieldName;
constexpr StringData GrantRolesToUserCommand::kCommandName;

const std::vector<StringData> GrantRolesToUserCommand::_knownBSONFields {
    GrantRolesToUserCommand::kRolesFieldName,
    GrantRolesToUserCommand::kCommandName,
};
const std::vector<StringData> GrantRolesToUserCommand::_knownOP_MSGFields {
    GrantRolesToUserCommand::kDbNameFieldName,
    GrantRolesToUserCommand::kRolesFieldName,
    GrantRolesToUserCommand::kCommandName,
};

GrantRolesToUserCommand::GrantRolesToUserCommand(const std::string commandParameter) : _commandParameter(std::move(commandParameter)), _hasRoles(false), _hasDbName(false) {
    // Used for initialization only
}
GrantRolesToUserCommand::GrantRolesToUserCommand(const std::string commandParameter, std::vector<mongo::RoleNameOrString> roles) : _commandParameter(std::move(commandParameter)), _roles(std::move(roles)), _hasRoles(true), _hasDbName(true) {
    // Used for initialization only
}


GrantRolesToUserCommand GrantRolesToUserCommand::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto localCmdType = mongo::idl::preparsedValue<std::string>();
    GrantRolesToUserCommand object(localCmdType);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void GrantRolesToUserCommand::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kRolesBit = 0;
    const size_t kDbNameBit = 1;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kRolesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kRolesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRolesBit);

                _hasRoles = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kRolesFieldName, &ctxt);
            std::vector<mongo::RoleNameOrString> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    values.emplace_back(RoleNameOrString::parseFromBSON(arrayElement));
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _roles = std::move(values);
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
        if (!usedFields[kRolesBit]) {
            ctxt.throwMissingField(kRolesFieldName);
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

GrantRolesToUserCommand GrantRolesToUserCommand::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto localCmdType = mongo::idl::preparsedValue<std::string>();
    GrantRolesToUserCommand object(localCmdType);
    object.parseProtected(ctxt, request);
    return object;
}
void GrantRolesToUserCommand::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<2> usedFields;
    const size_t kRolesBit = 0;
    const size_t kDbNameBit = 1;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kRolesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kRolesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRolesBit);

                _hasRoles = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kRolesFieldName, &ctxt);
            std::vector<mongo::RoleNameOrString> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    values.emplace_back(RoleNameOrString::parseFromBSON(arrayElement));
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _roles = std::move(values);
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
        if (!usedFields[kRolesBit]) {
            ctxt.throwMissingField(kRolesFieldName);
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

void GrantRolesToUserCommand::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasRoles && _hasDbName);

    builder->append(kCommandParameterFieldName, _commandParameter);
    {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kRolesFieldName));
        for (const auto& item : _roles) {
            item.serializeToBSON(&arrayBuilder);
        }
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest GrantRolesToUserCommand::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasRoles && _hasDbName);

        builder->append(kCommandParameterFieldName, _commandParameter);
        {
            BSONArrayBuilder arrayBuilder(builder->subarrayStart(kRolesFieldName));
            for (const auto& item : _roles) {
                item.serializeToBSON(&arrayBuilder);
            }
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj GrantRolesToUserCommand::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData RevokeRolesFromUserCommand::kCommandParameterFieldName;
constexpr StringData RevokeRolesFromUserCommand::kDbNameFieldName;
constexpr StringData RevokeRolesFromUserCommand::kRolesFieldName;
constexpr StringData RevokeRolesFromUserCommand::kCommandName;

const std::vector<StringData> RevokeRolesFromUserCommand::_knownBSONFields {
    RevokeRolesFromUserCommand::kRolesFieldName,
    RevokeRolesFromUserCommand::kCommandName,
};
const std::vector<StringData> RevokeRolesFromUserCommand::_knownOP_MSGFields {
    RevokeRolesFromUserCommand::kDbNameFieldName,
    RevokeRolesFromUserCommand::kRolesFieldName,
    RevokeRolesFromUserCommand::kCommandName,
};

RevokeRolesFromUserCommand::RevokeRolesFromUserCommand(const std::string commandParameter) : _commandParameter(std::move(commandParameter)), _hasRoles(false), _hasDbName(false) {
    // Used for initialization only
}
RevokeRolesFromUserCommand::RevokeRolesFromUserCommand(const std::string commandParameter, std::vector<mongo::RoleNameOrString> roles) : _commandParameter(std::move(commandParameter)), _roles(std::move(roles)), _hasRoles(true), _hasDbName(true) {
    // Used for initialization only
}


RevokeRolesFromUserCommand RevokeRolesFromUserCommand::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto localCmdType = mongo::idl::preparsedValue<std::string>();
    RevokeRolesFromUserCommand object(localCmdType);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void RevokeRolesFromUserCommand::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kRolesBit = 0;
    const size_t kDbNameBit = 1;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kRolesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kRolesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRolesBit);

                _hasRoles = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kRolesFieldName, &ctxt);
            std::vector<mongo::RoleNameOrString> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    values.emplace_back(RoleNameOrString::parseFromBSON(arrayElement));
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _roles = std::move(values);
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
        if (!usedFields[kRolesBit]) {
            ctxt.throwMissingField(kRolesFieldName);
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

RevokeRolesFromUserCommand RevokeRolesFromUserCommand::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto localCmdType = mongo::idl::preparsedValue<std::string>();
    RevokeRolesFromUserCommand object(localCmdType);
    object.parseProtected(ctxt, request);
    return object;
}
void RevokeRolesFromUserCommand::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<2> usedFields;
    const size_t kRolesBit = 0;
    const size_t kDbNameBit = 1;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kRolesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kRolesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRolesBit);

                _hasRoles = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kRolesFieldName, &ctxt);
            std::vector<mongo::RoleNameOrString> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    values.emplace_back(RoleNameOrString::parseFromBSON(arrayElement));
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _roles = std::move(values);
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
        if (!usedFields[kRolesBit]) {
            ctxt.throwMissingField(kRolesFieldName);
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

void RevokeRolesFromUserCommand::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasRoles && _hasDbName);

    builder->append(kCommandParameterFieldName, _commandParameter);
    {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kRolesFieldName));
        for (const auto& item : _roles) {
            item.serializeToBSON(&arrayBuilder);
        }
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest RevokeRolesFromUserCommand::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasRoles && _hasDbName);

        builder->append(kCommandParameterFieldName, _commandParameter);
        {
            BSONArrayBuilder arrayBuilder(builder->subarrayStart(kRolesFieldName));
            for (const auto& item : _roles) {
                item.serializeToBSON(&arrayBuilder);
            }
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj RevokeRolesFromUserCommand::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData CreateRoleCommand::kCommandParameterFieldName;
constexpr StringData CreateRoleCommand::kAuthenticationRestrictionsFieldName;
constexpr StringData CreateRoleCommand::kDbNameFieldName;
constexpr StringData CreateRoleCommand::kPrivilegesFieldName;
constexpr StringData CreateRoleCommand::kRolesFieldName;
constexpr StringData CreateRoleCommand::kCommandName;

const std::vector<StringData> CreateRoleCommand::_knownBSONFields {
    CreateRoleCommand::kAuthenticationRestrictionsFieldName,
    CreateRoleCommand::kPrivilegesFieldName,
    CreateRoleCommand::kRolesFieldName,
    CreateRoleCommand::kCommandName,
};
const std::vector<StringData> CreateRoleCommand::_knownOP_MSGFields {
    CreateRoleCommand::kAuthenticationRestrictionsFieldName,
    CreateRoleCommand::kDbNameFieldName,
    CreateRoleCommand::kPrivilegesFieldName,
    CreateRoleCommand::kRolesFieldName,
    CreateRoleCommand::kCommandName,
};

CreateRoleCommand::CreateRoleCommand(const std::string commandParameter) : _commandParameter(std::move(commandParameter)), _hasPrivileges(false), _hasRoles(false), _hasDbName(false) {
    // Used for initialization only
}
CreateRoleCommand::CreateRoleCommand(const std::string commandParameter, std::vector<mongo::Privilege> privileges, std::vector<mongo::RoleNameOrString> roles) : _commandParameter(std::move(commandParameter)), _privileges(std::move(privileges)), _roles(std::move(roles)), _hasPrivileges(true), _hasRoles(true), _hasDbName(true) {
    // Used for initialization only
}


CreateRoleCommand CreateRoleCommand::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto localCmdType = mongo::idl::preparsedValue<std::string>();
    CreateRoleCommand object(localCmdType);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void CreateRoleCommand::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<4> usedFields;
    const size_t kPrivilegesBit = 0;
    const size_t kRolesBit = 1;
    const size_t kAuthenticationRestrictionsBit = 2;
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

        if (fieldName == kPrivilegesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kPrivilegesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPrivilegesBit);

                _hasPrivileges = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kPrivilegesFieldName, &ctxt);
            std::vector<mongo::Privilege> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, Object)) {
                        const BSONObj localObject = arrayElement.Obj();
                        values.emplace_back(Privilege::fromBSON(localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _privileges = std::move(values);
        }
        else if (fieldName == kRolesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kRolesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRolesBit);

                _hasRoles = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kRolesFieldName, &ctxt);
            std::vector<mongo::RoleNameOrString> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    values.emplace_back(RoleNameOrString::parseFromBSON(arrayElement));
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _roles = std::move(values);
        }
        else if (fieldName == kAuthenticationRestrictionsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kAuthenticationRestrictionsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAuthenticationRestrictionsBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kAuthenticationRestrictionsFieldName, &ctxt);
            std::vector<mongo::Address_restriction> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, Object)) {
                        IDLParserErrorContext tempContext(kAuthenticationRestrictionsFieldName, &ctxt);
                        const auto localObject = arrayElement.Obj();
                        values.emplace_back(mongo::Address_restriction::parse(tempContext, localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _authenticationRestrictions = std::move(values);
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
        if (!usedFields[kPrivilegesBit]) {
            ctxt.throwMissingField(kPrivilegesFieldName);
        }
        if (!usedFields[kRolesBit]) {
            ctxt.throwMissingField(kRolesFieldName);
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

CreateRoleCommand CreateRoleCommand::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto localCmdType = mongo::idl::preparsedValue<std::string>();
    CreateRoleCommand object(localCmdType);
    object.parseProtected(ctxt, request);
    return object;
}
void CreateRoleCommand::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<4> usedFields;
    const size_t kPrivilegesBit = 0;
    const size_t kRolesBit = 1;
    const size_t kAuthenticationRestrictionsBit = 2;
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

        if (fieldName == kPrivilegesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kPrivilegesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPrivilegesBit);

                _hasPrivileges = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kPrivilegesFieldName, &ctxt);
            std::vector<mongo::Privilege> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, Object)) {
                        const BSONObj localObject = arrayElement.Obj();
                        values.emplace_back(Privilege::fromBSON(localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _privileges = std::move(values);
        }
        else if (fieldName == kRolesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kRolesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRolesBit);

                _hasRoles = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kRolesFieldName, &ctxt);
            std::vector<mongo::RoleNameOrString> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    values.emplace_back(RoleNameOrString::parseFromBSON(arrayElement));
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _roles = std::move(values);
        }
        else if (fieldName == kAuthenticationRestrictionsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kAuthenticationRestrictionsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAuthenticationRestrictionsBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kAuthenticationRestrictionsFieldName, &ctxt);
            std::vector<mongo::Address_restriction> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, Object)) {
                        IDLParserErrorContext tempContext(kAuthenticationRestrictionsFieldName, &ctxt);
                        const auto localObject = arrayElement.Obj();
                        values.emplace_back(mongo::Address_restriction::parse(tempContext, localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _authenticationRestrictions = std::move(values);
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
        if (!usedFields[kPrivilegesBit]) {
            ctxt.throwMissingField(kPrivilegesFieldName);
        }
        if (!usedFields[kRolesBit]) {
            ctxt.throwMissingField(kRolesFieldName);
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

void CreateRoleCommand::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasPrivileges && _hasRoles && _hasDbName);

    builder->append(kCommandParameterFieldName, _commandParameter);
    {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kPrivilegesFieldName));
        for (const auto& item : _privileges) {
            const BSONObj localObject = item.toBSON();
            arrayBuilder.append(localObject);
        }
    }

    {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kRolesFieldName));
        for (const auto& item : _roles) {
            item.serializeToBSON(&arrayBuilder);
        }
    }

    if (_authenticationRestrictions.is_initialized()) {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kAuthenticationRestrictionsFieldName));
        for (const auto& item : _authenticationRestrictions.get()) {
            BSONObjBuilder subObjBuilder(arrayBuilder.subobjStart());
            item.serialize(&subObjBuilder);
        }
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest CreateRoleCommand::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasPrivileges && _hasRoles && _hasDbName);

        builder->append(kCommandParameterFieldName, _commandParameter);
        {
            BSONArrayBuilder arrayBuilder(builder->subarrayStart(kPrivilegesFieldName));
            for (const auto& item : _privileges) {
                const BSONObj localObject = item.toBSON();
                arrayBuilder.append(localObject);
            }
        }

        {
            BSONArrayBuilder arrayBuilder(builder->subarrayStart(kRolesFieldName));
            for (const auto& item : _roles) {
                item.serializeToBSON(&arrayBuilder);
            }
        }

        if (_authenticationRestrictions.is_initialized()) {
            BSONArrayBuilder arrayBuilder(builder->subarrayStart(kAuthenticationRestrictionsFieldName));
            for (const auto& item : _authenticationRestrictions.get()) {
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

BSONObj CreateRoleCommand::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData UpdateRoleCommand::kCommandParameterFieldName;
constexpr StringData UpdateRoleCommand::kAuthenticationRestrictionsFieldName;
constexpr StringData UpdateRoleCommand::kDbNameFieldName;
constexpr StringData UpdateRoleCommand::kPrivilegesFieldName;
constexpr StringData UpdateRoleCommand::kRolesFieldName;
constexpr StringData UpdateRoleCommand::kCommandName;

const std::vector<StringData> UpdateRoleCommand::_knownBSONFields {
    UpdateRoleCommand::kAuthenticationRestrictionsFieldName,
    UpdateRoleCommand::kPrivilegesFieldName,
    UpdateRoleCommand::kRolesFieldName,
    UpdateRoleCommand::kCommandName,
};
const std::vector<StringData> UpdateRoleCommand::_knownOP_MSGFields {
    UpdateRoleCommand::kAuthenticationRestrictionsFieldName,
    UpdateRoleCommand::kDbNameFieldName,
    UpdateRoleCommand::kPrivilegesFieldName,
    UpdateRoleCommand::kRolesFieldName,
    UpdateRoleCommand::kCommandName,
};

UpdateRoleCommand::UpdateRoleCommand(const std::string commandParameter) : _commandParameter(std::move(commandParameter)), _hasDbName(false) {
    // Used for initialization only
}


UpdateRoleCommand UpdateRoleCommand::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto localCmdType = mongo::idl::preparsedValue<std::string>();
    UpdateRoleCommand object(localCmdType);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void UpdateRoleCommand::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<4> usedFields;
    const size_t kPrivilegesBit = 0;
    const size_t kRolesBit = 1;
    const size_t kAuthenticationRestrictionsBit = 2;
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

        if (fieldName == kPrivilegesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kPrivilegesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPrivilegesBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kPrivilegesFieldName, &ctxt);
            std::vector<mongo::Privilege> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, Object)) {
                        const BSONObj localObject = arrayElement.Obj();
                        values.emplace_back(Privilege::fromBSON(localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _privileges = std::move(values);
        }
        else if (fieldName == kRolesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kRolesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRolesBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kRolesFieldName, &ctxt);
            std::vector<mongo::RoleNameOrString> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    values.emplace_back(RoleNameOrString::parseFromBSON(arrayElement));
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _roles = std::move(values);
        }
        else if (fieldName == kAuthenticationRestrictionsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kAuthenticationRestrictionsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAuthenticationRestrictionsBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kAuthenticationRestrictionsFieldName, &ctxt);
            std::vector<mongo::Address_restriction> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, Object)) {
                        IDLParserErrorContext tempContext(kAuthenticationRestrictionsFieldName, &ctxt);
                        const auto localObject = arrayElement.Obj();
                        values.emplace_back(mongo::Address_restriction::parse(tempContext, localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _authenticationRestrictions = std::move(values);
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

UpdateRoleCommand UpdateRoleCommand::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto localCmdType = mongo::idl::preparsedValue<std::string>();
    UpdateRoleCommand object(localCmdType);
    object.parseProtected(ctxt, request);
    return object;
}
void UpdateRoleCommand::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<4> usedFields;
    const size_t kPrivilegesBit = 0;
    const size_t kRolesBit = 1;
    const size_t kAuthenticationRestrictionsBit = 2;
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

        if (fieldName == kPrivilegesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kPrivilegesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPrivilegesBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kPrivilegesFieldName, &ctxt);
            std::vector<mongo::Privilege> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, Object)) {
                        const BSONObj localObject = arrayElement.Obj();
                        values.emplace_back(Privilege::fromBSON(localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _privileges = std::move(values);
        }
        else if (fieldName == kRolesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kRolesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRolesBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kRolesFieldName, &ctxt);
            std::vector<mongo::RoleNameOrString> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    values.emplace_back(RoleNameOrString::parseFromBSON(arrayElement));
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _roles = std::move(values);
        }
        else if (fieldName == kAuthenticationRestrictionsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kAuthenticationRestrictionsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAuthenticationRestrictionsBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kAuthenticationRestrictionsFieldName, &ctxt);
            std::vector<mongo::Address_restriction> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, Object)) {
                        IDLParserErrorContext tempContext(kAuthenticationRestrictionsFieldName, &ctxt);
                        const auto localObject = arrayElement.Obj();
                        values.emplace_back(mongo::Address_restriction::parse(tempContext, localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _authenticationRestrictions = std::move(values);
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

void UpdateRoleCommand::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    builder->append(kCommandParameterFieldName, _commandParameter);
    if (_privileges.is_initialized()) {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kPrivilegesFieldName));
        for (const auto& item : _privileges.get()) {
            const BSONObj localObject = item.toBSON();
            arrayBuilder.append(localObject);
        }
    }

    if (_roles.is_initialized()) {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kRolesFieldName));
        for (const auto& item : _roles.get()) {
            item.serializeToBSON(&arrayBuilder);
        }
    }

    if (_authenticationRestrictions.is_initialized()) {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kAuthenticationRestrictionsFieldName));
        for (const auto& item : _authenticationRestrictions.get()) {
            BSONObjBuilder subObjBuilder(arrayBuilder.subobjStart());
            item.serialize(&subObjBuilder);
        }
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest UpdateRoleCommand::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        builder->append(kCommandParameterFieldName, _commandParameter);
        if (_privileges.is_initialized()) {
            BSONArrayBuilder arrayBuilder(builder->subarrayStart(kPrivilegesFieldName));
            for (const auto& item : _privileges.get()) {
                const BSONObj localObject = item.toBSON();
                arrayBuilder.append(localObject);
            }
        }

        if (_roles.is_initialized()) {
            BSONArrayBuilder arrayBuilder(builder->subarrayStart(kRolesFieldName));
            for (const auto& item : _roles.get()) {
                item.serializeToBSON(&arrayBuilder);
            }
        }

        if (_authenticationRestrictions.is_initialized()) {
            BSONArrayBuilder arrayBuilder(builder->subarrayStart(kAuthenticationRestrictionsFieldName));
            for (const auto& item : _authenticationRestrictions.get()) {
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

BSONObj UpdateRoleCommand::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData GrantPrivilegesToRoleCommand::kCommandParameterFieldName;
constexpr StringData GrantPrivilegesToRoleCommand::kDbNameFieldName;
constexpr StringData GrantPrivilegesToRoleCommand::kPrivilegesFieldName;
constexpr StringData GrantPrivilegesToRoleCommand::kCommandName;

const std::vector<StringData> GrantPrivilegesToRoleCommand::_knownBSONFields {
    GrantPrivilegesToRoleCommand::kPrivilegesFieldName,
    GrantPrivilegesToRoleCommand::kCommandName,
};
const std::vector<StringData> GrantPrivilegesToRoleCommand::_knownOP_MSGFields {
    GrantPrivilegesToRoleCommand::kDbNameFieldName,
    GrantPrivilegesToRoleCommand::kPrivilegesFieldName,
    GrantPrivilegesToRoleCommand::kCommandName,
};

GrantPrivilegesToRoleCommand::GrantPrivilegesToRoleCommand(const std::string commandParameter) : _commandParameter(std::move(commandParameter)), _hasPrivileges(false), _hasDbName(false) {
    // Used for initialization only
}
GrantPrivilegesToRoleCommand::GrantPrivilegesToRoleCommand(const std::string commandParameter, std::vector<mongo::Privilege> privileges) : _commandParameter(std::move(commandParameter)), _privileges(std::move(privileges)), _hasPrivileges(true), _hasDbName(true) {
    // Used for initialization only
}


GrantPrivilegesToRoleCommand GrantPrivilegesToRoleCommand::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto localCmdType = mongo::idl::preparsedValue<std::string>();
    GrantPrivilegesToRoleCommand object(localCmdType);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void GrantPrivilegesToRoleCommand::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kPrivilegesBit = 0;
    const size_t kDbNameBit = 1;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kPrivilegesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kPrivilegesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPrivilegesBit);

                _hasPrivileges = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kPrivilegesFieldName, &ctxt);
            std::vector<mongo::Privilege> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, Object)) {
                        const BSONObj localObject = arrayElement.Obj();
                        values.emplace_back(Privilege::fromBSON(localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _privileges = std::move(values);
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
        if (!usedFields[kPrivilegesBit]) {
            ctxt.throwMissingField(kPrivilegesFieldName);
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

GrantPrivilegesToRoleCommand GrantPrivilegesToRoleCommand::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto localCmdType = mongo::idl::preparsedValue<std::string>();
    GrantPrivilegesToRoleCommand object(localCmdType);
    object.parseProtected(ctxt, request);
    return object;
}
void GrantPrivilegesToRoleCommand::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<2> usedFields;
    const size_t kPrivilegesBit = 0;
    const size_t kDbNameBit = 1;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kPrivilegesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kPrivilegesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPrivilegesBit);

                _hasPrivileges = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kPrivilegesFieldName, &ctxt);
            std::vector<mongo::Privilege> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, Object)) {
                        const BSONObj localObject = arrayElement.Obj();
                        values.emplace_back(Privilege::fromBSON(localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _privileges = std::move(values);
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
        if (!usedFields[kPrivilegesBit]) {
            ctxt.throwMissingField(kPrivilegesFieldName);
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

void GrantPrivilegesToRoleCommand::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasPrivileges && _hasDbName);

    builder->append(kCommandParameterFieldName, _commandParameter);
    {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kPrivilegesFieldName));
        for (const auto& item : _privileges) {
            const BSONObj localObject = item.toBSON();
            arrayBuilder.append(localObject);
        }
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest GrantPrivilegesToRoleCommand::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasPrivileges && _hasDbName);

        builder->append(kCommandParameterFieldName, _commandParameter);
        {
            BSONArrayBuilder arrayBuilder(builder->subarrayStart(kPrivilegesFieldName));
            for (const auto& item : _privileges) {
                const BSONObj localObject = item.toBSON();
                arrayBuilder.append(localObject);
            }
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj GrantPrivilegesToRoleCommand::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData RevokePrivilegesFromRoleCommand::kCommandParameterFieldName;
constexpr StringData RevokePrivilegesFromRoleCommand::kDbNameFieldName;
constexpr StringData RevokePrivilegesFromRoleCommand::kPrivilegesFieldName;
constexpr StringData RevokePrivilegesFromRoleCommand::kCommandName;

const std::vector<StringData> RevokePrivilegesFromRoleCommand::_knownBSONFields {
    RevokePrivilegesFromRoleCommand::kPrivilegesFieldName,
    RevokePrivilegesFromRoleCommand::kCommandName,
};
const std::vector<StringData> RevokePrivilegesFromRoleCommand::_knownOP_MSGFields {
    RevokePrivilegesFromRoleCommand::kDbNameFieldName,
    RevokePrivilegesFromRoleCommand::kPrivilegesFieldName,
    RevokePrivilegesFromRoleCommand::kCommandName,
};

RevokePrivilegesFromRoleCommand::RevokePrivilegesFromRoleCommand(const std::string commandParameter) : _commandParameter(std::move(commandParameter)), _hasPrivileges(false), _hasDbName(false) {
    // Used for initialization only
}
RevokePrivilegesFromRoleCommand::RevokePrivilegesFromRoleCommand(const std::string commandParameter, std::vector<mongo::Privilege> privileges) : _commandParameter(std::move(commandParameter)), _privileges(std::move(privileges)), _hasPrivileges(true), _hasDbName(true) {
    // Used for initialization only
}


RevokePrivilegesFromRoleCommand RevokePrivilegesFromRoleCommand::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto localCmdType = mongo::idl::preparsedValue<std::string>();
    RevokePrivilegesFromRoleCommand object(localCmdType);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void RevokePrivilegesFromRoleCommand::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kPrivilegesBit = 0;
    const size_t kDbNameBit = 1;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kPrivilegesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kPrivilegesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPrivilegesBit);

                _hasPrivileges = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kPrivilegesFieldName, &ctxt);
            std::vector<mongo::Privilege> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, Object)) {
                        const BSONObj localObject = arrayElement.Obj();
                        values.emplace_back(Privilege::fromBSON(localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _privileges = std::move(values);
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
        if (!usedFields[kPrivilegesBit]) {
            ctxt.throwMissingField(kPrivilegesFieldName);
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

RevokePrivilegesFromRoleCommand RevokePrivilegesFromRoleCommand::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto localCmdType = mongo::idl::preparsedValue<std::string>();
    RevokePrivilegesFromRoleCommand object(localCmdType);
    object.parseProtected(ctxt, request);
    return object;
}
void RevokePrivilegesFromRoleCommand::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<2> usedFields;
    const size_t kPrivilegesBit = 0;
    const size_t kDbNameBit = 1;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kPrivilegesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kPrivilegesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPrivilegesBit);

                _hasPrivileges = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kPrivilegesFieldName, &ctxt);
            std::vector<mongo::Privilege> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, Object)) {
                        const BSONObj localObject = arrayElement.Obj();
                        values.emplace_back(Privilege::fromBSON(localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _privileges = std::move(values);
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
        if (!usedFields[kPrivilegesBit]) {
            ctxt.throwMissingField(kPrivilegesFieldName);
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

void RevokePrivilegesFromRoleCommand::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasPrivileges && _hasDbName);

    builder->append(kCommandParameterFieldName, _commandParameter);
    {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kPrivilegesFieldName));
        for (const auto& item : _privileges) {
            const BSONObj localObject = item.toBSON();
            arrayBuilder.append(localObject);
        }
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest RevokePrivilegesFromRoleCommand::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasPrivileges && _hasDbName);

        builder->append(kCommandParameterFieldName, _commandParameter);
        {
            BSONArrayBuilder arrayBuilder(builder->subarrayStart(kPrivilegesFieldName));
            for (const auto& item : _privileges) {
                const BSONObj localObject = item.toBSON();
                arrayBuilder.append(localObject);
            }
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj RevokePrivilegesFromRoleCommand::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData GrantRolesToRoleCommand::kCommandParameterFieldName;
constexpr StringData GrantRolesToRoleCommand::kDbNameFieldName;
constexpr StringData GrantRolesToRoleCommand::kRolesFieldName;
constexpr StringData GrantRolesToRoleCommand::kCommandName;

const std::vector<StringData> GrantRolesToRoleCommand::_knownBSONFields {
    GrantRolesToRoleCommand::kRolesFieldName,
    GrantRolesToRoleCommand::kCommandName,
};
const std::vector<StringData> GrantRolesToRoleCommand::_knownOP_MSGFields {
    GrantRolesToRoleCommand::kDbNameFieldName,
    GrantRolesToRoleCommand::kRolesFieldName,
    GrantRolesToRoleCommand::kCommandName,
};

GrantRolesToRoleCommand::GrantRolesToRoleCommand(const std::string commandParameter) : _commandParameter(std::move(commandParameter)), _hasRoles(false), _hasDbName(false) {
    // Used for initialization only
}
GrantRolesToRoleCommand::GrantRolesToRoleCommand(const std::string commandParameter, std::vector<mongo::RoleNameOrString> roles) : _commandParameter(std::move(commandParameter)), _roles(std::move(roles)), _hasRoles(true), _hasDbName(true) {
    // Used for initialization only
}


GrantRolesToRoleCommand GrantRolesToRoleCommand::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto localCmdType = mongo::idl::preparsedValue<std::string>();
    GrantRolesToRoleCommand object(localCmdType);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void GrantRolesToRoleCommand::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kRolesBit = 0;
    const size_t kDbNameBit = 1;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kRolesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kRolesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRolesBit);

                _hasRoles = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kRolesFieldName, &ctxt);
            std::vector<mongo::RoleNameOrString> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    values.emplace_back(RoleNameOrString::parseFromBSON(arrayElement));
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _roles = std::move(values);
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
        if (!usedFields[kRolesBit]) {
            ctxt.throwMissingField(kRolesFieldName);
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

GrantRolesToRoleCommand GrantRolesToRoleCommand::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto localCmdType = mongo::idl::preparsedValue<std::string>();
    GrantRolesToRoleCommand object(localCmdType);
    object.parseProtected(ctxt, request);
    return object;
}
void GrantRolesToRoleCommand::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<2> usedFields;
    const size_t kRolesBit = 0;
    const size_t kDbNameBit = 1;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kRolesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kRolesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRolesBit);

                _hasRoles = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kRolesFieldName, &ctxt);
            std::vector<mongo::RoleNameOrString> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    values.emplace_back(RoleNameOrString::parseFromBSON(arrayElement));
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _roles = std::move(values);
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
        if (!usedFields[kRolesBit]) {
            ctxt.throwMissingField(kRolesFieldName);
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

void GrantRolesToRoleCommand::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasRoles && _hasDbName);

    builder->append(kCommandParameterFieldName, _commandParameter);
    {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kRolesFieldName));
        for (const auto& item : _roles) {
            item.serializeToBSON(&arrayBuilder);
        }
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest GrantRolesToRoleCommand::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasRoles && _hasDbName);

        builder->append(kCommandParameterFieldName, _commandParameter);
        {
            BSONArrayBuilder arrayBuilder(builder->subarrayStart(kRolesFieldName));
            for (const auto& item : _roles) {
                item.serializeToBSON(&arrayBuilder);
            }
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj GrantRolesToRoleCommand::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData RevokeRolesFromRoleCommand::kCommandParameterFieldName;
constexpr StringData RevokeRolesFromRoleCommand::kDbNameFieldName;
constexpr StringData RevokeRolesFromRoleCommand::kRolesFieldName;
constexpr StringData RevokeRolesFromRoleCommand::kCommandName;

const std::vector<StringData> RevokeRolesFromRoleCommand::_knownBSONFields {
    RevokeRolesFromRoleCommand::kRolesFieldName,
    RevokeRolesFromRoleCommand::kCommandName,
};
const std::vector<StringData> RevokeRolesFromRoleCommand::_knownOP_MSGFields {
    RevokeRolesFromRoleCommand::kDbNameFieldName,
    RevokeRolesFromRoleCommand::kRolesFieldName,
    RevokeRolesFromRoleCommand::kCommandName,
};

RevokeRolesFromRoleCommand::RevokeRolesFromRoleCommand(const std::string commandParameter) : _commandParameter(std::move(commandParameter)), _hasRoles(false), _hasDbName(false) {
    // Used for initialization only
}
RevokeRolesFromRoleCommand::RevokeRolesFromRoleCommand(const std::string commandParameter, std::vector<mongo::RoleNameOrString> roles) : _commandParameter(std::move(commandParameter)), _roles(std::move(roles)), _hasRoles(true), _hasDbName(true) {
    // Used for initialization only
}


RevokeRolesFromRoleCommand RevokeRolesFromRoleCommand::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto localCmdType = mongo::idl::preparsedValue<std::string>();
    RevokeRolesFromRoleCommand object(localCmdType);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void RevokeRolesFromRoleCommand::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kRolesBit = 0;
    const size_t kDbNameBit = 1;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kRolesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kRolesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRolesBit);

                _hasRoles = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kRolesFieldName, &ctxt);
            std::vector<mongo::RoleNameOrString> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    values.emplace_back(RoleNameOrString::parseFromBSON(arrayElement));
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _roles = std::move(values);
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
        if (!usedFields[kRolesBit]) {
            ctxt.throwMissingField(kRolesFieldName);
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

RevokeRolesFromRoleCommand RevokeRolesFromRoleCommand::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto localCmdType = mongo::idl::preparsedValue<std::string>();
    RevokeRolesFromRoleCommand object(localCmdType);
    object.parseProtected(ctxt, request);
    return object;
}
void RevokeRolesFromRoleCommand::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<2> usedFields;
    const size_t kRolesBit = 0;
    const size_t kDbNameBit = 1;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kRolesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kRolesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRolesBit);

                _hasRoles = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kRolesFieldName, &ctxt);
            std::vector<mongo::RoleNameOrString> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    values.emplace_back(RoleNameOrString::parseFromBSON(arrayElement));
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _roles = std::move(values);
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
        if (!usedFields[kRolesBit]) {
            ctxt.throwMissingField(kRolesFieldName);
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

void RevokeRolesFromRoleCommand::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasRoles && _hasDbName);

    builder->append(kCommandParameterFieldName, _commandParameter);
    {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kRolesFieldName));
        for (const auto& item : _roles) {
            item.serializeToBSON(&arrayBuilder);
        }
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest RevokeRolesFromRoleCommand::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasRoles && _hasDbName);

        builder->append(kCommandParameterFieldName, _commandParameter);
        {
            BSONArrayBuilder arrayBuilder(builder->subarrayStart(kRolesFieldName));
            for (const auto& item : _roles) {
                item.serializeToBSON(&arrayBuilder);
            }
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj RevokeRolesFromRoleCommand::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData DropRoleCommand::kCommandParameterFieldName;
constexpr StringData DropRoleCommand::kDbNameFieldName;
constexpr StringData DropRoleCommand::kCommandName;

const std::vector<StringData> DropRoleCommand::_knownBSONFields {
    DropRoleCommand::kCommandName,
};
const std::vector<StringData> DropRoleCommand::_knownOP_MSGFields {
    DropRoleCommand::kDbNameFieldName,
    DropRoleCommand::kCommandName,
};

DropRoleCommand::DropRoleCommand(const std::string commandParameter) : _commandParameter(std::move(commandParameter)), _hasDbName(false) {
    // Used for initialization only
}


DropRoleCommand DropRoleCommand::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto localCmdType = mongo::idl::preparsedValue<std::string>();
    DropRoleCommand object(localCmdType);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void DropRoleCommand::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
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
        if (MONGO_likely(ctxt.checkAndAssertType(commandElement, String))) {
            _commandParameter = commandElement.str();
        }
        else {
            ctxt.throwMissingField(kCommandParameterFieldName);
        }
    }
}

DropRoleCommand DropRoleCommand::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto localCmdType = mongo::idl::preparsedValue<std::string>();
    DropRoleCommand object(localCmdType);
    object.parseProtected(ctxt, request);
    return object;
}
void DropRoleCommand::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
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
        if (MONGO_likely(ctxt.checkAndAssertType(commandElement, String))) {
            _commandParameter = commandElement.str();
        }
        else {
            ctxt.throwMissingField(kCommandParameterFieldName);
        }
    }
}

void DropRoleCommand::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    builder->append(kCommandParameterFieldName, _commandParameter);
    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest DropRoleCommand::serialize(const BSONObj& commandPassthroughFields) const {
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

BSONObj DropRoleCommand::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData DropAllRolesFromDatabaseCommand::kDbNameFieldName;
constexpr StringData DropAllRolesFromDatabaseCommand::kCommandName;

const std::vector<StringData> DropAllRolesFromDatabaseCommand::_knownBSONFields {
    DropAllRolesFromDatabaseCommand::kCommandName,
};
const std::vector<StringData> DropAllRolesFromDatabaseCommand::_knownOP_MSGFields {
    DropAllRolesFromDatabaseCommand::kDbNameFieldName,
    DropAllRolesFromDatabaseCommand::kCommandName,
};

DropAllRolesFromDatabaseCommand::DropAllRolesFromDatabaseCommand() : _hasDbName(false) {
    // Used for initialization only
}


DropAllRolesFromDatabaseCommand DropAllRolesFromDatabaseCommand::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<DropAllRolesFromDatabaseCommand>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void DropAllRolesFromDatabaseCommand::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
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

DropAllRolesFromDatabaseCommand DropAllRolesFromDatabaseCommand::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto object = mongo::idl::preparsedValue<DropAllRolesFromDatabaseCommand>();
    object.parseProtected(ctxt, request);
    return object;
}
void DropAllRolesFromDatabaseCommand::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
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

void DropAllRolesFromDatabaseCommand::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    builder->append("dropAllRolesFromDatabase"_sd, 1);
    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest DropAllRolesFromDatabaseCommand::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        builder->append("dropAllRolesFromDatabase"_sd, 1);
        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj DropAllRolesFromDatabaseCommand::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData UsersInfoCommand::kCommandParameterFieldName;
constexpr StringData UsersInfoCommand::kDbNameFieldName;
constexpr StringData UsersInfoCommand::kFilterFieldName;
constexpr StringData UsersInfoCommand::kShowAuthenticationRestrictionsFieldName;
constexpr StringData UsersInfoCommand::kShowCredentialsFieldName;
constexpr StringData UsersInfoCommand::kShowPrivilegesFieldName;
constexpr StringData UsersInfoCommand::kCommandName;

const std::vector<StringData> UsersInfoCommand::_knownBSONFields {
    UsersInfoCommand::kFilterFieldName,
    UsersInfoCommand::kShowAuthenticationRestrictionsFieldName,
    UsersInfoCommand::kShowCredentialsFieldName,
    UsersInfoCommand::kShowPrivilegesFieldName,
    UsersInfoCommand::kCommandName,
};
const std::vector<StringData> UsersInfoCommand::_knownOP_MSGFields {
    UsersInfoCommand::kDbNameFieldName,
    UsersInfoCommand::kFilterFieldName,
    UsersInfoCommand::kShowAuthenticationRestrictionsFieldName,
    UsersInfoCommand::kShowCredentialsFieldName,
    UsersInfoCommand::kShowPrivilegesFieldName,
    UsersInfoCommand::kCommandName,
};

UsersInfoCommand::UsersInfoCommand(const mongo::auth::UsersInfoCommandArg commandParameter) : _commandParameter(std::move(commandParameter)), _hasDbName(false) {
    // Used for initialization only
}


UsersInfoCommand UsersInfoCommand::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto localCmdType = mongo::idl::preparsedValue<mongo::auth::UsersInfoCommandArg>();
    UsersInfoCommand object(localCmdType);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void UsersInfoCommand::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<5> usedFields;
    const size_t kShowPrivilegesBit = 0;
    const size_t kShowCredentialsBit = 1;
    const size_t kShowAuthenticationRestrictionsBit = 2;
    const size_t kFilterBit = 3;
    const size_t kDbNameBit = 4;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kShowPrivilegesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kShowPrivilegesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kShowPrivilegesBit);

                _showPrivileges = element.trueValue();
            }
        }
        else if (fieldName == kShowCredentialsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kShowCredentialsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kShowCredentialsBit);

                _showCredentials = element.trueValue();
            }
        }
        else if (fieldName == kShowAuthenticationRestrictionsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kShowAuthenticationRestrictionsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kShowAuthenticationRestrictionsBit);

                _showAuthenticationRestrictions = element.trueValue();
            }
        }
        else if (fieldName == kFilterFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kFilterBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kFilterBit);

                _filter = element.Obj();
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
        if (!usedFields[kShowPrivilegesBit]) {
            _showPrivileges = false;
        }
        if (!usedFields[kShowCredentialsBit]) {
            _showCredentials = false;
        }
        if (!usedFields[kShowAuthenticationRestrictionsBit]) {
            _showAuthenticationRestrictions = false;
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    {
        _commandParameter = auth::UsersInfoCommandArg::parseFromBSON(commandElement);
    }
}

UsersInfoCommand UsersInfoCommand::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto localCmdType = mongo::idl::preparsedValue<mongo::auth::UsersInfoCommandArg>();
    UsersInfoCommand object(localCmdType);
    object.parseProtected(ctxt, request);
    return object;
}
void UsersInfoCommand::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<5> usedFields;
    const size_t kShowPrivilegesBit = 0;
    const size_t kShowCredentialsBit = 1;
    const size_t kShowAuthenticationRestrictionsBit = 2;
    const size_t kFilterBit = 3;
    const size_t kDbNameBit = 4;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kShowPrivilegesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kShowPrivilegesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kShowPrivilegesBit);

                _showPrivileges = element.trueValue();
            }
        }
        else if (fieldName == kShowCredentialsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kShowCredentialsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kShowCredentialsBit);

                _showCredentials = element.trueValue();
            }
        }
        else if (fieldName == kShowAuthenticationRestrictionsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kShowAuthenticationRestrictionsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kShowAuthenticationRestrictionsBit);

                _showAuthenticationRestrictions = element.trueValue();
            }
        }
        else if (fieldName == kFilterFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kFilterBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kFilterBit);

                _filter = element.Obj();
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
        if (!usedFields[kShowPrivilegesBit]) {
            _showPrivileges = false;
        }
        if (!usedFields[kShowCredentialsBit]) {
            _showCredentials = false;
        }
        if (!usedFields[kShowAuthenticationRestrictionsBit]) {
            _showAuthenticationRestrictions = false;
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    {
        _commandParameter = auth::UsersInfoCommandArg::parseFromBSON(commandElement);
    }
}

void UsersInfoCommand::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    {
        _commandParameter.serializeToBSON(kCommandParameterFieldName, builder);
    }
    builder->append(kShowPrivilegesFieldName, _showPrivileges);

    builder->append(kShowCredentialsFieldName, _showCredentials);

    builder->append(kShowAuthenticationRestrictionsFieldName, _showAuthenticationRestrictions);

    if (_filter.is_initialized()) {
        builder->append(kFilterFieldName, _filter.get());
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest UsersInfoCommand::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        {
            _commandParameter.serializeToBSON(kCommandParameterFieldName, builder);
        }
        builder->append(kShowPrivilegesFieldName, _showPrivileges);

        builder->append(kShowCredentialsFieldName, _showCredentials);

        builder->append(kShowAuthenticationRestrictionsFieldName, _showAuthenticationRestrictions);

        if (_filter.is_initialized()) {
            builder->append(kFilterFieldName, _filter.get());
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj UsersInfoCommand::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData RolesInfoCommand::kCommandParameterFieldName;
constexpr StringData RolesInfoCommand::kDbNameFieldName;
constexpr StringData RolesInfoCommand::kShowAuthenticationRestrictionsFieldName;
constexpr StringData RolesInfoCommand::kShowBuiltinRolesFieldName;
constexpr StringData RolesInfoCommand::kShowPrivilegesFieldName;
constexpr StringData RolesInfoCommand::kCommandName;

const std::vector<StringData> RolesInfoCommand::_knownBSONFields {
    RolesInfoCommand::kShowAuthenticationRestrictionsFieldName,
    RolesInfoCommand::kShowBuiltinRolesFieldName,
    RolesInfoCommand::kShowPrivilegesFieldName,
    RolesInfoCommand::kCommandName,
};
const std::vector<StringData> RolesInfoCommand::_knownOP_MSGFields {
    RolesInfoCommand::kDbNameFieldName,
    RolesInfoCommand::kShowAuthenticationRestrictionsFieldName,
    RolesInfoCommand::kShowBuiltinRolesFieldName,
    RolesInfoCommand::kShowPrivilegesFieldName,
    RolesInfoCommand::kCommandName,
};

RolesInfoCommand::RolesInfoCommand(const mongo::auth::RolesInfoCommandArg commandParameter) : _commandParameter(std::move(commandParameter)), _hasDbName(false) {
    // Used for initialization only
}


RolesInfoCommand RolesInfoCommand::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto localCmdType = mongo::idl::preparsedValue<mongo::auth::RolesInfoCommandArg>();
    RolesInfoCommand object(localCmdType);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void RolesInfoCommand::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<4> usedFields;
    const size_t kShowPrivilegesBit = 0;
    const size_t kShowBuiltinRolesBit = 1;
    const size_t kShowAuthenticationRestrictionsBit = 2;
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

        if (fieldName == kShowPrivilegesFieldName) {
            if (MONGO_unlikely(usedFields[kShowPrivilegesBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kShowPrivilegesBit);

            _showPrivileges = auth::ParsedPrivilegeFormat::parseFromBSON(element);
        }
        else if (fieldName == kShowBuiltinRolesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kShowBuiltinRolesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kShowBuiltinRolesBit);

                _showBuiltinRoles = element.trueValue();
            }
        }
        else if (fieldName == kShowAuthenticationRestrictionsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kShowAuthenticationRestrictionsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kShowAuthenticationRestrictionsBit);

                _showAuthenticationRestrictions = element.trueValue();
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
        if (!usedFields[kShowPrivilegesBit]) {
            _showPrivileges = false;
        }
        if (!usedFields[kShowBuiltinRolesBit]) {
            _showBuiltinRoles = false;
        }
        if (!usedFields[kShowAuthenticationRestrictionsBit]) {
            _showAuthenticationRestrictions = false;
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    {
        _commandParameter = auth::RolesInfoCommandArg::parseFromBSON(commandElement);
    }
}

RolesInfoCommand RolesInfoCommand::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto localCmdType = mongo::idl::preparsedValue<mongo::auth::RolesInfoCommandArg>();
    RolesInfoCommand object(localCmdType);
    object.parseProtected(ctxt, request);
    return object;
}
void RolesInfoCommand::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<4> usedFields;
    const size_t kShowPrivilegesBit = 0;
    const size_t kShowBuiltinRolesBit = 1;
    const size_t kShowAuthenticationRestrictionsBit = 2;
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

        if (fieldName == kShowPrivilegesFieldName) {
            if (MONGO_unlikely(usedFields[kShowPrivilegesBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kShowPrivilegesBit);

            _showPrivileges = auth::ParsedPrivilegeFormat::parseFromBSON(element);
        }
        else if (fieldName == kShowBuiltinRolesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kShowBuiltinRolesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kShowBuiltinRolesBit);

                _showBuiltinRoles = element.trueValue();
            }
        }
        else if (fieldName == kShowAuthenticationRestrictionsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kShowAuthenticationRestrictionsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kShowAuthenticationRestrictionsBit);

                _showAuthenticationRestrictions = element.trueValue();
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
        if (!usedFields[kShowPrivilegesBit]) {
            _showPrivileges = false;
        }
        if (!usedFields[kShowBuiltinRolesBit]) {
            _showBuiltinRoles = false;
        }
        if (!usedFields[kShowAuthenticationRestrictionsBit]) {
            _showAuthenticationRestrictions = false;
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    {
        _commandParameter = auth::RolesInfoCommandArg::parseFromBSON(commandElement);
    }
}

void RolesInfoCommand::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    {
        _commandParameter.serializeToBSON(kCommandParameterFieldName, builder);
    }
    {
        _showPrivileges.serializeToBSON(kShowPrivilegesFieldName, builder);
    }

    builder->append(kShowBuiltinRolesFieldName, _showBuiltinRoles);

    builder->append(kShowAuthenticationRestrictionsFieldName, _showAuthenticationRestrictions);

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest RolesInfoCommand::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        {
            _commandParameter.serializeToBSON(kCommandParameterFieldName, builder);
        }
        {
            _showPrivileges.serializeToBSON(kShowPrivilegesFieldName, builder);
        }

        builder->append(kShowBuiltinRolesFieldName, _showBuiltinRoles);

        builder->append(kShowAuthenticationRestrictionsFieldName, _showAuthenticationRestrictions);

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj RolesInfoCommand::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData InvalidateUserCacheCommand::kDbNameFieldName;
constexpr StringData InvalidateUserCacheCommand::kCommandName;

const std::vector<StringData> InvalidateUserCacheCommand::_knownBSONFields {
    InvalidateUserCacheCommand::kCommandName,
};
const std::vector<StringData> InvalidateUserCacheCommand::_knownOP_MSGFields {
    InvalidateUserCacheCommand::kDbNameFieldName,
    InvalidateUserCacheCommand::kCommandName,
};

InvalidateUserCacheCommand::InvalidateUserCacheCommand() : _hasDbName(false) {
    // Used for initialization only
}


InvalidateUserCacheCommand InvalidateUserCacheCommand::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<InvalidateUserCacheCommand>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void InvalidateUserCacheCommand::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
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

InvalidateUserCacheCommand InvalidateUserCacheCommand::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto object = mongo::idl::preparsedValue<InvalidateUserCacheCommand>();
    object.parseProtected(ctxt, request);
    return object;
}
void InvalidateUserCacheCommand::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
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

void InvalidateUserCacheCommand::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    builder->append("invalidateUserCache"_sd, 1);
    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest InvalidateUserCacheCommand::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        builder->append("invalidateUserCache"_sd, 1);
        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj InvalidateUserCacheCommand::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData GetUserCacheGenerationCommand::kDbNameFieldName;
constexpr StringData GetUserCacheGenerationCommand::kCommandName;

const std::vector<StringData> GetUserCacheGenerationCommand::_knownBSONFields {
    GetUserCacheGenerationCommand::kCommandName,
};
const std::vector<StringData> GetUserCacheGenerationCommand::_knownOP_MSGFields {
    GetUserCacheGenerationCommand::kDbNameFieldName,
    GetUserCacheGenerationCommand::kCommandName,
};

GetUserCacheGenerationCommand::GetUserCacheGenerationCommand() : _hasDbName(false) {
    // Used for initialization only
}


GetUserCacheGenerationCommand GetUserCacheGenerationCommand::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<GetUserCacheGenerationCommand>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void GetUserCacheGenerationCommand::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
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

GetUserCacheGenerationCommand GetUserCacheGenerationCommand::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto object = mongo::idl::preparsedValue<GetUserCacheGenerationCommand>();
    object.parseProtected(ctxt, request);
    return object;
}
void GetUserCacheGenerationCommand::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
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

void GetUserCacheGenerationCommand::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    builder->append("_getUserCacheGeneration"_sd, 1);
    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest GetUserCacheGenerationCommand::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        builder->append("_getUserCacheGeneration"_sd, 1);
        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj GetUserCacheGenerationCommand::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData MergeAuthzCollectionsCommand::kDbFieldName;
constexpr StringData MergeAuthzCollectionsCommand::kDbNameFieldName;
constexpr StringData MergeAuthzCollectionsCommand::kDropFieldName;
constexpr StringData MergeAuthzCollectionsCommand::kTempRolesCollectionFieldName;
constexpr StringData MergeAuthzCollectionsCommand::kTempUsersCollectionFieldName;
constexpr StringData MergeAuthzCollectionsCommand::kCommandName;

const std::vector<StringData> MergeAuthzCollectionsCommand::_knownBSONFields {
    MergeAuthzCollectionsCommand::kDbFieldName,
    MergeAuthzCollectionsCommand::kDropFieldName,
    MergeAuthzCollectionsCommand::kTempRolesCollectionFieldName,
    MergeAuthzCollectionsCommand::kTempUsersCollectionFieldName,
    MergeAuthzCollectionsCommand::kCommandName,
};
const std::vector<StringData> MergeAuthzCollectionsCommand::_knownOP_MSGFields {
    MergeAuthzCollectionsCommand::kDbFieldName,
    MergeAuthzCollectionsCommand::kDbNameFieldName,
    MergeAuthzCollectionsCommand::kDropFieldName,
    MergeAuthzCollectionsCommand::kTempRolesCollectionFieldName,
    MergeAuthzCollectionsCommand::kTempUsersCollectionFieldName,
    MergeAuthzCollectionsCommand::kCommandName,
};

MergeAuthzCollectionsCommand::MergeAuthzCollectionsCommand() : _db(mongo::idl::preparsedValue<decltype(_db)>()), _hasDb(false), _hasDbName(false) {
    // Used for initialization only
}
MergeAuthzCollectionsCommand::MergeAuthzCollectionsCommand(std::string db) : _db(std::move(db)), _hasDb(true), _hasDbName(true) {
    // Used for initialization only
}


MergeAuthzCollectionsCommand MergeAuthzCollectionsCommand::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<MergeAuthzCollectionsCommand>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void MergeAuthzCollectionsCommand::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<5> usedFields;
    const size_t kTempUsersCollectionBit = 0;
    const size_t kTempRolesCollectionBit = 1;
    const size_t kDbBit = 2;
    const size_t kDropBit = 3;
    const size_t kDbNameBit = 4;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kTempUsersCollectionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kTempUsersCollectionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTempUsersCollectionBit);

                _tempUsersCollection = element.str();
            }
        }
        else if (fieldName == kTempRolesCollectionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kTempRolesCollectionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTempRolesCollectionBit);

                _tempRolesCollection = element.str();
            }
        }
        else if (fieldName == kDbFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kDbBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDbBit);

                _hasDb = true;
                _db = element.str();
            }
        }
        else if (fieldName == kDropFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kDropBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDropBit);

                _drop = element.boolean();
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
        if (!usedFields[kTempUsersCollectionBit]) {
            _tempUsersCollection = "";
        }
        if (!usedFields[kTempRolesCollectionBit]) {
            _tempRolesCollection = "";
        }
        if (!usedFields[kDbBit]) {
            ctxt.throwMissingField(kDbFieldName);
        }
        if (!usedFields[kDropBit]) {
            _drop = false;
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

}

MergeAuthzCollectionsCommand MergeAuthzCollectionsCommand::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto object = mongo::idl::preparsedValue<MergeAuthzCollectionsCommand>();
    object.parseProtected(ctxt, request);
    return object;
}
void MergeAuthzCollectionsCommand::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<5> usedFields;
    const size_t kTempUsersCollectionBit = 0;
    const size_t kTempRolesCollectionBit = 1;
    const size_t kDbBit = 2;
    const size_t kDropBit = 3;
    const size_t kDbNameBit = 4;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kTempUsersCollectionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kTempUsersCollectionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTempUsersCollectionBit);

                _tempUsersCollection = element.str();
            }
        }
        else if (fieldName == kTempRolesCollectionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kTempRolesCollectionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTempRolesCollectionBit);

                _tempRolesCollection = element.str();
            }
        }
        else if (fieldName == kDbFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kDbBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDbBit);

                _hasDb = true;
                _db = element.str();
            }
        }
        else if (fieldName == kDropFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kDropBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDropBit);

                _drop = element.boolean();
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
        if (!usedFields[kTempUsersCollectionBit]) {
            _tempUsersCollection = "";
        }
        if (!usedFields[kTempRolesCollectionBit]) {
            _tempRolesCollection = "";
        }
        if (!usedFields[kDbBit]) {
            ctxt.throwMissingField(kDbFieldName);
        }
        if (!usedFields[kDropBit]) {
            _drop = false;
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

}

void MergeAuthzCollectionsCommand::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDb && _hasDbName);

    builder->append("_mergeAuthzCollections"_sd, 1);
    builder->append(kTempUsersCollectionFieldName, _tempUsersCollection);

    builder->append(kTempRolesCollectionFieldName, _tempRolesCollection);

    builder->append(kDbFieldName, _db);

    builder->append(kDropFieldName, _drop);

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest MergeAuthzCollectionsCommand::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDb && _hasDbName);

        builder->append("_mergeAuthzCollections"_sd, 1);
        builder->append(kTempUsersCollectionFieldName, _tempUsersCollection);

        builder->append(kTempRolesCollectionFieldName, _tempRolesCollection);

        builder->append(kDbFieldName, _db);

        builder->append(kDropFieldName, _drop);

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj MergeAuthzCollectionsCommand::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
