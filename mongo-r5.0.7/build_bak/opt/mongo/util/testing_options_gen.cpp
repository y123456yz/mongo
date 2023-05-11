/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/util/testing_options_gen.h --output build/opt/mongo/util/testing_options_gen.cpp src/mongo/util/testing_options.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/util/testing_options_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"
#include "mongo/idl/server_parameter.h"
#include "mongo/idl/server_parameter_with_storage.h"

namespace mongo {

bool gTestingDiagnosticsEnabledAtStartup{false};
MONGO_SERVER_PARAMETER_REGISTER(idl_46248b5e8c87b6cf9c488586ed731c6d6dddb49f)(InitializerContext*) {
    /**
     * Start with test-only diagnostic behavior enabled
     */
    [[maybe_unused]] auto* scp_0 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("testingDiagnosticsEnabled", gTestingDiagnosticsEnabledAtStartup);
        return ret;
    })();

}
}  // namespace mongo
