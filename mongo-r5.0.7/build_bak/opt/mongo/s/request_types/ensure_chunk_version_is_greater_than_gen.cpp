/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/s/request_types/ensure_chunk_version_is_greater_than_gen.h --output build/opt/mongo/s/request_types/ensure_chunk_version_is_greater_than_gen.cpp src/mongo/s/request_types/ensure_chunk_version_is_greater_than.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/s/request_types/ensure_chunk_version_is_greater_than_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData ConfigsvrEnsureChunkVersionIsGreaterThan::kCollectionUUIDFieldName;
constexpr StringData ConfigsvrEnsureChunkVersionIsGreaterThan::kDbNameFieldName;
constexpr StringData ConfigsvrEnsureChunkVersionIsGreaterThan::kMaxKeyFieldName;
constexpr StringData ConfigsvrEnsureChunkVersionIsGreaterThan::kMinKeyFieldName;
constexpr StringData ConfigsvrEnsureChunkVersionIsGreaterThan::kNssFieldName;
constexpr StringData ConfigsvrEnsureChunkVersionIsGreaterThan::kVersionFieldName;
constexpr StringData ConfigsvrEnsureChunkVersionIsGreaterThan::kCommandName;

const std::vector<StringData> ConfigsvrEnsureChunkVersionIsGreaterThan::_knownBSONFields {
    ConfigsvrEnsureChunkVersionIsGreaterThan::kCollectionUUIDFieldName,
    ConfigsvrEnsureChunkVersionIsGreaterThan::kMaxKeyFieldName,
    ConfigsvrEnsureChunkVersionIsGreaterThan::kMinKeyFieldName,
    ConfigsvrEnsureChunkVersionIsGreaterThan::kNssFieldName,
    ConfigsvrEnsureChunkVersionIsGreaterThan::kVersionFieldName,
    ConfigsvrEnsureChunkVersionIsGreaterThan::kCommandName,
};
const std::vector<StringData> ConfigsvrEnsureChunkVersionIsGreaterThan::_knownOP_MSGFields {
    ConfigsvrEnsureChunkVersionIsGreaterThan::kCollectionUUIDFieldName,
    ConfigsvrEnsureChunkVersionIsGreaterThan::kDbNameFieldName,
    ConfigsvrEnsureChunkVersionIsGreaterThan::kMaxKeyFieldName,
    ConfigsvrEnsureChunkVersionIsGreaterThan::kMinKeyFieldName,
    ConfigsvrEnsureChunkVersionIsGreaterThan::kNssFieldName,
    ConfigsvrEnsureChunkVersionIsGreaterThan::kVersionFieldName,
    ConfigsvrEnsureChunkVersionIsGreaterThan::kCommandName,
};

ConfigsvrEnsureChunkVersionIsGreaterThan::ConfigsvrEnsureChunkVersionIsGreaterThan() : _minKey(mongo::idl::preparsedValue<decltype(_minKey)>()), _maxKey(mongo::idl::preparsedValue<decltype(_maxKey)>()), _version(mongo::idl::preparsedValue<decltype(_version)>()), _hasMinKey(false), _hasMaxKey(false), _hasVersion(false), _hasDbName(false) {
    // Used for initialization only
}
ConfigsvrEnsureChunkVersionIsGreaterThan::ConfigsvrEnsureChunkVersionIsGreaterThan(mongo::BSONObj minKey, mongo::BSONObj maxKey, mongo::ChunkVersion version) : _minKey(std::move(minKey)), _maxKey(std::move(maxKey)), _version(std::move(version)), _hasMinKey(true), _hasMaxKey(true), _hasVersion(true), _hasDbName(true) {
    // Used for initialization only
}


