/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/s/request_types/auto_split_vector_gen.h --output build/opt/mongo/s/request_types/auto_split_vector_gen.cpp src/mongo/s/request_types/auto_split_vector.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/s/request_types/auto_split_vector_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData AutoSplitVectorResponse::kSplitKeysFieldName;


AutoSplitVectorResponse::AutoSplitVectorResponse() : _splitKeys(mongo::idl::preparsedValue<decltype(_splitKeys)>()), _hasSplitKeys(false) {
    // Used for initialization only
}
AutoSplitVectorResponse::AutoSplitVectorResponse(std::vector<mongo::BSONObj> splitKeys) : _splitKeys(std::move(splitKeys)), _hasSplitKeys(true) {
    // Used for initialization only
}


AutoSplitVectorResponse AutoSplitVectorResponse::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<AutoSplitVectorResponse>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void AutoSplitVectorResponse::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kSplitKeysBit = 0;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kSplitKeysFieldName) {
            if (MONGO_unlikely(usedFields[kSplitKeysBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kSplitKeysBit);

            _hasSplitKeys = true;
            _splitKeys = parseSplitKeys(element);
        }
        else {
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kSplitKeysBit]) {
            ctxt.throwMissingField(kSplitKeysFieldName);
        }
    }

}


void AutoSplitVectorResponse::serialize(BSONObjBuilder* builder) const {
    invariant(_hasSplitKeys);

    builder->append(kSplitKeysFieldName, _splitKeys);

}


BSONObj AutoSplitVectorResponse::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData AutoSplitVectorRequest::kDbNameFieldName;
constexpr StringData AutoSplitVectorRequest::kKeyPatternFieldName;
constexpr StringData AutoSplitVectorRequest::kMaxFieldName;
constexpr StringData AutoSplitVectorRequest::kMaxChunkSizeBytesFieldName;
constexpr StringData AutoSplitVectorRequest::kMinFieldName;
constexpr StringData AutoSplitVectorRequest::kCommandName;

const std::vector<StringData> AutoSplitVectorRequest::_knownBSONFields {
    AutoSplitVectorRequest::kKeyPatternFieldName,
    AutoSplitVectorRequest::kMaxFieldName,
    AutoSplitVectorRequest::kMaxChunkSizeBytesFieldName,
    AutoSplitVectorRequest::kMinFieldName,
    AutoSplitVectorRequest::kCommandName,
};
const std::vector<StringData> AutoSplitVectorRequest::_knownOP_MSGFields {
    AutoSplitVectorRequest::kDbNameFieldName,
    AutoSplitVectorRequest::kKeyPatternFieldName,
    AutoSplitVectorRequest::kMaxFieldName,
    AutoSplitVectorRequest::kMaxChunkSizeBytesFieldName,
    AutoSplitVectorRequest::kMinFieldName,
    AutoSplitVectorRequest::kCommandName,
};

AutoSplitVectorRequest::AutoSplitVectorRequest(const NamespaceString nss) : _nss(std::move(nss)), _keyPattern(mongo::idl::preparsedValue<decltype(_keyPattern)>()), _min(mongo::idl::preparsedValue<decltype(_min)>()), _max(mongo::idl::preparsedValue<decltype(_max)>()), _maxChunkSizeBytes(mongo::idl::preparsedValue<decltype(_maxChunkSizeBytes)>()), _dbName(nss.db().toString()), _hasKeyPattern(false), _hasMin(false), _hasMax(false), _hasMaxChunkSizeBytes(false), _hasDbName(true) {
    // Used for initialization only
}
AutoSplitVectorRequest::AutoSplitVectorRequest(const NamespaceString nss, mongo::BSONObj keyPattern, mongo::BSONObj min, mongo::BSONObj max, std::int64_t maxChunkSizeBytes) : _nss(std::move(nss)), _keyPattern(std::move(keyPattern)), _min(std::move(min)), _max(std::move(max)), _maxChunkSizeBytes(std::move(maxChunkSizeBytes)), _dbName(nss.db().toString()), _hasKeyPattern(true), _hasMin(true), _hasMax(true), _hasMaxChunkSizeBytes(true), _hasDbName(true) {
    // Used for initialization only
}


