/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/repl/apply_ops_gen.h --output build/opt/mongo/db/repl/apply_ops_gen.cpp src/mongo/db/repl/apply_ops.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/repl/apply_ops_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {
namespace repl {

constexpr StringData ApplyOpsCommandInfoBase::kAllowAtomicFieldName;
constexpr StringData ApplyOpsCommandInfoBase::kAlwaysUpsertFieldName;
constexpr StringData ApplyOpsCommandInfoBase::kCountFieldName;
constexpr StringData ApplyOpsCommandInfoBase::kOperationsFieldName;
constexpr StringData ApplyOpsCommandInfoBase::kPartialTxnFieldName;
constexpr StringData ApplyOpsCommandInfoBase::kPreConditionFieldName;
constexpr StringData ApplyOpsCommandInfoBase::kPrepareFieldName;


ApplyOpsCommandInfoBase::ApplyOpsCommandInfoBase() : _hasOperations(false) {
    // Used for initialization only
}
ApplyOpsCommandInfoBase::ApplyOpsCommandInfoBase(std::vector<mongo::BSONObj> operations) : _operations(std::move(operations)), _hasOperations(true) {
    // Used for initialization only
}


ApplyOpsCommandInfoBase ApplyOpsCommandInfoBase::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ApplyOpsCommandInfoBase>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ApplyOpsCommandInfoBase::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<7> usedFields;
    const size_t kOperationsBit = 0;
    const size_t kAllowAtomicBit = 1;
    const size_t kAlwaysUpsertBit = 2;
    const size_t kPreConditionBit = 3;
    const size_t kPrepareBit = 4;
    const size_t kPartialTxnBit = 5;
    const size_t kCountBit = 6;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kOperationsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kOperationsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kOperationsBit);

                _hasOperations = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kOperationsFieldName, &ctxt);
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
            _operations = std::move(values);
        }
        else if (fieldName == kAllowAtomicFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kAllowAtomicBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAllowAtomicBit);

                _allowAtomic = element.boolean();
            }
        }
        else if (fieldName == kAlwaysUpsertFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kAlwaysUpsertBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAlwaysUpsertBit);

                _alwaysUpsert = element.boolean();
            }
        }
        else if (fieldName == kPreConditionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kPreConditionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPreConditionBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kPreConditionFieldName, &ctxt);
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
            _preCondition = std::move(values);
        }
        else if (fieldName == kPrepareFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kPrepareBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPrepareBit);

                _prepare = element.boolean();
            }
        }
        else if (fieldName == kPartialTxnFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kPartialTxnBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPartialTxnBit);

                _partialTxn = element.boolean();
            }
        }
        else if (fieldName == kCountFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kCountBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCountBit);

                _count = element.safeNumberLong();
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
        if (!usedFields[kOperationsBit]) {
            ctxt.throwMissingField(kOperationsFieldName);
        }
        if (!usedFields[kAllowAtomicBit]) {
            _allowAtomic = true;
        }
        if (!usedFields[kAlwaysUpsertBit]) {
            _alwaysUpsert = true;
        }
    }

}


void ApplyOpsCommandInfoBase::serialize(BSONObjBuilder* builder) const {
    invariant(_hasOperations);

    {
        builder->append(kOperationsFieldName, _operations);
    }

    builder->append(kAllowAtomicFieldName, _allowAtomic);

    builder->append(kAlwaysUpsertFieldName, _alwaysUpsert);

    if (_preCondition.is_initialized()) {
        builder->append(kPreConditionFieldName, _preCondition.get());
    }

    if (_prepare.is_initialized()) {
        builder->append(kPrepareFieldName, _prepare.get());
    }

    if (_partialTxn.is_initialized()) {
        builder->append(kPartialTxnFieldName, _partialTxn.get());
    }

    if (_count.is_initialized()) {
        builder->append(kCountFieldName, _count.get());
    }

}


BSONObj ApplyOpsCommandInfoBase::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace repl
}  // namespace mongo
