/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/ops/write_ops_gen.h --output build/opt/mongo/db/ops/write_ops_gen.cpp src/mongo/db/ops/write_ops.idl
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
#include "mongo/db/ops/write_ops_parsers.h"
#include "mongo/db/pipeline/legacy_runtime_constants_gen.h"
#include "mongo/db/query/hint_parser.h"
#include "mongo/db/repl/optime.h"
#include "mongo/idl/basic_types.h"
#include "mongo/idl/basic_types_gen.h"
#include "mongo/idl/idl_parser.h"
#include "mongo/rpc/op_msg.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/util/uuid.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {
namespace write_ops {

/**
 * Contains fields that is common in all the write commands reply.
 */
class WriteCommandReplyBase {
public:
    static constexpr auto kElectionIdFieldName = "electionId"_sd;
    static constexpr auto kNFieldName = "n"_sd;
    static constexpr auto kOpTimeFieldName = "opTime"_sd;
    static constexpr auto kWriteErrorsFieldName = "writeErrors"_sd;

    WriteCommandReplyBase();

    static WriteCommandReplyBase parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * For insert: number of documents inserted. For update: number of documents that matched the query predicate. For delete: number of documents deleted.
     */
    std::int32_t getN() const { return _n; }
    void setN(std::int32_t value) & {  _n = std::move(value);  }

    /**
     * Replication coordinator election id.
     */
    const boost::optional<mongo::OID>& getElectionId() const& { return _electionId; }
    void getElectionId() && = delete;
    void setElectionId(boost::optional<mongo::OID> value) & {  _electionId = std::move(value);  }

    /**
     * Operation time for the command.
     */
    const boost::optional<mongo::repl::OpTime>& getOpTime() const& { return _opTime; }
    void getOpTime() && = delete;
    void setOpTime(boost::optional<mongo::repl::OpTime> value) & {  _opTime = std::move(value);  }

    /**
     * Contains all the errors encoutered.
     */
    const boost::optional<std::vector<mongo::BSONObj>>& getWriteErrors() const& { return _writeErrors; }
    void getWriteErrors() && = delete;
    void setWriteErrors(boost::optional<std::vector<mongo::BSONObj>> value) & {  _writeErrors = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    std::int32_t _n{0};
    boost::optional<mongo::OID> _electionId;
    boost::optional<mongo::repl::OpTime> _opTime;
    boost::optional<std::vector<mongo::BSONObj>> _writeErrors;
};

/**
 * Contains information related to insert command reply.
 */
class InsertCommandReply {
public:
    static constexpr auto kElectionIdFieldName = "electionId"_sd;
    static constexpr auto kNFieldName = "n"_sd;
    static constexpr auto kOpTimeFieldName = "opTime"_sd;
    static constexpr auto kWriteCommandReplyBaseFieldName = "WriteCommandReplyBase"_sd;
    static constexpr auto kWriteErrorsFieldName = "writeErrors"_sd;

    InsertCommandReply();

    static InsertCommandReply parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Contains fields that is common in all the write commands reply.
     */
    const mongo::write_ops::WriteCommandReplyBase& getWriteCommandReplyBase() const { return _writeCommandReplyBase; }
    mongo::write_ops::WriteCommandReplyBase& getWriteCommandReplyBase() { return _writeCommandReplyBase; }
    void setWriteCommandReplyBase(mongo::write_ops::WriteCommandReplyBase value) & {  _writeCommandReplyBase = std::move(value);  }

    /**
     * For insert: number of documents inserted. For update: number of documents that matched the query predicate. For delete: number of documents deleted.
     */
     std::int32_t getN() const { return _writeCommandReplyBase.getN(); }
    /**
     * Replication coordinator election id.
     */
    const  boost::optional<mongo::OID>& getElectionId() const { return _writeCommandReplyBase.getElectionId(); }
    /**
     * Operation time for the command.
     */
    const  boost::optional<mongo::repl::OpTime>& getOpTime() const { return _writeCommandReplyBase.getOpTime(); }
    /**
     * Contains all the errors encoutered.
     */
    const  boost::optional<std::vector<mongo::BSONObj>>& getWriteErrors() const { return _writeCommandReplyBase.getWriteErrors(); }
protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::write_ops::WriteCommandReplyBase _writeCommandReplyBase;
};

/**
 * Contains documents that have been upserted.
 */
class Upserted {
public:
    static constexpr auto k_idFieldName = "_id"_sd;
    static constexpr auto kIndexFieldName = "index"_sd;

    Upserted();
    Upserted(std::int32_t index, mongo::IDLAnyTypeOwned _id);

    static Upserted parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Index of the document.
     */
    std::int32_t getIndex() const { return _index; }
    void setIndex(std::int32_t value) & {  _index = std::move(value); _hasIndex = true; }

    /**
     * ID of the document.
     */
    const mongo::IDLAnyTypeOwned& get_id() const { return __id; }
    void set_id(mongo::IDLAnyTypeOwned value) & {  __id = std::move(value); _has_id = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    std::int32_t _index;
    mongo::IDLAnyTypeOwned __id;
    bool _hasIndex : 1;
    bool _has_id : 1;
};

/**
 * Contains information related to update command reply.
 */
class UpdateCommandReply {
public:
    static constexpr auto kElectionIdFieldName = "electionId"_sd;
    static constexpr auto kNFieldName = "n"_sd;
    static constexpr auto kNModifiedFieldName = "nModified"_sd;
    static constexpr auto kOpTimeFieldName = "opTime"_sd;
    static constexpr auto kUpsertedFieldName = "upserted"_sd;
    static constexpr auto kWriteCommandReplyBaseFieldName = "WriteCommandReplyBase"_sd;
    static constexpr auto kWriteErrorsFieldName = "writeErrors"_sd;

