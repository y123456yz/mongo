/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/rpc/rewrite_state_change_errors_server_parameter_gen.h --output build/opt/mongo/rpc/rewrite_state_change_errors_server_parameter_gen.cpp src/mongo/rpc/rewrite_state_change_errors_server_parameter.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/rpc/rewrite_state_change_errors_server_parameter_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"
#include "mongo/idl/server_parameter.h"
#include "mongo/idl/server_parameter_with_storage.h"

namespace mongo {
namespace rpc {

bool rewriteStateChangeErrors{true};
MONGO_SERVER_PARAMETER_REGISTER(idl_7b99b0c219a835a61e76ea40b4f6c99171205bac)(InitializerContext*) {
    /**
     * A failsafe to disable mongos state change error rewriting.
     */
    [[maybe_unused]] auto* scp_0 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("rewriteStateChangeErrors", rewriteStateChangeErrors);
        return ret;
    })();

}
}  // namespace rpc
}  // namespace mongo
