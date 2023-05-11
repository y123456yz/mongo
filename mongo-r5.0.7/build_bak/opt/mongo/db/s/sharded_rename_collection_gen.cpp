/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/s/sharded_rename_collection_gen.h --output build/opt/mongo/db/s/sharded_rename_collection_gen.cpp src/mongo/db/s/sharded_rename_collection.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/s/sharded_rename_collection_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

/**
 * The current state of a rename collection operation on the coordinator.
 */
namespace  {
constexpr StringData kRenameCollectionCoordinatorPhase_kUnset = "unset"_sd;
constexpr StringData kRenameCollectionCoordinatorPhase_kCheckPreconditions = "checkPreconditions"_sd;
constexpr StringData kRenameCollectionCoordinatorPhase_kFreezeMigrations = "freezeMigrations"_sd;
constexpr StringData kRenameCollectionCoordinatorPhase_kBlockCrudAndRename = "blockCRUDAndRename"_sd;
constexpr StringData kRenameCollectionCoordinatorPhase_kRenameMetadata = "renameMetadata"_sd;
constexpr StringData kRenameCollectionCoordinatorPhase_kUnblockCRUD = "unblockCRUD"_sd;
constexpr StringData kRenameCollectionCoordinatorPhase_kSetResponse = "setResponse"_sd;
}  // namespace 

RenameCollectionCoordinatorPhaseEnum RenameCollectionCoordinatorPhase_parse(const IDLParserErrorContext& ctxt, StringData value) {
    if (value == kRenameCollectionCoordinatorPhase_kUnset) {
        return RenameCollectionCoordinatorPhaseEnum::kUnset;
    }
    if (value == kRenameCollectionCoordinatorPhase_kCheckPreconditions) {
        return RenameCollectionCoordinatorPhaseEnum::kCheckPreconditions;
    }
    if (value == kRenameCollectionCoordinatorPhase_kFreezeMigrations) {
        return RenameCollectionCoordinatorPhaseEnum::kFreezeMigrations;
    }
    if (value == kRenameCollectionCoordinatorPhase_kBlockCrudAndRename) {
        return RenameCollectionCoordinatorPhaseEnum::kBlockCrudAndRename;
    }
    if (value == kRenameCollectionCoordinatorPhase_kRenameMetadata) {
        return RenameCollectionCoordinatorPhaseEnum::kRenameMetadata;
    }
    if (value == kRenameCollectionCoordinatorPhase_kUnblockCRUD) {
        return RenameCollectionCoordinatorPhaseEnum::kUnblockCRUD;
    }
    if (value == kRenameCollectionCoordinatorPhase_kSetResponse) {
        return RenameCollectionCoordinatorPhaseEnum::kSetResponse;
    }
    ctxt.throwBadEnumValue(value);
}

StringData RenameCollectionCoordinatorPhase_serializer(RenameCollectionCoordinatorPhaseEnum value) {
    if (value == RenameCollectionCoordinatorPhaseEnum::kUnset) {
        return kRenameCollectionCoordinatorPhase_kUnset;
    }
    if (value == RenameCollectionCoordinatorPhaseEnum::kCheckPreconditions) {
        return kRenameCollectionCoordinatorPhase_kCheckPreconditions;
    }
    if (value == RenameCollectionCoordinatorPhaseEnum::kFreezeMigrations) {
        return kRenameCollectionCoordinatorPhase_kFreezeMigrations;
    }
    if (value == RenameCollectionCoordinatorPhaseEnum::kBlockCrudAndRename) {
        return kRenameCollectionCoordinatorPhase_kBlockCrudAndRename;
    }
    if (value == RenameCollectionCoordinatorPhaseEnum::kRenameMetadata) {
        return kRenameCollectionCoordinatorPhase_kRenameMetadata;
    }
    if (value == RenameCollectionCoordinatorPhaseEnum::kUnblockCRUD) {
        return kRenameCollectionCoordinatorPhase_kUnblockCRUD;
    }
    if (value == RenameCollectionCoordinatorPhaseEnum::kSetResponse) {
        return kRenameCollectionCoordinatorPhase_kSetResponse;
    }
    MONGO_UNREACHABLE;
    return StringData();
}

