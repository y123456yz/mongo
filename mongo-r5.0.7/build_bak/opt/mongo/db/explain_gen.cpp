/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/explain_gen.h --output build/opt/mongo/db/explain_gen.cpp src/mongo/db/explain.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/explain_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData ExplainCommandRequest::kCommandParameterFieldName;
constexpr StringData ExplainCommandRequest::kCollationFieldName;
constexpr StringData ExplainCommandRequest::kDbNameFieldName;
constexpr StringData ExplainCommandRequest::kUse44SortKeysFieldName;
constexpr StringData ExplainCommandRequest::kUseNewUpsertFieldName;
constexpr StringData ExplainCommandRequest::kVerbosityFieldName;
constexpr StringData ExplainCommandRequest::kCommandName;

const std::vector<StringData> ExplainCommandRequest::_knownBSONFields {
    ExplainCommandRequest::kCollationFieldName,
    ExplainCommandRequest::kUse44SortKeysFieldName,
    ExplainCommandRequest::kUseNewUpsertFieldName,
    ExplainCommandRequest::kVerbosityFieldName,
    ExplainCommandRequest::kCommandName,
};
const std::vector<StringData> ExplainCommandRequest::_knownOP_MSGFields {
    ExplainCommandRequest::kCollationFieldName,
    ExplainCommandRequest::kDbNameFieldName,
    ExplainCommandRequest::kUse44SortKeysFieldName,
    ExplainCommandRequest::kUseNewUpsertFieldName,
    ExplainCommandRequest::kVerbosityFieldName,
    ExplainCommandRequest::kCommandName,
};

ExplainCommandRequest::ExplainCommandRequest(const mongo::BSONObj commandParameter) : _commandParameter(std::move(commandParameter)), _hasDbName(false) {
    // Used for initialization only
}


ExplainCommandRequest ExplainCommandRequest::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto localCmdType = mongo::idl::preparsedValue<mongo::BSONObj>();
    ExplainCommandRequest object(localCmdType);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ExplainCommandRequest::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<5> usedFields;
    const size_t kVerbosityBit = 0;
    const size_t kCollationBit = 1;
    const size_t kUse44SortKeysBit = 2;
    const size_t kUseNewUpsertBit = 3;
    const size_t kDbNameBit = 4;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kVerbosityFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kVerbosityBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kVerbosityBit);

                IDLParserErrorContext tempContext(kVerbosityFieldName, &ctxt);
                _verbosity = explain::Verbosity_parse(tempContext, element.valueStringData());
            }
        }
        else if (fieldName == kCollationFieldName) {
            if (MONGO_unlikely(usedFields[kCollationBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kCollationBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            // ignore field
        }
        else if (fieldName == kUse44SortKeysFieldName) {
            if (MONGO_unlikely(usedFields[kUse44SortKeysBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kUse44SortKeysBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            // ignore field
        }
        else if (fieldName == kUseNewUpsertFieldName) {
            if (MONGO_unlikely(usedFields[kUseNewUpsertBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kUseNewUpsertBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            // ignore field
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
        if (!usedFields[kVerbosityBit]) {
            _verbosity = mongo::explain::VerbosityEnum::kExecAllPlans;
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    {
        if (MONGO_likely(ctxt.checkAndAssertType(commandElement, Object))) {
            _commandParameter = commandElement.Obj();
        }
        else {
            ctxt.throwMissingField(kCommandParameterFieldName);
        }
    }
}

ExplainCommandRequest ExplainCommandRequest::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto localCmdType = mongo::idl::preparsedValue<mongo::BSONObj>();
    ExplainCommandRequest object(localCmdType);
    object.parseProtected(ctxt, request);
    return object;
}
void ExplainCommandRequest::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<5> usedFields;
    const size_t kVerbosityBit = 0;
    const size_t kCollationBit = 1;
    const size_t kUse44SortKeysBit = 2;
    const size_t kUseNewUpsertBit = 3;
    const size_t kDbNameBit = 4;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kVerbosityFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kVerbosityBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kVerbosityBit);

                IDLParserErrorContext tempContext(kVerbosityFieldName, &ctxt);
                _verbosity = explain::Verbosity_parse(tempContext, element.valueStringData());
            }
        }
        else if (fieldName == kCollationFieldName) {
            if (MONGO_unlikely(usedFields[kCollationBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kCollationBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            // ignore field
        }
        else if (fieldName == kUse44SortKeysFieldName) {
            if (MONGO_unlikely(usedFields[kUse44SortKeysBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kUse44SortKeysBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            // ignore field
        }
        else if (fieldName == kUseNewUpsertFieldName) {
            if (MONGO_unlikely(usedFields[kUseNewUpsertBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kUseNewUpsertBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            // ignore field
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
        if (!usedFields[kVerbosityBit]) {
            _verbosity = mongo::explain::VerbosityEnum::kExecAllPlans;
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    {
        if (MONGO_likely(ctxt.checkAndAssertType(commandElement, Object))) {
            _commandParameter = commandElement.Obj();
        }
        else {
            ctxt.throwMissingField(kCommandParameterFieldName);
        }
    }
}

void ExplainCommandRequest::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    builder->append(kCommandParameterFieldName, _commandParameter);
    {
        builder->append(kVerbosityFieldName, ::mongo::explain::Verbosity_serializer(_verbosity));
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest ExplainCommandRequest::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        builder->append(kCommandParameterFieldName, _commandParameter);
        {
            builder->append(kVerbosityFieldName, ::mongo::explain::Verbosity_serializer(_verbosity));
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj ExplainCommandRequest::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
