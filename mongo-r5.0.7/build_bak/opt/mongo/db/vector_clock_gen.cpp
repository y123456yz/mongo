/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/vector_clock_gen.h --output build/opt/mongo/db/vector_clock_gen.cpp src/mongo/db/vector_clock.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/vector_clock_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"
#include "mongo/idl/server_parameter.h"
#include "mongo/idl/server_parameter_with_storage.h"

namespace mongo {

long long gMaxAcceptableLogicalClockDriftSecs{(365 * 24 * 60 * 60)};
MONGO_SERVER_PARAMETER_REGISTER(idl_bda08f8f69324604d2317d5735268010ad25a653)(InitializerContext*) {
    /**
     * The value defines the maximum time, in seconds, that a new logical time (such as $clusterTime) may be ahead of the node's current wallclock time. Default value is 1 year.
     */
    [[maybe_unused]] auto* scp_0 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("maxAcceptableLogicalClockDriftSecs", gMaxAcceptableLogicalClockDriftSecs);
        ret->addBound<idl_server_parameter_detail::GT>(0);
        return ret;
    })();

}
}  // namespace mongo
