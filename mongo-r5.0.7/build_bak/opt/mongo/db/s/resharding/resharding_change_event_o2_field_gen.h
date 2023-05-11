/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/s/resharding/resharding_change_event_o2_field_gen.h --output build/opt/mongo/db/s/resharding/resharding_change_event_o2_field_gen.cpp src/mongo/db/s/resharding/resharding_change_event_o2_field.idl
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
#include "mongo/db/namespace_string.h"
#include "mongo/idl/basic_types.h"
#include "mongo/idl/basic_types_gen.h"
#include "mongo/idl/idl_parser.h"
#include "mongo/rpc/op_msg.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/util/uuid.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {

/**
 * Types of possible change events during a resharding operation.
 */
enum class ReshardingChangeEventEnum : std::int32_t {
    kReshardBegin ,
    kReshardDoneCatchUp ,
};
static constexpr uint32_t kNumReshardingChangeEventEnum = 2;

ReshardingChangeEventEnum ReshardingChangeEvent_parse(const IDLParserErrorContext& ctxt, StringData value);
StringData ReshardingChangeEvent_serializer(ReshardingChangeEventEnum value);

/**
 * Represents a change that occurs during a resharding operation. Stored in the o2 field of an oplog entry.
 */
class ReshardingChangeEventO2Field {
public:
    static constexpr auto kReshardingUUIDFieldName = "reshardingUUID"_sd;
    static constexpr auto kTypeFieldName = "type"_sd;

    ReshardingChangeEventO2Field();
    ReshardingChangeEventO2Field(mongo::UUID reshardingUUID, mongo::ReshardingChangeEventEnum type);

    static ReshardingChangeEventO2Field parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * The UUID for this resharding operation.
     */
    const mongo::UUID& getReshardingUUID() const { return _reshardingUUID; }
    void setReshardingUUID(mongo::UUID value) & {  _reshardingUUID = std::move(value); _hasReshardingUUID = true; }

    /**
     * The type of change that occured during the resharding operation.
     */
    mongo::ReshardingChangeEventEnum getType() const { return _type; }
    void setType(mongo::ReshardingChangeEventEnum value) & {  _type = std::move(value); _hasType = true; }


    friend bool operator==(const ReshardingChangeEventO2Field& left, const ReshardingChangeEventO2Field& right) {
        return left._reshardingUUID == right._reshardingUUID && left._type == right._type;
    }

    friend bool operator!=(const ReshardingChangeEventO2Field& left, const ReshardingChangeEventO2Field& right) {
        return left._reshardingUUID != right._reshardingUUID || left._type != right._type;
    }
    friend bool operator<(const ReshardingChangeEventO2Field& left, const ReshardingChangeEventO2Field& right) {
        return left._reshardingUUID < right._reshardingUUID || (!(right._reshardingUUID < left._reshardingUUID) && (left._type < right._type));
    }
    friend bool operator>(const ReshardingChangeEventO2Field& left, const ReshardingChangeEventO2Field& right) {
        return right < left;
    }
    friend bool operator<=(const ReshardingChangeEventO2Field& left, const ReshardingChangeEventO2Field& right) {
        return !(right < left);
    }
    friend bool operator>=(const ReshardingChangeEventO2Field& left, const ReshardingChangeEventO2Field& right) {
        return !(left < right);
    }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::UUID _reshardingUUID;
    mongo::ReshardingChangeEventEnum _type;
    bool _hasReshardingUUID : 1;
    bool _hasType : 1;
};

}  // namespace mongo
