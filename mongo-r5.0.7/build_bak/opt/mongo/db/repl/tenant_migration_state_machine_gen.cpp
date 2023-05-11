/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/repl/tenant_migration_state_machine_gen.h --output build/opt/mongo/db/repl/tenant_migration_state_machine_gen.cpp src/mongo/db/repl/tenant_migration_state_machine.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/repl/tenant_migration_state_machine_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

/**
 * The state of an in-progress tenant migration.
 */
namespace  {
constexpr StringData kTenantMigrationDonorState_kUninitialized = "uninitialized"_sd;
constexpr StringData kTenantMigrationDonorState_kAbortingIndexBuilds = "aborting index builds"_sd;
constexpr StringData kTenantMigrationDonorState_kDataSync = "data sync"_sd;
constexpr StringData kTenantMigrationDonorState_kBlocking = "blocking"_sd;
constexpr StringData kTenantMigrationDonorState_kCommitted = "committed"_sd;
constexpr StringData kTenantMigrationDonorState_kAborted = "aborted"_sd;
}  // namespace 

TenantMigrationDonorStateEnum TenantMigrationDonorState_parse(const IDLParserErrorContext& ctxt, StringData value) {
    if (value == kTenantMigrationDonorState_kUninitialized) {
        return TenantMigrationDonorStateEnum::kUninitialized;
    }
    if (value == kTenantMigrationDonorState_kAbortingIndexBuilds) {
        return TenantMigrationDonorStateEnum::kAbortingIndexBuilds;
    }
    if (value == kTenantMigrationDonorState_kDataSync) {
        return TenantMigrationDonorStateEnum::kDataSync;
    }
    if (value == kTenantMigrationDonorState_kBlocking) {
        return TenantMigrationDonorStateEnum::kBlocking;
    }
    if (value == kTenantMigrationDonorState_kCommitted) {
        return TenantMigrationDonorStateEnum::kCommitted;
    }
    if (value == kTenantMigrationDonorState_kAborted) {
        return TenantMigrationDonorStateEnum::kAborted;
    }
    ctxt.throwBadEnumValue(value);
}

StringData TenantMigrationDonorState_serializer(TenantMigrationDonorStateEnum value) {
    if (value == TenantMigrationDonorStateEnum::kUninitialized) {
        return kTenantMigrationDonorState_kUninitialized;
    }
    if (value == TenantMigrationDonorStateEnum::kAbortingIndexBuilds) {
        return kTenantMigrationDonorState_kAbortingIndexBuilds;
    }
    if (value == TenantMigrationDonorStateEnum::kDataSync) {
        return kTenantMigrationDonorState_kDataSync;
    }
    if (value == TenantMigrationDonorStateEnum::kBlocking) {
        return kTenantMigrationDonorState_kBlocking;
    }
    if (value == TenantMigrationDonorStateEnum::kCommitted) {
        return kTenantMigrationDonorState_kCommitted;
    }
    if (value == TenantMigrationDonorStateEnum::kAborted) {
        return kTenantMigrationDonorState_kAborted;
    }
    MONGO_UNREACHABLE;
    return StringData();
}

/**
 * The state of an tenant migration on recipient side.
 */
namespace  {
constexpr StringData kTenantMigrationRecipientState_kUninitialized = "uninitialized"_sd;
constexpr StringData kTenantMigrationRecipientState_kStarted = "started"_sd;
constexpr StringData kTenantMigrationRecipientState_kConsistent = "consistent"_sd;
constexpr StringData kTenantMigrationRecipientState_kDone = "done"_sd;
}  // namespace 

TenantMigrationRecipientStateEnum TenantMigrationRecipientState_parse(const IDLParserErrorContext& ctxt, StringData value) {
    if (value == kTenantMigrationRecipientState_kUninitialized) {
        return TenantMigrationRecipientStateEnum::kUninitialized;
    }
    if (value == kTenantMigrationRecipientState_kStarted) {
        return TenantMigrationRecipientStateEnum::kStarted;
    }
    if (value == kTenantMigrationRecipientState_kConsistent) {
        return TenantMigrationRecipientStateEnum::kConsistent;
    }
    if (value == kTenantMigrationRecipientState_kDone) {
        return TenantMigrationRecipientStateEnum::kDone;
    }
    ctxt.throwBadEnumValue(value);
}

