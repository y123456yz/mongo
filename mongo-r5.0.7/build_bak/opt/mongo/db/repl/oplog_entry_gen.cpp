/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/repl/oplog_entry_gen.h --output build/opt/mongo/db/repl/oplog_entry_gen.cpp src/mongo/db/repl/oplog_entry.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/repl/oplog_entry_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {
namespace repl {

/**
 * The type of an operation in the oplog
 */
namespace  {
constexpr StringData kOpType_kCommand = "c"_sd;
constexpr StringData kOpType_kInsert = "i"_sd;
constexpr StringData kOpType_kUpdate = "u"_sd;
constexpr StringData kOpType_kDelete = "d"_sd;
constexpr StringData kOpType_kNoop = "n"_sd;
}  // namespace 

OpTypeEnum OpType_parse(const IDLParserErrorContext& ctxt, StringData value) {
    if (value == kOpType_kCommand) {
        return OpTypeEnum::kCommand;
    }
    if (value == kOpType_kInsert) {
        return OpTypeEnum::kInsert;
    }
    if (value == kOpType_kUpdate) {
        return OpTypeEnum::kUpdate;
    }
    if (value == kOpType_kDelete) {
        return OpTypeEnum::kDelete;
    }
    if (value == kOpType_kNoop) {
        return OpTypeEnum::kNoop;
    }
    ctxt.throwBadEnumValue(value);
}

StringData OpType_serializer(OpTypeEnum value) {
    if (value == OpTypeEnum::kCommand) {
        return kOpType_kCommand;
    }
    if (value == OpTypeEnum::kInsert) {
        return kOpType_kInsert;
    }
    if (value == OpTypeEnum::kUpdate) {
        return kOpType_kUpdate;
    }
    if (value == OpTypeEnum::kDelete) {
        return kOpType_kDelete;
    }
    if (value == OpTypeEnum::kNoop) {
        return kOpType_kNoop;
    }
    MONGO_UNREACHABLE;
    return StringData();
}

/**
 * Dictates whether a pre-image or post-image is to be stored on behalf of this retryable write.
 */
namespace  {
constexpr StringData kRetryImage_kPreImage = "preImage"_sd;
constexpr StringData kRetryImage_kPostImage = "postImage"_sd;
}  // namespace 

RetryImageEnum RetryImage_parse(const IDLParserErrorContext& ctxt, StringData value) {
    if (value == kRetryImage_kPreImage) {
        return RetryImageEnum::kPreImage;
    }
    if (value == kRetryImage_kPostImage) {
        return RetryImageEnum::kPostImage;
    }
    ctxt.throwBadEnumValue(value);
}

StringData RetryImage_serializer(RetryImageEnum value) {
    if (value == RetryImageEnum::kPreImage) {
        return kRetryImage_kPreImage;
    }
    if (value == RetryImageEnum::kPostImage) {
        return kRetryImage_kPostImage;
    }
    MONGO_UNREACHABLE;
    return StringData();
}

constexpr StringData DurableReplOperation::kDestinedRecipientFieldName;
constexpr StringData DurableReplOperation::kNssFieldName;
constexpr StringData DurableReplOperation::kObjectFieldName;
constexpr StringData DurableReplOperation::kObject2FieldName;
constexpr StringData DurableReplOperation::kOpTypeFieldName;
constexpr StringData DurableReplOperation::kPreImageOpTimeFieldName;
constexpr StringData DurableReplOperation::kUpsertFieldName;
constexpr StringData DurableReplOperation::kUuidFieldName;


DurableReplOperation::DurableReplOperation() : _opType(mongo::idl::preparsedValue<decltype(_opType)>()), _nss(mongo::idl::preparsedValue<decltype(_nss)>()), _object(mongo::idl::preparsedValue<decltype(_object)>()), _hasOpType(false), _hasNss(false), _hasObject(false) {
    // Used for initialization only
}
DurableReplOperation::DurableReplOperation(mongo::repl::OpTypeEnum opType, mongo::NamespaceString nss, mongo::BSONObj object) : _opType(std::move(opType)), _nss(std::move(nss)), _object(std::move(object)), _hasOpType(true), _hasNss(true), _hasObject(true) {
    // Used for initialization only
}


DurableReplOperation DurableReplOperation::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<DurableReplOperation>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void DurableReplOperation::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<8> usedFields;
    const size_t kOpTypeBit = 0;
    const size_t kNssBit = 1;
    const size_t kUuidBit = 2;
    const size_t kObjectBit = 3;
    const size_t kObject2Bit = 4;
    const size_t kUpsertBit = 5;
    const size_t kPreImageOpTimeBit = 6;
    const size_t kDestinedRecipientBit = 7;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kOpTypeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kOpTypeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kOpTypeBit);

                _hasOpType = true;
                IDLParserErrorContext tempContext(kOpTypeFieldName, &ctxt);
                _opType = repl::OpType_parse(tempContext, element.valueStringData());
            }
        }
        else if (fieldName == kNssFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kNssBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNssBit);

                _hasNss = true;
                _nss = NamespaceString(element.valueStringData());
            }
        }
        else if (fieldName == kUuidFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kUuidBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUuidBit);

                _uuid = UUID(uassertStatusOK(UUID::parse(element)));
            }
        }
        else if (fieldName == kObjectFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kObjectBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kObjectBit);

                _hasObject = true;
                _object = element.Obj();
            }
        }
        else if (fieldName == kObject2FieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kObject2Bit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kObject2Bit);

                _object2 = element.Obj();
            }
        }
        else if (fieldName == kUpsertFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kUpsertBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUpsertBit);

                _upsert = element.boolean();
            }
        }
        else if (fieldName == kPreImageOpTimeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kPreImageOpTimeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPreImageOpTimeBit);

                const BSONObj localObject = element.Obj();
                _preImageOpTime = repl::OpTime::parse(localObject);
            }
        }
        else if (fieldName == kDestinedRecipientFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kDestinedRecipientBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDestinedRecipientBit);

                _destinedRecipient = element.str();
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kOpTypeBit]) {
            ctxt.throwMissingField(kOpTypeFieldName);
        }
        if (!usedFields[kNssBit]) {
            ctxt.throwMissingField(kNssFieldName);
        }
        if (!usedFields[kObjectBit]) {
            ctxt.throwMissingField(kObjectFieldName);
        }
    }

}


