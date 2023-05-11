/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/query/find_command_gen.h --output build/opt/mongo/db/query/find_command_gen.cpp src/mongo/db/query/find_command.idl
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
#include "mongo/db/commands.h"
#include "mongo/db/logical_session_id_gen.h"
#include "mongo/db/namespace_string.h"
#include "mongo/db/pipeline/legacy_runtime_constants_gen.h"
#include "mongo/db/query/cursor_response_gen.h"
#include "mongo/db/query/hint_parser.h"
#include "mongo/db/query/max_time_ms_parser.h"
#include "mongo/idl/basic_types.h"
#include "mongo/idl/basic_types_gen.h"
#include "mongo/idl/idl_parser.h"
#include "mongo/rpc/op_msg.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/util/uuid.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {

/**
 * A struct representing the find command
 */
class FindCommandRequest {
public:
    using Reply = mongo::CursorInitialReply;
    static constexpr auto k_use44SortKeysFieldName = "_use44SortKeys"_sd;
    static constexpr auto kAllowDiskUseFieldName = "allowDiskUse"_sd;
    static constexpr auto kAllowPartialResultsFieldName = "allowPartialResults"_sd;
    static constexpr auto kAllowSpeculativeMajorityReadFieldName = "allowSpeculativeMajorityRead"_sd;
    static constexpr auto kAwaitDataFieldName = "awaitData"_sd;
    static constexpr auto kBatchSizeFieldName = "batchSize"_sd;
    static constexpr auto kCollationFieldName = "collation"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kFilterFieldName = "filter"_sd;
    static constexpr auto kHintFieldName = "hint"_sd;
    static constexpr auto kLegacyRuntimeConstantsFieldName = "runtimeConstants"_sd;
    static constexpr auto kLetFieldName = "let"_sd;
    static constexpr auto kLimitFieldName = "limit"_sd;
    static constexpr auto kMaxFieldName = "max"_sd;
    static constexpr auto kMaxTimeMSFieldName = "maxTimeMS"_sd;
    static constexpr auto kMinFieldName = "min"_sd;
    static constexpr auto kNoCursorTimeoutFieldName = "noCursorTimeout"_sd;
    static constexpr auto kNtoreturnFieldName = "ntoreturn"_sd;
    static constexpr auto kOplogReplayFieldName = "oplogReplay"_sd;
    static constexpr auto kOptionsFieldName = "options"_sd;
    static constexpr auto kProjectionFieldName = "projection"_sd;
    static constexpr auto kReadConcernFieldName = "readConcern"_sd;
    static constexpr auto kReadOnceFieldName = "readOnce"_sd;
    static constexpr auto kRequestResumeTokenFieldName = "$_requestResumeToken"_sd;
    static constexpr auto kResumeAfterFieldName = "$_resumeAfter"_sd;
    static constexpr auto kReturnKeyFieldName = "returnKey"_sd;
    static constexpr auto kShowRecordIdFieldName = "showRecordId"_sd;
    static constexpr auto kSingleBatchFieldName = "singleBatch"_sd;
    static constexpr auto kSkipFieldName = "skip"_sd;
    static constexpr auto kSortFieldName = "sort"_sd;
    static constexpr auto kTailableFieldName = "tailable"_sd;
    static constexpr auto kTermFieldName = "term"_sd;
    static constexpr auto kUnwrappedReadPrefFieldName = "$queryOptions"_sd;
    static constexpr auto kCommandName = "find"_sd;

    static AuthorizationContract kAuthorizationContract;

    explicit FindCommandRequest(const NamespaceStringOrUUID nssOrUUID);

    static FindCommandRequest parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static FindCommandRequest parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const NamespaceStringOrUUID& getNamespaceOrUUID() const { return _nssOrUUID; }
    NamespaceStringOrUUID& getNamespaceOrUUID() { return _nssOrUUID; }

    /**
     * The query predicate. If unspecified, then all documents in the collection will match the predicate.
     */
    const mongo::BSONObj& getFilter() const { return _filter; }
    void setFilter(mongo::BSONObj value) & {  _filter = std::move(value);  }

    /**
     * The projection specification to determine which fields to include in the returned documents.
     */
    const mongo::BSONObj& getProjection() const { return _projection; }
    void setProjection(mongo::BSONObj value) & {  _projection = std::move(value);  }

