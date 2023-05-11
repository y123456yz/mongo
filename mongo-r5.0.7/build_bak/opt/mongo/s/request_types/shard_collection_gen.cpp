/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/s/request_types/shard_collection_gen.h --output build/opt/mongo/s/request_types/shard_collection_gen.cpp src/mongo/s/request_types/shard_collection.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/s/request_types/shard_collection_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData ConfigsvrShardCollectionRequest::k_configsvrShardCollectionFieldName;
constexpr StringData ConfigsvrShardCollectionRequest::kCollationFieldName;
constexpr StringData ConfigsvrShardCollectionRequest::kGetUUIDfromPrimaryShardFieldName;
constexpr StringData ConfigsvrShardCollectionRequest::kInitialSplitPointsFieldName;
constexpr StringData ConfigsvrShardCollectionRequest::kKeyFieldName;
constexpr StringData ConfigsvrShardCollectionRequest::kNumInitialChunksFieldName;
constexpr StringData ConfigsvrShardCollectionRequest::kPresplitHashedZonesFieldName;
constexpr StringData ConfigsvrShardCollectionRequest::kUniqueFieldName;


ConfigsvrShardCollectionRequest::ConfigsvrShardCollectionRequest() : _key(mongo::idl::preparsedValue<decltype(_key)>()), _hasKey(false) {
    // Used for initialization only
}
ConfigsvrShardCollectionRequest::ConfigsvrShardCollectionRequest(mongo::BSONObj key) : _key(std::move(key)), _hasKey(true) {
    // Used for initialization only
}


ConfigsvrShardCollectionRequest ConfigsvrShardCollectionRequest::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ConfigsvrShardCollectionRequest>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ConfigsvrShardCollectionRequest::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<8> usedFields;
    const size_t k_configsvrShardCollectionBit = 0;
    const size_t kKeyBit = 1;
    const size_t kUniqueBit = 2;
    const size_t kNumInitialChunksBit = 3;
    const size_t kPresplitHashedZonesBit = 4;
    const size_t kInitialSplitPointsBit = 5;
    const size_t kCollationBit = 6;
    const size_t kGetUUIDfromPrimaryShardBit = 7;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == k_configsvrShardCollectionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[k_configsvrShardCollectionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(k_configsvrShardCollectionBit);

                __configsvrShardCollection = NamespaceString(element.valueStringData());
            }
        }
        else if (fieldName == kKeyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kKeyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kKeyBit);

                _hasKey = true;
                _key = element.Obj();
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
        else if (fieldName == kNumInitialChunksFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kNumInitialChunksBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNumInitialChunksBit);

                _numInitialChunks = element.safeNumberLong();
            }
        }
        else if (fieldName == kPresplitHashedZonesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kPresplitHashedZonesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPresplitHashedZonesBit);

                _presplitHashedZones = element.boolean();
            }
        }
        else if (fieldName == kInitialSplitPointsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kInitialSplitPointsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kInitialSplitPointsBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kInitialSplitPointsFieldName, &ctxt);
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
            _initialSplitPoints = std::move(values);
        }
        else if (fieldName == kCollationFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCollationBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollationBit);

                _collation = element.Obj();
            }
        }
        else if (fieldName == kGetUUIDfromPrimaryShardFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kGetUUIDfromPrimaryShardBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kGetUUIDfromPrimaryShardBit);

                _getUUIDfromPrimaryShard = element.boolean();
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
        if (!usedFields[kKeyBit]) {
            ctxt.throwMissingField(kKeyFieldName);
        }
        if (!usedFields[kUniqueBit]) {
            _unique = false;
        }
        if (!usedFields[kNumInitialChunksBit]) {
            _numInitialChunks = 0;
        }
        if (!usedFields[kPresplitHashedZonesBit]) {
            _presplitHashedZones = false;
        }
        if (!usedFields[kGetUUIDfromPrimaryShardBit]) {
            _getUUIDfromPrimaryShard = true;
        }
    }

}


