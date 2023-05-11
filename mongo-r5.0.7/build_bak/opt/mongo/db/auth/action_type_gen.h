/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/auth/action_type_gen.h --output build/opt/mongo/db/auth/action_type_gen.cpp src/mongo/db/auth/action_type.idl
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
 * test
 */
enum class ActionTypeEnum : std::int32_t {
    addShard ,
    advanceClusterTime ,
    anyAction ,
    appendOplogNote ,
    applicationMessage ,
    auditConfigure ,
    auditLogRotate ,
    authCheck ,
    authenticate ,
    authSchemaUpgrade ,
    bypassDocumentValidation ,
    changeCustomData ,
    changePassword ,
    changeOwnPassword ,
    changeOwnCustomData ,
    changeStream ,
    checkFreeMonitoringStatus ,
    cleanupOrphaned ,
    clearJumboFlag ,
    closeAllDatabases ,
    collMod ,
    collStats ,
    compact ,
    connPoolStats ,
    connPoolSync ,
    convertToCapped ,
    cpuProfiler ,
    createCollection ,
    createDatabase ,
    createIndex ,
    createRole ,
    createUser ,
    dbCheck ,
    dbHash ,
    dbStats ,
    dropAllRolesFromDatabase ,
    dropAllUsersFromDatabase ,
    dropCollection ,
    dropConnections ,
    dropDatabase ,
    dropIndex ,
    dropRole ,
    dropUser ,
    emptycapped ,
    enableProfiler ,
    enableSharding ,
    exportCollection ,
    find ,
    flushRouterConfig ,
    forceUUID ,
    fsync ,
    getDatabaseVersion ,
    getDefaultRWConcern ,
    getCmdLineOpts ,
    getLog ,
    getParameter ,
    getShardMap ,
    getShardVersion ,
    grantRole ,
    grantPrivilegesToRole ,
    grantRolesToRole ,
    grantRolesToUser ,
    hostInfo ,
    impersonate ,
    importCollection ,
    indexStats ,
    inprog ,
    insert ,
    internal ,
    invalidateUserCache ,
    killAnyCursor ,
    killAnySession ,
    killCursors ,
    killop ,
    listCachedAndActiveUsers ,
    listCollections ,
    listCursors ,
    listDatabases ,
    listIndexes ,
    listSessions ,
    listShards ,
    logRotate ,
    moveChunk ,
    netstat ,
    oidReset ,
    operationMetrics ,
    planCacheIndexFilter ,
    planCacheRead ,
    planCacheWrite ,
    refineCollectionShardKey ,
    reIndex ,
    remove ,
    removeShard ,
    renameCollection ,
    renameCollectionSameDB ,
    repairDatabase ,
    replSetConfigure ,
    replSetGetConfig ,
    replSetGetStatus ,
    replSetHeartbeat ,
    replSetReconfig ,
    replSetResizeOplog ,
    replSetStateChange ,
    reshardCollection ,
    resync ,
    revokeRole ,
    revokePrivilegesFromRole ,
    revokeRolesFromRole ,
    revokeRolesFromUser ,
    rotateCertificates ,
    runAsLessPrivilegedUser ,
    runTenantMigration ,
    serverStatus ,
    setAuthenticationRestriction ,
    setDefaultRWConcern ,
    setFeatureCompatibilityVersion ,
    setFreeMonitoring ,
    setParameter ,
    shardCollection ,
    shardingState ,
    shutdown ,
    splitChunk ,
    splitVector ,
    storageDetails ,
    top ,
    touch ,
    trafficRecord ,
    unlock ,
    useUUID ,
    update ,
    updateRole ,
    updateUser ,
    validate ,
    viewRole ,
    viewUser ,
    applyOps ,
};
static constexpr uint32_t kNumActionTypeEnum = 136;

ActionTypeEnum ActionType_parse(const IDLParserErrorContext& ctxt, StringData value);
StringData ActionType_serializer(ActionTypeEnum value);

/**
 * test
 */
enum class MatchTypeEnum : std::int32_t {
    kMatchNever ,
    kMatchClusterResource ,
    kMatchDatabaseName ,
    kMatchCollectionName ,
    kMatchExactNamespace ,
    kMatchAnyNormalResource ,
    kMatchAnyResource ,
    kMatchExactSystemBucketResource ,
    kMatchSystemBucketInAnyDBResource ,
    kMatchAnySystemBucketInDBResource ,
    kMatchAnySystemBucketResource ,
};
static constexpr uint32_t kNumMatchTypeEnum = 11;

MatchTypeEnum MatchType_parse(const IDLParserErrorContext& ctxt, StringData value);
StringData MatchType_serializer(MatchTypeEnum value);

}  // namespace mongo
