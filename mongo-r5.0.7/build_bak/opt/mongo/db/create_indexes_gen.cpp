/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/create_indexes_gen.h --output build/opt/mongo/db/create_indexes_gen.cpp src/mongo/db/create_indexes.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/create_indexes_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData CreateIndexesReply::kCommitQuorumFieldName;
constexpr StringData CreateIndexesReply::kCreatedCollectionAutomaticallyFieldName;
constexpr StringData CreateIndexesReply::kNoteFieldName;
constexpr StringData CreateIndexesReply::kNumIndexesAfterFieldName;
constexpr StringData CreateIndexesReply::kNumIndexesBeforeFieldName;


CreateIndexesReply::CreateIndexesReply()  {
    // Used for initialization only
}


CreateIndexesReply CreateIndexesReply::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<CreateIndexesReply>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void CreateIndexesReply::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<5> usedFields;
    const size_t kNumIndexesBeforeBit = 0;
    const size_t kNumIndexesAfterBit = 1;
    const size_t kCreatedCollectionAutomaticallyBit = 2;
    const size_t kCommitQuorumBit = 3;
    const size_t kNoteBit = 4;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kNumIndexesBeforeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberInt))) {
                if (MONGO_unlikely(usedFields[kNumIndexesBeforeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNumIndexesBeforeBit);

                _numIndexesBefore = element._numberInt();
            }
        }
        else if (fieldName == kNumIndexesAfterFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberInt))) {
                if (MONGO_unlikely(usedFields[kNumIndexesAfterBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNumIndexesAfterBit);

                _numIndexesAfter = element._numberInt();
            }
        }
        else if (fieldName == kCreatedCollectionAutomaticallyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kCreatedCollectionAutomaticallyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCreatedCollectionAutomaticallyBit);

                _createdCollectionAutomatically = element.boolean();
            }
        }
        else if (fieldName == kCommitQuorumFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble, String}))) {
                if (MONGO_unlikely(usedFields[kCommitQuorumBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCommitQuorumBit);

                _commitQuorum = CommitQuorumOptions::deserializerForIDL(element);
            }
        }
        else if (fieldName == kNoteFieldName) {
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


void CreateIndexesReply::serialize(BSONObjBuilder* builder) const {
    if (_numIndexesBefore.is_initialized()) {
        builder->append(kNumIndexesBeforeFieldName, _numIndexesBefore.get());
    }

    if (_numIndexesAfter.is_initialized()) {
        builder->append(kNumIndexesAfterFieldName, _numIndexesAfter.get());
    }

    if (_createdCollectionAutomatically.is_initialized()) {
        builder->append(kCreatedCollectionAutomaticallyFieldName, _createdCollectionAutomatically.get());
    }

    if (_commitQuorum.is_initialized()) {
        _commitQuorum.get().appendToBuilder(kCommitQuorumFieldName, builder);
    }

    if (_note.is_initialized()) {
        builder->append(kNoteFieldName, _note.get());
    }

}


BSONObj CreateIndexesReply::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData NewIndexSpec::k2dsphereIndexVersionFieldName;
constexpr StringData NewIndexSpec::kBackgroundFieldName;
constexpr StringData NewIndexSpec::kBitsFieldName;
constexpr StringData NewIndexSpec::kBucketSizeFieldName;
constexpr StringData NewIndexSpec::kCoarsestIndexedLevelFieldName;
constexpr StringData NewIndexSpec::kCollationFieldName;
constexpr StringData NewIndexSpec::kDefault_languageFieldName;
constexpr StringData NewIndexSpec::kDropDupsFieldName;
constexpr StringData NewIndexSpec::kExpireAfterSecondsFieldName;
constexpr StringData NewIndexSpec::kFinestIndexedLevelFieldName;
constexpr StringData NewIndexSpec::kHiddenFieldName;
constexpr StringData NewIndexSpec::kKeyFieldName;
constexpr StringData NewIndexSpec::kLanguage_overrideFieldName;
constexpr StringData NewIndexSpec::kMaxFieldName;
constexpr StringData NewIndexSpec::kMinFieldName;
constexpr StringData NewIndexSpec::kNameFieldName;
constexpr StringData NewIndexSpec::kNsFieldName;
constexpr StringData NewIndexSpec::kPartialFilterExpressionFieldName;
constexpr StringData NewIndexSpec::kSparseFieldName;
constexpr StringData NewIndexSpec::kStorageEngineFieldName;
constexpr StringData NewIndexSpec::kTextIndexVersionFieldName;
constexpr StringData NewIndexSpec::kUniqueFieldName;
constexpr StringData NewIndexSpec::kVFieldName;
constexpr StringData NewIndexSpec::kWeightsFieldName;
constexpr StringData NewIndexSpec::kWildcardProjectionFieldName;


NewIndexSpec::NewIndexSpec() : _key(mongo::idl::preparsedValue<decltype(_key)>()), _name(mongo::idl::preparsedValue<decltype(_name)>()), _hasKey(false), _hasName(false) {
    // Used for initialization only
}
NewIndexSpec::NewIndexSpec(mongo::BSONObj key, std::string name) : _key(std::move(key)), _name(std::move(name)), _hasKey(true), _hasName(true) {
    // Used for initialization only
}


NewIndexSpec NewIndexSpec::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<NewIndexSpec>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void NewIndexSpec::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<25> usedFields;
    const size_t kVBit = 0;
    const size_t kKeyBit = 1;
    const size_t kNameBit = 2;
    const size_t kNsBit = 3;
    const size_t kBackgroundBit = 4;
    const size_t kUniqueBit = 5;
    const size_t kHiddenBit = 6;
    const size_t kPartialFilterExpressionBit = 7;
    const size_t kSparseBit = 8;
    const size_t kExpireAfterSecondsBit = 9;
    const size_t kStorageEngineBit = 10;
    const size_t kWeightsBit = 11;
    const size_t kDefault_languageBit = 12;
    const size_t kLanguage_overrideBit = 13;
    const size_t kTextIndexVersionBit = 14;
    const size_t k2dsphereIndexVersionBit = 15;
    const size_t kBitsBit = 16;
    const size_t kMinBit = 17;
    const size_t kMaxBit = 18;
    const size_t kBucketSizeBit = 19;
    const size_t kCollationBit = 20;
    const size_t kWildcardProjectionBit = 21;
    const size_t kCoarsestIndexedLevelBit = 22;
    const size_t kFinestIndexedLevelBit = 23;
    const size_t kDropDupsBit = 24;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kVFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kVBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kVBit);

                _v = element.safeNumberInt();
            }
        }
        else if (fieldName == kKeyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kKeyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kKeyBit);

                _hasKey = true;
                const BSONObj localObject = element.Obj();
                _key = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kNameFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kNameBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNameBit);

                _hasName = true;
                _name = element.str();
            }
        }
        else if (fieldName == kNsFieldName) {
            if (MONGO_unlikely(usedFields[kNsBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kNsBit);

            // ignore field
        }
        else if (fieldName == kBackgroundFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kBackgroundBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kBackgroundBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                _background = element.trueValue();
            }
        }
        else if (fieldName == kUniqueFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kUniqueBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUniqueBit);

                _unique = element.trueValue();
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
        else if (fieldName == kPartialFilterExpressionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kPartialFilterExpressionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPartialFilterExpressionBit);

                const BSONObj localObject = element.Obj();
                _partialFilterExpression = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kSparseFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kSparseBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSparseBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                _sparse = element.trueValue();
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
        else if (fieldName == kStorageEngineFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kStorageEngineBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStorageEngineBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                const BSONObj localObject = element.Obj();
                _storageEngine = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kWeightsFieldName) {
            if (MONGO_unlikely(usedFields[kWeightsBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kWeightsBit);


            const BSONType variantType = element.type();
            switch (variantType) {
            case String:
            {
                _weights = element.str();
                break;
            }
            case Object:
            {
                const BSONObj localObject = element.Obj();
                _weights = BSONObj::getOwned(localObject);
                break;
            }
            default:
                ctxt.throwBadType(element, {BSONType::String, BSONType::Object});
                break;
            }
        }
        else if (fieldName == kDefault_languageFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kDefault_languageBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDefault_languageBit);

                _default_language = element.str();
            }
        }
        else if (fieldName == kLanguage_overrideFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kLanguage_overrideBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLanguage_overrideBit);

                _language_override = element.str();
            }
        }
        else if (fieldName == kTextIndexVersionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kTextIndexVersionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTextIndexVersionBit);

                _textIndexVersion = element.safeNumberInt();
            }
        }
        else if (fieldName == k2dsphereIndexVersionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[k2dsphereIndexVersionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(k2dsphereIndexVersionBit);

                _2dsphereIndexVersion = element.safeNumberInt();
            }
        }
        else if (fieldName == kBitsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kBitsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kBitsBit);

                _bits = element.safeNumberInt();
            }
        }
        else if (fieldName == kMinFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kMinBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMinBit);

                _min = element.safeNumberDouble();
            }
        }
        else if (fieldName == kMaxFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kMaxBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMaxBit);

                _max = element.safeNumberDouble();
            }
        }
        else if (fieldName == kBucketSizeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kBucketSizeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kBucketSizeBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                _bucketSize = element.safeNumberDouble();
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
        else if (fieldName == kWildcardProjectionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kWildcardProjectionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kWildcardProjectionBit);

                const BSONObj localObject = element.Obj();
                _wildcardProjection = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kCoarsestIndexedLevelFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kCoarsestIndexedLevelBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCoarsestIndexedLevelBit);

                _coarsestIndexedLevel = element.safeNumberInt();
            }
        }
        else if (fieldName == kFinestIndexedLevelFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kFinestIndexedLevelBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kFinestIndexedLevelBit);

                _finestIndexedLevel = element.safeNumberInt();
            }
        }
        else if (fieldName == kDropDupsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kDropDupsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDropDupsBit);

                ctxt.throwAPIStrictErrorIfApplicable(element);

                _dropDups = element.trueValue();
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kKeyBit]) {
            ctxt.throwMissingField(kKeyFieldName);
        }
        if (!usedFields[kNameBit]) {
            ctxt.throwMissingField(kNameFieldName);
        }
    }

}


