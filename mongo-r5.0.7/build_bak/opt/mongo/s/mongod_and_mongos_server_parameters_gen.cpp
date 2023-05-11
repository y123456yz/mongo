/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/s/mongod_and_mongos_server_parameters_gen.h --output build/opt/mongo/s/mongod_and_mongos_server_parameters_gen.cpp src/mongo/s/mongod_and_mongos_server_parameters.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/s/mongod_and_mongos_server_parameters_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"
#include "mongo/idl/server_parameter.h"
#include "mongo/idl/server_parameter_with_storage.h"

namespace mongo {

bool gLoadRoutingTableOnStartup{true};
bool gWarmMinConnectionsInShardingTaskExecutorPoolOnStartup{true};
int gWarmMinConnectionsInShardingTaskExecutorPoolOnStartupWaitMS{2000};
bool gEnableFinerGrainedCatalogCacheRefresh{false};
MONGO_SERVER_PARAMETER_REGISTER(idl_eb870057f566484ce320ec7a7c6ceca985f01a82)(InitializerContext*) {
    /**
     * Enables precaching of the mongos routing table on startup.
     */
    [[maybe_unused]] auto* scp_0 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("loadRoutingTableOnStartup", gLoadRoutingTableOnStartup);
        return ret;
    })();

    /**
     * Enables prewarming of the connection pool.
     */
    [[maybe_unused]] auto* scp_1 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("warmMinConnectionsInShardingTaskExecutorPoolOnStartup", gWarmMinConnectionsInShardingTaskExecutorPoolOnStartup);
        return ret;
    })();

    /**
     * How long to wait for all hosts to have at least one connection.
     */
    [[maybe_unused]] auto* scp_2 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("warmMinConnectionsInShardingTaskExecutorPoolOnStartupWaitMS", gWarmMinConnectionsInShardingTaskExecutorPoolOnStartupWaitMS);
        ret->addBound<idl_server_parameter_detail::GTE>(0);
        return ret;
    })();

    /**
     * Enables the finer grained catalog cache refresh behavior.
     */
    [[maybe_unused]] auto* scp_3 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("enableFinerGrainedCatalogCacheRefresh", gEnableFinerGrainedCatalogCacheRefresh);
        return ret;
    })();

}
}  // namespace mongo
