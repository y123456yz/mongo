/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/timeseries/timeseries_gen.h --output build/opt/mongo/db/timeseries/timeseries_gen.cpp src/mongo/db/timeseries/timeseries.idl
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
#include "mongo/db/timeseries/timeseries_global_options.h"
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

/**
 * Describes a time-series collection's expected interval between subsequent measurements
 */
enum class BucketGranularityEnum : std::int32_t {
    Seconds ,
    Minutes ,
    Hours ,
};
static constexpr uint32_t kNumBucketGranularityEnum = 3;

BucketGranularityEnum BucketGranularity_parse(const IDLParserErrorContext& ctxt, StringData value);
StringData BucketGranularity_serializer(BucketGranularityEnum value);

/**
 * The options that define a time-series collection.
 */
class TimeseriesOptions {
public:
    static constexpr auto kBucketMaxSpanSecondsFieldName = "bucketMaxSpanSeconds"_sd;
    static constexpr auto kGranularityFieldName = "granularity"_sd;
    static constexpr auto kMetaFieldFieldName = "metaField"_sd;
    static constexpr auto kTimeFieldFieldName = "timeField"_sd;

    TimeseriesOptions();
    TimeseriesOptions(std::string timeField);

    static TimeseriesOptions parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * The name of the top-level field to be used for time. Inserted documents must have this field, and the field must be of the BSON UTC datetime type (0x9)
     */
    const StringData getTimeField() const& { return _timeField; }
    void getTimeField() && = delete;
    void setTimeField(StringData value) & { auto _tmpValue = value.toString();  _timeField = std::move(_tmpValue); _hasTimeField = true; }

    /**
     * The name of the top-level field describing the series. This field is used to group related data and may be of any BSON type. This may not be "_id" or the same as 'timeField'.
     */
    const boost::optional<StringData> getMetaField() const& { return boost::optional<StringData>{_metaField}; }
    void getMetaField() && = delete;
    void setMetaField(boost::optional<StringData> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get().toString();
        
        _metaField = std::move(_tmpValue);
    } else {
        _metaField = boost::none;
    }
      }

    /**
     * Describes the expected interval between subsequent measurements
     */
    mongo::BucketGranularityEnum getGranularity() const { return _granularity; }
    void setGranularity(mongo::BucketGranularityEnum value) & {  _granularity = std::move(value);  }

    /**
     * The maximum range of time values for a bucket, in seconds
     */
    const boost::optional<std::int32_t> getBucketMaxSpanSeconds() const& { return _bucketMaxSpanSeconds; }
    void getBucketMaxSpanSeconds() && = delete;
    void setBucketMaxSpanSeconds(boost::optional<std::int32_t> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get();
        validateBucketMaxSpanSeconds(_tmpValue);
        _bucketMaxSpanSeconds = std::move(_tmpValue);
    } else {
        _bucketMaxSpanSeconds = boost::none;
    }
      }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    void validateBucketMaxSpanSeconds(const std::int32_t value);
    void validateBucketMaxSpanSeconds(IDLParserErrorContext& ctxt, const std::int32_t value);

private:
    std::string _timeField;
    boost::optional<std::string> _metaField;
    mongo::BucketGranularityEnum _granularity{mongo::BucketGranularityEnum::Seconds};
    boost::optional<std::int32_t> _bucketMaxSpanSeconds;
    bool _hasTimeField : 1;
};

constexpr auto kTimeseriesBucketMaxCountDefault = 1000;

extern std::int32_t gTimeseriesBucketMaxCount;
constexpr auto kTimeseriesBucketMaxSizeDefault = 128000;

extern std::int32_t gTimeseriesBucketMaxSize;
constexpr auto kTimeseriesBucketsCollectionClusterByIdDefault = true;

extern bool gTimeseriesBucketsCollectionClusterById;
}  // namespace mongo
