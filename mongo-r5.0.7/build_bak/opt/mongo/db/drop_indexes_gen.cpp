/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/drop_indexes_gen.h --output build/opt/mongo/db/drop_indexes_gen.cpp src/mongo/db/drop_indexes.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/drop_indexes_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData DropIndexesReply::kMsgFieldName;
constexpr StringData DropIndexesReply::kNIndexesWasFieldName;


DropIndexesReply::DropIndexesReply()  {
    // Used for initialization only
}


DropIndexesReply DropIndexesReply::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<DropIndexesReply>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void DropIndexesReply::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kNIndexesWasBit = 0;
    const size_t kMsgBit = 1;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kNIndexesWasFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberInt))) {
                if (MONGO_unlikely(usedFields[kNIndexesWasBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNIndexesWasBit);

                _nIndexesWas = element._numberInt();
            }
        }
        else if (fieldName == kMsgFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kMsgBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMsgBit);

                _msg = element.str();
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
    }

}


void DropIndexesReply::serialize(BSONObjBuilder* builder) const {
    if (_nIndexesWas.is_initialized()) {
        builder->append(kNIndexesWasFieldName, _nIndexesWas.get());
    }

    if (_msg.is_initialized()) {
        builder->append(kMsgFieldName, _msg.get());
    }

}


BSONObj DropIndexesReply::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData DropIndexes::kDbNameFieldName;
constexpr StringData DropIndexes::kIndexFieldName;
constexpr StringData DropIndexes::kIsTimeseriesNamespaceFieldName;
constexpr StringData DropIndexes::kCommandName;
constexpr StringData DropIndexes::kCommandAlias;

mongo::AuthorizationContract DropIndexes::kAuthorizationContract = AuthorizationContract(std::initializer_list<AccessCheckEnum>{}, std::initializer_list<Privilege>{Privilege(ResourcePattern::forAuthorizationContract(MatchTypeEnum::kMatchExactNamespace), ActionSet{ActionType::dropIndex})});

const std::vector<StringData> DropIndexes::_knownBSONFields {
    DropIndexes::kIndexFieldName,
    DropIndexes::kIsTimeseriesNamespaceFieldName,
    DropIndexes::kCommandName,
};
const std::vector<StringData> DropIndexes::_knownOP_MSGFields {
    DropIndexes::kDbNameFieldName,
    DropIndexes::kIndexFieldName,
    DropIndexes::kIsTimeseriesNamespaceFieldName,
    DropIndexes::kCommandName,
};

DropIndexes::DropIndexes(const NamespaceString nss) : _nss(std::move(nss)), _index(mongo::idl::preparsedValue<decltype(_index)>()), _dbName(nss.db().toString()), _hasIndex(false), _hasDbName(true) {
    // Used for initialization only
}
DropIndexes::DropIndexes(const NamespaceString nss, stdx::variant<std::string, std::vector<std::string>, mongo::BSONObj> index) : _nss(std::move(nss)), _index(std::move(index)), _dbName(nss.db().toString()), _hasIndex(true), _hasDbName(true) {
    // Used for initialization only
}


