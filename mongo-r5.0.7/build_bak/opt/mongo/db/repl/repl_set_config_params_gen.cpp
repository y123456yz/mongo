/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/repl/repl_set_config_params_gen.h --output build/opt/mongo/db/repl/repl_set_config_params_gen.cpp src/mongo/db/repl/repl_set_config_params.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/repl/repl_set_config_params_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"
#include "mongo/idl/server_parameter.h"
#include "mongo/idl/server_parameter_with_storage.h"

namespace mongo {

bool skipShardingConfigurationChecks{false};
MONGO_SERVER_PARAMETER_REGISTER(idl_e0f54d7a5f088b5faca930c7254fa374729c3933)(InitializerContext*) {
    /**
     * Dont run any sharding validations. Can not be combined with --configsvr or shardvr. Intended to allow restarting config server or shard as an independent replica set.
     */
    [[maybe_unused]] auto* scp_0 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("skipShardingConfigurationChecks", skipShardingConfigurationChecks);
        return ret;
    })();

}
}  // namespace mongo
