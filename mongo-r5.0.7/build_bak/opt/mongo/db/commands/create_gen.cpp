/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/commands/create_gen.h --output build/opt/mongo/db/commands/create_gen.cpp src/mongo/db/commands/create.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/commands/create_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData CreateCommandReply::kNoteFieldName;


CreateCommandReply::CreateCommandReply()  {
    // Used for initialization only
}


CreateCommandReply CreateCommandReply::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<CreateCommandReply>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void CreateCommandReply::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kNoteBit = 0;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kNoteFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kNoteBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNoteBit);

                _note = element.str();
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
    }

}


void CreateCommandReply::serialize(BSONObjBuilder* builder) const {
    if (_note.is_initialized()) {
        builder->append(kNoteFieldName, _note.get());
    }

}


BSONObj CreateCommandReply::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData CreateCommand::kAutoIndexIdFieldName;
constexpr StringData CreateCommand::kCappedFieldName;
constexpr StringData CreateCommand::kClusteredIndexFieldName;
constexpr StringData CreateCommand::kCollationFieldName;
constexpr StringData CreateCommand::kDbNameFieldName;
constexpr StringData CreateCommand::kExpireAfterSecondsFieldName;
constexpr StringData CreateCommand::kFlagsFieldName;
constexpr StringData CreateCommand::kIdIndexFieldName;
constexpr StringData CreateCommand::kIndexOptionDefaultsFieldName;
constexpr StringData CreateCommand::kMaxFieldName;
constexpr StringData CreateCommand::kPipelineFieldName;
constexpr StringData CreateCommand::kRecordPreImagesFieldName;
constexpr StringData CreateCommand::kSizeFieldName;
constexpr StringData CreateCommand::kStorageEngineFieldName;
constexpr StringData CreateCommand::kTempFieldName;
constexpr StringData CreateCommand::kTimeseriesFieldName;
constexpr StringData CreateCommand::kValidationActionFieldName;
constexpr StringData CreateCommand::kValidationLevelFieldName;
constexpr StringData CreateCommand::kValidatorFieldName;
constexpr StringData CreateCommand::kViewOnFieldName;
constexpr StringData CreateCommand::kCommandName;

mongo::AuthorizationContract CreateCommand::kAuthorizationContract = AuthorizationContract(std::initializer_list<AccessCheckEnum>{AccessCheckEnum::kShouldIgnoreAuthChecks,AccessCheckEnum::kGetSingleUser,AccessCheckEnum::kLookupUser}, std::initializer_list<Privilege>{Privilege(ResourcePattern::forAuthorizationContract(MatchTypeEnum::kMatchExactNamespace), ActionSet{ActionType::convertToCapped}),Privilege(ResourcePattern::forAuthorizationContract(MatchTypeEnum::kMatchExactNamespace), ActionSet{ActionType::createCollection}),Privilege(ResourcePattern::forAuthorizationContract(MatchTypeEnum::kMatchExactNamespace), ActionSet{ActionType::insert}),Privilege(ResourcePattern::forAuthorizationContract(MatchTypeEnum::kMatchExactNamespace), ActionSet{ActionType::find}),Privilege(ResourcePattern::forAuthorizationContract(MatchTypeEnum::kMatchExactNamespace), ActionSet{ActionType::remove,ActionType::update,ActionType::collStats,ActionType::indexStats,ActionType::planCacheRead})});

const std::vector<StringData> CreateCommand::_knownBSONFields {
    CreateCommand::kAutoIndexIdFieldName,
    CreateCommand::kCappedFieldName,
    CreateCommand::kClusteredIndexFieldName,
    CreateCommand::kCollationFieldName,
    CreateCommand::kExpireAfterSecondsFieldName,
    CreateCommand::kFlagsFieldName,
    CreateCommand::kIdIndexFieldName,
    CreateCommand::kIndexOptionDefaultsFieldName,
    CreateCommand::kMaxFieldName,
    CreateCommand::kPipelineFieldName,
    CreateCommand::kRecordPreImagesFieldName,
    CreateCommand::kSizeFieldName,
    CreateCommand::kStorageEngineFieldName,
    CreateCommand::kTempFieldName,
    CreateCommand::kTimeseriesFieldName,
    CreateCommand::kValidationActionFieldName,
    CreateCommand::kValidationLevelFieldName,
    CreateCommand::kValidatorFieldName,
    CreateCommand::kViewOnFieldName,
    CreateCommand::kCommandName,
};
const std::vector<StringData> CreateCommand::_knownOP_MSGFields {
    CreateCommand::kAutoIndexIdFieldName,
    CreateCommand::kCappedFieldName,
    CreateCommand::kClusteredIndexFieldName,
    CreateCommand::kCollationFieldName,
    CreateCommand::kDbNameFieldName,
    CreateCommand::kExpireAfterSecondsFieldName,
    CreateCommand::kFlagsFieldName,
    CreateCommand::kIdIndexFieldName,
    CreateCommand::kIndexOptionDefaultsFieldName,
    CreateCommand::kMaxFieldName,
    CreateCommand::kPipelineFieldName,
    CreateCommand::kRecordPreImagesFieldName,
    CreateCommand::kSizeFieldName,
    CreateCommand::kStorageEngineFieldName,
    CreateCommand::kTempFieldName,
    CreateCommand::kTimeseriesFieldName,
    CreateCommand::kValidationActionFieldName,
    CreateCommand::kValidationLevelFieldName,
    CreateCommand::kValidatorFieldName,
    CreateCommand::kViewOnFieldName,
    CreateCommand::kCommandName,
};

