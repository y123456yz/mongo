/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/rpc/write_concern_error_gen.h --output build/opt/mongo/rpc/write_concern_error_gen.cpp src/mongo/rpc/write_concern_error.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/rpc/write_concern_error_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData WriteConcernError::kCodeFieldName;
constexpr StringData WriteConcernError::kCodeNameFieldName;
constexpr StringData WriteConcernError::kErrInfoFieldName;
constexpr StringData WriteConcernError::kErrmsgFieldName;


WriteConcernError::WriteConcernError() : _code(mongo::idl::preparsedValue<decltype(_code)>()), _errmsg(mongo::idl::preparsedValue<decltype(_errmsg)>()), _hasCode(false), _hasErrmsg(false) {
    // Used for initialization only
}
WriteConcernError::WriteConcernError(std::int32_t code, std::string errmsg) : _code(std::move(code)), _errmsg(std::move(errmsg)), _hasCode(true), _hasErrmsg(true) {
    // Used for initialization only
}


WriteConcernError WriteConcernError::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<WriteConcernError>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void WriteConcernError::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<4> usedFields;
    const size_t kCodeBit = 0;
    const size_t kCodeNameBit = 1;
    const size_t kErrmsgBit = 2;
    const size_t kErrInfoBit = 3;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kCodeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberInt))) {
                if (MONGO_unlikely(usedFields[kCodeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCodeBit);

                _hasCode = true;
                _code = element._numberInt();
            }
        }
        else if (fieldName == kCodeNameFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kCodeNameBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCodeNameBit);

                _codeName = element.str();
            }
        }
        else if (fieldName == kErrmsgFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kErrmsgBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kErrmsgBit);

                _hasErrmsg = true;
                _errmsg = element.str();
            }
        }
        else if (fieldName == kErrInfoFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kErrInfoBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kErrInfoBit);

                _errInfo = element.Obj();
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kCodeBit]) {
            ctxt.throwMissingField(kCodeFieldName);
        }
        if (!usedFields[kErrmsgBit]) {
            ctxt.throwMissingField(kErrmsgFieldName);
        }
    }

}


void WriteConcernError::serialize(BSONObjBuilder* builder) const {
    invariant(_hasCode && _hasErrmsg);

    builder->append(kCodeFieldName, _code);

    if (_codeName.is_initialized()) {
        builder->append(kCodeNameFieldName, _codeName.get());
    }

    builder->append(kErrmsgFieldName, _errmsg);

    if (_errInfo.is_initialized()) {
        builder->append(kErrInfoFieldName, _errInfo.get());
    }

}


BSONObj WriteConcernError::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
