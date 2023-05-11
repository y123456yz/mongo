/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/query/kill_cursors_gen.h --output build/opt/mongo/db/query/kill_cursors_gen.cpp src/mongo/db/query/kill_cursors.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/query/kill_cursors_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData KillCursorsCommandReply::kCursorsAliveFieldName;
constexpr StringData KillCursorsCommandReply::kCursorsKilledFieldName;
constexpr StringData KillCursorsCommandReply::kCursorsNotFoundFieldName;
constexpr StringData KillCursorsCommandReply::kCursorsUnknownFieldName;


KillCursorsCommandReply::KillCursorsCommandReply() : _hasCursorsKilled(false), _hasCursorsNotFound(false), _hasCursorsAlive(false), _hasCursorsUnknown(false) {
    // Used for initialization only
}
KillCursorsCommandReply::KillCursorsCommandReply(std::vector<mongo::CursorId> cursorsKilled, std::vector<mongo::CursorId> cursorsNotFound, std::vector<mongo::CursorId> cursorsAlive, std::vector<mongo::CursorId> cursorsUnknown) : _cursorsKilled(std::move(cursorsKilled)), _cursorsNotFound(std::move(cursorsNotFound)), _cursorsAlive(std::move(cursorsAlive)), _cursorsUnknown(std::move(cursorsUnknown)), _hasCursorsKilled(true), _hasCursorsNotFound(true), _hasCursorsAlive(true), _hasCursorsUnknown(true) {
    // Used for initialization only
}


KillCursorsCommandReply KillCursorsCommandReply::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<KillCursorsCommandReply>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void KillCursorsCommandReply::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<4> usedFields;
    const size_t kCursorsKilledBit = 0;
    const size_t kCursorsNotFoundBit = 1;
    const size_t kCursorsAliveBit = 2;
    const size_t kCursorsUnknownBit = 3;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kCursorsKilledFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kCursorsKilledBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCursorsKilledBit);

                _hasCursorsKilled = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kCursorsKilledFieldName, &ctxt);
            std::vector<mongo::CursorId> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, NumberLong)) {
                        values.emplace_back(arrayElement._numberLong());
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _cursorsKilled = std::move(values);
        }
        else if (fieldName == kCursorsNotFoundFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kCursorsNotFoundBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCursorsNotFoundBit);

                _hasCursorsNotFound = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kCursorsNotFoundFieldName, &ctxt);
            std::vector<mongo::CursorId> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, NumberLong)) {
                        values.emplace_back(arrayElement._numberLong());
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _cursorsNotFound = std::move(values);
        }
        else if (fieldName == kCursorsAliveFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kCursorsAliveBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCursorsAliveBit);

                _hasCursorsAlive = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kCursorsAliveFieldName, &ctxt);
            std::vector<mongo::CursorId> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, NumberLong)) {
                        values.emplace_back(arrayElement._numberLong());
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _cursorsAlive = std::move(values);
        }
        else if (fieldName == kCursorsUnknownFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kCursorsUnknownBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCursorsUnknownBit);

                _hasCursorsUnknown = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kCursorsUnknownFieldName, &ctxt);
            std::vector<mongo::CursorId> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, NumberLong)) {
                        values.emplace_back(arrayElement._numberLong());
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _cursorsUnknown = std::move(values);
        }
        else {
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kCursorsKilledBit]) {
            ctxt.throwMissingField(kCursorsKilledFieldName);
        }
        if (!usedFields[kCursorsNotFoundBit]) {
            ctxt.throwMissingField(kCursorsNotFoundFieldName);
        }
        if (!usedFields[kCursorsAliveBit]) {
            ctxt.throwMissingField(kCursorsAliveFieldName);
        }
        if (!usedFields[kCursorsUnknownBit]) {
            ctxt.throwMissingField(kCursorsUnknownFieldName);
        }
    }

}


void KillCursorsCommandReply::serialize(BSONObjBuilder* builder) const {
    invariant(_hasCursorsKilled && _hasCursorsNotFound && _hasCursorsAlive && _hasCursorsUnknown);

    {
        builder->append(kCursorsKilledFieldName, _cursorsKilled);
    }

    {
        builder->append(kCursorsNotFoundFieldName, _cursorsNotFound);
    }

    {
        builder->append(kCursorsAliveFieldName, _cursorsAlive);
    }

    {
        builder->append(kCursorsUnknownFieldName, _cursorsUnknown);
    }

}


