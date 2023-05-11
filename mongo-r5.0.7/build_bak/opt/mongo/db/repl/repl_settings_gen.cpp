/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/repl/repl_settings_gen.h --output build/opt/mongo/db/repl/repl_settings_gen.cpp src/mongo/db/repl/repl_settings.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/repl/repl_settings_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"
#include "mongo/idl/server_parameter.h"
#include "mongo/idl/server_parameter_with_storage.h"

namespace mongo {
namespace repl {

bool recoverFromOplogAsStandalone{false};
int maxSyncSourceLagSecs{30};
double replElectionTimeoutOffsetLimitFraction{0.15};
MONGO_SERVER_PARAMETER_REGISTER(idl_905720127adf85022538db8bcccbdd80953abffe)(InitializerContext*) {
    /**
     * Tells the server to perform replication recovery as a standalone.
     */
    [[maybe_unused]] auto* scp_0 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("recoverFromOplogAsStandalone", recoverFromOplogAsStandalone);
        return ret;
    })();

    /**
     * 
     */
    [[maybe_unused]] auto* scp_1 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("maxSyncSourceLagSecs", maxSyncSourceLagSecs);
        ret->addBound<idl_server_parameter_detail::GT>(0);
        return ret;
    })();

    /**
     * 
     */
    [[maybe_unused]] auto* scp_2 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("replElectionTimeoutOffsetLimitFraction", replElectionTimeoutOffsetLimitFraction);
        ret->addBound<idl_server_parameter_detail::GT>(0.01);
        return ret;
    })();

}
}  // namespace repl
}  // namespace mongo
