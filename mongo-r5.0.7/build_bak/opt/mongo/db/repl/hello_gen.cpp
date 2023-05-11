/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/repl/hello_gen.h --output build/opt/mongo/db/repl/hello_gen.cpp src/mongo/db/repl/hello.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/repl/hello_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData HelloInternalClientField::kMaxWireVersionFieldName;
constexpr StringData HelloInternalClientField::kMinWireVersionFieldName;


HelloInternalClientField::HelloInternalClientField() : _maxWireVersion(mongo::idl::preparsedValue<decltype(_maxWireVersion)>()), _hasMaxWireVersion(false) {
    // Used for initialization only
}
HelloInternalClientField::HelloInternalClientField(std::int32_t maxWireVersion) : _maxWireVersion(std::move(maxWireVersion)), _hasMaxWireVersion(true) {
    // Used for initialization only
}


HelloInternalClientField HelloInternalClientField::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<HelloInternalClientField>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void HelloInternalClientField::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kMinWireVersionBit = 0;
    const size_t kMaxWireVersionBit = 1;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kMinWireVersionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kMinWireVersionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMinWireVersionBit);

                _minWireVersion = element.safeNumberInt();
            }
        }
        else if (fieldName == kMaxWireVersionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kMaxWireVersionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMaxWireVersionBit);

                _hasMaxWireVersion = true;
                _maxWireVersion = element.safeNumberInt();
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kMinWireVersionBit]) {
            _minWireVersion = 0;
        }
        if (!usedFields[kMaxWireVersionBit]) {
            ctxt.throwMissingField(kMaxWireVersionFieldName);
        }
    }

}


void HelloInternalClientField::serialize(BSONObjBuilder* builder) const {
    invariant(_hasMaxWireVersion);

    builder->append(kMinWireVersionFieldName, _minWireVersion);

    builder->append(kMaxWireVersionFieldName, _maxWireVersion);

}


BSONObj HelloInternalClientField::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData HelloLastWrite::kLastWriteDateFieldName;
constexpr StringData HelloLastWrite::kMajorityOpTimeFieldName;
constexpr StringData HelloLastWrite::kMajorityWriteDateFieldName;
constexpr StringData HelloLastWrite::kOpTimeFieldName;


HelloLastWrite::HelloLastWrite()  {
    // Used for initialization only
}


