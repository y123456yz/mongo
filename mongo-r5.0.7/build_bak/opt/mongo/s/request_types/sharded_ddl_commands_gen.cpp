/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/s/request_types/sharded_ddl_commands_gen.h --output build/opt/mongo/s/request_types/sharded_ddl_commands_gen.cpp src/mongo/s/request_types/sharded_ddl_commands.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/s/request_types/sharded_ddl_commands_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData ConfigsvrCreateDatabaseResponse::kDatabaseVersionFieldName;


ConfigsvrCreateDatabaseResponse::ConfigsvrCreateDatabaseResponse() : _databaseVersion(mongo::idl::preparsedValue<decltype(_databaseVersion)>()), _hasDatabaseVersion(false) {
    // Used for initialization only
}
ConfigsvrCreateDatabaseResponse::ConfigsvrCreateDatabaseResponse(mongo::DatabaseVersionBase databaseVersion) : _databaseVersion(std::move(databaseVersion)), _hasDatabaseVersion(true) {
    // Used for initialization only
}


ConfigsvrCreateDatabaseResponse ConfigsvrCreateDatabaseResponse::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ConfigsvrCreateDatabaseResponse>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ConfigsvrCreateDatabaseResponse::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kDatabaseVersionBit = 0;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kDatabaseVersionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kDatabaseVersionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDatabaseVersionBit);

                _hasDatabaseVersion = true;
                IDLParserErrorContext tempContext(kDatabaseVersionFieldName, &ctxt);
                const auto localObject = element.Obj();
                _databaseVersion = mongo::DatabaseVersionBase::parse(tempContext, localObject);
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
        if (!usedFields[kDatabaseVersionBit]) {
            ctxt.throwMissingField(kDatabaseVersionFieldName);
        }
    }

}


void ConfigsvrCreateDatabaseResponse::serialize(BSONObjBuilder* builder) const {
    invariant(_hasDatabaseVersion);

    {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kDatabaseVersionFieldName));
        _databaseVersion.serialize(&subObjBuilder);
    }

}


BSONObj ConfigsvrCreateDatabaseResponse::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData RenameCollectionRequest::kDropTargetFieldName;
constexpr StringData RenameCollectionRequest::kStayTempFieldName;
constexpr StringData RenameCollectionRequest::kToFieldName;


RenameCollectionRequest::RenameCollectionRequest() : _to(mongo::idl::preparsedValue<decltype(_to)>()), _hasTo(false) {
    // Used for initialization only
}
RenameCollectionRequest::RenameCollectionRequest(mongo::NamespaceString to) : _to(std::move(to)), _hasTo(true) {
    // Used for initialization only
}


RenameCollectionRequest RenameCollectionRequest::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<RenameCollectionRequest>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void RenameCollectionRequest::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<3> usedFields;
    const size_t kToBit = 0;
    const size_t kDropTargetBit = 1;
    const size_t kStayTempBit = 2;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kToFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kToBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kToBit);

                _hasTo = true;
                _to = NamespaceString(element.valueStringData());
            }
        }
        else if (fieldName == kDropTargetFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kDropTargetBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDropTargetBit);

                _dropTarget = element.boolean();
            }
        }
        else if (fieldName == kStayTempFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kStayTempBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStayTempBit);

                _stayTemp = element.boolean();
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
        if (!usedFields[kToBit]) {
            ctxt.throwMissingField(kToFieldName);
        }
        if (!usedFields[kDropTargetBit]) {
            _dropTarget = false;
        }
        if (!usedFields[kStayTempBit]) {
            _stayTemp = false;
        }
    }

}


void RenameCollectionRequest::serialize(BSONObjBuilder* builder) const {
    invariant(_hasTo);

    {
        builder->append(kToFieldName, _to.toString());
    }

    builder->append(kDropTargetFieldName, _dropTarget);

    builder->append(kStayTempFieldName, _stayTemp);

}


BSONObj RenameCollectionRequest::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData RenameCollectionResponse::kCollectionVersionFieldName;


RenameCollectionResponse::RenameCollectionResponse() : _collectionVersion(mongo::idl::preparsedValue<decltype(_collectionVersion)>()), _hasCollectionVersion(false) {
    // Used for initialization only
}
RenameCollectionResponse::RenameCollectionResponse(mongo::ChunkVersion collectionVersion) : _collectionVersion(std::move(collectionVersion)), _hasCollectionVersion(true) {
    // Used for initialization only
}


RenameCollectionResponse RenameCollectionResponse::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<RenameCollectionResponse>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void RenameCollectionResponse::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kCollectionVersionBit = 0;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kCollectionVersionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCollectionVersionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollectionVersionBit);

                _hasCollectionVersion = true;
                const BSONObj localObject = element.Obj();
                _collectionVersion = ChunkVersion::fromBSONThrowing(localObject);
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
        if (!usedFields[kCollectionVersionBit]) {
            ctxt.throwMissingField(kCollectionVersionFieldName);
        }
    }

}


void RenameCollectionResponse::serialize(BSONObjBuilder* builder) const {
    invariant(_hasCollectionVersion);

    {
        const BSONObj localObject = _collectionVersion.toBSON();
        builder->append(kCollectionVersionFieldName, localObject);
    }

}


BSONObj RenameCollectionResponse::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData CreateCollectionRequest::kCollationFieldName;
constexpr StringData CreateCollectionRequest::kInitialSplitPointsFieldName;
constexpr StringData CreateCollectionRequest::kNumInitialChunksFieldName;
constexpr StringData CreateCollectionRequest::kPresplitHashedZonesFieldName;
constexpr StringData CreateCollectionRequest::kShardKeyFieldName;
constexpr StringData CreateCollectionRequest::kTimeseriesFieldName;
constexpr StringData CreateCollectionRequest::kUniqueFieldName;


CreateCollectionRequest::CreateCollectionRequest()  {
    // Used for initialization only
}


CreateCollectionRequest CreateCollectionRequest::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<CreateCollectionRequest>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void CreateCollectionRequest::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<7> usedFields;
    const size_t kShardKeyBit = 0;
    const size_t kUniqueBit = 1;
    const size_t kNumInitialChunksBit = 2;
    const size_t kPresplitHashedZonesBit = 3;
    const size_t kInitialSplitPointsBit = 4;
    const size_t kTimeseriesBit = 5;
    const size_t kCollationBit = 6;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kShardKeyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kShardKeyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kShardKeyBit);

                const BSONObj localObject = element.Obj();
                _shardKey = BSONObj::getOwned(localObject);
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
                        const BSONObj localObject = arrayElement.Obj();
                        values.emplace_back(BSONObj::getOwned(localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _initialSplitPoints = std::move(values);
        }
        else if (fieldName == kTimeseriesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kTimeseriesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTimeseriesBit);

                IDLParserErrorContext tempContext(kTimeseriesFieldName, &ctxt);
                const auto localObject = element.Obj();
                _timeseries = mongo::TimeseriesOptions::parse(tempContext, localObject);
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
        else {
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
    }

}


void CreateCollectionRequest::serialize(BSONObjBuilder* builder) const {
    if (_shardKey.is_initialized()) {
        builder->append(kShardKeyFieldName, _shardKey.get());
    }

    if (_unique.is_initialized()) {
        builder->append(kUniqueFieldName, _unique.get());
    }

    if (_numInitialChunks.is_initialized()) {
        builder->append(kNumInitialChunksFieldName, _numInitialChunks.get());
    }

    if (_presplitHashedZones.is_initialized()) {
        builder->append(kPresplitHashedZonesFieldName, _presplitHashedZones.get());
    }

    if (_initialSplitPoints.is_initialized()) {
        builder->append(kInitialSplitPointsFieldName, _initialSplitPoints.get());
    }

    if (_timeseries.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kTimeseriesFieldName));
        _timeseries.get().serialize(&subObjBuilder);
    }

    if (_collation.is_initialized()) {
        builder->append(kCollationFieldName, _collation.get());
    }

}