CreateCommand::CreateCommand(const NamespaceString nss) : _nss(std::move(nss)), _dbName(nss.db().toString()), _hasDbName(true) {
    // Used for initialization only
}

void CreateCommand::validateSize(IDLParserErrorContext& ctxt, const std::int64_t value)
{
    if (!(value >= 1)) {
        throwComparisonError<std::int64_t>(ctxt, "size", ">="_sd, value, 1);
    }
    if (!(value <= 1125899906842624.0)) {
        throwComparisonError<std::int64_t>(ctxt, "size", "<="_sd, value, 1125899906842624.0);
    }
}

void CreateCommand::validateSize(const std::int64_t value)
{
    if (!(value >= 1)) {
        throwComparisonError<std::int64_t>("size", ">="_sd, value, 1);
    }
    if (!(value <= 1125899906842624.0)) {
        throwComparisonError<std::int64_t>("size", "<="_sd, value, 1125899906842624.0);
    }
}

void CreateCommand::validateMax(IDLParserErrorContext& ctxt, const std::int64_t value)
{
    if (!(value < 2147483648.0)) {
        throwComparisonError<std::int64_t>(ctxt, "max", "<"_sd, value, 2147483648.0);
    }
}

void CreateCommand::validateMax(const std::int64_t value)
{
    if (!(value < 2147483648.0)) {
        throwComparisonError<std::int64_t>("max", "<"_sd, value, 2147483648.0);
    }
}

void CreateCommand::validateViewOn(IDLParserErrorContext& ctxt, const std::string& value)
{
    uassertStatusOK(create_command_validation::validateViewOnNotEmpty(value));
}

void CreateCommand::validateViewOn(const std::string& value)
{
    uassertStatusOK(create_command_validation::validateViewOnNotEmpty(value));
}


