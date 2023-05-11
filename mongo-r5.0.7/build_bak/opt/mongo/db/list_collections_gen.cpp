/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/list_collections_gen.h --output build/opt/mongo/db/list_collections_gen.cpp src/mongo/db/list_collections.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/list_collections_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData ListCollectionsReplyInfo::kReadOnlyFieldName;
constexpr StringData ListCollectionsReplyInfo::kUuidFieldName;


ListCollectionsReplyInfo::ListCollectionsReplyInfo()  {
    // Used for initialization only
}


ListCollectionsReplyInfo ListCollectionsReplyInfo::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ListCollectionsReplyInfo>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ListCollectionsReplyInfo::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kReadOnlyBit = 0;
    const size_t kUuidBit = 1;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kReadOnlyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kReadOnlyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kReadOnlyBit);

                _readOnly = element.boolean();
            }
        }
        else if (fieldName == kUuidFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kUuidBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUuidBit);

                _uuid = UUID(uassertStatusOK(UUID::parse(element)));
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
    }

}


void ListCollectionsReplyInfo::serialize(BSONObjBuilder* builder) const {
    if (_readOnly.is_initialized()) {
        builder->append(kReadOnlyFieldName, _readOnly.get());
    }

    if (_uuid.is_initialized()) {
        ConstDataRange tempCDR = _uuid.get().toCDR();
        builder->append(kUuidFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

}


BSONObj ListCollectionsReplyInfo::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData ListCollectionsReplyItem::kIdIndexFieldName;
constexpr StringData ListCollectionsReplyItem::kInfoFieldName;
constexpr StringData ListCollectionsReplyItem::kNameFieldName;
constexpr StringData ListCollectionsReplyItem::kOptionsFieldName;
constexpr StringData ListCollectionsReplyItem::kTypeFieldName;


ListCollectionsReplyItem::ListCollectionsReplyItem() : _name(mongo::idl::preparsedValue<decltype(_name)>()), _type(mongo::idl::preparsedValue<decltype(_type)>()), _hasName(false), _hasType(false) {
    // Used for initialization only
}
ListCollectionsReplyItem::ListCollectionsReplyItem(std::string name, std::string type) : _name(std::move(name)), _type(std::move(type)), _hasName(true), _hasType(true) {
    // Used for initialization only
}


ListCollectionsReplyItem ListCollectionsReplyItem::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ListCollectionsReplyItem>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ListCollectionsReplyItem::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<5> usedFields;
    const size_t kNameBit = 0;
    const size_t kTypeBit = 1;
    const size_t kOptionsBit = 2;
    const size_t kInfoBit = 3;
    const size_t kIdIndexBit = 4;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kNameFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kNameBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNameBit);

                _hasName = true;
                _name = element.str();
            }
        }
        else if (fieldName == kTypeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kTypeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTypeBit);

                _hasType = true;
                _type = element.str();
            }
        }
        else if (fieldName == kOptionsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kOptionsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kOptionsBit);

                const BSONObj localObject = element.Obj();
                _options = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kInfoFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kInfoBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kInfoBit);

                IDLParserErrorContext tempContext(kInfoFieldName, &ctxt);
                const auto localObject = element.Obj();
                _info = mongo::ListCollectionsReplyInfo::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kIdIndexFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kIdIndexBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIdIndexBit);

                const BSONObj localObject = element.Obj();
                _idIndex = BSONObj::getOwned(localObject);
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kNameBit]) {
            ctxt.throwMissingField(kNameFieldName);
        }
        if (!usedFields[kTypeBit]) {
            ctxt.throwMissingField(kTypeFieldName);
        }
    }

}


void ListCollectionsReplyItem::serialize(BSONObjBuilder* builder) const {
    invariant(_hasName && _hasType);

    builder->append(kNameFieldName, _name);

    builder->append(kTypeFieldName, _type);

    if (_options.is_initialized()) {
        builder->append(kOptionsFieldName, _options.get());
    }

    if (_info.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kInfoFieldName));
        _info.get().serialize(&subObjBuilder);
    }

    if (_idIndex.is_initialized()) {
        builder->append(kIdIndexFieldName, _idIndex.get());
    }

}


BSONObj ListCollectionsReplyItem::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData ListCollectionsReplyCursor::kFirstBatchFieldName;
constexpr StringData ListCollectionsReplyCursor::kIdFieldName;
constexpr StringData ListCollectionsReplyCursor::kNsFieldName;