/**
 * The current state of a rename collection operation on a participant.
 */
namespace  {
constexpr StringData kRenameCollectionParticipantPhase_kUnset = "unset"_sd;
constexpr StringData kRenameCollectionParticipantPhase_kBlockCRUDAndSnapshotRangeDeletions = "blockCRUDAndSnapshotRangeDeletions"_sd;
constexpr StringData kRenameCollectionParticipantPhase_kRenameLocalAndRestoreRangeDeletions = "renameLocalAndRestoreRangeDeletions"_sd;
constexpr StringData kRenameCollectionParticipantPhase_kDeleteFromRangeDeletions = "deleteFromRangeDeletions"_sd;
constexpr StringData kRenameCollectionParticipantPhase_kUnblockCRUD = "unblockCRUD"_sd;
}  // namespace 

RenameCollectionParticipantPhaseEnum RenameCollectionParticipantPhase_parse(const IDLParserErrorContext& ctxt, StringData value) {
    if (value == kRenameCollectionParticipantPhase_kUnset) {
        return RenameCollectionParticipantPhaseEnum::kUnset;
    }
    if (value == kRenameCollectionParticipantPhase_kBlockCRUDAndSnapshotRangeDeletions) {
        return RenameCollectionParticipantPhaseEnum::kBlockCRUDAndSnapshotRangeDeletions;
    }
    if (value == kRenameCollectionParticipantPhase_kRenameLocalAndRestoreRangeDeletions) {
        return RenameCollectionParticipantPhaseEnum::kRenameLocalAndRestoreRangeDeletions;
    }
    if (value == kRenameCollectionParticipantPhase_kDeleteFromRangeDeletions) {
        return RenameCollectionParticipantPhaseEnum::kDeleteFromRangeDeletions;
    }
    if (value == kRenameCollectionParticipantPhase_kUnblockCRUD) {
        return RenameCollectionParticipantPhaseEnum::kUnblockCRUD;
    }
    ctxt.throwBadEnumValue(value);
}

StringData RenameCollectionParticipantPhase_serializer(RenameCollectionParticipantPhaseEnum value) {
    if (value == RenameCollectionParticipantPhaseEnum::kUnset) {
        return kRenameCollectionParticipantPhase_kUnset;
    }
    if (value == RenameCollectionParticipantPhaseEnum::kBlockCRUDAndSnapshotRangeDeletions) {
        return kRenameCollectionParticipantPhase_kBlockCRUDAndSnapshotRangeDeletions;
    }
    if (value == RenameCollectionParticipantPhaseEnum::kRenameLocalAndRestoreRangeDeletions) {
        return kRenameCollectionParticipantPhase_kRenameLocalAndRestoreRangeDeletions;
    }
    if (value == RenameCollectionParticipantPhaseEnum::kDeleteFromRangeDeletions) {
        return kRenameCollectionParticipantPhase_kDeleteFromRangeDeletions;
    }
    if (value == RenameCollectionParticipantPhaseEnum::kUnblockCRUD) {
        return kRenameCollectionParticipantPhase_kUnblockCRUD;
    }
    MONGO_UNREACHABLE;
    return StringData();
}

constexpr StringData RenameCollectionCoordinatorDocument::kRenameCollectionRequestFieldName;
constexpr StringData RenameCollectionCoordinatorDocument::kShardingDDLCoordinatorMetadataFieldName;
constexpr StringData RenameCollectionCoordinatorDocument::kDatabaseVersionFieldName;
constexpr StringData RenameCollectionCoordinatorDocument::kDropTargetFieldName;
constexpr StringData RenameCollectionCoordinatorDocument::kForwardableOpMetadataFieldName;
constexpr StringData RenameCollectionCoordinatorDocument::kIdFieldName;
constexpr StringData RenameCollectionCoordinatorDocument::kOptShardedCollInfoFieldName;
constexpr StringData RenameCollectionCoordinatorDocument::kPhaseFieldName;
constexpr StringData RenameCollectionCoordinatorDocument::kRecoveredFromDiskFieldName;
constexpr StringData RenameCollectionCoordinatorDocument::kSessionFieldName;
constexpr StringData RenameCollectionCoordinatorDocument::kSourceUUIDFieldName;
constexpr StringData RenameCollectionCoordinatorDocument::kStayTempFieldName;
constexpr StringData RenameCollectionCoordinatorDocument::kTargetIsShardedFieldName;
constexpr StringData RenameCollectionCoordinatorDocument::kTargetUUIDFieldName;
constexpr StringData RenameCollectionCoordinatorDocument::kToFieldName;


