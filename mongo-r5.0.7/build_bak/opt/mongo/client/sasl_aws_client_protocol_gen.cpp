/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/client/sasl_aws_client_protocol_gen.h --output build/opt/mongo/client/sasl_aws_client_protocol_gen.cpp src/mongo/client/sasl_aws_client_protocol.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/client/sasl_aws_client_protocol_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData Ec2SecurityCredentials::kAccessKeyIdFieldName;
constexpr StringData Ec2SecurityCredentials::kCodeFieldName;
constexpr StringData Ec2SecurityCredentials::kExpirationFieldName;
constexpr StringData Ec2SecurityCredentials::kLastUpdatedFieldName;
constexpr StringData Ec2SecurityCredentials::kSecretAccessKeyFieldName;
constexpr StringData Ec2SecurityCredentials::kTokenFieldName;
constexpr StringData Ec2SecurityCredentials::kTypeFieldName;


Ec2SecurityCredentials::Ec2SecurityCredentials() : _code(mongo::idl::preparsedValue<decltype(_code)>()), _lastUpdated(mongo::idl::preparsedValue<decltype(_lastUpdated)>()), _type(mongo::idl::preparsedValue<decltype(_type)>()), _accessKeyId(mongo::idl::preparsedValue<decltype(_accessKeyId)>()), _secretAccessKey(mongo::idl::preparsedValue<decltype(_secretAccessKey)>()), _token(mongo::idl::preparsedValue<decltype(_token)>()), _expiration(mongo::idl::preparsedValue<decltype(_expiration)>()), _hasCode(false), _hasLastUpdated(false), _hasType(false), _hasAccessKeyId(false), _hasSecretAccessKey(false), _hasToken(false), _hasExpiration(false) {
    // Used for initialization only
}
Ec2SecurityCredentials::Ec2SecurityCredentials(std::string code, std::string lastUpdated, std::string type, std::string accessKeyId, std::string secretAccessKey, std::string token, std::string expiration) : _code(std::move(code)), _lastUpdated(std::move(lastUpdated)), _type(std::move(type)), _accessKeyId(std::move(accessKeyId)), _secretAccessKey(std::move(secretAccessKey)), _token(std::move(token)), _expiration(std::move(expiration)), _hasCode(true), _hasLastUpdated(true), _hasType(true), _hasAccessKeyId(true), _hasSecretAccessKey(true), _hasToken(true), _hasExpiration(true) {
    // Used for initialization only
}


Ec2SecurityCredentials Ec2SecurityCredentials::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<Ec2SecurityCredentials>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void Ec2SecurityCredentials::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<7> usedFields;
    const size_t kCodeBit = 0;
    const size_t kLastUpdatedBit = 1;
    const size_t kTypeBit = 2;
    const size_t kAccessKeyIdBit = 3;
    const size_t kSecretAccessKeyBit = 4;
    const size_t kTokenBit = 5;
    const size_t kExpirationBit = 6;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kCodeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kCodeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCodeBit);

                _hasCode = true;
                _code = element.str();
            }
        }
        else if (fieldName == kLastUpdatedFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kLastUpdatedBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLastUpdatedBit);

                _hasLastUpdated = true;
                _lastUpdated = element.str();
            }
        }
        else if (fieldName == kTypeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kTypeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTypeBit);

                _hasType = true;
                _type = element.str();
            }
        }
        else if (fieldName == kAccessKeyIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kAccessKeyIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAccessKeyIdBit);

                _hasAccessKeyId = true;
                _accessKeyId = element.str();
            }
        }
        else if (fieldName == kSecretAccessKeyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kSecretAccessKeyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSecretAccessKeyBit);

                _hasSecretAccessKey = true;
                _secretAccessKey = element.str();
            }
        }
        else if (fieldName == kTokenFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kTokenBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTokenBit);

                _hasToken = true;
                _token = element.str();
            }
        }
        else if (fieldName == kExpirationFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kExpirationBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kExpirationBit);

                _hasExpiration = true;
                _expiration = element.str();
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
        if (!usedFields[kCodeBit]) {
            ctxt.throwMissingField(kCodeFieldName);
        }
        if (!usedFields[kLastUpdatedBit]) {
            ctxt.throwMissingField(kLastUpdatedFieldName);
        }
        if (!usedFields[kTypeBit]) {
            ctxt.throwMissingField(kTypeFieldName);
        }
        if (!usedFields[kAccessKeyIdBit]) {
            ctxt.throwMissingField(kAccessKeyIdFieldName);
        }
        if (!usedFields[kSecretAccessKeyBit]) {
            ctxt.throwMissingField(kSecretAccessKeyFieldName);
        }
        if (!usedFields[kTokenBit]) {
            ctxt.throwMissingField(kTokenFieldName);
        }
        if (!usedFields[kExpirationBit]) {
            ctxt.throwMissingField(kExpirationFieldName);
        }
    }

}


