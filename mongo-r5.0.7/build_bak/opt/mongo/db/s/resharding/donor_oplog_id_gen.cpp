/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/s/resharding/donor_oplog_id_gen.h --output build/opt/mongo/db/s/resharding/donor_oplog_id_gen.cpp src/mongo/db/s/resharding/donor_oplog_id.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/s/resharding/donor_oplog_id_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData ReshardingDonorOplogId::kClusterTimeFieldName;
constexpr StringData ReshardingDonorOplogId::kTsFieldName;


ReshardingDonorOplogId::ReshardingDonorOplogId() : _clusterTime(mongo::idl::preparsedValue<decltype(_clusterTime)>()), _ts(mongo::idl::preparsedValue<decltype(_ts)>()), _hasClusterTime(false), _hasTs(false) {
    // Used for initialization only
}
ReshardingDonorOplogId::ReshardingDonorOplogId(mongo::Timestamp clusterTime, mongo::Timestamp ts) : _clusterTime(std::move(clusterTime)), _ts(std::move(ts)), _hasClusterTime(true), _hasTs(true) {
    // Used for initialization only
}


ReshardingDonorOplogId ReshardingDonorOplogId::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ReshardingDonorOplogId>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ReshardingDonorOplogId::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kClusterTimeBit = 0;
    const size_t kTsBit = 1;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kClusterTimeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, bsonTimestamp))) {
                if (MONGO_unlikely(usedFields[kClusterTimeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kClusterTimeBit);

                _hasClusterTime = true;
                _clusterTime = element.timestamp();
            }
        }
        else if (fieldName == kTsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, bsonTimestamp))) {
                if (MONGO_unlikely(usedFields[kTsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTsBit);

                _hasTs = true;
                _ts = element.timestamp();
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kClusterTimeBit]) {
            ctxt.throwMissingField(kClusterTimeFieldName);
        }
        if (!usedFields[kTsBit]) {
            ctxt.throwMissingField(kTsFieldName);
        }
    }

}


void ReshardingDonorOplogId::serialize(BSONObjBuilder* builder) const {
    invariant(_hasClusterTime && _hasTs);

    builder->append(kClusterTimeFieldName, _clusterTime);

    builder->append(kTsFieldName, _ts);

}


BSONObj ReshardingDonorOplogId::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
