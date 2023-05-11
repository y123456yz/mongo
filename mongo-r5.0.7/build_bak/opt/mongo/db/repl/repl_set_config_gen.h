/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/repl/repl_set_config_gen.h --output build/opt/mongo/db/repl/repl_set_config_gen.cpp src/mongo/db/repl/repl_set_config.idl
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
#include "mongo/db/repl/member_config.h"
#include "mongo/db/repl/member_config_gen.h"
#include "mongo/db/repl/member_id.h"
#include "mongo/db/repl/optime.h"
#include "mongo/db/repl/repl_set_config_validators.h"
#include "mongo/db/repl/repl_set_tag.h"
#include "mongo/db/repl/repl_set_write_concern_mode_definitions.h"
#include "mongo/db/write_concern_options.h"
#include "mongo/idl/basic_types.h"
#include "mongo/idl/basic_types_gen.h"
#include "mongo/idl/idl_parser.h"
#include "mongo/rpc/op_msg.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/util/net/hostandport.h"
#include "mongo/util/string_map.h"
#include "mongo/util/uuid.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {
namespace repl {

/**
 * The configuration options that apply to the whole replica set
 */
class ReplSetConfigSettings {
public:
    static constexpr auto kCatchUpTakeoverDelayMillisFieldName = "catchUpTakeoverDelayMillis"_sd;
    static constexpr auto kCatchUpTimeoutMillisFieldName = "catchUpTimeoutMillis"_sd;
    static constexpr auto kChainingAllowedFieldName = "chainingAllowed"_sd;
    static constexpr auto kDefaultWriteConcernFieldName = "getLastErrorDefaults"_sd;
    static constexpr auto kElectionTimeoutMillisFieldName = "electionTimeoutMillis"_sd;
    static constexpr auto kGetLastErrorModesFieldName = "getLastErrorModes"_sd;
    static constexpr auto kHeartbeatIntervalMillisFieldName = "heartbeatIntervalMillis"_sd;
    static constexpr auto kHeartbeatTimeoutSecsFieldName = "heartbeatTimeoutSecs"_sd;
    static constexpr auto kReplicaSetIdFieldName = "replicaSetId"_sd;

    ReplSetConfigSettings();

    static ReplSetConfigSettings parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * When true, the replica set allows secondary members to replicate from other secondary members. When false, secondaries can replicate only from the primary.
     */
    bool getChainingAllowed() const { return _chainingAllowed; }
    void setChainingAllowed(bool value) & {  _chainingAllowed = std::move(value);  }

    /**
     * The frequency in milliseconds of the heartbeats
     */
    std::int64_t getHeartbeatIntervalMillis() const { return _heartbeatIntervalMillis; }
    void setHeartbeatIntervalMillis(std::int64_t value) & { validateHeartbeatIntervalMillis(value); _heartbeatIntervalMillis = std::move(value);  }

    /**
     * Number of seconds that the replica set members wait for a successful heartbeat from each other
     */
    std::int64_t getHeartbeatTimeoutSecs() const { return _heartbeatTimeoutSecs; }
    void setHeartbeatTimeoutSecs(std::int64_t value) & { validateHeartbeatTimeoutSecs(value); _heartbeatTimeoutSecs = std::move(value);  }

    /**
     * The time limit in milliseconds for detecting when a replica set’s primary is unreachable
     */
    std::int64_t getElectionTimeoutMillis() const { return _electionTimeoutMillis; }
    void setElectionTimeoutMillis(std::int64_t value) & { validateElectionTimeoutMillis(value); _electionTimeoutMillis = std::move(value);  }

    /**
     * Time limit in milliseconds for a newly elected primary to sync (catch up) with the other replica set members that may have more recent writes. If timeout is -1, infinite catchup time.  If timeout is 0, newly elected primaries will not attempt to catch up
     */
    std::int64_t getCatchUpTimeoutMillis() const { return _catchUpTimeoutMillis; }
    void setCatchUpTimeoutMillis(std::int64_t value) & { validateCatchUpTimeoutMillis(value); _catchUpTimeoutMillis = std::move(value);  }