    /**
     * The sort specification for the ordering of the results.
     */
    const mongo::BSONObj& getSort() const { return _sort; }
    void setSort(mongo::BSONObj value) & {  _sort = std::move(value);  }

    /**
     * Specify either the index name as a string or the index key pattern. If specified, then the query system will only consider plans using the hinted index.
     */
    const mongo::BSONObj& getHint() const { return _hint; }
    void setHint(mongo::BSONObj value) & {  _hint = std::move(value);  }

    /**
     * Specifies the collation to use for the operation.
     */
    const mongo::BSONObj& getCollation() const { return _collation; }
    void setCollation(mongo::BSONObj value) & {  _collation = std::move(value);  }

    /**
     * Number of documents to skip.
     */
    const boost::optional<std::int64_t> getSkip() const& { return _skip; }
    void getSkip() && = delete;
    void setSkip(boost::optional<std::int64_t> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get();
        validateSkip(_tmpValue);
        _skip = std::move(_tmpValue);
    } else {
        _skip = boost::none;
    }
      }

    /**
     * The maximum number of documents to return.
     */
    const boost::optional<std::int64_t> getLimit() const& { return _limit; }
    void getLimit() && = delete;
    void setLimit(boost::optional<std::int64_t> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get();
        validateLimit(_tmpValue);
        _limit = std::move(_tmpValue);
    } else {
        _limit = boost::none;
    }
      }

    /**
     * The number of documents to return in the first batch.
     */
    const boost::optional<std::int64_t> getBatchSize() const& { return _batchSize; }
    void getBatchSize() && = delete;
    void setBatchSize(boost::optional<std::int64_t> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get();
        validateBatchSize(_tmpValue);
        _batchSize = std::move(_tmpValue);
    } else {
        _batchSize = boost::none;
    }
      }

    /**
     * Deprecated. Should use batchSize.
     */
    const boost::optional<std::int64_t> getNtoreturn() const& { return _ntoreturn; }
    void getNtoreturn() && = delete;
    void setNtoreturn(boost::optional<std::int64_t> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get();
        validateNtoreturn(_tmpValue);
        _ntoreturn = std::move(_tmpValue);
    } else {
        _ntoreturn = boost::none;
    }
      }

    /**
     * Determines whether to close the cursor after the first batch.
     */
    const mongo::OptionalBool& getSingleBatch() const { return _singleBatch; }
    void setSingleBatch(mongo::OptionalBool value) & {  _singleBatch = std::move(value);  }

    /**
     * Use allowDiskUse to allow MongoDB to use temporary files on disk to store data exceeding the 100 megabyte memory limit while processing a blocking sort operation.
     */
    const mongo::OptionalBool& getAllowDiskUse() const { return _allowDiskUse; }
    void setAllowDiskUse(mongo::OptionalBool value) & {  _allowDiskUse = std::move(value);  }

    /**
     * The inclusive lower bound for a specific index.
     */
    const mongo::BSONObj& getMin() const { return _min; }
    void setMin(mongo::BSONObj value) & {  _min = std::move(value);  }

    /**
     * The exclusive upper bound for a specific index.
     */
    const mongo::BSONObj& getMax() const { return _max; }
    void setMax(mongo::BSONObj value) & {  _max = std::move(value);  }

    /**
     * If true, returns only the index keys in the resulting documents.
     */
    const mongo::OptionalBool& getReturnKey() const { return _returnKey; }
    void setReturnKey(mongo::OptionalBool value) & {  _returnKey = std::move(value);  }

    /**
     * Determines whether to return the record identifier for each document.
     */
    const mongo::OptionalBool& getShowRecordId() const { return _showRecordId; }
    void setShowRecordId(mongo::OptionalBool value) & {  _showRecordId = std::move(value);  }

    /**
     * Deprecated. A mechanism to specify readPreference.
     */
    const mongo::BSONObj& getUnwrappedReadPref() const { return _unwrappedReadPref; }
    void setUnwrappedReadPref(mongo::BSONObj value) & {  _unwrappedReadPref = std::move(value);  }

    /**
     * Returns a tailable cursor for a capped collections.
     */
    const mongo::OptionalBool& getTailable() const { return _tailable; }
    void setTailable(mongo::OptionalBool value) & {  _tailable = std::move(value);  }

    /**
     * Deprecated. An internal command for replaying a replica set’s oplog.
     */
    const boost::optional<bool> getOplogReplay() const& { return _oplogReplay; }
    void getOplogReplay() && = delete;
    void setOplogReplay(boost::optional<bool> value) & {  _oplogReplay = std::move(value);  }

    /**
     * Prevents the server from timing out idle cursors after an inactivity period.
     */
    const mongo::OptionalBool& getNoCursorTimeout() const { return _noCursorTimeout; }
    void setNoCursorTimeout(mongo::OptionalBool value) & {  _noCursorTimeout = std::move(value);  }

    /**
     * Use in conjunction with the tailable option to block a getMore command on the cursor temporarily if at the end of data rather than returning no data.
     */
    const mongo::OptionalBool& getAwaitData() const { return _awaitData; }
    void setAwaitData(mongo::OptionalBool value) & {  _awaitData = std::move(value);  }

    /**
     * For queries against a sharded collection, allows the command (or subsequent getMore commands) to return partial results, rather than an error, if one or more queried shards are unavailable.
     */
    const mongo::OptionalBool& getAllowPartialResults() const { return _allowPartialResults; }
    void setAllowPartialResults(mongo::OptionalBool value) & {  _allowPartialResults = std::move(value);  }

    /**
     * Allows user defined variables to be used inside $expr.
     */
    const boost::optional<mongo::BSONObj>& getLet() const& { return _let; }
    void getLet() && = delete;
    void setLet(boost::optional<mongo::BSONObj> value) & {  _let = std::move(value);  }

    /**
     * Deprecated.
     */
    const boost::optional<mongo::BSONObj>& getOptions() const& { return _options; }
    void getOptions() && = delete;
    void setOptions(boost::optional<mongo::BSONObj> value) & {  _options = std::move(value);  }

    /**
     * Deprecated.
     */
    const boost::optional<std::int64_t> getTerm() const& { return _term; }
    void getTerm() && = delete;
    void setTerm(boost::optional<std::int64_t> value) & {  _term = std::move(value);  }

    /**
     * Deprecated.
     */
    const mongo::OptionalBool& getReadOnce() const { return _readOnce; }
    void setReadOnce(mongo::OptionalBool value) & {  _readOnce = std::move(value);  }

    /**
     * Deprecated.
     */
    const mongo::OptionalBool& getAllowSpeculativeMajorityRead() const { return _allowSpeculativeMajorityRead; }
    void setAllowSpeculativeMajorityRead(mongo::OptionalBool value) & {  _allowSpeculativeMajorityRead = std::move(value);  }

    /**
     * Deprecated.
     */
    const mongo::OptionalBool& getRequestResumeToken() const { return _requestResumeToken; }
    void setRequestResumeToken(mongo::OptionalBool value) & {  _requestResumeToken = std::move(value);  }

    /**
     * Deprecated.
     */
    const mongo::BSONObj& getResumeAfter() const { return _resumeAfter; }
    void setResumeAfter(mongo::BSONObj value) & {  _resumeAfter = std::move(value);  }

    /**
     * An internal parameter used to determine the serialization format for sort keys. TODO SERVER-47065: A 4.7+ node still has to accept the '_use44SortKeys' field, since it could be included in a command sent from a 4.4 mongos. When 5.0 becomes last-lts, this code to tolerate the '_use44SortKeys' field can be deleted.
     */
    const boost::optional<bool> get_use44SortKeys() const& { return __use44SortKeys; }
    void get_use44SortKeys() && = delete;
    void set_use44SortKeys(boost::optional<bool> value) & {  __use44SortKeys = std::move(value);  }

    /**
     * The cumulative time limit in milliseconds for processing operations on the cursor.
     */
    const boost::optional<std::int32_t> getMaxTimeMS() const& { return _maxTimeMS; }
    void getMaxTimeMS() && = delete;
    void setMaxTimeMS(boost::optional<std::int32_t> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get();
        validateMaxTimeMS(_tmpValue);
        _maxTimeMS = std::move(_tmpValue);
    } else {
        _maxTimeMS = boost::none;
    }
      }

    /**
     * Specifies the read concern.
     */
    const boost::optional<mongo::BSONObj>& getReadConcern() const& { return _readConcern; }
    void getReadConcern() && = delete;
    void setReadConcern(boost::optional<mongo::BSONObj> value) & {  _readConcern = std::move(value);  }

    /**
     * A collection of values that do not change once computed.
     */
    const boost::optional<mongo::LegacyRuntimeConstants>& getLegacyRuntimeConstants() const& { return _legacyRuntimeConstants; }
    void getLegacyRuntimeConstants() && = delete;
    void setLegacyRuntimeConstants(boost::optional<mongo::LegacyRuntimeConstants> value) & {  _legacyRuntimeConstants = std::move(value);  }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    void validateSkip(const std::int64_t value);
    void validateSkip(IDLParserErrorContext& ctxt, const std::int64_t value);

    void validateLimit(const std::int64_t value);
    void validateLimit(IDLParserErrorContext& ctxt, const std::int64_t value);

    void validateBatchSize(const std::int64_t value);
    void validateBatchSize(IDLParserErrorContext& ctxt, const std::int64_t value);

    void validateNtoreturn(const std::int64_t value);
    void validateNtoreturn(IDLParserErrorContext& ctxt, const std::int64_t value);

    void validateMaxTimeMS(const std::int32_t value);
    void validateMaxTimeMS(IDLParserErrorContext& ctxt, const std::int32_t value);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;


    NamespaceStringOrUUID _nssOrUUID;

    mongo::BSONObj _filter{mongo::BSONObj()};
    mongo::BSONObj _projection{mongo::BSONObj()};
    mongo::BSONObj _sort{mongo::BSONObj()};
    mongo::BSONObj _hint{mongo::BSONObj()};
    mongo::BSONObj _collation{mongo::BSONObj()};
    boost::optional<std::int64_t> _skip;
    boost::optional<std::int64_t> _limit;
    boost::optional<std::int64_t> _batchSize;
    boost::optional<std::int64_t> _ntoreturn;
    mongo::OptionalBool _singleBatch{mongo::OptionalBool()};
    mongo::OptionalBool _allowDiskUse{mongo::OptionalBool()};
    mongo::BSONObj _min{mongo::BSONObj()};
    mongo::BSONObj _max{mongo::BSONObj()};
    mongo::OptionalBool _returnKey{mongo::OptionalBool()};
    mongo::OptionalBool _showRecordId{mongo::OptionalBool()};
    mongo::BSONObj _unwrappedReadPref{mongo::BSONObj()};
    mongo::OptionalBool _tailable{mongo::OptionalBool()};
    boost::optional<bool> _oplogReplay;
    mongo::OptionalBool _noCursorTimeout{mongo::OptionalBool()};
    mongo::OptionalBool _awaitData{mongo::OptionalBool()};
    mongo::OptionalBool _allowPartialResults{mongo::OptionalBool()};
    boost::optional<mongo::BSONObj> _let;
    boost::optional<mongo::BSONObj> _options;
    boost::optional<std::int64_t> _term;
    mongo::OptionalBool _readOnce{mongo::OptionalBool()};
    mongo::OptionalBool _allowSpeculativeMajorityRead{mongo::OptionalBool()};
    mongo::OptionalBool _requestResumeToken{mongo::OptionalBool()};
    mongo::BSONObj _resumeAfter{mongo::BSONObj()};
    boost::optional<bool> __use44SortKeys;
    boost::optional<std::int32_t> _maxTimeMS;
    boost::optional<mongo::BSONObj> _readConcern;
    boost::optional<mongo::LegacyRuntimeConstants> _legacyRuntimeConstants;
    std::string _dbName;
    bool _hasDbName : 1;
};


template <typename Derived>
class FindCmdVersion1Gen : public TypedCommand<Derived> {
    using _TypedCommandInvocationBase = typename TypedCommand<Derived>::InvocationBase;

public:
    using Request = FindCommandRequest;
    using Reply = mongo::CursorInitialReply;

    virtual ~FindCmdVersion1Gen() = default;

    virtual const std::set<std::string>& apiVersions() const final {
        return kApiVersions1;
    }
    virtual const std::set<std::string>& deprecatedApiVersions() const final {
        return kNoApiVersions;
    }
    const AuthorizationContract* getAuthorizationContract() const final { return &Request::kAuthorizationContract; } 

    class InvocationBaseGen : public _TypedCommandInvocationBase {
    public:
        using _TypedCommandInvocationBase::_TypedCommandInvocationBase;
        virtual Reply typedRun(OperationContext* opCtx) = 0;
    };
};
}  // namespace mongo
