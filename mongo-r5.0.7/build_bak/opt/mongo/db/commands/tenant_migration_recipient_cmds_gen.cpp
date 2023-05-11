/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/commands/tenant_migration_recipient_cmds_gen.h --output build/opt/mongo/db/commands/tenant_migration_recipient_cmds_gen.cpp src/mongo/db/commands/tenant_migration_recipient_cmds.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/commands/tenant_migration_recipient_cmds_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData RecipientSyncDataResponse::kMajorityAppliedDonorOpTimeFieldName;


RecipientSyncDataResponse::RecipientSyncDataResponse() : _majorityAppliedDonorOpTime(mongo::idl::preparsedValue<decltype(_majorityAppliedDonorOpTime)>()), _hasMajorityAppliedDonorOpTime(false) {
    // Used for initialization only
}
RecipientSyncDataResponse::RecipientSyncDataResponse(mongo::repl::OpTime majorityAppliedDonorOpTime) : _majorityAppliedDonorOpTime(std::move(majorityAppliedDonorOpTime)), _hasMajorityAppliedDonorOpTime(true) {
    // Used for initialization only
}


RecipientSyncDataResponse RecipientSyncDataResponse::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<RecipientSyncDataResponse>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void RecipientSyncDataResponse::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kMajorityAppliedDonorOpTimeBit = 0;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kMajorityAppliedDonorOpTimeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kMajorityAppliedDonorOpTimeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMajorityAppliedDonorOpTimeBit);

                _hasMajorityAppliedDonorOpTime = true;
                const BSONObj localObject = element.Obj();
                _majorityAppliedDonorOpTime = repl::OpTime::parse(localObject);
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
        if (!usedFields[kMajorityAppliedDonorOpTimeBit]) {
            ctxt.throwMissingField(kMajorityAppliedDonorOpTimeFieldName);
        }
    }

}


void RecipientSyncDataResponse::serialize(BSONObjBuilder* builder) const {
    invariant(_hasMajorityAppliedDonorOpTime);

    {
        const BSONObj localObject = _majorityAppliedDonorOpTime.toBSON();
        builder->append(kMajorityAppliedDonorOpTimeFieldName, localObject);
    }

}


BSONObj RecipientSyncDataResponse::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData MigrationRecipientCommonData::kDonorConnectionStringFieldName;
constexpr StringData MigrationRecipientCommonData::kMigrationIdFieldName;
constexpr StringData MigrationRecipientCommonData::kReadPreferenceFieldName;
constexpr StringData MigrationRecipientCommonData::kRecipientCertificateForDonorFieldName;
constexpr StringData MigrationRecipientCommonData::kTenantIdFieldName;


MigrationRecipientCommonData::MigrationRecipientCommonData() : _migrationId(mongo::idl::preparsedValue<decltype(_migrationId)>()), _donorConnectionString(mongo::idl::preparsedValue<decltype(_donorConnectionString)>()), _tenantId(mongo::idl::preparsedValue<decltype(_tenantId)>()), _readPreference(mongo::idl::preparsedValue<decltype(_readPreference)>()), _hasMigrationId(false), _hasDonorConnectionString(false), _hasTenantId(false), _hasReadPreference(false) {
    // Used for initialization only
}
MigrationRecipientCommonData::MigrationRecipientCommonData(mongo::UUID migrationId, std::string donorConnectionString, std::string tenantId, mongo::ReadPreferenceSetting readPreference) : _migrationId(std::move(migrationId)), _donorConnectionString(std::move(donorConnectionString)), _tenantId(std::move(tenantId)), _readPreference(std::move(readPreference)), _hasMigrationId(true), _hasDonorConnectionString(true), _hasTenantId(true), _hasReadPreference(true) {
    // Used for initialization only
}

void MigrationRecipientCommonData::validateDonorConnectionString(IDLParserErrorContext& ctxt, const std::string& value)
{
    uassertStatusOK(tenant_migration_util::validateConnectionString(value));
}

void MigrationRecipientCommonData::validateDonorConnectionString(const std::string& value)
{
    uassertStatusOK(tenant_migration_util::validateConnectionString(value));
}

