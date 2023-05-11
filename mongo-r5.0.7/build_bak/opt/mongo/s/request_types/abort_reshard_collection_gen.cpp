/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/s/request_types/abort_reshard_collection_gen.h --output build/opt/mongo/s/request_types/abort_reshard_collection_gen.cpp src/mongo/s/request_types/abort_reshard_collection.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/s/request_types/abort_reshard_collection_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData AbortReshardCollection::kCommandParameterFieldName;
constexpr StringData AbortReshardCollection::kDbNameFieldName;
constexpr StringData AbortReshardCollection::kCommandName;

const std::vector<StringData> AbortReshardCollection::_knownBSONFields {
    AbortReshardCollection::kCommandName,
};
const std::vector<StringData> AbortReshardCollection::_knownOP_MSGFields {
    AbortReshardCollection::kDbNameFieldName,
    AbortReshardCollection::kCommandName,
};

AbortReshardCollection::AbortReshardCollection(const mongo::NamespaceString commandParameter) : _commandParameter(std::move(commandParameter)), _hasDbName(false) {
    // Used for initialization only
}


AbortReshardCollection AbortReshardCollection::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto localCmdType = mongo::idl::preparsedValue<mongo::NamespaceString>();
    AbortReshardCollection object(localCmdType);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void AbortReshardCollection::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kDbNameBit = 0;
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
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
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
            _commandParameter = NamespaceString(commandElement.valueStringData());
        }
        else {
            ctxt.throwMissingField(kCommandParameterFieldName);
        }
    }
}

AbortReshardCollection AbortReshardCollection::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto localCmdType = mongo::idl::preparsedValue<mongo::NamespaceString>();
    AbortReshardCollection object(localCmdType);
    object.parseProtected(ctxt, request);
    return object;
}
void AbortReshardCollection::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<1> usedFields;
    const size_t kDbNameBit = 0;
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
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
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
            _commandParameter = NamespaceString(commandElement.valueStringData());
        }
        else {
            ctxt.throwMissingField(kCommandParameterFieldName);
        }
    }
}

void AbortReshardCollection::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    {
        builder->append(kCommandParameterFieldName, _commandParameter.toString());
    }
    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest AbortReshardCollection::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        {
            builder->append(kCommandParameterFieldName, _commandParameter.toString());
        }
        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj AbortReshardCollection::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData ConfigsvrAbortReshardCollection::kCommandParameterFieldName;
constexpr StringData ConfigsvrAbortReshardCollection::kDbNameFieldName;
constexpr StringData ConfigsvrAbortReshardCollection::kCommandName;

const std::vector<StringData> ConfigsvrAbortReshardCollection::_knownBSONFields {
    ConfigsvrAbortReshardCollection::kCommandName,
};
const std::vector<StringData> ConfigsvrAbortReshardCollection::_knownOP_MSGFields {
    ConfigsvrAbortReshardCollection::kDbNameFieldName,
    ConfigsvrAbortReshardCollection::kCommandName,
};

ConfigsvrAbortReshardCollection::ConfigsvrAbortReshardCollection(const mongo::NamespaceString commandParameter) : _commandParameter(std::move(commandParameter)), _hasDbName(false) {
    // Used for initialization only
}


ConfigsvrAbortReshardCollection ConfigsvrAbortReshardCollection::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto localCmdType = mongo::idl::preparsedValue<mongo::NamespaceString>();
    ConfigsvrAbortReshardCollection object(localCmdType);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ConfigsvrAbortReshardCollection::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kDbNameBit = 0;
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
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
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
            _commandParameter = NamespaceString(commandElement.valueStringData());
        }
        else {
            ctxt.throwMissingField(kCommandParameterFieldName);
        }
    }
}

ConfigsvrAbortReshardCollection ConfigsvrAbortReshardCollection::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto localCmdType = mongo::idl::preparsedValue<mongo::NamespaceString>();
    ConfigsvrAbortReshardCollection object(localCmdType);
    object.parseProtected(ctxt, request);
    return object;
}
void ConfigsvrAbortReshardCollection::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<1> usedFields;
    const size_t kDbNameBit = 0;
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
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
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
            _commandParameter = NamespaceString(commandElement.valueStringData());
        }
        else {
            ctxt.throwMissingField(kCommandParameterFieldName);
        }
    }
}

