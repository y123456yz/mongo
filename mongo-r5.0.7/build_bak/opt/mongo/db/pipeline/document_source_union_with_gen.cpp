/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/pipeline/document_source_union_with_gen.h --output build/opt/mongo/db/pipeline/document_source_union_with_gen.cpp src/mongo/db/pipeline/document_source_union_with.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/pipeline/document_source_union_with_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData UnionWithSpec::kCollFieldName;
constexpr StringData UnionWithSpec::kPipelineFieldName;


UnionWithSpec::UnionWithSpec()  {
    // Used for initialization only
}


UnionWithSpec UnionWithSpec::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<UnionWithSpec>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void UnionWithSpec::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kCollBit = 0;
    const size_t kPipelineBit = 1;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kCollFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kCollBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollBit);

                _coll = element.str();
            }
        }
        else if (fieldName == kPipelineFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kPipelineBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPipelineBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kPipelineFieldName, &ctxt);
            std::vector<mongo::BSONObj> values;

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
                        values.emplace_back(arrayElement.Obj());
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _pipeline = std::move(values);
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
    }

}


void UnionWithSpec::serialize(BSONObjBuilder* builder) const {
    if (_coll.is_initialized()) {
        builder->append(kCollFieldName, _coll.get());
    }

    if (_pipeline.is_initialized()) {
        builder->append(kPipelineFieldName, _pipeline.get());
    }

}


BSONObj UnionWithSpec::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
