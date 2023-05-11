/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/commands/feature_compatibility_version_document_gen.h --output build/opt/mongo/db/commands/feature_compatibility_version_document_gen.cpp src/mongo/db/commands/feature_compatibility_version_document.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/commands/feature_compatibility_version_document_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData FeatureCompatibilityVersionDocument::k_idFieldName;
constexpr StringData FeatureCompatibilityVersionDocument::kChangeTimestampFieldName;
constexpr StringData FeatureCompatibilityVersionDocument::kPreviousVersionFieldName;
constexpr StringData FeatureCompatibilityVersionDocument::kTargetVersionFieldName;
constexpr StringData FeatureCompatibilityVersionDocument::kVersionFieldName;


FeatureCompatibilityVersionDocument::FeatureCompatibilityVersionDocument() : _version(mongo::idl::preparsedValue<decltype(_version)>()), _hasVersion(false) {
    // Used for initialization only
}
FeatureCompatibilityVersionDocument::FeatureCompatibilityVersionDocument(ServerGlobalParams::FeatureCompatibility::Version version) : _version(std::move(version)), _hasVersion(true) {
    // Used for initialization only
}

void FeatureCompatibilityVersionDocument::validatePreviousVersion(IDLParserErrorContext& ctxt, const ServerGlobalParams::FeatureCompatibility::Version value)
{
    uassertStatusOK(FeatureCompatibilityVersionParser::validatePreviousVersionField(value));
}

void FeatureCompatibilityVersionDocument::validatePreviousVersion(const ServerGlobalParams::FeatureCompatibility::Version value)
{
    uassertStatusOK(FeatureCompatibilityVersionParser::validatePreviousVersionField(value));
}


FeatureCompatibilityVersionDocument FeatureCompatibilityVersionDocument::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<FeatureCompatibilityVersionDocument>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void FeatureCompatibilityVersionDocument::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<5> usedFields;
    const size_t k_idBit = 0;
    const size_t kVersionBit = 1;
    const size_t kTargetVersionBit = 2;
    const size_t kPreviousVersionBit = 3;
    const size_t kChangeTimestampBit = 4;

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
        else if (fieldName == kVersionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kVersionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kVersionBit);

                _hasVersion = true;
                _version = FeatureCompatibilityVersionParser::parseVersion(element.valueStringData());
            }
        }
        else if (fieldName == kTargetVersionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kTargetVersionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTargetVersionBit);

                _targetVersion = FeatureCompatibilityVersionParser::parseVersion(element.valueStringData());
            }
        }
        else if (fieldName == kPreviousVersionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kPreviousVersionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPreviousVersionBit);

                {
                    auto value = FeatureCompatibilityVersionParser::parseVersion(element.valueStringData());
                    validatePreviousVersion(value);
                    _previousVersion = std::move(value);
                }
            }
        }
        else if (fieldName == kChangeTimestampFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, bsonTimestamp))) {
                if (MONGO_unlikely(usedFields[kChangeTimestampBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kChangeTimestampBit);

                _changeTimestamp = element.timestamp();
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[k_idBit]) {
            __id = "featureCompatibilityVersion";
        }
        if (!usedFields[kVersionBit]) {
            ctxt.throwMissingField(kVersionFieldName);
        }
    }

}


void FeatureCompatibilityVersionDocument::serialize(BSONObjBuilder* builder) const {
    invariant(_hasVersion);

    builder->append(k_idFieldName, __id);

    {
        builder->append(kVersionFieldName, ::mongo::FeatureCompatibilityVersionParser::serializeVersion(_version));
    }

    if (_targetVersion.is_initialized()) {
        builder->append(kTargetVersionFieldName, ::mongo::FeatureCompatibilityVersionParser::serializeVersion(_targetVersion.get()));
    }

    if (_previousVersion.is_initialized()) {
        builder->append(kPreviousVersionFieldName, ::mongo::FeatureCompatibilityVersionParser::serializeVersion(_previousVersion.get()));
    }

    if (_changeTimestamp.is_initialized()) {
        builder->append(kChangeTimestampFieldName, _changeTimestamp.get());
    }

}


BSONObj FeatureCompatibilityVersionDocument::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
