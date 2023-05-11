/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/s/type_shard_collection_gen.h --output build/opt/mongo/db/s/type_shard_collection_gen.cpp src/mongo/db/s/type_shard_collection.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/s/type_shard_collection_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData ShardCollectionTypeBase::kDefaultCollationFieldName;
constexpr StringData ShardCollectionTypeBase::kEnterCriticalSectionCounterFieldName;
constexpr StringData ShardCollectionTypeBase::kEpochFieldName;
constexpr StringData ShardCollectionTypeBase::kKeyPatternFieldName;
constexpr StringData ShardCollectionTypeBase::kLastRefreshedCollectionVersionFieldName;
constexpr StringData ShardCollectionTypeBase::kNssFieldName;
constexpr StringData ShardCollectionTypeBase::kPre50CompatibleAllowMigrationsFieldName;
constexpr StringData ShardCollectionTypeBase::kRefreshingFieldName;
constexpr StringData ShardCollectionTypeBase::kReshardingFieldsFieldName;
constexpr StringData ShardCollectionTypeBase::kTimeseriesFieldsFieldName;
constexpr StringData ShardCollectionTypeBase::kTimestampFieldName;
constexpr StringData ShardCollectionTypeBase::kUniqueFieldName;
constexpr StringData ShardCollectionTypeBase::kUuidFieldName;


ShardCollectionTypeBase::ShardCollectionTypeBase() : _nss(mongo::idl::preparsedValue<decltype(_nss)>()), _epoch(mongo::idl::preparsedValue<decltype(_epoch)>()), _uuid(mongo::idl::preparsedValue<decltype(_uuid)>()), _keyPattern(mongo::idl::preparsedValue<decltype(_keyPattern)>()), _unique(mongo::idl::preparsedValue<decltype(_unique)>()), _hasNss(false), _hasEpoch(false), _hasUuid(false), _hasKeyPattern(false), _hasUnique(false) {
    // Used for initialization only
}
ShardCollectionTypeBase::ShardCollectionTypeBase(mongo::NamespaceString nss, mongo::OID epoch, mongo::UUID uuid, mongo::KeyPattern keyPattern, bool unique) : _nss(std::move(nss)), _epoch(std::move(epoch)), _uuid(std::move(uuid)), _keyPattern(std::move(keyPattern)), _unique(std::move(unique)), _hasNss(true), _hasEpoch(true), _hasUuid(true), _hasKeyPattern(true), _hasUnique(true) {
    // Used for initialization only
}


