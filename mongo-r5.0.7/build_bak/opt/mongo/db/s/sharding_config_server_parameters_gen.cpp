/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/s/sharding_config_server_parameters_gen.h --output build/opt/mongo/db/s/sharding_config_server_parameters_gen.cpp src/mongo/db/s/sharding_config_server_parameters.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/s/sharding_config_server_parameters_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"
#include "mongo/idl/server_parameter.h"
#include "mongo/idl/server_parameter_with_storage.h"

namespace mongo {

AtomicWord<int32_t> minNumChunksForSessionsCollection{1024};
MONGO_SERVER_PARAMETER_REGISTER(idl_8f2675647ba93a985ebc2d830341d8c6f4f98dcd)(InitializerContext*) {
    /**
     * The minimum number of chunks for config.system.sessions collection
     */
    [[maybe_unused]] auto* scp_0 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("minNumChunksForSessionsCollection", minNumChunksForSessionsCollection);
        ret->addBound<idl_server_parameter_detail::LTE>(1000000);
        ret->addBound<idl_server_parameter_detail::GTE>(1);
        return ret;
    })();

}
}  // namespace mongo