void ConfigsvrShardCollectionRequest::serialize(BSONObjBuilder* builder) const {
    invariant(_hasKey);

    if (__configsvrShardCollection.is_initialized()) {
        builder->append(k_configsvrShardCollectionFieldName, __configsvrShardCollection.get().toString());
    }

    builder->append(kKeyFieldName, _key);

    builder->append(kUniqueFieldName, _unique);

    builder->append(kNumInitialChunksFieldName, _numInitialChunks);

    builder->append(kPresplitHashedZonesFieldName, _presplitHashedZones);

    if (_initialSplitPoints.is_initialized()) {
        builder->append(kInitialSplitPointsFieldName, _initialSplitPoints.get());
    }

    if (_collation.is_initialized()) {
        builder->append(kCollationFieldName, _collation.get());
    }

    builder->append(kGetUUIDfromPrimaryShardFieldName, _getUUIDfromPrimaryShard);

}


BSONObj ConfigsvrShardCollectionRequest::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData ConfigsvrShardCollectionResponse::kCollectionUUIDFieldName;
constexpr StringData ConfigsvrShardCollectionResponse::kCollectionshardedFieldName;


ConfigsvrShardCollectionResponse::ConfigsvrShardCollectionResponse() : _collectionsharded(mongo::idl::preparsedValue<decltype(_collectionsharded)>()), _hasCollectionsharded(false) {
    // Used for initialization only
}
ConfigsvrShardCollectionResponse::ConfigsvrShardCollectionResponse(std::string collectionsharded) : _collectionsharded(std::move(collectionsharded)), _hasCollectionsharded(true) {
    // Used for initialization only
}


ConfigsvrShardCollectionResponse ConfigsvrShardCollectionResponse::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ConfigsvrShardCollectionResponse>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ConfigsvrShardCollectionResponse::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kCollectionshardedBit = 0;
    const size_t kCollectionUUIDBit = 1;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kCollectionshardedFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kCollectionshardedBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollectionshardedBit);

                _hasCollectionsharded = true;
                _collectionsharded = element.str();
            }
        }
        else if (fieldName == kCollectionUUIDFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kCollectionUUIDBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollectionUUIDBit);

                _collectionUUID = UUID(uassertStatusOK(UUID::parse(element)));
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
        if (!usedFields[kCollectionshardedBit]) {
            ctxt.throwMissingField(kCollectionshardedFieldName);
        }
    }

}


void ConfigsvrShardCollectionResponse::serialize(BSONObjBuilder* builder) const {
    invariant(_hasCollectionsharded);

    builder->append(kCollectionshardedFieldName, _collectionsharded);

    if (_collectionUUID.is_initialized()) {
        ConstDataRange tempCDR = _collectionUUID.get().toCDR();
        builder->append(kCollectionUUIDFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

}


BSONObj ConfigsvrShardCollectionResponse::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData ShardsvrShardCollectionRequest::k_shardsvrShardCollectionFieldName;
constexpr StringData ShardsvrShardCollectionRequest::kCollationFieldName;
constexpr StringData ShardsvrShardCollectionRequest::kGetUUIDfromPrimaryShardFieldName;
constexpr StringData ShardsvrShardCollectionRequest::kInitialSplitPointsFieldName;
constexpr StringData ShardsvrShardCollectionRequest::kKeyFieldName;
constexpr StringData ShardsvrShardCollectionRequest::kNumInitialChunksFieldName;
constexpr StringData ShardsvrShardCollectionRequest::kPresplitHashedZonesFieldName;
constexpr StringData ShardsvrShardCollectionRequest::kUniqueFieldName;


ShardsvrShardCollectionRequest::ShardsvrShardCollectionRequest() : _key(mongo::idl::preparsedValue<decltype(_key)>()), _hasKey(false) {
    // Used for initialization only
}
ShardsvrShardCollectionRequest::ShardsvrShardCollectionRequest(mongo::BSONObj key) : _key(std::move(key)), _hasKey(true) {
    // Used for initialization only
}


ShardsvrShardCollectionRequest ShardsvrShardCollectionRequest::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ShardsvrShardCollectionRequest>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ShardsvrShardCollectionRequest::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<8> usedFields;
    const size_t k_shardsvrShardCollectionBit = 0;
    const size_t kKeyBit = 1;
    const size_t kUniqueBit = 2;
    const size_t kNumInitialChunksBit = 3;
    const size_t kPresplitHashedZonesBit = 4;
    const size_t kInitialSplitPointsBit = 5;
    const size_t kCollationBit = 6;
    const size_t kGetUUIDfromPrimaryShardBit = 7;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == k_shardsvrShardCollectionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[k_shardsvrShardCollectionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(k_shardsvrShardCollectionBit);

                __shardsvrShardCollection = NamespaceString(element.valueStringData());
            }
        }
        else if (fieldName == kKeyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kKeyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kKeyBit);

                _hasKey = true;
                _key = element.Obj();
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
        else if (fieldName == kNumInitialChunksFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kNumInitialChunksBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNumInitialChunksBit);

                _numInitialChunks = element.safeNumberLong();
            }
        }
        else if (fieldName == kPresplitHashedZonesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kPresplitHashedZonesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPresplitHashedZonesBit);

                _presplitHashedZones = element.boolean();
            }
        }
        else if (fieldName == kInitialSplitPointsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kInitialSplitPointsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kInitialSplitPointsBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kInitialSplitPointsFieldName, &ctxt);
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
            _initialSplitPoints = std::move(values);
        }
        else if (fieldName == kCollationFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCollationBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollationBit);

                _collation = element.Obj();
            }
        }
        else if (fieldName == kGetUUIDfromPrimaryShardFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kGetUUIDfromPrimaryShardBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kGetUUIDfromPrimaryShardBit);

                _getUUIDfromPrimaryShard = element.boolean();
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
        if (!usedFields[kKeyBit]) {
            ctxt.throwMissingField(kKeyFieldName);
        }
        if (!usedFields[kUniqueBit]) {
            _unique = false;
        }
        if (!usedFields[kNumInitialChunksBit]) {
            _numInitialChunks = 0;
        }
        if (!usedFields[kPresplitHashedZonesBit]) {
            _presplitHashedZones = false;
        }
        if (!usedFields[kGetUUIDfromPrimaryShardBit]) {
            _getUUIDfromPrimaryShard = true;
        }
    }

}


