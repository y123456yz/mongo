/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/commands/list_databases_gen.h --output build/opt/mongo/db/commands/list_databases_gen.cpp src/mongo/db/commands/list_databases.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/commands/list_databases_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData ListDatabasesReplyItem::kEmptyFieldName;
constexpr StringData ListDatabasesReplyItem::kNameFieldName;
constexpr StringData ListDatabasesReplyItem::kShardsFieldName;
constexpr StringData ListDatabasesReplyItem::kSizeOnDiskFieldName;


ListDatabasesReplyItem::ListDatabasesReplyItem() : _name(mongo::idl::preparsedValue<decltype(_name)>()), _hasName(false) {
    // Used for initialization only
}
ListDatabasesReplyItem::ListDatabasesReplyItem(std::string name) : _name(std::move(name)), _hasName(true) {
    // Used for initialization only
}


ListDatabasesReplyItem ListDatabasesReplyItem::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ListDatabasesReplyItem>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ListDatabasesReplyItem::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<4> usedFields;
    const size_t kNameBit = 0;
    const size_t kSizeOnDiskBit = 1;
    const size_t kEmptyBit = 2;
    const size_t kShardsBit = 3;

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
        else if (fieldName == kSizeOnDiskFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kSizeOnDiskBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSizeOnDiskBit);

                _sizeOnDisk = element._numberLong();
            }
        }
        else if (fieldName == kEmptyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kEmptyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kEmptyBit);

                _empty = element.boolean();
            }
        }
        else if (fieldName == kShardsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kShardsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kShardsBit);

                const BSONObj localObject = element.Obj();
                _shards = BSONObj::getOwned(localObject);
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
    }

}


void ListDatabasesReplyItem::serialize(BSONObjBuilder* builder) const {
    invariant(_hasName);

    builder->append(kNameFieldName, _name);

    if (_sizeOnDisk.is_initialized()) {
        builder->append(kSizeOnDiskFieldName, _sizeOnDisk.get());
    }

    if (_empty.is_initialized()) {
        builder->append(kEmptyFieldName, _empty.get());
    }

    if (_shards.is_initialized()) {
        builder->append(kShardsFieldName, _shards.get());
    }

}


BSONObj ListDatabasesReplyItem::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData ListDatabasesReply::kDatabasesFieldName;
constexpr StringData ListDatabasesReply::kTotalSizeFieldName;
constexpr StringData ListDatabasesReply::kTotalSizeMbFieldName;


ListDatabasesReply::ListDatabasesReply() : _hasDatabases(false) {
    // Used for initialization only
}
ListDatabasesReply::ListDatabasesReply(std::vector<mongo::ListDatabasesReplyItem> databases) : _databases(std::move(databases)), _hasDatabases(true) {
    // Used for initialization only
}


ListDatabasesReply ListDatabasesReply::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ListDatabasesReply>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ListDatabasesReply::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<3> usedFields;
    const size_t kDatabasesBit = 0;
    const size_t kTotalSizeBit = 1;
    const size_t kTotalSizeMbBit = 2;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kDatabasesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kDatabasesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDatabasesBit);

                _hasDatabases = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kDatabasesFieldName, &ctxt);
            std::vector<mongo::ListDatabasesReplyItem> values;

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
                        IDLParserErrorContext tempContext(kDatabasesFieldName, &ctxt);
                        const auto localObject = arrayElement.Obj();
                        values.emplace_back(mongo::ListDatabasesReplyItem::parse(tempContext, localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _databases = std::move(values);
        }
        else if (fieldName == kTotalSizeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kTotalSizeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTotalSizeBit);

                _totalSize = element._numberLong();
            }
        }
        else if (fieldName == kTotalSizeMbFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kTotalSizeMbBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTotalSizeMbBit);

                _totalSizeMb = element._numberLong();
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kDatabasesBit]) {
            ctxt.throwMissingField(kDatabasesFieldName);
        }
    }

}


