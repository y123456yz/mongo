/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/query/find_command_gen.h --output build/opt/mongo/db/query/find_command_gen.cpp src/mongo/db/query/find_command.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/query/find_command_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData FindCommandRequest::k_use44SortKeysFieldName;
constexpr StringData FindCommandRequest::kAllowDiskUseFieldName;
constexpr StringData FindCommandRequest::kAllowPartialResultsFieldName;
constexpr StringData FindCommandRequest::kAllowSpeculativeMajorityReadFieldName;
constexpr StringData FindCommandRequest::kAwaitDataFieldName;
constexpr StringData FindCommandRequest::kBatchSizeFieldName;
constexpr StringData FindCommandRequest::kCollationFieldName;
constexpr StringData FindCommandRequest::kDbNameFieldName;
constexpr StringData FindCommandRequest::kFilterFieldName;
constexpr StringData FindCommandRequest::kHintFieldName;
constexpr StringData FindCommandRequest::kLegacyRuntimeConstantsFieldName;
constexpr StringData FindCommandRequest::kLetFieldName;
constexpr StringData FindCommandRequest::kLimitFieldName;
constexpr StringData FindCommandRequest::kMaxFieldName;
constexpr StringData FindCommandRequest::kMaxTimeMSFieldName;
constexpr StringData FindCommandRequest::kMinFieldName;
constexpr StringData FindCommandRequest::kNoCursorTimeoutFieldName;
constexpr StringData FindCommandRequest::kNtoreturnFieldName;
constexpr StringData FindCommandRequest::kOplogReplayFieldName;
constexpr StringData FindCommandRequest::kOptionsFieldName;
constexpr StringData FindCommandRequest::kProjectionFieldName;
constexpr StringData FindCommandRequest::kReadConcernFieldName;
constexpr StringData FindCommandRequest::kReadOnceFieldName;
constexpr StringData FindCommandRequest::kRequestResumeTokenFieldName;
constexpr StringData FindCommandRequest::kResumeAfterFieldName;
constexpr StringData FindCommandRequest::kReturnKeyFieldName;
constexpr StringData FindCommandRequest::kShowRecordIdFieldName;
constexpr StringData FindCommandRequest::kSingleBatchFieldName;
constexpr StringData FindCommandRequest::kSkipFieldName;
constexpr StringData FindCommandRequest::kSortFieldName;
constexpr StringData FindCommandRequest::kTailableFieldName;
constexpr StringData FindCommandRequest::kTermFieldName;
constexpr StringData FindCommandRequest::kUnwrappedReadPrefFieldName;
constexpr StringData FindCommandRequest::kCommandName;

mongo::AuthorizationContract FindCommandRequest::kAuthorizationContract = AuthorizationContract(std::initializer_list<AccessCheckEnum>{AccessCheckEnum::kIsAuthorizedToParseNamespaceElement}, std::initializer_list<Privilege>{Privilege(ResourcePattern::forAuthorizationContract(MatchTypeEnum::kMatchExactNamespace), ActionSet{ActionType::find}),Privilege(ResourcePattern::forAuthorizationContract(MatchTypeEnum::kMatchClusterResource), ActionSet{ActionType::useUUID})});

