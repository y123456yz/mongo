/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/rpc/deprecated_wire_ops_gen.h --output build/opt/mongo/rpc/deprecated_wire_ops_gen.cpp src/mongo/rpc/deprecated_wire_ops.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/rpc/deprecated_wire_ops_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"
#include "mongo/idl/server_parameter.h"
#include "mongo/idl/server_parameter_with_storage.h"

namespace mongo {

AtomicWord<int> deprecatedWireOpsWarningPeriodInSeconds{3600};
MONGO_SERVER_PARAMETER_REGISTER(idl_1dd27471492d04bf27fcea0ae36227a340fb5f81)(InitializerContext*) {
    /**
     * The period in which the server logs a warning message for deprecated op codes and getLastError command. The server logs a warning message only once per each client in this period irrespective of how many such requests have been received. Such requests include OP_QUERY, OP_GET_MORE, OP_KILL_CURSORS, OP_INSERT, OP_UPDATE, OP_DELETE op codes and getLastError command.
     */
    [[maybe_unused]] auto* scp_0 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("deprecatedWireOpsWarningPeriodInSeconds", deprecatedWireOpsWarningPeriodInSeconds);
        ret->addBound<idl_server_parameter_detail::GTE>(0);
        return ret;
    })();

}
}  // namespace mongo
