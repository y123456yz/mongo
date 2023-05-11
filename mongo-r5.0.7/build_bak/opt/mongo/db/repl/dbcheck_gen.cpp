/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/repl/dbcheck_gen.h --output build/opt/mongo/db/repl/dbcheck_gen.cpp src/mongo/db/repl/dbcheck.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/repl/dbcheck_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"
#include "mongo/idl/server_parameter.h"
#include "mongo/idl/server_parameter_with_storage.h"

namespace mongo {

/**
 * The type of dbCheck oplog entry.
 */
namespace  {
constexpr StringData kOplogEntries_Batch = "batch"_sd;
constexpr StringData kOplogEntries_Collection = "collection"_sd;
constexpr StringData kOplogEntries_Start = "start"_sd;
constexpr StringData kOplogEntries_Stop = "stop"_sd;
}  // namespace 

OplogEntriesEnum OplogEntries_parse(const IDLParserErrorContext& ctxt, StringData value) {
    if (value == kOplogEntries_Batch) {
        return OplogEntriesEnum::Batch;
    }
    if (value == kOplogEntries_Collection) {
        return OplogEntriesEnum::Collection;
    }
    if (value == kOplogEntries_Start) {
        return OplogEntriesEnum::Start;
    }
    if (value == kOplogEntries_Stop) {
        return OplogEntriesEnum::Stop;
    }
    ctxt.throwBadEnumValue(value);
}

StringData OplogEntries_serializer(OplogEntriesEnum value) {
    if (value == OplogEntriesEnum::Batch) {
        return kOplogEntries_Batch;
    }
    if (value == OplogEntriesEnum::Collection) {
        return kOplogEntries_Collection;
    }
    if (value == OplogEntriesEnum::Start) {
        return kOplogEntries_Start;
    }
    if (value == OplogEntriesEnum::Stop) {
        return kOplogEntries_Stop;
    }
    MONGO_UNREACHABLE;
    return StringData();
}

constexpr StringData DbCheckSingleInvocation::kBatchWriteConcernFieldName;
constexpr StringData DbCheckSingleInvocation::kCollFieldName;
constexpr StringData DbCheckSingleInvocation::kMaxBatchTimeMillisFieldName;
constexpr StringData DbCheckSingleInvocation::kMaxBytesPerBatchFieldName;
constexpr StringData DbCheckSingleInvocation::kMaxCountFieldName;
constexpr StringData DbCheckSingleInvocation::kMaxCountPerSecondFieldName;
constexpr StringData DbCheckSingleInvocation::kMaxDocsPerBatchFieldName;
constexpr StringData DbCheckSingleInvocation::kMaxKeyFieldName;
constexpr StringData DbCheckSingleInvocation::kMaxSizeFieldName;
constexpr StringData DbCheckSingleInvocation::kMinKeyFieldName;
constexpr StringData DbCheckSingleInvocation::kSnapshotReadFieldName;


DbCheckSingleInvocation::DbCheckSingleInvocation() : _coll(mongo::idl::preparsedValue<decltype(_coll)>()), _hasColl(false) {
    // Used for initialization only
}
DbCheckSingleInvocation::DbCheckSingleInvocation(std::string coll) : _coll(std::move(coll)), _hasColl(true) {
    // Used for initialization only
}

void DbCheckSingleInvocation::validateMaxDocsPerBatch(IDLParserErrorContext& ctxt, const std::int64_t value)
{
    if (!(value >= 1)) {
        throwComparisonError<std::int64_t>(ctxt, "maxDocsPerBatch", ">="_sd, value, 1);
    }
    if (!(value <= 10000)) {
        throwComparisonError<std::int64_t>(ctxt, "maxDocsPerBatch", "<="_sd, value, 10000);
    }
}

void DbCheckSingleInvocation::validateMaxDocsPerBatch(const std::int64_t value)
{
    if (!(value >= 1)) {
        throwComparisonError<std::int64_t>("maxDocsPerBatch", ">="_sd, value, 1);
    }
    if (!(value <= 10000)) {
        throwComparisonError<std::int64_t>("maxDocsPerBatch", "<="_sd, value, 10000);
    }
}

void DbCheckSingleInvocation::validateMaxBytesPerBatch(IDLParserErrorContext& ctxt, const std::int64_t value)
{
    if (!(value >= 102400)) {
        throwComparisonError<std::int64_t>(ctxt, "maxBytesPerBatch", ">="_sd, value, 102400);
    }
    if (!(value <= 268435456)) {
        throwComparisonError<std::int64_t>(ctxt, "maxBytesPerBatch", "<="_sd, value, 268435456);
    }
}

void DbCheckSingleInvocation::validateMaxBytesPerBatch(const std::int64_t value)
{
    if (!(value >= 102400)) {
        throwComparisonError<std::int64_t>("maxBytesPerBatch", ">="_sd, value, 102400);
    }
    if (!(value <= 268435456)) {
        throwComparisonError<std::int64_t>("maxBytesPerBatch", "<="_sd, value, 268435456);
    }
}

void DbCheckSingleInvocation::validateMaxBatchTimeMillis(IDLParserErrorContext& ctxt, const std::int64_t value)
{
    if (!(value >= 10)) {
        throwComparisonError<std::int64_t>(ctxt, "maxBatchTimeMillis", ">="_sd, value, 10);
    }
    if (!(value <= 20000)) {
        throwComparisonError<std::int64_t>(ctxt, "maxBatchTimeMillis", "<="_sd, value, 20000);
    }
}

void DbCheckSingleInvocation::validateMaxBatchTimeMillis(const std::int64_t value)
{
    if (!(value >= 10)) {
        throwComparisonError<std::int64_t>("maxBatchTimeMillis", ">="_sd, value, 10);
    }
    if (!(value <= 20000)) {
        throwComparisonError<std::int64_t>("maxBatchTimeMillis", "<="_sd, value, 20000);
    }
}


DbCheckSingleInvocation DbCheckSingleInvocation::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<DbCheckSingleInvocation>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void DbCheckSingleInvocation::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<11> usedFields;
    const size_t kCollBit = 0;
    const size_t kMinKeyBit = 1;
    const size_t kMaxKeyBit = 2;
    const size_t kMaxCountBit = 3;
    const size_t kMaxSizeBit = 4;
    const size_t kMaxCountPerSecondBit = 5;
    const size_t kMaxDocsPerBatchBit = 6;
    const size_t kMaxBytesPerBatchBit = 7;
    const size_t kMaxBatchTimeMillisBit = 8;
    const size_t kSnapshotReadBit = 9;
    const size_t kBatchWriteConcernBit = 10;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kCollFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kCollBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollBit);

                _hasColl = true;
                _coll = element.str();
            }
        }
        else if (fieldName == kMinKeyFieldName) {
            if (MONGO_unlikely(usedFields[kMinKeyBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kMinKeyBit);

            _minKey = BSONKey::parseFromBSON(element);
        }
        else if (fieldName == kMaxKeyFieldName) {
            if (MONGO_unlikely(usedFields[kMaxKeyBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kMaxKeyBit);

            _maxKey = BSONKey::parseFromBSON(element);
        }
        else if (fieldName == kMaxCountFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kMaxCountBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMaxCountBit);

                _maxCount = element.safeNumberLong();
            }
        }
        else if (fieldName == kMaxSizeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kMaxSizeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMaxSizeBit);

                _maxSize = element.safeNumberLong();
            }
        }
        else if (fieldName == kMaxCountPerSecondFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kMaxCountPerSecondBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMaxCountPerSecondBit);

                _maxCountPerSecond = element.safeNumberLong();
            }
        }
        else if (fieldName == kMaxDocsPerBatchFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kMaxDocsPerBatchBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMaxDocsPerBatchBit);

                {
                    auto value = element.safeNumberLong();
                    validateMaxDocsPerBatch(value);
                    _maxDocsPerBatch = std::move(value);
                }
            }
        }
        else if (fieldName == kMaxBytesPerBatchFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kMaxBytesPerBatchBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMaxBytesPerBatchBit);

                {
                    auto value = element.safeNumberLong();
                    validateMaxBytesPerBatch(value);
                    _maxBytesPerBatch = std::move(value);
                }
            }
        }
        else if (fieldName == kMaxBatchTimeMillisFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kMaxBatchTimeMillisBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMaxBatchTimeMillisBit);

                {
                    auto value = element.safeNumberLong();
                    validateMaxBatchTimeMillis(value);
                    _maxBatchTimeMillis = std::move(value);
                }
            }
        }
        else if (fieldName == kSnapshotReadFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kSnapshotReadBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSnapshotReadBit);

                _snapshotRead = element.trueValue();
            }
        }
        else if (fieldName == kBatchWriteConcernFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kBatchWriteConcernBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kBatchWriteConcernBit);

                const BSONObj localObject = element.Obj();
                _batchWriteConcern = WriteConcernOptions::deserializerForIDL(localObject);
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kCollBit]) {
            ctxt.throwMissingField(kCollFieldName);
        }
        if (!usedFields[kMinKeyBit]) {
            _minKey = BSONKey::min();
        }
        if (!usedFields[kMaxKeyBit]) {
            _maxKey = BSONKey::max();
        }
        if (!usedFields[kMaxCountBit]) {
            _maxCount = std::numeric_limits<int64_t>::max();
        }
        if (!usedFields[kMaxSizeBit]) {
            _maxSize = std::numeric_limits<int64_t>::max();
        }
        if (!usedFields[kMaxCountPerSecondBit]) {
            _maxCountPerSecond = std::numeric_limits<int64_t>::max();
        }
        if (!usedFields[kMaxDocsPerBatchBit]) {
            _maxDocsPerBatch = 5000;
        }
        if (!usedFields[kMaxBytesPerBatchBit]) {
            _maxBytesPerBatch = 20 * 1024 * 1024;
        }
        if (!usedFields[kMaxBatchTimeMillisBit]) {
            _maxBatchTimeMillis = 1000;
        }
        if (!usedFields[kSnapshotReadBit]) {
            _snapshotRead = true;
        }
        if (!usedFields[kBatchWriteConcernBit]) {
            _batchWriteConcern = WriteConcernOptions();
        }
    }

}