    UpdateCommandReply();

    static UpdateCommandReply parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Contains fields that is common in all the write commands reply.
     */
    const mongo::write_ops::WriteCommandReplyBase& getWriteCommandReplyBase() const { return _writeCommandReplyBase; }
    mongo::write_ops::WriteCommandReplyBase& getWriteCommandReplyBase() { return _writeCommandReplyBase; }
    void setWriteCommandReplyBase(mongo::write_ops::WriteCommandReplyBase value) & {  _writeCommandReplyBase = std::move(value);  }

    /**
     * For insert: number of documents inserted. For update: number of documents that matched the query predicate. For delete: number of documents deleted.
     */
     std::int32_t getN() const { return _writeCommandReplyBase.getN(); }
    /**
     * Replication coordinator election id.
     */
    const  boost::optional<mongo::OID>& getElectionId() const { return _writeCommandReplyBase.getElectionId(); }
    /**
     * Operation time for the command.
     */
    const  boost::optional<mongo::repl::OpTime>& getOpTime() const { return _writeCommandReplyBase.getOpTime(); }
    /**
     * Contains all the errors encoutered.
     */
    const  boost::optional<std::vector<mongo::BSONObj>>& getWriteErrors() const { return _writeCommandReplyBase.getWriteErrors(); }
    /**
     * An array contains information about upserted documents.
     */
    const boost::optional<std::vector<mongo::write_ops::Upserted>>& getUpserted() const& { return _upserted; }
    void getUpserted() && = delete;
    void setUpserted(boost::optional<std::vector<mongo::write_ops::Upserted>> value) & {  _upserted = std::move(value);  }

    /**
     * Number of updated documents.
     */
    std::int32_t getNModified() const { return _nModified; }
    void setNModified(std::int32_t value) & {  _nModified = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::write_ops::WriteCommandReplyBase _writeCommandReplyBase;
    boost::optional<std::vector<mongo::write_ops::Upserted>> _upserted;
    std::int32_t _nModified{0};
};

/**
 * Contains information related to delete command reply.
 */
class DeleteCommandReply {
public:
    static constexpr auto kElectionIdFieldName = "electionId"_sd;
    static constexpr auto kNFieldName = "n"_sd;
    static constexpr auto kOpTimeFieldName = "opTime"_sd;
    static constexpr auto kWriteCommandReplyBaseFieldName = "WriteCommandReplyBase"_sd;
    static constexpr auto kWriteErrorsFieldName = "writeErrors"_sd;

    DeleteCommandReply();

    static DeleteCommandReply parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Contains fields that is common in all the write commands reply.
     */
    const mongo::write_ops::WriteCommandReplyBase& getWriteCommandReplyBase() const { return _writeCommandReplyBase; }
    mongo::write_ops::WriteCommandReplyBase& getWriteCommandReplyBase() { return _writeCommandReplyBase; }
    void setWriteCommandReplyBase(mongo::write_ops::WriteCommandReplyBase value) & {  _writeCommandReplyBase = std::move(value);  }

    /**
     * For insert: number of documents inserted. For update: number of documents that matched the query predicate. For delete: number of documents deleted.
     */
     std::int32_t getN() const { return _writeCommandReplyBase.getN(); }
    /**
     * Replication coordinator election id.
     */
    const  boost::optional<mongo::OID>& getElectionId() const { return _writeCommandReplyBase.getElectionId(); }
    /**
     * Operation time for the command.
     */
    const  boost::optional<mongo::repl::OpTime>& getOpTime() const { return _writeCommandReplyBase.getOpTime(); }
    /**
     * Contains all the errors encoutered.
     */
    const  boost::optional<std::vector<mongo::BSONObj>>& getWriteErrors() const { return _writeCommandReplyBase.getWriteErrors(); }
protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::write_ops::WriteCommandReplyBase _writeCommandReplyBase;
};

/**
 * Contains basic information included by all write commands
 */
class WriteCommandRequestBase {
public:
    static constexpr auto kBypassDocumentValidationFieldName = "bypassDocumentValidation"_sd;
    static constexpr auto kIsTimeseriesNamespaceFieldName = "isTimeseriesNamespace"_sd;
    static constexpr auto kOrderedFieldName = "ordered"_sd;
    static constexpr auto kStmtIdFieldName = "stmtId"_sd;
    static constexpr auto kStmtIdsFieldName = "stmtIds"_sd;

    WriteCommandRequestBase();

    static WriteCommandRequestBase parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Enables the operation to bypass document validation. This lets you write documents that do not meet the validation requirements.
     */
    bool getBypassDocumentValidation() const { return _bypassDocumentValidation; }
    void setBypassDocumentValidation(bool value) & {  _bypassDocumentValidation = std::move(value);  }

    /**
     * If true, then when an write statement fails, the command returns without executing the remaining statements. If false, then statements are allowed to be executed in parallel and if a statement fails, continue with the remaining statements, if any.
     */
    bool getOrdered() const { return _ordered; }
    void setOrdered(bool value) & {  _ordered = std::move(value);  }

