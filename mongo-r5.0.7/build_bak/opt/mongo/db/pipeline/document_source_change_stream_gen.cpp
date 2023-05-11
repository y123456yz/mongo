/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/pipeline/document_source_change_stream_gen.h --output build/opt/mongo/db/pipeline/document_source_change_stream_gen.cpp src/mongo/db/pipeline/document_source_change_stream.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/pipeline/document_source_change_stream_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

/**
 * Possible modes for the 'fullDocumentBeforeChange' parameter of the $changeStream stage.
 */
namespace  {
constexpr StringData kFullDocumentBeforeChangeMode_kOff = "off"_sd;
constexpr StringData kFullDocumentBeforeChangeMode_kWhenAvailable = "whenAvailable"_sd;
constexpr StringData kFullDocumentBeforeChangeMode_kRequired = "required"_sd;
}  // namespace 

FullDocumentBeforeChangeModeEnum FullDocumentBeforeChangeMode_parse(const IDLParserErrorContext& ctxt, StringData value) {
    if (value == kFullDocumentBeforeChangeMode_kOff) {
        return FullDocumentBeforeChangeModeEnum::kOff;
    }
    if (value == kFullDocumentBeforeChangeMode_kWhenAvailable) {
        return FullDocumentBeforeChangeModeEnum::kWhenAvailable;
    }
    if (value == kFullDocumentBeforeChangeMode_kRequired) {
        return FullDocumentBeforeChangeModeEnum::kRequired;
    }
    ctxt.throwBadEnumValue(value);
}

StringData FullDocumentBeforeChangeMode_serializer(FullDocumentBeforeChangeModeEnum value) {
    if (value == FullDocumentBeforeChangeModeEnum::kOff) {
        return kFullDocumentBeforeChangeMode_kOff;
    }
    if (value == FullDocumentBeforeChangeModeEnum::kWhenAvailable) {
        return kFullDocumentBeforeChangeMode_kWhenAvailable;
    }
    if (value == FullDocumentBeforeChangeModeEnum::kRequired) {
        return kFullDocumentBeforeChangeMode_kRequired;
    }
    MONGO_UNREACHABLE;
    return StringData();
}

/**
 * Possible modes for the 'fullDocument' parameter of the $changeStream stage.
 */
namespace  {
constexpr StringData kFullDocumentMode_kUpdateLookup = "updateLookup"_sd;
constexpr StringData kFullDocumentMode_kDefault = "default"_sd;
}  // namespace 

FullDocumentModeEnum FullDocumentMode_parse(const IDLParserErrorContext& ctxt, StringData value) {
    if (value == kFullDocumentMode_kUpdateLookup) {
        return FullDocumentModeEnum::kUpdateLookup;
    }
    if (value == kFullDocumentMode_kDefault) {
        return FullDocumentModeEnum::kDefault;
    }
    ctxt.throwBadEnumValue(value);
}

StringData FullDocumentMode_serializer(FullDocumentModeEnum value) {
    if (value == FullDocumentModeEnum::kUpdateLookup) {
        return kFullDocumentMode_kUpdateLookup;
    }
    if (value == FullDocumentModeEnum::kDefault) {
        return kFullDocumentMode_kDefault;
    }
    MONGO_UNREACHABLE;
    return StringData();
}

constexpr StringData ResumeTokenClusterTime::kTimestampFieldName;


ResumeTokenClusterTime::ResumeTokenClusterTime() : _timestamp(mongo::idl::preparsedValue<decltype(_timestamp)>()), _hasTimestamp(false) {
    // Used for initialization only
}
ResumeTokenClusterTime::ResumeTokenClusterTime(mongo::Timestamp timestamp) : _timestamp(std::move(timestamp)), _hasTimestamp(true) {
    // Used for initialization only
}


ResumeTokenClusterTime ResumeTokenClusterTime::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ResumeTokenClusterTime>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ResumeTokenClusterTime::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kTimestampBit = 0;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kTimestampFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, bsonTimestamp))) {
                if (MONGO_unlikely(usedFields[kTimestampBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTimestampBit);

                _hasTimestamp = true;
                _timestamp = element.timestamp();
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kTimestampBit]) {
            ctxt.throwMissingField(kTimestampFieldName);
        }
    }

}


