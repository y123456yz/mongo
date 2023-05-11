/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/process_health/health_monitoring_server_parameters_gen.h --output build/opt/mongo/db/process_health/health_monitoring_server_parameters_gen.cpp src/mongo/db/process_health/health_monitoring_server_parameters.idl
 */

#pragma once

#include <algorithm>
#include <boost/optional.hpp>
#include <cstdint>
#include <string>
#include <tuple>
#include <vector>

#include "mongo/base/data_range.h"
#include "mongo/base/string_data.h"
#include "mongo/bson/bsonobj.h"
#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/bson/simple_bsonobj_comparator.h"
#include "mongo/db/namespace_string.h"
#include "mongo/idl/basic_types.h"
#include "mongo/idl/basic_types_gen.h"
#include "mongo/idl/idl_parser.h"
#include "mongo/idl/server_parameter.h"
#include "mongo/idl/server_parameter_with_storage.h"
#include "mongo/rpc/op_msg.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/util/uuid.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {

/**
 * Enum representing the intensity of a health observer.
 */
enum class HealthObserverIntensityEnum : std::int32_t {
    kOff ,
    kCritical ,
    kNonCritical ,
};
static constexpr uint32_t kNumHealthObserverIntensityEnum = 3;

HealthObserverIntensityEnum HealthObserverIntensity_parse(const IDLParserErrorContext& ctxt, StringData value);
StringData HealthObserverIntensity_serializer(HealthObserverIntensityEnum value);

/**
 * Enum representing available health observer types
 */
enum class HealthObserverTypeEnum : std::int32_t {
    kLdap ,
    kDns ,
    kTest ,
    kConfigServer ,
};
static constexpr uint32_t kNumHealthObserverTypeEnum = 4;

HealthObserverTypeEnum HealthObserverType_parse(const IDLParserErrorContext& ctxt, StringData value);
StringData HealthObserverType_serializer(HealthObserverTypeEnum value);

/**
 * One health observer intensity setting
 */
class HealthObserverIntensitySetting {
public:
    static constexpr auto kIntensityFieldName = "intensity"_sd;
    static constexpr auto kTypeFieldName = "type"_sd;

    HealthObserverIntensitySetting();
    HealthObserverIntensitySetting(mongo::HealthObserverTypeEnum type);

    static HealthObserverIntensitySetting parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    mongo::HealthObserverTypeEnum getType() const { return _type; }
    void setType(mongo::HealthObserverTypeEnum value) & {  _type = std::move(value); _hasType = true; }

    mongo::HealthObserverIntensityEnum getIntensity() const { return _intensity; }
    void setIntensity(mongo::HealthObserverIntensityEnum value) & {  _intensity = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::HealthObserverTypeEnum _type;
    mongo::HealthObserverIntensityEnum _intensity{mongo::HealthObserverIntensityEnum::kOff};
    bool _hasType : 1;
};

/**
 * A struct representing the health observer intensities.
 */
class HealthObserverIntensities {
public:
    static constexpr auto kValuesFieldName = "values"_sd;

    HealthObserverIntensities();

    static HealthObserverIntensities parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Array of health observer intensity settings
     */
    const boost::optional<std::vector<mongo::HealthObserverIntensitySetting>>& getValues() const& { return _values; }
    void getValues() && = delete;
    void setValues(boost::optional<std::vector<mongo::HealthObserverIntensitySetting>> value) & {  _values = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    boost::optional<std::vector<mongo::HealthObserverIntensitySetting>> _values;
};

/**
 * One health observer check interval setting, in milliseconds
 */
class HealthObserverIntervalSetting {
public:
    static constexpr auto kIntervalFieldName = "interval"_sd;
    static constexpr auto kTypeFieldName = "type"_sd;

    HealthObserverIntervalSetting();
    HealthObserverIntervalSetting(mongo::HealthObserverTypeEnum type, std::int32_t interval);

