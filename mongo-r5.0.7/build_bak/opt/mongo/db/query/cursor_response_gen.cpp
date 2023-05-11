/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/query/cursor_response_gen.h --output build/opt/mongo/db/query/cursor_response_gen.cpp src/mongo/db/query/cursor_response.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/query/cursor_response_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData ResponseCursorBase::kAtClusterTimeFieldName;
constexpr StringData ResponseCursorBase::kCursorIdFieldName;
constexpr StringData ResponseCursorBase::kInvalidatedFieldName;
constexpr StringData ResponseCursorBase::kNsFieldName;
constexpr StringData ResponseCursorBase::kPartialResultsReturnedFieldName;
constexpr StringData ResponseCursorBase::kPostBatchResumeTokenFieldName;


ResponseCursorBase::ResponseCursorBase() : _cursorId(mongo::idl::preparsedValue<decltype(_cursorId)>()), _ns(mongo::idl::preparsedValue<decltype(_ns)>()), _hasCursorId(false), _hasNs(false) {
    // Used for initialization only
}
ResponseCursorBase::ResponseCursorBase(std::int64_t cursorId, mongo::NamespaceString ns) : _cursorId(std::move(cursorId)), _ns(std::move(ns)), _hasCursorId(true), _hasNs(true) {
    // Used for initialization only
}


ResponseCursorBase ResponseCursorBase::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ResponseCursorBase>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ResponseCursorBase::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<6> usedFields;
    const size_t kCursorIdBit = 0;
    const size_t kNsBit = 1;
    const size_t kPostBatchResumeTokenBit = 2;
    const size_t kAtClusterTimeBit = 3;
    const size_t kPartialResultsReturnedBit = 4;
    const size_t kInvalidatedBit = 5;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kCursorIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kCursorIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCursorIdBit);

                _hasCursorId = true;
                _cursorId = element._numberLong();
            }
        }
        else if (fieldName == kNsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kNsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNsBit);

                _hasNs = true;
                _ns = NamespaceString(element.valueStringData());
            }
        }
        else if (fieldName == kPostBatchResumeTokenFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kPostBatchResumeTokenBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPostBatchResumeTokenBit);

                _postBatchResumeToken = element.Obj();
            }
        }
        else if (fieldName == kAtClusterTimeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, bsonTimestamp))) {
                if (MONGO_unlikely(usedFields[kAtClusterTimeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAtClusterTimeBit);

                _atClusterTime = element.timestamp();
            }
        }
        else if (fieldName == kPartialResultsReturnedFieldName) {
            if (MONGO_unlikely(usedFields[kPartialResultsReturnedBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kPartialResultsReturnedBit);

            _partialResultsReturned = OptionalBool::parseFromBSON(element);
        }
        else if (fieldName == kInvalidatedFieldName) {
            if (MONGO_unlikely(usedFields[kInvalidatedBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kInvalidatedBit);

            _invalidated = OptionalBool::parseFromBSON(element);
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kCursorIdBit]) {
            ctxt.throwMissingField(kCursorIdFieldName);
        }
        if (!usedFields[kNsBit]) {
            ctxt.throwMissingField(kNsFieldName);
        }
        if (!usedFields[kPartialResultsReturnedBit]) {
            _partialResultsReturned = mongo::OptionalBool();
        }
        if (!usedFields[kInvalidatedBit]) {
            _invalidated = mongo::OptionalBool();
        }
    }

}


void ResponseCursorBase::serialize(BSONObjBuilder* builder) const {
    invariant(_hasCursorId && _hasNs);

    builder->append(kCursorIdFieldName, _cursorId);

    {
        builder->append(kNsFieldName, _ns.toString());
    }

    if (_postBatchResumeToken.is_initialized()) {
        builder->append(kPostBatchResumeTokenFieldName, _postBatchResumeToken.get());
    }

    if (_atClusterTime.is_initialized()) {
        builder->append(kAtClusterTimeFieldName, _atClusterTime.get());
    }

    {
        _partialResultsReturned.serializeToBSON(kPartialResultsReturnedFieldName, builder);
    }

    {
        _invalidated.serializeToBSON(kInvalidatedFieldName, builder);
    }

}


BSONObj ResponseCursorBase::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData InitialResponseCursor::kResponseCursorBaseFieldName;
constexpr StringData InitialResponseCursor::kAtClusterTimeFieldName;
constexpr StringData InitialResponseCursor::kCursorIdFieldName;
constexpr StringData InitialResponseCursor::kFirstBatchFieldName;
constexpr StringData InitialResponseCursor::kInvalidatedFieldName;
constexpr StringData InitialResponseCursor::kNsFieldName;
constexpr StringData InitialResponseCursor::kPartialResultsReturnedFieldName;
constexpr StringData InitialResponseCursor::kPostBatchResumeTokenFieldName;


InitialResponseCursor::InitialResponseCursor() : _hasFirstBatch(false) {
    // Used for initialization only
}
InitialResponseCursor::InitialResponseCursor(std::vector<mongo::BSONObj> firstBatch) : _firstBatch(std::move(firstBatch)), _hasFirstBatch(true) {
    // Used for initialization only
}


InitialResponseCursor InitialResponseCursor::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<InitialResponseCursor>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void InitialResponseCursor::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<8> usedFields;
    const size_t kCursorIdBit = 0;
    const size_t kNsBit = 1;
    const size_t kPostBatchResumeTokenBit = 2;
    const size_t kAtClusterTimeBit = 3;
    const size_t kPartialResultsReturnedBit = 4;
    const size_t kInvalidatedBit = 5;
    const size_t kFirstBatchBit = 6;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kCursorIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kCursorIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCursorIdBit);

                _responseCursorBase.setCursorId(element._numberLong());
            }
        }
        else if (fieldName == kNsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kNsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNsBit);

                _responseCursorBase.setNs(NamespaceString(element.valueStringData()));
            }
        }
        else if (fieldName == kPostBatchResumeTokenFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kPostBatchResumeTokenBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPostBatchResumeTokenBit);

                _responseCursorBase.setPostBatchResumeToken(boost::optional<mongo::BSONObj>(element.Obj()));
            }
        }
        else if (fieldName == kAtClusterTimeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, bsonTimestamp))) {
                if (MONGO_unlikely(usedFields[kAtClusterTimeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAtClusterTimeBit);

                _responseCursorBase.setAtClusterTime(boost::optional<mongo::Timestamp>(element.timestamp()));
            }
        }
        else if (fieldName == kPartialResultsReturnedFieldName) {
            if (MONGO_unlikely(usedFields[kPartialResultsReturnedBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kPartialResultsReturnedBit);

            _responseCursorBase.setPartialResultsReturned(OptionalBool::parseFromBSON(element));
        }
        else if (fieldName == kInvalidatedFieldName) {
            if (MONGO_unlikely(usedFields[kInvalidatedBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kInvalidatedBit);

            _responseCursorBase.setInvalidated(OptionalBool::parseFromBSON(element));
        }
        else if (fieldName == kFirstBatchFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kFirstBatchBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kFirstBatchBit);

                _hasFirstBatch = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kFirstBatchFieldName, &ctxt);
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
            _firstBatch = std::move(values);
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kCursorIdBit]) {
            ctxt.throwMissingField(kCursorIdFieldName);
        }
        if (!usedFields[kNsBit]) {
            ctxt.throwMissingField(kNsFieldName);
        }
        if (!usedFields[kPartialResultsReturnedBit]) {
            _responseCursorBase.setPartialResultsReturned(mongo::OptionalBool());
        }
        if (!usedFields[kInvalidatedBit]) {
            _responseCursorBase.setInvalidated(mongo::OptionalBool());
        }
        if (!usedFields[kFirstBatchBit]) {
            ctxt.throwMissingField(kFirstBatchFieldName);
        }
    }

}


