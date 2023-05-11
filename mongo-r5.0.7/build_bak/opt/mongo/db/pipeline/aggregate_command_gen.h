/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/pipeline/aggregate_command_gen.h --output build/opt/mongo/db/pipeline/aggregate_command_gen.cpp src/mongo/db/pipeline/aggregate_command.idl
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
#include "mongo/db/commands.h"
#include "mongo/db/namespace_string.h"
#include "mongo/db/pipeline/aggregation_request_helper.h"
#include "mongo/db/pipeline/exchange_spec_gen.h"
#include "mongo/db/pipeline/legacy_runtime_constants_gen.h"
#include "mongo/db/query/count_request.h"
#include "mongo/db/query/cursor_response_gen.h"
#include "mongo/db/query/explain_options.h"
#include "mongo/db/query/hint_parser.h"
#include "mongo/db/write_concern_options.h"
#include "mongo/idl/basic_types.h"
#include "mongo/idl/basic_types_gen.h"
#include "mongo/idl/idl_parser.h"
#include "mongo/rpc/op_msg.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/util/uuid.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {

/**
 * Represents the user-supplied options to the aggregate command.
 */
class AggregateCommandRequest {
public:
    using Reply = mongo::CursorInitialReply;
    static constexpr auto kAllowDiskUseFieldName = "allowDiskUse"_sd;
    static constexpr auto kBypassDocumentValidationFieldName = "bypassDocumentValidation"_sd;
    static constexpr auto kCollationFieldName = "collation"_sd;
    static constexpr auto kCollectionUUIDFieldName = "collectionUUID"_sd;
    static constexpr auto kCursorFieldName = "cursor"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kExchangeFieldName = "exchange"_sd;
    static constexpr auto kExplainFieldName = "explain"_sd;
    static constexpr auto kFromMongosFieldName = "fromMongos"_sd;
    static constexpr auto kHintFieldName = "hint"_sd;
    static constexpr auto kIsMapReduceCommandFieldName = "isMapReduceCommand"_sd;
    static constexpr auto kLegacyRuntimeConstantsFieldName = "runtimeConstants"_sd;
    static constexpr auto kLetFieldName = "let"_sd;
    static constexpr auto kMaxTimeMSFieldName = "maxTimeMS"_sd;
    static constexpr auto kNeedsMergeFieldName = "needsMerge"_sd;
    static constexpr auto kPipelineFieldName = "pipeline"_sd;
    static constexpr auto kReadConcernFieldName = "readConcern"_sd;
    static constexpr auto kRequestReshardingResumeTokenFieldName = "$_requestReshardingResumeToken"_sd;
    static constexpr auto kUnwrappedReadPrefFieldName = "$queryOptions"_sd;
    static constexpr auto kUse44SortKeysFieldName = "use44SortKeys"_sd;
    static constexpr auto kUseNewUpsertFieldName = "useNewUpsert"_sd;
    static constexpr auto kWriteConcernFieldName = "writeConcern"_sd;
    static constexpr auto kCommandName = "aggregate"_sd;

    static AuthorizationContract kAuthorizationContract;

    explicit AggregateCommandRequest(const NamespaceString nss);
    AggregateCommandRequest(const NamespaceString nss, std::vector<mongo::BSONObj> pipeline);

    static AggregateCommandRequest parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static AggregateCommandRequest parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const NamespaceString& getNamespace() const { return _nss; }

    /**
     * An unparsed version of the pipeline.
     */
    const std::vector<mongo::BSONObj>& getPipeline() const { return _pipeline; }
    void setPipeline(std::vector<mongo::BSONObj> value) & {  _pipeline = std::move(value); _hasPipeline = true; }

    /**
     * Specifies to return the information on the processing of the pipeline.
     */
    const boost::optional<mongo::ExplainOptions::Verbosity>& getExplain() const& { return _explain; }
    void getExplain() && = delete;
    void setExplain(boost::optional<mongo::ExplainOptions::Verbosity> value) & {  _explain = std::move(value);  }