void NewIndexSpec::serialize(BSONObjBuilder* builder) const {
    invariant(_hasKey && _hasName);

    if (_v.is_initialized()) {
        builder->append(kVFieldName, _v.get());
    }

    builder->append(kKeyFieldName, _key);

    builder->append(kNameFieldName, _name);

    if (_background.is_initialized()) {
        builder->append(kBackgroundFieldName, _background.get());
    }

    if (_unique.is_initialized()) {
        builder->append(kUniqueFieldName, _unique.get());
    }

    if (_hidden.is_initialized()) {
        builder->append(kHiddenFieldName, _hidden.get());
    }

    if (_partialFilterExpression.is_initialized()) {
        builder->append(kPartialFilterExpressionFieldName, _partialFilterExpression.get());
    }

    if (_sparse.is_initialized()) {
        builder->append(kSparseFieldName, _sparse.get());
    }

    if (_expireAfterSeconds.is_initialized()) {
        builder->append(kExpireAfterSecondsFieldName, _expireAfterSeconds.get());
    }

    if (_storageEngine.is_initialized()) {
        builder->append(kStorageEngineFieldName, _storageEngine.get());
    }

    if (_weights.is_initialized()) {
        stdx::visit([builder](auto&& arg) {
            idl::idlSerialize(builder, kWeightsFieldName, arg);
        }, _weights.get());
    }

    if (_default_language.is_initialized()) {
        builder->append(kDefault_languageFieldName, _default_language.get());
    }

    if (_language_override.is_initialized()) {
        builder->append(kLanguage_overrideFieldName, _language_override.get());
    }

    if (_textIndexVersion.is_initialized()) {
        builder->append(kTextIndexVersionFieldName, _textIndexVersion.get());
    }

    if (_2dsphereIndexVersion.is_initialized()) {
        builder->append(k2dsphereIndexVersionFieldName, _2dsphereIndexVersion.get());
    }

    if (_bits.is_initialized()) {
        builder->append(kBitsFieldName, _bits.get());
    }

    if (_min.is_initialized()) {
        builder->append(kMinFieldName, _min.get());
    }

    if (_max.is_initialized()) {
        builder->append(kMaxFieldName, _max.get());
    }

    if (_bucketSize.is_initialized()) {
        builder->append(kBucketSizeFieldName, _bucketSize.get());
    }

    if (_collation.is_initialized()) {
        builder->append(kCollationFieldName, _collation.get());
    }

    if (_wildcardProjection.is_initialized()) {
        builder->append(kWildcardProjectionFieldName, _wildcardProjection.get());
    }

    if (_coarsestIndexedLevel.is_initialized()) {
        builder->append(kCoarsestIndexedLevelFieldName, _coarsestIndexedLevel.get());
    }

    if (_finestIndexedLevel.is_initialized()) {
        builder->append(kFinestIndexedLevelFieldName, _finestIndexedLevel.get());
    }

    if (_dropDups.is_initialized()) {
        builder->append(kDropDupsFieldName, _dropDups.get());
    }

}


