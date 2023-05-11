/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/commands/set_index_commit_quorum_gen.h --output build/opt/mongo/db/commands/set_index_commit_quorum_gen.cpp src/mongo/db/commands/set_index_commit_quorum.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/commands/set_index_commit_quorum_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData SetIndexCommitQuorum::kCommitQuorumFieldName;
constexpr StringData SetIndexCommitQuorum::kDbNameFieldName;
constexpr StringData SetIndexCommitQuorum::kIndexNamesFieldName;
constexpr StringData SetIndexCommitQuorum::kCommandName;

const std::vector<StringData> SetIndexCommitQuorum::_knownBSONFields {
    SetIndexCommitQuorum::kCommitQuorumFieldName,
    SetIndexCommitQuorum::kIndexNamesFieldName,
    SetIndexCommitQuorum::kCommandName,
};
const std::vector<StringData> SetIndexCommitQuorum::_knownOP_MSGFields {
    SetIndexCommitQuorum::kCommitQuorumFieldName,
    SetIndexCommitQuorum::kDbNameFieldName,
    SetIndexCommitQuorum::kIndexNamesFieldName,
    SetIndexCommitQuorum::kCommandName,
};

SetIndexCommitQuorum::SetIndexCommitQuorum(const NamespaceString nss) : _nss(std::move(nss)), _commitQuorum(mongo::idl::preparsedValue<decltype(_commitQuorum)>()), _dbName(nss.db().toString()), _hasIndexNames(false), _hasCommitQuorum(false), _hasDbName(true) {
    // Used for initialization only
}
SetIndexCommitQuorum::SetIndexCommitQuorum(const NamespaceString nss, std::vector<std::string> indexNames, mongo::CommitQuorumOptions commitQuorum) : _nss(std::move(nss)), _indexNames(std::move(indexNames)), _commitQuorum(std::move(commitQuorum)), _dbName(nss.db().toString()), _hasIndexNames(true), _hasCommitQuorum(true), _hasDbName(true) {
    // Used for initialization only
}


SetIndexCommitQuorum SetIndexCommitQuorum::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    NamespaceString localNS;
    SetIndexCommitQuorum object(localNS);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void SetIndexCommitQuorum::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<3> usedFields;
    const size_t kIndexNamesBit = 0;
    const size_t kCommitQuorumBit = 1;
    const size_t kDbNameBit = 2;
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

        if (fieldName == kIndexNamesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kIndexNamesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIndexNamesBit);

                _hasIndexNames = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kIndexNamesFieldName, &ctxt);
            std::vector<std::string> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, String)) {
                        values.emplace_back(arrayElement.str());
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _indexNames = std::move(values);
        }
        else if (fieldName == kCommitQuorumFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble, String}))) {
                if (MONGO_unlikely(usedFields[kCommitQuorumBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCommitQuorumBit);

                _hasCommitQuorum = true;
                _commitQuorum = CommitQuorumOptions::deserializerForIDL(element);
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
        if (!usedFields[kIndexNamesBit]) {
            ctxt.throwMissingField(kIndexNamesFieldName);
        }
        if (!usedFields[kCommitQuorumBit]) {
            ctxt.throwMissingField(kCommitQuorumFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

SetIndexCommitQuorum SetIndexCommitQuorum::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    NamespaceString localNS;
    SetIndexCommitQuorum object(localNS);
    object.parseProtected(ctxt, request);
    return object;
}
void SetIndexCommitQuorum::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<3> usedFields;
    const size_t kIndexNamesBit = 0;
    const size_t kCommitQuorumBit = 1;
    const size_t kDbNameBit = 2;
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

        if (fieldName == kIndexNamesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kIndexNamesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIndexNamesBit);

                _hasIndexNames = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kIndexNamesFieldName, &ctxt);
            std::vector<std::string> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, String)) {
                        values.emplace_back(arrayElement.str());
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _indexNames = std::move(values);
        }
        else if (fieldName == kCommitQuorumFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble, String}))) {
                if (MONGO_unlikely(usedFields[kCommitQuorumBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCommitQuorumBit);

                _hasCommitQuorum = true;
                _commitQuorum = CommitQuorumOptions::deserializerForIDL(element);
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
        if (!usedFields[kIndexNamesBit]) {
            ctxt.throwMissingField(kIndexNamesFieldName);
        }
        if (!usedFields[kCommitQuorumBit]) {
            ctxt.throwMissingField(kCommitQuorumFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

void SetIndexCommitQuorum::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasIndexNames && _hasCommitQuorum && _hasDbName);

    invariant(!_nss.isEmpty());
    builder->append("setIndexCommitQuorum"_sd, _nss.coll());

    {
        builder->append(kIndexNamesFieldName, _indexNames);
    }

    {
        _commitQuorum.appendToBuilder(kCommitQuorumFieldName, builder);
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest SetIndexCommitQuorum::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasIndexNames && _hasCommitQuorum && _hasDbName);

        invariant(!_nss.isEmpty());
        builder->append("setIndexCommitQuorum"_sd, _nss.coll());

        {
            builder->append(kIndexNamesFieldName, _indexNames);
        }

        {
            _commitQuorum.appendToBuilder(kCommitQuorumFieldName, builder);
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj SetIndexCommitQuorum::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
