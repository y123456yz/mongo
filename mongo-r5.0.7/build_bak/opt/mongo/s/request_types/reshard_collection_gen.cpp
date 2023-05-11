/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/s/request_types/reshard_collection_gen.h --output build/opt/mongo/s/request_types/reshard_collection_gen.cpp src/mongo/s/request_types/reshard_collection.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/s/request_types/reshard_collection_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData ReshardCollection::kCommandParameterFieldName;
constexpr StringData ReshardCollection::k_presetReshardedChunksFieldName;
constexpr StringData ReshardCollection::kCollationFieldName;
constexpr StringData ReshardCollection::kDbNameFieldName;
constexpr StringData ReshardCollection::kKeyFieldName;
constexpr StringData ReshardCollection::kNumInitialChunksFieldName;
constexpr StringData ReshardCollection::kUniqueFieldName;
constexpr StringData ReshardCollection::kZonesFieldName;
constexpr StringData ReshardCollection::kCommandName;

const std::vector<StringData> ReshardCollection::_knownBSONFields {
    ReshardCollection::k_presetReshardedChunksFieldName,
    ReshardCollection::kCollationFieldName,
    ReshardCollection::kKeyFieldName,
    ReshardCollection::kNumInitialChunksFieldName,
    ReshardCollection::kUniqueFieldName,
    ReshardCollection::kZonesFieldName,
    ReshardCollection::kCommandName,
};
const std::vector<StringData> ReshardCollection::_knownOP_MSGFields {
    ReshardCollection::k_presetReshardedChunksFieldName,
    ReshardCollection::kCollationFieldName,
    ReshardCollection::kDbNameFieldName,
    ReshardCollection::kKeyFieldName,
    ReshardCollection::kNumInitialChunksFieldName,
    ReshardCollection::kUniqueFieldName,
    ReshardCollection::kZonesFieldName,
    ReshardCollection::kCommandName,
};

ReshardCollection::ReshardCollection(const mongo::NamespaceString commandParameter) : _commandParameter(std::move(commandParameter)), _key(mongo::idl::preparsedValue<decltype(_key)>()), _hasKey(false), _hasDbName(false) {
    // Used for initialization only
}
ReshardCollection::ReshardCollection(const mongo::NamespaceString commandParameter, mongo::BSONObj key) : _commandParameter(std::move(commandParameter)), _key(std::move(key)), _hasKey(true), _hasDbName(true) {
    // Used for initialization only
}


