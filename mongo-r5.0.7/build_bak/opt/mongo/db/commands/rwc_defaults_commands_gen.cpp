/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/commands/rwc_defaults_commands_gen.h --output build/opt/mongo/db/commands/rwc_defaults_commands_gen.cpp src/mongo/db/commands/rwc_defaults_commands.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/commands/rwc_defaults_commands_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData GetDefaultRWConcernResponse::kRWConcernDefaultFieldName;
constexpr StringData GetDefaultRWConcernResponse::kDefaultReadConcernFieldName;
constexpr StringData GetDefaultRWConcernResponse::kDefaultReadConcernSourceFieldName;
constexpr StringData GetDefaultRWConcernResponse::kDefaultWriteConcernFieldName;
constexpr StringData GetDefaultRWConcernResponse::kDefaultWriteConcernSourceFieldName;
constexpr StringData GetDefaultRWConcernResponse::kInMemoryFieldName;
constexpr StringData GetDefaultRWConcernResponse::kLocalUpdateWallClockTimeFieldName;
constexpr StringData GetDefaultRWConcernResponse::kUpdateOpTimeFieldName;
constexpr StringData GetDefaultRWConcernResponse::kUpdateWallClockTimeFieldName;


GetDefaultRWConcernResponse::GetDefaultRWConcernResponse() : _localUpdateWallClockTime(mongo::idl::preparsedValue<decltype(_localUpdateWallClockTime)>()), _hasLocalUpdateWallClockTime(false) {
    // Used for initialization only
}
GetDefaultRWConcernResponse::GetDefaultRWConcernResponse(mongo::Date_t localUpdateWallClockTime) : _localUpdateWallClockTime(std::move(localUpdateWallClockTime)), _hasLocalUpdateWallClockTime(true) {
    // Used for initialization only
}


