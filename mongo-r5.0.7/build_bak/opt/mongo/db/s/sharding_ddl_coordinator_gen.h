/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/s/sharding_ddl_coordinator_gen.h --output build/opt/mongo/db/s/sharding_ddl_coordinator_gen.cpp src/mongo/db/s/sharding_ddl_coordinator.idl
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
#include "mongo/db/logical_session_id_gen.h"
#include "mongo/db/namespace_string.h"
#include "mongo/db/s/forwardable_operation_metadata.h"
#include "mongo/idl/basic_types.h"
#include "mongo/idl/basic_types_gen.h"
#include "mongo/idl/idl_parser.h"
#include "mongo/rpc/op_msg.h"
#include "mongo/s/database_version.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/util/uuid.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {

/**
 * Type of the sharding DDL Operation.
 */
enum class DDLCoordinatorTypeEnum : std::int32_t {
    kDropDatabase ,
    kDropCollection ,
    kRenameCollection ,
    kCreateCollection ,
    kSetAllowMigrations ,
};
static constexpr uint32_t kNumDDLCoordinatorTypeEnum = 5;

DDLCoordinatorTypeEnum DDLCoordinatorType_parse(const IDLParserErrorContext& ctxt, StringData value);
StringData DDLCoordinatorType_serializer(DDLCoordinatorTypeEnum value);

/**
 * Identifier for a specific sharding DDL Coordinator.
 */
class ShardingDDLCoordinatorId {
public:
    static constexpr auto kNssFieldName = "namespace"_sd;
    static constexpr auto kOperationTypeFieldName = "operationType"_sd;

    ShardingDDLCoordinatorId();
    ShardingDDLCoordinatorId(mongo::NamespaceString nss, mongo::DDLCoordinatorTypeEnum operationType);

    static ShardingDDLCoordinatorId parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * The target namespace of the DDL operation.
     */
    const mongo::NamespaceString& getNss() const { return _nss; }
    void setNss(mongo::NamespaceString value) & {  _nss = std::move(value); _hasNss = true; }

    /**
     * Type of the sharding DDL coordinator.
     */
    mongo::DDLCoordinatorTypeEnum getOperationType() const { return _operationType; }
    void setOperationType(mongo::DDLCoordinatorTypeEnum value) & {  _operationType = std::move(value); _hasOperationType = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::NamespaceString _nss;
    mongo::DDLCoordinatorTypeEnum _operationType;
    bool _hasNss : 1;
    bool _hasOperationType : 1;
};

/**
 * Container for DDL coordinator session.
 */
class ShardingDDLSession {
public:
    static constexpr auto kLsidFieldName = "lsid"_sd;
    static constexpr auto kTxnNumberFieldName = "txnNumber"_sd;

    ShardingDDLSession();
    ShardingDDLSession(mongo::LogicalSessionId lsid, std::int64_t txnNumber);

    static ShardingDDLSession parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    const mongo::LogicalSessionId& getLsid() const { return _lsid; }
    mongo::LogicalSessionId& getLsid() { return _lsid; }
    void setLsid(mongo::LogicalSessionId value) & {  _lsid = std::move(value); _hasLsid = true; }

    std::int64_t getTxnNumber() const { return _txnNumber; }
    void setTxnNumber(std::int64_t value) & {  _txnNumber = std::move(value); _hasTxnNumber = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::LogicalSessionId _lsid;
    std::int64_t _txnNumber;
    bool _hasLsid : 1;
    bool _hasTxnNumber : 1;
};

/**
 * Commong metadata for all sharding DDL coordinator.
 */
class ShardingDDLCoordinatorMetadata {
public:
    static constexpr auto kDatabaseVersionFieldName = "databaseVersion"_sd;
    static constexpr auto kForwardableOpMetadataFieldName = "forwardableOpMetadata"_sd;
    static constexpr auto kIdFieldName = "_id"_sd;
    static constexpr auto kRecoveredFromDiskFieldName = "recoveredFromDisk"_sd;
    static constexpr auto kSessionFieldName = "session"_sd;

    ShardingDDLCoordinatorMetadata();
    ShardingDDLCoordinatorMetadata(mongo::ShardingDDLCoordinatorId id);

    static ShardingDDLCoordinatorMetadata parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    const mongo::ShardingDDLCoordinatorId& getId() const { return _id; }
    mongo::ShardingDDLCoordinatorId& getId() { return _id; }
    void setId(mongo::ShardingDDLCoordinatorId value) & {  _id = std::move(value); _hasId = true; }

    bool getRecoveredFromDisk() const { return _recoveredFromDisk; }
    void setRecoveredFromDisk(bool value) & {  _recoveredFromDisk = std::move(value);  }

    const boost::optional<mongo::ForwardableOperationMetadata>& getForwardableOpMetadata() const& { return _forwardableOpMetadata; }
    void getForwardableOpMetadata() && = delete;
    void setForwardableOpMetadata(boost::optional<mongo::ForwardableOperationMetadata> value) & {  _forwardableOpMetadata = std::move(value);  }

    const boost::optional<mongo::DatabaseVersion>& getDatabaseVersion() const& { return _databaseVersion; }
    void getDatabaseVersion() && = delete;
    void setDatabaseVersion(boost::optional<mongo::DatabaseVersion> value) & {  _databaseVersion = std::move(value);  }

    const boost::optional<mongo::ShardingDDLSession>& getSession() const& { return _session; }
    void getSession() && = delete;
    void setSession(boost::optional<mongo::ShardingDDLSession> value) & {  _session = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::ShardingDDLCoordinatorId _id;
    bool _recoveredFromDisk{false};
    boost::optional<mongo::ForwardableOperationMetadata> _forwardableOpMetadata;
    boost::optional<mongo::DatabaseVersion> _databaseVersion;
    boost::optional<mongo::ShardingDDLSession> _session;
    bool _hasId : 1;
};

}  // namespace mongo
