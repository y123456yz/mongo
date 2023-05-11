/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/s/resharding_test_commands_gen.h --output build/opt/mongo/db/s/resharding_test_commands_gen.cpp src/mongo/db/s/resharding_test_commands.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/s/resharding_test_commands_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData TestReshardCloneCollection::kCommandParameterFieldName;
constexpr StringData TestReshardCloneCollection::kAtClusterTimeFieldName;
constexpr StringData TestReshardCloneCollection::kDbNameFieldName;
constexpr StringData TestReshardCloneCollection::kOutputNsFieldName;
constexpr StringData TestReshardCloneCollection::kShardIdFieldName;
constexpr StringData TestReshardCloneCollection::kShardKeyFieldName;
constexpr StringData TestReshardCloneCollection::kUuidFieldName;
constexpr StringData TestReshardCloneCollection::kCommandName;

const std::vector<StringData> TestReshardCloneCollection::_knownBSONFields {
    TestReshardCloneCollection::kAtClusterTimeFieldName,
    TestReshardCloneCollection::kOutputNsFieldName,
    TestReshardCloneCollection::kShardIdFieldName,
    TestReshardCloneCollection::kShardKeyFieldName,
    TestReshardCloneCollection::kUuidFieldName,
    TestReshardCloneCollection::kCommandName,
};
const std::vector<StringData> TestReshardCloneCollection::_knownOP_MSGFields {
    TestReshardCloneCollection::kAtClusterTimeFieldName,
    TestReshardCloneCollection::kDbNameFieldName,
    TestReshardCloneCollection::kOutputNsFieldName,
    TestReshardCloneCollection::kShardIdFieldName,
    TestReshardCloneCollection::kShardKeyFieldName,
    TestReshardCloneCollection::kUuidFieldName,
    TestReshardCloneCollection::kCommandName,
};

TestReshardCloneCollection::TestReshardCloneCollection(const mongo::NamespaceString commandParameter) : _commandParameter(std::move(commandParameter)), _atClusterTime(mongo::idl::preparsedValue<decltype(_atClusterTime)>()), _outputNs(mongo::idl::preparsedValue<decltype(_outputNs)>()), _shardKey(mongo::idl::preparsedValue<decltype(_shardKey)>()), _shardId(mongo::idl::preparsedValue<decltype(_shardId)>()), _uuid(mongo::idl::preparsedValue<decltype(_uuid)>()), _hasAtClusterTime(false), _hasOutputNs(false), _hasShardKey(false), _hasShardId(false), _hasUuid(false), _hasDbName(false) {
    // Used for initialization only
}
TestReshardCloneCollection::TestReshardCloneCollection(const mongo::NamespaceString commandParameter, mongo::Timestamp atClusterTime, mongo::NamespaceString outputNs, mongo::BSONObj shardKey, mongo::ShardId shardId, mongo::UUID uuid) : _commandParameter(std::move(commandParameter)), _atClusterTime(std::move(atClusterTime)), _outputNs(std::move(outputNs)), _shardKey(std::move(shardKey)), _shardId(std::move(shardId)), _uuid(std::move(uuid)), _hasAtClusterTime(true), _hasOutputNs(true), _hasShardKey(true), _hasShardId(true), _hasUuid(true), _hasDbName(true) {
    // Used for initialization only
}


