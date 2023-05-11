/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/commands/set_feature_compatibility_version_gen.h --output build/opt/mongo/db/commands/set_feature_compatibility_version_gen.cpp src/mongo/db/commands/set_feature_compatibility_version.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/commands/set_feature_compatibility_version_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

/**
 * Enum that defines the phases of the 2-phase setFCV protocol.
 */
namespace  {
constexpr StringData kSetFCVPhase_kStart = "start"_sd;
constexpr StringData kSetFCVPhase_kComplete = "complete"_sd;
}  // namespace 

SetFCVPhaseEnum SetFCVPhase_parse(const IDLParserErrorContext& ctxt, StringData value) {
    if (value == kSetFCVPhase_kStart) {
        return SetFCVPhaseEnum::kStart;
    }
    if (value == kSetFCVPhase_kComplete) {
        return SetFCVPhaseEnum::kComplete;
    }
    ctxt.throwBadEnumValue(value);
}

StringData SetFCVPhase_serializer(SetFCVPhaseEnum value) {
    if (value == SetFCVPhaseEnum::kStart) {
        return kSetFCVPhase_kStart;
    }
    if (value == SetFCVPhaseEnum::kComplete) {
        return kSetFCVPhase_kComplete;
    }
    MONGO_UNREACHABLE;
    return StringData();
}

constexpr StringData SetFeatureCompatibilityVersion::kCommandParameterFieldName;
constexpr StringData SetFeatureCompatibilityVersion::kChangeTimestampFieldName;
constexpr StringData SetFeatureCompatibilityVersion::kDbNameFieldName;
constexpr StringData SetFeatureCompatibilityVersion::kDowngradeOnDiskChangesFieldName;
constexpr StringData SetFeatureCompatibilityVersion::kFromConfigServerFieldName;
constexpr StringData SetFeatureCompatibilityVersion::kPhaseFieldName;
constexpr StringData SetFeatureCompatibilityVersion::kCommandName;

const std::vector<StringData> SetFeatureCompatibilityVersion::_knownBSONFields {
    SetFeatureCompatibilityVersion::kChangeTimestampFieldName,
    SetFeatureCompatibilityVersion::kDowngradeOnDiskChangesFieldName,
    SetFeatureCompatibilityVersion::kFromConfigServerFieldName,
    SetFeatureCompatibilityVersion::kPhaseFieldName,
    SetFeatureCompatibilityVersion::kCommandName,
};
const std::vector<StringData> SetFeatureCompatibilityVersion::_knownOP_MSGFields {
    SetFeatureCompatibilityVersion::kChangeTimestampFieldName,
    SetFeatureCompatibilityVersion::kDbNameFieldName,
    SetFeatureCompatibilityVersion::kDowngradeOnDiskChangesFieldName,
    SetFeatureCompatibilityVersion::kFromConfigServerFieldName,
    SetFeatureCompatibilityVersion::kPhaseFieldName,
    SetFeatureCompatibilityVersion::kCommandName,
};

SetFeatureCompatibilityVersion::SetFeatureCompatibilityVersion(const ServerGlobalParams::FeatureCompatibility::Version commandParameter) : _commandParameter(std::move(commandParameter)), _hasDbName(false) {
    // Used for initialization only
}


