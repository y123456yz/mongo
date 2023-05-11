/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/repl/tenant_migration_pem_payload_gen.h --output build/opt/mongo/db/repl/tenant_migration_pem_payload_gen.cpp src/mongo/db/repl/tenant_migration_pem_payload.idl
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
#include "mongo/db/namespace_string.h"
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
 * Contains SSL certificate and private key PEM blobs for a replica set.
 */
class TenantMigrationPEMPayload {
public:
    static constexpr auto kCertificateFieldName = "certificate"_sd;
    static constexpr auto kPrivateKeyFieldName = "privateKey"_sd;

    TenantMigrationPEMPayload();
    TenantMigrationPEMPayload(std::string certificate, std::string privateKey);

    static TenantMigrationPEMPayload parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Certificate PEM blob.
     */
    const StringData getCertificate() const& { return _certificate; }
    void getCertificate() && = delete;
    void setCertificate(StringData value) & { auto _tmpValue = value.toString(); validateCertificate(_tmpValue); _certificate = std::move(_tmpValue); _hasCertificate = true; }

    /**
     * Private key PEM blob.
     */
    const StringData getPrivateKey() const& { return _privateKey; }
    void getPrivateKey() && = delete;
    void setPrivateKey(StringData value) & { auto _tmpValue = value.toString(); validatePrivateKey(_tmpValue); _privateKey = std::move(_tmpValue); _hasPrivateKey = true; }


    friend bool operator==(const TenantMigrationPEMPayload& left, const TenantMigrationPEMPayload& right) {
        return left._certificate == right._certificate && left._privateKey == right._privateKey;
    }

    friend bool operator!=(const TenantMigrationPEMPayload& left, const TenantMigrationPEMPayload& right) {
        return left._certificate != right._certificate || left._privateKey != right._privateKey;
    }
    friend bool operator<(const TenantMigrationPEMPayload& left, const TenantMigrationPEMPayload& right) {
        return left._certificate < right._certificate || (!(right._certificate < left._certificate) && (left._privateKey < right._privateKey));
    }
    friend bool operator>(const TenantMigrationPEMPayload& left, const TenantMigrationPEMPayload& right) {
        return right < left;
    }
    friend bool operator<=(const TenantMigrationPEMPayload& left, const TenantMigrationPEMPayload& right) {
        return !(right < left);
    }
    friend bool operator>=(const TenantMigrationPEMPayload& left, const TenantMigrationPEMPayload& right) {
        return !(left < right);
    }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    void validateCertificate(const std::string& value);
    void validateCertificate(IDLParserErrorContext& ctxt, const std::string& value);

    void validatePrivateKey(const std::string& value);
    void validatePrivateKey(IDLParserErrorContext& ctxt, const std::string& value);

private:
    std::string _certificate;
    std::string _privateKey;
    bool _hasCertificate : 1;
    bool _hasPrivateKey : 1;
};

}  // namespace mongo
