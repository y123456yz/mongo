/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/s/request_types/clear_jumbo_flag_gen.h --output build/opt/mongo/s/request_types/clear_jumbo_flag_gen.cpp src/mongo/s/request_types/clear_jumbo_flag.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/s/request_types/clear_jumbo_flag_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData ClearJumboFlag::kCommandParameterFieldName;
constexpr StringData ClearJumboFlag::kBoundsFieldName;
constexpr StringData ClearJumboFlag::kDbNameFieldName;
constexpr StringData ClearJumboFlag::kFindFieldName;
constexpr StringData ClearJumboFlag::kCommandName;

const std::vector<StringData> ClearJumboFlag::_knownBSONFields {
    ClearJumboFlag::kBoundsFieldName,
    ClearJumboFlag::kFindFieldName,
    ClearJumboFlag::kCommandName,
};
const std::vector<StringData> ClearJumboFlag::_knownOP_MSGFields {
    ClearJumboFlag::kBoundsFieldName,
    ClearJumboFlag::kDbNameFieldName,
    ClearJumboFlag::kFindFieldName,
    ClearJumboFlag::kCommandName,
};

ClearJumboFlag::ClearJumboFlag(const mongo::NamespaceString commandParameter) : _commandParameter(std::move(commandParameter)), _hasDbName(false) {
    // Used for initialization only
}


ClearJumboFlag ClearJumboFlag::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto localCmdType = mongo::idl::preparsedValue<mongo::NamespaceString>();
    ClearJumboFlag object(localCmdType);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ClearJumboFlag::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<3> usedFields;
    const size_t kBoundsBit = 0;
    const size_t kFindBit = 1;
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

        if (fieldName == kBoundsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kBoundsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kBoundsBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kBoundsFieldName, &ctxt);
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
                        values.emplace_back(arrayElement.Obj());
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _bounds = std::move(values);
        }
        else if (fieldName == kFindFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kFindBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kFindBit);

                _find = element.Obj();
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

ClearJumboFlag ClearJumboFlag::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto localCmdType = mongo::idl::preparsedValue<mongo::NamespaceString>();
    ClearJumboFlag object(localCmdType);
    object.parseProtected(ctxt, request);
    return object;
}
void ClearJumboFlag::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<3> usedFields;
    const size_t kBoundsBit = 0;
    const size_t kFindBit = 1;
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

        if (fieldName == kBoundsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kBoundsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kBoundsBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kBoundsFieldName, &ctxt);
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
                        values.emplace_back(arrayElement.Obj());
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _bounds = std::move(values);
        }
        else if (fieldName == kFindFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kFindBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kFindBit);

                _find = element.Obj();
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