    /**
     * Time in milliseconds a node waits to initiate a catchup takeover after determining it is ahead of the current primary. -1 disables catchup takeover
     */
    std::int64_t getCatchUpTakeoverDelayMillis() const { return _catchUpTakeoverDelayMillis; }
    void setCatchUpTakeoverDelayMillis(std::int64_t value) & { validateCatchUpTakeoverDelayMillis(value); _catchUpTakeoverDelayMillis = std::move(value);  }

    const mongo::repl::ReplSetWriteConcernModeDefinitions& getGetLastErrorModes() const { return _getLastErrorModes; }
    void setGetLastErrorModes(mongo::repl::ReplSetWriteConcernModeDefinitions value) & {  _getLastErrorModes = std::move(value);  }

    const mongo::WriteConcernOptions& getDefaultWriteConcern() const { return _defaultWriteConcern; }
    void setDefaultWriteConcern(mongo::WriteConcernOptions value) & { validateDefaultWriteConcern(value); _defaultWriteConcern = std::move(value);  }

    const boost::optional<mongo::OID>& getReplicaSetId() const& { return _replicaSetId; }
    void getReplicaSetId() && = delete;
    void setReplicaSetId(boost::optional<mongo::OID> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get();
        validateReplicaSetId(_tmpValue);
        _replicaSetId = std::move(_tmpValue);
    } else {
        _replicaSetId = boost::none;
    }
      }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    void validateHeartbeatIntervalMillis(const std::int64_t value);
    void validateHeartbeatIntervalMillis(IDLParserErrorContext& ctxt, const std::int64_t value);

    void validateHeartbeatTimeoutSecs(const std::int64_t value);
    void validateHeartbeatTimeoutSecs(IDLParserErrorContext& ctxt, const std::int64_t value);

    void validateElectionTimeoutMillis(const std::int64_t value);
    void validateElectionTimeoutMillis(IDLParserErrorContext& ctxt, const std::int64_t value);

    void validateCatchUpTimeoutMillis(const std::int64_t value);
    void validateCatchUpTimeoutMillis(IDLParserErrorContext& ctxt, const std::int64_t value);

    void validateCatchUpTakeoverDelayMillis(const std::int64_t value);
    void validateCatchUpTakeoverDelayMillis(IDLParserErrorContext& ctxt, const std::int64_t value);

    void validateDefaultWriteConcern(const mongo::WriteConcernOptions& value);
    void validateDefaultWriteConcern(IDLParserErrorContext& ctxt, const mongo::WriteConcernOptions& value);

    void validateReplicaSetId(const mongo::OID& value);
    void validateReplicaSetId(IDLParserErrorContext& ctxt, const mongo::OID& value);

private:
    bool _chainingAllowed{true};
    std::int64_t _heartbeatIntervalMillis{2000};
    std::int64_t _heartbeatTimeoutSecs{10};
    std::int64_t _electionTimeoutMillis{10000};
    std::int64_t _catchUpTimeoutMillis{-1};
    std::int64_t _catchUpTakeoverDelayMillis{30000};
    mongo::repl::ReplSetWriteConcernModeDefinitions _getLastErrorModes{ReplSetWriteConcernModeDefinitions()};
    mongo::WriteConcernOptions _defaultWriteConcern{WriteConcernOptions()};
    boost::optional<mongo::OID> _replicaSetId;
};

/**
 * The complete configuration for the replica set
 */
class ReplSetConfigBase {
public:
    static constexpr auto kConfigServerFieldName = "configsvr"_sd;
    static constexpr auto kConfigTermFieldName = "term"_sd;
    static constexpr auto kConfigVersionFieldName = "version"_sd;
    static constexpr auto kMembersFieldName = "members"_sd;
    static constexpr auto kProtocolVersionFieldName = "protocolVersion"_sd;
    static constexpr auto kRepairedFieldName = "repaired"_sd;
    static constexpr auto kReplSetNameFieldName = "_id"_sd;
    static constexpr auto kSettingsFieldName = "settings"_sd;
    static constexpr auto kWriteConcernMajorityShouldJournalFieldName = "writeConcernMajorityJournalDefault"_sd;

    ReplSetConfigBase();
    ReplSetConfigBase(std::string replSetName, std::int64_t configVersion, std::vector<mongo::repl::MemberConfig> members);

