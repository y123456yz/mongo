/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/s/sharding_ddl_coordinator_gen.h --output build/opt/mongo/db/s/sharding_ddl_coordinator_gen.cpp src/mongo/db/s/sharding_ddl_coordinator.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/s/sharding_ddl_coordinator_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

/**
 * Type of the sharding DDL Operation.
 */
namespace  {
constexpr StringData kDDLCoordinatorType_kDropDatabase = "dropDatabase"_sd;
constexpr StringData kDDLCoordinatorType_kDropCollection = "dropCollection"_sd;
constexpr StringData kDDLCoordinatorType_kRenameCollection = "renameCollection"_sd;
constexpr StringData kDDLCoordinatorType_kCreateCollection = "createCollection"_sd;
constexpr StringData kDDLCoordinatorType_kSetAllowMigrations = "setAllowMigrations"_sd;
}  // namespace 

DDLCoordinatorTypeEnum DDLCoordinatorType_parse(const IDLParserErrorContext& ctxt, StringData value) {
    if (value == kDDLCoordinatorType_kDropDatabase) {
        return DDLCoordinatorTypeEnum::kDropDatabase;
    }
    if (value == kDDLCoordinatorType_kDropCollection) {
        return DDLCoordinatorTypeEnum::kDropCollection;
    }
    if (value == kDDLCoordinatorType_kRenameCollection) {
        return DDLCoordinatorTypeEnum::kRenameCollection;
    }
    if (value == kDDLCoordinatorType_kCreateCollection) {
        return DDLCoordinatorTypeEnum::kCreateCollection;
    }
    if (value == kDDLCoordinatorType_kSetAllowMigrations) {
        return DDLCoordinatorTypeEnum::kSetAllowMigrations;
    }
    ctxt.throwBadEnumValue(value);
}

StringData DDLCoordinatorType_serializer(DDLCoordinatorTypeEnum value) {
    if (value == DDLCoordinatorTypeEnum::kDropDatabase) {
        return kDDLCoordinatorType_kDropDatabase;
    }
    if (value == DDLCoordinatorTypeEnum::kDropCollection) {
        return kDDLCoordinatorType_kDropCollection;
    }
    if (value == DDLCoordinatorTypeEnum::kRenameCollection) {
        return kDDLCoordinatorType_kRenameCollection;
    }
    if (value == DDLCoordinatorTypeEnum::kCreateCollection) {
        return kDDLCoordinatorType_kCreateCollection;
    }
    if (value == DDLCoordinatorTypeEnum::kSetAllowMigrations) {
        return kDDLCoordinatorType_kSetAllowMigrations;
    }
    MONGO_UNREACHABLE;
    return StringData();
}

constexpr StringData ShardingDDLCoordinatorId::kNssFieldName;
constexpr StringData ShardingDDLCoordinatorId::kOperationTypeFieldName;


ShardingDDLCoordinatorId::ShardingDDLCoordinatorId() : _nss(mongo::idl::preparsedValue<decltype(_nss)>()), _operationType(mongo::idl::preparsedValue<decltype(_operationType)>()), _hasNss(false), _hasOperationType(false) {
    // Used for initialization only
}
ShardingDDLCoordinatorId::ShardingDDLCoordinatorId(mongo::NamespaceString nss, mongo::DDLCoordinatorTypeEnum operationType) : _nss(std::move(nss)), _operationType(std::move(operationType)), _hasNss(true), _hasOperationType(true) {
    // Used for initialization only
}


ShardingDDLCoordinatorId ShardingDDLCoordinatorId::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ShardingDDLCoordinatorId>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ShardingDDLCoordinatorId::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kNssBit = 0;
    const size_t kOperationTypeBit = 1;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kNssFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kNssBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNssBit);

                _hasNss = true;
                _nss = NamespaceString(element.valueStringData());
            }
        }
        else if (fieldName == kOperationTypeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kOperationTypeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kOperationTypeBit);

                _hasOperationType = true;
                IDLParserErrorContext tempContext(kOperationTypeFieldName, &ctxt);
                _operationType = DDLCoordinatorType_parse(tempContext, element.valueStringData());
            }
        }
        else {
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kNssBit]) {
            ctxt.throwMissingField(kNssFieldName);
        }
        if (!usedFields[kOperationTypeBit]) {
            ctxt.throwMissingField(kOperationTypeFieldName);
        }
    }

}


void ShardingDDLCoordinatorId::serialize(BSONObjBuilder* builder) const {
    invariant(_hasNss && _hasOperationType);

    {
        builder->append(kNssFieldName, _nss.toString());
    }

    {
        builder->append(kOperationTypeFieldName, ::mongo::DDLCoordinatorType_serializer(_operationType));
    }

}


BSONObj ShardingDDLCoordinatorId::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData ShardingDDLSession::kLsidFieldName;
constexpr StringData ShardingDDLSession::kTxnNumberFieldName;


