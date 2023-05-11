/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/ops/write_ops_gen.h --output build/opt/mongo/db/ops/write_ops_gen.cpp src/mongo/db/ops/write_ops.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/ops/write_ops_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {
namespace write_ops {

constexpr StringData WriteCommandReplyBase::kElectionIdFieldName;
constexpr StringData WriteCommandReplyBase::kNFieldName;
constexpr StringData WriteCommandReplyBase::kOpTimeFieldName;
constexpr StringData WriteCommandReplyBase::kWriteErrorsFieldName;


WriteCommandReplyBase::WriteCommandReplyBase()  {
    // Used for initialization only
}


WriteCommandReplyBase WriteCommandReplyBase::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<WriteCommandReplyBase>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void WriteCommandReplyBase::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<4> usedFields;
    const size_t kNBit = 0;
    const size_t kElectionIdBit = 1;
    const size_t kOpTimeBit = 2;
    const size_t kWriteErrorsBit = 3;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kNFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberInt))) {
                if (MONGO_unlikely(usedFields[kNBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNBit);

                _n = element._numberInt();
            }
        }
        else if (fieldName == kElectionIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, jstOID))) {
                if (MONGO_unlikely(usedFields[kElectionIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kElectionIdBit);

                _electionId = element.OID();
            }
        }
        else if (fieldName == kOpTimeFieldName) {
            if (MONGO_unlikely(usedFields[kOpTimeBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kOpTimeBit);

            _opTime = write_ops::opTimeParser(element);
        }
        else if (fieldName == kWriteErrorsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kWriteErrorsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kWriteErrorsBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kWriteErrorsFieldName, &ctxt);
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
                        const BSONObj localObject = arrayElement.Obj();
                        values.emplace_back(BSONObj::getOwned(localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _writeErrors = std::move(values);
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kNBit]) {
            _n = 0;
        }
    }

}


void WriteCommandReplyBase::serialize(BSONObjBuilder* builder) const {
    builder->append(kNFieldName, _n);

    if (_electionId.is_initialized()) {
        builder->append(kElectionIdFieldName, _electionId.get());
    }

    if (_opTime.is_initialized()) {
        opTimeSerializerWithTermCheck(_opTime.get(), kOpTimeFieldName, builder);
    }

    if (_writeErrors.is_initialized()) {
        builder->append(kWriteErrorsFieldName, _writeErrors.get());
    }

}


BSONObj WriteCommandReplyBase::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData InsertCommandReply::kElectionIdFieldName;
constexpr StringData InsertCommandReply::kNFieldName;
constexpr StringData InsertCommandReply::kOpTimeFieldName;
constexpr StringData InsertCommandReply::kWriteCommandReplyBaseFieldName;
constexpr StringData InsertCommandReply::kWriteErrorsFieldName;


InsertCommandReply::InsertCommandReply()  {
    // Used for initialization only
}


InsertCommandReply InsertCommandReply::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<InsertCommandReply>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void InsertCommandReply::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<5> usedFields;
    const size_t kNBit = 0;
    const size_t kElectionIdBit = 1;
    const size_t kOpTimeBit = 2;
    const size_t kWriteErrorsBit = 3;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kNFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberInt))) {
                if (MONGO_unlikely(usedFields[kNBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNBit);

                _writeCommandReplyBase.setN(element._numberInt());
            }
        }
        else if (fieldName == kElectionIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, jstOID))) {
                if (MONGO_unlikely(usedFields[kElectionIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kElectionIdBit);

                _writeCommandReplyBase.setElectionId(boost::optional<mongo::OID>(element.OID()));
            }
        }
        else if (fieldName == kOpTimeFieldName) {
            if (MONGO_unlikely(usedFields[kOpTimeBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kOpTimeBit);

            _writeCommandReplyBase.setOpTime(boost::optional<mongo::repl::OpTime>(write_ops::opTimeParser(element)));
        }
        else if (fieldName == kWriteErrorsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kWriteErrorsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kWriteErrorsBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kWriteErrorsFieldName, &ctxt);
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
                        const BSONObj localObject = arrayElement.Obj();
                        values.emplace_back(BSONObj::getOwned(localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _writeCommandReplyBase.setWriteErrors(std::move(values));
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kNBit]) {
            _writeCommandReplyBase.setN(0);
        }
    }

}


void InsertCommandReply::serialize(BSONObjBuilder* builder) const {
    {
        _writeCommandReplyBase.serialize(builder);
    }

}


BSONObj InsertCommandReply::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData Upserted::k_idFieldName;
constexpr StringData Upserted::kIndexFieldName;


Upserted::Upserted() : _index(mongo::idl::preparsedValue<decltype(_index)>()), __id(mongo::idl::preparsedValue<decltype(__id)>()), _hasIndex(false), _has_id(false) {
    // Used for initialization only
}
Upserted::Upserted(std::int32_t index, mongo::IDLAnyTypeOwned _id) : _index(std::move(index)), __id(std::move(_id)), _hasIndex(true), _has_id(true) {
    // Used for initialization only
}


Upserted Upserted::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<Upserted>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void Upserted::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kIndexBit = 0;
    const size_t k_idBit = 1;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kIndexFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberInt))) {
                if (MONGO_unlikely(usedFields[kIndexBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIndexBit);

                _hasIndex = true;
                _index = element._numberInt();
            }
        }
        else if (fieldName == k_idFieldName) {
            if (MONGO_unlikely(usedFields[k_idBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(k_idBit);

            _has_id = true;
            __id = IDLAnyTypeOwned::parseFromBSON(element);
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kIndexBit]) {
            ctxt.throwMissingField(kIndexFieldName);
        }
        if (!usedFields[k_idBit]) {
            ctxt.throwMissingField(k_idFieldName);
        }
    }

}


void Upserted::serialize(BSONObjBuilder* builder) const {
    invariant(_hasIndex && _has_id);

    builder->append(kIndexFieldName, _index);

    {
        __id.serializeToBSON(k_idFieldName, builder);
    }

}


BSONObj Upserted::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData UpdateCommandReply::kElectionIdFieldName;
constexpr StringData UpdateCommandReply::kNFieldName;
constexpr StringData UpdateCommandReply::kNModifiedFieldName;
constexpr StringData UpdateCommandReply::kOpTimeFieldName;
constexpr StringData UpdateCommandReply::kUpsertedFieldName;
constexpr StringData UpdateCommandReply::kWriteCommandReplyBaseFieldName;
constexpr StringData UpdateCommandReply::kWriteErrorsFieldName;


UpdateCommandReply::UpdateCommandReply()  {
    // Used for initialization only
}


UpdateCommandReply UpdateCommandReply::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<UpdateCommandReply>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void UpdateCommandReply::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<7> usedFields;
    const size_t kNBit = 0;
    const size_t kElectionIdBit = 1;
    const size_t kOpTimeBit = 2;
    const size_t kWriteErrorsBit = 3;
    const size_t kUpsertedBit = 4;
    const size_t kNModifiedBit = 5;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kNFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberInt))) {
                if (MONGO_unlikely(usedFields[kNBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNBit);

                _writeCommandReplyBase.setN(element._numberInt());
            }
        }
        else if (fieldName == kElectionIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, jstOID))) {
                if (MONGO_unlikely(usedFields[kElectionIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kElectionIdBit);

                _writeCommandReplyBase.setElectionId(boost::optional<mongo::OID>(element.OID()));
            }
        }
        else if (fieldName == kOpTimeFieldName) {
            if (MONGO_unlikely(usedFields[kOpTimeBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kOpTimeBit);

            _writeCommandReplyBase.setOpTime(boost::optional<mongo::repl::OpTime>(write_ops::opTimeParser(element)));
        }
        else if (fieldName == kWriteErrorsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kWriteErrorsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kWriteErrorsBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kWriteErrorsFieldName, &ctxt);
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
                        const BSONObj localObject = arrayElement.Obj();
                        values.emplace_back(BSONObj::getOwned(localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _writeCommandReplyBase.setWriteErrors(std::move(values));
        }
        else if (fieldName == kUpsertedFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kUpsertedBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUpsertedBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kUpsertedFieldName, &ctxt);
            std::vector<mongo::write_ops::Upserted> values;

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
                        IDLParserErrorContext tempContext(kUpsertedFieldName, &ctxt);
                        const auto localObject = arrayElement.Obj();
                        values.emplace_back(mongo::write_ops::Upserted::parse(tempContext, localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _upserted = std::move(values);
        }
        else if (fieldName == kNModifiedFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberInt))) {
                if (MONGO_unlikely(usedFields[kNModifiedBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNModifiedBit);

                _nModified = element._numberInt();
            }
        }
        else {
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kNBit]) {
            _writeCommandReplyBase.setN(0);
        }
        if (!usedFields[kNModifiedBit]) {
            _nModified = 0;
        }
    }

}


void UpdateCommandReply::serialize(BSONObjBuilder* builder) const {
    {
        _writeCommandReplyBase.serialize(builder);
    }

    if (_upserted.is_initialized()) {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kUpsertedFieldName));
        for (const auto& item : _upserted.get()) {
            BSONObjBuilder subObjBuilder(arrayBuilder.subobjStart());
            item.serialize(&subObjBuilder);
        }
    }

    builder->append(kNModifiedFieldName, _nModified);

}


