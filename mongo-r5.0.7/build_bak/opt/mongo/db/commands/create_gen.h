/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/commands/create_gen.h --output build/opt/mongo/db/commands/create_gen.cpp src/mongo/db/commands/create.idl
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
#include "mongo/idl/idl_parser.h"
#include "mongo/rpc/op_msg.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/util/uuid.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {

/**
 * Reply from the {create: ...} command
 */
class CreateCommandReply {
public:
    static constexpr auto kNoteFieldName = "note"_sd;

    CreateCommandReply();

    static CreateCommandReply parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Warnings or other additional information
     */
    const boost::optional<StringData> getNote() const& { return boost::optional<StringData>{_note}; }
    void getNote() && = delete;
    void setNote(boost::optional<StringData> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get().toString();
        
        _note = std::move(_tmpValue);
    } else {
        _note = boost::none;
    }
      }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    boost::optional<std::string> _note;
};

/**
 * Parser for the 'create' Command
 */
class CreateCommand {
public:
    using Reply = mongo::CreateCommandReply;
    static constexpr auto kAutoIndexIdFieldName = "autoIndexId"_sd;
    static constexpr auto kCappedFieldName = "capped"_sd;
    static constexpr auto kClusteredIndexFieldName = "clusteredIndex"_sd;
    static constexpr auto kCollationFieldName = "collation"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kExpireAfterSecondsFieldName = "expireAfterSeconds"_sd;
    static constexpr auto kFlagsFieldName = "flags"_sd;
    static constexpr auto kIdIndexFieldName = "idIndex"_sd;
    static constexpr auto kIndexOptionDefaultsFieldName = "indexOptionDefaults"_sd;
    static constexpr auto kMaxFieldName = "max"_sd;
    static constexpr auto kPipelineFieldName = "pipeline"_sd;
    static constexpr auto kRecordPreImagesFieldName = "recordPreImages"_sd;
    static constexpr auto kSizeFieldName = "size"_sd;
    static constexpr auto kStorageEngineFieldName = "storageEngine"_sd;
    static constexpr auto kTempFieldName = "temp"_sd;
    static constexpr auto kTimeseriesFieldName = "timeseries"_sd;
    static constexpr auto kValidationActionFieldName = "validationAction"_sd;
    static constexpr auto kValidationLevelFieldName = "validationLevel"_sd;
    static constexpr auto kValidatorFieldName = "validator"_sd;
    static constexpr auto kViewOnFieldName = "viewOn"_sd;
    static constexpr auto kCommandName = "create"_sd;

    static AuthorizationContract kAuthorizationContract;

    explicit CreateCommand(const NamespaceString nss);

    static CreateCommand parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static CreateCommand parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const NamespaceString& getNamespace() const { return _nss; }

    /**
     * Specify true to create a capped collection. If you specify true, you must also set a maximum size in the 'size' field.
     */
    bool getCapped() const { return _capped; }
    void setCapped(bool value) & {  _capped = std::move(value);  }

    /**
     * Specify false to disable the automatic creation of an index on the _id field.
     */
    const boost::optional<bool> getAutoIndexId() const& { return _autoIndexId; }
    void getAutoIndexId() && = delete;
    void setAutoIndexId(boost::optional<bool> value) & {  _autoIndexId = std::move(value);  }

    /**
     * Specify the default _id index specification.
     */
    const boost::optional<mongo::BSONObj>& getIdIndex() const& { return _idIndex; }
    void getIdIndex() && = delete;
    void setIdIndex(boost::optional<mongo::BSONObj> value) & {  _idIndex = std::move(value);  }

