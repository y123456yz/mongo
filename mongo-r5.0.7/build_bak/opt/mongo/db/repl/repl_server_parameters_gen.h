/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/repl/repl_server_parameters_gen.h --output build/opt/mongo/db/repl/repl_server_parameters_gen.cpp src/mongo/db/repl/repl_server_parameters.idl
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
#include "mongo/client/read_preference.h"
#include "mongo/db/namespace_string.h"
#include "mongo/idl/basic_types.h"
#include "mongo/idl/basic_types_gen.h"
#include "mongo/idl/feature_flag.h"
#include "mongo/idl/idl_parser.h"
#include "mongo/idl/server_parameter.h"
#include "mongo/idl/server_parameter_with_storage.h"
#include "mongo/rpc/op_msg.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/util/uuid.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {
namespace repl {

namespace feature_flags {
extern ::mongo::FeatureFlag gTenantMigrations;
}  // namespace feature_flags

namespace feature_flags {
extern ::mongo::FeatureFlag gUseSecondaryDelaySecs;
}  // namespace feature_flags

namespace feature_flags {
extern ::mongo::FeatureFlag gDefaultWCMajority;
}  // namespace feature_flags

namespace feature_flags {
extern ::mongo::FeatureFlag gFeatureFlagRetryableFindAndModify;
}  // namespace feature_flags

namespace feature_flags {
extern ::mongo::FeatureFlag gDefaultRCLocal;
}  // namespace feature_flags

constexpr auto kInitialSyncOplogBufferDefault = "collection";

extern std::string initialSyncOplogBuffer;
constexpr auto kInitialSyncOplogBufferPeekCacheSizeDefault = 10000;

extern int initialSyncOplogBufferPeekCacheSize;
constexpr auto kNumInitialSyncConnectAttemptsDefault = 10;

extern AtomicWord<int> numInitialSyncConnectAttempts;
constexpr auto kNumInitialSyncOplogFindAttemptsDefault = 3;

extern AtomicWord<int> numInitialSyncOplogFindAttempts;
constexpr auto kInitialSyncOplogFetcherBatchSizeDefault = (16 * 1024 * 1024) / 12 * 10;

extern int initialSyncOplogFetcherBatchSize;
constexpr auto kOplogInitialFindMaxSecondsDefault = 60;

extern AtomicWord<int> oplogInitialFindMaxSeconds;
constexpr auto kOplogRetriedFindMaxSecondsDefault = 2;

extern AtomicWord<int> oplogRetriedFindMaxSeconds;
constexpr auto kOplogFetcherUsesExhaustDefault = true;

extern bool oplogFetcherUsesExhaust;
constexpr auto kBgSyncOplogFetcherBatchSizeDefault = (16 * 1024 * 1024) / 12 * 10;

extern int bgSyncOplogFetcherBatchSize;
constexpr auto kRollbackRemoteOplogQueryBatchSizeDefault = 2000;

extern AtomicWord<int> rollbackRemoteOplogQueryBatchSize;
constexpr auto kForceRollbackViaRefetchDefault = false;

extern AtomicWord<bool> forceRollbackViaRefetch;
constexpr auto kWritePeriodicNoopsDefault = true;

extern AtomicWord<bool> writePeriodicNoops;
constexpr auto kCollectionClonerUsesExhaustDefault = true;

extern bool collectionClonerUsesExhaust;
constexpr auto kCollectionBulkLoaderBatchSizeInBytesDefault = 256 * 1024;

extern int collectionBulkLoaderBatchSizeInBytes;
constexpr auto kCollectionClonerBatchSizeDefault = 0;

extern int collectionClonerBatchSize;
constexpr auto kOplogFetcherSteadyStateMaxFetcherRestartsDefault = 1;

extern AtomicWord<int> oplogFetcherSteadyStateMaxFetcherRestarts;
constexpr auto kOplogFetcherInitialSyncMaxFetcherRestartsDefault = 10;

extern AtomicWord<int> oplogFetcherInitialSyncMaxFetcherRestarts;
constexpr auto kReplWriterThreadCountDefault = 16;

extern int replWriterThreadCount;
constexpr auto kReplWriterMinThreadCountDefault = 0;

extern int replWriterMinThreadCount;
constexpr auto kReplBatchLimitOperationsDefault = 5 * 1000;

extern AtomicWord<int> replBatchLimitOperations;
constexpr auto kReplBatchLimitBytesDefault = 100 * 1024 * 1024;

extern AtomicWord<int> replBatchLimitBytes;
constexpr auto kTenantApplierBatchSizeBytesDefault = 16 * 1024 * 1024;

extern AtomicWord<int> tenantApplierBatchSizeBytes;
constexpr auto kTenantApplierBatchSizeOpsDefault = 500;

extern AtomicWord<int> tenantApplierBatchSizeOps;
constexpr auto kMinOplogEntriesPerThreadDefault = 16;

extern AtomicWord<int> minOplogEntriesPerThread;
constexpr auto kTenantApplierThreadCountDefault = 5;

extern int tenantApplierThreadCount;
constexpr auto kInitialSyncTransientErrorRetryPeriodSecondsDefault = 24 * 60 * 60;

extern AtomicWord<int> initialSyncTransientErrorRetryPeriodSeconds;
constexpr auto kOplogNetworkTimeoutBufferSecondsDefault = 5;

extern AtomicWord<int> oplogNetworkTimeoutBufferSeconds;
constexpr auto kOplogApplicationEnforcesSteadyStateConstraintsDefault = false;

extern bool oplogApplicationEnforcesSteadyStateConstraints;
constexpr auto kInitialSyncSourceReadPreferenceDefault = "";

extern std::string initialSyncSourceReadPreference;
constexpr auto kChangeSyncSourceThresholdMillisDefault = 5;

extern AtomicWord<long long> changeSyncSourceThresholdMillis;
constexpr auto kMaxNumSyncSourceChangesPerHourDefault = 3;

extern AtomicWord<int> maxNumSyncSourceChangesPerHour;
constexpr auto kEnableOverrideClusterChainingSettingDefault = false;

extern AtomicWord<bool> enableOverrideClusterChainingSetting;
constexpr auto kDisableSplitHorizonIPCheckDefault = false;

extern bool disableSplitHorizonIPCheck;
constexpr auto kTenantMigrationGarbageCollectionDelayMSDefault = 15 * 60 * 1000;

extern AtomicWord<int> tenantMigrationGarbageCollectionDelayMS;
constexpr auto kTenantMigrationExternalKeysRemovalBufferSecsDefault = 60 * 60 * 24;

extern AtomicWord<int> tenantMigrationExternalKeysRemovalBufferSecs;
constexpr auto kTenantMigrationOplogBufferPeekCacheSizeDefault = 10000;

extern int tenantMigrationOplogBufferPeekCacheSize;
constexpr auto kTenantMigrationOplogFetcherBatchSizeDefault = (16 * 1024 * 1024) / 12 * 10;

extern int tenantMigrationOplogFetcherBatchSize;
constexpr auto kMaxTenantMigrationRecipientThreadPoolSizeDefault = 128;

extern int maxTenantMigrationRecipientThreadPoolSize;
constexpr auto kMaxTenantMigrationDonorServiceThreadPoolSizeDefault = 8;

extern int maxTenantMigrationDonorServiceThreadPoolSize;
constexpr auto kTenantMigrationBlockingStateTimeoutMSDefault = 3600000;

extern AtomicWord<int> tenantMigrationBlockingStateTimeoutMS;
constexpr auto kTenantMigrationDisableX509AuthDefault = false;

extern bool tenantMigrationDisableX509Auth;
constexpr auto kTenantMigrationExcludeDonorHostTimeoutMSDefault = 60000;

extern int tenantMigrationExcludeDonorHostTimeoutMS;
constexpr auto kEnableDefaultWriteConcernUpdatesForInitiateDefault = false;

extern AtomicWord<bool> enableDefaultWriteConcernUpdatesForInitiate;
constexpr auto kStartupRecoveryForRestoreDefault = false;

extern bool startupRecoveryForRestore;
constexpr auto kStoreFindAndModifyImagesInSideCollectionDefault = false;

extern AtomicWord<bool> gStoreFindAndModifyImagesInSideCollection;
constexpr auto kEnableReconfigRollbackCommittedWritesCheckDefault = true;

extern AtomicWord<bool> enableReconfigRollbackCommittedWritesCheck;
}  // namespace repl
}  // namespace mongo
