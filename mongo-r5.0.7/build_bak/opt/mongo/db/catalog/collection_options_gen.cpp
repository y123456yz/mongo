/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/catalog/collection_options_gen.h --output build/opt/mongo/db/catalog/collection_options_gen.cpp src/mongo/db/catalog/collection_options.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/catalog/collection_options_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

/**
 * Determines how strictly MongoDB applies the validation rules to existing documents during an update.
 */
namespace  {
constexpr StringData kValidationLevel_off = "off"_sd;
constexpr StringData kValidationLevel_strict = "strict"_sd;
constexpr StringData kValidationLevel_moderate = "moderate"_sd;
}  // namespace 

ValidationLevelEnum ValidationLevel_parse(const IDLParserErrorContext& ctxt, StringData value) {
    if (value == kValidationLevel_off) {
        return ValidationLevelEnum::off;
    }
    if (value == kValidationLevel_strict) {
        return ValidationLevelEnum::strict;
    }
    if (value == kValidationLevel_moderate) {
        return ValidationLevelEnum::moderate;
    }
    ctxt.throwBadEnumValue(value);
}

StringData ValidationLevel_serializer(ValidationLevelEnum value) {
    if (value == ValidationLevelEnum::off) {
        return kValidationLevel_off;
    }
    if (value == ValidationLevelEnum::strict) {
        return kValidationLevel_strict;
    }
    if (value == ValidationLevelEnum::moderate) {
        return kValidationLevel_moderate;
    }
    MONGO_UNREACHABLE;
    return StringData();
}

/**
 * Determines whether to error on invalid documents or just warn about the violations but allow invalid documents to be inserted.
 */
namespace  {
constexpr StringData kValidationAction_error = "error"_sd;
constexpr StringData kValidationAction_warn = "warn"_sd;
}  // namespace 

ValidationActionEnum ValidationAction_parse(const IDLParserErrorContext& ctxt, StringData value) {
    if (value == kValidationAction_error) {
        return ValidationActionEnum::error;
    }
    if (value == kValidationAction_warn) {
        return ValidationActionEnum::warn;
    }
    ctxt.throwBadEnumValue(value);
}

StringData ValidationAction_serializer(ValidationActionEnum value) {
    if (value == ValidationActionEnum::error) {
        return kValidationAction_error;
    }
    if (value == ValidationActionEnum::warn) {
        return kValidationAction_warn;
    }
    MONGO_UNREACHABLE;
    return StringData();
}

constexpr StringData IndexOptionDefaults::kStorageEngineFieldName;


IndexOptionDefaults::IndexOptionDefaults()  {
    // Used for initialization only
}

void IndexOptionDefaults::validateStorageEngine(IDLParserErrorContext& ctxt, const mongo::BSONObj& value)
{
    uassertStatusOK(collection_options_validation::validateStorageEngineOptions(value));
}

void IndexOptionDefaults::validateStorageEngine(const mongo::BSONObj& value)
{
    uassertStatusOK(collection_options_validation::validateStorageEngineOptions(value));
}


IndexOptionDefaults IndexOptionDefaults::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<IndexOptionDefaults>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void IndexOptionDefaults::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kStorageEngineBit = 0;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kStorageEngineFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kStorageEngineBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStorageEngineBit);

                const BSONObj localObject = element.Obj();
                {
                    auto value = BSONObj::getOwned(localObject);
                    validateStorageEngine(value);
                    _storageEngine = std::move(value);
                }
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
    }

}


void IndexOptionDefaults::serialize(BSONObjBuilder* builder) const {
    if (_storageEngine.is_initialized()) {
        builder->append(kStorageEngineFieldName, _storageEngine.get());
    }

}


BSONObj IndexOptionDefaults::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
