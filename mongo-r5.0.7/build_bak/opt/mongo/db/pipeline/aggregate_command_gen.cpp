/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/pipeline/aggregate_command_gen.h --output build/opt/mongo/db/pipeline/aggregate_command_gen.cpp src/mongo/db/pipeline/aggregate_command.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/pipeline/aggregate_command_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData AggregateCommandRequest::kAllowDiskUseFieldName;
constexpr StringData AggregateCommandRequest::kBypassDocumentValidationFieldName;
constexpr StringData AggregateCommandRequest::kCollationFieldName;
constexpr StringData AggregateCommandRequest::kCollectionUUIDFieldName;
constexpr StringData AggregateCommandRequest::kCursorFieldName;
constexpr StringData AggregateCommandRequest::kDbNameFieldName;
constexpr StringData AggregateCommandRequest::kExchangeFieldName;
constexpr StringData AggregateCommandRequest::kExplainFieldName;
constexpr StringData AggregateCommandRequest::kFromMongosFieldName;
constexpr StringData AggregateCommandRequest::kHintFieldName;
constexpr StringData AggregateCommandRequest::kIsMapReduceCommandFieldName;
constexpr StringData AggregateCommandRequest::kLegacyRuntimeConstantsFieldName;
constexpr StringData AggregateCommandRequest::kLetFieldName;
constexpr StringData AggregateCommandRequest::kMaxTimeMSFieldName;
constexpr StringData AggregateCommandRequest::kNeedsMergeFieldName;
constexpr StringData AggregateCommandRequest::kPipelineFieldName;
constexpr StringData AggregateCommandRequest::kReadConcernFieldName;
constexpr StringData AggregateCommandRequest::kRequestReshardingResumeTokenFieldName;
constexpr StringData AggregateCommandRequest::kUnwrappedReadPrefFieldName;
constexpr StringData AggregateCommandRequest::kUse44SortKeysFieldName;
constexpr StringData AggregateCommandRequest::kUseNewUpsertFieldName;
constexpr StringData AggregateCommandRequest::kWriteConcernFieldName;
constexpr StringData AggregateCommandRequest::kCommandName;

mongo::AuthorizationContract AggregateCommandRequest::kAuthorizationContract = AuthorizationContract(std::initializer_list<AccessCheckEnum>{AccessCheckEnum::kIsCoauthorizedWithClient,AccessCheckEnum::kIsCoauthorizedWith,AccessCheckEnum::kShouldIgnoreAuthChecks,AccessCheckEnum::kGetSingleUser,AccessCheckEnum::kLookupUser}, std::initializer_list<Privilege>{Privilege(ResourcePattern::forAuthorizationContract(MatchTypeEnum::kMatchExactNamespace), ActionSet{ActionType::find,ActionType::insert,ActionType::update,ActionType::remove}),Privilege(ResourcePattern::forAuthorizationContract(MatchTypeEnum::kMatchExactNamespace), ActionSet{ActionType::planCacheRead}),Privilege(ResourcePattern::forAuthorizationContract(MatchTypeEnum::kMatchExactNamespace), ActionSet{ActionType::changeStream}),Privilege(ResourcePattern::forAuthorizationContract(MatchTypeEnum::kMatchDatabaseName), ActionSet{ActionType::changeStream}),Privilege(ResourcePattern::forAuthorizationContract(MatchTypeEnum::kMatchAnyNormalResource), ActionSet{ActionType::changeStream}),Privilege(ResourcePattern::forAuthorizationContract(MatchTypeEnum::kMatchDatabaseName), ActionSet{ActionType::find}),Privilege(ResourcePattern::forAuthorizationContract(MatchTypeEnum::kMatchAnyNormalResource), ActionSet{ActionType::find}),Privilege(ResourcePattern::forAuthorizationContract(MatchTypeEnum::kMatchClusterResource), ActionSet{ActionType::internal}),Privilege(ResourcePattern::forAuthorizationContract(MatchTypeEnum::kMatchExactNamespace), ActionSet{ActionType::collStats}),Privilege(ResourcePattern::forAuthorizationContract(MatchTypeEnum::kMatchClusterResource), ActionSet{ActionType::inprog}),Privilege(ResourcePattern::forAuthorizationContract(MatchTypeEnum::kMatchExactNamespace), ActionSet{ActionType::indexStats}),Privilege(ResourcePattern::forAuthorizationContract(MatchTypeEnum::kMatchAnyNormalResource), ActionSet{ActionType::listCachedAndActiveUsers}),Privilege(ResourcePattern::forAuthorizationContract(MatchTypeEnum::kMatchClusterResource), ActionSet{ActionType::listSessions}),Privilege(ResourcePattern::forAuthorizationContract(MatchTypeEnum::kMatchExactNamespace), ActionSet{ActionType::bypassDocumentValidation}),Privilege(ResourcePattern::forAuthorizationContract(MatchTypeEnum::kMatchClusterResource), ActionSet{ActionType::operationMetrics}),Privilege(ResourcePattern::forAuthorizationContract(MatchTypeEnum::kMatchClusterResource), ActionSet{ActionType::fsync})});