AutoSplitVectorRequest AutoSplitVectorRequest::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    NamespaceString localNS;
    AutoSplitVectorRequest object(localNS);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void AutoSplitVectorRequest::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<5> usedFields;
    const size_t kKeyPatternBit = 0;
    const size_t kMinBit = 1;
    const size_t kMaxBit = 2;
    const size_t kMaxChunkSizeBytesBit = 3;
    const size_t kDbNameBit = 4;
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

        if (fieldName == kKeyPatternFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kKeyPatternBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kKeyPatternBit);

                _hasKeyPattern = true;
                const BSONObj localObject = element.Obj();
                _keyPattern = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kMinFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kMinBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMinBit);

                _hasMin = true;
                const BSONObj localObject = element.Obj();
                _min = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kMaxFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kMaxBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMaxBit);

                _hasMax = true;
                const BSONObj localObject = element.Obj();
                _max = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kMaxChunkSizeBytesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kMaxChunkSizeBytesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMaxChunkSizeBytesBit);

                _hasMaxChunkSizeBytes = true;
                _maxChunkSizeBytes = element.safeNumberLong();
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
        if (!usedFields[kKeyPatternBit]) {
            ctxt.throwMissingField(kKeyPatternFieldName);
        }
        if (!usedFields[kMinBit]) {
            ctxt.throwMissingField(kMinFieldName);
        }
        if (!usedFields[kMaxBit]) {
            ctxt.throwMissingField(kMaxFieldName);
        }
        if (!usedFields[kMaxChunkSizeBytesBit]) {
            ctxt.throwMissingField(kMaxChunkSizeBytesFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

AutoSplitVectorRequest AutoSplitVectorRequest::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    NamespaceString localNS;
    AutoSplitVectorRequest object(localNS);
    object.parseProtected(ctxt, request);
    return object;
}
void AutoSplitVectorRequest::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<5> usedFields;
    const size_t kKeyPatternBit = 0;
    const size_t kMinBit = 1;
    const size_t kMaxBit = 2;
    const size_t kMaxChunkSizeBytesBit = 3;
    const size_t kDbNameBit = 4;
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

        if (fieldName == kKeyPatternFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kKeyPatternBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kKeyPatternBit);

                _hasKeyPattern = true;
                const BSONObj localObject = element.Obj();
                _keyPattern = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kMinFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kMinBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMinBit);

                _hasMin = true;
                const BSONObj localObject = element.Obj();
                _min = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kMaxFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kMaxBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMaxBit);

                _hasMax = true;
                const BSONObj localObject = element.Obj();
                _max = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kMaxChunkSizeBytesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kMaxChunkSizeBytesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMaxChunkSizeBytesBit);

                _hasMaxChunkSizeBytes = true;
                _maxChunkSizeBytes = element.safeNumberLong();
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
        if (!usedFields[kKeyPatternBit]) {
            ctxt.throwMissingField(kKeyPatternFieldName);
        }
        if (!usedFields[kMinBit]) {
            ctxt.throwMissingField(kMinFieldName);
        }
        if (!usedFields[kMaxBit]) {
            ctxt.throwMissingField(kMaxFieldName);
        }
        if (!usedFields[kMaxChunkSizeBytesBit]) {
            ctxt.throwMissingField(kMaxChunkSizeBytesFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

void AutoSplitVectorRequest::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasKeyPattern && _hasMin && _hasMax && _hasMaxChunkSizeBytes && _hasDbName);

    invariant(!_nss.isEmpty());
    builder->append("autoSplitVector"_sd, _nss.coll());

    builder->append(kKeyPatternFieldName, _keyPattern);

    builder->append(kMinFieldName, _min);

    builder->append(kMaxFieldName, _max);

    builder->append(kMaxChunkSizeBytesFieldName, _maxChunkSizeBytes);

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest AutoSplitVectorRequest::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasKeyPattern && _hasMin && _hasMax && _hasMaxChunkSizeBytes && _hasDbName);

        invariant(!_nss.isEmpty());
        builder->append("autoSplitVector"_sd, _nss.coll());

        builder->append(kKeyPatternFieldName, _keyPattern);

        builder->append(kMinFieldName, _min);

        builder->append(kMaxFieldName, _max);

        builder->append(kMaxChunkSizeBytesFieldName, _maxChunkSizeBytes);

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj AutoSplitVectorRequest::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