BSONObj UpdateCommandReply::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData DeleteCommandReply::kElectionIdFieldName;
constexpr StringData DeleteCommandReply::kNFieldName;
constexpr StringData DeleteCommandReply::kOpTimeFieldName;
constexpr StringData DeleteCommandReply::kWriteCommandReplyBaseFieldName;
constexpr StringData DeleteCommandReply::kWriteErrorsFieldName;


DeleteCommandReply::DeleteCommandReply()  {
    // Used for initialization only
}


DeleteCommandReply DeleteCommandReply::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<DeleteCommandReply>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void DeleteCommandReply::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<5> usedFields;
    const size_t kNBit = 0;
    const size_t kElectionIdBit = 1;
    const size_t kOpTimeBit = 2;
    const size_t kWriteErrorsBit = 3;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kNFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberInt))) {
                if (MONGO_unlikely(usedFields[kNBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNBit);

                _writeCommandReplyBase.setN(element._numberInt());
            }
        }
        else if (fieldName == kElectionIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, jstOID))) {
                if (MONGO_unlikely(usedFields[kElectionIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kElectionIdBit);

                _writeCommandReplyBase.setElectionId(boost::optional<mongo::OID>(element.OID()));
            }
        }
        else if (fieldName == kOpTimeFieldName) {
            if (MONGO_unlikely(usedFields[kOpTimeBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kOpTimeBit);

            _writeCommandReplyBase.setOpTime(boost::optional<mongo::repl::OpTime>(write_ops::opTimeParser(element)));
        }
        else if (fieldName == kWriteErrorsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kWriteErrorsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kWriteErrorsBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kWriteErrorsFieldName, &ctxt);
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
                        const BSONObj localObject = arrayElement.Obj();
                        values.emplace_back(BSONObj::getOwned(localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _writeCommandReplyBase.setWriteErrors(std::move(values));
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kNBit]) {
            _writeCommandReplyBase.setN(0);
        }
    }

}


void DeleteCommandReply::serialize(BSONObjBuilder* builder) const {
    {
        _writeCommandReplyBase.serialize(builder);
    }

}


BSONObj DeleteCommandReply::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData WriteCommandRequestBase::kBypassDocumentValidationFieldName;
constexpr StringData WriteCommandRequestBase::kIsTimeseriesNamespaceFieldName;
constexpr StringData WriteCommandRequestBase::kOrderedFieldName;
constexpr StringData WriteCommandRequestBase::kStmtIdFieldName;
constexpr StringData WriteCommandRequestBase::kStmtIdsFieldName;


WriteCommandRequestBase::WriteCommandRequestBase()  {
    // Used for initialization only
}


WriteCommandRequestBase WriteCommandRequestBase::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<WriteCommandRequestBase>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void WriteCommandRequestBase::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<5> usedFields;
    const size_t kBypassDocumentValidationBit = 0;
    const size_t kOrderedBit = 1;
    const size_t kStmtIdBit = 2;
    const size_t kStmtIdsBit = 3;
    const size_t kIsTimeseriesNamespaceBit = 4;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kBypassDocumentValidationFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kBypassDocumentValidationBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kBypassDocumentValidationBit);

                _bypassDocumentValidation = element.trueValue();
            }
        }
        else if (fieldName == kOrderedFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kOrderedBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kOrderedBit);

                _ordered = element.boolean();
            }
        }
        else if (fieldName == kStmtIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberInt))) {
                if (MONGO_unlikely(usedFields[kStmtIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStmtIdBit);

                _stmtId = element._numberInt();
            }
        }
        else if (fieldName == kStmtIdsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kStmtIdsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStmtIdsBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kStmtIdsFieldName, &ctxt);
            std::vector<std::int32_t> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, NumberInt)) {
                        values.emplace_back(arrayElement._numberInt());
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _stmtIds = std::move(values);
        }
        else if (fieldName == kIsTimeseriesNamespaceFieldName) {
            if (MONGO_unlikely(usedFields[kIsTimeseriesNamespaceBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kIsTimeseriesNamespaceBit);

            _isTimeseriesNamespace = OptionalBool::parseFromBSON(element);
        }
        else {
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kBypassDocumentValidationBit]) {
            _bypassDocumentValidation = false;
        }
        if (!usedFields[kOrderedBit]) {
            _ordered = true;
        }
        if (!usedFields[kIsTimeseriesNamespaceBit]) {
            _isTimeseriesNamespace = mongo::OptionalBool();
        }
    }

}


void WriteCommandRequestBase::serialize(BSONObjBuilder* builder) const {
    builder->append(kBypassDocumentValidationFieldName, _bypassDocumentValidation);

    builder->append(kOrderedFieldName, _ordered);

    if (_stmtId.is_initialized()) {
        builder->append(kStmtIdFieldName, _stmtId.get());
    }

    if (_stmtIds.is_initialized()) {
        builder->append(kStmtIdsFieldName, _stmtIds.get());
    }

    {
        _isTimeseriesNamespace.serializeToBSON(kIsTimeseriesNamespaceFieldName, builder);
    }

}


BSONObj WriteCommandRequestBase::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData UpdateOpEntry::kArrayFiltersFieldName;
constexpr StringData UpdateOpEntry::kCFieldName;
constexpr StringData UpdateOpEntry::kCollationFieldName;
constexpr StringData UpdateOpEntry::kHintFieldName;
constexpr StringData UpdateOpEntry::kMultiFieldName;
constexpr StringData UpdateOpEntry::kQFieldName;
constexpr StringData UpdateOpEntry::kUFieldName;
constexpr StringData UpdateOpEntry::kUpsertFieldName;
constexpr StringData UpdateOpEntry::kUpsertSuppliedFieldName;


UpdateOpEntry::UpdateOpEntry() : _q(mongo::idl::preparsedValue<decltype(_q)>()), _u(mongo::idl::preparsedValue<decltype(_u)>()), _hasQ(false), _hasU(false) {
    // Used for initialization only
}
UpdateOpEntry::UpdateOpEntry(mongo::BSONObj q, mongo::write_ops::UpdateModification u) : _q(std::move(q)), _u(std::move(u)), _hasQ(true), _hasU(true) {
    // Used for initialization only
}


UpdateOpEntry UpdateOpEntry::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<UpdateOpEntry>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void UpdateOpEntry::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<9> usedFields;
    const size_t kQBit = 0;
    const size_t kUBit = 1;
    const size_t kCBit = 2;
    const size_t kArrayFiltersBit = 3;
    const size_t kHintBit = 4;
    const size_t kMultiBit = 5;
    const size_t kUpsertBit = 6;
    const size_t kUpsertSuppliedBit = 7;
    const size_t kCollationBit = 8;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kQFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kQBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kQBit);

                _hasQ = true;
                _q = element.Obj();
            }
        }
        else if (fieldName == kUFieldName) {
            if (MONGO_unlikely(usedFields[kUBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kUBit);

            _hasU = true;
            _u = write_ops::UpdateModification::parseFromBSON(element);
        }
        else if (fieldName == kCFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCBit);

                _c = element.Obj();
            }
        }
        else if (fieldName == kArrayFiltersFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kArrayFiltersBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kArrayFiltersBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kArrayFiltersFieldName, &ctxt);
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
            _arrayFilters = std::move(values);
        }
        else if (fieldName == kHintFieldName) {
            if (MONGO_unlikely(usedFields[kHintBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kHintBit);

            _hint = parseHint(element);
        }
        else if (fieldName == kMultiFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kMultiBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMultiBit);

                _multi = element.boolean();
            }
        }
        else if (fieldName == kUpsertFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kUpsertBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUpsertBit);

                _upsert = element.boolean();
            }
        }
        else if (fieldName == kUpsertSuppliedFieldName) {
            if (MONGO_unlikely(usedFields[kUpsertSuppliedBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kUpsertSuppliedBit);

            _upsertSupplied = OptionalBool::parseFromBSON(element);
        }
        else if (fieldName == kCollationFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCollationBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollationBit);

                _collation = element.Obj();
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kQBit]) {
            ctxt.throwMissingField(kQFieldName);
        }
        if (!usedFields[kUBit]) {
            ctxt.throwMissingField(kUFieldName);
        }
        if (!usedFields[kHintBit]) {
            _hint = mongo::BSONObj();
        }
        if (!usedFields[kMultiBit]) {
            _multi = false;
        }
        if (!usedFields[kUpsertBit]) {
            _upsert = false;
        }
        if (!usedFields[kUpsertSuppliedBit]) {
            _upsertSupplied = mongo::OptionalBool();
        }
    }

}


void UpdateOpEntry::serialize(BSONObjBuilder* builder) const {
    invariant(_hasQ && _hasU);

    builder->append(kQFieldName, _q);

    {
        _u.serializeToBSON(kUFieldName, builder);
    }

    if (_c.is_initialized()) {
        builder->append(kCFieldName, _c.get());
    }

    if (_arrayFilters.is_initialized()) {
        builder->append(kArrayFiltersFieldName, _arrayFilters.get());
    }

    {
        serializeHintToBSON(_hint, kHintFieldName, builder);
    }

    builder->append(kMultiFieldName, _multi);

    builder->append(kUpsertFieldName, _upsert);

    {
        _upsertSupplied.serializeToBSON(kUpsertSuppliedFieldName, builder);
    }

    if (_collation.is_initialized()) {
        builder->append(kCollationFieldName, _collation.get());
    }

}