HelloLastWrite HelloLastWrite::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<HelloLastWrite>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void HelloLastWrite::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<4> usedFields;
    const size_t kOpTimeBit = 0;
    const size_t kLastWriteDateBit = 1;
    const size_t kMajorityOpTimeBit = 2;
    const size_t kMajorityWriteDateBit = 3;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kOpTimeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kOpTimeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kOpTimeBit);

                const BSONObj localObject = element.Obj();
                _opTime = repl::OpTime::parse(localObject);
            }
        }
        else if (fieldName == kLastWriteDateFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Date))) {
                if (MONGO_unlikely(usedFields[kLastWriteDateBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLastWriteDateBit);

                _lastWriteDate = element.date();
            }
        }
        else if (fieldName == kMajorityOpTimeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kMajorityOpTimeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMajorityOpTimeBit);

                const BSONObj localObject = element.Obj();
                _majorityOpTime = repl::OpTime::parse(localObject);
            }
        }
        else if (fieldName == kMajorityWriteDateFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Date))) {
                if (MONGO_unlikely(usedFields[kMajorityWriteDateBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMajorityWriteDateBit);

                _majorityWriteDate = element.date();
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
    }

}


void HelloLastWrite::serialize(BSONObjBuilder* builder) const {
    if (_opTime.is_initialized()) {
        const BSONObj localObject = _opTime.get().toBSON();
        builder->append(kOpTimeFieldName, localObject);
    }

    if (_lastWriteDate.is_initialized()) {
        builder->append(kLastWriteDateFieldName, _lastWriteDate.get());
    }

    if (_majorityOpTime.is_initialized()) {
        const BSONObj localObject = _majorityOpTime.get().toBSON();
        builder->append(kMajorityOpTimeFieldName, localObject);
    }

    if (_majorityWriteDate.is_initialized()) {
        builder->append(kMajorityWriteDateFieldName, _majorityWriteDate.get());
    }

}


BSONObj HelloLastWrite::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData HelloCommandReply::kArbiterOnlyFieldName;
constexpr StringData HelloCommandReply::kArbitersFieldName;
constexpr StringData HelloCommandReply::kAutomationServiceDescriptorFieldName;
constexpr StringData HelloCommandReply::kBuildIndexesFieldName;
constexpr StringData HelloCommandReply::kClientSupportsHelloFieldName;
constexpr StringData HelloCommandReply::kCompressionFieldName;
constexpr StringData HelloCommandReply::kConfigsvrFieldName;
constexpr StringData HelloCommandReply::kConnectionIdFieldName;
constexpr StringData HelloCommandReply::kCwwcFieldName;
constexpr StringData HelloCommandReply::kElectionIdFieldName;
constexpr StringData HelloCommandReply::kHelloOkFieldName;
constexpr StringData HelloCommandReply::kHiddenFieldName;
constexpr StringData HelloCommandReply::kHostsFieldName;
constexpr StringData HelloCommandReply::kInfoFieldName;
constexpr StringData HelloCommandReply::kIsImplicitDefaultMajorityWCFieldName;
constexpr StringData HelloCommandReply::kIsWritablePrimaryFieldName;
constexpr StringData HelloCommandReply::kIsmasterFieldName;
constexpr StringData HelloCommandReply::kIsreplicasetFieldName;
constexpr StringData HelloCommandReply::kLastWriteFieldName;
constexpr StringData HelloCommandReply::kLocalTimeFieldName;
constexpr StringData HelloCommandReply::kLogicalSessionTimeoutMinutesFieldName;
constexpr StringData HelloCommandReply::kMaxBsonObjectSizeFieldName;
constexpr StringData HelloCommandReply::kMaxMessageSizeBytesFieldName;
constexpr StringData HelloCommandReply::kMaxWireVersionFieldName;
constexpr StringData HelloCommandReply::kMaxWriteBatchSizeFieldName;
constexpr StringData HelloCommandReply::kMeFieldName;
constexpr StringData HelloCommandReply::kMinWireVersionFieldName;
constexpr StringData HelloCommandReply::kMsgFieldName;
constexpr StringData HelloCommandReply::kPassiveFieldName;
constexpr StringData HelloCommandReply::kPassivesFieldName;
constexpr StringData HelloCommandReply::kPrimaryFieldName;
constexpr StringData HelloCommandReply::kReadOnlyFieldName;
constexpr StringData HelloCommandReply::kSaslSupportedMechsFieldName;
constexpr StringData HelloCommandReply::kSecondaryFieldName;
constexpr StringData HelloCommandReply::kSecondaryDelaySecsFieldName;
constexpr StringData HelloCommandReply::kServiceIdFieldName;
constexpr StringData HelloCommandReply::kSetNameFieldName;
constexpr StringData HelloCommandReply::kSetVersionFieldName;
constexpr StringData HelloCommandReply::kSlaveDelayFieldName;
constexpr StringData HelloCommandReply::kSpeculativeAuthenticateFieldName;
constexpr StringData HelloCommandReply::kTagsFieldName;
constexpr StringData HelloCommandReply::kTopologyVersionFieldName;


HelloCommandReply::HelloCommandReply() : _topologyVersion(mongo::idl::preparsedValue<decltype(_topologyVersion)>()), _hasTopologyVersion(false) {
    // Used for initialization only
}
HelloCommandReply::HelloCommandReply(mongo::TopologyVersion topologyVersion) : _topologyVersion(std::move(topologyVersion)), _hasTopologyVersion(true) {
    // Used for initialization only
}


HelloCommandReply HelloCommandReply::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<HelloCommandReply>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void HelloCommandReply::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<42> usedFields;
    const size_t kHelloOkBit = 0;
    const size_t kClientSupportsHelloBit = 1;
    const size_t kConfigsvrBit = 2;
    const size_t kMaxBsonObjectSizeBit = 3;
    const size_t kMaxMessageSizeBytesBit = 4;
    const size_t kMaxWriteBatchSizeBit = 5;
    const size_t kLocalTimeBit = 6;
    const size_t kLogicalSessionTimeoutMinutesBit = 7;
    const size_t kConnectionIdBit = 8;
    const size_t kMinWireVersionBit = 9;
    const size_t kMaxWireVersionBit = 10;
    const size_t kReadOnlyBit = 11;
    const size_t kCompressionBit = 12;
    const size_t kAutomationServiceDescriptorBit = 13;
    const size_t kSaslSupportedMechsBit = 14;
    const size_t kSpeculativeAuthenticateBit = 15;
    const size_t kMsgBit = 16;
    const size_t kServiceIdBit = 17;
    const size_t kTopologyVersionBit = 18;
    const size_t kIsmasterBit = 19;
    const size_t kIsWritablePrimaryBit = 20;
    const size_t kHostsBit = 21;
    const size_t kPassivesBit = 22;
    const size_t kArbitersBit = 23;
    const size_t kSetNameBit = 24;
    const size_t kPrimaryBit = 25;
    const size_t kSecondaryBit = 26;
    const size_t kInfoBit = 27;
    const size_t kIsreplicasetBit = 28;
    const size_t kSetVersionBit = 29;
    const size_t kArbiterOnlyBit = 30;
    const size_t kPassiveBit = 31;
    const size_t kHiddenBit = 32;
    const size_t kBuildIndexesBit = 33;
    const size_t kSlaveDelayBit = 34;
    const size_t kSecondaryDelaySecsBit = 35;
    const size_t kTagsBit = 36;
    const size_t kMeBit = 37;
    const size_t kElectionIdBit = 38;
    const size_t kLastWriteBit = 39;
    const size_t kIsImplicitDefaultMajorityWCBit = 40;
    const size_t kCwwcBit = 41;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kHelloOkFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kHelloOkBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kHelloOkBit);

                _helloOk = element.boolean();
            }
        }
        else if (fieldName == kClientSupportsHelloFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kClientSupportsHelloBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kClientSupportsHelloBit);

                _clientSupportsHello = element.boolean();
            }
        }
        else if (fieldName == kConfigsvrFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kConfigsvrBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kConfigsvrBit);

                _configsvr = element.safeNumberInt();
            }
        }
        else if (fieldName == kMaxBsonObjectSizeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kMaxBsonObjectSizeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMaxBsonObjectSizeBit);

                _maxBsonObjectSize = element.safeNumberLong();
            }
        }
        else if (fieldName == kMaxMessageSizeBytesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kMaxMessageSizeBytesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMaxMessageSizeBytesBit);

                _maxMessageSizeBytes = element.safeNumberLong();
            }
        }
        else if (fieldName == kMaxWriteBatchSizeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kMaxWriteBatchSizeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMaxWriteBatchSizeBit);

                _maxWriteBatchSize = element.safeNumberLong();
            }
        }
        else if (fieldName == kLocalTimeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Date))) {
                if (MONGO_unlikely(usedFields[kLocalTimeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLocalTimeBit);

                _localTime = element.date();
            }
        }
        else if (fieldName == kLogicalSessionTimeoutMinutesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kLogicalSessionTimeoutMinutesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLogicalSessionTimeoutMinutesBit);

                _logicalSessionTimeoutMinutes = element.safeNumberInt();
            }
        }
        else if (fieldName == kConnectionIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kConnectionIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kConnectionIdBit);

                _connectionId = element.safeNumberLong();
            }
        }
        else if (fieldName == kMinWireVersionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kMinWireVersionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMinWireVersionBit);

                _minWireVersion = element.safeNumberInt();
            }
        }
        else if (fieldName == kMaxWireVersionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kMaxWireVersionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMaxWireVersionBit);

                _maxWireVersion = element.safeNumberInt();
            }
        }
        else if (fieldName == kReadOnlyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kReadOnlyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kReadOnlyBit);

                _readOnly = element.boolean();
            }
        }
        else if (fieldName == kCompressionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kCompressionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCompressionBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kCompressionFieldName, &ctxt);
            std::vector<std::string> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, String)) {
                        values.emplace_back(arrayElement.str());
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _compression = std::move(values);
        }
        else if (fieldName == kAutomationServiceDescriptorFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kAutomationServiceDescriptorBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kAutomationServiceDescriptorBit);

                _automationServiceDescriptor = element.str();
            }
        }
        else if (fieldName == kSaslSupportedMechsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kSaslSupportedMechsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSaslSupportedMechsBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kSaslSupportedMechsFieldName, &ctxt);
            std::vector<std::string> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, String)) {
                        values.emplace_back(arrayElement.str());
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _saslSupportedMechs = std::move(values);
        }
        else if (fieldName == kSpeculativeAuthenticateFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kSpeculativeAuthenticateBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSpeculativeAuthenticateBit);

                _speculativeAuthenticate = element.Obj();
            }
        }
        else if (fieldName == kMsgFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kMsgBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMsgBit);

                _msg = element.str();
            }
        }
        else if (fieldName == kServiceIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, jstOID))) {
                if (MONGO_unlikely(usedFields[kServiceIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kServiceIdBit);

                _serviceId = element.OID();
            }
        }
        else if (fieldName == kTopologyVersionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kTopologyVersionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTopologyVersionBit);

                _hasTopologyVersion = true;
                IDLParserErrorContext tempContext(kTopologyVersionFieldName, &ctxt);
                const auto localObject = element.Obj();
                _topologyVersion = mongo::TopologyVersion::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kIsmasterFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kIsmasterBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIsmasterBit);

                _ismaster = element.boolean();
            }
        }
        else if (fieldName == kIsWritablePrimaryFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kIsWritablePrimaryBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIsWritablePrimaryBit);

                _isWritablePrimary = element.boolean();
            }
        }
        else if (fieldName == kHostsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kHostsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kHostsBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kHostsFieldName, &ctxt);
            std::vector<std::string> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, String)) {
                        values.emplace_back(arrayElement.str());
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _hosts = std::move(values);
        }
        else if (fieldName == kPassivesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kPassivesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPassivesBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kPassivesFieldName, &ctxt);
            std::vector<std::string> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, String)) {
                        values.emplace_back(arrayElement.str());
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _passives = std::move(values);
        }
        else if (fieldName == kArbitersFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kArbitersBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kArbitersBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kArbitersFieldName, &ctxt);
            std::vector<std::string> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, String)) {
                        values.emplace_back(arrayElement.str());
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _arbiters = std::move(values);
        }
        else if (fieldName == kSetNameFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kSetNameBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSetNameBit);

                _setName = element.str();
            }
        }
        else if (fieldName == kPrimaryFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kPrimaryBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPrimaryBit);

                _primary = element.str();
            }
        }
        else if (fieldName == kSecondaryFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kSecondaryBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSecondaryBit);

                _secondary = element.boolean();
            }
        }
        else if (fieldName == kInfoFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kInfoBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kInfoBit);

                _info = element.str();
            }
        }
        else if (fieldName == kIsreplicasetFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kIsreplicasetBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIsreplicasetBit);

                _isreplicaset = element.boolean();
            }
        }
        else if (fieldName == kSetVersionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kSetVersionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSetVersionBit);

                _setVersion = element.safeNumberInt();
            }
        }
        else if (fieldName == kArbiterOnlyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kArbiterOnlyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kArbiterOnlyBit);

                _arbiterOnly = element.boolean();
            }
        }
        else if (fieldName == kPassiveFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kPassiveBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPassiveBit);

                _passive = element.boolean();
            }
        }
        else if (fieldName == kHiddenFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kHiddenBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kHiddenBit);

                _hidden = element.boolean();
            }
        }
        else if (fieldName == kBuildIndexesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kBuildIndexesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kBuildIndexesBit);

                _buildIndexes = element.boolean();
            }
        }
        else if (fieldName == kSlaveDelayFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kSlaveDelayBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSlaveDelayBit);

                _slaveDelay = element.safeNumberLong();
            }
        }
        else if (fieldName == kSecondaryDelaySecsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kSecondaryDelaySecsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSecondaryDelaySecsBit);

                _secondaryDelaySecs = element.safeNumberLong();
            }
        }
        else if (fieldName == kTagsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kTagsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTagsBit);

                _tags = element.Obj();
            }
        }
        else if (fieldName == kMeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kMeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMeBit);

                _me = element.str();
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
        else if (fieldName == kLastWriteFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kLastWriteBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLastWriteBit);

                IDLParserErrorContext tempContext(kLastWriteFieldName, &ctxt);
                const auto localObject = element.Obj();
                _lastWrite = mongo::HelloLastWrite::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kIsImplicitDefaultMajorityWCFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kIsImplicitDefaultMajorityWCBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIsImplicitDefaultMajorityWCBit);

                _isImplicitDefaultMajorityWC = element.boolean();
            }
        }
        else if (fieldName == kCwwcFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCwwcBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCwwcBit);

                const BSONObj localObject = element.Obj();
                _cwwc = WriteConcernOptions::deserializerForIDL(localObject);
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kHelloOkBit]) {
            _helloOk = true;
        }
        if (!usedFields[kTopologyVersionBit]) {
            ctxt.throwMissingField(kTopologyVersionFieldName);
        }
    }

}