void ResumeTokenClusterTime::serialize(BSONObjBuilder* builder) const {
    invariant(_hasTimestamp);

    builder->append(kTimestampFieldName, _timestamp);

}


BSONObj ResumeTokenClusterTime::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData DocumentSourceChangeStreamSpec::kAllChangesForClusterFieldName;
constexpr StringData DocumentSourceChangeStreamSpec::kAllowToRunOnConfigDBFieldName;
constexpr StringData DocumentSourceChangeStreamSpec::kAllowToRunOnSystemNSFieldName;
constexpr StringData DocumentSourceChangeStreamSpec::kFullDocumentFieldName;
constexpr StringData DocumentSourceChangeStreamSpec::kFullDocumentBeforeChangeFieldName;
constexpr StringData DocumentSourceChangeStreamSpec::kResumeAfterFieldName;
constexpr StringData DocumentSourceChangeStreamSpec::kShowMigrationEventsFieldName;
constexpr StringData DocumentSourceChangeStreamSpec::kStartAfterFieldName;
constexpr StringData DocumentSourceChangeStreamSpec::kStartAtOperationTimeFieldName;


DocumentSourceChangeStreamSpec::DocumentSourceChangeStreamSpec()  {
    // Used for initialization only
}


DocumentSourceChangeStreamSpec DocumentSourceChangeStreamSpec::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<DocumentSourceChangeStreamSpec>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void DocumentSourceChangeStreamSpec::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<9> usedFields;
    const size_t kResumeAfterBit = 0;
    const size_t kStartAfterBit = 1;
    const size_t kStartAtOperationTimeBit = 2;
    const size_t kFullDocumentBit = 3;
    const size_t kFullDocumentBeforeChangeBit = 4;
    const size_t kAllChangesForClusterBit = 5;
    const size_t kShowMigrationEventsBit = 6;
    const size_t kAllowToRunOnConfigDBBit = 7;
    const size_t kAllowToRunOnSystemNSBit = 8;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kResumeAfterFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kResumeAfterBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kResumeAfterBit);

                const BSONObj localObject = element.Obj();
                _resumeAfter = ResumeToken::parse(localObject);
            }
        }
        else if (fieldName == kStartAfterFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kStartAfterBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStartAfterBit);

                const BSONObj localObject = element.Obj();
                _startAfter = ResumeToken::parse(localObject);
            }
        }
        else if (fieldName == kStartAtOperationTimeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, bsonTimestamp))) {
                if (MONGO_unlikely(usedFields[kStartAtOperationTimeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStartAtOperationTimeBit);

                _startAtOperationTime = element.timestamp();
            }
        }
        else if (fieldName == kFullDocumentFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kFullDocumentBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kFullDocumentBit);

                IDLParserErrorContext tempContext(kFullDocumentFieldName, &ctxt);
                _fullDocument = FullDocumentMode_parse(tempContext, element.valueStringData());
            }
        }
        else if (fieldName == kFullDocumentBeforeChangeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kFullDocumentBeforeChangeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kFullDocumentBeforeChangeBit);

                IDLParserErrorContext tempContext(kFullDocumentBeforeChangeFieldName, &ctxt);
                _fullDocumentBeforeChange = FullDocumentBeforeChangeMode_parse(tempContext, element.valueStringData());
            }
        }
        else if (fieldName == kAllChangesForClusterFieldName) {
            if (MONGO_unlikely(usedFields[kAllChangesForClusterBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kAllChangesForClusterBit);

            _allChangesForCluster = OptionalBool::parseFromBSON(element);
        }
        else if (fieldName == kShowMigrationEventsFieldName) {
            if (MONGO_unlikely(usedFields[kShowMigrationEventsBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kShowMigrationEventsBit);

            _showMigrationEvents = OptionalBool::parseFromBSON(element);
        }
        else if (fieldName == kAllowToRunOnConfigDBFieldName) {
            if (MONGO_unlikely(usedFields[kAllowToRunOnConfigDBBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kAllowToRunOnConfigDBBit);

            _allowToRunOnConfigDB = OptionalBool::parseFromBSON(element);
        }
        else if (fieldName == kAllowToRunOnSystemNSFieldName) {
            if (MONGO_unlikely(usedFields[kAllowToRunOnSystemNSBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kAllowToRunOnSystemNSBit);

            _allowToRunOnSystemNS = OptionalBool::parseFromBSON(element);
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kFullDocumentBit]) {
            _fullDocument = mongo::FullDocumentModeEnum::kDefault;
        }
        if (!usedFields[kFullDocumentBeforeChangeBit]) {
            _fullDocumentBeforeChange = mongo::FullDocumentBeforeChangeModeEnum::kOff;
        }
        if (!usedFields[kAllChangesForClusterBit]) {
            _allChangesForCluster = mongo::OptionalBool();
        }
        if (!usedFields[kShowMigrationEventsBit]) {
            _showMigrationEvents = mongo::OptionalBool();
        }
        if (!usedFields[kAllowToRunOnConfigDBBit]) {
            _allowToRunOnConfigDB = mongo::OptionalBool();
        }
        if (!usedFields[kAllowToRunOnSystemNSBit]) {
            _allowToRunOnSystemNS = mongo::OptionalBool();
        }
    }

}


void DocumentSourceChangeStreamSpec::serialize(BSONObjBuilder* builder) const {
    if (_resumeAfter.is_initialized()) {
        const BSONObj localObject = _resumeAfter.get().toBSON();
        builder->append(kResumeAfterFieldName, localObject);
    }

    if (_startAfter.is_initialized()) {
        const BSONObj localObject = _startAfter.get().toBSON();
        builder->append(kStartAfterFieldName, localObject);
    }

    if (_startAtOperationTime.is_initialized()) {
        builder->append(kStartAtOperationTimeFieldName, _startAtOperationTime.get());
    }

    {
        builder->append(kFullDocumentFieldName, ::mongo::FullDocumentMode_serializer(_fullDocument));
    }

    {
        builder->append(kFullDocumentBeforeChangeFieldName, ::mongo::FullDocumentBeforeChangeMode_serializer(_fullDocumentBeforeChange));
    }

    {
        _allChangesForCluster.serializeToBSON(kAllChangesForClusterFieldName, builder);
    }

    {
        _showMigrationEvents.serializeToBSON(kShowMigrationEventsFieldName, builder);
    }

    {
        _allowToRunOnConfigDB.serializeToBSON(kAllowToRunOnConfigDBFieldName, builder);
    }

    {
        _allowToRunOnSystemNS.serializeToBSON(kAllowToRunOnSystemNSFieldName, builder);
    }

}


BSONObj DocumentSourceChangeStreamSpec::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData DocumentSourceChangeStreamOplogMatchSpec::kFilterFieldName;


DocumentSourceChangeStreamOplogMatchSpec::DocumentSourceChangeStreamOplogMatchSpec() : _filter(mongo::idl::preparsedValue<decltype(_filter)>()), _hasFilter(false) {
    // Used for initialization only
}
DocumentSourceChangeStreamOplogMatchSpec::DocumentSourceChangeStreamOplogMatchSpec(mongo::BSONObj filter) : _filter(std::move(filter)), _hasFilter(true) {
    // Used for initialization only
}


DocumentSourceChangeStreamOplogMatchSpec DocumentSourceChangeStreamOplogMatchSpec::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<DocumentSourceChangeStreamOplogMatchSpec>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void DocumentSourceChangeStreamOplogMatchSpec::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kFilterBit = 0;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kFilterFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kFilterBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kFilterBit);

                _hasFilter = true;
                const BSONObj localObject = element.Obj();
                _filter = BSONObj::getOwned(localObject);
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kFilterBit]) {
            ctxt.throwMissingField(kFilterFieldName);
        }
    }

}


