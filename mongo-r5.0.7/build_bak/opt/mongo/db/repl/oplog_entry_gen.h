/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/repl/oplog_entry_gen.h --output build/opt/mongo/db/repl/oplog_entry_gen.cpp src/mongo/db/repl/oplog_entry.idl
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
#include "mongo/db/exec/document_value/value.h"
#include "mongo/db/logical_session_id_gen.h"
#include "mongo/db/namespace_string.h"
#include "mongo/db/repl/optime.h"
#include "mongo/db/repl/optime_base_gen.h"
#include "mongo/idl/basic_types.h"
#include "mongo/idl/basic_types_gen.h"
#include "mongo/idl/idl_parser.h"
#include "mongo/rpc/op_msg.h"
#include "mongo/s/shard_id.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/util/uuid.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {
namespace repl {

/**
 * The type of an operation in the oplog
 */
enum class OpTypeEnum : std::int32_t {
    kCommand ,
    kInsert ,
    kUpdate ,
    kDelete ,
    kNoop ,
};
static constexpr uint32_t kNumOpTypeEnum = 5;

OpTypeEnum OpType_parse(const IDLParserErrorContext& ctxt, StringData value);
StringData OpType_serializer(OpTypeEnum value);

/**
 * Dictates whether a pre-image or post-image is to be stored on behalf of this retryable write.
 */
enum class RetryImageEnum : std::int32_t {
    kPreImage ,
    kPostImage ,
};
static constexpr uint32_t kNumRetryImageEnum = 2;

RetryImageEnum RetryImage_parse(const IDLParserErrorContext& ctxt, StringData value);
StringData RetryImage_serializer(RetryImageEnum value);

/**
 * A document that represents an operation in a transaction. Should never be used directly in server code. Instead, create an instance of ReplOperation.
 */
class DurableReplOperation {
public:
    static constexpr auto kDestinedRecipientFieldName = "destinedRecipient"_sd;
    static constexpr auto kNssFieldName = "ns"_sd;
    static constexpr auto kObjectFieldName = "o"_sd;
    static constexpr auto kObject2FieldName = "o2"_sd;
    static constexpr auto kOpTypeFieldName = "op"_sd;
    static constexpr auto kPreImageOpTimeFieldName = "preImageOpTime"_sd;
    static constexpr auto kUpsertFieldName = "b"_sd;
    static constexpr auto kUuidFieldName = "ui"_sd;

    DurableReplOperation();
    DurableReplOperation(mongo::repl::OpTypeEnum opType, mongo::NamespaceString nss, mongo::BSONObj object);

    static DurableReplOperation parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * The operation type
     */
    mongo::repl::OpTypeEnum getOpType() const { return _opType; }
    void setOpType(mongo::repl::OpTypeEnum value) & {  _opType = std::move(value); _hasOpType = true; }

    /**
     * The namespace on which to apply the operation
     */
    const mongo::NamespaceString& getNss() const { return _nss; }
    void setNss(mongo::NamespaceString value) & {  _nss = std::move(value); _hasNss = true; }

    /**
     * The UUID of the collection
     */
    const boost::optional<mongo::UUID>& getUuid() const& { return _uuid; }
    void getUuid() && = delete;
    void setUuid(boost::optional<mongo::UUID> value) & {  _uuid = std::move(value);  }

    /**
     * The operation applied
     */
    const mongo::BSONObj& getObject() const { return _object; }
    void setObject(mongo::BSONObj value) & {  _object = std::move(value); _hasObject = true; }

    /**
     * Additional information about the operation applied
     */
    const boost::optional<mongo::BSONObj>& getObject2() const& { return _object2; }
    void getObject2() && = delete;
    void setObject2(boost::optional<mongo::BSONObj> value) & {  _object2 = std::move(value);  }

    /**
     * If true, treats this update operation as an upsert. Used when extracting individual update oplog entries from the oplog entry of an applyOps command that was executed with alwaysUpsert true (the default). Originally added for backwards compatibility with updates from 3.6 and before.
     */
    const boost::optional<bool> getUpsert() const& { return _upsert; }
    void getUpsert() && = delete;
    void setUpsert(boost::optional<bool> value) & {  _upsert = std::move(value);  }

    /**
     * The optime of another oplog entry that contains the document before an update/remove was applied.
     */
    const boost::optional<mongo::repl::OpTime>& getPreImageOpTime() const& { return _preImageOpTime; }
    void getPreImageOpTime() && = delete;
    void setPreImageOpTime(boost::optional<mongo::repl::OpTime> value) & {  _preImageOpTime = std::move(value);  }

