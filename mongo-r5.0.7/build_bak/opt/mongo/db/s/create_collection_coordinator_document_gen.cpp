/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/s/create_collection_coordinator_document_gen.h --output build/opt/mongo/db/s/create_collection_coordinator_document_gen.cpp src/mongo/db/s/create_collection_coordinator_document.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/s/create_collection_coordinator_document_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

/**
 * Current create collection coordinator's operation state.
 */
namespace  {
constexpr StringData kCreateCollectionCoordinatorPhase_kUnset = "unset"_sd;
constexpr StringData kCreateCollectionCoordinatorPhase_kCommit = "commit"_sd;
}  // namespace 

CreateCollectionCoordinatorPhaseEnum CreateCollectionCoordinatorPhase_parse(const IDLParserErrorContext& ctxt, StringData value) {
    if (value == kCreateCollectionCoordinatorPhase_kUnset) {
        return CreateCollectionCoordinatorPhaseEnum::kUnset;
    }
    if (value == kCreateCollectionCoordinatorPhase_kCommit) {
        return CreateCollectionCoordinatorPhaseEnum::kCommit;
    }
    ctxt.throwBadEnumValue(value);
}

StringData CreateCollectionCoordinatorPhase_serializer(CreateCollectionCoordinatorPhaseEnum value) {
    if (value == CreateCollectionCoordinatorPhaseEnum::kUnset) {
        return kCreateCollectionCoordinatorPhase_kUnset;
    }
    if (value == CreateCollectionCoordinatorPhaseEnum::kCommit) {
        return kCreateCollectionCoordinatorPhase_kCommit;
    }
    MONGO_UNREACHABLE;
    return StringData();
}

constexpr StringData CreateCollectionCoordinatorDocument::kCreateCollectionRequestFieldName;
constexpr StringData CreateCollectionCoordinatorDocument::kShardingDDLCoordinatorMetadataFieldName;
constexpr StringData CreateCollectionCoordinatorDocument::kCollationFieldName;
constexpr StringData CreateCollectionCoordinatorDocument::kDatabaseVersionFieldName;
constexpr StringData CreateCollectionCoordinatorDocument::kForwardableOpMetadataFieldName;
constexpr StringData CreateCollectionCoordinatorDocument::kIdFieldName;
constexpr StringData CreateCollectionCoordinatorDocument::kInitialSplitPointsFieldName;
constexpr StringData CreateCollectionCoordinatorDocument::kNumInitialChunksFieldName;
constexpr StringData CreateCollectionCoordinatorDocument::kPhaseFieldName;
constexpr StringData CreateCollectionCoordinatorDocument::kPresplitHashedZonesFieldName;
constexpr StringData CreateCollectionCoordinatorDocument::kRecoveredFromDiskFieldName;
constexpr StringData CreateCollectionCoordinatorDocument::kSessionFieldName;
constexpr StringData CreateCollectionCoordinatorDocument::kShardKeyFieldName;
constexpr StringData CreateCollectionCoordinatorDocument::kTimeseriesFieldName;
constexpr StringData CreateCollectionCoordinatorDocument::kUniqueFieldName;


CreateCollectionCoordinatorDocument::CreateCollectionCoordinatorDocument()  {
    // Used for initialization only
}


CreateCollectionCoordinatorDocument CreateCollectionCoordinatorDocument::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<CreateCollectionCoordinatorDocument>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void CreateCollectionCoordinatorDocument::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<15> usedFields;
    const size_t kIdBit = 0;
    const size_t kRecoveredFromDiskBit = 1;
    const size_t kForwardableOpMetadataBit = 2;
    const size_t kDatabaseVersionBit = 3;
    const size_t kSessionBit = 4;
    const size_t kShardKeyBit = 5;
    const size_t kUniqueBit = 6;
    const size_t kNumInitialChunksBit = 7;
    const size_t kPresplitHashedZonesBit = 8;
    const size_t kInitialSplitPointsBit = 9;
    const size_t kTimeseriesBit = 10;
    const size_t kCollationBit = 11;
    const size_t kPhaseBit = 12;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIdBit);

                IDLParserErrorContext tempContext(kIdFieldName, &ctxt);
                const auto localObject = element.Obj();
                _shardingDDLCoordinatorMetadata.setId(mongo::ShardingDDLCoordinatorId::parse(tempContext, localObject));
            }
        }
        else if (fieldName == kRecoveredFromDiskFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kRecoveredFromDiskBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRecoveredFromDiskBit);

                _shardingDDLCoordinatorMetadata.setRecoveredFromDisk(element.boolean());
            }
        }
        else if (fieldName == kForwardableOpMetadataFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kForwardableOpMetadataBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kForwardableOpMetadataBit);

                const BSONObj localObject = element.Obj();
                _shardingDDLCoordinatorMetadata.setForwardableOpMetadata(boost::optional<mongo::ForwardableOperationMetadata>(ForwardableOperationMetadata(localObject)));
            }
        }
        else if (fieldName == kDatabaseVersionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kDatabaseVersionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDatabaseVersionBit);

                const BSONObj localObject = element.Obj();
                _shardingDDLCoordinatorMetadata.setDatabaseVersion(boost::optional<mongo::DatabaseVersion>(DatabaseVersion(localObject)));
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
                _shardingDDLCoordinatorMetadata.setSession(boost::optional<mongo::ShardingDDLSession>(mongo::ShardingDDLSession::parse(tempContext, localObject)));
            }
        }
        else if (fieldName == kShardKeyFieldName) {
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
        else if (fieldName == kPhaseFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kPhaseBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPhaseBit);

                IDLParserErrorContext tempContext(kPhaseFieldName, &ctxt);
                _phase = CreateCollectionCoordinatorPhase_parse(tempContext, element.valueStringData());
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
            _shardingDDLCoordinatorMetadata.setRecoveredFromDisk(false);
        }
        if (!usedFields[kPhaseBit]) {
            _phase = mongo::CreateCollectionCoordinatorPhaseEnum::kUnset;
        }
    }

}


void CreateCollectionCoordinatorDocument::serialize(BSONObjBuilder* builder) const {
    {
        _shardingDDLCoordinatorMetadata.serialize(builder);
    }

    {
        _createCollectionRequest.serialize(builder);
    }

    {
        builder->append(kPhaseFieldName, ::mongo::CreateCollectionCoordinatorPhase_serializer(_phase));
    }

}


BSONObj CreateCollectionCoordinatorDocument::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
