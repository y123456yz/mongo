/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/commands/tenant_migration_donor_cmds_gen.h --output build/opt/mongo/db/commands/tenant_migration_donor_cmds_gen.cpp src/mongo/db/commands/tenant_migration_donor_cmds.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/commands/tenant_migration_donor_cmds_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData DonorStartMigrationResponse::kAbortReasonFieldName;
constexpr StringData DonorStartMigrationResponse::kStateFieldName;


DonorStartMigrationResponse::DonorStartMigrationResponse() : _state(mongo::idl::preparsedValue<decltype(_state)>()), _hasState(false) {
    // Used for initialization only
}
DonorStartMigrationResponse::DonorStartMigrationResponse(mongo::TenantMigrationDonorStateEnum state) : _state(std::move(state)), _hasState(true) {
    // Used for initialization only
}


DonorStartMigrationResponse DonorStartMigrationResponse::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<DonorStartMigrationResponse>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void DonorStartMigrationResponse::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kStateBit = 0;
    const size_t kAbortReasonBit = 1;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kStateFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kStateBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStateBit);

                _hasState = true;
                IDLParserErrorContext tempContext(kStateFieldName, &ctxt);
                _state = TenantMigrationDonorState_parse(tempContext, element.valueStringData());
            }
        }
        else if (fieldName == kAbortReasonFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kAbortReasonBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAbortReasonBit);

                _abortReason = element.Obj();
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
        if (!usedFields[kStateBit]) {
            ctxt.throwMissingField(kStateFieldName);
        }
    }

}


void DonorStartMigrationResponse::serialize(BSONObjBuilder* builder) const {
    invariant(_hasState);

    {
        builder->append(kStateFieldName, ::mongo::TenantMigrationDonorState_serializer(_state));
    }

    if (_abortReason.is_initialized()) {
        builder->append(kAbortReasonFieldName, _abortReason.get());
    }

}


BSONObj DonorStartMigrationResponse::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData DonorStartMigration::kDbNameFieldName;
constexpr StringData DonorStartMigration::kDonorCertificateForRecipientFieldName;
constexpr StringData DonorStartMigration::kMigrationIdFieldName;
constexpr StringData DonorStartMigration::kReadPreferenceFieldName;
constexpr StringData DonorStartMigration::kRecipientCertificateForDonorFieldName;
constexpr StringData DonorStartMigration::kRecipientConnectionStringFieldName;
constexpr StringData DonorStartMigration::kTenantIdFieldName;
constexpr StringData DonorStartMigration::kCommandName;

const std::vector<StringData> DonorStartMigration::_knownBSONFields {
    DonorStartMigration::kDonorCertificateForRecipientFieldName,
    DonorStartMigration::kMigrationIdFieldName,
    DonorStartMigration::kReadPreferenceFieldName,
    DonorStartMigration::kRecipientCertificateForDonorFieldName,
    DonorStartMigration::kRecipientConnectionStringFieldName,
    DonorStartMigration::kTenantIdFieldName,
    DonorStartMigration::kCommandName,
};
const std::vector<StringData> DonorStartMigration::_knownOP_MSGFields {
    DonorStartMigration::kDbNameFieldName,
    DonorStartMigration::kDonorCertificateForRecipientFieldName,
    DonorStartMigration::kMigrationIdFieldName,
    DonorStartMigration::kReadPreferenceFieldName,
    DonorStartMigration::kRecipientCertificateForDonorFieldName,
    DonorStartMigration::kRecipientConnectionStringFieldName,
    DonorStartMigration::kTenantIdFieldName,
    DonorStartMigration::kCommandName,
};

DonorStartMigration::DonorStartMigration() : _migrationId(mongo::idl::preparsedValue<decltype(_migrationId)>()), _recipientConnectionString(mongo::idl::preparsedValue<decltype(_recipientConnectionString)>()), _tenantId(mongo::idl::preparsedValue<decltype(_tenantId)>()), _readPreference(mongo::idl::preparsedValue<decltype(_readPreference)>()), _hasMigrationId(false), _hasRecipientConnectionString(false), _hasTenantId(false), _hasReadPreference(false), _hasDbName(false) {
    // Used for initialization only
}
DonorStartMigration::DonorStartMigration(mongo::UUID migrationId, std::string recipientConnectionString, std::string tenantId, mongo::ReadPreferenceSetting readPreference) : _migrationId(std::move(migrationId)), _recipientConnectionString(std::move(recipientConnectionString)), _tenantId(std::move(tenantId)), _readPreference(std::move(readPreference)), _hasMigrationId(true), _hasRecipientConnectionString(true), _hasTenantId(true), _hasReadPreference(true), _hasDbName(true) {
    // Used for initialization only
}

