/**
 *    Copyright (C) 2018-present MongoDB, Inc.
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the Server Side Public License, version 1,
 *    as published by MongoDB, Inc.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    Server Side Public License for more details.
 *
 *    You should have received a copy of the Server Side Public License
 *    along with this program. If not, see
 *    <http://www.mongodb.com/licensing/server-side-public-license>.
 *
 *    As a special exception, the copyright holders give permission to link the
 *    code of portions of this program with the OpenSSL library under certain
 *    conditions as described in each individual source file and distribute
 *    linked combinations including the program with the OpenSSL library. You
 *    must comply with the Server Side Public License in all respects for
 *    all of the code used other than as permitted herein. If you modify file(s)
 *    with this exception, you may extend this exception to your version of the
 *    file(s), but you are not obligated to do so. If you do not wish to do so,
 *    delete this exception statement from your version. If you delete this
 *    exception statement from all source files in the program, then also delete
 *    it in the license file.
 */

#define MONGO_LOGV2_DEFAULT_COMPONENT ::mongo::logv2::LogComponent::kSharding

#include "mongo/platform/basic.h"

#include "mongo/s/chunk.h"

#include "mongo/platform/random.h"
#include "mongo/s/chunk_writes_tracker.h"
#include "mongo/util/str.h"

namespace mongo {

ChunkInfo::ChunkInfo(const ChunkType& from)
    : _range(from.getMin(), from.getMax()),
      _maxKeyString(ShardKeyPattern::toKeyString(from.getMax())),
      _shardId(from.getShard()),
      _lastmod(from.getVersion()),
      _history(from.getHistory()),
      _jumbo(from.getJumbo()),
      _writesTracker(std::make_shared<ChunkWritesTracker>()) {
    uassertStatusOK(from.validate());
}

ChunkInfo::ChunkInfo(ChunkRange range,
                     std::string maxKeyString,
                     ShardId shardId,
                     ChunkVersion version,
                     std::vector<ChunkHistory> history,
                     bool jumbo,
                     std::shared_ptr<ChunkWritesTracker> writesTracker)
    : _range(std::move(range)),
      _maxKeyString(std::move(maxKeyString)),
      _shardId(shardId),
      _lastmod(std::move(version)),
      _history(std::move(history)),
      _jumbo(jumbo),
      _writesTracker(writesTracker) {}

//该chunk当前所属分片信息
const ShardId& ChunkInfo::getShardIdAt(const boost::optional<Timestamp>& ts) const {
    // This chunk was refreshed from FCV 3.6 config server so it doesn't have history
    if (_history.empty()) {
        return _shardId;
    }

    // If the timestamp is not provided than we return the latest shardid
    if (!ts) {
        invariant(_shardId == _history.front().getShard());
        return _history.front().getShard();
    }

    for (const auto& h : _history) {
        if (h.getValidAfter() <= ts) {
            return h.getShard();
        }
    }

    uasserted(ErrorCodes::StaleChunkHistory,
              str::stream() << "Cannot find shardId the chunk belonged to at cluster time "
                            << ts.get().toString());
}

void ChunkInfo::throwIfMovedSince(const Timestamp& ts) const {
    uassert(50978, "Chunk has no history entries", !_history.empty());

    const auto& latestValidAfter = _history.front().getValidAfter();
    if (latestValidAfter <= ts) {
        return;
    }

    uassert(ErrorCodes::StaleChunkHistory,
            str::stream() << "Cannot find shardId the chunk belonged to at cluster time "
                          << ts.toString(),
            _history.back().getValidAfter() <= ts);

    uasserted(ErrorCodes::MigrationConflict,
              str::stream() << "Chunk has moved since timestamp: " << ts.toString()
                            << ", most recently at timestamp: " << latestValidAfter.toString());
}

bool ChunkInfo::containsKey(const BSONObj& shardKey) const {
    return getMin().woCompare(shardKey) <= 0 && shardKey.woCompare(getMax()) < 0;
}

/*
{"t":{"$date":"2022-09-17T13:11:07.219+08:00"},"s":"I",  "c":"SHARDING", "id":22753,   "ctx":"conn30575",
"msg":"Routing info requested by getShardVersion","attr":{"routingInfo":"RoutingTableHistory: yyz.yyz1 key: 
{ bookId: \"hashed\" }\nChunks:\n\tshard: mongodb_5.0_shard1, lastmod: 1|0||632556c15fcc6dccc6f7f57a||Timestamp(1663391425, 12), 
[{ bookId: MinKey }, { bookId: -4611686018427387902 })\n\tshard: mongodb_5.0_shard1, lastmod: 1|1||632556c15fcc6dccc6f7f57a||
Timestamp(1663391425, 12), [{ bookId: -4611686018427387902 }, { bookId: 0 })\n\tshard: mongodb_5.0_shard2, lastmod: 1|2||
632556c15fcc6dccc6f7f57a||Timestamp(1663391425, 12), [{ bookId: 0 }, { bookId: 4611686018427387902 })\n\tshard: 
mongodb_5.0_shard2, lastmod: 1|3||632556c15fcc6dccc6f7f57a||Timestamp(1663391425, 12), [{ bookId: 4611686018427387902 }, 
{ bookId: MaxKey })\nShard versions:\n\tmongodb_5.0_shard1: 1|1||632556c15fcc6dccc6f7f57a||Timestamp(1663391425, 12)\n\t
mongodb_5.0_shard2: 1|3||632556c15fcc6dccc6f7f57a||Timestamp(1663391425, 12)\n"}}
*/
//RoutingTableHistory::toString()   ChunkMap::toBSON()
std::string ChunkInfo::toString() const {
    return str::stream() << ChunkType::shard() << ": " << _shardId << ", " << ChunkType::lastmod()
                         << ": " << _lastmod.toString() << ", " << _range.toString();
}

void ChunkInfo::markAsJumbo() {
    _jumbo = true;
}

void Chunk::throwIfMoved() const {
    if (!_atClusterTime) {
        return;
    }

    _chunkInfo.throwIfMovedSince(*_atClusterTime);
}

}  // namespace mongo