ListCollectionsReplyCursor::ListCollectionsReplyCursor() : _id(mongo::idl::preparsedValue<decltype(_id)>()), _ns(mongo::idl::preparsedValue<decltype(_ns)>()), _hasId(false), _hasNs(false), _hasFirstBatch(false) {
    // Used for initialization only
}
ListCollectionsReplyCursor::ListCollectionsReplyCursor(std::int64_t id, mongo::NamespaceString ns, std::vector<mongo::ListCollectionsReplyItem> firstBatch) : _id(std::move(id)), _ns(std::move(ns)), _firstBatch(std::move(firstBatch)), _hasId(true), _hasNs(true), _hasFirstBatch(true) {
    // Used for initialization only
}


ListCollectionsReplyCursor ListCollectionsReplyCursor::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ListCollectionsReplyCursor>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ListCollectionsReplyCursor::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<3> usedFields;
    const size_t kIdBit = 0;
    const size_t kNsBit = 1;
    const size_t kFirstBatchBit = 2;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIdBit);

                _hasId = true;
                _id = element._numberLong();
            }
        }
        else if (fieldName == kNsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kNsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNsBit);

                _hasNs = true;
                _ns = NamespaceString(element.valueStringData());
            }
        }
        else if (fieldName == kFirstBatchFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kFirstBatchBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kFirstBatchBit);

                _hasFirstBatch = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kFirstBatchFieldName, &ctxt);
            std::vector<mongo::ListCollectionsReplyItem> values;

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
                        IDLParserErrorContext tempContext(kFirstBatchFieldName, &ctxt);
                        const auto localObject = arrayElement.Obj();
                        values.emplace_back(mongo::ListCollectionsReplyItem::parse(tempContext, localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _firstBatch = std::move(values);
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kIdBit]) {
            ctxt.throwMissingField(kIdFieldName);
        }
        if (!usedFields[kNsBit]) {
            ctxt.throwMissingField(kNsFieldName);
        }
        if (!usedFields[kFirstBatchBit]) {
            ctxt.throwMissingField(kFirstBatchFieldName);
        }
    }

}


void ListCollectionsReplyCursor::serialize(BSONObjBuilder* builder) const {
    invariant(_hasId && _hasNs && _hasFirstBatch);

    builder->append(kIdFieldName, _id);

    {
        builder->append(kNsFieldName, _ns.toString());
    }

    {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kFirstBatchFieldName));
        for (const auto& item : _firstBatch) {
            BSONObjBuilder subObjBuilder(arrayBuilder.subobjStart());
            item.serialize(&subObjBuilder);
        }
    }

}


BSONObj ListCollectionsReplyCursor::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData ListCollectionsReply::kCursorFieldName;


ListCollectionsReply::ListCollectionsReply() : _cursor(mongo::idl::preparsedValue<decltype(_cursor)>()), _hasCursor(false) {
    // Used for initialization only
}
ListCollectionsReply::ListCollectionsReply(mongo::ListCollectionsReplyCursor cursor) : _cursor(std::move(cursor)), _hasCursor(true) {
    // Used for initialization only
}


ListCollectionsReply ListCollectionsReply::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ListCollectionsReply>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ListCollectionsReply::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kCursorBit = 0;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kCursorFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCursorBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCursorBit);

                _hasCursor = true;
                IDLParserErrorContext tempContext(kCursorFieldName, &ctxt);
                const auto localObject = element.Obj();
                _cursor = mongo::ListCollectionsReplyCursor::parse(tempContext, localObject);
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kCursorBit]) {
            ctxt.throwMissingField(kCursorFieldName);
        }
    }

}


void ListCollectionsReply::serialize(BSONObjBuilder* builder) const {
    invariant(_hasCursor);

    {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kCursorFieldName));
        _cursor.serialize(&subObjBuilder);
    }

}


BSONObj ListCollectionsReply::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData ListCollections::kAuthorizedCollectionsFieldName;
constexpr StringData ListCollections::kCursorFieldName;
constexpr StringData ListCollections::kDbNameFieldName;
constexpr StringData ListCollections::kFilterFieldName;
constexpr StringData ListCollections::kIncludePendingDropsFieldName;
constexpr StringData ListCollections::kNameOnlyFieldName;
constexpr StringData ListCollections::kCommandName;

mongo::AuthorizationContract ListCollections::kAuthorizationContract = AuthorizationContract(std::initializer_list<AccessCheckEnum>{AccessCheckEnum::kIsAuthorizedForAnyActionOnResource,AccessCheckEnum::kIsAuthorizedForAnyActionOnAnyResourceInDB,AccessCheckEnum::kShouldIgnoreAuthChecks,AccessCheckEnum::kCheckAuthorizedToListCollections}, std::initializer_list<Privilege>{Privilege(ResourcePattern::forAuthorizationContract(MatchTypeEnum::kMatchDatabaseName), ActionSet{ActionType::listCollections})});