void DocumentSourceChangeStreamOplogMatchSpec::serialize(BSONObjBuilder* builder) const {
    invariant(_hasFilter);

    builder->append(kFilterFieldName, _filter);

}


BSONObj DocumentSourceChangeStreamOplogMatchSpec::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData DocumentSourceChangeStreamUnwindTransactionSpec::kNsRegexFieldName;


DocumentSourceChangeStreamUnwindTransactionSpec::DocumentSourceChangeStreamUnwindTransactionSpec() : _nsRegex(mongo::idl::preparsedValue<decltype(_nsRegex)>()), _hasNsRegex(false) {
    // Used for initialization only
}
DocumentSourceChangeStreamUnwindTransactionSpec::DocumentSourceChangeStreamUnwindTransactionSpec(std::string nsRegex) : _nsRegex(std::move(nsRegex)), _hasNsRegex(true) {
    // Used for initialization only
}


DocumentSourceChangeStreamUnwindTransactionSpec DocumentSourceChangeStreamUnwindTransactionSpec::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<DocumentSourceChangeStreamUnwindTransactionSpec>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void DocumentSourceChangeStreamUnwindTransactionSpec::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kNsRegexBit = 0;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kNsRegexFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kNsRegexBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNsRegexBit);

                _hasNsRegex = true;
                _nsRegex = element.str();
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kNsRegexBit]) {
            ctxt.throwMissingField(kNsRegexFieldName);
        }
    }

}


