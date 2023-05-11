/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/pipeline/document_source_change_stream_gen.h --output build/opt/mongo/db/pipeline/document_source_change_stream_gen.cpp src/mongo/db/pipeline/document_source_change_stream.idl
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
#include "mongo/db/pipeline/resume_token.h"
#include "mongo/idl/basic_types.h"
#include "mongo/idl/basic_types_gen.h"
#include "mongo/idl/idl_parser.h"
#include "mongo/rpc/op_msg.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/util/uuid.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {

/**
 * Possible modes for the 'fullDocumentBeforeChange' parameter of the $changeStream stage.
 */
enum class FullDocumentBeforeChangeModeEnum : std::int32_t {
    kOff ,
    kWhenAvailable ,
    kRequired ,
};
static constexpr uint32_t kNumFullDocumentBeforeChangeModeEnum = 3;

FullDocumentBeforeChangeModeEnum FullDocumentBeforeChangeMode_parse(const IDLParserErrorContext& ctxt, StringData value);
StringData FullDocumentBeforeChangeMode_serializer(FullDocumentBeforeChangeModeEnum value);

/**
 * Possible modes for the 'fullDocument' parameter of the $changeStream stage.
 */
enum class FullDocumentModeEnum : std::int32_t {
    kUpdateLookup ,
    kDefault ,
};
static constexpr uint32_t kNumFullDocumentModeEnum = 2;

FullDocumentModeEnum FullDocumentMode_parse(const IDLParserErrorContext& ctxt, StringData value);
StringData FullDocumentMode_serializer(FullDocumentModeEnum value);

/**
 * The IDL type of cluster time
 */
class ResumeTokenClusterTime {
public:
    static constexpr auto kTimestampFieldName = "ts"_sd;

    ResumeTokenClusterTime();
    ResumeTokenClusterTime(mongo::Timestamp timestamp);

    static ResumeTokenClusterTime parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * The timestamp of the logical time
     */
    const mongo::Timestamp& getTimestamp() const { return _timestamp; }
    void setTimestamp(mongo::Timestamp value) & {  _timestamp = std::move(value); _hasTimestamp = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::Timestamp _timestamp;
    bool _hasTimestamp : 1;
};

/**
 * A document used to specify the $changeStream stage of an aggregation pipeline. The same spec is also used by the $_internalChangeStreamTransform stage.
 */
class DocumentSourceChangeStreamSpec {
public:
    static constexpr auto kAllChangesForClusterFieldName = "allChangesForCluster"_sd;
    static constexpr auto kAllowToRunOnConfigDBFieldName = "allowToRunOnConfigDB"_sd;
    static constexpr auto kAllowToRunOnSystemNSFieldName = "allowToRunOnSystemNS"_sd;
    static constexpr auto kFullDocumentFieldName = "fullDocument"_sd;
    static constexpr auto kFullDocumentBeforeChangeFieldName = "fullDocumentBeforeChange"_sd;
    static constexpr auto kResumeAfterFieldName = "resumeAfter"_sd;
    static constexpr auto kShowMigrationEventsFieldName = "showMigrationEvents"_sd;
    static constexpr auto kStartAfterFieldName = "startAfter"_sd;
    static constexpr auto kStartAtOperationTimeFieldName = "startAtOperationTime"_sd;

    DocumentSourceChangeStreamSpec();

    static DocumentSourceChangeStreamSpec parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * An object representing the point at which we should resume reporting changes from. Only one of resumeAfter, startAfter, and startAtOperationTime should be specified.
     */
    const boost::optional<mongo::ResumeToken>& getResumeAfter() const& { return _resumeAfter; }
    void getResumeAfter() && = delete;
    void setResumeAfter(boost::optional<mongo::ResumeToken> value) & {  _resumeAfter = std::move(value);  }

    /**
     * An object representing the point at which we should start reporting changes from. This is allowed to be a token from an invalidating command. Only one of resumeAfter, startAfter, and startAtOperationTime should be specified.
     */
    const boost::optional<mongo::ResumeToken>& getStartAfter() const& { return _startAfter; }
    void getStartAfter() && = delete;
    void setStartAfter(boost::optional<mongo::ResumeToken> value) & {  _startAfter = std::move(value);  }

