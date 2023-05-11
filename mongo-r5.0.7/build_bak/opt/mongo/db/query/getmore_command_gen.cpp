/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/query/getmore_command_gen.h --output build/opt/mongo/db/query/getmore_command_gen.cpp src/mongo/db/query/getmore_command.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/query/getmore_command_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData GetMoreCommandRequest::kCommandParameterFieldName;
constexpr StringData GetMoreCommandRequest::kBatchSizeFieldName;
constexpr StringData GetMoreCommandRequest::kCollectionFieldName;
constexpr StringData GetMoreCommandRequest::kDbNameFieldName;
constexpr StringData GetMoreCommandRequest::kLastKnownCommittedOpTimeFieldName;
constexpr StringData GetMoreCommandRequest::kMaxTimeMSFieldName;
constexpr StringData GetMoreCommandRequest::kTermFieldName;
constexpr StringData GetMoreCommandRequest::kCommandName;

const std::vector<StringData> GetMoreCommandRequest::_knownBSONFields {
    GetMoreCommandRequest::kBatchSizeFieldName,
    GetMoreCommandRequest::kCollectionFieldName,
    GetMoreCommandRequest::kLastKnownCommittedOpTimeFieldName,
    GetMoreCommandRequest::kMaxTimeMSFieldName,
    GetMoreCommandRequest::kTermFieldName,
    GetMoreCommandRequest::kCommandName,
};
const std::vector<StringData> GetMoreCommandRequest::_knownOP_MSGFields {
    GetMoreCommandRequest::kBatchSizeFieldName,
    GetMoreCommandRequest::kCollectionFieldName,
    GetMoreCommandRequest::kDbNameFieldName,
    GetMoreCommandRequest::kLastKnownCommittedOpTimeFieldName,
    GetMoreCommandRequest::kMaxTimeMSFieldName,
    GetMoreCommandRequest::kTermFieldName,
    GetMoreCommandRequest::kCommandName,
};

GetMoreCommandRequest::GetMoreCommandRequest(const std::int64_t commandParameter) : _commandParameter(std::move(commandParameter)), _collection(mongo::idl::preparsedValue<decltype(_collection)>()), _hasCollection(false), _hasDbName(false) {
    // Used for initialization only
}
GetMoreCommandRequest::GetMoreCommandRequest(const std::int64_t commandParameter, std::string collection) : _commandParameter(std::move(commandParameter)), _collection(std::move(collection)), _hasCollection(true), _hasDbName(true) {
    // Used for initialization only
}

void GetMoreCommandRequest::validateCollection(IDLParserErrorContext& ctxt, const std::string& value)
{
    uassertStatusOK(query_request_helper::validateGetMoreCollectionName(value));
}

void GetMoreCommandRequest::validateCollection(const std::string& value)
{
    uassertStatusOK(query_request_helper::validateGetMoreCollectionName(value));
}

void GetMoreCommandRequest::validateBatchSize(IDLParserErrorContext& ctxt, const std::int64_t value)
{
    if (!(value >= 0)) {
        throwComparisonError<std::int64_t>(ctxt, "batchSize", ">="_sd, value, 0);
    }
}

void GetMoreCommandRequest::validateBatchSize(const std::int64_t value)
{
    if (!(value >= 0)) {
        throwComparisonError<std::int64_t>("batchSize", ">="_sd, value, 0);
    }
}


