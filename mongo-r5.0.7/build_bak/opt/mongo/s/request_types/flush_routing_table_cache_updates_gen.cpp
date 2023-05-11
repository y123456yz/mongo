/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/s/request_types/flush_routing_table_cache_updates_gen.h --output build/opt/mongo/s/request_types/flush_routing_table_cache_updates_gen.cpp src/mongo/s/request_types/flush_routing_table_cache_updates.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/s/request_types/flush_routing_table_cache_updates_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData FlushRoutingTableCacheUpdates::kCommandParameterFieldName;
constexpr StringData FlushRoutingTableCacheUpdates::kDbNameFieldName;
constexpr StringData FlushRoutingTableCacheUpdates::kSyncFromConfigFieldName;
constexpr StringData FlushRoutingTableCacheUpdates::kCommandName;

const std::vector<StringData> FlushRoutingTableCacheUpdates::_knownBSONFields {
    FlushRoutingTableCacheUpdates::kSyncFromConfigFieldName,
    FlushRoutingTableCacheUpdates::kCommandName,
};
const std::vector<StringData> FlushRoutingTableCacheUpdates::_knownOP_MSGFields {
    FlushRoutingTableCacheUpdates::kDbNameFieldName,
    FlushRoutingTableCacheUpdates::kSyncFromConfigFieldName,
    FlushRoutingTableCacheUpdates::kCommandName,
};

FlushRoutingTableCacheUpdates::FlushRoutingTableCacheUpdates(const mongo::NamespaceString commandParameter) : _commandParameter(std::move(commandParameter)), _hasDbName(false) {
    // Used for initialization only
}


FlushRoutingTableCacheUpdates FlushRoutingTableCacheUpdates::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto localCmdType = mongo::idl::preparsedValue<mongo::NamespaceString>();
    FlushRoutingTableCacheUpdates object(localCmdType);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void FlushRoutingTableCacheUpdates::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kSyncFromConfigBit = 0;
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

        if (fieldName == kSyncFromConfigFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kSyncFromConfigBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSyncFromConfigBit);

                _syncFromConfig = element.boolean();
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
        if (!usedFields[kSyncFromConfigBit]) {
            _syncFromConfig = true;
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    {
        if (MONGO_likely(ctxt.checkAndAssertType(commandElement, String))) {
            _commandParameter = NamespaceString(commandElement.valueStringData());
        }
        else {
            ctxt.throwMissingField(kCommandParameterFieldName);
        }
    }
}

FlushRoutingTableCacheUpdates FlushRoutingTableCacheUpdates::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto localCmdType = mongo::idl::preparsedValue<mongo::NamespaceString>();
    FlushRoutingTableCacheUpdates object(localCmdType);
    object.parseProtected(ctxt, request);
    return object;
}
void FlushRoutingTableCacheUpdates::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<2> usedFields;
    const size_t kSyncFromConfigBit = 0;
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

        if (fieldName == kSyncFromConfigFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kSyncFromConfigBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSyncFromConfigBit);

                _syncFromConfig = element.boolean();
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
        if (!usedFields[kSyncFromConfigBit]) {
            _syncFromConfig = true;
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    {
        if (MONGO_likely(ctxt.checkAndAssertType(commandElement, String))) {
            _commandParameter = NamespaceString(commandElement.valueStringData());
        }
        else {
            ctxt.throwMissingField(kCommandParameterFieldName);
        }
    }
}

void FlushRoutingTableCacheUpdates::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    {
        builder->append(kCommandParameterFieldName, _commandParameter.toString());
    }
    builder->append(kSyncFromConfigFieldName, _syncFromConfig);

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest FlushRoutingTableCacheUpdates::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        {
            builder->append(kCommandParameterFieldName, _commandParameter.toString());
        }
        builder->append(kSyncFromConfigFieldName, _syncFromConfig);

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj FlushRoutingTableCacheUpdates::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData FlushRoutingTableCacheUpdatesWithWriteConcern::kCommandParameterFieldName;
constexpr StringData FlushRoutingTableCacheUpdatesWithWriteConcern::kDbNameFieldName;
constexpr StringData FlushRoutingTableCacheUpdatesWithWriteConcern::kSyncFromConfigFieldName;
constexpr StringData FlushRoutingTableCacheUpdatesWithWriteConcern::kCommandName;

