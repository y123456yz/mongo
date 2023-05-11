/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/idl/feature_flag_test_gen.h --output build/opt/mongo/idl/feature_flag_test_gen.cpp src/mongo/idl/feature_flag_test.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/idl/feature_flag_test_gen.h"

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

::mongo::FeatureFlag gFeatureFlagToaster{false, ""_sd};
::mongo::FeatureFlag gFeatureFlagFryer{false, ""_sd};
::mongo::FeatureFlag gFeatureFlagBlender{true, "4.9"_sd};
::mongo::FeatureFlag gFeatureFlagSpoon{true, "4.4"_sd};
MONGO_SERVER_PARAMETER_REGISTER(idl_76b234f56345c10756ef64af1e65d89e61470241)(InitializerContext*) {
    /**
     * Create a feature flag
     */
    [[maybe_unused]] auto* scp_0 = ([]() -> ServerParameter* {
        auto* ret = new FeatureFlagServerParameter("featureFlagToaster", gFeatureFlagToaster);
        return ret;
    })();

    /**
     * Create a feature flag
     */
    [[maybe_unused]] auto* scp_1 = ([]() -> ServerParameter* {
        auto* ret = new FeatureFlagServerParameter("featureFlagFryer", gFeatureFlagFryer);
        return ret;
    })();

    /**
     * Create a feature flag
     */
    [[maybe_unused]] auto* scp_2 = ([]() -> ServerParameter* {
        auto* ret = new FeatureFlagServerParameter("featureFlagBlender", gFeatureFlagBlender);
        return ret;
    })();

    /**
     * Create a feature flag
     */
    [[maybe_unused]] auto* scp_3 = ([]() -> ServerParameter* {
        auto* ret = new FeatureFlagServerParameter("featureFlagSpoon", gFeatureFlagSpoon);
        return ret;
    })();

}
}  // namespace feature_flags
}  // namespace mongo
