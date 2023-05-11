/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/stats/operation_resource_consumption_gen.h --output build/opt/mongo/db/stats/operation_resource_consumption_gen.cpp src/mongo/db/stats/operation_resource_consumption.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/stats/operation_resource_consumption_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"
#include "mongo/idl/server_parameter.h"
#include "mongo/idl/server_parameter_with_storage.h"

namespace mongo {

bool gAggregateOperationResourceConsumptionMetrics{false};
bool gProfileOperationResourceConsumptionMetrics{false};
int32_t gDocumentUnitSizeBytes{128};
int32_t gIndexEntryUnitSizeBytes{16};
int32_t gTotalUnitWriteSizeBytes{128};
MONGO_SERVER_PARAMETER_REGISTER(idl_0f3ea9b062fd7706675943a793e25b9f1b5aedba)(InitializerContext*) {
    /**
     * When true, globally aggregates per-operation resource consumption metrics.
     */
    [[maybe_unused]] auto* scp_0 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("aggregateOperationResourceConsumptionMetrics", gAggregateOperationResourceConsumptionMetrics);
        return ret;
    })();

    /**
     * When true, records and profiles per-operation resource consumption metrics
     */
    [[maybe_unused]] auto* scp_1 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("profileOperationResourceConsumptionMetrics", gProfileOperationResourceConsumptionMetrics);
        return ret;
    })();

    /**
     * The size of a document unit in bytes for resource consumption metrics collection
     */
    [[maybe_unused]] auto* scp_2 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("documentUnitSizeBytes", gDocumentUnitSizeBytes);
        ret->addBound<idl_server_parameter_detail::GTE>(1);
        return ret;
    })();

    /**
     * The size of an index entry unit for resource consumption metrics collection
     */
    [[maybe_unused]] auto* scp_3 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("indexEntryUnitSizeBytes", gIndexEntryUnitSizeBytes);
        ret->addBound<idl_server_parameter_detail::GTE>(1);
        return ret;
    })();

    /**
     * The size of a (doc + index) unit in written bytes for resource consumption metrics collection
     */
    [[maybe_unused]] auto* scp_4 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("totalUnitWriteSizeBytes", gTotalUnitWriteSizeBytes);
        ret->addBound<idl_server_parameter_detail::GTE>(1);
        return ret;
    })();

}
}  // namespace mongo
