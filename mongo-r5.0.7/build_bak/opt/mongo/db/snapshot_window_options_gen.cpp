/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/snapshot_window_options_gen.h --output build/opt/mongo/db/snapshot_window_options_gen.cpp src/mongo/db/snapshot_window_options.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/snapshot_window_options_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"
#include "mongo/idl/server_parameter.h"
#include "mongo/idl/server_parameter_with_storage.h"

namespace mongo {

AtomicWord<int> minSnapshotHistoryWindowInSeconds{300};
MONGO_SERVER_PARAMETER_REGISTER(idl_9f9852bf8c7821940266b14ab747993125c57886)(InitializerContext*) {
    /**
     * Minimum snapshot history to keep, in seconds
     */
    [[maybe_unused]] auto* scp_0 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("minSnapshotHistoryWindowInSeconds", minSnapshotHistoryWindowInSeconds);
        ret->addBound<idl_server_parameter_detail::GTE>(0);
        return ret;
    })();

}
}  // namespace mongo
