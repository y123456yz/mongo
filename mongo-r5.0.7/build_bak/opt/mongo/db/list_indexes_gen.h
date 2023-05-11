/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/list_indexes_gen.h --output build/opt/mongo/db/list_indexes_gen.cpp src/mongo/db/list_indexes.idl
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
#include "mongo/db/catalog/commit_quorum_options.h"
#include "mongo/db/commands.h"
#include "mongo/db/create_indexes_gen.h"
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
 * An item in the listIndexes command's reply
 */
class ListIndexesReplyItem {
public:
    static constexpr auto k2dsphereIndexVersionFieldName = "2dsphereIndexVersion"_sd;
    static constexpr auto kBackgroundFieldName = "background"_sd;
    static constexpr auto kBitsFieldName = "bits"_sd;
    static constexpr auto kBucketSizeFieldName = "bucketSize"_sd;
    static constexpr auto kBuildUUIDFieldName = "buildUUID"_sd;
    static constexpr auto kCoarsestIndexedLevelFieldName = "coarsestIndexedLevel"_sd;
    static constexpr auto kCollationFieldName = "collation"_sd;
    static constexpr auto kDefault_languageFieldName = "default_language"_sd;
    static constexpr auto kDropDupsFieldName = "dropDups"_sd;
    static constexpr auto kExpireAfterSecondsFieldName = "expireAfterSeconds"_sd;
    static constexpr auto kFinestIndexedLevelFieldName = "finestIndexedLevel"_sd;
    static constexpr auto kHiddenFieldName = "hidden"_sd;
    static constexpr auto kKeyFieldName = "key"_sd;
    static constexpr auto kLanguage_overrideFieldName = "language_override"_sd;
    static constexpr auto kMaxFieldName = "max"_sd;
    static constexpr auto kMinFieldName = "min"_sd;
    static constexpr auto kNameFieldName = "name"_sd;
    static constexpr auto kNsFieldName = "ns"_sd;
    static constexpr auto kPartialFilterExpressionFieldName = "partialFilterExpression"_sd;
    static constexpr auto kSparseFieldName = "sparse"_sd;
    static constexpr auto kSpecFieldName = "spec"_sd;
    static constexpr auto kStorageEngineFieldName = "storageEngine"_sd;
    static constexpr auto kTextIndexVersionFieldName = "textIndexVersion"_sd;
    static constexpr auto kUniqueFieldName = "unique"_sd;
    static constexpr auto kVFieldName = "v"_sd;
    static constexpr auto kWeightsFieldName = "weights"_sd;
    static constexpr auto kWildcardProjectionFieldName = "wildcardProjection"_sd;

    ListIndexesReplyItem();

    static ListIndexesReplyItem parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    const boost::optional<std::int32_t> getV() const& { return _v; }
    void getV() && = delete;
    void setV(boost::optional<std::int32_t> value) & {  _v = std::move(value);  }

    const boost::optional<mongo::BSONObj>& getKey() const& { return _key; }
    void getKey() && = delete;
    void setKey(boost::optional<mongo::BSONObj> value) & {  _key = std::move(value);  }

