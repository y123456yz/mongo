/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/query/getmore_command_gen.h --output build/opt/mongo/db/query/getmore_command_gen.cpp src/mongo/db/query/getmore_command.idl
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
#include "mongo/db/query/cursor_response_gen.h"
#include "mongo/db/query/query_request_helper.h"
#include "mongo/db/repl/optime.h"
#include "mongo/idl/basic_types.h"
#include "mongo/idl/basic_types_gen.h"
#include "mongo/idl/idl_parser.h"
#include "mongo/rpc/op_msg.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/util/uuid.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {

/**
 * Parser for the getMore command.
 */
class GetMoreCommandRequest {
public:
    using Reply = mongo::CursorGetMoreReply;
    static constexpr auto kCommandParameterFieldName = "getMore"_sd;
    static constexpr auto kBatchSizeFieldName = "batchSize"_sd;
    static constexpr auto kCollectionFieldName = "collection"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kLastKnownCommittedOpTimeFieldName = "lastKnownCommittedOpTime"_sd;
    static constexpr auto kMaxTimeMSFieldName = "maxTimeMS"_sd;
    static constexpr auto kTermFieldName = "term"_sd;
    static constexpr auto kCommandName = "getMore"_sd;

    explicit GetMoreCommandRequest(const std::int64_t commandParameter);
    explicit GetMoreCommandRequest(const std::int64_t commandParameter, std::string collection);

    static GetMoreCommandRequest parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static GetMoreCommandRequest parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    std::int64_t getCommandParameter() const { return _commandParameter; }

    const StringData getCollection() const& { return _collection; }
    void getCollection() && = delete;
    void setCollection(StringData value) & { auto _tmpValue = value.toString(); validateCollection(_tmpValue); _collection = std::move(_tmpValue); _hasCollection = true; }

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
     * The awaitData timeout.
     */
    const boost::optional<std::int64_t> getMaxTimeMS() const& { return _maxTimeMS; }
    void getMaxTimeMS() && = delete;
    void setMaxTimeMS(boost::optional<std::int64_t> value) & {  _maxTimeMS = std::move(value);  }

    const boost::optional<std::int64_t> getTerm() const& { return _term; }
    void getTerm() && = delete;
    void setTerm(boost::optional<std::int64_t> value) & {  _term = std::move(value);  }

    const boost::optional<mongo::repl::OpTime>& getLastKnownCommittedOpTime() const& { return _lastKnownCommittedOpTime; }
    void getLastKnownCommittedOpTime() && = delete;
    void setLastKnownCommittedOpTime(boost::optional<mongo::repl::OpTime> value) & {  _lastKnownCommittedOpTime = std::move(value);  }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    void validateCollection(const std::string& value);
    void validateCollection(IDLParserErrorContext& ctxt, const std::string& value);

    void validateBatchSize(const std::int64_t value);
    void validateBatchSize(IDLParserErrorContext& ctxt, const std::int64_t value);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;


    std::int64_t _commandParameter;

    std::string _collection;
    boost::optional<std::int64_t> _batchSize;
    boost::optional<std::int64_t> _maxTimeMS;
    boost::optional<std::int64_t> _term;
    boost::optional<mongo::repl::OpTime> _lastKnownCommittedOpTime;
    std::string _dbName;
    bool _hasCollection : 1;
    bool _hasDbName : 1;
};


template <typename Derived>
class GetMoreCmdVersion1Gen : public TypedCommand<Derived> {
    using _TypedCommandInvocationBase = typename TypedCommand<Derived>::InvocationBase;

public:
    using Request = GetMoreCommandRequest;
    using Reply = mongo::CursorGetMoreReply;

    virtual ~GetMoreCmdVersion1Gen() = default;

    virtual const std::set<std::string>& apiVersions() const final {
        return kApiVersions1;
    }
    virtual const std::set<std::string>& deprecatedApiVersions() const final {
        return kNoApiVersions;
    }
    class InvocationBaseGen : public _TypedCommandInvocationBase {
    public:
        using _TypedCommandInvocationBase::_TypedCommandInvocationBase;
        virtual Reply typedRun(OperationContext* opCtx) = 0;
    };
};
}  // namespace mongo
