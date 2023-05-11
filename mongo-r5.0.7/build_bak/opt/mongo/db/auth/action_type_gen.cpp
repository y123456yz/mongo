/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/auth/action_type_gen.h --output build/opt/mongo/db/auth/action_type_gen.cpp src/mongo/db/auth/action_type.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/auth/action_type_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

/**
 * test
 */
namespace  {
constexpr StringData kActionType_addShard = "addShard"_sd;
constexpr StringData kActionType_advanceClusterTime = "advanceClusterTime"_sd;
constexpr StringData kActionType_anyAction = "anyAction"_sd;
constexpr StringData kActionType_appendOplogNote = "appendOplogNote"_sd;
constexpr StringData kActionType_applicationMessage = "applicationMessage"_sd;
constexpr StringData kActionType_auditConfigure = "auditConfigure"_sd;
constexpr StringData kActionType_auditLogRotate = "auditLogRotate"_sd;
constexpr StringData kActionType_authCheck = "authCheck"_sd;
constexpr StringData kActionType_authenticate = "authenticate"_sd;
constexpr StringData kActionType_authSchemaUpgrade = "authSchemaUpgrade"_sd;
constexpr StringData kActionType_bypassDocumentValidation = "bypassDocumentValidation"_sd;
constexpr StringData kActionType_changeCustomData = "changeCustomData"_sd;
constexpr StringData kActionType_changePassword = "changePassword"_sd;
constexpr StringData kActionType_changeOwnPassword = "changeOwnPassword"_sd;
constexpr StringData kActionType_changeOwnCustomData = "changeOwnCustomData"_sd;
constexpr StringData kActionType_changeStream = "changeStream"_sd;
constexpr StringData kActionType_checkFreeMonitoringStatus = "checkFreeMonitoringStatus"_sd;
constexpr StringData kActionType_cleanupOrphaned = "cleanupOrphaned"_sd;
constexpr StringData kActionType_clearJumboFlag = "clearJumboFlag"_sd;
constexpr StringData kActionType_closeAllDatabases = "closeAllDatabases"_sd;
constexpr StringData kActionType_collMod = "collMod"_sd;
constexpr StringData kActionType_collStats = "collStats"_sd;
constexpr StringData kActionType_compact = "compact"_sd;
constexpr StringData kActionType_connPoolStats = "connPoolStats"_sd;
constexpr StringData kActionType_connPoolSync = "connPoolSync"_sd;
constexpr StringData kActionType_convertToCapped = "convertToCapped"_sd;
constexpr StringData kActionType_cpuProfiler = "cpuProfiler"_sd;
constexpr StringData kActionType_createCollection = "createCollection"_sd;
constexpr StringData kActionType_createDatabase = "createDatabase"_sd;
constexpr StringData kActionType_createIndex = "createIndex"_sd;
constexpr StringData kActionType_createRole = "createRole"_sd;
constexpr StringData kActionType_createUser = "createUser"_sd;
constexpr StringData kActionType_dbCheck = "dbCheck"_sd;
constexpr StringData kActionType_dbHash = "dbHash"_sd;
constexpr StringData kActionType_dbStats = "dbStats"_sd;
constexpr StringData kActionType_dropAllRolesFromDatabase = "dropAllRolesFromDatabase"_sd;
constexpr StringData kActionType_dropAllUsersFromDatabase = "dropAllUsersFromDatabase"_sd;
constexpr StringData kActionType_dropCollection = "dropCollection"_sd;
constexpr StringData kActionType_dropConnections = "dropConnections"_sd;
constexpr StringData kActionType_dropDatabase = "dropDatabase"_sd;
constexpr StringData kActionType_dropIndex = "dropIndex"_sd;
constexpr StringData kActionType_dropRole = "dropRole"_sd;
constexpr StringData kActionType_dropUser = "dropUser"_sd;
constexpr StringData kActionType_emptycapped = "emptycapped"_sd;
constexpr StringData kActionType_enableProfiler = "enableProfiler"_sd;
constexpr StringData kActionType_enableSharding = "enableSharding"_sd;
constexpr StringData kActionType_exportCollection = "exportCollection"_sd;
constexpr StringData kActionType_find = "find"_sd;
constexpr StringData kActionType_flushRouterConfig = "flushRouterConfig"_sd;
constexpr StringData kActionType_forceUUID = "forceUUID"_sd;
constexpr StringData kActionType_fsync = "fsync"_sd;
constexpr StringData kActionType_getDatabaseVersion = "getDatabaseVersion"_sd;
constexpr StringData kActionType_getDefaultRWConcern = "getDefaultRWConcern"_sd;
constexpr StringData kActionType_getCmdLineOpts = "getCmdLineOpts"_sd;
constexpr StringData kActionType_getLog = "getLog"_sd;
constexpr StringData kActionType_getParameter = "getParameter"_sd;
constexpr StringData kActionType_getShardMap = "getShardMap"_sd;
constexpr StringData kActionType_getShardVersion = "getShardVersion"_sd;
constexpr StringData kActionType_grantRole = "grantRole"_sd;
constexpr StringData kActionType_grantPrivilegesToRole = "grantPrivilegesToRole"_sd;
constexpr StringData kActionType_grantRolesToRole = "grantRolesToRole"_sd;
constexpr StringData kActionType_grantRolesToUser = "grantRolesToUser"_sd;
constexpr StringData kActionType_hostInfo = "hostInfo"_sd;
constexpr StringData kActionType_impersonate = "impersonate"_sd;
constexpr StringData kActionType_importCollection = "importCollection"_sd;
constexpr StringData kActionType_indexStats = "indexStats"_sd;
constexpr StringData kActionType_inprog = "inprog"_sd;
constexpr StringData kActionType_insert = "insert"_sd;
constexpr StringData kActionType_internal = "internal"_sd;
constexpr StringData kActionType_invalidateUserCache = "invalidateUserCache"_sd;
constexpr StringData kActionType_killAnyCursor = "killAnyCursor"_sd;
constexpr StringData kActionType_killAnySession = "killAnySession"_sd;
constexpr StringData kActionType_killCursors = "killCursors"_sd;
constexpr StringData kActionType_killop = "killop"_sd;
constexpr StringData kActionType_listCachedAndActiveUsers = "listCachedAndActiveUsers"_sd;
constexpr StringData kActionType_listCollections = "listCollections"_sd;
constexpr StringData kActionType_listCursors = "listCursors"_sd;
constexpr StringData kActionType_listDatabases = "listDatabases"_sd;
constexpr StringData kActionType_listIndexes = "listIndexes"_sd;
constexpr StringData kActionType_listSessions = "listSessions"_sd;
constexpr StringData kActionType_listShards = "listShards"_sd;
constexpr StringData kActionType_logRotate = "logRotate"_sd;
constexpr StringData kActionType_moveChunk = "moveChunk"_sd;
constexpr StringData kActionType_netstat = "netstat"_sd;
constexpr StringData kActionType_oidReset = "oidReset"_sd;
constexpr StringData kActionType_operationMetrics = "operationMetrics"_sd;
constexpr StringData kActionType_planCacheIndexFilter = "planCacheIndexFilter"_sd;
constexpr StringData kActionType_planCacheRead = "planCacheRead"_sd;
constexpr StringData kActionType_planCacheWrite = "planCacheWrite"_sd;
constexpr StringData kActionType_refineCollectionShardKey = "refineCollectionShardKey"_sd;
constexpr StringData kActionType_reIndex = "reIndex"_sd;
constexpr StringData kActionType_remove = "remove"_sd;
constexpr StringData kActionType_removeShard = "removeShard"_sd;
constexpr StringData kActionType_renameCollection = "renameCollection"_sd;
constexpr StringData kActionType_renameCollectionSameDB = "renameCollectionSameDB"_sd;
constexpr StringData kActionType_repairDatabase = "repairDatabase"_sd;
constexpr StringData kActionType_replSetConfigure = "replSetConfigure"_sd;
constexpr StringData kActionType_replSetGetConfig = "replSetGetConfig"_sd;
constexpr StringData kActionType_replSetGetStatus = "replSetGetStatus"_sd;
constexpr StringData kActionType_replSetHeartbeat = "replSetHeartbeat"_sd;
constexpr StringData kActionType_replSetReconfig = "replSetReconfig"_sd;
constexpr StringData kActionType_replSetResizeOplog = "replSetResizeOplog"_sd;
constexpr StringData kActionType_replSetStateChange = "replSetStateChange"_sd;
constexpr StringData kActionType_reshardCollection = "reshardCollection"_sd;
constexpr StringData kActionType_resync = "resync"_sd;
constexpr StringData kActionType_revokeRole = "revokeRole"_sd;
constexpr StringData kActionType_revokePrivilegesFromRole = "revokePrivilegesFromRole"_sd;
constexpr StringData kActionType_revokeRolesFromRole = "revokeRolesFromRole"_sd;
constexpr StringData kActionType_revokeRolesFromUser = "revokeRolesFromUser"_sd;
constexpr StringData kActionType_rotateCertificates = "rotateCertificates"_sd;
constexpr StringData kActionType_runAsLessPrivilegedUser = "runAsLessPrivilegedUser"_sd;
constexpr StringData kActionType_runTenantMigration = "runTenantMigration"_sd;
constexpr StringData kActionType_serverStatus = "serverStatus"_sd;
constexpr StringData kActionType_setAuthenticationRestriction = "setAuthenticationRestriction"_sd;
constexpr StringData kActionType_setDefaultRWConcern = "setDefaultRWConcern"_sd;
constexpr StringData kActionType_setFeatureCompatibilityVersion = "setFeatureCompatibilityVersion"_sd;
constexpr StringData kActionType_setFreeMonitoring = "setFreeMonitoring"_sd;
constexpr StringData kActionType_setParameter = "setParameter"_sd;
constexpr StringData kActionType_shardCollection = "shardCollection"_sd;
constexpr StringData kActionType_shardingState = "shardingState"_sd;
constexpr StringData kActionType_shutdown = "shutdown"_sd;
constexpr StringData kActionType_splitChunk = "splitChunk"_sd;
constexpr StringData kActionType_splitVector = "splitVector"_sd;
constexpr StringData kActionType_storageDetails = "storageDetails"_sd;
constexpr StringData kActionType_top = "top"_sd;
constexpr StringData kActionType_touch = "touch"_sd;
constexpr StringData kActionType_trafficRecord = "trafficRecord"_sd;
constexpr StringData kActionType_unlock = "unlock"_sd;
constexpr StringData kActionType_useUUID = "useUUID"_sd;
constexpr StringData kActionType_update = "update"_sd;
constexpr StringData kActionType_updateRole = "updateRole"_sd;
constexpr StringData kActionType_updateUser = "updateUser"_sd;
constexpr StringData kActionType_validate = "validate"_sd;
constexpr StringData kActionType_viewRole = "viewRole"_sd;
constexpr StringData kActionType_viewUser = "viewUser"_sd;
constexpr StringData kActionType_applyOps = "applyOps"_sd;
}  // namespace 

