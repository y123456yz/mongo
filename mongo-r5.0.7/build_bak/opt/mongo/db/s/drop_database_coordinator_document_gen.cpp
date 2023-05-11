/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/s/drop_database_coordinator_document_gen.h --output build/opt/mongo/db/s/drop_database_coordinator_document_gen.cpp src/mongo/db/s/drop_database_coordinator_document.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/s/drop_database_coordinator_document_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

/**
 * The current phase of a drop database coordinator.
 */
namespace  {
constexpr StringData kDropDatabaseCoordinatorPhase_kUnset = "unset"_sd;
constexpr StringData kDropDatabaseCoordinatorPhase_kDrop = "drop"_sd;
}  // namespace 

DropDatabaseCoordinatorPhaseEnum DropDatabaseCoordinatorPhase_parse(const IDLParserErrorContext& ctxt, StringData value) {
    if (value == kDropDatabaseCoordinatorPhase_kUnset) {
        return DropDatabaseCoordinatorPhaseEnum::kUnset;
    }
    if (value == kDropDatabaseCoordinatorPhase_kDrop) {
        return DropDatabaseCoordinatorPhaseEnum::kDrop;
    }
    ctxt.throwBadEnumValue(value);
}

StringData DropDatabaseCoordinatorPhase_serializer(DropDatabaseCoordinatorPhaseEnum value) {
    if (value == DropDatabaseCoordinatorPhaseEnum::kUnset) {
        return kDropDatabaseCoordinatorPhase_kUnset;
    }
    if (value == DropDatabaseCoordinatorPhaseEnum::kDrop) {
        return kDropDatabaseCoordinatorPhase_kDrop;
    }
    MONGO_UNREACHABLE;
    return StringData();
}

constexpr StringData DropDatabaseCoordinatorDocument::kShardingDDLCoordinatorMetadataFieldName;
constexpr StringData DropDatabaseCoordinatorDocument::kCollInfoFieldName;
constexpr StringData DropDatabaseCoordinatorDocument::kDatabaseVersionFieldName;
constexpr StringData DropDatabaseCoordinatorDocument::kForwardableOpMetadataFieldName;
constexpr StringData DropDatabaseCoordinatorDocument::kIdFieldName;
constexpr StringData DropDatabaseCoordinatorDocument::kPhaseFieldName;
constexpr StringData DropDatabaseCoordinatorDocument::kRecoveredFromDiskFieldName;
constexpr StringData DropDatabaseCoordinatorDocument::kSessionFieldName;


DropDatabaseCoordinatorDocument::DropDatabaseCoordinatorDocument()  {
    // Used for initialization only
}


DropDatabaseCoordinatorDocument DropDatabaseCoordinatorDocument::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<DropDatabaseCoordinatorDocument>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void DropDatabaseCoordinatorDocument::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<8> usedFields;
    const size_t kIdBit = 0;
    const size_t kRecoveredFromDiskBit = 1;
    const size_t kForwardableOpMetadataBit = 2;
    const size_t kDatabaseVersionBit = 3;
    const size_t kSessionBit = 4;
    const size_t kPhaseBit = 5;
    const size_t kCollInfoBit = 6;
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
        else if (fieldName == kPhaseFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kPhaseBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPhaseBit);

                IDLParserErrorContext tempContext(kPhaseFieldName, &ctxt);
                _phase = DropDatabaseCoordinatorPhase_parse(tempContext, element.valueStringData());
            }
        }
        else if (fieldName == kCollInfoFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCollInfoBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollInfoBit);

                const BSONObj localObject = element.Obj();
                _collInfo = CollectionType(localObject);
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
            _phase = mongo::DropDatabaseCoordinatorPhaseEnum::kUnset;
        }
    }

}


void DropDatabaseCoordinatorDocument::serialize(BSONObjBuilder* builder) const {
    {
        _shardingDDLCoordinatorMetadata.serialize(builder);
    }

    {
        builder->append(kPhaseFieldName, ::mongo::DropDatabaseCoordinatorPhase_serializer(_phase));
    }

    if (_collInfo.is_initialized()) {
        const BSONObj localObject = _collInfo.get().toBSON();
        builder->append(kCollInfoFieldName, localObject);
    }

}


BSONObj DropDatabaseCoordinatorDocument::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
