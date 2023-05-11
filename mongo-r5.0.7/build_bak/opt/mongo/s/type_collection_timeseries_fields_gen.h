/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/s/type_collection_timeseries_fields_gen.h --output build/opt/mongo/s/type_collection_timeseries_fields_gen.cpp src/mongo/s/type_collection_timeseries_fields.idl
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
#include "mongo/db/timeseries/timeseries_gen.h"
#include "mongo/db/timeseries/timeseries_global_options.h"
#include "mongo/idl/basic_types.h"
#include "mongo/idl/basic_types_gen.h"
#include "mongo/idl/idl_parser.h"
#include "mongo/rpc/op_msg.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/util/uuid.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {

/**
 * Fields for time-series buckets collection fields in config.collections.
 */
class TypeCollectionTimeseriesFields {
public:
    static constexpr auto kTimeseriesOptionsFieldName = "TimeseriesOptions"_sd;
    static constexpr auto kBucketMaxSpanSecondsFieldName = "bucketMaxSpanSeconds"_sd;
    static constexpr auto kGranularityFieldName = "granularity"_sd;
    static constexpr auto kMetaFieldFieldName = "metaField"_sd;
    static constexpr auto kTimeFieldFieldName = "timeField"_sd;

    TypeCollectionTimeseriesFields();

    static TypeCollectionTimeseriesFields parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * The options that define a time-series collection.
     */
    const mongo::TimeseriesOptions& getTimeseriesOptions() const { return _timeseriesOptions; }
    mongo::TimeseriesOptions& getTimeseriesOptions() { return _timeseriesOptions; }
    void setTimeseriesOptions(mongo::TimeseriesOptions value) & {  _timeseriesOptions = std::move(value);  }

    /**
     * The name of the top-level field to be used for time. Inserted documents must have this field, and the field must be of the BSON UTC datetime type (0x9)
     */
    const  StringData getTimeField() const { return _timeseriesOptions.getTimeField(); }
    /**
     * The name of the top-level field describing the series. This field is used to group related data and may be of any BSON type. This may not be "_id" or the same as 'timeField'.
     */
    const  boost::optional<StringData> getMetaField() const { return _timeseriesOptions.getMetaField(); }
    /**
     * Describes the expected interval between subsequent measurements
     */
     mongo::BucketGranularityEnum getGranularity() const { return _timeseriesOptions.getGranularity(); }
    /**
     * The maximum range of time values for a bucket, in seconds
     */
    const  boost::optional<std::int32_t> getBucketMaxSpanSeconds() const { return _timeseriesOptions.getBucketMaxSpanSeconds(); }
protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    void validateBucketMaxSpanSeconds(const std::int32_t value);
    void validateBucketMaxSpanSeconds(IDLParserErrorContext& ctxt, const std::int32_t value);

private:
    mongo::TimeseriesOptions _timeseriesOptions;
};

}  // namespace mongo