ActionTypeEnum ActionType_parse(const IDLParserErrorContext& ctxt, StringData value) {
    if (value == kActionType_addShard) {
        return ActionTypeEnum::addShard;
    }
    if (value == kActionType_advanceClusterTime) {
        return ActionTypeEnum::advanceClusterTime;
    }
    if (value == kActionType_anyAction) {
        return ActionTypeEnum::anyAction;
    }
    if (value == kActionType_appendOplogNote) {
        return ActionTypeEnum::appendOplogNote;
    }
    if (value == kActionType_applicationMessage) {
        return ActionTypeEnum::applicationMessage;
    }
    if (value == kActionType_auditConfigure) {
        return ActionTypeEnum::auditConfigure;
    }
    if (value == kActionType_auditLogRotate) {
        return ActionTypeEnum::auditLogRotate;
    }
    if (value == kActionType_authCheck) {
        return ActionTypeEnum::authCheck;
    }
    if (value == kActionType_authenticate) {
        return ActionTypeEnum::authenticate;
    }
    if (value == kActionType_authSchemaUpgrade) {
        return ActionTypeEnum::authSchemaUpgrade;
    }
    if (value == kActionType_bypassDocumentValidation) {
        return ActionTypeEnum::bypassDocumentValidation;
    }
    if (value == kActionType_changeCustomData) {
        return ActionTypeEnum::changeCustomData;
    }
    if (value == kActionType_changePassword) {
        return ActionTypeEnum::changePassword;
    }
    if (value == kActionType_changeOwnPassword) {
        return ActionTypeEnum::changeOwnPassword;
    }
    if (value == kActionType_changeOwnCustomData) {
        return ActionTypeEnum::changeOwnCustomData;
    }
    if (value == kActionType_changeStream) {
        return ActionTypeEnum::changeStream;
    }
    if (value == kActionType_checkFreeMonitoringStatus) {
        return ActionTypeEnum::checkFreeMonitoringStatus;
    }
    if (value == kActionType_cleanupOrphaned) {
        return ActionTypeEnum::cleanupOrphaned;
    }
    if (value == kActionType_clearJumboFlag) {
        return ActionTypeEnum::clearJumboFlag;
    }
    if (value == kActionType_closeAllDatabases) {
        return ActionTypeEnum::closeAllDatabases;
    }
    if (value == kActionType_collMod) {
        return ActionTypeEnum::collMod;
    }
    if (value == kActionType_collStats) {
        return ActionTypeEnum::collStats;
    }
    if (value == kActionType_compact) {
        return ActionTypeEnum::compact;
    }
    if (value == kActionType_connPoolStats) {
        return ActionTypeEnum::connPoolStats;
    }
    if (value == kActionType_connPoolSync) {
        return ActionTypeEnum::connPoolSync;
    }
    if (value == kActionType_convertToCapped) {
        return ActionTypeEnum::convertToCapped;
    }
    if (value == kActionType_cpuProfiler) {
        return ActionTypeEnum::cpuProfiler;
    }
    if (value == kActionType_createCollection) {
        return ActionTypeEnum::createCollection;
    }
    if (value == kActionType_createDatabase) {
        return ActionTypeEnum::createDatabase;
    }
    if (value == kActionType_createIndex) {
        return ActionTypeEnum::createIndex;
    }
    if (value == kActionType_createRole) {
        return ActionTypeEnum::createRole;
    }
    if (value == kActionType_createUser) {
        return ActionTypeEnum::createUser;
    }
    if (value == kActionType_dbCheck) {
        return ActionTypeEnum::dbCheck;
    }
    if (value == kActionType_dbHash) {
        return ActionTypeEnum::dbHash;
    }
    if (value == kActionType_dbStats) {
        return ActionTypeEnum::dbStats;
    }
    if (value == kActionType_dropAllRolesFromDatabase) {
        return ActionTypeEnum::dropAllRolesFromDatabase;
    }
    if (value == kActionType_dropAllUsersFromDatabase) {
        return ActionTypeEnum::dropAllUsersFromDatabase;
    }
    if (value == kActionType_dropCollection) {
        return ActionTypeEnum::dropCollection;
    }
    if (value == kActionType_dropConnections) {
        return ActionTypeEnum::dropConnections;
    }
    if (value == kActionType_dropDatabase) {
        return ActionTypeEnum::dropDatabase;
    }
    if (value == kActionType_dropIndex) {
        return ActionTypeEnum::dropIndex;
    }
    if (value == kActionType_dropRole) {
        return ActionTypeEnum::dropRole;
    }
    if (value == kActionType_dropUser) {
        return ActionTypeEnum::dropUser;
    }
    if (value == kActionType_emptycapped) {
        return ActionTypeEnum::emptycapped;
    }
    if (value == kActionType_enableProfiler) {
        return ActionTypeEnum::enableProfiler;
    }
    if (value == kActionType_enableSharding) {
        return ActionTypeEnum::enableSharding;
    }
    if (value == kActionType_exportCollection) {
        return ActionTypeEnum::exportCollection;
    }
    if (value == kActionType_find) {
        return ActionTypeEnum::find;
    }
    if (value == kActionType_flushRouterConfig) {
        return ActionTypeEnum::flushRouterConfig;
    }
    if (value == kActionType_forceUUID) {
        return ActionTypeEnum::forceUUID;
    }
    if (value == kActionType_fsync) {
        return ActionTypeEnum::fsync;
    }
    if (value == kActionType_getDatabaseVersion) {
        return ActionTypeEnum::getDatabaseVersion;
    }
    if (value == kActionType_getDefaultRWConcern) {
        return ActionTypeEnum::getDefaultRWConcern;
    }
    if (value == kActionType_getCmdLineOpts) {
        return ActionTypeEnum::getCmdLineOpts;
    }
    if (value == kActionType_getLog) {
        return ActionTypeEnum::getLog;
    }
    if (value == kActionType_getParameter) {
        return ActionTypeEnum::getParameter;
    }
    if (value == kActionType_getShardMap) {
        return ActionTypeEnum::getShardMap;
    }
    if (value == kActionType_getShardVersion) {
        return ActionTypeEnum::getShardVersion;
    }
    if (value == kActionType_grantRole) {
        return ActionTypeEnum::grantRole;
    }
    if (value == kActionType_grantPrivilegesToRole) {
        return ActionTypeEnum::grantPrivilegesToRole;
    }
    if (value == kActionType_grantRolesToRole) {
        return ActionTypeEnum::grantRolesToRole;
    }
    if (value == kActionType_grantRolesToUser) {
        return ActionTypeEnum::grantRolesToUser;
    }
    if (value == kActionType_hostInfo) {
        return ActionTypeEnum::hostInfo;
    }
    if (value == kActionType_impersonate) {
        return ActionTypeEnum::impersonate;
    }
    if (value == kActionType_importCollection) {
        return ActionTypeEnum::importCollection;
    }
    if (value == kActionType_indexStats) {
        return ActionTypeEnum::indexStats;
    }
    if (value == kActionType_inprog) {
        return ActionTypeEnum::inprog;
    }
    if (value == kActionType_insert) {
        return ActionTypeEnum::insert;
    }
    if (value == kActionType_internal) {
        return ActionTypeEnum::internal;
    }
    if (value == kActionType_invalidateUserCache) {
        return ActionTypeEnum::invalidateUserCache;
    }
    if (value == kActionType_killAnyCursor) {
        return ActionTypeEnum::killAnyCursor;
    }
    if (value == kActionType_killAnySession) {
        return ActionTypeEnum::killAnySession;
    }
    if (value == kActionType_killCursors) {
        return ActionTypeEnum::killCursors;
    }
    if (value == kActionType_killop) {
        return ActionTypeEnum::killop;
    }
    if (value == kActionType_listCachedAndActiveUsers) {
        return ActionTypeEnum::listCachedAndActiveUsers;
    }
    if (value == kActionType_listCollections) {
        return ActionTypeEnum::listCollections;
    }
    if (value == kActionType_listCursors) {
        return ActionTypeEnum::listCursors;
    }
    if (value == kActionType_listDatabases) {
        return ActionTypeEnum::listDatabases;
    }
    if (value == kActionType_listIndexes) {
        return ActionTypeEnum::listIndexes;
    }
    if (value == kActionType_listSessions) {
        return ActionTypeEnum::listSessions;
    }
    if (value == kActionType_listShards) {
        return ActionTypeEnum::listShards;
    }
    if (value == kActionType_logRotate) {
        return ActionTypeEnum::logRotate;
    }
    if (value == kActionType_moveChunk) {
        return ActionTypeEnum::moveChunk;
    }
    if (value == kActionType_netstat) {
        return ActionTypeEnum::netstat;
    }
    if (value == kActionType_oidReset) {
        return ActionTypeEnum::oidReset;
    }
    if (value == kActionType_operationMetrics) {
        return ActionTypeEnum::operationMetrics;
    }
    if (value == kActionType_planCacheIndexFilter) {
        return ActionTypeEnum::planCacheIndexFilter;
    }
    if (value == kActionType_planCacheRead) {
        return ActionTypeEnum::planCacheRead;
    }
    if (value == kActionType_planCacheWrite) {
        return ActionTypeEnum::planCacheWrite;
    }
    if (value == kActionType_refineCollectionShardKey) {
        return ActionTypeEnum::refineCollectionShardKey;
    }
    if (value == kActionType_reIndex) {
        return ActionTypeEnum::reIndex;
    }
    if (value == kActionType_remove) {
        return ActionTypeEnum::remove;
    }
    if (value == kActionType_removeShard) {
        return ActionTypeEnum::removeShard;
    }
    if (value == kActionType_renameCollection) {
        return ActionTypeEnum::renameCollection;
    }
    if (value == kActionType_renameCollectionSameDB) {
        return ActionTypeEnum::renameCollectionSameDB;
    }
    if (value == kActionType_repairDatabase) {
        return ActionTypeEnum::repairDatabase;
    }
    if (value == kActionType_replSetConfigure) {
        return ActionTypeEnum::replSetConfigure;
    }
    if (value == kActionType_replSetGetConfig) {
        return ActionTypeEnum::replSetGetConfig;
    }
    if (value == kActionType_replSetGetStatus) {
        return ActionTypeEnum::replSetGetStatus;
    }
    if (value == kActionType_replSetHeartbeat) {
        return ActionTypeEnum::replSetHeartbeat;
    }
    if (value == kActionType_replSetReconfig) {
        return ActionTypeEnum::replSetReconfig;
    }
    if (value == kActionType_replSetResizeOplog) {
        return ActionTypeEnum::replSetResizeOplog;
    }
    if (value == kActionType_replSetStateChange) {
        return ActionTypeEnum::replSetStateChange;
    }
    if (value == kActionType_reshardCollection) {
        return ActionTypeEnum::reshardCollection;
    }
    if (value == kActionType_resync) {
        return ActionTypeEnum::resync;
    }
    if (value == kActionType_revokeRole) {
        return ActionTypeEnum::revokeRole;
    }
    if (value == kActionType_revokePrivilegesFromRole) {
        return ActionTypeEnum::revokePrivilegesFromRole;
    }
    if (value == kActionType_revokeRolesFromRole) {
        return ActionTypeEnum::revokeRolesFromRole;
    }
    if (value == kActionType_revokeRolesFromUser) {
        return ActionTypeEnum::revokeRolesFromUser;
    }
    if (value == kActionType_rotateCertificates) {
        return ActionTypeEnum::rotateCertificates;
    }
    if (value == kActionType_runAsLessPrivilegedUser) {
        return ActionTypeEnum::runAsLessPrivilegedUser;
    }
    if (value == kActionType_runTenantMigration) {
        return ActionTypeEnum::runTenantMigration;
    }
    if (value == kActionType_serverStatus) {
        return ActionTypeEnum::serverStatus;
    }
    if (value == kActionType_setAuthenticationRestriction) {
        return ActionTypeEnum::setAuthenticationRestriction;
    }
    if (value == kActionType_setDefaultRWConcern) {
        return ActionTypeEnum::setDefaultRWConcern;
    }
    if (value == kActionType_setFeatureCompatibilityVersion) {
        return ActionTypeEnum::setFeatureCompatibilityVersion;
    }
    if (value == kActionType_setFreeMonitoring) {
        return ActionTypeEnum::setFreeMonitoring;
    }
    if (value == kActionType_setParameter) {
        return ActionTypeEnum::setParameter;
    }
    if (value == kActionType_shardCollection) {
        return ActionTypeEnum::shardCollection;
    }
    if (value == kActionType_shardingState) {
        return ActionTypeEnum::shardingState;
    }
    if (value == kActionType_shutdown) {
        return ActionTypeEnum::shutdown;
    }
    if (value == kActionType_splitChunk) {
        return ActionTypeEnum::splitChunk;
    }
    if (value == kActionType_splitVector) {
        return ActionTypeEnum::splitVector;
    }
    if (value == kActionType_storageDetails) {
        return ActionTypeEnum::storageDetails;
    }
    if (value == kActionType_top) {
        return ActionTypeEnum::top;
    }
    if (value == kActionType_touch) {
        return ActionTypeEnum::touch;
    }
    if (value == kActionType_trafficRecord) {
        return ActionTypeEnum::trafficRecord;
    }
    if (value == kActionType_unlock) {
        return ActionTypeEnum::unlock;
    }
    if (value == kActionType_useUUID) {
        return ActionTypeEnum::useUUID;
    }
    if (value == kActionType_update) {
        return ActionTypeEnum::update;
    }
    if (value == kActionType_updateRole) {
        return ActionTypeEnum::updateRole;
    }
    if (value == kActionType_updateUser) {
        return ActionTypeEnum::updateUser;
    }
    if (value == kActionType_validate) {
        return ActionTypeEnum::validate;
    }
    if (value == kActionType_viewRole) {
        return ActionTypeEnum::viewRole;
    }
    if (value == kActionType_viewUser) {
        return ActionTypeEnum::viewUser;
    }
    if (value == kActionType_applyOps) {
        return ActionTypeEnum::applyOps;
    }
    ctxt.throwBadEnumValue(value);
}

