/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/coll_mod_gen.h --output build/opt/mongo/db/coll_mod_gen.cpp src/mongo/db/coll_mod.idl
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
#include "mongo/db/catalog/collection_options_gen.h"
#include "mongo/db/catalog/collection_options_validation.h"
#include "mongo/db/commands.h"
#include "mongo/db/commands/create_command_validation.h"
#include "mongo/db/namespace_string.h"
#include "mongo/db/timeseries/timeseries_gen.h"
#include "mongo/db/timeseries/timeseries_global_options.h"
#include "mongo/idl/basic_types.h"
#include "mongo/idl/basic_types_gen.h"
#include "mongo/idl/idl_parser.h"
#include "mongo/rpc/op_msg.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/util/uuid.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {

/**
 * A type representing a spec for an index to be modified by collMod command.
 */
class CollModIndex {
public:
    static constexpr auto kExpireAfterSecondsFieldName = "expireAfterSeconds"_sd;
    static constexpr auto kHiddenFieldName = "hidden"_sd;
    static constexpr auto kKeyPatternFieldName = "keyPattern"_sd;
    static constexpr auto kNameFieldName = "name"_sd;

    CollModIndex();

    static CollModIndex parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    const boost::optional<StringData> getName() const& { return boost::optional<StringData>{_name}; }
    void getName() && = delete;
    void setName(boost::optional<StringData> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get().toString();
        
        _name = std::move(_tmpValue);
    } else {
        _name = boost::none;
    }
      }

    const boost::optional<mongo::BSONObj>& getKeyPattern() const& { return _keyPattern; }
    void getKeyPattern() && = delete;
    void setKeyPattern(boost::optional<mongo::BSONObj> value) & {  _keyPattern = std::move(value);  }

    const boost::optional<std::int32_t> getExpireAfterSeconds() const& { return _expireAfterSeconds; }
    void getExpireAfterSeconds() && = delete;
    void setExpireAfterSeconds(boost::optional<std::int32_t> value) & {  _expireAfterSeconds = std::move(value);  }

    const boost::optional<bool> getHidden() const& { return _hidden; }
    void getHidden() && = delete;
    void setHidden(boost::optional<bool> value) & {  _hidden = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    boost::optional<std::string> _name;
    boost::optional<mongo::BSONObj> _keyPattern;
    boost::optional<std::int32_t> _expireAfterSeconds;
    boost::optional<bool> _hidden;
};

/**
 * The collMod command's reply.
 */
class CollModReply {
public:
    static constexpr auto kExpireAfterSeconds_newFieldName = "expireAfterSeconds_new"_sd;
    static constexpr auto kExpireAfterSeconds_oldFieldName = "expireAfterSeconds_old"_sd;
    static constexpr auto kHidden_newFieldName = "hidden_new"_sd;
    static constexpr auto kHidden_oldFieldName = "hidden_old"_sd;

    CollModReply();

    static CollModReply parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    const boost::optional<std::int32_t> getExpireAfterSeconds_old() const& { return _expireAfterSeconds_old; }
    void getExpireAfterSeconds_old() && = delete;
    void setExpireAfterSeconds_old(boost::optional<std::int32_t> value) & {  _expireAfterSeconds_old = std::move(value);  }

    const boost::optional<std::int32_t> getExpireAfterSeconds_new() const& { return _expireAfterSeconds_new; }
    void getExpireAfterSeconds_new() && = delete;
    void setExpireAfterSeconds_new(boost::optional<std::int32_t> value) & {  _expireAfterSeconds_new = std::move(value);  }

    const boost::optional<bool> getHidden_old() const& { return _hidden_old; }
    void getHidden_old() && = delete;
    void setHidden_old(boost::optional<bool> value) & {  _hidden_old = std::move(value);  }

    const boost::optional<bool> getHidden_new() const& { return _hidden_new; }
    void getHidden_new() && = delete;
    void setHidden_new(boost::optional<bool> value) & {  _hidden_new = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    boost::optional<std::int32_t> _expireAfterSeconds_old;
    boost::optional<std::int32_t> _expireAfterSeconds_new;
    boost::optional<bool> _hidden_old;
    boost::optional<bool> _hidden_new;
};

/**
 * A type representing the adjustable options on timeseries collections
 */
class CollModTimeseries {
public:
    static constexpr auto kGranularityFieldName = "granularity"_sd;

    CollModTimeseries();

    static CollModTimeseries parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    const boost::optional<mongo::BucketGranularityEnum> getGranularity() const& { return _granularity; }
    void getGranularity() && = delete;
    void setGranularity(boost::optional<mongo::BucketGranularityEnum> value) & {  _granularity = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    boost::optional<mongo::BucketGranularityEnum> _granularity;
};

/**
 * Specify collMod Command.
 */
class CollMod {
public:
    using Reply = mongo::CollModReply;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kExpireAfterSecondsFieldName = "expireAfterSeconds"_sd;
    static constexpr auto kIndexFieldName = "index"_sd;
    static constexpr auto kIsTimeseriesNamespaceFieldName = "isTimeseriesNamespace"_sd;
    static constexpr auto kPipelineFieldName = "pipeline"_sd;
    static constexpr auto kRecordPreImagesFieldName = "recordPreImages"_sd;
    static constexpr auto kTimeseriesFieldName = "timeseries"_sd;
    static constexpr auto kValidationActionFieldName = "validationAction"_sd;
    static constexpr auto kValidationLevelFieldName = "validationLevel"_sd;
    static constexpr auto kValidatorFieldName = "validator"_sd;
    static constexpr auto kViewOnFieldName = "viewOn"_sd;
    static constexpr auto kCommandName = "collMod"_sd;