SetFeatureCompatibilityVersion SetFeatureCompatibilityVersion::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto localCmdType = mongo::idl::preparsedValue<ServerGlobalParams::FeatureCompatibility::Version>();
    SetFeatureCompatibilityVersion object(localCmdType);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void SetFeatureCompatibilityVersion::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<5> usedFields;
    const size_t kDowngradeOnDiskChangesBit = 0;
    const size_t kFromConfigServerBit = 1;
    const size_t kPhaseBit = 2;
    const size_t kChangeTimestampBit = 3;
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

        if (fieldName == kDowngradeOnDiskChangesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kDowngradeOnDiskChangesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDowngradeOnDiskChangesBit);

                _downgradeOnDiskChanges = element.trueValue();
            }
        }
        else if (fieldName == kFromConfigServerFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kFromConfigServerBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kFromConfigServerBit);

                _fromConfigServer = element.trueValue();
            }
        }
        else if (fieldName == kPhaseFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kPhaseBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPhaseBit);

                IDLParserErrorContext tempContext(kPhaseFieldName, &ctxt);
                _phase = SetFCVPhase_parse(tempContext, element.valueStringData());
            }
        }
        else if (fieldName == kChangeTimestampFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, bsonTimestamp))) {
                if (MONGO_unlikely(usedFields[kChangeTimestampBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kChangeTimestampBit);

                _changeTimestamp = element.timestamp();
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

    {
        if (MONGO_likely(ctxt.checkAndAssertType(commandElement, String))) {
            _commandParameter = FeatureCompatibilityVersionParser::parseVersion(commandElement.valueStringData());
        }
        else {
            ctxt.throwMissingField(kCommandParameterFieldName);
        }
    }
}

SetFeatureCompatibilityVersion SetFeatureCompatibilityVersion::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto localCmdType = mongo::idl::preparsedValue<ServerGlobalParams::FeatureCompatibility::Version>();
    SetFeatureCompatibilityVersion object(localCmdType);
    object.parseProtected(ctxt, request);
    return object;
}
void SetFeatureCompatibilityVersion::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<5> usedFields;
    const size_t kDowngradeOnDiskChangesBit = 0;
    const size_t kFromConfigServerBit = 1;
    const size_t kPhaseBit = 2;
    const size_t kChangeTimestampBit = 3;
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

        if (fieldName == kDowngradeOnDiskChangesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kDowngradeOnDiskChangesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDowngradeOnDiskChangesBit);

                _downgradeOnDiskChanges = element.trueValue();
            }
        }
        else if (fieldName == kFromConfigServerFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kFromConfigServerBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kFromConfigServerBit);

                _fromConfigServer = element.trueValue();
            }
        }
        else if (fieldName == kPhaseFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kPhaseBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPhaseBit);

                IDLParserErrorContext tempContext(kPhaseFieldName, &ctxt);
                _phase = SetFCVPhase_parse(tempContext, element.valueStringData());
            }
        }
        else if (fieldName == kChangeTimestampFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, bsonTimestamp))) {
                if (MONGO_unlikely(usedFields[kChangeTimestampBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kChangeTimestampBit);

                _changeTimestamp = element.timestamp();
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

    {
        if (MONGO_likely(ctxt.checkAndAssertType(commandElement, String))) {
            _commandParameter = FeatureCompatibilityVersionParser::parseVersion(commandElement.valueStringData());
        }
        else {
            ctxt.throwMissingField(kCommandParameterFieldName);
        }
    }
}

void SetFeatureCompatibilityVersion::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    {
        builder->append(kCommandParameterFieldName, ::mongo::FeatureCompatibilityVersionParser::serializeVersion(_commandParameter));
    }
    if (_downgradeOnDiskChanges.is_initialized()) {
        builder->append(kDowngradeOnDiskChangesFieldName, _downgradeOnDiskChanges.get());
    }

    if (_fromConfigServer.is_initialized()) {
        builder->append(kFromConfigServerFieldName, _fromConfigServer.get());
    }

    if (_phase.is_initialized()) {
        builder->append(kPhaseFieldName, ::mongo::SetFCVPhase_serializer(_phase.get()));
    }

    if (_changeTimestamp.is_initialized()) {
        builder->append(kChangeTimestampFieldName, _changeTimestamp.get());
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest SetFeatureCompatibilityVersion::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        {
            builder->append(kCommandParameterFieldName, ::mongo::FeatureCompatibilityVersionParser::serializeVersion(_commandParameter));
        }
        if (_downgradeOnDiskChanges.is_initialized()) {
            builder->append(kDowngradeOnDiskChangesFieldName, _downgradeOnDiskChanges.get());
        }

        if (_fromConfigServer.is_initialized()) {
            builder->append(kFromConfigServerFieldName, _fromConfigServer.get());
        }

        if (_phase.is_initialized()) {
            builder->append(kPhaseFieldName, ::mongo::SetFCVPhase_serializer(_phase.get()));
        }

        if (_changeTimestamp.is_initialized()) {
            builder->append(kChangeTimestampFieldName, _changeTimestamp.get());
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj SetFeatureCompatibilityVersion::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
