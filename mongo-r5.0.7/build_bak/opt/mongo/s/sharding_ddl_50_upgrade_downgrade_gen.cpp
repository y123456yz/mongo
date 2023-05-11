/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/s/sharding_ddl_50_upgrade_downgrade_gen.h --output build/opt/mongo/s/sharding_ddl_50_upgrade_downgrade_gen.cpp src/mongo/s/sharding_ddl_50_upgrade_downgrade.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/s/sharding_ddl_50_upgrade_downgrade_gen.h"

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

::mongo::FeatureFlag gShardingFullDDLSupport{true, "5.0"_sd};
MONGO_SERVER_PARAMETER_REGISTER(idl_d3d1cad2d93c0cc3f30f5cd9c0e0b2fd10f81c30)(InitializerContext*) {
    /**
     * Ensures extra guarantees on DDL operations under a sharded cluster.
     */
    [[maybe_unused]] auto* scp_0 = ([]() -> ServerParameter* {
        auto* ret = new FeatureFlagServerParameter("featureFlagShardingFullDDLSupport", gShardingFullDDLSupport);
        return ret;
    })();

}
}  // namespace feature_flags
}  // namespace mongo