BSONObj NewIndexSpec::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData CreateIndexesCommand::kCommitQuorumFieldName;
constexpr StringData CreateIndexesCommand::kDbNameFieldName;
constexpr StringData CreateIndexesCommand::kIgnoreUnknownIndexOptionsFieldName;
constexpr StringData CreateIndexesCommand::kIndexesFieldName;
constexpr StringData CreateIndexesCommand::kIsTimeseriesNamespaceFieldName;
constexpr StringData CreateIndexesCommand::kVFieldName;
constexpr StringData CreateIndexesCommand::kCommandName;

mongo::AuthorizationContract CreateIndexesCommand::kAuthorizationContract = AuthorizationContract(std::initializer_list<AccessCheckEnum>{}, std::initializer_list<Privilege>{Privilege(ResourcePattern::forAuthorizationContract(MatchTypeEnum::kMatchExactNamespace), ActionSet{ActionType::createIndex})});

const std::vector<StringData> CreateIndexesCommand::_knownBSONFields {
    CreateIndexesCommand::kCommitQuorumFieldName,
    CreateIndexesCommand::kIgnoreUnknownIndexOptionsFieldName,
    CreateIndexesCommand::kIndexesFieldName,
    CreateIndexesCommand::kIsTimeseriesNamespaceFieldName,
    CreateIndexesCommand::kVFieldName,
    CreateIndexesCommand::kCommandName,
};
const std::vector<StringData> CreateIndexesCommand::_knownOP_MSGFields {
    CreateIndexesCommand::kCommitQuorumFieldName,
    CreateIndexesCommand::kDbNameFieldName,
    CreateIndexesCommand::kIgnoreUnknownIndexOptionsFieldName,
    CreateIndexesCommand::kIndexesFieldName,
    CreateIndexesCommand::kIsTimeseriesNamespaceFieldName,
    CreateIndexesCommand::kVFieldName,
    CreateIndexesCommand::kCommandName,
};

