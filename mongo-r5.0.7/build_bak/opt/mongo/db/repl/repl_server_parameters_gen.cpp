/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/repl/repl_server_parameters_gen.h --output build/opt/mongo/db/repl/repl_server_parameters_gen.cpp src/mongo/db/repl/repl_server_parameters.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/repl/repl_server_parameters_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"
#include "mongo/idl/server_parameter.h"
#include "mongo/idl/server_parameter_with_storage.h"

namespace mongo {
namespace repl {

::mongo::FeatureFlag feature_flags::gTenantMigrations{true, "4.9"_sd};
::mongo::FeatureFlag feature_flags::gUseSecondaryDelaySecs{true, "4.9"_sd};
::mongo::FeatureFlag feature_flags::gDefaultWCMajority{true, "5.0"_sd};
::mongo::FeatureFlag feature_flags::gFeatureFlagRetryableFindAndModify{true, "5.0"_sd};
::mongo::FeatureFlag feature_flags::gDefaultRCLocal{true, "5.0"_sd};
std::string initialSyncOplogBuffer{"collection"};
int initialSyncOplogBufferPeekCacheSize{10000};
AtomicWord<int> numInitialSyncConnectAttempts{10};
AtomicWord<int> numInitialSyncOplogFindAttempts{3};
int initialSyncOplogFetcherBatchSize{(16 * 1024 * 1024) / 12 * 10};
AtomicWord<int> oplogInitialFindMaxSeconds{60};
AtomicWord<int> oplogRetriedFindMaxSeconds{2};
bool oplogFetcherUsesExhaust{true};
int bgSyncOplogFetcherBatchSize{(16 * 1024 * 1024) / 12 * 10};
AtomicWord<int> rollbackRemoteOplogQueryBatchSize{2000};
AtomicWord<bool> forceRollbackViaRefetch{false};
AtomicWord<bool> writePeriodicNoops{true};
bool collectionClonerUsesExhaust{true};
int collectionBulkLoaderBatchSizeInBytes{256 * 1024};
int collectionClonerBatchSize{0};
AtomicWord<int> oplogFetcherSteadyStateMaxFetcherRestarts{1};
AtomicWord<int> oplogFetcherInitialSyncMaxFetcherRestarts{10};
int replWriterThreadCount{16};
int replWriterMinThreadCount{0};
AtomicWord<int> replBatchLimitOperations{5 * 1000};
AtomicWord<int> replBatchLimitBytes{100 * 1024 * 1024};
AtomicWord<int> tenantApplierBatchSizeBytes{16 * 1024 * 1024};
AtomicWord<int> tenantApplierBatchSizeOps{500};
AtomicWord<int> minOplogEntriesPerThread{16};
int tenantApplierThreadCount{5};
AtomicWord<int> initialSyncTransientErrorRetryPeriodSeconds{24 * 60 * 60};
AtomicWord<int> oplogNetworkTimeoutBufferSeconds{5};
bool oplogApplicationEnforcesSteadyStateConstraints{false};
std::string initialSyncSourceReadPreference{""};
AtomicWord<long long> changeSyncSourceThresholdMillis{5};
AtomicWord<int> maxNumSyncSourceChangesPerHour{3};
AtomicWord<bool> enableOverrideClusterChainingSetting{false};
bool disableSplitHorizonIPCheck{false};
AtomicWord<int> tenantMigrationGarbageCollectionDelayMS{15 * 60 * 1000};
AtomicWord<int> tenantMigrationExternalKeysRemovalBufferSecs{60 * 60 * 24};
int tenantMigrationOplogBufferPeekCacheSize{10000};
int tenantMigrationOplogFetcherBatchSize{(16 * 1024 * 1024) / 12 * 10};
int maxTenantMigrationRecipientThreadPoolSize{128};
int maxTenantMigrationDonorServiceThreadPoolSize{8};
AtomicWord<int> tenantMigrationBlockingStateTimeoutMS{3600000};
bool tenantMigrationDisableX509Auth{false};
int tenantMigrationExcludeDonorHostTimeoutMS{60000};
AtomicWord<bool> enableDefaultWriteConcernUpdatesForInitiate{false};
bool startupRecoveryForRestore{false};
AtomicWord<bool> gStoreFindAndModifyImagesInSideCollection{false};
AtomicWord<bool> enableReconfigRollbackCommittedWritesCheck{true};
MONGO_SERVER_PARAMETER_REGISTER(idl_8ddc250dbb1c12b1430c218ab90a19f202a22596)(InitializerContext*) {
    /**
     * When enabled, tenant migration commands are supported.
     */
    [[maybe_unused]] auto* scp_0 = ([]() -> ServerParameter* {
        auto* ret = new FeatureFlagServerParameter("featureFlagTenantMigrations", feature_flags::gTenantMigrations);
        return ret;
    })();

    /**
     * If enabled, use field secondaryDelaySecs instead of slaveDelay in MemberConfig.
     */
    [[maybe_unused]] auto* scp_1 = ([]() -> ServerParameter* {
        auto* ret = new FeatureFlagServerParameter("featureFlagUseSecondaryDelaySecs", feature_flags::gUseSecondaryDelaySecs);
        return ret;
    })();

    /**
     * When enabled, default write concern might be set to majority following the default write concern formula if there is no cluster wide write concern (CWWC).
     */
    [[maybe_unused]] auto* scp_2 = ([]() -> ServerParameter* {
        auto* ret = new FeatureFlagServerParameter("featureFlagDefaultWriteConcernMajority", feature_flags::gDefaultWCMajority);
        return ret;
    })();

    /**
     * When enabled, storeFindAndModifyImagesInOplog=false will change the location of any document images for retryable find and modifies.
     */
    [[maybe_unused]] auto* scp_3 = ([]() -> ServerParameter* {
        auto* ret = new FeatureFlagServerParameter("featureFlagRetryableFindAndModify", feature_flags::gFeatureFlagRetryableFindAndModify);
        return ret;
    })();

    /**
     * When enabled, default read concern will be set to local if there is no cluster wide read concern (CWRC).
     */
    [[maybe_unused]] auto* scp_4 = ([]() -> ServerParameter* {
        auto* ret = new FeatureFlagServerParameter("featureFlagDefaultReadConcernLocal", feature_flags::gDefaultRCLocal);
        return ret;
    })();

    /**
     * Set this to specify whether to use a collection to buffer the oplog on the destination server during initial sync to prevent rolling over the oplog.
     */
    [[maybe_unused]] auto* scp_5 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("initialSyncOplogBuffer", initialSyncOplogBuffer);
        return ret;
    })();

