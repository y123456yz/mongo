/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/s/resharding/resharding_server_parameters_gen.h --output build/opt/mongo/db/s/resharding/resharding_server_parameters_gen.cpp src/mongo/db/s/resharding/resharding_server_parameters.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/s/resharding/resharding_server_parameters_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"
#include "mongo/idl/server_parameter.h"
#include "mongo/idl/server_parameter_with_storage.h"

namespace mongo {
namespace resharding {

int gReshardingCoordinatorServiceMaxThreadCount{3};
int gReshardingDonorServiceMaxThreadCount{2};
int gReshardingRecipientServiceMaxThreadCount{8};
AtomicWord<int> gReshardingCollectionClonerBatchSizeInBytes{100 * 1024};
AtomicWord<int> gReshardingTxnClonerProgressBatchSize{1000};
AtomicWord<int> gReshardingOplogBatchTaskCount{(gReshardingRecipientServiceMaxThreadCount + 1) / 2};
AtomicWord<int> gReshardingOplogBatchLimitOperations{5 * 1000};
AtomicWord<int> gReshardingOplogBatchLimitBytes{100 * 1024 * 1024};
AtomicWord<int> gReshardingOplogApplierMaxLockRequestTimeoutMillis{5};
AtomicWord<int> gReshardingMinimumOperationDurationMillis{5 * 60 * 1000};
AtomicWord<int> gReshardingCriticalSectionTimeoutMillis{5 * 1000};
AtomicWord<int> gRemainingReshardingOperationTimeThresholdMillis{2 * 1000};
MONGO_SERVER_PARAMETER_REGISTER(idl_4b683f8411f1d6d2352bcf9ce3e99886660adc1e)(InitializerContext*) {
    /**
     * The max number of threads in the resharding coordinator's thread pool.
     */
    [[maybe_unused]] auto* scp_0 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("reshardingCoordinatorServiceMaxThreadCount", gReshardingCoordinatorServiceMaxThreadCount);
        ret->addBound<idl_server_parameter_detail::LTE>(256);
        ret->addBound<idl_server_parameter_detail::GTE>(1);
        return ret;
    })();

    /**
     * The max number of threads in the resharding donor's thread pool.
     */
    [[maybe_unused]] auto* scp_1 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("reshardingDonorServiceMaxThreadCount", gReshardingDonorServiceMaxThreadCount);
        ret->addBound<idl_server_parameter_detail::LTE>(256);
        ret->addBound<idl_server_parameter_detail::GTE>(1);
        return ret;
    })();

    /**
     * The max number of threads in the resharding recipient's thread pool.
     */
    [[maybe_unused]] auto* scp_2 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("reshardingRecipientServiceMaxThreadCount", gReshardingRecipientServiceMaxThreadCount);
        ret->addBound<idl_server_parameter_detail::LTE>(256);
        ret->addBound<idl_server_parameter_detail::GTE>(1);
        return ret;
    })();

    /**
     * Limit for the number of bytes of data inserted per storage transaction (WriteUnitOfWork) by ReshardingCollectionCloner.
     */
    [[maybe_unused]] auto* scp_3 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("reshardingCollectionClonerBatchSizeInBytes", gReshardingCollectionClonerBatchSizeInBytes);
        ret->addBound<idl_server_parameter_detail::GTE>(1);
        return ret;
    })();

    /**
     * Number of config.transactions records from a donor shard to process before recording the lsid locally to resume from on primary failover or server restart.
     */
    [[maybe_unused]] auto* scp_4 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("reshardingTxnClonerProgressBatchSize", gReshardingTxnClonerProgressBatchSize);
        ret->addBound<idl_server_parameter_detail::GTE>(1);
        return ret;
    })();

    /**
     * The number of subtasks to divide a single oplog batch into so that it may be applied concurrently by different threads.
     */
    [[maybe_unused]] auto* scp_5 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("reshardingOplogBatchTaskCount", gReshardingOplogBatchTaskCount);
        ret->addBound<idl_server_parameter_detail::LTE>(256);
        ret->addBound<idl_server_parameter_detail::GTE>(1);
        return ret;
    })();

    /**
     * The maximum number of operations for ReshardingOplogApplier to apply in a single batch.
     */
    [[maybe_unused]] auto* scp_6 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("reshardingOplogBatchLimitOperations", gReshardingOplogBatchLimitOperations);
        ret->addBound<idl_server_parameter_detail::LTE>(([]{ constexpr auto value = 1000 * 1000; return value; })());
        ret->addBound<idl_server_parameter_detail::GTE>(1);
        return ret;
    })();

    /**
     * The maximum size in bytes for ReshardingOplogApplier to apply in a single batch.
     */
    [[maybe_unused]] auto* scp_7 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("reshardingOplogBatchLimitBytes", gReshardingOplogBatchLimitBytes);
        ret->addBound<idl_server_parameter_detail::LTE>(([]{ constexpr auto value = 100 * 1024 * 1024; return value; })());
        ret->addBound<idl_server_parameter_detail::GTE>(([]{ constexpr auto value = 16 * 1024 * 1024; return value; })());
        return ret;
    })();

    /**
     * The max number of milliseconds that the resharding oplog applier will wait for lock acquisition.
     */
    [[maybe_unused]] auto* scp_8 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("reshardingOplogApplierMaxLockRequestTimeoutMillis", gReshardingOplogApplierMaxLockRequestTimeoutMillis);
        return ret;
    })();

    /**
     * Controls the minimum duration of resharding operations, and allows transactions and  retryable writes started after the current resharding operation to complete within the  period defined by the parameter.
     */
    [[maybe_unused]] auto* scp_9 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("reshardingMinimumOperationDurationMillis", gReshardingMinimumOperationDurationMillis);
        ret->addBound<idl_server_parameter_detail::GTE>(0);
        return ret;
    })();

    /**
     * The upper limit on how long to wait to hear back from recipient shards reaching strict consistency after engaging the critical section.
     */
    [[maybe_unused]] auto* scp_10 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("reshardingCriticalSectionTimeoutMillis", gReshardingCriticalSectionTimeoutMillis);
        ret->addBound<idl_server_parameter_detail::GTE>(0);
        return ret;
    })();

    /**
     * Controls the threshold for engaging the critical section of resharding operations.  Once the remaining operation time on all recipients falls below this threshold, the  resharding coordinator will engage the critical section and block incoming writes.
     */
    [[maybe_unused]] auto* scp_11 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("remainingReshardingOperationTimeThresholdMillis", gRemainingReshardingOperationTimeThresholdMillis);
        ret->addBound<idl_server_parameter_detail::GTE>(0);
        return ret;
    })();

}
}  // namespace resharding
}  // namespace mongo
