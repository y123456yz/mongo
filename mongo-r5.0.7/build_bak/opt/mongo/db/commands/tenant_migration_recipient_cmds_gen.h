/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/commands/tenant_migration_recipient_cmds_gen.h --output build/opt/mongo/db/commands/tenant_migration_recipient_cmds_gen.cpp src/mongo/db/commands/tenant_migration_recipient_cmds.idl
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
#include "mongo/db/namespace_string.h"
#include "mongo/db/repl/optime.h"
#include "mongo/db/repl/tenant_migration_pem_payload_gen.h"
#include "mongo/db/repl/tenant_migration_util.h"
#include "mongo/idl/basic_types.h"
#include "mongo/idl/basic_types_gen.h"
#include "mongo/idl/idl_parser.h"
#include "mongo/rpc/op_msg.h"
#include "mongo/s/shard_id.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/util/uuid.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {

/**
 * Response for the 'recipientSyncData' command
 */
class RecipientSyncDataResponse {
public:
    static constexpr auto kMajorityAppliedDonorOpTimeFieldName = "majorityAppliedDonorOpTime"_sd;

    RecipientSyncDataResponse();
    RecipientSyncDataResponse(mongo::repl::OpTime majorityAppliedDonorOpTime);

    static RecipientSyncDataResponse parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Majority applied donor optime by the recipient
     */
    const mongo::repl::OpTime& getMajorityAppliedDonorOpTime() const { return _majorityAppliedDonorOpTime; }
    void setMajorityAppliedDonorOpTime(mongo::repl::OpTime value) & {  _majorityAppliedDonorOpTime = std::move(value); _hasMajorityAppliedDonorOpTime = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::repl::OpTime _majorityAppliedDonorOpTime;
    bool _hasMajorityAppliedDonorOpTime : 1;
};

/**
 * Command data for tenant migration recipient commands.
 */
class MigrationRecipientCommonData {
public:
    static constexpr auto kDonorConnectionStringFieldName = "donorConnectionString"_sd;
    static constexpr auto kMigrationIdFieldName = "migrationId"_sd;
    static constexpr auto kReadPreferenceFieldName = "readPreference"_sd;
    static constexpr auto kRecipientCertificateForDonorFieldName = "recipientCertificateForDonor"_sd;
    static constexpr auto kTenantIdFieldName = "tenantId"_sd;

    MigrationRecipientCommonData();
    MigrationRecipientCommonData(mongo::UUID migrationId, std::string donorConnectionString, std::string tenantId, mongo::ReadPreferenceSetting readPreference);

    static MigrationRecipientCommonData parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Unique identifier for the tenant migration.
     */
    const mongo::UUID& getMigrationId() const { return _migrationId; }
    void setMigrationId(mongo::UUID value) & {  _migrationId = std::move(value); _hasMigrationId = true; }

    /**
     * The URI string that the recipient will utilize to create a connection with the donor.
     */
    const StringData getDonorConnectionString() const& { return _donorConnectionString; }
    void getDonorConnectionString() && = delete;
    void setDonorConnectionString(StringData value) & { auto _tmpValue = value.toString(); validateDonorConnectionString(_tmpValue); _donorConnectionString = std::move(_tmpValue); _hasDonorConnectionString = true; }

    /**
     * The prefix from which the migrating database will be matched. The prefixes 'admin', 'local', 'config', the empty string, are not allowed.
     */
    const StringData getTenantId() const& { return _tenantId; }
    void getTenantId() && = delete;
    void setTenantId(StringData value) & { auto _tmpValue = value.toString(); validateTenantId(_tmpValue); _tenantId = std::move(_tmpValue); _hasTenantId = true; }

    /**
     * The read preference settings that the donor will pass on to the recipient.
     */
    const mongo::ReadPreferenceSetting& getReadPreference() const { return _readPreference; }
    void setReadPreference(mongo::ReadPreferenceSetting value) & {  _readPreference = std::move(value); _hasReadPreference = true; }