    /**
     * Specify a maximum size in bytes for the capped collection.
     */
    const boost::optional<std::int64_t> getSize() const& { return _size; }
    void getSize() && = delete;
    void setSize(boost::optional<std::int64_t> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get();
        validateSize(_tmpValue);
        _size = std::move(_tmpValue);
    } else {
        _size = boost::none;
    }
      }

    /**
     * The maximum number of documents allowed in the capped collection. The 'size' limit takes precedence over this limit.
     */
    const boost::optional<std::int64_t> getMax() const& { return _max; }
    void getMax() && = delete;
    void setMax(boost::optional<std::int64_t> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get();
        validateMax(_tmpValue);
        _max = std::move(_tmpValue);
    } else {
        _max = boost::none;
    }
      }

    /**
     * Specify a configuration to the storage engine on a per-collection basis when creating a collection.
     */
    const boost::optional<mongo::BSONObj>& getStorageEngine() const& { return _storageEngine; }
    void getStorageEngine() && = delete;
    void setStorageEngine(boost::optional<mongo::BSONObj> value) & {  _storageEngine = std::move(value);  }

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
     * Allows users to specify a default configuration for indexes when creating a collection.
     */
    const boost::optional<mongo::IndexOptionDefaults>& getIndexOptionDefaults() const& { return _indexOptionDefaults; }
    void getIndexOptionDefaults() && = delete;
    void setIndexOptionDefaults(boost::optional<mongo::IndexOptionDefaults> value) & {  _indexOptionDefaults = std::move(value);  }

    /**
     * The name of the source collection or view from which to create the view.
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
     * An array that consists of the aggregation pipeline. Creates the view by applying the specified pipeline to the 'viewOn' collection or view.
     */
    const boost::optional<std::vector<mongo::BSONObj>>& getPipeline() const& { return _pipeline; }
    void getPipeline() && = delete;
    void setPipeline(boost::optional<std::vector<mongo::BSONObj>> value) & {  _pipeline = std::move(value);  }

    /**
     * Specifies the default collation for the collection or the view.
     */
    const boost::optional<mongo::Collation>& getCollation() const& { return _collation; }
    void getCollation() && = delete;
    void setCollation(boost::optional<mongo::Collation> value) & {  _collation = std::move(value);  }

    /**
     * Sets whether updates/deletes should store the pre-image of the document in the oplog
     */
    const boost::optional<bool> getRecordPreImages() const& { return _recordPreImages; }
    void getRecordPreImages() && = delete;
    void setRecordPreImages(boost::optional<bool> value) & {  _recordPreImages = std::move(value);  }

    /**
     * The options to create the time-series collection with.
     */
    const boost::optional<mongo::TimeseriesOptions>& getTimeseries() const& { return _timeseries; }
    void getTimeseries() && = delete;
    void setTimeseries(boost::optional<mongo::TimeseriesOptions> value) & {  _timeseries = std::move(value);  }

    /**
     * Specifies whether this collection should be clustered on _id.
     */
    const boost::optional<bool> getClusteredIndex() const& { return _clusteredIndex; }
    void getClusteredIndex() && = delete;
    void setClusteredIndex(boost::optional<bool> value) & {  _clusteredIndex = std::move(value);  }

    /**
     * The number of seconds after which old data should be deleted.
     */
    const boost::optional<std::int64_t> getExpireAfterSeconds() const& { return _expireAfterSeconds; }
    void getExpireAfterSeconds() && = delete;
    void setExpireAfterSeconds(boost::optional<std::int64_t> value) & {  _expireAfterSeconds = std::move(value);  }

    /**
     * DEPRECATED
     */
    const boost::optional<bool> getTemp() const& { return _temp; }
    void getTemp() && = delete;
    void setTemp(boost::optional<bool> value) & {  _temp = std::move(value);  }

    /**
     * DEPRECATED
     */
    const boost::optional<std::int64_t> getFlags() const& { return _flags; }
    void getFlags() && = delete;
    void setFlags(boost::optional<std::int64_t> value) & {  _flags = std::move(value);  }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    void validateSize(const std::int64_t value);
    void validateSize(IDLParserErrorContext& ctxt, const std::int64_t value);

    void validateMax(const std::int64_t value);
    void validateMax(IDLParserErrorContext& ctxt, const std::int64_t value);

    void validateViewOn(const std::string& value);
    void validateViewOn(IDLParserErrorContext& ctxt, const std::string& value);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;


    NamespaceString _nss;

    bool _capped{false};
    boost::optional<bool> _autoIndexId;
    boost::optional<mongo::BSONObj> _idIndex;
    boost::optional<std::int64_t> _size;
    boost::optional<std::int64_t> _max;
    boost::optional<mongo::BSONObj> _storageEngine;
    boost::optional<mongo::BSONObj> _validator;
    boost::optional<mongo::ValidationLevelEnum> _validationLevel;
    boost::optional<mongo::ValidationActionEnum> _validationAction;
    boost::optional<mongo::IndexOptionDefaults> _indexOptionDefaults;
    boost::optional<std::string> _viewOn;
    boost::optional<std::vector<mongo::BSONObj>> _pipeline;
    boost::optional<mongo::Collation> _collation;
    boost::optional<bool> _recordPreImages;
    boost::optional<mongo::TimeseriesOptions> _timeseries;
    boost::optional<bool> _clusteredIndex;
    boost::optional<std::int64_t> _expireAfterSeconds;
    boost::optional<bool> _temp;
    boost::optional<std::int64_t> _flags;
    std::string _dbName;
    bool _hasDbName : 1;
};


template <typename Derived>
class CreateCmdVersion1Gen : public TypedCommand<Derived> {
    using _TypedCommandInvocationBase = typename TypedCommand<Derived>::InvocationBase;

public:
    using Request = CreateCommand;
    using Reply = mongo::CreateCommandReply;

    virtual ~CreateCmdVersion1Gen() = default;

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
