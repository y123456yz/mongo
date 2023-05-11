/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/transport/service_executor_gen.h --output build/opt/mongo/transport/service_executor_gen.cpp src/mongo/transport/service_executor.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/transport/service_executor_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"
#include "mongo/idl/server_parameter.h"
#include "mongo/idl/server_parameter_with_storage.h"

namespace mongo {
namespace transport {

std::string initialServiceExecutorThreadingModel{"dedicated"};
AtomicWord<int> synchronousServiceExecutorRecursionLimit{8};
AtomicWord<int> fixedServiceExecutorRecursionLimit{8};
AtomicWord<int> reservedServiceExecutorRecursionLimit{8};
int fixedServiceExecutorThreadLimit{1000};
MONGO_SERVER_PARAMETER_REGISTER(idl_7ffdacdacfd04bf86d553bc3bd3458d88773deb4)(InitializerContext*) {
    /**
     * Start new client connections using an executor that follows this model.
     */
    [[maybe_unused]] auto* scp_0 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("initialServiceExecutorThreadingModel", initialServiceExecutorThreadingModel);
        ret->setOnUpdate(ServiceExecutor::setInitialThreadingModelFromString);
        return ret;
    })();

    /**
     * Tasks may recurse further if their recursion depth is less than this value.
     */
    [[maybe_unused]] auto* scp_1 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("synchronousServiceExecutorRecursionLimit", synchronousServiceExecutorRecursionLimit);
        return ret;
    })();

    /**
     * Tasks may recurse further if their recursion depth is less than this value.
     */
    [[maybe_unused]] auto* scp_2 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("fixedServiceExecutorRecursionLimit", fixedServiceExecutorRecursionLimit);
        return ret;
    })();

    /**
     * Tasks may recurse further if their recursion depth is less than this value.
     */
    [[maybe_unused]] auto* scp_3 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("reservedServiceExecutorRecursionLimit", reservedServiceExecutorRecursionLimit);
        return ret;
    })();

    /**
     * The fixed service executor (thread model "borrowed") can only maintain a count of threads less than this value.
     */
    [[maybe_unused]] auto* scp_4 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("fixedServiceExecutorThreadLimit", fixedServiceExecutorThreadLimit);
        ret->addBound<idl_server_parameter_detail::GTE>(10);
        return ret;
    })();

}
}  // namespace transport
}  // namespace mongo
