/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/s/request_types/drop_collection_if_uuid_not_matching_gen.h --output build/opt/mongo/s/request_types/drop_collection_if_uuid_not_matching_gen.cpp src/mongo/s/request_types/drop_collection_if_uuid_not_matching.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/s/request_types/drop_collection_if_uuid_not_matching_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData ShardsvrDropCollectionIfUUIDNotMatchingRequest::kDbNameFieldName;
constexpr StringData ShardsvrDropCollectionIfUUIDNotMatchingRequest::kExpectedCollectionUUIDFieldName;
constexpr StringData ShardsvrDropCollectionIfUUIDNotMatchingRequest::kCommandName;

const std::vector<StringData> ShardsvrDropCollectionIfUUIDNotMatchingRequest::_knownBSONFields {
    ShardsvrDropCollectionIfUUIDNotMatchingRequest::kExpectedCollectionUUIDFieldName,
    ShardsvrDropCollectionIfUUIDNotMatchingRequest::kCommandName,
};
const std::vector<StringData> ShardsvrDropCollectionIfUUIDNotMatchingRequest::_knownOP_MSGFields {
    ShardsvrDropCollectionIfUUIDNotMatchingRequest::kDbNameFieldName,
    ShardsvrDropCollectionIfUUIDNotMatchingRequest::kExpectedCollectionUUIDFieldName,
    ShardsvrDropCollectionIfUUIDNotMatchingRequest::kCommandName,
};

ShardsvrDropCollectionIfUUIDNotMatchingRequest::ShardsvrDropCollectionIfUUIDNotMatchingRequest(const NamespaceString nss) : _nss(std::move(nss)), _expectedCollectionUUID(mongo::idl::preparsedValue<decltype(_expectedCollectionUUID)>()), _dbName(nss.db().toString()), _hasExpectedCollectionUUID(false), _hasDbName(true) {
    // Used for initialization only
}
ShardsvrDropCollectionIfUUIDNotMatchingRequest::ShardsvrDropCollectionIfUUIDNotMatchingRequest(const NamespaceString nss, mongo::UUID expectedCollectionUUID) : _nss(std::move(nss)), _expectedCollectionUUID(std::move(expectedCollectionUUID)), _dbName(nss.db().toString()), _hasExpectedCollectionUUID(true), _hasDbName(true) {
    // Used for initialization only
}


ShardsvrDropCollectionIfUUIDNotMatchingRequest ShardsvrDropCollectionIfUUIDNotMatchingRequest::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    NamespaceString localNS;
    ShardsvrDropCollectionIfUUIDNotMatchingRequest object(localNS);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ShardsvrDropCollectionIfUUIDNotMatchingRequest::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kExpectedCollectionUUIDBit = 0;
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

        if (fieldName == kExpectedCollectionUUIDFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kExpectedCollectionUUIDBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kExpectedCollectionUUIDBit);

                _hasExpectedCollectionUUID = true;
                _expectedCollectionUUID = UUID(uassertStatusOK(UUID::parse(element)));
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
        if (!usedFields[kExpectedCollectionUUIDBit]) {
            ctxt.throwMissingField(kExpectedCollectionUUIDFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

ShardsvrDropCollectionIfUUIDNotMatchingRequest ShardsvrDropCollectionIfUUIDNotMatchingRequest::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    NamespaceString localNS;
    ShardsvrDropCollectionIfUUIDNotMatchingRequest object(localNS);
    object.parseProtected(ctxt, request);
    return object;
}
void ShardsvrDropCollectionIfUUIDNotMatchingRequest::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<2> usedFields;
    const size_t kExpectedCollectionUUIDBit = 0;
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

        if (fieldName == kExpectedCollectionUUIDFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kExpectedCollectionUUIDBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kExpectedCollectionUUIDBit);

                _hasExpectedCollectionUUID = true;
                _expectedCollectionUUID = UUID(uassertStatusOK(UUID::parse(element)));
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
        if (!usedFields[kExpectedCollectionUUIDBit]) {
            ctxt.throwMissingField(kExpectedCollectionUUIDFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

void ShardsvrDropCollectionIfUUIDNotMatchingRequest::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasExpectedCollectionUUID && _hasDbName);

    invariant(!_nss.isEmpty());
    builder->append("_shardsvrDropCollectionIfUUIDNotMatching"_sd, _nss.coll());

    {
        ConstDataRange tempCDR = _expectedCollectionUUID.toCDR();
        builder->append(kExpectedCollectionUUIDFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest ShardsvrDropCollectionIfUUIDNotMatchingRequest::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasExpectedCollectionUUID && _hasDbName);

        invariant(!_nss.isEmpty());
        builder->append("_shardsvrDropCollectionIfUUIDNotMatching"_sd, _nss.coll());

        {
            ConstDataRange tempCDR = _expectedCollectionUUID.toCDR();
            builder->append(kExpectedCollectionUUIDFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj ShardsvrDropCollectionIfUUIDNotMatchingRequest::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