    /**
     * Enables writing to temporary files.
     */
    const mongo::OptionalBool& getAllowDiskUse() const { return _allowDiskUse; }
    void setAllowDiskUse(mongo::OptionalBool value) & {  _allowDiskUse = std::move(value);  }

    /**
     * To indicate a cursor with a non-default batch size.
     */
    const mongo::SimpleCursorOptions& getCursor() const { return _cursor; }
    void setCursor(mongo::SimpleCursorOptions value) & {  _cursor = std::move(value);  }

    /**
     * Specifies a time limit in milliseconds for processing operations on a cursor. If you do not specify a value for maxTimeMS, operations will not time out.
     */
    const boost::optional<std::int64_t> getMaxTimeMS() const& { return _maxTimeMS; }
    void getMaxTimeMS() && = delete;
    void setMaxTimeMS(boost::optional<std::int64_t> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get();
        validateMaxTimeMS(_tmpValue);
        _maxTimeMS = std::move(_tmpValue);
    } else {
        _maxTimeMS = boost::none;
    }
      }

    /**
     * True if this should bypass the document validation.
     */
    const boost::optional<bool> getBypassDocumentValidation() const& { return _bypassDocumentValidation; }
    void getBypassDocumentValidation() && = delete;
    void setBypassDocumentValidation(boost::optional<bool> value) & {  _bypassDocumentValidation = std::move(value);  }

    /**
     * Specifies the read concern.
     */
    const boost::optional<mongo::BSONObj>& getReadConcern() const& { return _readConcern; }
    void getReadConcern() && = delete;
    void setReadConcern(boost::optional<mongo::BSONObj> value) & {  _readConcern = std::move(value);  }

    /**
     * Specifies the collation to use for the operation.
     */
    const boost::optional<mongo::BSONObj>& getCollation() const& { return _collation; }
    void getCollation() && = delete;
    void setCollation(boost::optional<mongo::BSONObj> value) & {  _collation = std::move(value);  }

    /**
     * The index name to use or the index specification document.
     */
    const boost::optional<mongo::BSONObj>& getHint() const& { return _hint; }
    void getHint() && = delete;
    void setHint(boost::optional<mongo::BSONObj> value) & {  _hint = std::move(value);  }

    /**
     * A document that expresses the write concern to use with the $out or $merge stage.
     */
    const boost::optional<mongo::WriteConcernOptions>& getWriteConcern() const& { return _writeConcern; }
    void getWriteConcern() && = delete;
    void setWriteConcern(boost::optional<mongo::WriteConcernOptions> value) & {  _writeConcern = std::move(value);  }

    /**
     * A document containing user-specified let parameter constants; i.e. values that do not change once computed.
     */
    const boost::optional<mongo::BSONObj>& getLet() const& { return _let; }
    void getLet() && = delete;
    void setLet(boost::optional<mongo::BSONObj> value) & {  _let = std::move(value);  }

    /**
     * True if this request represents the shards part of a split pipeline, and should produce mergeable output.
     */
    const mongo::OptionalBool& getNeedsMerge() const { return _needsMerge; }
    void setNeedsMerge(mongo::OptionalBool value) & {  _needsMerge = std::move(value);  }

    /**
     * True if this request originated from a mongoS.
     */
    const mongo::OptionalBool& getFromMongos() const { return _fromMongos; }
    void setFromMongos(mongo::OptionalBool value) & {  _fromMongos = std::move(value);  }

    /**
     * The unwrapped readPreference object, if one was given to us by the mongos command processor. This object will be empty when no readPreference is specified or if the request does not originate from mongos.
     */
    const boost::optional<mongo::BSONObj>& getUnwrappedReadPref() const& { return _unwrappedReadPref; }
    void getUnwrappedReadPref() && = delete;
    void setUnwrappedReadPref(boost::optional<mongo::BSONObj> value) & {  _unwrappedReadPref = std::move(value);  }

    /**
     * True if this requests resharding resume token.
     */
    const mongo::OptionalBool& getRequestReshardingResumeToken() const { return _requestReshardingResumeToken; }
    void setRequestReshardingResumeToken(mongo::OptionalBool value) & {  _requestReshardingResumeToken = std::move(value);  }

    /**
     * An optional exchange specification for this request. If set it means that the request represents a producer running as a part of the exchange machinery. This is an internal option; we do not expect it to be set on requests from users or drivers.
     */
    const boost::optional<mongo::ExchangeSpec>& getExchange() const& { return _exchange; }
    void getExchange() && = delete;
    void setExchange(boost::optional<mongo::ExchangeSpec> value) & {  _exchange = std::move(value);  }

    /**
     * A legacy way to specify constant variables available during execution. 'let' is now preferred.
     */
    const boost::optional<mongo::LegacyRuntimeConstants>& getLegacyRuntimeConstants() const& { return _legacyRuntimeConstants; }
    void getLegacyRuntimeConstants() && = delete;
    void setLegacyRuntimeConstants(boost::optional<mongo::LegacyRuntimeConstants> value) & {  _legacyRuntimeConstants = std::move(value);  }

    /**
     * True if an aggregation was invoked by the MapReduce command.
     */
    const mongo::OptionalBool& getIsMapReduceCommand() const { return _isMapReduceCommand; }
    void setIsMapReduceCommand(mongo::OptionalBool value) & {  _isMapReduceCommand = std::move(value);  }

    /**
     * The expected UUID of the namespace the aggregation executes on.
     */
    const boost::optional<mongo::UUID>& getCollectionUUID() const& { return _collectionUUID; }
    void getCollectionUUID() && = delete;
    void setCollectionUUID(boost::optional<mongo::UUID> value) & {  _collectionUUID = std::move(value);  }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    void validateMaxTimeMS(const std::int64_t value);
    void validateMaxTimeMS(IDLParserErrorContext& ctxt, const std::int64_t value);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;


    NamespaceString _nss;

    std::vector<mongo::BSONObj> _pipeline;
    boost::optional<mongo::ExplainOptions::Verbosity> _explain;
    mongo::OptionalBool _allowDiskUse{mongo::OptionalBool()};
    mongo::SimpleCursorOptions _cursor{SimpleCursorOptions()};
    boost::optional<std::int64_t> _maxTimeMS;
    boost::optional<bool> _bypassDocumentValidation;
    boost::optional<mongo::BSONObj> _readConcern;
    boost::optional<mongo::BSONObj> _collation;
    boost::optional<mongo::BSONObj> _hint;
    boost::optional<mongo::WriteConcernOptions> _writeConcern;
    boost::optional<mongo::BSONObj> _let;
    mongo::OptionalBool _needsMerge{mongo::OptionalBool()};
    mongo::OptionalBool _fromMongos{mongo::OptionalBool()};
    boost::optional<mongo::BSONObj> _unwrappedReadPref;
    mongo::OptionalBool _requestReshardingResumeToken{mongo::OptionalBool()};
    boost::optional<mongo::ExchangeSpec> _exchange;
    boost::optional<mongo::LegacyRuntimeConstants> _legacyRuntimeConstants;
    mongo::OptionalBool _isMapReduceCommand{mongo::OptionalBool()};
    boost::optional<mongo::UUID> _collectionUUID;
    std::string _dbName;
    bool _hasPipeline : 1;
    bool _hasDbName : 1;
};


template <typename Derived>
class AggregateCmdVersion1Gen : public TypedCommand<Derived> {
    using _TypedCommandInvocationBase = typename TypedCommand<Derived>::InvocationBase;

public:
    using Request = AggregateCommandRequest;
    using Reply = mongo::CursorInitialReply;

    virtual ~AggregateCmdVersion1Gen() = default;

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
