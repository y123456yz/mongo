/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/s/resharding/type_collection_fields_gen.h --output build/opt/mongo/s/resharding/type_collection_fields_gen.cpp src/mongo/s/resharding/type_collection_fields.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/s/resharding/type_collection_fields_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData TypeCollectionDonorFields::kRecipientShardIdsFieldName;
constexpr StringData TypeCollectionDonorFields::kReshardingKeyFieldName;
constexpr StringData TypeCollectionDonorFields::kTempReshardingNssFieldName;


TypeCollectionDonorFields::TypeCollectionDonorFields() : _tempReshardingNss(mongo::idl::preparsedValue<decltype(_tempReshardingNss)>()), _reshardingKey(mongo::idl::preparsedValue<decltype(_reshardingKey)>()), _hasTempReshardingNss(false), _hasReshardingKey(false), _hasRecipientShardIds(false) {
    // Used for initialization only
}
TypeCollectionDonorFields::TypeCollectionDonorFields(mongo::NamespaceString tempReshardingNss, mongo::KeyPattern reshardingKey, std::vector<mongo::ShardId> recipientShardIds) : _tempReshardingNss(std::move(tempReshardingNss)), _reshardingKey(std::move(reshardingKey)), _recipientShardIds(std::move(recipientShardIds)), _hasTempReshardingNss(true), _hasReshardingKey(true), _hasRecipientShardIds(true) {
    // Used for initialization only
}


TypeCollectionDonorFields TypeCollectionDonorFields::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<TypeCollectionDonorFields>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void TypeCollectionDonorFields::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<3> usedFields;
    const size_t kTempReshardingNssBit = 0;
    const size_t kReshardingKeyBit = 1;
    const size_t kRecipientShardIdsBit = 2;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kTempReshardingNssFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kTempReshardingNssBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTempReshardingNssBit);

                _hasTempReshardingNss = true;
                _tempReshardingNss = NamespaceString(element.valueStringData());
            }
        }
        else if (fieldName == kReshardingKeyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kReshardingKeyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kReshardingKeyBit);

                _hasReshardingKey = true;
                const BSONObj localObject = element.Obj();
                _reshardingKey = KeyPattern::fromBSON(localObject);
            }
        }
        else if (fieldName == kRecipientShardIdsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kRecipientShardIdsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRecipientShardIdsBit);

                _hasRecipientShardIds = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kRecipientShardIdsFieldName, &ctxt);
            std::vector<mongo::ShardId> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, String)) {
                        values.emplace_back(arrayElement.str());
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _recipientShardIds = std::move(values);
        }
        else {
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kTempReshardingNssBit]) {
            ctxt.throwMissingField(kTempReshardingNssFieldName);
        }
        if (!usedFields[kReshardingKeyBit]) {
            ctxt.throwMissingField(kReshardingKeyFieldName);
        }
        if (!usedFields[kRecipientShardIdsBit]) {
            ctxt.throwMissingField(kRecipientShardIdsFieldName);
        }
    }

}


void TypeCollectionDonorFields::serialize(BSONObjBuilder* builder) const {
    invariant(_hasTempReshardingNss && _hasReshardingKey && _hasRecipientShardIds);

    {
        builder->append(kTempReshardingNssFieldName, _tempReshardingNss.toString());
    }

    {
        const BSONObj localObject = _reshardingKey.toBSON();
        builder->append(kReshardingKeyFieldName, localObject);
    }

    {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kRecipientShardIdsFieldName));
        for (const auto& item : _recipientShardIds) {
            arrayBuilder.append(item.toString());
        }
    }

}


BSONObj TypeCollectionDonorFields::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData TypeCollectionRecipientFields::kReshardingApproxCopySizeStructFieldName;
constexpr StringData TypeCollectionRecipientFields::kApproxBytesToCopyFieldName;
constexpr StringData TypeCollectionRecipientFields::kApproxDocumentsToCopyFieldName;
constexpr StringData TypeCollectionRecipientFields::kCloneTimestampFieldName;
constexpr StringData TypeCollectionRecipientFields::kDonorShardsFieldName;
constexpr StringData TypeCollectionRecipientFields::kMinimumOperationDurationMillisFieldName;
constexpr StringData TypeCollectionRecipientFields::kSourceNssFieldName;
constexpr StringData TypeCollectionRecipientFields::kSourceUUIDFieldName;


