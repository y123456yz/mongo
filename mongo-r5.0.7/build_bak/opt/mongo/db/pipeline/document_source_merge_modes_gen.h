/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/pipeline/document_source_merge_modes_gen.h --output build/opt/mongo/db/pipeline/document_source_merge_modes_gen.cpp src/mongo/db/pipeline/document_source_merge_modes.idl
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
#include "mongo/rpc/op_msg.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/util/uuid.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {

/**
 * Possible merge mode values for $merge's 'whenMatched' field.
 */
enum class MergeWhenMatchedModeEnum : std::int32_t {
    kFail ,
    kKeepExisting ,
    kMerge ,
    kPipeline ,
    kReplace ,
};
static constexpr uint32_t kNumMergeWhenMatchedModeEnum = 5;

MergeWhenMatchedModeEnum MergeWhenMatchedMode_parse(const IDLParserErrorContext& ctxt, StringData value);
StringData MergeWhenMatchedMode_serializer(MergeWhenMatchedModeEnum value);

/**
 * Possible merge mode values for $merge's 'whenNotMatched'. field
 */
enum class MergeWhenNotMatchedModeEnum : std::int32_t {
    kDiscard ,
    kFail ,
    kInsert ,
};
static constexpr uint32_t kNumMergeWhenNotMatchedModeEnum = 3;

MergeWhenNotMatchedModeEnum MergeWhenNotMatchedMode_parse(const IDLParserErrorContext& ctxt, StringData value);
StringData MergeWhenNotMatchedMode_serializer(MergeWhenNotMatchedModeEnum value);

}  // namespace mongo