ShardCollectionTypeBase ShardCollectionTypeBase::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ShardCollectionTypeBase>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ShardCollectionTypeBase::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<13> usedFields;
    const size_t kNssBit = 0;
    const size_t kEpochBit = 1;
    const size_t kTimestampBit = 2;
    const size_t kUuidBit = 3;
    const size_t kKeyPatternBit = 4;
    const size_t kDefaultCollationBit = 5;
    const size_t kUniqueBit = 6;
    const size_t kRefreshingBit = 7;
    const size_t kLastRefreshedCollectionVersionBit = 8;
    const size_t kEnterCriticalSectionCounterBit = 9;
    const size_t kReshardingFieldsBit = 10;
    const size_t kPre50CompatibleAllowMigrationsBit = 11;
    const size_t kTimeseriesFieldsBit = 12;
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
        else if (fieldName == kEpochFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, jstOID))) {
                if (MONGO_unlikely(usedFields[kEpochBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kEpochBit);

                _hasEpoch = true;
                _epoch = element.OID();
            }
        }
        else if (fieldName == kTimestampFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, bsonTimestamp))) {
                if (MONGO_unlikely(usedFields[kTimestampBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTimestampBit);

                _timestamp = element.timestamp();
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
        else if (fieldName == kKeyPatternFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kKeyPatternBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kKeyPatternBit);

                _hasKeyPattern = true;
                const BSONObj localObject = element.Obj();
                _keyPattern = KeyPattern::fromBSON(localObject);
            }
        }
        else if (fieldName == kDefaultCollationFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kDefaultCollationBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDefaultCollationBit);

                const BSONObj localObject = element.Obj();
                _defaultCollation = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kUniqueFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kUniqueBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUniqueBit);

                _hasUnique = true;
                _unique = element.boolean();
            }
        }
        else if (fieldName == kRefreshingFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kRefreshingBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRefreshingBit);

                _refreshing = element.boolean();
            }
        }
        else if (fieldName == kLastRefreshedCollectionVersionFieldName) {
            if (MONGO_unlikely(usedFields[kLastRefreshedCollectionVersionBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kLastRefreshedCollectionVersionBit);

            _lastRefreshedCollectionVersion = ChunkVersion::legacyFromBSONThrowing(element);
        }
        else if (fieldName == kEnterCriticalSectionCounterFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberInt))) {
                if (MONGO_unlikely(usedFields[kEnterCriticalSectionCounterBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kEnterCriticalSectionCounterBit);

                _enterCriticalSectionCounter = element._numberInt();
            }
        }
        else if (fieldName == kReshardingFieldsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kReshardingFieldsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kReshardingFieldsBit);

                IDLParserErrorContext tempContext(kReshardingFieldsFieldName, &ctxt);
                const auto localObject = element.Obj();
                _reshardingFields = mongo::TypeCollectionReshardingFields::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kPre50CompatibleAllowMigrationsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kPre50CompatibleAllowMigrationsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPre50CompatibleAllowMigrationsBit);

                _pre50CompatibleAllowMigrations = element.boolean();
            }
        }
        else if (fieldName == kTimeseriesFieldsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kTimeseriesFieldsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTimeseriesFieldsBit);

                IDLParserErrorContext tempContext(kTimeseriesFieldsFieldName, &ctxt);
                const auto localObject = element.Obj();
                _timeseriesFields = mongo::TypeCollectionTimeseriesFields::parse(tempContext, localObject);
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
        if (!usedFields[kEpochBit]) {
            ctxt.throwMissingField(kEpochFieldName);
        }
        if (!usedFields[kUuidBit]) {
            ctxt.throwMissingField(kUuidFieldName);
        }
        if (!usedFields[kKeyPatternBit]) {
            ctxt.throwMissingField(kKeyPatternFieldName);
        }
        if (!usedFields[kDefaultCollationBit]) {
            _defaultCollation = BSONObj();
        }
        if (!usedFields[kUniqueBit]) {
            ctxt.throwMissingField(kUniqueFieldName);
        }
    }

}


void ShardCollectionTypeBase::serialize(BSONObjBuilder* builder) const {
    invariant(_hasNss && _hasEpoch && _hasUuid && _hasKeyPattern && _hasUnique);

    {
        builder->append(kNssFieldName, _nss.toString());
    }

    builder->append(kEpochFieldName, _epoch);

    if (_timestamp.is_initialized()) {
        builder->append(kTimestampFieldName, _timestamp.get());
    }

    {
        ConstDataRange tempCDR = _uuid.toCDR();
        builder->append(kUuidFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    {
        const BSONObj localObject = _keyPattern.toBSON();
        builder->append(kKeyPatternFieldName, localObject);
    }

    builder->append(kDefaultCollationFieldName, _defaultCollation);

    builder->append(kUniqueFieldName, _unique);

    if (_refreshing.is_initialized()) {
        builder->append(kRefreshingFieldName, _refreshing.get());
    }

    if (_lastRefreshedCollectionVersion.is_initialized()) {
        _lastRefreshedCollectionVersion.get().legacyToBSON(kLastRefreshedCollectionVersionFieldName, builder);
    }

    if (_enterCriticalSectionCounter.is_initialized()) {
        builder->append(kEnterCriticalSectionCounterFieldName, _enterCriticalSectionCounter.get());
    }

    if (_reshardingFields.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kReshardingFieldsFieldName));
        _reshardingFields.get().serialize(&subObjBuilder);
    }

    if (_pre50CompatibleAllowMigrations.is_initialized()) {
        builder->append(kPre50CompatibleAllowMigrationsFieldName, _pre50CompatibleAllowMigrations.get());
    }

    if (_timeseriesFields.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kTimeseriesFieldsFieldName));
        _timeseriesFields.get().serialize(&subObjBuilder);
    }

}


BSONObj ShardCollectionTypeBase::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