void ConfigsvrAbortReshardCollection::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    {
        builder->append(kCommandParameterFieldName, _commandParameter.toString());
    }
    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest ConfigsvrAbortReshardCollection::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        {
            builder->append(kCommandParameterFieldName, _commandParameter.toString());
        }
        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj ConfigsvrAbortReshardCollection::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData ShardsvrAbortReshardCollection::kCommandParameterFieldName;
constexpr StringData ShardsvrAbortReshardCollection::kDbNameFieldName;
constexpr StringData ShardsvrAbortReshardCollection::kUserCanceledFieldName;
constexpr StringData ShardsvrAbortReshardCollection::kCommandName;

const std::vector<StringData> ShardsvrAbortReshardCollection::_knownBSONFields {
    ShardsvrAbortReshardCollection::kUserCanceledFieldName,
    ShardsvrAbortReshardCollection::kCommandName,
};
const std::vector<StringData> ShardsvrAbortReshardCollection::_knownOP_MSGFields {
    ShardsvrAbortReshardCollection::kDbNameFieldName,
    ShardsvrAbortReshardCollection::kUserCanceledFieldName,
    ShardsvrAbortReshardCollection::kCommandName,
};

ShardsvrAbortReshardCollection::ShardsvrAbortReshardCollection(const mongo::UUID commandParameter) : _commandParameter(std::move(commandParameter)), _userCanceled(mongo::idl::preparsedValue<decltype(_userCanceled)>()), _hasUserCanceled(false), _hasDbName(false) {
    // Used for initialization only
}
ShardsvrAbortReshardCollection::ShardsvrAbortReshardCollection(const mongo::UUID commandParameter, bool userCanceled) : _commandParameter(std::move(commandParameter)), _userCanceled(std::move(userCanceled)), _hasUserCanceled(true), _hasDbName(true) {
    // Used for initialization only
}


ShardsvrAbortReshardCollection ShardsvrAbortReshardCollection::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto localCmdType = mongo::idl::preparsedValue<mongo::UUID>();
    ShardsvrAbortReshardCollection object(localCmdType);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ShardsvrAbortReshardCollection::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kUserCanceledBit = 0;
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

        if (fieldName == kUserCanceledFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kUserCanceledBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUserCanceledBit);

                _hasUserCanceled = true;
                _userCanceled = element.boolean();
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
        if (!usedFields[kUserCanceledBit]) {
            ctxt.throwMissingField(kUserCanceledFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    {
        if (MONGO_likely(ctxt.checkAndAssertBinDataType(commandElement, newUUID))) {
            _commandParameter = UUID(uassertStatusOK(UUID::parse(commandElement)));
        }
        else {
            ctxt.throwMissingField(kCommandParameterFieldName);
        }
    }
}

ShardsvrAbortReshardCollection ShardsvrAbortReshardCollection::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto localCmdType = mongo::idl::preparsedValue<mongo::UUID>();
    ShardsvrAbortReshardCollection object(localCmdType);
    object.parseProtected(ctxt, request);
    return object;
}
void ShardsvrAbortReshardCollection::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<2> usedFields;
    const size_t kUserCanceledBit = 0;
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

        if (fieldName == kUserCanceledFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kUserCanceledBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUserCanceledBit);

                _hasUserCanceled = true;
                _userCanceled = element.boolean();
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
        if (!usedFields[kUserCanceledBit]) {
            ctxt.throwMissingField(kUserCanceledFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    {
        if (MONGO_likely(ctxt.checkAndAssertBinDataType(commandElement, newUUID))) {
            _commandParameter = UUID(uassertStatusOK(UUID::parse(commandElement)));
        }
        else {
            ctxt.throwMissingField(kCommandParameterFieldName);
        }
    }
}

void ShardsvrAbortReshardCollection::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasUserCanceled && _hasDbName);

    {
        ConstDataRange tempCDR = _commandParameter.toCDR();
        builder->append(kCommandParameterFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }
    builder->append(kUserCanceledFieldName, _userCanceled);

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest ShardsvrAbortReshardCollection::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasUserCanceled && _hasDbName);

        {
            ConstDataRange tempCDR = _commandParameter.toCDR();
            builder->append(kCommandParameterFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
        }
        builder->append(kUserCanceledFieldName, _userCanceled);

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj ShardsvrAbortReshardCollection::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