GetDefaultRWConcernResponse GetDefaultRWConcernResponse::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<GetDefaultRWConcernResponse>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void GetDefaultRWConcernResponse::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<9> usedFields;
    const size_t kDefaultReadConcernBit = 0;
    const size_t kDefaultWriteConcernBit = 1;
    const size_t kUpdateOpTimeBit = 2;
    const size_t kUpdateWallClockTimeBit = 3;
    const size_t kDefaultWriteConcernSourceBit = 4;
    const size_t kDefaultReadConcernSourceBit = 5;
    const size_t kInMemoryBit = 6;
    const size_t kLocalUpdateWallClockTimeBit = 7;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kDefaultReadConcernFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kDefaultReadConcernBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDefaultReadConcernBit);

                const BSONObj localObject = element.Obj();
                _rWConcernDefault.setDefaultReadConcern(boost::optional<mongo::repl::ReadConcernArgs>(repl::ReadConcernArgs::fromBSONThrows(localObject)));
            }
        }
        else if (fieldName == kDefaultWriteConcernFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kDefaultWriteConcernBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDefaultWriteConcernBit);

                const BSONObj localObject = element.Obj();
                _rWConcernDefault.setDefaultWriteConcern(boost::optional<mongo::WriteConcernOptions>(WriteConcernOptions::deserializerForIDL(localObject)));
            }
        }
        else if (fieldName == kUpdateOpTimeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, bsonTimestamp))) {
                if (MONGO_unlikely(usedFields[kUpdateOpTimeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUpdateOpTimeBit);

                _rWConcernDefault.setUpdateOpTime(boost::optional<mongo::Timestamp>(element.timestamp()));
            }
        }
        else if (fieldName == kUpdateWallClockTimeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Date))) {
                if (MONGO_unlikely(usedFields[kUpdateWallClockTimeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUpdateWallClockTimeBit);

                _rWConcernDefault.setUpdateWallClockTime(boost::optional<mongo::Date_t>(element.date()));
            }
        }
        else if (fieldName == kDefaultWriteConcernSourceFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kDefaultWriteConcernSourceBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDefaultWriteConcernSourceBit);

                IDLParserErrorContext tempContext(kDefaultWriteConcernSourceFieldName, &ctxt);
                _rWConcernDefault.setDefaultWriteConcernSource(boost::optional<mongo::DefaultWriteConcernSourceEnum>(DefaultWriteConcernSource_parse(tempContext, element.valueStringData())));
            }
        }
        else if (fieldName == kDefaultReadConcernSourceFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kDefaultReadConcernSourceBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDefaultReadConcernSourceBit);

                IDLParserErrorContext tempContext(kDefaultReadConcernSourceFieldName, &ctxt);
                _rWConcernDefault.setDefaultReadConcernSource(boost::optional<mongo::DefaultReadConcernSourceEnum>(DefaultReadConcernSource_parse(tempContext, element.valueStringData())));
            }
        }
        else if (fieldName == kInMemoryFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kInMemoryBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kInMemoryBit);

                _inMemory = element.boolean();
            }
        }
        else if (fieldName == kLocalUpdateWallClockTimeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Date))) {
                if (MONGO_unlikely(usedFields[kLocalUpdateWallClockTimeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLocalUpdateWallClockTimeBit);

                _hasLocalUpdateWallClockTime = true;
                _localUpdateWallClockTime = element.date();
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
        if (!usedFields[kLocalUpdateWallClockTimeBit]) {
            ctxt.throwMissingField(kLocalUpdateWallClockTimeFieldName);
        }
    }

}


void GetDefaultRWConcernResponse::serialize(BSONObjBuilder* builder) const {
    invariant(_hasLocalUpdateWallClockTime);

    {
        _rWConcernDefault.serialize(builder);
    }

    if (_inMemory.is_initialized()) {
        builder->append(kInMemoryFieldName, _inMemory.get());
    }

    builder->append(kLocalUpdateWallClockTimeFieldName, _localUpdateWallClockTime);

}


BSONObj GetDefaultRWConcernResponse::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData SetDefaultRWConcern::kDbNameFieldName;
constexpr StringData SetDefaultRWConcern::kDefaultReadConcernFieldName;
constexpr StringData SetDefaultRWConcern::kDefaultWriteConcernFieldName;
constexpr StringData SetDefaultRWConcern::kCommandName;

const std::vector<StringData> SetDefaultRWConcern::_knownBSONFields {
    SetDefaultRWConcern::kDefaultReadConcernFieldName,
    SetDefaultRWConcern::kDefaultWriteConcernFieldName,
    SetDefaultRWConcern::kCommandName,
};
const std::vector<StringData> SetDefaultRWConcern::_knownOP_MSGFields {
    SetDefaultRWConcern::kDbNameFieldName,
    SetDefaultRWConcern::kDefaultReadConcernFieldName,
    SetDefaultRWConcern::kDefaultWriteConcernFieldName,
    SetDefaultRWConcern::kCommandName,
};

SetDefaultRWConcern::SetDefaultRWConcern() : _hasDbName(false) {
    // Used for initialization only
}


SetDefaultRWConcern SetDefaultRWConcern::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<SetDefaultRWConcern>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void SetDefaultRWConcern::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<3> usedFields;
    const size_t kDefaultReadConcernBit = 0;
    const size_t kDefaultWriteConcernBit = 1;
    const size_t kDbNameBit = 2;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kDefaultReadConcernFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kDefaultReadConcernBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDefaultReadConcernBit);

                const BSONObj localObject = element.Obj();
                _defaultReadConcern = repl::ReadConcernArgs::fromBSONThrows(localObject);
            }
        }
        else if (fieldName == kDefaultWriteConcernFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kDefaultWriteConcernBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDefaultWriteConcernBit);

                const BSONObj localObject = element.Obj();
                _defaultWriteConcern = WriteConcernOptions::deserializerForIDL(localObject);
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
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

}

