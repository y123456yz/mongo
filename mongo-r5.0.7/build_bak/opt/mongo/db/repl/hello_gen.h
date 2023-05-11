/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/repl/hello_gen.h --output build/opt/mongo/db/repl/hello_gen.cpp src/mongo/db/repl/hello.idl
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
#include "mongo/db/auth/auth_types_gen.h"
#include "mongo/db/auth/privilege.h"
#include "mongo/db/auth/role_name.h"
#include "mongo/db/auth/role_name_or_string.h"
#include "mongo/db/auth/user_name.h"
#include "mongo/db/commands.h"
#include "mongo/db/namespace_string.h"
#include "mongo/db/repl/optime.h"
#include "mongo/db/write_concern_options.h"
#include "mongo/idl/basic_types.h"
#include "mongo/idl/basic_types_gen.h"
#include "mongo/idl/idl_parser.h"
#include "mongo/rpc/metadata/client_metadata.h"
#include "mongo/rpc/op_msg.h"
#include "mongo/rpc/topology_version_gen.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/util/uuid.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {

/**
 * Specifies min/max wire protocol versions
 */
class HelloInternalClientField {
public:
    static constexpr auto kMaxWireVersionFieldName = "maxWireVersion"_sd;
    static constexpr auto kMinWireVersionFieldName = "minWireVersion"_sd;

    HelloInternalClientField();
    HelloInternalClientField(std::int32_t maxWireVersion);

    static HelloInternalClientField parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    std::int32_t getMinWireVersion() const { return _minWireVersion; }
    void setMinWireVersion(std::int32_t value) & {  _minWireVersion = std::move(value);  }

    std::int32_t getMaxWireVersion() const { return _maxWireVersion; }
    void setMaxWireVersion(std::int32_t value) & {  _maxWireVersion = std::move(value); _hasMaxWireVersion = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    std::int32_t _minWireVersion{0};
    std::int32_t _maxWireVersion;
    bool _hasMaxWireVersion : 1;
};

/**
 * Most recent op/write times for this node
 */
class HelloLastWrite {
public:
    static constexpr auto kLastWriteDateFieldName = "lastWriteDate"_sd;
    static constexpr auto kMajorityOpTimeFieldName = "majorityOpTime"_sd;
    static constexpr auto kMajorityWriteDateFieldName = "majorityWriteDate"_sd;
    static constexpr auto kOpTimeFieldName = "opTime"_sd;

    HelloLastWrite();

    static HelloLastWrite parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    const boost::optional<mongo::repl::OpTime>& getOpTime() const& { return _opTime; }
    void getOpTime() && = delete;
    void setOpTime(boost::optional<mongo::repl::OpTime> value) & {  _opTime = std::move(value);  }

    const boost::optional<mongo::Date_t>& getLastWriteDate() const& { return _lastWriteDate; }
    void getLastWriteDate() && = delete;
    void setLastWriteDate(boost::optional<mongo::Date_t> value) & {  _lastWriteDate = std::move(value);  }

    const boost::optional<mongo::repl::OpTime>& getMajorityOpTime() const& { return _majorityOpTime; }
    void getMajorityOpTime() && = delete;
    void setMajorityOpTime(boost::optional<mongo::repl::OpTime> value) & {  _majorityOpTime = std::move(value);  }