RenameCollectionCoordinatorDocument::RenameCollectionCoordinatorDocument()  {
    // Used for initialization only
}


RenameCollectionCoordinatorDocument RenameCollectionCoordinatorDocument::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<RenameCollectionCoordinatorDocument>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void RenameCollectionCoordinatorDocument::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<15> usedFields;
    const size_t kIdBit = 0;
    const size_t kRecoveredFromDiskBit = 1;
    const size_t kForwardableOpMetadataBit = 2;
    const size_t kDatabaseVersionBit = 3;
    const size_t kSessionBit = 4;
    const size_t kToBit = 5;
    const size_t kDropTargetBit = 6;
    const size_t kStayTempBit = 7;
    const size_t kPhaseBit = 8;
    const size_t kTargetIsShardedBit = 9;
    const size_t kOptShardedCollInfoBit = 10;
    const size_t kSourceUUIDBit = 11;
    const size_t kTargetUUIDBit = 12;
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
        else if (fieldName == kToFieldName) {
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
        else if (fieldName == kPhaseFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kPhaseBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPhaseBit);

                IDLParserErrorContext tempContext(kPhaseFieldName, &ctxt);
                _phase = RenameCollectionCoordinatorPhase_parse(tempContext, element.valueStringData());
            }
        }
        else if (fieldName == kTargetIsShardedFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kTargetIsShardedBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTargetIsShardedBit);

                _targetIsSharded = element.boolean();
            }
        }
        else if (fieldName == kOptShardedCollInfoFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kOptShardedCollInfoBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kOptShardedCollInfoBit);

                const BSONObj localObject = element.Obj();
                _optShardedCollInfo = CollectionType(localObject);
            }
        }
        else if (fieldName == kSourceUUIDFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kSourceUUIDBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSourceUUIDBit);

                _sourceUUID = UUID(uassertStatusOK(UUID::parse(element)));
            }
        }
        else if (fieldName == kTargetUUIDFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kTargetUUIDBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTargetUUIDBit);

                _targetUUID = UUID(uassertStatusOK(UUID::parse(element)));
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
        if (!usedFields[kToBit]) {
            ctxt.throwMissingField(kToFieldName);
        }
        if (!usedFields[kDropTargetBit]) {
            _renameCollectionRequest.setDropTarget(false);
        }
        if (!usedFields[kStayTempBit]) {
            _renameCollectionRequest.setStayTemp(false);
        }
        if (!usedFields[kPhaseBit]) {
            _phase = mongo::RenameCollectionCoordinatorPhaseEnum::kUnset;
        }
        if (!usedFields[kTargetIsShardedBit]) {
            _targetIsSharded = false;
        }
    }

}


