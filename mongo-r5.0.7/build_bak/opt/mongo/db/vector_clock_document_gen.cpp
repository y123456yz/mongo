/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/vector_clock_document_gen.h --output build/opt/mongo/db/vector_clock_document_gen.cpp src/mongo/db/vector_clock_document.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/vector_clock_document_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData VectorClockDocument::k_idFieldName;
constexpr StringData VectorClockDocument::kConfigTimeFieldName;
constexpr StringData VectorClockDocument::kTopologyTimeFieldName;


VectorClockDocument::VectorClockDocument()  {
    // Used for initialization only
}


VectorClockDocument VectorClockDocument::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<VectorClockDocument>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void VectorClockDocument::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<3> usedFields;
    const size_t k_idBit = 0;
    const size_t kConfigTimeBit = 1;
    const size_t kTopologyTimeBit = 2;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == k_idFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[k_idBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(k_idBit);

                __id = element.str();
            }
        }
        else if (fieldName == kConfigTimeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, bsonTimestamp))) {
                if (MONGO_unlikely(usedFields[kConfigTimeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kConfigTimeBit);

                _configTime = element.timestamp();
            }
        }
        else if (fieldName == kTopologyTimeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, bsonTimestamp))) {
                if (MONGO_unlikely(usedFields[kTopologyTimeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTopologyTimeBit);

                _topologyTime = element.timestamp();
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
        if (!usedFields[k_idBit]) {
            __id = "vectorClockState";
        }
        if (!usedFields[kConfigTimeBit]) {
            _configTime = Timestamp(0, 1);
        }
        if (!usedFields[kTopologyTimeBit]) {
            _topologyTime = Timestamp(0, 1);
        }
    }

}


void VectorClockDocument::serialize(BSONObjBuilder* builder) const {
    builder->append(k_idFieldName, __id);

    builder->append(kConfigTimeFieldName, _configTime);

    builder->append(kTopologyTimeFieldName, _topologyTime);

}


BSONObj VectorClockDocument::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
