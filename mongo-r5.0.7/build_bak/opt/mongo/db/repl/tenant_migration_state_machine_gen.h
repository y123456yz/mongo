/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/repl/tenant_migration_state_machine_gen.h --output build/opt/mongo/db/repl/tenant_migration_state_machine_gen.cpp src/mongo/db/repl/tenant_migration_state_machine.idl
 */

#pragma once

#include <algorithm>
#include <boost/optional.hpp>
#include <cstdint>
#include <string>
#include <tuple>
#include <vector>

#include "mongo/base/data_range.h"
#include "mongo/base/string_data.h"
#include "mongo/bson/bsonobj.h"
#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/bson/simple_bsonobj_comparator.h"
#include "mongo/client/read_preference.h"
#include "mongo/db/commands/feature_compatibility_version_parser.h"
#include "mongo/db/namespace_string.h"
#include "mongo/db/repl/optime.h"
#include "mongo/db/repl/tenant_migration_pem_payload_gen.h"
#include "mongo/db/repl/tenant_migration_util.h"
#include "mongo/idl/basic_types.h"
#include "mongo/idl/basic_types_gen.h"
#include "mongo/idl/idl_parser.h"
#include "mongo/rpc/op_msg.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/util/uuid.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {

/**
 * The state of an in-progress tenant migration.
 */
enum class TenantMigrationDonorStateEnum : std::int32_t {
    kUninitialized ,
    kAbortingIndexBuilds ,
    kDataSync ,
    kBlocking ,
    kCommitted ,
    kAborted ,
};
static constexpr uint32_t kNumTenantMigrationDonorStateEnum = 6;

TenantMigrationDonorStateEnum TenantMigrationDonorState_parse(const IDLParserErrorContext& ctxt, StringData value);
StringData TenantMigrationDonorState_serializer(TenantMigrationDonorStateEnum value);

/**
 * The state of an tenant migration on recipient side.
 */
enum class TenantMigrationRecipientStateEnum : std::int32_t {
    kUninitialized ,
    kStarted ,
    kConsistent ,
    kDone ,
};
static constexpr uint32_t kNumTenantMigrationRecipientStateEnum = 4;

TenantMigrationRecipientStateEnum TenantMigrationRecipientState_parse(const IDLParserErrorContext& ctxt, StringData value);
StringData TenantMigrationRecipientState_serializer(TenantMigrationRecipientStateEnum value);

/**
 * Represents an in-progress tenant migration on the migration donor.
 */
class TenantMigrationDonorDocument {
public:
    static constexpr auto kAbortReasonFieldName = "abortReason"_sd;
    static constexpr auto kBlockTimestampFieldName = "blockTimestamp"_sd;
    static constexpr auto kCommitOrAbortOpTimeFieldName = "commitOrAbortOpTime"_sd;
    static constexpr auto kDonorCertificateForRecipientFieldName = "donorCertificateForRecipient"_sd;
    static constexpr auto kExpireAtFieldName = "expireAt"_sd;
    static constexpr auto kIdFieldName = "_id"_sd;
    static constexpr auto kMigrationStartFieldName = "migrationStart"_sd;
    static constexpr auto kReadPreferenceFieldName = "readPreference"_sd;
    static constexpr auto kRecipientCertificateForDonorFieldName = "recipientCertificateForDonor"_sd;
    static constexpr auto kRecipientConnectionStringFieldName = "recipientConnectionString"_sd;
    static constexpr auto kStartMigrationDonorTimestampFieldName = "startMigrationDonorTimestamp"_sd;
    static constexpr auto kStateFieldName = "state"_sd;
    static constexpr auto kTenantIdFieldName = "tenantId"_sd;

    TenantMigrationDonorDocument();
    TenantMigrationDonorDocument(mongo::UUID id, std::string recipientConnectionString, mongo::ReadPreferenceSetting readPreference, std::string tenantId);

    static TenantMigrationDonorDocument parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Unique identifier for the tenant migration.
     */
    const mongo::UUID& getId() const { return _id; }
    void setId(mongo::UUID value) & {  _id = std::move(value); _hasId = true; }

    /**
     * The URI string that the donor will utilize to create a connection with the recipient.
     */
    const StringData getRecipientConnectionString() const& { return _recipientConnectionString; }
    void getRecipientConnectionString() && = delete;
    void setRecipientConnectionString(StringData value) & { auto _tmpValue = value.toString(); validateRecipientConnectionString(_tmpValue); _recipientConnectionString = std::move(_tmpValue); _hasRecipientConnectionString = true; }

