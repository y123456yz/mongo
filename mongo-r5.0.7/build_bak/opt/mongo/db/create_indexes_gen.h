/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/create_indexes_gen.h --output build/opt/mongo/db/create_indexes_gen.cpp src/mongo/db/create_indexes.idl
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
 * Reply to 'createIndexes' command
 */
class CreateIndexesReply {
public:
    static constexpr auto kCommitQuorumFieldName = "commitQuorum"_sd;
    static constexpr auto kCreatedCollectionAutomaticallyFieldName = "createdCollectionAutomatically"_sd;
    static constexpr auto kNoteFieldName = "note"_sd;
    static constexpr auto kNumIndexesAfterFieldName = "numIndexesAfter"_sd;
    static constexpr auto kNumIndexesBeforeFieldName = "numIndexesBefore"_sd;

    CreateIndexesReply();

    static CreateIndexesReply parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Index count before create
     */
    const boost::optional<std::int32_t> getNumIndexesBefore() const& { return _numIndexesBefore; }
    void getNumIndexesBefore() && = delete;
    void setNumIndexesBefore(boost::optional<std::int32_t> value) & {  _numIndexesBefore = std::move(value);  }

    /**
     * Index count after create
     */
    const boost::optional<std::int32_t> getNumIndexesAfter() const& { return _numIndexesAfter; }
    void getNumIndexesAfter() && = delete;
    void setNumIndexesAfter(boost::optional<std::int32_t> value) & {  _numIndexesAfter = std::move(value);  }

    /**
     * Whether or not this createIndexes command resulted in a newly created collection.
     */
    const boost::optional<bool> getCreatedCollectionAutomatically() const& { return _createdCollectionAutomatically; }
    void getCreatedCollectionAutomatically() && = delete;
    void setCreatedCollectionAutomatically(boost::optional<bool> value) & {  _createdCollectionAutomatically = std::move(value);  }

    /**
     * Commit Quorum options used
     */
    const boost::optional<mongo::CommitQuorumOptions>& getCommitQuorum() const& { return _commitQuorum; }
    void getCommitQuorum() && = delete;
    void setCommitQuorum(boost::optional<mongo::CommitQuorumOptions> value) & {  _commitQuorum = std::move(value);  }

    /**
     * Optional warning/error related to createIndex
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
    boost::optional<std::int32_t> _numIndexesBefore;
    boost::optional<std::int32_t> _numIndexesAfter;
    boost::optional<bool> _createdCollectionAutomatically;
    boost::optional<mongo::CommitQuorumOptions> _commitQuorum;
    boost::optional<std::string> _note;
};

/**
 * A type representing a spec for a new index
 */
class NewIndexSpec {
public:
    static constexpr auto k2dsphereIndexVersionFieldName = "2dsphereIndexVersion"_sd;
    static constexpr auto kBackgroundFieldName = "background"_sd;
    static constexpr auto kBitsFieldName = "bits"_sd;
    static constexpr auto kBucketSizeFieldName = "bucketSize"_sd;
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
    static constexpr auto kStorageEngineFieldName = "storageEngine"_sd;
    static constexpr auto kTextIndexVersionFieldName = "textIndexVersion"_sd;
    static constexpr auto kUniqueFieldName = "unique"_sd;
    static constexpr auto kVFieldName = "v"_sd;
    static constexpr auto kWeightsFieldName = "weights"_sd;
    static constexpr auto kWildcardProjectionFieldName = "wildcardProjection"_sd;

    NewIndexSpec();
    NewIndexSpec(mongo::BSONObj key, std::string name);

    static NewIndexSpec parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Index spec version
     */
    const boost::optional<std::int32_t> getV() const& { return _v; }
    void getV() && = delete;
    void setV(boost::optional<std::int32_t> value) & {  _v = std::move(value);  }

    /**
     * Key to index on
     */
    const mongo::BSONObj& getKey() const { return _key; }
    void setKey(mongo::BSONObj value) & {  _key = std::move(value); _hasKey = true; }

    /**
     * Descriptive name for the index
     */
    const StringData getName() const& { return _name; }
    void getName() && = delete;
    void setName(StringData value) & { auto _tmpValue = value.toString();  _name = std::move(_tmpValue); _hasName = true; }

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

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    boost::optional<std::int32_t> _v;
    mongo::BSONObj _key;
    std::string _name;
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
    bool _hasKey : 1;
    bool _hasName : 1;
};

/**
 * Command for creating indexes on a collection
 */
class CreateIndexesCommand {
public:
    using Reply = mongo::CreateIndexesReply;
    static constexpr auto kCommitQuorumFieldName = "commitQuorum"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kIgnoreUnknownIndexOptionsFieldName = "ignoreUnknownIndexOptions"_sd;
    static constexpr auto kIndexesFieldName = "indexes"_sd;
    static constexpr auto kIsTimeseriesNamespaceFieldName = "isTimeseriesNamespace"_sd;
    static constexpr auto kVFieldName = "v"_sd;
    static constexpr auto kCommandName = "createIndexes"_sd;

    static AuthorizationContract kAuthorizationContract;

    explicit CreateIndexesCommand(const NamespaceString nss);
    CreateIndexesCommand(const NamespaceString nss, std::vector<mongo::BSONObj> indexes);

    static CreateIndexesCommand parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static CreateIndexesCommand parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const NamespaceString& getNamespace() const { return _nss; }

    /**
     * Index schema version
     */
    std::int32_t getV() const { return _v; }
    void setV(std::int32_t value) & {  _v = std::move(value);  }

    /**
     * Indexes to be created
     */
    const std::vector<mongo::BSONObj>& getIndexes() const& { return _indexes; }
    void getIndexes() && = delete;
    void setIndexes(std::vector<mongo::BSONObj> value) & {  _indexes = std::move(value); _hasIndexes = true; }

    /**
     * Ignore unknown options in index spec
     */
    bool getIgnoreUnknownIndexOptions() const { return _ignoreUnknownIndexOptions; }
    void setIgnoreUnknownIndexOptions(bool value) & {  _ignoreUnknownIndexOptions = std::move(value);  }

    /**
     * Commit Quorum options
     */
    const boost::optional<mongo::CommitQuorumOptions>& getCommitQuorum() const& { return _commitQuorum; }
    void getCommitQuorum() && = delete;
    void setCommitQuorum(boost::optional<mongo::CommitQuorumOptions> value) & {  _commitQuorum = std::move(value);  }

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


    NamespaceString _nss;

    std::int32_t _v{2};
    std::vector<mongo::BSONObj> _indexes;
    bool _ignoreUnknownIndexOptions{false};
    boost::optional<mongo::CommitQuorumOptions> _commitQuorum;
    boost::optional<bool> _isTimeseriesNamespace;
    std::string _dbName;
    bool _hasIndexes : 1;
    bool _hasDbName : 1;
};


template <typename Derived>
class CreateIndexesCmdVersion1Gen : public TypedCommand<Derived> {
    using _TypedCommandInvocationBase = typename TypedCommand<Derived>::InvocationBase;

public:
    using Request = CreateIndexesCommand;
    using Reply = mongo::CreateIndexesReply;

    virtual ~CreateIndexesCmdVersion1Gen() = default;

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
