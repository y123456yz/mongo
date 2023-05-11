/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/s/resharding/type_collection_fields_gen.h --output build/opt/mongo/s/resharding/type_collection_fields_gen.cpp src/mongo/s/resharding/type_collection_fields.idl
 */

#pragma once

#include <algorithm>
#include <boost/optional.hpp>
#include <cstdint>
#include <string>
#include <tuple>
#include <vector>

#include "mongo/base/data_range.h"
#include "mongo/base/string_data.h"
#include "mongo/bson/bsonobj.h"
#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/bson/simple_bsonobj_comparator.h"
#include "mongo/db/keypattern.h"
#include "mongo/db/namespace_string.h"
#include "mongo/idl/basic_types.h"
#include "mongo/idl/idl_parser.h"
#include "mongo/rpc/op_msg.h"
#include "mongo/s/resharding/common_types_gen.h"
#include "mongo/s/shard_id.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/util/uuid.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {

/**
 * Resharding-related fields specific to donor shards.
 */
class TypeCollectionDonorFields {
public:
    static constexpr auto kRecipientShardIdsFieldName = "recipientShardIds"_sd;
    static constexpr auto kReshardingKeyFieldName = "reshardingKey"_sd;
    static constexpr auto kTempReshardingNssFieldName = "tempNs"_sd;

    TypeCollectionDonorFields();
    TypeCollectionDonorFields(mongo::NamespaceString tempReshardingNss, mongo::KeyPattern reshardingKey, std::vector<mongo::ShardId> recipientShardIds);

    static TypeCollectionDonorFields parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * The namespace of the temporary resharding collection that exists on recipient shards.
     */
    const mongo::NamespaceString& getTempReshardingNss() const { return _tempReshardingNss; }
    void setTempReshardingNss(mongo::NamespaceString value) & {  _tempReshardingNss = std::move(value); _hasTempReshardingNss = true; }

    const mongo::KeyPattern& getReshardingKey() const { return _reshardingKey; }
    void setReshardingKey(mongo::KeyPattern value) & {  _reshardingKey = std::move(value); _hasReshardingKey = true; }

    const std::vector<mongo::ShardId>& getRecipientShardIds() const& { return _recipientShardIds; }
    void getRecipientShardIds() && = delete;
    void setRecipientShardIds(std::vector<mongo::ShardId> value) & {  _recipientShardIds = std::move(value); _hasRecipientShardIds = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::NamespaceString _tempReshardingNss;
    mongo::KeyPattern _reshardingKey;
    std::vector<mongo::ShardId> _recipientShardIds;
    bool _hasTempReshardingNss : 1;
    bool _hasReshardingKey : 1;
    bool _hasRecipientShardIds : 1;
};

/**
 * Resharding-related fields specific to recipient shards.
 */
class TypeCollectionRecipientFields {
public:
    static constexpr auto kReshardingApproxCopySizeStructFieldName = "ReshardingApproxCopySize"_sd;
    static constexpr auto kApproxBytesToCopyFieldName = "approxBytesToCopy"_sd;
    static constexpr auto kApproxDocumentsToCopyFieldName = "approxDocumentsToCopy"_sd;
    static constexpr auto kCloneTimestampFieldName = "cloneTimestamp"_sd;
    static constexpr auto kDonorShardsFieldName = "donorShards"_sd;
    static constexpr auto kMinimumOperationDurationMillisFieldName = "minimumOperationDurationMillis"_sd;
    static constexpr auto kSourceNssFieldName = "sourceNs"_sd;
    static constexpr auto kSourceUUIDFieldName = "sourceUUID"_sd;

    TypeCollectionRecipientFields();
    TypeCollectionRecipientFields(std::vector<mongo::DonorShardFetchTimestamp> donorShards, mongo::UUID sourceUUID, mongo::NamespaceString sourceNss, std::int64_t minimumOperationDurationMillis);

    static TypeCollectionRecipientFields parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Not meant to be used directly. Only use internal fields.
     */
    const mongo::ReshardingApproxCopySize& getReshardingApproxCopySizeStruct() const { return _reshardingApproxCopySizeStruct; }
    mongo::ReshardingApproxCopySize& getReshardingApproxCopySizeStruct() { return _reshardingApproxCopySizeStruct; }
    void setReshardingApproxCopySizeStruct(mongo::ReshardingApproxCopySize value) & {  _reshardingApproxCopySizeStruct = std::move(value);  }

