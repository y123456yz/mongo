/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/ftdc/ftdc_mongod_gen.h --output build/opt/mongo/db/ftdc/ftdc_mongod_gen.cpp src/mongo/db/ftdc/ftdc_mongod.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/ftdc/ftdc_mongod_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"
#include "mongo/idl/server_parameter.h"
#include "mongo/idl/server_parameter_with_storage.h"

namespace mongo {

synchronized_value<std::vector<std::string>> gDiagnosticDataCollectionStatsNamespaces;
MONGO_SERVER_PARAMETER_REGISTER(idl_fc7ab24fb0262be54db2603100e694c0ca3dd9cd)(InitializerContext*) {
    /**
     * Specifies a comma-separated list of collections to collect metrics on
     */
    [[maybe_unused]] auto* scp_0 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("diagnosticDataCollectionStatsNamespaces", gDiagnosticDataCollectionStatsNamespaces);
        ret->addValidator(validateCollectionStatsNamespaces);
        return ret;
    })();

}
}  // namespace mongo
