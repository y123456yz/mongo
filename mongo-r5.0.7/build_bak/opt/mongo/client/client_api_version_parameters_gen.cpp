/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/client/client_api_version_parameters_gen.h --output build/opt/mongo/client/client_api_version_parameters_gen.cpp src/mongo/client/client_api_version_parameters.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/client/client_api_version_parameters_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData ClientAPIVersionParameters::kDeprecationErrorsFieldName;
constexpr StringData ClientAPIVersionParameters::kStrictFieldName;
constexpr StringData ClientAPIVersionParameters::kVersionFieldName;


ClientAPIVersionParameters::ClientAPIVersionParameters()  {
    // Used for initialization only
}


ClientAPIVersionParameters ClientAPIVersionParameters::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ClientAPIVersionParameters>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ClientAPIVersionParameters::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<3> usedFields;
    const size_t kVersionBit = 0;
    const size_t kStrictBit = 1;
    const size_t kDeprecationErrorsBit = 2;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kVersionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kVersionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kVersionBit);

                _version = element.str();
            }
        }
        else if (fieldName == kStrictFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kStrictBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStrictBit);

                _strict = element.boolean();
            }
        }
        else if (fieldName == kDeprecationErrorsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kDeprecationErrorsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDeprecationErrorsBit);

                _deprecationErrors = element.boolean();
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
    }

}


void ClientAPIVersionParameters::serialize(BSONObjBuilder* builder) const {
    if (_version.is_initialized()) {
        builder->append(kVersionFieldName, _version.get());
    }

    if (_strict.is_initialized()) {
        builder->append(kStrictFieldName, _strict.get());
    }

    if (_deprecationErrors.is_initialized()) {
        builder->append(kDeprecationErrorsFieldName, _deprecationErrors.get());
    }

}


BSONObj ClientAPIVersionParameters::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
