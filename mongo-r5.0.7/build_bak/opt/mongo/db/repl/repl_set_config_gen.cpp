/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/repl/repl_set_config_gen.h --output build/opt/mongo/db/repl/repl_set_config_gen.cpp src/mongo/db/repl/repl_set_config.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/repl/repl_set_config_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {
namespace repl {

constexpr StringData ReplSetConfigSettings::kCatchUpTakeoverDelayMillisFieldName;
constexpr StringData ReplSetConfigSettings::kCatchUpTimeoutMillisFieldName;
constexpr StringData ReplSetConfigSettings::kChainingAllowedFieldName;
constexpr StringData ReplSetConfigSettings::kDefaultWriteConcernFieldName;
constexpr StringData ReplSetConfigSettings::kElectionTimeoutMillisFieldName;
constexpr StringData ReplSetConfigSettings::kGetLastErrorModesFieldName;
constexpr StringData ReplSetConfigSettings::kHeartbeatIntervalMillisFieldName;
constexpr StringData ReplSetConfigSettings::kHeartbeatTimeoutSecsFieldName;
constexpr StringData ReplSetConfigSettings::kReplicaSetIdFieldName;


ReplSetConfigSettings::ReplSetConfigSettings()  {
    // Used for initialization only
}

void ReplSetConfigSettings::validateHeartbeatIntervalMillis(IDLParserErrorContext& ctxt, const std::int64_t value)
{
    if (!(value > 0)) {
        throwComparisonError<std::int64_t>(ctxt, "heartbeatIntervalMillis", ">"_sd, value, 0);
    }
}

void ReplSetConfigSettings::validateHeartbeatIntervalMillis(const std::int64_t value)
{
    if (!(value > 0)) {
        throwComparisonError<std::int64_t>("heartbeatIntervalMillis", ">"_sd, value, 0);
    }
}

void ReplSetConfigSettings::validateHeartbeatTimeoutSecs(IDLParserErrorContext& ctxt, const std::int64_t value)
{
    if (!(value > 0)) {
        throwComparisonError<std::int64_t>(ctxt, "heartbeatTimeoutSecs", ">"_sd, value, 0);
    }
}

void ReplSetConfigSettings::validateHeartbeatTimeoutSecs(const std::int64_t value)
{
    if (!(value > 0)) {
        throwComparisonError<std::int64_t>("heartbeatTimeoutSecs", ">"_sd, value, 0);
    }
}

void ReplSetConfigSettings::validateElectionTimeoutMillis(IDLParserErrorContext& ctxt, const std::int64_t value)
{
    if (!(value > 0)) {
        throwComparisonError<std::int64_t>(ctxt, "electionTimeoutMillis", ">"_sd, value, 0);
    }
}

void ReplSetConfigSettings::validateElectionTimeoutMillis(const std::int64_t value)
{
    if (!(value > 0)) {
        throwComparisonError<std::int64_t>("electionTimeoutMillis", ">"_sd, value, 0);
    }
}

void ReplSetConfigSettings::validateCatchUpTimeoutMillis(IDLParserErrorContext& ctxt, const std::int64_t value)
{
    if (!(value >= -1)) {
        throwComparisonError<std::int64_t>(ctxt, "catchUpTimeoutMillis", ">="_sd, value, -1);
    }
}

void ReplSetConfigSettings::validateCatchUpTimeoutMillis(const std::int64_t value)
{
    if (!(value >= -1)) {
        throwComparisonError<std::int64_t>("catchUpTimeoutMillis", ">="_sd, value, -1);
    }
}

void ReplSetConfigSettings::validateCatchUpTakeoverDelayMillis(IDLParserErrorContext& ctxt, const std::int64_t value)
{
    if (!(value >= -1)) {
        throwComparisonError<std::int64_t>(ctxt, "catchUpTakeoverDelayMillis", ">="_sd, value, -1);
    }
}

void ReplSetConfigSettings::validateCatchUpTakeoverDelayMillis(const std::int64_t value)
{
    if (!(value >= -1)) {
        throwComparisonError<std::int64_t>("catchUpTakeoverDelayMillis", ">="_sd, value, -1);
    }
}

void ReplSetConfigSettings::validateDefaultWriteConcern(IDLParserErrorContext& ctxt, const mongo::WriteConcernOptions& value)
{
    uassertStatusOK(validateDefaultWriteConcernHasMember(value));
}

void ReplSetConfigSettings::validateDefaultWriteConcern(const mongo::WriteConcernOptions& value)
{
    uassertStatusOK(validateDefaultWriteConcernHasMember(value));
}

void ReplSetConfigSettings::validateReplicaSetId(IDLParserErrorContext& ctxt, const mongo::OID& value)
{
    uassertStatusOK(validateReplicaSetIdNotNull(value));
}

void ReplSetConfigSettings::validateReplicaSetId(const mongo::OID& value)
{
    uassertStatusOK(validateReplicaSetIdNotNull(value));
}


ReplSetConfigSettings ReplSetConfigSettings::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ReplSetConfigSettings>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ReplSetConfigSettings::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<9> usedFields;
    const size_t kChainingAllowedBit = 0;
    const size_t kHeartbeatIntervalMillisBit = 1;
    const size_t kHeartbeatTimeoutSecsBit = 2;
    const size_t kElectionTimeoutMillisBit = 3;
    const size_t kCatchUpTimeoutMillisBit = 4;
    const size_t kCatchUpTakeoverDelayMillisBit = 5;
    const size_t kGetLastErrorModesBit = 6;
    const size_t kDefaultWriteConcernBit = 7;
    const size_t kReplicaSetIdBit = 8;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kChainingAllowedFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kChainingAllowedBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kChainingAllowedBit);

                _chainingAllowed = element.trueValue();
            }
        }
        else if (fieldName == kHeartbeatIntervalMillisFieldName) {
            if (MONGO_unlikely(usedFields[kHeartbeatIntervalMillisBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kHeartbeatIntervalMillisBit);

            {
                auto value = parseSmallExactInt64(element);
                validateHeartbeatIntervalMillis(value);
                _heartbeatIntervalMillis = std::move(value);
            }
        }
        else if (fieldName == kHeartbeatTimeoutSecsFieldName) {
            if (MONGO_unlikely(usedFields[kHeartbeatTimeoutSecsBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kHeartbeatTimeoutSecsBit);

            {
                auto value = parseSmallExactInt64(element);
                validateHeartbeatTimeoutSecs(value);
                _heartbeatTimeoutSecs = std::move(value);
            }
        }
        else if (fieldName == kElectionTimeoutMillisFieldName) {
            if (MONGO_unlikely(usedFields[kElectionTimeoutMillisBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kElectionTimeoutMillisBit);

            {
                auto value = parseSmallExactInt64(element);
                validateElectionTimeoutMillis(value);
                _electionTimeoutMillis = std::move(value);
            }
        }
        else if (fieldName == kCatchUpTimeoutMillisFieldName) {
            if (MONGO_unlikely(usedFields[kCatchUpTimeoutMillisBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kCatchUpTimeoutMillisBit);

            {
                auto value = parseSmallExactInt64(element);
                validateCatchUpTimeoutMillis(value);
                _catchUpTimeoutMillis = std::move(value);
            }
        }
        else if (fieldName == kCatchUpTakeoverDelayMillisFieldName) {
            if (MONGO_unlikely(usedFields[kCatchUpTakeoverDelayMillisBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kCatchUpTakeoverDelayMillisBit);

            {
                auto value = parseSmallExactInt64(element);
                validateCatchUpTakeoverDelayMillis(value);
                _catchUpTakeoverDelayMillis = std::move(value);
            }
        }
        else if (fieldName == kGetLastErrorModesFieldName) {
            if (MONGO_unlikely(usedFields[kGetLastErrorModesBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kGetLastErrorModesBit);

            _getLastErrorModes = repl::ReplSetWriteConcernModeDefinitions::parseFromBSON(element);
        }
        else if (fieldName == kDefaultWriteConcernFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kDefaultWriteConcernBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDefaultWriteConcernBit);

                const BSONObj localObject = element.Obj();
                {
                    auto value = WriteConcernOptions::deserializerForIDL(localObject);
                    validateDefaultWriteConcern(value);
                    _defaultWriteConcern = std::move(value);
                }
            }
        }
        else if (fieldName == kReplicaSetIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, jstOID))) {
                if (MONGO_unlikely(usedFields[kReplicaSetIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kReplicaSetIdBit);

                {
                    auto value = element.OID();
                    validateReplicaSetId(value);
                    _replicaSetId = std::move(value);
                }
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
        if (!usedFields[kChainingAllowedBit]) {
            _chainingAllowed = true;
        }
        if (!usedFields[kHeartbeatIntervalMillisBit]) {
            _heartbeatIntervalMillis = 2000;
        }
        if (!usedFields[kHeartbeatTimeoutSecsBit]) {
            _heartbeatTimeoutSecs = 10;
        }
        if (!usedFields[kElectionTimeoutMillisBit]) {
            _electionTimeoutMillis = 10000;
        }
        if (!usedFields[kCatchUpTimeoutMillisBit]) {
            _catchUpTimeoutMillis = -1;
        }
        if (!usedFields[kCatchUpTakeoverDelayMillisBit]) {
            _catchUpTakeoverDelayMillis = 30000;
        }
        if (!usedFields[kGetLastErrorModesBit]) {
            _getLastErrorModes = ReplSetWriteConcernModeDefinitions();
        }
        if (!usedFields[kDefaultWriteConcernBit]) {
            _defaultWriteConcern = WriteConcernOptions();
        }
    }

}


void ReplSetConfigSettings::serialize(BSONObjBuilder* builder) const {
    builder->append(kChainingAllowedFieldName, _chainingAllowed);

    {
        smallExactInt64Append(_heartbeatIntervalMillis, kHeartbeatIntervalMillisFieldName, builder);
    }

    {
        smallExactInt64Append(_heartbeatTimeoutSecs, kHeartbeatTimeoutSecsFieldName, builder);
    }

    {
        smallExactInt64Append(_electionTimeoutMillis, kElectionTimeoutMillisFieldName, builder);
    }

    {
        smallExactInt64Append(_catchUpTimeoutMillis, kCatchUpTimeoutMillisFieldName, builder);
    }

    {
        smallExactInt64Append(_catchUpTakeoverDelayMillis, kCatchUpTakeoverDelayMillisFieldName, builder);
    }

    {
        _getLastErrorModes.serializeToBSON(kGetLastErrorModesFieldName, builder);
    }

    {
        const BSONObj localObject = _defaultWriteConcern.toBSON();
        builder->append(kDefaultWriteConcernFieldName, localObject);
    }

    if (_replicaSetId.is_initialized()) {
        builder->append(kReplicaSetIdFieldName, _replicaSetId.get());
    }

}


BSONObj ReplSetConfigSettings::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData ReplSetConfigBase::kConfigServerFieldName;
constexpr StringData ReplSetConfigBase::kConfigTermFieldName;
constexpr StringData ReplSetConfigBase::kConfigVersionFieldName;
constexpr StringData ReplSetConfigBase::kMembersFieldName;
constexpr StringData ReplSetConfigBase::kProtocolVersionFieldName;
constexpr StringData ReplSetConfigBase::kRepairedFieldName;
constexpr StringData ReplSetConfigBase::kReplSetNameFieldName;
constexpr StringData ReplSetConfigBase::kSettingsFieldName;
constexpr StringData ReplSetConfigBase::kWriteConcernMajorityShouldJournalFieldName;


ReplSetConfigBase::ReplSetConfigBase() : _replSetName(mongo::idl::preparsedValue<decltype(_replSetName)>()), _configVersion(mongo::idl::preparsedValue<decltype(_configVersion)>()), _hasReplSetName(false), _hasConfigVersion(false), _hasMembers(false) {
    // Used for initialization only
}
ReplSetConfigBase::ReplSetConfigBase(std::string replSetName, std::int64_t configVersion, std::vector<mongo::repl::MemberConfig> members) : _replSetName(std::move(replSetName)), _configVersion(std::move(configVersion)), _members(std::move(members)), _hasReplSetName(true), _hasConfigVersion(true), _hasMembers(true) {
    // Used for initialization only
}

void ReplSetConfigBase::validateReplSetName(IDLParserErrorContext& ctxt, const std::string& value)
{
    uassertStatusOK(validateReplSetNameNonEmpty(value));
}

void ReplSetConfigBase::validateReplSetName(const std::string& value)
{
    uassertStatusOK(validateReplSetNameNonEmpty(value));
}

void ReplSetConfigBase::validateConfigVersion(IDLParserErrorContext& ctxt, const std::int64_t value)
{
    if (!(value > 0)) {
        throwComparisonError<std::int64_t>(ctxt, "version", ">"_sd, value, 0);
    }
    if (!(value < 2147483648.0)) {
        throwComparisonError<std::int64_t>(ctxt, "version", "<"_sd, value, 2147483648.0);
    }
}

void ReplSetConfigBase::validateConfigVersion(const std::int64_t value)
{
    if (!(value > 0)) {
        throwComparisonError<std::int64_t>("version", ">"_sd, value, 0);
    }
    if (!(value < 2147483648.0)) {
        throwComparisonError<std::int64_t>("version", "<"_sd, value, 2147483648.0);
    }
}

void ReplSetConfigBase::validateConfigTerm(IDLParserErrorContext& ctxt, const std::int64_t value)
{
    if (!(value >= -1)) {
        throwComparisonError<std::int64_t>(ctxt, "term", ">="_sd, value, -1);
    }
    if (!(value < 2147483648.0)) {
        throwComparisonError<std::int64_t>(ctxt, "term", "<"_sd, value, 2147483648.0);
    }
}

void ReplSetConfigBase::validateConfigTerm(const std::int64_t value)
{
    if (!(value >= -1)) {
        throwComparisonError<std::int64_t>("term", ">="_sd, value, -1);
    }
    if (!(value < 2147483648.0)) {
        throwComparisonError<std::int64_t>("term", "<"_sd, value, 2147483648.0);
    }
}

void ReplSetConfigBase::validateProtocolVersion(IDLParserErrorContext& ctxt, const std::int64_t value)
{
    if (!(value >= 1)) {
        throwComparisonError<std::int64_t>(ctxt, "protocolVersion", ">="_sd, value, 1);
    }
    if (!(value <= 1)) {
        throwComparisonError<std::int64_t>(ctxt, "protocolVersion", "<="_sd, value, 1);
    }
}

void ReplSetConfigBase::validateProtocolVersion(const std::int64_t value)
{
    if (!(value >= 1)) {
        throwComparisonError<std::int64_t>("protocolVersion", ">="_sd, value, 1);
    }
    if (!(value <= 1)) {
        throwComparisonError<std::int64_t>("protocolVersion", "<="_sd, value, 1);
    }
}


ReplSetConfigBase ReplSetConfigBase::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ReplSetConfigBase>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ReplSetConfigBase::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<9> usedFields;
    const size_t kReplSetNameBit = 0;
    const size_t kConfigVersionBit = 1;
    const size_t kConfigTermBit = 2;
    const size_t kMembersBit = 3;
    const size_t kConfigServerBit = 4;
    const size_t kProtocolVersionBit = 5;
    const size_t kWriteConcernMajorityShouldJournalBit = 6;
    const size_t kSettingsBit = 7;
    const size_t kRepairedBit = 8;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kReplSetNameFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kReplSetNameBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kReplSetNameBit);

                _hasReplSetName = true;
                {
                    auto value = element.str();
                    validateReplSetName(value);
                    _replSetName = std::move(value);
                }
            }
        }
        else if (fieldName == kConfigVersionFieldName) {
            if (MONGO_unlikely(usedFields[kConfigVersionBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kConfigVersionBit);

            _hasConfigVersion = true;
            {
                auto value = parseSmallExactInt64(element);
                validateConfigVersion(value);
                _configVersion = std::move(value);
            }
        }
        else if (fieldName == kConfigTermFieldName) {
            if (MONGO_unlikely(usedFields[kConfigTermBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kConfigTermBit);

            {
                auto value = parseSmallExactInt64(element);
                validateConfigTerm(value);
                _configTerm = std::move(value);
            }
        }
        else if (fieldName == kMembersFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kMembersBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMembersBit);

                _hasMembers = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kMembersFieldName, &ctxt);
            std::vector<mongo::repl::MemberConfig> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, Object)) {
                        const BSONObj localObject = arrayElement.Obj();
                        values.emplace_back(repl::MemberConfig::parseFromBSON(localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _members = std::move(values);
        }
        else if (fieldName == kConfigServerFieldName) {
            if (MONGO_unlikely(usedFields[kConfigServerBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kConfigServerBit);

            _configServer = OptionalBool::parseFromBSON(element);
        }
        else if (fieldName == kProtocolVersionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kProtocolVersionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kProtocolVersionBit);

                {
                    auto value = element.safeNumberLong();
                    validateProtocolVersion(value);
                    _protocolVersion = std::move(value);
                }
            }
        }
        else if (fieldName == kWriteConcernMajorityShouldJournalFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kWriteConcernMajorityShouldJournalBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kWriteConcernMajorityShouldJournalBit);

                _writeConcernMajorityShouldJournal = element.trueValue();
            }
        }
        else if (fieldName == kSettingsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kSettingsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSettingsBit);

                IDLParserErrorContext tempContext(kSettingsFieldName, &ctxt);
                const auto localObject = element.Obj();
                _settings = mongo::repl::ReplSetConfigSettings::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kRepairedFieldName) {
            if (MONGO_unlikely(usedFields[kRepairedBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kRepairedBit);

            _repaired = OptionalBool::parseFromBSON(element);
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kReplSetNameBit]) {
            ctxt.throwMissingField(kReplSetNameFieldName);
        }
        if (!usedFields[kConfigVersionBit]) {
            ctxt.throwMissingField(kConfigVersionFieldName);
        }
        if (!usedFields[kConfigTermBit]) {
            _configTerm = -1;
        }
        if (!usedFields[kMembersBit]) {
            ctxt.throwMissingField(kMembersFieldName);
        }
        if (!usedFields[kConfigServerBit]) {
            _configServer = mongo::OptionalBool();
        }
        if (!usedFields[kProtocolVersionBit]) {
            _protocolVersion = 1;
        }
        if (!usedFields[kWriteConcernMajorityShouldJournalBit]) {
            _writeConcernMajorityShouldJournal = true;
        }
        if (!usedFields[kRepairedBit]) {
            _repaired = mongo::OptionalBool();
        }
    }

}


void ReplSetConfigBase::serialize(BSONObjBuilder* builder) const {
    invariant(_hasReplSetName && _hasConfigVersion && _hasMembers);

    builder->append(kReplSetNameFieldName, _replSetName);

    {
        smallExactInt64Append(_configVersion, kConfigVersionFieldName, builder);
    }

    {
        serializeTermField(_configTerm, kConfigTermFieldName, builder);
    }

    {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kMembersFieldName));
        for (const auto& item : _members) {
            const BSONObj localObject = item.toBSON();
            arrayBuilder.append(localObject);
        }
    }

    {
        serializeOptionalBoolIfTrue(_configServer, kConfigServerFieldName, builder);
    }

    builder->append(kProtocolVersionFieldName, _protocolVersion);

    builder->append(kWriteConcernMajorityShouldJournalFieldName, _writeConcernMajorityShouldJournal);

    if (_settings.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kSettingsFieldName));
        _settings.get().serialize(&subObjBuilder);
    }

    {
        _repaired.serializeToBSON(kRepairedFieldName, builder);
    }

}


BSONObj ReplSetConfigBase::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace repl
}  // namespace mongo
