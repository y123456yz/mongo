/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/idl/generic_argument_gen.h --output build/opt/mongo/idl/generic_argument_gen.cpp src/mongo/idl/generic_argument.idl
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
#include "mongo/idl/idl_parser.h"
#include "mongo/rpc/op_msg.h"
#include "mongo/stdx/unordered_map.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {

/**
 * Arguments accepted by all commands. These are guaranteed backwards-compatible for as long as the server supports API Version 1.
 */
class Generic_args_api_v1 {
public:
    static bool hasField(StringData fieldName);
    static bool shouldForwardToShards(StringData fieldName);

private:
    // Map: fieldName -> shouldForwardToShards
    static const stdx::unordered_map<std::string, bool> _genericFields;

};

/**
 * Arguments accepted by all commands. These are not guaranteed backwards-compatible.
 */
class Generic_args_unstable_v1 {
public:
    static bool hasField(StringData fieldName);
    static bool shouldForwardToShards(StringData fieldName);

private:
    // Map: fieldName -> shouldForwardToShards
    static const stdx::unordered_map<std::string, bool> _genericFields;

};

/**
 * Fields that may appear in any command reply. These are guaranteed backwards-compatible for as long as the server supports API Version 1.
 */
class Generic_reply_fields_api_v1 {
public:
    static bool hasField(StringData fieldName);
    static bool shouldForwardFromShards(StringData fieldName);

private:
    // Map: fieldName -> shouldForwardFromShards
    static const stdx::unordered_map<std::string, bool> _genericFields;

};

/**
 * Fields that may appear in any command reply. These are not guaranteed backwards-compatible.
 */
class Generic_reply_fields_unstable_v1 {
public:
    static bool hasField(StringData fieldName);
    static bool shouldForwardFromShards(StringData fieldName);

private:
    // Map: fieldName -> shouldForwardFromShards
    static const stdx::unordered_map<std::string, bool> _genericFields;

};

}  // namespace mongo
