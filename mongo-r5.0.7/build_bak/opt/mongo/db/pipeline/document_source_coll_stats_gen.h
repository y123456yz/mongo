/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/pipeline/document_source_coll_stats_gen.h --output build/opt/mongo/db/pipeline/document_source_coll_stats_gen.cpp src/mongo/db/pipeline/document_source_coll_stats.idl
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
#include "mongo/db/pipeline/document_source_parsing_validators.h"
#include "mongo/db/pipeline/storage_stats_spec_gen.h"
#include "mongo/idl/basic_types.h"
#include "mongo/idl/basic_types_gen.h"
#include "mongo/idl/idl_parser.h"
#include "mongo/rpc/op_msg.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/util/uuid.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {

/**
 * Represents the 'latencyStats' argument to the $collStats stage.
 */
class LatencyStatsSpec {
public:
    static constexpr auto kHistogramsFieldName = "histograms"_sd;

    LatencyStatsSpec();

    static LatencyStatsSpec parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Adds latency histogram information to the embedded documents in latencyStats if true.
     */
    const mongo::OptionalBool& getHistograms() const { return _histograms; }
    void setHistograms(mongo::OptionalBool value) & {  _histograms = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::OptionalBool _histograms{mongo::OptionalBool()};
};

/**
 * Specification for a $collStats stage.
 */
class DocumentSourceCollStatsSpec {
public:
    static constexpr auto kCountFieldName = "count"_sd;
    static constexpr auto kLatencyStatsFieldName = "latencyStats"_sd;
    static constexpr auto kQueryExecStatsFieldName = "queryExecStats"_sd;
    static constexpr auto kStorageStatsFieldName = "storageStats"_sd;

    DocumentSourceCollStatsSpec();

    static DocumentSourceCollStatsSpec parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * A request to include latency stats in the $collStats output.
     */
    const boost::optional<mongo::LatencyStatsSpec>& getLatencyStats() const& { return _latencyStats; }
    void getLatencyStats() && = delete;
    void setLatencyStats(boost::optional<mongo::LatencyStatsSpec> value) & {  _latencyStats = std::move(value);  }

    /**
     * Adds storage statistics to the return document.
     */
    const boost::optional<mongo::StorageStatsSpec>& getStorageStats() const& { return _storageStats; }
    void getStorageStats() && = delete;
    void setStorageStats(boost::optional<mongo::StorageStatsSpec> value) & {  _storageStats = std::move(value);  }

    /**
     * Adds the total number of documents in the collection to the return document.
     */
    const boost::optional<mongo::BSONObj>& getCount() const& { return _count; }
    void getCount() && = delete;
    void setCount(boost::optional<mongo::BSONObj> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get();
        validateCount(_tmpValue);
        _count = std::move(_tmpValue);
    } else {
        _count = boost::none;
    }
      }

    /**
     * Adds query execution statistics to the return document.
     */
    const boost::optional<mongo::BSONObj>& getQueryExecStats() const& { return _queryExecStats; }
    void getQueryExecStats() && = delete;
    void setQueryExecStats(boost::optional<mongo::BSONObj> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get();
        validateQueryExecStats(_tmpValue);
        _queryExecStats = std::move(_tmpValue);
    } else {
        _queryExecStats = boost::none;
    }
      }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    void validateCount(const mongo::BSONObj& value);
    void validateCount(IDLParserErrorContext& ctxt, const mongo::BSONObj& value);

    void validateQueryExecStats(const mongo::BSONObj& value);
    void validateQueryExecStats(IDLParserErrorContext& ctxt, const mongo::BSONObj& value);

private:
    boost::optional<mongo::LatencyStatsSpec> _latencyStats;
    boost::optional<mongo::StorageStatsSpec> _storageStats;
    boost::optional<mongo::BSONObj> _count;
    boost::optional<mongo::BSONObj> _queryExecStats;
};

}  // namespace mongo
