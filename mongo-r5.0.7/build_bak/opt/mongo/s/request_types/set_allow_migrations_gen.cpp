/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/s/request_types/set_allow_migrations_gen.h --output build/opt/mongo/s/request_types/set_allow_migrations_gen.cpp src/mongo/s/request_types/set_allow_migrations.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/s/request_types/set_allow_migrations_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData ConfigsvrSetAllowMigrations::kCommandParameterFieldName;
constexpr StringData ConfigsvrSetAllowMigrations::kAllowMigrationsFieldName;
constexpr StringData ConfigsvrSetAllowMigrations::kCollectionUUIDFieldName;
constexpr StringData ConfigsvrSetAllowMigrations::kDbNameFieldName;
constexpr StringData ConfigsvrSetAllowMigrations::kCommandName;

const std::vector<StringData> ConfigsvrSetAllowMigrations::_knownBSONFields {
    ConfigsvrSetAllowMigrations::kAllowMigrationsFieldName,
    ConfigsvrSetAllowMigrations::kCollectionUUIDFieldName,
    ConfigsvrSetAllowMigrations::kCommandName,
};
const std::vector<StringData> ConfigsvrSetAllowMigrations::_knownOP_MSGFields {
    ConfigsvrSetAllowMigrations::kAllowMigrationsFieldName,
    ConfigsvrSetAllowMigrations::kCollectionUUIDFieldName,
    ConfigsvrSetAllowMigrations::kDbNameFieldName,
    ConfigsvrSetAllowMigrations::kCommandName,
};

ConfigsvrSetAllowMigrations::ConfigsvrSetAllowMigrations(const mongo::NamespaceString commandParameter) : _commandParameter(std::move(commandParameter)), _allowMigrations(mongo::idl::preparsedValue<decltype(_allowMigrations)>()), _hasAllowMigrations(false), _hasDbName(false) {
    // Used for initialization only
}
ConfigsvrSetAllowMigrations::ConfigsvrSetAllowMigrations(const mongo::NamespaceString commandParameter, bool allowMigrations) : _commandParameter(std::move(commandParameter)), _allowMigrations(std::move(allowMigrations)), _hasAllowMigrations(true), _hasDbName(true) {
    // Used for initialization only
}


