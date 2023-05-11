/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/process_health/health_monitoring_server_parameters_gen.h --output build/opt/mongo/db/process_health/health_monitoring_server_parameters_gen.cpp src/mongo/db/process_health/health_monitoring_server_parameters.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/process_health/health_monitoring_server_parameters_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"
#include "mongo/idl/server_parameter.h"
#include "mongo/idl/server_parameter_with_storage.h"

namespace mongo {

/**
 * Enum representing the intensity of a health observer.
 */
namespace  {
constexpr StringData kHealthObserverIntensity_kOff = "off"_sd;
constexpr StringData kHealthObserverIntensity_kCritical = "critical"_sd;
constexpr StringData kHealthObserverIntensity_kNonCritical = "non-critical"_sd;
}  // namespace 

HealthObserverIntensityEnum HealthObserverIntensity_parse(const IDLParserErrorContext& ctxt, StringData value) {
    if (value == kHealthObserverIntensity_kOff) {
        return HealthObserverIntensityEnum::kOff;
    }
    if (value == kHealthObserverIntensity_kCritical) {
        return HealthObserverIntensityEnum::kCritical;
    }
    if (value == kHealthObserverIntensity_kNonCritical) {
        return HealthObserverIntensityEnum::kNonCritical;
    }
    ctxt.throwBadEnumValue(value);
}

StringData HealthObserverIntensity_serializer(HealthObserverIntensityEnum value) {
    if (value == HealthObserverIntensityEnum::kOff) {
        return kHealthObserverIntensity_kOff;
    }
    if (value == HealthObserverIntensityEnum::kCritical) {
        return kHealthObserverIntensity_kCritical;
    }
    if (value == HealthObserverIntensityEnum::kNonCritical) {
        return kHealthObserverIntensity_kNonCritical;
    }
    MONGO_UNREACHABLE;
    return StringData();
}

/**
 * Enum representing available health observer types
 */
namespace  {
constexpr StringData kHealthObserverType_kLdap = "ldap"_sd;
constexpr StringData kHealthObserverType_kDns = "dns"_sd;
constexpr StringData kHealthObserverType_kTest = "test"_sd;
constexpr StringData kHealthObserverType_kConfigServer = "configServer"_sd;
}  // namespace 

HealthObserverTypeEnum HealthObserverType_parse(const IDLParserErrorContext& ctxt, StringData value) {
    if (value == kHealthObserverType_kLdap) {
        return HealthObserverTypeEnum::kLdap;
    }
    if (value == kHealthObserverType_kDns) {
        return HealthObserverTypeEnum::kDns;
    }
    if (value == kHealthObserverType_kTest) {
        return HealthObserverTypeEnum::kTest;
    }
    if (value == kHealthObserverType_kConfigServer) {
        return HealthObserverTypeEnum::kConfigServer;
    }
    ctxt.throwBadEnumValue(value);
}

StringData HealthObserverType_serializer(HealthObserverTypeEnum value) {
    if (value == HealthObserverTypeEnum::kLdap) {
        return kHealthObserverType_kLdap;
    }
    if (value == HealthObserverTypeEnum::kDns) {
        return kHealthObserverType_kDns;
    }
    if (value == HealthObserverTypeEnum::kTest) {
        return kHealthObserverType_kTest;
    }
    if (value == HealthObserverTypeEnum::kConfigServer) {
        return kHealthObserverType_kConfigServer;
    }
    MONGO_UNREACHABLE;
    return StringData();
}

constexpr StringData HealthObserverIntensitySetting::kIntensityFieldName;
constexpr StringData HealthObserverIntensitySetting::kTypeFieldName;


HealthObserverIntensitySetting::HealthObserverIntensitySetting() : _type(mongo::idl::preparsedValue<decltype(_type)>()), _hasType(false) {
    // Used for initialization only
}
HealthObserverIntensitySetting::HealthObserverIntensitySetting(mongo::HealthObserverTypeEnum type) : _type(std::move(type)), _hasType(true) {
    // Used for initialization only
}


HealthObserverIntensitySetting HealthObserverIntensitySetting::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<HealthObserverIntensitySetting>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void HealthObserverIntensitySetting::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kTypeBit = 0;
    const size_t kIntensityBit = 1;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kTypeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kTypeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTypeBit);

                _hasType = true;
                IDLParserErrorContext tempContext(kTypeFieldName, &ctxt);
                _type = HealthObserverType_parse(tempContext, element.valueStringData());
            }
        }
        else if (fieldName == kIntensityFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kIntensityBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIntensityBit);

                IDLParserErrorContext tempContext(kIntensityFieldName, &ctxt);
                _intensity = HealthObserverIntensity_parse(tempContext, element.valueStringData());
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kTypeBit]) {
            ctxt.throwMissingField(kTypeFieldName);
        }
        if (!usedFields[kIntensityBit]) {
            _intensity = mongo::HealthObserverIntensityEnum::kOff;
        }
    }

}


