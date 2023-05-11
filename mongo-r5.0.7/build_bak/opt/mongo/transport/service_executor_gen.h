/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/transport/service_executor_gen.h --output build/opt/mongo/transport/service_executor_gen.cpp src/mongo/transport/service_executor.idl
 */

#pragma once

#include <algorithm>
#include <boost/optional.hpp>
#include <cstdint>
#include <string>
#include <tuple>
#include <vector>

#include "mongo/base/data_range.h"
#include "mongo/base/string_data.h"
#include "mongo/bson/bsonobj.h"
#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/bson/simple_bsonobj_comparator.h"
#include "mongo/idl/idl_parser.h"
#include "mongo/idl/server_parameter.h"
#include "mongo/idl/server_parameter_with_storage.h"
#include "mongo/rpc/op_msg.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/transport/service_executor.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {
namespace transport {

constexpr auto kInitialServiceExecutorThreadingModelDefault = "dedicated";

extern std::string initialServiceExecutorThreadingModel;
constexpr auto kSynchronousServiceExecutorRecursionLimitDefault = 8;

extern AtomicWord<int> synchronousServiceExecutorRecursionLimit;
constexpr auto kFixedServiceExecutorRecursionLimitDefault = 8;

extern AtomicWord<int> fixedServiceExecutorRecursionLimit;
constexpr auto kReservedServiceExecutorRecursionLimitDefault = 8;

extern AtomicWord<int> reservedServiceExecutorRecursionLimit;
constexpr auto kFixedServiceExecutorThreadLimitDefault = 1000;

extern int fixedServiceExecutorThreadLimit;
}  // namespace transport
}  // namespace mongo
