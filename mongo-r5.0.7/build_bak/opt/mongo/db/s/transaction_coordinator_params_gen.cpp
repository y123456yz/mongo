/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/s/transaction_coordinator_params_gen.h --output build/opt/mongo/db/s/transaction_coordinator_params_gen.cpp src/mongo/db/s/transaction_coordinator_params.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/s/transaction_coordinator_params_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"
#include "mongo/idl/server_parameter.h"
#include "mongo/idl/server_parameter_with_storage.h"

namespace mongo {

AtomicWord<bool> coordinateCommitReturnImmediatelyAfterPersistingDecision{true};
MONGO_SERVER_PARAMETER_REGISTER(idl_b5c09511d48a083f6c7b766cc79f39efb1dc982f)(InitializerContext*) {
    /**
     * Whether the transaction coordinator should return the decision as soon as the the decision is made durable.
     */
    [[maybe_unused]] auto* scp_0 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("coordinateCommitReturnImmediatelyAfterPersistingDecision", coordinateCommitReturnImmediatelyAfterPersistingDecision);
        return ret;
    })();

}
}  // namespace mongo