const std::vector<StringData> AggregateCommandRequest::_knownBSONFields {
    AggregateCommandRequest::kAllowDiskUseFieldName,
    AggregateCommandRequest::kBypassDocumentValidationFieldName,
    AggregateCommandRequest::kCollationFieldName,
    AggregateCommandRequest::kCollectionUUIDFieldName,
    AggregateCommandRequest::kCursorFieldName,
    AggregateCommandRequest::kExchangeFieldName,
    AggregateCommandRequest::kExplainFieldName,
    AggregateCommandRequest::kFromMongosFieldName,
    AggregateCommandRequest::kHintFieldName,
    AggregateCommandRequest::kIsMapReduceCommandFieldName,
    AggregateCommandRequest::kLegacyRuntimeConstantsFieldName,
    AggregateCommandRequest::kLetFieldName,
    AggregateCommandRequest::kMaxTimeMSFieldName,
    AggregateCommandRequest::kNeedsMergeFieldName,
    AggregateCommandRequest::kPipelineFieldName,
    AggregateCommandRequest::kReadConcernFieldName,
    AggregateCommandRequest::kRequestReshardingResumeTokenFieldName,
    AggregateCommandRequest::kUnwrappedReadPrefFieldName,
    AggregateCommandRequest::kUse44SortKeysFieldName,
    AggregateCommandRequest::kUseNewUpsertFieldName,
    AggregateCommandRequest::kWriteConcernFieldName,
    AggregateCommandRequest::kCommandName,
};
const std::vector<StringData> AggregateCommandRequest::_knownOP_MSGFields {
    AggregateCommandRequest::kAllowDiskUseFieldName,
    AggregateCommandRequest::kBypassDocumentValidationFieldName,
    AggregateCommandRequest::kCollationFieldName,
    AggregateCommandRequest::kCollectionUUIDFieldName,
    AggregateCommandRequest::kCursorFieldName,
    AggregateCommandRequest::kDbNameFieldName,
    AggregateCommandRequest::kExchangeFieldName,
    AggregateCommandRequest::kExplainFieldName,
    AggregateCommandRequest::kFromMongosFieldName,
    AggregateCommandRequest::kHintFieldName,
    AggregateCommandRequest::kIsMapReduceCommandFieldName,
    AggregateCommandRequest::kLegacyRuntimeConstantsFieldName,
    AggregateCommandRequest::kLetFieldName,
    AggregateCommandRequest::kMaxTimeMSFieldName,
    AggregateCommandRequest::kNeedsMergeFieldName,
    AggregateCommandRequest::kPipelineFieldName,
    AggregateCommandRequest::kReadConcernFieldName,
    AggregateCommandRequest::kRequestReshardingResumeTokenFieldName,
    AggregateCommandRequest::kUnwrappedReadPrefFieldName,
    AggregateCommandRequest::kUse44SortKeysFieldName,
    AggregateCommandRequest::kUseNewUpsertFieldName,
    AggregateCommandRequest::kWriteConcernFieldName,
    AggregateCommandRequest::kCommandName,
};