void DbCheckSingleInvocation::serialize(BSONObjBuilder* builder) const {
    invariant(_hasColl);

    builder->append(kCollFieldName, _coll);

    {
        _minKey.serializeToBSON(kMinKeyFieldName, builder);
    }

    {
        _maxKey.serializeToBSON(kMaxKeyFieldName, builder);
    }

    builder->append(kMaxCountFieldName, _maxCount);

    builder->append(kMaxSizeFieldName, _maxSize);

    builder->append(kMaxCountPerSecondFieldName, _maxCountPerSecond);

    builder->append(kMaxDocsPerBatchFieldName, _maxDocsPerBatch);

    builder->append(kMaxBytesPerBatchFieldName, _maxBytesPerBatch);

    builder->append(kMaxBatchTimeMillisFieldName, _maxBatchTimeMillis);

    builder->append(kSnapshotReadFieldName, _snapshotRead);

    {
        const BSONObj localObject = _batchWriteConcern.toBSON();
        builder->append(kBatchWriteConcernFieldName, localObject);
    }

}


BSONObj DbCheckSingleInvocation::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData DbCheckAllInvocation::kBatchWriteConcernFieldName;
constexpr StringData DbCheckAllInvocation::kMaxBatchTimeMillisFieldName;
constexpr StringData DbCheckAllInvocation::kMaxBytesPerBatchFieldName;
constexpr StringData DbCheckAllInvocation::kMaxCountPerSecondFieldName;
constexpr StringData DbCheckAllInvocation::kMaxDocsPerBatchFieldName;
constexpr StringData DbCheckAllInvocation::kSnapshotReadFieldName;
constexpr StringData DbCheckAllInvocation::kTagFieldName;