BSONObj CreateCollectionRequest::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData CreateCollectionResponse::kCollectionUUIDFieldName;
constexpr StringData CreateCollectionResponse::kCollectionVersionFieldName;


CreateCollectionResponse::CreateCollectionResponse() : _collectionVersion(mongo::idl::preparsedValue<decltype(_collectionVersion)>()), _hasCollectionVersion(false) {
    // Used for initialization only
}
CreateCollectionResponse::CreateCollectionResponse(mongo::ChunkVersion collectionVersion) : _collectionVersion(std::move(collectionVersion)), _hasCollectionVersion(true) {
    // Used for initialization only
}


CreateCollectionResponse CreateCollectionResponse::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<CreateCollectionResponse>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void CreateCollectionResponse::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kCollectionUUIDBit = 0;
    const size_t kCollectionVersionBit = 1;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kCollectionUUIDFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kCollectionUUIDBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollectionUUIDBit);

                _collectionUUID = UUID(uassertStatusOK(UUID::parse(element)));
            }
        }
        else if (fieldName == kCollectionVersionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCollectionVersionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollectionVersionBit);

                _hasCollectionVersion = true;
                const BSONObj localObject = element.Obj();
                _collectionVersion = ChunkVersion::fromBSONThrowing(localObject);
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
        if (!usedFields[kCollectionVersionBit]) {
            ctxt.throwMissingField(kCollectionVersionFieldName);
        }
    }

}


void CreateCollectionResponse::serialize(BSONObjBuilder* builder) const {
    invariant(_hasCollectionVersion);

    if (_collectionUUID.is_initialized()) {
        ConstDataRange tempCDR = _collectionUUID.get().toCDR();
        builder->append(kCollectionUUIDFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    {
        const BSONObj localObject = _collectionVersion.toBSON();
        builder->append(kCollectionVersionFieldName, localObject);
    }

}


BSONObj CreateCollectionResponse::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData SetAllowMigrationsRequest::kAllowMigrationsFieldName;


SetAllowMigrationsRequest::SetAllowMigrationsRequest() : _allowMigrations(mongo::idl::preparsedValue<decltype(_allowMigrations)>()), _hasAllowMigrations(false) {
    // Used for initialization only
}
SetAllowMigrationsRequest::SetAllowMigrationsRequest(bool allowMigrations) : _allowMigrations(std::move(allowMigrations)), _hasAllowMigrations(true) {
    // Used for initialization only
}


SetAllowMigrationsRequest SetAllowMigrationsRequest::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<SetAllowMigrationsRequest>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void SetAllowMigrationsRequest::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kAllowMigrationsBit = 0;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kAllowMigrationsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kAllowMigrationsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAllowMigrationsBit);

                _hasAllowMigrations = true;
                _allowMigrations = element.boolean();
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
        if (!usedFields[kAllowMigrationsBit]) {
            ctxt.throwMissingField(kAllowMigrationsFieldName);
        }
    }

}


void SetAllowMigrationsRequest::serialize(BSONObjBuilder* builder) const {
    invariant(_hasAllowMigrations);

    builder->append(kAllowMigrationsFieldName, _allowMigrations);

}


BSONObj SetAllowMigrationsRequest::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData ShardsvrCreateCollection::kCreateCollectionRequestFieldName;
constexpr StringData ShardsvrCreateCollection::kCollationFieldName;
constexpr StringData ShardsvrCreateCollection::kDbNameFieldName;
constexpr StringData ShardsvrCreateCollection::kInitialSplitPointsFieldName;
constexpr StringData ShardsvrCreateCollection::kNumInitialChunksFieldName;
constexpr StringData ShardsvrCreateCollection::kPresplitHashedZonesFieldName;
constexpr StringData ShardsvrCreateCollection::kShardKeyFieldName;
constexpr StringData ShardsvrCreateCollection::kTimeseriesFieldName;
constexpr StringData ShardsvrCreateCollection::kUniqueFieldName;
constexpr StringData ShardsvrCreateCollection::kCommandName;

const std::vector<StringData> ShardsvrCreateCollection::_knownBSONFields {
    ShardsvrCreateCollection::kCreateCollectionRequestFieldName,
    ShardsvrCreateCollection::kCollationFieldName,
    ShardsvrCreateCollection::kInitialSplitPointsFieldName,
    ShardsvrCreateCollection::kNumInitialChunksFieldName,
    ShardsvrCreateCollection::kPresplitHashedZonesFieldName,
    ShardsvrCreateCollection::kShardKeyFieldName,
    ShardsvrCreateCollection::kTimeseriesFieldName,
    ShardsvrCreateCollection::kUniqueFieldName,
    ShardsvrCreateCollection::kCommandName,
};
const std::vector<StringData> ShardsvrCreateCollection::_knownOP_MSGFields {
    ShardsvrCreateCollection::kCreateCollectionRequestFieldName,
    ShardsvrCreateCollection::kCollationFieldName,
    ShardsvrCreateCollection::kDbNameFieldName,
    ShardsvrCreateCollection::kInitialSplitPointsFieldName,
    ShardsvrCreateCollection::kNumInitialChunksFieldName,
    ShardsvrCreateCollection::kPresplitHashedZonesFieldName,
    ShardsvrCreateCollection::kShardKeyFieldName,
    ShardsvrCreateCollection::kTimeseriesFieldName,
    ShardsvrCreateCollection::kUniqueFieldName,
    ShardsvrCreateCollection::kCommandName,
};

ShardsvrCreateCollection::ShardsvrCreateCollection(const NamespaceString nss) : _nss(std::move(nss)), _dbName(nss.db().toString()), _hasDbName(true) {
    // Used for initialization only
}


ShardsvrCreateCollection ShardsvrCreateCollection::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    NamespaceString localNS;
    ShardsvrCreateCollection object(localNS);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ShardsvrCreateCollection::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<9> usedFields;
    const size_t kShardKeyBit = 0;
    const size_t kUniqueBit = 1;
    const size_t kNumInitialChunksBit = 2;
    const size_t kPresplitHashedZonesBit = 3;
    const size_t kInitialSplitPointsBit = 4;
    const size_t kTimeseriesBit = 5;
    const size_t kCollationBit = 6;
    const size_t kDbNameBit = 7;
    std::set<StringData> usedFieldSet;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kShardKeyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kShardKeyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kShardKeyBit);

                const BSONObj localObject = element.Obj();
                _createCollectionRequest.setShardKey(boost::optional<mongo::BSONObj>(BSONObj::getOwned(localObject)));
            }
        }
        else if (fieldName == kUniqueFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kUniqueBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUniqueBit);

                _createCollectionRequest.setUnique(boost::optional<bool>(element.boolean()));
            }
        }
        else if (fieldName == kNumInitialChunksFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kNumInitialChunksBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNumInitialChunksBit);

                _createCollectionRequest.setNumInitialChunks(boost::optional<std::int64_t>(element.safeNumberLong()));
            }
        }
        else if (fieldName == kPresplitHashedZonesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kPresplitHashedZonesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPresplitHashedZonesBit);

                _createCollectionRequest.setPresplitHashedZones(boost::optional<bool>(element.boolean()));
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
                        const BSONObj localObject = arrayElement.Obj();
                        values.emplace_back(BSONObj::getOwned(localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _createCollectionRequest.setInitialSplitPoints(std::move(values));
        }
        else if (fieldName == kTimeseriesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kTimeseriesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTimeseriesBit);

                IDLParserErrorContext tempContext(kTimeseriesFieldName, &ctxt);
                const auto localObject = element.Obj();
                _createCollectionRequest.setTimeseries(boost::optional<mongo::TimeseriesOptions>(mongo::TimeseriesOptions::parse(tempContext, localObject)));
            }
        }
        else if (fieldName == kCollationFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCollationBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollationBit);

                const BSONObj localObject = element.Obj();
                _createCollectionRequest.setCollation(boost::optional<mongo::BSONObj>(BSONObj::getOwned(localObject)));
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
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