void HelloCommandReply::serialize(BSONObjBuilder* builder) const {
    invariant(_hasTopologyVersion);

    builder->append(kHelloOkFieldName, _helloOk);

    if (_clientSupportsHello.is_initialized()) {
        builder->append(kClientSupportsHelloFieldName, _clientSupportsHello.get());
    }

    if (_configsvr.is_initialized()) {
        builder->append(kConfigsvrFieldName, _configsvr.get());
    }

    if (_maxBsonObjectSize.is_initialized()) {
        builder->append(kMaxBsonObjectSizeFieldName, _maxBsonObjectSize.get());
    }

    if (_maxMessageSizeBytes.is_initialized()) {
        builder->append(kMaxMessageSizeBytesFieldName, _maxMessageSizeBytes.get());
    }

    if (_maxWriteBatchSize.is_initialized()) {
        builder->append(kMaxWriteBatchSizeFieldName, _maxWriteBatchSize.get());
    }

    if (_localTime.is_initialized()) {
        builder->append(kLocalTimeFieldName, _localTime.get());
    }

    if (_logicalSessionTimeoutMinutes.is_initialized()) {
        builder->append(kLogicalSessionTimeoutMinutesFieldName, _logicalSessionTimeoutMinutes.get());
    }

    if (_connectionId.is_initialized()) {
        builder->append(kConnectionIdFieldName, _connectionId.get());
    }

    if (_minWireVersion.is_initialized()) {
        builder->append(kMinWireVersionFieldName, _minWireVersion.get());
    }

    if (_maxWireVersion.is_initialized()) {
        builder->append(kMaxWireVersionFieldName, _maxWireVersion.get());
    }

    if (_readOnly.is_initialized()) {
        builder->append(kReadOnlyFieldName, _readOnly.get());
    }

    if (_compression.is_initialized()) {
        builder->append(kCompressionFieldName, _compression.get());
    }

    if (_automationServiceDescriptor.is_initialized()) {
        builder->append(kAutomationServiceDescriptorFieldName, _automationServiceDescriptor.get());
    }

    if (_saslSupportedMechs.is_initialized()) {
        builder->append(kSaslSupportedMechsFieldName, _saslSupportedMechs.get());
    }

    if (_speculativeAuthenticate.is_initialized()) {
        builder->append(kSpeculativeAuthenticateFieldName, _speculativeAuthenticate.get());
    }

    if (_msg.is_initialized()) {
        builder->append(kMsgFieldName, _msg.get());
    }

    if (_serviceId.is_initialized()) {
        builder->append(kServiceIdFieldName, _serviceId.get());
    }

    {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kTopologyVersionFieldName));
        _topologyVersion.serialize(&subObjBuilder);
    }

    if (_ismaster.is_initialized()) {
        builder->append(kIsmasterFieldName, _ismaster.get());
    }

    if (_isWritablePrimary.is_initialized()) {
        builder->append(kIsWritablePrimaryFieldName, _isWritablePrimary.get());
    }

    if (_hosts.is_initialized()) {
        builder->append(kHostsFieldName, _hosts.get());
    }

    if (_passives.is_initialized()) {
        builder->append(kPassivesFieldName, _passives.get());
    }

    if (_arbiters.is_initialized()) {
        builder->append(kArbitersFieldName, _arbiters.get());
    }

    if (_setName.is_initialized()) {
        builder->append(kSetNameFieldName, _setName.get());
    }

    if (_primary.is_initialized()) {
        builder->append(kPrimaryFieldName, _primary.get());
    }

    if (_secondary.is_initialized()) {
        builder->append(kSecondaryFieldName, _secondary.get());
    }

    if (_info.is_initialized()) {
        builder->append(kInfoFieldName, _info.get());
    }

    if (_isreplicaset.is_initialized()) {
        builder->append(kIsreplicasetFieldName, _isreplicaset.get());
    }

    if (_setVersion.is_initialized()) {
        builder->append(kSetVersionFieldName, _setVersion.get());
    }

    if (_arbiterOnly.is_initialized()) {
        builder->append(kArbiterOnlyFieldName, _arbiterOnly.get());
    }

    if (_passive.is_initialized()) {
        builder->append(kPassiveFieldName, _passive.get());
    }

    if (_hidden.is_initialized()) {
        builder->append(kHiddenFieldName, _hidden.get());
    }

    if (_buildIndexes.is_initialized()) {
        builder->append(kBuildIndexesFieldName, _buildIndexes.get());
    }

    if (_slaveDelay.is_initialized()) {
        builder->append(kSlaveDelayFieldName, _slaveDelay.get());
    }

    if (_secondaryDelaySecs.is_initialized()) {
        builder->append(kSecondaryDelaySecsFieldName, _secondaryDelaySecs.get());
    }

    if (_tags.is_initialized()) {
        builder->append(kTagsFieldName, _tags.get());
    }

    if (_me.is_initialized()) {
        builder->append(kMeFieldName, _me.get());
    }

    if (_electionId.is_initialized()) {
        builder->append(kElectionIdFieldName, _electionId.get());
    }

    if (_lastWrite.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kLastWriteFieldName));
        _lastWrite.get().serialize(&subObjBuilder);
    }

    if (_isImplicitDefaultMajorityWC.is_initialized()) {
        builder->append(kIsImplicitDefaultMajorityWCFieldName, _isImplicitDefaultMajorityWC.get());
    }

    if (_cwwc.is_initialized()) {
        const BSONObj localObject = _cwwc.get().toBSON();
        builder->append(kCwwcFieldName, localObject);
    }

}