void ShardsvrShardCollectionRequest::serialize(BSONObjBuilder* builder) const {
    invariant(_hasKey);

    if (__shardsvrShardCollection.is_initialized()) {
        builder->append(k_shardsvrShardCollectionFieldName, __shardsvrShardCollection.get().toString());
    }

    builder->append(kKeyFieldName, _key);

    builder->append(kUniqueFieldName, _unique);

    builder->append(kNumInitialChunksFieldName, _numInitialChunks);

    builder->append(kPresplitHashedZonesFieldName, _presplitHashedZones);

    if (_initialSplitPoints.is_initialized()) {
        builder->append(kInitialSplitPointsFieldName, _initialSplitPoints.get());
    }

    if (_collation.is_initialized()) {
        builder->append(kCollationFieldName, _collation.get());
    }

    builder->append(kGetUUIDfromPrimaryShardFieldName, _getUUIDfromPrimaryShard);

}


BSONObj ShardsvrShardCollectionRequest::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData ShardsvrShardCollectionResponse::kCollectionUUIDFieldName;
constexpr StringData ShardsvrShardCollectionResponse::kCollectionshardedFieldName;


ShardsvrShardCollectionResponse::ShardsvrShardCollectionResponse() : _collectionsharded(mongo::idl::preparsedValue<decltype(_collectionsharded)>()), _hasCollectionsharded(false) {
    // Used for initialization only
}
ShardsvrShardCollectionResponse::ShardsvrShardCollectionResponse(std::string collectionsharded) : _collectionsharded(std::move(collectionsharded)), _hasCollectionsharded(true) {
    // Used for initialization only
}


ShardsvrShardCollectionResponse ShardsvrShardCollectionResponse::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ShardsvrShardCollectionResponse>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ShardsvrShardCollectionResponse::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kCollectionshardedBit = 0;
    const size_t kCollectionUUIDBit = 1;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kCollectionshardedFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kCollectionshardedBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollectionshardedBit);

                _hasCollectionsharded = true;
                _collectionsharded = element.str();
            }
        }
        else if (fieldName == kCollectionUUIDFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kCollectionUUIDBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollectionUUIDBit);

                _collectionUUID = UUID(uassertStatusOK(UUID::parse(element)));
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
        if (!usedFields[kCollectionshardedBit]) {
            ctxt.throwMissingField(kCollectionshardedFieldName);
        }
    }

}


void ShardsvrShardCollectionResponse::serialize(BSONObjBuilder* builder) const {
    invariant(_hasCollectionsharded);

    builder->append(kCollectionshardedFieldName, _collectionsharded);

    if (_collectionUUID.is_initialized()) {
        ConstDataRange tempCDR = _collectionUUID.get().toCDR();
        builder->append(kCollectionUUIDFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

}


BSONObj ShardsvrShardCollectionResponse::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
