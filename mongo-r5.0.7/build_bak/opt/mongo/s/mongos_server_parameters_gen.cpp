/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/s/mongos_server_parameters_gen.h --output build/opt/mongo/s/mongos_server_parameters_gen.cpp src/mongo/s/mongos_server_parameters.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/s/mongos_server_parameters_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"
#include "mongo/idl/server_parameter.h"
#include "mongo/idl/server_parameter_with_storage.h"

namespace mongo {

/**
 * readHedgingMode: Enables hedged reads.
 */
Status HedgingModeServerParameter::set(const BSONElement& newValueElement) {
    auto swValue = coerceToString(newValueElement, false);
    if (!swValue.isOK()) {
        return swValue.getStatus();
    }
    return setFromString(swValue.getValue());
}

AtomicWord<int> gMaxTimeMSForHedgedReads{150};
AtomicWord<int> mongosShutdownTimeoutMillisForSignaledShutdown{15000};
AtomicWord<int> loadBalancerPort{0};
MONGO_SERVER_PARAMETER_REGISTER(idl_509541ad8d8ee10b0466f3f7708c64a1309b5620)(InitializerContext*) {
    /**
     * Enables hedged reads.
     */
    [[maybe_unused]] auto* scp_0 = ([]() -> ServerParameter* {
        return new HedgingModeServerParameter("readHedgingMode", ServerParameterType::kStartupAndRuntime);
    })();

    /**
     * The maxTimeMS to set on hedged reads.
     */
    [[maybe_unused]] auto* scp_1 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("maxTimeMSForHedgedReads", gMaxTimeMSForHedgedReads);
        ret->addBound<idl_server_parameter_detail::GTE>(0);
        return ret;
    })();

    /**
     * The time taken for quiesce mode at shutdown in response to SIGTERM.
     */
    [[maybe_unused]] auto* scp_2 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("mongosShutdownTimeoutMillisForSignaledShutdown", mongosShutdownTimeoutMillisForSignaledShutdown);
        ret->addBound<idl_server_parameter_detail::GTE>(0);
        return ret;
    })();

    /**
     * The port over which proxied connections using the Proxy Protocol may be made. A value of 0 disables the port entirely.
     */
    [[maybe_unused]] auto* scp_3 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("loadBalancerPort", loadBalancerPort);
        ret->addBound<idl_server_parameter_detail::LTE>(65535);
        ret->addBound<idl_server_parameter_detail::GTE>(0);
        return ret;
    })();

}
}  // namespace mongo