SetDefaultRWConcern SetDefaultRWConcern::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto object = mongo::idl::preparsedValue<SetDefaultRWConcern>();
    object.parseProtected(ctxt, request);
    return object;
}
void SetDefaultRWConcern::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<3> usedFields;
    const size_t kDefaultReadConcernBit = 0;
    const size_t kDefaultWriteConcernBit = 1;
    const size_t kDbNameBit = 2;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kDefaultReadConcernFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kDefaultReadConcernBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDefaultReadConcernBit);

                const BSONObj localObject = element.Obj();
                _defaultReadConcern = repl::ReadConcernArgs::fromBSONThrows(localObject);
            }
        }
        else if (fieldName == kDefaultWriteConcernFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kDefaultWriteConcernBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDefaultWriteConcernBit);

                const BSONObj localObject = element.Obj();
                _defaultWriteConcern = WriteConcernOptions::deserializerForIDL(localObject);
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
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

}

void SetDefaultRWConcern::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    builder->append("setDefaultRWConcern"_sd, 1);
    if (_defaultReadConcern.is_initialized()) {
        const BSONObj localObject = _defaultReadConcern.get().toBSONInner();
        builder->append(kDefaultReadConcernFieldName, localObject);
    }

    if (_defaultWriteConcern.is_initialized()) {
        const BSONObj localObject = _defaultWriteConcern.get().toBSON();
        builder->append(kDefaultWriteConcernFieldName, localObject);
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest SetDefaultRWConcern::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        builder->append("setDefaultRWConcern"_sd, 1);
        if (_defaultReadConcern.is_initialized()) {
            const BSONObj localObject = _defaultReadConcern.get().toBSONInner();
            builder->append(kDefaultReadConcernFieldName, localObject);
        }

        if (_defaultWriteConcern.is_initialized()) {
            const BSONObj localObject = _defaultWriteConcern.get().toBSON();
            builder->append(kDefaultWriteConcernFieldName, localObject);
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj SetDefaultRWConcern::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData GetDefaultRWConcern::kDbNameFieldName;
constexpr StringData GetDefaultRWConcern::kInMemoryFieldName;
constexpr StringData GetDefaultRWConcern::kCommandName;

const std::vector<StringData> GetDefaultRWConcern::_knownBSONFields {
    GetDefaultRWConcern::kInMemoryFieldName,
    GetDefaultRWConcern::kCommandName,
};
const std::vector<StringData> GetDefaultRWConcern::_knownOP_MSGFields {
    GetDefaultRWConcern::kDbNameFieldName,
    GetDefaultRWConcern::kInMemoryFieldName,
    GetDefaultRWConcern::kCommandName,
};

GetDefaultRWConcern::GetDefaultRWConcern() : _hasDbName(false) {
    // Used for initialization only
}


GetDefaultRWConcern GetDefaultRWConcern::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<GetDefaultRWConcern>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void GetDefaultRWConcern::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kInMemoryBit = 0;
    const size_t kDbNameBit = 1;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kInMemoryFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kInMemoryBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kInMemoryBit);

                _inMemory = element.boolean();
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
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

}

GetDefaultRWConcern GetDefaultRWConcern::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto object = mongo::idl::preparsedValue<GetDefaultRWConcern>();
    object.parseProtected(ctxt, request);
    return object;
}
void GetDefaultRWConcern::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<2> usedFields;
    const size_t kInMemoryBit = 0;
    const size_t kDbNameBit = 1;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kInMemoryFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kInMemoryBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kInMemoryBit);

                _inMemory = element.boolean();
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
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

}

void GetDefaultRWConcern::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    builder->append("getDefaultRWConcern"_sd, 1);
    if (_inMemory.is_initialized()) {
        builder->append(kInMemoryFieldName, _inMemory.get());
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest GetDefaultRWConcern::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        builder->append("getDefaultRWConcern"_sd, 1);
        if (_inMemory.is_initialized()) {
            builder->append(kInMemoryFieldName, _inMemory.get());
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj GetDefaultRWConcern::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