GetMoreCommandRequest GetMoreCommandRequest::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto localCmdType = mongo::idl::preparsedValue<std::int64_t>();
    GetMoreCommandRequest object(localCmdType);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void GetMoreCommandRequest::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<6> usedFields;
    const size_t kCollectionBit = 0;
    const size_t kBatchSizeBit = 1;
    const size_t kMaxTimeMSBit = 2;
    const size_t kTermBit = 3;
    const size_t kLastKnownCommittedOpTimeBit = 4;
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

        if (fieldName == kCollectionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kCollectionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollectionBit);

                _hasCollection = true;
                {
                    auto value = element.str();
                    validateCollection(value);
                    _collection = std::move(value);
                }
            }
        }
        else if (fieldName == kBatchSizeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kBatchSizeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kBatchSizeBit);

                {
                    auto value = element.safeNumberLong();
                    validateBatchSize(value);
                    _batchSize = std::move(value);
                }
            }
        }
        else if (fieldName == kMaxTimeMSFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kMaxTimeMSBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMaxTimeMSBit);

                _maxTimeMS = element.safeNumberLong();
            }
        }
        else if (fieldName == kTermFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kTermBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTermBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                _term = element._numberLong();
            }
        }
        else if (fieldName == kLastKnownCommittedOpTimeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kLastKnownCommittedOpTimeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLastKnownCommittedOpTimeBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                const BSONObj localObject = element.Obj();
                _lastKnownCommittedOpTime = repl::OpTime::parse(localObject);
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
        if (!usedFields[kCollectionBit]) {
            ctxt.throwMissingField(kCollectionFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    {
        if (MONGO_likely(ctxt.checkAndAssertType(commandElement, NumberLong))) {
            _commandParameter = commandElement._numberLong();
        }
        else {
            ctxt.throwMissingField(kCommandParameterFieldName);
        }
    }
}

GetMoreCommandRequest GetMoreCommandRequest::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto localCmdType = mongo::idl::preparsedValue<std::int64_t>();
    GetMoreCommandRequest object(localCmdType);
    object.parseProtected(ctxt, request);
    return object;
}
void GetMoreCommandRequest::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<6> usedFields;
    const size_t kCollectionBit = 0;
    const size_t kBatchSizeBit = 1;
    const size_t kMaxTimeMSBit = 2;
    const size_t kTermBit = 3;
    const size_t kLastKnownCommittedOpTimeBit = 4;
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

        if (fieldName == kCollectionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kCollectionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollectionBit);

                _hasCollection = true;
                {
                    auto value = element.str();
                    validateCollection(value);
                    _collection = std::move(value);
                }
            }
        }
        else if (fieldName == kBatchSizeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kBatchSizeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kBatchSizeBit);

                {
                    auto value = element.safeNumberLong();
                    validateBatchSize(value);
                    _batchSize = std::move(value);
                }
            }
        }
        else if (fieldName == kMaxTimeMSFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kMaxTimeMSBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMaxTimeMSBit);

                _maxTimeMS = element.safeNumberLong();
            }
        }
        else if (fieldName == kTermFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kTermBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTermBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                _term = element._numberLong();
            }
        }
        else if (fieldName == kLastKnownCommittedOpTimeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kLastKnownCommittedOpTimeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLastKnownCommittedOpTimeBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                const BSONObj localObject = element.Obj();
                _lastKnownCommittedOpTime = repl::OpTime::parse(localObject);
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
        if (!usedFields[kCollectionBit]) {
            ctxt.throwMissingField(kCollectionFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    {
        if (MONGO_likely(ctxt.checkAndAssertType(commandElement, NumberLong))) {
            _commandParameter = commandElement._numberLong();
        }
        else {
            ctxt.throwMissingField(kCommandParameterFieldName);
        }
    }
}

void GetMoreCommandRequest::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasCollection && _hasDbName);

    builder->append(kCommandParameterFieldName, _commandParameter);
    builder->append(kCollectionFieldName, _collection);

    if (_batchSize.is_initialized()) {
        builder->append(kBatchSizeFieldName, _batchSize.get());
    }

    if (_maxTimeMS.is_initialized()) {
        builder->append(kMaxTimeMSFieldName, _maxTimeMS.get());
    }

    if (_term.is_initialized()) {
        builder->append(kTermFieldName, _term.get());
    }

    if (_lastKnownCommittedOpTime.is_initialized()) {
        const BSONObj localObject = _lastKnownCommittedOpTime.get().toBSON();
        builder->append(kLastKnownCommittedOpTimeFieldName, localObject);
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest GetMoreCommandRequest::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasCollection && _hasDbName);

        builder->append(kCommandParameterFieldName, _commandParameter);
        builder->append(kCollectionFieldName, _collection);

        if (_batchSize.is_initialized()) {
            builder->append(kBatchSizeFieldName, _batchSize.get());
        }

        if (_maxTimeMS.is_initialized()) {
            builder->append(kMaxTimeMSFieldName, _maxTimeMS.get());
        }

        if (_term.is_initialized()) {
            builder->append(kTermFieldName, _term.get());
        }

        if (_lastKnownCommittedOpTime.is_initialized()) {
            const BSONObj localObject = _lastKnownCommittedOpTime.get().toBSON();
            builder->append(kLastKnownCommittedOpTimeFieldName, localObject);
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj GetMoreCommandRequest::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