ShardsvrCreateCollection ShardsvrCreateCollection::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    NamespaceString localNS;
    ShardsvrCreateCollection object(localNS);
    object.parseProtected(ctxt, request);
    return object;
}
void ShardsvrCreateCollection::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<9> usedFields;
    const size_t kShardKeyBit = 0;
    const size_t kUniqueBit = 1;
    const size_t kNumInitialChunksBit = 2;
    const size_t kPresplitHashedZonesBit = 3;
    const size_t kInitialSplitPointsBit = 4;
    const size_t kTimeseriesBit = 5;
    const size_t kCollationBit = 6;
    const size_t kDbNameBit = 7;
    std::set<StringData> usedFieldSet;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kShardKeyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kShardKeyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kShardKeyBit);

                const BSONObj localObject = element.Obj();
                _createCollectionRequest.setShardKey(boost::optional<mongo::BSONObj>(BSONObj::getOwned(localObject)));
            }
        }
        else if (fieldName == kUniqueFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kUniqueBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUniqueBit);

                _createCollectionRequest.setUnique(boost::optional<bool>(element.boolean()));
            }
        }
        else if (fieldName == kNumInitialChunksFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kNumInitialChunksBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNumInitialChunksBit);

                _createCollectionRequest.setNumInitialChunks(boost::optional<std::int64_t>(element.safeNumberLong()));
            }
        }
        else if (fieldName == kPresplitHashedZonesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kPresplitHashedZonesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPresplitHashedZonesBit);

                _createCollectionRequest.setPresplitHashedZones(boost::optional<bool>(element.boolean()));
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
                        const BSONObj localObject = arrayElement.Obj();
                        values.emplace_back(BSONObj::getOwned(localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _createCollectionRequest.setInitialSplitPoints(std::move(values));
        }
        else if (fieldName == kTimeseriesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kTimeseriesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTimeseriesBit);

                IDLParserErrorContext tempContext(kTimeseriesFieldName, &ctxt);
                const auto localObject = element.Obj();
                _createCollectionRequest.setTimeseries(boost::optional<mongo::TimeseriesOptions>(mongo::TimeseriesOptions::parse(tempContext, localObject)));
            }
        }
        else if (fieldName == kCollationFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCollationBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollationBit);

                const BSONObj localObject = element.Obj();
                _createCollectionRequest.setCollation(boost::optional<mongo::BSONObj>(BSONObj::getOwned(localObject)));
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
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

void ShardsvrCreateCollection::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    invariant(!_nss.isEmpty());
    builder->append("_shardsvrCreateCollection"_sd, _nss.coll());

    {
        _createCollectionRequest.serialize(builder);
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest ShardsvrCreateCollection::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        invariant(!_nss.isEmpty());
        builder->append("_shardsvrCreateCollection"_sd, _nss.coll());

        {
            _createCollectionRequest.serialize(builder);
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj ShardsvrCreateCollection::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData ShardsvrCreateCollectionParticipant::kCollectionUUIDFieldName;
constexpr StringData ShardsvrCreateCollectionParticipant::kDbNameFieldName;
constexpr StringData ShardsvrCreateCollectionParticipant::kIdIndexFieldName;
constexpr StringData ShardsvrCreateCollectionParticipant::kIndexesFieldName;
constexpr StringData ShardsvrCreateCollectionParticipant::kOptionsFieldName;
constexpr StringData ShardsvrCreateCollectionParticipant::kCommandName;

const std::vector<StringData> ShardsvrCreateCollectionParticipant::_knownBSONFields {
    ShardsvrCreateCollectionParticipant::kCollectionUUIDFieldName,
    ShardsvrCreateCollectionParticipant::kIdIndexFieldName,
    ShardsvrCreateCollectionParticipant::kIndexesFieldName,
    ShardsvrCreateCollectionParticipant::kOptionsFieldName,
    ShardsvrCreateCollectionParticipant::kCommandName,
};
const std::vector<StringData> ShardsvrCreateCollectionParticipant::_knownOP_MSGFields {
    ShardsvrCreateCollectionParticipant::kCollectionUUIDFieldName,
    ShardsvrCreateCollectionParticipant::kDbNameFieldName,
    ShardsvrCreateCollectionParticipant::kIdIndexFieldName,
    ShardsvrCreateCollectionParticipant::kIndexesFieldName,
    ShardsvrCreateCollectionParticipant::kOptionsFieldName,
    ShardsvrCreateCollectionParticipant::kCommandName,
};

ShardsvrCreateCollectionParticipant::ShardsvrCreateCollectionParticipant(const NamespaceString nss) : _nss(std::move(nss)), _options(mongo::idl::preparsedValue<decltype(_options)>()), _idIndex(mongo::idl::preparsedValue<decltype(_idIndex)>()), _dbName(nss.db().toString()), _hasIndexes(false), _hasOptions(false), _hasIdIndex(false), _hasDbName(true) {
    // Used for initialization only
}
ShardsvrCreateCollectionParticipant::ShardsvrCreateCollectionParticipant(const NamespaceString nss, std::vector<mongo::BSONObj> indexes, mongo::BSONObj options, mongo::BSONObj idIndex) : _nss(std::move(nss)), _indexes(std::move(indexes)), _options(std::move(options)), _idIndex(std::move(idIndex)), _dbName(nss.db().toString()), _hasIndexes(true), _hasOptions(true), _hasIdIndex(true), _hasDbName(true) {
    // Used for initialization only
}


ShardsvrCreateCollectionParticipant ShardsvrCreateCollectionParticipant::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    NamespaceString localNS;
    ShardsvrCreateCollectionParticipant object(localNS);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ShardsvrCreateCollectionParticipant::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<5> usedFields;
    const size_t kIndexesBit = 0;
    const size_t kOptionsBit = 1;
    const size_t kCollectionUUIDBit = 2;
    const size_t kIdIndexBit = 3;
    const size_t kDbNameBit = 4;
    std::set<StringData> usedFieldSet;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kIndexesFieldName) {
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
        else if (fieldName == kCollectionUUIDFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kCollectionUUIDBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollectionUUIDBit);

                _collectionUUID = UUID(uassertStatusOK(UUID::parse(element)));
            }
        }
        else if (fieldName == kIdIndexFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kIdIndexBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIdIndexBit);

                _hasIdIndex = true;
                _idIndex = element.Obj();
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
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kIndexesBit]) {
            ctxt.throwMissingField(kIndexesFieldName);
        }
        if (!usedFields[kOptionsBit]) {
            ctxt.throwMissingField(kOptionsFieldName);
        }
        if (!usedFields[kIdIndexBit]) {
            ctxt.throwMissingField(kIdIndexFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

ShardsvrCreateCollectionParticipant ShardsvrCreateCollectionParticipant::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    NamespaceString localNS;
    ShardsvrCreateCollectionParticipant object(localNS);
    object.parseProtected(ctxt, request);
    return object;
}
void ShardsvrCreateCollectionParticipant::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<5> usedFields;
    const size_t kIndexesBit = 0;
    const size_t kOptionsBit = 1;
    const size_t kCollectionUUIDBit = 2;
    const size_t kIdIndexBit = 3;
    const size_t kDbNameBit = 4;
    std::set<StringData> usedFieldSet;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kIndexesFieldName) {
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
        else if (fieldName == kCollectionUUIDFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kCollectionUUIDBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollectionUUIDBit);

                _collectionUUID = UUID(uassertStatusOK(UUID::parse(element)));
            }
        }
        else if (fieldName == kIdIndexFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kIdIndexBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIdIndexBit);

                _hasIdIndex = true;
                _idIndex = element.Obj();
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
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kIndexesBit]) {
            ctxt.throwMissingField(kIndexesFieldName);
        }
        if (!usedFields[kOptionsBit]) {
            ctxt.throwMissingField(kOptionsFieldName);
        }
        if (!usedFields[kIdIndexBit]) {
            ctxt.throwMissingField(kIdIndexFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

void ShardsvrCreateCollectionParticipant::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasIndexes && _hasOptions && _hasIdIndex && _hasDbName);

    invariant(!_nss.isEmpty());
    builder->append("_shardsvrCreateCollectionParticipant"_sd, _nss.coll());

    {
        builder->append(kIndexesFieldName, _indexes);
    }

    builder->append(kOptionsFieldName, _options);

    if (_collectionUUID.is_initialized()) {
        ConstDataRange tempCDR = _collectionUUID.get().toCDR();
        builder->append(kCollectionUUIDFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    builder->append(kIdIndexFieldName, _idIndex);

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest ShardsvrCreateCollectionParticipant::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasIndexes && _hasOptions && _hasIdIndex && _hasDbName);

        invariant(!_nss.isEmpty());
        builder->append("_shardsvrCreateCollectionParticipant"_sd, _nss.coll());

        {
            builder->append(kIndexesFieldName, _indexes);
        }

        builder->append(kOptionsFieldName, _options);

        if (_collectionUUID.is_initialized()) {
            ConstDataRange tempCDR = _collectionUUID.get().toCDR();
            builder->append(kCollectionUUIDFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
        }

        builder->append(kIdIndexFieldName, _idIndex);

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj ShardsvrCreateCollectionParticipant::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData ShardsvrDropDatabase::kDbNameFieldName;
constexpr StringData ShardsvrDropDatabase::kCommandName;

const std::vector<StringData> ShardsvrDropDatabase::_knownBSONFields {
    ShardsvrDropDatabase::kCommandName,
};
const std::vector<StringData> ShardsvrDropDatabase::_knownOP_MSGFields {
    ShardsvrDropDatabase::kDbNameFieldName,
    ShardsvrDropDatabase::kCommandName,
};

ShardsvrDropDatabase::ShardsvrDropDatabase() : _hasDbName(false) {
    // Used for initialization only
}


ShardsvrDropDatabase ShardsvrDropDatabase::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ShardsvrDropDatabase>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ShardsvrDropDatabase::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kDbNameBit = 0;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kDbNameFieldName) {
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

}

ShardsvrDropDatabase ShardsvrDropDatabase::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto object = mongo::idl::preparsedValue<ShardsvrDropDatabase>();
    object.parseProtected(ctxt, request);
    return object;
}
void ShardsvrDropDatabase::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<1> usedFields;
    const size_t kDbNameBit = 0;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kDbNameFieldName) {
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

}