StringData TenantMigrationRecipientState_serializer(TenantMigrationRecipientStateEnum value) {
    if (value == TenantMigrationRecipientStateEnum::kUninitialized) {
        return kTenantMigrationRecipientState_kUninitialized;
    }
    if (value == TenantMigrationRecipientStateEnum::kStarted) {
        return kTenantMigrationRecipientState_kStarted;
    }
    if (value == TenantMigrationRecipientStateEnum::kConsistent) {
        return kTenantMigrationRecipientState_kConsistent;
    }
    if (value == TenantMigrationRecipientStateEnum::kDone) {
        return kTenantMigrationRecipientState_kDone;
    }
    MONGO_UNREACHABLE;
    return StringData();
}

constexpr StringData TenantMigrationDonorDocument::kAbortReasonFieldName;
constexpr StringData TenantMigrationDonorDocument::kBlockTimestampFieldName;
constexpr StringData TenantMigrationDonorDocument::kCommitOrAbortOpTimeFieldName;
constexpr StringData TenantMigrationDonorDocument::kDonorCertificateForRecipientFieldName;
constexpr StringData TenantMigrationDonorDocument::kExpireAtFieldName;
constexpr StringData TenantMigrationDonorDocument::kIdFieldName;
constexpr StringData TenantMigrationDonorDocument::kMigrationStartFieldName;
constexpr StringData TenantMigrationDonorDocument::kReadPreferenceFieldName;
constexpr StringData TenantMigrationDonorDocument::kRecipientCertificateForDonorFieldName;
constexpr StringData TenantMigrationDonorDocument::kRecipientConnectionStringFieldName;
constexpr StringData TenantMigrationDonorDocument::kStartMigrationDonorTimestampFieldName;
constexpr StringData TenantMigrationDonorDocument::kStateFieldName;
constexpr StringData TenantMigrationDonorDocument::kTenantIdFieldName;


TenantMigrationDonorDocument::TenantMigrationDonorDocument() : _id(mongo::idl::preparsedValue<decltype(_id)>()), _recipientConnectionString(mongo::idl::preparsedValue<decltype(_recipientConnectionString)>()), _readPreference(mongo::idl::preparsedValue<decltype(_readPreference)>()), _tenantId(mongo::idl::preparsedValue<decltype(_tenantId)>()), _hasId(false), _hasRecipientConnectionString(false), _hasReadPreference(false), _hasTenantId(false) {
    // Used for initialization only
}
TenantMigrationDonorDocument::TenantMigrationDonorDocument(mongo::UUID id, std::string recipientConnectionString, mongo::ReadPreferenceSetting readPreference, std::string tenantId) : _id(std::move(id)), _recipientConnectionString(std::move(recipientConnectionString)), _readPreference(std::move(readPreference)), _tenantId(std::move(tenantId)), _hasId(true), _hasRecipientConnectionString(true), _hasReadPreference(true), _hasTenantId(true) {
    // Used for initialization only
}

void TenantMigrationDonorDocument::validateRecipientConnectionString(IDLParserErrorContext& ctxt, const std::string& value)
{
    uassertStatusOK(tenant_migration_util::validateConnectionString(value));
}

void TenantMigrationDonorDocument::validateRecipientConnectionString(const std::string& value)
{
    uassertStatusOK(tenant_migration_util::validateConnectionString(value));
}

void TenantMigrationDonorDocument::validateStartMigrationDonorTimestamp(IDLParserErrorContext& ctxt, const mongo::Timestamp& value)
{
    uassertStatusOK(tenant_migration_util::validateTimestampNotNull(value));
}

void TenantMigrationDonorDocument::validateStartMigrationDonorTimestamp(const mongo::Timestamp& value)
{
    uassertStatusOK(tenant_migration_util::validateTimestampNotNull(value));
}