    /**
     * A statement number relative to the transaction. If this field is set, the statement ids of the contained operation will be implicitly generated based on their offset, starting from the value given. This field is mutually exclusive with 'stmtIds'.
     */
    const boost::optional<std::int32_t> getStmtId() const& { return _stmtId; }
    void getStmtId() && = delete;
    void setStmtId(boost::optional<std::int32_t> value) & {  _stmtId = std::move(value);  }

    /**
     * An array of statement numbers relative to the transaction. If this field is set, its size must be exactly the same as the number of entries in the corresponding insert/update/delete request. If it is not set, the statement ids of the contained operation will be implicitly generated based on their offset, starting from 'stmtId' or 0 if 'stmtId' is not specified. This field is mutually exclusive with 'stmtId'.
     */
    const boost::optional<std::vector<std::int32_t>>& getStmtIds() const& { return _stmtIds; }
    void getStmtIds() && = delete;
    void setStmtIds(boost::optional<std::vector<std::int32_t>> value) & {  _stmtIds = std::move(value);  }

    /**
     * This flag is set to true when the write command was originally sent to the time-series view, but got rewritten to target time-series buckets namespace.
     */
    const mongo::OptionalBool& getIsTimeseriesNamespace() const { return _isTimeseriesNamespace; }
    void setIsTimeseriesNamespace(mongo::OptionalBool value) & {  _isTimeseriesNamespace = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    bool _bypassDocumentValidation{false};
    bool _ordered{true};
    boost::optional<std::int32_t> _stmtId;
    boost::optional<std::vector<std::int32_t>> _stmtIds;
    mongo::OptionalBool _isTimeseriesNamespace{mongo::OptionalBool()};
};

/**
 * Parser for the entries in the 'updates' array of an update command.
 */
class UpdateOpEntry {
public:
    static constexpr auto kArrayFiltersFieldName = "arrayFilters"_sd;
    static constexpr auto kCFieldName = "c"_sd;
    static constexpr auto kCollationFieldName = "collation"_sd;
    static constexpr auto kHintFieldName = "hint"_sd;
    static constexpr auto kMultiFieldName = "multi"_sd;
    static constexpr auto kQFieldName = "q"_sd;
    static constexpr auto kUFieldName = "u"_sd;
    static constexpr auto kUpsertFieldName = "upsert"_sd;
    static constexpr auto kUpsertSuppliedFieldName = "upsertSupplied"_sd;

    UpdateOpEntry();
    UpdateOpEntry(mongo::BSONObj q, mongo::write_ops::UpdateModification u);

    static UpdateOpEntry parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * The query that matches documents to update. Uses the same query selectors as used in the 'find' operation.
     */
    const mongo::BSONObj& getQ() const { return _q; }
    void setQ(mongo::BSONObj value) & {  _q = std::move(value); _hasQ = true; }

    /**
     * Set of modifications to apply.
     */
    const mongo::write_ops::UpdateModification& getU() const { return _u; }
    void setU(mongo::write_ops::UpdateModification value) & {  _u = std::move(value); _hasU = true; }

    /**
     * Specifies constant values that can be referred to in the pipeline performing a custom update.
     */
    const boost::optional<mongo::BSONObj>& getC() const& { return _c; }
    void getC() && = delete;
    void setC(boost::optional<mongo::BSONObj> value) & {  _c = std::move(value);  }

    /**
     * Specifies which array elements an update modifier should apply to.
     */
    const boost::optional<std::vector<mongo::BSONObj>>& getArrayFilters() const& { return _arrayFilters; }
    void getArrayFilters() && = delete;
    void setArrayFilters(boost::optional<std::vector<mongo::BSONObj>> value) & {  _arrayFilters = std::move(value);  }

    /**
     * Specifies the hint to use for the operation.
     */
    const mongo::BSONObj& getHint() const { return _hint; }
    void setHint(mongo::BSONObj value) & {  _hint = std::move(value);  }

    /**
     * If true, updates all documents that meet the query criteria. If false, limits the update to one document which meets the query criteria.
     */
    bool getMulti() const { return _multi; }
    void setMulti(bool value) & {  _multi = std::move(value);  }

    /**
     * If true, perform an insert if no documents match the query. If both upsert and multi are true and no documents match the query, the update operation inserts only a single document.
     */
    bool getUpsert() const { return _upsert; }
    void setUpsert(bool value) & {  _upsert = std::move(value);  }

    /**
     * Only applicable when upsert is true. If set, and if no documents match the query, the update subsystem will insert the document supplied as 'c.new' rather than generating a new document from the update spec.
     */
    const mongo::OptionalBool& getUpsertSupplied() const { return _upsertSupplied; }
    void setUpsertSupplied(mongo::OptionalBool value) & {  _upsertSupplied = std::move(value);  }

