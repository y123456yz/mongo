/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/idl/generic_argument_gen.h --output build/opt/mongo/idl/generic_argument_gen.cpp src/mongo/idl/generic_argument.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/idl/generic_argument_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

// Map: fieldName -> shouldForwardToShards
const stdx::unordered_map<std::string, bool> Generic_args_api_v1::_genericFields {
    {"$clusterTime", false},
    {"$db", false},
    {"$readPreference", false},
    {"apiDeprecationErrors", false},
    {"apiStrict", false},
    {"apiVersion", false},
    {"autocommit", true},
    {"clientOperationKey", true},
    {"comment", true},
    {"lsid", true},
    {"maxTimeMS", true},
    {"readConcern", true},
    {"startTransaction", true},
    {"stmtId", true},
    {"txnNumber", true},
    {"writeConcern", true},
};

bool Generic_args_api_v1::hasField(StringData fieldName) {
    return _genericFields.find(fieldName.toString()) != _genericFields.end();
}

bool Generic_args_api_v1::shouldForwardToShards(StringData fieldName) {
    auto it = _genericFields.find(fieldName.toString());
    return (it == _genericFields.end() || it->second);
}


// Map: fieldName -> shouldForwardToShards
const stdx::unordered_map<std::string, bool> Generic_args_unstable_v1::_genericFields {
    {"$audit", false},
    {"$client", false},
    {"$configServerState", false},
    {"$configTime", false},
    {"$oplogQueryData", false},
    {"$queryOptions", true},
    {"$replData", false},
    {"$topologyTime", false},
    {"allowImplicitCollectionCreation", false},
    {"coordinator", true},
    {"databaseVersion", false},
    {"maxTimeMSOpOnly", false},
    {"shardVersion", false},
    {"tracking_info", false},
};

bool Generic_args_unstable_v1::hasField(StringData fieldName) {
    return _genericFields.find(fieldName.toString()) != _genericFields.end();
}

bool Generic_args_unstable_v1::shouldForwardToShards(StringData fieldName) {
    auto it = _genericFields.find(fieldName.toString());
    return (it == _genericFields.end() || it->second);
}


// Map: fieldName -> shouldForwardFromShards
const stdx::unordered_map<std::string, bool> Generic_reply_fields_api_v1::_genericFields {
    {"$clusterTime", false},
    {"operationTime", false},
};

bool Generic_reply_fields_api_v1::hasField(StringData fieldName) {
    return _genericFields.find(fieldName.toString()) != _genericFields.end();
}

bool Generic_reply_fields_api_v1::shouldForwardFromShards(StringData fieldName) {
    auto it = _genericFields.find(fieldName.toString());
    return (it == _genericFields.end() || it->second);
}


// Map: fieldName -> shouldForwardFromShards
const stdx::unordered_map<std::string, bool> Generic_reply_fields_unstable_v1::_genericFields {
    {"$configServerState", false},
    {"$configTime", false},
    {"$gleStats", false},
    {"$oplogQueryData", false},
    {"$replData", false},
    {"$topologyTime", false},
    {"lastCommittedOpTime", false},
    {"readOnly", false},
};

bool Generic_reply_fields_unstable_v1::hasField(StringData fieldName) {
    return _genericFields.find(fieldName.toString()) != _genericFields.end();
}

bool Generic_reply_fields_unstable_v1::shouldForwardFromShards(StringData fieldName) {
    auto it = _genericFields.find(fieldName.toString());
    return (it == _genericFields.end() || it->second);
}


}  // namespace mongo