StringData ActionType_serializer(ActionTypeEnum value) {
    if (value == ActionTypeEnum::addShard) {
        return kActionType_addShard;
    }
    if (value == ActionTypeEnum::advanceClusterTime) {
        return kActionType_advanceClusterTime;
    }
    if (value == ActionTypeEnum::anyAction) {
        return kActionType_anyAction;
    }
    if (value == ActionTypeEnum::appendOplogNote) {
        return kActionType_appendOplogNote;
    }
    if (value == ActionTypeEnum::applicationMessage) {
        return kActionType_applicationMessage;
    }
    if (value == ActionTypeEnum::auditConfigure) {
        return kActionType_auditConfigure;
    }
    if (value == ActionTypeEnum::auditLogRotate) {
        return kActionType_auditLogRotate;
    }
    if (value == ActionTypeEnum::authCheck) {
        return kActionType_authCheck;
    }
    if (value == ActionTypeEnum::authenticate) {
        return kActionType_authenticate;
    }
    if (value == ActionTypeEnum::authSchemaUpgrade) {
        return kActionType_authSchemaUpgrade;
    }
    if (value == ActionTypeEnum::bypassDocumentValidation) {
        return kActionType_bypassDocumentValidation;
    }
    if (value == ActionTypeEnum::changeCustomData) {
        return kActionType_changeCustomData;
    }
    if (value == ActionTypeEnum::changePassword) {
        return kActionType_changePassword;
    }
    if (value == ActionTypeEnum::changeOwnPassword) {
        return kActionType_changeOwnPassword;
    }
    if (value == ActionTypeEnum::changeOwnCustomData) {
        return kActionType_changeOwnCustomData;
    }
    if (value == ActionTypeEnum::changeStream) {
        return kActionType_changeStream;
    }
    if (value == ActionTypeEnum::checkFreeMonitoringStatus) {
        return kActionType_checkFreeMonitoringStatus;
    }
    if (value == ActionTypeEnum::cleanupOrphaned) {
        return kActionType_cleanupOrphaned;
    }
    if (value == ActionTypeEnum::clearJumboFlag) {
        return kActionType_clearJumboFlag;
    }
    if (value == ActionTypeEnum::closeAllDatabases) {
        return kActionType_closeAllDatabases;
    }
    if (value == ActionTypeEnum::collMod) {
        return kActionType_collMod;
    }
    if (value == ActionTypeEnum::collStats) {
        return kActionType_collStats;
    }
    if (value == ActionTypeEnum::compact) {
        return kActionType_compact;
    }
    if (value == ActionTypeEnum::connPoolStats) {
        return kActionType_connPoolStats;
    }
    if (value == ActionTypeEnum::connPoolSync) {
        return kActionType_connPoolSync;
    }
    if (value == ActionTypeEnum::convertToCapped) {
        return kActionType_convertToCapped;
    }
    if (value == ActionTypeEnum::cpuProfiler) {
        return kActionType_cpuProfiler;
    }
    if (value == ActionTypeEnum::createCollection) {
        return kActionType_createCollection;
    }
    if (value == ActionTypeEnum::createDatabase) {
        return kActionType_createDatabase;
    }
    if (value == ActionTypeEnum::createIndex) {
        return kActionType_createIndex;
    }
    if (value == ActionTypeEnum::createRole) {
        return kActionType_createRole;
    }
    if (value == ActionTypeEnum::createUser) {
        return kActionType_createUser;
    }
    if (value == ActionTypeEnum::dbCheck) {
        return kActionType_dbCheck;
    }
    if (value == ActionTypeEnum::dbHash) {
        return kActionType_dbHash;
    }
    if (value == ActionTypeEnum::dbStats) {
        return kActionType_dbStats;
    }
    if (value == ActionTypeEnum::dropAllRolesFromDatabase) {
        return kActionType_dropAllRolesFromDatabase;
    }
    if (value == ActionTypeEnum::dropAllUsersFromDatabase) {
        return kActionType_dropAllUsersFromDatabase;
    }
    if (value == ActionTypeEnum::dropCollection) {
        return kActionType_dropCollection;
    }
    if (value == ActionTypeEnum::dropConnections) {
        return kActionType_dropConnections;
    }
    if (value == ActionTypeEnum::dropDatabase) {
        return kActionType_dropDatabase;
    }
    if (value == ActionTypeEnum::dropIndex) {
        return kActionType_dropIndex;
    }
    if (value == ActionTypeEnum::dropRole) {
        return kActionType_dropRole;
    }
    if (value == ActionTypeEnum::dropUser) {
        return kActionType_dropUser;
    }
    if (value == ActionTypeEnum::emptycapped) {
        return kActionType_emptycapped;
    }
    if (value == ActionTypeEnum::enableProfiler) {
        return kActionType_enableProfiler;
    }
    if (value == ActionTypeEnum::enableSharding) {
        return kActionType_enableSharding;
    }
    if (value == ActionTypeEnum::exportCollection) {
        return kActionType_exportCollection;
    }
    if (value == ActionTypeEnum::find) {
        return kActionType_find;
    }
    if (value == ActionTypeEnum::flushRouterConfig) {
        return kActionType_flushRouterConfig;
    }
    if (value == ActionTypeEnum::forceUUID) {
        return kActionType_forceUUID;
    }
    if (value == ActionTypeEnum::fsync) {
        return kActionType_fsync;
    }
    if (value == ActionTypeEnum::getDatabaseVersion) {
        return kActionType_getDatabaseVersion;
    }
    if (value == ActionTypeEnum::getDefaultRWConcern) {
        return kActionType_getDefaultRWConcern;
    }
    if (value == ActionTypeEnum::getCmdLineOpts) {
        return kActionType_getCmdLineOpts;
    }
    if (value == ActionTypeEnum::getLog) {
        return kActionType_getLog;
    }
    if (value == ActionTypeEnum::getParameter) {
        return kActionType_getParameter;
    }
    if (value == ActionTypeEnum::getShardMap) {
        return kActionType_getShardMap;
    }
    if (value == ActionTypeEnum::getShardVersion) {
        return kActionType_getShardVersion;
    }
    if (value == ActionTypeEnum::grantRole) {
        return kActionType_grantRole;
    }
    if (value == ActionTypeEnum::grantPrivilegesToRole) {
        return kActionType_grantPrivilegesToRole;
    }
    if (value == ActionTypeEnum::grantRolesToRole) {
        return kActionType_grantRolesToRole;
    }
    if (value == ActionTypeEnum::grantRolesToUser) {
        return kActionType_grantRolesToUser;
    }
    if (value == ActionTypeEnum::hostInfo) {
        return kActionType_hostInfo;
    }
    if (value == ActionTypeEnum::impersonate) {
        return kActionType_impersonate;
    }
    if (value == ActionTypeEnum::importCollection) {
        return kActionType_importCollection;
    }
    if (value == ActionTypeEnum::indexStats) {
        return kActionType_indexStats;
    }
    if (value == ActionTypeEnum::inprog) {
        return kActionType_inprog;
    }
    if (value == ActionTypeEnum::insert) {
        return kActionType_insert;
    }
    if (value == ActionTypeEnum::internal) {
        return kActionType_internal;
    }
    if (value == ActionTypeEnum::invalidateUserCache) {
        return kActionType_invalidateUserCache;
    }
    if (value == ActionTypeEnum::killAnyCursor) {
        return kActionType_killAnyCursor;
    }
    if (value == ActionTypeEnum::killAnySession) {
        return kActionType_killAnySession;
    }
    if (value == ActionTypeEnum::killCursors) {
        return kActionType_killCursors;
    }
    if (value == ActionTypeEnum::killop) {
        return kActionType_killop;
    }
    if (value == ActionTypeEnum::listCachedAndActiveUsers) {
        return kActionType_listCachedAndActiveUsers;
    }
    if (value == ActionTypeEnum::listCollections) {
        return kActionType_listCollections;
    }
    if (value == ActionTypeEnum::listCursors) {
        return kActionType_listCursors;
    }
    if (value == ActionTypeEnum::listDatabases) {
        return kActionType_listDatabases;
    }
    if (value == ActionTypeEnum::listIndexes) {
        return kActionType_listIndexes;
    }
    if (value == ActionTypeEnum::listSessions) {
        return kActionType_listSessions;
    }
    if (value == ActionTypeEnum::listShards) {
        return kActionType_listShards;
    }
    if (value == ActionTypeEnum::logRotate) {
        return kActionType_logRotate;
    }
    if (value == ActionTypeEnum::moveChunk) {
        return kActionType_moveChunk;
    }
    if (value == ActionTypeEnum::netstat) {
        return kActionType_netstat;
    }
    if (value == ActionTypeEnum::oidReset) {
        return kActionType_oidReset;
    }
    if (value == ActionTypeEnum::operationMetrics) {
        return kActionType_operationMetrics;
    }
    if (value == ActionTypeEnum::planCacheIndexFilter) {
        return kActionType_planCacheIndexFilter;
    }
    if (value == ActionTypeEnum::planCacheRead) {
        return kActionType_planCacheRead;
    }
    if (value == ActionTypeEnum::planCacheWrite) {
        return kActionType_planCacheWrite;
    }
    if (value == ActionTypeEnum::refineCollectionShardKey) {
        return kActionType_refineCollectionShardKey;
    }
    if (value == ActionTypeEnum::reIndex) {
        return kActionType_reIndex;
    }
    if (value == ActionTypeEnum::remove) {
        return kActionType_remove;
    }
    if (value == ActionTypeEnum::removeShard) {
        return kActionType_removeShard;
    }
    if (value == ActionTypeEnum::renameCollection) {
        return kActionType_renameCollection;
    }
    if (value == ActionTypeEnum::renameCollectionSameDB) {
        return kActionType_renameCollectionSameDB;
    }
    if (value == ActionTypeEnum::repairDatabase) {
        return kActionType_repairDatabase;
    }
    if (value == ActionTypeEnum::replSetConfigure) {
        return kActionType_replSetConfigure;
    }
    if (value == ActionTypeEnum::replSetGetConfig) {
        return kActionType_replSetGetConfig;
    }
    if (value == ActionTypeEnum::replSetGetStatus) {
        return kActionType_replSetGetStatus;
    }
    if (value == ActionTypeEnum::replSetHeartbeat) {
        return kActionType_replSetHeartbeat;
    }
    if (value == ActionTypeEnum::replSetReconfig) {
        return kActionType_replSetReconfig;
    }
    if (value == ActionTypeEnum::replSetResizeOplog) {
        return kActionType_replSetResizeOplog;
    }
    if (value == ActionTypeEnum::replSetStateChange) {
        return kActionType_replSetStateChange;
    }
    if (value == ActionTypeEnum::reshardCollection) {
        return kActionType_reshardCollection;
    }
    if (value == ActionTypeEnum::resync) {
        return kActionType_resync;
    }
    if (value == ActionTypeEnum::revokeRole) {
        return kActionType_revokeRole;
    }
    if (value == ActionTypeEnum::revokePrivilegesFromRole) {
        return kActionType_revokePrivilegesFromRole;
    }
    if (value == ActionTypeEnum::revokeRolesFromRole) {
        return kActionType_revokeRolesFromRole;
    }
    if (value == ActionTypeEnum::revokeRolesFromUser) {
        return kActionType_revokeRolesFromUser;
    }
    if (value == ActionTypeEnum::rotateCertificates) {
        return kActionType_rotateCertificates;
    }
    if (value == ActionTypeEnum::runAsLessPrivilegedUser) {
        return kActionType_runAsLessPrivilegedUser;
    }
    if (value == ActionTypeEnum::runTenantMigration) {
        return kActionType_runTenantMigration;
    }
    if (value == ActionTypeEnum::serverStatus) {
        return kActionType_serverStatus;
    }
    if (value == ActionTypeEnum::setAuthenticationRestriction) {
        return kActionType_setAuthenticationRestriction;
    }
    if (value == ActionTypeEnum::setDefaultRWConcern) {
        return kActionType_setDefaultRWConcern;
    }
    if (value == ActionTypeEnum::setFeatureCompatibilityVersion) {
        return kActionType_setFeatureCompatibilityVersion;
    }
    if (value == ActionTypeEnum::setFreeMonitoring) {
        return kActionType_setFreeMonitoring;
    }
    if (value == ActionTypeEnum::setParameter) {
        return kActionType_setParameter;
    }
    if (value == ActionTypeEnum::shardCollection) {
        return kActionType_shardCollection;
    }
    if (value == ActionTypeEnum::shardingState) {
        return kActionType_shardingState;
    }
    if (value == ActionTypeEnum::shutdown) {
        return kActionType_shutdown;
    }
    if (value == ActionTypeEnum::splitChunk) {
        return kActionType_splitChunk;
    }
    if (value == ActionTypeEnum::splitVector) {
        return kActionType_splitVector;
    }
    if (value == ActionTypeEnum::storageDetails) {
        return kActionType_storageDetails;
    }
    if (value == ActionTypeEnum::top) {
        return kActionType_top;
    }
    if (value == ActionTypeEnum::touch) {
        return kActionType_touch;
    }
    if (value == ActionTypeEnum::trafficRecord) {
        return kActionType_trafficRecord;
    }
    if (value == ActionTypeEnum::unlock) {
        return kActionType_unlock;
    }
    if (value == ActionTypeEnum::useUUID) {
        return kActionType_useUUID;
    }
    if (value == ActionTypeEnum::update) {
        return kActionType_update;
    }
    if (value == ActionTypeEnum::updateRole) {
        return kActionType_updateRole;
    }
    if (value == ActionTypeEnum::updateUser) {
        return kActionType_updateUser;
    }
    if (value == ActionTypeEnum::validate) {
        return kActionType_validate;
    }
    if (value == ActionTypeEnum::viewRole) {
        return kActionType_viewRole;
    }
    if (value == ActionTypeEnum::viewUser) {
        return kActionType_viewUser;
    }
    if (value == ActionTypeEnum::applyOps) {
        return kActionType_applyOps;
    }
    MONGO_UNREACHABLE;
    return StringData();
}