ConfigsvrEnsureChunkVersionIsGreaterThan ConfigsvrEnsureChunkVersionIsGreaterThan::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ConfigsvrEnsureChunkVersionIsGreaterThan>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ConfigsvrEnsureChunkVersionIsGreaterThan::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<6> usedFields;
    const size_t kMinKeyBit = 0;
    const size_t kMaxKeyBit = 1;
    const size_t kVersionBit = 2;
    const size_t kCollectionUUIDBit = 3;
    const size_t kNssBit = 4;
    const size_t kDbNameBit = 5;
    std::set<StringData> usedFieldSet;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kMinKeyFieldName) {
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
        else if (fieldName == kVersionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kVersionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kVersionBit);

                _hasVersion = true;
                const BSONObj localObject = element.Obj();
                _version = ChunkVersion::fromBSONThrowing(localObject);
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
        else if (fieldName == kNssFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kNssBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNssBit);

                _nss = NamespaceString(element.valueStringData());
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
        if (!usedFields[kMinKeyBit]) {
            ctxt.throwMissingField(kMinKeyFieldName);
        }
        if (!usedFields[kMaxKeyBit]) {
            ctxt.throwMissingField(kMaxKeyFieldName);
        }
        if (!usedFields[kVersionBit]) {
            ctxt.throwMissingField(kVersionFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

}

ConfigsvrEnsureChunkVersionIsGreaterThan ConfigsvrEnsureChunkVersionIsGreaterThan::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto object = mongo::idl::preparsedValue<ConfigsvrEnsureChunkVersionIsGreaterThan>();
    object.parseProtected(ctxt, request);
    return object;
}
void ConfigsvrEnsureChunkVersionIsGreaterThan::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<6> usedFields;
    const size_t kMinKeyBit = 0;
    const size_t kMaxKeyBit = 1;
    const size_t kVersionBit = 2;
    const size_t kCollectionUUIDBit = 3;
    const size_t kNssBit = 4;
    const size_t kDbNameBit = 5;
    std::set<StringData> usedFieldSet;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kMinKeyFieldName) {
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
        else if (fieldName == kVersionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kVersionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kVersionBit);

                _hasVersion = true;
                const BSONObj localObject = element.Obj();
                _version = ChunkVersion::fromBSONThrowing(localObject);
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
        else if (fieldName == kNssFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kNssBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNssBit);

                _nss = NamespaceString(element.valueStringData());
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
        if (!usedFields[kMinKeyBit]) {
            ctxt.throwMissingField(kMinKeyFieldName);
        }
        if (!usedFields[kMaxKeyBit]) {
            ctxt.throwMissingField(kMaxKeyFieldName);
        }
        if (!usedFields[kVersionBit]) {
            ctxt.throwMissingField(kVersionFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

}

void ConfigsvrEnsureChunkVersionIsGreaterThan::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasMinKey && _hasMaxKey && _hasVersion && _hasDbName);

    builder->append("_configsvrEnsureChunkVersionIsGreaterThan"_sd, 1);
    builder->append(kMinKeyFieldName, _minKey);

    builder->append(kMaxKeyFieldName, _maxKey);

    {
        const BSONObj localObject = _version.toBSON();
        builder->append(kVersionFieldName, localObject);
    }

    if (_collectionUUID.is_initialized()) {
        ConstDataRange tempCDR = _collectionUUID.get().toCDR();
        builder->append(kCollectionUUIDFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    if (_nss.is_initialized()) {
        builder->append(kNssFieldName, _nss.get().toString());
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest ConfigsvrEnsureChunkVersionIsGreaterThan::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasMinKey && _hasMaxKey && _hasVersion && _hasDbName);

        builder->append("_configsvrEnsureChunkVersionIsGreaterThan"_sd, 1);
        builder->append(kMinKeyFieldName, _minKey);

        builder->append(kMaxKeyFieldName, _maxKey);

        {
            const BSONObj localObject = _version.toBSON();
            builder->append(kVersionFieldName, localObject);
        }

        if (_collectionUUID.is_initialized()) {
            ConstDataRange tempCDR = _collectionUUID.get().toCDR();
            builder->append(kCollectionUUIDFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
        }

        if (_nss.is_initialized()) {
            builder->append(kNssFieldName, _nss.get().toString());
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj ConfigsvrEnsureChunkVersionIsGreaterThan::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