    static AuthorizationContract kAuthorizationContract;

    explicit CollMod(const NamespaceString nss);

    static CollMod parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static CollMod parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const NamespaceString& getNamespace() const { return _nss; }

    /**
     * Index to be modified.
     */
    const boost::optional<mongo::CollModIndex>& getIndex() const& { return _index; }
    void getIndex() && = delete;
    void setIndex(boost::optional<mongo::CollModIndex> value) & {  _index = std::move(value);  }

    /**
     * Specify validation rules or expressions for the collection.
     */
    const boost::optional<mongo::BSONObj>& getValidator() const& { return _validator; }
    void getValidator() && = delete;
    void setValidator(boost::optional<mongo::BSONObj> value) & {  _validator = std::move(value);  }

    /**
     * Determines how strictly to apply the validation rules to existing documents during an update. Can be one of following values: 'off', 'strict' or 'moderate'.
     */
    const boost::optional<mongo::ValidationLevelEnum> getValidationLevel() const& { return _validationLevel; }
    void getValidationLevel() && = delete;
    void setValidationLevel(boost::optional<mongo::ValidationLevelEnum> value) & {  _validationLevel = std::move(value);  }

    /**
     * Determines whether to error on invalid documents or just warn about the violations but allow invalid documents to be inserted. Can be either 'warn' or 'error'.
     */
    const boost::optional<mongo::ValidationActionEnum> getValidationAction() const& { return _validationAction; }
    void getValidationAction() && = delete;
    void setValidationAction(boost::optional<mongo::ValidationActionEnum> value) & {  _validationAction = std::move(value);  }

    /**
     * The name of the source collection or view that 'namespace' is based off of.
     */
    const boost::optional<StringData> getViewOn() const& { return boost::optional<StringData>{_viewOn}; }
    void getViewOn() && = delete;
    void setViewOn(boost::optional<StringData> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get().toString();
        validateViewOn(_tmpValue);
        _viewOn = std::move(_tmpValue);
    } else {
        _viewOn = boost::none;
    }
      }

    /**
     * An array that consists of the aggregation pipeline. Defines the view by applying the specified pipeline to the 'viewOn' collection or view.
     */
    const boost::optional<std::vector<mongo::BSONObj>>& getPipeline() const& { return _pipeline; }
    void getPipeline() && = delete;
    void setPipeline(boost::optional<std::vector<mongo::BSONObj>> value) & {  _pipeline = std::move(value);  }

    /**
     * Sets whether updates/deletes should store the pre-image of the document in the oplog
     */
    const boost::optional<bool> getRecordPreImages() const& { return _recordPreImages; }
    void getRecordPreImages() && = delete;
    void setRecordPreImages(boost::optional<bool> value) & {  _recordPreImages = std::move(value);  }

    /**
     * The number of seconds after which old data should be deleted. This can be disabled by passing in 'off' as a value
     */
    const boost::optional<stdx::variant<std::string, std::int64_t>>& getExpireAfterSeconds() const& { return _expireAfterSeconds; }
    void getExpireAfterSeconds() && = delete;
    void setExpireAfterSeconds(boost::optional<stdx::variant<std::string, std::int64_t>> value) & {  _expireAfterSeconds = std::move(value);  }

    /**
     * Adjusts parameters for timeseries collections
     */
    const boost::optional<mongo::CollModTimeseries>& getTimeseries() const& { return _timeseries; }
    void getTimeseries() && = delete;
    void setTimeseries(boost::optional<mongo::CollModTimeseries> value) & {  _timeseries = std::move(value);  }

    /**
     * This flag is set to true when the command was originally sent to mongos on the time-series view, but got rewritten to target time-series buckets namespace before being sent to shards.
     */
    const boost::optional<bool> getIsTimeseriesNamespace() const& { return _isTimeseriesNamespace; }
    void getIsTimeseriesNamespace() && = delete;
    void setIsTimeseriesNamespace(boost::optional<bool> value) & {  _isTimeseriesNamespace = std::move(value);  }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    void validateViewOn(const std::string& value);
    void validateViewOn(IDLParserErrorContext& ctxt, const std::string& value);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;


    NamespaceString _nss;

    boost::optional<mongo::CollModIndex> _index;
    boost::optional<mongo::BSONObj> _validator;
    boost::optional<mongo::ValidationLevelEnum> _validationLevel;
    boost::optional<mongo::ValidationActionEnum> _validationAction;
    boost::optional<std::string> _viewOn;
    boost::optional<std::vector<mongo::BSONObj>> _pipeline;
    boost::optional<bool> _recordPreImages;
    boost::optional<stdx::variant<std::string, std::int64_t>> _expireAfterSeconds;
    boost::optional<mongo::CollModTimeseries> _timeseries;
    boost::optional<bool> _isTimeseriesNamespace;
    std::string _dbName;
    bool _hasDbName : 1;
};


template <typename Derived>
class CollModCmdVersion1Gen : public TypedCommand<Derived> {
    using _TypedCommandInvocationBase = typename TypedCommand<Derived>::InvocationBase;

public:
    using Request = CollMod;
    using Reply = mongo::CollModReply;

    virtual ~CollModCmdVersion1Gen() = default;

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
    };
};
}  // namespace mongo
