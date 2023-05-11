/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/list_indexes_gen.h --output build/opt/mongo/db/list_indexes_gen.cpp src/mongo/db/list_indexes.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/list_indexes_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData ListIndexesReplyItem::k2dsphereIndexVersionFieldName;
constexpr StringData ListIndexesReplyItem::kBackgroundFieldName;
constexpr StringData ListIndexesReplyItem::kBitsFieldName;
constexpr StringData ListIndexesReplyItem::kBucketSizeFieldName;
constexpr StringData ListIndexesReplyItem::kBuildUUIDFieldName;
constexpr StringData ListIndexesReplyItem::kCoarsestIndexedLevelFieldName;
constexpr StringData ListIndexesReplyItem::kCollationFieldName;
constexpr StringData ListIndexesReplyItem::kDefault_languageFieldName;
constexpr StringData ListIndexesReplyItem::kDropDupsFieldName;
constexpr StringData ListIndexesReplyItem::kExpireAfterSecondsFieldName;
constexpr StringData ListIndexesReplyItem::kFinestIndexedLevelFieldName;
constexpr StringData ListIndexesReplyItem::kHiddenFieldName;
constexpr StringData ListIndexesReplyItem::kKeyFieldName;
constexpr StringData ListIndexesReplyItem::kLanguage_overrideFieldName;
constexpr StringData ListIndexesReplyItem::kMaxFieldName;
constexpr StringData ListIndexesReplyItem::kMinFieldName;
constexpr StringData ListIndexesReplyItem::kNameFieldName;
constexpr StringData ListIndexesReplyItem::kNsFieldName;
constexpr StringData ListIndexesReplyItem::kPartialFilterExpressionFieldName;
constexpr StringData ListIndexesReplyItem::kSparseFieldName;
constexpr StringData ListIndexesReplyItem::kSpecFieldName;
constexpr StringData ListIndexesReplyItem::kStorageEngineFieldName;
constexpr StringData ListIndexesReplyItem::kTextIndexVersionFieldName;
constexpr StringData ListIndexesReplyItem::kUniqueFieldName;
constexpr StringData ListIndexesReplyItem::kVFieldName;
constexpr StringData ListIndexesReplyItem::kWeightsFieldName;
constexpr StringData ListIndexesReplyItem::kWildcardProjectionFieldName;


ListIndexesReplyItem::ListIndexesReplyItem()  {
    // Used for initialization only
}


