/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/repl/member_config_gen.h --output build/opt/mongo/db/repl/member_config_gen.cpp src/mongo/db/repl/member_config.idl
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
#include "mongo/db/repl/member_id.h"
#include "mongo/db/repl/repl_set_config_validators.h"
#include "mongo/idl/basic_types.h"
#include "mongo/idl/basic_types_gen.h"
#include "mongo/idl/idl_parser.h"
#include "mongo/rpc/op_msg.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/util/uuid.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {
namespace repl {

/**
 * The configuration for a given member inside of the replica set config
 */
class MemberConfigBase {
public:
    static constexpr auto kArbiterOnlyFieldName = "arbiterOnly"_sd;
    static constexpr auto kBuildIndexesFieldName = "buildIndexes"_sd;
    static constexpr auto kHiddenFieldName = "hidden"_sd;
    static constexpr auto kHorizonsFieldName = "horizons"_sd;
    static constexpr auto kHostFieldName = "host"_sd;
    static constexpr auto kIdFieldName = "_id"_sd;
    static constexpr auto kNewlyAddedFieldName = "newlyAdded"_sd;
    static constexpr auto kPriorityFieldName = "priority"_sd;
    static constexpr auto kSecondaryDelaySecsFieldName = "secondaryDelaySecs"_sd;
    static constexpr auto kSlaveDelaySecsFieldName = "slaveDelay"_sd;
    static constexpr auto kTagsFieldName = "tags"_sd;
    static constexpr auto kVotesFieldName = "votes"_sd;

    MemberConfigBase();
    MemberConfigBase(mongo::repl::MemberId id, std::string host);

    static MemberConfigBase parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * An integer identifier of every member in the replica set
     */
    const mongo::repl::MemberId& getId() const { return _id; }
    void setId(mongo::repl::MemberId value) & {  _id = std::move(value); _hasId = true; }

    /**
     * The hostname and, if specified, the port number, of the set member
     */
    const StringData getHost() const& { return _host; }
    void getHost() && = delete;
    void setHost(StringData value) & { auto _tmpValue = value.toString();  _host = std::move(_tmpValue); _hasHost = true; }

    /**
     * The number of votes a server will cast in a replica set election. The number of votes each member has is either 1 or 0, and arbiters always have exactly 1 vote
     */
    std::int64_t getVotes() const { return _votes; }
    void setVotes(std::int64_t value) & { validateVotes(value); _votes = std::move(value);  }

    /**
     * Set to true if the member was just added and is in initial sync. Must be true when specified. Indicates that the votes and priority fields should be considered '0' for the duration of the initial sync
     */
    const boost::optional<bool> getNewlyAdded() const& { return _newlyAdded; }
    void getNewlyAdded() && = delete;
    void setNewlyAdded(boost::optional<bool> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get();
        validateNewlyAdded(_tmpValue);
        _newlyAdded = std::move(_tmpValue);
    } else {
        _newlyAdded = boost::none;
    }
      }

    /**
     * A number that indicates the relative eligibility of a member to become a primary
     */
    double getPriority() const { return _priority; }
    void setPriority(double value) & { validatePriority(value); _priority = std::move(value);  }

    /**
     * When this value is true, the replica set hides this instance and does not include the member in the output of db.hello() or hello. This prevents read operations (i.e. queries) from ever reaching this host by way of secondary read preference
     */
    bool getHidden() const { return _hidden; }
    void setHidden(bool value) & {  _hidden = std::move(value);  }

    /**
     * The number of seconds 'behind' the primary that this replica set member should 'lag'. This is a legacy field kept for backwards compatibility, and 5.0+ nodes should use secondaryDelaySecs
     */
    const boost::optional<std::int64_t> getSlaveDelaySecs() const& { return _slaveDelaySecs; }
    void getSlaveDelaySecs() && = delete;
    void setSlaveDelaySecs(boost::optional<std::int64_t> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get();
        validateSlaveDelaySecs(_tmpValue);
        _slaveDelaySecs = std::move(_tmpValue);
    } else {
        _slaveDelaySecs = boost::none;
    }
      }

    /**
     * The number of seconds 'behind' the primary that this replica set member should 'lag'. Only 5.0+ nodes will use this field, and older nodes will use slaveDelay
     */
    const boost::optional<std::int64_t> getSecondaryDelaySecs() const& { return _secondaryDelaySecs; }
    void getSecondaryDelaySecs() && = delete;
    void setSecondaryDelaySecs(boost::optional<std::int64_t> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get();
        validateSecondaryDelaySecs(_tmpValue);
        _secondaryDelaySecs = std::move(_tmpValue);
    } else {
        _secondaryDelaySecs = boost::none;
    }
      }

    /**
     * A boolean that identifies an arbiter. A value of true indicates that the member is an arbiter
     */
    bool getArbiterOnly() const { return _arbiterOnly; }
    void setArbiterOnly(bool value) & {  _arbiterOnly = std::move(value);  }

    /**
     * A boolean that indicates whether the mongod builds indexes on this member
     */
    bool getBuildIndexes() const { return _buildIndexes; }
    void setBuildIndexes(bool value) & {  _buildIndexes = std::move(value);  }

    /**
     * A tags document contains user-defined tag field and value pairs for the replica set member
     */
    const boost::optional<mongo::BSONObj>& getTags() const& { return _tags; }
    void getTags() && = delete;
    void setTags(boost::optional<mongo::BSONObj> value) & {  _tags = std::move(value);  }

    /**
     * The hostnames for the provided horizons
     */
    const boost::optional<mongo::BSONObj>& getHorizons() const& { return _horizons; }
    void getHorizons() && = delete;
    void setHorizons(boost::optional<mongo::BSONObj> value) & {  _horizons = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    void validateVotes(const std::int64_t value);
    void validateVotes(IDLParserErrorContext& ctxt, const std::int64_t value);

    void validateNewlyAdded(const bool value);
    void validateNewlyAdded(IDLParserErrorContext& ctxt, const bool value);

    void validatePriority(const double value);
    void validatePriority(IDLParserErrorContext& ctxt, const double value);

    void validateSlaveDelaySecs(const std::int64_t value);
    void validateSlaveDelaySecs(IDLParserErrorContext& ctxt, const std::int64_t value);

    void validateSecondaryDelaySecs(const std::int64_t value);
    void validateSecondaryDelaySecs(IDLParserErrorContext& ctxt, const std::int64_t value);

private:
    mongo::repl::MemberId _id;
    std::string _host;
    std::int64_t _votes{1};
    boost::optional<bool> _newlyAdded;
    double _priority{1.0};
    bool _hidden{false};
    boost::optional<std::int64_t> _slaveDelaySecs;
    boost::optional<std::int64_t> _secondaryDelaySecs;
    bool _arbiterOnly{false};
    bool _buildIndexes{true};
    boost::optional<mongo::BSONObj> _tags;
    boost::optional<mongo::BSONObj> _horizons;
    bool _hasId : 1;
    bool _hasHost : 1;
};

}  // namespace repl
}  // namespace mongo