TenantMigrationDonorDocument TenantMigrationDonorDocument::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<TenantMigrationDonorDocument>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void TenantMigrationDonorDocument::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<13> usedFields;
    const size_t kIdBit = 0;
    const size_t kRecipientConnectionStringBit = 1;
    const size_t kReadPreferenceBit = 2;
    const size_t kTenantIdBit = 3;
    const size_t kStateBit = 4;
    const size_t kBlockTimestampBit = 5;
    const size_t kCommitOrAbortOpTimeBit = 6;
    const size_t kAbortReasonBit = 7;
    const size_t kExpireAtBit = 8;
    const size_t kDonorCertificateForRecipientBit = 9;
    const size_t kRecipientCertificateForDonorBit = 10;
    const size_t kStartMigrationDonorTimestampBit = 11;
    const size_t kMigrationStartBit = 12;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIdBit);

                _hasId = true;
                _id = UUID(uassertStatusOK(UUID::parse(element)));
            }
        }
        else if (fieldName == kRecipientConnectionStringFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kRecipientConnectionStringBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRecipientConnectionStringBit);

                _hasRecipientConnectionString = true;
                {
                    auto value = element.str();
                    validateRecipientConnectionString(value);
                    _recipientConnectionString = std::move(value);
                }
            }
        }
        else if (fieldName == kReadPreferenceFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kReadPreferenceBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kReadPreferenceBit);

                _hasReadPreference = true;
                const BSONObj localObject = element.Obj();
                _readPreference = ReadPreferenceSetting::fromInnerBSONForIDL(localObject);
            }
        }
        else if (fieldName == kTenantIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kTenantIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTenantIdBit);

                _hasTenantId = true;
                _tenantId = element.str();
            }
        }
        else if (fieldName == kStateFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kStateBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStateBit);

                IDLParserErrorContext tempContext(kStateFieldName, &ctxt);
                _state = TenantMigrationDonorState_parse(tempContext, element.valueStringData());
            }
        }
        else if (fieldName == kBlockTimestampFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, bsonTimestamp))) {
                if (MONGO_unlikely(usedFields[kBlockTimestampBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kBlockTimestampBit);

                _blockTimestamp = element.timestamp();
            }
        }
        else if (fieldName == kCommitOrAbortOpTimeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCommitOrAbortOpTimeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCommitOrAbortOpTimeBit);

                const BSONObj localObject = element.Obj();
                _commitOrAbortOpTime = repl::OpTime::parse(localObject);
            }
        }
        else if (fieldName == kAbortReasonFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kAbortReasonBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAbortReasonBit);

                const BSONObj localObject = element.Obj();
                _abortReason = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kExpireAtFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Date))) {
                if (MONGO_unlikely(usedFields[kExpireAtBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kExpireAtBit);

                _expireAt = element.date();
            }
        }
        else if (fieldName == kDonorCertificateForRecipientFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kDonorCertificateForRecipientBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDonorCertificateForRecipientBit);

                IDLParserErrorContext tempContext(kDonorCertificateForRecipientFieldName, &ctxt);
                const auto localObject = element.Obj();
                _donorCertificateForRecipient = mongo::TenantMigrationPEMPayload::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kRecipientCertificateForDonorFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kRecipientCertificateForDonorBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRecipientCertificateForDonorBit);

                IDLParserErrorContext tempContext(kRecipientCertificateForDonorFieldName, &ctxt);
                const auto localObject = element.Obj();
                _recipientCertificateForDonor = mongo::TenantMigrationPEMPayload::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kStartMigrationDonorTimestampFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, bsonTimestamp))) {
                if (MONGO_unlikely(usedFields[kStartMigrationDonorTimestampBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStartMigrationDonorTimestampBit);

                {
                    auto value = element.timestamp();
                    validateStartMigrationDonorTimestamp(value);
                    _startMigrationDonorTimestamp = std::move(value);
                }
            }
        }
        else if (fieldName == kMigrationStartFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Date))) {
                if (MONGO_unlikely(usedFields[kMigrationStartBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMigrationStartBit);

                _migrationStart = element.date();
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
        if (!usedFields[kRecipientConnectionStringBit]) {
            ctxt.throwMissingField(kRecipientConnectionStringFieldName);
        }
        if (!usedFields[kReadPreferenceBit]) {
            ctxt.throwMissingField(kReadPreferenceFieldName);
        }
        if (!usedFields[kTenantIdBit]) {
            ctxt.throwMissingField(kTenantIdFieldName);
        }
        if (!usedFields[kStateBit]) {
            _state = mongo::TenantMigrationDonorStateEnum::kUninitialized;
        }
    }

}


void TenantMigrationDonorDocument::serialize(BSONObjBuilder* builder) const {
    invariant(_hasId && _hasRecipientConnectionString && _hasReadPreference && _hasTenantId);

    {
        ConstDataRange tempCDR = _id.toCDR();
        builder->append(kIdFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    builder->append(kRecipientConnectionStringFieldName, _recipientConnectionString);

    {
        const BSONObj localObject = _readPreference.toInnerBSON();
        builder->append(kReadPreferenceFieldName, localObject);
    }

    builder->append(kTenantIdFieldName, _tenantId);

    {
        builder->append(kStateFieldName, ::mongo::TenantMigrationDonorState_serializer(_state));
    }

    if (_blockTimestamp.is_initialized()) {
        builder->append(kBlockTimestampFieldName, _blockTimestamp.get());
    }

    if (_commitOrAbortOpTime.is_initialized()) {
        const BSONObj localObject = _commitOrAbortOpTime.get().toBSON();
        builder->append(kCommitOrAbortOpTimeFieldName, localObject);
    }

    if (_abortReason.is_initialized()) {
        builder->append(kAbortReasonFieldName, _abortReason.get());
    }

    if (_expireAt.is_initialized()) {
        builder->append(kExpireAtFieldName, _expireAt.get());
    }

    if (_donorCertificateForRecipient.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kDonorCertificateForRecipientFieldName));
        _donorCertificateForRecipient.get().serialize(&subObjBuilder);
    }

    if (_recipientCertificateForDonor.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kRecipientCertificateForDonorFieldName));
        _recipientCertificateForDonor.get().serialize(&subObjBuilder);
    }

    if (_startMigrationDonorTimestamp.is_initialized()) {
        builder->append(kStartMigrationDonorTimestampFieldName, _startMigrationDonorTimestamp.get());
    }

    if (_migrationStart.is_initialized()) {
        builder->append(kMigrationStartFieldName, _migrationStart.get());
    }

}


