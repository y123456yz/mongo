/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/auth/auth_types_gen.h --output build/opt/mongo/db/auth/auth_types_gen.cpp src/mongo/db/auth/auth_types.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/auth/auth_types_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData AuthLocalGetUserFailPoint::kResolveRolesDelayMSFieldName;


AuthLocalGetUserFailPoint::AuthLocalGetUserFailPoint() : _resolveRolesDelayMS(mongo::idl::preparsedValue<decltype(_resolveRolesDelayMS)>()), _hasResolveRolesDelayMS(false) {
    // Used for initialization only
}
AuthLocalGetUserFailPoint::AuthLocalGetUserFailPoint(std::int32_t resolveRolesDelayMS) : _resolveRolesDelayMS(std::move(resolveRolesDelayMS)), _hasResolveRolesDelayMS(true) {
    // Used for initialization only
}

void AuthLocalGetUserFailPoint::validateResolveRolesDelayMS(IDLParserErrorContext& ctxt, const std::int32_t value)
{
    if (!(value >= 0)) {
        throwComparisonError<std::int32_t>(ctxt, "resolveRolesDelayMS", ">="_sd, value, 0);
    }
}

void AuthLocalGetUserFailPoint::validateResolveRolesDelayMS(const std::int32_t value)
{
    if (!(value >= 0)) {
        throwComparisonError<std::int32_t>("resolveRolesDelayMS", ">="_sd, value, 0);
    }
}


AuthLocalGetUserFailPoint AuthLocalGetUserFailPoint::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<AuthLocalGetUserFailPoint>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void AuthLocalGetUserFailPoint::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kResolveRolesDelayMSBit = 0;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kResolveRolesDelayMSFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberInt))) {
                if (MONGO_unlikely(usedFields[kResolveRolesDelayMSBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kResolveRolesDelayMSBit);

                _hasResolveRolesDelayMS = true;
                {
                    auto value = element._numberInt();
                    validateResolveRolesDelayMS(value);
                    _resolveRolesDelayMS = std::move(value);
                }
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kResolveRolesDelayMSBit]) {
            ctxt.throwMissingField(kResolveRolesDelayMSFieldName);
        }
    }

}


void AuthLocalGetUserFailPoint::serialize(BSONObjBuilder* builder) const {
    invariant(_hasResolveRolesDelayMS);

    builder->append(kResolveRolesDelayMSFieldName, _resolveRolesDelayMS);

}


BSONObj AuthLocalGetUserFailPoint::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData WaitForUserCacheInvalidationFailPoint::kUserNameFieldName;


WaitForUserCacheInvalidationFailPoint::WaitForUserCacheInvalidationFailPoint() : _userName(mongo::idl::preparsedValue<decltype(_userName)>()), _hasUserName(false) {
    // Used for initialization only
}
WaitForUserCacheInvalidationFailPoint::WaitForUserCacheInvalidationFailPoint(mongo::UserName userName) : _userName(std::move(userName)), _hasUserName(true) {
    // Used for initialization only
}


WaitForUserCacheInvalidationFailPoint WaitForUserCacheInvalidationFailPoint::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<WaitForUserCacheInvalidationFailPoint>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void WaitForUserCacheInvalidationFailPoint::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kUserNameBit = 0;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kUserNameFieldName) {
            if (MONGO_unlikely(usedFields[kUserNameBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kUserNameBit);

            _hasUserName = true;
            _userName = UserName::parseFromBSON(element);
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kUserNameBit]) {
            ctxt.throwMissingField(kUserNameFieldName);
        }
    }

}


void WaitForUserCacheInvalidationFailPoint::serialize(BSONObjBuilder* builder) const {
    invariant(_hasUserName);

    {
        _userName.serializeToBSON(kUserNameFieldName, builder);
    }

}


BSONObj WaitForUserCacheInvalidationFailPoint::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