    /**
     * Specifies the collation to use for the operation.
     */
    const boost::optional<mongo::BSONObj>& getCollation() const& { return _collation; }
    void getCollation() && = delete;
    void setCollation(boost::optional<mongo::BSONObj> value) & {  _collation = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::BSONObj _q;
    mongo::write_ops::UpdateModification _u;
    boost::optional<mongo::BSONObj> _c;
    boost::optional<std::vector<mongo::BSONObj>> _arrayFilters;
    mongo::BSONObj _hint{mongo::BSONObj()};
    bool _multi{false};
    bool _upsert{false};
    mongo::OptionalBool _upsertSupplied{mongo::OptionalBool()};
    boost::optional<mongo::BSONObj> _collation;
    bool _hasQ : 1;
    bool _hasU : 1;
};

/**
 * Parser for the entries in the 'deletes' array of a delete command.
 */
class DeleteOpEntry {
public:
    static constexpr auto kCollationFieldName = "collation"_sd;
    static constexpr auto kHintFieldName = "hint"_sd;
    static constexpr auto kMultiFieldName = "limit"_sd;
    static constexpr auto kQFieldName = "q"_sd;

    DeleteOpEntry();
    DeleteOpEntry(mongo::BSONObj q, bool multi);

    static DeleteOpEntry parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * The query that matches documents to delete. Uses the same query selectors as used in the 'find' operation.
     */
    const mongo::BSONObj& getQ() const { return _q; }
    void setQ(mongo::BSONObj value) & {  _q = std::move(value); _hasQ = true; }

    /**
     * The number of matching documents to delete. Value of 0 deletes all matching documents and 1 deletes a single document.
     */
    bool getMulti() const { return _multi; }
    void setMulti(bool value) & {  _multi = std::move(value); _hasMulti = true; }

    /**
     * Specifies the hint to use for the operation.
     */
    const mongo::BSONObj& getHint() const { return _hint; }
    void setHint(mongo::BSONObj value) & {  _hint = std::move(value);  }

    /**
     * Specifies the collation to use for the operation.
     */
    const boost::optional<mongo::BSONObj>& getCollation() const& { return _collation; }
    void getCollation() && = delete;
    void setCollation(boost::optional<mongo::BSONObj> value) & {  _collation = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::BSONObj _q;
    bool _multi;
    mongo::BSONObj _hint{mongo::BSONObj()};
    boost::optional<mongo::BSONObj> _collation;
    bool _hasQ : 1;
    bool _hasMulti : 1;
};

/**
 * Contains execution details for the findAndModify command
 */
class FindAndModifyLastError {
public:
    static constexpr auto kNumDocsFieldName = "n"_sd;
    static constexpr auto kUpdatedExistingFieldName = "updatedExisting"_sd;
    static constexpr auto kUpsertedFieldName = "upserted"_sd;

    FindAndModifyLastError();
    FindAndModifyLastError(std::int32_t numDocs);

    static FindAndModifyLastError parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * The number of documents that were inserted/deleted or matched the update predicate.
     */
    std::int32_t getNumDocs() const { return _numDocs; }
    void setNumDocs(std::int32_t value) & {  _numDocs = std::move(value); _hasNumDocs = true; }

    /**
     * Whether an existing document was updated.
     */
    const boost::optional<bool> getUpdatedExisting() const& { return _updatedExisting; }
    void getUpdatedExisting() && = delete;
    void setUpdatedExisting(boost::optional<bool> value) & {  _updatedExisting = std::move(value);  }

    /**
     * The _id of the inserted document.
     */
    const boost::optional<mongo::IDLAnyTypeOwned>& getUpserted() const& { return _upserted; }
    void getUpserted() && = delete;
    void setUpserted(boost::optional<mongo::IDLAnyTypeOwned> value) & {  _upserted = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    std::int32_t _numDocs;
    boost::optional<bool> _updatedExisting;
    boost::optional<mongo::IDLAnyTypeOwned> _upserted;
    bool _hasNumDocs : 1;
};

/**
 * Parser for the response from a `findAndModify` command
 */
class FindAndModifyCommandReply {
public:
    static constexpr auto kLastErrorObjectFieldName = "lastErrorObject"_sd;
    static constexpr auto kValueFieldName = "value"_sd;

    FindAndModifyCommandReply();
    FindAndModifyCommandReply(mongo::write_ops::FindAndModifyLastError lastErrorObject);

    static FindAndModifyCommandReply parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    const mongo::write_ops::FindAndModifyLastError& getLastErrorObject() const { return _lastErrorObject; }
    mongo::write_ops::FindAndModifyLastError& getLastErrorObject() { return _lastErrorObject; }
    void setLastErrorObject(mongo::write_ops::FindAndModifyLastError value) & {  _lastErrorObject = std::move(value); _hasLastErrorObject = true; }

    /**
     * The document after the write, if the 'new' field of the request is true. Otherwise, the document before the write.
     */
    const boost::optional<mongo::BSONObj>& getValue() const& { return _value; }
    void getValue() && = delete;
    void setValue(boost::optional<mongo::BSONObj> value) & {  _value = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::write_ops::FindAndModifyLastError _lastErrorObject;
    boost::optional<mongo::BSONObj> _value;
    bool _hasLastErrorObject : 1;
};

/**
 * Parser for the 'insert' command.
 */
class InsertCommandRequest {
public:
    using Reply = mongo::write_ops::InsertCommandReply;
    static constexpr auto kBypassDocumentValidationFieldName = "bypassDocumentValidation"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kDocumentsFieldName = "documents"_sd;
    static constexpr auto kIsTimeseriesNamespaceFieldName = "isTimeseriesNamespace"_sd;
    static constexpr auto kOrderedFieldName = "ordered"_sd;
    static constexpr auto kStmtIdFieldName = "stmtId"_sd;
    static constexpr auto kStmtIdsFieldName = "stmtIds"_sd;
    static constexpr auto kWriteCommandRequestBaseFieldName = "WriteCommandRequestBase"_sd;
    static constexpr auto kCommandName = "insert"_sd;