BSONObj HelloCommandReply::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData HelloCommand::kClientFieldName;
constexpr StringData HelloCommand::kCompressionFieldName;
constexpr StringData HelloCommand::kDbNameFieldName;
constexpr StringData HelloCommand::kForShellFieldName;
constexpr StringData HelloCommand::kHangUpOnStepDownFieldName;
constexpr StringData HelloCommand::kHelloOkFieldName;
constexpr StringData HelloCommand::kHostInfoFieldName;
constexpr StringData HelloCommand::kInternalClientFieldName;
constexpr StringData HelloCommand::kLoadBalancedFieldName;
constexpr StringData HelloCommand::kMaxAwaitTimeMSFieldName;
constexpr StringData HelloCommand::kSaslSupportedMechsFieldName;
constexpr StringData HelloCommand::kSpeculativeAuthenticateFieldName;
constexpr StringData HelloCommand::kTopologyVersionFieldName;
constexpr StringData HelloCommand::kCommandName;

mongo::AuthorizationContract HelloCommand::kAuthorizationContract = AuthorizationContract(std::initializer_list<AccessCheckEnum>{}, std::initializer_list<Privilege>{});

const std::vector<StringData> HelloCommand::_knownBSONFields {
    HelloCommand::kClientFieldName,
    HelloCommand::kCompressionFieldName,
    HelloCommand::kForShellFieldName,
    HelloCommand::kHangUpOnStepDownFieldName,
    HelloCommand::kHelloOkFieldName,
    HelloCommand::kHostInfoFieldName,
    HelloCommand::kInternalClientFieldName,
    HelloCommand::kLoadBalancedFieldName,
    HelloCommand::kMaxAwaitTimeMSFieldName,
    HelloCommand::kSaslSupportedMechsFieldName,
    HelloCommand::kSpeculativeAuthenticateFieldName,
    HelloCommand::kTopologyVersionFieldName,
    HelloCommand::kCommandName,
};
const std::vector<StringData> HelloCommand::_knownOP_MSGFields {
    HelloCommand::kClientFieldName,
    HelloCommand::kCompressionFieldName,
    HelloCommand::kDbNameFieldName,
    HelloCommand::kForShellFieldName,
    HelloCommand::kHangUpOnStepDownFieldName,
    HelloCommand::kHelloOkFieldName,
    HelloCommand::kHostInfoFieldName,
    HelloCommand::kInternalClientFieldName,
    HelloCommand::kLoadBalancedFieldName,
    HelloCommand::kMaxAwaitTimeMSFieldName,
    HelloCommand::kSaslSupportedMechsFieldName,
    HelloCommand::kSpeculativeAuthenticateFieldName,
    HelloCommand::kTopologyVersionFieldName,
    HelloCommand::kCommandName,
};

