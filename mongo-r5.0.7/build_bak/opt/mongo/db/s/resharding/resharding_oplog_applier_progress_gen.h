/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/s/resharding/resharding_oplog_applier_progress_gen.h --output build/opt/mongo/db/s/resharding/resharding_oplog_applier_progress_gen.cpp src/mongo/db/s/resharding/resharding_oplog_applier_progress.idl
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
#include "mongo/db/keypattern.h"
#include "mongo/db/namespace_string.h"
#include "mongo/db/s/resharding/donor_oplog_id_gen.h"
#include "mongo/idl/basic_types.h"
#include "mongo/idl/basic_types_gen.h"
#include "mongo/idl/idl_parser.h"
#include "mongo/rpc/op_msg.h"
#include "mongo/s/resharding/common_types_gen.h"
#include "mongo/s/shard_id.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/util/uuid.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {

/**
 * Used for storing the progress made by the resharding oplog applier.
 */
class ReshardingOplogApplierProgress {
public:
    static constexpr auto kNumEntriesAppliedFieldName = "numEntriesApplied"_sd;
    static constexpr auto kOplogSourceIdFieldName = "_id"_sd;
    static constexpr auto kProgressFieldName = "progress"_sd;

    ReshardingOplogApplierProgress();
    ReshardingOplogApplierProgress(mongo::ReshardingSourceId oplogSourceId, mongo::ReshardingDonorOplogId progress, std::int64_t numEntriesApplied);

    static ReshardingOplogApplierProgress parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * The identifier for the source of the oplog entries.
     */
    const mongo::ReshardingSourceId& getOplogSourceId() const { return _oplogSourceId; }
    mongo::ReshardingSourceId& getOplogSourceId() { return _oplogSourceId; }
    void setOplogSourceId(mongo::ReshardingSourceId value) & {  _oplogSourceId = std::move(value); _hasOplogSourceId = true; }

    /**
     * The minimum point where the resharding oplog applier can start without missing any oplog it needs to process.
     */
    const mongo::ReshardingDonorOplogId& getProgress() const { return _progress; }
    mongo::ReshardingDonorOplogId& getProgress() { return _progress; }
    void setProgress(mongo::ReshardingDonorOplogId value) & {  _progress = std::move(value); _hasProgress = true; }

    /**
     * The total number of oplog entries that have been applied by this ReshardingOplogApplier.
     */
    std::int64_t getNumEntriesApplied() const { return _numEntriesApplied; }
    void setNumEntriesApplied(std::int64_t value) & {  _numEntriesApplied = std::move(value); _hasNumEntriesApplied = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::ReshardingSourceId _oplogSourceId;
    mongo::ReshardingDonorOplogId _progress;
    std::int64_t _numEntriesApplied;
    bool _hasOplogSourceId : 1;
    bool _hasProgress : 1;
    bool _hasNumEntriesApplied : 1;
};

}  // namespace mongo