    /**
     * Set this to specify size of read ahead buffer in the OplogBufferCollection.
     */
    [[maybe_unused]] auto* scp_6 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("initialSyncOplogBufferPeekCacheSize", initialSyncOplogBufferPeekCacheSize);
        return ret;
    })();

    /**
     * The number of attempts to connect to a sync source
     */
    [[maybe_unused]] auto* scp_7 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("numInitialSyncConnectAttempts", numInitialSyncConnectAttempts);
        return ret;
    })();

    /**
     * The number of attempts to call find on the remote oplog
     */
    [[maybe_unused]] auto* scp_8 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("numInitialSyncOplogFindAttempts", numInitialSyncOplogFindAttempts);
        return ret;
    })();

    /**
     * The batchSize to use for the find/getMore queries called by the OplogFetcher
     */
    [[maybe_unused]] auto* scp_9 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("initialSyncOplogFetcherBatchSize", initialSyncOplogFetcherBatchSize);
        return ret;
    })();

    /**
     * Number of seconds for the `maxTimeMS` on the initial `find` command. For the initial 'find' request, we provide a generous timeout, to account for the potentially slow process of a sync source finding the lastApplied optime provided in a node's query in its oplog.
     */
    [[maybe_unused]] auto* scp_10 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("oplogInitialFindMaxSeconds", oplogInitialFindMaxSeconds);
        return ret;
    })();

    /**
     * Number of seconds for the `maxTimeMS` on any retried `find` commands
     */
    [[maybe_unused]] auto* scp_11 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("oplogRetriedFindMaxSeconds", oplogRetriedFindMaxSeconds);
        return ret;
    })();

    /**
     * Whether to use the "exhaust cursor" feature when fetching oplog entries from the sync source.
     */
    [[maybe_unused]] auto* scp_12 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("oplogFetcherUsesExhaust", oplogFetcherUsesExhaust);
        return ret;
    })();

    /**
     * The batchSize to use for the find/getMore queries called by the OplogFetcher
     */
    [[maybe_unused]] auto* scp_13 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("bgSyncOplogFetcherBatchSize", bgSyncOplogFetcherBatchSize);
        return ret;
    })();

    /**
     * The batchSize to use for the find/getMore queries called by the rollback common point resolver. A batchSize of 0 means that the 'find' and 'getMore' commands will be given no batchSize. We set the default to 2000 to prevent the sync source from having to read too much data at once, and reduce the chance of a socket timeout.
     */
    [[maybe_unused]] auto* scp_14 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("rollbackRemoteOplogQueryBatchSize", rollbackRemoteOplogQueryBatchSize);
        return ret;
    })();

    /**
     * If 'forceRollbackViaRefetch' is true, always perform rollbacks via the refetch algorithm, even if the storage engine supports rollback via recover to timestamp.
     */
    [[maybe_unused]] auto* scp_15 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("forceRollbackViaRefetch", forceRollbackViaRefetch);
        return ret;
    })();

    /**
     * Sets whether to write periodic noops or not
     */
    [[maybe_unused]] auto* scp_16 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("writePeriodicNoops", writePeriodicNoops);
        return ret;
    })();

    /**
     * Whether to use the "exhaust cursor" feature when retrieving collection data.
     */
    [[maybe_unused]] auto* scp_17 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("collectionClonerUsesExhaust", collectionClonerUsesExhaust);
        return ret;
    })();

    /**
     * Limit for the number of bytes of data inserted per storage transaction (WriteUnitOfWork) by collectionBulkLoader during initial sync collection cloning
     */
    [[maybe_unused]] auto* scp_18 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("collectionBulkLoaderBatchSizeInBytes", collectionBulkLoaderBatchSizeInBytes);
        return ret;
    })();

    /**
     * The batch size (number of documents) to use for the queries in the CollectionCloner. Default of '0' means the limit is the number of documents that will fit in a single BSON object.
     */
    [[maybe_unused]] auto* scp_19 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("collectionClonerBatchSize", collectionClonerBatchSize);
        ret->addBound<idl_server_parameter_detail::GTE>(0);
        return ret;
    })();

    /**
     * Set this to specify the maximum number of times the oplog fetcher will consecutively restart the oplog tailing query on non-cancellation errors during steady state replication.
     */
    [[maybe_unused]] auto* scp_20 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("oplogFetcherSteadyStateMaxFetcherRestarts", oplogFetcherSteadyStateMaxFetcherRestarts);
        ret->addBound<idl_server_parameter_detail::GTE>(0);
        return ret;
    })();

    /**
     * Set this to specify the maximum number of times the oplog fetcher will consecutively restart the oplog tailing query on non-cancellation errors during initial sync. By default we provide a generous amount of restarts to avoid potentially restarting an entire initial sync from scratch.
     */
    [[maybe_unused]] auto* scp_21 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("oplogFetcherInitialSyncMaxFetcherRestarts", oplogFetcherInitialSyncMaxFetcherRestarts);
        ret->addBound<idl_server_parameter_detail::GTE>(0);
        return ret;
    })();

    /**
     * The number of threads in the thread pool used to apply the oplog
     */
    [[maybe_unused]] auto* scp_22 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("replWriterThreadCount", replWriterThreadCount);
        ret->addBound<idl_server_parameter_detail::LTE>(256);
        ret->addBound<idl_server_parameter_detail::GTE>(1);
        return ret;
    })();

    /**
     * The minimum number of threads in the thread pool used to apply the oplog
     */
    [[maybe_unused]] auto* scp_23 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("replWriterMinThreadCount", replWriterMinThreadCount);
        ret->addBound<idl_server_parameter_detail::LTE>(256);
        ret->addBound<idl_server_parameter_detail::GTE>(0);
        return ret;
    })();

    /**
     * The maximum number of operations to apply in a single batch
     */
    [[maybe_unused]] auto* scp_24 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("replBatchLimitOperations", replBatchLimitOperations);
        ret->addBound<idl_server_parameter_detail::LTE>(([]{ constexpr auto value = 1000 * 1000; return value; })());
        ret->addBound<idl_server_parameter_detail::GTE>(1);
        return ret;
    })();

    /**
     * The maximum oplog application batch size in bytes
     */
    [[maybe_unused]] auto* scp_25 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("replBatchLimitBytes", replBatchLimitBytes);
        ret->addBound<idl_server_parameter_detail::LTE>(([]{ constexpr auto value = 100 * 1024 * 1024; return value; })());
        ret->addBound<idl_server_parameter_detail::GTE>(([]{ constexpr auto value = 16 * 1024 * 1024; return value; })());
        return ret;
    })();

    /**
     * The maximum tenant oplog applier batch size in bytes.
     */
    [[maybe_unused]] auto* scp_26 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("tenantApplierBatchSizeBytes", tenantApplierBatchSizeBytes);
        ret->addBound<idl_server_parameter_detail::LTE>(([]{ constexpr auto value = 100 * 1024 * 1024; return value; })());
        ret->addBound<idl_server_parameter_detail::GTE>(([]{ constexpr auto value = 16 * 1024 * 1024; return value; })());
        return ret;
    })();

    /**
     * The maximum number of operations in a tenant oplog applier batch.
     */
    [[maybe_unused]] auto* scp_27 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("tenantApplierBatchSizeOps", tenantApplierBatchSizeOps);
        ret->addBound<idl_server_parameter_detail::LTE>(([]{ constexpr auto value = 100 * 1000; return value; })());
        ret->addBound<idl_server_parameter_detail::GTE>(1);
        return ret;
    })();

    /**
     * The minimum number of operations allotted to a tenant oplog applier worker thread.
     */
    [[maybe_unused]] auto* scp_28 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("minOplogEntriesPerThread", minOplogEntriesPerThread);
        ret->addBound<idl_server_parameter_detail::LTE>(32);
        ret->addBound<idl_server_parameter_detail::GTE>(1);
        return ret;
    })();

    /**
     * The number of threads in the tenant migration writer pool used to apply operations.
     */
    [[maybe_unused]] auto* scp_29 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("tenantApplierThreadCount", tenantApplierThreadCount);
        ret->addBound<idl_server_parameter_detail::LTE>(256);
        ret->addBound<idl_server_parameter_detail::GTE>(1);
        return ret;
    })();

    /**
     * The amount of time to continue retrying transient errors during initial sync before declaring the attempt failed.
     */
    [[maybe_unused]] auto* scp_30 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("initialSyncTransientErrorRetryPeriodSeconds", initialSyncTransientErrorRetryPeriodSeconds);
        ret->addBound<idl_server_parameter_detail::GTE>(0);
        return ret;
    })();

    /**
     * Number of seconds to add to the `find` and `getMore` timeouts for oplog fetching to calculate the network timeout for the requests.
     */
    [[maybe_unused]] auto* scp_31 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("oplogNetworkTimeoutBufferSeconds", oplogNetworkTimeoutBufferSeconds);
        ret->addBound<idl_server_parameter_detail::GTE>(0);
        return ret;
    })();

    /**
     * Whether or not secondary oplog application enforces (by fassert) consistency constraints that apply if an oplog entry is to be applied exactly once and in order.
     */
    [[maybe_unused]] auto* scp_32 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("oplogApplicationEnforcesSteadyStateConstraints", oplogApplicationEnforcesSteadyStateConstraints);
        return ret;
    })();

    /**
     * Set this to specify how the sync source for initial sync is determined. Valid options are: nearest, primary, primaryPreferred, secondary, and secondaryPreferred.
     */
    [[maybe_unused]] auto* scp_33 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("initialSyncSourceReadPreference", initialSyncSourceReadPreference);
        ret->addValidator(validateReadPreferenceMode);
        return ret;
    })();

    /**
     * Threshold between ping times that are considered as coming from the same data center and ping times considered as coming from a different data center. Used to determine if the node should attempt to change sync sources because another node is significantly closer than its current sync source.
     */
    [[maybe_unused]] auto* scp_34 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("changeSyncSourceThresholdMillis", changeSyncSourceThresholdMillis);
        ret->addBound<idl_server_parameter_detail::GTE>(0);
        return ret;
    })();

    /**
     * The number of sync source changes that can happen per hour before the node temporarily turns off reevaluating its sync source. This will only affect sync source changes while a node has a valid sync source.
     */
    [[maybe_unused]] auto* scp_35 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("maxNumSyncSourceChangesPerHour", maxNumSyncSourceChangesPerHour);
        ret->addBound<idl_server_parameter_detail::GT>(0);
        return ret;
    })();

    /**
     * When enabled, allows a node to override the cluster-wide chainingAllowed setting.  If chaining is disabled in the replica set, enabling this parameter allows the node to chain regardless. 
     */
    [[maybe_unused]] auto* scp_36 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("enableOverrideClusterChainingSetting", enableOverrideClusterChainingSetting);
        return ret;
    })();

    /**
     * If true, disable check for IP addresses in split horizon configurations. As per the definition of SNI laid out in RFC6066, literal IP addresses are not allowed as server names.
     */
    [[maybe_unused]] auto* scp_37 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("disableSplitHorizonIPCheck", disableSplitHorizonIPCheck);
        return ret;
    })();

    /**
     * The amount of time in milliseconds that the donor or recipient should wait before removing the migration state document after receiving donorForgetMigration or recipientForgetMigration.
     */
    [[maybe_unused]] auto* scp_38 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("tenantMigrationGarbageCollectionDelayMS", tenantMigrationGarbageCollectionDelayMS);
        return ret;
    })();

    /**
     * The amount of time in seconds that the donor or recipient should wait before removing the cluster time keys cloned from each other after receiving donorForgetMigration or recipientForgetMigration
     */
    [[maybe_unused]] auto* scp_39 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("tenantMigrationExternalKeysRemovalBufferSecs", tenantMigrationExternalKeysRemovalBufferSecs);
        return ret;
    })();

    /**
     * Set this to specify size of read ahead buffer in the OplogBufferCollection for tenant migrations.
     */
    [[maybe_unused]] auto* scp_40 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("tenantMigrationOplogBufferPeekCacheSize", tenantMigrationOplogBufferPeekCacheSize);
        return ret;
    })();

    /**
     * The batchSize to use for the find/getMore queries called by the OplogFetcher for tenant migrations.
     */
    [[maybe_unused]] auto* scp_41 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("tenantMigrationOplogFetcherBatchSize", tenantMigrationOplogFetcherBatchSize);
        return ret;
    })();

    /**
     * The maximum number of threads in the tenant migration recipient's thread pool.
     */
    [[maybe_unused]] auto* scp_42 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("maxTenantMigrationRecipientThreadPoolSize", maxTenantMigrationRecipientThreadPoolSize);
        ret->addBound<idl_server_parameter_detail::GTE>(1);
        return ret;
    })();

    /**
     * The maximum number of threads in the tenant migration donor service's thread pool.
     */
    [[maybe_unused]] auto* scp_43 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("maxTenantMigrationDonorServiceThreadPoolSize", maxTenantMigrationDonorServiceThreadPoolSize);
        ret->addBound<idl_server_parameter_detail::GTE>(1);
        return ret;
    })();

    /**
     * Period of time, in milliseconds, after which the blocking state should be interrupted.
     */
    [[maybe_unused]] auto* scp_44 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("tenantMigrationBlockingStateTimeoutMS", tenantMigrationBlockingStateTimeoutMS);
        ret->addBound<idl_server_parameter_detail::GTE>(1);
        return ret;
    })();

    /**
     * Disable x509 authentication for all ingoing and outgoing tenant migrations.
     */
    [[maybe_unused]] auto* scp_45 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("tenantMigrationDisableX509Auth", tenantMigrationDisableX509Auth);
        return ret;
    })();

    /**
     * Period of time, in milliseconds, that a donor host should be excluded for.
     */
    [[maybe_unused]] auto* scp_46 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("tenantMigrationExcludeDonorHostTimeoutMS", tenantMigrationExcludeDonorHostTimeoutMS);
        ret->addBound<idl_server_parameter_detail::GTE>(1);
        return ret;
    })();

    /**
     * When enabled, allow the default write concern to be updated in the replica set initiate process. This parameter should only ever be enabled in our testing infrastructure, as using it in production may lead to undefined behavior.
     */
    [[maybe_unused]] auto* scp_47 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("enableDefaultWriteConcernUpdatesForInitiate", enableDefaultWriteConcernUpdatesForInitiate);
        return ret;
    })();

    /**
     * When set, do startup recovery in such a way that the history of the recovered operations is not preserved.  At the end of startup recovery, snapshot reads before the recovered top of oplog will not be possible.  Reduces cache pressure when recovering many oplog entries, as when restoring from backup in some scenarios.
     */
    [[maybe_unused]] auto* scp_48 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("startupRecoveryForRestore", startupRecoveryForRestore);
        return ret;
    })();

    /**
     * Determines where document images for retryable find and modifies are to be stored.
     */
    [[maybe_unused]] auto* scp_49 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("storeFindAndModifyImagesInSideCollection", gStoreFindAndModifyImagesInSideCollection);
        return ret;
    })();

    /**
     * Enables the reconfig check to ensure that committed writes cannot be rolled back in sets with arbiters. Enabled by default. Test-only.
     */
    auto* scp_50 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("enableReconfigRollbackCommittedWritesCheck", enableReconfigRollbackCommittedWritesCheck);
        return ret;
    })();
    scp_50->setTestOnly();

}
}  // namespace repl
}  // namespace mongo