BSONObj UpdateOpEntry::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData DeleteOpEntry::kCollationFieldName;
constexpr StringData DeleteOpEntry::kHintFieldName;
constexpr StringData DeleteOpEntry::kMultiFieldName;
constexpr StringData DeleteOpEntry::kQFieldName;


DeleteOpEntry::DeleteOpEntry() : _q(mongo::idl::preparsedValue<decltype(_q)>()), _multi(mongo::idl::preparsedValue<decltype(_multi)>()), _hasQ(false), _hasMulti(false) {
    // Used for initialization only
}
DeleteOpEntry::DeleteOpEntry(mongo::BSONObj q, bool multi) : _q(std::move(q)), _multi(std::move(multi)), _hasQ(true), _hasMulti(true) {
    // Used for initialization only
}


DeleteOpEntry DeleteOpEntry::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<DeleteOpEntry>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void DeleteOpEntry::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<4> usedFields;
    const size_t kQBit = 0;
    const size_t kMultiBit = 1;
    const size_t kHintBit = 2;
    const size_t kCollationBit = 3;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kQFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kQBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kQBit);

                _hasQ = true;
                _q = element.Obj();
            }
        }
        else if (fieldName == kMultiFieldName) {
            if (MONGO_unlikely(usedFields[kMultiBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kMultiBit);

            _hasMulti = true;
            _multi = write_ops::readMultiDeleteProperty(element);
        }
        else if (fieldName == kHintFieldName) {
            if (MONGO_unlikely(usedFields[kHintBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kHintBit);

            _hint = parseHint(element);
        }
        else if (fieldName == kCollationFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCollationBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollationBit);

                _collation = element.Obj();
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kQBit]) {
            ctxt.throwMissingField(kQFieldName);
        }
        if (!usedFields[kMultiBit]) {
            ctxt.throwMissingField(kMultiFieldName);
        }
        if (!usedFields[kHintBit]) {
            _hint = mongo::BSONObj();
        }
    }

}


void DeleteOpEntry::serialize(BSONObjBuilder* builder) const {
    invariant(_hasQ && _hasMulti);

    builder->append(kQFieldName, _q);

    {
        writeMultiDeleteProperty(_multi, kMultiFieldName, builder);
    }

    {
        serializeHintToBSON(_hint, kHintFieldName, builder);
    }

    if (_collation.is_initialized()) {
        builder->append(kCollationFieldName, _collation.get());
    }

}


BSONObj DeleteOpEntry::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData FindAndModifyLastError::kNumDocsFieldName;
constexpr StringData FindAndModifyLastError::kUpdatedExistingFieldName;
constexpr StringData FindAndModifyLastError::kUpsertedFieldName;


FindAndModifyLastError::FindAndModifyLastError() : _numDocs(mongo::idl::preparsedValue<decltype(_numDocs)>()), _hasNumDocs(false) {
    // Used for initialization only
}
FindAndModifyLastError::FindAndModifyLastError(std::int32_t numDocs) : _numDocs(std::move(numDocs)), _hasNumDocs(true) {
    // Used for initialization only
}


FindAndModifyLastError FindAndModifyLastError::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<FindAndModifyLastError>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void FindAndModifyLastError::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<3> usedFields;
    const size_t kNumDocsBit = 0;
    const size_t kUpdatedExistingBit = 1;
    const size_t kUpsertedBit = 2;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kNumDocsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberInt))) {
                if (MONGO_unlikely(usedFields[kNumDocsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNumDocsBit);

                _hasNumDocs = true;
                _numDocs = element._numberInt();
            }
        }
        else if (fieldName == kUpdatedExistingFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kUpdatedExistingBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUpdatedExistingBit);

                _updatedExisting = element.boolean();
            }
        }
        else if (fieldName == kUpsertedFieldName) {
            if (MONGO_unlikely(usedFields[kUpsertedBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kUpsertedBit);

            _upserted = IDLAnyTypeOwned::parseFromBSON(element);
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kNumDocsBit]) {
            ctxt.throwMissingField(kNumDocsFieldName);
        }
    }

}


void FindAndModifyLastError::serialize(BSONObjBuilder* builder) const {
    invariant(_hasNumDocs);

    builder->append(kNumDocsFieldName, _numDocs);

    if (_updatedExisting.is_initialized()) {
        builder->append(kUpdatedExistingFieldName, _updatedExisting.get());
    }

    if (_upserted.is_initialized()) {
        _upserted.get().serializeToBSON(kUpsertedFieldName, builder);
    }

}


BSONObj FindAndModifyLastError::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData FindAndModifyCommandReply::kLastErrorObjectFieldName;
constexpr StringData FindAndModifyCommandReply::kValueFieldName;


FindAndModifyCommandReply::FindAndModifyCommandReply() : _lastErrorObject(mongo::idl::preparsedValue<decltype(_lastErrorObject)>()), _hasLastErrorObject(false) {
    // Used for initialization only
}
FindAndModifyCommandReply::FindAndModifyCommandReply(mongo::write_ops::FindAndModifyLastError lastErrorObject) : _lastErrorObject(std::move(lastErrorObject)), _hasLastErrorObject(true) {
    // Used for initialization only
}


FindAndModifyCommandReply FindAndModifyCommandReply::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<FindAndModifyCommandReply>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void FindAndModifyCommandReply::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kLastErrorObjectBit = 0;
    const size_t kValueBit = 1;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kLastErrorObjectFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kLastErrorObjectBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLastErrorObjectBit);

                _hasLastErrorObject = true;
                IDLParserErrorContext tempContext(kLastErrorObjectFieldName, &ctxt);
                const auto localObject = element.Obj();
                _lastErrorObject = mongo::write_ops::FindAndModifyLastError::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kValueFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kValueBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kValueBit);

                const BSONObj localObject = element.Obj();
                _value = BSONObj::getOwned(localObject);
            }
        }
        else {
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kLastErrorObjectBit]) {
            ctxt.throwMissingField(kLastErrorObjectFieldName);
        }
    }

}


void FindAndModifyCommandReply::serialize(BSONObjBuilder* builder) const {
    invariant(_hasLastErrorObject);

    {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kLastErrorObjectFieldName));
        _lastErrorObject.serialize(&subObjBuilder);
    }

    if (_value.is_initialized()) {
        builder->append(kValueFieldName, _value.get());
    }
    else {
        builder->appendNull(kValueFieldName);
    }

}


BSONObj FindAndModifyCommandReply::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData InsertCommandRequest::kBypassDocumentValidationFieldName;
constexpr StringData InsertCommandRequest::kDbNameFieldName;
constexpr StringData InsertCommandRequest::kDocumentsFieldName;
constexpr StringData InsertCommandRequest::kIsTimeseriesNamespaceFieldName;
constexpr StringData InsertCommandRequest::kOrderedFieldName;
constexpr StringData InsertCommandRequest::kStmtIdFieldName;
constexpr StringData InsertCommandRequest::kStmtIdsFieldName;
constexpr StringData InsertCommandRequest::kWriteCommandRequestBaseFieldName;
constexpr StringData InsertCommandRequest::kCommandName;

mongo::AuthorizationContract InsertCommandRequest::kAuthorizationContract = AuthorizationContract(std::initializer_list<AccessCheckEnum>{}, std::initializer_list<Privilege>{Privilege(ResourcePattern::forAuthorizationContract(MatchTypeEnum::kMatchExactNamespace), ActionSet{ActionType::bypassDocumentValidation,ActionType::insert})});

const std::vector<StringData> InsertCommandRequest::_knownBSONFields {
    InsertCommandRequest::kBypassDocumentValidationFieldName,
    InsertCommandRequest::kDocumentsFieldName,
    InsertCommandRequest::kIsTimeseriesNamespaceFieldName,
    InsertCommandRequest::kOrderedFieldName,
    InsertCommandRequest::kStmtIdFieldName,
    InsertCommandRequest::kStmtIdsFieldName,
    InsertCommandRequest::kWriteCommandRequestBaseFieldName,
    InsertCommandRequest::kCommandName,
};
const std::vector<StringData> InsertCommandRequest::_knownOP_MSGFields {
    InsertCommandRequest::kBypassDocumentValidationFieldName,
    InsertCommandRequest::kDbNameFieldName,
    InsertCommandRequest::kDocumentsFieldName,
    InsertCommandRequest::kIsTimeseriesNamespaceFieldName,
    InsertCommandRequest::kOrderedFieldName,
    InsertCommandRequest::kStmtIdFieldName,
    InsertCommandRequest::kStmtIdsFieldName,
    InsertCommandRequest::kWriteCommandRequestBaseFieldName,
    InsertCommandRequest::kCommandName,
};

