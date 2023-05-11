/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/timeseries/timeseries_gen.h --output build/opt/mongo/db/timeseries/timeseries_gen.cpp src/mongo/db/timeseries/timeseries.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/timeseries/timeseries_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"
#include "mongo/idl/server_parameter.h"
#include "mongo/idl/server_parameter_with_storage.h"

namespace mongo {

/**
 * Describes a time-series collection's expected interval between subsequent measurements
 */
namespace  {
constexpr StringData kBucketGranularity_Seconds = "seconds"_sd;
constexpr StringData kBucketGranularity_Minutes = "minutes"_sd;
constexpr StringData kBucketGranularity_Hours = "hours"_sd;
}  // namespace 

BucketGranularityEnum BucketGranularity_parse(const IDLParserErrorContext& ctxt, StringData value) {
    if (value == kBucketGranularity_Seconds) {
        return BucketGranularityEnum::Seconds;
    }
    if (value == kBucketGranularity_Minutes) {
        return BucketGranularityEnum::Minutes;
    }
    if (value == kBucketGranularity_Hours) {
        return BucketGranularityEnum::Hours;
    }
    ctxt.throwBadEnumValue(value);
}

StringData BucketGranularity_serializer(BucketGranularityEnum value) {
    if (value == BucketGranularityEnum::Seconds) {
        return kBucketGranularity_Seconds;
    }
    if (value == BucketGranularityEnum::Minutes) {
        return kBucketGranularity_Minutes;
    }
    if (value == BucketGranularityEnum::Hours) {
        return kBucketGranularity_Hours;
    }
    MONGO_UNREACHABLE;
    return StringData();
}

constexpr StringData TimeseriesOptions::kBucketMaxSpanSecondsFieldName;
constexpr StringData TimeseriesOptions::kGranularityFieldName;
constexpr StringData TimeseriesOptions::kMetaFieldFieldName;
constexpr StringData TimeseriesOptions::kTimeFieldFieldName;


TimeseriesOptions::TimeseriesOptions() : _timeField(mongo::idl::preparsedValue<decltype(_timeField)>()), _hasTimeField(false) {
    // Used for initialization only
}
TimeseriesOptions::TimeseriesOptions(std::string timeField) : _timeField(std::move(timeField)), _hasTimeField(true) {
    // Used for initialization only
}

void TimeseriesOptions::validateBucketMaxSpanSeconds(IDLParserErrorContext& ctxt, const std::int32_t value)
{
    if (!(value >= 1)) {
        throwComparisonError<std::int32_t>(ctxt, "bucketMaxSpanSeconds", ">="_sd, value, 1);
    }
}

void TimeseriesOptions::validateBucketMaxSpanSeconds(const std::int32_t value)
{
    if (!(value >= 1)) {
        throwComparisonError<std::int32_t>("bucketMaxSpanSeconds", ">="_sd, value, 1);
    }
}


TimeseriesOptions TimeseriesOptions::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<TimeseriesOptions>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void TimeseriesOptions::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<4> usedFields;
    const size_t kTimeFieldBit = 0;
    const size_t kMetaFieldBit = 1;
    const size_t kGranularityBit = 2;
    const size_t kBucketMaxSpanSecondsBit = 3;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kTimeFieldFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kTimeFieldBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTimeFieldBit);

                _hasTimeField = true;
                _timeField = element.str();
            }
        }
        else if (fieldName == kMetaFieldFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kMetaFieldBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMetaFieldBit);

                _metaField = element.str();
            }
        }
        else if (fieldName == kGranularityFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kGranularityBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kGranularityBit);

                IDLParserErrorContext tempContext(kGranularityFieldName, &ctxt);
                _granularity = BucketGranularity_parse(tempContext, element.valueStringData());
            }
        }
        else if (fieldName == kBucketMaxSpanSecondsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kBucketMaxSpanSecondsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kBucketMaxSpanSecondsBit);

                {
                    auto value = element.safeNumberInt();
                    validateBucketMaxSpanSeconds(value);
                    _bucketMaxSpanSeconds = std::move(value);
                }
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kTimeFieldBit]) {
            ctxt.throwMissingField(kTimeFieldFieldName);
        }
        if (!usedFields[kGranularityBit]) {
            _granularity = mongo::BucketGranularityEnum::Seconds;
        }
    }

}


void TimeseriesOptions::serialize(BSONObjBuilder* builder) const {
    invariant(_hasTimeField);

    builder->append(kTimeFieldFieldName, _timeField);

    if (_metaField.is_initialized()) {
        builder->append(kMetaFieldFieldName, _metaField.get());
    }

    {
        builder->append(kGranularityFieldName, ::mongo::BucketGranularity_serializer(_granularity));
    }

    if (_bucketMaxSpanSeconds.is_initialized()) {
        builder->append(kBucketMaxSpanSecondsFieldName, _bucketMaxSpanSeconds.get());
    }

}


BSONObj TimeseriesOptions::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

std::int32_t gTimeseriesBucketMaxCount{1000};
std::int32_t gTimeseriesBucketMaxSize{128000};
bool gTimeseriesBucketsCollectionClusterById{true};
MONGO_SERVER_PARAMETER_REGISTER(idl_36ac8765eed4b8e5fefd8fc9452f7e1ca50d4ea5)(InitializerContext*) {
    /**
     * Maximum number of measurements to store in a single bucket
     */
    [[maybe_unused]] auto* scp_0 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("timeseriesBucketMaxCount", gTimeseriesBucketMaxCount);
        ret->addBound<idl_server_parameter_detail::GTE>(1);
        return ret;
    })();

    /**
     * Maximum size in bytes of measurements to store together in a single bucket
     */
    [[maybe_unused]] auto* scp_1 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("timeseriesBucketMaxSize", gTimeseriesBucketMaxSize);
        ret->addBound<idl_server_parameter_detail::GTE>(1);
        return ret;
    })();

    /**
     * The threshold in bytes for bucket catalog memory usage above which idle buckets will be expired
     */
    [[maybe_unused]] auto* scp_2 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("timeseriesIdleBucketExpiryMemoryUsageThreshold", gTimeseriesIdleBucketExpiryMemoryUsageThresholdBytes);
        ret->addBound<idl_server_parameter_detail::GTE>(1);
        return ret;
    })();

    /**
     * When true, newly-created time-series buckets collections are clustered by _id
     */
    [[maybe_unused]] auto* scp_3 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("timeseriesBucketsCollectionClusterById", gTimeseriesBucketsCollectionClusterById);
        return ret;
    })();

}
}  // namespace mongo
