/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/pipeline/document_source_set_window_fields_gen.h --output build/opt/mongo/db/pipeline/document_source_set_window_fields_gen.cpp src/mongo/db/pipeline/document_source_set_window_fields.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/pipeline/document_source_set_window_fields_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData SetWindowFieldsSpec::kOutputFieldName;
constexpr StringData SetWindowFieldsSpec::kPartitionByFieldName;
constexpr StringData SetWindowFieldsSpec::kSortByFieldName;


SetWindowFieldsSpec::SetWindowFieldsSpec() : _output(mongo::idl::preparsedValue<decltype(_output)>()), _hasOutput(false) {
    // Used for initialization only
}
SetWindowFieldsSpec::SetWindowFieldsSpec(mongo::BSONObj output) : _output(std::move(output)), _hasOutput(true) {
    // Used for initialization only
}


SetWindowFieldsSpec SetWindowFieldsSpec::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<SetWindowFieldsSpec>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void SetWindowFieldsSpec::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<3> usedFields;
    const size_t kPartitionByBit = 0;
    const size_t kSortByBit = 1;
    const size_t kOutputBit = 2;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kPartitionByFieldName) {
            if (MONGO_unlikely(usedFields[kPartitionByBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kPartitionByBit);

            _partitionBy = IDLAnyType::parseFromBSON(element);
        }
        else if (fieldName == kSortByFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kSortByBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSortByBit);

                _sortBy = element.Obj();
            }
        }
        else if (fieldName == kOutputFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kOutputBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kOutputBit);

                _hasOutput = true;
                _output = element.Obj();
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kOutputBit]) {
            ctxt.throwMissingField(kOutputFieldName);
        }
    }

}


void SetWindowFieldsSpec::serialize(BSONObjBuilder* builder) const {
    invariant(_hasOutput);

    if (_partitionBy.is_initialized()) {
        _partitionBy.get().serializeToBSON(kPartitionByFieldName, builder);
    }

    if (_sortBy.is_initialized()) {
        builder->append(kSortByFieldName, _sortBy.get());
    }

    builder->append(kOutputFieldName, _output);

}


BSONObj SetWindowFieldsSpec::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