/**
 * test
 */
namespace  {
constexpr StringData kMatchType_kMatchNever = "never"_sd;
constexpr StringData kMatchType_kMatchClusterResource = "cluster"_sd;
constexpr StringData kMatchType_kMatchDatabaseName = "database"_sd;
constexpr StringData kMatchType_kMatchCollectionName = "collection"_sd;
constexpr StringData kMatchType_kMatchExactNamespace = "exact_namespace"_sd;
constexpr StringData kMatchType_kMatchAnyNormalResource = "any_normal"_sd;
constexpr StringData kMatchType_kMatchAnyResource = "any"_sd;
constexpr StringData kMatchType_kMatchExactSystemBucketResource = "system_buckets"_sd;
constexpr StringData kMatchType_kMatchSystemBucketInAnyDBResource = "system_buckets_in_any_db"_sd;
constexpr StringData kMatchType_kMatchAnySystemBucketInDBResource = "any_system_buckets_in_db"_sd;
constexpr StringData kMatchType_kMatchAnySystemBucketResource = "any_system_buckets"_sd;
}  // namespace 

MatchTypeEnum MatchType_parse(const IDLParserErrorContext& ctxt, StringData value) {
    if (value == kMatchType_kMatchNever) {
        return MatchTypeEnum::kMatchNever;
    }
    if (value == kMatchType_kMatchClusterResource) {
        return MatchTypeEnum::kMatchClusterResource;
    }
    if (value == kMatchType_kMatchDatabaseName) {
        return MatchTypeEnum::kMatchDatabaseName;
    }
    if (value == kMatchType_kMatchCollectionName) {
        return MatchTypeEnum::kMatchCollectionName;
    }
    if (value == kMatchType_kMatchExactNamespace) {
        return MatchTypeEnum::kMatchExactNamespace;
    }
    if (value == kMatchType_kMatchAnyNormalResource) {
        return MatchTypeEnum::kMatchAnyNormalResource;
    }
    if (value == kMatchType_kMatchAnyResource) {
        return MatchTypeEnum::kMatchAnyResource;
    }
    if (value == kMatchType_kMatchExactSystemBucketResource) {
        return MatchTypeEnum::kMatchExactSystemBucketResource;
    }
    if (value == kMatchType_kMatchSystemBucketInAnyDBResource) {
        return MatchTypeEnum::kMatchSystemBucketInAnyDBResource;
    }
    if (value == kMatchType_kMatchAnySystemBucketInDBResource) {
        return MatchTypeEnum::kMatchAnySystemBucketInDBResource;
    }
    if (value == kMatchType_kMatchAnySystemBucketResource) {
        return MatchTypeEnum::kMatchAnySystemBucketResource;
    }
    ctxt.throwBadEnumValue(value);
}

