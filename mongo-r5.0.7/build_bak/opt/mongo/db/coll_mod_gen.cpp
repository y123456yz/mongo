/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/coll_mod_gen.h --output build/opt/mongo/db/coll_mod_gen.cpp src/mongo/db/coll_mod.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/coll_mod_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData CollModIndex::kExpireAfterSecondsFieldName;
constexpr StringData CollModIndex::kHiddenFieldName;
constexpr StringData CollModIndex::kKeyPatternFieldName;
constexpr StringData CollModIndex::kNameFieldName;


CollModIndex::CollModIndex()  {
    // Used for initialization only
}


CollModIndex CollModIndex::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<CollModIndex>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void CollModIndex::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<4> usedFields;
    const size_t kNameBit = 0;
    const size_t kKeyPatternBit = 1;
    const size_t kExpireAfterSecondsBit = 2;
    const size_t kHiddenBit = 3;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kNameFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kNameBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNameBit);

                _name = element.str();
            }
        }
        else if (fieldName == kKeyPatternFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kKeyPatternBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kKeyPatternBit);

                _keyPattern = element.Obj();
            }
        }
        else if (fieldName == kExpireAfterSecondsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kExpireAfterSecondsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kExpireAfterSecondsBit);

                _expireAfterSeconds = element.safeNumberInt();
            }
        }
        else if (fieldName == kHiddenFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kHiddenBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kHiddenBit);

                _hidden = element.trueValue();
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
    }

}


void CollModIndex::serialize(BSONObjBuilder* builder) const {
    if (_name.is_initialized()) {
        builder->append(kNameFieldName, _name.get());
    }

    if (_keyPattern.is_initialized()) {
        builder->append(kKeyPatternFieldName, _keyPattern.get());
    }

    if (_expireAfterSeconds.is_initialized()) {
        builder->append(kExpireAfterSecondsFieldName, _expireAfterSeconds.get());
    }

    if (_hidden.is_initialized()) {
        builder->append(kHiddenFieldName, _hidden.get());
    }

}


BSONObj CollModIndex::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData CollModReply::kExpireAfterSeconds_newFieldName;
constexpr StringData CollModReply::kExpireAfterSeconds_oldFieldName;
constexpr StringData CollModReply::kHidden_newFieldName;
constexpr StringData CollModReply::kHidden_oldFieldName;


CollModReply::CollModReply()  {
    // Used for initialization only
}


CollModReply CollModReply::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<CollModReply>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void CollModReply::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<4> usedFields;
    const size_t kExpireAfterSeconds_oldBit = 0;
    const size_t kExpireAfterSeconds_newBit = 1;
    const size_t kHidden_oldBit = 2;
    const size_t kHidden_newBit = 3;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kExpireAfterSeconds_oldFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kExpireAfterSeconds_oldBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kExpireAfterSeconds_oldBit);

                _expireAfterSeconds_old = element.safeNumberInt();
            }
        }
        else if (fieldName == kExpireAfterSeconds_newFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kExpireAfterSeconds_newBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kExpireAfterSeconds_newBit);

                _expireAfterSeconds_new = element.safeNumberInt();
            }
        }
        else if (fieldName == kHidden_oldFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kHidden_oldBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kHidden_oldBit);

                _hidden_old = element.trueValue();
            }
        }
        else if (fieldName == kHidden_newFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kHidden_newBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kHidden_newBit);

                _hidden_new = element.trueValue();
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
    }

}


void CollModReply::serialize(BSONObjBuilder* builder) const {
    if (_expireAfterSeconds_old.is_initialized()) {
        builder->append(kExpireAfterSeconds_oldFieldName, _expireAfterSeconds_old.get());
    }

    if (_expireAfterSeconds_new.is_initialized()) {
        builder->append(kExpireAfterSeconds_newFieldName, _expireAfterSeconds_new.get());
    }

    if (_hidden_old.is_initialized()) {
        builder->append(kHidden_oldFieldName, _hidden_old.get());
    }

    if (_hidden_new.is_initialized()) {
        builder->append(kHidden_newFieldName, _hidden_new.get());
    }

}


BSONObj CollModReply::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData CollModTimeseries::kGranularityFieldName;


CollModTimeseries::CollModTimeseries()  {
    // Used for initialization only
}


CollModTimeseries CollModTimeseries::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<CollModTimeseries>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void CollModTimeseries::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kGranularityBit = 0;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kGranularityFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kGranularityBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kGranularityBit);

                IDLParserErrorContext tempContext(kGranularityFieldName, &ctxt);
                _granularity = BucketGranularity_parse(tempContext, element.valueStringData());
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
    }

}