void InitialResponseCursor::serialize(BSONObjBuilder* builder) const {
    invariant(_hasFirstBatch);

    {
        _responseCursorBase.serialize(builder);
    }

    {
        builder->append(kFirstBatchFieldName, _firstBatch);
    }

}


BSONObj InitialResponseCursor::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData CursorInitialReply::kCursorFieldName;
constexpr StringData CursorInitialReply::kVarsFieldName;


CursorInitialReply::CursorInitialReply() : _cursor(mongo::idl::preparsedValue<decltype(_cursor)>()), _hasCursor(false) {
    // Used for initialization only
}
CursorInitialReply::CursorInitialReply(mongo::InitialResponseCursor cursor) : _cursor(std::move(cursor)), _hasCursor(true) {
    // Used for initialization only
}


CursorInitialReply CursorInitialReply::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<CursorInitialReply>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void CursorInitialReply::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kCursorBit = 0;
    const size_t kVarsBit = 1;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kCursorFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCursorBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCursorBit);

                _hasCursor = true;
                IDLParserErrorContext tempContext(kCursorFieldName, &ctxt);
                const auto localObject = element.Obj();
                _cursor = mongo::InitialResponseCursor::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kVarsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kVarsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kVarsBit);

                _vars = element.Obj();
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kCursorBit]) {
            ctxt.throwMissingField(kCursorFieldName);
        }
    }

}


void CursorInitialReply::serialize(BSONObjBuilder* builder) const {
    invariant(_hasCursor);

    {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kCursorFieldName));
        _cursor.serialize(&subObjBuilder);
    }

    if (_vars.is_initialized()) {
        builder->append(kVarsFieldName, _vars.get());
    }

}


BSONObj CursorInitialReply::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData GetMoreResponseCursor::kResponseCursorBaseFieldName;
constexpr StringData GetMoreResponseCursor::kAtClusterTimeFieldName;
constexpr StringData GetMoreResponseCursor::kCursorIdFieldName;
constexpr StringData GetMoreResponseCursor::kInvalidatedFieldName;
constexpr StringData GetMoreResponseCursor::kNextBatchFieldName;
constexpr StringData GetMoreResponseCursor::kNsFieldName;
constexpr StringData GetMoreResponseCursor::kPartialResultsReturnedFieldName;
constexpr StringData GetMoreResponseCursor::kPostBatchResumeTokenFieldName;