void Ec2SecurityCredentials::serialize(BSONObjBuilder* builder) const {
    invariant(_hasCode && _hasLastUpdated && _hasType && _hasAccessKeyId && _hasSecretAccessKey && _hasToken && _hasExpiration);

    builder->append(kCodeFieldName, _code);

    builder->append(kLastUpdatedFieldName, _lastUpdated);

    builder->append(kTypeFieldName, _type);

    builder->append(kAccessKeyIdFieldName, _accessKeyId);

    builder->append(kSecretAccessKeyFieldName, _secretAccessKey);

    builder->append(kTokenFieldName, _token);

    builder->append(kExpirationFieldName, _expiration);

}


BSONObj Ec2SecurityCredentials::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData EcsTaskSecurityCredentials::kAccessKeyIdFieldName;
constexpr StringData EcsTaskSecurityCredentials::kExpirationFieldName;
constexpr StringData EcsTaskSecurityCredentials::kRoleArnFieldName;
constexpr StringData EcsTaskSecurityCredentials::kSecretAccessKeyFieldName;
constexpr StringData EcsTaskSecurityCredentials::kTokenFieldName;


EcsTaskSecurityCredentials::EcsTaskSecurityCredentials() : _accessKeyId(mongo::idl::preparsedValue<decltype(_accessKeyId)>()), _expiration(mongo::idl::preparsedValue<decltype(_expiration)>()), _roleArn(mongo::idl::preparsedValue<decltype(_roleArn)>()), _secretAccessKey(mongo::idl::preparsedValue<decltype(_secretAccessKey)>()), _token(mongo::idl::preparsedValue<decltype(_token)>()), _hasAccessKeyId(false), _hasExpiration(false), _hasRoleArn(false), _hasSecretAccessKey(false), _hasToken(false) {
    // Used for initialization only
}
EcsTaskSecurityCredentials::EcsTaskSecurityCredentials(std::string accessKeyId, std::string expiration, std::string roleArn, std::string secretAccessKey, std::string token) : _accessKeyId(std::move(accessKeyId)), _expiration(std::move(expiration)), _roleArn(std::move(roleArn)), _secretAccessKey(std::move(secretAccessKey)), _token(std::move(token)), _hasAccessKeyId(true), _hasExpiration(true), _hasRoleArn(true), _hasSecretAccessKey(true), _hasToken(true) {
    // Used for initialization only
}


EcsTaskSecurityCredentials EcsTaskSecurityCredentials::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<EcsTaskSecurityCredentials>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void EcsTaskSecurityCredentials::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<5> usedFields;
    const size_t kAccessKeyIdBit = 0;
    const size_t kExpirationBit = 1;
    const size_t kRoleArnBit = 2;
    const size_t kSecretAccessKeyBit = 3;
    const size_t kTokenBit = 4;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kAccessKeyIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kAccessKeyIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAccessKeyIdBit);

                _hasAccessKeyId = true;
                _accessKeyId = element.str();
            }
        }
        else if (fieldName == kExpirationFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kExpirationBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kExpirationBit);

                _hasExpiration = true;
                _expiration = element.str();
            }
        }
        else if (fieldName == kRoleArnFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kRoleArnBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRoleArnBit);

                _hasRoleArn = true;
                _roleArn = element.str();
            }
        }
        else if (fieldName == kSecretAccessKeyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kSecretAccessKeyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSecretAccessKeyBit);

                _hasSecretAccessKey = true;
                _secretAccessKey = element.str();
            }
        }
        else if (fieldName == kTokenFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kTokenBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTokenBit);

                _hasToken = true;
                _token = element.str();
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
        if (!usedFields[kAccessKeyIdBit]) {
            ctxt.throwMissingField(kAccessKeyIdFieldName);
        }
        if (!usedFields[kExpirationBit]) {
            ctxt.throwMissingField(kExpirationFieldName);
        }
        if (!usedFields[kRoleArnBit]) {
            ctxt.throwMissingField(kRoleArnFieldName);
        }
        if (!usedFields[kSecretAccessKeyBit]) {
            ctxt.throwMissingField(kSecretAccessKeyFieldName);
        }
        if (!usedFields[kTokenBit]) {
            ctxt.throwMissingField(kTokenFieldName);
        }
    }

}


void EcsTaskSecurityCredentials::serialize(BSONObjBuilder* builder) const {
    invariant(_hasAccessKeyId && _hasExpiration && _hasRoleArn && _hasSecretAccessKey && _hasToken);

    builder->append(kAccessKeyIdFieldName, _accessKeyId);

    builder->append(kExpirationFieldName, _expiration);

    builder->append(kRoleArnFieldName, _roleArn);

    builder->append(kSecretAccessKeyFieldName, _secretAccessKey);

    builder->append(kTokenFieldName, _token);

}


BSONObj EcsTaskSecurityCredentials::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
