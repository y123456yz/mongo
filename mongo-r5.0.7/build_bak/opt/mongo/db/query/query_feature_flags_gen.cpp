/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/query/query_feature_flags_gen.h --output build/opt/mongo/db/query/query_feature_flags_gen.cpp src/mongo/db/query/query_feature_flags.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/query/query_feature_flags_gen.h"

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

::mongo::FeatureFlag gFeatureFlagChangeStreamsOptimization{false, ""_sd};
::mongo::FeatureFlag gFeatureFlagDotsAndDollars{true, "5.0"_sd};
::mongo::FeatureFlag gFeatureFlagSearchMeta{true, "5.0"_sd};
::mongo::FeatureFlag gFeatureFlagShardedTimeSeries{true, "5.0"_sd};
::mongo::FeatureFlag gFeatureFlagShardedTimeSeriesUpdateDelete{true, "5.0"_sd};
MONGO_SERVER_PARAMETER_REGISTER(idl_ac82ba65741618f216ccc923d9000cb277603f26)(InitializerContext*) {
    /**
     * Feature flag for enabling change streams optimization
     */
    [[maybe_unused]] auto* scp_0 = ([]() -> ServerParameter* {
        auto* ret = new FeatureFlagServerParameter("featureFlagChangeStreamsOptimization", gFeatureFlagChangeStreamsOptimization);
        return ret;
    })();

    /**
     * Feature flag for allowing use of field names containing dots and dollars
     */
    [[maybe_unused]] auto* scp_1 = ([]() -> ServerParameter* {
        auto* ret = new FeatureFlagServerParameter("featureFlagDotsAndDollars", gFeatureFlagDotsAndDollars);
        return ret;
    })();

    /**
     * Feature flag for allowing use of search collectors alongside search results
     */
    [[maybe_unused]] auto* scp_2 = ([]() -> ServerParameter* {
        auto* ret = new FeatureFlagServerParameter("featureFlagSearchMeta", gFeatureFlagSearchMeta);
        return ret;
    })();

    /**
     * Feature flag for allowing sharding a Time Series collection
     */
    [[maybe_unused]] auto* scp_3 = ([]() -> ServerParameter* {
        auto* ret = new FeatureFlagServerParameter("featureFlagShardedTimeSeries", gFeatureFlagShardedTimeSeries);
        return ret;
    })();

    /**
     * Feature flag for allowing update and delete operations on a sharded Time Series collection
     */
    [[maybe_unused]] auto* scp_4 = ([]() -> ServerParameter* {
        auto* ret = new FeatureFlagServerParameter("featureFlagShardedTimeSeriesUpdateDelete", gFeatureFlagShardedTimeSeriesUpdateDelete);
        return ret;
    })();

}
}  // namespace feature_flags
}  // namespace mongo