void DonorStartMigration::validateRecipientConnectionString(IDLParserErrorContext& ctxt, const std::string& value)
{
    uassertStatusOK(tenant_migration_util::validateConnectionString(value));
}

void DonorStartMigration::validateRecipientConnectionString(const std::string& value)
{
    uassertStatusOK(tenant_migration_util::validateConnectionString(value));
}

void DonorStartMigration::validateTenantId(IDLParserErrorContext& ctxt, const std::string& value)
{
    uassertStatusOK(tenant_migration_util::validateDatabasePrefix(value));
}

void DonorStartMigration::validateTenantId(const std::string& value)
{
    uassertStatusOK(tenant_migration_util::validateDatabasePrefix(value));
}


DonorStartMigration DonorStartMigration::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<DonorStartMigration>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void DonorStartMigration::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<7> usedFields;
    const size_t kMigrationIdBit = 0;
    const size_t kRecipientConnectionStringBit = 1;
    const size_t kTenantIdBit = 2;
    const size_t kReadPreferenceBit = 3;
    const size_t kDonorCertificateForRecipientBit = 4;
    const size_t kRecipientCertificateForDonorBit = 5;
    const size_t kDbNameBit = 6;
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

                _hasMigrationId = true;
                _migrationId = UUID(uassertStatusOK(UUID::parse(element)));
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
        if (!usedFields[kRecipientConnectionStringBit]) {
            ctxt.throwMissingField(kRecipientConnectionStringFieldName);
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

DonorStartMigration DonorStartMigration::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto object = mongo::idl::preparsedValue<DonorStartMigration>();
    object.parseProtected(ctxt, request);
    return object;
}
void DonorStartMigration::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<7> usedFields;
    const size_t kMigrationIdBit = 0;
    const size_t kRecipientConnectionStringBit = 1;
    const size_t kTenantIdBit = 2;
    const size_t kReadPreferenceBit = 3;
    const size_t kDonorCertificateForRecipientBit = 4;
    const size_t kRecipientCertificateForDonorBit = 5;
    const size_t kDbNameBit = 6;
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

                _hasMigrationId = true;
                _migrationId = UUID(uassertStatusOK(UUID::parse(element)));
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
        if (!usedFields[kRecipientConnectionStringBit]) {
            ctxt.throwMissingField(kRecipientConnectionStringFieldName);
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

void DonorStartMigration::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasMigrationId && _hasRecipientConnectionString && _hasTenantId && _hasReadPreference && _hasDbName);

    builder->append("donorStartMigration"_sd, 1);
    {
        ConstDataRange tempCDR = _migrationId.toCDR();
        builder->append(kMigrationIdFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    builder->append(kRecipientConnectionStringFieldName, _recipientConnectionString);

    builder->append(kTenantIdFieldName, _tenantId);

    {
        const BSONObj localObject = _readPreference.toInnerBSON();
        builder->append(kReadPreferenceFieldName, localObject);
    }

    if (_donorCertificateForRecipient.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kDonorCertificateForRecipientFieldName));
        _donorCertificateForRecipient.get().serialize(&subObjBuilder);
    }

    if (_recipientCertificateForDonor.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kRecipientCertificateForDonorFieldName));
        _recipientCertificateForDonor.get().serialize(&subObjBuilder);
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest DonorStartMigration::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasMigrationId && _hasRecipientConnectionString && _hasTenantId && _hasReadPreference && _hasDbName);

        builder->append("donorStartMigration"_sd, 1);
        {
            ConstDataRange tempCDR = _migrationId.toCDR();
            builder->append(kMigrationIdFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
        }

        builder->append(kRecipientConnectionStringFieldName, _recipientConnectionString);

        builder->append(kTenantIdFieldName, _tenantId);

        {
            const BSONObj localObject = _readPreference.toInnerBSON();
            builder->append(kReadPreferenceFieldName, localObject);
        }

        if (_donorCertificateForRecipient.is_initialized()) {
            BSONObjBuilder subObjBuilder(builder->subobjStart(kDonorCertificateForRecipientFieldName));
            _donorCertificateForRecipient.get().serialize(&subObjBuilder);
        }

        if (_recipientCertificateForDonor.is_initialized()) {
            BSONObjBuilder subObjBuilder(builder->subobjStart(kRecipientCertificateForDonorFieldName));
            _recipientCertificateForDonor.get().serialize(&subObjBuilder);
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj DonorStartMigration::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData DonorForgetMigration::kDbNameFieldName;
constexpr StringData DonorForgetMigration::kMigrationIdFieldName;
constexpr StringData DonorForgetMigration::kCommandName;

const std::vector<StringData> DonorForgetMigration::_knownBSONFields {
    DonorForgetMigration::kMigrationIdFieldName,
    DonorForgetMigration::kCommandName,
};
const std::vector<StringData> DonorForgetMigration::_knownOP_MSGFields {
    DonorForgetMigration::kDbNameFieldName,
    DonorForgetMigration::kMigrationIdFieldName,
    DonorForgetMigration::kCommandName,
};

DonorForgetMigration::DonorForgetMigration() : _migrationId(mongo::idl::preparsedValue<decltype(_migrationId)>()), _hasMigrationId(false), _hasDbName(false) {
    // Used for initialization only
}
DonorForgetMigration::DonorForgetMigration(mongo::UUID migrationId) : _migrationId(std::move(migrationId)), _hasMigrationId(true), _hasDbName(true) {
    // Used for initialization only
}


DonorForgetMigration DonorForgetMigration::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<DonorForgetMigration>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void DonorForgetMigration::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kMigrationIdBit = 0;
    const size_t kDbNameBit = 1;
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

                _hasMigrationId = true;
                _migrationId = UUID(uassertStatusOK(UUID::parse(element)));
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
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

}

DonorForgetMigration DonorForgetMigration::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto object = mongo::idl::preparsedValue<DonorForgetMigration>();
    object.parseProtected(ctxt, request);
    return object;
}
void DonorForgetMigration::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<2> usedFields;
    const size_t kMigrationIdBit = 0;
    const size_t kDbNameBit = 1;
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

                _hasMigrationId = true;
                _migrationId = UUID(uassertStatusOK(UUID::parse(element)));
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
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

}