    /**
     * The read preference setting that the recipient will use to determine which node in the donor replica set to clone from.
     */
    const mongo::ReadPreferenceSetting& getReadPreference() const { return _readPreference; }
    void setReadPreference(mongo::ReadPreferenceSetting value) & {  _readPreference = std::move(value); _hasReadPreference = true; }

    /**
     * The tenantId for the migration.
     */
    const StringData getTenantId() const& { return _tenantId; }
    void getTenantId() && = delete;
    void setTenantId(StringData value) & { auto _tmpValue = value.toString();  _tenantId = std::move(_tmpValue); _hasTenantId = true; }

    /**
     * The state of the tenant migration.
     */
    mongo::TenantMigrationDonorStateEnum getState() const { return _state; }
    void setState(mongo::TenantMigrationDonorStateEnum value) & {  _state = std::move(value);  }

    /**
     * The timestamp at which writes and causal reads against the databases being migrated should start blocking.
     */
    const boost::optional<mongo::Timestamp>& getBlockTimestamp() const& { return _blockTimestamp; }
    void getBlockTimestamp() && = delete;
    void setBlockTimestamp(boost::optional<mongo::Timestamp> value) & {  _blockTimestamp = std::move(value);  }

    /**
     * The opTime at which the donor's state document was set to 'committed' or 'aborted'.
     */
    const boost::optional<mongo::repl::OpTime>& getCommitOrAbortOpTime() const& { return _commitOrAbortOpTime; }
    void getCommitOrAbortOpTime() && = delete;
    void setCommitOrAbortOpTime(boost::optional<mongo::repl::OpTime> value) & {  _commitOrAbortOpTime = std::move(value);  }

    /**
     * The error that caused the migration to abort.
     */
    const boost::optional<mongo::BSONObj>& getAbortReason() const& { return _abortReason; }
    void getAbortReason() && = delete;
    void setAbortReason(boost::optional<mongo::BSONObj> value) & {  _abortReason = std::move(value);  }

    /**
     * The wall-clock time at which the state machine document should be removed by the TTL monitor.
     */
    const boost::optional<mongo::Date_t>& getExpireAt() const& { return _expireAt; }
    void getExpireAt() && = delete;
    void setExpireAt(boost::optional<mongo::Date_t> value) & {  _expireAt = std::move(value);  }

    /**
     * The SSL certificate and private key that the donor should use to authenticate to the recipient.
     */
    const boost::optional<mongo::TenantMigrationPEMPayload>& getDonorCertificateForRecipient() const& { return _donorCertificateForRecipient; }
    void getDonorCertificateForRecipient() && = delete;
    void setDonorCertificateForRecipient(boost::optional<mongo::TenantMigrationPEMPayload> value) & {  _donorCertificateForRecipient = std::move(value);  }

    /**
     * The SSL certificate and private key that the recipient should use to authenticate to the donor.
     */
    const boost::optional<mongo::TenantMigrationPEMPayload>& getRecipientCertificateForDonor() const& { return _recipientCertificateForDonor; }
    void getRecipientCertificateForDonor() && = delete;
    void setRecipientCertificateForDonor(boost::optional<mongo::TenantMigrationPEMPayload> value) & {  _recipientCertificateForDonor = std::move(value);  }

    /**
     * Timestamp after all index builds for tenant are complete or aborted.  Recipient must not start cloning/fetching oplog entries from the donor until this timestamp is majority committed.
     */
    const boost::optional<mongo::Timestamp>& getStartMigrationDonorTimestamp() const& { return _startMigrationDonorTimestamp; }
    void getStartMigrationDonorTimestamp() && = delete;
    void setStartMigrationDonorTimestamp(boost::optional<mongo::Timestamp> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get();
        validateStartMigrationDonorTimestamp(_tmpValue);
        _startMigrationDonorTimestamp = std::move(_tmpValue);
    } else {
        _startMigrationDonorTimestamp = boost::none;
    }
      }

    /**
     * The wall-clock time at which the migration has started.
     */
    const boost::optional<mongo::Date_t>& getMigrationStart() const& { return _migrationStart; }
    void getMigrationStart() && = delete;
    void setMigrationStart(boost::optional<mongo::Date_t> value) & {  _migrationStart = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    void validateRecipientConnectionString(const std::string& value);
    void validateRecipientConnectionString(IDLParserErrorContext& ctxt, const std::string& value);

    void validateStartMigrationDonorTimestamp(const mongo::Timestamp& value);
    void validateStartMigrationDonorTimestamp(IDLParserErrorContext& ctxt, const mongo::Timestamp& value);

private:
    mongo::UUID _id;
    std::string _recipientConnectionString;
    mongo::ReadPreferenceSetting _readPreference;
    std::string _tenantId;
    mongo::TenantMigrationDonorStateEnum _state{mongo::TenantMigrationDonorStateEnum::kUninitialized};
    boost::optional<mongo::Timestamp> _blockTimestamp;
    boost::optional<mongo::repl::OpTime> _commitOrAbortOpTime;
    boost::optional<mongo::BSONObj> _abortReason;
    boost::optional<mongo::Date_t> _expireAt;
    boost::optional<mongo::TenantMigrationPEMPayload> _donorCertificateForRecipient;
    boost::optional<mongo::TenantMigrationPEMPayload> _recipientCertificateForDonor;
    boost::optional<mongo::Timestamp> _startMigrationDonorTimestamp;
    boost::optional<mongo::Date_t> _migrationStart;
    bool _hasId : 1;
    bool _hasRecipientConnectionString : 1;
    bool _hasReadPreference : 1;
    bool _hasTenantId : 1;
};

