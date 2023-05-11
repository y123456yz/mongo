/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/stats/read_concern_stats_gen.h --output build/opt/mongo/db/stats/read_concern_stats_gen.cpp src/mongo/db/stats/read_concern_stats.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/stats/read_concern_stats_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData SnapshotOps::kWithClusterTimeFieldName;
constexpr StringData SnapshotOps::kWithoutClusterTimeFieldName;


SnapshotOps::SnapshotOps()  {
    // Used for initialization only
}


SnapshotOps SnapshotOps::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<SnapshotOps>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void SnapshotOps::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kWithClusterTimeBit = 0;
    const size_t kWithoutClusterTimeBit = 1;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kWithClusterTimeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kWithClusterTimeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kWithClusterTimeBit);

                _withClusterTime = element._numberLong();
            }
        }
        else if (fieldName == kWithoutClusterTimeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kWithoutClusterTimeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kWithoutClusterTimeBit);

                _withoutClusterTime = element._numberLong();
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kWithClusterTimeBit]) {
            _withClusterTime = 0;
        }
        if (!usedFields[kWithoutClusterTimeBit]) {
            _withoutClusterTime = 0;
        }
    }

}


void SnapshotOps::serialize(BSONObjBuilder* builder) const {
    builder->append(kWithClusterTimeFieldName, _withClusterTime);

    builder->append(kWithoutClusterTimeFieldName, _withoutClusterTime);

}


BSONObj SnapshotOps::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData CWRCReadConcernOps::kAvailableFieldName;
constexpr StringData CWRCReadConcernOps::kLocalFieldName;
constexpr StringData CWRCReadConcernOps::kMajorityFieldName;


CWRCReadConcernOps::CWRCReadConcernOps()  {
    // Used for initialization only
}


CWRCReadConcernOps CWRCReadConcernOps::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<CWRCReadConcernOps>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void CWRCReadConcernOps::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<3> usedFields;
    const size_t kLocalBit = 0;
    const size_t kAvailableBit = 1;
    const size_t kMajorityBit = 2;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kLocalFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kLocalBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLocalBit);

                _local = element._numberLong();
            }
        }
        else if (fieldName == kAvailableFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kAvailableBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAvailableBit);

                _available = element._numberLong();
            }
        }
        else if (fieldName == kMajorityFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kMajorityBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMajorityBit);

                _majority = element._numberLong();
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kLocalBit]) {
            _local = 0;
        }
        if (!usedFields[kMajorityBit]) {
            _majority = 0;
        }
    }

}


void CWRCReadConcernOps::serialize(BSONObjBuilder* builder) const {
    builder->append(kLocalFieldName, _local);

    if (_available.is_initialized()) {
        builder->append(kAvailableFieldName, _available.get());
    }

    builder->append(kMajorityFieldName, _majority);

}


BSONObj CWRCReadConcernOps::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData ImplicitDefaultReadConcernOps::kAvailableFieldName;
constexpr StringData ImplicitDefaultReadConcernOps::kLocalFieldName;


ImplicitDefaultReadConcernOps::ImplicitDefaultReadConcernOps()  {
    // Used for initialization only
}


ImplicitDefaultReadConcernOps ImplicitDefaultReadConcernOps::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ImplicitDefaultReadConcernOps>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ImplicitDefaultReadConcernOps::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kLocalBit = 0;
    const size_t kAvailableBit = 1;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kLocalFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kLocalBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLocalBit);

                _local = element._numberLong();
            }
        }
        else if (fieldName == kAvailableFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kAvailableBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAvailableBit);

                _available = element._numberLong();
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kLocalBit]) {
            _local = 0;
        }
    }

}


void ImplicitDefaultReadConcernOps::serialize(BSONObjBuilder* builder) const {
    builder->append(kLocalFieldName, _local);

    if (_available.is_initialized()) {
        builder->append(kAvailableFieldName, _available.get());
    }

}


BSONObj ImplicitDefaultReadConcernOps::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData NoneInfo::kCWRCFieldName;
constexpr StringData NoneInfo::kImplicitDefaultFieldName;


