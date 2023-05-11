/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/catalog/validate_gen.h --output build/opt/mongo/db/catalog/validate_gen.cpp src/mongo/db/catalog/validate.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/catalog/validate_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"
#include "mongo/idl/server_parameter.h"
#include "mongo/idl/server_parameter_with_storage.h"

namespace mongo {

AtomicWord<int> gMaxValidateMBperSec{0};
AtomicWord<int> maxValidateMemoryUsageMB{200};
MONGO_SERVER_PARAMETER_REGISTER(idl_497fbe89db87f6e83eae9d304fa6ab70bf770914)(InitializerContext*) {
    /**
     * Max MB per second that a single validate command running with { background: true } will process in order to limit I/O and CPU usage. Defaults to 0, which turns off throttling.
     */
    [[maybe_unused]] auto* scp_0 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("maxValidateMBperSec", gMaxValidateMBperSec);
        ret->addBound<idl_server_parameter_detail::GTE>(0);
        return ret;
    })();

    /**
     * Limits the amount of memory that a single validate command will use.
     */
    [[maybe_unused]] auto* scp_1 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("maxValidateMemoryUsageMB", maxValidateMemoryUsageMB);
        ret->addBound<idl_server_parameter_detail::GT>(0);
        return ret;
    })();

}
}  // namespace mongo
