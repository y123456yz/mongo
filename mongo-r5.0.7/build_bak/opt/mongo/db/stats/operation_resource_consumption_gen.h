/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/stats/operation_resource_consumption_gen.h --output build/opt/mongo/db/stats/operation_resource_consumption_gen.cpp src/mongo/db/stats/operation_resource_consumption.idl
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

namespace mongo { class AuthorizationContract; }

namespace mongo {

constexpr auto kAggregateOperationResourceConsumptionMetricsDefault = false;

extern bool gAggregateOperationResourceConsumptionMetrics;
constexpr auto kProfileOperationResourceConsumptionMetricsDefault = false;

extern bool gProfileOperationResourceConsumptionMetrics;
constexpr auto kDocumentUnitSizeBytesDefault = 128;

extern int32_t gDocumentUnitSizeBytes;
constexpr auto kIndexEntryUnitSizeBytesDefault = 16;

extern int32_t gIndexEntryUnitSizeBytes;
constexpr auto kTotalUnitWriteSizeBytesDefault = 128;

extern int32_t gTotalUnitWriteSizeBytes;
}  // namespace mongo