HelloCommand::HelloCommand() : _hasDbName(false) {
    // Used for initialization only
}

void HelloCommand::validateMaxAwaitTimeMS(IDLParserErrorContext& ctxt, const std::int64_t value)
{
    if (!(value >= 0)) {
        throwComparisonError<std::int64_t>(ctxt, "maxAwaitTimeMS", ">="_sd, value, 0);
    }
}

void HelloCommand::validateMaxAwaitTimeMS(const std::int64_t value)
{
    if (!(value >= 0)) {
        throwComparisonError<std::int64_t>("maxAwaitTimeMS", ">="_sd, value, 0);
    }
}


HelloCommand HelloCommand::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<HelloCommand>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void HelloCommand::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<13> usedFields;
    const size_t kForShellBit = 0;
    const size_t kHostInfoBit = 1;
    const size_t kHangUpOnStepDownBit = 2;
    const size_t kInternalClientBit = 3;
    const size_t kClientBit = 4;
    const size_t kTopologyVersionBit = 5;
    const size_t kMaxAwaitTimeMSBit = 6;
    const size_t kHelloOkBit = 7;
    const size_t kCompressionBit = 8;
    const size_t kSaslSupportedMechsBit = 9;
    const size_t kSpeculativeAuthenticateBit = 10;
    const size_t kLoadBalancedBit = 11;
    const size_t kDbNameBit = 12;
    std::set<StringData> usedFieldSet;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kForShellFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kForShellBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kForShellBit);

                _forShell = element.trueValue();
            }
        }
        else if (fieldName == kHostInfoFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kHostInfoBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kHostInfoBit);

                _hostInfo = element.str();
            }
        }
        else if (fieldName == kHangUpOnStepDownFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kHangUpOnStepDownBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kHangUpOnStepDownBit);

                _hangUpOnStepDown = element.trueValue();
            }
        }
        else if (fieldName == kInternalClientFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kInternalClientBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kInternalClientBit);

                IDLParserErrorContext tempContext(kInternalClientFieldName, &ctxt);
                const auto localObject = element.Obj();
                _internalClient = mongo::HelloInternalClientField::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kClientFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kClientBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kClientBit);

                const BSONObj localObject = element.Obj();
                _client = ClientMetadata::parseFromBSON(localObject);
            }
        }
        else if (fieldName == kTopologyVersionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kTopologyVersionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTopologyVersionBit);

                IDLParserErrorContext tempContext(kTopologyVersionFieldName, &ctxt);
                const auto localObject = element.Obj();
                _topologyVersion = mongo::TopologyVersion::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kMaxAwaitTimeMSFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kMaxAwaitTimeMSBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMaxAwaitTimeMSBit);

                {
                    auto value = element.safeNumberLong();
                    validateMaxAwaitTimeMS(value);
                    _maxAwaitTimeMS = std::move(value);
                }
            }
        }
        else if (fieldName == kHelloOkFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kHelloOkBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kHelloOkBit);

                _helloOk = element.trueValue();
            }
        }
        else if (fieldName == kCompressionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kCompressionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCompressionBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kCompressionFieldName, &ctxt);
            std::vector<std::string> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, String)) {
                        values.emplace_back(arrayElement.str());
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _compression = std::move(values);
        }
        else if (fieldName == kSaslSupportedMechsFieldName) {
            if (MONGO_unlikely(usedFields[kSaslSupportedMechsBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kSaslSupportedMechsBit);


            const BSONType variantType = element.type();
            switch (variantType) {
            case String:
            {
                _saslSupportedMechs = element.str();
                break;
            }
            case Object:
            {
                const BSONObj localObject = element.Obj();
                _saslSupportedMechs = BSONObj::getOwned(localObject);
                break;
            }
            default:
                ctxt.throwBadType(element, {BSONType::String, BSONType::Object});
                break;
            }
        }
        else if (fieldName == kSpeculativeAuthenticateFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kSpeculativeAuthenticateBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSpeculativeAuthenticateBit);

                _speculativeAuthenticate = element.Obj();
            }
        }
        else if (fieldName == kLoadBalancedFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kLoadBalancedBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLoadBalancedBit);

                _loadBalanced = element.boolean();
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
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kForShellBit]) {
            _forShell = false;
        }
        if (!usedFields[kHostInfoBit]) {
            _hostInfo = false;
        }
        if (!usedFields[kHangUpOnStepDownBit]) {
            _hangUpOnStepDown = true;
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

}