    const boost::optional<mongo::Date_t>& getMajorityWriteDate() const& { return _majorityWriteDate; }
    void getMajorityWriteDate() && = delete;
    void setMajorityWriteDate(boost::optional<mongo::Date_t> value) & {  _majorityWriteDate = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    boost::optional<mongo::repl::OpTime> _opTime;
    boost::optional<mongo::Date_t> _lastWriteDate;
    boost::optional<mongo::repl::OpTime> _majorityOpTime;
    boost::optional<mongo::Date_t> _majorityWriteDate;
};

/**
 * Reply to 'hello' command
 */
class HelloCommandReply {
public:
    static constexpr auto kArbiterOnlyFieldName = "arbiterOnly"_sd;
    static constexpr auto kArbitersFieldName = "arbiters"_sd;
    static constexpr auto kAutomationServiceDescriptorFieldName = "automationServiceDescriptor"_sd;
    static constexpr auto kBuildIndexesFieldName = "buildIndexes"_sd;
    static constexpr auto kClientSupportsHelloFieldName = "clientSupportsHello"_sd;
    static constexpr auto kCompressionFieldName = "compression"_sd;
    static constexpr auto kConfigsvrFieldName = "configsvr"_sd;
    static constexpr auto kConnectionIdFieldName = "connectionId"_sd;
    static constexpr auto kCwwcFieldName = "cwwc"_sd;
    static constexpr auto kElectionIdFieldName = "electionId"_sd;
    static constexpr auto kHelloOkFieldName = "helloOk"_sd;
    static constexpr auto kHiddenFieldName = "hidden"_sd;
    static constexpr auto kHostsFieldName = "hosts"_sd;
    static constexpr auto kInfoFieldName = "info"_sd;
    static constexpr auto kIsImplicitDefaultMajorityWCFieldName = "isImplicitDefaultMajorityWC"_sd;
    static constexpr auto kIsWritablePrimaryFieldName = "isWritablePrimary"_sd;
    static constexpr auto kIsmasterFieldName = "ismaster"_sd;
    static constexpr auto kIsreplicasetFieldName = "isreplicaset"_sd;
    static constexpr auto kLastWriteFieldName = "lastWrite"_sd;
    static constexpr auto kLocalTimeFieldName = "localTime"_sd;
    static constexpr auto kLogicalSessionTimeoutMinutesFieldName = "logicalSessionTimeoutMinutes"_sd;
    static constexpr auto kMaxBsonObjectSizeFieldName = "maxBsonObjectSize"_sd;
    static constexpr auto kMaxMessageSizeBytesFieldName = "maxMessageSizeBytes"_sd;
    static constexpr auto kMaxWireVersionFieldName = "maxWireVersion"_sd;
    static constexpr auto kMaxWriteBatchSizeFieldName = "maxWriteBatchSize"_sd;
    static constexpr auto kMeFieldName = "me"_sd;
    static constexpr auto kMinWireVersionFieldName = "minWireVersion"_sd;
    static constexpr auto kMsgFieldName = "msg"_sd;
    static constexpr auto kPassiveFieldName = "passive"_sd;
    static constexpr auto kPassivesFieldName = "passives"_sd;
    static constexpr auto kPrimaryFieldName = "primary"_sd;
    static constexpr auto kReadOnlyFieldName = "readOnly"_sd;
    static constexpr auto kSaslSupportedMechsFieldName = "saslSupportedMechs"_sd;
    static constexpr auto kSecondaryFieldName = "secondary"_sd;
    static constexpr auto kSecondaryDelaySecsFieldName = "secondaryDelaySecs"_sd;
    static constexpr auto kServiceIdFieldName = "serviceId"_sd;
    static constexpr auto kSetNameFieldName = "setName"_sd;
    static constexpr auto kSetVersionFieldName = "setVersion"_sd;
    static constexpr auto kSlaveDelayFieldName = "slaveDelay"_sd;
    static constexpr auto kSpeculativeAuthenticateFieldName = "speculativeAuthenticate"_sd;
    static constexpr auto kTagsFieldName = "tags"_sd;
    static constexpr auto kTopologyVersionFieldName = "topologyVersion"_sd;

    HelloCommandReply();
    HelloCommandReply(mongo::TopologyVersion topologyVersion);

    static HelloCommandReply parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    bool getHelloOk() const { return _helloOk; }
    void setHelloOk(bool value) & {  _helloOk = std::move(value);  }

    const boost::optional<bool> getClientSupportsHello() const& { return _clientSupportsHello; }
    void getClientSupportsHello() && = delete;
    void setClientSupportsHello(boost::optional<bool> value) & {  _clientSupportsHello = std::move(value);  }

    const boost::optional<std::int32_t> getConfigsvr() const& { return _configsvr; }
    void getConfigsvr() && = delete;
    void setConfigsvr(boost::optional<std::int32_t> value) & {  _configsvr = std::move(value);  }

