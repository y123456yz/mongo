/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/s/remove_chunks_gen.h --output build/opt/mongo/db/s/remove_chunks_gen.cpp src/mongo/db/s/remove_chunks.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/s/remove_chunks_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData ConfigsvrRemoveChunks::kCollectionUUIDFieldName;
constexpr StringData ConfigsvrRemoveChunks::kDbNameFieldName;
constexpr StringData ConfigsvrRemoveChunks::kCommandName;

const std::vector<StringData> ConfigsvrRemoveChunks::_knownBSONFields {
    ConfigsvrRemoveChunks::kCollectionUUIDFieldName,
    ConfigsvrRemoveChunks::kCommandName,
};
const std::vector<StringData> ConfigsvrRemoveChunks::_knownOP_MSGFields {
    ConfigsvrRemoveChunks::kCollectionUUIDFieldName,
    ConfigsvrRemoveChunks::kDbNameFieldName,
    ConfigsvrRemoveChunks::kCommandName,
};

ConfigsvrRemoveChunks::ConfigsvrRemoveChunks() : _collectionUUID(mongo::idl::preparsedValue<decltype(_collectionUUID)>()), _hasCollectionUUID(false), _hasDbName(false) {
    // Used for initialization only
}
ConfigsvrRemoveChunks::ConfigsvrRemoveChunks(mongo::UUID collectionUUID) : _collectionUUID(std::move(collectionUUID)), _hasCollectionUUID(true), _hasDbName(true) {
    // Used for initialization only
}


ConfigsvrRemoveChunks ConfigsvrRemoveChunks::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ConfigsvrRemoveChunks>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ConfigsvrRemoveChunks::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kCollectionUUIDBit = 0;
    const size_t kDbNameBit = 1;
    std::set<StringData> usedFieldSet;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kCollectionUUIDFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kCollectionUUIDBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollectionUUIDBit);

                _hasCollectionUUID = true;
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
        if (!usedFields[kCollectionUUIDBit]) {
            ctxt.throwMissingField(kCollectionUUIDFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

}

ConfigsvrRemoveChunks ConfigsvrRemoveChunks::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto object = mongo::idl::preparsedValue<ConfigsvrRemoveChunks>();
    object.parseProtected(ctxt, request);
    return object;
}
void ConfigsvrRemoveChunks::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<2> usedFields;
    const size_t kCollectionUUIDBit = 0;
    const size_t kDbNameBit = 1;
    std::set<StringData> usedFieldSet;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kCollectionUUIDFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kCollectionUUIDBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollectionUUIDBit);

                _hasCollectionUUID = true;
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
        if (!usedFields[kCollectionUUIDBit]) {
            ctxt.throwMissingField(kCollectionUUIDFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

}

void ConfigsvrRemoveChunks::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasCollectionUUID && _hasDbName);

    builder->append("_configsvrRemoveChunks"_sd, 1);
    {
        ConstDataRange tempCDR = _collectionUUID.toCDR();
        builder->append(kCollectionUUIDFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest ConfigsvrRemoveChunks::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasCollectionUUID && _hasDbName);

        builder->append("_configsvrRemoveChunks"_sd, 1);
        {
            ConstDataRange tempCDR = _collectionUUID.toCDR();
            builder->append(kCollectionUUIDFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj ConfigsvrRemoveChunks::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