ListIndexesReplyItem ListIndexesReplyItem::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ListIndexesReplyItem>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ListIndexesReplyItem::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<27> usedFields;
    const size_t kVBit = 0;
    const size_t kKeyBit = 1;
    const size_t kNameBit = 2;
    const size_t kNsBit = 3;
    const size_t kBackgroundBit = 4;
    const size_t kUniqueBit = 5;
    const size_t kHiddenBit = 6;
    const size_t kPartialFilterExpressionBit = 7;
    const size_t kSparseBit = 8;
    const size_t kExpireAfterSecondsBit = 9;
    const size_t kStorageEngineBit = 10;
    const size_t kWeightsBit = 11;
    const size_t kDefault_languageBit = 12;
    const size_t kLanguage_overrideBit = 13;
    const size_t kTextIndexVersionBit = 14;
    const size_t k2dsphereIndexVersionBit = 15;
    const size_t kBitsBit = 16;
    const size_t kMinBit = 17;
    const size_t kMaxBit = 18;
    const size_t kBucketSizeBit = 19;
    const size_t kCollationBit = 20;
    const size_t kWildcardProjectionBit = 21;
    const size_t kCoarsestIndexedLevelBit = 22;
    const size_t kFinestIndexedLevelBit = 23;
    const size_t kDropDupsBit = 24;
    const size_t kBuildUUIDBit = 25;
    const size_t kSpecBit = 26;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kVFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kVBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kVBit);

                _v = element.safeNumberInt();
            }
        }
        else if (fieldName == kKeyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kKeyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kKeyBit);

                const BSONObj localObject = element.Obj();
                _key = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kNameFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kNameBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNameBit);

                _name = element.str();
            }
        }
        else if (fieldName == kNsFieldName) {
            if (MONGO_unlikely(usedFields[kNsBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kNsBit);

            // ignore field
        }
        else if (fieldName == kBackgroundFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kBackgroundBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kBackgroundBit);

                _background = element.trueValue();
            }
        }
        else if (fieldName == kUniqueFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kUniqueBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUniqueBit);

                _unique = element.trueValue();
            }
        }
        else if (fieldName == kHiddenFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kHiddenBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kHiddenBit);

                _hidden = element.trueValue();
            }
        }
        else if (fieldName == kPartialFilterExpressionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kPartialFilterExpressionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPartialFilterExpressionBit);

                const BSONObj localObject = element.Obj();
                _partialFilterExpression = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kSparseFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kSparseBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSparseBit);

                _sparse = element.trueValue();
            }
        }
        else if (fieldName == kExpireAfterSecondsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kExpireAfterSecondsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kExpireAfterSecondsBit);

                _expireAfterSeconds = element.safeNumberInt();
            }
        }
        else if (fieldName == kStorageEngineFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kStorageEngineBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStorageEngineBit);

                const BSONObj localObject = element.Obj();
                _storageEngine = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kWeightsFieldName) {
            if (MONGO_unlikely(usedFields[kWeightsBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kWeightsBit);


            const BSONType variantType = element.type();
            switch (variantType) {
            case String:
            {
                _weights = element.str();
                break;
            }
            case Object:
            {
                const BSONObj localObject = element.Obj();
                _weights = BSONObj::getOwned(localObject);
                break;
            }
            default:
                ctxt.throwBadType(element, {BSONType::String, BSONType::Object});
                break;
            }
        }
        else if (fieldName == kDefault_languageFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kDefault_languageBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDefault_languageBit);

                _default_language = element.str();
            }
        }
        else if (fieldName == kLanguage_overrideFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kLanguage_overrideBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLanguage_overrideBit);

                _language_override = element.str();
            }
        }
        else if (fieldName == kTextIndexVersionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kTextIndexVersionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTextIndexVersionBit);

                _textIndexVersion = element.safeNumberInt();
            }
        }
        else if (fieldName == k2dsphereIndexVersionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[k2dsphereIndexVersionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(k2dsphereIndexVersionBit);

                _2dsphereIndexVersion = element.safeNumberInt();
            }
        }
        else if (fieldName == kBitsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kBitsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kBitsBit);

                _bits = element.safeNumberInt();
            }
        }
        else if (fieldName == kMinFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kMinBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMinBit);

                _min = element.safeNumberDouble();
            }
        }
        else if (fieldName == kMaxFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kMaxBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMaxBit);

                _max = element.safeNumberDouble();
            }
        }
        else if (fieldName == kBucketSizeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kBucketSizeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kBucketSizeBit);

                _bucketSize = element.safeNumberDouble();
            }
        }
        else if (fieldName == kCollationFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCollationBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollationBit);

                const BSONObj localObject = element.Obj();
                _collation = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kWildcardProjectionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kWildcardProjectionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kWildcardProjectionBit);

                const BSONObj localObject = element.Obj();
                _wildcardProjection = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kCoarsestIndexedLevelFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kCoarsestIndexedLevelBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCoarsestIndexedLevelBit);

                _coarsestIndexedLevel = element.safeNumberInt();
            }
        }
        else if (fieldName == kFinestIndexedLevelFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kFinestIndexedLevelBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kFinestIndexedLevelBit);

                _finestIndexedLevel = element.safeNumberInt();
            }
        }
        else if (fieldName == kDropDupsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kDropDupsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDropDupsBit);

                _dropDups = element.trueValue();
            }
        }
        else if (fieldName == kBuildUUIDFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kBuildUUIDBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kBuildUUIDBit);

                _buildUUID = UUID(uassertStatusOK(UUID::parse(element)));
            }
        }
        else if (fieldName == kSpecFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kSpecBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSpecBit);

                IDLParserErrorContext tempContext(kSpecFieldName, &ctxt);
                const auto localObject = element.Obj();
                _spec = mongo::NewIndexSpec::parse(tempContext, localObject);
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
    }

}