    const boost::optional<std::int64_t> getMaxBsonObjectSize() const& { return _maxBsonObjectSize; }
    void getMaxBsonObjectSize() && = delete;
    void setMaxBsonObjectSize(boost::optional<std::int64_t> value) & {  _maxBsonObjectSize = std::move(value);  }

    const boost::optional<std::int64_t> getMaxMessageSizeBytes() const& { return _maxMessageSizeBytes; }
    void getMaxMessageSizeBytes() && = delete;
    void setMaxMessageSizeBytes(boost::optional<std::int64_t> value) & {  _maxMessageSizeBytes = std::move(value);  }

    const boost::optional<std::int64_t> getMaxWriteBatchSize() const& { return _maxWriteBatchSize; }
    void getMaxWriteBatchSize() && = delete;
    void setMaxWriteBatchSize(boost::optional<std::int64_t> value) & {  _maxWriteBatchSize = std::move(value);  }

    const boost::optional<mongo::Date_t>& getLocalTime() const& { return _localTime; }
    void getLocalTime() && = delete;
    void setLocalTime(boost::optional<mongo::Date_t> value) & {  _localTime = std::move(value);  }

    const boost::optional<std::int32_t> getLogicalSessionTimeoutMinutes() const& { return _logicalSessionTimeoutMinutes; }
    void getLogicalSessionTimeoutMinutes() && = delete;
    void setLogicalSessionTimeoutMinutes(boost::optional<std::int32_t> value) & {  _logicalSessionTimeoutMinutes = std::move(value);  }

    const boost::optional<std::int64_t> getConnectionId() const& { return _connectionId; }
    void getConnectionId() && = delete;
    void setConnectionId(boost::optional<std::int64_t> value) & {  _connectionId = std::move(value);  }

    const boost::optional<std::int32_t> getMinWireVersion() const& { return _minWireVersion; }
    void getMinWireVersion() && = delete;
    void setMinWireVersion(boost::optional<std::int32_t> value) & {  _minWireVersion = std::move(value);  }

    const boost::optional<std::int32_t> getMaxWireVersion() const& { return _maxWireVersion; }
    void getMaxWireVersion() && = delete;
    void setMaxWireVersion(boost::optional<std::int32_t> value) & {  _maxWireVersion = std::move(value);  }

    const boost::optional<bool> getReadOnly() const& { return _readOnly; }
    void getReadOnly() && = delete;
    void setReadOnly(boost::optional<bool> value) & {  _readOnly = std::move(value);  }

    const boost::optional<std::vector<StringData>> getCompression() const& { if (_compression.is_initialized()) {
        return transformVector(_compression.get());
    } else {
        return boost::none;
    }
     }
    void getCompression() && = delete;
    void setCompression(boost::optional<std::vector<StringData>> value) & { if (value.is_initialized()) {
        auto _tmpValue = transformVector(value.get());
        
        _compression = std::move(_tmpValue);
    } else {
        _compression = boost::none;
    }
      }

    const boost::optional<StringData> getAutomationServiceDescriptor() const& { return boost::optional<StringData>{_automationServiceDescriptor}; }
    void getAutomationServiceDescriptor() && = delete;
    void setAutomationServiceDescriptor(boost::optional<StringData> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get().toString();
        
        _automationServiceDescriptor = std::move(_tmpValue);
    } else {
        _automationServiceDescriptor = boost::none;
    }
      }

    const boost::optional<std::vector<StringData>> getSaslSupportedMechs() const& { if (_saslSupportedMechs.is_initialized()) {
        return transformVector(_saslSupportedMechs.get());
    } else {
        return boost::none;
    }
     }
    void getSaslSupportedMechs() && = delete;
    void setSaslSupportedMechs(boost::optional<std::vector<StringData>> value) & { if (value.is_initialized()) {
        auto _tmpValue = transformVector(value.get());
        
        _saslSupportedMechs = std::move(_tmpValue);
    } else {
        _saslSupportedMechs = boost::none;
    }
      }

