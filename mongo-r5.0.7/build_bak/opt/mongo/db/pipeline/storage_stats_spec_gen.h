/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/pipeline/storage_stats_spec_gen.h --output build/opt/mongo/db/pipeline/storage_stats_spec_gen.cpp src/mongo/db/pipeline/storage_stats_spec.idl
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
 * Represents the 'storageStats' argument to the $collStats stage.
 */
class StorageStatsSpec {
public:
    static constexpr auto kScaleFieldName = "scale"_sd;
    static constexpr auto kVerboseFieldName = "verbose"_sd;
    static constexpr auto kWaitForLockFieldName = "waitForLock"_sd;

    StorageStatsSpec();

    static StorageStatsSpec parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * A number to use as a scaling factor applied to reported metrics.
     */
    const boost::optional<std::int32_t> getScale() const& { return _scale; }
    void getScale() && = delete;
    void setScale(boost::optional<std::int32_t> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get();
        validateScale(_tmpValue);
        _scale = std::move(_tmpValue);
    } else {
        _scale = boost::none;
    }
      }

    const mongo::OptionalBool& getVerbose() const { return _verbose; }
    void setVerbose(mongo::OptionalBool value) & {  _verbose = std::move(value);  }

    const mongo::OptionalBool& getWaitForLock() const { return _waitForLock; }
    void setWaitForLock(mongo::OptionalBool value) & {  _waitForLock = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    void validateScale(const std::int32_t value);
    void validateScale(IDLParserErrorContext& ctxt, const std::int32_t value);

private:
    boost::optional<std::int32_t> _scale;
    mongo::OptionalBool _verbose{false};
    mongo::OptionalBool _waitForLock{true};
};

}  // namespace mongo
