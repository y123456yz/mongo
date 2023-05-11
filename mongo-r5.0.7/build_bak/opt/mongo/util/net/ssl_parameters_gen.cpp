/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/util/net/ssl_parameters_gen.h --output build/opt/mongo/util/net/ssl_parameters_gen.cpp src/mongo/util/net/ssl_parameters.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/util/net/ssl_parameters_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"
#include "mongo/idl/server_parameter.h"
#include "mongo/idl/server_parameter_with_storage.h"

namespace mongo {

constexpr StringData TLSCATrust::kRolesFieldName;
constexpr StringData TLSCATrust::kSha256FieldName;


TLSCATrust::TLSCATrust() : _sha256(mongo::idl::preparsedValue<decltype(_sha256)>()), _hasSha256(false), _hasRoles(false) {
    // Used for initialization only
}
TLSCATrust::TLSCATrust(mongo::SHA256Block sha256, std::vector<mongo::RoleName> roles) : _sha256(std::move(sha256)), _roles(std::move(roles)), _hasSha256(true), _hasRoles(true) {
    // Used for initialization only
}


TLSCATrust TLSCATrust::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<TLSCATrust>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void TLSCATrust::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kSha256Bit = 0;
    const size_t kRolesBit = 1;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kSha256FieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kSha256Bit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSha256Bit);

                _hasSha256 = true;
                _sha256 = SHA256Block::fromHexString(element.valueStringData());
            }
        }
        else if (fieldName == kRolesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kRolesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRolesBit);

                _hasRoles = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kRolesFieldName, &ctxt);
            std::vector<mongo::RoleName> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    values.emplace_back(RoleName::parseFromBSON(arrayElement));
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _roles = std::move(values);
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kSha256Bit]) {
            ctxt.throwMissingField(kSha256FieldName);
        }
        if (!usedFields[kRolesBit]) {
            ctxt.throwMissingField(kRolesFieldName);
        }
    }

}


void TLSCATrust::serialize(BSONObjBuilder* builder) const {
    invariant(_hasSha256 && _hasRoles);

    {
        builder->append(kSha256FieldName, _sha256.toHexString());
    }

    {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kRolesFieldName));
        for (const auto& item : _roles) {
            item.serializeToBSON(&arrayBuilder);
        }
    }

}


BSONObj TLSCATrust::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

bool tlsOCSPEnabled{true};
std::int32_t tlsOCSPCacheSize{300};
long long kOCSPStaplingRefreshPeriodSecs{-1};
int gTLSOCSPVerifyTimeoutSecs{5};
int gTLSOCSPStaplingTimeoutSecs{-1};
/**
 * sslMode: Transition from allowSSL to preferSSL, or from preferSSL to requireSSL
 */
Status SSLModeServerParameter::set(const BSONElement& newValueElement) {
    auto swValue = coerceToString(newValueElement, false);
    if (!swValue.isOK()) {
        return swValue.getStatus();
    }
    return setFromString(swValue.getValue());
}

/**
 * tlsMode: Transition from allowTLS to preferTLS, or from preferTLS to requireTLS
 */
Status TLSModeServerParameter::set(const BSONElement& newValueElement) {
    auto swValue = coerceToString(newValueElement, false);
    if (!swValue.isOK()) {
        return swValue.getStatus();
    }
    return setFromString(swValue.getValue());
}

/**
 * tlsX509ClusterAuthDNOverride: Distinguished name to use for cluster membership
 */
Status ClusterMemberDNOverride::set(const BSONElement& newValueElement) {
    auto swValue = coerceToString(newValueElement, false);
    if (!swValue.isOK()) {
        return swValue.getStatus();
    }
    return setFromString(swValue.getValue());
}