    static AuthorizationContract kAuthorizationContract;

    explicit InsertCommandRequest(const NamespaceString nss);
    InsertCommandRequest(const NamespaceString nss, std::vector<mongo::BSONObj> documents);

    static InsertCommandRequest parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static InsertCommandRequest parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const NamespaceString& getNamespace() const { return _nss; }

    /**
     * Contains basic information included by all write commands
     */
    const mongo::write_ops::WriteCommandRequestBase& getWriteCommandRequestBase() const { return _writeCommandRequestBase; }
    mongo::write_ops::WriteCommandRequestBase& getWriteCommandRequestBase() { return _writeCommandRequestBase; }
    void setWriteCommandRequestBase(mongo::write_ops::WriteCommandRequestBase value) & {  _writeCommandRequestBase = std::move(value);  }

    /**
     * Enables the operation to bypass document validation. This lets you write documents that do not meet the validation requirements.
     */
     bool getBypassDocumentValidation() const { return _writeCommandRequestBase.getBypassDocumentValidation(); }
    /**
     * If true, then when an write statement fails, the command returns without executing the remaining statements. If false, then statements are allowed to be executed in parallel and if a statement fails, continue with the remaining statements, if any.
     */
     bool getOrdered() const { return _writeCommandRequestBase.getOrdered(); }
    /**
     * A statement number relative to the transaction. If this field is set, the statement ids of the contained operation will be implicitly generated based on their offset, starting from the value given. This field is mutually exclusive with 'stmtIds'.
     */
    const  boost::optional<std::int32_t> getStmtId() const { return _writeCommandRequestBase.getStmtId(); }
    /**
     * An array of statement numbers relative to the transaction. If this field is set, its size must be exactly the same as the number of entries in the corresponding insert/update/delete request. If it is not set, the statement ids of the contained operation will be implicitly generated based on their offset, starting from 'stmtId' or 0 if 'stmtId' is not specified. This field is mutually exclusive with 'stmtId'.
     */
    const  boost::optional<std::vector<std::int32_t>>& getStmtIds() const { return _writeCommandRequestBase.getStmtIds(); }
    /**
     * This flag is set to true when the write command was originally sent to the time-series view, but got rewritten to target time-series buckets namespace.
     */
    const  mongo::OptionalBool& getIsTimeseriesNamespace() const { return _writeCommandRequestBase.getIsTimeseriesNamespace(); }
    /**
     * An array of one or more documents to insert.
     */
    const std::vector<mongo::BSONObj>& getDocuments() const& { return _documents; }
    void getDocuments() && = delete;
    void setDocuments(std::vector<mongo::BSONObj> value) & {  _documents = std::move(value); _hasDocuments = true; }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;


    NamespaceString _nss;

    mongo::write_ops::WriteCommandRequestBase _writeCommandRequestBase;
    std::vector<mongo::BSONObj> _documents;
    std::string _dbName;
    bool _hasDocuments : 1;
    bool _hasDbName : 1;
};

/**
 * Parser for the 'update' command.
 */
class UpdateCommandRequest {
public:
    using Reply = mongo::write_ops::UpdateCommandReply;
    static constexpr auto kBypassDocumentValidationFieldName = "bypassDocumentValidation"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kIsTimeseriesNamespaceFieldName = "isTimeseriesNamespace"_sd;
    static constexpr auto kLegacyRuntimeConstantsFieldName = "runtimeConstants"_sd;
    static constexpr auto kLetFieldName = "let"_sd;
    static constexpr auto kOrderedFieldName = "ordered"_sd;
    static constexpr auto kStmtIdFieldName = "stmtId"_sd;
    static constexpr auto kStmtIdsFieldName = "stmtIds"_sd;
    static constexpr auto kUpdatesFieldName = "updates"_sd;
    static constexpr auto kWriteCommandRequestBaseFieldName = "WriteCommandRequestBase"_sd;
    static constexpr auto kCommandName = "update"_sd;

    static AuthorizationContract kAuthorizationContract;

    explicit UpdateCommandRequest(const NamespaceString nss);
    UpdateCommandRequest(const NamespaceString nss, std::vector<mongo::write_ops::UpdateOpEntry> updates);

    static UpdateCommandRequest parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static UpdateCommandRequest parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const NamespaceString& getNamespace() const { return _nss; }

    /**
     * Contains basic information included by all write commands
     */
    const mongo::write_ops::WriteCommandRequestBase& getWriteCommandRequestBase() const { return _writeCommandRequestBase; }
    mongo::write_ops::WriteCommandRequestBase& getWriteCommandRequestBase() { return _writeCommandRequestBase; }
    void setWriteCommandRequestBase(mongo::write_ops::WriteCommandRequestBase value) & {  _writeCommandRequestBase = std::move(value);  }