HelloCommand HelloCommand::parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    auto object = mongo::idl::preparsedValue<HelloCommand>();
    object.parseProtected(ctxt, request);
    return object;
}
void HelloCommand::parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request) {
    std::bitset<13> usedFields;
    const size_t kForShellBit = 0;
    const size_t kHostInfoBit = 1;
    const size_t kHangUpOnStepDownBit = 2;
    const size_t kInternalClientBit = 3;
    const size_t kClientBit = 4;
    const size_t kTopologyVersionBit = 5;
    const size_t kMaxAwaitTimeMSBit = 6;
    const size_t kHelloOkBit = 7;
    const size_t kCompressionBit = 8;
    const size_t kSaslSupportedMechsBit = 9;
    const size_t kSpeculativeAuthenticateBit = 10;
    const size_t kLoadBalancedBit = 11;
    const size_t kDbNameBit = 12;
    std::set<StringData> usedFieldSet;
    BSONElement commandElement;
    bool firstFieldFound = false;

    for (const auto& element :request.body) {
        const auto fieldName = element.fieldNameStringData();

        if (firstFieldFound == false) {
            firstFieldFound = true;
            continue;
        }

        if (fieldName == kForShellFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kForShellBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kForShellBit);

                _forShell = element.trueValue();
            }
        }
        else if (fieldName == kHostInfoFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kHostInfoBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kHostInfoBit);

                _hostInfo = element.str();
            }
        }
        else if (fieldName == kHangUpOnStepDownFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kHangUpOnStepDownBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kHangUpOnStepDownBit);

                _hangUpOnStepDown = element.trueValue();
            }
        }
        else if (fieldName == kInternalClientFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kInternalClientBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kInternalClientBit);

                IDLParserErrorContext tempContext(kInternalClientFieldName, &ctxt);
                const auto localObject = element.Obj();
                _internalClient = mongo::HelloInternalClientField::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kClientFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kClientBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kClientBit);

                const BSONObj localObject = element.Obj();
                _client = ClientMetadata::parseFromBSON(localObject);
            }
        }
        else if (fieldName == kTopologyVersionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kTopologyVersionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTopologyVersionBit);

                IDLParserErrorContext tempContext(kTopologyVersionFieldName, &ctxt);
                const auto localObject = element.Obj();
                _topologyVersion = mongo::TopologyVersion::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kMaxAwaitTimeMSFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kMaxAwaitTimeMSBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMaxAwaitTimeMSBit);

                {
                    auto value = element.safeNumberLong();
                    validateMaxAwaitTimeMS(value);
                    _maxAwaitTimeMS = std::move(value);
                }
            }
        }
        else if (fieldName == kHelloOkFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {Bool, NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kHelloOkBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kHelloOkBit);

                _helloOk = element.trueValue();
            }
        }
        else if (fieldName == kCompressionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kCompressionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCompressionBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kCompressionFieldName, &ctxt);
            std::vector<std::string> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, String)) {
                        values.emplace_back(arrayElement.str());
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _compression = std::move(values);
        }
        else if (fieldName == kSaslSupportedMechsFieldName) {
            if (MONGO_unlikely(usedFields[kSaslSupportedMechsBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kSaslSupportedMechsBit);


            const BSONType variantType = element.type();
            switch (variantType) {
            case String:
            {
                _saslSupportedMechs = element.str();
                break;
            }
            case Object:
            {
                const BSONObj localObject = element.Obj();
                _saslSupportedMechs = BSONObj::getOwned(localObject);
                break;
            }
            default:
                ctxt.throwBadType(element, {BSONType::String, BSONType::Object});
                break;
            }
        }
        else if (fieldName == kSpeculativeAuthenticateFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kSpeculativeAuthenticateBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSpeculativeAuthenticateBit);

                _speculativeAuthenticate = element.Obj();
            }
        }
        else if (fieldName == kLoadBalancedFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kLoadBalancedBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLoadBalancedBit);

                _loadBalanced = element.boolean();
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
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kForShellBit]) {
            _forShell = false;
        }
        if (!usedFields[kHostInfoBit]) {
            _hostInfo = false;
        }
        if (!usedFields[kHangUpOnStepDownBit]) {
            _hangUpOnStepDown = true;
        }
        if (!usedFields[kDbNameBit]) {
            ctxt.throwMissingField(kDbNameFieldName);
        }
    }

}