    const boost::optional<StringData> getName() const& { return boost::optional<StringData>{_name}; }
    void getName() && = delete;
    void setName(boost::optional<StringData> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get().toString();
        
        _name = std::move(_tmpValue);
    } else {
        _name = boost::none;
    }
      }

    const boost::optional<bool> getBackground() const& { return _background; }
    void getBackground() && = delete;
    void setBackground(boost::optional<bool> value) & {  _background = std::move(value);  }

    const boost::optional<bool> getUnique() const& { return _unique; }
    void getUnique() && = delete;
    void setUnique(boost::optional<bool> value) & {  _unique = std::move(value);  }

    const boost::optional<bool> getHidden() const& { return _hidden; }
    void getHidden() && = delete;
    void setHidden(boost::optional<bool> value) & {  _hidden = std::move(value);  }

    const boost::optional<mongo::BSONObj>& getPartialFilterExpression() const& { return _partialFilterExpression; }
    void getPartialFilterExpression() && = delete;
    void setPartialFilterExpression(boost::optional<mongo::BSONObj> value) & {  _partialFilterExpression = std::move(value);  }

    const boost::optional<bool> getSparse() const& { return _sparse; }
    void getSparse() && = delete;
    void setSparse(boost::optional<bool> value) & {  _sparse = std::move(value);  }

    const boost::optional<std::int32_t> getExpireAfterSeconds() const& { return _expireAfterSeconds; }
    void getExpireAfterSeconds() && = delete;
    void setExpireAfterSeconds(boost::optional<std::int32_t> value) & {  _expireAfterSeconds = std::move(value);  }

    const boost::optional<mongo::BSONObj>& getStorageEngine() const& { return _storageEngine; }
    void getStorageEngine() && = delete;
    void setStorageEngine(boost::optional<mongo::BSONObj> value) & {  _storageEngine = std::move(value);  }

    const boost::optional<stdx::variant<std::string, mongo::BSONObj>>& getWeights() const& { return _weights; }
    void getWeights() && = delete;
    void setWeights(boost::optional<stdx::variant<std::string, mongo::BSONObj>> value) & {  _weights = std::move(value);  }

    const boost::optional<StringData> getDefault_language() const& { return boost::optional<StringData>{_default_language}; }
    void getDefault_language() && = delete;
    void setDefault_language(boost::optional<StringData> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get().toString();
        
        _default_language = std::move(_tmpValue);
    } else {
        _default_language = boost::none;
    }
      }

    const boost::optional<StringData> getLanguage_override() const& { return boost::optional<StringData>{_language_override}; }
    void getLanguage_override() && = delete;
    void setLanguage_override(boost::optional<StringData> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get().toString();
        
        _language_override = std::move(_tmpValue);
    } else {
        _language_override = boost::none;
    }
      }

    const boost::optional<std::int32_t> getTextIndexVersion() const& { return _textIndexVersion; }
    void getTextIndexVersion() && = delete;
    void setTextIndexVersion(boost::optional<std::int32_t> value) & {  _textIndexVersion = std::move(value);  }

    const boost::optional<std::int32_t> get2dsphereIndexVersion() const& { return _2dsphereIndexVersion; }
    void get2dsphereIndexVersion() && = delete;
    void set2dsphereIndexVersion(boost::optional<std::int32_t> value) & {  _2dsphereIndexVersion = std::move(value);  }

    const boost::optional<std::int32_t> getBits() const& { return _bits; }
    void getBits() && = delete;
    void setBits(boost::optional<std::int32_t> value) & {  _bits = std::move(value);  }

    const boost::optional<double> getMin() const& { return _min; }
    void getMin() && = delete;
    void setMin(boost::optional<double> value) & {  _min = std::move(value);  }

    const boost::optional<double> getMax() const& { return _max; }
    void getMax() && = delete;
    void setMax(boost::optional<double> value) & {  _max = std::move(value);  }

    const boost::optional<double> getBucketSize() const& { return _bucketSize; }
    void getBucketSize() && = delete;
    void setBucketSize(boost::optional<double> value) & {  _bucketSize = std::move(value);  }

    const boost::optional<mongo::BSONObj>& getCollation() const& { return _collation; }
    void getCollation() && = delete;
    void setCollation(boost::optional<mongo::BSONObj> value) & {  _collation = std::move(value);  }

    const boost::optional<mongo::BSONObj>& getWildcardProjection() const& { return _wildcardProjection; }
    void getWildcardProjection() && = delete;
    void setWildcardProjection(boost::optional<mongo::BSONObj> value) & {  _wildcardProjection = std::move(value);  }

    const boost::optional<std::int32_t> getCoarsestIndexedLevel() const& { return _coarsestIndexedLevel; }
    void getCoarsestIndexedLevel() && = delete;
    void setCoarsestIndexedLevel(boost::optional<std::int32_t> value) & {  _coarsestIndexedLevel = std::move(value);  }

    const boost::optional<std::int32_t> getFinestIndexedLevel() const& { return _finestIndexedLevel; }
    void getFinestIndexedLevel() && = delete;
    void setFinestIndexedLevel(boost::optional<std::int32_t> value) & {  _finestIndexedLevel = std::move(value);  }

    const boost::optional<bool> getDropDups() const& { return _dropDups; }
    void getDropDups() && = delete;
    void setDropDups(boost::optional<bool> value) & {  _dropDups = std::move(value);  }

    const boost::optional<mongo::UUID>& getBuildUUID() const& { return _buildUUID; }
    void getBuildUUID() && = delete;
    void setBuildUUID(boost::optional<mongo::UUID> value) & {  _buildUUID = std::move(value);  }

    const boost::optional<mongo::NewIndexSpec>& getSpec() const& { return _spec; }
    void getSpec() && = delete;
    void setSpec(boost::optional<mongo::NewIndexSpec> value) & {  _spec = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    boost::optional<std::int32_t> _v;
    boost::optional<mongo::BSONObj> _key;
    boost::optional<std::string> _name;
    boost::optional<bool> _background;
    boost::optional<bool> _unique;
    boost::optional<bool> _hidden;
    boost::optional<mongo::BSONObj> _partialFilterExpression;
    boost::optional<bool> _sparse;
    boost::optional<std::int32_t> _expireAfterSeconds;
    boost::optional<mongo::BSONObj> _storageEngine;
    boost::optional<stdx::variant<std::string, mongo::BSONObj>> _weights;
    boost::optional<std::string> _default_language;
    boost::optional<std::string> _language_override;
    boost::optional<std::int32_t> _textIndexVersion;
    boost::optional<std::int32_t> _2dsphereIndexVersion;
    boost::optional<std::int32_t> _bits;
    boost::optional<double> _min;
    boost::optional<double> _max;
    boost::optional<double> _bucketSize;
    boost::optional<mongo::BSONObj> _collation;
    boost::optional<mongo::BSONObj> _wildcardProjection;
    boost::optional<std::int32_t> _coarsestIndexedLevel;
    boost::optional<std::int32_t> _finestIndexedLevel;
    boost::optional<bool> _dropDups;
    boost::optional<mongo::UUID> _buildUUID;
    boost::optional<mongo::NewIndexSpec> _spec;
};