ShardingDDLSession::ShardingDDLSession() : _lsid(mongo::idl::preparsedValue<decltype(_lsid)>()), _txnNumber(mongo::idl::preparsedValue<decltype(_txnNumber)>()), _hasLsid(false), _hasTxnNumber(false) {
    // Used for initialization only
}
ShardingDDLSession::ShardingDDLSession(mongo::LogicalSessionId lsid, std::int64_t txnNumber) : _lsid(std::move(lsid)), _txnNumber(std::move(txnNumber)), _hasLsid(true), _hasTxnNumber(true) {
    // Used for initialization only
}


ShardingDDLSession ShardingDDLSession::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ShardingDDLSession>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ShardingDDLSession::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kLsidBit = 0;
    const size_t kTxnNumberBit = 1;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kLsidFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kLsidBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLsidBit);

                _hasLsid = true;
                IDLParserErrorContext tempContext(kLsidFieldName, &ctxt);
                const auto localObject = element.Obj();
                _lsid = mongo::LogicalSessionId::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kTxnNumberFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kTxnNumberBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTxnNumberBit);

                _hasTxnNumber = true;
                _txnNumber = element._numberLong();
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kLsidBit]) {
            ctxt.throwMissingField(kLsidFieldName);
        }
        if (!usedFields[kTxnNumberBit]) {
            ctxt.throwMissingField(kTxnNumberFieldName);
        }
    }

}


void ShardingDDLSession::serialize(BSONObjBuilder* builder) const {
    invariant(_hasLsid && _hasTxnNumber);

    {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kLsidFieldName));
        _lsid.serialize(&subObjBuilder);
    }

    builder->append(kTxnNumberFieldName, _txnNumber);

}


BSONObj ShardingDDLSession::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData ShardingDDLCoordinatorMetadata::kDatabaseVersionFieldName;
constexpr StringData ShardingDDLCoordinatorMetadata::kForwardableOpMetadataFieldName;
constexpr StringData ShardingDDLCoordinatorMetadata::kIdFieldName;
constexpr StringData ShardingDDLCoordinatorMetadata::kRecoveredFromDiskFieldName;
constexpr StringData ShardingDDLCoordinatorMetadata::kSessionFieldName;


ShardingDDLCoordinatorMetadata::ShardingDDLCoordinatorMetadata() : _id(mongo::idl::preparsedValue<decltype(_id)>()), _hasId(false) {
    // Used for initialization only
}
ShardingDDLCoordinatorMetadata::ShardingDDLCoordinatorMetadata(mongo::ShardingDDLCoordinatorId id) : _id(std::move(id)), _hasId(true) {
    // Used for initialization only
}


ShardingDDLCoordinatorMetadata ShardingDDLCoordinatorMetadata::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ShardingDDLCoordinatorMetadata>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ShardingDDLCoordinatorMetadata::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<5> usedFields;
    const size_t kIdBit = 0;
    const size_t kRecoveredFromDiskBit = 1;
    const size_t kForwardableOpMetadataBit = 2;
    const size_t kDatabaseVersionBit = 3;
    const size_t kSessionBit = 4;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIdBit);

                _hasId = true;
                IDLParserErrorContext tempContext(kIdFieldName, &ctxt);
                const auto localObject = element.Obj();
                _id = mongo::ShardingDDLCoordinatorId::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kRecoveredFromDiskFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kRecoveredFromDiskBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRecoveredFromDiskBit);

                _recoveredFromDisk = element.boolean();
            }
        }
        else if (fieldName == kForwardableOpMetadataFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kForwardableOpMetadataBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kForwardableOpMetadataBit);

                const BSONObj localObject = element.Obj();
                _forwardableOpMetadata = ForwardableOperationMetadata(localObject);
            }
        }
        else if (fieldName == kDatabaseVersionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kDatabaseVersionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDatabaseVersionBit);

                const BSONObj localObject = element.Obj();
                _databaseVersion = DatabaseVersion(localObject);
            }
        }
        else if (fieldName == kSessionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kSessionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSessionBit);

                IDLParserErrorContext tempContext(kSessionFieldName, &ctxt);
                const auto localObject = element.Obj();
                _session = mongo::ShardingDDLSession::parse(tempContext, localObject);
            }
        }
        else {
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kIdBit]) {
            ctxt.throwMissingField(kIdFieldName);
        }
        if (!usedFields[kRecoveredFromDiskBit]) {
            _recoveredFromDisk = false;
        }
    }

}


void ShardingDDLCoordinatorMetadata::serialize(BSONObjBuilder* builder) const {
    invariant(_hasId);

    {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kIdFieldName));
        _id.serialize(&subObjBuilder);
    }

    builder->append(kRecoveredFromDiskFieldName, _recoveredFromDisk);

    if (_forwardableOpMetadata.is_initialized()) {
        const BSONObj localObject = _forwardableOpMetadata.get().toBSON();
        builder->append(kForwardableOpMetadataFieldName, localObject);
    }

    if (_databaseVersion.is_initialized()) {
        const BSONObj localObject = _databaseVersion.get().toBSON();
        builder->append(kDatabaseVersionFieldName, localObject);
    }

    if (_session.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kSessionFieldName));
        _session.get().serialize(&subObjBuilder);
    }

}


BSONObj ShardingDDLCoordinatorMetadata::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
