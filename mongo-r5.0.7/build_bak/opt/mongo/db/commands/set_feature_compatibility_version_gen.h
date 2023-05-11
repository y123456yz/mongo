/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/commands/set_feature_compatibility_version_gen.h --output build/opt/mongo/db/commands/set_feature_compatibility_version_gen.cpp src/mongo/db/commands/set_feature_compatibility_version.idl
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
 * Enum that defines the phases of the 2-phase setFCV protocol.
 */
enum class SetFCVPhaseEnum : std::int32_t {
    kStart ,
    kComplete ,
};
static constexpr uint32_t kNumSetFCVPhaseEnum = 2;

SetFCVPhaseEnum SetFCVPhase_parse(const IDLParserErrorContext& ctxt, StringData value);
StringData SetFCVPhase_serializer(SetFCVPhaseEnum value);

/**
 * Parser for the 'setFeatureCompatibilityVersion' command.
 */
class SetFeatureCompatibilityVersion {
public:
    using Reply = void;
    static constexpr auto kCommandParameterFieldName = "setFeatureCompatibilityVersion"_sd;
    static constexpr auto kChangeTimestampFieldName = "changeTimestamp"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kDowngradeOnDiskChangesFieldName = "downgradeOnDiskChanges"_sd;
    static constexpr auto kFromConfigServerFieldName = "fromConfigServer"_sd;
    static constexpr auto kPhaseFieldName = "phase"_sd;
    static constexpr auto kCommandName = "setFeatureCompatibilityVersion"_sd;

    explicit SetFeatureCompatibilityVersion(const ServerGlobalParams::FeatureCompatibility::Version commandParameter);

    static SetFeatureCompatibilityVersion parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static SetFeatureCompatibilityVersion parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    ServerGlobalParams::FeatureCompatibility::Version getCommandParameter() const { return _commandParameter; }

    /**
     * A boolean that indicates whether we should rollback all possible on-disk changes associated with the upgraded featureCompatibilityVersion. This should only be called with a downgraded featureCompatibilityVersion.
     */
    const boost::optional<bool> getDowngradeOnDiskChanges() const& { return _downgradeOnDiskChanges; }
    void getDowngradeOnDiskChanges() && = delete;
    void setDowngradeOnDiskChanges(boost::optional<bool> value) & {  _downgradeOnDiskChanges = std::move(value);  }

    /**
     * A boolean that indicates whether the command is being requested by a config server. Normally FCV upgrades between last-lts and anything less than latest are not allowed, but in a sharded cluster, newly started shard nodes start in lastLTS and this parameter is required in order to be able to add such a shard to a cluster, which is currently running at last-continuous.
     */
    const boost::optional<bool> getFromConfigServer() const& { return _fromConfigServer; }
    void getFromConfigServer() && = delete;
    void setFromConfigServer(boost::optional<bool> value) & {  _fromConfigServer = std::move(value);  }

    /**
     * An enum that indicates whether the the command is requesting the shard to enter phase-1 (kStart) or phase-2 (kComplete) of the 2-phase setFCV protocol. Only valid to be specified for shards. If not specified on a shard, it will run the full setFCV sequence (both phases).
     */
    const boost::optional<mongo::SetFCVPhaseEnum> getPhase() const& { return _phase; }
    void getPhase() && = delete;
    void setPhase(boost::optional<mongo::SetFCVPhaseEnum> value) & {  _phase = std::move(value);  }

    /**
     * Timestamp used to identify the 2-phase setFCV request. Both phases (kStart and kComplete) must have the same timestamp for the entire sequence, and every new sequence started must strictly have incrementing timestamp.
     */
    const boost::optional<mongo::Timestamp>& getChangeTimestamp() const& { return _changeTimestamp; }
    void getChangeTimestamp() && = delete;
    void setChangeTimestamp(boost::optional<mongo::Timestamp> value) & {  _changeTimestamp = std::move(value);  }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;


    ServerGlobalParams::FeatureCompatibility::Version _commandParameter;

    boost::optional<bool> _downgradeOnDiskChanges;
    boost::optional<bool> _fromConfigServer;
    boost::optional<mongo::SetFCVPhaseEnum> _phase;
    boost::optional<mongo::Timestamp> _changeTimestamp;
    std::string _dbName;
    bool _hasDbName : 1;
};

}  // namespace mongo