/**
 * Cursor object
 */
class ListIndexesReplyCursor {
public:
    static constexpr auto kFirstBatchFieldName = "firstBatch"_sd;
    static constexpr auto kIdFieldName = "id"_sd;
    static constexpr auto kNsFieldName = "ns"_sd;

    ListIndexesReplyCursor();
    ListIndexesReplyCursor(std::int64_t id, mongo::NamespaceString ns, std::vector<mongo::ListIndexesReplyItem> firstBatch);

    static ListIndexesReplyCursor parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    std::int64_t getId() const { return _id; }
    void setId(std::int64_t value) & {  _id = std::move(value); _hasId = true; }

    const mongo::NamespaceString& getNs() const { return _ns; }
    void setNs(mongo::NamespaceString value) & {  _ns = std::move(value); _hasNs = true; }

    const std::vector<mongo::ListIndexesReplyItem>& getFirstBatch() const& { return _firstBatch; }
    void getFirstBatch() && = delete;
    void setFirstBatch(std::vector<mongo::ListIndexesReplyItem> value) & {  _firstBatch = std::move(value); _hasFirstBatch = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    std::int64_t _id;
    mongo::NamespaceString _ns;
    std::vector<mongo::ListIndexesReplyItem> _firstBatch;
    bool _hasId : 1;
    bool _hasNs : 1;
    bool _hasFirstBatch : 1;
};

/**
 * The listIndexes command's reply.
 */
class ListIndexesReply {
public:
    static constexpr auto kCursorFieldName = "cursor"_sd;
    static constexpr auto kOkFieldName = "ok"_sd;

    ListIndexesReply();
    ListIndexesReply(mongo::ListIndexesReplyCursor cursor);

    static ListIndexesReply parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    const mongo::ListIndexesReplyCursor& getCursor() const { return _cursor; }
    mongo::ListIndexesReplyCursor& getCursor() { return _cursor; }
    void setCursor(mongo::ListIndexesReplyCursor value) & {  _cursor = std::move(value); _hasCursor = true; }

    const boost::optional<double> getOk() const& { return _ok; }
    void getOk() && = delete;
    void setOk(boost::optional<double> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get();
        validateOk(_tmpValue);
        _ok = std::move(_tmpValue);
    } else {
        _ok = boost::none;
    }
      }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    void validateOk(const double value);
    void validateOk(IDLParserErrorContext& ctxt, const double value);

private:
    mongo::ListIndexesReplyCursor _cursor;
    boost::optional<double> _ok;
    bool _hasCursor : 1;
};

/**
 * Parser for the listIndexes command
 */
class ListIndexes {
public:
    using Reply = mongo::ListIndexesReply;
    static constexpr auto kCursorFieldName = "cursor"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kIncludeBuildUUIDsFieldName = "includeBuildUUIDs"_sd;
    static constexpr auto kIsTimeseriesNamespaceFieldName = "isTimeseriesNamespace"_sd;
    static constexpr auto kCommandName = "listIndexes"_sd;

    static AuthorizationContract kAuthorizationContract;

    explicit ListIndexes(const NamespaceStringOrUUID nssOrUUID);

    static ListIndexes parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static ListIndexes parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const NamespaceStringOrUUID& getNamespaceOrUUID() const { return _nssOrUUID; }

    const boost::optional<mongo::SimpleCursorOptions>& getCursor() const& { return _cursor; }
    void getCursor() && = delete;
    void setCursor(boost::optional<mongo::SimpleCursorOptions> value) & {  _cursor = std::move(value);  }

    const boost::optional<bool> getIncludeBuildUUIDs() const& { return _includeBuildUUIDs; }
    void getIncludeBuildUUIDs() && = delete;
    void setIncludeBuildUUIDs(boost::optional<bool> value) & {  _includeBuildUUIDs = std::move(value);  }

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
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;


    NamespaceStringOrUUID _nssOrUUID;

    boost::optional<mongo::SimpleCursorOptions> _cursor;
    boost::optional<bool> _includeBuildUUIDs;
    boost::optional<bool> _isTimeseriesNamespace;
    std::string _dbName;
    bool _hasDbName : 1;
};


template <typename Derived>
class ListIndexesCmdVersion1Gen : public TypedCommand<Derived> {
    using _TypedCommandInvocationBase = typename TypedCommand<Derived>::InvocationBase;

public:
    using Request = ListIndexes;
    using Reply = mongo::ListIndexesReply;

    virtual ~ListIndexesCmdVersion1Gen() = default;

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