void ShardsvrDropDatabase::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    builder->append("_shardsvrDropDatabase"_sd, 1);
    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest ShardsvrDropDatabase::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        builder->append("_shardsvrDropDatabase"_sd, 1);
        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj ShardsvrDropDatabase::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData ShardsvrDropDatabaseParticipant::kDbNameFieldName;
constexpr StringData ShardsvrDropDatabaseParticipant::kCommandName;

const std::vector<StringData> ShardsvrDropDatabaseParticipant::_knownBSONFields {
    ShardsvrDropDatabaseParticipant::kCommandName,
};
const std::vector<StringData> ShardsvrDropDatabaseParticipant::_knownOP_MSGFields {
    ShardsvrDropDatabaseParticipant::kDbNameFieldName,
    ShardsvrDropDatabaseParticipant::kCommandName,
};

ShardsvrDropDatabaseParticipant::ShardsvrDropDatabaseParticipant() : _hasDbName(false) {
    // Used for initialization only
}


ShardsvrDropDatabaseParticipant ShardsvrDropDatabaseParticipant::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ShardsvrDropDatabaseParticipant>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ShardsvrDropDatabaseParticipant::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kDbNameBit = 0;
    std::set<StringData> usedFieldSet;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kDbNameFieldName) {
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
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

}

ShardsvrDropDatabaseParticipant ShardsvrDropDatabaseParticipant::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto object = mongo::idl::preparsedValue<ShardsvrDropDatabaseParticipant>();
    object.parseProtected(ctxt, request);
    return object;
}
void ShardsvrDropDatabaseParticipant::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<1> usedFields;
    const size_t kDbNameBit = 0;
    std::set<StringData> usedFieldSet;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kDbNameFieldName) {
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
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

}

void ShardsvrDropDatabaseParticipant::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    builder->append("_shardsvrDropDatabaseParticipant"_sd, 1);
    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest ShardsvrDropDatabaseParticipant::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        builder->append("_shardsvrDropDatabaseParticipant"_sd, 1);
        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj ShardsvrDropDatabaseParticipant::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData ShardsvrDropCollection::kDbNameFieldName;
constexpr StringData ShardsvrDropCollection::kCommandName;

const std::vector<StringData> ShardsvrDropCollection::_knownBSONFields {
    ShardsvrDropCollection::kCommandName,
};
const std::vector<StringData> ShardsvrDropCollection::_knownOP_MSGFields {
    ShardsvrDropCollection::kDbNameFieldName,
    ShardsvrDropCollection::kCommandName,
};

ShardsvrDropCollection::ShardsvrDropCollection(const NamespaceString nss) : _nss(std::move(nss)), _dbName(nss.db().toString()), _hasDbName(true) {
    // Used for initialization only
}