void RenameCollectionCoordinatorDocument::serialize(BSONObjBuilder* builder) const {
    {
        _shardingDDLCoordinatorMetadata.serialize(builder);
    }

    {
        _renameCollectionRequest.serialize(builder);
    }

    {
        builder->append(kPhaseFieldName, ::mongo::RenameCollectionCoordinatorPhase_serializer(_phase));
    }

    builder->append(kTargetIsShardedFieldName, _targetIsSharded);

    if (_optShardedCollInfo.is_initialized()) {
        const BSONObj localObject = _optShardedCollInfo.get().toBSON();
        builder->append(kOptShardedCollInfoFieldName, localObject);
    }

    if (_sourceUUID.is_initialized()) {
        ConstDataRange tempCDR = _sourceUUID.get().toCDR();
        builder->append(kSourceUUIDFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    if (_targetUUID.is_initialized()) {
        ConstDataRange tempCDR = _targetUUID.get().toCDR();
        builder->append(kTargetUUIDFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

}


BSONObj RenameCollectionCoordinatorDocument::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData RenameCollectionParticipantDocument::kRenameCollectionRequestFieldName;
constexpr StringData RenameCollectionParticipantDocument::kDropTargetFieldName;
constexpr StringData RenameCollectionParticipantDocument::kForwardableOpMetadataFieldName;
constexpr StringData RenameCollectionParticipantDocument::kFromNssFieldName;
constexpr StringData RenameCollectionParticipantDocument::kPhaseFieldName;
constexpr StringData RenameCollectionParticipantDocument::kSourceUUIDFieldName;
constexpr StringData RenameCollectionParticipantDocument::kStayTempFieldName;
constexpr StringData RenameCollectionParticipantDocument::kTargetUUIDFieldName;
constexpr StringData RenameCollectionParticipantDocument::kToFieldName;


RenameCollectionParticipantDocument::RenameCollectionParticipantDocument() : _fromNss(mongo::idl::preparsedValue<decltype(_fromNss)>()), _forwardableOpMetadata(mongo::idl::preparsedValue<decltype(_forwardableOpMetadata)>()), _sourceUUID(mongo::idl::preparsedValue<decltype(_sourceUUID)>()), _hasFromNss(false), _hasForwardableOpMetadata(false), _hasSourceUUID(false) {
    // Used for initialization only
}
RenameCollectionParticipantDocument::RenameCollectionParticipantDocument(mongo::NamespaceString fromNss, mongo::ForwardableOperationMetadata forwardableOpMetadata, mongo::UUID sourceUUID) : _fromNss(std::move(fromNss)), _forwardableOpMetadata(std::move(forwardableOpMetadata)), _sourceUUID(std::move(sourceUUID)), _hasFromNss(true), _hasForwardableOpMetadata(true), _hasSourceUUID(true) {
    // Used for initialization only
}


RenameCollectionParticipantDocument RenameCollectionParticipantDocument::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<RenameCollectionParticipantDocument>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void RenameCollectionParticipantDocument::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<9> usedFields;
    const size_t kToBit = 0;
    const size_t kDropTargetBit = 1;
    const size_t kStayTempBit = 2;
    const size_t kFromNssBit = 3;
    const size_t kPhaseBit = 4;
    const size_t kForwardableOpMetadataBit = 5;
    const size_t kSourceUUIDBit = 6;
    const size_t kTargetUUIDBit = 7;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


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
        else if (fieldName == kFromNssFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kFromNssBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kFromNssBit);

                _hasFromNss = true;
                _fromNss = NamespaceString(element.valueStringData());
            }
        }
        else if (fieldName == kPhaseFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kPhaseBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPhaseBit);

                IDLParserErrorContext tempContext(kPhaseFieldName, &ctxt);
                _phase = RenameCollectionParticipantPhase_parse(tempContext, element.valueStringData());
            }
        }
        else if (fieldName == kForwardableOpMetadataFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kForwardableOpMetadataBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kForwardableOpMetadataBit);

                _hasForwardableOpMetadata = true;
                const BSONObj localObject = element.Obj();
                _forwardableOpMetadata = ForwardableOperationMetadata(localObject);
            }
        }
        else if (fieldName == kSourceUUIDFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kSourceUUIDBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSourceUUIDBit);

                _hasSourceUUID = true;
                _sourceUUID = UUID(uassertStatusOK(UUID::parse(element)));
            }
        }
        else if (fieldName == kTargetUUIDFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kTargetUUIDBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTargetUUIDBit);

                _targetUUID = UUID(uassertStatusOK(UUID::parse(element)));
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
        if (!usedFields[kFromNssBit]) {
            ctxt.throwMissingField(kFromNssFieldName);
        }
        if (!usedFields[kPhaseBit]) {
            _phase = mongo::RenameCollectionParticipantPhaseEnum::kUnset;
        }
        if (!usedFields[kForwardableOpMetadataBit]) {
            ctxt.throwMissingField(kForwardableOpMetadataFieldName);
        }
        if (!usedFields[kSourceUUIDBit]) {
            ctxt.throwMissingField(kSourceUUIDFieldName);
        }
    }

}