ReshardCollection ReshardCollection::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto localCmdType = mongo::idl::preparsedValue<mongo::NamespaceString>();
    ReshardCollection object(localCmdType);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ReshardCollection::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<7> usedFields;
    const size_t kKeyBit = 0;
    const size_t kUniqueBit = 1;
    const size_t kNumInitialChunksBit = 2;
    const size_t kCollationBit = 3;
    const size_t kZonesBit = 4;
    const size_t k_presetReshardedChunksBit = 5;
    const size_t kDbNameBit = 6;
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

        if (fieldName == kKeyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kKeyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kKeyBit);

                _hasKey = true;
                _key = element.Obj();
            }
        }
        else if (fieldName == kUniqueFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kUniqueBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUniqueBit);

                _unique = element.boolean();
            }
        }
        else if (fieldName == kNumInitialChunksFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kNumInitialChunksBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNumInitialChunksBit);

                _numInitialChunks = element.safeNumberLong();
            }
        }
        else if (fieldName == kCollationFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCollationBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollationBit);

                _collation = element.Obj();
            }
        }
        else if (fieldName == kZonesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kZonesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kZonesBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kZonesFieldName, &ctxt);
            std::vector<mongo::ReshardingZoneType> values;

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
                        IDLParserErrorContext tempContext(kZonesFieldName, &ctxt);
                        const auto localObject = arrayElement.Obj();
                        values.emplace_back(mongo::ReshardingZoneType::parse(tempContext, localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _zones = std::move(values);
        }
        else if (fieldName == k_presetReshardedChunksFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[k_presetReshardedChunksBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(k_presetReshardedChunksBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(k_presetReshardedChunksFieldName, &ctxt);
            std::vector<mongo::ReshardedChunk> values;

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
                        IDLParserErrorContext tempContext(k_presetReshardedChunksFieldName, &ctxt);
                        const auto localObject = arrayElement.Obj();
                        values.emplace_back(mongo::ReshardedChunk::parse(tempContext, localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            __presetReshardedChunks = std::move(values);
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
        if (!usedFields[kKeyBit]) {
            ctxt.throwMissingField(kKeyFieldName);
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

ReshardCollection ReshardCollection::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto localCmdType = mongo::idl::preparsedValue<mongo::NamespaceString>();
    ReshardCollection object(localCmdType);
    object.parseProtected(ctxt, request);
    return object;
}
void ReshardCollection::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<7> usedFields;
    const size_t kKeyBit = 0;
    const size_t kUniqueBit = 1;
    const size_t kNumInitialChunksBit = 2;
    const size_t kCollationBit = 3;
    const size_t kZonesBit = 4;
    const size_t k_presetReshardedChunksBit = 5;
    const size_t kDbNameBit = 6;
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

        if (fieldName == kKeyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kKeyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kKeyBit);

                _hasKey = true;
                _key = element.Obj();
            }
        }
        else if (fieldName == kUniqueFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kUniqueBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUniqueBit);

                _unique = element.boolean();
            }
        }
        else if (fieldName == kNumInitialChunksFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kNumInitialChunksBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNumInitialChunksBit);

                _numInitialChunks = element.safeNumberLong();
            }
        }
        else if (fieldName == kCollationFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCollationBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollationBit);

                _collation = element.Obj();
            }
        }
        else if (fieldName == kZonesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kZonesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kZonesBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kZonesFieldName, &ctxt);
            std::vector<mongo::ReshardingZoneType> values;

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
                        IDLParserErrorContext tempContext(kZonesFieldName, &ctxt);
                        const auto localObject = arrayElement.Obj();
                        values.emplace_back(mongo::ReshardingZoneType::parse(tempContext, localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _zones = std::move(values);
        }
        else if (fieldName == k_presetReshardedChunksFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[k_presetReshardedChunksBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(k_presetReshardedChunksBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(k_presetReshardedChunksFieldName, &ctxt);
            std::vector<mongo::ReshardedChunk> values;

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
                        IDLParserErrorContext tempContext(k_presetReshardedChunksFieldName, &ctxt);
                        const auto localObject = arrayElement.Obj();
                        values.emplace_back(mongo::ReshardedChunk::parse(tempContext, localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            __presetReshardedChunks = std::move(values);
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
        if (!usedFields[kKeyBit]) {
            ctxt.throwMissingField(kKeyFieldName);
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

void ReshardCollection::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasKey && _hasDbName);

    {
        builder->append(kCommandParameterFieldName, _commandParameter.toString());
    }
    builder->append(kKeyFieldName, _key);

    if (_unique.is_initialized()) {
        builder->append(kUniqueFieldName, _unique.get());
    }

    if (_numInitialChunks.is_initialized()) {
        builder->append(kNumInitialChunksFieldName, _numInitialChunks.get());
    }

    if (_collation.is_initialized()) {
        builder->append(kCollationFieldName, _collation.get());
    }

    if (_zones.is_initialized()) {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kZonesFieldName));
        for (const auto& item : _zones.get()) {
            BSONObjBuilder subObjBuilder(arrayBuilder.subobjStart());
            item.serialize(&subObjBuilder);
        }
    }

    if (__presetReshardedChunks.is_initialized()) {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(k_presetReshardedChunksFieldName));
        for (const auto& item : __presetReshardedChunks.get()) {
            BSONObjBuilder subObjBuilder(arrayBuilder.subobjStart());
            item.serialize(&subObjBuilder);
        }
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest ReshardCollection::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasKey && _hasDbName);

        {
            builder->append(kCommandParameterFieldName, _commandParameter.toString());
        }
        builder->append(kKeyFieldName, _key);

        if (_unique.is_initialized()) {
            builder->append(kUniqueFieldName, _unique.get());
        }

        if (_numInitialChunks.is_initialized()) {
            builder->append(kNumInitialChunksFieldName, _numInitialChunks.get());
        }

        if (_collation.is_initialized()) {
            builder->append(kCollationFieldName, _collation.get());
        }

        if (_zones.is_initialized()) {
            BSONArrayBuilder arrayBuilder(builder->subarrayStart(kZonesFieldName));
            for (const auto& item : _zones.get()) {
                BSONObjBuilder subObjBuilder(arrayBuilder.subobjStart());
                item.serialize(&subObjBuilder);
            }
        }

        if (__presetReshardedChunks.is_initialized()) {
            BSONArrayBuilder arrayBuilder(builder->subarrayStart(k_presetReshardedChunksFieldName));
            for (const auto& item : __presetReshardedChunks.get()) {
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

BSONObj ReshardCollection::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData ConfigsvrReshardCollection::kCommandParameterFieldName;
constexpr StringData ConfigsvrReshardCollection::k_presetReshardedChunksFieldName;
constexpr StringData ConfigsvrReshardCollection::kCollationFieldName;
constexpr StringData ConfigsvrReshardCollection::kDbNameFieldName;
constexpr StringData ConfigsvrReshardCollection::kKeyFieldName;
constexpr StringData ConfigsvrReshardCollection::kNumInitialChunksFieldName;
constexpr StringData ConfigsvrReshardCollection::kUniqueFieldName;
constexpr StringData ConfigsvrReshardCollection::kZonesFieldName;
constexpr StringData ConfigsvrReshardCollection::kCommandName;

const std::vector<StringData> ConfigsvrReshardCollection::_knownBSONFields {
    ConfigsvrReshardCollection::k_presetReshardedChunksFieldName,
    ConfigsvrReshardCollection::kCollationFieldName,
    ConfigsvrReshardCollection::kKeyFieldName,
    ConfigsvrReshardCollection::kNumInitialChunksFieldName,
    ConfigsvrReshardCollection::kUniqueFieldName,
    ConfigsvrReshardCollection::kZonesFieldName,
    ConfigsvrReshardCollection::kCommandName,
};
const std::vector<StringData> ConfigsvrReshardCollection::_knownOP_MSGFields {
    ConfigsvrReshardCollection::k_presetReshardedChunksFieldName,
    ConfigsvrReshardCollection::kCollationFieldName,
    ConfigsvrReshardCollection::kDbNameFieldName,
    ConfigsvrReshardCollection::kKeyFieldName,
    ConfigsvrReshardCollection::kNumInitialChunksFieldName,
    ConfigsvrReshardCollection::kUniqueFieldName,
    ConfigsvrReshardCollection::kZonesFieldName,
    ConfigsvrReshardCollection::kCommandName,
};

ConfigsvrReshardCollection::ConfigsvrReshardCollection(const mongo::NamespaceString commandParameter) : _commandParameter(std::move(commandParameter)), _key(mongo::idl::preparsedValue<decltype(_key)>()), _hasKey(false), _hasDbName(false) {
    // Used for initialization only
}
ConfigsvrReshardCollection::ConfigsvrReshardCollection(const mongo::NamespaceString commandParameter, mongo::BSONObj key) : _commandParameter(std::move(commandParameter)), _key(std::move(key)), _hasKey(true), _hasDbName(true) {
    // Used for initialization only
}


ConfigsvrReshardCollection ConfigsvrReshardCollection::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto localCmdType = mongo::idl::preparsedValue<mongo::NamespaceString>();
    ConfigsvrReshardCollection object(localCmdType);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ConfigsvrReshardCollection::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<7> usedFields;
    const size_t kKeyBit = 0;
    const size_t kUniqueBit = 1;
    const size_t kNumInitialChunksBit = 2;
    const size_t kCollationBit = 3;
    const size_t kZonesBit = 4;
    const size_t k_presetReshardedChunksBit = 5;
    const size_t kDbNameBit = 6;
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

        if (fieldName == kKeyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kKeyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kKeyBit);

                _hasKey = true;
                _key = element.Obj();
            }
        }
        else if (fieldName == kUniqueFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kUniqueBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUniqueBit);

                _unique = element.boolean();
            }
        }
        else if (fieldName == kNumInitialChunksFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kNumInitialChunksBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNumInitialChunksBit);

                _numInitialChunks = element.safeNumberLong();
            }
        }
        else if (fieldName == kCollationFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCollationBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollationBit);

                _collation = element.Obj();
            }
        }
        else if (fieldName == kZonesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kZonesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kZonesBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kZonesFieldName, &ctxt);
            std::vector<mongo::ReshardingZoneType> values;

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
                        IDLParserErrorContext tempContext(kZonesFieldName, &ctxt);
                        const auto localObject = arrayElement.Obj();
                        values.emplace_back(mongo::ReshardingZoneType::parse(tempContext, localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _zones = std::move(values);
        }
        else if (fieldName == k_presetReshardedChunksFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[k_presetReshardedChunksBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(k_presetReshardedChunksBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(k_presetReshardedChunksFieldName, &ctxt);
            std::vector<mongo::ReshardedChunk> values;

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
                        IDLParserErrorContext tempContext(k_presetReshardedChunksFieldName, &ctxt);
                        const auto localObject = arrayElement.Obj();
                        values.emplace_back(mongo::ReshardedChunk::parse(tempContext, localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            __presetReshardedChunks = std::move(values);
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
        if (!usedFields[kKeyBit]) {
            ctxt.throwMissingField(kKeyFieldName);
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

ConfigsvrReshardCollection ConfigsvrReshardCollection::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto localCmdType = mongo::idl::preparsedValue<mongo::NamespaceString>();
    ConfigsvrReshardCollection object(localCmdType);
    object.parseProtected(ctxt, request);
    return object;
}
void ConfigsvrReshardCollection::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<7> usedFields;
    const size_t kKeyBit = 0;
    const size_t kUniqueBit = 1;
    const size_t kNumInitialChunksBit = 2;
    const size_t kCollationBit = 3;
    const size_t kZonesBit = 4;
    const size_t k_presetReshardedChunksBit = 5;
    const size_t kDbNameBit = 6;
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

        if (fieldName == kKeyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kKeyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kKeyBit);

                _hasKey = true;
                _key = element.Obj();
            }
        }
        else if (fieldName == kUniqueFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kUniqueBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUniqueBit);

                _unique = element.boolean();
            }
        }
        else if (fieldName == kNumInitialChunksFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kNumInitialChunksBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNumInitialChunksBit);

                _numInitialChunks = element.safeNumberLong();
            }
        }
        else if (fieldName == kCollationFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCollationBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollationBit);

                _collation = element.Obj();
            }
        }
        else if (fieldName == kZonesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kZonesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kZonesBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kZonesFieldName, &ctxt);
            std::vector<mongo::ReshardingZoneType> values;

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
                        IDLParserErrorContext tempContext(kZonesFieldName, &ctxt);
                        const auto localObject = arrayElement.Obj();
                        values.emplace_back(mongo::ReshardingZoneType::parse(tempContext, localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _zones = std::move(values);
        }
        else if (fieldName == k_presetReshardedChunksFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[k_presetReshardedChunksBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(k_presetReshardedChunksBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(k_presetReshardedChunksFieldName, &ctxt);
            std::vector<mongo::ReshardedChunk> values;

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
                        IDLParserErrorContext tempContext(k_presetReshardedChunksFieldName, &ctxt);
                        const auto localObject = arrayElement.Obj();
                        values.emplace_back(mongo::ReshardedChunk::parse(tempContext, localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            __presetReshardedChunks = std::move(values);
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
        if (!usedFields[kKeyBit]) {
            ctxt.throwMissingField(kKeyFieldName);
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

void ConfigsvrReshardCollection::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasKey && _hasDbName);

    {
        builder->append(kCommandParameterFieldName, _commandParameter.toString());
    }
    builder->append(kKeyFieldName, _key);

    if (_unique.is_initialized()) {
        builder->append(kUniqueFieldName, _unique.get());
    }

    if (_numInitialChunks.is_initialized()) {
        builder->append(kNumInitialChunksFieldName, _numInitialChunks.get());
    }

    if (_collation.is_initialized()) {
        builder->append(kCollationFieldName, _collation.get());
    }

    if (_zones.is_initialized()) {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kZonesFieldName));
        for (const auto& item : _zones.get()) {
            BSONObjBuilder subObjBuilder(arrayBuilder.subobjStart());
            item.serialize(&subObjBuilder);
        }
    }

    if (__presetReshardedChunks.is_initialized()) {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(k_presetReshardedChunksFieldName));
        for (const auto& item : __presetReshardedChunks.get()) {
            BSONObjBuilder subObjBuilder(arrayBuilder.subobjStart());
            item.serialize(&subObjBuilder);
        }
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest ConfigsvrReshardCollection::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasKey && _hasDbName);

        {
            builder->append(kCommandParameterFieldName, _commandParameter.toString());
        }
        builder->append(kKeyFieldName, _key);

        if (_unique.is_initialized()) {
            builder->append(kUniqueFieldName, _unique.get());
        }

        if (_numInitialChunks.is_initialized()) {
            builder->append(kNumInitialChunksFieldName, _numInitialChunks.get());
        }

        if (_collation.is_initialized()) {
            builder->append(kCollationFieldName, _collation.get());
        }

        if (_zones.is_initialized()) {
            BSONArrayBuilder arrayBuilder(builder->subarrayStart(kZonesFieldName));
            for (const auto& item : _zones.get()) {
                BSONObjBuilder subObjBuilder(arrayBuilder.subobjStart());
                item.serialize(&subObjBuilder);
            }
        }

        if (__presetReshardedChunks.is_initialized()) {
            BSONArrayBuilder arrayBuilder(builder->subarrayStart(k_presetReshardedChunksFieldName));
            for (const auto& item : __presetReshardedChunks.get()) {
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

BSONObj ConfigsvrReshardCollection::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
