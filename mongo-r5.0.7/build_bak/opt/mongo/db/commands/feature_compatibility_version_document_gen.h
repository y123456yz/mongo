/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/commands/feature_compatibility_version_document_gen.h --output build/opt/mongo/db/commands/feature_compatibility_version_document_gen.cpp src/mongo/db/commands/feature_compatibility_version_document.idl
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
#include "mongo/db/commands/feature_compatibility_version_parser.h"
#include "mongo/db/namespace_string.h"
#include "mongo/idl/basic_types.h"
#include "mongo/idl/basic_types_gen.h"
#include "mongo/idl/idl_parser.h"
#include "mongo/rpc/op_msg.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/util/uuid.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {

/**
 * featureCompatibilityVersion on-disk document format
 */
class FeatureCompatibilityVersionDocument {
public:
    static constexpr auto k_idFieldName = "_id"_sd;
    static constexpr auto kChangeTimestampFieldName = "changeTimestamp"_sd;
    static constexpr auto kPreviousVersionFieldName = "previousVersion"_sd;
    static constexpr auto kTargetVersionFieldName = "targetVersion"_sd;
    static constexpr auto kVersionFieldName = "version"_sd;

    FeatureCompatibilityVersionDocument();
    FeatureCompatibilityVersionDocument(ServerGlobalParams::FeatureCompatibility::Version version);

    static FeatureCompatibilityVersionDocument parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Key of the featureCompatibilityVersion state singleton document
     */
    const StringData get_id() const& { return __id; }
    void get_id() && = delete;
    void set_id(StringData value) & { auto _tmpValue = value.toString();  __id = std::move(_tmpValue);  }

    /**
     * Effective featureCompatibilityVersion
     */
    ServerGlobalParams::FeatureCompatibility::Version getVersion() const { return _version; }
    void setVersion(ServerGlobalParams::FeatureCompatibility::Version value) & {  _version = std::move(value); _hasVersion = true; }

    /**
     * Target featureCompatibilityVersion for upgrade/downgrade
     */
    const boost::optional<ServerGlobalParams::FeatureCompatibility::Version> getTargetVersion() const& { return _targetVersion; }
    void getTargetVersion() && = delete;
    void setTargetVersion(boost::optional<ServerGlobalParams::FeatureCompatibility::Version> value) & {  _targetVersion = std::move(value);  }

    /**
     * Previous featureCompatibilityVersion for downgrading states, will always be kLatest when present
     */
    const boost::optional<ServerGlobalParams::FeatureCompatibility::Version> getPreviousVersion() const& { return _previousVersion; }
    void getPreviousVersion() && = delete;
    void setPreviousVersion(boost::optional<ServerGlobalParams::FeatureCompatibility::Version> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get();
        validatePreviousVersion(_tmpValue);
        _previousVersion = std::move(_tmpValue);
    } else {
        _previousVersion = boost::none;
    }
      }

    /**
     * Timestamp used to identify the 2-phase setFCV request. Both phases (kStart and kComplete) must have the same timestamp for the entire sequence, and every new sequence started must strictly have incrementing timestamp.
     */
    const boost::optional<mongo::Timestamp>& getChangeTimestamp() const& { return _changeTimestamp; }
    void getChangeTimestamp() && = delete;
    void setChangeTimestamp(boost::optional<mongo::Timestamp> value) & {  _changeTimestamp = std::move(value);  }


    friend bool operator==(const FeatureCompatibilityVersionDocument& left, const FeatureCompatibilityVersionDocument& right) {
        return left.__id == right.__id && left._version == right._version && left._targetVersion == right._targetVersion && left._previousVersion == right._previousVersion && left._changeTimestamp == right._changeTimestamp;
    }

    friend bool operator!=(const FeatureCompatibilityVersionDocument& left, const FeatureCompatibilityVersionDocument& right) {
        return left.__id != right.__id || left._version != right._version || left._targetVersion != right._targetVersion || left._previousVersion != right._previousVersion || left._changeTimestamp != right._changeTimestamp;
    }
    friend bool operator<(const FeatureCompatibilityVersionDocument& left, const FeatureCompatibilityVersionDocument& right) {
        return left.__id < right.__id || (!(right.__id < left.__id) && (left._version < right._version || (!(right._version < left._version) && (left._targetVersion < right._targetVersion || (!(right._targetVersion < left._targetVersion) && (left._previousVersion < right._previousVersion || (!(right._previousVersion < left._previousVersion) && (left._changeTimestamp < right._changeTimestamp))))))));
    }
    friend bool operator>(const FeatureCompatibilityVersionDocument& left, const FeatureCompatibilityVersionDocument& right) {
        return right < left;
    }
    friend bool operator<=(const FeatureCompatibilityVersionDocument& left, const FeatureCompatibilityVersionDocument& right) {
        return !(right < left);
    }
    friend bool operator>=(const FeatureCompatibilityVersionDocument& left, const FeatureCompatibilityVersionDocument& right) {
        return !(left < right);
    }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    void validatePreviousVersion(const ServerGlobalParams::FeatureCompatibility::Version value);
    void validatePreviousVersion(IDLParserErrorContext& ctxt, const ServerGlobalParams::FeatureCompatibility::Version value);

private:
    std::string __id{"featureCompatibilityVersion"};
    ServerGlobalParams::FeatureCompatibility::Version _version;
    boost::optional<ServerGlobalParams::FeatureCompatibility::Version> _targetVersion;
    boost::optional<ServerGlobalParams::FeatureCompatibility::Version> _previousVersion;
    boost::optional<mongo::Timestamp> _changeTimestamp;
    bool _hasVersion : 1;
};

}  // namespace mongo