    const boost::optional<mongo::BSONObj>& getSpeculativeAuthenticate() const& { return _speculativeAuthenticate; }
    void getSpeculativeAuthenticate() && = delete;
    void setSpeculativeAuthenticate(boost::optional<mongo::BSONObj> value) & {  _speculativeAuthenticate = std::move(value);  }

    const boost::optional<StringData> getMsg() const& { return boost::optional<StringData>{_msg}; }
    void getMsg() && = delete;
    void setMsg(boost::optional<StringData> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get().toString();
        
        _msg = std::move(_tmpValue);
    } else {
        _msg = boost::none;
    }
      }

    const boost::optional<mongo::OID>& getServiceId() const& { return _serviceId; }
    void getServiceId() && = delete;
    void setServiceId(boost::optional<mongo::OID> value) & {  _serviceId = std::move(value);  }

    const mongo::TopologyVersion& getTopologyVersion() const { return _topologyVersion; }
    mongo::TopologyVersion& getTopologyVersion() { return _topologyVersion; }
    void setTopologyVersion(mongo::TopologyVersion value) & {  _topologyVersion = std::move(value); _hasTopologyVersion = true; }

    const boost::optional<bool> getIsmaster() const& { return _ismaster; }
    void getIsmaster() && = delete;
    void setIsmaster(boost::optional<bool> value) & {  _ismaster = std::move(value);  }

    const boost::optional<bool> getIsWritablePrimary() const& { return _isWritablePrimary; }
    void getIsWritablePrimary() && = delete;
    void setIsWritablePrimary(boost::optional<bool> value) & {  _isWritablePrimary = std::move(value);  }

    const boost::optional<std::vector<StringData>> getHosts() const& { if (_hosts.is_initialized()) {
        return transformVector(_hosts.get());
    } else {
        return boost::none;
    }
     }
    void getHosts() && = delete;
    void setHosts(boost::optional<std::vector<StringData>> value) & { if (value.is_initialized()) {
        auto _tmpValue = transformVector(value.get());
        
        _hosts = std::move(_tmpValue);
    } else {
        _hosts = boost::none;
    }
      }

    const boost::optional<std::vector<StringData>> getPassives() const& { if (_passives.is_initialized()) {
        return transformVector(_passives.get());
    } else {
        return boost::none;
    }
     }
    void getPassives() && = delete;
    void setPassives(boost::optional<std::vector<StringData>> value) & { if (value.is_initialized()) {
        auto _tmpValue = transformVector(value.get());
        
        _passives = std::move(_tmpValue);
    } else {
        _passives = boost::none;
    }
      }

    const boost::optional<std::vector<StringData>> getArbiters() const& { if (_arbiters.is_initialized()) {
        return transformVector(_arbiters.get());
    } else {
        return boost::none;
    }
     }
    void getArbiters() && = delete;
    void setArbiters(boost::optional<std::vector<StringData>> value) & { if (value.is_initialized()) {
        auto _tmpValue = transformVector(value.get());
        
        _arbiters = std::move(_tmpValue);
    } else {
        _arbiters = boost::none;
    }
      }

