/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/s/resharding/resharding_txn_cloner_progress_gen.h --output build/opt/mongo/db/s/resharding/resharding_txn_cloner_progress_gen.cpp src/mongo/db/s/resharding/resharding_txn_cloner_progress.idl
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
#include "mongo/crypto/sha256_block.h"
#include "mongo/db/keypattern.h"
#include "mongo/db/logical_session_id_gen.h"
#include "mongo/db/namespace_string.h"
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
 * Used for storing the progress made by the resharding transaction cloner.
 */
class ReshardingTxnClonerProgress {
public:
    static constexpr auto kProgressFieldName = "progress"_sd;
    static constexpr auto kSourceIdFieldName = "_id"_sd;

    ReshardingTxnClonerProgress();
    ReshardingTxnClonerProgress(mongo::ReshardingSourceId sourceId, mongo::LogicalSessionId progress);

    static ReshardingTxnClonerProgress parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * The identifier for the source of the config.transactions entries.
     */
    const mongo::ReshardingSourceId& getSourceId() const { return _sourceId; }
    mongo::ReshardingSourceId& getSourceId() { return _sourceId; }
    void setSourceId(mongo::ReshardingSourceId value) & {  _sourceId = std::move(value); _hasSourceId = true; }

    /**
     * The minimum point where the resharding transaction cloner can start without missing any config.transactions entries it needs to process.
     */
    const mongo::LogicalSessionId& getProgress() const { return _progress; }
    mongo::LogicalSessionId& getProgress() { return _progress; }
    void setProgress(mongo::LogicalSessionId value) & {  _progress = std::move(value); _hasProgress = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::ReshardingSourceId _sourceId;
    mongo::LogicalSessionId _progress;
    bool _hasSourceId : 1;
    bool _hasProgress : 1;
};

}  // namespace mongo