NoneInfo::NoneInfo() : _cWRC(mongo::idl::preparsedValue<decltype(_cWRC)>()), _implicitDefault(mongo::idl::preparsedValue<decltype(_implicitDefault)>()), _hasCWRC(false), _hasImplicitDefault(false) {
    // Used for initialization only
}
NoneInfo::NoneInfo(mongo::CWRCReadConcernOps cWRC, mongo::ImplicitDefaultReadConcernOps implicitDefault) : _cWRC(std::move(cWRC)), _implicitDefault(std::move(implicitDefault)), _hasCWRC(true), _hasImplicitDefault(true) {
    // Used for initialization only
}


NoneInfo NoneInfo::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<NoneInfo>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void NoneInfo::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kCWRCBit = 0;
    const size_t kImplicitDefaultBit = 1;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kCWRCFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCWRCBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCWRCBit);

                _hasCWRC = true;
                IDLParserErrorContext tempContext(kCWRCFieldName, &ctxt);
                const auto localObject = element.Obj();
                _cWRC = mongo::CWRCReadConcernOps::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kImplicitDefaultFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kImplicitDefaultBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kImplicitDefaultBit);

                _hasImplicitDefault = true;
                IDLParserErrorContext tempContext(kImplicitDefaultFieldName, &ctxt);
                const auto localObject = element.Obj();
                _implicitDefault = mongo::ImplicitDefaultReadConcernOps::parse(tempContext, localObject);
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kCWRCBit]) {
            ctxt.throwMissingField(kCWRCFieldName);
        }
        if (!usedFields[kImplicitDefaultBit]) {
            ctxt.throwMissingField(kImplicitDefaultFieldName);
        }
    }

}


void NoneInfo::serialize(BSONObjBuilder* builder) const {
    invariant(_hasCWRC && _hasImplicitDefault);

    {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kCWRCFieldName));
        _cWRC.serialize(&subObjBuilder);
    }

    {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kImplicitDefaultFieldName));
        _implicitDefault.serialize(&subObjBuilder);
    }

}


BSONObj NoneInfo::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData ReadConcernOps::kAvailableFieldName;
constexpr StringData ReadConcernOps::kLinearizableFieldName;
constexpr StringData ReadConcernOps::kLocalFieldName;
constexpr StringData ReadConcernOps::kMajorityFieldName;
constexpr StringData ReadConcernOps::kNoneFieldName;
constexpr StringData ReadConcernOps::kNoneInfoFieldName;
constexpr StringData ReadConcernOps::kSnapshotFieldName;


ReadConcernOps::ReadConcernOps() : _noneInfo(mongo::idl::preparsedValue<decltype(_noneInfo)>()), _snapshot(mongo::idl::preparsedValue<decltype(_snapshot)>()), _hasNoneInfo(false), _hasSnapshot(false) {
    // Used for initialization only
}
ReadConcernOps::ReadConcernOps(mongo::NoneInfo noneInfo, mongo::SnapshotOps snapshot) : _noneInfo(std::move(noneInfo)), _snapshot(std::move(snapshot)), _hasNoneInfo(true), _hasSnapshot(true) {
    // Used for initialization only
}


