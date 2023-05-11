/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/s/resharding/resharding_oplog_applier_progress_gen.h --output build/opt/mongo/db/s/resharding/resharding_oplog_applier_progress_gen.cpp src/mongo/db/s/resharding/resharding_oplog_applier_progress.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/s/resharding/resharding_oplog_applier_progress_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData ReshardingOplogApplierProgress::kNumEntriesAppliedFieldName;
constexpr StringData ReshardingOplogApplierProgress::kOplogSourceIdFieldName;
constexpr StringData ReshardingOplogApplierProgress::kProgressFieldName;


ReshardingOplogApplierProgress::ReshardingOplogApplierProgress() : _oplogSourceId(mongo::idl::preparsedValue<decltype(_oplogSourceId)>()), _progress(mongo::idl::preparsedValue<decltype(_progress)>()), _numEntriesApplied(mongo::idl::preparsedValue<decltype(_numEntriesApplied)>()), _hasOplogSourceId(false), _hasProgress(false), _hasNumEntriesApplied(false) {
    // Used for initialization only
}
ReshardingOplogApplierProgress::ReshardingOplogApplierProgress(mongo::ReshardingSourceId oplogSourceId, mongo::ReshardingDonorOplogId progress, std::int64_t numEntriesApplied) : _oplogSourceId(std::move(oplogSourceId)), _progress(std::move(progress)), _numEntriesApplied(std::move(numEntriesApplied)), _hasOplogSourceId(true), _hasProgress(true), _hasNumEntriesApplied(true) {
    // Used for initialization only
}


ReshardingOplogApplierProgress ReshardingOplogApplierProgress::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ReshardingOplogApplierProgress>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ReshardingOplogApplierProgress::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<3> usedFields;
    const size_t kOplogSourceIdBit = 0;
    const size_t kProgressBit = 1;
    const size_t kNumEntriesAppliedBit = 2;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kOplogSourceIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kOplogSourceIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kOplogSourceIdBit);

                _hasOplogSourceId = true;
                IDLParserErrorContext tempContext(kOplogSourceIdFieldName, &ctxt);
                const auto localObject = element.Obj();
                _oplogSourceId = mongo::ReshardingSourceId::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kProgressFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kProgressBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kProgressBit);

                _hasProgress = true;
                IDLParserErrorContext tempContext(kProgressFieldName, &ctxt);
                const auto localObject = element.Obj();
                _progress = mongo::ReshardingDonorOplogId::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kNumEntriesAppliedFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kNumEntriesAppliedBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNumEntriesAppliedBit);

                _hasNumEntriesApplied = true;
                _numEntriesApplied = element._numberLong();
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
        if (!usedFields[kOplogSourceIdBit]) {
            ctxt.throwMissingField(kOplogSourceIdFieldName);
        }
        if (!usedFields[kProgressBit]) {
            ctxt.throwMissingField(kProgressFieldName);
        }
        if (!usedFields[kNumEntriesAppliedBit]) {
            ctxt.throwMissingField(kNumEntriesAppliedFieldName);
        }
    }

}


void ReshardingOplogApplierProgress::serialize(BSONObjBuilder* builder) const {
    invariant(_hasOplogSourceId && _hasProgress && _hasNumEntriesApplied);

    {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kOplogSourceIdFieldName));
        _oplogSourceId.serialize(&subObjBuilder);
    }

    {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kProgressFieldName));
        _progress.serialize(&subObjBuilder);
    }

    builder->append(kNumEntriesAppliedFieldName, _numEntriesApplied);

}


BSONObj ReshardingOplogApplierProgress::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