    /**
     * Enables the operation to bypass document validation. This lets you write documents that do not meet the validation requirements.
     */
     bool getBypassDocumentValidation() const { return _writeCommandRequestBase.getBypassDocumentValidation(); }
    /**
     * If true, then when an write statement fails, the command returns without executing the remaining statements. If false, then statements are allowed to be executed in parallel and if a statement fails, continue with the remaining statements, if any.
     */
     bool getOrdered() const { return _writeCommandRequestBase.getOrdered(); }
    /**
     * A statement number relative to the transaction. If this field is set, the statement ids of the contained operation will be implicitly generated based on their offset, starting from the value given. This field is mutually exclusive with 'stmtIds'.
     */
    const  boost::optional<std::int32_t> getStmtId() const { return _writeCommandRequestBase.getStmtId(); }
    /**
     * An array of statement numbers relative to the transaction. If this field is set, its size must be exactly the same as the number of entries in the corresponding insert/update/delete request. If it is not set, the statement ids of the contained operation will be implicitly generated based on their offset, starting from 'stmtId' or 0 if 'stmtId' is not specified. This field is mutually exclusive with 'stmtId'.
     */
    const  boost::optional<std::vector<std::int32_t>>& getStmtIds() const { return _writeCommandRequestBase.getStmtIds(); }
    /**
     * This flag is set to true when the write command was originally sent to the time-series view, but got rewritten to target time-series buckets namespace.
     */
    const  mongo::OptionalBool& getIsTimeseriesNamespace() const { return _writeCommandRequestBase.getIsTimeseriesNamespace(); }
    /**
     * An array of one or more update statements to perform.
     */
    const std::vector<mongo::write_ops::UpdateOpEntry>& getUpdates() const& { return _updates; }
    void getUpdates() && = delete;
    void setUpdates(std::vector<mongo::write_ops::UpdateOpEntry> value) & {  _updates = std::move(value); _hasUpdates = true; }

    /**
     * A set of user-specified constants used by pipeline-style update operations and $expr.
     */
    const boost::optional<mongo::BSONObj>& getLet() const& { return _let; }
    void getLet() && = delete;
    void setLet(boost::optional<mongo::BSONObj> value) & {  _let = std::move(value);  }

    /**
     * A legacy way to specify constant variables available during execution. 'let' is now preferred.
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
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;


    NamespaceString _nss;

    mongo::write_ops::WriteCommandRequestBase _writeCommandRequestBase;
    std::vector<mongo::write_ops::UpdateOpEntry> _updates;
    boost::optional<mongo::BSONObj> _let;
    boost::optional<mongo::LegacyRuntimeConstants> _legacyRuntimeConstants;
    std::string _dbName;
    bool _hasUpdates : 1;
    bool _hasDbName : 1;
};

/**
 * Parser for the 'delete' command.
 */
class DeleteCommandRequest {
public:
    using Reply = mongo::write_ops::DeleteCommandReply;
    static constexpr auto kBypassDocumentValidationFieldName = "bypassDocumentValidation"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kDeletesFieldName = "deletes"_sd;
    static constexpr auto kIsTimeseriesNamespaceFieldName = "isTimeseriesNamespace"_sd;
    static constexpr auto kLegacyRuntimeConstantsFieldName = "runtimeConstants"_sd;
    static constexpr auto kLetFieldName = "let"_sd;
    static constexpr auto kOrderedFieldName = "ordered"_sd;
    static constexpr auto kStmtIdFieldName = "stmtId"_sd;
    static constexpr auto kStmtIdsFieldName = "stmtIds"_sd;
    static constexpr auto kWriteCommandRequestBaseFieldName = "WriteCommandRequestBase"_sd;
    static constexpr auto kCommandName = "delete"_sd;

    static AuthorizationContract kAuthorizationContract;

    explicit DeleteCommandRequest(const NamespaceString nss);
    DeleteCommandRequest(const NamespaceString nss, std::vector<mongo::write_ops::DeleteOpEntry> deletes);

    static DeleteCommandRequest parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static DeleteCommandRequest parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const NamespaceString& getNamespace() const { return _nss; }

    /**
     * Contains basic information included by all write commands
     */
    const mongo::write_ops::WriteCommandRequestBase& getWriteCommandRequestBase() const { return _writeCommandRequestBase; }
    mongo::write_ops::WriteCommandRequestBase& getWriteCommandRequestBase() { return _writeCommandRequestBase; }
    void setWriteCommandRequestBase(mongo::write_ops::WriteCommandRequestBase value) & {  _writeCommandRequestBase = std::move(value);  }

    /**
     * Enables the operation to bypass document validation. This lets you write documents that do not meet the validation requirements.
     */
     bool getBypassDocumentValidation() const { return _writeCommandRequestBase.getBypassDocumentValidation(); }
    /**
     * If true, then when an write statement fails, the command returns without executing the remaining statements. If false, then statements are allowed to be executed in parallel and if a statement fails, continue with the remaining statements, if any.
     */
     bool getOrdered() const { return _writeCommandRequestBase.getOrdered(); }
    /**
     * A statement number relative to the transaction. If this field is set, the statement ids of the contained operation will be implicitly generated based on their offset, starting from the value given. This field is mutually exclusive with 'stmtIds'.
     */
    const  boost::optional<std::int32_t> getStmtId() const { return _writeCommandRequestBase.getStmtId(); }
    /**
     * An array of statement numbers relative to the transaction. If this field is set, its size must be exactly the same as the number of entries in the corresponding insert/update/delete request. If it is not set, the statement ids of the contained operation will be implicitly generated based on their offset, starting from 'stmtId' or 0 if 'stmtId' is not specified. This field is mutually exclusive with 'stmtId'.
     */
    const  boost::optional<std::vector<std::int32_t>>& getStmtIds() const { return _writeCommandRequestBase.getStmtIds(); }
    /**
     * This flag is set to true when the write command was originally sent to the time-series view, but got rewritten to target time-series buckets namespace.
     */
    const  mongo::OptionalBool& getIsTimeseriesNamespace() const { return _writeCommandRequestBase.getIsTimeseriesNamespace(); }
    /**
     * An array of one or more delete statements to perform.
     */
    const std::vector<mongo::write_ops::DeleteOpEntry>& getDeletes() const& { return _deletes; }
    void getDeletes() && = delete;
    void setDeletes(std::vector<mongo::write_ops::DeleteOpEntry> value) & {  _deletes = std::move(value); _hasDeletes = true; }

