/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/s/request_types/flush_resharding_state_change_gen.h --output build/opt/mongo/s/request_types/flush_resharding_state_change_gen.cpp src/mongo/s/request_types/flush_resharding_state_change.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/s/request_types/flush_resharding_state_change_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData _flushReshardingStateChange::kCommandParameterFieldName;
constexpr StringData _flushReshardingStateChange::kDbNameFieldName;
constexpr StringData _flushReshardingStateChange::kReshardingUUIDFieldName;
constexpr StringData _flushReshardingStateChange::kCommandName;

const std::vector<StringData> _flushReshardingStateChange::_knownBSONFields {
    _flushReshardingStateChange::kReshardingUUIDFieldName,
    _flushReshardingStateChange::kCommandName,
};
const std::vector<StringData> _flushReshardingStateChange::_knownOP_MSGFields {
    _flushReshardingStateChange::kDbNameFieldName,
    _flushReshardingStateChange::kReshardingUUIDFieldName,
    _flushReshardingStateChange::kCommandName,
};

_flushReshardingStateChange::_flushReshardingStateChange(const mongo::NamespaceString commandParameter) : _commandParameter(std::move(commandParameter)), _reshardingUUID(mongo::idl::preparsedValue<decltype(_reshardingUUID)>()), _hasReshardingUUID(false), _hasDbName(false) {
    // Used for initialization only
}
_flushReshardingStateChange::_flushReshardingStateChange(const mongo::NamespaceString commandParameter, mongo::UUID reshardingUUID) : _commandParameter(std::move(commandParameter)), _reshardingUUID(std::move(reshardingUUID)), _hasReshardingUUID(true), _hasDbName(true) {
    // Used for initialization only
}


_flushReshardingStateChange _flushReshardingStateChange::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto localCmdType = mongo::idl::preparsedValue<mongo::NamespaceString>();
    _flushReshardingStateChange object(localCmdType);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void _flushReshardingStateChange::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kReshardingUUIDBit = 0;
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

        if (fieldName == kReshardingUUIDFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kReshardingUUIDBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kReshardingUUIDBit);

                _hasReshardingUUID = true;
                _reshardingUUID = UUID(uassertStatusOK(UUID::parse(element)));
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
        if (!usedFields[kReshardingUUIDBit]) {
            ctxt.throwMissingField(kReshardingUUIDFieldName);
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

_flushReshardingStateChange _flushReshardingStateChange::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto localCmdType = mongo::idl::preparsedValue<mongo::NamespaceString>();
    _flushReshardingStateChange object(localCmdType);
    object.parseProtected(ctxt, request);
    return object;
}
void _flushReshardingStateChange::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<2> usedFields;
    const size_t kReshardingUUIDBit = 0;
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

        if (fieldName == kReshardingUUIDFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kReshardingUUIDBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kReshardingUUIDBit);

                _hasReshardingUUID = true;
                _reshardingUUID = UUID(uassertStatusOK(UUID::parse(element)));
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
        if (!usedFields[kReshardingUUIDBit]) {
            ctxt.throwMissingField(kReshardingUUIDFieldName);
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

void _flushReshardingStateChange::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasReshardingUUID && _hasDbName);

    {
        builder->append(kCommandParameterFieldName, _commandParameter.toString());
    }
    {
        ConstDataRange tempCDR = _reshardingUUID.toCDR();
        builder->append(kReshardingUUIDFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest _flushReshardingStateChange::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasReshardingUUID && _hasDbName);

        {
            builder->append(kCommandParameterFieldName, _commandParameter.toString());
        }
        {
            ConstDataRange tempCDR = _reshardingUUID.toCDR();
            builder->append(kReshardingUUIDFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj _flushReshardingStateChange::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