const std::vector<StringData> FindCommandRequest::_knownBSONFields {
    FindCommandRequest::k_use44SortKeysFieldName,
    FindCommandRequest::kAllowDiskUseFieldName,
    FindCommandRequest::kAllowPartialResultsFieldName,
    FindCommandRequest::kAllowSpeculativeMajorityReadFieldName,
    FindCommandRequest::kAwaitDataFieldName,
    FindCommandRequest::kBatchSizeFieldName,
    FindCommandRequest::kCollationFieldName,
    FindCommandRequest::kFilterFieldName,
    FindCommandRequest::kHintFieldName,
    FindCommandRequest::kLegacyRuntimeConstantsFieldName,
    FindCommandRequest::kLetFieldName,
    FindCommandRequest::kLimitFieldName,
    FindCommandRequest::kMaxFieldName,
    FindCommandRequest::kMaxTimeMSFieldName,
    FindCommandRequest::kMinFieldName,
    FindCommandRequest::kNoCursorTimeoutFieldName,
    FindCommandRequest::kNtoreturnFieldName,
    FindCommandRequest::kOplogReplayFieldName,
    FindCommandRequest::kOptionsFieldName,
    FindCommandRequest::kProjectionFieldName,
    FindCommandRequest::kReadConcernFieldName,
    FindCommandRequest::kReadOnceFieldName,
    FindCommandRequest::kRequestResumeTokenFieldName,
    FindCommandRequest::kResumeAfterFieldName,
    FindCommandRequest::kReturnKeyFieldName,
    FindCommandRequest::kShowRecordIdFieldName,
    FindCommandRequest::kSingleBatchFieldName,
    FindCommandRequest::kSkipFieldName,
    FindCommandRequest::kSortFieldName,
    FindCommandRequest::kTailableFieldName,
    FindCommandRequest::kTermFieldName,
    FindCommandRequest::kUnwrappedReadPrefFieldName,
    FindCommandRequest::kCommandName,
};
const std::vector<StringData> FindCommandRequest::_knownOP_MSGFields {
    FindCommandRequest::k_use44SortKeysFieldName,
    FindCommandRequest::kAllowDiskUseFieldName,
    FindCommandRequest::kAllowPartialResultsFieldName,
    FindCommandRequest::kAllowSpeculativeMajorityReadFieldName,
    FindCommandRequest::kAwaitDataFieldName,
    FindCommandRequest::kBatchSizeFieldName,
    FindCommandRequest::kCollationFieldName,
    FindCommandRequest::kDbNameFieldName,
    FindCommandRequest::kFilterFieldName,
    FindCommandRequest::kHintFieldName,
    FindCommandRequest::kLegacyRuntimeConstantsFieldName,
    FindCommandRequest::kLetFieldName,
    FindCommandRequest::kLimitFieldName,
    FindCommandRequest::kMaxFieldName,
    FindCommandRequest::kMaxTimeMSFieldName,
    FindCommandRequest::kMinFieldName,
    FindCommandRequest::kNoCursorTimeoutFieldName,
    FindCommandRequest::kNtoreturnFieldName,
    FindCommandRequest::kOplogReplayFieldName,
    FindCommandRequest::kOptionsFieldName,
    FindCommandRequest::kProjectionFieldName,
    FindCommandRequest::kReadConcernFieldName,
    FindCommandRequest::kReadOnceFieldName,
    FindCommandRequest::kRequestResumeTokenFieldName,
    FindCommandRequest::kResumeAfterFieldName,
    FindCommandRequest::kReturnKeyFieldName,
    FindCommandRequest::kShowRecordIdFieldName,
    FindCommandRequest::kSingleBatchFieldName,
    FindCommandRequest::kSkipFieldName,
    FindCommandRequest::kSortFieldName,
    FindCommandRequest::kTailableFieldName,
    FindCommandRequest::kTermFieldName,
    FindCommandRequest::kUnwrappedReadPrefFieldName,
    FindCommandRequest::kCommandName,
};

FindCommandRequest::FindCommandRequest(const NamespaceStringOrUUID nssOrUUID) : _nssOrUUID(std::move(nssOrUUID)), _dbName(nssOrUUID.uuid() ? nssOrUUID.dbname() : nssOrUUID.nss().get().db().toString()), _hasDbName(true) {
    // Used for initialization only
}

void FindCommandRequest::validateSkip(IDLParserErrorContext& ctxt, const std::int64_t value)
{
    if (!(value >= 0)) {
        throwComparisonError<std::int64_t>(ctxt, "skip", ">="_sd, value, 0);
    }
}

void FindCommandRequest::validateSkip(const std::int64_t value)
{
    if (!(value >= 0)) {
        throwComparisonError<std::int64_t>("skip", ">="_sd, value, 0);
    }
}

void FindCommandRequest::validateLimit(IDLParserErrorContext& ctxt, const std::int64_t value)
{
    if (!(value >= 0)) {
        throwComparisonError<std::int64_t>(ctxt, "limit", ">="_sd, value, 0);
    }
}

void FindCommandRequest::validateLimit(const std::int64_t value)
{
    if (!(value >= 0)) {
        throwComparisonError<std::int64_t>("limit", ">="_sd, value, 0);
    }
}

void FindCommandRequest::validateBatchSize(IDLParserErrorContext& ctxt, const std::int64_t value)
{
    if (!(value >= 0)) {
        throwComparisonError<std::int64_t>(ctxt, "batchSize", ">="_sd, value, 0);
    }
}

void FindCommandRequest::validateBatchSize(const std::int64_t value)
{
    if (!(value >= 0)) {
        throwComparisonError<std::int64_t>("batchSize", ">="_sd, value, 0);
    }
}

void FindCommandRequest::validateNtoreturn(IDLParserErrorContext& ctxt, const std::int64_t value)
{
    if (!(value >= 0)) {
        throwComparisonError<std::int64_t>(ctxt, "ntoreturn", ">="_sd, value, 0);
    }
}

void FindCommandRequest::validateNtoreturn(const std::int64_t value)
{
    if (!(value >= 0)) {
        throwComparisonError<std::int64_t>("ntoreturn", ">="_sd, value, 0);
    }
}

