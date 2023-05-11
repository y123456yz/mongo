/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/commands/validate_db_metadata_gen.h --output build/opt/mongo/db/commands/validate_db_metadata_gen.cpp src/mongo/db/commands/validate_db_metadata.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/commands/validate_db_metadata_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData ErrorReplyElement::kCodeFieldName;
constexpr StringData ErrorReplyElement::kCodeNameFieldName;
constexpr StringData ErrorReplyElement::kErrmsgFieldName;
constexpr StringData ErrorReplyElement::kNsFieldName;
constexpr StringData ErrorReplyElement::kShardFieldName;


ErrorReplyElement::ErrorReplyElement() : _ns(mongo::idl::preparsedValue<decltype(_ns)>()), _code(mongo::idl::preparsedValue<decltype(_code)>()), _codeName(mongo::idl::preparsedValue<decltype(_codeName)>()), _errmsg(mongo::idl::preparsedValue<decltype(_errmsg)>()), _hasNs(false), _hasCode(false), _hasCodeName(false), _hasErrmsg(false) {
    // Used for initialization only
}
ErrorReplyElement::ErrorReplyElement(std::string ns, std::int32_t code, std::string codeName, std::string errmsg) : _ns(std::move(ns)), _code(std::move(code)), _codeName(std::move(codeName)), _errmsg(std::move(errmsg)), _hasNs(true), _hasCode(true), _hasCodeName(true), _hasErrmsg(true) {
    // Used for initialization only
}


ErrorReplyElement ErrorReplyElement::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ErrorReplyElement>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ErrorReplyElement::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<5> usedFields;
    const size_t kShardBit = 0;
    const size_t kNsBit = 1;
    const size_t kCodeBit = 2;
    const size_t kCodeNameBit = 3;
    const size_t kErrmsgBit = 4;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kShardFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kShardBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kShardBit);

                _shard = element.str();
            }
        }
        else if (fieldName == kNsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kNsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNsBit);

                _hasNs = true;
                _ns = element.str();
            }
        }
        else if (fieldName == kCodeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberInt))) {
                if (MONGO_unlikely(usedFields[kCodeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCodeBit);

                _hasCode = true;
                _code = element._numberInt();
            }
        }
        else if (fieldName == kCodeNameFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kCodeNameBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCodeNameBit);

                _hasCodeName = true;
                _codeName = element.str();
            }
        }
        else if (fieldName == kErrmsgFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kErrmsgBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kErrmsgBit);

                _hasErrmsg = true;
                _errmsg = element.str();
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kNsBit]) {
            ctxt.throwMissingField(kNsFieldName);
        }
        if (!usedFields[kCodeBit]) {
            ctxt.throwMissingField(kCodeFieldName);
        }
        if (!usedFields[kCodeNameBit]) {
            ctxt.throwMissingField(kCodeNameFieldName);
        }
        if (!usedFields[kErrmsgBit]) {
            ctxt.throwMissingField(kErrmsgFieldName);
        }
    }

}


void ErrorReplyElement::serialize(BSONObjBuilder* builder) const {
    invariant(_hasNs && _hasCode && _hasCodeName && _hasErrmsg);

    if (_shard.is_initialized()) {
        builder->append(kShardFieldName, _shard.get());
    }

    builder->append(kNsFieldName, _ns);

    builder->append(kCodeFieldName, _code);

    builder->append(kCodeNameFieldName, _codeName);

    builder->append(kErrmsgFieldName, _errmsg);

}


BSONObj ErrorReplyElement::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData ValidateDBMetadataCommandReply::kApiVersionErrorsFieldName;
constexpr StringData ValidateDBMetadataCommandReply::kHasMoreErrorsFieldName;


ValidateDBMetadataCommandReply::ValidateDBMetadataCommandReply()  {
    // Used for initialization only
}