DropIndexes DropIndexes::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    NamespaceString localNS;
    DropIndexes object(localNS);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void DropIndexes::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<3> usedFields;
    const size_t kIndexBit = 0;
    const size_t kIsTimeseriesNamespaceBit = 1;
    const size_t kDbNameBit = 2;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kIndexFieldName) {
            if (MONGO_unlikely(usedFields[kIndexBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kIndexBit);

            _hasIndex = true;

            const BSONType variantType = element.type();
            switch (variantType) {
            case Array:
                if (element.Obj().isEmpty()) {
                    std::uint32_t expectedFieldNumber{0};
                    const IDLParserErrorContext arrayCtxt(kIndexFieldName, &ctxt);
                    std::vector<std::string> values;

                    const BSONObj arrayObject = element.Obj();
                    for (const auto& arrayElement : arrayObject) {
                        const auto arrayFieldName = arrayElement.fieldNameStringData();
                        std::uint32_t fieldNumber;

                        Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                        if (status.isOK()) {
                            if (fieldNumber != expectedFieldNumber) {
                                arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                            }

                            if (arrayCtxt.checkAndAssertType(arrayElement, String)) {
                                values.emplace_back(arrayElement.str());
                            }
                        }
                        else {
                            arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                        }
                        ++expectedFieldNumber;
                    }
                    _index = std::move(values);
                }
                else {
                    const BSONType elemType = element.Obj().firstElement().type();
                    switch (elemType) {
                    case String:
                    {
                        std::uint32_t expectedFieldNumber{0};
                        const IDLParserErrorContext arrayCtxt(kIndexFieldName, &ctxt);
                        std::vector<std::string> values;

                        const BSONObj arrayObject = element.Obj();
                        for (const auto& arrayElement : arrayObject) {
                            const auto arrayFieldName = arrayElement.fieldNameStringData();
                            std::uint32_t fieldNumber;

                            Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                            if (status.isOK()) {
                                if (fieldNumber != expectedFieldNumber) {
                                    arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                                }

                                if (arrayCtxt.checkAndAssertType(arrayElement, String)) {
                                    values.emplace_back(arrayElement.str());
                                }
                            }
                            else {
                                arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                            }
                            ++expectedFieldNumber;
                        }
                        _index = std::move(values);
                        break;
                    }
                    default:
                        ctxt.throwBadType(element, {BSONType::String});
                        break;
                    }
                }
                break;
            case String:
            {
                _index = element.str();
                break;
            }
            case Object:
            {
                _index = element.Obj();
                break;
            }
            default:
                ctxt.throwBadType(element, {BSONType::String, BSONType::Object});
                break;
            }
        }
        else if (fieldName == kIsTimeseriesNamespaceFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kIsTimeseriesNamespaceBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIsTimeseriesNamespaceBit);

                _isTimeseriesNamespace = element.boolean();
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
        if (!usedFields[kIndexBit]) {
            ctxt.throwMissingField(kIndexFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

DropIndexes DropIndexes::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    NamespaceString localNS;
    DropIndexes object(localNS);
    object.parseProtected(ctxt, request);
    return object;
}
void DropIndexes::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<3> usedFields;
    const size_t kIndexBit = 0;
    const size_t kIsTimeseriesNamespaceBit = 1;
    const size_t kDbNameBit = 2;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kIndexFieldName) {
            if (MONGO_unlikely(usedFields[kIndexBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kIndexBit);

            _hasIndex = true;

            const BSONType variantType = element.type();
            switch (variantType) {
            case Array:
                if (element.Obj().isEmpty()) {
                    std::uint32_t expectedFieldNumber{0};
                    const IDLParserErrorContext arrayCtxt(kIndexFieldName, &ctxt);
                    std::vector<std::string> values;

                    const BSONObj arrayObject = element.Obj();
                    for (const auto& arrayElement : arrayObject) {
                        const auto arrayFieldName = arrayElement.fieldNameStringData();
                        std::uint32_t fieldNumber;

                        Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                        if (status.isOK()) {
                            if (fieldNumber != expectedFieldNumber) {
                                arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                            }

                            if (arrayCtxt.checkAndAssertType(arrayElement, String)) {
                                values.emplace_back(arrayElement.str());
                            }
                        }
                        else {
                            arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                        }
                        ++expectedFieldNumber;
                    }
                    _index = std::move(values);
                }
                else {
                    const BSONType elemType = element.Obj().firstElement().type();
                    switch (elemType) {
                    case String:
                    {
                        std::uint32_t expectedFieldNumber{0};
                        const IDLParserErrorContext arrayCtxt(kIndexFieldName, &ctxt);
                        std::vector<std::string> values;

                        const BSONObj arrayObject = element.Obj();
                        for (const auto& arrayElement : arrayObject) {
                            const auto arrayFieldName = arrayElement.fieldNameStringData();
                            std::uint32_t fieldNumber;

                            Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                            if (status.isOK()) {
                                if (fieldNumber != expectedFieldNumber) {
                                    arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                                }

                                if (arrayCtxt.checkAndAssertType(arrayElement, String)) {
                                    values.emplace_back(arrayElement.str());
                                }
                            }
                            else {
                                arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                            }
                            ++expectedFieldNumber;
                        }
                        _index = std::move(values);
                        break;
                    }
                    default:
                        ctxt.throwBadType(element, {BSONType::String});
                        break;
                    }
                }
                break;
            case String:
            {
                _index = element.str();
                break;
            }
            case Object:
            {
                _index = element.Obj();
                break;
            }
            default:
                ctxt.throwBadType(element, {BSONType::String, BSONType::Object});
                break;
            }
        }
        else if (fieldName == kIsTimeseriesNamespaceFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kIsTimeseriesNamespaceBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIsTimeseriesNamespaceBit);

                _isTimeseriesNamespace = element.boolean();
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
        if (!usedFields[kIndexBit]) {
            ctxt.throwMissingField(kIndexFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

void DropIndexes::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasIndex && _hasDbName);

    invariant(!_nss.isEmpty());
    builder->append("dropIndexes"_sd, _nss.coll());

    stdx::visit([builder](auto&& arg) {
        idl::idlSerialize(builder, kIndexFieldName, arg);
    }, _index);

    if (_isTimeseriesNamespace.is_initialized()) {
        builder->append(kIsTimeseriesNamespaceFieldName, _isTimeseriesNamespace.get());
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest DropIndexes::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasIndex && _hasDbName);

        invariant(!_nss.isEmpty());
        builder->append("dropIndexes"_sd, _nss.coll());

        stdx::visit([builder](auto&& arg) {
            idl::idlSerialize(builder, kIndexFieldName, arg);
        }, _index);

        if (_isTimeseriesNamespace.is_initialized()) {
            builder->append(kIsTimeseriesNamespaceFieldName, _isTimeseriesNamespace.get());
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj DropIndexes::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
