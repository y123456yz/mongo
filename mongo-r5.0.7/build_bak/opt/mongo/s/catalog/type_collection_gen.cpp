/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/s/catalog/type_collection_gen.h --output build/opt/mongo/s/catalog/type_collection_gen.cpp src/mongo/s/catalog/type_collection.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/s/catalog/type_collection_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData CollectionTypeBase::kNoBalanceFieldName;
constexpr StringData CollectionTypeBase::kNssFieldName;
constexpr StringData CollectionTypeBase::kPermitMigrationsFieldName;
constexpr StringData CollectionTypeBase::kPre22CompatibleEpochFieldName;
constexpr StringData CollectionTypeBase::kPre50CompatibleAllowMigrationsFieldName;
constexpr StringData CollectionTypeBase::kPre50CompatibleDefaultCollationFieldName;
constexpr StringData CollectionTypeBase::kPre50CompatibleDroppedFieldName;
constexpr StringData CollectionTypeBase::kPre50CompatibleKeyPatternFieldName;
constexpr StringData CollectionTypeBase::kPre50CompatibleUuidFieldName;
constexpr StringData CollectionTypeBase::kReshardingFieldsFieldName;
constexpr StringData CollectionTypeBase::kTimeseriesFieldsFieldName;
constexpr StringData CollectionTypeBase::kTimestampFieldName;
constexpr StringData CollectionTypeBase::kUniqueFieldName;
constexpr StringData CollectionTypeBase::kUpdatedAtFieldName;


CollectionTypeBase::CollectionTypeBase() : _nss(mongo::idl::preparsedValue<decltype(_nss)>()), _updatedAt(mongo::idl::preparsedValue<decltype(_updatedAt)>()), _hasNss(false), _hasUpdatedAt(false) {
    // Used for initialization only
}
CollectionTypeBase::CollectionTypeBase(mongo::NamespaceString nss, mongo::Date_t updatedAt) : _nss(std::move(nss)), _updatedAt(std::move(updatedAt)), _hasNss(true), _hasUpdatedAt(true) {
    // Used for initialization only
}


CollectionTypeBase CollectionTypeBase::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<CollectionTypeBase>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void CollectionTypeBase::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<14> usedFields;
    const size_t kNssBit = 0;
    const size_t kPre22CompatibleEpochBit = 1;
    const size_t kUpdatedAtBit = 2;
    const size_t kTimestampBit = 3;
    const size_t kPre50CompatibleUuidBit = 4;
    const size_t kPre50CompatibleDroppedBit = 5;
    const size_t kPre50CompatibleKeyPatternBit = 6;
    const size_t kPre50CompatibleDefaultCollationBit = 7;
    const size_t kUniqueBit = 8;
    const size_t kNoBalanceBit = 9;
    const size_t kReshardingFieldsBit = 10;
    const size_t kPre50CompatibleAllowMigrationsBit = 11;
    const size_t kTimeseriesFieldsBit = 12;
    const size_t kPermitMigrationsBit = 13;
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
        else if (fieldName == kPre22CompatibleEpochFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, jstOID))) {
                if (MONGO_unlikely(usedFields[kPre22CompatibleEpochBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPre22CompatibleEpochBit);

                _pre22CompatibleEpoch = element.OID();
            }
        }
        else if (fieldName == kUpdatedAtFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Date))) {
                if (MONGO_unlikely(usedFields[kUpdatedAtBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUpdatedAtBit);

                _hasUpdatedAt = true;
                _updatedAt = element.date();
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
        else if (fieldName == kPre50CompatibleUuidFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kPre50CompatibleUuidBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPre50CompatibleUuidBit);

                _pre50CompatibleUuid = UUID(uassertStatusOK(UUID::parse(element)));
            }
        }
        else if (fieldName == kPre50CompatibleDroppedFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kPre50CompatibleDroppedBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPre50CompatibleDroppedBit);

                _pre50CompatibleDropped = element.boolean();
            }
        }
        else if (fieldName == kPre50CompatibleKeyPatternFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kPre50CompatibleKeyPatternBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPre50CompatibleKeyPatternBit);

                const BSONObj localObject = element.Obj();
                _pre50CompatibleKeyPattern = KeyPattern::fromBSON(localObject);
            }
        }
        else if (fieldName == kPre50CompatibleDefaultCollationFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kPre50CompatibleDefaultCollationBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPre50CompatibleDefaultCollationBit);

                const BSONObj localObject = element.Obj();
                _pre50CompatibleDefaultCollation = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kUniqueFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kUniqueBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUniqueBit);

                _unique = element.boolean();
            }
        }
        else if (fieldName == kNoBalanceFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kNoBalanceBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNoBalanceBit);

                _noBalance = element.boolean();
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
        else if (fieldName == kPermitMigrationsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kPermitMigrationsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPermitMigrationsBit);

                _permitMigrations = element.boolean();
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
        if (!usedFields[kUpdatedAtBit]) {
            ctxt.throwMissingField(kUpdatedAtFieldName);
        }
        if (!usedFields[kUniqueBit]) {
            _unique = false;
        }
        if (!usedFields[kNoBalanceBit]) {
            _noBalance = false;
        }
    }

}


void CollectionTypeBase::serialize(BSONObjBuilder* builder) const {
    invariant(_hasNss && _hasUpdatedAt);

    {
        builder->append(kNssFieldName, _nss.toString());
    }

    if (_pre22CompatibleEpoch.is_initialized()) {
        builder->append(kPre22CompatibleEpochFieldName, _pre22CompatibleEpoch.get());
    }

    builder->append(kUpdatedAtFieldName, _updatedAt);

    if (_timestamp.is_initialized()) {
        builder->append(kTimestampFieldName, _timestamp.get());
    }

    if (_pre50CompatibleUuid.is_initialized()) {
        ConstDataRange tempCDR = _pre50CompatibleUuid.get().toCDR();
        builder->append(kPre50CompatibleUuidFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    if (_pre50CompatibleDropped.is_initialized()) {
        builder->append(kPre50CompatibleDroppedFieldName, _pre50CompatibleDropped.get());
    }

    if (_pre50CompatibleKeyPattern.is_initialized()) {
        const BSONObj localObject = _pre50CompatibleKeyPattern.get().toBSON();
        builder->append(kPre50CompatibleKeyPatternFieldName, localObject);
    }

    if (_pre50CompatibleDefaultCollation.is_initialized()) {
        builder->append(kPre50CompatibleDefaultCollationFieldName, _pre50CompatibleDefaultCollation.get());
    }

    builder->append(kUniqueFieldName, _unique);

    builder->append(kNoBalanceFieldName, _noBalance);

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

    if (_permitMigrations.is_initialized()) {
        builder->append(kPermitMigrationsFieldName, _permitMigrations.get());
    }

}


BSONObj CollectionTypeBase::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