    static HealthObserverIntervalSetting parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    mongo::HealthObserverTypeEnum getType() const { return _type; }
    void setType(mongo::HealthObserverTypeEnum value) & {  _type = std::move(value); _hasType = true; }

    std::int32_t getInterval() const { return _interval; }
    void setInterval(std::int32_t value) & { validateInterval(value); _interval = std::move(value); _hasInterval = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    void validateInterval(const std::int32_t value);
    void validateInterval(IDLParserErrorContext& ctxt, const std::int32_t value);

private:
    mongo::HealthObserverTypeEnum _type;
    std::int32_t _interval;
    bool _hasType : 1;
    bool _hasInterval : 1;
};

/**
 * A struct representing the interval in milliseconds for each health observer.
 */
class HealthObserverIntervals {
public:
    static constexpr auto kValuesFieldName = "values"_sd;

    HealthObserverIntervals();

    static HealthObserverIntervals parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Array of health observer intervals settings
     */
    const boost::optional<std::vector<mongo::HealthObserverIntervalSetting>>& getValues() const& { return _values; }
    void getValues() && = delete;
    void setValues(boost::optional<std::vector<mongo::HealthObserverIntervalSetting>> value) & {  _values = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    boost::optional<std::vector<mongo::HealthObserverIntervalSetting>> _values;
};

/**
 * A struct representing configuration for health observer liveness checks.
 */
class HealthObserverProgressMonitorConfig {
public:
    static constexpr auto kDeadlineFieldName = "deadline"_sd;
    static constexpr auto kIntervalFieldName = "interval"_sd;

    HealthObserverProgressMonitorConfig();

    static HealthObserverProgressMonitorConfig parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Interval between liveness checks in milliseconds.
     */
    std::int32_t getInterval() const { return _interval; }
    void setInterval(std::int32_t value) & { validateInterval(value); _interval = std::move(value);  }

    /**
     * Deadline for liveness checks, after which process should exit, in seconds.
     */
    std::int32_t getDeadline() const { return _deadline; }
    void setDeadline(std::int32_t value) & { validateDeadline(value); _deadline = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    void validateInterval(const std::int32_t value);
    void validateInterval(IDLParserErrorContext& ctxt, const std::int32_t value);

    void validateDeadline(const std::int32_t value);
    void validateDeadline(IDLParserErrorContext& ctxt, const std::int32_t value);

private:
    std::int32_t _interval{1000};
    std::int32_t _deadline{300};
};

class HealthMonitoringIntensitiesServerParameter : public ServerParameter {
public:
    using ServerParameter::ServerParameter;

    void append(OperationContext*, BSONObjBuilder&, const std::string&) final;
    Status set(const BSONElement&) final;
    Status setFromString(const std::string&) final;

    synchronized_value<HealthObserverIntensities> _data;
};

class HealthMonitoringProgressMonitorServerParameter : public ServerParameter {
public:
    using ServerParameter::ServerParameter;

    void append(OperationContext*, BSONObjBuilder&, const std::string&) final;
    Status set(const BSONElement&) final;
    Status setFromString(const std::string&) final;

    synchronized_value<HealthObserverProgressMonitorConfig> _data;
};

class PeriodicHealthCheckIntervalsServerParameter : public ServerParameter {
public:
    using ServerParameter::ServerParameter;

    void append(OperationContext*, BSONObjBuilder&, const std::string&) final;
    Status set(const BSONElement&) final;
    Status setFromString(const std::string&) final;

    synchronized_value<HealthObserverIntervals> _data;
};

constexpr auto kActiveFaultDurationSecsDefault = 120;

extern AtomicWord<int> gActiveFaultDurationSecs;
constexpr auto kReachableConfigReplicasRequiredByHealthMonitoringDefault = 1;

extern AtomicWord<int> gReachableConfigReplicasRequired;
constexpr auto kConfigReplicasProbedByHealthMonitoringDefault = 2;

extern AtomicWord<int> gConfigReplicasProbed;
}  // namespace mongo