AggregateCommandRequest::AggregateCommandRequest(const NamespaceString nss) : _nss(std::move(nss)), _pipeline(mongo::idl::preparsedValue<decltype(_pipeline)>()), _dbName(nss.db().toString()), _hasPipeline(false), _hasDbName(true) {
    // Used for initialization only
}
AggregateCommandRequest::AggregateCommandRequest(const NamespaceString nss, std::vector<mongo::BSONObj> pipeline) : _nss(std::move(nss)), _pipeline(std::move(pipeline)), _dbName(nss.db().toString()), _hasPipeline(true), _hasDbName(true) {
    // Used for initialization only
}

void AggregateCommandRequest::validateMaxTimeMS(IDLParserErrorContext& ctxt, const std::int64_t value)
{
    if (!(value >= 0)) {
        throwComparisonError<std::int64_t>(ctxt, "maxTimeMS", ">="_sd, value, 0);
    }
}

void AggregateCommandRequest::validateMaxTimeMS(const std::int64_t value)
{
    if (!(value >= 0)) {
        throwComparisonError<std::int64_t>("maxTimeMS", ">="_sd, value, 0);
    }
}


AggregateCommandRequest AggregateCommandRequest::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    NamespaceString localNS;
    AggregateCommandRequest object(localNS);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void AggregateCommandRequest::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<22> usedFields;
    const size_t kPipelineBit = 0;
    const size_t kExplainBit = 1;
    const size_t kAllowDiskUseBit = 2;
    const size_t kCursorBit = 3;
    const size_t kMaxTimeMSBit = 4;
    const size_t kBypassDocumentValidationBit = 5;
    const size_t kReadConcernBit = 6;
    const size_t kCollationBit = 7;
    const size_t kHintBit = 8;
    const size_t kWriteConcernBit = 9;
    const size_t kLetBit = 10;
    const size_t kNeedsMergeBit = 11;
    const size_t kFromMongosBit = 12;
    const size_t kUnwrappedReadPrefBit = 13;
    const size_t kRequestReshardingResumeTokenBit = 14;
    const size_t kExchangeBit = 15;
    const size_t kLegacyRuntimeConstantsBit = 16;
    const size_t kIsMapReduceCommandBit = 17;
    const size_t kCollectionUUIDBit = 18;
    const size_t kUse44SortKeysBit = 19;
    const size_t kUseNewUpsertBit = 20;
    const size_t kDbNameBit = 21;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kPipelineFieldName) {
            if (MONGO_unlikely(usedFields[kPipelineBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kPipelineBit);

            _hasPipeline = true;
            _pipeline = parsePipelineFromBSON(element);
        }
        else if (fieldName == kExplainFieldName) {
            if (MONGO_unlikely(usedFields[kExplainBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kExplainBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            _explain = parseExplainModeFromBSON(element);
        }
        else if (fieldName == kAllowDiskUseFieldName) {
            if (MONGO_unlikely(usedFields[kAllowDiskUseBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kAllowDiskUseBit);

            _allowDiskUse = OptionalBool::parseFromBSON(element);
        }
        else if (fieldName == kCursorFieldName) {
            if (MONGO_unlikely(usedFields[kCursorBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kCursorBit);

            _cursor = parseAggregateCursorFromBSON(element);
        }
        else if (fieldName == kMaxTimeMSFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kMaxTimeMSBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMaxTimeMSBit);

                {
                    auto value = element.safeNumberLong();
                    validateMaxTimeMS(value);
                    _maxTimeMS = std::move(value);
                }
            }
        }
        else if (fieldName == kBypassDocumentValidationFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kBypassDocumentValidationBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kBypassDocumentValidationBit);

                _bypassDocumentValidation = element.trueValue();
            }
        }
        else if (fieldName == kReadConcernFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kReadConcernBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kReadConcernBit);

                const BSONObj localObject = element.Obj();
                _readConcern = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kCollationFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCollationBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollationBit);

                const BSONObj localObject = element.Obj();
                _collation = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kHintFieldName) {
            if (MONGO_unlikely(usedFields[kHintBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kHintBit);

            _hint = parseHint(element);
        }
        else if (fieldName == kWriteConcernFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kWriteConcernBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kWriteConcernBit);

                const BSONObj localObject = element.Obj();
                _writeConcern = WriteConcernOptions::deserializerForIDL(localObject);
            }
        }
        else if (fieldName == kLetFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kLetBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLetBit);

                const BSONObj localObject = element.Obj();
                _let = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kNeedsMergeFieldName) {
            if (MONGO_unlikely(usedFields[kNeedsMergeBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kNeedsMergeBit);

            _needsMerge = OptionalBool::parseFromBSON(element);
        }
        else if (fieldName == kFromMongosFieldName) {
            if (MONGO_unlikely(usedFields[kFromMongosBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kFromMongosBit);

            _fromMongos = OptionalBool::parseFromBSON(element);
        }
        else if (fieldName == kUnwrappedReadPrefFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kUnwrappedReadPrefBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUnwrappedReadPrefBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                const BSONObj localObject = element.Obj();
                _unwrappedReadPref = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kRequestReshardingResumeTokenFieldName) {
            if (MONGO_unlikely(usedFields[kRequestReshardingResumeTokenBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kRequestReshardingResumeTokenBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            _requestReshardingResumeToken = OptionalBool::parseFromBSON(element);
        }
        else if (fieldName == kExchangeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kExchangeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kExchangeBit);

                IDLParserErrorContext tempContext(kExchangeFieldName, &ctxt);
                const auto localObject = element.Obj();
                _exchange = mongo::ExchangeSpec::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kLegacyRuntimeConstantsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kLegacyRuntimeConstantsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLegacyRuntimeConstantsBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                IDLParserErrorContext tempContext(kLegacyRuntimeConstantsFieldName, &ctxt);
                const auto localObject = element.Obj();
                _legacyRuntimeConstants = mongo::LegacyRuntimeConstants::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kIsMapReduceCommandFieldName) {
            if (MONGO_unlikely(usedFields[kIsMapReduceCommandBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kIsMapReduceCommandBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            _isMapReduceCommand = OptionalBool::parseFromBSON(element);
        }
        else if (fieldName == kCollectionUUIDFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kCollectionUUIDBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollectionUUIDBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                _collectionUUID = UUID(uassertStatusOK(UUID::parse(element)));
            }
        }
        else if (fieldName == kUse44SortKeysFieldName) {
            if (MONGO_unlikely(usedFields[kUse44SortKeysBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kUse44SortKeysBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            // ignore field
        }
        else if (fieldName == kUseNewUpsertFieldName) {
            if (MONGO_unlikely(usedFields[kUseNewUpsertBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kUseNewUpsertBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            // ignore field
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
        if (!usedFields[kPipelineBit]) {
            ctxt.throwMissingField(kPipelineFieldName);
        }
        if (!usedFields[kAllowDiskUseBit]) {
            _allowDiskUse = mongo::OptionalBool();
        }
        if (!usedFields[kCursorBit]) {
            _cursor = SimpleCursorOptions();
        }
        if (!usedFields[kNeedsMergeBit]) {
            _needsMerge = mongo::OptionalBool();
        }
        if (!usedFields[kFromMongosBit]) {
            _fromMongos = mongo::OptionalBool();
        }
        if (!usedFields[kRequestReshardingResumeTokenBit]) {
            _requestReshardingResumeToken = mongo::OptionalBool();
        }
        if (!usedFields[kIsMapReduceCommandBit]) {
            _isMapReduceCommand = mongo::OptionalBool();
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, true);
}

AggregateCommandRequest AggregateCommandRequest::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    NamespaceString localNS;
    AggregateCommandRequest object(localNS);
    object.parseProtected(ctxt, request);
    return object;
}
void AggregateCommandRequest::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<22> usedFields;
    const size_t kPipelineBit = 0;
    const size_t kExplainBit = 1;
    const size_t kAllowDiskUseBit = 2;
    const size_t kCursorBit = 3;
    const size_t kMaxTimeMSBit = 4;
    const size_t kBypassDocumentValidationBit = 5;
    const size_t kReadConcernBit = 6;
    const size_t kCollationBit = 7;
    const size_t kHintBit = 8;
    const size_t kWriteConcernBit = 9;
    const size_t kLetBit = 10;
    const size_t kNeedsMergeBit = 11;
    const size_t kFromMongosBit = 12;
    const size_t kUnwrappedReadPrefBit = 13;
    const size_t kRequestReshardingResumeTokenBit = 14;
    const size_t kExchangeBit = 15;
    const size_t kLegacyRuntimeConstantsBit = 16;
    const size_t kIsMapReduceCommandBit = 17;
    const size_t kCollectionUUIDBit = 18;
    const size_t kUse44SortKeysBit = 19;
    const size_t kUseNewUpsertBit = 20;
    const size_t kDbNameBit = 21;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kPipelineFieldName) {
            if (MONGO_unlikely(usedFields[kPipelineBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kPipelineBit);

            _hasPipeline = true;
            _pipeline = parsePipelineFromBSON(element);
        }
        else if (fieldName == kExplainFieldName) {
            if (MONGO_unlikely(usedFields[kExplainBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kExplainBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            _explain = parseExplainModeFromBSON(element);
        }
        else if (fieldName == kAllowDiskUseFieldName) {
            if (MONGO_unlikely(usedFields[kAllowDiskUseBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kAllowDiskUseBit);

            _allowDiskUse = OptionalBool::parseFromBSON(element);
        }
        else if (fieldName == kCursorFieldName) {
            if (MONGO_unlikely(usedFields[kCursorBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kCursorBit);

            _cursor = parseAggregateCursorFromBSON(element);
        }
        else if (fieldName == kMaxTimeMSFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kMaxTimeMSBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMaxTimeMSBit);

                {
                    auto value = element.safeNumberLong();
                    validateMaxTimeMS(value);
                    _maxTimeMS = std::move(value);
                }
            }
        }
        else if (fieldName == kBypassDocumentValidationFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kBypassDocumentValidationBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kBypassDocumentValidationBit);

                _bypassDocumentValidation = element.trueValue();
            }
        }
        else if (fieldName == kReadConcernFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kReadConcernBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kReadConcernBit);

                const BSONObj localObject = element.Obj();
                _readConcern = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kCollationFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCollationBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollationBit);

                const BSONObj localObject = element.Obj();
                _collation = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kHintFieldName) {
            if (MONGO_unlikely(usedFields[kHintBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kHintBit);

            _hint = parseHint(element);
        }
        else if (fieldName == kWriteConcernFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kWriteConcernBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kWriteConcernBit);

                const BSONObj localObject = element.Obj();
                _writeConcern = WriteConcernOptions::deserializerForIDL(localObject);
            }
        }
        else if (fieldName == kLetFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kLetBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLetBit);

                const BSONObj localObject = element.Obj();
                _let = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kNeedsMergeFieldName) {
            if (MONGO_unlikely(usedFields[kNeedsMergeBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kNeedsMergeBit);

            _needsMerge = OptionalBool::parseFromBSON(element);
        }
        else if (fieldName == kFromMongosFieldName) {
            if (MONGO_unlikely(usedFields[kFromMongosBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kFromMongosBit);

            _fromMongos = OptionalBool::parseFromBSON(element);
        }
        else if (fieldName == kUnwrappedReadPrefFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kUnwrappedReadPrefBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUnwrappedReadPrefBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                const BSONObj localObject = element.Obj();
                _unwrappedReadPref = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kRequestReshardingResumeTokenFieldName) {
            if (MONGO_unlikely(usedFields[kRequestReshardingResumeTokenBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kRequestReshardingResumeTokenBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            _requestReshardingResumeToken = OptionalBool::parseFromBSON(element);
        }
        else if (fieldName == kExchangeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kExchangeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kExchangeBit);

                IDLParserErrorContext tempContext(kExchangeFieldName, &ctxt);
                const auto localObject = element.Obj();
                _exchange = mongo::ExchangeSpec::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kLegacyRuntimeConstantsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kLegacyRuntimeConstantsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLegacyRuntimeConstantsBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                IDLParserErrorContext tempContext(kLegacyRuntimeConstantsFieldName, &ctxt);
                const auto localObject = element.Obj();
                _legacyRuntimeConstants = mongo::LegacyRuntimeConstants::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kIsMapReduceCommandFieldName) {
            if (MONGO_unlikely(usedFields[kIsMapReduceCommandBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kIsMapReduceCommandBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            _isMapReduceCommand = OptionalBool::parseFromBSON(element);
        }
        else if (fieldName == kCollectionUUIDFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kCollectionUUIDBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollectionUUIDBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                _collectionUUID = UUID(uassertStatusOK(UUID::parse(element)));
            }
        }
        else if (fieldName == kUse44SortKeysFieldName) {
            if (MONGO_unlikely(usedFields[kUse44SortKeysBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kUse44SortKeysBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            // ignore field
        }
        else if (fieldName == kUseNewUpsertFieldName) {
            if (MONGO_unlikely(usedFields[kUseNewUpsertBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kUseNewUpsertBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            // ignore field
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
        if (!usedFields[kPipelineBit]) {
            ctxt.throwMissingField(kPipelineFieldName);
        }
        if (!usedFields[kAllowDiskUseBit]) {
            _allowDiskUse = mongo::OptionalBool();
        }
        if (!usedFields[kCursorBit]) {
            _cursor = SimpleCursorOptions();
        }
        if (!usedFields[kNeedsMergeBit]) {
            _needsMerge = mongo::OptionalBool();
        }
        if (!usedFields[kFromMongosBit]) {
            _fromMongos = mongo::OptionalBool();
        }
        if (!usedFields[kRequestReshardingResumeTokenBit]) {
            _requestReshardingResumeToken = mongo::OptionalBool();
        }
        if (!usedFields[kIsMapReduceCommandBit]) {
            _isMapReduceCommand = mongo::OptionalBool();
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, true);
}

void AggregateCommandRequest::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasPipeline && _hasDbName);

    _nss.serializeCollectionName(builder, "aggregate"_sd);

    builder->append(kPipelineFieldName, _pipeline);

    if (_explain.is_initialized()) {
        serializeExplainToBSON(_explain.get(), kExplainFieldName, builder);
    }

    {
        _allowDiskUse.serializeToBSON(kAllowDiskUseFieldName, builder);
    }

    {
        serializeAggregateCursorToBSON(_cursor, kCursorFieldName, builder);
    }

    if (_maxTimeMS.is_initialized()) {
        builder->append(kMaxTimeMSFieldName, _maxTimeMS.get());
    }

    if (_bypassDocumentValidation.is_initialized()) {
        builder->append(kBypassDocumentValidationFieldName, _bypassDocumentValidation.get());
    }

    if (_readConcern.is_initialized()) {
        builder->append(kReadConcernFieldName, _readConcern.get());
    }

    if (_collation.is_initialized()) {
        builder->append(kCollationFieldName, _collation.get());
    }

    if (_hint.is_initialized()) {
        serializeHintToBSON(_hint.get(), kHintFieldName, builder);
    }

    if (_writeConcern.is_initialized()) {
        const BSONObj localObject = _writeConcern.get().toBSON();
        builder->append(kWriteConcernFieldName, localObject);
    }

    if (_let.is_initialized()) {
        builder->append(kLetFieldName, _let.get());
    }

    {
        _needsMerge.serializeToBSON(kNeedsMergeFieldName, builder);
    }

    {
        _fromMongos.serializeToBSON(kFromMongosFieldName, builder);
    }

    if (_unwrappedReadPref.is_initialized()) {
        builder->append(kUnwrappedReadPrefFieldName, _unwrappedReadPref.get());
    }

    {
        _requestReshardingResumeToken.serializeToBSON(kRequestReshardingResumeTokenFieldName, builder);
    }

    if (_exchange.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kExchangeFieldName));
        _exchange.get().serialize(&subObjBuilder);
    }

    if (_legacyRuntimeConstants.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kLegacyRuntimeConstantsFieldName));
        _legacyRuntimeConstants.get().serialize(&subObjBuilder);
    }

    {
        _isMapReduceCommand.serializeToBSON(kIsMapReduceCommandFieldName, builder);
    }

    if (_collectionUUID.is_initialized()) {
        ConstDataRange tempCDR = _collectionUUID.get().toCDR();
        builder->append(kCollectionUUIDFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest AggregateCommandRequest::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasPipeline && _hasDbName);

        _nss.serializeCollectionName(builder, "aggregate"_sd);

        builder->append(kPipelineFieldName, _pipeline);

        if (_explain.is_initialized()) {
            serializeExplainToBSON(_explain.get(), kExplainFieldName, builder);
        }

        {
            _allowDiskUse.serializeToBSON(kAllowDiskUseFieldName, builder);
        }

        {
            serializeAggregateCursorToBSON(_cursor, kCursorFieldName, builder);
        }

        if (_maxTimeMS.is_initialized()) {
            builder->append(kMaxTimeMSFieldName, _maxTimeMS.get());
        }

        if (_bypassDocumentValidation.is_initialized()) {
            builder->append(kBypassDocumentValidationFieldName, _bypassDocumentValidation.get());
        }

        if (_readConcern.is_initialized()) {
            builder->append(kReadConcernFieldName, _readConcern.get());
        }

        if (_collation.is_initialized()) {
            builder->append(kCollationFieldName, _collation.get());
        }

        if (_hint.is_initialized()) {
            serializeHintToBSON(_hint.get(), kHintFieldName, builder);
        }

        if (_writeConcern.is_initialized()) {
            const BSONObj localObject = _writeConcern.get().toBSON();
            builder->append(kWriteConcernFieldName, localObject);
        }

        if (_let.is_initialized()) {
            builder->append(kLetFieldName, _let.get());
        }

        {
            _needsMerge.serializeToBSON(kNeedsMergeFieldName, builder);
        }

        {
            _fromMongos.serializeToBSON(kFromMongosFieldName, builder);
        }

        if (_unwrappedReadPref.is_initialized()) {
            builder->append(kUnwrappedReadPrefFieldName, _unwrappedReadPref.get());
        }

        {
            _requestReshardingResumeToken.serializeToBSON(kRequestReshardingResumeTokenFieldName, builder);
        }

        if (_exchange.is_initialized()) {
            BSONObjBuilder subObjBuilder(builder->subobjStart(kExchangeFieldName));
            _exchange.get().serialize(&subObjBuilder);
        }

        if (_legacyRuntimeConstants.is_initialized()) {
            BSONObjBuilder subObjBuilder(builder->subobjStart(kLegacyRuntimeConstantsFieldName));
            _legacyRuntimeConstants.get().serialize(&subObjBuilder);
        }

        {
            _isMapReduceCommand.serializeToBSON(kIsMapReduceCommandFieldName, builder);
        }

        if (_collectionUUID.is_initialized()) {
            ConstDataRange tempCDR = _collectionUUID.get().toCDR();
            builder->append(kCollectionUUIDFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj AggregateCommandRequest::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