    const boost::optional<StringData> getSetName() const& { return boost::optional<StringData>{_setName}; }
    void getSetName() && = delete;
    void setSetName(boost::optional<StringData> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get().toString();
        
        _setName = std::move(_tmpValue);
    } else {
        _setName = boost::none;
    }
      }

    const boost::optional<StringData> getPrimary() const& { return boost::optional<StringData>{_primary}; }
    void getPrimary() && = delete;
    void setPrimary(boost::optional<StringData> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get().toString();
        
        _primary = std::move(_tmpValue);
    } else {
        _primary = boost::none;
    }
      }

    const boost::optional<bool> getSecondary() const& { return _secondary; }
    void getSecondary() && = delete;
    void setSecondary(boost::optional<bool> value) & {  _secondary = std::move(value);  }

    const boost::optional<StringData> getInfo() const& { return boost::optional<StringData>{_info}; }
    void getInfo() && = delete;
    void setInfo(boost::optional<StringData> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get().toString();
        
        _info = std::move(_tmpValue);
    } else {
        _info = boost::none;
    }
      }

    const boost::optional<bool> getIsreplicaset() const& { return _isreplicaset; }
    void getIsreplicaset() && = delete;
    void setIsreplicaset(boost::optional<bool> value) & {  _isreplicaset = std::move(value);  }

    const boost::optional<std::int32_t> getSetVersion() const& { return _setVersion; }
    void getSetVersion() && = delete;
    void setSetVersion(boost::optional<std::int32_t> value) & {  _setVersion = std::move(value);  }

    const boost::optional<bool> getArbiterOnly() const& { return _arbiterOnly; }
    void getArbiterOnly() && = delete;
    void setArbiterOnly(boost::optional<bool> value) & {  _arbiterOnly = std::move(value);  }

    const boost::optional<bool> getPassive() const& { return _passive; }
    void getPassive() && = delete;
    void setPassive(boost::optional<bool> value) & {  _passive = std::move(value);  }

    const boost::optional<bool> getHidden() const& { return _hidden; }
    void getHidden() && = delete;
    void setHidden(boost::optional<bool> value) & {  _hidden = std::move(value);  }

    const boost::optional<bool> getBuildIndexes() const& { return _buildIndexes; }
    void getBuildIndexes() && = delete;
    void setBuildIndexes(boost::optional<bool> value) & {  _buildIndexes = std::move(value);  }

    const boost::optional<std::int64_t> getSlaveDelay() const& { return _slaveDelay; }
    void getSlaveDelay() && = delete;
    void setSlaveDelay(boost::optional<std::int64_t> value) & {  _slaveDelay = std::move(value);  }

    const boost::optional<std::int64_t> getSecondaryDelaySecs() const& { return _secondaryDelaySecs; }
    void getSecondaryDelaySecs() && = delete;
    void setSecondaryDelaySecs(boost::optional<std::int64_t> value) & {  _secondaryDelaySecs = std::move(value);  }

    const boost::optional<mongo::BSONObj>& getTags() const& { return _tags; }
    void getTags() && = delete;
    void setTags(boost::optional<mongo::BSONObj> value) & {  _tags = std::move(value);  }

    const boost::optional<StringData> getMe() const& { return boost::optional<StringData>{_me}; }
    void getMe() && = delete;
    void setMe(boost::optional<StringData> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get().toString();
        
        _me = std::move(_tmpValue);
    } else {
        _me = boost::none;
    }
      }

    const boost::optional<mongo::OID>& getElectionId() const& { return _electionId; }
    void getElectionId() && = delete;
    void setElectionId(boost::optional<mongo::OID> value) & {  _electionId = std::move(value);  }

    const boost::optional<mongo::HelloLastWrite>& getLastWrite() const& { return _lastWrite; }
    void getLastWrite() && = delete;
    void setLastWrite(boost::optional<mongo::HelloLastWrite> value) & {  _lastWrite = std::move(value);  }

    const boost::optional<bool> getIsImplicitDefaultMajorityWC() const& { return _isImplicitDefaultMajorityWC; }
    void getIsImplicitDefaultMajorityWC() && = delete;
    void setIsImplicitDefaultMajorityWC(boost::optional<bool> value) & {  _isImplicitDefaultMajorityWC = std::move(value);  }

    const boost::optional<mongo::WriteConcernOptions>& getCwwc() const& { return _cwwc; }
    void getCwwc() && = delete;
    void setCwwc(boost::optional<mongo::WriteConcernOptions> value) & {  _cwwc = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    bool _helloOk{true};
    boost::optional<bool> _clientSupportsHello;
    boost::optional<std::int32_t> _configsvr;
    boost::optional<std::int64_t> _maxBsonObjectSize;
    boost::optional<std::int64_t> _maxMessageSizeBytes;
    boost::optional<std::int64_t> _maxWriteBatchSize;
    boost::optional<mongo::Date_t> _localTime;
    boost::optional<std::int32_t> _logicalSessionTimeoutMinutes;
    boost::optional<std::int64_t> _connectionId;
    boost::optional<std::int32_t> _minWireVersion;
    boost::optional<std::int32_t> _maxWireVersion;
    boost::optional<bool> _readOnly;
    boost::optional<std::vector<std::string>> _compression;
    boost::optional<std::string> _automationServiceDescriptor;
    boost::optional<std::vector<std::string>> _saslSupportedMechs;
    boost::optional<mongo::BSONObj> _speculativeAuthenticate;
    boost::optional<std::string> _msg;
    boost::optional<mongo::OID> _serviceId;
    mongo::TopologyVersion _topologyVersion;
    boost::optional<bool> _ismaster;
    boost::optional<bool> _isWritablePrimary;
    boost::optional<std::vector<std::string>> _hosts;
    boost::optional<std::vector<std::string>> _passives;
    boost::optional<std::vector<std::string>> _arbiters;
    boost::optional<std::string> _setName;
    boost::optional<std::string> _primary;
    boost::optional<bool> _secondary;
    boost::optional<std::string> _info;
    boost::optional<bool> _isreplicaset;
    boost::optional<std::int32_t> _setVersion;
    boost::optional<bool> _arbiterOnly;
    boost::optional<bool> _passive;
    boost::optional<bool> _hidden;
    boost::optional<bool> _buildIndexes;
    boost::optional<std::int64_t> _slaveDelay;
    boost::optional<std::int64_t> _secondaryDelaySecs;
    boost::optional<mongo::BSONObj> _tags;
    boost::optional<std::string> _me;
    boost::optional<mongo::OID> _electionId;
    boost::optional<mongo::HelloLastWrite> _lastWrite;
    boost::optional<bool> _isImplicitDefaultMajorityWC;
    boost::optional<mongo::WriteConcernOptions> _cwwc;
    bool _hasTopologyVersion : 1;
};