DbCheckAllInvocation::DbCheckAllInvocation() : _tag(mongo::idl::preparsedValue<decltype(_tag)>()), _hasTag(false) {
    // Used for initialization only
}
DbCheckAllInvocation::DbCheckAllInvocation(std::int64_t tag) : _tag(std::move(tag)), _hasTag(true) {
    // Used for initialization only
}

void DbCheckAllInvocation::validateMaxDocsPerBatch(IDLParserErrorContext& ctxt, const std::int64_t value)
{
    if (!(value >= 1)) {
        throwComparisonError<std::int64_t>(ctxt, "maxDocsPerBatch", ">="_sd, value, 1);
    }
    if (!(value <= 10000)) {
        throwComparisonError<std::int64_t>(ctxt, "maxDocsPerBatch", "<="_sd, value, 10000);
    }
}

void DbCheckAllInvocation::validateMaxDocsPerBatch(const std::int64_t value)
{
    if (!(value >= 1)) {
        throwComparisonError<std::int64_t>("maxDocsPerBatch", ">="_sd, value, 1);
    }
    if (!(value <= 10000)) {
        throwComparisonError<std::int64_t>("maxDocsPerBatch", "<="_sd, value, 10000);
    }
}

void DbCheckAllInvocation::validateMaxBytesPerBatch(IDLParserErrorContext& ctxt, const std::int64_t value)
{
    if (!(value >= 102400)) {
        throwComparisonError<std::int64_t>(ctxt, "maxBytesPerBatch", ">="_sd, value, 102400);
    }
    if (!(value <= 268435456)) {
        throwComparisonError<std::int64_t>(ctxt, "maxBytesPerBatch", "<="_sd, value, 268435456);
    }
}