void MigrationRecipientCommonData::validateTenantId(IDLParserErrorContext& ctxt, const std::string& value)
{
    uassertStatusOK(tenant_migration_util::validateDatabasePrefix(value));
}

void MigrationRecipientCommonData::validateTenantId(const std::string& value)
{
    uassertStatusOK(tenant_migration_util::validateDatabasePrefix(value));
}


MigrationRecipientCommonData MigrationRecipientCommonData::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<MigrationRecipientCommonData>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void MigrationRecipientCommonData::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<5> usedFields;
    const size_t kMigrationIdBit = 0;
    const size_t kDonorConnectionStringBit = 1;
    const size_t kTenantIdBit = 2;
    const size_t kReadPreferenceBit = 3;
    const size_t kRecipientCertificateForDonorBit = 4;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kMigrationIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kMigrationIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMigrationIdBit);

                _hasMigrationId = true;
                _migrationId = UUID(uassertStatusOK(UUID::parse(element)));
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
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kMigrationIdBit]) {
            ctxt.throwMissingField(kMigrationIdFieldName);
        }
        if (!usedFields[kDonorConnectionStringBit]) {
            ctxt.throwMissingField(kDonorConnectionStringFieldName);
        }
        if (!usedFields[kTenantIdBit]) {
            ctxt.throwMissingField(kTenantIdFieldName);
        }
        if (!usedFields[kReadPreferenceBit]) {
            ctxt.throwMissingField(kReadPreferenceFieldName);
        }
    }

}


void MigrationRecipientCommonData::serialize(BSONObjBuilder* builder) const {
    invariant(_hasMigrationId && _hasDonorConnectionString && _hasTenantId && _hasReadPreference);

    {
        ConstDataRange tempCDR = _migrationId.toCDR();
        builder->append(kMigrationIdFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    builder->append(kDonorConnectionStringFieldName, _donorConnectionString);

    builder->append(kTenantIdFieldName, _tenantId);

    {
        const BSONObj localObject = _readPreference.toInnerBSON();
        builder->append(kReadPreferenceFieldName, localObject);
    }

    if (_recipientCertificateForDonor.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kRecipientCertificateForDonorFieldName));
        _recipientCertificateForDonor.get().serialize(&subObjBuilder);
    }

}


BSONObj MigrationRecipientCommonData::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData RecipientSyncData::kMigrationRecipientCommonDataFieldName;
constexpr StringData RecipientSyncData::kDbNameFieldName;
constexpr StringData RecipientSyncData::kDonorConnectionStringFieldName;
constexpr StringData RecipientSyncData::kMigrationIdFieldName;
constexpr StringData RecipientSyncData::kReadPreferenceFieldName;
constexpr StringData RecipientSyncData::kRecipientCertificateForDonorFieldName;
constexpr StringData RecipientSyncData::kReturnAfterReachingDonorTimestampFieldName;
constexpr StringData RecipientSyncData::kStartMigrationDonorTimestampFieldName;
constexpr StringData RecipientSyncData::kTenantIdFieldName;
constexpr StringData RecipientSyncData::kCommandName;

const std::vector<StringData> RecipientSyncData::_knownBSONFields {
    RecipientSyncData::kMigrationRecipientCommonDataFieldName,
    RecipientSyncData::kDonorConnectionStringFieldName,
    RecipientSyncData::kMigrationIdFieldName,
    RecipientSyncData::kReadPreferenceFieldName,
    RecipientSyncData::kRecipientCertificateForDonorFieldName,
    RecipientSyncData::kReturnAfterReachingDonorTimestampFieldName,
    RecipientSyncData::kStartMigrationDonorTimestampFieldName,
    RecipientSyncData::kTenantIdFieldName,
    RecipientSyncData::kCommandName,
};
const std::vector<StringData> RecipientSyncData::_knownOP_MSGFields {
    RecipientSyncData::kMigrationRecipientCommonDataFieldName,
    RecipientSyncData::kDbNameFieldName,
    RecipientSyncData::kDonorConnectionStringFieldName,
    RecipientSyncData::kMigrationIdFieldName,
    RecipientSyncData::kReadPreferenceFieldName,
    RecipientSyncData::kRecipientCertificateForDonorFieldName,
    RecipientSyncData::kReturnAfterReachingDonorTimestampFieldName,
    RecipientSyncData::kStartMigrationDonorTimestampFieldName,
    RecipientSyncData::kTenantIdFieldName,
    RecipientSyncData::kCommandName,
};