ValidateDBMetadataCommandReply ValidateDBMetadataCommandReply::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ValidateDBMetadataCommandReply>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ValidateDBMetadataCommandReply::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kApiVersionErrorsBit = 0;
    const size_t kHasMoreErrorsBit = 1;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kApiVersionErrorsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kApiVersionErrorsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kApiVersionErrorsBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kApiVersionErrorsFieldName, &ctxt);
            std::vector<mongo::ErrorReplyElement> values;

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
                        IDLParserErrorContext tempContext(kApiVersionErrorsFieldName, &ctxt);
                        const auto localObject = arrayElement.Obj();
                        values.emplace_back(mongo::ErrorReplyElement::parse(tempContext, localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _apiVersionErrors = std::move(values);
        }
        else if (fieldName == kHasMoreErrorsFieldName) {
            if (MONGO_unlikely(usedFields[kHasMoreErrorsBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kHasMoreErrorsBit);

            _hasMoreErrors = OptionalBool::parseFromBSON(element);
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kHasMoreErrorsBit]) {
            _hasMoreErrors = mongo::OptionalBool();
        }
    }

}


void ValidateDBMetadataCommandReply::serialize(BSONObjBuilder* builder) const {
    if (_apiVersionErrors.is_initialized()) {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kApiVersionErrorsFieldName));
        for (const auto& item : _apiVersionErrors.get()) {
            BSONObjBuilder subObjBuilder(arrayBuilder.subobjStart());
            item.serialize(&subObjBuilder);
        }
    }

    {
        _hasMoreErrors.serializeToBSON(kHasMoreErrorsFieldName, builder);
    }

}


BSONObj ValidateDBMetadataCommandReply::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData APIParamsForCmd::kDeprecationErrorsFieldName;
constexpr StringData APIParamsForCmd::kStrictFieldName;
constexpr StringData APIParamsForCmd::kVersionFieldName;


APIParamsForCmd::APIParamsForCmd() : _version(mongo::idl::preparsedValue<decltype(_version)>()), _hasVersion(false) {
    // Used for initialization only
}
APIParamsForCmd::APIParamsForCmd(std::string version) : _version(std::move(version)), _hasVersion(true) {
    // Used for initialization only
}