    /**
     * The SSL certificate and private key that the recipient should use to authenticate to the donor.
     */
    const boost::optional<mongo::TenantMigrationPEMPayload>& getRecipientCertificateForDonor() const& { return _recipientCertificateForDonor; }
    void getRecipientCertificateForDonor() && = delete;
    void setRecipientCertificateForDonor(boost::optional<mongo::TenantMigrationPEMPayload> value) & {  _recipientCertificateForDonor = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    void validateDonorConnectionString(const std::string& value);
    void validateDonorConnectionString(IDLParserErrorContext& ctxt, const std::string& value);

    void validateTenantId(const std::string& value);
    void validateTenantId(IDLParserErrorContext& ctxt, const std::string& value);

private:
    mongo::UUID _migrationId;
    std::string _donorConnectionString;
    std::string _tenantId;
    mongo::ReadPreferenceSetting _readPreference;
    boost::optional<mongo::TenantMigrationPEMPayload> _recipientCertificateForDonor;
    bool _hasMigrationId : 1;
    bool _hasDonorConnectionString : 1;
    bool _hasTenantId : 1;
    bool _hasReadPreference : 1;
};

/**
 * Parser for the 'recipientSyncData' command.
 */
class RecipientSyncData {
public:
    using Reply = void;
    static constexpr auto kMigrationRecipientCommonDataFieldName = "MigrationRecipientCommonData"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kDonorConnectionStringFieldName = "donorConnectionString"_sd;
    static constexpr auto kMigrationIdFieldName = "migrationId"_sd;
    static constexpr auto kReadPreferenceFieldName = "readPreference"_sd;
    static constexpr auto kRecipientCertificateForDonorFieldName = "recipientCertificateForDonor"_sd;
    static constexpr auto kReturnAfterReachingDonorTimestampFieldName = "returnAfterReachingDonorTimestamp"_sd;
    static constexpr auto kStartMigrationDonorTimestampFieldName = "startMigrationDonorTimestamp"_sd;
    static constexpr auto kTenantIdFieldName = "tenantId"_sd;
    static constexpr auto kCommandName = "recipientSyncData"_sd;

    RecipientSyncData();
    RecipientSyncData(mongo::Timestamp startMigrationDonorTimestamp);

    static RecipientSyncData parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static RecipientSyncData parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;


    /**
     * Command data for tenant migration recipient commands.
     */
    const mongo::MigrationRecipientCommonData& getMigrationRecipientCommonData() const { return _migrationRecipientCommonData; }
    mongo::MigrationRecipientCommonData& getMigrationRecipientCommonData() { return _migrationRecipientCommonData; }
    void setMigrationRecipientCommonData(mongo::MigrationRecipientCommonData value) & {  _migrationRecipientCommonData = std::move(value);  }

    /**
     * Unique identifier for the tenant migration.
     */
    const  mongo::UUID& getMigrationId() const { return _migrationRecipientCommonData.getMigrationId(); }
    /**
     * The URI string that the recipient will utilize to create a connection with the donor.
     */
    const  StringData getDonorConnectionString() const { return _migrationRecipientCommonData.getDonorConnectionString(); }
    /**
     * The prefix from which the migrating database will be matched. The prefixes 'admin', 'local', 'config', the empty string, are not allowed.
     */
    const  StringData getTenantId() const { return _migrationRecipientCommonData.getTenantId(); }
    /**
     * The read preference settings that the donor will pass on to the recipient.
     */
    const  mongo::ReadPreferenceSetting& getReadPreference() const { return _migrationRecipientCommonData.getReadPreference(); }
    /**
     * The SSL certificate and private key that the recipient should use to authenticate to the donor.
     */
    const  boost::optional<mongo::TenantMigrationPEMPayload>& getRecipientCertificateForDonor() const { return _migrationRecipientCommonData.getRecipientCertificateForDonor(); }
    /**
     * If provided, the recipient should return after syncing up to this donor timestamp. Otherwise, the recipient will return once its copy of the data is consistent.
     */
    const boost::optional<mongo::Timestamp>& getReturnAfterReachingDonorTimestamp() const& { return _returnAfterReachingDonorTimestamp; }
    void getReturnAfterReachingDonorTimestamp() && = delete;
    void setReturnAfterReachingDonorTimestamp(boost::optional<mongo::Timestamp> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get();
        validateReturnAfterReachingDonorTimestamp(_tmpValue);
        _returnAfterReachingDonorTimestamp = std::move(_tmpValue);
    } else {
        _returnAfterReachingDonorTimestamp = boost::none;
    }
      }