void HelloCommand::serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const {
    invariant(_hasDbName);

    builder->append("hello"_sd, 1);
    builder->append(kForShellFieldName, _forShell);

    builder->append(kHostInfoFieldName, _hostInfo);

    builder->append(kHangUpOnStepDownFieldName, _hangUpOnStepDown);

    if (_internalClient.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kInternalClientFieldName));
        _internalClient.get().serialize(&subObjBuilder);
    }

    if (_client.is_initialized()) {
        const BSONObj localObject = _client.get().getDocument();
        builder->append(kClientFieldName, localObject);
    }

    if (_topologyVersion.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kTopologyVersionFieldName));
        _topologyVersion.get().serialize(&subObjBuilder);
    }

    if (_maxAwaitTimeMS.is_initialized()) {
        builder->append(kMaxAwaitTimeMSFieldName, _maxAwaitTimeMS.get());
    }

    if (_helloOk.is_initialized()) {
        builder->append(kHelloOkFieldName, _helloOk.get());
    }

    if (_compression.is_initialized()) {
        builder->append(kCompressionFieldName, _compression.get());
    }

    if (_saslSupportedMechs.is_initialized()) {
        stdx::visit([builder](auto&& arg) {
            idl::idlSerialize(builder, kSaslSupportedMechsFieldName, arg);
        }, _saslSupportedMechs.get());
    }

    if (_speculativeAuthenticate.is_initialized()) {
        builder->append(kSpeculativeAuthenticateFieldName, _speculativeAuthenticate.get());
    }

    if (_loadBalanced.is_initialized()) {
        builder->append(kLoadBalancedFieldName, _loadBalanced.get());
    }

    IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownBSONFields, builder);

}