void ListIndexesReplyItem::serialize(BSONObjBuilder* builder) const {
    if (_v.is_initialized()) {
        builder->append(kVFieldName, _v.get());
    }

    if (_key.is_initialized()) {
        builder->append(kKeyFieldName, _key.get());
    }

    if (_name.is_initialized()) {
        builder->append(kNameFieldName, _name.get());
    }

    if (_background.is_initialized()) {
        builder->append(kBackgroundFieldName, _background.get());
    }

    if (_unique.is_initialized()) {
        builder->append(kUniqueFieldName, _unique.get());
    }

    if (_hidden.is_initialized()) {
        builder->append(kHiddenFieldName, _hidden.get());
    }

    if (_partialFilterExpression.is_initialized()) {
        builder->append(kPartialFilterExpressionFieldName, _partialFilterExpression.get());
    }

    if (_sparse.is_initialized()) {
        builder->append(kSparseFieldName, _sparse.get());
    }

    if (_expireAfterSeconds.is_initialized()) {
        builder->append(kExpireAfterSecondsFieldName, _expireAfterSeconds.get());
    }

    if (_storageEngine.is_initialized()) {
        builder->append(kStorageEngineFieldName, _storageEngine.get());
    }

    if (_weights.is_initialized()) {
        stdx::visit([builder](auto&& arg) {
            idl::idlSerialize(builder, kWeightsFieldName, arg);
        }, _weights.get());
    }

    if (_default_language.is_initialized()) {
        builder->append(kDefault_languageFieldName, _default_language.get());
    }

    if (_language_override.is_initialized()) {
        builder->append(kLanguage_overrideFieldName, _language_override.get());
    }

    if (_textIndexVersion.is_initialized()) {
        builder->append(kTextIndexVersionFieldName, _textIndexVersion.get());
    }

    if (_2dsphereIndexVersion.is_initialized()) {
        builder->append(k2dsphereIndexVersionFieldName, _2dsphereIndexVersion.get());
    }

    if (_bits.is_initialized()) {
        builder->append(kBitsFieldName, _bits.get());
    }

    if (_min.is_initialized()) {
        builder->append(kMinFieldName, _min.get());
    }

    if (_max.is_initialized()) {
        builder->append(kMaxFieldName, _max.get());
    }

    if (_bucketSize.is_initialized()) {
        builder->append(kBucketSizeFieldName, _bucketSize.get());
    }

    if (_collation.is_initialized()) {
        builder->append(kCollationFieldName, _collation.get());
    }

    if (_wildcardProjection.is_initialized()) {
        builder->append(kWildcardProjectionFieldName, _wildcardProjection.get());
    }

    if (_coarsestIndexedLevel.is_initialized()) {
        builder->append(kCoarsestIndexedLevelFieldName, _coarsestIndexedLevel.get());
    }

    if (_finestIndexedLevel.is_initialized()) {
        builder->append(kFinestIndexedLevelFieldName, _finestIndexedLevel.get());
    }

    if (_dropDups.is_initialized()) {
        builder->append(kDropDupsFieldName, _dropDups.get());
    }

    if (_buildUUID.is_initialized()) {
        ConstDataRange tempCDR = _buildUUID.get().toCDR();
        builder->append(kBuildUUIDFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    if (_spec.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kSpecFieldName));
        _spec.get().serialize(&subObjBuilder);
    }

}


BSONObj ListIndexesReplyItem::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData ListIndexesReplyCursor::kFirstBatchFieldName;
constexpr StringData ListIndexesReplyCursor::kIdFieldName;
constexpr StringData ListIndexesReplyCursor::kNsFieldName;


ListIndexesReplyCursor::ListIndexesReplyCursor() : _id(mongo::idl::preparsedValue<decltype(_id)>()), _ns(mongo::idl::preparsedValue<decltype(_ns)>()), _hasId(false), _hasNs(false), _hasFirstBatch(false) {
    // Used for initialization only
}
ListIndexesReplyCursor::ListIndexesReplyCursor(std::int64_t id, mongo::NamespaceString ns, std::vector<mongo::ListIndexesReplyItem> firstBatch) : _id(std::move(id)), _ns(std::move(ns)), _firstBatch(std::move(firstBatch)), _hasId(true), _hasNs(true), _hasFirstBatch(true) {
    // Used for initialization only
}


ListIndexesReplyCursor ListIndexesReplyCursor::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ListIndexesReplyCursor>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ListIndexesReplyCursor::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<3> usedFields;
    const size_t kIdBit = 0;
    const size_t kNsBit = 1;
    const size_t kFirstBatchBit = 2;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIdBit);

                _hasId = true;
                _id = element._numberLong();
            }
        }
        else if (fieldName == kNsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kNsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNsBit);

                _hasNs = true;
                _ns = NamespaceString(element.valueStringData());
            }
        }
        else if (fieldName == kFirstBatchFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kFirstBatchBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kFirstBatchBit);

                _hasFirstBatch = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kFirstBatchFieldName, &ctxt);
            std::vector<mongo::ListIndexesReplyItem> values;

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
                        IDLParserErrorContext tempContext(kFirstBatchFieldName, &ctxt);
                        const auto localObject = arrayElement.Obj();
                        values.emplace_back(mongo::ListIndexesReplyItem::parse(tempContext, localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _firstBatch = std::move(values);
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kIdBit]) {
            ctxt.throwMissingField(kIdFieldName);
        }
        if (!usedFields[kNsBit]) {
            ctxt.throwMissingField(kNsFieldName);
        }
        if (!usedFields[kFirstBatchBit]) {
            ctxt.throwMissingField(kFirstBatchFieldName);
        }
    }

}