ConfigsvrSetAllowMigrations ConfigsvrSetAllowMigrations::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto localCmdType = mongo::idl::preparsedValue<mongo::NamespaceString>();
    ConfigsvrSetAllowMigrations object(localCmdType);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ConfigsvrSetAllowMigrations::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<3> usedFields;
    const size_t kAllowMigrationsBit = 0;
    const size_t kCollectionUUIDBit = 1;
    const size_t kDbNameBit = 2;
    std::set<StringData> usedFieldSet;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kAllowMigrationsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kAllowMigrationsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAllowMigrationsBit);

                _hasAllowMigrations = true;
                _allowMigrations = element.boolean();
            }
        }
        else if (fieldName == kCollectionUUIDFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kCollectionUUIDBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollectionUUIDBit);

                _collectionUUID = UUID(uassertStatusOK(UUID::parse(element)));
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
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kAllowMigrationsBit]) {
            ctxt.throwMissingField(kAllowMigrationsFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    {
        if (MONGO_likely(ctxt.checkAndAssertType(commandElement, String))) {
            _commandParameter = NamespaceString(commandElement.valueStringData());
        }
        else {
            ctxt.throwMissingField(kCommandParameterFieldName);
        }
    }
}

ConfigsvrSetAllowMigrations ConfigsvrSetAllowMigrations::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto localCmdType = mongo::idl::preparsedValue<mongo::NamespaceString>();
    ConfigsvrSetAllowMigrations object(localCmdType);
    object.parseProtected(ctxt, request);
    return object;
}
void ConfigsvrSetAllowMigrations::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<3> usedFields;
    const size_t kAllowMigrationsBit = 0;
    const size_t kCollectionUUIDBit = 1;
    const size_t kDbNameBit = 2;
    std::set<StringData> usedFieldSet;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kAllowMigrationsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kAllowMigrationsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAllowMigrationsBit);

                _hasAllowMigrations = true;
                _allowMigrations = element.boolean();
            }
        }
        else if (fieldName == kCollectionUUIDFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kCollectionUUIDBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollectionUUIDBit);

                _collectionUUID = UUID(uassertStatusOK(UUID::parse(element)));
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
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kAllowMigrationsBit]) {
            ctxt.throwMissingField(kAllowMigrationsFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    {
        if (MONGO_likely(ctxt.checkAndAssertType(commandElement, String))) {
            _commandParameter = NamespaceString(commandElement.valueStringData());
        }
        else {
            ctxt.throwMissingField(kCommandParameterFieldName);
        }
    }
}

void ConfigsvrSetAllowMigrations::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasAllowMigrations && _hasDbName);

    {
        builder->append(kCommandParameterFieldName, _commandParameter.toString());
    }
    builder->append(kAllowMigrationsFieldName, _allowMigrations);

    if (_collectionUUID.is_initialized()) {
        ConstDataRange tempCDR = _collectionUUID.get().toCDR();
        builder->append(kCollectionUUIDFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest ConfigsvrSetAllowMigrations::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasAllowMigrations && _hasDbName);

        {
            builder->append(kCommandParameterFieldName, _commandParameter.toString());
        }
        builder->append(kAllowMigrationsFieldName, _allowMigrations);

        if (_collectionUUID.is_initialized()) {
            ConstDataRange tempCDR = _collectionUUID.get().toCDR();
            builder->append(kCollectionUUIDFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj ConfigsvrSetAllowMigrations::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData SetAllowMigrations::kCommandParameterFieldName;
constexpr StringData SetAllowMigrations::kSetAllowMigrationsRequestFieldName;
constexpr StringData SetAllowMigrations::kAllowMigrationsFieldName;
constexpr StringData SetAllowMigrations::kDbNameFieldName;
constexpr StringData SetAllowMigrations::kCommandName;

const std::vector<StringData> SetAllowMigrations::_knownBSONFields {
    SetAllowMigrations::kSetAllowMigrationsRequestFieldName,
    SetAllowMigrations::kAllowMigrationsFieldName,
    SetAllowMigrations::kCommandName,
};
const std::vector<StringData> SetAllowMigrations::_knownOP_MSGFields {
    SetAllowMigrations::kSetAllowMigrationsRequestFieldName,
    SetAllowMigrations::kAllowMigrationsFieldName,
    SetAllowMigrations::kDbNameFieldName,
    SetAllowMigrations::kCommandName,
};

SetAllowMigrations::SetAllowMigrations(const mongo::NamespaceString commandParameter) : _commandParameter(std::move(commandParameter)), _hasDbName(false) {
    // Used for initialization only
}


SetAllowMigrations SetAllowMigrations::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto localCmdType = mongo::idl::preparsedValue<mongo::NamespaceString>();
    SetAllowMigrations object(localCmdType);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void SetAllowMigrations::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<3> usedFields;
    const size_t kAllowMigrationsBit = 0;
    const size_t kDbNameBit = 1;
    std::set<StringData> usedFieldSet;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kAllowMigrationsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kAllowMigrationsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAllowMigrationsBit);

                _setAllowMigrationsRequest.setAllowMigrations(element.boolean());
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
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kAllowMigrationsBit]) {
            ctxt.throwMissingField(kAllowMigrationsFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    {
        if (MONGO_likely(ctxt.checkAndAssertType(commandElement, String))) {
            _commandParameter = NamespaceString(commandElement.valueStringData());
        }
        else {
            ctxt.throwMissingField(kCommandParameterFieldName);
        }
    }
}

SetAllowMigrations SetAllowMigrations::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto localCmdType = mongo::idl::preparsedValue<mongo::NamespaceString>();
    SetAllowMigrations object(localCmdType);
    object.parseProtected(ctxt, request);
    return object;
}
void SetAllowMigrations::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<3> usedFields;
    const size_t kAllowMigrationsBit = 0;
    const size_t kDbNameBit = 1;
    std::set<StringData> usedFieldSet;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kAllowMigrationsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kAllowMigrationsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAllowMigrationsBit);

                _setAllowMigrationsRequest.setAllowMigrations(element.boolean());
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
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kAllowMigrationsBit]) {
            ctxt.throwMissingField(kAllowMigrationsFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    {
        if (MONGO_likely(ctxt.checkAndAssertType(commandElement, String))) {
            _commandParameter = NamespaceString(commandElement.valueStringData());
        }
        else {
            ctxt.throwMissingField(kCommandParameterFieldName);
        }
    }
}

void SetAllowMigrations::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    {
        builder->append(kCommandParameterFieldName, _commandParameter.toString());
    }
    {
        _setAllowMigrationsRequest.serialize(builder);
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest SetAllowMigrations::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        {
            builder->append(kCommandParameterFieldName, _commandParameter.toString());
        }
        {
            _setAllowMigrationsRequest.serialize(builder);
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj SetAllowMigrations::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