OpMsgRequest HelloCommand::serialize(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder localBuilder;
    {
        BSONObjBuilder* builder = &localBuilder;
        invariant(_hasDbName);

        builder->append("hello"_sd, 1);
        builder->append(kForShellFieldName, _forShell);

        builder->append(kHostInfoFieldName, _hostInfo);

        builder->append(kHangUpOnStepDownFieldName, _hangUpOnStepDown);

        if (_internalClient.is_initialized()) {
            BSONObjBuilder subObjBuilder(builder->subobjStart(kInternalClientFieldName));
            _internalClient.get().serialize(&subObjBuilder);
        }

        if (_client.is_initialized()) {
            const BSONObj localObject = _client.get().getDocument();
            builder->append(kClientFieldName, localObject);
        }

        if (_topologyVersion.is_initialized()) {
            BSONObjBuilder subObjBuilder(builder->subobjStart(kTopologyVersionFieldName));
            _topologyVersion.get().serialize(&subObjBuilder);
        }

        if (_maxAwaitTimeMS.is_initialized()) {
            builder->append(kMaxAwaitTimeMSFieldName, _maxAwaitTimeMS.get());
        }

        if (_helloOk.is_initialized()) {
            builder->append(kHelloOkFieldName, _helloOk.get());
        }

        if (_compression.is_initialized()) {
            builder->append(kCompressionFieldName, _compression.get());
        }

        if (_saslSupportedMechs.is_initialized()) {
            stdx::visit([builder](auto&& arg) {
                idl::idlSerialize(builder, kSaslSupportedMechsFieldName, arg);
            }, _saslSupportedMechs.get());
        }

        if (_speculativeAuthenticate.is_initialized()) {
            builder->append(kSpeculativeAuthenticateFieldName, _speculativeAuthenticate.get());
        }

        if (_loadBalanced.is_initialized()) {
            builder->append(kLoadBalancedFieldName, _loadBalanced.get());
        }

        builder->append(kDbNameFieldName, _dbName);

        IDLParserErrorContext::appendGenericCommandArguments(commandPassthroughFields, _knownOP_MSGFields, builder);

    }
    OpMsgRequest request;
    request.body = localBuilder.obj();
    return request;
}

BSONObj HelloCommand::toBSON(const BSONObj& commandPassthroughFields) const {
    BSONObjBuilder builder;
    serialize(commandPassthroughFields, &builder);
    return builder.obj();
}

}  // namespace mongo