StringData MatchType_serializer(MatchTypeEnum value) {
    if (value == MatchTypeEnum::kMatchNever) {
        return kMatchType_kMatchNever;
    }
    if (value == MatchTypeEnum::kMatchClusterResource) {
        return kMatchType_kMatchClusterResource;
    }
    if (value == MatchTypeEnum::kMatchDatabaseName) {
        return kMatchType_kMatchDatabaseName;
    }
    if (value == MatchTypeEnum::kMatchCollectionName) {
        return kMatchType_kMatchCollectionName;
    }
    if (value == MatchTypeEnum::kMatchExactNamespace) {
        return kMatchType_kMatchExactNamespace;
    }
    if (value == MatchTypeEnum::kMatchAnyNormalResource) {
        return kMatchType_kMatchAnyNormalResource;
    }
    if (value == MatchTypeEnum::kMatchAnyResource) {
        return kMatchType_kMatchAnyResource;
    }
    if (value == MatchTypeEnum::kMatchExactSystemBucketResource) {
        return kMatchType_kMatchExactSystemBucketResource;
    }
    if (value == MatchTypeEnum::kMatchSystemBucketInAnyDBResource) {
        return kMatchType_kMatchSystemBucketInAnyDBResource;
    }
    if (value == MatchTypeEnum::kMatchAnySystemBucketInDBResource) {
        return kMatchType_kMatchAnySystemBucketInDBResource;
    }
    if (value == MatchTypeEnum::kMatchAnySystemBucketResource) {
        return kMatchType_kMatchAnySystemBucketResource;
    }
    MONGO_UNREACHABLE;
    return StringData();
}

}  // namespace mongo