void DonorForgetMigration::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasMigrationId && _hasDbName);

    builder->append("donorForgetMigration"_sd, 1);
    {
        ConstDataRange tempCDR = _migrationId.toCDR();
        builder->append(kMigrationIdFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest DonorForgetMigration::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasMigrationId && _hasDbName);

        builder->append("donorForgetMigration"_sd, 1);
        {
            ConstDataRange tempCDR = _migrationId.toCDR();
            builder->append(kMigrationIdFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj DonorForgetMigration::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData DonorAbortMigration::kDbNameFieldName;
constexpr StringData DonorAbortMigration::kMigrationIdFieldName;
constexpr StringData DonorAbortMigration::kCommandName;

const std::vector<StringData> DonorAbortMigration::_knownBSONFields {
    DonorAbortMigration::kMigrationIdFieldName,
    DonorAbortMigration::kCommandName,
};
const std::vector<StringData> DonorAbortMigration::_knownOP_MSGFields {
    DonorAbortMigration::kDbNameFieldName,
    DonorAbortMigration::kMigrationIdFieldName,
    DonorAbortMigration::kCommandName,
};

DonorAbortMigration::DonorAbortMigration() : _migrationId(mongo::idl::preparsedValue<decltype(_migrationId)>()), _hasMigrationId(false), _hasDbName(false) {
    // Used for initialization only
}
DonorAbortMigration::DonorAbortMigration(mongo::UUID migrationId) : _migrationId(std::move(migrationId)), _hasMigrationId(true), _hasDbName(true) {
    // Used for initialization only
}


DonorAbortMigration DonorAbortMigration::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<DonorAbortMigration>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void DonorAbortMigration::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kMigrationIdBit = 0;
    const size_t kDbNameBit = 1;
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

                _hasMigrationId = true;
                _migrationId = UUID(uassertStatusOK(UUID::parse(element)));
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
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

}

DonorAbortMigration DonorAbortMigration::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto object = mongo::idl::preparsedValue<DonorAbortMigration>();
    object.parseProtected(ctxt, request);
    return object;
}
void DonorAbortMigration::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<2> usedFields;
    const size_t kMigrationIdBit = 0;
    const size_t kDbNameBit = 1;
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

                _hasMigrationId = true;
                _migrationId = UUID(uassertStatusOK(UUID::parse(element)));
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
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

}

void DonorAbortMigration::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasMigrationId && _hasDbName);

    builder->append("donorAbortMigration"_sd, 1);
    {
        ConstDataRange tempCDR = _migrationId.toCDR();
        builder->append(kMigrationIdFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest DonorAbortMigration::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasMigrationId && _hasDbName);

        builder->append("donorAbortMigration"_sd, 1);
        {
            ConstDataRange tempCDR = _migrationId.toCDR();
            builder->append(kMigrationIdFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj DonorAbortMigration::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
