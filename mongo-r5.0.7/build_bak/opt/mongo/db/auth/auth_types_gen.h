/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/auth/auth_types_gen.h --output build/opt/mongo/db/auth/auth_types_gen.cpp src/mongo/db/auth/auth_types.idl
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
#include "mongo/db/auth/privilege.h"
#include "mongo/db/auth/role_name.h"
#include "mongo/db/auth/role_name_or_string.h"
#include "mongo/db/auth/user_name.h"
#include "mongo/db/namespace_string.h"
#include "mongo/idl/basic_types.h"
#include "mongo/idl/basic_types_gen.h"
#include "mongo/idl/idl_parser.h"
#include "mongo/rpc/op_msg.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/util/uuid.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {

/**
 * Data for authLocalGetUser failpoint
 */
class AuthLocalGetUserFailPoint {
public:
    static constexpr auto kResolveRolesDelayMSFieldName = "resolveRolesDelayMS"_sd;

    AuthLocalGetUserFailPoint();
    AuthLocalGetUserFailPoint(std::int32_t resolveRolesDelayMS);

    static AuthLocalGetUserFailPoint parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    std::int32_t getResolveRolesDelayMS() const { return _resolveRolesDelayMS; }
    void setResolveRolesDelayMS(std::int32_t value) & { validateResolveRolesDelayMS(value); _resolveRolesDelayMS = std::move(value); _hasResolveRolesDelayMS = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    void validateResolveRolesDelayMS(const std::int32_t value);
    void validateResolveRolesDelayMS(IDLParserErrorContext& ctxt, const std::int32_t value);

private:
    std::int32_t _resolveRolesDelayMS;
    bool _hasResolveRolesDelayMS : 1;
};

/**
 * Data for waitForUserCacheInvalidation fail point
 */
class WaitForUserCacheInvalidationFailPoint {
public:
    static constexpr auto kUserNameFieldName = "userName"_sd;

    WaitForUserCacheInvalidationFailPoint();
    WaitForUserCacheInvalidationFailPoint(mongo::UserName userName);

    static WaitForUserCacheInvalidationFailPoint parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    const mongo::UserName& getUserName() const { return _userName; }
    void setUserName(mongo::UserName value) & {  _userName = std::move(value); _hasUserName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::UserName _userName;
    bool _hasUserName : 1;
};

}  // namespace mongo