void FindCommandRequest::validateMaxTimeMS(IDLParserErrorContext& ctxt, const std::int32_t value)
{
    if (!(value >= 0)) {
        throwComparisonError<std::int32_t>(ctxt, "maxTimeMS", ">="_sd, value, 0);
    }
}

void FindCommandRequest::validateMaxTimeMS(const std::int32_t value)
{
    if (!(value >= 0)) {
        throwComparisonError<std::int32_t>("maxTimeMS", ">="_sd, value, 0);
    }
}


FindCommandRequest FindCommandRequest::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    NamespaceString localNS;
    FindCommandRequest object(localNS);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void FindCommandRequest::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<33> usedFields;
    const size_t kFilterBit = 0;
    const size_t kProjectionBit = 1;
    const size_t kSortBit = 2;
    const size_t kHintBit = 3;
    const size_t kCollationBit = 4;
    const size_t kSkipBit = 5;
    const size_t kLimitBit = 6;
    const size_t kBatchSizeBit = 7;
    const size_t kNtoreturnBit = 8;
    const size_t kSingleBatchBit = 9;
    const size_t kAllowDiskUseBit = 10;
    const size_t kMinBit = 11;
    const size_t kMaxBit = 12;
    const size_t kReturnKeyBit = 13;
    const size_t kShowRecordIdBit = 14;
    const size_t kUnwrappedReadPrefBit = 15;
    const size_t kTailableBit = 16;
    const size_t kOplogReplayBit = 17;
    const size_t kNoCursorTimeoutBit = 18;
    const size_t kAwaitDataBit = 19;
    const size_t kAllowPartialResultsBit = 20;
    const size_t kLetBit = 21;
    const size_t kOptionsBit = 22;
    const size_t kTermBit = 23;
    const size_t kReadOnceBit = 24;
    const size_t kAllowSpeculativeMajorityReadBit = 25;
    const size_t kRequestResumeTokenBit = 26;
    const size_t kResumeAfterBit = 27;
    const size_t k_use44SortKeysBit = 28;
    const size_t kMaxTimeMSBit = 29;
    const size_t kReadConcernBit = 30;
    const size_t kLegacyRuntimeConstantsBit = 31;
    const size_t kDbNameBit = 32;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kFilterFieldName) {
            if (MONGO_unlikely(usedFields[kFilterBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kFilterBit);

            _filter = parseOwnedBSON(element);
        }
        else if (fieldName == kProjectionFieldName) {
            if (MONGO_unlikely(usedFields[kProjectionBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kProjectionBit);

            _projection = parseOwnedBSON(element);
        }
        else if (fieldName == kSortFieldName) {
            if (MONGO_unlikely(usedFields[kSortBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kSortBit);

            _sort = parseOwnedBSON(element);
        }
        else if (fieldName == kHintFieldName) {
            if (MONGO_unlikely(usedFields[kHintBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kHintBit);

            _hint = parseHint(element);
        }
        else if (fieldName == kCollationFieldName) {
            if (MONGO_unlikely(usedFields[kCollationBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kCollationBit);

            _collation = parseOwnedBSON(element);
        }
        else if (fieldName == kSkipFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kSkipBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSkipBit);

                {
                    auto value = element.safeNumberLong();
                    validateSkip(value);
                    _skip = std::move(value);
                }
            }
        }
        else if (fieldName == kLimitFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kLimitBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLimitBit);

                {
                    auto value = element.safeNumberLong();
                    validateLimit(value);
                    _limit = std::move(value);
                }
            }
        }
        else if (fieldName == kBatchSizeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kBatchSizeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kBatchSizeBit);

                {
                    auto value = element.safeNumberLong();
                    validateBatchSize(value);
                    _batchSize = std::move(value);
                }
            }
        }
        else if (fieldName == kNtoreturnFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kNtoreturnBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNtoreturnBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                {
                    auto value = element.safeNumberLong();
                    validateNtoreturn(value);
                    _ntoreturn = std::move(value);
                }
            }
        }
        else if (fieldName == kSingleBatchFieldName) {
            if (MONGO_unlikely(usedFields[kSingleBatchBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kSingleBatchBit);

            _singleBatch = OptionalBool::parseFromBSON(element);
        }
        else if (fieldName == kAllowDiskUseFieldName) {
            if (MONGO_unlikely(usedFields[kAllowDiskUseBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kAllowDiskUseBit);

            _allowDiskUse = OptionalBool::parseFromBSON(element);
        }
        else if (fieldName == kMinFieldName) {
            if (MONGO_unlikely(usedFields[kMinBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kMinBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            _min = parseOwnedBSON(element);
        }
        else if (fieldName == kMaxFieldName) {
            if (MONGO_unlikely(usedFields[kMaxBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kMaxBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            _max = parseOwnedBSON(element);
        }
        else if (fieldName == kReturnKeyFieldName) {
            if (MONGO_unlikely(usedFields[kReturnKeyBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kReturnKeyBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            _returnKey = OptionalBool::parseFromBSON(element);
        }
        else if (fieldName == kShowRecordIdFieldName) {
            if (MONGO_unlikely(usedFields[kShowRecordIdBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kShowRecordIdBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            _showRecordId = OptionalBool::parseFromBSON(element);
        }
        else if (fieldName == kUnwrappedReadPrefFieldName) {
            if (MONGO_unlikely(usedFields[kUnwrappedReadPrefBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kUnwrappedReadPrefBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            _unwrappedReadPref = parseOwnedBSON(element);
        }
        else if (fieldName == kTailableFieldName) {
            if (MONGO_unlikely(usedFields[kTailableBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kTailableBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            _tailable = OptionalBool::parseFromBSON(element);
        }
        else if (fieldName == kOplogReplayFieldName) {
            if (MONGO_unlikely(usedFields[kOplogReplayBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kOplogReplayBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            _oplogReplay = parseBoolean(element);
        }
        else if (fieldName == kNoCursorTimeoutFieldName) {
            if (MONGO_unlikely(usedFields[kNoCursorTimeoutBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kNoCursorTimeoutBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            _noCursorTimeout = OptionalBool::parseFromBSON(element);
        }
        else if (fieldName == kAwaitDataFieldName) {
            if (MONGO_unlikely(usedFields[kAwaitDataBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kAwaitDataBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            _awaitData = OptionalBool::parseFromBSON(element);
        }
        else if (fieldName == kAllowPartialResultsFieldName) {
            if (MONGO_unlikely(usedFields[kAllowPartialResultsBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kAllowPartialResultsBit);

            _allowPartialResults = OptionalBool::parseFromBSON(element);
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
        else if (fieldName == kOptionsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kOptionsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kOptionsBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                const BSONObj localObject = element.Obj();
                _options = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kTermFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kTermBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTermBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                _term = element.safeNumberLong();
            }
        }
        else if (fieldName == kReadOnceFieldName) {
            if (MONGO_unlikely(usedFields[kReadOnceBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kReadOnceBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            _readOnce = OptionalBool::parseFromBSON(element);
        }
        else if (fieldName == kAllowSpeculativeMajorityReadFieldName) {
            if (MONGO_unlikely(usedFields[kAllowSpeculativeMajorityReadBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kAllowSpeculativeMajorityReadBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            _allowSpeculativeMajorityRead = OptionalBool::parseFromBSON(element);
        }
        else if (fieldName == kRequestResumeTokenFieldName) {
            if (MONGO_unlikely(usedFields[kRequestResumeTokenBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kRequestResumeTokenBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            _requestResumeToken = OptionalBool::parseFromBSON(element);
        }
        else if (fieldName == kResumeAfterFieldName) {
            if (MONGO_unlikely(usedFields[kResumeAfterBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kResumeAfterBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            _resumeAfter = parseOwnedBSON(element);
        }
        else if (fieldName == k_use44SortKeysFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[k_use44SortKeysBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(k_use44SortKeysBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                __use44SortKeys = element.boolean();
            }
        }
        else if (fieldName == kMaxTimeMSFieldName) {
            if (MONGO_unlikely(usedFields[kMaxTimeMSBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kMaxTimeMSBit);

            {
                auto value = parseMaxTimeMSForIDL(element);
                validateMaxTimeMS(value);
                _maxTimeMS = std::move(value);
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
        if (!usedFields[kFilterBit]) {
            _filter = mongo::BSONObj();
        }
        if (!usedFields[kProjectionBit]) {
            _projection = mongo::BSONObj();
        }
        if (!usedFields[kSortBit]) {
            _sort = mongo::BSONObj();
        }
        if (!usedFields[kHintBit]) {
            _hint = mongo::BSONObj();
        }
        if (!usedFields[kCollationBit]) {
            _collation = mongo::BSONObj();
        }
        if (!usedFields[kSingleBatchBit]) {
            _singleBatch = mongo::OptionalBool();
        }
        if (!usedFields[kAllowDiskUseBit]) {
            _allowDiskUse = mongo::OptionalBool();
        }
        if (!usedFields[kMinBit]) {
            _min = mongo::BSONObj();
        }
        if (!usedFields[kMaxBit]) {
            _max = mongo::BSONObj();
        }
        if (!usedFields[kReturnKeyBit]) {
            _returnKey = mongo::OptionalBool();
        }
        if (!usedFields[kShowRecordIdBit]) {
            _showRecordId = mongo::OptionalBool();
        }
        if (!usedFields[kUnwrappedReadPrefBit]) {
            _unwrappedReadPref = mongo::BSONObj();
        }
        if (!usedFields[kTailableBit]) {
            _tailable = mongo::OptionalBool();
        }
        if (!usedFields[kNoCursorTimeoutBit]) {
            _noCursorTimeout = mongo::OptionalBool();
        }
        if (!usedFields[kAwaitDataBit]) {
            _awaitData = mongo::OptionalBool();
        }
        if (!usedFields[kAllowPartialResultsBit]) {
            _allowPartialResults = mongo::OptionalBool();
        }
        if (!usedFields[kReadOnceBit]) {
            _readOnce = mongo::OptionalBool();
        }
        if (!usedFields[kAllowSpeculativeMajorityReadBit]) {
            _allowSpeculativeMajorityRead = mongo::OptionalBool();
        }
        if (!usedFields[kRequestResumeTokenBit]) {
            _requestResumeToken = mongo::OptionalBool();
        }
        if (!usedFields[kResumeAfterBit]) {
            _resumeAfter = mongo::BSONObj();
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nssOrUUID.nss() || _nssOrUUID.uuid());
    _nssOrUUID = ctxt.parseNsOrUUID(_dbName, commandElement);
}

FindCommandRequest FindCommandRequest::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    NamespaceString localNS;
    FindCommandRequest object(localNS);
    object.parseProtected(ctxt, request);
    return object;
}
void FindCommandRequest::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<33> usedFields;
    const size_t kFilterBit = 0;
    const size_t kProjectionBit = 1;
    const size_t kSortBit = 2;
    const size_t kHintBit = 3;
    const size_t kCollationBit = 4;
    const size_t kSkipBit = 5;
    const size_t kLimitBit = 6;
    const size_t kBatchSizeBit = 7;
    const size_t kNtoreturnBit = 8;
    const size_t kSingleBatchBit = 9;
    const size_t kAllowDiskUseBit = 10;
    const size_t kMinBit = 11;
    const size_t kMaxBit = 12;
    const size_t kReturnKeyBit = 13;
    const size_t kShowRecordIdBit = 14;
    const size_t kUnwrappedReadPrefBit = 15;
    const size_t kTailableBit = 16;
    const size_t kOplogReplayBit = 17;
    const size_t kNoCursorTimeoutBit = 18;
    const size_t kAwaitDataBit = 19;
    const size_t kAllowPartialResultsBit = 20;
    const size_t kLetBit = 21;
    const size_t kOptionsBit = 22;
    const size_t kTermBit = 23;
    const size_t kReadOnceBit = 24;
    const size_t kAllowSpeculativeMajorityReadBit = 25;
    const size_t kRequestResumeTokenBit = 26;
    const size_t kResumeAfterBit = 27;
    const size_t k_use44SortKeysBit = 28;
    const size_t kMaxTimeMSBit = 29;
    const size_t kReadConcernBit = 30;
    const size_t kLegacyRuntimeConstantsBit = 31;
    const size_t kDbNameBit = 32;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kFilterFieldName) {
            if (MONGO_unlikely(usedFields[kFilterBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kFilterBit);

            _filter = parseOwnedBSON(element);
        }
        else if (fieldName == kProjectionFieldName) {
            if (MONGO_unlikely(usedFields[kProjectionBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kProjectionBit);

            _projection = parseOwnedBSON(element);
        }
        else if (fieldName == kSortFieldName) {
            if (MONGO_unlikely(usedFields[kSortBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kSortBit);

            _sort = parseOwnedBSON(element);
        }
        else if (fieldName == kHintFieldName) {
            if (MONGO_unlikely(usedFields[kHintBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kHintBit);

            _hint = parseHint(element);
        }
        else if (fieldName == kCollationFieldName) {
            if (MONGO_unlikely(usedFields[kCollationBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kCollationBit);

            _collation = parseOwnedBSON(element);
        }
        else if (fieldName == kSkipFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kSkipBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSkipBit);

                {
                    auto value = element.safeNumberLong();
                    validateSkip(value);
                    _skip = std::move(value);
                }
            }
        }
        else if (fieldName == kLimitFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kLimitBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLimitBit);

                {
                    auto value = element.safeNumberLong();
                    validateLimit(value);
                    _limit = std::move(value);
                }
            }
        }
        else if (fieldName == kBatchSizeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kBatchSizeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kBatchSizeBit);

                {
                    auto value = element.safeNumberLong();
                    validateBatchSize(value);
                    _batchSize = std::move(value);
                }
            }
        }
        else if (fieldName == kNtoreturnFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kNtoreturnBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNtoreturnBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                {
                    auto value = element.safeNumberLong();
                    validateNtoreturn(value);
                    _ntoreturn = std::move(value);
                }
            }
        }
        else if (fieldName == kSingleBatchFieldName) {
            if (MONGO_unlikely(usedFields[kSingleBatchBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kSingleBatchBit);

            _singleBatch = OptionalBool::parseFromBSON(element);
        }
        else if (fieldName == kAllowDiskUseFieldName) {
            if (MONGO_unlikely(usedFields[kAllowDiskUseBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kAllowDiskUseBit);

            _allowDiskUse = OptionalBool::parseFromBSON(element);
        }
        else if (fieldName == kMinFieldName) {
            if (MONGO_unlikely(usedFields[kMinBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kMinBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            _min = parseOwnedBSON(element);
        }
        else if (fieldName == kMaxFieldName) {
            if (MONGO_unlikely(usedFields[kMaxBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kMaxBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            _max = parseOwnedBSON(element);
        }
        else if (fieldName == kReturnKeyFieldName) {
            if (MONGO_unlikely(usedFields[kReturnKeyBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kReturnKeyBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            _returnKey = OptionalBool::parseFromBSON(element);
        }
        else if (fieldName == kShowRecordIdFieldName) {
            if (MONGO_unlikely(usedFields[kShowRecordIdBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kShowRecordIdBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            _showRecordId = OptionalBool::parseFromBSON(element);
        }
        else if (fieldName == kUnwrappedReadPrefFieldName) {
            if (MONGO_unlikely(usedFields[kUnwrappedReadPrefBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kUnwrappedReadPrefBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            _unwrappedReadPref = parseOwnedBSON(element);
        }
        else if (fieldName == kTailableFieldName) {
            if (MONGO_unlikely(usedFields[kTailableBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kTailableBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            _tailable = OptionalBool::parseFromBSON(element);
        }
        else if (fieldName == kOplogReplayFieldName) {
            if (MONGO_unlikely(usedFields[kOplogReplayBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kOplogReplayBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            _oplogReplay = parseBoolean(element);
        }
        else if (fieldName == kNoCursorTimeoutFieldName) {
            if (MONGO_unlikely(usedFields[kNoCursorTimeoutBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kNoCursorTimeoutBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            _noCursorTimeout = OptionalBool::parseFromBSON(element);
        }
        else if (fieldName == kAwaitDataFieldName) {
            if (MONGO_unlikely(usedFields[kAwaitDataBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kAwaitDataBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            _awaitData = OptionalBool::parseFromBSON(element);
        }
        else if (fieldName == kAllowPartialResultsFieldName) {
            if (MONGO_unlikely(usedFields[kAllowPartialResultsBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kAllowPartialResultsBit);

            _allowPartialResults = OptionalBool::parseFromBSON(element);
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
        else if (fieldName == kOptionsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kOptionsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kOptionsBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                const BSONObj localObject = element.Obj();
                _options = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kTermFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kTermBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTermBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                _term = element.safeNumberLong();
            }
        }
        else if (fieldName == kReadOnceFieldName) {
            if (MONGO_unlikely(usedFields[kReadOnceBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kReadOnceBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            _readOnce = OptionalBool::parseFromBSON(element);
        }
        else if (fieldName == kAllowSpeculativeMajorityReadFieldName) {
            if (MONGO_unlikely(usedFields[kAllowSpeculativeMajorityReadBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kAllowSpeculativeMajorityReadBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            _allowSpeculativeMajorityRead = OptionalBool::parseFromBSON(element);
        }
        else if (fieldName == kRequestResumeTokenFieldName) {
            if (MONGO_unlikely(usedFields[kRequestResumeTokenBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kRequestResumeTokenBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            _requestResumeToken = OptionalBool::parseFromBSON(element);
        }
        else if (fieldName == kResumeAfterFieldName) {
            if (MONGO_unlikely(usedFields[kResumeAfterBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kResumeAfterBit);

            ctxt.throwAPIStrictErrorIfApplicable(element);

            _resumeAfter = parseOwnedBSON(element);
        }
        else if (fieldName == k_use44SortKeysFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[k_use44SortKeysBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(k_use44SortKeysBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                __use44SortKeys = element.boolean();
            }
        }
        else if (fieldName == kMaxTimeMSFieldName) {
            if (MONGO_unlikely(usedFields[kMaxTimeMSBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kMaxTimeMSBit);

            {
                auto value = parseMaxTimeMSForIDL(element);
                validateMaxTimeMS(value);
                _maxTimeMS = std::move(value);
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
        if (!usedFields[kFilterBit]) {
            _filter = mongo::BSONObj();
        }
        if (!usedFields[kProjectionBit]) {
            _projection = mongo::BSONObj();
        }
        if (!usedFields[kSortBit]) {
            _sort = mongo::BSONObj();
        }
        if (!usedFields[kHintBit]) {
            _hint = mongo::BSONObj();
        }
        if (!usedFields[kCollationBit]) {
            _collation = mongo::BSONObj();
        }
        if (!usedFields[kSingleBatchBit]) {
            _singleBatch = mongo::OptionalBool();
        }
        if (!usedFields[kAllowDiskUseBit]) {
            _allowDiskUse = mongo::OptionalBool();
        }
        if (!usedFields[kMinBit]) {
            _min = mongo::BSONObj();
        }
        if (!usedFields[kMaxBit]) {
            _max = mongo::BSONObj();
        }
        if (!usedFields[kReturnKeyBit]) {
            _returnKey = mongo::OptionalBool();
        }
        if (!usedFields[kShowRecordIdBit]) {
            _showRecordId = mongo::OptionalBool();
        }
        if (!usedFields[kUnwrappedReadPrefBit]) {
            _unwrappedReadPref = mongo::BSONObj();
        }
        if (!usedFields[kTailableBit]) {
            _tailable = mongo::OptionalBool();
        }
        if (!usedFields[kNoCursorTimeoutBit]) {
            _noCursorTimeout = mongo::OptionalBool();
        }
        if (!usedFields[kAwaitDataBit]) {
            _awaitData = mongo::OptionalBool();
        }
        if (!usedFields[kAllowPartialResultsBit]) {
            _allowPartialResults = mongo::OptionalBool();
        }
        if (!usedFields[kReadOnceBit]) {
            _readOnce = mongo::OptionalBool();
        }
        if (!usedFields[kAllowSpeculativeMajorityReadBit]) {
            _allowSpeculativeMajorityRead = mongo::OptionalBool();
        }
        if (!usedFields[kRequestResumeTokenBit]) {
            _requestResumeToken = mongo::OptionalBool();
        }
        if (!usedFields[kResumeAfterBit]) {
            _resumeAfter = mongo::BSONObj();
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nssOrUUID.nss() || _nssOrUUID.uuid());
    _nssOrUUID = ctxt.parseNsOrUUID(_dbName, commandElement);
}

void FindCommandRequest::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    _nssOrUUID.serialize(builder, "find"_sd);

    {
        serializeBSONWhenNotEmpty(_filter, kFilterFieldName, builder);
    }

    {
        serializeBSONWhenNotEmpty(_projection, kProjectionFieldName, builder);
    }

    {
        serializeBSONWhenNotEmpty(_sort, kSortFieldName, builder);
    }

    {
        serializeHintToBSON(_hint, kHintFieldName, builder);
    }

    {
        serializeBSONWhenNotEmpty(_collation, kCollationFieldName, builder);
    }

    if (_skip.is_initialized()) {
        builder->append(kSkipFieldName, _skip.get());
    }

    if (_limit.is_initialized()) {
        builder->append(kLimitFieldName, _limit.get());
    }

    if (_batchSize.is_initialized()) {
        builder->append(kBatchSizeFieldName, _batchSize.get());
    }

    if (_ntoreturn.is_initialized()) {
        builder->append(kNtoreturnFieldName, _ntoreturn.get());
    }

    {
        _singleBatch.serializeToBSON(kSingleBatchFieldName, builder);
    }

    {
        _allowDiskUse.serializeToBSON(kAllowDiskUseFieldName, builder);
    }

    {
        serializeBSONWhenNotEmpty(_min, kMinFieldName, builder);
    }

    {
        serializeBSONWhenNotEmpty(_max, kMaxFieldName, builder);
    }

    {
        _returnKey.serializeToBSON(kReturnKeyFieldName, builder);
    }

    {
        _showRecordId.serializeToBSON(kShowRecordIdFieldName, builder);
    }

    {
        serializeBSONWhenNotEmpty(_unwrappedReadPref, kUnwrappedReadPrefFieldName, builder);
    }

    {
        _tailable.serializeToBSON(kTailableFieldName, builder);
    }

    if (_oplogReplay.is_initialized()) {
        noOpSerializer(_oplogReplay.get(), kOplogReplayFieldName, builder);
    }

    {
        _noCursorTimeout.serializeToBSON(kNoCursorTimeoutFieldName, builder);
    }

    {
        _awaitData.serializeToBSON(kAwaitDataFieldName, builder);
    }

    {
        _allowPartialResults.serializeToBSON(kAllowPartialResultsFieldName, builder);
    }

    if (_let.is_initialized()) {
        builder->append(kLetFieldName, _let.get());
    }

    if (_options.is_initialized()) {
        builder->append(kOptionsFieldName, _options.get());
    }

    if (_term.is_initialized()) {
        builder->append(kTermFieldName, _term.get());
    }

    {
        _readOnce.serializeToBSON(kReadOnceFieldName, builder);
    }

    {
        _allowSpeculativeMajorityRead.serializeToBSON(kAllowSpeculativeMajorityReadFieldName, builder);
    }

    {
        _requestResumeToken.serializeToBSON(kRequestResumeTokenFieldName, builder);
    }

    {
        serializeBSONWhenNotEmpty(_resumeAfter, kResumeAfterFieldName, builder);
    }

    if (__use44SortKeys.is_initialized()) {
        builder->append(k_use44SortKeysFieldName, __use44SortKeys.get());
    }

    if (_maxTimeMS.is_initialized()) {
        builder->append(kMaxTimeMSFieldName, _maxTimeMS.get());
    }

    if (_readConcern.is_initialized()) {
        builder->append(kReadConcernFieldName, _readConcern.get());
    }

    if (_legacyRuntimeConstants.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kLegacyRuntimeConstantsFieldName));
        _legacyRuntimeConstants.get().serialize(&subObjBuilder);
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest FindCommandRequest::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        _nssOrUUID.serialize(builder, "find"_sd);

        {
            serializeBSONWhenNotEmpty(_filter, kFilterFieldName, builder);
        }

        {
            serializeBSONWhenNotEmpty(_projection, kProjectionFieldName, builder);
        }

        {
            serializeBSONWhenNotEmpty(_sort, kSortFieldName, builder);
        }

        {
            serializeHintToBSON(_hint, kHintFieldName, builder);
        }

        {
            serializeBSONWhenNotEmpty(_collation, kCollationFieldName, builder);
        }

        if (_skip.is_initialized()) {
            builder->append(kSkipFieldName, _skip.get());
        }

        if (_limit.is_initialized()) {
            builder->append(kLimitFieldName, _limit.get());
        }

        if (_batchSize.is_initialized()) {
            builder->append(kBatchSizeFieldName, _batchSize.get());
        }

        if (_ntoreturn.is_initialized()) {
            builder->append(kNtoreturnFieldName, _ntoreturn.get());
        }

        {
            _singleBatch.serializeToBSON(kSingleBatchFieldName, builder);
        }

        {
            _allowDiskUse.serializeToBSON(kAllowDiskUseFieldName, builder);
        }

        {
            serializeBSONWhenNotEmpty(_min, kMinFieldName, builder);
        }

        {
            serializeBSONWhenNotEmpty(_max, kMaxFieldName, builder);
        }

        {
            _returnKey.serializeToBSON(kReturnKeyFieldName, builder);
        }

        {
            _showRecordId.serializeToBSON(kShowRecordIdFieldName, builder);
        }

        {
            serializeBSONWhenNotEmpty(_unwrappedReadPref, kUnwrappedReadPrefFieldName, builder);
        }

        {
            _tailable.serializeToBSON(kTailableFieldName, builder);
        }

        if (_oplogReplay.is_initialized()) {
            noOpSerializer(_oplogReplay.get(), kOplogReplayFieldName, builder);
        }

        {
            _noCursorTimeout.serializeToBSON(kNoCursorTimeoutFieldName, builder);
        }

        {
            _awaitData.serializeToBSON(kAwaitDataFieldName, builder);
        }

        {
            _allowPartialResults.serializeToBSON(kAllowPartialResultsFieldName, builder);
        }

        if (_let.is_initialized()) {
            builder->append(kLetFieldName, _let.get());
        }

        if (_options.is_initialized()) {
            builder->append(kOptionsFieldName, _options.get());
        }

        if (_term.is_initialized()) {
            builder->append(kTermFieldName, _term.get());
        }

        {
            _readOnce.serializeToBSON(kReadOnceFieldName, builder);
        }

        {
            _allowSpeculativeMajorityRead.serializeToBSON(kAllowSpeculativeMajorityReadFieldName, builder);
        }

        {
            _requestResumeToken.serializeToBSON(kRequestResumeTokenFieldName, builder);
        }

        {
            serializeBSONWhenNotEmpty(_resumeAfter, kResumeAfterFieldName, builder);
        }

        if (__use44SortKeys.is_initialized()) {
            builder->append(k_use44SortKeysFieldName, __use44SortKeys.get());
        }

        if (_maxTimeMS.is_initialized()) {
            builder->append(kMaxTimeMSFieldName, _maxTimeMS.get());
        }

        if (_readConcern.is_initialized()) {
            builder->append(kReadConcernFieldName, _readConcern.get());
        }

        if (_legacyRuntimeConstants.is_initialized()) {
            BSONObjBuilder subObjBuilder(builder->subobjStart(kLegacyRuntimeConstantsFieldName));
            _legacyRuntimeConstants.get().serialize(&subObjBuilder);
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj FindCommandRequest::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