BSONObj TenantMigrationDonorDocument::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData TenantMigrationRecipientDocument::kCloneFinishedRecipientOpTimeFieldName;
constexpr StringData TenantMigrationRecipientDocument::kCompletedFetchingRetryableWritesBeforeStartOpTimeFieldName;
constexpr StringData TenantMigrationRecipientDocument::kCompletedUpdatingTransactionsBeforeStartOpTimeFieldName;
constexpr StringData TenantMigrationRecipientDocument::kDataConsistentStopDonorOpTimeFieldName;
constexpr StringData TenantMigrationRecipientDocument::kDonorConnectionStringFieldName;
constexpr StringData TenantMigrationRecipientDocument::kExpireAtFieldName;
constexpr StringData TenantMigrationRecipientDocument::kIdFieldName;
constexpr StringData TenantMigrationRecipientDocument::kNumRestartsDueToDonorConnectionFailureFieldName;
constexpr StringData TenantMigrationRecipientDocument::kNumRestartsDueToRecipientFailureFieldName;
constexpr StringData TenantMigrationRecipientDocument::kReadPreferenceFieldName;
constexpr StringData TenantMigrationRecipientDocument::kRecipientCertificateForDonorFieldName;
constexpr StringData TenantMigrationRecipientDocument::kRecipientPrimaryStartingFCVFieldName;
constexpr StringData TenantMigrationRecipientDocument::kRejectReadsBeforeTimestampFieldName;
constexpr StringData TenantMigrationRecipientDocument::kStartApplyingDonorOpTimeFieldName;
constexpr StringData TenantMigrationRecipientDocument::kStartAtFieldName;
constexpr StringData TenantMigrationRecipientDocument::kStartFetchingDonorOpTimeFieldName;
constexpr StringData TenantMigrationRecipientDocument::kStartMigrationDonorTimestampFieldName;
constexpr StringData TenantMigrationRecipientDocument::kStateFieldName;
constexpr StringData TenantMigrationRecipientDocument::kTenantIdFieldName;


TenantMigrationRecipientDocument::TenantMigrationRecipientDocument() : _id(mongo::idl::preparsedValue<decltype(_id)>()), _donorConnectionString(mongo::idl::preparsedValue<decltype(_donorConnectionString)>()), _tenantId(mongo::idl::preparsedValue<decltype(_tenantId)>()), _startMigrationDonorTimestamp(mongo::idl::preparsedValue<decltype(_startMigrationDonorTimestamp)>()), _readPreference(mongo::idl::preparsedValue<decltype(_readPreference)>()), _hasId(false), _hasDonorConnectionString(false), _hasTenantId(false), _hasStartMigrationDonorTimestamp(false), _hasReadPreference(false) {
    // Used for initialization only
}
TenantMigrationRecipientDocument::TenantMigrationRecipientDocument(mongo::UUID id, std::string donorConnectionString, std::string tenantId, mongo::Timestamp startMigrationDonorTimestamp, mongo::ReadPreferenceSetting readPreference) : _id(std::move(id)), _donorConnectionString(std::move(donorConnectionString)), _tenantId(std::move(tenantId)), _startMigrationDonorTimestamp(std::move(startMigrationDonorTimestamp)), _readPreference(std::move(readPreference)), _hasId(true), _hasDonorConnectionString(true), _hasTenantId(true), _hasStartMigrationDonorTimestamp(true), _hasReadPreference(true) {
    // Used for initialization only
}