void DbCheckAllInvocation::validateMaxBytesPerBatch(const std::int64_t value)
{
    if (!(value >= 102400)) {
        throwComparisonError<std::int64_t>("maxBytesPerBatch", ">="_sd, value, 102400);
    }
    if (!(value <= 268435456)) {
        throwComparisonError<std::int64_t>("maxBytesPerBatch", "<="_sd, value, 268435456);
    }
}

void DbCheckAllInvocation::validateMaxBatchTimeMillis(IDLParserErrorContext& ctxt, const std::int64_t value)
{
    if (!(value >= 10)) {
        throwComparisonError<std::int64_t>(ctxt, "maxBatchTimeMillis", ">="_sd, value, 10);
    }
    if (!(value <= 20000)) {
        throwComparisonError<std::int64_t>(ctxt, "maxBatchTimeMillis", "<="_sd, value, 20000);
    }
}

void DbCheckAllInvocation::validateMaxBatchTimeMillis(const std::int64_t value)
{
    if (!(value >= 10)) {
        throwComparisonError<std::int64_t>("maxBatchTimeMillis", ">="_sd, value, 10);
    }
    if (!(value <= 20000)) {
        throwComparisonError<std::int64_t>("maxBatchTimeMillis", "<="_sd, value, 20000);
    }
}