CreateIndexesCommand::CreateIndexesCommand(const NamespaceString nss) : _nss(std::move(nss)), _dbName(nss.db().toString()), _hasIndexes(false), _hasDbName(true) {
    // Used for initialization only
}
CreateIndexesCommand::CreateIndexesCommand(const NamespaceString nss, std::vector<mongo::BSONObj> indexes) : _nss(std::move(nss)), _indexes(std::move(indexes)), _dbName(nss.db().toString()), _hasIndexes(true), _hasDbName(true) {
    // Used for initialization only
}


CreateIndexesCommand CreateIndexesCommand::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    NamespaceString localNS;
    CreateIndexesCommand object(localNS);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void CreateIndexesCommand::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<6> usedFields;
    const size_t kVBit = 0;
    const size_t kIndexesBit = 1;
    const size_t kIgnoreUnknownIndexOptionsBit = 2;
    const size_t kCommitQuorumBit = 3;
    const size_t kIsTimeseriesNamespaceBit = 4;
    const size_t kDbNameBit = 5;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kVFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kVBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kVBit);

                _v = element.safeNumberInt();
            }
        }
        else if (fieldName == kIndexesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kIndexesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIndexesBit);

                _hasIndexes = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kIndexesFieldName, &ctxt);
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
            _indexes = std::move(values);
        }
        else if (fieldName == kIgnoreUnknownIndexOptionsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kIgnoreUnknownIndexOptionsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIgnoreUnknownIndexOptionsBit);

                _ignoreUnknownIndexOptions = element.trueValue();
            }
        }
        else if (fieldName == kCommitQuorumFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble, String}))) {
                if (MONGO_unlikely(usedFields[kCommitQuorumBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCommitQuorumBit);

                _commitQuorum = CommitQuorumOptions::deserializerForIDL(element);
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
        if (!usedFields[kVBit]) {
            _v = 2;
        }
        if (!usedFields[kIndexesBit]) {
            ctxt.throwMissingField(kIndexesFieldName);
        }
        if (!usedFields[kIgnoreUnknownIndexOptionsBit]) {
            _ignoreUnknownIndexOptions = false;
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

CreateIndexesCommand CreateIndexesCommand::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    NamespaceString localNS;
    CreateIndexesCommand object(localNS);
    object.parseProtected(ctxt, request);
    return object;
}
void CreateIndexesCommand::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<6> usedFields;
    const size_t kVBit = 0;
    const size_t kIndexesBit = 1;
    const size_t kIgnoreUnknownIndexOptionsBit = 2;
    const size_t kCommitQuorumBit = 3;
    const size_t kIsTimeseriesNamespaceBit = 4;
    const size_t kDbNameBit = 5;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kVFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kVBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kVBit);

                _v = element.safeNumberInt();
            }
        }
        else if (fieldName == kIndexesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kIndexesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIndexesBit);

                _hasIndexes = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kIndexesFieldName, &ctxt);
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
            _indexes = std::move(values);
        }
        else if (fieldName == kIgnoreUnknownIndexOptionsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kIgnoreUnknownIndexOptionsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIgnoreUnknownIndexOptionsBit);

                _ignoreUnknownIndexOptions = element.trueValue();
            }
        }
        else if (fieldName == kCommitQuorumFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble, String}))) {
                if (MONGO_unlikely(usedFields[kCommitQuorumBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCommitQuorumBit);

                _commitQuorum = CommitQuorumOptions::deserializerForIDL(element);
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
        if (!usedFields[kVBit]) {
            _v = 2;
        }
        if (!usedFields[kIndexesBit]) {
            ctxt.throwMissingField(kIndexesFieldName);
        }
        if (!usedFields[kIgnoreUnknownIndexOptionsBit]) {
            _ignoreUnknownIndexOptions = false;
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

void CreateIndexesCommand::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasIndexes && _hasDbName);

    invariant(!_nss.isEmpty());
    builder->append("createIndexes"_sd, _nss.coll());

    builder->append(kVFieldName, _v);

    {
        builder->append(kIndexesFieldName, _indexes);
    }

    builder->append(kIgnoreUnknownIndexOptionsFieldName, _ignoreUnknownIndexOptions);

    if (_commitQuorum.is_initialized()) {
        _commitQuorum.get().appendToBuilder(kCommitQuorumFieldName, builder);
    }

    if (_isTimeseriesNamespace.is_initialized()) {
        builder->append(kIsTimeseriesNamespaceFieldName, _isTimeseriesNamespace.get());
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest CreateIndexesCommand::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasIndexes && _hasDbName);

        invariant(!_nss.isEmpty());
        builder->append("createIndexes"_sd, _nss.coll());

        builder->append(kVFieldName, _v);

        {
            builder->append(kIndexesFieldName, _indexes);
        }

        builder->append(kIgnoreUnknownIndexOptionsFieldName, _ignoreUnknownIndexOptions);

        if (_commitQuorum.is_initialized()) {
            _commitQuorum.get().appendToBuilder(kCommitQuorumFieldName, builder);
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

BSONObj CreateIndexesCommand::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