InsertCommandRequest::InsertCommandRequest(const NamespaceString nss) : _nss(std::move(nss)), _dbName(nss.db().toString()), _hasDocuments(false), _hasDbName(true) {
    // Used for initialization only
}
InsertCommandRequest::InsertCommandRequest(const NamespaceString nss, std::vector<mongo::BSONObj> documents) : _nss(std::move(nss)), _documents(std::move(documents)), _dbName(nss.db().toString()), _hasDocuments(true), _hasDbName(true) {
    // Used for initialization only
}


InsertCommandRequest InsertCommandRequest::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    NamespaceString localNS;
    InsertCommandRequest object(localNS);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void InsertCommandRequest::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<8> usedFields;
    const size_t kBypassDocumentValidationBit = 0;
    const size_t kOrderedBit = 1;
    const size_t kStmtIdBit = 2;
    const size_t kStmtIdsBit = 3;
    const size_t kIsTimeseriesNamespaceBit = 4;
    const size_t kDocumentsBit = 5;
    const size_t kDbNameBit = 6;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kBypassDocumentValidationFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kBypassDocumentValidationBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kBypassDocumentValidationBit);

                _writeCommandRequestBase.setBypassDocumentValidation(element.trueValue());
            }
        }
        else if (fieldName == kOrderedFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kOrderedBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kOrderedBit);

                _writeCommandRequestBase.setOrdered(element.boolean());
            }
        }
        else if (fieldName == kStmtIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberInt))) {
                if (MONGO_unlikely(usedFields[kStmtIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStmtIdBit);

                _writeCommandRequestBase.setStmtId(boost::optional<std::int32_t>(element._numberInt()));
            }
        }
        else if (fieldName == kStmtIdsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kStmtIdsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStmtIdsBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kStmtIdsFieldName, &ctxt);
            std::vector<std::int32_t> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, NumberInt)) {
                        values.emplace_back(arrayElement._numberInt());
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _writeCommandRequestBase.setStmtIds(std::move(values));
        }
        else if (fieldName == kIsTimeseriesNamespaceFieldName) {
            if (MONGO_unlikely(usedFields[kIsTimeseriesNamespaceBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kIsTimeseriesNamespaceBit);

            _writeCommandRequestBase.setIsTimeseriesNamespace(OptionalBool::parseFromBSON(element));
        }
        else if (fieldName == kDocumentsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kDocumentsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDocumentsBit);

                _hasDocuments = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kDocumentsFieldName, &ctxt);
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
            _documents = std::move(values);
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
        if (!usedFields[kBypassDocumentValidationBit]) {
            _writeCommandRequestBase.setBypassDocumentValidation(false);
        }
        if (!usedFields[kOrderedBit]) {
            _writeCommandRequestBase.setOrdered(true);
        }
        if (!usedFields[kIsTimeseriesNamespaceBit]) {
            _writeCommandRequestBase.setIsTimeseriesNamespace(mongo::OptionalBool());
        }
        if (!usedFields[kDocumentsBit]) {
            ctxt.throwMissingField(kDocumentsFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

InsertCommandRequest InsertCommandRequest::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    NamespaceString localNS;
    InsertCommandRequest object(localNS);
    object.parseProtected(ctxt, request);
    return object;
}
void InsertCommandRequest::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<8> usedFields;
    const size_t kBypassDocumentValidationBit = 0;
    const size_t kOrderedBit = 1;
    const size_t kStmtIdBit = 2;
    const size_t kStmtIdsBit = 3;
    const size_t kIsTimeseriesNamespaceBit = 4;
    const size_t kDocumentsBit = 5;
    const size_t kDbNameBit = 6;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kBypassDocumentValidationFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kBypassDocumentValidationBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kBypassDocumentValidationBit);

                _writeCommandRequestBase.setBypassDocumentValidation(element.trueValue());
            }
        }
        else if (fieldName == kOrderedFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kOrderedBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kOrderedBit);

                _writeCommandRequestBase.setOrdered(element.boolean());
            }
        }
        else if (fieldName == kStmtIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberInt))) {
                if (MONGO_unlikely(usedFields[kStmtIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStmtIdBit);

                _writeCommandRequestBase.setStmtId(boost::optional<std::int32_t>(element._numberInt()));
            }
        }
        else if (fieldName == kStmtIdsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kStmtIdsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStmtIdsBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kStmtIdsFieldName, &ctxt);
            std::vector<std::int32_t> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, NumberInt)) {
                        values.emplace_back(arrayElement._numberInt());
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _writeCommandRequestBase.setStmtIds(std::move(values));
        }
        else if (fieldName == kIsTimeseriesNamespaceFieldName) {
            if (MONGO_unlikely(usedFields[kIsTimeseriesNamespaceBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kIsTimeseriesNamespaceBit);

            _writeCommandRequestBase.setIsTimeseriesNamespace(OptionalBool::parseFromBSON(element));
        }
        else if (fieldName == kDocumentsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kDocumentsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDocumentsBit);

                _hasDocuments = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kDocumentsFieldName, &ctxt);
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
            _documents = std::move(values);
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

    for (auto&& sequence : request.sequences) {

        if (sequence.name == kDocumentsFieldName) {
            if (MONGO_unlikely(usedFields[kDocumentsBit])) {
                ctxt.throwDuplicateField(sequence.name);
            }

            usedFields.set(kDocumentsBit);

            _hasDocuments = true;
            std::vector<mongo::BSONObj> values;

            for (const BSONObj& sequenceObject : sequence.objs) {
                values.emplace_back(sequenceObject);
            }
            _documents = std::move(values);
        }
        else {
            ctxt.throwUnknownField(sequence.name);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kBypassDocumentValidationBit]) {
            _writeCommandRequestBase.setBypassDocumentValidation(false);
        }
        if (!usedFields[kOrderedBit]) {
            _writeCommandRequestBase.setOrdered(true);
        }
        if (!usedFields[kIsTimeseriesNamespaceBit]) {
            _writeCommandRequestBase.setIsTimeseriesNamespace(mongo::OptionalBool());
        }
        if (!usedFields[kDocumentsBit]) {
            ctxt.throwMissingField(kDocumentsFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

void InsertCommandRequest::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDocuments && _hasDbName);

    invariant(!_nss.isEmpty());
    builder->append("insert"_sd, _nss.coll());

    {
        _writeCommandRequestBase.serialize(builder);
    }

    {
        builder->append(kDocumentsFieldName, _documents);
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest InsertCommandRequest::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDocuments && _hasDbName);

        invariant(!_nss.isEmpty());
        builder->append("insert"_sd, _nss.coll());

        {
            _writeCommandRequestBase.serialize(builder);
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    {
        OpMsg::DocumentSequence documentSequence;
        documentSequence.name = kDocumentsFieldName.toString();
        for (const auto& item : _documents) {
            documentSequence.objs.push_back(item);
        }
        request.sequences.emplace_back(documentSequence);
    }

    return request;
}

BSONObj InsertCommandRequest::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData UpdateCommandRequest::kBypassDocumentValidationFieldName;
constexpr StringData UpdateCommandRequest::kDbNameFieldName;
constexpr StringData UpdateCommandRequest::kIsTimeseriesNamespaceFieldName;
constexpr StringData UpdateCommandRequest::kLegacyRuntimeConstantsFieldName;
constexpr StringData UpdateCommandRequest::kLetFieldName;
constexpr StringData UpdateCommandRequest::kOrderedFieldName;
constexpr StringData UpdateCommandRequest::kStmtIdFieldName;
constexpr StringData UpdateCommandRequest::kStmtIdsFieldName;
constexpr StringData UpdateCommandRequest::kUpdatesFieldName;
constexpr StringData UpdateCommandRequest::kWriteCommandRequestBaseFieldName;
constexpr StringData UpdateCommandRequest::kCommandName;

mongo::AuthorizationContract UpdateCommandRequest::kAuthorizationContract = AuthorizationContract(std::initializer_list<AccessCheckEnum>{}, std::initializer_list<Privilege>{Privilege(ResourcePattern::forAuthorizationContract(MatchTypeEnum::kMatchExactNamespace), ActionSet{ActionType::bypassDocumentValidation,ActionType::insert,ActionType::update})});

const std::vector<StringData> UpdateCommandRequest::_knownBSONFields {
    UpdateCommandRequest::kBypassDocumentValidationFieldName,
    UpdateCommandRequest::kIsTimeseriesNamespaceFieldName,
    UpdateCommandRequest::kLegacyRuntimeConstantsFieldName,
    UpdateCommandRequest::kLetFieldName,
    UpdateCommandRequest::kOrderedFieldName,
    UpdateCommandRequest::kStmtIdFieldName,
    UpdateCommandRequest::kStmtIdsFieldName,
    UpdateCommandRequest::kUpdatesFieldName,
    UpdateCommandRequest::kWriteCommandRequestBaseFieldName,
    UpdateCommandRequest::kCommandName,
};
const std::vector<StringData> UpdateCommandRequest::_knownOP_MSGFields {
    UpdateCommandRequest::kBypassDocumentValidationFieldName,
    UpdateCommandRequest::kDbNameFieldName,
    UpdateCommandRequest::kIsTimeseriesNamespaceFieldName,
    UpdateCommandRequest::kLegacyRuntimeConstantsFieldName,
    UpdateCommandRequest::kLetFieldName,
    UpdateCommandRequest::kOrderedFieldName,
    UpdateCommandRequest::kStmtIdFieldName,
    UpdateCommandRequest::kStmtIdsFieldName,
    UpdateCommandRequest::kUpdatesFieldName,
    UpdateCommandRequest::kWriteCommandRequestBaseFieldName,
    UpdateCommandRequest::kCommandName,
};

UpdateCommandRequest::UpdateCommandRequest(const NamespaceString nss) : _nss(std::move(nss)), _dbName(nss.db().toString()), _hasUpdates(false), _hasDbName(true) {
    // Used for initialization only
}
UpdateCommandRequest::UpdateCommandRequest(const NamespaceString nss, std::vector<mongo::write_ops::UpdateOpEntry> updates) : _nss(std::move(nss)), _updates(std::move(updates)), _dbName(nss.db().toString()), _hasUpdates(true), _hasDbName(true) {
    // Used for initialization only
}


UpdateCommandRequest UpdateCommandRequest::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    NamespaceString localNS;
    UpdateCommandRequest object(localNS);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void UpdateCommandRequest::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<10> usedFields;
    const size_t kBypassDocumentValidationBit = 0;
    const size_t kOrderedBit = 1;
    const size_t kStmtIdBit = 2;
    const size_t kStmtIdsBit = 3;
    const size_t kIsTimeseriesNamespaceBit = 4;
    const size_t kUpdatesBit = 5;
    const size_t kLetBit = 6;
    const size_t kLegacyRuntimeConstantsBit = 7;
    const size_t kDbNameBit = 8;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kBypassDocumentValidationFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kBypassDocumentValidationBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kBypassDocumentValidationBit);

                _writeCommandRequestBase.setBypassDocumentValidation(element.trueValue());
            }
        }
        else if (fieldName == kOrderedFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kOrderedBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kOrderedBit);

                _writeCommandRequestBase.setOrdered(element.boolean());
            }
        }
        else if (fieldName == kStmtIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberInt))) {
                if (MONGO_unlikely(usedFields[kStmtIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStmtIdBit);

                _writeCommandRequestBase.setStmtId(boost::optional<std::int32_t>(element._numberInt()));
            }
        }
        else if (fieldName == kStmtIdsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kStmtIdsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStmtIdsBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kStmtIdsFieldName, &ctxt);
            std::vector<std::int32_t> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, NumberInt)) {
                        values.emplace_back(arrayElement._numberInt());
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _writeCommandRequestBase.setStmtIds(std::move(values));
        }
        else if (fieldName == kIsTimeseriesNamespaceFieldName) {
            if (MONGO_unlikely(usedFields[kIsTimeseriesNamespaceBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kIsTimeseriesNamespaceBit);

            _writeCommandRequestBase.setIsTimeseriesNamespace(OptionalBool::parseFromBSON(element));
        }
        else if (fieldName == kUpdatesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kUpdatesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUpdatesBit);

                _hasUpdates = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kUpdatesFieldName, &ctxt);
            std::vector<mongo::write_ops::UpdateOpEntry> values;

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
                        IDLParserErrorContext tempContext(kUpdatesFieldName, &ctxt);
                        const auto localObject = arrayElement.Obj();
                        values.emplace_back(mongo::write_ops::UpdateOpEntry::parse(tempContext, localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _updates = std::move(values);
        }
        else if (fieldName == kLetFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kLetBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLetBit);

                _let = element.Obj();
            }
        }
        else if (fieldName == kLegacyRuntimeConstantsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kLegacyRuntimeConstantsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLegacyRuntimeConstantsBit);

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
        if (!usedFields[kBypassDocumentValidationBit]) {
            _writeCommandRequestBase.setBypassDocumentValidation(false);
        }
        if (!usedFields[kOrderedBit]) {
            _writeCommandRequestBase.setOrdered(true);
        }
        if (!usedFields[kIsTimeseriesNamespaceBit]) {
            _writeCommandRequestBase.setIsTimeseriesNamespace(mongo::OptionalBool());
        }
        if (!usedFields[kUpdatesBit]) {
            ctxt.throwMissingField(kUpdatesFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

UpdateCommandRequest UpdateCommandRequest::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    NamespaceString localNS;
    UpdateCommandRequest object(localNS);
    object.parseProtected(ctxt, request);
    return object;
}
void UpdateCommandRequest::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<10> usedFields;
    const size_t kBypassDocumentValidationBit = 0;
    const size_t kOrderedBit = 1;
    const size_t kStmtIdBit = 2;
    const size_t kStmtIdsBit = 3;
    const size_t kIsTimeseriesNamespaceBit = 4;
    const size_t kUpdatesBit = 5;
    const size_t kLetBit = 6;
    const size_t kLegacyRuntimeConstantsBit = 7;
    const size_t kDbNameBit = 8;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kBypassDocumentValidationFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kBypassDocumentValidationBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kBypassDocumentValidationBit);

                _writeCommandRequestBase.setBypassDocumentValidation(element.trueValue());
            }
        }
        else if (fieldName == kOrderedFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kOrderedBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kOrderedBit);

                _writeCommandRequestBase.setOrdered(element.boolean());
            }
        }
        else if (fieldName == kStmtIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberInt))) {
                if (MONGO_unlikely(usedFields[kStmtIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStmtIdBit);

                _writeCommandRequestBase.setStmtId(boost::optional<std::int32_t>(element._numberInt()));
            }
        }
        else if (fieldName == kStmtIdsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kStmtIdsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStmtIdsBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kStmtIdsFieldName, &ctxt);
            std::vector<std::int32_t> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, NumberInt)) {
                        values.emplace_back(arrayElement._numberInt());
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _writeCommandRequestBase.setStmtIds(std::move(values));
        }
        else if (fieldName == kIsTimeseriesNamespaceFieldName) {
            if (MONGO_unlikely(usedFields[kIsTimeseriesNamespaceBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kIsTimeseriesNamespaceBit);

            _writeCommandRequestBase.setIsTimeseriesNamespace(OptionalBool::parseFromBSON(element));
        }
        else if (fieldName == kUpdatesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kUpdatesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUpdatesBit);

                _hasUpdates = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kUpdatesFieldName, &ctxt);
            std::vector<mongo::write_ops::UpdateOpEntry> values;

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
                        IDLParserErrorContext tempContext(kUpdatesFieldName, &ctxt);
                        const auto localObject = arrayElement.Obj();
                        values.emplace_back(mongo::write_ops::UpdateOpEntry::parse(tempContext, localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _updates = std::move(values);
        }
        else if (fieldName == kLetFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kLetBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLetBit);

                _let = element.Obj();
            }
        }
        else if (fieldName == kLegacyRuntimeConstantsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kLegacyRuntimeConstantsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLegacyRuntimeConstantsBit);

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

    for (auto&& sequence : request.sequences) {

        if (sequence.name == kUpdatesFieldName) {
            if (MONGO_unlikely(usedFields[kUpdatesBit])) {
                ctxt.throwDuplicateField(sequence.name);
            }

            usedFields.set(kUpdatesBit);

            _hasUpdates = true;
            std::vector<mongo::write_ops::UpdateOpEntry> values;

            for (const BSONObj& sequenceObject : sequence.objs) {
                IDLParserErrorContext tempContext(kUpdatesFieldName, &ctxt);
                values.emplace_back(mongo::write_ops::UpdateOpEntry::parse(tempContext, sequenceObject));
            }
            _updates = std::move(values);
        }
        else {
            ctxt.throwUnknownField(sequence.name);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kBypassDocumentValidationBit]) {
            _writeCommandRequestBase.setBypassDocumentValidation(false);
        }
        if (!usedFields[kOrderedBit]) {
            _writeCommandRequestBase.setOrdered(true);
        }
        if (!usedFields[kIsTimeseriesNamespaceBit]) {
            _writeCommandRequestBase.setIsTimeseriesNamespace(mongo::OptionalBool());
        }
        if (!usedFields[kUpdatesBit]) {
            ctxt.throwMissingField(kUpdatesFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

void UpdateCommandRequest::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasUpdates && _hasDbName);

    invariant(!_nss.isEmpty());
    builder->append("update"_sd, _nss.coll());

    {
        _writeCommandRequestBase.serialize(builder);
    }

    {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kUpdatesFieldName));
        for (const auto& item : _updates) {
            BSONObjBuilder subObjBuilder(arrayBuilder.subobjStart());
            item.serialize(&subObjBuilder);
        }
    }

    if (_let.is_initialized()) {
        builder->append(kLetFieldName, _let.get());
    }

    if (_legacyRuntimeConstants.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kLegacyRuntimeConstantsFieldName));
        _legacyRuntimeConstants.get().serialize(&subObjBuilder);
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest UpdateCommandRequest::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasUpdates && _hasDbName);

        invariant(!_nss.isEmpty());
        builder->append("update"_sd, _nss.coll());

        {
            _writeCommandRequestBase.serialize(builder);
        }

        if (_let.is_initialized()) {
            builder->append(kLetFieldName, _let.get());
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
    {
        OpMsg::DocumentSequence documentSequence;
        documentSequence.name = kUpdatesFieldName.toString();
        for (const auto& item : _updates) {
            BSONObjBuilder builder;
            item.serialize(&builder);
            documentSequence.objs.push_back(builder.obj());
        }
        request.sequences.emplace_back(documentSequence);
    }

    return request;
}