/**
 * Check if this server is primary for a replica set { hello: 1 }
 */
class HelloCommand {
public:
    using Reply = mongo::HelloCommandReply;
    static constexpr auto kClientFieldName = "client"_sd;
    static constexpr auto kCompressionFieldName = "compression"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kForShellFieldName = "forShell"_sd;
    static constexpr auto kHangUpOnStepDownFieldName = "hangUpOnStepDown"_sd;
    static constexpr auto kHelloOkFieldName = "helloOk"_sd;
    static constexpr auto kHostInfoFieldName = "hostInfo"_sd;
    static constexpr auto kInternalClientFieldName = "internalClient"_sd;
    static constexpr auto kLoadBalancedFieldName = "loadBalanced"_sd;
    static constexpr auto kMaxAwaitTimeMSFieldName = "maxAwaitTimeMS"_sd;
    static constexpr auto kSaslSupportedMechsFieldName = "saslSupportedMechs"_sd;
    static constexpr auto kSpeculativeAuthenticateFieldName = "speculativeAuthenticate"_sd;
    static constexpr auto kTopologyVersionFieldName = "topologyVersion"_sd;
    static constexpr auto kCommandName = "hello"_sd;

    static AuthorizationContract kAuthorizationContract;

    HelloCommand();

    static HelloCommand parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static HelloCommand parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;


    bool getForShell() const { return _forShell; }
    void setForShell(bool value) & {  _forShell = std::move(value);  }

    const StringData getHostInfo() const& { return _hostInfo; }
    void getHostInfo() && = delete;
    void setHostInfo(StringData value) & { auto _tmpValue = value.toString();  _hostInfo = std::move(_tmpValue);  }

    bool getHangUpOnStepDown() const { return _hangUpOnStepDown; }
    void setHangUpOnStepDown(bool value) & {  _hangUpOnStepDown = std::move(value);  }

    const boost::optional<mongo::HelloInternalClientField>& getInternalClient() const& { return _internalClient; }
    void getInternalClient() && = delete;
    void setInternalClient(boost::optional<mongo::HelloInternalClientField> value) & {  _internalClient = std::move(value);  }

    const boost::optional<mongo::ClientMetadata>& getClient() const& { return _client; }
    void getClient() && = delete;
    void setClient(boost::optional<mongo::ClientMetadata> value) & {  _client = std::move(value);  }

    const boost::optional<mongo::TopologyVersion>& getTopologyVersion() const& { return _topologyVersion; }
    void getTopologyVersion() && = delete;
    void setTopologyVersion(boost::optional<mongo::TopologyVersion> value) & {  _topologyVersion = std::move(value);  }