    /**
     * The operation time after which we should start reporting changes. Only one of resumeAfter, startAfter, and startAtOperationTime should be specified.
     */
    const boost::optional<mongo::Timestamp>& getStartAtOperationTime() const& { return _startAtOperationTime; }
    void getStartAtOperationTime() && = delete;
    void setStartAtOperationTime(boost::optional<mongo::Timestamp> value) & {  _startAtOperationTime = std::move(value);  }

    /**
     * A string '"updateLookup"' or '"default"', indicating whether or not we should return a full document or just changes for an update.
     */
    mongo::FullDocumentModeEnum getFullDocument() const { return _fullDocument; }
    void setFullDocument(mongo::FullDocumentModeEnum value) & {  _fullDocument = std::move(value);  }

    /**
     * Valid values are "off", "whenAvailable", or "required". If set to "off", the "fullDocumentBeforeChange" field of the output document is always omitted. If set to "whenAvailable", the "fullDocumentBeforeChange" field will be populated with the pre-image of the document modified by the current change event if such a pre-image is available, and will be omitted otherwise. If set to "required", then the "fullDocumentBeforeChange" field is always populated and an exception is thrown if the pre-image is not available.
     */
    mongo::FullDocumentBeforeChangeModeEnum getFullDocumentBeforeChange() const { return _fullDocumentBeforeChange; }
    void setFullDocumentBeforeChange(mongo::FullDocumentBeforeChangeModeEnum value) & {  _fullDocumentBeforeChange = std::move(value);  }

    /**
     * A flag indicating whether the stream should report all changes that occur on the deployment, aside from those on internal databases or collections.
     */
    const mongo::OptionalBool& getAllChangesForCluster() const { return _allChangesForCluster; }
    void setAllChangesForCluster(mongo::OptionalBool value) & {  _allChangesForCluster = std::move(value);  }

    /**
     * A flag indicating whether the stream should report changes that occur on the deployment that are related to chunk migrations. These operations are reported like normal events. For example, inserts and deletes may appear that do not reflect actual deletions or insertions of data. Instead they reflect this data moving from one shard to another.
     */
    const mongo::OptionalBool& getShowMigrationEvents() const { return _showMigrationEvents; }
    void setShowMigrationEvents(mongo::OptionalBool value) & {  _showMigrationEvents = std::move(value);  }

    /**
     * A flag indicating whether the change stream may be opened on the 'config' database, which is usually banned. This flag is used internally to allow mongoS to open a stream on 'config.shards', in order to monitor for the addition of new shards to the cluster.
     */
    const mongo::OptionalBool& getAllowToRunOnConfigDB() const { return _allowToRunOnConfigDB; }
    void setAllowToRunOnConfigDB(mongo::OptionalBool value) & {  _allowToRunOnConfigDB = std::move(value);  }

    /**
     * An internal flag indicating whether the change stream may be opened on a system collection.
     */
    const mongo::OptionalBool& getAllowToRunOnSystemNS() const { return _allowToRunOnSystemNS; }
    void setAllowToRunOnSystemNS(mongo::OptionalBool value) & {  _allowToRunOnSystemNS = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    boost::optional<mongo::ResumeToken> _resumeAfter;
    boost::optional<mongo::ResumeToken> _startAfter;
    boost::optional<mongo::Timestamp> _startAtOperationTime;
    mongo::FullDocumentModeEnum _fullDocument{mongo::FullDocumentModeEnum::kDefault};
    mongo::FullDocumentBeforeChangeModeEnum _fullDocumentBeforeChange{mongo::FullDocumentBeforeChangeModeEnum::kOff};
    mongo::OptionalBool _allChangesForCluster{mongo::OptionalBool()};
    mongo::OptionalBool _showMigrationEvents{mongo::OptionalBool()};
    mongo::OptionalBool _allowToRunOnConfigDB{mongo::OptionalBool()};
    mongo::OptionalBool _allowToRunOnSystemNS{mongo::OptionalBool()};
};

/**
 * A document used to specify the $_internalChangeStreamOplogMatch stage of an aggregation pipeline.
 */
class DocumentSourceChangeStreamOplogMatchSpec {
public:
    static constexpr auto kFilterFieldName = "filter"_sd;

    DocumentSourceChangeStreamOplogMatchSpec();
    DocumentSourceChangeStreamOplogMatchSpec(mongo::BSONObj filter);

