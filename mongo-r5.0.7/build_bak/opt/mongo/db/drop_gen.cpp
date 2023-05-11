/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/drop_gen.h --output build/opt/mongo/db/drop_gen.cpp src/mongo/db/drop.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/drop_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData DropReply::kInfoFieldName;
constexpr StringData DropReply::kNIndexesWasFieldName;
constexpr StringData DropReply::kNsFieldName;
constexpr StringData DropReply::kOkFieldName;


DropReply::DropReply()  {
    // Used for initialization only
}


DropReply DropReply::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<DropReply>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void DropReply::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<4> usedFields;
    const size_t kNIndexesWasBit = 0;
    const size_t kNsBit = 1;
    const size_t kInfoBit = 2;
    const size_t kOkBit = 3;

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
        else if (fieldName == kNsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kNsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNsBit);

                _ns = NamespaceString(element.valueStringData());
            }
        }
        else if (fieldName == kInfoFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kInfoBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kInfoBit);

                _info = element.str();
            }
        }
        else if (fieldName == kOkFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kOkBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kOkBit);

                _ok = element.safeNumberDouble();
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
    }

}


void DropReply::serialize(BSONObjBuilder* builder) const {
    if (_nIndexesWas.is_initialized()) {
        builder->append(kNIndexesWasFieldName, _nIndexesWas.get());
    }

    if (_ns.is_initialized()) {
        builder->append(kNsFieldName, _ns.get().toString());
    }

    if (_info.is_initialized()) {
        builder->append(kInfoFieldName, _info.get());
    }

    if (_ok.is_initialized()) {
        builder->append(kOkFieldName, _ok.get());
    }

}


BSONObj DropReply::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData Drop::kDbNameFieldName;
constexpr StringData Drop::kCommandName;

mongo::AuthorizationContract Drop::kAuthorizationContract = AuthorizationContract(std::initializer_list<AccessCheckEnum>{}, std::initializer_list<Privilege>{Privilege(ResourcePattern::forAuthorizationContract(MatchTypeEnum::kMatchExactNamespace), ActionSet{ActionType::dropCollection})});

const std::vector<StringData> Drop::_knownBSONFields {
    Drop::kCommandName,
};
const std::vector<StringData> Drop::_knownOP_MSGFields {
    Drop::kDbNameFieldName,
    Drop::kCommandName,
};

Drop::Drop(const NamespaceString nss) : _nss(std::move(nss)), _dbName(nss.db().toString()), _hasDbName(true) {
    // Used for initialization only
}


Drop Drop::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    NamespaceString localNS;
    Drop object(localNS);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void Drop::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kDbNameBit = 0;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kDbNameFieldName) {
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
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

Drop Drop::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    NamespaceString localNS;
    Drop object(localNS);
    object.parseProtected(ctxt, request);
    return object;
}
void Drop::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<1> usedFields;
    const size_t kDbNameBit = 0;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kDbNameFieldName) {
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
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

void Drop::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    invariant(!_nss.isEmpty());
    builder->append("drop"_sd, _nss.coll());

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest Drop::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        invariant(!_nss.isEmpty());
        builder->append("drop"_sd, _nss.coll());

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj Drop::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
