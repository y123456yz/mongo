/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/commands/shutdown_gen.h --output build/opt/mongo/db/commands/shutdown_gen.cpp src/mongo/db/commands/shutdown.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/commands/shutdown_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData ShutdownRequest::kDbNameFieldName;
constexpr StringData ShutdownRequest::kForceFieldName;
constexpr StringData ShutdownRequest::kTimeoutSecsFieldName;
constexpr StringData ShutdownRequest::kCommandName;

const std::vector<StringData> ShutdownRequest::_knownBSONFields {
    ShutdownRequest::kForceFieldName,
    ShutdownRequest::kTimeoutSecsFieldName,
    ShutdownRequest::kCommandName,
};
const std::vector<StringData> ShutdownRequest::_knownOP_MSGFields {
    ShutdownRequest::kDbNameFieldName,
    ShutdownRequest::kForceFieldName,
    ShutdownRequest::kTimeoutSecsFieldName,
    ShutdownRequest::kCommandName,
};

ShutdownRequest::ShutdownRequest() : _hasDbName(false) {
    // Used for initialization only
}


ShutdownRequest ShutdownRequest::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ShutdownRequest>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ShutdownRequest::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<3> usedFields;
    const size_t kForceBit = 0;
    const size_t kTimeoutSecsBit = 1;
    const size_t kDbNameBit = 2;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kForceFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kForceBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kForceBit);

                _force = element.boolean();
            }
        }
        else if (fieldName == kTimeoutSecsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kTimeoutSecsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTimeoutSecsBit);

                _timeoutSecs = element.safeNumberLong();
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
        if (!usedFields[kForceBit]) {
            _force = false;
        }
        if (!usedFields[kTimeoutSecsBit]) {
            _timeoutSecs = 15;
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

}

ShutdownRequest ShutdownRequest::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto object = mongo::idl::preparsedValue<ShutdownRequest>();
    object.parseProtected(ctxt, request);
    return object;
}
void ShutdownRequest::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<3> usedFields;
    const size_t kForceBit = 0;
    const size_t kTimeoutSecsBit = 1;
    const size_t kDbNameBit = 2;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kForceFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kForceBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kForceBit);

                _force = element.boolean();
            }
        }
        else if (fieldName == kTimeoutSecsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kTimeoutSecsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTimeoutSecsBit);

                _timeoutSecs = element.safeNumberLong();
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
        if (!usedFields[kForceBit]) {
            _force = false;
        }
        if (!usedFields[kTimeoutSecsBit]) {
            _timeoutSecs = 15;
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

}

void ShutdownRequest::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    builder->append("shutdown"_sd, 1);
    builder->append(kForceFieldName, _force);

    builder->append(kTimeoutSecsFieldName, _timeoutSecs);

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest ShutdownRequest::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        builder->append("shutdown"_sd, 1);
        builder->append(kForceFieldName, _force);

        builder->append(kTimeoutSecsFieldName, _timeoutSecs);

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj ShutdownRequest::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