    /**
     * The destined recipient for this op under the new shard key pattern. Only included when a resharding operation is in progress.
     */
    const boost::optional<mongo::ShardId>& getDestinedRecipient() const& { return _destinedRecipient; }
    void getDestinedRecipient() && = delete;
    void setDestinedRecipient(boost::optional<mongo::ShardId> value) & {  _destinedRecipient = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::repl::OpTypeEnum _opType;
    mongo::NamespaceString _nss;
    boost::optional<mongo::UUID> _uuid;
    mongo::BSONObj _object;
    boost::optional<mongo::BSONObj> _object2;
    boost::optional<bool> _upsert;
    boost::optional<mongo::repl::OpTime> _preImageOpTime;
    boost::optional<mongo::ShardId> _destinedRecipient;
    bool _hasOpType : 1;
    bool _hasNss : 1;
    bool _hasObject : 1;
};

/**
 * A document in which the server stores an oplog entry.
 */
class OplogEntryBase {
public:
    static constexpr auto kDurableReplOperationFieldName = "DurableReplOperation"_sd;
    static constexpr auto kOpTimeBaseFieldName = "OpTimeBase"_sd;
    static constexpr auto kOperationSessionInfoFieldName = "OperationSessionInfo"_sd;
    static constexpr auto k_idFieldName = "_id"_sd;
    static constexpr auto kDestinedRecipientFieldName = "destinedRecipient"_sd;
    static constexpr auto kFromMigrateFieldName = "fromMigrate"_sd;
    static constexpr auto kFromTenantMigrationFieldName = "fromTenantMigration"_sd;
    static constexpr auto kHashFieldName = "h"_sd;
    static constexpr auto kNeedsRetryImageFieldName = "needsRetryImage"_sd;
    static constexpr auto kNssFieldName = "ns"_sd;
    static constexpr auto kObjectFieldName = "o"_sd;
    static constexpr auto kObject2FieldName = "o2"_sd;
    static constexpr auto kOpTypeFieldName = "op"_sd;
    static constexpr auto kPostImageOpTimeFieldName = "postImageOpTime"_sd;
    static constexpr auto kPreImageOpTimeFieldName = "preImageOpTime"_sd;
    static constexpr auto kPrevWriteOpTimeInTransactionFieldName = "prevOpTime"_sd;
    static constexpr auto kSessionIdFieldName = "lsid"_sd;
    static constexpr auto kStatementIdsFieldName = "stmtId"_sd;
    static constexpr auto kTermFieldName = "t"_sd;
    static constexpr auto kTimestampFieldName = "ts"_sd;
    static constexpr auto kTxnNumberFieldName = "txnNumber"_sd;
    static constexpr auto kUpsertFieldName = "b"_sd;
    static constexpr auto kUuidFieldName = "ui"_sd;
    static constexpr auto kVersionFieldName = "v"_sd;
    static constexpr auto kWallClockTimeFieldName = "wall"_sd;

    OplogEntryBase();
    OplogEntryBase(mongo::Date_t wallClockTime);

    static OplogEntryBase parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Parser for serializing sessionId/txnNumber combination
     */
    const mongo::OperationSessionInfo& getOperationSessionInfo() const { return _operationSessionInfo; }
    mongo::OperationSessionInfo& getOperationSessionInfo() { return _operationSessionInfo; }
    void setOperationSessionInfo(mongo::OperationSessionInfo value) & {  _operationSessionInfo = std::move(value);  }

    const  boost::optional<mongo::LogicalSessionId>& getSessionId() const { return _operationSessionInfo.getSessionId(); }
    /**
     * The transaction number relative to the session in which a particular write operation executes.
     */
    const  boost::optional<std::int64_t> getTxnNumber() const { return _operationSessionInfo.getTxnNumber(); }
    /**
     * A document that represents an operation in a transaction. Should never be used directly in server code. Instead, create an instance of ReplOperation.
     */
    const mongo::repl::DurableReplOperation& getDurableReplOperation() const { return _durableReplOperation; }
    mongo::repl::DurableReplOperation& getDurableReplOperation() { return _durableReplOperation; }
    void setDurableReplOperation(mongo::repl::DurableReplOperation value) & {  _durableReplOperation = std::move(value);  }

    /**
     * The operation type
     */
     mongo::repl::OpTypeEnum getOpType() const { return _durableReplOperation.getOpType(); }
    /**
     * The namespace on which to apply the operation
     */
    const  mongo::NamespaceString& getNss() const { return _durableReplOperation.getNss(); }
    /**
     * The UUID of the collection
     */
    const  boost::optional<mongo::UUID>& getUuid() const { return _durableReplOperation.getUuid(); }
    /**
     * The operation applied
     */
    const  mongo::BSONObj& getObject() const { return _durableReplOperation.getObject(); }
    /**
     * Additional information about the operation applied
     */
    const  boost::optional<mongo::BSONObj>& getObject2() const { return _durableReplOperation.getObject2(); }
    /**
     * If true, treats this update operation as an upsert. Used when extracting individual update oplog entries from the oplog entry of an applyOps command that was executed with alwaysUpsert true (the default). Originally added for backwards compatibility with updates from 3.6 and before.
     */
    const  boost::optional<bool> getUpsert() const { return _durableReplOperation.getUpsert(); }
    /**
     * The optime of another oplog entry that contains the document before an update/remove was applied.
     */
    const  boost::optional<mongo::repl::OpTime>& getPreImageOpTime() const { return _durableReplOperation.getPreImageOpTime(); }
    /**
     * The destined recipient for this op under the new shard key pattern. Only included when a resharding operation is in progress.
     */
    const  boost::optional<mongo::ShardId>& getDestinedRecipient() const { return _durableReplOperation.getDestinedRecipient(); }
    /**
     * A document that stores the logical time-related fields in an oplog entry. Should never be used directly in server code. Instead, create an instance of OpTime.
     */
    const mongo::repl::OpTimeBase& getOpTimeBase() const { return _opTimeBase; }
    mongo::repl::OpTimeBase& getOpTimeBase() { return _opTimeBase; }
    void setOpTimeBase(mongo::repl::OpTimeBase value) & {  _opTimeBase = std::move(value);  }