DbCheckAllInvocation DbCheckAllInvocation::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<DbCheckAllInvocation>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void DbCheckAllInvocation::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<7> usedFields;
    const size_t kTagBit = 0;
    const size_t kMaxCountPerSecondBit = 1;
    const size_t kMaxDocsPerBatchBit = 2;
    const size_t kMaxBytesPerBatchBit = 3;
    const size_t kMaxBatchTimeMillisBit = 4;
    const size_t kSnapshotReadBit = 5;
    const size_t kBatchWriteConcernBit = 6;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kTagFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kTagBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTagBit);

                _hasTag = true;
                _tag = element.safeNumberLong();
            }
        }
        else if (fieldName == kMaxCountPerSecondFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kMaxCountPerSecondBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMaxCountPerSecondBit);

                _maxCountPerSecond = element.safeNumberLong();
            }
        }
        else if (fieldName == kMaxDocsPerBatchFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kMaxDocsPerBatchBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMaxDocsPerBatchBit);

                {
                    auto value = element.safeNumberLong();
                    validateMaxDocsPerBatch(value);
                    _maxDocsPerBatch = std::move(value);
                }
            }
        }
        else if (fieldName == kMaxBytesPerBatchFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kMaxBytesPerBatchBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMaxBytesPerBatchBit);

                {
                    auto value = element.safeNumberLong();
                    validateMaxBytesPerBatch(value);
                    _maxBytesPerBatch = std::move(value);
                }
            }
        }
        else if (fieldName == kMaxBatchTimeMillisFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kMaxBatchTimeMillisBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMaxBatchTimeMillisBit);

                {
                    auto value = element.safeNumberLong();
                    validateMaxBatchTimeMillis(value);
                    _maxBatchTimeMillis = std::move(value);
                }
            }
        }
        else if (fieldName == kSnapshotReadFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kSnapshotReadBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSnapshotReadBit);

                _snapshotRead = element.trueValue();
            }
        }
        else if (fieldName == kBatchWriteConcernFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kBatchWriteConcernBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kBatchWriteConcernBit);

                const BSONObj localObject = element.Obj();
                _batchWriteConcern = WriteConcernOptions::deserializerForIDL(localObject);
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kTagBit]) {
            ctxt.throwMissingField(kTagFieldName);
        }
        if (!usedFields[kMaxCountPerSecondBit]) {
            _maxCountPerSecond = std::numeric_limits<int64_t>::max();
        }
        if (!usedFields[kMaxDocsPerBatchBit]) {
            _maxDocsPerBatch = 5000;
        }
        if (!usedFields[kMaxBytesPerBatchBit]) {
            _maxBytesPerBatch = 20 * 1024 * 1024;
        }
        if (!usedFields[kMaxBatchTimeMillisBit]) {
            _maxBatchTimeMillis = 1000;
        }
        if (!usedFields[kSnapshotReadBit]) {
            _snapshotRead = true;
        }
        if (!usedFields[kBatchWriteConcernBit]) {
            _batchWriteConcern = WriteConcernOptions();
        }
    }

}


void DbCheckAllInvocation::serialize(BSONObjBuilder* builder) const {
    invariant(_hasTag);

    builder->append(kTagFieldName, _tag);

    builder->append(kMaxCountPerSecondFieldName, _maxCountPerSecond);

    builder->append(kMaxDocsPerBatchFieldName, _maxDocsPerBatch);

    builder->append(kMaxBytesPerBatchFieldName, _maxBytesPerBatch);

    builder->append(kMaxBatchTimeMillisFieldName, _maxBatchTimeMillis);

    builder->append(kSnapshotReadFieldName, _snapshotRead);

    {
        const BSONObj localObject = _batchWriteConcern.toBSON();
        builder->append(kBatchWriteConcernFieldName, localObject);
    }

}


BSONObj DbCheckAllInvocation::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData DbCheckOplogBatch::kMaxKeyFieldName;
constexpr StringData DbCheckOplogBatch::kMaxRateFieldName;
constexpr StringData DbCheckOplogBatch::kMd5FieldName;
constexpr StringData DbCheckOplogBatch::kMinKeyFieldName;
constexpr StringData DbCheckOplogBatch::kNssFieldName;
constexpr StringData DbCheckOplogBatch::kReadTimestampFieldName;
constexpr StringData DbCheckOplogBatch::kTypeFieldName;


DbCheckOplogBatch::DbCheckOplogBatch() : _nss(mongo::idl::preparsedValue<decltype(_nss)>()), _type(mongo::idl::preparsedValue<decltype(_type)>()), _md5(mongo::idl::preparsedValue<decltype(_md5)>()), _minKey(mongo::idl::preparsedValue<decltype(_minKey)>()), _maxKey(mongo::idl::preparsedValue<decltype(_maxKey)>()), _hasNss(false), _hasType(false), _hasMd5(false), _hasMinKey(false), _hasMaxKey(false) {
    // Used for initialization only
}
DbCheckOplogBatch::DbCheckOplogBatch(mongo::NamespaceString nss, mongo::OplogEntriesEnum type, std::string md5, mongo::BSONKey minKey, mongo::BSONKey maxKey) : _nss(std::move(nss)), _type(std::move(type)), _md5(std::move(md5)), _minKey(std::move(minKey)), _maxKey(std::move(maxKey)), _hasNss(true), _hasType(true), _hasMd5(true), _hasMinKey(true), _hasMaxKey(true) {
    // Used for initialization only
}