BSONObj KillCursorsCommandReply::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData KillCursorsCommandRequest::kCursorIdsFieldName;
constexpr StringData KillCursorsCommandRequest::kDbNameFieldName;
constexpr StringData KillCursorsCommandRequest::kCommandName;

mongo::AuthorizationContract KillCursorsCommandRequest::kAuthorizationContract = AuthorizationContract(std::initializer_list<AccessCheckEnum>{AccessCheckEnum::kIsCoauthorizedWith}, std::initializer_list<Privilege>{Privilege(ResourcePattern::forAuthorizationContract(MatchTypeEnum::kMatchClusterResource), ActionSet{ActionType::killAnyCursor}),Privilege(ResourcePattern::forAuthorizationContract(MatchTypeEnum::kMatchDatabaseName), ActionSet{ActionType::killAnyCursor}),Privilege(ResourcePattern::forAuthorizationContract(MatchTypeEnum::kMatchExactNamespace), ActionSet{ActionType::killAnyCursor})});

const std::vector<StringData> KillCursorsCommandRequest::_knownBSONFields {
    KillCursorsCommandRequest::kCursorIdsFieldName,
    KillCursorsCommandRequest::kCommandName,
};
const std::vector<StringData> KillCursorsCommandRequest::_knownOP_MSGFields {
    KillCursorsCommandRequest::kCursorIdsFieldName,
    KillCursorsCommandRequest::kDbNameFieldName,
    KillCursorsCommandRequest::kCommandName,
};

KillCursorsCommandRequest::KillCursorsCommandRequest(const NamespaceString nss) : _nss(std::move(nss)), _dbName(nss.db().toString()), _hasCursorIds(false), _hasDbName(true) {
    // Used for initialization only
}
KillCursorsCommandRequest::KillCursorsCommandRequest(const NamespaceString nss, std::vector<mongo::CursorId> cursorIds) : _nss(std::move(nss)), _cursorIds(std::move(cursorIds)), _dbName(nss.db().toString()), _hasCursorIds(true), _hasDbName(true) {
    // Used for initialization only
}


KillCursorsCommandRequest KillCursorsCommandRequest::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    NamespaceString localNS;
    KillCursorsCommandRequest object(localNS);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void KillCursorsCommandRequest::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kCursorIdsBit = 0;
    const size_t kDbNameBit = 1;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kCursorIdsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kCursorIdsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCursorIdsBit);

                _hasCursorIds = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kCursorIdsFieldName, &ctxt);
            std::vector<mongo::CursorId> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, NumberLong)) {
                        values.emplace_back(arrayElement._numberLong());
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _cursorIds = std::move(values);
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
        if (!usedFields[kCursorIdsBit]) {
            ctxt.throwMissingField(kCursorIdsFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

KillCursorsCommandRequest KillCursorsCommandRequest::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    NamespaceString localNS;
    KillCursorsCommandRequest object(localNS);
    object.parseProtected(ctxt, request);
    return object;
}
void KillCursorsCommandRequest::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<2> usedFields;
    const size_t kCursorIdsBit = 0;
    const size_t kDbNameBit = 1;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kCursorIdsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kCursorIdsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCursorIdsBit);

                _hasCursorIds = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kCursorIdsFieldName, &ctxt);
            std::vector<mongo::CursorId> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, NumberLong)) {
                        values.emplace_back(arrayElement._numberLong());
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _cursorIds = std::move(values);
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
        if (!usedFields[kCursorIdsBit]) {
            ctxt.throwMissingField(kCursorIdsFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

void KillCursorsCommandRequest::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasCursorIds && _hasDbName);

    invariant(!_nss.isEmpty());
    builder->append("killCursors"_sd, _nss.coll());

    {
        builder->append(kCursorIdsFieldName, _cursorIds);
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest KillCursorsCommandRequest::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasCursorIds && _hasDbName);

        invariant(!_nss.isEmpty());
        builder->append("killCursors"_sd, _nss.coll());

        {
            builder->append(kCursorIdsFieldName, _cursorIds);
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj KillCursorsCommandRequest::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