/**
 * Represents an in-progress tenant migration on the migration recipient.
 */
class TenantMigrationRecipientDocument {
public:
    static constexpr auto kCloneFinishedRecipientOpTimeFieldName = "cloneFinishedRecipientOpTime"_sd;
    static constexpr auto kCompletedFetchingRetryableWritesBeforeStartOpTimeFieldName = "completedFetchingRetryableWritesBeforeStartOpTime"_sd;
    static constexpr auto kCompletedUpdatingTransactionsBeforeStartOpTimeFieldName = "completedUpdatingTransactionsBeforeStartOpTime"_sd;
    static constexpr auto kDataConsistentStopDonorOpTimeFieldName = "dataConsistentStopDonorOpTime"_sd;
    static constexpr auto kDonorConnectionStringFieldName = "donorConnectionString"_sd;
    static constexpr auto kExpireAtFieldName = "expireAt"_sd;
    static constexpr auto kIdFieldName = "_id"_sd;
    static constexpr auto kNumRestartsDueToDonorConnectionFailureFieldName = "numRestartsDueToDonorConnectionFailure"_sd;
    static constexpr auto kNumRestartsDueToRecipientFailureFieldName = "numRestartsDueToRecipientFailure"_sd;
    static constexpr auto kReadPreferenceFieldName = "readPreference"_sd;
    static constexpr auto kRecipientCertificateForDonorFieldName = "recipientCertificateForDonor"_sd;
    static constexpr auto kRecipientPrimaryStartingFCVFieldName = "recipientPrimaryStartingFCV"_sd;
    static constexpr auto kRejectReadsBeforeTimestampFieldName = "rejectReadsBeforeTimestamp"_sd;
    static constexpr auto kStartApplyingDonorOpTimeFieldName = "startApplyingDonorOpTime"_sd;
    static constexpr auto kStartAtFieldName = "startAt"_sd;
    static constexpr auto kStartFetchingDonorOpTimeFieldName = "startFetchingDonorOpTime"_sd;
    static constexpr auto kStartMigrationDonorTimestampFieldName = "startMigrationDonorTimestamp"_sd;
    static constexpr auto kStateFieldName = "state"_sd;
    static constexpr auto kTenantIdFieldName = "tenantId"_sd;

    TenantMigrationRecipientDocument();
    TenantMigrationRecipientDocument(mongo::UUID id, std::string donorConnectionString, std::string tenantId, mongo::Timestamp startMigrationDonorTimestamp, mongo::ReadPreferenceSetting readPreference);

    static TenantMigrationRecipientDocument parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Unique identifier for the tenant migration.
     */
    const mongo::UUID& getId() const { return _id; }
    void setId(mongo::UUID value) & {  _id = std::move(value); _hasId = true; }

    /**
     * The URI string that the recipient will utilize to create a connection with the donor.
     */
    const StringData getDonorConnectionString() const& { return _donorConnectionString; }
    void getDonorConnectionString() && = delete;
    void setDonorConnectionString(StringData value) & { auto _tmpValue = value.toString(); validateDonorConnectionString(_tmpValue); _donorConnectionString = std::move(_tmpValue); _hasDonorConnectionString = true; }

    /**
     * The tenantId for the migration.
     */
    const StringData getTenantId() const& { return _tenantId; }
    void getTenantId() && = delete;
    void setTenantId(StringData value) & { auto _tmpValue = value.toString(); validateTenantId(_tmpValue); _tenantId = std::move(_tmpValue); _hasTenantId = true; }

