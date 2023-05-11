/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/commands/tenant_migration_donor_cmds_gen.h --output build/opt/mongo/db/commands/tenant_migration_donor_cmds_gen.cpp src/mongo/db/commands/tenant_migration_donor_cmds.idl
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
#include "mongo/db/repl/tenant_migration_state_machine_gen.h"
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
 * Response of the donorStartMigration command
 */
class DonorStartMigrationResponse {
public:
    static constexpr auto kAbortReasonFieldName = "abortReason"_sd;
    static constexpr auto kStateFieldName = "state"_sd;

    DonorStartMigrationResponse();
    DonorStartMigrationResponse(mongo::TenantMigrationDonorStateEnum state);

    static DonorStartMigrationResponse parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * The state of the tenant migration.
     */
    mongo::TenantMigrationDonorStateEnum getState() const { return _state; }
    void setState(mongo::TenantMigrationDonorStateEnum value) & {  _state = std::move(value); _hasState = true; }

    /**
     * The error that caused the migration to abort.
     */
    const boost::optional<mongo::BSONObj>& getAbortReason() const& { return _abortReason; }
    void getAbortReason() && = delete;
    void setAbortReason(boost::optional<mongo::BSONObj> value) & {  _abortReason = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::TenantMigrationDonorStateEnum _state;
    boost::optional<mongo::BSONObj> _abortReason;
    bool _hasState : 1;
};

/**
 * Parser for the 'donorStartMigration' command.
 */
class DonorStartMigration {
public:
    using Reply = void;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kDonorCertificateForRecipientFieldName = "donorCertificateForRecipient"_sd;
    static constexpr auto kMigrationIdFieldName = "migrationId"_sd;
    static constexpr auto kReadPreferenceFieldName = "readPreference"_sd;
    static constexpr auto kRecipientCertificateForDonorFieldName = "recipientCertificateForDonor"_sd;
    static constexpr auto kRecipientConnectionStringFieldName = "recipientConnectionString"_sd;
    static constexpr auto kTenantIdFieldName = "tenantId"_sd;
    static constexpr auto kCommandName = "donorStartMigration"_sd;

    DonorStartMigration();
    DonorStartMigration(mongo::UUID migrationId, std::string recipientConnectionString, std::string tenantId, mongo::ReadPreferenceSetting readPreference);

    static DonorStartMigration parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static DonorStartMigration parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;


    /**
     * Unique identifier for the tenant migration.
     */
    const mongo::UUID& getMigrationId() const { return _migrationId; }
    void setMigrationId(mongo::UUID value) & {  _migrationId = std::move(value); _hasMigrationId = true; }

    /**
     * The URI string that the donor will utilize to create a connection with the recipient.
     */
    const StringData getRecipientConnectionString() const& { return _recipientConnectionString; }
    void getRecipientConnectionString() && = delete;
    void setRecipientConnectionString(StringData value) & { auto _tmpValue = value.toString(); validateRecipientConnectionString(_tmpValue); _recipientConnectionString = std::move(_tmpValue); _hasRecipientConnectionString = true; }

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

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    void validateRecipientConnectionString(const std::string& value);
    void validateRecipientConnectionString(IDLParserErrorContext& ctxt, const std::string& value);

    void validateTenantId(const std::string& value);
    void validateTenantId(IDLParserErrorContext& ctxt, const std::string& value);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;



    mongo::UUID _migrationId;
    std::string _recipientConnectionString;
    std::string _tenantId;
    mongo::ReadPreferenceSetting _readPreference;
    boost::optional<mongo::TenantMigrationPEMPayload> _donorCertificateForRecipient;
    boost::optional<mongo::TenantMigrationPEMPayload> _recipientCertificateForDonor;
    std::string _dbName;
    bool _hasMigrationId : 1;
    bool _hasRecipientConnectionString : 1;
    bool _hasTenantId : 1;
    bool _hasReadPreference : 1;
    bool _hasDbName : 1;
};

/**
 * Parser for the 'donorForgetMigration' command.
 */
class DonorForgetMigration {
public:
    using Reply = void;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kMigrationIdFieldName = "migrationId"_sd;
    static constexpr auto kCommandName = "donorForgetMigration"_sd;

    DonorForgetMigration();
    DonorForgetMigration(mongo::UUID migrationId);

    static DonorForgetMigration parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static DonorForgetMigration parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;


    /**
     * Unique identifier for the tenant migration.
     */
    const mongo::UUID& getMigrationId() const { return _migrationId; }
    void setMigrationId(mongo::UUID value) & {  _migrationId = std::move(value); _hasMigrationId = true; }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;



    mongo::UUID _migrationId;
    std::string _dbName;
    bool _hasMigrationId : 1;
    bool _hasDbName : 1;
};

/**
 * Parser for the 'donorAbortMigration' command.
 */
class DonorAbortMigration {
public:
    using Reply = void;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kMigrationIdFieldName = "migrationId"_sd;
    static constexpr auto kCommandName = "donorAbortMigration"_sd;

    DonorAbortMigration();
    DonorAbortMigration(mongo::UUID migrationId);

    static DonorAbortMigration parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static DonorAbortMigration parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;


    /**
     * Unique identifier for the tenant migration.
     */
    const mongo::UUID& getMigrationId() const { return _migrationId; }
    void setMigrationId(mongo::UUID value) & {  _migrationId = std::move(value); _hasMigrationId = true; }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;



    mongo::UUID _migrationId;
    std::string _dbName;
    bool _hasMigrationId : 1;
    bool _hasDbName : 1;
};

}  // namespace mongo
