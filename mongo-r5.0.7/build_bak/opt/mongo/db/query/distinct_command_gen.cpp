/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/query/distinct_command_gen.h --output build/opt/mongo/db/query/distinct_command_gen.cpp src/mongo/db/query/distinct_command.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/query/distinct_command_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData DistinctCommandRequest::kCollationFieldName;
constexpr StringData DistinctCommandRequest::kDbNameFieldName;
constexpr StringData DistinctCommandRequest::kKeyFieldName;
constexpr StringData DistinctCommandRequest::kQueryFieldName;
constexpr StringData DistinctCommandRequest::kCommandName;

const std::vector<StringData> DistinctCommandRequest::_knownBSONFields {
    DistinctCommandRequest::kCollationFieldName,
    DistinctCommandRequest::kKeyFieldName,
    DistinctCommandRequest::kQueryFieldName,
    DistinctCommandRequest::kCommandName,
};
const std::vector<StringData> DistinctCommandRequest::_knownOP_MSGFields {
    DistinctCommandRequest::kCollationFieldName,
    DistinctCommandRequest::kDbNameFieldName,
    DistinctCommandRequest::kKeyFieldName,
    DistinctCommandRequest::kQueryFieldName,
    DistinctCommandRequest::kCommandName,
};

DistinctCommandRequest::DistinctCommandRequest(const NamespaceStringOrUUID nssOrUUID) : _nssOrUUID(std::move(nssOrUUID)), _key(mongo::idl::preparsedValue<decltype(_key)>()), _dbName(nssOrUUID.uuid() ? nssOrUUID.dbname() : nssOrUUID.nss().get().db().toString()), _hasKey(false), _hasDbName(true) {
    // Used for initialization only
}
DistinctCommandRequest::DistinctCommandRequest(const NamespaceStringOrUUID nssOrUUID, std::string key) : _nssOrUUID(std::move(nssOrUUID)), _key(std::move(key)), _dbName(nssOrUUID.uuid() ? nssOrUUID.dbname() : nssOrUUID.nss().get().db().toString()), _hasKey(true), _hasDbName(true) {
    // Used for initialization only
}


DistinctCommandRequest DistinctCommandRequest::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    NamespaceString localNS;
    DistinctCommandRequest object(localNS);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void DistinctCommandRequest::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<4> usedFields;
    const size_t kKeyBit = 0;
    const size_t kQueryBit = 1;
    const size_t kCollationBit = 2;
    const size_t kDbNameBit = 3;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kKeyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kKeyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kKeyBit);

                _hasKey = true;
                _key = element.str();
            }
        }
        else if (fieldName == kQueryFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kQueryBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kQueryBit);

                _query = element.Obj();
            }
        }
        else if (fieldName == kCollationFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCollationBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollationBit);

                _collation = element.Obj();
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
        if (!usedFields[kKeyBit]) {
            ctxt.throwMissingField(kKeyFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nssOrUUID.nss() || _nssOrUUID.uuid());
    _nssOrUUID = ctxt.parseNsOrUUID(_dbName, commandElement);
}

DistinctCommandRequest DistinctCommandRequest::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    NamespaceString localNS;
    DistinctCommandRequest object(localNS);
    object.parseProtected(ctxt, request);
    return object;
}
void DistinctCommandRequest::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<4> usedFields;
    const size_t kKeyBit = 0;
    const size_t kQueryBit = 1;
    const size_t kCollationBit = 2;
    const size_t kDbNameBit = 3;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kKeyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kKeyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kKeyBit);

                _hasKey = true;
                _key = element.str();
            }
        }
        else if (fieldName == kQueryFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kQueryBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kQueryBit);

                _query = element.Obj();
            }
        }
        else if (fieldName == kCollationFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCollationBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollationBit);

                _collation = element.Obj();
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
        if (!usedFields[kKeyBit]) {
            ctxt.throwMissingField(kKeyFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nssOrUUID.nss() || _nssOrUUID.uuid());
    _nssOrUUID = ctxt.parseNsOrUUID(_dbName, commandElement);
}

void DistinctCommandRequest::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasKey && _hasDbName);

    _nssOrUUID.serialize(builder, "distinct"_sd);

    builder->append(kKeyFieldName, _key);

    if (_query.is_initialized()) {
        builder->append(kQueryFieldName, _query.get());
    }

    if (_collation.is_initialized()) {
        builder->append(kCollationFieldName, _collation.get());
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest DistinctCommandRequest::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasKey && _hasDbName);

        _nssOrUUID.serialize(builder, "distinct"_sd);

        builder->append(kKeyFieldName, _key);

        if (_query.is_initialized()) {
            builder->append(kQueryFieldName, _query.get());
        }

        if (_collation.is_initialized()) {
            builder->append(kCollationFieldName, _collation.get());
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj DistinctCommandRequest::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