CreateCommand CreateCommand::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    NamespaceString localNS;
    CreateCommand object(localNS);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void CreateCommand::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<20> usedFields;
    const size_t kCappedBit = 0;
    const size_t kAutoIndexIdBit = 1;
    const size_t kIdIndexBit = 2;
    const size_t kSizeBit = 3;
    const size_t kMaxBit = 4;
    const size_t kStorageEngineBit = 5;
    const size_t kValidatorBit = 6;
    const size_t kValidationLevelBit = 7;
    const size_t kValidationActionBit = 8;
    const size_t kIndexOptionDefaultsBit = 9;
    const size_t kViewOnBit = 10;
    const size_t kPipelineBit = 11;
    const size_t kCollationBit = 12;
    const size_t kRecordPreImagesBit = 13;
    const size_t kTimeseriesBit = 14;
    const size_t kClusteredIndexBit = 15;
    const size_t kExpireAfterSecondsBit = 16;
    const size_t kTempBit = 17;
    const size_t kFlagsBit = 18;
    const size_t kDbNameBit = 19;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kCappedFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kCappedBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCappedBit);

                _capped = element.trueValue();
            }
        }
        else if (fieldName == kAutoIndexIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kAutoIndexIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAutoIndexIdBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                _autoIndexId = element.trueValue();
            }
        }
        else if (fieldName == kIdIndexFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kIdIndexBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIdIndexBit);

                _idIndex = element.Obj();
            }
        }
        else if (fieldName == kSizeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kSizeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSizeBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                {
                    auto value = element.safeNumberLong();
                    validateSize(value);
                    _size = std::move(value);
                }
            }
        }
        else if (fieldName == kMaxFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kMaxBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMaxBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                {
                    auto value = element.safeNumberLong();
                    validateMax(value);
                    _max = std::move(value);
                }
            }
        }
        else if (fieldName == kStorageEngineFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kStorageEngineBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStorageEngineBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                _storageEngine = element.Obj();
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
        else if (fieldName == kIndexOptionDefaultsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kIndexOptionDefaultsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIndexOptionDefaultsBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                IDLParserErrorContext tempContext(kIndexOptionDefaultsFieldName, &ctxt);
                const auto localObject = element.Obj();
                _indexOptionDefaults = mongo::IndexOptionDefaults::parse(tempContext, localObject);
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
        else if (fieldName == kCollationFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCollationBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollationBit);

                IDLParserErrorContext tempContext(kCollationFieldName, &ctxt);
                const auto localObject = element.Obj();
                _collation = mongo::Collation::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kRecordPreImagesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kRecordPreImagesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRecordPreImagesBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                _recordPreImages = element.trueValue();
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
                _timeseries = mongo::TimeseriesOptions::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kClusteredIndexFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kClusteredIndexBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kClusteredIndexBit);

                _clusteredIndex = element.trueValue();
            }
        }
        else if (fieldName == kExpireAfterSecondsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kExpireAfterSecondsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kExpireAfterSecondsBit);

                _expireAfterSeconds = element.safeNumberLong();
            }
        }
        else if (fieldName == kTempFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kTempBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTempBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                _temp = element.trueValue();
            }
        }
        else if (fieldName == kFlagsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kFlagsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kFlagsBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                _flags = element.safeNumberLong();
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
        if (!usedFields[kCappedBit]) {
            _capped = false;
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

CreateCommand CreateCommand::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    NamespaceString localNS;
    CreateCommand object(localNS);
    object.parseProtected(ctxt, request);
    return object;
}
void CreateCommand::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<20> usedFields;
    const size_t kCappedBit = 0;
    const size_t kAutoIndexIdBit = 1;
    const size_t kIdIndexBit = 2;
    const size_t kSizeBit = 3;
    const size_t kMaxBit = 4;
    const size_t kStorageEngineBit = 5;
    const size_t kValidatorBit = 6;
    const size_t kValidationLevelBit = 7;
    const size_t kValidationActionBit = 8;
    const size_t kIndexOptionDefaultsBit = 9;
    const size_t kViewOnBit = 10;
    const size_t kPipelineBit = 11;
    const size_t kCollationBit = 12;
    const size_t kRecordPreImagesBit = 13;
    const size_t kTimeseriesBit = 14;
    const size_t kClusteredIndexBit = 15;
    const size_t kExpireAfterSecondsBit = 16;
    const size_t kTempBit = 17;
    const size_t kFlagsBit = 18;
    const size_t kDbNameBit = 19;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kCappedFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kCappedBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCappedBit);

                _capped = element.trueValue();
            }
        }
        else if (fieldName == kAutoIndexIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kAutoIndexIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAutoIndexIdBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                _autoIndexId = element.trueValue();
            }
        }
        else if (fieldName == kIdIndexFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kIdIndexBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIdIndexBit);

                _idIndex = element.Obj();
            }
        }
        else if (fieldName == kSizeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kSizeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSizeBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                {
                    auto value = element.safeNumberLong();
                    validateSize(value);
                    _size = std::move(value);
                }
            }
        }
        else if (fieldName == kMaxFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kMaxBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMaxBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                {
                    auto value = element.safeNumberLong();
                    validateMax(value);
                    _max = std::move(value);
                }
            }
        }
        else if (fieldName == kStorageEngineFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kStorageEngineBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStorageEngineBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                _storageEngine = element.Obj();
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
        else if (fieldName == kIndexOptionDefaultsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kIndexOptionDefaultsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIndexOptionDefaultsBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                IDLParserErrorContext tempContext(kIndexOptionDefaultsFieldName, &ctxt);
                const auto localObject = element.Obj();
                _indexOptionDefaults = mongo::IndexOptionDefaults::parse(tempContext, localObject);
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
        else if (fieldName == kCollationFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCollationBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollationBit);

                IDLParserErrorContext tempContext(kCollationFieldName, &ctxt);
                const auto localObject = element.Obj();
                _collation = mongo::Collation::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kRecordPreImagesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kRecordPreImagesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRecordPreImagesBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                _recordPreImages = element.trueValue();
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
                _timeseries = mongo::TimeseriesOptions::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kClusteredIndexFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kClusteredIndexBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kClusteredIndexBit);

                _clusteredIndex = element.trueValue();
            }
        }
        else if (fieldName == kExpireAfterSecondsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kExpireAfterSecondsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kExpireAfterSecondsBit);

                _expireAfterSeconds = element.safeNumberLong();
            }
        }
        else if (fieldName == kTempFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kTempBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTempBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                _temp = element.trueValue();
            }
        }
        else if (fieldName == kFlagsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kFlagsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kFlagsBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                _flags = element.safeNumberLong();
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
        if (!usedFields[kCappedBit]) {
            _capped = false;
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

void CreateCommand::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    invariant(!_nss.isEmpty());
    builder->append("create"_sd, _nss.coll());

    builder->append(kCappedFieldName, _capped);

    if (_autoIndexId.is_initialized()) {
        builder->append(kAutoIndexIdFieldName, _autoIndexId.get());
    }

    if (_idIndex.is_initialized()) {
        builder->append(kIdIndexFieldName, _idIndex.get());
    }

    if (_size.is_initialized()) {
        builder->append(kSizeFieldName, _size.get());
    }

    if (_max.is_initialized()) {
        builder->append(kMaxFieldName, _max.get());
    }

    if (_storageEngine.is_initialized()) {
        builder->append(kStorageEngineFieldName, _storageEngine.get());
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

    if (_indexOptionDefaults.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kIndexOptionDefaultsFieldName));
        _indexOptionDefaults.get().serialize(&subObjBuilder);
    }

    if (_viewOn.is_initialized()) {
        builder->append(kViewOnFieldName, _viewOn.get());
    }

    if (_pipeline.is_initialized()) {
        builder->append(kPipelineFieldName, _pipeline.get());
    }

    if (_collation.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kCollationFieldName));
        _collation.get().serialize(&subObjBuilder);
    }

    if (_recordPreImages.is_initialized()) {
        builder->append(kRecordPreImagesFieldName, _recordPreImages.get());
    }

    if (_timeseries.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kTimeseriesFieldName));
        _timeseries.get().serialize(&subObjBuilder);
    }

    if (_clusteredIndex.is_initialized()) {
        builder->append(kClusteredIndexFieldName, _clusteredIndex.get());
    }

    if (_expireAfterSeconds.is_initialized()) {
        builder->append(kExpireAfterSecondsFieldName, _expireAfterSeconds.get());
    }

    if (_temp.is_initialized()) {
        builder->append(kTempFieldName, _temp.get());
    }

    if (_flags.is_initialized()) {
        builder->append(kFlagsFieldName, _flags.get());
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest CreateCommand::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        invariant(!_nss.isEmpty());
        builder->append("create"_sd, _nss.coll());

        builder->append(kCappedFieldName, _capped);

        if (_autoIndexId.is_initialized()) {
            builder->append(kAutoIndexIdFieldName, _autoIndexId.get());
        }

        if (_idIndex.is_initialized()) {
            builder->append(kIdIndexFieldName, _idIndex.get());
        }

        if (_size.is_initialized()) {
            builder->append(kSizeFieldName, _size.get());
        }

        if (_max.is_initialized()) {
            builder->append(kMaxFieldName, _max.get());
        }

        if (_storageEngine.is_initialized()) {
            builder->append(kStorageEngineFieldName, _storageEngine.get());
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

        if (_indexOptionDefaults.is_initialized()) {
            BSONObjBuilder subObjBuilder(builder->subobjStart(kIndexOptionDefaultsFieldName));
            _indexOptionDefaults.get().serialize(&subObjBuilder);
        }

        if (_viewOn.is_initialized()) {
            builder->append(kViewOnFieldName, _viewOn.get());
        }

        if (_pipeline.is_initialized()) {
            builder->append(kPipelineFieldName, _pipeline.get());
        }

        if (_collation.is_initialized()) {
            BSONObjBuilder subObjBuilder(builder->subobjStart(kCollationFieldName));
            _collation.get().serialize(&subObjBuilder);
        }

        if (_recordPreImages.is_initialized()) {
            builder->append(kRecordPreImagesFieldName, _recordPreImages.get());
        }

        if (_timeseries.is_initialized()) {
            BSONObjBuilder subObjBuilder(builder->subobjStart(kTimeseriesFieldName));
            _timeseries.get().serialize(&subObjBuilder);
        }

        if (_clusteredIndex.is_initialized()) {
            builder->append(kClusteredIndexFieldName, _clusteredIndex.get());
        }

        if (_expireAfterSeconds.is_initialized()) {
            builder->append(kExpireAfterSecondsFieldName, _expireAfterSeconds.get());
        }

        if (_temp.is_initialized()) {
            builder->append(kTempFieldName, _temp.get());
        }

        if (_flags.is_initialized()) {
            builder->append(kFlagsFieldName, _flags.get());
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj CreateCommand::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
