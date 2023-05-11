/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/s/load_balancer_feature_flag_gen.h --output build/opt/mongo/s/load_balancer_feature_flag_gen.cpp src/mongo/s/load_balancer_feature_flag.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/s/load_balancer_feature_flag_gen.h"

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

::mongo::FeatureFlag gFeatureFlagLoadBalancer{false, ""_sd};
MONGO_SERVER_PARAMETER_REGISTER(idl_06623adbb017bdc98e21259360d54e7d42025327)(InitializerContext*) {
    /**
     * Feature flag for enabling L4 load balancer support.
     */
    [[maybe_unused]] auto* scp_0 = ([]() -> ServerParameter* {
        auto* ret = new FeatureFlagServerParameter("featureFlagLoadBalancer", gFeatureFlagLoadBalancer);
        return ret;
    })();

}
}  // namespace feature_flags
}  // namespace mongo