    /**
     * A set of user-specified constants used by $expr.
     */
    const boost::optional<mongo::BSONObj>& getLet() const& { return _let; }
    void getLet() && = delete;
    void setLet(boost::optional<mongo::BSONObj> value) & {  _let = std::move(value);  }

    /**
     * A legacy way to specify constant variables available during execution. 'let' is now preferred.
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
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;


    NamespaceString _nss;

    mongo::write_ops::WriteCommandRequestBase _writeCommandRequestBase;
    std::vector<mongo::write_ops::DeleteOpEntry> _deletes;
    boost::optional<mongo::BSONObj> _let;
    boost::optional<mongo::LegacyRuntimeConstants> _legacyRuntimeConstants;
    std::string _dbName;
    bool _hasDeletes : 1;
    bool _hasDbName : 1;
};

/**
 * Parser for the 'findAndModify' command.
 */
class FindAndModifyCommandRequest {
public:
    using Reply = mongo::write_ops::FindAndModifyCommandReply;
    static constexpr auto kArrayFiltersFieldName = "arrayFilters"_sd;
    static constexpr auto kBatchSizeFieldName = "batchSize"_sd;
    static constexpr auto kBypassDocumentValidationFieldName = "bypassDocumentValidation"_sd;
    static constexpr auto kCollationFieldName = "collation"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kFieldsFieldName = "fields"_sd;
    static constexpr auto kHintFieldName = "hint"_sd;
    static constexpr auto kLegacyRuntimeConstantsFieldName = "runtimeConstants"_sd;
    static constexpr auto kLetFieldName = "let"_sd;
    static constexpr auto kNewFieldName = "new"_sd;
    static constexpr auto kQueryFieldName = "query"_sd;
    static constexpr auto kRemoveFieldName = "remove"_sd;
    static constexpr auto kSingleBatchFieldName = "singleBatch"_sd;
    static constexpr auto kSortFieldName = "sort"_sd;
    static constexpr auto kUpdateFieldName = "update"_sd;
    static constexpr auto kUpsertFieldName = "upsert"_sd;
    static constexpr auto kWriteConcernFieldName = "writeConcern"_sd;
    static constexpr auto kCommandName = "findAndModify"_sd;
    static constexpr auto kCommandAlias = "findandmodify"_sd;

    static AuthorizationContract kAuthorizationContract;

    explicit FindAndModifyCommandRequest(const NamespaceString nss);

    static FindAndModifyCommandRequest parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static FindAndModifyCommandRequest parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const NamespaceString& getNamespace() const { return _nss; }

    /**
     * The query that matches documents to update. Uses the same query selectors as used in the 'find' operation.
     */
    const mongo::BSONObj& getQuery() const { return _query; }
    void setQuery(mongo::BSONObj value) & {  _query = std::move(value);  }

    /**
     * A subset of fields to return.
     */
    const boost::optional<mongo::BSONObj>& getFields() const& { return _fields; }
    void getFields() && = delete;
    void setFields(boost::optional<mongo::BSONObj> value) & {  _fields = std::move(value);  }

    /**
     * Determines which document the operation modifies if the query selects multiple documents.
     */
    const boost::optional<mongo::BSONObj>& getSort() const& { return _sort; }
    void getSort() && = delete;
    void setSort(boost::optional<mongo::BSONObj> value) & {  _sort = std::move(value);  }

    /**
     * Determines the batch size.
     */
    const boost::optional<std::int32_t> getBatchSize() const& { return _batchSize; }
    void getBatchSize() && = delete;
    void setBatchSize(boost::optional<std::int32_t> value) & {  _batchSize = std::move(value);  }

    /**
     * Determines if the batch is single.
     */
    const boost::optional<bool> getSingleBatch() const& { return _singleBatch; }
    void getSingleBatch() && = delete;
    void setSingleBatch(boost::optional<bool> value) & {  _singleBatch = std::move(value);  }

    /**
     * Specifies the hint to use for the operation.
     */
    const mongo::BSONObj& getHint() const { return _hint; }
    void setHint(mongo::BSONObj value) & {  _hint = std::move(value);  }

    /**
     * Specifies the collation to use for the operation.
     */
    const boost::optional<mongo::BSONObj>& getCollation() const& { return _collation; }
    void getCollation() && = delete;
    void setCollation(boost::optional<mongo::BSONObj> value) & {  _collation = std::move(value);  }

    /**
     * Specifies which array elements an update modifier should apply to.
     */
    const boost::optional<std::vector<mongo::BSONObj>>& getArrayFilters() const& { return _arrayFilters; }
    void getArrayFilters() && = delete;
    void setArrayFilters(boost::optional<std::vector<mongo::BSONObj>> value) & {  _arrayFilters = std::move(value);  }