RecipientSyncData::RecipientSyncData() : _startMigrationDonorTimestamp(mongo::idl::preparsedValue<decltype(_startMigrationDonorTimestamp)>()), _hasStartMigrationDonorTimestamp(false), _hasDbName(false) {
    // Used for initialization only
}
RecipientSyncData::RecipientSyncData(mongo::Timestamp startMigrationDonorTimestamp) : _startMigrationDonorTimestamp(std::move(startMigrationDonorTimestamp)), _hasStartMigrationDonorTimestamp(true), _hasDbName(true) {
    // Used for initialization only
}

void RecipientSyncData::validateDonorConnectionString(IDLParserErrorContext& ctxt, const std::string& value)
{
    uassertStatusOK(tenant_migration_util::validateConnectionString(value));
}

void RecipientSyncData::validateDonorConnectionString(const std::string& value)
{
    uassertStatusOK(tenant_migration_util::validateConnectionString(value));
}

void RecipientSyncData::validateTenantId(IDLParserErrorContext& ctxt, const std::string& value)
{
    uassertStatusOK(tenant_migration_util::validateDatabasePrefix(value));
}

void RecipientSyncData::validateTenantId(const std::string& value)
{
    uassertStatusOK(tenant_migration_util::validateDatabasePrefix(value));
}

void RecipientSyncData::validateReturnAfterReachingDonorTimestamp(IDLParserErrorContext& ctxt, const mongo::Timestamp& value)
{
    uassertStatusOK(tenant_migration_util::validateTimestampNotNull(value));
}

void RecipientSyncData::validateReturnAfterReachingDonorTimestamp(const mongo::Timestamp& value)
{
    uassertStatusOK(tenant_migration_util::validateTimestampNotNull(value));
}

void RecipientSyncData::validateStartMigrationDonorTimestamp(IDLParserErrorContext& ctxt, const mongo::Timestamp& value)
{
    uassertStatusOK(tenant_migration_util::validateTimestampNotNull(value));
}

void RecipientSyncData::validateStartMigrationDonorTimestamp(const mongo::Timestamp& value)
{
    uassertStatusOK(tenant_migration_util::validateTimestampNotNull(value));
}


