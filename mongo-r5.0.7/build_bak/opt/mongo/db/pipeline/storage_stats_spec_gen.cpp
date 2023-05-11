/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/pipeline/storage_stats_spec_gen.h --output build/opt/mongo/db/pipeline/storage_stats_spec_gen.cpp src/mongo/db/pipeline/storage_stats_spec.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/pipeline/storage_stats_spec_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData StorageStatsSpec::kScaleFieldName;
constexpr StringData StorageStatsSpec::kVerboseFieldName;
constexpr StringData StorageStatsSpec::kWaitForLockFieldName;


StorageStatsSpec::StorageStatsSpec()  {
    // Used for initialization only
}

void StorageStatsSpec::validateScale(IDLParserErrorContext& ctxt, const std::int32_t value)
{
    if (!(value >= 1)) {
        throwComparisonError<std::int32_t>(ctxt, "scale", ">="_sd, value, 1);
    }
}

void StorageStatsSpec::validateScale(const std::int32_t value)
{
    if (!(value >= 1)) {
        throwComparisonError<std::int32_t>("scale", ">="_sd, value, 1);
    }
}


StorageStatsSpec StorageStatsSpec::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<StorageStatsSpec>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void StorageStatsSpec::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<3> usedFields;
    const size_t kScaleBit = 0;
    const size_t kVerboseBit = 1;
    const size_t kWaitForLockBit = 2;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kScaleFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kScaleBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kScaleBit);

                {
                    auto value = element.safeNumberInt();
                    validateScale(value);
                    _scale = std::move(value);
                }
            }
        }
        else if (fieldName == kVerboseFieldName) {
            if (MONGO_unlikely(usedFields[kVerboseBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kVerboseBit);

            _verbose = OptionalBool::parseFromBSON(element);
        }
        else if (fieldName == kWaitForLockFieldName) {
            if (MONGO_unlikely(usedFields[kWaitForLockBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kWaitForLockBit);

            _waitForLock = OptionalBool::parseFromBSON(element);
        }
        else {
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kVerboseBit]) {
            _verbose = false;
        }
        if (!usedFields[kWaitForLockBit]) {
            _waitForLock = true;
        }
    }

}


void StorageStatsSpec::serialize(BSONObjBuilder* builder) const {
    if (_scale.is_initialized()) {
        builder->append(kScaleFieldName, _scale.get());
    }

    {
        _verbose.serializeToBSON(kVerboseFieldName, builder);
    }

    {
        _waitForLock.serializeToBSON(kWaitForLockFieldName, builder);
    }

}


BSONObj StorageStatsSpec::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