void HealthObserverIntensitySetting::serialize(BSONObjBuilder* builder) const {
    invariant(_hasType);

    {
        builder->append(kTypeFieldName, ::mongo::HealthObserverType_serializer(_type));
    }

    {
        builder->append(kIntensityFieldName, ::mongo::HealthObserverIntensity_serializer(_intensity));
    }

}


BSONObj HealthObserverIntensitySetting::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData HealthObserverIntensities::kValuesFieldName;


HealthObserverIntensities::HealthObserverIntensities()  {
    // Used for initialization only
}


HealthObserverIntensities HealthObserverIntensities::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<HealthObserverIntensities>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void HealthObserverIntensities::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kValuesBit = 0;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kValuesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kValuesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kValuesBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kValuesFieldName, &ctxt);
            std::vector<mongo::HealthObserverIntensitySetting> values;

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
                        IDLParserErrorContext tempContext(kValuesFieldName, &ctxt);
                        const auto localObject = arrayElement.Obj();
                        values.emplace_back(mongo::HealthObserverIntensitySetting::parse(tempContext, localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _values = std::move(values);
        }
        else {
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
    }

}


void HealthObserverIntensities::serialize(BSONObjBuilder* builder) const {
    if (_values.is_initialized()) {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kValuesFieldName));
        for (const auto& item : _values.get()) {
            BSONObjBuilder subObjBuilder(arrayBuilder.subobjStart());
            item.serialize(&subObjBuilder);
        }
    }

}


BSONObj HealthObserverIntensities::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData HealthObserverIntervalSetting::kIntervalFieldName;
constexpr StringData HealthObserverIntervalSetting::kTypeFieldName;


HealthObserverIntervalSetting::HealthObserverIntervalSetting() : _type(mongo::idl::preparsedValue<decltype(_type)>()), _interval(mongo::idl::preparsedValue<decltype(_interval)>()), _hasType(false), _hasInterval(false) {
    // Used for initialization only
}
HealthObserverIntervalSetting::HealthObserverIntervalSetting(mongo::HealthObserverTypeEnum type, std::int32_t interval) : _type(std::move(type)), _interval(std::move(interval)), _hasType(true), _hasInterval(true) {
    // Used for initialization only
}

void HealthObserverIntervalSetting::validateInterval(IDLParserErrorContext& ctxt, const std::int32_t value)
{
    if (!(value > 0)) {
        throwComparisonError<std::int32_t>(ctxt, "interval", ">"_sd, value, 0);
    }
}

void HealthObserverIntervalSetting::validateInterval(const std::int32_t value)
{
    if (!(value > 0)) {
        throwComparisonError<std::int32_t>("interval", ">"_sd, value, 0);
    }
}


HealthObserverIntervalSetting HealthObserverIntervalSetting::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<HealthObserverIntervalSetting>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void HealthObserverIntervalSetting::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kTypeBit = 0;
    const size_t kIntervalBit = 1;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kTypeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kTypeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTypeBit);

                _hasType = true;
                IDLParserErrorContext tempContext(kTypeFieldName, &ctxt);
                _type = HealthObserverType_parse(tempContext, element.valueStringData());
            }
        }
        else if (fieldName == kIntervalFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberInt))) {
                if (MONGO_unlikely(usedFields[kIntervalBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIntervalBit);

                _hasInterval = true;
                {
                    auto value = element._numberInt();
                    validateInterval(value);
                    _interval = std::move(value);
                }
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kTypeBit]) {
            ctxt.throwMissingField(kTypeFieldName);
        }
        if (!usedFields[kIntervalBit]) {
            ctxt.throwMissingField(kIntervalFieldName);
        }
    }

}


void HealthObserverIntervalSetting::serialize(BSONObjBuilder* builder) const {
    invariant(_hasType && _hasInterval);

    {
        builder->append(kTypeFieldName, ::mongo::HealthObserverType_serializer(_type));
    }

    builder->append(kIntervalFieldName, _interval);

}


BSONObj HealthObserverIntervalSetting::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData HealthObserverIntervals::kValuesFieldName;


HealthObserverIntervals::HealthObserverIntervals()  {
    // Used for initialization only
}


HealthObserverIntervals HealthObserverIntervals::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<HealthObserverIntervals>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void HealthObserverIntervals::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kValuesBit = 0;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kValuesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kValuesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kValuesBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kValuesFieldName, &ctxt);
            std::vector<mongo::HealthObserverIntervalSetting> values;

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
                        IDLParserErrorContext tempContext(kValuesFieldName, &ctxt);
                        const auto localObject = arrayElement.Obj();
                        values.emplace_back(mongo::HealthObserverIntervalSetting::parse(tempContext, localObject));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _values = std::move(values);
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
    }

}


