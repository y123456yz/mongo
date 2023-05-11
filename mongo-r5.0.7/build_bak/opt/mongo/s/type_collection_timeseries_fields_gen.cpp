/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/s/type_collection_timeseries_fields_gen.h --output build/opt/mongo/s/type_collection_timeseries_fields_gen.cpp src/mongo/s/type_collection_timeseries_fields.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/s/type_collection_timeseries_fields_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData TypeCollectionTimeseriesFields::kTimeseriesOptionsFieldName;
constexpr StringData TypeCollectionTimeseriesFields::kBucketMaxSpanSecondsFieldName;
constexpr StringData TypeCollectionTimeseriesFields::kGranularityFieldName;
constexpr StringData TypeCollectionTimeseriesFields::kMetaFieldFieldName;
constexpr StringData TypeCollectionTimeseriesFields::kTimeFieldFieldName;


TypeCollectionTimeseriesFields::TypeCollectionTimeseriesFields()  {
    // Used for initialization only
}

void TypeCollectionTimeseriesFields::validateBucketMaxSpanSeconds(IDLParserErrorContext& ctxt, const std::int32_t value)
{
    if (!(value >= 1)) {
        throwComparisonError<std::int32_t>(ctxt, "bucketMaxSpanSeconds", ">="_sd, value, 1);
    }
}

void TypeCollectionTimeseriesFields::validateBucketMaxSpanSeconds(const std::int32_t value)
{
    if (!(value >= 1)) {
        throwComparisonError<std::int32_t>("bucketMaxSpanSeconds", ">="_sd, value, 1);
    }
}


TypeCollectionTimeseriesFields TypeCollectionTimeseriesFields::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<TypeCollectionTimeseriesFields>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void TypeCollectionTimeseriesFields::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<5> usedFields;
    const size_t kTimeFieldBit = 0;
    const size_t kMetaFieldBit = 1;
    const size_t kGranularityBit = 2;
    const size_t kBucketMaxSpanSecondsBit = 3;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kTimeFieldFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kTimeFieldBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTimeFieldBit);

                _timeseriesOptions.setTimeField(element.str());
            }
        }
        else if (fieldName == kMetaFieldFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kMetaFieldBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMetaFieldBit);

                _timeseriesOptions.setMetaField(boost::optional<StringData>(element.str()));
            }
        }
        else if (fieldName == kGranularityFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kGranularityBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kGranularityBit);

                IDLParserErrorContext tempContext(kGranularityFieldName, &ctxt);
                _timeseriesOptions.setGranularity(BucketGranularity_parse(tempContext, element.valueStringData()));
            }
        }
        else if (fieldName == kBucketMaxSpanSecondsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kBucketMaxSpanSecondsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kBucketMaxSpanSecondsBit);

                _timeseriesOptions.setBucketMaxSpanSeconds(boost::optional<std::int32_t>(element.safeNumberInt()));
            }
        }
        else {
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kTimeFieldBit]) {
            ctxt.throwMissingField(kTimeFieldFieldName);
        }
        if (!usedFields[kGranularityBit]) {
            _timeseriesOptions.setGranularity(mongo::BucketGranularityEnum::Seconds);
        }
    }

}


void TypeCollectionTimeseriesFields::serialize(BSONObjBuilder* builder) const {
    {
        _timeseriesOptions.serialize(builder);
    }

}


BSONObj TypeCollectionTimeseriesFields::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