RecipientSyncData RecipientSyncData::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<RecipientSyncData>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void RecipientSyncData::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<9> usedFields;
    const size_t kMigrationIdBit = 0;
    const size_t kDonorConnectionStringBit = 1;
    const size_t kTenantIdBit = 2;
    const size_t kReadPreferenceBit = 3;
    const size_t kRecipientCertificateForDonorBit = 4;
    const size_t kReturnAfterReachingDonorTimestampBit = 5;
    const size_t kStartMigrationDonorTimestampBit = 6;
    const size_t kDbNameBit = 7;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kMigrationIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kMigrationIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMigrationIdBit);

                _migrationRecipientCommonData.setMigrationId(UUID(uassertStatusOK(UUID::parse(element))));
            }
        }
        else if (fieldName == kDonorConnectionStringFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kDonorConnectionStringBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDonorConnectionStringBit);

                _migrationRecipientCommonData.setDonorConnectionString(element.str());
            }
        }
        else if (fieldName == kTenantIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kTenantIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTenantIdBit);

                _migrationRecipientCommonData.setTenantId(element.str());
            }
        }
        else if (fieldName == kReadPreferenceFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kReadPreferenceBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kReadPreferenceBit);

                const BSONObj localObject = element.Obj();
                _migrationRecipientCommonData.setReadPreference(ReadPreferenceSetting::fromInnerBSONForIDL(localObject));
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
                _migrationRecipientCommonData.setRecipientCertificateForDonor(boost::optional<mongo::TenantMigrationPEMPayload>(mongo::TenantMigrationPEMPayload::parse(tempContext, localObject)));
            }
        }
        else if (fieldName == kReturnAfterReachingDonorTimestampFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, bsonTimestamp))) {
                if (MONGO_unlikely(usedFields[kReturnAfterReachingDonorTimestampBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kReturnAfterReachingDonorTimestampBit);

                {
                    auto value = element.timestamp();
                    validateReturnAfterReachingDonorTimestamp(value);
                    _returnAfterReachingDonorTimestamp = std::move(value);
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
        if (!usedFields[kMigrationIdBit]) {
            ctxt.throwMissingField(kMigrationIdFieldName);
        }
        if (!usedFields[kDonorConnectionStringBit]) {
            ctxt.throwMissingField(kDonorConnectionStringFieldName);
        }
        if (!usedFields[kTenantIdBit]) {
            ctxt.throwMissingField(kTenantIdFieldName);
        }
        if (!usedFields[kReadPreferenceBit]) {
            ctxt.throwMissingField(kReadPreferenceFieldName);
        }
        if (!usedFields[kStartMigrationDonorTimestampBit]) {
            ctxt.throwMissingField(kStartMigrationDonorTimestampFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

}

RecipientSyncData RecipientSyncData::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto object = mongo::idl::preparsedValue<RecipientSyncData>();
    object.parseProtected(ctxt, request);
    return object;
}
void RecipientSyncData::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<9> usedFields;
    const size_t kMigrationIdBit = 0;
    const size_t kDonorConnectionStringBit = 1;
    const size_t kTenantIdBit = 2;
    const size_t kReadPreferenceBit = 3;
    const size_t kRecipientCertificateForDonorBit = 4;
    const size_t kReturnAfterReachingDonorTimestampBit = 5;
    const size_t kStartMigrationDonorTimestampBit = 6;
    const size_t kDbNameBit = 7;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kMigrationIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kMigrationIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMigrationIdBit);

                _migrationRecipientCommonData.setMigrationId(UUID(uassertStatusOK(UUID::parse(element))));
            }
        }
        else if (fieldName == kDonorConnectionStringFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kDonorConnectionStringBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDonorConnectionStringBit);

                _migrationRecipientCommonData.setDonorConnectionString(element.str());
            }
        }
        else if (fieldName == kTenantIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kTenantIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTenantIdBit);

                _migrationRecipientCommonData.setTenantId(element.str());
            }
        }
        else if (fieldName == kReadPreferenceFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kReadPreferenceBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kReadPreferenceBit);

                const BSONObj localObject = element.Obj();
                _migrationRecipientCommonData.setReadPreference(ReadPreferenceSetting::fromInnerBSONForIDL(localObject));
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
                _migrationRecipientCommonData.setRecipientCertificateForDonor(boost::optional<mongo::TenantMigrationPEMPayload>(mongo::TenantMigrationPEMPayload::parse(tempContext, localObject)));
            }
        }
        else if (fieldName == kReturnAfterReachingDonorTimestampFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, bsonTimestamp))) {
                if (MONGO_unlikely(usedFields[kReturnAfterReachingDonorTimestampBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kReturnAfterReachingDonorTimestampBit);

                {
                    auto value = element.timestamp();
                    validateReturnAfterReachingDonorTimestamp(value);
                    _returnAfterReachingDonorTimestamp = std::move(value);
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
        if (!usedFields[kMigrationIdBit]) {
            ctxt.throwMissingField(kMigrationIdFieldName);
        }
        if (!usedFields[kDonorConnectionStringBit]) {
            ctxt.throwMissingField(kDonorConnectionStringFieldName);
        }
        if (!usedFields[kTenantIdBit]) {
            ctxt.throwMissingField(kTenantIdFieldName);
        }
        if (!usedFields[kReadPreferenceBit]) {
            ctxt.throwMissingField(kReadPreferenceFieldName);
        }
        if (!usedFields[kStartMigrationDonorTimestampBit]) {
            ctxt.throwMissingField(kStartMigrationDonorTimestampFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

}

void RecipientSyncData::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasStartMigrationDonorTimestamp && _hasDbName);

    builder->append("recipientSyncData"_sd, 1);
    {
        _migrationRecipientCommonData.serialize(builder);
    }

    if (_returnAfterReachingDonorTimestamp.is_initialized()) {
        builder->append(kReturnAfterReachingDonorTimestampFieldName, _returnAfterReachingDonorTimestamp.get());
    }

    builder->append(kStartMigrationDonorTimestampFieldName, _startMigrationDonorTimestamp);

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest RecipientSyncData::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasStartMigrationDonorTimestamp && _hasDbName);

        builder->append("recipientSyncData"_sd, 1);
        {
            _migrationRecipientCommonData.serialize(builder);
        }

        if (_returnAfterReachingDonorTimestamp.is_initialized()) {
            builder->append(kReturnAfterReachingDonorTimestampFieldName, _returnAfterReachingDonorTimestamp.get());
        }

        builder->append(kStartMigrationDonorTimestampFieldName, _startMigrationDonorTimestamp);

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj RecipientSyncData::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData RecipientForgetMigration::kMigrationRecipientCommonDataFieldName;
constexpr StringData RecipientForgetMigration::kDbNameFieldName;
constexpr StringData RecipientForgetMigration::kDonorConnectionStringFieldName;
constexpr StringData RecipientForgetMigration::kMigrationIdFieldName;
constexpr StringData RecipientForgetMigration::kReadPreferenceFieldName;
constexpr StringData RecipientForgetMigration::kRecipientCertificateForDonorFieldName;
constexpr StringData RecipientForgetMigration::kTenantIdFieldName;
constexpr StringData RecipientForgetMigration::kCommandName;

const std::vector<StringData> RecipientForgetMigration::_knownBSONFields {
    RecipientForgetMigration::kMigrationRecipientCommonDataFieldName,
    RecipientForgetMigration::kDonorConnectionStringFieldName,
    RecipientForgetMigration::kMigrationIdFieldName,
    RecipientForgetMigration::kReadPreferenceFieldName,
    RecipientForgetMigration::kRecipientCertificateForDonorFieldName,
    RecipientForgetMigration::kTenantIdFieldName,
    RecipientForgetMigration::kCommandName,
};
const std::vector<StringData> RecipientForgetMigration::_knownOP_MSGFields {
    RecipientForgetMigration::kMigrationRecipientCommonDataFieldName,
    RecipientForgetMigration::kDbNameFieldName,
    RecipientForgetMigration::kDonorConnectionStringFieldName,
    RecipientForgetMigration::kMigrationIdFieldName,
    RecipientForgetMigration::kReadPreferenceFieldName,
    RecipientForgetMigration::kRecipientCertificateForDonorFieldName,
    RecipientForgetMigration::kTenantIdFieldName,
    RecipientForgetMigration::kCommandName,
};

RecipientForgetMigration::RecipientForgetMigration() : _hasDbName(false) {
    // Used for initialization only
}

void RecipientForgetMigration::validateDonorConnectionString(IDLParserErrorContext& ctxt, const std::string& value)
{
    uassertStatusOK(tenant_migration_util::validateConnectionString(value));
}

void RecipientForgetMigration::validateDonorConnectionString(const std::string& value)
{
    uassertStatusOK(tenant_migration_util::validateConnectionString(value));
}

void RecipientForgetMigration::validateTenantId(IDLParserErrorContext& ctxt, const std::string& value)
{
    uassertStatusOK(tenant_migration_util::validateDatabasePrefix(value));
}

void RecipientForgetMigration::validateTenantId(const std::string& value)
{
    uassertStatusOK(tenant_migration_util::validateDatabasePrefix(value));
}


RecipientForgetMigration RecipientForgetMigration::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<RecipientForgetMigration>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void RecipientForgetMigration::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<7> usedFields;
    const size_t kMigrationIdBit = 0;
    const size_t kDonorConnectionStringBit = 1;
    const size_t kTenantIdBit = 2;
    const size_t kReadPreferenceBit = 3;
    const size_t kRecipientCertificateForDonorBit = 4;
    const size_t kDbNameBit = 5;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kMigrationIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kMigrationIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMigrationIdBit);

                _migrationRecipientCommonData.setMigrationId(UUID(uassertStatusOK(UUID::parse(element))));
            }
        }
        else if (fieldName == kDonorConnectionStringFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kDonorConnectionStringBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDonorConnectionStringBit);

                _migrationRecipientCommonData.setDonorConnectionString(element.str());
            }
        }
        else if (fieldName == kTenantIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kTenantIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTenantIdBit);

                _migrationRecipientCommonData.setTenantId(element.str());
            }
        }
        else if (fieldName == kReadPreferenceFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kReadPreferenceBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kReadPreferenceBit);

                const BSONObj localObject = element.Obj();
                _migrationRecipientCommonData.setReadPreference(ReadPreferenceSetting::fromInnerBSONForIDL(localObject));
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
                _migrationRecipientCommonData.setRecipientCertificateForDonor(boost::optional<mongo::TenantMigrationPEMPayload>(mongo::TenantMigrationPEMPayload::parse(tempContext, localObject)));
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
        if (!usedFields[kMigrationIdBit]) {
            ctxt.throwMissingField(kMigrationIdFieldName);
        }
        if (!usedFields[kDonorConnectionStringBit]) {
            ctxt.throwMissingField(kDonorConnectionStringFieldName);
        }
        if (!usedFields[kTenantIdBit]) {
            ctxt.throwMissingField(kTenantIdFieldName);
        }
        if (!usedFields[kReadPreferenceBit]) {
            ctxt.throwMissingField(kReadPreferenceFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

}

RecipientForgetMigration RecipientForgetMigration::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto object = mongo::idl::preparsedValue<RecipientForgetMigration>();
    object.parseProtected(ctxt, request);
    return object;
}
void RecipientForgetMigration::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<7> usedFields;
    const size_t kMigrationIdBit = 0;
    const size_t kDonorConnectionStringBit = 1;
    const size_t kTenantIdBit = 2;
    const size_t kReadPreferenceBit = 3;
    const size_t kRecipientCertificateForDonorBit = 4;
    const size_t kDbNameBit = 5;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kMigrationIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kMigrationIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMigrationIdBit);

                _migrationRecipientCommonData.setMigrationId(UUID(uassertStatusOK(UUID::parse(element))));
            }
        }
        else if (fieldName == kDonorConnectionStringFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kDonorConnectionStringBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDonorConnectionStringBit);

                _migrationRecipientCommonData.setDonorConnectionString(element.str());
            }
        }
        else if (fieldName == kTenantIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kTenantIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTenantIdBit);

                _migrationRecipientCommonData.setTenantId(element.str());
            }
        }
        else if (fieldName == kReadPreferenceFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kReadPreferenceBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kReadPreferenceBit);

                const BSONObj localObject = element.Obj();
                _migrationRecipientCommonData.setReadPreference(ReadPreferenceSetting::fromInnerBSONForIDL(localObject));
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
                _migrationRecipientCommonData.setRecipientCertificateForDonor(boost::optional<mongo::TenantMigrationPEMPayload>(mongo::TenantMigrationPEMPayload::parse(tempContext, localObject)));
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
        if (!usedFields[kMigrationIdBit]) {
            ctxt.throwMissingField(kMigrationIdFieldName);
        }
        if (!usedFields[kDonorConnectionStringBit]) {
            ctxt.throwMissingField(kDonorConnectionStringFieldName);
        }
        if (!usedFields[kTenantIdBit]) {
            ctxt.throwMissingField(kTenantIdFieldName);
        }
        if (!usedFields[kReadPreferenceBit]) {
            ctxt.throwMissingField(kReadPreferenceFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

}

void RecipientForgetMigration::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    builder->append("recipientForgetMigration"_sd, 1);
    {
        _migrationRecipientCommonData.serialize(builder);
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest RecipientForgetMigration::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        builder->append("recipientForgetMigration"_sd, 1);
        {
            _migrationRecipientCommonData.serialize(builder);
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj RecipientForgetMigration::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
