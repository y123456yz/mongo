/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/read_write_concern_defaults_gen.h --output build/opt/mongo/db/read_write_concern_defaults_gen.cpp src/mongo/db/read_write_concern_defaults.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/read_write_concern_defaults_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

/**
 * The source of the default write concern
 */
namespace  {
constexpr StringData kDefaultWriteConcernSource_kImplicit = "implicit"_sd;
constexpr StringData kDefaultWriteConcernSource_kGlobal = "global"_sd;
}  // namespace 

DefaultWriteConcernSourceEnum DefaultWriteConcernSource_parse(const IDLParserErrorContext& ctxt, StringData value) {
    if (value == kDefaultWriteConcernSource_kImplicit) {
        return DefaultWriteConcernSourceEnum::kImplicit;
    }
    if (value == kDefaultWriteConcernSource_kGlobal) {
        return DefaultWriteConcernSourceEnum::kGlobal;
    }
    ctxt.throwBadEnumValue(value);
}

StringData DefaultWriteConcernSource_serializer(DefaultWriteConcernSourceEnum value) {
    if (value == DefaultWriteConcernSourceEnum::kImplicit) {
        return kDefaultWriteConcernSource_kImplicit;
    }
    if (value == DefaultWriteConcernSourceEnum::kGlobal) {
        return kDefaultWriteConcernSource_kGlobal;
    }
    MONGO_UNREACHABLE;
    return StringData();
}

/**
 * The source of the default read concern
 */
namespace  {
constexpr StringData kDefaultReadConcernSource_kImplicit = "implicit"_sd;
constexpr StringData kDefaultReadConcernSource_kGlobal = "global"_sd;
}  // namespace 

DefaultReadConcernSourceEnum DefaultReadConcernSource_parse(const IDLParserErrorContext& ctxt, StringData value) {
    if (value == kDefaultReadConcernSource_kImplicit) {
        return DefaultReadConcernSourceEnum::kImplicit;
    }
    if (value == kDefaultReadConcernSource_kGlobal) {
        return DefaultReadConcernSourceEnum::kGlobal;
    }
    ctxt.throwBadEnumValue(value);
}

StringData DefaultReadConcernSource_serializer(DefaultReadConcernSourceEnum value) {
    if (value == DefaultReadConcernSourceEnum::kImplicit) {
        return kDefaultReadConcernSource_kImplicit;
    }
    if (value == DefaultReadConcernSourceEnum::kGlobal) {
        return kDefaultReadConcernSource_kGlobal;
    }
    MONGO_UNREACHABLE;
    return StringData();
}

constexpr StringData RWConcernDefault::kDefaultReadConcernFieldName;
constexpr StringData RWConcernDefault::kDefaultReadConcernSourceFieldName;
constexpr StringData RWConcernDefault::kDefaultWriteConcernFieldName;
constexpr StringData RWConcernDefault::kDefaultWriteConcernSourceFieldName;
constexpr StringData RWConcernDefault::kUpdateOpTimeFieldName;
constexpr StringData RWConcernDefault::kUpdateWallClockTimeFieldName;


RWConcernDefault::RWConcernDefault()  {
    // Used for initialization only
}


RWConcernDefault RWConcernDefault::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<RWConcernDefault>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void RWConcernDefault::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<6> usedFields;
    const size_t kDefaultReadConcernBit = 0;
    const size_t kDefaultWriteConcernBit = 1;
    const size_t kUpdateOpTimeBit = 2;
    const size_t kUpdateWallClockTimeBit = 3;
    const size_t kDefaultWriteConcernSourceBit = 4;
    const size_t kDefaultReadConcernSourceBit = 5;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kDefaultReadConcernFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kDefaultReadConcernBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDefaultReadConcernBit);

                const BSONObj localObject = element.Obj();
                _defaultReadConcern = repl::ReadConcernArgs::fromBSONThrows(localObject);
            }
        }
        else if (fieldName == kDefaultWriteConcernFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kDefaultWriteConcernBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDefaultWriteConcernBit);

                const BSONObj localObject = element.Obj();
                _defaultWriteConcern = WriteConcernOptions::deserializerForIDL(localObject);
            }
        }
        else if (fieldName == kUpdateOpTimeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, bsonTimestamp))) {
                if (MONGO_unlikely(usedFields[kUpdateOpTimeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUpdateOpTimeBit);

                _updateOpTime = element.timestamp();
            }
        }
        else if (fieldName == kUpdateWallClockTimeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Date))) {
                if (MONGO_unlikely(usedFields[kUpdateWallClockTimeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUpdateWallClockTimeBit);

                _updateWallClockTime = element.date();
            }
        }
        else if (fieldName == kDefaultWriteConcernSourceFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kDefaultWriteConcernSourceBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDefaultWriteConcernSourceBit);

                IDLParserErrorContext tempContext(kDefaultWriteConcernSourceFieldName, &ctxt);
                _defaultWriteConcernSource = DefaultWriteConcernSource_parse(tempContext, element.valueStringData());
            }
        }
        else if (fieldName == kDefaultReadConcernSourceFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kDefaultReadConcernSourceBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDefaultReadConcernSourceBit);

                IDLParserErrorContext tempContext(kDefaultReadConcernSourceFieldName, &ctxt);
                _defaultReadConcernSource = DefaultReadConcernSource_parse(tempContext, element.valueStringData());
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


void RWConcernDefault::serialize(BSONObjBuilder* builder) const {
    if (_defaultReadConcern.is_initialized()) {
        const BSONObj localObject = _defaultReadConcern.get().toBSONInner();
        builder->append(kDefaultReadConcernFieldName, localObject);
    }

    if (_defaultWriteConcern.is_initialized()) {
        const BSONObj localObject = _defaultWriteConcern.get().toBSON();
        builder->append(kDefaultWriteConcernFieldName, localObject);
    }

    if (_updateOpTime.is_initialized()) {
        builder->append(kUpdateOpTimeFieldName, _updateOpTime.get());
    }

    if (_updateWallClockTime.is_initialized()) {
        builder->append(kUpdateWallClockTimeFieldName, _updateWallClockTime.get());
    }

    if (_defaultWriteConcernSource.is_initialized()) {
        builder->append(kDefaultWriteConcernSourceFieldName, ::mongo::DefaultWriteConcernSource_serializer(_defaultWriteConcernSource.get()));
    }

    if (_defaultReadConcernSource.is_initialized()) {
        builder->append(kDefaultReadConcernSourceFieldName, ::mongo::DefaultReadConcernSource_serializer(_defaultReadConcernSource.get()));
    }

}


BSONObj RWConcernDefault::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
