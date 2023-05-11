/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/s/resharding/donor_oplog_id_gen.h --output build/opt/mongo/db/s/resharding/donor_oplog_id_gen.cpp src/mongo/db/s/resharding/donor_oplog_id.idl
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
 * Represents the set of timestamps that belong to an operation from the donor shard.
 */
class ReshardingDonorOplogId {
public:
    static constexpr auto kClusterTimeFieldName = "clusterTime"_sd;
    static constexpr auto kTsFieldName = "ts"_sd;

    ReshardingDonorOplogId();
    ReshardingDonorOplogId(mongo::Timestamp clusterTime, mongo::Timestamp ts);

    static ReshardingDonorOplogId parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * The oplog entry timestamp of the final oplog entry of a transaction. If the operation is not from a transaction, then it is the same value as the ts field.
     */
    const mongo::Timestamp& getClusterTime() const { return _clusterTime; }
    void setClusterTime(mongo::Timestamp value) & {  _clusterTime = std::move(value); _hasClusterTime = true; }

    /**
     * The oplog entry timestamp associated with this operation.
     */
    const mongo::Timestamp& getTs() const { return _ts; }
    void setTs(mongo::Timestamp value) & {  _ts = std::move(value); _hasTs = true; }


    friend bool operator==(const ReshardingDonorOplogId& left, const ReshardingDonorOplogId& right) {
        return left._clusterTime == right._clusterTime && left._ts == right._ts;
    }

    friend bool operator!=(const ReshardingDonorOplogId& left, const ReshardingDonorOplogId& right) {
        return left._clusterTime != right._clusterTime || left._ts != right._ts;
    }
    friend bool operator<(const ReshardingDonorOplogId& left, const ReshardingDonorOplogId& right) {
        return left._clusterTime < right._clusterTime || (!(right._clusterTime < left._clusterTime) && (left._ts < right._ts));
    }
    friend bool operator>(const ReshardingDonorOplogId& left, const ReshardingDonorOplogId& right) {
        return right < left;
    }
    friend bool operator<=(const ReshardingDonorOplogId& left, const ReshardingDonorOplogId& right) {
        return !(right < left);
    }
    friend bool operator>=(const ReshardingDonorOplogId& left, const ReshardingDonorOplogId& right) {
        return !(left < right);
    }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::Timestamp _clusterTime;
    mongo::Timestamp _ts;
    bool _hasClusterTime : 1;
    bool _hasTs : 1;
};

}  // namespace mongo