const std::vector<StringData> ListCollections::_knownBSONFields {
    ListCollections::kAuthorizedCollectionsFieldName,
    ListCollections::kCursorFieldName,
    ListCollections::kFilterFieldName,
    ListCollections::kIncludePendingDropsFieldName,
    ListCollections::kNameOnlyFieldName,
    ListCollections::kCommandName,
};
const std::vector<StringData> ListCollections::_knownOP_MSGFields {
    ListCollections::kAuthorizedCollectionsFieldName,
    ListCollections::kCursorFieldName,
    ListCollections::kDbNameFieldName,
    ListCollections::kFilterFieldName,
    ListCollections::kIncludePendingDropsFieldName,
    ListCollections::kNameOnlyFieldName,
    ListCollections::kCommandName,
};

ListCollections::ListCollections() : _hasDbName(false) {
    // Used for initialization only
}


ListCollections ListCollections::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ListCollections>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ListCollections::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<6> usedFields;
    const size_t kCursorBit = 0;
    const size_t kFilterBit = 1;
    const size_t kNameOnlyBit = 2;
    const size_t kAuthorizedCollectionsBit = 3;
    const size_t kIncludePendingDropsBit = 4;
    const size_t kDbNameBit = 5;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kCursorFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCursorBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCursorBit);

                IDLParserErrorContext tempContext(kCursorFieldName, &ctxt);
                const auto localObject = element.Obj();
                _cursor = mongo::SimpleCursorOptions::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kFilterFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kFilterBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kFilterBit);

                _filter = element.Obj();
            }
        }
        else if (fieldName == kNameOnlyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kNameOnlyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNameOnlyBit);

                _nameOnly = element.boolean();
            }
        }
        else if (fieldName == kAuthorizedCollectionsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kAuthorizedCollectionsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAuthorizedCollectionsBit);

                _authorizedCollections = element.boolean();
            }
        }
        else if (fieldName == kIncludePendingDropsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kIncludePendingDropsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIncludePendingDropsBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                _includePendingDrops = element.trueValue();
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
        if (!usedFields[kNameOnlyBit]) {
            _nameOnly = false;
        }
        if (!usedFields[kAuthorizedCollectionsBit]) {
            _authorizedCollections = false;
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

}

ListCollections ListCollections::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto object = mongo::idl::preparsedValue<ListCollections>();
    object.parseProtected(ctxt, request);
    return object;
}
void ListCollections::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<6> usedFields;
    const size_t kCursorBit = 0;
    const size_t kFilterBit = 1;
    const size_t kNameOnlyBit = 2;
    const size_t kAuthorizedCollectionsBit = 3;
    const size_t kIncludePendingDropsBit = 4;
    const size_t kDbNameBit = 5;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kCursorFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCursorBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCursorBit);

                IDLParserErrorContext tempContext(kCursorFieldName, &ctxt);
                const auto localObject = element.Obj();
                _cursor = mongo::SimpleCursorOptions::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kFilterFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kFilterBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kFilterBit);

                _filter = element.Obj();
            }
        }
        else if (fieldName == kNameOnlyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kNameOnlyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNameOnlyBit);

                _nameOnly = element.boolean();
            }
        }
        else if (fieldName == kAuthorizedCollectionsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kAuthorizedCollectionsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAuthorizedCollectionsBit);

                _authorizedCollections = element.boolean();
            }
        }
        else if (fieldName == kIncludePendingDropsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kIncludePendingDropsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIncludePendingDropsBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                _includePendingDrops = element.trueValue();
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
        if (!usedFields[kNameOnlyBit]) {
            _nameOnly = false;
        }
        if (!usedFields[kAuthorizedCollectionsBit]) {
            _authorizedCollections = false;
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

}

void ListCollections::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    builder->append("listCollections"_sd, 1);
    if (_cursor.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kCursorFieldName));
        _cursor.get().serialize(&subObjBuilder);
    }

    if (_filter.is_initialized()) {
        builder->append(kFilterFieldName, _filter.get());
    }

    builder->append(kNameOnlyFieldName, _nameOnly);

    builder->append(kAuthorizedCollectionsFieldName, _authorizedCollections);

    if (_includePendingDrops.is_initialized()) {
        builder->append(kIncludePendingDropsFieldName, _includePendingDrops.get());
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest ListCollections::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        builder->append("listCollections"_sd, 1);
        if (_cursor.is_initialized()) {
            BSONObjBuilder subObjBuilder(builder->subobjStart(kCursorFieldName));
            _cursor.get().serialize(&subObjBuilder);
        }

        if (_filter.is_initialized()) {
            builder->append(kFilterFieldName, _filter.get());
        }

        builder->append(kNameOnlyFieldName, _nameOnly);

        builder->append(kAuthorizedCollectionsFieldName, _authorizedCollections);

        if (_includePendingDrops.is_initialized()) {
            builder->append(kIncludePendingDropsFieldName, _includePendingDrops.get());
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj ListCollections::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