TypeCollectionRecipientFields::TypeCollectionRecipientFields() : _sourceUUID(mongo::idl::preparsedValue<decltype(_sourceUUID)>()), _sourceNss(mongo::idl::preparsedValue<decltype(_sourceNss)>()), _minimumOperationDurationMillis(mongo::idl::preparsedValue<decltype(_minimumOperationDurationMillis)>()), _hasDonorShards(false), _hasSourceUUID(false), _hasSourceNss(false), _hasMinimumOperationDurationMillis(false) {
    // Used for initialization only
}
TypeCollectionRecipientFields::TypeCollectionRecipientFields(std::vector<mongo::DonorShardFetchTimestamp> donorShards, mongo::UUID sourceUUID, mongo::NamespaceString sourceNss, std::int64_t minimumOperationDurationMillis) : _donorShards(std::move(donorShards)), _sourceUUID(std::move(sourceUUID)), _sourceNss(std::move(sourceNss)), _minimumOperationDurationMillis(std::move(minimumOperationDurationMillis)), _hasDonorShards(true), _hasSourceUUID(true), _hasSourceNss(true), _hasMinimumOperationDurationMillis(true) {
    // Used for initialization only
}


TypeCollectionRecipientFields TypeCollectionRecipientFields::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<TypeCollectionRecipientFields>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void TypeCollectionRecipientFields::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<8> usedFields;
    const size_t kApproxDocumentsToCopyBit = 0;
    const size_t kApproxBytesToCopyBit = 1;
    const size_t kCloneTimestampBit = 2;
    const size_t kDonorShardsBit = 3;
    const size_t kSourceUUIDBit = 4;
    const size_t kSourceNssBit = 5;
    const size_t kMinimumOperationDurationMillisBit = 6;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kApproxDocumentsToCopyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kApproxDocumentsToCopyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kApproxDocumentsToCopyBit);

                _reshardingApproxCopySizeStruct.setApproxDocumentsToCopy(boost::optional<std::int64_t>(element._numberLong()));
            }
        }
        else if (fieldName == kApproxBytesToCopyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kApproxBytesToCopyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kApproxBytesToCopyBit);

                _reshardingApproxCopySizeStruct.setApproxBytesToCopy(boost::optional<std::int64_t>(element._numberLong()));
            }
        }
        else if (fieldName == kCloneTimestampFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, bsonTimestamp))) {
                if (MONGO_unlikely(usedFields[kCloneTimestampBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCloneTimestampBit);

                _cloneTimestamp = element.timestamp();
            }
        }
        else if (fieldName == kDonorShardsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kDonorShardsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDonorShardsBit);

                _hasDonorShards = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kDonorShardsFieldName, &ctxt);
            std::vector<mongo::DonorShardFetchTimestamp> values;

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
                        IDLParserErrorContext tempContext(kDonorShardsFieldName, &ctxt);
                        const auto localObject = arrayElement.Obj();
                        values.emplace_back(mongo::DonorShardFetchTimestamp::parse(tempContext, localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _donorShards = std::move(values);
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
        else if (fieldName == kSourceNssFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kSourceNssBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSourceNssBit);

                _hasSourceNss = true;
                _sourceNss = NamespaceString(element.valueStringData());
            }
        }
        else if (fieldName == kMinimumOperationDurationMillisFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kMinimumOperationDurationMillisBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMinimumOperationDurationMillisBit);

                _hasMinimumOperationDurationMillis = true;
                _minimumOperationDurationMillis = element._numberLong();
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
        if (!usedFields[kDonorShardsBit]) {
            ctxt.throwMissingField(kDonorShardsFieldName);
        }
        if (!usedFields[kSourceUUIDBit]) {
            ctxt.throwMissingField(kSourceUUIDFieldName);
        }
        if (!usedFields[kSourceNssBit]) {
            ctxt.throwMissingField(kSourceNssFieldName);
        }
        if (!usedFields[kMinimumOperationDurationMillisBit]) {
            ctxt.throwMissingField(kMinimumOperationDurationMillisFieldName);
        }
    }

}