    /**
     * Timestamp after all index builds for tenant are complete or aborted.  Recipient must not start cloning/fetching oplog entries from the donor until this timestamp is majority committed.
     */
    const mongo::Timestamp& getStartMigrationDonorTimestamp() const { return _startMigrationDonorTimestamp; }
    void setStartMigrationDonorTimestamp(mongo::Timestamp value) & { validateStartMigrationDonorTimestamp(value); _startMigrationDonorTimestamp = std::move(value); _hasStartMigrationDonorTimestamp = true; }

    /**
     * The read preference setting that the recipient will use to determine which node in the donor replica set to clone from.
     */
    const mongo::ReadPreferenceSetting& getReadPreference() const { return _readPreference; }
    void setReadPreference(mongo::ReadPreferenceSetting value) & {  _readPreference = std::move(value); _hasReadPreference = true; }

    /**
     * The state of the tenant migration.
     */
    mongo::TenantMigrationRecipientStateEnum getState() const { return _state; }
    void setState(mongo::TenantMigrationRecipientStateEnum value) & {  _state = std::move(value);  }

    /**
     * The wall-clock time at which the state machine document should be removed by the TTL monitor.
     */
    const boost::optional<mongo::Date_t>& getExpireAt() const& { return _expireAt; }
    void getExpireAt() && = delete;
    void setExpireAt(boost::optional<mongo::Date_t> value) & {  _expireAt = std::move(value);  }

    /**
     * Populated during data sync; the donor's operation time when the data cloning starts.
     */
    const boost::optional<mongo::repl::OpTime>& getStartApplyingDonorOpTime() const& { return _startApplyingDonorOpTime; }
    void getStartApplyingDonorOpTime() && = delete;
    void setStartApplyingDonorOpTime(boost::optional<mongo::repl::OpTime> value) & {  _startApplyingDonorOpTime = std::move(value);  }

    /**
     * Populated during data sync; the donor's operation time of the last open transaction when the data cloning started.
     */
    const boost::optional<mongo::repl::OpTime>& getStartFetchingDonorOpTime() const& { return _startFetchingDonorOpTime; }
    void getStartFetchingDonorOpTime() && = delete;
    void setStartFetchingDonorOpTime(boost::optional<mongo::repl::OpTime> value) & {  _startFetchingDonorOpTime = std::move(value);  }

    /**
     * Populated during data sync; the donor's operation time when the data cloning finishes.
     */
    const boost::optional<mongo::repl::OpTime>& getDataConsistentStopDonorOpTime() const& { return _dataConsistentStopDonorOpTime; }
    void getDataConsistentStopDonorOpTime() && = delete;
    void setDataConsistentStopDonorOpTime(boost::optional<mongo::repl::OpTime> value) & {  _dataConsistentStopDonorOpTime = std::move(value);  }

    /**
     * Populated during data sync when the recipientSyncData with the returnAfterReachingTimestamp is received after data is consistent; the earliest timestamp at which reads are allowed on the recipient (corresponds to the donor's blockTimestamp).
     */
    const boost::optional<mongo::Timestamp>& getRejectReadsBeforeTimestamp() const& { return _rejectReadsBeforeTimestamp; }
    void getRejectReadsBeforeTimestamp() && = delete;
    void setRejectReadsBeforeTimestamp(boost::optional<mongo::Timestamp> value) & {  _rejectReadsBeforeTimestamp = std::move(value);  }

    /**
     * Populated during data sync; the recipient operation time when the data cloning finishes.
     */
    const boost::optional<mongo::repl::OpTime>& getCloneFinishedRecipientOpTime() const& { return _cloneFinishedRecipientOpTime; }
    void getCloneFinishedRecipientOpTime() && = delete;
    void setCloneFinishedRecipientOpTime(boost::optional<mongo::repl::OpTime> value) & {  _cloneFinishedRecipientOpTime = std::move(value);  }

    /**
     * The SSL certificate and private key that the recipient should use to authenticate to the donor.
     */
    const boost::optional<mongo::TenantMigrationPEMPayload>& getRecipientCertificateForDonor() const& { return _recipientCertificateForDonor; }
    void getRecipientCertificateForDonor() && = delete;
    void setRecipientCertificateForDonor(boost::optional<mongo::TenantMigrationPEMPayload> value) & {  _recipientCertificateForDonor = std::move(value);  }

