/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/repl/member_config_gen.h --output build/opt/mongo/db/repl/member_config_gen.cpp src/mongo/db/repl/member_config.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/repl/member_config_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {
namespace repl {

constexpr StringData MemberConfigBase::kArbiterOnlyFieldName;
constexpr StringData MemberConfigBase::kBuildIndexesFieldName;
constexpr StringData MemberConfigBase::kHiddenFieldName;
constexpr StringData MemberConfigBase::kHorizonsFieldName;
constexpr StringData MemberConfigBase::kHostFieldName;
constexpr StringData MemberConfigBase::kIdFieldName;
constexpr StringData MemberConfigBase::kNewlyAddedFieldName;
constexpr StringData MemberConfigBase::kPriorityFieldName;
constexpr StringData MemberConfigBase::kSecondaryDelaySecsFieldName;
constexpr StringData MemberConfigBase::kSlaveDelaySecsFieldName;
constexpr StringData MemberConfigBase::kTagsFieldName;
constexpr StringData MemberConfigBase::kVotesFieldName;


MemberConfigBase::MemberConfigBase() : _id(mongo::idl::preparsedValue<decltype(_id)>()), _host(mongo::idl::preparsedValue<decltype(_host)>()), _hasId(false), _hasHost(false) {
    // Used for initialization only
}
MemberConfigBase::MemberConfigBase(mongo::repl::MemberId id, std::string host) : _id(std::move(id)), _host(std::move(host)), _hasId(true), _hasHost(true) {
    // Used for initialization only
}

void MemberConfigBase::validateVotes(IDLParserErrorContext& ctxt, const std::int64_t value)
{
    if (!(value >= 0)) {
        throwComparisonError<std::int64_t>(ctxt, "votes", ">="_sd, value, 0);
    }
    if (!(value <= 1)) {
        throwComparisonError<std::int64_t>(ctxt, "votes", "<="_sd, value, 1);
    }
}

void MemberConfigBase::validateVotes(const std::int64_t value)
{
    if (!(value >= 0)) {
        throwComparisonError<std::int64_t>("votes", ">="_sd, value, 0);
    }
    if (!(value <= 1)) {
        throwComparisonError<std::int64_t>("votes", "<="_sd, value, 1);
    }
}

void MemberConfigBase::validateNewlyAdded(IDLParserErrorContext& ctxt, const bool value)
{
    uassertStatusOK(validateTrue(value));
}

void MemberConfigBase::validateNewlyAdded(const bool value)
{
    uassertStatusOK(validateTrue(value));
}

void MemberConfigBase::validatePriority(IDLParserErrorContext& ctxt, const double value)
{
    if (!(value >= 0)) {
        throwComparisonError<double>(ctxt, "priority", ">="_sd, value, 0);
    }
    if (!(value <= 1000)) {
        throwComparisonError<double>(ctxt, "priority", "<="_sd, value, 1000);
    }
}

void MemberConfigBase::validatePriority(const double value)
{
    if (!(value >= 0)) {
        throwComparisonError<double>("priority", ">="_sd, value, 0);
    }
    if (!(value <= 1000)) {
        throwComparisonError<double>("priority", "<="_sd, value, 1000);
    }
}

void MemberConfigBase::validateSlaveDelaySecs(IDLParserErrorContext& ctxt, const std::int64_t value)
{
    if (!(value >= 0)) {
        throwComparisonError<std::int64_t>(ctxt, "slaveDelay", ">="_sd, value, 0);
    }
    if (!(value <= 31622400)) {
        throwComparisonError<std::int64_t>(ctxt, "slaveDelay", "<="_sd, value, 31622400);
    }
}

void MemberConfigBase::validateSlaveDelaySecs(const std::int64_t value)
{
    if (!(value >= 0)) {
        throwComparisonError<std::int64_t>("slaveDelay", ">="_sd, value, 0);
    }
    if (!(value <= 31622400)) {
        throwComparisonError<std::int64_t>("slaveDelay", "<="_sd, value, 31622400);
    }
}

void MemberConfigBase::validateSecondaryDelaySecs(IDLParserErrorContext& ctxt, const std::int64_t value)
{
    if (!(value >= 0)) {
        throwComparisonError<std::int64_t>(ctxt, "secondaryDelaySecs", ">="_sd, value, 0);
    }
    if (!(value <= 31622400)) {
        throwComparisonError<std::int64_t>(ctxt, "secondaryDelaySecs", "<="_sd, value, 31622400);
    }
}

void MemberConfigBase::validateSecondaryDelaySecs(const std::int64_t value)
{
    if (!(value >= 0)) {
        throwComparisonError<std::int64_t>("secondaryDelaySecs", ">="_sd, value, 0);
    }
    if (!(value <= 31622400)) {
        throwComparisonError<std::int64_t>("secondaryDelaySecs", "<="_sd, value, 31622400);
    }
}


MemberConfigBase MemberConfigBase::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<MemberConfigBase>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void MemberConfigBase::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<12> usedFields;
    const size_t kIdBit = 0;
    const size_t kHostBit = 1;
    const size_t kVotesBit = 2;
    const size_t kNewlyAddedBit = 3;
    const size_t kPriorityBit = 4;
    const size_t kHiddenBit = 5;
    const size_t kSlaveDelaySecsBit = 6;
    const size_t kSecondaryDelaySecsBit = 7;
    const size_t kArbiterOnlyBit = 8;
    const size_t kBuildIndexesBit = 9;
    const size_t kTagsBit = 10;
    const size_t kHorizonsBit = 11;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kIdFieldName) {
            if (MONGO_unlikely(usedFields[kIdBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kIdBit);

            _hasId = true;
            _id = repl::MemberId::parseFromBSON(element);
        }
        else if (fieldName == kHostFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kHostBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kHostBit);

                _hasHost = true;
                _host = element.str();
            }
        }
        else if (fieldName == kVotesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kVotesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kVotesBit);

                {
                    auto value = element.safeNumberLong();
                    validateVotes(value);
                    _votes = std::move(value);
                }
            }
        }
        else if (fieldName == kNewlyAddedFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kNewlyAddedBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNewlyAddedBit);

                {
                    auto value = element.boolean();
                    validateNewlyAdded(value);
                    _newlyAdded = std::move(value);
                }
            }
        }
        else if (fieldName == kPriorityFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kPriorityBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPriorityBit);

                {
                    auto value = element.safeNumberDouble();
                    validatePriority(value);
                    _priority = std::move(value);
                }
            }
        }
        else if (fieldName == kHiddenFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kHiddenBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kHiddenBit);

                _hidden = element.trueValue();
            }
        }
        else if (fieldName == kSlaveDelaySecsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kSlaveDelaySecsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSlaveDelaySecsBit);

                {
                    auto value = element.safeNumberLong();
                    validateSlaveDelaySecs(value);
                    _slaveDelaySecs = std::move(value);
                }
            }
        }
        else if (fieldName == kSecondaryDelaySecsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kSecondaryDelaySecsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSecondaryDelaySecsBit);

                {
                    auto value = element.safeNumberLong();
                    validateSecondaryDelaySecs(value);
                    _secondaryDelaySecs = std::move(value);
                }
            }
        }
        else if (fieldName == kArbiterOnlyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kArbiterOnlyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kArbiterOnlyBit);

                _arbiterOnly = element.trueValue();
            }
        }
        else if (fieldName == kBuildIndexesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kBuildIndexesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kBuildIndexesBit);

                _buildIndexes = element.trueValue();
            }
        }
        else if (fieldName == kTagsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kTagsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTagsBit);

                const BSONObj localObject = element.Obj();
                _tags = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kHorizonsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kHorizonsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kHorizonsBit);

                _horizons = element.Obj();
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kIdBit]) {
            ctxt.throwMissingField(kIdFieldName);
        }
        if (!usedFields[kHostBit]) {
            ctxt.throwMissingField(kHostFieldName);
        }
        if (!usedFields[kVotesBit]) {
            _votes = 1;
        }
        if (!usedFields[kPriorityBit]) {
            _priority = 1.0;
        }
        if (!usedFields[kHiddenBit]) {
            _hidden = false;
        }
        if (!usedFields[kArbiterOnlyBit]) {
            _arbiterOnly = false;
        }
        if (!usedFields[kBuildIndexesBit]) {
            _buildIndexes = true;
        }
    }

}