BSONObj UpdateCommandRequest::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData DeleteCommandRequest::kBypassDocumentValidationFieldName;
constexpr StringData DeleteCommandRequest::kDbNameFieldName;
constexpr StringData DeleteCommandRequest::kDeletesFieldName;
constexpr StringData DeleteCommandRequest::kIsTimeseriesNamespaceFieldName;
constexpr StringData DeleteCommandRequest::kLegacyRuntimeConstantsFieldName;
constexpr StringData DeleteCommandRequest::kLetFieldName;
constexpr StringData DeleteCommandRequest::kOrderedFieldName;
constexpr StringData DeleteCommandRequest::kStmtIdFieldName;
constexpr StringData DeleteCommandRequest::kStmtIdsFieldName;
constexpr StringData DeleteCommandRequest::kWriteCommandRequestBaseFieldName;
constexpr StringData DeleteCommandRequest::kCommandName;

mongo::AuthorizationContract DeleteCommandRequest::kAuthorizationContract = AuthorizationContract(std::initializer_list<AccessCheckEnum>{}, std::initializer_list<Privilege>{Privilege(ResourcePattern::forAuthorizationContract(MatchTypeEnum::kMatchExactNamespace), ActionSet{ActionType::bypassDocumentValidation,ActionType::remove})});