void TenantMigrationRecipientDocument::validateDonorConnectionString(IDLParserErrorContext& ctxt, const std::string& value)
{
    uassertStatusOK(tenant_migration_util::validateConnectionString(value));
}

void TenantMigrationRecipientDocument::validateDonorConnectionString(const std::string& value)
{
    uassertStatusOK(tenant_migration_util::validateConnectionString(value));
}

void TenantMigrationRecipientDocument::validateTenantId(IDLParserErrorContext& ctxt, const std::string& value)
{
    uassertStatusOK(tenant_migration_util::validateDatabasePrefix(value));
}

void TenantMigrationRecipientDocument::validateTenantId(const std::string& value)
{
    uassertStatusOK(tenant_migration_util::validateDatabasePrefix(value));
}

void TenantMigrationRecipientDocument::validateStartMigrationDonorTimestamp(IDLParserErrorContext& ctxt, const mongo::Timestamp& value)
{
    uassertStatusOK(tenant_migration_util::validateTimestampNotNull(value));
}

void TenantMigrationRecipientDocument::validateStartMigrationDonorTimestamp(const mongo::Timestamp& value)
{
    uassertStatusOK(tenant_migration_util::validateTimestampNotNull(value));
}


TenantMigrationRecipientDocument TenantMigrationRecipientDocument::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<TenantMigrationRecipientDocument>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void TenantMigrationRecipientDocument::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<19> usedFields;
    const size_t kIdBit = 0;
    const size_t kDonorConnectionStringBit = 1;
    const size_t kTenantIdBit = 2;
    const size_t kStartMigrationDonorTimestampBit = 3;
    const size_t kReadPreferenceBit = 4;
    const size_t kStateBit = 5;
    const size_t kExpireAtBit = 6;
    const size_t kStartApplyingDonorOpTimeBit = 7;
    const size_t kStartFetchingDonorOpTimeBit = 8;
    const size_t kDataConsistentStopDonorOpTimeBit = 9;
    const size_t kRejectReadsBeforeTimestampBit = 10;
    const size_t kCloneFinishedRecipientOpTimeBit = 11;
    const size_t kRecipientCertificateForDonorBit = 12;
    const size_t kRecipientPrimaryStartingFCVBit = 13;
    const size_t kNumRestartsDueToDonorConnectionFailureBit = 14;
    const size_t kNumRestartsDueToRecipientFailureBit = 15;
    const size_t kCompletedUpdatingTransactionsBeforeStartOpTimeBit = 16;
    const size_t kCompletedFetchingRetryableWritesBeforeStartOpTimeBit = 17;
    const size_t kStartAtBit = 18;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIdBit);

                _hasId = true;
                _id = UUID(uassertStatusOK(UUID::parse(element)));
            }
        }
        else if (fieldName == kDonorConnectionStringFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kDonorConnectionStringBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDonorConnectionStringBit);

                _hasDonorConnectionString = true;
                {
                    auto value = element.str();
                    validateDonorConnectionString(value);
                    _donorConnectionString = std::move(value);
                }
            }
        }
        else if (fieldName == kTenantIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kTenantIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTenantIdBit);

                _hasTenantId = true;
                {
                    auto value = element.str();
                    validateTenantId(value);
                    _tenantId = std::move(value);
                }
            }
        }
        else if (fieldName == kStartMigrationDonorTimestampFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, bsonTimestamp))) {
                if (MONGO_unlikely(usedFields[kStartMigrationDonorTimestampBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStartMigrationDonorTimestampBit);

                _hasStartMigrationDonorTimestamp = true;
                {
                    auto value = element.timestamp();
                    validateStartMigrationDonorTimestamp(value);
                    _startMigrationDonorTimestamp = std::move(value);
                }
            }
        }
        else if (fieldName == kReadPreferenceFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kReadPreferenceBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kReadPreferenceBit);

                _hasReadPreference = true;
                const BSONObj localObject = element.Obj();
                _readPreference = ReadPreferenceSetting::fromInnerBSONForIDL(localObject);
            }
        }
        else if (fieldName == kStateFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kStateBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStateBit);

                IDLParserErrorContext tempContext(kStateFieldName, &ctxt);
                _state = TenantMigrationRecipientState_parse(tempContext, element.valueStringData());
            }
        }
        else if (fieldName == kExpireAtFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Date))) {
                if (MONGO_unlikely(usedFields[kExpireAtBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kExpireAtBit);

                _expireAt = element.date();
            }
        }
        else if (fieldName == kStartApplyingDonorOpTimeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kStartApplyingDonorOpTimeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStartApplyingDonorOpTimeBit);

                const BSONObj localObject = element.Obj();
                _startApplyingDonorOpTime = repl::OpTime::parse(localObject);
            }
        }
        else if (fieldName == kStartFetchingDonorOpTimeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kStartFetchingDonorOpTimeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStartFetchingDonorOpTimeBit);

                const BSONObj localObject = element.Obj();
                _startFetchingDonorOpTime = repl::OpTime::parse(localObject);
            }
        }
        else if (fieldName == kDataConsistentStopDonorOpTimeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kDataConsistentStopDonorOpTimeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDataConsistentStopDonorOpTimeBit);

                const BSONObj localObject = element.Obj();
                _dataConsistentStopDonorOpTime = repl::OpTime::parse(localObject);
            }
        }
        else if (fieldName == kRejectReadsBeforeTimestampFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, bsonTimestamp))) {
                if (MONGO_unlikely(usedFields[kRejectReadsBeforeTimestampBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRejectReadsBeforeTimestampBit);

                _rejectReadsBeforeTimestamp = element.timestamp();
            }
        }
        else if (fieldName == kCloneFinishedRecipientOpTimeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCloneFinishedRecipientOpTimeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCloneFinishedRecipientOpTimeBit);

                const BSONObj localObject = element.Obj();
                _cloneFinishedRecipientOpTime = repl::OpTime::parse(localObject);
            }
        }
        else if (fieldName == kRecipientCertificateForDonorFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kRecipientCertificateForDonorBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRecipientCertificateForDonorBit);

                IDLParserErrorContext tempContext(kRecipientCertificateForDonorFieldName, &ctxt);
                const auto localObject = element.Obj();
                _recipientCertificateForDonor = mongo::TenantMigrationPEMPayload::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kRecipientPrimaryStartingFCVFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kRecipientPrimaryStartingFCVBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRecipientPrimaryStartingFCVBit);

                _recipientPrimaryStartingFCV = FeatureCompatibilityVersionParser::parseVersion(element.valueStringData());
            }
        }
        else if (fieldName == kNumRestartsDueToDonorConnectionFailureFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kNumRestartsDueToDonorConnectionFailureBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNumRestartsDueToDonorConnectionFailureBit);

                _numRestartsDueToDonorConnectionFailure = element._numberLong();
            }
        }
        else if (fieldName == kNumRestartsDueToRecipientFailureFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kNumRestartsDueToRecipientFailureBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNumRestartsDueToRecipientFailureBit);

                _numRestartsDueToRecipientFailure = element._numberLong();
            }
        }
        else if (fieldName == kCompletedUpdatingTransactionsBeforeStartOpTimeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kCompletedUpdatingTransactionsBeforeStartOpTimeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCompletedUpdatingTransactionsBeforeStartOpTimeBit);

                _completedUpdatingTransactionsBeforeStartOpTime = element.boolean();
            }
        }
        else if (fieldName == kCompletedFetchingRetryableWritesBeforeStartOpTimeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kCompletedFetchingRetryableWritesBeforeStartOpTimeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCompletedFetchingRetryableWritesBeforeStartOpTimeBit);

                _completedFetchingRetryableWritesBeforeStartOpTime = element.boolean();
            }
        }
        else if (fieldName == kStartAtFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Date))) {
                if (MONGO_unlikely(usedFields[kStartAtBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStartAtBit);

                _startAt = element.date();
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
        if (!usedFields[kDonorConnectionStringBit]) {
            ctxt.throwMissingField(kDonorConnectionStringFieldName);
        }
        if (!usedFields[kTenantIdBit]) {
            ctxt.throwMissingField(kTenantIdFieldName);
        }
        if (!usedFields[kStartMigrationDonorTimestampBit]) {
            ctxt.throwMissingField(kStartMigrationDonorTimestampFieldName);
        }
        if (!usedFields[kReadPreferenceBit]) {
            ctxt.throwMissingField(kReadPreferenceFieldName);
        }
        if (!usedFields[kStateBit]) {
            _state = mongo::TenantMigrationRecipientStateEnum::kUninitialized;
        }
        if (!usedFields[kNumRestartsDueToDonorConnectionFailureBit]) {
            _numRestartsDueToDonorConnectionFailure = 0;
        }
        if (!usedFields[kNumRestartsDueToRecipientFailureBit]) {
            _numRestartsDueToRecipientFailure = 0;
        }
        if (!usedFields[kCompletedUpdatingTransactionsBeforeStartOpTimeBit]) {
            _completedUpdatingTransactionsBeforeStartOpTime = false;
        }
        if (!usedFields[kCompletedFetchingRetryableWritesBeforeStartOpTimeBit]) {
            _completedFetchingRetryableWritesBeforeStartOpTime = false;
        }
    }

}


void TenantMigrationRecipientDocument::serialize(BSONObjBuilder* builder) const {
    invariant(_hasId && _hasDonorConnectionString && _hasTenantId && _hasStartMigrationDonorTimestamp && _hasReadPreference);

    {
        ConstDataRange tempCDR = _id.toCDR();
        builder->append(kIdFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    builder->append(kDonorConnectionStringFieldName, _donorConnectionString);

    builder->append(kTenantIdFieldName, _tenantId);

    builder->append(kStartMigrationDonorTimestampFieldName, _startMigrationDonorTimestamp);

    {
        const BSONObj localObject = _readPreference.toInnerBSON();
        builder->append(kReadPreferenceFieldName, localObject);
    }

    {
        builder->append(kStateFieldName, ::mongo::TenantMigrationRecipientState_serializer(_state));
    }

    if (_expireAt.is_initialized()) {
        builder->append(kExpireAtFieldName, _expireAt.get());
    }

    if (_startApplyingDonorOpTime.is_initialized()) {
        const BSONObj localObject = _startApplyingDonorOpTime.get().toBSON();
        builder->append(kStartApplyingDonorOpTimeFieldName, localObject);
    }

    if (_startFetchingDonorOpTime.is_initialized()) {
        const BSONObj localObject = _startFetchingDonorOpTime.get().toBSON();
        builder->append(kStartFetchingDonorOpTimeFieldName, localObject);
    }

    if (_dataConsistentStopDonorOpTime.is_initialized()) {
        const BSONObj localObject = _dataConsistentStopDonorOpTime.get().toBSON();
        builder->append(kDataConsistentStopDonorOpTimeFieldName, localObject);
    }

    if (_rejectReadsBeforeTimestamp.is_initialized()) {
        builder->append(kRejectReadsBeforeTimestampFieldName, _rejectReadsBeforeTimestamp.get());
    }

    if (_cloneFinishedRecipientOpTime.is_initialized()) {
        const BSONObj localObject = _cloneFinishedRecipientOpTime.get().toBSON();
        builder->append(kCloneFinishedRecipientOpTimeFieldName, localObject);
    }

    if (_recipientCertificateForDonor.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kRecipientCertificateForDonorFieldName));
        _recipientCertificateForDonor.get().serialize(&subObjBuilder);
    }

    if (_recipientPrimaryStartingFCV.is_initialized()) {
        builder->append(kRecipientPrimaryStartingFCVFieldName, ::mongo::FeatureCompatibilityVersionParser::serializeVersion(_recipientPrimaryStartingFCV.get()));
    }

    builder->append(kNumRestartsDueToDonorConnectionFailureFieldName, _numRestartsDueToDonorConnectionFailure);

    builder->append(kNumRestartsDueToRecipientFailureFieldName, _numRestartsDueToRecipientFailure);

    builder->append(kCompletedUpdatingTransactionsBeforeStartOpTimeFieldName, _completedUpdatingTransactionsBeforeStartOpTime);

    builder->append(kCompletedFetchingRetryableWritesBeforeStartOpTimeFieldName, _completedFetchingRetryableWritesBeforeStartOpTime);

    if (_startAt.is_initialized()) {
        builder->append(kStartAtFieldName, _startAt.get());
    }

}


BSONObj TenantMigrationRecipientDocument::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