    static DocumentSourceChangeStreamOplogMatchSpec parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    const mongo::BSONObj& getFilter() const { return _filter; }
    void setFilter(mongo::BSONObj value) & {  _filter = std::move(value); _hasFilter = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::BSONObj _filter;
    bool _hasFilter : 1;
};

/**
 * A document used to specify the $_internalChangeStreamUnwindTransaction stage of an aggregation pipeline.
 */
class DocumentSourceChangeStreamUnwindTransactionSpec {
public:
    static constexpr auto kNsRegexFieldName = "nsRegex"_sd;

    DocumentSourceChangeStreamUnwindTransactionSpec();
    DocumentSourceChangeStreamUnwindTransactionSpec(std::string nsRegex);

    static DocumentSourceChangeStreamUnwindTransactionSpec parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    const StringData getNsRegex() const& { return _nsRegex; }
    void getNsRegex() && = delete;
    void setNsRegex(StringData value) & { auto _tmpValue = value.toString();  _nsRegex = std::move(_tmpValue); _hasNsRegex = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    std::string _nsRegex;
    bool _hasNsRegex : 1;
};

/**
 * A document used to specify the $_internalChangeStreamCheckInvalidate stage of an aggregation pipeline.
 */
class DocumentSourceChangeStreamCheckInvalidateSpec {
public:
    static constexpr auto kStartAfterInvalidateFieldName = "startAfterInvalidate"_sd;

    DocumentSourceChangeStreamCheckInvalidateSpec();

    static DocumentSourceChangeStreamCheckInvalidateSpec parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    const boost::optional<mongo::ResumeToken>& getStartAfterInvalidate() const& { return _startAfterInvalidate; }
    void getStartAfterInvalidate() && = delete;
    void setStartAfterInvalidate(boost::optional<mongo::ResumeToken> value) & {  _startAfterInvalidate = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    boost::optional<mongo::ResumeToken> _startAfterInvalidate;
};

/**
 * A document used to specify the $_internalChangeStreamCheckResumability stage of an aggregation pipeline.
 */
class DocumentSourceChangeStreamCheckResumabilitySpec {
public:
    static constexpr auto kResumeTokenFieldName = "resumeToken"_sd;

    DocumentSourceChangeStreamCheckResumabilitySpec();
    DocumentSourceChangeStreamCheckResumabilitySpec(mongo::ResumeToken resumeToken);

    static DocumentSourceChangeStreamCheckResumabilitySpec parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    const mongo::ResumeToken& getResumeToken() const { return _resumeToken; }
    void setResumeToken(mongo::ResumeToken value) & {  _resumeToken = std::move(value); _hasResumeToken = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::ResumeToken _resumeToken;
    bool _hasResumeToken : 1;
};

/**
 * A document used to specify the $_internalChangeStreamLookupPreImage stage of an aggregation pipeline.
 */
class DocumentSourceChangeStreamLookUpPreImageSpec {
public:
    static constexpr auto kFullDocumentBeforeChangeFieldName = "fullDocumentBeforeChange"_sd;

    DocumentSourceChangeStreamLookUpPreImageSpec();
    DocumentSourceChangeStreamLookUpPreImageSpec(mongo::FullDocumentBeforeChangeModeEnum fullDocumentBeforeChange);

    static DocumentSourceChangeStreamLookUpPreImageSpec parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    mongo::FullDocumentBeforeChangeModeEnum getFullDocumentBeforeChange() const { return _fullDocumentBeforeChange; }
    void setFullDocumentBeforeChange(mongo::FullDocumentBeforeChangeModeEnum value) & {  _fullDocumentBeforeChange = std::move(value); _hasFullDocumentBeforeChange = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::FullDocumentBeforeChangeModeEnum _fullDocumentBeforeChange;
    bool _hasFullDocumentBeforeChange : 1;
};

/**
 * A document used to specify the $_internalChangeStreamLookupPostImage stage of an aggregation pipeline.
 */
class DocumentSourceChangeStreamLookUpPostImageSpec {
public:
    static constexpr auto kFullDocumentFieldName = "fullDocument"_sd;

    DocumentSourceChangeStreamLookUpPostImageSpec();
    DocumentSourceChangeStreamLookUpPostImageSpec(mongo::FullDocumentModeEnum fullDocument);

    static DocumentSourceChangeStreamLookUpPostImageSpec parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    mongo::FullDocumentModeEnum getFullDocument() const { return _fullDocument; }
    void setFullDocument(mongo::FullDocumentModeEnum value) & {  _fullDocument = std::move(value); _hasFullDocument = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::FullDocumentModeEnum _fullDocument;
    bool _hasFullDocument : 1;
};

}  // namespace mongo