void DocumentSourceChangeStreamUnwindTransactionSpec::serialize(BSONObjBuilder* builder) const {
    invariant(_hasNsRegex);

    builder->append(kNsRegexFieldName, _nsRegex);

}


BSONObj DocumentSourceChangeStreamUnwindTransactionSpec::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData DocumentSourceChangeStreamCheckInvalidateSpec::kStartAfterInvalidateFieldName;


DocumentSourceChangeStreamCheckInvalidateSpec::DocumentSourceChangeStreamCheckInvalidateSpec()  {
    // Used for initialization only
}


DocumentSourceChangeStreamCheckInvalidateSpec DocumentSourceChangeStreamCheckInvalidateSpec::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<DocumentSourceChangeStreamCheckInvalidateSpec>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void DocumentSourceChangeStreamCheckInvalidateSpec::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kStartAfterInvalidateBit = 0;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kStartAfterInvalidateFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kStartAfterInvalidateBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStartAfterInvalidateBit);

                const BSONObj localObject = element.Obj();
                _startAfterInvalidate = ResumeToken::parse(localObject);
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
    }

}


void DocumentSourceChangeStreamCheckInvalidateSpec::serialize(BSONObjBuilder* builder) const {
    if (_startAfterInvalidate.is_initialized()) {
        const BSONObj localObject = _startAfterInvalidate.get().toBSON();
        builder->append(kStartAfterInvalidateFieldName, localObject);
    }

}


BSONObj DocumentSourceChangeStreamCheckInvalidateSpec::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData DocumentSourceChangeStreamCheckResumabilitySpec::kResumeTokenFieldName;


DocumentSourceChangeStreamCheckResumabilitySpec::DocumentSourceChangeStreamCheckResumabilitySpec() : _resumeToken(mongo::idl::preparsedValue<decltype(_resumeToken)>()), _hasResumeToken(false) {
    // Used for initialization only
}
DocumentSourceChangeStreamCheckResumabilitySpec::DocumentSourceChangeStreamCheckResumabilitySpec(mongo::ResumeToken resumeToken) : _resumeToken(std::move(resumeToken)), _hasResumeToken(true) {
    // Used for initialization only
}


DocumentSourceChangeStreamCheckResumabilitySpec DocumentSourceChangeStreamCheckResumabilitySpec::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<DocumentSourceChangeStreamCheckResumabilitySpec>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void DocumentSourceChangeStreamCheckResumabilitySpec::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kResumeTokenBit = 0;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kResumeTokenFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kResumeTokenBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kResumeTokenBit);

                _hasResumeToken = true;
                const BSONObj localObject = element.Obj();
                _resumeToken = ResumeToken::parse(localObject);
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kResumeTokenBit]) {
            ctxt.throwMissingField(kResumeTokenFieldName);
        }
    }

}