ShardsvrDropCollection ShardsvrDropCollection::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    NamespaceString localNS;
    ShardsvrDropCollection object(localNS);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ShardsvrDropCollection::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kDbNameBit = 0;
    std::set<StringData> usedFieldSet;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kDbNameFieldName) {
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
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

ShardsvrDropCollection ShardsvrDropCollection::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    NamespaceString localNS;
    ShardsvrDropCollection object(localNS);
    object.parseProtected(ctxt, request);
    return object;
}
void ShardsvrDropCollection::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<1> usedFields;
    const size_t kDbNameBit = 0;
    std::set<StringData> usedFieldSet;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kDbNameFieldName) {
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
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

void ShardsvrDropCollection::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    invariant(!_nss.isEmpty());
    builder->append("_shardsvrDropCollection"_sd, _nss.coll());

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest ShardsvrDropCollection::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        invariant(!_nss.isEmpty());
        builder->append("_shardsvrDropCollection"_sd, _nss.coll());

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj ShardsvrDropCollection::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData ShardsvrDropCollectionParticipant::kDbNameFieldName;
constexpr StringData ShardsvrDropCollectionParticipant::kCommandName;

const std::vector<StringData> ShardsvrDropCollectionParticipant::_knownBSONFields {
    ShardsvrDropCollectionParticipant::kCommandName,
};
const std::vector<StringData> ShardsvrDropCollectionParticipant::_knownOP_MSGFields {
    ShardsvrDropCollectionParticipant::kDbNameFieldName,
    ShardsvrDropCollectionParticipant::kCommandName,
};

ShardsvrDropCollectionParticipant::ShardsvrDropCollectionParticipant(const NamespaceString nss) : _nss(std::move(nss)), _dbName(nss.db().toString()), _hasDbName(true) {
    // Used for initialization only
}


ShardsvrDropCollectionParticipant ShardsvrDropCollectionParticipant::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    NamespaceString localNS;
    ShardsvrDropCollectionParticipant object(localNS);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ShardsvrDropCollectionParticipant::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kDbNameBit = 0;
    std::set<StringData> usedFieldSet;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kDbNameFieldName) {
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
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

ShardsvrDropCollectionParticipant ShardsvrDropCollectionParticipant::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    NamespaceString localNS;
    ShardsvrDropCollectionParticipant object(localNS);
    object.parseProtected(ctxt, request);
    return object;
}
void ShardsvrDropCollectionParticipant::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<1> usedFields;
    const size_t kDbNameBit = 0;
    std::set<StringData> usedFieldSet;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kDbNameFieldName) {
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
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

void ShardsvrDropCollectionParticipant::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    invariant(!_nss.isEmpty());
    builder->append("_shardsvrDropCollectionParticipant"_sd, _nss.coll());

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest ShardsvrDropCollectionParticipant::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        invariant(!_nss.isEmpty());
        builder->append("_shardsvrDropCollectionParticipant"_sd, _nss.coll());

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj ShardsvrDropCollectionParticipant::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData ShardsvrRenameCollection::kRenameCollectionRequestFieldName;
constexpr StringData ShardsvrRenameCollection::kDbNameFieldName;
constexpr StringData ShardsvrRenameCollection::kDropTargetFieldName;
constexpr StringData ShardsvrRenameCollection::kStayTempFieldName;
constexpr StringData ShardsvrRenameCollection::kToFieldName;
constexpr StringData ShardsvrRenameCollection::kCommandName;

const std::vector<StringData> ShardsvrRenameCollection::_knownBSONFields {
    ShardsvrRenameCollection::kRenameCollectionRequestFieldName,
    ShardsvrRenameCollection::kDropTargetFieldName,
    ShardsvrRenameCollection::kStayTempFieldName,
    ShardsvrRenameCollection::kToFieldName,
    ShardsvrRenameCollection::kCommandName,
};
const std::vector<StringData> ShardsvrRenameCollection::_knownOP_MSGFields {
    ShardsvrRenameCollection::kRenameCollectionRequestFieldName,
    ShardsvrRenameCollection::kDbNameFieldName,
    ShardsvrRenameCollection::kDropTargetFieldName,
    ShardsvrRenameCollection::kStayTempFieldName,
    ShardsvrRenameCollection::kToFieldName,
    ShardsvrRenameCollection::kCommandName,
};

ShardsvrRenameCollection::ShardsvrRenameCollection(const NamespaceString nss) : _nss(std::move(nss)), _dbName(nss.db().toString()), _hasDbName(true) {
    // Used for initialization only
}


ShardsvrRenameCollection ShardsvrRenameCollection::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    NamespaceString localNS;
    ShardsvrRenameCollection object(localNS);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ShardsvrRenameCollection::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<5> usedFields;
    const size_t kToBit = 0;
    const size_t kDropTargetBit = 1;
    const size_t kStayTempBit = 2;
    const size_t kDbNameBit = 3;
    std::set<StringData> usedFieldSet;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kToFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kToBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kToBit);

                _renameCollectionRequest.setTo(NamespaceString(element.valueStringData()));
            }
        }
        else if (fieldName == kDropTargetFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kDropTargetBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDropTargetBit);

                _renameCollectionRequest.setDropTarget(element.boolean());
            }
        }
        else if (fieldName == kStayTempFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kStayTempBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStayTempBit);

                _renameCollectionRequest.setStayTemp(element.boolean());
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
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kToBit]) {
            ctxt.throwMissingField(kToFieldName);
        }
        if (!usedFields[kDropTargetBit]) {
            _renameCollectionRequest.setDropTarget(false);
        }
        if (!usedFields[kStayTempBit]) {
            _renameCollectionRequest.setStayTemp(false);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

ShardsvrRenameCollection ShardsvrRenameCollection::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    NamespaceString localNS;
    ShardsvrRenameCollection object(localNS);
    object.parseProtected(ctxt, request);
    return object;
}
void ShardsvrRenameCollection::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<5> usedFields;
    const size_t kToBit = 0;
    const size_t kDropTargetBit = 1;
    const size_t kStayTempBit = 2;
    const size_t kDbNameBit = 3;
    std::set<StringData> usedFieldSet;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kToFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kToBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kToBit);

                _renameCollectionRequest.setTo(NamespaceString(element.valueStringData()));
            }
        }
        else if (fieldName == kDropTargetFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kDropTargetBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDropTargetBit);

                _renameCollectionRequest.setDropTarget(element.boolean());
            }
        }
        else if (fieldName == kStayTempFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kStayTempBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStayTempBit);

                _renameCollectionRequest.setStayTemp(element.boolean());
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
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kToBit]) {
            ctxt.throwMissingField(kToFieldName);
        }
        if (!usedFields[kDropTargetBit]) {
            _renameCollectionRequest.setDropTarget(false);
        }
        if (!usedFields[kStayTempBit]) {
            _renameCollectionRequest.setStayTemp(false);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

void ShardsvrRenameCollection::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    invariant(!_nss.isEmpty());
    builder->append("_shardsvrRenameCollection"_sd, _nss.coll());

    {
        _renameCollectionRequest.serialize(builder);
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest ShardsvrRenameCollection::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        invariant(!_nss.isEmpty());
        builder->append("_shardsvrRenameCollection"_sd, _nss.coll());

        {
            _renameCollectionRequest.serialize(builder);
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj ShardsvrRenameCollection::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData ShardsvrSetAllowMigrations::kSetAllowMigrationsRequestFieldName;
constexpr StringData ShardsvrSetAllowMigrations::kAllowMigrationsFieldName;
constexpr StringData ShardsvrSetAllowMigrations::kDbNameFieldName;
constexpr StringData ShardsvrSetAllowMigrations::kCommandName;

const std::vector<StringData> ShardsvrSetAllowMigrations::_knownBSONFields {
    ShardsvrSetAllowMigrations::kSetAllowMigrationsRequestFieldName,
    ShardsvrSetAllowMigrations::kAllowMigrationsFieldName,
    ShardsvrSetAllowMigrations::kCommandName,
};
const std::vector<StringData> ShardsvrSetAllowMigrations::_knownOP_MSGFields {
    ShardsvrSetAllowMigrations::kSetAllowMigrationsRequestFieldName,
    ShardsvrSetAllowMigrations::kAllowMigrationsFieldName,
    ShardsvrSetAllowMigrations::kDbNameFieldName,
    ShardsvrSetAllowMigrations::kCommandName,
};

ShardsvrSetAllowMigrations::ShardsvrSetAllowMigrations(const NamespaceString nss) : _nss(std::move(nss)), _dbName(nss.db().toString()), _hasDbName(true) {
    // Used for initialization only
}


ShardsvrSetAllowMigrations ShardsvrSetAllowMigrations::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    NamespaceString localNS;
    ShardsvrSetAllowMigrations object(localNS);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ShardsvrSetAllowMigrations::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<3> usedFields;
    const size_t kAllowMigrationsBit = 0;
    const size_t kDbNameBit = 1;
    std::set<StringData> usedFieldSet;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kAllowMigrationsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kAllowMigrationsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAllowMigrationsBit);

                _setAllowMigrationsRequest.setAllowMigrations(element.boolean());
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
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kAllowMigrationsBit]) {
            ctxt.throwMissingField(kAllowMigrationsFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

ShardsvrSetAllowMigrations ShardsvrSetAllowMigrations::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    NamespaceString localNS;
    ShardsvrSetAllowMigrations object(localNS);
    object.parseProtected(ctxt, request);
    return object;
}
void ShardsvrSetAllowMigrations::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<3> usedFields;
    const size_t kAllowMigrationsBit = 0;
    const size_t kDbNameBit = 1;
    std::set<StringData> usedFieldSet;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kAllowMigrationsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kAllowMigrationsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAllowMigrationsBit);

                _setAllowMigrationsRequest.setAllowMigrations(element.boolean());
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
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kAllowMigrationsBit]) {
            ctxt.throwMissingField(kAllowMigrationsFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

void ShardsvrSetAllowMigrations::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    invariant(!_nss.isEmpty());
    builder->append("_shardsvrSetAllowMigrations"_sd, _nss.coll());

    {
        _setAllowMigrationsRequest.serialize(builder);
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest ShardsvrSetAllowMigrations::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        invariant(!_nss.isEmpty());
        builder->append("_shardsvrSetAllowMigrations"_sd, _nss.coll());

        {
            _setAllowMigrationsRequest.serialize(builder);
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj ShardsvrSetAllowMigrations::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData ConfigsvrRenameCollectionMetadata::kDbNameFieldName;
constexpr StringData ConfigsvrRenameCollectionMetadata::kOptFromCollectionFieldName;
constexpr StringData ConfigsvrRenameCollectionMetadata::kToFieldName;
constexpr StringData ConfigsvrRenameCollectionMetadata::kCommandName;

const std::vector<StringData> ConfigsvrRenameCollectionMetadata::_knownBSONFields {
    ConfigsvrRenameCollectionMetadata::kOptFromCollectionFieldName,
    ConfigsvrRenameCollectionMetadata::kToFieldName,
    ConfigsvrRenameCollectionMetadata::kCommandName,
};
const std::vector<StringData> ConfigsvrRenameCollectionMetadata::_knownOP_MSGFields {
    ConfigsvrRenameCollectionMetadata::kDbNameFieldName,
    ConfigsvrRenameCollectionMetadata::kOptFromCollectionFieldName,
    ConfigsvrRenameCollectionMetadata::kToFieldName,
    ConfigsvrRenameCollectionMetadata::kCommandName,
};

ConfigsvrRenameCollectionMetadata::ConfigsvrRenameCollectionMetadata(const NamespaceString nss) : _nss(std::move(nss)), _to(mongo::idl::preparsedValue<decltype(_to)>()), _dbName(nss.db().toString()), _hasTo(false), _hasDbName(true) {
    // Used for initialization only
}
ConfigsvrRenameCollectionMetadata::ConfigsvrRenameCollectionMetadata(const NamespaceString nss, mongo::NamespaceString to) : _nss(std::move(nss)), _to(std::move(to)), _dbName(nss.db().toString()), _hasTo(true), _hasDbName(true) {
    // Used for initialization only
}


ConfigsvrRenameCollectionMetadata ConfigsvrRenameCollectionMetadata::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    NamespaceString localNS;
    ConfigsvrRenameCollectionMetadata object(localNS);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ConfigsvrRenameCollectionMetadata::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<3> usedFields;
    const size_t kToBit = 0;
    const size_t kOptFromCollectionBit = 1;
    const size_t kDbNameBit = 2;
    std::set<StringData> usedFieldSet;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kToFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kToBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kToBit);

                _hasTo = true;
                _to = NamespaceString(element.valueStringData());
            }
        }
        else if (fieldName == kOptFromCollectionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kOptFromCollectionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kOptFromCollectionBit);

                const BSONObj localObject = element.Obj();
                _optFromCollection = CollectionType(localObject);
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
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kToBit]) {
            ctxt.throwMissingField(kToFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

ConfigsvrRenameCollectionMetadata ConfigsvrRenameCollectionMetadata::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    NamespaceString localNS;
    ConfigsvrRenameCollectionMetadata object(localNS);
    object.parseProtected(ctxt, request);
    return object;
}
void ConfigsvrRenameCollectionMetadata::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<3> usedFields;
    const size_t kToBit = 0;
    const size_t kOptFromCollectionBit = 1;
    const size_t kDbNameBit = 2;
    std::set<StringData> usedFieldSet;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kToFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kToBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kToBit);

                _hasTo = true;
                _to = NamespaceString(element.valueStringData());
            }
        }
        else if (fieldName == kOptFromCollectionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kOptFromCollectionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kOptFromCollectionBit);

                const BSONObj localObject = element.Obj();
                _optFromCollection = CollectionType(localObject);
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
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kToBit]) {
            ctxt.throwMissingField(kToFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

void ConfigsvrRenameCollectionMetadata::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasTo && _hasDbName);

    invariant(!_nss.isEmpty());
    builder->append("_configsvrRenameCollectionMetadata"_sd, _nss.coll());

    {
        builder->append(kToFieldName, _to.toString());
    }

    if (_optFromCollection.is_initialized()) {
        const BSONObj localObject = _optFromCollection.get().toBSON();
        builder->append(kOptFromCollectionFieldName, localObject);
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest ConfigsvrRenameCollectionMetadata::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasTo && _hasDbName);

        invariant(!_nss.isEmpty());
        builder->append("_configsvrRenameCollectionMetadata"_sd, _nss.coll());

        {
            builder->append(kToFieldName, _to.toString());
        }

        if (_optFromCollection.is_initialized()) {
            const BSONObj localObject = _optFromCollection.get().toBSON();
            builder->append(kOptFromCollectionFieldName, localObject);
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj ConfigsvrRenameCollectionMetadata::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData ShardsvrReshardCollection::kCommandParameterFieldName;
constexpr StringData ShardsvrReshardCollection::k_presetReshardedChunksFieldName;
constexpr StringData ShardsvrReshardCollection::kCollationFieldName;
constexpr StringData ShardsvrReshardCollection::kDbNameFieldName;
constexpr StringData ShardsvrReshardCollection::kKeyFieldName;
constexpr StringData ShardsvrReshardCollection::kNumInitialChunksFieldName;
constexpr StringData ShardsvrReshardCollection::kUniqueFieldName;
constexpr StringData ShardsvrReshardCollection::kZonesFieldName;
constexpr StringData ShardsvrReshardCollection::kCommandName;

const std::vector<StringData> ShardsvrReshardCollection::_knownBSONFields {
    ShardsvrReshardCollection::k_presetReshardedChunksFieldName,
    ShardsvrReshardCollection::kCollationFieldName,
    ShardsvrReshardCollection::kKeyFieldName,
    ShardsvrReshardCollection::kNumInitialChunksFieldName,
    ShardsvrReshardCollection::kUniqueFieldName,
    ShardsvrReshardCollection::kZonesFieldName,
    ShardsvrReshardCollection::kCommandName,
};
const std::vector<StringData> ShardsvrReshardCollection::_knownOP_MSGFields {
    ShardsvrReshardCollection::k_presetReshardedChunksFieldName,
    ShardsvrReshardCollection::kCollationFieldName,
    ShardsvrReshardCollection::kDbNameFieldName,
    ShardsvrReshardCollection::kKeyFieldName,
    ShardsvrReshardCollection::kNumInitialChunksFieldName,
    ShardsvrReshardCollection::kUniqueFieldName,
    ShardsvrReshardCollection::kZonesFieldName,
    ShardsvrReshardCollection::kCommandName,
};

ShardsvrReshardCollection::ShardsvrReshardCollection(const mongo::NamespaceString commandParameter) : _commandParameter(std::move(commandParameter)), _key(mongo::idl::preparsedValue<decltype(_key)>()), _hasKey(false), _hasDbName(false) {
    // Used for initialization only
}
ShardsvrReshardCollection::ShardsvrReshardCollection(const mongo::NamespaceString commandParameter, mongo::BSONObj key) : _commandParameter(std::move(commandParameter)), _key(std::move(key)), _hasKey(true), _hasDbName(true) {
    // Used for initialization only
}


ShardsvrReshardCollection ShardsvrReshardCollection::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto localCmdType = mongo::idl::preparsedValue<mongo::NamespaceString>();
    ShardsvrReshardCollection object(localCmdType);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ShardsvrReshardCollection::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<7> usedFields;
    const size_t kKeyBit = 0;
    const size_t kUniqueBit = 1;
    const size_t kNumInitialChunksBit = 2;
    const size_t kCollationBit = 3;
    const size_t kZonesBit = 4;
    const size_t k_presetReshardedChunksBit = 5;
    const size_t kDbNameBit = 6;
    std::set<StringData> usedFieldSet;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kKeyFieldName) {
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
        else if (fieldName == kCollationFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCollationBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollationBit);

                _collation = element.Obj();
            }
        }
        else if (fieldName == kZonesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kZonesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kZonesBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kZonesFieldName, &ctxt);
            std::vector<mongo::ReshardingZoneType> values;

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
                        IDLParserErrorContext tempContext(kZonesFieldName, &ctxt);
                        const auto localObject = arrayElement.Obj();
                        values.emplace_back(mongo::ReshardingZoneType::parse(tempContext, localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _zones = std::move(values);
        }
        else if (fieldName == k_presetReshardedChunksFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[k_presetReshardedChunksBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(k_presetReshardedChunksBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(k_presetReshardedChunksFieldName, &ctxt);
            std::vector<mongo::ReshardedChunk> values;

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
                        IDLParserErrorContext tempContext(k_presetReshardedChunksFieldName, &ctxt);
                        const auto localObject = arrayElement.Obj();
                        values.emplace_back(mongo::ReshardedChunk::parse(tempContext, localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            __presetReshardedChunks = std::move(values);
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
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    {
        if (MONGO_likely(ctxt.checkAndAssertType(commandElement, String))) {
            _commandParameter = NamespaceString(commandElement.valueStringData());
        }
        else {
            ctxt.throwMissingField(kCommandParameterFieldName);
        }
    }
}

ShardsvrReshardCollection ShardsvrReshardCollection::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto localCmdType = mongo::idl::preparsedValue<mongo::NamespaceString>();
    ShardsvrReshardCollection object(localCmdType);
    object.parseProtected(ctxt, request);
    return object;
}
void ShardsvrReshardCollection::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<7> usedFields;
    const size_t kKeyBit = 0;
    const size_t kUniqueBit = 1;
    const size_t kNumInitialChunksBit = 2;
    const size_t kCollationBit = 3;
    const size_t kZonesBit = 4;
    const size_t k_presetReshardedChunksBit = 5;
    const size_t kDbNameBit = 6;
    std::set<StringData> usedFieldSet;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kKeyFieldName) {
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
        else if (fieldName == kCollationFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCollationBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollationBit);

                _collation = element.Obj();
            }
        }
        else if (fieldName == kZonesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kZonesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kZonesBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kZonesFieldName, &ctxt);
            std::vector<mongo::ReshardingZoneType> values;

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
                        IDLParserErrorContext tempContext(kZonesFieldName, &ctxt);
                        const auto localObject = arrayElement.Obj();
                        values.emplace_back(mongo::ReshardingZoneType::parse(tempContext, localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _zones = std::move(values);
        }
        else if (fieldName == k_presetReshardedChunksFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[k_presetReshardedChunksBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(k_presetReshardedChunksBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(k_presetReshardedChunksFieldName, &ctxt);
            std::vector<mongo::ReshardedChunk> values;

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
                        IDLParserErrorContext tempContext(k_presetReshardedChunksFieldName, &ctxt);
                        const auto localObject = arrayElement.Obj();
                        values.emplace_back(mongo::ReshardedChunk::parse(tempContext, localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            __presetReshardedChunks = std::move(values);
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
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    {
        if (MONGO_likely(ctxt.checkAndAssertType(commandElement, String))) {
            _commandParameter = NamespaceString(commandElement.valueStringData());
        }
        else {
            ctxt.throwMissingField(kCommandParameterFieldName);
        }
    }
}

void ShardsvrReshardCollection::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasKey && _hasDbName);

    {
        builder->append(kCommandParameterFieldName, _commandParameter.toString());
    }
    builder->append(kKeyFieldName, _key);

    if (_unique.is_initialized()) {
        builder->append(kUniqueFieldName, _unique.get());
    }

    if (_numInitialChunks.is_initialized()) {
        builder->append(kNumInitialChunksFieldName, _numInitialChunks.get());
    }

    if (_collation.is_initialized()) {
        builder->append(kCollationFieldName, _collation.get());
    }

    if (_zones.is_initialized()) {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kZonesFieldName));
        for (const auto& item : _zones.get()) {
            BSONObjBuilder subObjBuilder(arrayBuilder.subobjStart());
            item.serialize(&subObjBuilder);
        }
    }

    if (__presetReshardedChunks.is_initialized()) {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(k_presetReshardedChunksFieldName));
        for (const auto& item : __presetReshardedChunks.get()) {
            BSONObjBuilder subObjBuilder(arrayBuilder.subobjStart());
            item.serialize(&subObjBuilder);
        }
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest ShardsvrReshardCollection::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasKey && _hasDbName);

        {
            builder->append(kCommandParameterFieldName, _commandParameter.toString());
        }
        builder->append(kKeyFieldName, _key);

        if (_unique.is_initialized()) {
            builder->append(kUniqueFieldName, _unique.get());
        }

        if (_numInitialChunks.is_initialized()) {
            builder->append(kNumInitialChunksFieldName, _numInitialChunks.get());
        }

        if (_collation.is_initialized()) {
            builder->append(kCollationFieldName, _collation.get());
        }

        if (_zones.is_initialized()) {
            BSONArrayBuilder arrayBuilder(builder->subarrayStart(kZonesFieldName));
            for (const auto& item : _zones.get()) {
                BSONObjBuilder subObjBuilder(arrayBuilder.subobjStart());
                item.serialize(&subObjBuilder);
            }
        }

        if (__presetReshardedChunks.is_initialized()) {
            BSONArrayBuilder arrayBuilder(builder->subarrayStart(k_presetReshardedChunksFieldName));
            for (const auto& item : __presetReshardedChunks.get()) {
                BSONObjBuilder subObjBuilder(arrayBuilder.subobjStart());
                item.serialize(&subObjBuilder);
            }
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj ShardsvrReshardCollection::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData ShardsvrRefineCollectionShardKey::kDbNameFieldName;
constexpr StringData ShardsvrRefineCollectionShardKey::kNewShardKeyFieldName;
constexpr StringData ShardsvrRefineCollectionShardKey::kCommandName;

const std::vector<StringData> ShardsvrRefineCollectionShardKey::_knownBSONFields {
    ShardsvrRefineCollectionShardKey::kNewShardKeyFieldName,
    ShardsvrRefineCollectionShardKey::kCommandName,
};
const std::vector<StringData> ShardsvrRefineCollectionShardKey::_knownOP_MSGFields {
    ShardsvrRefineCollectionShardKey::kDbNameFieldName,
    ShardsvrRefineCollectionShardKey::kNewShardKeyFieldName,
    ShardsvrRefineCollectionShardKey::kCommandName,
};

ShardsvrRefineCollectionShardKey::ShardsvrRefineCollectionShardKey(const NamespaceString nss) : _nss(std::move(nss)), _newShardKey(mongo::idl::preparsedValue<decltype(_newShardKey)>()), _dbName(nss.db().toString()), _hasNewShardKey(false), _hasDbName(true) {
    // Used for initialization only
}
ShardsvrRefineCollectionShardKey::ShardsvrRefineCollectionShardKey(const NamespaceString nss, mongo::KeyPattern newShardKey) : _nss(std::move(nss)), _newShardKey(std::move(newShardKey)), _dbName(nss.db().toString()), _hasNewShardKey(true), _hasDbName(true) {
    // Used for initialization only
}


ShardsvrRefineCollectionShardKey ShardsvrRefineCollectionShardKey::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    NamespaceString localNS;
    ShardsvrRefineCollectionShardKey object(localNS);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ShardsvrRefineCollectionShardKey::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kNewShardKeyBit = 0;
    const size_t kDbNameBit = 1;
    std::set<StringData> usedFieldSet;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kNewShardKeyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kNewShardKeyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNewShardKeyBit);

                _hasNewShardKey = true;
                const BSONObj localObject = element.Obj();
                _newShardKey = KeyPattern::fromBSON(localObject);
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
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kNewShardKeyBit]) {
            ctxt.throwMissingField(kNewShardKeyFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

ShardsvrRefineCollectionShardKey ShardsvrRefineCollectionShardKey::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    NamespaceString localNS;
    ShardsvrRefineCollectionShardKey object(localNS);
    object.parseProtected(ctxt, request);
    return object;
}
void ShardsvrRefineCollectionShardKey::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<2> usedFields;
    const size_t kNewShardKeyBit = 0;
    const size_t kDbNameBit = 1;
    std::set<StringData> usedFieldSet;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kNewShardKeyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kNewShardKeyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNewShardKeyBit);

                _hasNewShardKey = true;
                const BSONObj localObject = element.Obj();
                _newShardKey = KeyPattern::fromBSON(localObject);
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
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kNewShardKeyBit]) {
            ctxt.throwMissingField(kNewShardKeyFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

void ShardsvrRefineCollectionShardKey::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasNewShardKey && _hasDbName);

    invariant(!_nss.isEmpty());
    builder->append("_shardsvrRefineCollectionShardKey"_sd, _nss.coll());

    {
        const BSONObj localObject = _newShardKey.toBSON();
        builder->append(kNewShardKeyFieldName, localObject);
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest ShardsvrRefineCollectionShardKey::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasNewShardKey && _hasDbName);

        invariant(!_nss.isEmpty());
        builder->append("_shardsvrRefineCollectionShardKey"_sd, _nss.coll());

        {
            const BSONObj localObject = _newShardKey.toBSON();
            builder->append(kNewShardKeyFieldName, localObject);
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj ShardsvrRefineCollectionShardKey::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData ConfigsvrCreateDatabase::kCommandParameterFieldName;
constexpr StringData ConfigsvrCreateDatabase::kDbNameFieldName;
constexpr StringData ConfigsvrCreateDatabase::kEnableShardingFieldName;
constexpr StringData ConfigsvrCreateDatabase::kPrimaryShardIdFieldName;
constexpr StringData ConfigsvrCreateDatabase::kCommandName;

const std::vector<StringData> ConfigsvrCreateDatabase::_knownBSONFields {
    ConfigsvrCreateDatabase::kEnableShardingFieldName,
    ConfigsvrCreateDatabase::kPrimaryShardIdFieldName,
    ConfigsvrCreateDatabase::kCommandName,
};
const std::vector<StringData> ConfigsvrCreateDatabase::_knownOP_MSGFields {
    ConfigsvrCreateDatabase::kDbNameFieldName,
    ConfigsvrCreateDatabase::kEnableShardingFieldName,
    ConfigsvrCreateDatabase::kPrimaryShardIdFieldName,
    ConfigsvrCreateDatabase::kCommandName,
};

ConfigsvrCreateDatabase::ConfigsvrCreateDatabase(const std::string commandParameter) : _commandParameter(std::move(commandParameter)), _hasDbName(false) {
    // Used for initialization only
}


ConfigsvrCreateDatabase ConfigsvrCreateDatabase::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto localCmdType = mongo::idl::preparsedValue<std::string>();
    ConfigsvrCreateDatabase object(localCmdType);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ConfigsvrCreateDatabase::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<3> usedFields;
    const size_t kPrimaryShardIdBit = 0;
    const size_t kEnableShardingBit = 1;
    const size_t kDbNameBit = 2;
    std::set<StringData> usedFieldSet;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kPrimaryShardIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kPrimaryShardIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPrimaryShardIdBit);

                _primaryShardId = element.str();
            }
        }
        else if (fieldName == kEnableShardingFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kEnableShardingBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kEnableShardingBit);

                _enableSharding = element.boolean();
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
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    {
        if (MONGO_likely(ctxt.checkAndAssertType(commandElement, String))) {
            _commandParameter = commandElement.str();
        }
        else {
            ctxt.throwMissingField(kCommandParameterFieldName);
        }
    }
}