DbCheckOplogBatch DbCheckOplogBatch::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<DbCheckOplogBatch>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void DbCheckOplogBatch::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<7> usedFields;
    const size_t kNssBit = 0;
    const size_t kTypeBit = 1;
    const size_t kMd5Bit = 2;
    const size_t kMinKeyBit = 3;
    const size_t kMaxKeyBit = 4;
    const size_t kMaxRateBit = 5;
    const size_t kReadTimestampBit = 6;

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
        else if (fieldName == kTypeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kTypeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTypeBit);

                _hasType = true;
                IDLParserErrorContext tempContext(kTypeFieldName, &ctxt);
                _type = OplogEntries_parse(tempContext, element.valueStringData());
            }
        }
        else if (fieldName == kMd5FieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kMd5Bit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMd5Bit);

                _hasMd5 = true;
                _md5 = element.str();
            }
        }
        else if (fieldName == kMinKeyFieldName) {
            if (MONGO_unlikely(usedFields[kMinKeyBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kMinKeyBit);

            _hasMinKey = true;
            _minKey = BSONKey::parseFromBSON(element);
        }
        else if (fieldName == kMaxKeyFieldName) {
            if (MONGO_unlikely(usedFields[kMaxKeyBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kMaxKeyBit);

            _hasMaxKey = true;
            _maxKey = BSONKey::parseFromBSON(element);
        }
        else if (fieldName == kMaxRateFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kMaxRateBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMaxRateBit);

                _maxRate = element.safeNumberLong();
            }
        }
        else if (fieldName == kReadTimestampFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, bsonTimestamp))) {
                if (MONGO_unlikely(usedFields[kReadTimestampBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kReadTimestampBit);

                _readTimestamp = element.timestamp();
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kNssBit]) {
            ctxt.throwMissingField(kNssFieldName);
        }
        if (!usedFields[kTypeBit]) {
            ctxt.throwMissingField(kTypeFieldName);
        }
        if (!usedFields[kMd5Bit]) {
            ctxt.throwMissingField(kMd5FieldName);
        }
        if (!usedFields[kMinKeyBit]) {
            ctxt.throwMissingField(kMinKeyFieldName);
        }
        if (!usedFields[kMaxKeyBit]) {
            ctxt.throwMissingField(kMaxKeyFieldName);
        }
    }

}


void DbCheckOplogBatch::serialize(BSONObjBuilder* builder) const {
    invariant(_hasNss && _hasType && _hasMd5 && _hasMinKey && _hasMaxKey);

    {
        builder->append(kNssFieldName, _nss.toString());
    }

    {
        builder->append(kTypeFieldName, ::mongo::OplogEntries_serializer(_type));
    }

    builder->append(kMd5FieldName, _md5);

    {
        _minKey.serializeToBSON(kMinKeyFieldName, builder);
    }

    {
        _maxKey.serializeToBSON(kMaxKeyFieldName, builder);
    }

    if (_maxRate.is_initialized()) {
        builder->append(kMaxRateFieldName, _maxRate.get());
    }

    if (_readTimestamp.is_initialized()) {
        builder->append(kReadTimestampFieldName, _readTimestamp.get());
    }

}


BSONObj DbCheckOplogBatch::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData DbCheckOplogCollection::kIndexesFieldName;
constexpr StringData DbCheckOplogCollection::kNextFieldName;
constexpr StringData DbCheckOplogCollection::kNssFieldName;
constexpr StringData DbCheckOplogCollection::kOptionsFieldName;
constexpr StringData DbCheckOplogCollection::kPrevFieldName;
constexpr StringData DbCheckOplogCollection::kTypeFieldName;
constexpr StringData DbCheckOplogCollection::kUuidFieldName;


