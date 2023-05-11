/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/s/forwardable_operation_metadata_gen.h --output build/opt/mongo/db/s/forwardable_operation_metadata_gen.cpp src/mongo/db/s/forwardable_operation_metadata.idl
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
#include "mongo/rpc/metadata/impersonated_user_metadata_gen.h"
#include "mongo/rpc/op_msg.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/util/uuid.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {

/**
 * A struct representing the impersonated users associated with a specific operation.
 */
class AuthenticationMetadata {
public:
    static constexpr auto kRolesFieldName = "roles"_sd;
    static constexpr auto kUsersFieldName = "users"_sd;

    AuthenticationMetadata();
    AuthenticationMetadata(std::vector<mongo::UserName> users, std::vector<mongo::RoleName> roles);

    static AuthenticationMetadata parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    const std::vector<mongo::UserName>& getUsers() const& { return _users; }
    void getUsers() && = delete;
    void setUsers(std::vector<mongo::UserName> value) & {  _users = std::move(value); _hasUsers = true; }

    const std::vector<mongo::RoleName>& getRoles() const& { return _roles; }
    void getRoles() && = delete;
    void setRoles(std::vector<mongo::RoleName> value) & {  _roles = std::move(value); _hasRoles = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    std::vector<mongo::UserName> _users;
    std::vector<mongo::RoleName> _roles;
    bool _hasUsers : 1;
    bool _hasRoles : 1;
};

/**
 * Used to store metadata of an operation context that can be safely passed among different threads.
 */
class ForwardableOperationMetadataBase {
public:
    static constexpr auto kCommentFieldName = "comment"_sd;
    static constexpr auto kImpersonatedUserMetadataFieldName = "impersonatedUserMetadata"_sd;

    ForwardableOperationMetadataBase();

    static ForwardableOperationMetadataBase parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * The comment assiociated with the operation.
     */
    const boost::optional<mongo::BSONObj>& getComment() const& { return _comment; }
    void getComment() && = delete;
    void setComment(boost::optional<mongo::BSONObj> value) & {  _comment = std::move(value);  }

    /**
     * The impersonated users associated with the operation.
     */
    const boost::optional<mongo::AuthenticationMetadata>& getImpersonatedUserMetadata() const& { return _impersonatedUserMetadata; }
    void getImpersonatedUserMetadata() && = delete;
    void setImpersonatedUserMetadata(boost::optional<mongo::AuthenticationMetadata> value) & {  _impersonatedUserMetadata = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    boost::optional<mongo::BSONObj> _comment;
    boost::optional<mongo::AuthenticationMetadata> _impersonatedUserMetadata;
};

}  // namespace mongo
