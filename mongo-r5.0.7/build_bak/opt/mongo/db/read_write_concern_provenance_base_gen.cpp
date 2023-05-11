/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/read_write_concern_provenance_base_gen.h --output build/opt/mongo/db/read_write_concern_provenance_base_gen.cpp src/mongo/db/read_write_concern_provenance_base.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/read_write_concern_provenance_base_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData ReadWriteConcernProvenanceBase::kSourceFieldName;


ReadWriteConcernProvenanceBase::ReadWriteConcernProvenanceBase()  {
    // Used for initialization only
}


ReadWriteConcernProvenanceBase ReadWriteConcernProvenanceBase::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ReadWriteConcernProvenanceBase>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ReadWriteConcernProvenanceBase::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kSourceBit = 0;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kSourceFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kSourceBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSourceBit);

                IDLParserErrorContext tempContext(kSourceFieldName, &ctxt);
                _source = ReadWriteConcernProvenanceSource_parse(tempContext, element.valueStringData());
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


void ReadWriteConcernProvenanceBase::serialize(BSONObjBuilder* builder) const {
    if (_source.is_initialized()) {
        builder->append(kSourceFieldName, ::mongo::ReadWriteConcernProvenanceSource_serializer(_source.get()));
    }

}


BSONObj ReadWriteConcernProvenanceBase::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