DbCheckOplogCollection::DbCheckOplogCollection() : _nss(mongo::idl::preparsedValue<decltype(_nss)>()), _type(mongo::idl::preparsedValue<decltype(_type)>()), _uuid(mongo::idl::preparsedValue<decltype(_uuid)>()), _options(mongo::idl::preparsedValue<decltype(_options)>()), _hasNss(false), _hasType(false), _hasUuid(false), _hasIndexes(false), _hasOptions(false) {
    // Used for initialization only
}
DbCheckOplogCollection::DbCheckOplogCollection(mongo::NamespaceString nss, mongo::OplogEntriesEnum type, mongo::UUID uuid, std::vector<mongo::BSONObj> indexes, mongo::BSONObj options) : _nss(std::move(nss)), _type(std::move(type)), _uuid(std::move(uuid)), _indexes(std::move(indexes)), _options(std::move(options)), _hasNss(true), _hasType(true), _hasUuid(true), _hasIndexes(true), _hasOptions(true) {
    // Used for initialization only
}


DbCheckOplogCollection DbCheckOplogCollection::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<DbCheckOplogCollection>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void DbCheckOplogCollection::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<7> usedFields;
    const size_t kNssBit = 0;
    const size_t kTypeBit = 1;
    const size_t kUuidBit = 2;
    const size_t kPrevBit = 3;
    const size_t kNextBit = 4;
    const size_t kIndexesBit = 5;
    const size_t kOptionsBit = 6;

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
        else if (fieldName == kTypeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kTypeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTypeBit);

                _hasType = true;
                IDLParserErrorContext tempContext(kTypeFieldName, &ctxt);
                _type = OplogEntries_parse(tempContext, element.valueStringData());
            }
        }
        else if (fieldName == kUuidFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kUuidBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUuidBit);

                _hasUuid = true;
                _uuid = UUID(uassertStatusOK(UUID::parse(element)));
            }
        }
        else if (fieldName == kPrevFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kPrevBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPrevBit);

                _prev = UUID(uassertStatusOK(UUID::parse(element)));
            }
        }
        else if (fieldName == kNextFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kNextBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNextBit);

                _next = UUID(uassertStatusOK(UUID::parse(element)));
            }
        }
        else if (fieldName == kIndexesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kIndexesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIndexesBit);

                _hasIndexes = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kIndexesFieldName, &ctxt);
            std::vector<mongo::BSONObj> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, Object)) {
                        values.emplace_back(arrayElement.Obj());
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _indexes = std::move(values);
        }
        else if (fieldName == kOptionsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kOptionsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kOptionsBit);

                _hasOptions = true;
                _options = element.Obj();
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kNssBit]) {
            ctxt.throwMissingField(kNssFieldName);
        }
        if (!usedFields[kTypeBit]) {
            ctxt.throwMissingField(kTypeFieldName);
        }
        if (!usedFields[kUuidBit]) {
            ctxt.throwMissingField(kUuidFieldName);
        }
        if (!usedFields[kIndexesBit]) {
            ctxt.throwMissingField(kIndexesFieldName);
        }
        if (!usedFields[kOptionsBit]) {
            ctxt.throwMissingField(kOptionsFieldName);
        }
    }

}