const std::vector<StringData> FlushRoutingTableCacheUpdatesWithWriteConcern::_knownBSONFields {
    FlushRoutingTableCacheUpdatesWithWriteConcern::kSyncFromConfigFieldName,
    FlushRoutingTableCacheUpdatesWithWriteConcern::kCommandName,
};
const std::vector<StringData> FlushRoutingTableCacheUpdatesWithWriteConcern::_knownOP_MSGFields {
    FlushRoutingTableCacheUpdatesWithWriteConcern::kDbNameFieldName,
    FlushRoutingTableCacheUpdatesWithWriteConcern::kSyncFromConfigFieldName,
    FlushRoutingTableCacheUpdatesWithWriteConcern::kCommandName,
};

FlushRoutingTableCacheUpdatesWithWriteConcern::FlushRoutingTableCacheUpdatesWithWriteConcern(const mongo::NamespaceString commandParameter) : _commandParameter(std::move(commandParameter)), _hasDbName(false) {
    // Used for initialization only
}


FlushRoutingTableCacheUpdatesWithWriteConcern FlushRoutingTableCacheUpdatesWithWriteConcern::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto localCmdType = mongo::idl::preparsedValue<mongo::NamespaceString>();
    FlushRoutingTableCacheUpdatesWithWriteConcern object(localCmdType);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void FlushRoutingTableCacheUpdatesWithWriteConcern::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kSyncFromConfigBit = 0;
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

        if (fieldName == kSyncFromConfigFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kSyncFromConfigBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSyncFromConfigBit);

                _syncFromConfig = element.boolean();
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
        if (!usedFields[kSyncFromConfigBit]) {
            _syncFromConfig = true;
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    {
        if (MONGO_likely(ctxt.checkAndAssertType(commandElement, String))) {
            _commandParameter = NamespaceString(commandElement.valueStringData());
        }
        else {
            ctxt.throwMissingField(kCommandParameterFieldName);
        }
    }
}

FlushRoutingTableCacheUpdatesWithWriteConcern FlushRoutingTableCacheUpdatesWithWriteConcern::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto localCmdType = mongo::idl::preparsedValue<mongo::NamespaceString>();
    FlushRoutingTableCacheUpdatesWithWriteConcern object(localCmdType);
    object.parseProtected(ctxt, request);
    return object;
}
void FlushRoutingTableCacheUpdatesWithWriteConcern::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<2> usedFields;
    const size_t kSyncFromConfigBit = 0;
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

        if (fieldName == kSyncFromConfigFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kSyncFromConfigBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSyncFromConfigBit);

                _syncFromConfig = element.boolean();
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
        if (!usedFields[kSyncFromConfigBit]) {
            _syncFromConfig = true;
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    {
        if (MONGO_likely(ctxt.checkAndAssertType(commandElement, String))) {
            _commandParameter = NamespaceString(commandElement.valueStringData());
        }
        else {
            ctxt.throwMissingField(kCommandParameterFieldName);
        }
    }
}

void FlushRoutingTableCacheUpdatesWithWriteConcern::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    {
        builder->append(kCommandParameterFieldName, _commandParameter.toString());
    }
    builder->append(kSyncFromConfigFieldName, _syncFromConfig);

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest FlushRoutingTableCacheUpdatesWithWriteConcern::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        {
            builder->append(kCommandParameterFieldName, _commandParameter.toString());
        }
        builder->append(kSyncFromConfigFieldName, _syncFromConfig);

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj FlushRoutingTableCacheUpdatesWithWriteConcern::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