void CollModTimeseries::serialize(BSONObjBuilder* builder) const {
    if (_granularity.is_initialized()) {
        builder->append(kGranularityFieldName, ::mongo::BucketGranularity_serializer(_granularity.get()));
    }

}


BSONObj CollModTimeseries::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData CollMod::kDbNameFieldName;
constexpr StringData CollMod::kExpireAfterSecondsFieldName;
constexpr StringData CollMod::kIndexFieldName;
constexpr StringData CollMod::kIsTimeseriesNamespaceFieldName;
constexpr StringData CollMod::kPipelineFieldName;
constexpr StringData CollMod::kRecordPreImagesFieldName;
constexpr StringData CollMod::kTimeseriesFieldName;
constexpr StringData CollMod::kValidationActionFieldName;
constexpr StringData CollMod::kValidationLevelFieldName;
constexpr StringData CollMod::kValidatorFieldName;
constexpr StringData CollMod::kViewOnFieldName;
constexpr StringData CollMod::kCommandName;

mongo::AuthorizationContract CollMod::kAuthorizationContract = AuthorizationContract(std::initializer_list<AccessCheckEnum>{AccessCheckEnum::kShouldIgnoreAuthChecks}, std::initializer_list<Privilege>{Privilege(ResourcePattern::forAuthorizationContract(MatchTypeEnum::kMatchExactNamespace), ActionSet{ActionType::collMod}),Privilege(ResourcePattern::forAuthorizationContract(MatchTypeEnum::kMatchExactNamespace), ActionSet{ActionType::find})});

const std::vector<StringData> CollMod::_knownBSONFields {
    CollMod::kExpireAfterSecondsFieldName,
    CollMod::kIndexFieldName,
    CollMod::kIsTimeseriesNamespaceFieldName,
    CollMod::kPipelineFieldName,
    CollMod::kRecordPreImagesFieldName,
    CollMod::kTimeseriesFieldName,
    CollMod::kValidationActionFieldName,
    CollMod::kValidationLevelFieldName,
    CollMod::kValidatorFieldName,
    CollMod::kViewOnFieldName,
    CollMod::kCommandName,
};
const std::vector<StringData> CollMod::_knownOP_MSGFields {
    CollMod::kDbNameFieldName,
    CollMod::kExpireAfterSecondsFieldName,
    CollMod::kIndexFieldName,
    CollMod::kIsTimeseriesNamespaceFieldName,
    CollMod::kPipelineFieldName,
    CollMod::kRecordPreImagesFieldName,
    CollMod::kTimeseriesFieldName,
    CollMod::kValidationActionFieldName,
    CollMod::kValidationLevelFieldName,
    CollMod::kValidatorFieldName,
    CollMod::kViewOnFieldName,
    CollMod::kCommandName,
};

CollMod::CollMod(const NamespaceString nss) : _nss(std::move(nss)), _dbName(nss.db().toString()), _hasDbName(true) {
    // Used for initialization only
}

void CollMod::validateViewOn(IDLParserErrorContext& ctxt, const std::string& value)
{
    uassertStatusOK(create_command_validation::validateViewOnNotEmpty(value));
}

void CollMod::validateViewOn(const std::string& value)
{
    uassertStatusOK(create_command_validation::validateViewOnNotEmpty(value));
}