ConfigsvrCreateDatabase ConfigsvrCreateDatabase::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto localCmdType = mongo::idl::preparsedValue<std::string>();
    ConfigsvrCreateDatabase object(localCmdType);
    object.parseProtected(ctxt, request);
    return object;
}
void ConfigsvrCreateDatabase::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<3> usedFields;
    const size_t kPrimaryShardIdBit = 0;
    const size_t kEnableShardingBit = 1;
    const size_t kDbNameBit = 2;
    std::set<StringData> usedFieldSet;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kPrimaryShardIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kPrimaryShardIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPrimaryShardIdBit);

                _primaryShardId = element.str();
            }
        }
        else if (fieldName == kEnableShardingFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kEnableShardingBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kEnableShardingBit);

                _enableSharding = element.boolean();
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
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    {
        if (MONGO_likely(ctxt.checkAndAssertType(commandElement, String))) {
            _commandParameter = commandElement.str();
        }
        else {
            ctxt.throwMissingField(kCommandParameterFieldName);
        }
    }
}

void ConfigsvrCreateDatabase::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    builder->append(kCommandParameterFieldName, _commandParameter);
    if (_primaryShardId.is_initialized()) {
        builder->append(kPrimaryShardIdFieldName, _primaryShardId.get());
    }

    if (_enableSharding.is_initialized()) {
        builder->append(kEnableShardingFieldName, _enableSharding.get());
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest ConfigsvrCreateDatabase::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        builder->append(kCommandParameterFieldName, _commandParameter);
        if (_primaryShardId.is_initialized()) {
            builder->append(kPrimaryShardIdFieldName, _primaryShardId.get());
        }

        if (_enableSharding.is_initialized()) {
            builder->append(kEnableShardingFieldName, _enableSharding.get());
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj ConfigsvrCreateDatabase::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