ReadConcernOps ReadConcernOps::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ReadConcernOps>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ReadConcernOps::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<7> usedFields;
    const size_t kNoneBit = 0;
    const size_t kNoneInfoBit = 1;
    const size_t kLocalBit = 2;
    const size_t kAvailableBit = 3;
    const size_t kMajorityBit = 4;
    const size_t kSnapshotBit = 5;
    const size_t kLinearizableBit = 6;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kNoneFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kNoneBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNoneBit);

                _none = element._numberLong();
            }
        }
        else if (fieldName == kNoneInfoFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kNoneInfoBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNoneInfoBit);

                _hasNoneInfo = true;
                IDLParserErrorContext tempContext(kNoneInfoFieldName, &ctxt);
                const auto localObject = element.Obj();
                _noneInfo = mongo::NoneInfo::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kLocalFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kLocalBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLocalBit);

                _local = element._numberLong();
            }
        }
        else if (fieldName == kAvailableFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kAvailableBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAvailableBit);

                _available = element._numberLong();
            }
        }
        else if (fieldName == kMajorityFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kMajorityBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMajorityBit);

                _majority = element._numberLong();
            }
        }
        else if (fieldName == kSnapshotFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kSnapshotBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSnapshotBit);

                _hasSnapshot = true;
                IDLParserErrorContext tempContext(kSnapshotFieldName, &ctxt);
                const auto localObject = element.Obj();
                _snapshot = mongo::SnapshotOps::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kLinearizableFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kLinearizableBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLinearizableBit);

                _linearizable = element._numberLong();
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kNoneBit]) {
            _none = 0;
        }
        if (!usedFields[kNoneInfoBit]) {
            ctxt.throwMissingField(kNoneInfoFieldName);
        }
        if (!usedFields[kLocalBit]) {
            _local = 0;
        }
        if (!usedFields[kMajorityBit]) {
            _majority = 0;
        }
        if (!usedFields[kSnapshotBit]) {
            ctxt.throwMissingField(kSnapshotFieldName);
        }
    }

}


void ReadConcernOps::serialize(BSONObjBuilder* builder) const {
    invariant(_hasNoneInfo && _hasSnapshot);

    builder->append(kNoneFieldName, _none);

    {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kNoneInfoFieldName));
        _noneInfo.serialize(&subObjBuilder);
    }

    builder->append(kLocalFieldName, _local);

    if (_available.is_initialized()) {
        builder->append(kAvailableFieldName, _available.get());
    }

    builder->append(kMajorityFieldName, _majority);

    {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kSnapshotFieldName));
        _snapshot.serialize(&subObjBuilder);
    }

    if (_linearizable.is_initialized()) {
        builder->append(kLinearizableFieldName, _linearizable.get());
    }

}


BSONObj ReadConcernOps::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData ReadConcernStats::kNonTransactionOpsFieldName;
constexpr StringData ReadConcernStats::kTransactionOpsFieldName;


ReadConcernStats::ReadConcernStats() : _nonTransactionOps(mongo::idl::preparsedValue<decltype(_nonTransactionOps)>()), _transactionOps(mongo::idl::preparsedValue<decltype(_transactionOps)>()), _hasNonTransactionOps(false), _hasTransactionOps(false) {
    // Used for initialization only
}
ReadConcernStats::ReadConcernStats(mongo::ReadConcernOps nonTransactionOps, mongo::ReadConcernOps transactionOps) : _nonTransactionOps(std::move(nonTransactionOps)), _transactionOps(std::move(transactionOps)), _hasNonTransactionOps(true), _hasTransactionOps(true) {
    // Used for initialization only
}


ReadConcernStats ReadConcernStats::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ReadConcernStats>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ReadConcernStats::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kNonTransactionOpsBit = 0;
    const size_t kTransactionOpsBit = 1;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kNonTransactionOpsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kNonTransactionOpsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNonTransactionOpsBit);

                _hasNonTransactionOps = true;
                IDLParserErrorContext tempContext(kNonTransactionOpsFieldName, &ctxt);
                const auto localObject = element.Obj();
                _nonTransactionOps = mongo::ReadConcernOps::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kTransactionOpsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kTransactionOpsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTransactionOpsBit);

                _hasTransactionOps = true;
                IDLParserErrorContext tempContext(kTransactionOpsFieldName, &ctxt);
                const auto localObject = element.Obj();
                _transactionOps = mongo::ReadConcernOps::parse(tempContext, localObject);
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kNonTransactionOpsBit]) {
            ctxt.throwMissingField(kNonTransactionOpsFieldName);
        }
        if (!usedFields[kTransactionOpsBit]) {
            ctxt.throwMissingField(kTransactionOpsFieldName);
        }
    }

}


void ReadConcernStats::serialize(BSONObjBuilder* builder) const {
    invariant(_hasNonTransactionOps && _hasTransactionOps);

    {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kNonTransactionOpsFieldName));
        _nonTransactionOps.serialize(&subObjBuilder);
    }

    {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kTransactionOpsFieldName));
        _transactionOps.serialize(&subObjBuilder);
    }

}


BSONObj ReadConcernStats::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