std::int32_t tlsX509ExpirationWarningThresholdDays{30};
MONGO_SERVER_PARAMETER_REGISTER(idl_bb7993b0c90b6b2629e378dfd88575ca0049ef7f)(InitializerContext*) {
    /**
     * OpenSSL Diffie-Hellman parameters
     */
    [[maybe_unused]] auto* scp_0 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("opensslDiffieHellmanParameters", sslGlobalParams.sslPEMTempDHParam);
        return ret;
    })();

    /**
     * Do not display a warning when client fails to send a TLS certificate
     */
    [[maybe_unused]] auto* scp_1 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("suppressNoTLSPeerCertificateWarning", sslGlobalParams.suppressNoTLSPeerCertificateWarning);
        return ret;
    })();

    /**
     * Do not send a client certificate when establishing intra-cluster connections
     */
    auto* scp_2 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("tlsWithholdClientCertificate", sslGlobalParams.tlsWithholdClientCertificate);
        return ret;
    })();
    [[maybe_unused]] auto* scp_2_0 = new IDLServerParameterDeprecatedAlias("sslWithholdClientCertificate", scp_2);

    /**
     * Enable OCSP
     */
    [[maybe_unused]] auto* scp_3 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("ocspEnabled", tlsOCSPEnabled);
        return ret;
    })();

    /**
     * Maximum number of entries in the OCSP Cache
     */
    [[maybe_unused]] auto* scp_4 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("ocspCacheSize", tlsOCSPCacheSize);
        ret->addBound<idl_server_parameter_detail::GT>(0);
        return ret;
    })();

    /**
     * Interval at which the OCSP response will be refreshed
     */
    auto* scp_5 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("ocspStaplingRefreshPeriodSecs", kOCSPStaplingRefreshPeriodSecs);
        ret->addBound<idl_server_parameter_detail::GTE>(1);
        return ret;
    })();
    [[maybe_unused]] auto* scp_5_0 = new IDLServerParameterDeprecatedAlias("ocspValidationRefreshPeriodSecs", scp_5);

    /**
     * How long the http client should wait before timing out when fetching OCSP Responses for peer certificate
     */
    [[maybe_unused]] auto* scp_6 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("tlsOCSPVerifyTimeoutSecs", gTLSOCSPVerifyTimeoutSecs);
        ret->addBound<idl_server_parameter_detail::GTE>(1);
        return ret;
    })();

    /**
     * How long the http client should wait before timing out when fetching OCSP Responses for stapling. If not set, value is taken  from tlsClientOCSPTimeoutSecs
     */
    [[maybe_unused]] auto* scp_7 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("tlsOCSPStaplingTimeoutSecs", gTLSOCSPStaplingTimeoutSecs);
        ret->addBound<idl_server_parameter_detail::GTE>(1);
        return ret;
    })();

    /**
     * Cipher configuration string for OpenSSL based TLS connections
     */
    [[maybe_unused]] auto* scp_8 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("opensslCipherConfig", sslGlobalParams.sslCipherConfig);
        ret->addValidator(validateOpensslCipherConfig);
        return ret;
    })();

    /**
     * Cipher configuration string for OpenSSL based connections that use TLS 1.3 or newer ONLY
     */
    [[maybe_unused]] auto* scp_9 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("opensslCipherSuiteConfig", sslGlobalParams.sslCipherSuiteConfig);
        return ret;
    })();

    /**
     * Suppress logging of warnings when non-SSL connections are accepted in preferSSL mode
     */
    auto* scp_10 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("disableNonTLSConnectionLogging", sslGlobalParams.disableNonSSLConnectionLogging);
        ret->setOnUpdate(onUpdateDisableNonTLSConnectionLogging);
        ret->addValidator(validateDisableNonTLSConnectionLogging);
        return ret;
    })();
    [[maybe_unused]] auto* scp_10_0 = new IDLServerParameterDeprecatedAlias("disableNonSSLConnectionLogging", scp_10);

    /**
     * Transition from allowSSL to preferSSL, or from preferSSL to requireSSL
     */
    [[maybe_unused]] auto* scp_11 = ([]() -> ServerParameter* {
        return new SSLModeServerParameter("sslMode", ServerParameterType::kRuntimeOnly);
    })();

    /**
     * Transition from allowTLS to preferTLS, or from preferTLS to requireTLS
     */
    [[maybe_unused]] auto* scp_12 = ([]() -> ServerParameter* {
        return new TLSModeServerParameter("tlsMode", ServerParameterType::kRuntimeOnly);
    })();

    /**
     * Distinguished name to use for cluster membership
     */
    [[maybe_unused]] auto* scp_13 = ([]() -> ServerParameter* {
        return new ClusterMemberDNOverride("tlsX509ClusterAuthDNOverride", ServerParameterType::kStartupAndRuntime);
    })();

    /**
     * If a client connects to the server using an X509 certificate expiring in less than the configured number of days, a warning will be emitted to the server logs. Set this value to 0 to disable the warning.
     */
    [[maybe_unused]] auto* scp_14 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("tlsX509ExpirationWarningThresholdDays", tlsX509ExpirationWarningThresholdDays);
        ret->addBound<idl_server_parameter_detail::GTE>(0);
        return ret;
    })();

    /**
     * Specify by fingerprint the certificate authorities which are allowed to accept role authorizations from an X509 certificate and the specific roles they are allowed to impart.
     */
#if defined(__linux__)
    [[maybe_unused]] auto* scp_15 = ([]() -> ServerParameter* {
        return new TLSCATrustsSetParameter("tlsCATrusts", ServerParameterType::kStartupOnly);
    })();
#endif

}
}  // namespace mongo