    /**
     * The featureCompatibilityVersion of the recipient as recorded at the beginning of a migration attempt. Implicitly includes information on current upgrade or downgrade state.
     */
    const boost::optional<ServerGlobalParams::FeatureCompatibility::Version> getRecipientPrimaryStartingFCV() const& { return _recipientPrimaryStartingFCV; }
    void getRecipientPrimaryStartingFCV() && = delete;
    void setRecipientPrimaryStartingFCV(boost::optional<ServerGlobalParams::FeatureCompatibility::Version> value) & {  _recipientPrimaryStartingFCV = std::move(value);  }

    /**
     * A counter that is incremented on each restart due to a donor connection failure.
     */
    std::int64_t getNumRestartsDueToDonorConnectionFailure() const { return _numRestartsDueToDonorConnectionFailure; }
    void setNumRestartsDueToDonorConnectionFailure(std::int64_t value) & {  _numRestartsDueToDonorConnectionFailure = std::move(value);  }

    /**
     * A counter that is incremented on each restart due to a recipient failure.
     */
    std::int64_t getNumRestartsDueToRecipientFailure() const { return _numRestartsDueToRecipientFailure; }
    void setNumRestartsDueToRecipientFailure(std::int64_t value) & {  _numRestartsDueToRecipientFailure = std::move(value);  }

    /**
     * Indicates if the recipient has finished updating transaction entries that were committed before 'startFetchingDonorOpTime'. If true, the recipient can skip the fetching transactions stage.
     */
    bool getCompletedUpdatingTransactionsBeforeStartOpTime() const { return _completedUpdatingTransactionsBeforeStartOpTime; }
    void setCompletedUpdatingTransactionsBeforeStartOpTime(bool value) & {  _completedUpdatingTransactionsBeforeStartOpTime = std::move(value);  }

    /**
     * Indicates if the recipient has finished fetching retryable writes oplog entries before 'startFetchingDonorOpTime' for each retryable writes entry in 'config.transactions'
     */
    bool getCompletedFetchingRetryableWritesBeforeStartOpTime() const { return _completedFetchingRetryableWritesBeforeStartOpTime; }
    void setCompletedFetchingRetryableWritesBeforeStartOpTime(bool value) & {  _completedFetchingRetryableWritesBeforeStartOpTime = std::move(value);  }

    /**
     * The wall-clock time at which the state machine document is initialized.
     */
    const boost::optional<mongo::Date_t>& getStartAt() const& { return _startAt; }
    void getStartAt() && = delete;
    void setStartAt(boost::optional<mongo::Date_t> value) & {  _startAt = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    void validateDonorConnectionString(const std::string& value);
    void validateDonorConnectionString(IDLParserErrorContext& ctxt, const std::string& value);

    void validateTenantId(const std::string& value);
    void validateTenantId(IDLParserErrorContext& ctxt, const std::string& value);

    void validateStartMigrationDonorTimestamp(const mongo::Timestamp& value);
    void validateStartMigrationDonorTimestamp(IDLParserErrorContext& ctxt, const mongo::Timestamp& value);

private:
    mongo::UUID _id;
    std::string _donorConnectionString;
    std::string _tenantId;
    mongo::Timestamp _startMigrationDonorTimestamp;
    mongo::ReadPreferenceSetting _readPreference;
    mongo::TenantMigrationRecipientStateEnum _state{mongo::TenantMigrationRecipientStateEnum::kUninitialized};
    boost::optional<mongo::Date_t> _expireAt;
    boost::optional<mongo::repl::OpTime> _startApplyingDonorOpTime;
    boost::optional<mongo::repl::OpTime> _startFetchingDonorOpTime;
    boost::optional<mongo::repl::OpTime> _dataConsistentStopDonorOpTime;
    boost::optional<mongo::Timestamp> _rejectReadsBeforeTimestamp;
    boost::optional<mongo::repl::OpTime> _cloneFinishedRecipientOpTime;
    boost::optional<mongo::TenantMigrationPEMPayload> _recipientCertificateForDonor;
    boost::optional<ServerGlobalParams::FeatureCompatibility::Version> _recipientPrimaryStartingFCV;
    std::int64_t _numRestartsDueToDonorConnectionFailure{0};
    std::int64_t _numRestartsDueToRecipientFailure{0};
    bool _completedUpdatingTransactionsBeforeStartOpTime{false};
    bool _completedFetchingRetryableWritesBeforeStartOpTime{false};
    boost::optional<mongo::Date_t> _startAt;
    bool _hasId : 1;
    bool _hasDonorConnectionString : 1;
    bool _hasTenantId : 1;
    bool _hasStartMigrationDonorTimestamp : 1;
    bool _hasReadPreference : 1;
};

}  // namespace mongo