const std::vector<StringData> DeleteCommandRequest::_knownBSONFields {
    DeleteCommandRequest::kBypassDocumentValidationFieldName,
    DeleteCommandRequest::kDeletesFieldName,
    DeleteCommandRequest::kIsTimeseriesNamespaceFieldName,
    DeleteCommandRequest::kLegacyRuntimeConstantsFieldName,
    DeleteCommandRequest::kLetFieldName,
    DeleteCommandRequest::kOrderedFieldName,
    DeleteCommandRequest::kStmtIdFieldName,
    DeleteCommandRequest::kStmtIdsFieldName,
    DeleteCommandRequest::kWriteCommandRequestBaseFieldName,
    DeleteCommandRequest::kCommandName,
};
const std::vector<StringData> DeleteCommandRequest::_knownOP_MSGFields {
    DeleteCommandRequest::kBypassDocumentValidationFieldName,
    DeleteCommandRequest::kDbNameFieldName,
    DeleteCommandRequest::kDeletesFieldName,
    DeleteCommandRequest::kIsTimeseriesNamespaceFieldName,
    DeleteCommandRequest::kLegacyRuntimeConstantsFieldName,
    DeleteCommandRequest::kLetFieldName,
    DeleteCommandRequest::kOrderedFieldName,
    DeleteCommandRequest::kStmtIdFieldName,
    DeleteCommandRequest::kStmtIdsFieldName,
    DeleteCommandRequest::kWriteCommandRequestBaseFieldName,
    DeleteCommandRequest::kCommandName,
};

DeleteCommandRequest::DeleteCommandRequest(const NamespaceString nss) : _nss(std::move(nss)), _dbName(nss.db().toString()), _hasDeletes(false), _hasDbName(true) {
    // Used for initialization only
}
DeleteCommandRequest::DeleteCommandRequest(const NamespaceString nss, std::vector<mongo::write_ops::DeleteOpEntry> deletes) : _nss(std::move(nss)), _deletes(std::move(deletes)), _dbName(nss.db().toString()), _hasDeletes(true), _hasDbName(true) {
    // Used for initialization only
}


DeleteCommandRequest DeleteCommandRequest::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    NamespaceString localNS;
    DeleteCommandRequest object(localNS);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void DeleteCommandRequest::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<10> usedFields;
    const size_t kBypassDocumentValidationBit = 0;
    const size_t kOrderedBit = 1;
    const size_t kStmtIdBit = 2;
    const size_t kStmtIdsBit = 3;
    const size_t kIsTimeseriesNamespaceBit = 4;
    const size_t kDeletesBit = 5;
    const size_t kLetBit = 6;
    const size_t kLegacyRuntimeConstantsBit = 7;
    const size_t kDbNameBit = 8;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kBypassDocumentValidationFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kBypassDocumentValidationBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kBypassDocumentValidationBit);

                _writeCommandRequestBase.setBypassDocumentValidation(element.trueValue());
            }
        }
        else if (fieldName == kOrderedFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kOrderedBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kOrderedBit);

                _writeCommandRequestBase.setOrdered(element.boolean());
            }
        }
        else if (fieldName == kStmtIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberInt))) {
                if (MONGO_unlikely(usedFields[kStmtIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStmtIdBit);

                _writeCommandRequestBase.setStmtId(boost::optional<std::int32_t>(element._numberInt()));
            }
        }
        else if (fieldName == kStmtIdsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kStmtIdsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStmtIdsBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kStmtIdsFieldName, &ctxt);
            std::vector<std::int32_t> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, NumberInt)) {
                        values.emplace_back(arrayElement._numberInt());
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _writeCommandRequestBase.setStmtIds(std::move(values));
        }
        else if (fieldName == kIsTimeseriesNamespaceFieldName) {
            if (MONGO_unlikely(usedFields[kIsTimeseriesNamespaceBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kIsTimeseriesNamespaceBit);

            _writeCommandRequestBase.setIsTimeseriesNamespace(OptionalBool::parseFromBSON(element));
        }
        else if (fieldName == kDeletesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kDeletesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDeletesBit);

                _hasDeletes = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kDeletesFieldName, &ctxt);
            std::vector<mongo::write_ops::DeleteOpEntry> values;

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
                        IDLParserErrorContext tempContext(kDeletesFieldName, &ctxt);
                        const auto localObject = arrayElement.Obj();
                        values.emplace_back(mongo::write_ops::DeleteOpEntry::parse(tempContext, localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _deletes = std::move(values);
        }
        else if (fieldName == kLetFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kLetBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLetBit);

                _let = element.Obj();
            }
        }
        else if (fieldName == kLegacyRuntimeConstantsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kLegacyRuntimeConstantsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLegacyRuntimeConstantsBit);

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
        if (!usedFields[kBypassDocumentValidationBit]) {
            _writeCommandRequestBase.setBypassDocumentValidation(false);
        }
        if (!usedFields[kOrderedBit]) {
            _writeCommandRequestBase.setOrdered(true);
        }
        if (!usedFields[kIsTimeseriesNamespaceBit]) {
            _writeCommandRequestBase.setIsTimeseriesNamespace(mongo::OptionalBool());
        }
        if (!usedFields[kDeletesBit]) {
            ctxt.throwMissingField(kDeletesFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

DeleteCommandRequest DeleteCommandRequest::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    NamespaceString localNS;
    DeleteCommandRequest object(localNS);
    object.parseProtected(ctxt, request);
    return object;
}
void DeleteCommandRequest::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<10> usedFields;
    const size_t kBypassDocumentValidationBit = 0;
    const size_t kOrderedBit = 1;
    const size_t kStmtIdBit = 2;
    const size_t kStmtIdsBit = 3;
    const size_t kIsTimeseriesNamespaceBit = 4;
    const size_t kDeletesBit = 5;
    const size_t kLetBit = 6;
    const size_t kLegacyRuntimeConstantsBit = 7;
    const size_t kDbNameBit = 8;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kBypassDocumentValidationFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kBypassDocumentValidationBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kBypassDocumentValidationBit);

                _writeCommandRequestBase.setBypassDocumentValidation(element.trueValue());
            }
        }
        else if (fieldName == kOrderedFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kOrderedBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kOrderedBit);

                _writeCommandRequestBase.setOrdered(element.boolean());
            }
        }
        else if (fieldName == kStmtIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberInt))) {
                if (MONGO_unlikely(usedFields[kStmtIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStmtIdBit);

                _writeCommandRequestBase.setStmtId(boost::optional<std::int32_t>(element._numberInt()));
            }
        }
        else if (fieldName == kStmtIdsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kStmtIdsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStmtIdsBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kStmtIdsFieldName, &ctxt);
            std::vector<std::int32_t> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, NumberInt)) {
                        values.emplace_back(arrayElement._numberInt());
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _writeCommandRequestBase.setStmtIds(std::move(values));
        }
        else if (fieldName == kIsTimeseriesNamespaceFieldName) {
            if (MONGO_unlikely(usedFields[kIsTimeseriesNamespaceBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kIsTimeseriesNamespaceBit);

            _writeCommandRequestBase.setIsTimeseriesNamespace(OptionalBool::parseFromBSON(element));
        }
        else if (fieldName == kDeletesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kDeletesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDeletesBit);

                _hasDeletes = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kDeletesFieldName, &ctxt);
            std::vector<mongo::write_ops::DeleteOpEntry> values;

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
                        IDLParserErrorContext tempContext(kDeletesFieldName, &ctxt);
                        const auto localObject = arrayElement.Obj();
                        values.emplace_back(mongo::write_ops::DeleteOpEntry::parse(tempContext, localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _deletes = std::move(values);
        }
        else if (fieldName == kLetFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kLetBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLetBit);

                _let = element.Obj();
            }
        }
        else if (fieldName == kLegacyRuntimeConstantsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kLegacyRuntimeConstantsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLegacyRuntimeConstantsBit);

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

    for (auto&& sequence : request.sequences) {

        if (sequence.name == kDeletesFieldName) {
            if (MONGO_unlikely(usedFields[kDeletesBit])) {
                ctxt.throwDuplicateField(sequence.name);
            }

            usedFields.set(kDeletesBit);

            _hasDeletes = true;
            std::vector<mongo::write_ops::DeleteOpEntry> values;

            for (const BSONObj& sequenceObject : sequence.objs) {
                IDLParserErrorContext tempContext(kDeletesFieldName, &ctxt);
                values.emplace_back(mongo::write_ops::DeleteOpEntry::parse(tempContext, sequenceObject));
            }
            _deletes = std::move(values);
        }
        else {
            ctxt.throwUnknownField(sequence.name);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kBypassDocumentValidationBit]) {
            _writeCommandRequestBase.setBypassDocumentValidation(false);
        }
        if (!usedFields[kOrderedBit]) {
            _writeCommandRequestBase.setOrdered(true);
        }
        if (!usedFields[kIsTimeseriesNamespaceBit]) {
            _writeCommandRequestBase.setIsTimeseriesNamespace(mongo::OptionalBool());
        }
        if (!usedFields[kDeletesBit]) {
            ctxt.throwMissingField(kDeletesFieldName);
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

void DeleteCommandRequest::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDeletes && _hasDbName);

    invariant(!_nss.isEmpty());
    builder->append("delete"_sd, _nss.coll());

    {
        _writeCommandRequestBase.serialize(builder);
    }

    {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kDeletesFieldName));
        for (const auto& item : _deletes) {
            BSONObjBuilder subObjBuilder(arrayBuilder.subobjStart());
            item.serialize(&subObjBuilder);
        }
    }

    if (_let.is_initialized()) {
        builder->append(kLetFieldName, _let.get());
    }

    if (_legacyRuntimeConstants.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kLegacyRuntimeConstantsFieldName));
        _legacyRuntimeConstants.get().serialize(&subObjBuilder);
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest DeleteCommandRequest::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDeletes && _hasDbName);

        invariant(!_nss.isEmpty());
        builder->append("delete"_sd, _nss.coll());

        {
            _writeCommandRequestBase.serialize(builder);
        }

        if (_let.is_initialized()) {
            builder->append(kLetFieldName, _let.get());
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
    {
        OpMsg::DocumentSequence documentSequence;
        documentSequence.name = kDeletesFieldName.toString();
        for (const auto& item : _deletes) {
            BSONObjBuilder builder;
            item.serialize(&builder);
            documentSequence.objs.push_back(builder.obj());
        }
        request.sequences.emplace_back(documentSequence);
    }

    return request;
}