APIParamsForCmd APIParamsForCmd::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<APIParamsForCmd>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void APIParamsForCmd::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<3> usedFields;
    const size_t kVersionBit = 0;
    const size_t kStrictBit = 1;
    const size_t kDeprecationErrorsBit = 2;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kVersionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kVersionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kVersionBit);

                _hasVersion = true;
                _version = element.str();
            }
        }
        else if (fieldName == kStrictFieldName) {
            if (MONGO_unlikely(usedFields[kStrictBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kStrictBit);

            _strict = OptionalBool::parseFromBSON(element);
        }
        else if (fieldName == kDeprecationErrorsFieldName) {
            if (MONGO_unlikely(usedFields[kDeprecationErrorsBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kDeprecationErrorsBit);

            _deprecationErrors = OptionalBool::parseFromBSON(element);
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kVersionBit]) {
            ctxt.throwMissingField(kVersionFieldName);
        }
        if (!usedFields[kStrictBit]) {
            _strict = mongo::OptionalBool();
        }
        if (!usedFields[kDeprecationErrorsBit]) {
            _deprecationErrors = mongo::OptionalBool();
        }
    }

}


void APIParamsForCmd::serialize(BSONObjBuilder* builder) const {
    invariant(_hasVersion);

    builder->append(kVersionFieldName, _version);

    {
        _strict.serializeToBSON(kStrictFieldName, builder);
    }

    {
        _deprecationErrors.serializeToBSON(kDeprecationErrorsFieldName, builder);
    }

}


BSONObj APIParamsForCmd::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData ValidateDBMetadataCommandRequest::kApiParametersFieldName;
constexpr StringData ValidateDBMetadataCommandRequest::kCollectionFieldName;
constexpr StringData ValidateDBMetadataCommandRequest::kDbFieldName;
constexpr StringData ValidateDBMetadataCommandRequest::kDbNameFieldName;
constexpr StringData ValidateDBMetadataCommandRequest::kCommandName;

const std::vector<StringData> ValidateDBMetadataCommandRequest::_knownBSONFields {
    ValidateDBMetadataCommandRequest::kApiParametersFieldName,
    ValidateDBMetadataCommandRequest::kCollectionFieldName,
    ValidateDBMetadataCommandRequest::kDbFieldName,
    ValidateDBMetadataCommandRequest::kCommandName,
};
const std::vector<StringData> ValidateDBMetadataCommandRequest::_knownOP_MSGFields {
    ValidateDBMetadataCommandRequest::kApiParametersFieldName,
    ValidateDBMetadataCommandRequest::kCollectionFieldName,
    ValidateDBMetadataCommandRequest::kDbFieldName,
    ValidateDBMetadataCommandRequest::kDbNameFieldName,
    ValidateDBMetadataCommandRequest::kCommandName,
};

ValidateDBMetadataCommandRequest::ValidateDBMetadataCommandRequest() : _apiParameters(mongo::idl::preparsedValue<decltype(_apiParameters)>()), _hasApiParameters(false), _hasDbName(false) {
    // Used for initialization only
}
ValidateDBMetadataCommandRequest::ValidateDBMetadataCommandRequest(mongo::APIParamsForCmd apiParameters) : _apiParameters(std::move(apiParameters)), _hasApiParameters(true), _hasDbName(true) {
    // Used for initialization only
}


ValidateDBMetadataCommandRequest ValidateDBMetadataCommandRequest::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ValidateDBMetadataCommandRequest>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ValidateDBMetadataCommandRequest::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<4> usedFields;
    const size_t kDbBit = 0;
    const size_t kCollectionBit = 1;
    const size_t kApiParametersBit = 2;
    const size_t kDbNameBit = 3;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kDbFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kDbBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDbBit);

                _db = element.str();
            }
        }
        else if (fieldName == kCollectionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kCollectionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollectionBit);

                _collection = element.str();
            }
        }
        else if (fieldName == kApiParametersFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kApiParametersBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kApiParametersBit);

                _hasApiParameters = true;
                IDLParserErrorContext tempContext(kApiParametersFieldName, &ctxt);
                const auto localObject = element.Obj();
                _apiParameters = mongo::APIParamsForCmd::parse(tempContext, localObject);
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
        if (!usedFields[kApiParametersBit]) {
            ctxt.throwMissingField(kApiParametersFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

}

ValidateDBMetadataCommandRequest ValidateDBMetadataCommandRequest::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto object = mongo::idl::preparsedValue<ValidateDBMetadataCommandRequest>();
    object.parseProtected(ctxt, request);
    return object;
}
void ValidateDBMetadataCommandRequest::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<4> usedFields;
    const size_t kDbBit = 0;
    const size_t kCollectionBit = 1;
    const size_t kApiParametersBit = 2;
    const size_t kDbNameBit = 3;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kDbFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kDbBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDbBit);

                _db = element.str();
            }
        }
        else if (fieldName == kCollectionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kCollectionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollectionBit);

                _collection = element.str();
            }
        }
        else if (fieldName == kApiParametersFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kApiParametersBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kApiParametersBit);

                _hasApiParameters = true;
                IDLParserErrorContext tempContext(kApiParametersFieldName, &ctxt);
                const auto localObject = element.Obj();
                _apiParameters = mongo::APIParamsForCmd::parse(tempContext, localObject);
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
        if (!usedFields[kApiParametersBit]) {
            ctxt.throwMissingField(kApiParametersFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

}

void ValidateDBMetadataCommandRequest::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasApiParameters && _hasDbName);

    builder->append("validateDBMetadata"_sd, 1);
    if (_db.is_initialized()) {
        builder->append(kDbFieldName, _db.get());
    }

    if (_collection.is_initialized()) {
        builder->append(kCollectionFieldName, _collection.get());
    }

    {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kApiParametersFieldName));
        _apiParameters.serialize(&subObjBuilder);
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest ValidateDBMetadataCommandRequest::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasApiParameters && _hasDbName);

        builder->append("validateDBMetadata"_sd, 1);
        if (_db.is_initialized()) {
            builder->append(kDbFieldName, _db.get());
        }

        if (_collection.is_initialized()) {
            builder->append(kCollectionFieldName, _collection.get());
        }

        {
            BSONObjBuilder subObjBuilder(builder->subobjStart(kApiParametersFieldName));
            _apiParameters.serialize(&subObjBuilder);
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj ValidateDBMetadataCommandRequest::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
