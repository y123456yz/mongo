/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/session_txn_record_gen.h --output build/opt/mongo/db/session_txn_record_gen.cpp src/mongo/db/session_txn_record.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/session_txn_record_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

/**
 * The state of the most recent durable transaction on a session
 */
namespace  {
constexpr StringData kDurableTxnState_kPrepared = "prepared"_sd;
constexpr StringData kDurableTxnState_kCommitted = "committed"_sd;
constexpr StringData kDurableTxnState_kAborted = "aborted"_sd;
constexpr StringData kDurableTxnState_kInProgress = "inProgress"_sd;
}  // namespace 

DurableTxnStateEnum DurableTxnState_parse(const IDLParserErrorContext& ctxt, StringData value) {
    if (value == kDurableTxnState_kPrepared) {
        return DurableTxnStateEnum::kPrepared;
    }
    if (value == kDurableTxnState_kCommitted) {
        return DurableTxnStateEnum::kCommitted;
    }
    if (value == kDurableTxnState_kAborted) {
        return DurableTxnStateEnum::kAborted;
    }
    if (value == kDurableTxnState_kInProgress) {
        return DurableTxnStateEnum::kInProgress;
    }
    ctxt.throwBadEnumValue(value);
}

StringData DurableTxnState_serializer(DurableTxnStateEnum value) {
    if (value == DurableTxnStateEnum::kPrepared) {
        return kDurableTxnState_kPrepared;
    }
    if (value == DurableTxnStateEnum::kCommitted) {
        return kDurableTxnState_kCommitted;
    }
    if (value == DurableTxnStateEnum::kAborted) {
        return kDurableTxnState_kAborted;
    }
    if (value == DurableTxnStateEnum::kInProgress) {
        return kDurableTxnState_kInProgress;
    }
    MONGO_UNREACHABLE;
    return StringData();
}

constexpr StringData SessionTxnRecord::kLastWriteDateFieldName;
constexpr StringData SessionTxnRecord::kLastWriteOpTimeFieldName;
constexpr StringData SessionTxnRecord::kSessionIdFieldName;
constexpr StringData SessionTxnRecord::kStartOpTimeFieldName;
constexpr StringData SessionTxnRecord::kStateFieldName;
constexpr StringData SessionTxnRecord::kTxnNumFieldName;


SessionTxnRecord::SessionTxnRecord() : _sessionId(mongo::idl::preparsedValue<decltype(_sessionId)>()), _txnNum(mongo::idl::preparsedValue<decltype(_txnNum)>()), _lastWriteOpTime(mongo::idl::preparsedValue<decltype(_lastWriteOpTime)>()), _lastWriteDate(mongo::idl::preparsedValue<decltype(_lastWriteDate)>()), _hasSessionId(false), _hasTxnNum(false), _hasLastWriteOpTime(false), _hasLastWriteDate(false) {
    // Used for initialization only
}
SessionTxnRecord::SessionTxnRecord(mongo::LogicalSessionId sessionId, std::int64_t txnNum, mongo::repl::OpTime lastWriteOpTime, mongo::Date_t lastWriteDate) : _sessionId(std::move(sessionId)), _txnNum(std::move(txnNum)), _lastWriteOpTime(std::move(lastWriteOpTime)), _lastWriteDate(std::move(lastWriteDate)), _hasSessionId(true), _hasTxnNum(true), _hasLastWriteOpTime(true), _hasLastWriteDate(true) {
    // Used for initialization only
}


SessionTxnRecord SessionTxnRecord::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<SessionTxnRecord>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void SessionTxnRecord::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<6> usedFields;
    const size_t kSessionIdBit = 0;
    const size_t kTxnNumBit = 1;
    const size_t kStartOpTimeBit = 2;
    const size_t kLastWriteOpTimeBit = 3;
    const size_t kLastWriteDateBit = 4;
    const size_t kStateBit = 5;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kSessionIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kSessionIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSessionIdBit);

                _hasSessionId = true;
                IDLParserErrorContext tempContext(kSessionIdFieldName, &ctxt);
                const auto localObject = element.Obj();
                _sessionId = mongo::LogicalSessionId::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kTxnNumFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kTxnNumBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTxnNumBit);

                _hasTxnNum = true;
                _txnNum = element._numberLong();
            }
        }
        else if (fieldName == kStartOpTimeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kStartOpTimeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStartOpTimeBit);

                const BSONObj localObject = element.Obj();
                _startOpTime = repl::OpTime::parse(localObject);
            }
        }
        else if (fieldName == kLastWriteOpTimeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kLastWriteOpTimeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLastWriteOpTimeBit);

                _hasLastWriteOpTime = true;
                const BSONObj localObject = element.Obj();
                _lastWriteOpTime = repl::OpTime::parse(localObject);
            }
        }
        else if (fieldName == kLastWriteDateFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Date))) {
                if (MONGO_unlikely(usedFields[kLastWriteDateBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLastWriteDateBit);

                _hasLastWriteDate = true;
                _lastWriteDate = element.date();
            }
        }
        else if (fieldName == kStateFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kStateBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStateBit);

                IDLParserErrorContext tempContext(kStateFieldName, &ctxt);
                _state = DurableTxnState_parse(tempContext, element.valueStringData());
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
        if (!usedFields[kSessionIdBit]) {
            ctxt.throwMissingField(kSessionIdFieldName);
        }
        if (!usedFields[kTxnNumBit]) {
            ctxt.throwMissingField(kTxnNumFieldName);
        }
        if (!usedFields[kLastWriteOpTimeBit]) {
            ctxt.throwMissingField(kLastWriteOpTimeFieldName);
        }
        if (!usedFields[kLastWriteDateBit]) {
            ctxt.throwMissingField(kLastWriteDateFieldName);
        }
    }

}


void SessionTxnRecord::serialize(BSONObjBuilder* builder) const {
    invariant(_hasSessionId && _hasTxnNum && _hasLastWriteOpTime && _hasLastWriteDate);

    {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kSessionIdFieldName));
        _sessionId.serialize(&subObjBuilder);
    }

    builder->append(kTxnNumFieldName, _txnNum);

    if (_startOpTime.is_initialized()) {
        const BSONObj localObject = _startOpTime.get().toBSON();
        builder->append(kStartOpTimeFieldName, localObject);
    }

    {
        const BSONObj localObject = _lastWriteOpTime.toBSON();
        builder->append(kLastWriteOpTimeFieldName, localObject);
    }

    builder->append(kLastWriteDateFieldName, _lastWriteDate);

    if (_state.is_initialized()) {
        builder->append(kStateFieldName, ::mongo::DurableTxnState_serializer(_state.get()));
    }

}


BSONObj SessionTxnRecord::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
