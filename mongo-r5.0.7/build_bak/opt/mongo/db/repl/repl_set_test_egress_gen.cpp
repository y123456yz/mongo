/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/repl/repl_set_test_egress_gen.h --output build/opt/mongo/db/repl/repl_set_test_egress_gen.cpp src/mongo/db/repl/repl_set_test_egress.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/repl/repl_set_test_egress_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {
namespace repl {

constexpr StringData ReplSetTestEgressReply::kTargetFieldName;


ReplSetTestEgressReply::ReplSetTestEgressReply() : _target(mongo::idl::preparsedValue<decltype(_target)>()), _hasTarget(false) {
    // Used for initialization only
}
ReplSetTestEgressReply::ReplSetTestEgressReply(std::string target) : _target(std::move(target)), _hasTarget(true) {
    // Used for initialization only
}


ReplSetTestEgressReply ReplSetTestEgressReply::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ReplSetTestEgressReply>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ReplSetTestEgressReply::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kTargetBit = 0;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kTargetFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kTargetBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTargetBit);

                _hasTarget = true;
                _target = element.str();
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kTargetBit]) {
            ctxt.throwMissingField(kTargetFieldName);
        }
    }

}


void ReplSetTestEgressReply::serialize(BSONObjBuilder* builder) const {
    invariant(_hasTarget);

    builder->append(kTargetFieldName, _target);

}


BSONObj ReplSetTestEgressReply::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData ReplSetTestEgress::kDbNameFieldName;
constexpr StringData ReplSetTestEgress::kTargetFieldName;
constexpr StringData ReplSetTestEgress::kTimeoutSecsFieldName;
constexpr StringData ReplSetTestEgress::kCommandName;

const std::vector<StringData> ReplSetTestEgress::_knownBSONFields {
    ReplSetTestEgress::kTargetFieldName,
    ReplSetTestEgress::kTimeoutSecsFieldName,
    ReplSetTestEgress::kCommandName,
};
const std::vector<StringData> ReplSetTestEgress::_knownOP_MSGFields {
    ReplSetTestEgress::kDbNameFieldName,
    ReplSetTestEgress::kTargetFieldName,
    ReplSetTestEgress::kTimeoutSecsFieldName,
    ReplSetTestEgress::kCommandName,
};

ReplSetTestEgress::ReplSetTestEgress() : _hasDbName(false) {
    // Used for initialization only
}

void ReplSetTestEgress::validateTimeoutSecs(IDLParserErrorContext& ctxt, const std::int32_t value)
{
    if (!(value > 0)) {
        throwComparisonError<std::int32_t>(ctxt, "timeoutSecs", ">"_sd, value, 0);
    }
}

void ReplSetTestEgress::validateTimeoutSecs(const std::int32_t value)
{
    if (!(value > 0)) {
        throwComparisonError<std::int32_t>("timeoutSecs", ">"_sd, value, 0);
    }
}


ReplSetTestEgress ReplSetTestEgress::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ReplSetTestEgress>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ReplSetTestEgress::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<3> usedFields;
    const size_t kTargetBit = 0;
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

        if (fieldName == kTargetFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kTargetBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTargetBit);

                _target = element.str();
            }
        }
        else if (fieldName == kTimeoutSecsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberInt))) {
                if (MONGO_unlikely(usedFields[kTimeoutSecsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTimeoutSecsBit);

                {
                    auto value = element._numberInt();
                    validateTimeoutSecs(value);
                    _timeoutSecs = std::move(value);
                }
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
        if (!usedFields[kTimeoutSecsBit]) {
            _timeoutSecs = 5;
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

}

ReplSetTestEgress ReplSetTestEgress::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto object = mongo::idl::preparsedValue<ReplSetTestEgress>();
    object.parseProtected(ctxt, request);
    return object;
}
void ReplSetTestEgress::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<3> usedFields;
    const size_t kTargetBit = 0;
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

        if (fieldName == kTargetFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kTargetBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTargetBit);

                _target = element.str();
            }
        }
        else if (fieldName == kTimeoutSecsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberInt))) {
                if (MONGO_unlikely(usedFields[kTimeoutSecsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTimeoutSecsBit);

                {
                    auto value = element._numberInt();
                    validateTimeoutSecs(value);
                    _timeoutSecs = std::move(value);
                }
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
        if (!usedFields[kTimeoutSecsBit]) {
            _timeoutSecs = 5;
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

}

void ReplSetTestEgress::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    builder->append("replSetTestEgress"_sd, 1);
    if (_target.is_initialized()) {
        builder->append(kTargetFieldName, _target.get());
    }

    builder->append(kTimeoutSecsFieldName, _timeoutSecs);

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest ReplSetTestEgress::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        builder->append("replSetTestEgress"_sd, 1);
        if (_target.is_initialized()) {
            builder->append(kTargetFieldName, _target.get());
        }

        builder->append(kTimeoutSecsFieldName, _timeoutSecs);

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj ReplSetTestEgress::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace repl
}  // namespace mongo