BSONObj DeleteCommandRequest::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

constexpr StringData FindAndModifyCommandRequest::kArrayFiltersFieldName;
constexpr StringData FindAndModifyCommandRequest::kBatchSizeFieldName;
constexpr StringData FindAndModifyCommandRequest::kBypassDocumentValidationFieldName;
constexpr StringData FindAndModifyCommandRequest::kCollationFieldName;
constexpr StringData FindAndModifyCommandRequest::kDbNameFieldName;
constexpr StringData FindAndModifyCommandRequest::kFieldsFieldName;
constexpr StringData FindAndModifyCommandRequest::kHintFieldName;
constexpr StringData FindAndModifyCommandRequest::kLegacyRuntimeConstantsFieldName;
constexpr StringData FindAndModifyCommandRequest::kLetFieldName;
constexpr StringData FindAndModifyCommandRequest::kNewFieldName;
constexpr StringData FindAndModifyCommandRequest::kQueryFieldName;
constexpr StringData FindAndModifyCommandRequest::kRemoveFieldName;
constexpr StringData FindAndModifyCommandRequest::kSingleBatchFieldName;
constexpr StringData FindAndModifyCommandRequest::kSortFieldName;
constexpr StringData FindAndModifyCommandRequest::kUpdateFieldName;
constexpr StringData FindAndModifyCommandRequest::kUpsertFieldName;
constexpr StringData FindAndModifyCommandRequest::kWriteConcernFieldName;
constexpr StringData FindAndModifyCommandRequest::kCommandName;
constexpr StringData FindAndModifyCommandRequest::kCommandAlias;

mongo::AuthorizationContract FindAndModifyCommandRequest::kAuthorizationContract = AuthorizationContract(std::initializer_list<AccessCheckEnum>{}, std::initializer_list<Privilege>{Privilege(ResourcePattern::forAuthorizationContract(MatchTypeEnum::kMatchExactNamespace), ActionSet{ActionType::bypassDocumentValidation,ActionType::find,ActionType::insert,ActionType::update,ActionType::remove})});

const std::vector<StringData> FindAndModifyCommandRequest::_knownBSONFields {
    FindAndModifyCommandRequest::kArrayFiltersFieldName,
    FindAndModifyCommandRequest::kBatchSizeFieldName,
    FindAndModifyCommandRequest::kBypassDocumentValidationFieldName,
    FindAndModifyCommandRequest::kCollationFieldName,
    FindAndModifyCommandRequest::kFieldsFieldName,
    FindAndModifyCommandRequest::kHintFieldName,
    FindAndModifyCommandRequest::kLegacyRuntimeConstantsFieldName,
    FindAndModifyCommandRequest::kLetFieldName,
    FindAndModifyCommandRequest::kNewFieldName,
    FindAndModifyCommandRequest::kQueryFieldName,
    FindAndModifyCommandRequest::kRemoveFieldName,
    FindAndModifyCommandRequest::kSingleBatchFieldName,
    FindAndModifyCommandRequest::kSortFieldName,
    FindAndModifyCommandRequest::kUpdateFieldName,
    FindAndModifyCommandRequest::kUpsertFieldName,
    FindAndModifyCommandRequest::kWriteConcernFieldName,
    FindAndModifyCommandRequest::kCommandName,
};
const std::vector<StringData> FindAndModifyCommandRequest::_knownOP_MSGFields {
    FindAndModifyCommandRequest::kArrayFiltersFieldName,
    FindAndModifyCommandRequest::kBatchSizeFieldName,
    FindAndModifyCommandRequest::kBypassDocumentValidationFieldName,
    FindAndModifyCommandRequest::kCollationFieldName,
    FindAndModifyCommandRequest::kDbNameFieldName,
    FindAndModifyCommandRequest::kFieldsFieldName,
    FindAndModifyCommandRequest::kHintFieldName,
    FindAndModifyCommandRequest::kLegacyRuntimeConstantsFieldName,
    FindAndModifyCommandRequest::kLetFieldName,
    FindAndModifyCommandRequest::kNewFieldName,
    FindAndModifyCommandRequest::kQueryFieldName,
    FindAndModifyCommandRequest::kRemoveFieldName,
    FindAndModifyCommandRequest::kSingleBatchFieldName,
    FindAndModifyCommandRequest::kSortFieldName,
    FindAndModifyCommandRequest::kUpdateFieldName,
    FindAndModifyCommandRequest::kUpsertFieldName,
    FindAndModifyCommandRequest::kWriteConcernFieldName,
    FindAndModifyCommandRequest::kCommandName,
};

FindAndModifyCommandRequest::FindAndModifyCommandRequest(const NamespaceString nss) : _nss(std::move(nss)), _dbName(nss.db().toString()), _hasDbName(true) {
    // Used for initialization only
}