void RenameCollectionParticipantDocument::serialize(BSONObjBuilder* builder) const {
    invariant(_hasFromNss && _hasForwardableOpMetadata && _hasSourceUUID);

    {
        _renameCollectionRequest.serialize(builder);
    }

    {
        builder->append(kFromNssFieldName, _fromNss.toString());
    }

    {
        builder->append(kPhaseFieldName, ::mongo::RenameCollectionParticipantPhase_serializer(_phase));
    }

    {
        const BSONObj localObject = _forwardableOpMetadata.toBSON();
        builder->append(kForwardableOpMetadataFieldName, localObject);
    }

    {
        ConstDataRange tempCDR = _sourceUUID.toCDR();
        builder->append(kSourceUUIDFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    if (_targetUUID.is_initialized()) {
        ConstDataRange tempCDR = _targetUUID.get().toCDR();
        builder->append(kTargetUUIDFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

}


BSONObj RenameCollectionParticipantDocument::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData ShardsvrRenameCollectionParticipant::kRenameCollectionRequestFieldName;
constexpr StringData ShardsvrRenameCollectionParticipant::kDbNameFieldName;
constexpr StringData ShardsvrRenameCollectionParticipant::kDropTargetFieldName;
constexpr StringData ShardsvrRenameCollectionParticipant::kSourceUUIDFieldName;
constexpr StringData ShardsvrRenameCollectionParticipant::kStayTempFieldName;
constexpr StringData ShardsvrRenameCollectionParticipant::kTargetUUIDFieldName;
constexpr StringData ShardsvrRenameCollectionParticipant::kToFieldName;
constexpr StringData ShardsvrRenameCollectionParticipant::kCommandName;

const std::vector<StringData> ShardsvrRenameCollectionParticipant::_knownBSONFields {
    ShardsvrRenameCollectionParticipant::kRenameCollectionRequestFieldName,
    ShardsvrRenameCollectionParticipant::kDropTargetFieldName,
    ShardsvrRenameCollectionParticipant::kSourceUUIDFieldName,
    ShardsvrRenameCollectionParticipant::kStayTempFieldName,
    ShardsvrRenameCollectionParticipant::kTargetUUIDFieldName,
    ShardsvrRenameCollectionParticipant::kToFieldName,
    ShardsvrRenameCollectionParticipant::kCommandName,
};
const std::vector<StringData> ShardsvrRenameCollectionParticipant::_knownOP_MSGFields {
    ShardsvrRenameCollectionParticipant::kRenameCollectionRequestFieldName,
    ShardsvrRenameCollectionParticipant::kDbNameFieldName,
    ShardsvrRenameCollectionParticipant::kDropTargetFieldName,
    ShardsvrRenameCollectionParticipant::kSourceUUIDFieldName,
    ShardsvrRenameCollectionParticipant::kStayTempFieldName,
    ShardsvrRenameCollectionParticipant::kTargetUUIDFieldName,
    ShardsvrRenameCollectionParticipant::kToFieldName,
    ShardsvrRenameCollectionParticipant::kCommandName,
};

ShardsvrRenameCollectionParticipant::ShardsvrRenameCollectionParticipant(const NamespaceString nss) : _nss(std::move(nss)), _sourceUUID(mongo::idl::preparsedValue<decltype(_sourceUUID)>()), _dbName(nss.db().toString()), _hasSourceUUID(false), _hasDbName(true) {
    // Used for initialization only
}
ShardsvrRenameCollectionParticipant::ShardsvrRenameCollectionParticipant(const NamespaceString nss, mongo::UUID sourceUUID) : _nss(std::move(nss)), _sourceUUID(std::move(sourceUUID)), _dbName(nss.db().toString()), _hasSourceUUID(true), _hasDbName(true) {
    // Used for initialization only
}


ShardsvrRenameCollectionParticipant ShardsvrRenameCollectionParticipant::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    NamespaceString localNS;
    ShardsvrRenameCollectionParticipant object(localNS);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ShardsvrRenameCollectionParticipant::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<7> usedFields;
    const size_t kToBit = 0;
    const size_t kDropTargetBit = 1;
    const size_t kStayTempBit = 2;
    const size_t kSourceUUIDBit = 3;
    const size_t kTargetUUIDBit = 4;
    const size_t kDbNameBit = 5;
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
        else if (fieldName == kSourceUUIDFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kSourceUUIDBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSourceUUIDBit);

                _hasSourceUUID = true;
                _sourceUUID = UUID(uassertStatusOK(UUID::parse(element)));
            }
        }
        else if (fieldName == kTargetUUIDFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kTargetUUIDBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTargetUUIDBit);

                _targetUUID = UUID(uassertStatusOK(UUID::parse(element)));
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
        if (!usedFields[kSourceUUIDBit]) {
            ctxt.throwMissingField(kSourceUUIDFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

ShardsvrRenameCollectionParticipant ShardsvrRenameCollectionParticipant::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    NamespaceString localNS;
    ShardsvrRenameCollectionParticipant object(localNS);
    object.parseProtected(ctxt, request);
    return object;
}
void ShardsvrRenameCollectionParticipant::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<7> usedFields;
    const size_t kToBit = 0;
    const size_t kDropTargetBit = 1;
    const size_t kStayTempBit = 2;
    const size_t kSourceUUIDBit = 3;
    const size_t kTargetUUIDBit = 4;
    const size_t kDbNameBit = 5;
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
        else if (fieldName == kSourceUUIDFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kSourceUUIDBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSourceUUIDBit);

                _hasSourceUUID = true;
                _sourceUUID = UUID(uassertStatusOK(UUID::parse(element)));
            }
        }
        else if (fieldName == kTargetUUIDFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kTargetUUIDBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTargetUUIDBit);

                _targetUUID = UUID(uassertStatusOK(UUID::parse(element)));
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
        if (!usedFields[kSourceUUIDBit]) {
            ctxt.throwMissingField(kSourceUUIDFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

void ShardsvrRenameCollectionParticipant::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasSourceUUID && _hasDbName);

    invariant(!_nss.isEmpty());
    builder->append("_shardsvrRenameCollectionParticipant"_sd, _nss.coll());

    {
        _renameCollectionRequest.serialize(builder);
    }

    {
        ConstDataRange tempCDR = _sourceUUID.toCDR();
        builder->append(kSourceUUIDFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    if (_targetUUID.is_initialized()) {
        ConstDataRange tempCDR = _targetUUID.get().toCDR();
        builder->append(kTargetUUIDFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest ShardsvrRenameCollectionParticipant::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasSourceUUID && _hasDbName);

        invariant(!_nss.isEmpty());
        builder->append("_shardsvrRenameCollectionParticipant"_sd, _nss.coll());

        {
            _renameCollectionRequest.serialize(builder);
        }

        {
            ConstDataRange tempCDR = _sourceUUID.toCDR();
            builder->append(kSourceUUIDFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
        }

        if (_targetUUID.is_initialized()) {
            ConstDataRange tempCDR = _targetUUID.get().toCDR();
            builder->append(kTargetUUIDFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj ShardsvrRenameCollectionParticipant::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData ShardsvrRenameCollectionUnblockParticipant::kRenameCollectionRequestFieldName;
constexpr StringData ShardsvrRenameCollectionUnblockParticipant::kDbNameFieldName;
constexpr StringData ShardsvrRenameCollectionUnblockParticipant::kDropTargetFieldName;
constexpr StringData ShardsvrRenameCollectionUnblockParticipant::kSourceUUIDFieldName;
constexpr StringData ShardsvrRenameCollectionUnblockParticipant::kStayTempFieldName;
constexpr StringData ShardsvrRenameCollectionUnblockParticipant::kToFieldName;
constexpr StringData ShardsvrRenameCollectionUnblockParticipant::kCommandName;

const std::vector<StringData> ShardsvrRenameCollectionUnblockParticipant::_knownBSONFields {
    ShardsvrRenameCollectionUnblockParticipant::kRenameCollectionRequestFieldName,
    ShardsvrRenameCollectionUnblockParticipant::kDropTargetFieldName,
    ShardsvrRenameCollectionUnblockParticipant::kSourceUUIDFieldName,
    ShardsvrRenameCollectionUnblockParticipant::kStayTempFieldName,
    ShardsvrRenameCollectionUnblockParticipant::kToFieldName,
    ShardsvrRenameCollectionUnblockParticipant::kCommandName,
};
const std::vector<StringData> ShardsvrRenameCollectionUnblockParticipant::_knownOP_MSGFields {
    ShardsvrRenameCollectionUnblockParticipant::kRenameCollectionRequestFieldName,
    ShardsvrRenameCollectionUnblockParticipant::kDbNameFieldName,
    ShardsvrRenameCollectionUnblockParticipant::kDropTargetFieldName,
    ShardsvrRenameCollectionUnblockParticipant::kSourceUUIDFieldName,
    ShardsvrRenameCollectionUnblockParticipant::kStayTempFieldName,
    ShardsvrRenameCollectionUnblockParticipant::kToFieldName,
    ShardsvrRenameCollectionUnblockParticipant::kCommandName,
};

ShardsvrRenameCollectionUnblockParticipant::ShardsvrRenameCollectionUnblockParticipant(const NamespaceString nss) : _nss(std::move(nss)), _sourceUUID(mongo::idl::preparsedValue<decltype(_sourceUUID)>()), _dbName(nss.db().toString()), _hasSourceUUID(false), _hasDbName(true) {
    // Used for initialization only
}
ShardsvrRenameCollectionUnblockParticipant::ShardsvrRenameCollectionUnblockParticipant(const NamespaceString nss, mongo::UUID sourceUUID) : _nss(std::move(nss)), _sourceUUID(std::move(sourceUUID)), _dbName(nss.db().toString()), _hasSourceUUID(true), _hasDbName(true) {
    // Used for initialization only
}


ShardsvrRenameCollectionUnblockParticipant ShardsvrRenameCollectionUnblockParticipant::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    NamespaceString localNS;
    ShardsvrRenameCollectionUnblockParticipant object(localNS);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ShardsvrRenameCollectionUnblockParticipant::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<6> usedFields;
    const size_t kToBit = 0;
    const size_t kDropTargetBit = 1;
    const size_t kStayTempBit = 2;
    const size_t kSourceUUIDBit = 3;
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
        else if (fieldName == kSourceUUIDFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kSourceUUIDBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSourceUUIDBit);

                _hasSourceUUID = true;
                _sourceUUID = UUID(uassertStatusOK(UUID::parse(element)));
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
        if (!usedFields[kSourceUUIDBit]) {
            ctxt.throwMissingField(kSourceUUIDFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

ShardsvrRenameCollectionUnblockParticipant ShardsvrRenameCollectionUnblockParticipant::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    NamespaceString localNS;
    ShardsvrRenameCollectionUnblockParticipant object(localNS);
    object.parseProtected(ctxt, request);
    return object;
}
void ShardsvrRenameCollectionUnblockParticipant::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<6> usedFields;
    const size_t kToBit = 0;
    const size_t kDropTargetBit = 1;
    const size_t kStayTempBit = 2;
    const size_t kSourceUUIDBit = 3;
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
        else if (fieldName == kSourceUUIDFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kSourceUUIDBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSourceUUIDBit);

                _hasSourceUUID = true;
                _sourceUUID = UUID(uassertStatusOK(UUID::parse(element)));
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
        if (!usedFields[kSourceUUIDBit]) {
            ctxt.throwMissingField(kSourceUUIDFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

void ShardsvrRenameCollectionUnblockParticipant::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasSourceUUID && _hasDbName);

    invariant(!_nss.isEmpty());
    builder->append("_shardsvrRenameCollectionParticipantUnblock"_sd, _nss.coll());

    {
        _renameCollectionRequest.serialize(builder);
    }

    {
        ConstDataRange tempCDR = _sourceUUID.toCDR();
        builder->append(kSourceUUIDFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest ShardsvrRenameCollectionUnblockParticipant::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasSourceUUID && _hasDbName);

        invariant(!_nss.isEmpty());
        builder->append("_shardsvrRenameCollectionParticipantUnblock"_sd, _nss.coll());

        {
            _renameCollectionRequest.serialize(builder);
        }

        {
            ConstDataRange tempCDR = _sourceUUID.toCDR();
            builder->append(kSourceUUIDFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj ShardsvrRenameCollectionUnblockParticipant::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
