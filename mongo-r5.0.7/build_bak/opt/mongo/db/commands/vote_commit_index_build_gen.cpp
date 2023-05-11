/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/commands/vote_commit_index_build_gen.h --output build/opt/mongo/db/commands/vote_commit_index_build_gen.cpp src/mongo/db/commands/vote_commit_index_build.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/commands/vote_commit_index_build_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData VoteCommitIndexBuild::kCommandParameterFieldName;
constexpr StringData VoteCommitIndexBuild::kDbNameFieldName;
constexpr StringData VoteCommitIndexBuild::kHostAndPortFieldName;
constexpr StringData VoteCommitIndexBuild::kCommandName;

const std::vector<StringData> VoteCommitIndexBuild::_knownBSONFields {
    VoteCommitIndexBuild::kHostAndPortFieldName,
    VoteCommitIndexBuild::kCommandName,
};
const std::vector<StringData> VoteCommitIndexBuild::_knownOP_MSGFields {
    VoteCommitIndexBuild::kDbNameFieldName,
    VoteCommitIndexBuild::kHostAndPortFieldName,
    VoteCommitIndexBuild::kCommandName,
};

VoteCommitIndexBuild::VoteCommitIndexBuild(const mongo::UUID commandParameter) : _commandParameter(std::move(commandParameter)), _hostAndPort(mongo::idl::preparsedValue<decltype(_hostAndPort)>()), _hasHostAndPort(false), _hasDbName(false) {
    // Used for initialization only
}
VoteCommitIndexBuild::VoteCommitIndexBuild(const mongo::UUID commandParameter, mongo::HostAndPort hostAndPort) : _commandParameter(std::move(commandParameter)), _hostAndPort(std::move(hostAndPort)), _hasHostAndPort(true), _hasDbName(true) {
    // Used for initialization only
}


VoteCommitIndexBuild VoteCommitIndexBuild::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto localCmdType = mongo::idl::preparsedValue<mongo::UUID>();
    VoteCommitIndexBuild object(localCmdType);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void VoteCommitIndexBuild::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kHostAndPortBit = 0;
    const size_t kDbNameBit = 1;
    std::set<StringData> usedFieldSet;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kHostAndPortFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kHostAndPortBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kHostAndPortBit);

                _hasHostAndPort = true;
                _hostAndPort = HostAndPort::parseThrowing(element.valueStringData());
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
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kHostAndPortBit]) {
            ctxt.throwMissingField(kHostAndPortFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    {
        if (MONGO_likely(ctxt.checkAndAssertBinDataType(commandElement, newUUID))) {
            _commandParameter = UUID(uassertStatusOK(UUID::parse(commandElement)));
        }
        else {
            ctxt.throwMissingField(kCommandParameterFieldName);
        }
    }
}

VoteCommitIndexBuild VoteCommitIndexBuild::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto localCmdType = mongo::idl::preparsedValue<mongo::UUID>();
    VoteCommitIndexBuild object(localCmdType);
    object.parseProtected(ctxt, request);
    return object;
}
void VoteCommitIndexBuild::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<2> usedFields;
    const size_t kHostAndPortBit = 0;
    const size_t kDbNameBit = 1;
    std::set<StringData> usedFieldSet;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kHostAndPortFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kHostAndPortBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kHostAndPortBit);

                _hasHostAndPort = true;
                _hostAndPort = HostAndPort::parseThrowing(element.valueStringData());
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
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kHostAndPortBit]) {
            ctxt.throwMissingField(kHostAndPortFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    {
        if (MONGO_likely(ctxt.checkAndAssertBinDataType(commandElement, newUUID))) {
            _commandParameter = UUID(uassertStatusOK(UUID::parse(commandElement)));
        }
        else {
            ctxt.throwMissingField(kCommandParameterFieldName);
        }
    }
}

void VoteCommitIndexBuild::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasHostAndPort && _hasDbName);

    {
        ConstDataRange tempCDR = _commandParameter.toCDR();
        builder->append(kCommandParameterFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }
    {
        builder->append(kHostAndPortFieldName, _hostAndPort.toString());
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest VoteCommitIndexBuild::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasHostAndPort && _hasDbName);

        {
            ConstDataRange tempCDR = _commandParameter.toCDR();
            builder->append(kCommandParameterFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
        }
        {
            builder->append(kHostAndPortFieldName, _hostAndPort.toString());
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj VoteCommitIndexBuild::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
