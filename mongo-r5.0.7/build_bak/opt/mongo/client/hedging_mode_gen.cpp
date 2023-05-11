/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/client/hedging_mode_gen.h --output build/opt/mongo/client/hedging_mode_gen.cpp src/mongo/client/hedging_mode.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/client/hedging_mode_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData HedgingMode::kEnabledFieldName;


HedgingMode::HedgingMode()  {
    // Used for initialization only
}


HedgingMode HedgingMode::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<HedgingMode>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void HedgingMode::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kEnabledBit = 0;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kEnabledFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kEnabledBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kEnabledBit);

                _enabled = element.boolean();
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kEnabledBit]) {
            _enabled = true;
        }
    }

}


void HedgingMode::serialize(BSONObjBuilder* builder) const {
    builder->append(kEnabledFieldName, _enabled);

}


BSONObj HedgingMode::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