    /**
     * The time when the oplog entry was created
     */
    const  mongo::Timestamp& getTimestamp() const { return _opTimeBase.getTimestamp(); }
    /**
     * The term of the primary that created the oplog entry
     */
    const  boost::optional<std::int64_t> getTerm() const { return _opTimeBase.getTerm(); }
    /**
     * The hash of the oplog entry
     */
    const boost::optional<std::int64_t> getHash() const& { return _hash; }
    void getHash() && = delete;
    void setHash(boost::optional<std::int64_t> value) & {  _hash = std::move(value);  }

    /**
     * The version of the oplog
     */
    std::int64_t getVersion() const { return _version; }
    void setVersion(std::int64_t value) & {  _version = std::move(value);  }

    /**
     * A wallclock time with MS resolution
     */
    const mongo::Date_t& getWallClockTime() const { return _wallClockTime; }
    void setWallClockTime(mongo::Date_t value) & {  _wallClockTime = std::move(value); _hasWallClockTime = true; }

    /**
     * An operation caused by a chunk migration
     */
    const boost::optional<bool> getFromMigrate() const& { return _fromMigrate; }
    void getFromMigrate() && = delete;
    void setFromMigrate(boost::optional<bool> value) & {  _fromMigrate = std::move(value);  }

    /**
     * Contains the UUID of a tenant migration for an operation caused by one.
     */
    const boost::optional<mongo::UUID>& getFromTenantMigration() const& { return _fromTenantMigration; }
    void getFromTenantMigration() && = delete;
    void setFromTenantMigration(boost::optional<mongo::UUID> value) & {  _fromTenantMigration = std::move(value);  }

    /**
     * Used by tests in replication and also by production resharding code to store timestamps.
     */
    const boost::optional<mongo::Value>& get_id() const& { return __id; }
    void get_id() && = delete;
    void set_id(boost::optional<mongo::Value> value) & {  __id = std::move(value);  }

    /**
     * Identifier of the transaction statement(s) which generated this oplog entry
     */
    const boost::optional<stdx::variant<std::int32_t, std::vector<std::int32_t>>>& getStatementIds() const& { return _statementIds; }
    void getStatementIds() && = delete;
    void setStatementIds(boost::optional<stdx::variant<std::int32_t, std::vector<std::int32_t>>> value) & {  _statementIds = std::move(value);  }

    /**
     * The opTime of the previous write with the same transaction.
     */
    const boost::optional<mongo::repl::OpTime>& getPrevWriteOpTimeInTransaction() const& { return _prevWriteOpTimeInTransaction; }
    void getPrevWriteOpTimeInTransaction() && = delete;
    void setPrevWriteOpTimeInTransaction(boost::optional<mongo::repl::OpTime> value) & {  _prevWriteOpTimeInTransaction = std::move(value);  }

    /**
     * The optime of another oplog entry that contains the document after an update was applied.
     */
    const boost::optional<mongo::repl::OpTime>& getPostImageOpTime() const& { return _postImageOpTime; }
    void getPostImageOpTime() && = delete;
    void setPostImageOpTime(boost::optional<mongo::repl::OpTime> value) & {  _postImageOpTime = std::move(value);  }

    /**
     * Identifies whether a secondary should store a pre-image or post-image associated with this oplog entry.
     */
    const boost::optional<mongo::repl::RetryImageEnum> getNeedsRetryImage() const& { return _needsRetryImage; }
    void getNeedsRetryImage() && = delete;
    void setNeedsRetryImage(boost::optional<mongo::repl::RetryImageEnum> value) & {  _needsRetryImage = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::OperationSessionInfo _operationSessionInfo;
    mongo::repl::DurableReplOperation _durableReplOperation;
    mongo::repl::OpTimeBase _opTimeBase;
    boost::optional<std::int64_t> _hash;
    std::int64_t _version{2};
    mongo::Date_t _wallClockTime;
    boost::optional<bool> _fromMigrate;
    boost::optional<mongo::UUID> _fromTenantMigration;
    boost::optional<mongo::Value> __id;
    boost::optional<stdx::variant<std::int32_t, std::vector<std::int32_t>>> _statementIds;
    boost::optional<mongo::repl::OpTime> _prevWriteOpTimeInTransaction;
    boost::optional<mongo::repl::OpTime> _postImageOpTime;
    boost::optional<mongo::repl::RetryImageEnum> _needsRetryImage;
    bool _hasWallClockTime : 1;
};

}  // namespace repl
}  // namespace mongo