void ListIndexesReplyCursor::serialize(BSONObjBuilder* builder) const {
    invariant(_hasId && _hasNs && _hasFirstBatch);

    builder->append(kIdFieldName, _id);

    {
        builder->append(kNsFieldName, _ns.toString());
    }

    {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kFirstBatchFieldName));
        for (const auto& item : _firstBatch) {
            BSONObjBuilder subObjBuilder(arrayBuilder.subobjStart());
            item.serialize(&subObjBuilder);
        }
    }

}


BSONObj ListIndexesReplyCursor::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData ListIndexesReply::kCursorFieldName;
constexpr StringData ListIndexesReply::kOkFieldName;


ListIndexesReply::ListIndexesReply() : _cursor(mongo::idl::preparsedValue<decltype(_cursor)>()), _hasCursor(false) {
    // Used for initialization only
}
ListIndexesReply::ListIndexesReply(mongo::ListIndexesReplyCursor cursor) : _cursor(std::move(cursor)), _hasCursor(true) {
    // Used for initialization only
}

void ListIndexesReply::validateOk(IDLParserErrorContext& ctxt, const double value)
{
    if (!(value >= 0.0)) {
        throwComparisonError<double>(ctxt, "ok", ">="_sd, value, 0.0);
    }
    if (!(value <= 1.0)) {
        throwComparisonError<double>(ctxt, "ok", "<="_sd, value, 1.0);
    }
}

void ListIndexesReply::validateOk(const double value)
{
    if (!(value >= 0.0)) {
        throwComparisonError<double>("ok", ">="_sd, value, 0.0);
    }
    if (!(value <= 1.0)) {
        throwComparisonError<double>("ok", "<="_sd, value, 1.0);
    }
}


ListIndexesReply ListIndexesReply::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ListIndexesReply>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ListIndexesReply::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kCursorBit = 0;
    const size_t kOkBit = 1;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kCursorFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCursorBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCursorBit);

                _hasCursor = true;
                IDLParserErrorContext tempContext(kCursorFieldName, &ctxt);
                const auto localObject = element.Obj();
                _cursor = mongo::ListIndexesReplyCursor::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kOkFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kOkBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kOkBit);

                {
                    auto value = element.safeNumberDouble();
                    validateOk(value);
                    _ok = std::move(value);
                }
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kCursorBit]) {
            ctxt.throwMissingField(kCursorFieldName);
        }
    }

}


void ListIndexesReply::serialize(BSONObjBuilder* builder) const {
    invariant(_hasCursor);

    {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kCursorFieldName));
        _cursor.serialize(&subObjBuilder);
    }

    if (_ok.is_initialized()) {
        builder->append(kOkFieldName, _ok.get());
    }

}


BSONObj ListIndexesReply::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData ListIndexes::kCursorFieldName;
constexpr StringData ListIndexes::kDbNameFieldName;
constexpr StringData ListIndexes::kIncludeBuildUUIDsFieldName;
constexpr StringData ListIndexes::kIsTimeseriesNamespaceFieldName;
constexpr StringData ListIndexes::kCommandName;

mongo::AuthorizationContract ListIndexes::kAuthorizationContract = AuthorizationContract(std::initializer_list<AccessCheckEnum>{AccessCheckEnum::kIsAuthorizedToParseNamespaceElement}, std::initializer_list<Privilege>{Privilege(ResourcePattern::forAuthorizationContract(MatchTypeEnum::kMatchExactNamespace), ActionSet{ActionType::listIndexes}),Privilege(ResourcePattern::forAuthorizationContract(MatchTypeEnum::kMatchClusterResource), ActionSet{ActionType::useUUID})});

const std::vector<StringData> ListIndexes::_knownBSONFields {
    ListIndexes::kCursorFieldName,
    ListIndexes::kIncludeBuildUUIDsFieldName,
    ListIndexes::kIsTimeseriesNamespaceFieldName,
    ListIndexes::kCommandName,
};
const std::vector<StringData> ListIndexes::_knownOP_MSGFields {
    ListIndexes::kCursorFieldName,
    ListIndexes::kDbNameFieldName,
    ListIndexes::kIncludeBuildUUIDsFieldName,
    ListIndexes::kIsTimeseriesNamespaceFieldName,
    ListIndexes::kCommandName,
};