CollMod CollMod::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    NamespaceString localNS;
    CollMod object(localNS);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void CollMod::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<11> usedFields;
    const size_t kIndexBit = 0;
    const size_t kValidatorBit = 1;
    const size_t kValidationLevelBit = 2;
    const size_t kValidationActionBit = 3;
    const size_t kViewOnBit = 4;
    const size_t kPipelineBit = 5;
    const size_t kRecordPreImagesBit = 6;
    const size_t kExpireAfterSecondsBit = 7;
    const size_t kTimeseriesBit = 8;
    const size_t kIsTimeseriesNamespaceBit = 9;
    const size_t kDbNameBit = 10;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kIndexFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kIndexBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIndexBit);

                IDLParserErrorContext tempContext(kIndexFieldName, &ctxt);
                const auto localObject = element.Obj();
                _index = mongo::CollModIndex::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kValidatorFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kValidatorBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kValidatorBit);

                _validator = element.Obj();
            }
        }
        else if (fieldName == kValidationLevelFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kValidationLevelBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kValidationLevelBit);

                IDLParserErrorContext tempContext(kValidationLevelFieldName, &ctxt);
                _validationLevel = ValidationLevel_parse(tempContext, element.valueStringData());
            }
        }
        else if (fieldName == kValidationActionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kValidationActionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kValidationActionBit);

                IDLParserErrorContext tempContext(kValidationActionFieldName, &ctxt);
                _validationAction = ValidationAction_parse(tempContext, element.valueStringData());
            }
        }
        else if (fieldName == kViewOnFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kViewOnBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kViewOnBit);

                {
                    auto value = element.str();
                    validateViewOn(value);
                    _viewOn = std::move(value);
                }
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
        else if (fieldName == kRecordPreImagesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kRecordPreImagesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRecordPreImagesBit);

                _recordPreImages = element.trueValue();
            }
        }
        else if (fieldName == kExpireAfterSecondsFieldName) {
            if (MONGO_unlikely(usedFields[kExpireAfterSecondsBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kExpireAfterSecondsBit);


            const BSONType variantType = element.type();
            switch (variantType) {
            case String:
            {
                _expireAfterSeconds = element.str();
                break;
            }
            case NumberLong:
            {
                _expireAfterSeconds = element.safeNumberLong();
                break;
            }
            case NumberInt:
            {
                _expireAfterSeconds = element.safeNumberLong();
                break;
            }
            case NumberDecimal:
            {
                _expireAfterSeconds = element.safeNumberLong();
                break;
            }
            case NumberDouble:
            {
                _expireAfterSeconds = element.safeNumberLong();
                break;
            }
            default:
                ctxt.throwBadType(element, {BSONType::String, BSONType::NumberLong});
                break;
            }
        }
        else if (fieldName == kTimeseriesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kTimeseriesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTimeseriesBit);

                IDLParserErrorContext tempContext(kTimeseriesFieldName, &ctxt);
                const auto localObject = element.Obj();
                _timeseries = mongo::CollModTimeseries::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kIsTimeseriesNamespaceFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kIsTimeseriesNamespaceBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIsTimeseriesNamespaceBit);

                _isTimeseriesNamespace = element.boolean();
            }
        }
        else if (fieldName == kDbNameFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kDbNameBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDbNameBit);

                _hasDbName = true;
                _dbName = element.str();
            }
        }
        else {
            if (!mongo::isGenericArgument(fieldName)) {
                ctxt.throwUnknownField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

CollMod CollMod::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    NamespaceString localNS;
    CollMod object(localNS);
    object.parseProtected(ctxt, request);
    return object;
}
void CollMod::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<11> usedFields;
    const size_t kIndexBit = 0;
    const size_t kValidatorBit = 1;
    const size_t kValidationLevelBit = 2;
    const size_t kValidationActionBit = 3;
    const size_t kViewOnBit = 4;
    const size_t kPipelineBit = 5;
    const size_t kRecordPreImagesBit = 6;
    const size_t kExpireAfterSecondsBit = 7;
    const size_t kTimeseriesBit = 8;
    const size_t kIsTimeseriesNamespaceBit = 9;
    const size_t kDbNameBit = 10;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kIndexFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kIndexBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIndexBit);

                IDLParserErrorContext tempContext(kIndexFieldName, &ctxt);
                const auto localObject = element.Obj();
                _index = mongo::CollModIndex::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kValidatorFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kValidatorBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kValidatorBit);

                _validator = element.Obj();
            }
        }
        else if (fieldName == kValidationLevelFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kValidationLevelBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kValidationLevelBit);

                IDLParserErrorContext tempContext(kValidationLevelFieldName, &ctxt);
                _validationLevel = ValidationLevel_parse(tempContext, element.valueStringData());
            }
        }
        else if (fieldName == kValidationActionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kValidationActionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kValidationActionBit);

                IDLParserErrorContext tempContext(kValidationActionFieldName, &ctxt);
                _validationAction = ValidationAction_parse(tempContext, element.valueStringData());
            }
        }
        else if (fieldName == kViewOnFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kViewOnBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kViewOnBit);

                {
                    auto value = element.str();
                    validateViewOn(value);
                    _viewOn = std::move(value);
                }
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
        else if (fieldName == kRecordPreImagesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kRecordPreImagesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRecordPreImagesBit);

                _recordPreImages = element.trueValue();
            }
        }
        else if (fieldName == kExpireAfterSecondsFieldName) {
            if (MONGO_unlikely(usedFields[kExpireAfterSecondsBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kExpireAfterSecondsBit);


            const BSONType variantType = element.type();
            switch (variantType) {
            case String:
            {
                _expireAfterSeconds = element.str();
                break;
            }
            case NumberLong:
            {
                _expireAfterSeconds = element.safeNumberLong();
                break;
            }
            case NumberInt:
            {
                _expireAfterSeconds = element.safeNumberLong();
                break;
            }
            case NumberDecimal:
            {
                _expireAfterSeconds = element.safeNumberLong();
                break;
            }
            case NumberDouble:
            {
                _expireAfterSeconds = element.safeNumberLong();
                break;
            }
            default:
                ctxt.throwBadType(element, {BSONType::String, BSONType::NumberLong});
                break;
            }
        }
        else if (fieldName == kTimeseriesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kTimeseriesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTimeseriesBit);

                IDLParserErrorContext tempContext(kTimeseriesFieldName, &ctxt);
                const auto localObject = element.Obj();
                _timeseries = mongo::CollModTimeseries::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kIsTimeseriesNamespaceFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kIsTimeseriesNamespaceBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIsTimeseriesNamespaceBit);

                _isTimeseriesNamespace = element.boolean();
            }
        }
        else if (fieldName == kDbNameFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kDbNameBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDbNameBit);

                _hasDbName = true;
                _dbName = element.str();
            }
        }
        else {
            if (!mongo::isGenericArgument(fieldName)) {
                ctxt.throwUnknownField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

void CollMod::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    invariant(!_nss.isEmpty());
    builder->append("collMod"_sd, _nss.coll());

    if (_index.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kIndexFieldName));
        _index.get().serialize(&subObjBuilder);
    }

    if (_validator.is_initialized()) {
        builder->append(kValidatorFieldName, _validator.get());
    }

    if (_validationLevel.is_initialized()) {
        builder->append(kValidationLevelFieldName, ::mongo::ValidationLevel_serializer(_validationLevel.get()));
    }

    if (_validationAction.is_initialized()) {
        builder->append(kValidationActionFieldName, ::mongo::ValidationAction_serializer(_validationAction.get()));
    }

    if (_viewOn.is_initialized()) {
        builder->append(kViewOnFieldName, _viewOn.get());
    }

    if (_pipeline.is_initialized()) {
        builder->append(kPipelineFieldName, _pipeline.get());
    }

    if (_recordPreImages.is_initialized()) {
        builder->append(kRecordPreImagesFieldName, _recordPreImages.get());
    }

    if (_expireAfterSeconds.is_initialized()) {
        stdx::visit([builder](auto&& arg) {
            idl::idlSerialize(builder, kExpireAfterSecondsFieldName, arg);
        }, _expireAfterSeconds.get());
    }

    if (_timeseries.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kTimeseriesFieldName));
        _timeseries.get().serialize(&subObjBuilder);
    }

    if (_isTimeseriesNamespace.is_initialized()) {
        builder->append(kIsTimeseriesNamespaceFieldName, _isTimeseriesNamespace.get());
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest CollMod::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        invariant(!_nss.isEmpty());
        builder->append("collMod"_sd, _nss.coll());

        if (_index.is_initialized()) {
            BSONObjBuilder subObjBuilder(builder->subobjStart(kIndexFieldName));
            _index.get().serialize(&subObjBuilder);
        }

        if (_validator.is_initialized()) {
            builder->append(kValidatorFieldName, _validator.get());
        }

        if (_validationLevel.is_initialized()) {
            builder->append(kValidationLevelFieldName, ::mongo::ValidationLevel_serializer(_validationLevel.get()));
        }

        if (_validationAction.is_initialized()) {
            builder->append(kValidationActionFieldName, ::mongo::ValidationAction_serializer(_validationAction.get()));
        }

        if (_viewOn.is_initialized()) {
            builder->append(kViewOnFieldName, _viewOn.get());
        }

        if (_pipeline.is_initialized()) {
            builder->append(kPipelineFieldName, _pipeline.get());
        }

        if (_recordPreImages.is_initialized()) {
            builder->append(kRecordPreImagesFieldName, _recordPreImages.get());
        }

        if (_expireAfterSeconds.is_initialized()) {
            stdx::visit([builder](auto&& arg) {
                idl::idlSerialize(builder, kExpireAfterSecondsFieldName, arg);
            }, _expireAfterSeconds.get());
        }

        if (_timeseries.is_initialized()) {
            BSONObjBuilder subObjBuilder(builder->subobjStart(kTimeseriesFieldName));
            _timeseries.get().serialize(&subObjBuilder);
        }

        if (_isTimeseriesNamespace.is_initialized()) {
            builder->append(kIsTimeseriesNamespaceFieldName, _isTimeseriesNamespace.get());
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj CollMod::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