void DurableReplOperation::serialize(BSONObjBuilder* builder) const {
    invariant(_hasOpType && _hasNss && _hasObject);

    {
        builder->append(kOpTypeFieldName, ::mongo::repl::OpType_serializer(_opType));
    }

    {
        builder->append(kNssFieldName, _nss.toString());
    }

    if (_uuid.is_initialized()) {
        ConstDataRange tempCDR = _uuid.get().toCDR();
        builder->append(kUuidFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    builder->append(kObjectFieldName, _object);

    if (_object2.is_initialized()) {
        builder->append(kObject2FieldName, _object2.get());
    }

    if (_upsert.is_initialized()) {
        builder->append(kUpsertFieldName, _upsert.get());
    }

    if (_preImageOpTime.is_initialized()) {
        const BSONObj localObject = _preImageOpTime.get().toBSON();
        builder->append(kPreImageOpTimeFieldName, localObject);
    }

    if (_destinedRecipient.is_initialized()) {
        builder->append(kDestinedRecipientFieldName, _destinedRecipient.get().toString());
    }

}


BSONObj DurableReplOperation::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData OplogEntryBase::kDurableReplOperationFieldName;
constexpr StringData OplogEntryBase::kOpTimeBaseFieldName;
constexpr StringData OplogEntryBase::kOperationSessionInfoFieldName;
constexpr StringData OplogEntryBase::k_idFieldName;
constexpr StringData OplogEntryBase::kDestinedRecipientFieldName;
constexpr StringData OplogEntryBase::kFromMigrateFieldName;
constexpr StringData OplogEntryBase::kFromTenantMigrationFieldName;
constexpr StringData OplogEntryBase::kHashFieldName;
constexpr StringData OplogEntryBase::kNeedsRetryImageFieldName;
constexpr StringData OplogEntryBase::kNssFieldName;
constexpr StringData OplogEntryBase::kObjectFieldName;
constexpr StringData OplogEntryBase::kObject2FieldName;
constexpr StringData OplogEntryBase::kOpTypeFieldName;
constexpr StringData OplogEntryBase::kPostImageOpTimeFieldName;
constexpr StringData OplogEntryBase::kPreImageOpTimeFieldName;
constexpr StringData OplogEntryBase::kPrevWriteOpTimeInTransactionFieldName;
constexpr StringData OplogEntryBase::kSessionIdFieldName;
constexpr StringData OplogEntryBase::kStatementIdsFieldName;
constexpr StringData OplogEntryBase::kTermFieldName;
constexpr StringData OplogEntryBase::kTimestampFieldName;
constexpr StringData OplogEntryBase::kTxnNumberFieldName;
constexpr StringData OplogEntryBase::kUpsertFieldName;
constexpr StringData OplogEntryBase::kUuidFieldName;
constexpr StringData OplogEntryBase::kVersionFieldName;
constexpr StringData OplogEntryBase::kWallClockTimeFieldName;


OplogEntryBase::OplogEntryBase() : _wallClockTime(mongo::idl::preparsedValue<decltype(_wallClockTime)>()), _hasWallClockTime(false) {
    // Used for initialization only
}
OplogEntryBase::OplogEntryBase(mongo::Date_t wallClockTime) : _wallClockTime(std::move(wallClockTime)), _hasWallClockTime(true) {
    // Used for initialization only
}


OplogEntryBase OplogEntryBase::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<OplogEntryBase>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void OplogEntryBase::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<25> usedFields;
    const size_t kSessionIdBit = 0;
    const size_t kTxnNumberBit = 1;
    const size_t kOpTypeBit = 2;
    const size_t kNssBit = 3;
    const size_t kUuidBit = 4;
    const size_t kObjectBit = 5;
    const size_t kObject2Bit = 6;
    const size_t kUpsertBit = 7;
    const size_t kPreImageOpTimeBit = 8;
    const size_t kDestinedRecipientBit = 9;
    const size_t kTimestampBit = 10;
    const size_t kTermBit = 11;
    const size_t kHashBit = 12;
    const size_t kVersionBit = 13;
    const size_t kWallClockTimeBit = 14;
    const size_t kFromMigrateBit = 15;
    const size_t kFromTenantMigrationBit = 16;
    const size_t k_idBit = 17;
    const size_t kStatementIdsBit = 18;
    const size_t kPrevWriteOpTimeInTransactionBit = 19;
    const size_t kPostImageOpTimeBit = 20;
    const size_t kNeedsRetryImageBit = 21;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kSessionIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kSessionIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSessionIdBit);

                IDLParserErrorContext tempContext(kSessionIdFieldName, &ctxt);
                const auto localObject = element.Obj();
                _operationSessionInfo.setSessionId(boost::optional<mongo::LogicalSessionId>(mongo::LogicalSessionId::parse(tempContext, localObject)));
            }
        }
        else if (fieldName == kTxnNumberFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kTxnNumberBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTxnNumberBit);

                _operationSessionInfo.setTxnNumber(boost::optional<std::int64_t>(element._numberLong()));
            }
        }
        else if (fieldName == kOpTypeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kOpTypeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kOpTypeBit);

                IDLParserErrorContext tempContext(kOpTypeFieldName, &ctxt);
                _durableReplOperation.setOpType(repl::OpType_parse(tempContext, element.valueStringData()));
            }
        }
        else if (fieldName == kNssFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kNssBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNssBit);

                _durableReplOperation.setNss(NamespaceString(element.valueStringData()));
            }
        }
        else if (fieldName == kUuidFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kUuidBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUuidBit);

                _durableReplOperation.setUuid(boost::optional<mongo::UUID>(UUID(uassertStatusOK(UUID::parse(element)))));
            }
        }
        else if (fieldName == kObjectFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kObjectBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kObjectBit);

                _durableReplOperation.setObject(element.Obj());
            }
        }
        else if (fieldName == kObject2FieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kObject2Bit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kObject2Bit);

                _durableReplOperation.setObject2(boost::optional<mongo::BSONObj>(element.Obj()));
            }
        }
        else if (fieldName == kUpsertFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kUpsertBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUpsertBit);

                _durableReplOperation.setUpsert(boost::optional<bool>(element.boolean()));
            }
        }
        else if (fieldName == kPreImageOpTimeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kPreImageOpTimeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPreImageOpTimeBit);

                const BSONObj localObject = element.Obj();
                _durableReplOperation.setPreImageOpTime(boost::optional<mongo::repl::OpTime>(repl::OpTime::parse(localObject)));
            }
        }
        else if (fieldName == kDestinedRecipientFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kDestinedRecipientBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDestinedRecipientBit);

                _durableReplOperation.setDestinedRecipient(boost::optional<mongo::ShardId>(element.str()));
            }
        }
        else if (fieldName == kTimestampFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, bsonTimestamp))) {
                if (MONGO_unlikely(usedFields[kTimestampBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTimestampBit);

                _opTimeBase.setTimestamp(element.timestamp());
            }
        }
        else if (fieldName == kTermFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kTermBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTermBit);

                _opTimeBase.setTerm(boost::optional<std::int64_t>(element._numberLong()));
            }
        }
        else if (fieldName == kHashFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kHashBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kHashBit);

                _hash = element._numberLong();
            }
        }
        else if (fieldName == kVersionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kVersionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kVersionBit);

                _version = element.safeNumberLong();
            }
        }
        else if (fieldName == kWallClockTimeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Date))) {
                if (MONGO_unlikely(usedFields[kWallClockTimeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kWallClockTimeBit);

                _hasWallClockTime = true;
                _wallClockTime = element.date();
            }
        }
        else if (fieldName == kFromMigrateFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kFromMigrateBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kFromMigrateBit);

                _fromMigrate = element.boolean();
            }
        }
        else if (fieldName == kFromTenantMigrationFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kFromTenantMigrationBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kFromTenantMigrationBit);

                _fromTenantMigration = UUID(uassertStatusOK(UUID::parse(element)));
            }
        }
        else if (fieldName == k_idFieldName) {
            if (MONGO_unlikely(usedFields[k_idBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(k_idBit);

            __id = Value::deserializeForIDL(element);
        }
        else if (fieldName == kStatementIdsFieldName) {
            if (MONGO_unlikely(usedFields[kStatementIdsBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kStatementIdsBit);


            const BSONType variantType = element.type();
            switch (variantType) {
            case Array:
                if (element.Obj().isEmpty()) {
                    std::uint32_t expectedFieldNumber{0};
                    const IDLParserErrorContext arrayCtxt(kStatementIdsFieldName, &ctxt);
                    std::vector<std::int32_t> values;

                    const BSONObj arrayObject = element.Obj();
                    for (const auto& arrayElement : arrayObject) {
                        const auto arrayFieldName = arrayElement.fieldNameStringData();
                        std::uint32_t fieldNumber;

                        Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                        if (status.isOK()) {
                            if (fieldNumber != expectedFieldNumber) {
                                arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                            }

                            if (arrayCtxt.checkAndAssertType(arrayElement, NumberInt)) {
                                values.emplace_back(arrayElement._numberInt());
                            }
                        }
                        else {
                            arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                        }
                        ++expectedFieldNumber;
                    }
                    _statementIds = std::move(values);
                }
                else {
                    const BSONType elemType = element.Obj().firstElement().type();
                    switch (elemType) {
                    case NumberInt:
                    {
                        std::uint32_t expectedFieldNumber{0};
                        const IDLParserErrorContext arrayCtxt(kStatementIdsFieldName, &ctxt);
                        std::vector<std::int32_t> values;

                        const BSONObj arrayObject = element.Obj();
                        for (const auto& arrayElement : arrayObject) {
                            const auto arrayFieldName = arrayElement.fieldNameStringData();
                            std::uint32_t fieldNumber;

                            Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                            if (status.isOK()) {
                                if (fieldNumber != expectedFieldNumber) {
                                    arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                                }

                                if (arrayCtxt.checkAndAssertType(arrayElement, NumberInt)) {
                                    values.emplace_back(arrayElement._numberInt());
                                }
                            }
                            else {
                                arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                            }
                            ++expectedFieldNumber;
                        }
                        _statementIds = std::move(values);
                        break;
                    }
                    default:
                        ctxt.throwBadType(element, {BSONType::NumberInt});
                        break;
                    }
                }
                break;
            case NumberInt:
            {
                _statementIds = element._numberInt();
                break;
            }
            default:
                ctxt.throwBadType(element, {BSONType::NumberInt});
                break;
            }
        }
        else if (fieldName == kPrevWriteOpTimeInTransactionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kPrevWriteOpTimeInTransactionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPrevWriteOpTimeInTransactionBit);

                const BSONObj localObject = element.Obj();
                _prevWriteOpTimeInTransaction = repl::OpTime::parse(localObject);
            }
        }
        else if (fieldName == kPostImageOpTimeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kPostImageOpTimeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPostImageOpTimeBit);

                const BSONObj localObject = element.Obj();
                _postImageOpTime = repl::OpTime::parse(localObject);
            }
        }
        else if (fieldName == kNeedsRetryImageFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kNeedsRetryImageBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNeedsRetryImageBit);

                IDLParserErrorContext tempContext(kNeedsRetryImageFieldName, &ctxt);
                _needsRetryImage = repl::RetryImage_parse(tempContext, element.valueStringData());
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kOpTypeBit]) {
            ctxt.throwMissingField(kOpTypeFieldName);
        }
        if (!usedFields[kNssBit]) {
            ctxt.throwMissingField(kNssFieldName);
        }
        if (!usedFields[kObjectBit]) {
            ctxt.throwMissingField(kObjectFieldName);
        }
        if (!usedFields[kTimestampBit]) {
            ctxt.throwMissingField(kTimestampFieldName);
        }
        if (!usedFields[kVersionBit]) {
            _version = 2;
        }
        if (!usedFields[kWallClockTimeBit]) {
            ctxt.throwMissingField(kWallClockTimeFieldName);
        }
    }

}