void DbCheckOplogCollection::serialize(BSONObjBuilder* builder) const {
    invariant(_hasNss && _hasType && _hasUuid && _hasIndexes && _hasOptions);

    {
        builder->append(kNssFieldName, _nss.toString());
    }

    {
        builder->append(kTypeFieldName, ::mongo::OplogEntries_serializer(_type));
    }

    {
        ConstDataRange tempCDR = _uuid.toCDR();
        builder->append(kUuidFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    if (_prev.is_initialized()) {
        ConstDataRange tempCDR = _prev.get().toCDR();
        builder->append(kPrevFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    if (_next.is_initialized()) {
        ConstDataRange tempCDR = _next.get().toCDR();
        builder->append(kNextFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    {
        builder->append(kIndexesFieldName, _indexes);
    }

    builder->append(kOptionsFieldName, _options);

}


BSONObj DbCheckOplogCollection::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData DbCheckOplogStartStop::kNssFieldName;
constexpr StringData DbCheckOplogStartStop::kTypeFieldName;


DbCheckOplogStartStop::DbCheckOplogStartStop() : _nss(mongo::idl::preparsedValue<decltype(_nss)>()), _type(mongo::idl::preparsedValue<decltype(_type)>()), _hasNss(false), _hasType(false) {
    // Used for initialization only
}
DbCheckOplogStartStop::DbCheckOplogStartStop(mongo::NamespaceString nss, mongo::OplogEntriesEnum type) : _nss(std::move(nss)), _type(std::move(type)), _hasNss(true), _hasType(true) {
    // Used for initialization only
}


DbCheckOplogStartStop DbCheckOplogStartStop::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<DbCheckOplogStartStop>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void DbCheckOplogStartStop::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kNssBit = 0;
    const size_t kTypeBit = 1;

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
        else if (fieldName == kTypeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kTypeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTypeBit);

                _hasType = true;
                IDLParserErrorContext tempContext(kTypeFieldName, &ctxt);
                _type = OplogEntries_parse(tempContext, element.valueStringData());
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kNssBit]) {
            ctxt.throwMissingField(kNssFieldName);
        }
        if (!usedFields[kTypeBit]) {
            ctxt.throwMissingField(kTypeFieldName);
        }
    }

}


void DbCheckOplogStartStop::serialize(BSONObjBuilder* builder) const {
    invariant(_hasNss && _hasType);

    {
        builder->append(kNssFieldName, _nss.toString());
    }

    {
        builder->append(kTypeFieldName, ::mongo::OplogEntries_serializer(_type));
    }

}


BSONObj DbCheckOplogStartStop::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

AtomicWord<int> gDbCheckCollectionTryLockTimeoutMillis{10};
AtomicWord<int> gDbCheckCollectionTryLockMaxAttempts{5};
AtomicWord<int> gDbCheckCollectionTryLockMinBackoffMillis{10};
AtomicWord<int> gDbCheckCollectionTryLockMaxBackoffMillis{60000};
AtomicWord<int> gDbCheckHealthLogEveryNBatches{25};
MONGO_SERVER_PARAMETER_REGISTER(idl_3c189b1c52ea3c2df1f494c47d9fc693d54ba905)(InitializerContext*) {
    /**
     * Timeout to acquire the collection for processing a dbCheck batch. Each subsequent attempt doubles the timeout
     */
    [[maybe_unused]] auto* scp_0 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("dbCheckCollectionTryLockTimeoutMillis", gDbCheckCollectionTryLockTimeoutMillis);
        ret->addBound<idl_server_parameter_detail::LTE>(10000);
        ret->addBound<idl_server_parameter_detail::GTE>(1);
        return ret;
    })();

    /**
     * Maximum number of attempts with backoff to acquire the collection lock for processing a dbCheck batch
     */
    [[maybe_unused]] auto* scp_1 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("dbCheckCollectionTryLockMaxAttempts", gDbCheckCollectionTryLockMaxAttempts);
        ret->addBound<idl_server_parameter_detail::LTE>(20);
        ret->addBound<idl_server_parameter_detail::GTE>(1);
        return ret;
    })();

    /**
     * Initial backoff on failure to acquire the collection lock for processing a dbCheck batch. Grows exponentially
     */
    [[maybe_unused]] auto* scp_2 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("dbCheckCollectionTryLockMinBackoffMillis", gDbCheckCollectionTryLockMinBackoffMillis);
        ret->addBound<idl_server_parameter_detail::LTE>(60000);
        ret->addBound<idl_server_parameter_detail::GTE>(2);
        return ret;
    })();

    /**
     * Maximum exponential backoff on failure to acquire the collection lock for processing a dbCheck batch.
     */
    [[maybe_unused]] auto* scp_3 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("dbCheckCollectionTryLockMaxBackoffMillis", gDbCheckCollectionTryLockMaxBackoffMillis);
        ret->addBound<idl_server_parameter_detail::LTE>(120000);
        ret->addBound<idl_server_parameter_detail::GTE>(20);
        return ret;
    })();

    /**
     * Emit an info-severity health log batch every N batches processed
     */
    [[maybe_unused]] auto* scp_4 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("dbCheckHealthLogEveryNBatches", gDbCheckHealthLogEveryNBatches);
        ret->addBound<idl_server_parameter_detail::LTE>(10000);
        ret->addBound<idl_server_parameter_detail::GTE>(1);
        return ret;
    })();

}
}  // namespace mongo
