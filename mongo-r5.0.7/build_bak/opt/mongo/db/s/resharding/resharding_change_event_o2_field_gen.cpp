/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/s/resharding/resharding_change_event_o2_field_gen.h --output build/opt/mongo/db/s/resharding/resharding_change_event_o2_field_gen.cpp src/mongo/db/s/resharding/resharding_change_event_o2_field.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/s/resharding/resharding_change_event_o2_field_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

/**
 * Types of possible change events during a resharding operation.
 */
namespace  {
constexpr StringData kReshardingChangeEvent_kReshardBegin = "reshardBegin"_sd;
constexpr StringData kReshardingChangeEvent_kReshardDoneCatchUp = "reshardDoneCatchUp"_sd;
}  // namespace 

ReshardingChangeEventEnum ReshardingChangeEvent_parse(const IDLParserErrorContext& ctxt, StringData value) {
    if (value == kReshardingChangeEvent_kReshardBegin) {
        return ReshardingChangeEventEnum::kReshardBegin;
    }
    if (value == kReshardingChangeEvent_kReshardDoneCatchUp) {
        return ReshardingChangeEventEnum::kReshardDoneCatchUp;
    }
    ctxt.throwBadEnumValue(value);
}

StringData ReshardingChangeEvent_serializer(ReshardingChangeEventEnum value) {
    if (value == ReshardingChangeEventEnum::kReshardBegin) {
        return kReshardingChangeEvent_kReshardBegin;
    }
    if (value == ReshardingChangeEventEnum::kReshardDoneCatchUp) {
        return kReshardingChangeEvent_kReshardDoneCatchUp;
    }
    MONGO_UNREACHABLE;
    return StringData();
}

constexpr StringData ReshardingChangeEventO2Field::kReshardingUUIDFieldName;
constexpr StringData ReshardingChangeEventO2Field::kTypeFieldName;


ReshardingChangeEventO2Field::ReshardingChangeEventO2Field() : _reshardingUUID(mongo::idl::preparsedValue<decltype(_reshardingUUID)>()), _type(mongo::idl::preparsedValue<decltype(_type)>()), _hasReshardingUUID(false), _hasType(false) {
    // Used for initialization only
}
ReshardingChangeEventO2Field::ReshardingChangeEventO2Field(mongo::UUID reshardingUUID, mongo::ReshardingChangeEventEnum type) : _reshardingUUID(std::move(reshardingUUID)), _type(std::move(type)), _hasReshardingUUID(true), _hasType(true) {
    // Used for initialization only
}


ReshardingChangeEventO2Field ReshardingChangeEventO2Field::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ReshardingChangeEventO2Field>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ReshardingChangeEventO2Field::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kReshardingUUIDBit = 0;
    const size_t kTypeBit = 1;
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
        else if (fieldName == kTypeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kTypeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTypeBit);

                _hasType = true;
                IDLParserErrorContext tempContext(kTypeFieldName, &ctxt);
                _type = ReshardingChangeEvent_parse(tempContext, element.valueStringData());
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
        if (!usedFields[kTypeBit]) {
            ctxt.throwMissingField(kTypeFieldName);
        }
    }

}


void ReshardingChangeEventO2Field::serialize(BSONObjBuilder* builder) const {
    invariant(_hasReshardingUUID && _hasType);

    {
        ConstDataRange tempCDR = _reshardingUUID.toCDR();
        builder->append(kReshardingUUIDFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    {
        builder->append(kTypeFieldName, ::mongo::ReshardingChangeEvent_serializer(_type));
    }

}


BSONObj ReshardingChangeEventO2Field::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