    static ReplSetConfigBase parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * The name of the replica set. Once set, you cannot change the name of a replica set
     */
    const StringData getReplSetName() const& { return _replSetName; }
    void getReplSetName() && = delete;
    void setReplSetName(StringData value) & { auto _tmpValue = value.toString(); validateReplSetName(_tmpValue); _replSetName = std::move(_tmpValue); _hasReplSetName = true; }

    /**
     * An incrementing number used to distinguish revisions of the replica set configuration object from previous iterations of the configuration
     */
    std::int64_t getConfigVersion() const { return _configVersion; }
    void setConfigVersion(std::int64_t value) & { validateConfigVersion(value); _configVersion = std::move(value); _hasConfigVersion = true; }

    /**
     * The configuration term is the term of the primary that originally created this configuration. Configurations in a replica set are totally ordered by their term and configuration version.
     */
    std::int64_t getConfigTerm() const { return _configTerm; }
    void setConfigTerm(std::int64_t value) & { validateConfigTerm(value); _configTerm = std::move(value);  }

    /**
     * An array of member configuration documents, one for each member of the replica set
     */
    const std::vector<mongo::repl::MemberConfig>& getMembers() const& { return _members; }
    void getMembers() && = delete;
    void setMembers(std::vector<mongo::repl::MemberConfig> value) & {  _members = std::move(value); _hasMembers = true; }

    /**
     * Indicates whether the replica set is used for a sharded cluster’s config servers. Set to true if the replica set is for a sharded cluster’s config servers
     */
    const mongo::OptionalBool& getConfigServer() const { return _configServer; }
    void setConfigServer(mongo::OptionalBool value) & {  _configServer = std::move(value);  }

    /**
     * Election protocol version.  Always 1, as PV0 is no longer supported
     */
    std::int64_t getProtocolVersion() const { return _protocolVersion; }
    void setProtocolVersion(std::int64_t value) & { validateProtocolVersion(value); _protocolVersion = std::move(value);  }

    /**
     * Determines the behavior of { w: "majority" } write concern if the write concern does not explicitly specify the journal option j
     */
    bool getWriteConcernMajorityShouldJournal() const { return _writeConcernMajorityShouldJournal; }
    void setWriteConcernMajorityShouldJournal(bool value) & {  _writeConcernMajorityShouldJournal = std::move(value);  }

    /**
     * A document that contains configuration options that apply to the whole replica set.
     */
    const boost::optional<mongo::repl::ReplSetConfigSettings>& getSettings() const& { return _settings; }
    void getSettings() && = delete;
    void setSettings(boost::optional<mongo::repl::ReplSetConfigSettings> value) & {  _settings = std::move(value);  }

    /**
     * This field indicates the replicated data has been repaired, and prevents use of the configuration until it is removed.
     */
    const mongo::OptionalBool& getRepaired() const { return _repaired; }
    void setRepaired(mongo::OptionalBool value) & {  _repaired = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    void validateReplSetName(const std::string& value);
    void validateReplSetName(IDLParserErrorContext& ctxt, const std::string& value);

    void validateConfigVersion(const std::int64_t value);
    void validateConfigVersion(IDLParserErrorContext& ctxt, const std::int64_t value);

    void validateConfigTerm(const std::int64_t value);
    void validateConfigTerm(IDLParserErrorContext& ctxt, const std::int64_t value);

    void validateProtocolVersion(const std::int64_t value);
    void validateProtocolVersion(IDLParserErrorContext& ctxt, const std::int64_t value);

private:
    std::string _replSetName;
    std::int64_t _configVersion;
    std::int64_t _configTerm{-1};
    std::vector<mongo::repl::MemberConfig> _members;
    mongo::OptionalBool _configServer{mongo::OptionalBool()};
    std::int64_t _protocolVersion{1};
    bool _writeConcernMajorityShouldJournal{true};
    boost::optional<mongo::repl::ReplSetConfigSettings> _settings;
    mongo::OptionalBool _repaired{mongo::OptionalBool()};
    bool _hasReplSetName : 1;
    bool _hasConfigVersion : 1;
    bool _hasMembers : 1;
};

}  // namespace repl
}  // namespace mongo