void ListDatabasesReply::serialize(BSONObjBuilder* builder) const {
    invariant(_hasDatabases);

    {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kDatabasesFieldName));
        for (const auto& item : _databases) {
            BSONObjBuilder subObjBuilder(arrayBuilder.subobjStart());
            item.serialize(&subObjBuilder);
        }
    }

    if (_totalSize.is_initialized()) {
        builder->append(kTotalSizeFieldName, _totalSize.get());
    }

    if (_totalSizeMb.is_initialized()) {
        builder->append(kTotalSizeMbFieldName, _totalSizeMb.get());
    }

}


BSONObj ListDatabasesReply::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData ListDatabasesCommand::kAuthorizedDatabasesFieldName;
constexpr StringData ListDatabasesCommand::kDbNameFieldName;
constexpr StringData ListDatabasesCommand::kFilterFieldName;
constexpr StringData ListDatabasesCommand::kNameOnlyFieldName;
constexpr StringData ListDatabasesCommand::kCommandName;

mongo::AuthorizationContract ListDatabasesCommand::kAuthorizationContract = AuthorizationContract(std::initializer_list<AccessCheckEnum>{AccessCheckEnum::kIsAuthorizedForAnyActionOnAnyResourceInDB}, std::initializer_list<Privilege>{Privilege(ResourcePattern::forAuthorizationContract(MatchTypeEnum::kMatchClusterResource), ActionSet{ActionType::listDatabases})});

const std::vector<StringData> ListDatabasesCommand::_knownBSONFields {
    ListDatabasesCommand::kAuthorizedDatabasesFieldName,
    ListDatabasesCommand::kFilterFieldName,
    ListDatabasesCommand::kNameOnlyFieldName,
    ListDatabasesCommand::kCommandName,
};
const std::vector<StringData> ListDatabasesCommand::_knownOP_MSGFields {
    ListDatabasesCommand::kAuthorizedDatabasesFieldName,
    ListDatabasesCommand::kDbNameFieldName,
    ListDatabasesCommand::kFilterFieldName,
    ListDatabasesCommand::kNameOnlyFieldName,
    ListDatabasesCommand::kCommandName,
};

ListDatabasesCommand::ListDatabasesCommand() : _hasDbName(false) {
    // Used for initialization only
}


ListDatabasesCommand ListDatabasesCommand::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ListDatabasesCommand>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ListDatabasesCommand::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<4> usedFields;
    const size_t kNameOnlyBit = 0;
    const size_t kAuthorizedDatabasesBit = 1;
    const size_t kFilterBit = 2;
    const size_t kDbNameBit = 3;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kNameOnlyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kNameOnlyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNameOnlyBit);

                _nameOnly = element.trueValue();
            }
        }
        else if (fieldName == kAuthorizedDatabasesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kAuthorizedDatabasesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAuthorizedDatabasesBit);

                _authorizedDatabases = element.boolean();
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
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

}

ListDatabasesCommand ListDatabasesCommand::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto object = mongo::idl::preparsedValue<ListDatabasesCommand>();
    object.parseProtected(ctxt, request);
    return object;
}
void ListDatabasesCommand::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<4> usedFields;
    const size_t kNameOnlyBit = 0;
    const size_t kAuthorizedDatabasesBit = 1;
    const size_t kFilterBit = 2;
    const size_t kDbNameBit = 3;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kNameOnlyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kNameOnlyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNameOnlyBit);

                _nameOnly = element.trueValue();
            }
        }
        else if (fieldName == kAuthorizedDatabasesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kAuthorizedDatabasesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAuthorizedDatabasesBit);

                _authorizedDatabases = element.boolean();
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
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

}

void ListDatabasesCommand::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    builder->append("listDatabases"_sd, 1);
    builder->append(kNameOnlyFieldName, _nameOnly);

    if (_authorizedDatabases.is_initialized()) {
        builder->append(kAuthorizedDatabasesFieldName, _authorizedDatabases.get());
    }

    if (_filter.is_initialized()) {
        builder->append(kFilterFieldName, _filter.get());
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest ListDatabasesCommand::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        builder->append("listDatabases"_sd, 1);
        builder->append(kNameOnlyFieldName, _nameOnly);

        if (_authorizedDatabases.is_initialized()) {
            builder->append(kAuthorizedDatabasesFieldName, _authorizedDatabases.get());
        }

        if (_filter.is_initialized()) {
            builder->append(kFilterFieldName, _filter.get());
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj ListDatabasesCommand::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