GetMoreResponseCursor::GetMoreResponseCursor() : _hasNextBatch(false) {
    // Used for initialization only
}
GetMoreResponseCursor::GetMoreResponseCursor(std::vector<mongo::BSONObj> nextBatch) : _nextBatch(std::move(nextBatch)), _hasNextBatch(true) {
    // Used for initialization only
}


GetMoreResponseCursor GetMoreResponseCursor::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<GetMoreResponseCursor>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void GetMoreResponseCursor::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<8> usedFields;
    const size_t kCursorIdBit = 0;
    const size_t kNsBit = 1;
    const size_t kPostBatchResumeTokenBit = 2;
    const size_t kAtClusterTimeBit = 3;
    const size_t kPartialResultsReturnedBit = 4;
    const size_t kInvalidatedBit = 5;
    const size_t kNextBatchBit = 6;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kCursorIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kCursorIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCursorIdBit);

                _responseCursorBase.setCursorId(element._numberLong());
            }
        }
        else if (fieldName == kNsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kNsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNsBit);

                _responseCursorBase.setNs(NamespaceString(element.valueStringData()));
            }
        }
        else if (fieldName == kPostBatchResumeTokenFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kPostBatchResumeTokenBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPostBatchResumeTokenBit);

                _responseCursorBase.setPostBatchResumeToken(boost::optional<mongo::BSONObj>(element.Obj()));
            }
        }
        else if (fieldName == kAtClusterTimeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, bsonTimestamp))) {
                if (MONGO_unlikely(usedFields[kAtClusterTimeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAtClusterTimeBit);

                _responseCursorBase.setAtClusterTime(boost::optional<mongo::Timestamp>(element.timestamp()));
            }
        }
        else if (fieldName == kPartialResultsReturnedFieldName) {
            if (MONGO_unlikely(usedFields[kPartialResultsReturnedBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kPartialResultsReturnedBit);

            _responseCursorBase.setPartialResultsReturned(OptionalBool::parseFromBSON(element));
        }
        else if (fieldName == kInvalidatedFieldName) {
            if (MONGO_unlikely(usedFields[kInvalidatedBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kInvalidatedBit);

            _responseCursorBase.setInvalidated(OptionalBool::parseFromBSON(element));
        }
        else if (fieldName == kNextBatchFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kNextBatchBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNextBatchBit);

                _hasNextBatch = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kNextBatchFieldName, &ctxt);
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
            _nextBatch = std::move(values);
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kCursorIdBit]) {
            ctxt.throwMissingField(kCursorIdFieldName);
        }
        if (!usedFields[kNsBit]) {
            ctxt.throwMissingField(kNsFieldName);
        }
        if (!usedFields[kPartialResultsReturnedBit]) {
            _responseCursorBase.setPartialResultsReturned(mongo::OptionalBool());
        }
        if (!usedFields[kInvalidatedBit]) {
            _responseCursorBase.setInvalidated(mongo::OptionalBool());
        }
        if (!usedFields[kNextBatchBit]) {
            ctxt.throwMissingField(kNextBatchFieldName);
        }
    }

}


void GetMoreResponseCursor::serialize(BSONObjBuilder* builder) const {
    invariant(_hasNextBatch);

    {
        _responseCursorBase.serialize(builder);
    }

    {
        builder->append(kNextBatchFieldName, _nextBatch);
    }

}


BSONObj GetMoreResponseCursor::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData CursorGetMoreReply::kCursorFieldName;


CursorGetMoreReply::CursorGetMoreReply() : _cursor(mongo::idl::preparsedValue<decltype(_cursor)>()), _hasCursor(false) {
    // Used for initialization only
}
CursorGetMoreReply::CursorGetMoreReply(mongo::GetMoreResponseCursor cursor) : _cursor(std::move(cursor)), _hasCursor(true) {
    // Used for initialization only
}


CursorGetMoreReply CursorGetMoreReply::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<CursorGetMoreReply>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void CursorGetMoreReply::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kCursorBit = 0;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kCursorFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCursorBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCursorBit);

                _hasCursor = true;
                IDLParserErrorContext tempContext(kCursorFieldName, &ctxt);
                const auto localObject = element.Obj();
                _cursor = mongo::GetMoreResponseCursor::parse(tempContext, localObject);
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kCursorBit]) {
            ctxt.throwMissingField(kCursorFieldName);
        }
    }

}


void CursorGetMoreReply::serialize(BSONObjBuilder* builder) const {
    invariant(_hasCursor);

    {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kCursorFieldName));
        _cursor.serialize(&subObjBuilder);
    }

}


BSONObj CursorGetMoreReply::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