void HealthObserverIntervals::serialize(BSONObjBuilder* builder) const {
    if (_values.is_initialized()) {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kValuesFieldName));
        for (const auto& item : _values.get()) {
            BSONObjBuilder subObjBuilder(arrayBuilder.subobjStart());
            item.serialize(&subObjBuilder);
        }
    }

}


BSONObj HealthObserverIntervals::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData HealthObserverProgressMonitorConfig::kDeadlineFieldName;
constexpr StringData HealthObserverProgressMonitorConfig::kIntervalFieldName;


HealthObserverProgressMonitorConfig::HealthObserverProgressMonitorConfig()  {
    // Used for initialization only
}

void HealthObserverProgressMonitorConfig::validateInterval(IDLParserErrorContext& ctxt, const std::int32_t value)
{
    if (!(value > 0)) {
        throwComparisonError<std::int32_t>(ctxt, "interval", ">"_sd, value, 0);
    }
}

void HealthObserverProgressMonitorConfig::validateInterval(const std::int32_t value)
{
    if (!(value > 0)) {
        throwComparisonError<std::int32_t>("interval", ">"_sd, value, 0);
    }
}

void HealthObserverProgressMonitorConfig::validateDeadline(IDLParserErrorContext& ctxt, const std::int32_t value)
{
    if (!(value > 0)) {
        throwComparisonError<std::int32_t>(ctxt, "deadline", ">"_sd, value, 0);
    }
}

void HealthObserverProgressMonitorConfig::validateDeadline(const std::int32_t value)
{
    if (!(value > 0)) {
        throwComparisonError<std::int32_t>("deadline", ">"_sd, value, 0);
    }
}


HealthObserverProgressMonitorConfig HealthObserverProgressMonitorConfig::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<HealthObserverProgressMonitorConfig>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void HealthObserverProgressMonitorConfig::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kIntervalBit = 0;
    const size_t kDeadlineBit = 1;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kIntervalFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberInt))) {
                if (MONGO_unlikely(usedFields[kIntervalBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIntervalBit);

                {
                    auto value = element._numberInt();
                    validateInterval(value);
                    _interval = std::move(value);
                }
            }
        }
        else if (fieldName == kDeadlineFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberInt))) {
                if (MONGO_unlikely(usedFields[kDeadlineBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDeadlineBit);

                {
                    auto value = element._numberInt();
                    validateDeadline(value);
                    _deadline = std::move(value);
                }
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kIntervalBit]) {
            _interval = 1000;
        }
        if (!usedFields[kDeadlineBit]) {
            _deadline = 300;
        }
    }

}


void HealthObserverProgressMonitorConfig::serialize(BSONObjBuilder* builder) const {
    builder->append(kIntervalFieldName, _interval);

    builder->append(kDeadlineFieldName, _deadline);

}


BSONObj HealthObserverProgressMonitorConfig::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

AtomicWord<int> gActiveFaultDurationSecs{120};
AtomicWord<int> gReachableConfigReplicasRequired{1};
AtomicWord<int> gConfigReplicasProbed{2};
MONGO_SERVER_PARAMETER_REGISTER(idl_d351586caa26e1a19b35da4cea828fda36734495)(InitializerContext*) {
    /**
     * A server parameter for specifying the intensity of fault facets.
     */
    [[maybe_unused]] auto* scp_0 = ([]() -> ServerParameter* {
        return new HealthMonitoringIntensitiesServerParameter("healthMonitoringIntensities", ServerParameterType::kStartupAndRuntime);
    })();

    /**
     * A server parameter for specifying intervals for health monitoring.
     */
    [[maybe_unused]] auto* scp_1 = ([]() -> ServerParameter* {
        return new HealthMonitoringProgressMonitorServerParameter("progressMonitor", ServerParameterType::kStartupAndRuntime);
    })();

    /**
     * A server parameter for specifying the interval in milliseconds between health checks.
     */
    [[maybe_unused]] auto* scp_2 = ([]() -> ServerParameter* {
        return new PeriodicHealthCheckIntervalsServerParameter("healthMonitoringIntervals", ServerParameterType::kStartupAndRuntime);
    })();

    /**
     * A server parameter for specifying the duration after which we transition to active fault.
     */
    [[maybe_unused]] auto* scp_3 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("activeFaultDurationSecs", gActiveFaultDurationSecs);
        ret->addBound<idl_server_parameter_detail::GTE>(0);
        return ret;
    })();

    /**
     * Minimal count of reachable Config server replicas required to pass the health check
     */
    [[maybe_unused]] auto* scp_4 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("reachableConfigReplicasRequiredByHealthMonitoring", gReachableConfigReplicasRequired);
        ret->addBound<idl_server_parameter_detail::GT>(0);
        return ret;
    })();

    /**
     * Count of Config server replicas probed by the health check
     */
    [[maybe_unused]] auto* scp_5 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("configReplicasProbedByHealthMonitoring", gConfigReplicasProbed);
        ret->addBound<idl_server_parameter_detail::GT>(0);
        return ret;
    })();

}
}  // namespace mongo