ListIndexes::ListIndexes(const NamespaceStringOrUUID nssOrUUID) : _nssOrUUID(std::move(nssOrUUID)), _dbName(nssOrUUID.uuid() ? nssOrUUID.dbname() : nssOrUUID.nss().get().db().toString()), _hasDbName(true) {
    // Used for initialization only
}


ListIndexes ListIndexes::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    NamespaceString localNS;
    ListIndexes object(localNS);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ListIndexes::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<4> usedFields;
    const size_t kCursorBit = 0;
    const size_t kIncludeBuildUUIDsBit = 1;
    const size_t kIsTimeseriesNamespaceBit = 2;
    const size_t kDbNameBit = 3;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kCursorFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCursorBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCursorBit);

                IDLParserErrorContext tempContext(kCursorFieldName, &ctxt);
                const auto localObject = element.Obj();
                _cursor = mongo::SimpleCursorOptions::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kIncludeBuildUUIDsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kIncludeBuildUUIDsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIncludeBuildUUIDsBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                _includeBuildUUIDs = element.trueValue();
            }
        }
        else if (fieldName == kIsTimeseriesNamespaceFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kIsTimeseriesNamespaceBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIsTimeseriesNamespaceBit);

                _isTimeseriesNamespace = element.boolean();
            }
        }
        else if (fieldName == kDbNameFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kDbNameBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDbNameBit);

                _hasDbName = true;
                _dbName = element.str();
            }
        }
        else {
            if (!mongo::isGenericArgument(fieldName)) {
                ctxt.throwUnknownField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nssOrUUID.nss() || _nssOrUUID.uuid());
    _nssOrUUID = ctxt.parseNsOrUUID(_dbName, commandElement);
}

ListIndexes ListIndexes::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    NamespaceString localNS;
    ListIndexes object(localNS);
    object.parseProtected(ctxt, request);
    return object;
}
void ListIndexes::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<4> usedFields;
    const size_t kCursorBit = 0;
    const size_t kIncludeBuildUUIDsBit = 1;
    const size_t kIsTimeseriesNamespaceBit = 2;
    const size_t kDbNameBit = 3;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kCursorFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCursorBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCursorBit);

                IDLParserErrorContext tempContext(kCursorFieldName, &ctxt);
                const auto localObject = element.Obj();
                _cursor = mongo::SimpleCursorOptions::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kIncludeBuildUUIDsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kIncludeBuildUUIDsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIncludeBuildUUIDsBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                _includeBuildUUIDs = element.trueValue();
            }
        }
        else if (fieldName == kIsTimeseriesNamespaceFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kIsTimeseriesNamespaceBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIsTimeseriesNamespaceBit);

                _isTimeseriesNamespace = element.boolean();
            }
        }
        else if (fieldName == kDbNameFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kDbNameBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDbNameBit);

                _hasDbName = true;
                _dbName = element.str();
            }
        }
        else {
            if (!mongo::isGenericArgument(fieldName)) {
                ctxt.throwUnknownField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nssOrUUID.nss() || _nssOrUUID.uuid());
    _nssOrUUID = ctxt.parseNsOrUUID(_dbName, commandElement);
}

void ListIndexes::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    _nssOrUUID.serialize(builder, "listIndexes"_sd);

    if (_cursor.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kCursorFieldName));
        _cursor.get().serialize(&subObjBuilder);
    }

    if (_includeBuildUUIDs.is_initialized()) {
        builder->append(kIncludeBuildUUIDsFieldName, _includeBuildUUIDs.get());
    }

    if (_isTimeseriesNamespace.is_initialized()) {
        builder->append(kIsTimeseriesNamespaceFieldName, _isTimeseriesNamespace.get());
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest ListIndexes::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        _nssOrUUID.serialize(builder, "listIndexes"_sd);

        if (_cursor.is_initialized()) {
            BSONObjBuilder subObjBuilder(builder->subobjStart(kCursorFieldName));
            _cursor.get().serialize(&subObjBuilder);
        }

        if (_includeBuildUUIDs.is_initialized()) {
            builder->append(kIncludeBuildUUIDsFieldName, _includeBuildUUIDs.get());
        }

        if (_isTimeseriesNamespace.is_initialized()) {
            builder->append(kIsTimeseriesNamespaceFieldName, _isTimeseriesNamespace.get());
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj ListIndexes::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
