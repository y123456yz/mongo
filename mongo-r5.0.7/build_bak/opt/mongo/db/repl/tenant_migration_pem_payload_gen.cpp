/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/repl/tenant_migration_pem_payload_gen.h --output build/opt/mongo/db/repl/tenant_migration_pem_payload_gen.cpp src/mongo/db/repl/tenant_migration_pem_payload.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/repl/tenant_migration_pem_payload_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData TenantMigrationPEMPayload::kCertificateFieldName;
constexpr StringData TenantMigrationPEMPayload::kPrivateKeyFieldName;


TenantMigrationPEMPayload::TenantMigrationPEMPayload() : _certificate(mongo::idl::preparsedValue<decltype(_certificate)>()), _privateKey(mongo::idl::preparsedValue<decltype(_privateKey)>()), _hasCertificate(false), _hasPrivateKey(false) {
    // Used for initialization only
}
TenantMigrationPEMPayload::TenantMigrationPEMPayload(std::string certificate, std::string privateKey) : _certificate(std::move(certificate)), _privateKey(std::move(privateKey)), _hasCertificate(true), _hasPrivateKey(true) {
    // Used for initialization only
}

void TenantMigrationPEMPayload::validateCertificate(IDLParserErrorContext& ctxt, const std::string& value)
{
    uassertStatusOK(tenant_migration_util::validateCertificatePEMPayload(value));
}

void TenantMigrationPEMPayload::validateCertificate(const std::string& value)
{
    uassertStatusOK(tenant_migration_util::validateCertificatePEMPayload(value));
}

void TenantMigrationPEMPayload::validatePrivateKey(IDLParserErrorContext& ctxt, const std::string& value)
{
    uassertStatusOK(tenant_migration_util::validatePrivateKeyPEMPayload(value));
}

void TenantMigrationPEMPayload::validatePrivateKey(const std::string& value)
{
    uassertStatusOK(tenant_migration_util::validatePrivateKeyPEMPayload(value));
}


TenantMigrationPEMPayload TenantMigrationPEMPayload::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<TenantMigrationPEMPayload>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void TenantMigrationPEMPayload::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kCertificateBit = 0;
    const size_t kPrivateKeyBit = 1;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kCertificateFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kCertificateBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCertificateBit);

                _hasCertificate = true;
                {
                    auto value = element.str();
                    validateCertificate(value);
                    _certificate = std::move(value);
                }
            }
        }
        else if (fieldName == kPrivateKeyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kPrivateKeyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPrivateKeyBit);

                _hasPrivateKey = true;
                {
                    auto value = element.str();
                    validatePrivateKey(value);
                    _privateKey = std::move(value);
                }
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kCertificateBit]) {
            ctxt.throwMissingField(kCertificateFieldName);
        }
        if (!usedFields[kPrivateKeyBit]) {
            ctxt.throwMissingField(kPrivateKeyFieldName);
        }
    }

}


void TenantMigrationPEMPayload::serialize(BSONObjBuilder* builder) const {
    invariant(_hasCertificate && _hasPrivateKey);

    builder->append(kCertificateFieldName, _certificate);

    builder->append(kPrivateKeyFieldName, _privateKey);

}


BSONObj TenantMigrationPEMPayload::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
