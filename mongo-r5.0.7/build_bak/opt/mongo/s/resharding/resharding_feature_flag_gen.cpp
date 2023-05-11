/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/s/resharding/resharding_feature_flag_gen.h --output build/opt/mongo/s/resharding/resharding_feature_flag_gen.cpp src/mongo/s/resharding/resharding_feature_flag.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/s/resharding/resharding_feature_flag_gen.h"

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

::mongo::FeatureFlag gFeatureFlagResharding{true, "5.0"_sd};
MONGO_SERVER_PARAMETER_REGISTER(idl_2054d7cfd4aa3a4791c9a7730ebad618e5fa3849)(InitializerContext*) {
    /**
     * When enabled, allows users to reshard their sharded collections.
     */
    [[maybe_unused]] auto* scp_0 = ([]() -> ServerParameter* {
        auto* ret = new FeatureFlagServerParameter("featureFlagResharding", gFeatureFlagResharding);
        return ret;
    })();

}
}  // namespace resharding
}  // namespace mongo