void OplogEntryBase::serialize(BSONObjBuilder* builder) const {
    invariant(_hasWallClockTime);

    {
        _operationSessionInfo.serialize(builder);
    }

    {
        _durableReplOperation.serialize(builder);
    }

    {
        _opTimeBase.serialize(builder);
    }

    if (_hash.is_initialized()) {
        builder->append(kHashFieldName, _hash.get());
    }

    builder->append(kVersionFieldName, _version);

    builder->append(kWallClockTimeFieldName, _wallClockTime);

    if (_fromMigrate.is_initialized()) {
        builder->append(kFromMigrateFieldName, _fromMigrate.get());
    }

    if (_fromTenantMigration.is_initialized()) {
        ConstDataRange tempCDR = _fromTenantMigration.get().toCDR();
        builder->append(kFromTenantMigrationFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    if (__id.is_initialized()) {
        __id.get().serializeForIDL(k_idFieldName, builder);
    }

    if (_statementIds.is_initialized()) {
        stdx::visit([builder](auto&& arg) {
            idl::idlSerialize(builder, kStatementIdsFieldName, arg);
        }, _statementIds.get());
    }

    if (_prevWriteOpTimeInTransaction.is_initialized()) {
        const BSONObj localObject = _prevWriteOpTimeInTransaction.get().toBSON();
        builder->append(kPrevWriteOpTimeInTransactionFieldName, localObject);
    }

    if (_postImageOpTime.is_initialized()) {
        const BSONObj localObject = _postImageOpTime.get().toBSON();
        builder->append(kPostImageOpTimeFieldName, localObject);
    }

    if (_needsRetryImage.is_initialized()) {
        builder->append(kNeedsRetryImageFieldName, ::mongo::repl::RetryImage_serializer(_needsRetryImage.get()));
    }

}


BSONObj OplogEntryBase::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace repl
}  // namespace mongo