void MemberConfigBase::serialize(BSONObjBuilder* builder) const {
    invariant(_hasId && _hasHost);

    {
        _id.serializeToBSON(kIdFieldName, builder);
    }

    builder->append(kHostFieldName, _host);

    builder->append(kVotesFieldName, _votes);

    if (_newlyAdded.is_initialized()) {
        builder->append(kNewlyAddedFieldName, _newlyAdded.get());
    }

    builder->append(kPriorityFieldName, _priority);

    builder->append(kHiddenFieldName, _hidden);

    if (_slaveDelaySecs.is_initialized()) {
        builder->append(kSlaveDelaySecsFieldName, _slaveDelaySecs.get());
    }

    if (_secondaryDelaySecs.is_initialized()) {
        builder->append(kSecondaryDelaySecsFieldName, _secondaryDelaySecs.get());
    }

    builder->append(kArbiterOnlyFieldName, _arbiterOnly);

    builder->append(kBuildIndexesFieldName, _buildIndexes);

    if (_tags.is_initialized()) {
        builder->append(kTagsFieldName, _tags.get());
    }

    if (_horizons.is_initialized()) {
        builder->append(kHorizonsFieldName, _horizons.get());
    }

}


BSONObj MemberConfigBase::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace repl
}  // namespace mongo
