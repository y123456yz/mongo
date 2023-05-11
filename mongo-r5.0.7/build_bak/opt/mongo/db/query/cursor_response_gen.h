/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/query/cursor_response_gen.h --output build/opt/mongo/db/query/cursor_response_gen.cpp src/mongo/db/query/cursor_response.idl
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
 * Common fields of initial and subsequent cursor responses.
 */
class ResponseCursorBase {
public:
    static constexpr auto kAtClusterTimeFieldName = "atClusterTime"_sd;
    static constexpr auto kCursorIdFieldName = "id"_sd;
    static constexpr auto kInvalidatedFieldName = "invalidated"_sd;
    static constexpr auto kNsFieldName = "ns"_sd;
    static constexpr auto kPartialResultsReturnedFieldName = "partialResultsReturned"_sd;
    static constexpr auto kPostBatchResumeTokenFieldName = "postBatchResumeToken"_sd;

    ResponseCursorBase();
    ResponseCursorBase(std::int64_t cursorId, mongo::NamespaceString ns);

    static ResponseCursorBase parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * The cursor id of the cursor.
     */
    std::int64_t getCursorId() const { return _cursorId; }
    void setCursorId(std::int64_t value) & {  _cursorId = std::move(value); _hasCursorId = true; }

    /**
     * The namespace of the cursor.
     */
    const mongo::NamespaceString& getNs() const { return _ns; }
    void setNs(mongo::NamespaceString value) & {  _ns = std::move(value); _hasNs = true; }

    /**
     * An optional resume token object.
     */
    const boost::optional<mongo::BSONObj>& getPostBatchResumeToken() const& { return _postBatchResumeToken; }
    void getPostBatchResumeToken() && = delete;
    void setPostBatchResumeToken(boost::optional<mongo::BSONObj> value) & {  _postBatchResumeToken = std::move(value);  }

    /**
     * The time stamp at which the response is being returned.
     */
    const boost::optional<mongo::Timestamp>& getAtClusterTime() const& { return _atClusterTime; }
    void getAtClusterTime() && = delete;
    void setAtClusterTime(boost::optional<mongo::Timestamp> value) & {  _atClusterTime = std::move(value);  }

    /**
     * Boolean represents whether partial results are being returned.
     */
    const mongo::OptionalBool& getPartialResultsReturned() const { return _partialResultsReturned; }
    void setPartialResultsReturned(mongo::OptionalBool value) & {  _partialResultsReturned = std::move(value);  }

    /**
     * Boolean represents if the cursor has been invalidated.
     */
    const mongo::OptionalBool& getInvalidated() const { return _invalidated; }
    void setInvalidated(mongo::OptionalBool value) & {  _invalidated = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    std::int64_t _cursorId;
    mongo::NamespaceString _ns;
    boost::optional<mongo::BSONObj> _postBatchResumeToken;
    boost::optional<mongo::Timestamp> _atClusterTime;
    mongo::OptionalBool _partialResultsReturned{mongo::OptionalBool()};
    mongo::OptionalBool _invalidated{mongo::OptionalBool()};
    bool _hasCursorId : 1;
    bool _hasNs : 1;
};

/**
 * A struct representing an initial response cursor.
 */
class InitialResponseCursor {
public:
    static constexpr auto kResponseCursorBaseFieldName = "ResponseCursorBase"_sd;
    static constexpr auto kAtClusterTimeFieldName = "atClusterTime"_sd;
    static constexpr auto kCursorIdFieldName = "id"_sd;
    static constexpr auto kFirstBatchFieldName = "firstBatch"_sd;
    static constexpr auto kInvalidatedFieldName = "invalidated"_sd;
    static constexpr auto kNsFieldName = "ns"_sd;
    static constexpr auto kPartialResultsReturnedFieldName = "partialResultsReturned"_sd;
    static constexpr auto kPostBatchResumeTokenFieldName = "postBatchResumeToken"_sd;

    InitialResponseCursor();
    InitialResponseCursor(std::vector<mongo::BSONObj> firstBatch);

    static InitialResponseCursor parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Common fields of initial and subsequent cursor responses.
     */
    const mongo::ResponseCursorBase& getResponseCursorBase() const { return _responseCursorBase; }
    mongo::ResponseCursorBase& getResponseCursorBase() { return _responseCursorBase; }
    void setResponseCursorBase(mongo::ResponseCursorBase value) & {  _responseCursorBase = std::move(value);  }