void ClearJumboFlag::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    {
        builder->append(kCommandParameterFieldName, _commandParameter.toString());
    }
    if (_bounds.is_initialized()) {
        builder->append(kBoundsFieldName, _bounds.get());
    }

    if (_find.is_initialized()) {
        builder->append(kFindFieldName, _find.get());
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest ClearJumboFlag::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        {
            builder->append(kCommandParameterFieldName, _commandParameter.toString());
        }
        if (_bounds.is_initialized()) {
            builder->append(kBoundsFieldName, _bounds.get());
        }

        if (_find.is_initialized()) {
            builder->append(kFindFieldName, _find.get());
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj ClearJumboFlag::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData ConfigsvrClearJumboFlag::kCommandParameterFieldName;
constexpr StringData ConfigsvrClearJumboFlag::kDbNameFieldName;
constexpr StringData ConfigsvrClearJumboFlag::kEpochFieldName;
constexpr StringData ConfigsvrClearJumboFlag::kMaxKeyFieldName;
constexpr StringData ConfigsvrClearJumboFlag::kMinKeyFieldName;
constexpr StringData ConfigsvrClearJumboFlag::kCommandName;

const std::vector<StringData> ConfigsvrClearJumboFlag::_knownBSONFields {
    ConfigsvrClearJumboFlag::kEpochFieldName,
    ConfigsvrClearJumboFlag::kMaxKeyFieldName,
    ConfigsvrClearJumboFlag::kMinKeyFieldName,
    ConfigsvrClearJumboFlag::kCommandName,
};
const std::vector<StringData> ConfigsvrClearJumboFlag::_knownOP_MSGFields {
    ConfigsvrClearJumboFlag::kDbNameFieldName,
    ConfigsvrClearJumboFlag::kEpochFieldName,
    ConfigsvrClearJumboFlag::kMaxKeyFieldName,
    ConfigsvrClearJumboFlag::kMinKeyFieldName,
    ConfigsvrClearJumboFlag::kCommandName,
};

ConfigsvrClearJumboFlag::ConfigsvrClearJumboFlag(const mongo::NamespaceString commandParameter) : _commandParameter(std::move(commandParameter)), _epoch(mongo::idl::preparsedValue<decltype(_epoch)>()), _minKey(mongo::idl::preparsedValue<decltype(_minKey)>()), _maxKey(mongo::idl::preparsedValue<decltype(_maxKey)>()), _hasEpoch(false), _hasMinKey(false), _hasMaxKey(false), _hasDbName(false) {
    // Used for initialization only
}
ConfigsvrClearJumboFlag::ConfigsvrClearJumboFlag(const mongo::NamespaceString commandParameter, mongo::OID epoch, mongo::BSONObj minKey, mongo::BSONObj maxKey) : _commandParameter(std::move(commandParameter)), _epoch(std::move(epoch)), _minKey(std::move(minKey)), _maxKey(std::move(maxKey)), _hasEpoch(true), _hasMinKey(true), _hasMaxKey(true), _hasDbName(true) {
    // Used for initialization only
}


ConfigsvrClearJumboFlag ConfigsvrClearJumboFlag::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto localCmdType = mongo::idl::preparsedValue<mongo::NamespaceString>();
    ConfigsvrClearJumboFlag object(localCmdType);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ConfigsvrClearJumboFlag::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<4> usedFields;
    const size_t kEpochBit = 0;
    const size_t kMinKeyBit = 1;
    const size_t kMaxKeyBit = 2;
    const size_t kDbNameBit = 3;
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

        if (fieldName == kEpochFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, jstOID))) {
                if (MONGO_unlikely(usedFields[kEpochBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kEpochBit);

                _hasEpoch = true;
                _epoch = element.OID();
            }
        }
        else if (fieldName == kMinKeyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kMinKeyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMinKeyBit);

                _hasMinKey = true;
                _minKey = element.Obj();
            }
        }
        else if (fieldName == kMaxKeyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kMaxKeyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMaxKeyBit);

                _hasMaxKey = true;
                _maxKey = element.Obj();
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
        if (!usedFields[kEpochBit]) {
            ctxt.throwMissingField(kEpochFieldName);
        }
        if (!usedFields[kMinKeyBit]) {
            ctxt.throwMissingField(kMinKeyFieldName);
        }
        if (!usedFields[kMaxKeyBit]) {
            ctxt.throwMissingField(kMaxKeyFieldName);
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

ConfigsvrClearJumboFlag ConfigsvrClearJumboFlag::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto localCmdType = mongo::idl::preparsedValue<mongo::NamespaceString>();
    ConfigsvrClearJumboFlag object(localCmdType);
    object.parseProtected(ctxt, request);
    return object;
}
void ConfigsvrClearJumboFlag::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<4> usedFields;
    const size_t kEpochBit = 0;
    const size_t kMinKeyBit = 1;
    const size_t kMaxKeyBit = 2;
    const size_t kDbNameBit = 3;
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

        if (fieldName == kEpochFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, jstOID))) {
                if (MONGO_unlikely(usedFields[kEpochBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kEpochBit);

                _hasEpoch = true;
                _epoch = element.OID();
            }
        }
        else if (fieldName == kMinKeyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kMinKeyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMinKeyBit);

                _hasMinKey = true;
                _minKey = element.Obj();
            }
        }
        else if (fieldName == kMaxKeyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kMaxKeyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMaxKeyBit);

                _hasMaxKey = true;
                _maxKey = element.Obj();
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
        if (!usedFields[kEpochBit]) {
            ctxt.throwMissingField(kEpochFieldName);
        }
        if (!usedFields[kMinKeyBit]) {
            ctxt.throwMissingField(kMinKeyFieldName);
        }
        if (!usedFields[kMaxKeyBit]) {
            ctxt.throwMissingField(kMaxKeyFieldName);
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

void ConfigsvrClearJumboFlag::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasEpoch && _hasMinKey && _hasMaxKey && _hasDbName);

    {
        builder->append(kCommandParameterFieldName, _commandParameter.toString());
    }
    builder->append(kEpochFieldName, _epoch);

    builder->append(kMinKeyFieldName, _minKey);

    builder->append(kMaxKeyFieldName, _maxKey);

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest ConfigsvrClearJumboFlag::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasEpoch && _hasMinKey && _hasMaxKey && _hasDbName);

        {
            builder->append(kCommandParameterFieldName, _commandParameter.toString());
        }
        builder->append(kEpochFieldName, _epoch);

        builder->append(kMinKeyFieldName, _minKey);

        builder->append(kMaxKeyFieldName, _maxKey);

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj ConfigsvrClearJumboFlag::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