    /**
     * Removes the document specified in the query field.
     */
    const boost::optional<bool> getRemove() const& { return _remove; }
    void getRemove() && = delete;
    void setRemove(boost::optional<bool> value) & {  _remove = std::move(value);  }

    /**
     * Modification to apply.
     */
    const boost::optional<mongo::write_ops::UpdateModification>& getUpdate() const& { return _update; }
    void getUpdate() && = delete;
    void setUpdate(boost::optional<mongo::write_ops::UpdateModification> value) & {  _update = std::move(value);  }

    /**
     * If true, perform an insert if no documents match the query. If both upsert and multi are true and no documents match the query, the update operation inserts only a single document.
     */
    const boost::optional<bool> getUpsert() const& { return _upsert; }
    void getUpsert() && = delete;
    void setUpsert(boost::optional<bool> value) & {  _upsert = std::move(value);  }

    /**
     * When true, returns the modified document rather than the original.
     */
    const boost::optional<bool> getNew() const& { return _new; }
    void getNew() && = delete;
    void setNew(boost::optional<bool> value) & {  _new = std::move(value);  }

    /**
     * Enables the operation to bypass document validation. This lets you write documents that do not meet the validation requirements.
     */
    const boost::optional<bool> getBypassDocumentValidation() const& { return _bypassDocumentValidation; }
    void getBypassDocumentValidation() && = delete;
    void setBypassDocumentValidation(boost::optional<bool> value) & {  _bypassDocumentValidation = std::move(value);  }

    /**
     * A set of user-specified constants used by pipeline-style update operations and $expr.
     */
    const boost::optional<mongo::BSONObj>& getLet() const& { return _let; }
    void getLet() && = delete;
    void setLet(boost::optional<mongo::BSONObj> value) & {  _let = std::move(value);  }

    /**
     * A collection of values that do not change once computed. These are used by pipeline-style update operations.
     */
    const boost::optional<mongo::LegacyRuntimeConstants>& getLegacyRuntimeConstants() const& { return _legacyRuntimeConstants; }
    void getLegacyRuntimeConstants() && = delete;
    void setLegacyRuntimeConstants(boost::optional<mongo::LegacyRuntimeConstants> value) & {  _legacyRuntimeConstants = std::move(value);  }

    /**
     * Describes the write concern.
     */
    const boost::optional<mongo::BSONObj>& getWriteConcern() const& { return _writeConcern; }
    void getWriteConcern() && = delete;
    void setWriteConcern(boost::optional<mongo::BSONObj> value) & {  _writeConcern = std::move(value);  }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;


    NamespaceString _nss;

    mongo::BSONObj _query{mongo::BSONObj()};
    boost::optional<mongo::BSONObj> _fields;
    boost::optional<mongo::BSONObj> _sort;
    boost::optional<std::int32_t> _batchSize;
    boost::optional<bool> _singleBatch;
    mongo::BSONObj _hint{mongo::BSONObj()};
    boost::optional<mongo::BSONObj> _collation;
    boost::optional<std::vector<mongo::BSONObj>> _arrayFilters;
    boost::optional<bool> _remove;
    boost::optional<mongo::write_ops::UpdateModification> _update;
    boost::optional<bool> _upsert;
    boost::optional<bool> _new;
    boost::optional<bool> _bypassDocumentValidation;
    boost::optional<mongo::BSONObj> _let;
    boost::optional<mongo::LegacyRuntimeConstants> _legacyRuntimeConstants;
    boost::optional<mongo::BSONObj> _writeConcern;
    std::string _dbName;
    bool _hasDbName : 1;
};


template <typename Derived>
class InsertCmdVersion1Gen : public TypedCommand<Derived> {
    using _TypedCommandInvocationBase = typename TypedCommand<Derived>::InvocationBase;

public:
    using Request = InsertCommandRequest;
    using Reply = mongo::write_ops::InsertCommandReply;

    virtual ~InsertCmdVersion1Gen() = default;

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

template <typename Derived>
class UpdateCmdVersion1Gen : public TypedCommand<Derived> {
    using _TypedCommandInvocationBase = typename TypedCommand<Derived>::InvocationBase;

public:
    using Request = UpdateCommandRequest;
    using Reply = mongo::write_ops::UpdateCommandReply;

    virtual ~UpdateCmdVersion1Gen() = default;

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

template <typename Derived>
class DeleteCmdVersion1Gen : public TypedCommand<Derived> {
    using _TypedCommandInvocationBase = typename TypedCommand<Derived>::InvocationBase;

public:
    using Request = DeleteCommandRequest;
    using Reply = mongo::write_ops::DeleteCommandReply;

    virtual ~DeleteCmdVersion1Gen() = default;

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

template <typename Derived>
class FindAndModifyCmdVersion1Gen : public TypedCommand<Derived> {
    using _TypedCommandInvocationBase = typename TypedCommand<Derived>::InvocationBase;

public:
    using Request = FindAndModifyCommandRequest;
    using Reply = mongo::write_ops::FindAndModifyCommandReply;

    FindAndModifyCmdVersion1Gen(): TypedCommand<Derived>(Request::kCommandName, Request::kCommandAlias) {}

    virtual ~FindAndModifyCmdVersion1Gen() = default;

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
}  // namespace write_ops
}  // namespace mongo
