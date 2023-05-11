/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/s/resharding/resharding_server_parameters_gen.h --output build/opt/mongo/db/s/resharding/resharding_server_parameters_gen.cpp src/mongo/db/s/resharding/resharding_server_parameters.idl
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
#include "mongo/db/namespace_string.h"
#include "mongo/idl/basic_types.h"
#include "mongo/idl/basic_types_gen.h"
#include "mongo/idl/idl_parser.h"
#include "mongo/idl/server_parameter.h"
#include "mongo/idl/server_parameter_with_storage.h"
#include "mongo/rpc/op_msg.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/util/uuid.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {
namespace resharding {

constexpr auto kReshardingCoordinatorServiceMaxThreadCountDefault = 3;

extern int gReshardingCoordinatorServiceMaxThreadCount;
constexpr auto kReshardingDonorServiceMaxThreadCountDefault = 2;

extern int gReshardingDonorServiceMaxThreadCount;
constexpr auto kReshardingRecipientServiceMaxThreadCountDefault = 8;

extern int gReshardingRecipientServiceMaxThreadCount;
constexpr auto kReshardingCollectionClonerBatchSizeInBytesDefault = 100 * 1024;

extern AtomicWord<int> gReshardingCollectionClonerBatchSizeInBytes;
constexpr auto kReshardingTxnClonerProgressBatchSizeDefault = 1000;

extern AtomicWord<int> gReshardingTxnClonerProgressBatchSize;
extern AtomicWord<int> gReshardingOplogBatchTaskCount;
constexpr auto kReshardingOplogBatchLimitOperationsDefault = 5 * 1000;

extern AtomicWord<int> gReshardingOplogBatchLimitOperations;
constexpr auto kReshardingOplogBatchLimitBytesDefault = 100 * 1024 * 1024;

extern AtomicWord<int> gReshardingOplogBatchLimitBytes;
constexpr auto kReshardingOplogApplierMaxLockRequestTimeoutMillisDefault = 5;

extern AtomicWord<int> gReshardingOplogApplierMaxLockRequestTimeoutMillis;
constexpr auto kReshardingMinimumOperationDurationMillisDefault = 5 * 60 * 1000;

extern AtomicWord<int> gReshardingMinimumOperationDurationMillis;
constexpr auto kReshardingCriticalSectionTimeoutMillisDefault = 5 * 1000;

extern AtomicWord<int> gReshardingCriticalSectionTimeoutMillis;
constexpr auto kRemainingReshardingOperationTimeThresholdMillisDefault = 2 * 1000;

extern AtomicWord<int> gRemainingReshardingOperationTimeThresholdMillis;
}  // namespace resharding
}  // namespace mongo