void DocumentSourceChangeStreamCheckResumabilitySpec::serialize(BSONObjBuilder* builder) const {
    invariant(_hasResumeToken);

    {
        const BSONObj localObject = _resumeToken.toBSON();
        builder->append(kResumeTokenFieldName, localObject);
    }

}


BSONObj DocumentSourceChangeStreamCheckResumabilitySpec::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData DocumentSourceChangeStreamLookUpPreImageSpec::kFullDocumentBeforeChangeFieldName;


DocumentSourceChangeStreamLookUpPreImageSpec::DocumentSourceChangeStreamLookUpPreImageSpec() : _fullDocumentBeforeChange(mongo::idl::preparsedValue<decltype(_fullDocumentBeforeChange)>()), _hasFullDocumentBeforeChange(false) {
    // Used for initialization only
}
DocumentSourceChangeStreamLookUpPreImageSpec::DocumentSourceChangeStreamLookUpPreImageSpec(mongo::FullDocumentBeforeChangeModeEnum fullDocumentBeforeChange) : _fullDocumentBeforeChange(std::move(fullDocumentBeforeChange)), _hasFullDocumentBeforeChange(true) {
    // Used for initialization only
}


DocumentSourceChangeStreamLookUpPreImageSpec DocumentSourceChangeStreamLookUpPreImageSpec::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<DocumentSourceChangeStreamLookUpPreImageSpec>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void DocumentSourceChangeStreamLookUpPreImageSpec::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kFullDocumentBeforeChangeBit = 0;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kFullDocumentBeforeChangeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kFullDocumentBeforeChangeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kFullDocumentBeforeChangeBit);

                _hasFullDocumentBeforeChange = true;
                IDLParserErrorContext tempContext(kFullDocumentBeforeChangeFieldName, &ctxt);
                _fullDocumentBeforeChange = FullDocumentBeforeChangeMode_parse(tempContext, element.valueStringData());
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kFullDocumentBeforeChangeBit]) {
            ctxt.throwMissingField(kFullDocumentBeforeChangeFieldName);
        }
    }

}


void DocumentSourceChangeStreamLookUpPreImageSpec::serialize(BSONObjBuilder* builder) const {
    invariant(_hasFullDocumentBeforeChange);

    {
        builder->append(kFullDocumentBeforeChangeFieldName, ::mongo::FullDocumentBeforeChangeMode_serializer(_fullDocumentBeforeChange));
    }

}


BSONObj DocumentSourceChangeStreamLookUpPreImageSpec::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData DocumentSourceChangeStreamLookUpPostImageSpec::kFullDocumentFieldName;


DocumentSourceChangeStreamLookUpPostImageSpec::DocumentSourceChangeStreamLookUpPostImageSpec() : _fullDocument(mongo::idl::preparsedValue<decltype(_fullDocument)>()), _hasFullDocument(false) {
    // Used for initialization only
}
DocumentSourceChangeStreamLookUpPostImageSpec::DocumentSourceChangeStreamLookUpPostImageSpec(mongo::FullDocumentModeEnum fullDocument) : _fullDocument(std::move(fullDocument)), _hasFullDocument(true) {
    // Used for initialization only
}


DocumentSourceChangeStreamLookUpPostImageSpec DocumentSourceChangeStreamLookUpPostImageSpec::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<DocumentSourceChangeStreamLookUpPostImageSpec>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void DocumentSourceChangeStreamLookUpPostImageSpec::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kFullDocumentBit = 0;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kFullDocumentFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kFullDocumentBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kFullDocumentBit);

                _hasFullDocument = true;
                IDLParserErrorContext tempContext(kFullDocumentFieldName, &ctxt);
                _fullDocument = FullDocumentMode_parse(tempContext, element.valueStringData());
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kFullDocumentBit]) {
            ctxt.throwMissingField(kFullDocumentFieldName);
        }
    }

}


void DocumentSourceChangeStreamLookUpPostImageSpec::serialize(BSONObjBuilder* builder) const {
    invariant(_hasFullDocument);

    {
        builder->append(kFullDocumentFieldName, ::mongo::FullDocumentMode_serializer(_fullDocument));
    }

}


BSONObj DocumentSourceChangeStreamLookUpPostImageSpec::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