void TypeCollectionRecipientFields::serialize(BSONObjBuilder* builder) const {
    invariant(_hasDonorShards && _hasSourceUUID && _hasSourceNss && _hasMinimumOperationDurationMillis);

    {
        _reshardingApproxCopySizeStruct.serialize(builder);
    }

    if (_cloneTimestamp.is_initialized()) {
        builder->append(kCloneTimestampFieldName, _cloneTimestamp.get());
    }

    {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kDonorShardsFieldName));
        for (const auto& item : _donorShards) {
            BSONObjBuilder subObjBuilder(arrayBuilder.subobjStart());
            item.serialize(&subObjBuilder);
        }
    }

    {
        ConstDataRange tempCDR = _sourceUUID.toCDR();
        builder->append(kSourceUUIDFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    {
        builder->append(kSourceNssFieldName, _sourceNss.toString());
    }

    builder->append(kMinimumOperationDurationMillisFieldName, _minimumOperationDurationMillis);

}


BSONObj TypeCollectionRecipientFields::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData TypeCollectionReshardingFields::kDonorFieldsFieldName;
constexpr StringData TypeCollectionReshardingFields::kRecipientFieldsFieldName;
constexpr StringData TypeCollectionReshardingFields::kReshardingUUIDFieldName;
constexpr StringData TypeCollectionReshardingFields::kStateFieldName;
constexpr StringData TypeCollectionReshardingFields::kUserCanceledFieldName;


TypeCollectionReshardingFields::TypeCollectionReshardingFields() : _reshardingUUID(mongo::idl::preparsedValue<decltype(_reshardingUUID)>()), _hasReshardingUUID(false) {
    // Used for initialization only
}
TypeCollectionReshardingFields::TypeCollectionReshardingFields(mongo::UUID reshardingUUID) : _reshardingUUID(std::move(reshardingUUID)), _hasReshardingUUID(true) {
    // Used for initialization only
}


TypeCollectionReshardingFields TypeCollectionReshardingFields::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<TypeCollectionReshardingFields>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void TypeCollectionReshardingFields::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<5> usedFields;
    const size_t kReshardingUUIDBit = 0;
    const size_t kStateBit = 1;
    const size_t kUserCanceledBit = 2;
    const size_t kDonorFieldsBit = 3;
    const size_t kRecipientFieldsBit = 4;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kReshardingUUIDFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kReshardingUUIDBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kReshardingUUIDBit);

                _hasReshardingUUID = true;
                _reshardingUUID = UUID(uassertStatusOK(UUID::parse(element)));
            }
        }
        else if (fieldName == kStateFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kStateBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStateBit);

                IDLParserErrorContext tempContext(kStateFieldName, &ctxt);
                _state = CoordinatorState_parse(tempContext, element.valueStringData());
            }
        }
        else if (fieldName == kUserCanceledFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kUserCanceledBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUserCanceledBit);

                _userCanceled = element.boolean();
            }
        }
        else if (fieldName == kDonorFieldsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kDonorFieldsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDonorFieldsBit);

                IDLParserErrorContext tempContext(kDonorFieldsFieldName, &ctxt);
                const auto localObject = element.Obj();
                _donorFields = mongo::TypeCollectionDonorFields::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kRecipientFieldsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kRecipientFieldsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRecipientFieldsBit);

                IDLParserErrorContext tempContext(kRecipientFieldsFieldName, &ctxt);
                const auto localObject = element.Obj();
                _recipientFields = mongo::TypeCollectionRecipientFields::parse(tempContext, localObject);
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
        if (!usedFields[kReshardingUUIDBit]) {
            ctxt.throwMissingField(kReshardingUUIDFieldName);
        }
        if (!usedFields[kStateBit]) {
            _state = mongo::CoordinatorStateEnum::kUnused;
        }
    }

}


void TypeCollectionReshardingFields::serialize(BSONObjBuilder* builder) const {
    invariant(_hasReshardingUUID);

    {
        ConstDataRange tempCDR = _reshardingUUID.toCDR();
        builder->append(kReshardingUUIDFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    {
        builder->append(kStateFieldName, ::mongo::CoordinatorState_serializer(_state));
    }

    if (_userCanceled.is_initialized()) {
        builder->append(kUserCanceledFieldName, _userCanceled.get());
    }

    if (_donorFields.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kDonorFieldsFieldName));
        _donorFields.get().serialize(&subObjBuilder);
    }

    if (_recipientFields.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kRecipientFieldsFieldName));
        _recipientFields.get().serialize(&subObjBuilder);
    }

}


BSONObj TypeCollectionReshardingFields::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