    const  boost::optional<std::int64_t> getApproxDocumentsToCopy() const { return _reshardingApproxCopySizeStruct.getApproxDocumentsToCopy(); }
    const  boost::optional<std::int64_t> getApproxBytesToCopy() const { return _reshardingApproxCopySizeStruct.getApproxBytesToCopy(); }
    /**
     * The timestamp for the snapshot read while cloning from the donors.
     */
    const boost::optional<mongo::Timestamp>& getCloneTimestamp() const& { return _cloneTimestamp; }
    void getCloneTimestamp() && = delete;
    void setCloneTimestamp(boost::optional<mongo::Timestamp> value) & {  _cloneTimestamp = std::move(value);  }

    /**
     * The list of donors to clone from.
     */
    const std::vector<mongo::DonorShardFetchTimestamp>& getDonorShards() const& { return _donorShards; }
    void getDonorShards() && = delete;
    void setDonorShards(std::vector<mongo::DonorShardFetchTimestamp> value) & {  _donorShards = std::move(value); _hasDonorShards = true; }

    /**
     * The UUID of the original collection being resharded.
     */
    const mongo::UUID& getSourceUUID() const { return _sourceUUID; }
    void setSourceUUID(mongo::UUID value) & {  _sourceUUID = std::move(value); _hasSourceUUID = true; }

    /**
     * The namespace of the collection being resharded.
     */
    const mongo::NamespaceString& getSourceNss() const { return _sourceNss; }
    void setSourceNss(mongo::NamespaceString value) & {  _sourceNss = std::move(value); _hasSourceNss = true; }

    std::int64_t getMinimumOperationDurationMillis() const { return _minimumOperationDurationMillis; }
    void setMinimumOperationDurationMillis(std::int64_t value) & {  _minimumOperationDurationMillis = std::move(value); _hasMinimumOperationDurationMillis = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::ReshardingApproxCopySize _reshardingApproxCopySizeStruct;
    boost::optional<mongo::Timestamp> _cloneTimestamp;
    std::vector<mongo::DonorShardFetchTimestamp> _donorShards;
    mongo::UUID _sourceUUID;
    mongo::NamespaceString _sourceNss;
    std::int64_t _minimumOperationDurationMillis;
    bool _hasDonorShards : 1;
    bool _hasSourceUUID : 1;
    bool _hasSourceNss : 1;
    bool _hasMinimumOperationDurationMillis : 1;
};

/**
 * Resharding-related fields meant to be stored in a config.collections document.
 */
class TypeCollectionReshardingFields {
public:
    static constexpr auto kDonorFieldsFieldName = "donorFields"_sd;
    static constexpr auto kRecipientFieldsFieldName = "recipientFields"_sd;
    static constexpr auto kReshardingUUIDFieldName = "uuid"_sd;
    static constexpr auto kStateFieldName = "state"_sd;
    static constexpr auto kUserCanceledFieldName = "userCanceled"_sd;

    TypeCollectionReshardingFields();
    TypeCollectionReshardingFields(mongo::UUID reshardingUUID);

    static TypeCollectionReshardingFields parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * A unique identifier for the resharding operation.
     */
    const mongo::UUID& getReshardingUUID() const { return _reshardingUUID; }
    void setReshardingUUID(mongo::UUID value) & {  _reshardingUUID = std::move(value); _hasReshardingUUID = true; }

    mongo::CoordinatorStateEnum getState() const { return _state; }
    void setState(mongo::CoordinatorStateEnum value) & {  _state = std::move(value);  }

    /**
     * If emplaced, indicates whether an abort originated from a user cancellation.
     */
    const boost::optional<bool> getUserCanceled() const& { return _userCanceled; }
    void getUserCanceled() && = delete;
    void setUserCanceled(boost::optional<bool> value) & {  _userCanceled = std::move(value);  }

    const boost::optional<mongo::TypeCollectionDonorFields>& getDonorFields() const& { return _donorFields; }
    void getDonorFields() && = delete;
    void setDonorFields(boost::optional<mongo::TypeCollectionDonorFields> value) & {  _donorFields = std::move(value);  }

    const boost::optional<mongo::TypeCollectionRecipientFields>& getRecipientFields() const& { return _recipientFields; }
    void getRecipientFields() && = delete;
    void setRecipientFields(boost::optional<mongo::TypeCollectionRecipientFields> value) & {  _recipientFields = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::UUID _reshardingUUID;
    mongo::CoordinatorStateEnum _state{mongo::CoordinatorStateEnum::kUnused};
    boost::optional<bool> _userCanceled;
    boost::optional<mongo::TypeCollectionDonorFields> _donorFields;
    boost::optional<mongo::TypeCollectionRecipientFields> _recipientFields;
    bool _hasReshardingUUID : 1;
};

}  // namespace mongo