FindAndModifyCommandRequest FindAndModifyCommandRequest::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    NamespaceString localNS;
    FindAndModifyCommandRequest object(localNS);
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void FindAndModifyCommandRequest::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<17> usedFields;
    const size_t kQueryBit = 0;
    const size_t kFieldsBit = 1;
    const size_t kSortBit = 2;
    const size_t kBatchSizeBit = 3;
    const size_t kSingleBatchBit = 4;
    const size_t kHintBit = 5;
    const size_t kCollationBit = 6;
    const size_t kArrayFiltersBit = 7;
    const size_t kRemoveBit = 8;
    const size_t kUpdateBit = 9;
    const size_t kUpsertBit = 10;
    const size_t kNewBit = 11;
    const size_t kBypassDocumentValidationBit = 12;
    const size_t kLetBit = 13;
    const size_t kLegacyRuntimeConstantsBit = 14;
    const size_t kWriteConcernBit = 15;
    const size_t kDbNameBit = 16;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kQueryFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kQueryBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kQueryBit);

                const BSONObj localObject = element.Obj();
                _query = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kFieldsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kFieldsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kFieldsBit);

                const BSONObj localObject = element.Obj();
                _fields = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kSortFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kSortBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSortBit);

                const BSONObj localObject = element.Obj();
                _sort = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kBatchSizeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberInt))) {
                if (MONGO_unlikely(usedFields[kBatchSizeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kBatchSizeBit);

                _batchSize = element._numberInt();
            }
        }
        else if (fieldName == kSingleBatchFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kSingleBatchBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSingleBatchBit);

                _singleBatch = element.boolean();
            }
        }
        else if (fieldName == kHintFieldName) {
            if (MONGO_unlikely(usedFields[kHintBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kHintBit);

            _hint = parseHint(element);
        }
        else if (fieldName == kCollationFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCollationBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollationBit);

                _collation = element.Obj();
            }
        }
        else if (fieldName == kArrayFiltersFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kArrayFiltersBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kArrayFiltersBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kArrayFiltersFieldName, &ctxt);
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
            _arrayFilters = std::move(values);
        }
        else if (fieldName == kRemoveFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kRemoveBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRemoveBit);

                _remove = element.trueValue();
            }
        }
        else if (fieldName == kUpdateFieldName) {
            if (MONGO_unlikely(usedFields[kUpdateBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kUpdateBit);

            _update = write_ops::UpdateModification::parseFromBSON(element);
        }
        else if (fieldName == kUpsertFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kUpsertBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUpsertBit);

                _upsert = element.trueValue();
            }
        }
        else if (fieldName == kNewFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kNewBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNewBit);

                _new = element.trueValue();
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
        else if (fieldName == kLetFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kLetBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLetBit);

                _let = element.Obj();
            }
        }
        else if (fieldName == kLegacyRuntimeConstantsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kLegacyRuntimeConstantsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLegacyRuntimeConstantsBit);

                IDLParserErrorContext tempContext(kLegacyRuntimeConstantsFieldName, &ctxt);
                const auto localObject = element.Obj();
                _legacyRuntimeConstants = mongo::LegacyRuntimeConstants::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kWriteConcernFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kWriteConcernBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kWriteConcernBit);

                _writeConcern = element.Obj();
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
        if (!usedFields[kQueryBit]) {
            _query = mongo::BSONObj();
        }
        if (!usedFields[kHintBit]) {
            _hint = mongo::BSONObj();
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

FindAndModifyCommandRequest FindAndModifyCommandRequest::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    NamespaceString localNS;
    FindAndModifyCommandRequest object(localNS);
    object.parseProtected(ctxt, request);
    return object;
}
void FindAndModifyCommandRequest::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<17> usedFields;
    const size_t kQueryBit = 0;
    const size_t kFieldsBit = 1;
    const size_t kSortBit = 2;
    const size_t kBatchSizeBit = 3;
    const size_t kSingleBatchBit = 4;
    const size_t kHintBit = 5;
    const size_t kCollationBit = 6;
    const size_t kArrayFiltersBit = 7;
    const size_t kRemoveBit = 8;
    const size_t kUpdateBit = 9;
    const size_t kUpsertBit = 10;
    const size_t kNewBit = 11;
    const size_t kBypassDocumentValidationBit = 12;
    const size_t kLetBit = 13;
    const size_t kLegacyRuntimeConstantsBit = 14;
    const size_t kWriteConcernBit = 15;
    const size_t kDbNameBit = 16;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            commandElement = element;
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kQueryFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kQueryBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kQueryBit);

                const BSONObj localObject = element.Obj();
                _query = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kFieldsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kFieldsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kFieldsBit);

                const BSONObj localObject = element.Obj();
                _fields = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kSortFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kSortBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSortBit);

                const BSONObj localObject = element.Obj();
                _sort = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kBatchSizeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberInt))) {
                if (MONGO_unlikely(usedFields[kBatchSizeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kBatchSizeBit);

                _batchSize = element._numberInt();
            }
        }
        else if (fieldName == kSingleBatchFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kSingleBatchBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSingleBatchBit);

                _singleBatch = element.boolean();
            }
        }
        else if (fieldName == kHintFieldName) {
            if (MONGO_unlikely(usedFields[kHintBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kHintBit);

            _hint = parseHint(element);
        }
        else if (fieldName == kCollationFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCollationBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollationBit);

                _collation = element.Obj();
            }
        }
        else if (fieldName == kArrayFiltersFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kArrayFiltersBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kArrayFiltersBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kArrayFiltersFieldName, &ctxt);
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
            _arrayFilters = std::move(values);
        }
        else if (fieldName == kRemoveFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kRemoveBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRemoveBit);

                _remove = element.trueValue();
            }
        }
        else if (fieldName == kUpdateFieldName) {
            if (MONGO_unlikely(usedFields[kUpdateBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kUpdateBit);

            _update = write_ops::UpdateModification::parseFromBSON(element);
        }
        else if (fieldName == kUpsertFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kUpsertBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUpsertBit);

                _upsert = element.trueValue();
            }
        }
        else if (fieldName == kNewFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kNewBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNewBit);

                _new = element.trueValue();
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
        else if (fieldName == kLetFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kLetBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLetBit);

                _let = element.Obj();
            }
        }
        else if (fieldName == kLegacyRuntimeConstantsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kLegacyRuntimeConstantsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLegacyRuntimeConstantsBit);

                IDLParserErrorContext tempContext(kLegacyRuntimeConstantsFieldName, &ctxt);
                const auto localObject = element.Obj();
                _legacyRuntimeConstants = mongo::LegacyRuntimeConstants::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kWriteConcernFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kWriteConcernBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kWriteConcernBit);

                _writeConcern = element.Obj();
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
        if (!usedFields[kQueryBit]) {
            _query = mongo::BSONObj();
        }
        if (!usedFields[kHintBit]) {
            _hint = mongo::BSONObj();
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

    invariant(_nss.isEmpty());
    _nss = ctxt.parseNSCollectionRequired(_dbName, commandElement, false);
}

void FindAndModifyCommandRequest::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    invariant(!_nss.isEmpty());
    builder->append("findAndModify"_sd, _nss.coll());

    builder->append(kQueryFieldName, _query);

    if (_fields.is_initialized()) {
        builder->append(kFieldsFieldName, _fields.get());
    }

    if (_sort.is_initialized()) {
        builder->append(kSortFieldName, _sort.get());
    }

    if (_batchSize.is_initialized()) {
        builder->append(kBatchSizeFieldName, _batchSize.get());
    }

    if (_singleBatch.is_initialized()) {
        builder->append(kSingleBatchFieldName, _singleBatch.get());
    }

    {
        serializeHintToBSON(_hint, kHintFieldName, builder);
    }

    if (_collation.is_initialized()) {
        builder->append(kCollationFieldName, _collation.get());
    }

    if (_arrayFilters.is_initialized()) {
        builder->append(kArrayFiltersFieldName, _arrayFilters.get());
    }

    if (_remove.is_initialized()) {
        builder->append(kRemoveFieldName, _remove.get());
    }

    if (_update.is_initialized()) {
        _update.get().serializeToBSON(kUpdateFieldName, builder);
    }

    if (_upsert.is_initialized()) {
        builder->append(kUpsertFieldName, _upsert.get());
    }

    if (_new.is_initialized()) {
        builder->append(kNewFieldName, _new.get());
    }

    if (_bypassDocumentValidation.is_initialized()) {
        builder->append(kBypassDocumentValidationFieldName, _bypassDocumentValidation.get());
    }

    if (_let.is_initialized()) {
        builder->append(kLetFieldName, _let.get());
    }

    if (_legacyRuntimeConstants.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kLegacyRuntimeConstantsFieldName));
        _legacyRuntimeConstants.get().serialize(&subObjBuilder);
    }

    if (_writeConcern.is_initialized()) {
        builder->append(kWriteConcernFieldName, _writeConcern.get());
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest FindAndModifyCommandRequest::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        invariant(!_nss.isEmpty());
        builder->append("findAndModify"_sd, _nss.coll());

        builder->append(kQueryFieldName, _query);

        if (_fields.is_initialized()) {
            builder->append(kFieldsFieldName, _fields.get());
        }

        if (_sort.is_initialized()) {
            builder->append(kSortFieldName, _sort.get());
        }

        if (_batchSize.is_initialized()) {
            builder->append(kBatchSizeFieldName, _batchSize.get());
        }

        if (_singleBatch.is_initialized()) {
            builder->append(kSingleBatchFieldName, _singleBatch.get());
        }

        {
            serializeHintToBSON(_hint, kHintFieldName, builder);
        }

        if (_collation.is_initialized()) {
            builder->append(kCollationFieldName, _collation.get());
        }

        if (_arrayFilters.is_initialized()) {
            builder->append(kArrayFiltersFieldName, _arrayFilters.get());
        }

        if (_remove.is_initialized()) {
            builder->append(kRemoveFieldName, _remove.get());
        }

        if (_update.is_initialized()) {
            _update.get().serializeToBSON(kUpdateFieldName, builder);
        }

        if (_upsert.is_initialized()) {
            builder->append(kUpsertFieldName, _upsert.get());
        }

        if (_new.is_initialized()) {
            builder->append(kNewFieldName, _new.get());
        }

        if (_bypassDocumentValidation.is_initialized()) {
            builder->append(kBypassDocumentValidationFieldName, _bypassDocumentValidation.get());
        }

        if (_let.is_initialized()) {
            builder->append(kLetFieldName, _let.get());
        }

        if (_legacyRuntimeConstants.is_initialized()) {
            BSONObjBuilder subObjBuilder(builder->subobjStart(kLegacyRuntimeConstantsFieldName));
            _legacyRuntimeConstants.get().serialize(&subObjBuilder);
        }

        if (_writeConcern.is_initialized()) {
            builder->append(kWriteConcernFieldName, _writeConcern.get());
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj FindAndModifyCommandRequest::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace write_ops
}  // namespace mongo