    /**
     * The cursor id of the cursor.
     */
     std::int64_t getCursorId() const { return _responseCursorBase.getCursorId(); }
    /**
     * The namespace of the cursor.
     */
    const  mongo::NamespaceString& getNs() const { return _responseCursorBase.getNs(); }
    /**
     * An optional resume token object.
     */
    const  boost::optional<mongo::BSONObj>& getPostBatchResumeToken() const { return _responseCursorBase.getPostBatchResumeToken(); }
    /**
     * The time stamp at which the response is being returned.
     */
    const  boost::optional<mongo::Timestamp>& getAtClusterTime() const { return _responseCursorBase.getAtClusterTime(); }
    /**
     * Boolean represents whether partial results are being returned.
     */
    const  mongo::OptionalBool& getPartialResultsReturned() const { return _responseCursorBase.getPartialResultsReturned(); }
    /**
     * Boolean represents if the cursor has been invalidated.
     */
    const  mongo::OptionalBool& getInvalidated() const { return _responseCursorBase.getInvalidated(); }
    /**
     * The first batch of the cursor.
     */
    const std::vector<mongo::BSONObj>& getFirstBatch() const& { return _firstBatch; }
    void getFirstBatch() && = delete;
    void setFirstBatch(std::vector<mongo::BSONObj> value) & {  _firstBatch = std::move(value); _hasFirstBatch = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::ResponseCursorBase _responseCursorBase;
    std::vector<mongo::BSONObj> _firstBatch;
    bool _hasFirstBatch : 1;
};

/**
 * A struct representing a initial cursor reply.
 */
class CursorInitialReply {
public:
    static constexpr auto kCursorFieldName = "cursor"_sd;
    static constexpr auto kVarsFieldName = "vars"_sd;

    CursorInitialReply();
    CursorInitialReply(mongo::InitialResponseCursor cursor);

    static CursorInitialReply parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * A response cursor object.
     */
    const mongo::InitialResponseCursor& getCursor() const { return _cursor; }
    mongo::InitialResponseCursor& getCursor() { return _cursor; }
    void setCursor(mongo::InitialResponseCursor value) & {  _cursor = std::move(value); _hasCursor = true; }

    /**
     * An optional field containing additional response information for the query.
     */
    const boost::optional<mongo::BSONObj>& getVars() const& { return _vars; }
    void getVars() && = delete;
    void setVars(boost::optional<mongo::BSONObj> value) & {  _vars = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::InitialResponseCursor _cursor;
    boost::optional<mongo::BSONObj> _vars;
    bool _hasCursor : 1;
};

/**
 * A struct representing a subsequent response cursor.
 */
class GetMoreResponseCursor {
public:
    static constexpr auto kResponseCursorBaseFieldName = "ResponseCursorBase"_sd;
    static constexpr auto kAtClusterTimeFieldName = "atClusterTime"_sd;
    static constexpr auto kCursorIdFieldName = "id"_sd;
    static constexpr auto kInvalidatedFieldName = "invalidated"_sd;
    static constexpr auto kNextBatchFieldName = "nextBatch"_sd;
    static constexpr auto kNsFieldName = "ns"_sd;
    static constexpr auto kPartialResultsReturnedFieldName = "partialResultsReturned"_sd;
    static constexpr auto kPostBatchResumeTokenFieldName = "postBatchResumeToken"_sd;

    GetMoreResponseCursor();
    GetMoreResponseCursor(std::vector<mongo::BSONObj> nextBatch);

    static GetMoreResponseCursor parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Common fields of initial and subsequent cursor responses.
     */
    const mongo::ResponseCursorBase& getResponseCursorBase() const { return _responseCursorBase; }
    mongo::ResponseCursorBase& getResponseCursorBase() { return _responseCursorBase; }
    void setResponseCursorBase(mongo::ResponseCursorBase value) & {  _responseCursorBase = std::move(value);  }

    /**
     * The cursor id of the cursor.
     */
     std::int64_t getCursorId() const { return _responseCursorBase.getCursorId(); }
    /**
     * The namespace of the cursor.
     */
    const  mongo::NamespaceString& getNs() const { return _responseCursorBase.getNs(); }
    /**
     * An optional resume token object.
     */
    const  boost::optional<mongo::BSONObj>& getPostBatchResumeToken() const { return _responseCursorBase.getPostBatchResumeToken(); }
    /**
     * The time stamp at which the response is being returned.
     */
    const  boost::optional<mongo::Timestamp>& getAtClusterTime() const { return _responseCursorBase.getAtClusterTime(); }
    /**
     * Boolean represents whether partial results are being returned.
     */
    const  mongo::OptionalBool& getPartialResultsReturned() const { return _responseCursorBase.getPartialResultsReturned(); }
    /**
     * Boolean represents if the cursor has been invalidated.
     */
    const  mongo::OptionalBool& getInvalidated() const { return _responseCursorBase.getInvalidated(); }
    /**
     * The subsequent batch of the cursor.
     */
    const std::vector<mongo::BSONObj>& getNextBatch() const& { return _nextBatch; }
    void getNextBatch() && = delete;
    void setNextBatch(std::vector<mongo::BSONObj> value) & {  _nextBatch = std::move(value); _hasNextBatch = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::ResponseCursorBase _responseCursorBase;
    std::vector<mongo::BSONObj> _nextBatch;
    bool _hasNextBatch : 1;
};

/**
 * A struct representing a getMore cursor reply.
 */
class CursorGetMoreReply {
public:
    static constexpr auto kCursorFieldName = "cursor"_sd;

    CursorGetMoreReply();
    CursorGetMoreReply(mongo::GetMoreResponseCursor cursor);

    static CursorGetMoreReply parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * A response cursor object.
     */
    const mongo::GetMoreResponseCursor& getCursor() const { return _cursor; }
    mongo::GetMoreResponseCursor& getCursor() { return _cursor; }
    void setCursor(mongo::GetMoreResponseCursor value) & {  _cursor = std::move(value); _hasCursor = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::GetMoreResponseCursor _cursor;
    bool _hasCursor : 1;
};

}  // namespace mongo
