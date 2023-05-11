/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/storage/two_phase_index_build_knobs_gen.h --output build/opt/mongo/db/storage/two_phase_index_build_knobs_gen.cpp src/mongo/db/storage/two_phase_index_build_knobs.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/storage/two_phase_index_build_knobs_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"
#include "mongo/idl/server_parameter.h"
#include "mongo/idl/server_parameter_with_storage.h"

namespace mongo {

bool enableIndexBuildCommitQuorum{true};
AtomicWord<int> maxNumActiveUserIndexBuilds{3};
long long gResumableIndexBuildMajorityOpTimeTimeoutMillis{10000};
bool enableResumableIndexBuilds{true};
MONGO_SERVER_PARAMETER_REGISTER(idl_edbde56ebd1a3db93d5d64bef5d4cdde6c045577)(InitializerContext*) {
    /**
     * Support for using commit quorum for two phase index builds.
     */
    [[maybe_unused]] auto* scp_0 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("enableIndexBuildCommitQuorum", enableIndexBuildCommitQuorum);
        return ret;
    })();

            /**
             * Specifies the maximum number of active user index builds that can be built simultaneously on the primary node. Index builds initiated by the system are not subject to this limitation.
    Additionally, active index builds initiated by the system count towards the limit and can delay scheduling user index builds even when the number of active user index builds is below the limit.
    
             */
    [[maybe_unused]] auto* scp_1 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("maxNumActiveUserIndexBuilds", maxNumActiveUserIndexBuilds);
        ret->addBound<idl_server_parameter_detail::GTE>(0);
        return ret;
    })();

    /**
     * Time in milliseconds a node waits for the last optime before installing the interceptors to be majority committed for a resumable index build. Once the interceptors are installed, the index build process will start the collection scan phase. If the majority commit point is not reached by the end of this waiting period, the index build will proceed as a non-resumable index build. Set to 0 to skip the wait. This will also disable resumable index builds. Set to a negative value to wait indefinitely for the majority commit point.
    
     */
    [[maybe_unused]] auto* scp_2 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("resumableIndexBuildMajorityOpTimeTimeoutMillis", gResumableIndexBuildMajorityOpTimeTimeoutMillis);
        return ret;
    })();

    /**
     * Support for using resumable index builds.
     */
    [[maybe_unused]] auto* scp_3 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("enableResumableIndexBuilds", enableResumableIndexBuilds);
        return ret;
    })();

}
}  // namespace mongo
