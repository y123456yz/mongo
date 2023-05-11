/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/pipeline/document_source_coll_stats_gen.h --output build/opt/mongo/db/pipeline/document_source_coll_stats_gen.cpp src/mongo/db/pipeline/document_source_coll_stats.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/pipeline/document_source_coll_stats_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData LatencyStatsSpec::kHistogramsFieldName;


LatencyStatsSpec::LatencyStatsSpec()  {
    // Used for initialization only
}


LatencyStatsSpec LatencyStatsSpec::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<LatencyStatsSpec>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void LatencyStatsSpec::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kHistogramsBit = 0;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kHistogramsFieldName) {
            if (MONGO_unlikely(usedFields[kHistogramsBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kHistogramsBit);

            _histograms = OptionalBool::parseFromBSON(element);
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kHistogramsBit]) {
            _histograms = mongo::OptionalBool();
        }
    }

}


void LatencyStatsSpec::serialize(BSONObjBuilder* builder) const {
    {
        _histograms.serializeToBSON(kHistogramsFieldName, builder);
    }

}


BSONObj LatencyStatsSpec::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData DocumentSourceCollStatsSpec::kCountFieldName;
constexpr StringData DocumentSourceCollStatsSpec::kLatencyStatsFieldName;
constexpr StringData DocumentSourceCollStatsSpec::kQueryExecStatsFieldName;
constexpr StringData DocumentSourceCollStatsSpec::kStorageStatsFieldName;


DocumentSourceCollStatsSpec::DocumentSourceCollStatsSpec()  {
    // Used for initialization only
}

void DocumentSourceCollStatsSpec::validateCount(IDLParserErrorContext& ctxt, const mongo::BSONObj& value)
{
    uassertStatusOK(validateObjectIsEmpty(value));
}

void DocumentSourceCollStatsSpec::validateCount(const mongo::BSONObj& value)
{
    uassertStatusOK(validateObjectIsEmpty(value));
}

void DocumentSourceCollStatsSpec::validateQueryExecStats(IDLParserErrorContext& ctxt, const mongo::BSONObj& value)
{
    uassertStatusOK(validateObjectIsEmpty(value));
}

void DocumentSourceCollStatsSpec::validateQueryExecStats(const mongo::BSONObj& value)
{
    uassertStatusOK(validateObjectIsEmpty(value));
}


DocumentSourceCollStatsSpec DocumentSourceCollStatsSpec::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<DocumentSourceCollStatsSpec>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void DocumentSourceCollStatsSpec::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<4> usedFields;
    const size_t kLatencyStatsBit = 0;
    const size_t kStorageStatsBit = 1;
    const size_t kCountBit = 2;
    const size_t kQueryExecStatsBit = 3;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kLatencyStatsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kLatencyStatsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLatencyStatsBit);

                IDLParserErrorContext tempContext(kLatencyStatsFieldName, &ctxt);
                const auto localObject = element.Obj();
                _latencyStats = mongo::LatencyStatsSpec::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kStorageStatsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kStorageStatsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStorageStatsBit);

                IDLParserErrorContext tempContext(kStorageStatsFieldName, &ctxt);
                const auto localObject = element.Obj();
                _storageStats = mongo::StorageStatsSpec::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kCountFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCountBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCountBit);

                {
                    auto value = element.Obj();
                    validateCount(value);
                    _count = std::move(value);
                }
            }
        }
        else if (fieldName == kQueryExecStatsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kQueryExecStatsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kQueryExecStatsBit);

                {
                    auto value = element.Obj();
                    validateQueryExecStats(value);
                    _queryExecStats = std::move(value);
                }
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
    }

}


void DocumentSourceCollStatsSpec::serialize(BSONObjBuilder* builder) const {
    if (_latencyStats.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kLatencyStatsFieldName));
        _latencyStats.get().serialize(&subObjBuilder);
    }

    if (_storageStats.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kStorageStatsFieldName));
        _storageStats.get().serialize(&subObjBuilder);
    }

    if (_count.is_initialized()) {
        builder->append(kCountFieldName, _count.get());
    }

    if (_queryExecStats.is_initialized()) {
        builder->append(kQueryExecStatsFieldName, _queryExecStats.get());
    }

}


BSONObj DocumentSourceCollStatsSpec::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
