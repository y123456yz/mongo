/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/pipeline/legacy_runtime_constants_gen.h --output build/opt/mongo/db/pipeline/legacy_runtime_constants_gen.cpp src/mongo/db/pipeline/legacy_runtime_constants.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/pipeline/legacy_runtime_constants_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData LegacyRuntimeConstants::kClusterTimeFieldName;
constexpr StringData LegacyRuntimeConstants::kIsMapReduceFieldName;
constexpr StringData LegacyRuntimeConstants::kJsScopeFieldName;
constexpr StringData LegacyRuntimeConstants::kLocalNowFieldName;


LegacyRuntimeConstants::LegacyRuntimeConstants() : _localNow(mongo::idl::preparsedValue<decltype(_localNow)>()), _clusterTime(mongo::idl::preparsedValue<decltype(_clusterTime)>()), _hasLocalNow(false), _hasClusterTime(false) {
    // Used for initialization only
}
LegacyRuntimeConstants::LegacyRuntimeConstants(mongo::Date_t localNow, mongo::Timestamp clusterTime) : _localNow(std::move(localNow)), _clusterTime(std::move(clusterTime)), _hasLocalNow(true), _hasClusterTime(true) {
    // Used for initialization only
}


LegacyRuntimeConstants LegacyRuntimeConstants::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<LegacyRuntimeConstants>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void LegacyRuntimeConstants::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<4> usedFields;
    const size_t kLocalNowBit = 0;
    const size_t kClusterTimeBit = 1;
    const size_t kJsScopeBit = 2;
    const size_t kIsMapReduceBit = 3;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kLocalNowFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Date))) {
                if (MONGO_unlikely(usedFields[kLocalNowBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLocalNowBit);

                _hasLocalNow = true;
                _localNow = element.date();
            }
        }
        else if (fieldName == kClusterTimeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, bsonTimestamp))) {
                if (MONGO_unlikely(usedFields[kClusterTimeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kClusterTimeBit);

                _hasClusterTime = true;
                _clusterTime = element.timestamp();
            }
        }
        else if (fieldName == kJsScopeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kJsScopeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kJsScopeBit);

                _jsScope = element.Obj();
            }
        }
        else if (fieldName == kIsMapReduceFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kIsMapReduceBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIsMapReduceBit);

                _isMapReduce = element.boolean();
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kLocalNowBit]) {
            ctxt.throwMissingField(kLocalNowFieldName);
        }
        if (!usedFields[kClusterTimeBit]) {
            ctxt.throwMissingField(kClusterTimeFieldName);
        }
    }

}


void LegacyRuntimeConstants::serialize(BSONObjBuilder* builder) const {
    invariant(_hasLocalNow && _hasClusterTime);

    builder->append(kLocalNowFieldName, _localNow);

    builder->append(kClusterTimeFieldName, _clusterTime);

    if (_jsScope.is_initialized()) {
        builder->append(kJsScopeFieldName, _jsScope.get());
    }

    if (_isMapReduce.is_initialized()) {
        builder->append(kIsMapReduceFieldName, _isMapReduce.get());
    }

}


BSONObj LegacyRuntimeConstants::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
