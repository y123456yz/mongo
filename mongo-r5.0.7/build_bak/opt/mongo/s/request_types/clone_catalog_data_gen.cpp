/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/s/request_types/clone_catalog_data_gen.h --output build/opt/mongo/s/request_types/clone_catalog_data_gen.cpp src/mongo/s/request_types/clone_catalog_data.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/s/request_types/clone_catalog_data_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData CloneCatalogData::kCommandParameterFieldName;
constexpr StringData CloneCatalogData::kDbNameFieldName;
constexpr StringData CloneCatalogData::kFromFieldName;
constexpr StringData CloneCatalogData::kCommandName;

const std::vector<StringData> CloneCatalogData::_knownBSONFields {
    CloneCatalogData::kFromFieldName,
    CloneCatalogData::kCommandName,
};
const std::vector<StringData> CloneCatalogData::_knownOP_MSGFields {
    CloneCatalogData::kDbNameFieldName,
    CloneCatalogData::kFromFieldName,
    CloneCatalogData::kCommandName,
};

CloneCatalogData::CloneCatalogData(const mongo::NamespaceString commandParameter) : _commandParameter(std::move(commandParameter)), _from(mongo::idl::preparsedValue<decltype(_from)>()), _hasFrom(false), _hasDbName(false) {
    // Used for initialization only
}
CloneCatalogData::CloneCatalogData(const mongo::NamespaceString commandParameter, std::string from) : _commandParameter(std::move(commandParameter)), _from(std::move(from)), _hasFrom(true), _hasDbName(true) {
    // Used for initialization only
}


CloneCatalogData CloneCatalogData::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto localCmdType = mongo::idl::preparsedValue<mongo::NamespaceString>();
    CloneCatalogData object(localCmdType);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void CloneCatalogData::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kFromBit = 0;
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

        if (fieldName == kFromFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kFromBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kFromBit);

                _hasFrom = true;
                _from = element.str();
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
        if (!usedFields[kFromBit]) {
            ctxt.throwMissingField(kFromFieldName);
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

CloneCatalogData CloneCatalogData::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto localCmdType = mongo::idl::preparsedValue<mongo::NamespaceString>();
    CloneCatalogData object(localCmdType);
    object.parseProtected(ctxt, request);
    return object;
}
void CloneCatalogData::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<2> usedFields;
    const size_t kFromBit = 0;
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

        if (fieldName == kFromFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kFromBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kFromBit);

                _hasFrom = true;
                _from = element.str();
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
        if (!usedFields[kFromBit]) {
            ctxt.throwMissingField(kFromFieldName);
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

void CloneCatalogData::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasFrom && _hasDbName);

    {
        builder->append(kCommandParameterFieldName, _commandParameter.toString());
    }
    builder->append(kFromFieldName, _from);

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest CloneCatalogData::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasFrom && _hasDbName);

        {
            builder->append(kCommandParameterFieldName, _commandParameter.toString());
        }
        builder->append(kFromFieldName, _from);

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj CloneCatalogData::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
