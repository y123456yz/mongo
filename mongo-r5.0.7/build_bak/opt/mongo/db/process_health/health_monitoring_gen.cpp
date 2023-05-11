/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/process_health/health_monitoring_gen.h --output build/opt/mongo/db/process_health/health_monitoring_gen.cpp src/mongo/db/process_health/health_monitoring.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/process_health/health_monitoring_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"
#include "mongo/idl/server_parameter.h"
#include "mongo/idl/server_parameter_with_storage.h"

namespace mongo {
namespace feature_flags {

::mongo::FeatureFlag gFeatureFlagHealthMonitoring{true, "5.0"_sd};
MONGO_SERVER_PARAMETER_REGISTER(idl_5679634b8101123c971be550e66113c203c103a5)(InitializerContext*) {
    /**
     * Feature flag for enabling fault facet support.
     */
    [[maybe_unused]] auto* scp_0 = ([]() -> ServerParameter* {
        auto* ret = new FeatureFlagServerParameter("featureFlagHealthMonitoring", gFeatureFlagHealthMonitoring);
        return ret;
    })();

}
}  // namespace feature_flags
}  // namespace mongo