    const boost::optional<std::int64_t> getMaxAwaitTimeMS() const& { return _maxAwaitTimeMS; }
    void getMaxAwaitTimeMS() && = delete;
    void setMaxAwaitTimeMS(boost::optional<std::int64_t> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get();
        validateMaxAwaitTimeMS(_tmpValue);
        _maxAwaitTimeMS = std::move(_tmpValue);
    } else {
        _maxAwaitTimeMS = boost::none;
    }
      }

    const boost::optional<bool> getHelloOk() const& { return _helloOk; }
    void getHelloOk() && = delete;
    void setHelloOk(boost::optional<bool> value) & {  _helloOk = std::move(value);  }

    const boost::optional<std::vector<StringData>> getCompression() const& { if (_compression.is_initialized()) {
        return transformVector(_compression.get());
    } else {
        return boost::none;
    }
     }
    void getCompression() && = delete;
    void setCompression(boost::optional<std::vector<StringData>> value) & { if (value.is_initialized()) {
        auto _tmpValue = transformVector(value.get());
        
        _compression = std::move(_tmpValue);
    } else {
        _compression = boost::none;
    }
      }

    const boost::optional<stdx::variant<std::string, mongo::BSONObj>>& getSaslSupportedMechs() const& { return _saslSupportedMechs; }
    void getSaslSupportedMechs() && = delete;
    void setSaslSupportedMechs(boost::optional<stdx::variant<std::string, mongo::BSONObj>> value) & {  _saslSupportedMechs = std::move(value);  }

    const boost::optional<mongo::BSONObj>& getSpeculativeAuthenticate() const& { return _speculativeAuthenticate; }
    void getSpeculativeAuthenticate() && = delete;
    void setSpeculativeAuthenticate(boost::optional<mongo::BSONObj> value) & {  _speculativeAuthenticate = std::move(value);  }

    const boost::optional<bool> getLoadBalanced() const& { return _loadBalanced; }
    void getLoadBalanced() && = delete;
    void setLoadBalanced(boost::optional<bool> value) & {  _loadBalanced = std::move(value);  }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    void validateMaxAwaitTimeMS(const std::int64_t value);
    void validateMaxAwaitTimeMS(IDLParserErrorContext& ctxt, const std::int64_t value);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;



    bool _forShell{false};
    std::string _hostInfo{false};
    bool _hangUpOnStepDown{true};
    boost::optional<mongo::HelloInternalClientField> _internalClient;
    boost::optional<mongo::ClientMetadata> _client;
    boost::optional<mongo::TopologyVersion> _topologyVersion;
    boost::optional<std::int64_t> _maxAwaitTimeMS;
    boost::optional<bool> _helloOk;
    boost::optional<std::vector<std::string>> _compression;
    boost::optional<stdx::variant<std::string, mongo::BSONObj>> _saslSupportedMechs;
    boost::optional<mongo::BSONObj> _speculativeAuthenticate;
    boost::optional<bool> _loadBalanced;
    std::string _dbName;
    bool _hasDbName : 1;
};


template <typename Derived>
class HelloCmdVersion1Gen : public TypedCommand<Derived> {
    using _TypedCommandInvocationBase = typename TypedCommand<Derived>::InvocationBase;

public:
    using Request = HelloCommand;
    using Reply = mongo::HelloCommandReply;

    virtual ~HelloCmdVersion1Gen() = default;

    virtual const std::set<std::string>& apiVersions() const final {
        return kApiVersions1;
    }
    virtual const std::set<std::string>& deprecatedApiVersions() const final {
        return kNoApiVersions;
    }
    const AuthorizationContract* getAuthorizationContract() const final { return &Request::kAuthorizationContract; } 

    class InvocationBaseGen : public _TypedCommandInvocationBase {
    public:
        using _TypedCommandInvocationBase::_TypedCommandInvocationBase;
        virtual Reply typedRun(OperationContext* opCtx) = 0;
        void doCheckAuthorization(OperationContext* opCtx) const final {}
    };
};
}  // namespace mongo