TestReshardCloneCollection TestReshardCloneCollection::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto localCmdType = mongo::idl::preparsedValue<mongo::NamespaceString>();
    TestReshardCloneCollection object(localCmdType);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void TestReshardCloneCollection::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<6> usedFields;
    const size_t kAtClusterTimeBit = 0;
    const size_t kOutputNsBit = 1;
    const size_t kShardKeyBit = 2;
    const size_t kShardIdBit = 3;
    const size_t kUuidBit = 4;
    const size_t kDbNameBit = 5;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kAtClusterTimeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, bsonTimestamp))) {
                if (MONGO_unlikely(usedFields[kAtClusterTimeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAtClusterTimeBit);

                _hasAtClusterTime = true;
                _atClusterTime = element.timestamp();
            }
        }
        else if (fieldName == kOutputNsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kOutputNsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kOutputNsBit);

                _hasOutputNs = true;
                _outputNs = NamespaceString(element.valueStringData());
            }
        }
        else if (fieldName == kShardKeyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kShardKeyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kShardKeyBit);

                _hasShardKey = true;
                _shardKey = element.Obj();
            }
        }
        else if (fieldName == kShardIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kShardIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kShardIdBit);

                _hasShardId = true;
                _shardId = element.str();
            }
        }
        else if (fieldName == kUuidFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kUuidBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUuidBit);

                _hasUuid = true;
                _uuid = UUID(uassertStatusOK(UUID::parse(element)));
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
        if (!usedFields[kAtClusterTimeBit]) {
            ctxt.throwMissingField(kAtClusterTimeFieldName);
        }
        if (!usedFields[kOutputNsBit]) {
            ctxt.throwMissingField(kOutputNsFieldName);
        }
        if (!usedFields[kShardKeyBit]) {
            ctxt.throwMissingField(kShardKeyFieldName);
        }
        if (!usedFields[kShardIdBit]) {
            ctxt.throwMissingField(kShardIdFieldName);
        }
        if (!usedFields[kUuidBit]) {
            ctxt.throwMissingField(kUuidFieldName);
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

TestReshardCloneCollection TestReshardCloneCollection::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto localCmdType = mongo::idl::preparsedValue<mongo::NamespaceString>();
    TestReshardCloneCollection object(localCmdType);
    object.parseProtected(ctxt, request);
    return object;
}
void TestReshardCloneCollection::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<6> usedFields;
    const size_t kAtClusterTimeBit = 0;
    const size_t kOutputNsBit = 1;
    const size_t kShardKeyBit = 2;
    const size_t kShardIdBit = 3;
    const size_t kUuidBit = 4;
    const size_t kDbNameBit = 5;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kAtClusterTimeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, bsonTimestamp))) {
                if (MONGO_unlikely(usedFields[kAtClusterTimeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAtClusterTimeBit);

                _hasAtClusterTime = true;
                _atClusterTime = element.timestamp();
            }
        }
        else if (fieldName == kOutputNsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kOutputNsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kOutputNsBit);

                _hasOutputNs = true;
                _outputNs = NamespaceString(element.valueStringData());
            }
        }
        else if (fieldName == kShardKeyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kShardKeyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kShardKeyBit);

                _hasShardKey = true;
                _shardKey = element.Obj();
            }
        }
        else if (fieldName == kShardIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kShardIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kShardIdBit);

                _hasShardId = true;
                _shardId = element.str();
            }
        }
        else if (fieldName == kUuidFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kUuidBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUuidBit);

                _hasUuid = true;
                _uuid = UUID(uassertStatusOK(UUID::parse(element)));
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
        if (!usedFields[kAtClusterTimeBit]) {
            ctxt.throwMissingField(kAtClusterTimeFieldName);
        }
        if (!usedFields[kOutputNsBit]) {
            ctxt.throwMissingField(kOutputNsFieldName);
        }
        if (!usedFields[kShardKeyBit]) {
            ctxt.throwMissingField(kShardKeyFieldName);
        }
        if (!usedFields[kShardIdBit]) {
            ctxt.throwMissingField(kShardIdFieldName);
        }
        if (!usedFields[kUuidBit]) {
            ctxt.throwMissingField(kUuidFieldName);
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

void TestReshardCloneCollection::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasAtClusterTime && _hasOutputNs && _hasShardKey && _hasShardId && _hasUuid && _hasDbName);

    {
        builder->append(kCommandParameterFieldName, _commandParameter.toString());
    }
    builder->append(kAtClusterTimeFieldName, _atClusterTime);

    {
        builder->append(kOutputNsFieldName, _outputNs.toString());
    }

    builder->append(kShardKeyFieldName, _shardKey);

    {
        builder->append(kShardIdFieldName, _shardId.toString());
    }

    {
        ConstDataRange tempCDR = _uuid.toCDR();
        builder->append(kUuidFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest TestReshardCloneCollection::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasAtClusterTime && _hasOutputNs && _hasShardKey && _hasShardId && _hasUuid && _hasDbName);

        {
            builder->append(kCommandParameterFieldName, _commandParameter.toString());
        }
        builder->append(kAtClusterTimeFieldName, _atClusterTime);

        {
            builder->append(kOutputNsFieldName, _outputNs.toString());
        }

        builder->append(kShardKeyFieldName, _shardKey);

        {
            builder->append(kShardIdFieldName, _shardId.toString());
        }

        {
            ConstDataRange tempCDR = _uuid.toCDR();
            builder->append(kUuidFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj TestReshardCloneCollection::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
