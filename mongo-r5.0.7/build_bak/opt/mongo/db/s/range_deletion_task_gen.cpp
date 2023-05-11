/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/s/range_deletion_task_gen.h --output build/opt/mongo/db/s/range_deletion_task_gen.cpp src/mongo/db/s/range_deletion_task.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/s/range_deletion_task_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

/**
 * When to cleanup ranges.
 */
namespace  {
constexpr StringData kCleanWhen_kNow = "now"_sd;
constexpr StringData kCleanWhen_kDelayed = "delayed"_sd;
}  // namespace 

CleanWhenEnum CleanWhen_parse(const IDLParserErrorContext& ctxt, StringData value) {
    if (value == kCleanWhen_kNow) {
        return CleanWhenEnum::kNow;
    }
    if (value == kCleanWhen_kDelayed) {
        return CleanWhenEnum::kDelayed;
    }
    ctxt.throwBadEnumValue(value);
}

StringData CleanWhen_serializer(CleanWhenEnum value) {
    if (value == CleanWhenEnum::kNow) {
        return kCleanWhen_kNow;
    }
    if (value == CleanWhenEnum::kDelayed) {
        return kCleanWhen_kDelayed;
    }
    MONGO_UNREACHABLE;
    return StringData();
}

constexpr StringData RangeDeletionTask::kCollectionUuidFieldName;
constexpr StringData RangeDeletionTask::kDonorShardIdFieldName;
constexpr StringData RangeDeletionTask::kIdFieldName;
constexpr StringData RangeDeletionTask::kNssFieldName;
constexpr StringData RangeDeletionTask::kPendingFieldName;
constexpr StringData RangeDeletionTask::kRangeFieldName;
constexpr StringData RangeDeletionTask::kWhenToCleanFieldName;


RangeDeletionTask::RangeDeletionTask() : _id(mongo::idl::preparsedValue<decltype(_id)>()), _nss(mongo::idl::preparsedValue<decltype(_nss)>()), _collectionUuid(mongo::idl::preparsedValue<decltype(_collectionUuid)>()), _donorShardId(mongo::idl::preparsedValue<decltype(_donorShardId)>()), _range(mongo::idl::preparsedValue<decltype(_range)>()), _whenToClean(mongo::idl::preparsedValue<decltype(_whenToClean)>()), _hasId(false), _hasNss(false), _hasCollectionUuid(false), _hasDonorShardId(false), _hasRange(false), _hasWhenToClean(false) {
    // Used for initialization only
}
RangeDeletionTask::RangeDeletionTask(mongo::UUID id, mongo::NamespaceString nss, mongo::UUID collectionUuid, mongo::ShardId donorShardId, mongo::ChunkRange range, mongo::CleanWhenEnum whenToClean) : _id(std::move(id)), _nss(std::move(nss)), _collectionUuid(std::move(collectionUuid)), _donorShardId(std::move(donorShardId)), _range(std::move(range)), _whenToClean(std::move(whenToClean)), _hasId(true), _hasNss(true), _hasCollectionUuid(true), _hasDonorShardId(true), _hasRange(true), _hasWhenToClean(true) {
    // Used for initialization only
}


RangeDeletionTask RangeDeletionTask::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<RangeDeletionTask>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void RangeDeletionTask::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<7> usedFields;
    const size_t kIdBit = 0;
    const size_t kNssBit = 1;
    const size_t kCollectionUuidBit = 2;
    const size_t kDonorShardIdBit = 3;
    const size_t kRangeBit = 4;
    const size_t kPendingBit = 5;
    const size_t kWhenToCleanBit = 6;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIdBit);

                _hasId = true;
                _id = UUID(uassertStatusOK(UUID::parse(element)));
            }
        }
        else if (fieldName == kNssFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kNssBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNssBit);

                _hasNss = true;
                _nss = NamespaceString(element.valueStringData());
            }
        }
        else if (fieldName == kCollectionUuidFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kCollectionUuidBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollectionUuidBit);

                _hasCollectionUuid = true;
                _collectionUuid = UUID(uassertStatusOK(UUID::parse(element)));
            }
        }
        else if (fieldName == kDonorShardIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kDonorShardIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDonorShardIdBit);

                _hasDonorShardId = true;
                _donorShardId = element.str();
            }
        }
        else if (fieldName == kRangeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kRangeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRangeBit);

                _hasRange = true;
                const BSONObj localObject = element.Obj();
                _range = ChunkRange::fromBSONThrowing(localObject);
            }
        }
        else if (fieldName == kPendingFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kPendingBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPendingBit);

                _pending = element.boolean();
            }
        }
        else if (fieldName == kWhenToCleanFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kWhenToCleanBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kWhenToCleanBit);

                _hasWhenToClean = true;
                IDLParserErrorContext tempContext(kWhenToCleanFieldName, &ctxt);
                _whenToClean = CleanWhen_parse(tempContext, element.valueStringData());
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
        if (!usedFields[kNssBit]) {
            ctxt.throwMissingField(kNssFieldName);
        }
        if (!usedFields[kCollectionUuidBit]) {
            ctxt.throwMissingField(kCollectionUuidFieldName);
        }
        if (!usedFields[kDonorShardIdBit]) {
            ctxt.throwMissingField(kDonorShardIdFieldName);
        }
        if (!usedFields[kRangeBit]) {
            ctxt.throwMissingField(kRangeFieldName);
        }
        if (!usedFields[kWhenToCleanBit]) {
            ctxt.throwMissingField(kWhenToCleanFieldName);
        }
    }

}


void RangeDeletionTask::serialize(BSONObjBuilder* builder) const {
    invariant(_hasId && _hasNss && _hasCollectionUuid && _hasDonorShardId && _hasRange && _hasWhenToClean);

    {
        ConstDataRange tempCDR = _id.toCDR();
        builder->append(kIdFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    {
        builder->append(kNssFieldName, _nss.toString());
    }

    {
        ConstDataRange tempCDR = _collectionUuid.toCDR();
        builder->append(kCollectionUuidFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    {
        builder->append(kDonorShardIdFieldName, _donorShardId.toString());
    }

    {
        const BSONObj localObject = _range.toBSON();
        builder->append(kRangeFieldName, localObject);
    }

    if (_pending.is_initialized()) {
        builder->append(kPendingFieldName, _pending.get());
    }

    {
        builder->append(kWhenToCleanFieldName, ::mongo::CleanWhen_serializer(_whenToClean));
    }

}


BSONObj RangeDeletionTask::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