    /**
     * Recipient must not start cloning/fetching oplog entries from the donor until this timestamp is majority committed.
     */
    const mongo::Timestamp& getStartMigrationDonorTimestamp() const { return _startMigrationDonorTimestamp; }
    void setStartMigrationDonorTimestamp(mongo::Timestamp value) & { validateStartMigrationDonorTimestamp(value); _startMigrationDonorTimestamp = std::move(value); _hasStartMigrationDonorTimestamp = true; }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    void validateDonorConnectionString(const std::string& value);
    void validateDonorConnectionString(IDLParserErrorContext& ctxt, const std::string& value);

    void validateTenantId(const std::string& value);
    void validateTenantId(IDLParserErrorContext& ctxt, const std::string& value);

    void validateReturnAfterReachingDonorTimestamp(const mongo::Timestamp& value);
    void validateReturnAfterReachingDonorTimestamp(IDLParserErrorContext& ctxt, const mongo::Timestamp& value);

    void validateStartMigrationDonorTimestamp(const mongo::Timestamp& value);
    void validateStartMigrationDonorTimestamp(IDLParserErrorContext& ctxt, const mongo::Timestamp& value);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;



    mongo::MigrationRecipientCommonData _migrationRecipientCommonData;
    boost::optional<mongo::Timestamp> _returnAfterReachingDonorTimestamp;
    mongo::Timestamp _startMigrationDonorTimestamp;
    std::string _dbName;
    bool _hasStartMigrationDonorTimestamp : 1;
    bool _hasDbName : 1;
};

/**
 * Parser for the 'recipientForgetMigration' command.
 */
class RecipientForgetMigration {
public:
    using Reply = void;
    static constexpr auto kMigrationRecipientCommonDataFieldName = "MigrationRecipientCommonData"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kDonorConnectionStringFieldName = "donorConnectionString"_sd;
    static constexpr auto kMigrationIdFieldName = "migrationId"_sd;
    static constexpr auto kReadPreferenceFieldName = "readPreference"_sd;
    static constexpr auto kRecipientCertificateForDonorFieldName = "recipientCertificateForDonor"_sd;
    static constexpr auto kTenantIdFieldName = "tenantId"_sd;
    static constexpr auto kCommandName = "recipientForgetMigration"_sd;

    RecipientForgetMigration();

    static RecipientForgetMigration parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static RecipientForgetMigration parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;


    /**
     * Command data for tenant migration recipient commands.
     */
    const mongo::MigrationRecipientCommonData& getMigrationRecipientCommonData() const { return _migrationRecipientCommonData; }
    mongo::MigrationRecipientCommonData& getMigrationRecipientCommonData() { return _migrationRecipientCommonData; }
    void setMigrationRecipientCommonData(mongo::MigrationRecipientCommonData value) & {  _migrationRecipientCommonData = std::move(value);  }

    /**
     * Unique identifier for the tenant migration.
     */
    const  mongo::UUID& getMigrationId() const { return _migrationRecipientCommonData.getMigrationId(); }
    /**
     * The URI string that the recipient will utilize to create a connection with the donor.
     */
    const  StringData getDonorConnectionString() const { return _migrationRecipientCommonData.getDonorConnectionString(); }
    /**
     * The prefix from which the migrating database will be matched. The prefixes 'admin', 'local', 'config', the empty string, are not allowed.
     */
    const  StringData getTenantId() const { return _migrationRecipientCommonData.getTenantId(); }
    /**
     * The read preference settings that the donor will pass on to the recipient.
     */
    const  mongo::ReadPreferenceSetting& getReadPreference() const { return _migrationRecipientCommonData.getReadPreference(); }
    /**
     * The SSL certificate and private key that the recipient should use to authenticate to the donor.
     */
    const  boost::optional<mongo::TenantMigrationPEMPayload>& getRecipientCertificateForDonor() const { return _migrationRecipientCommonData.getRecipientCertificateForDonor(); }
    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    void validateDonorConnectionString(const std::string& value);
    void validateDonorConnectionString(IDLParserErrorContext& ctxt, const std::string& value);

    void validateTenantId(const std::string& value);
    void validateTenantId(IDLParserErrorContext& ctxt, const std::string& value);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;



    mongo::MigrationRecipientCommonData _migrationRecipientCommonData;
    std::string _dbName;
    bool _hasDbName : 1;
};

}  // namespace mongo
