/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/list_collections_gen.h --output build/opt/mongo/db/list_collections_gen.cpp src/mongo/db/list_collections.idl
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
 * Information about the collection.
 */
class ListCollectionsReplyInfo {
public:
    static constexpr auto kReadOnlyFieldName = "readOnly"_sd;
    static constexpr auto kUuidFieldName = "uuid"_sd;

    ListCollectionsReplyInfo();

    static ListCollectionsReplyInfo parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * If true, the data store is read only.
     */
    const boost::optional<bool> getReadOnly() const& { return _readOnly; }
    void getReadOnly() && = delete;
    void setReadOnly(boost::optional<bool> value) & {  _readOnly = std::move(value);  }

    /**
     * Unique, immutable collection ID.
     */
    const boost::optional<mongo::UUID>& getUuid() const& { return _uuid; }
    void getUuid() && = delete;
    void setUuid(boost::optional<mongo::UUID> value) & {  _uuid = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    boost::optional<bool> _readOnly;
    boost::optional<mongo::UUID> _uuid;
};

/**
 * Individual result
 */
class ListCollectionsReplyItem {
public:
    static constexpr auto kIdIndexFieldName = "idIndex"_sd;
    static constexpr auto kInfoFieldName = "info"_sd;
    static constexpr auto kNameFieldName = "name"_sd;
    static constexpr auto kOptionsFieldName = "options"_sd;
    static constexpr auto kTypeFieldName = "type"_sd;

    ListCollectionsReplyItem();
    ListCollectionsReplyItem(std::string name, std::string type);

    static ListCollectionsReplyItem parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Name of the collection.
     */
    const StringData getName() const& { return _name; }
    void getName() && = delete;
    void setName(StringData value) & { auto _tmpValue = value.toString();  _name = std::move(_tmpValue); _hasName = true; }

    /**
     * Type of data store.
     */
    const StringData getType() const& { return _type; }
    void getType() && = delete;
    void setType(StringData value) & { auto _tmpValue = value.toString();  _type = std::move(_tmpValue); _hasType = true; }

    /**
     * Collection options.
     */
    const boost::optional<mongo::BSONObj>& getOptions() const& { return _options; }
    void getOptions() && = delete;
    void setOptions(boost::optional<mongo::BSONObj> value) & {  _options = std::move(value);  }

    /**
     * Information about the collection.
     */
    const boost::optional<mongo::ListCollectionsReplyInfo>& getInfo() const& { return _info; }
    void getInfo() && = delete;
    void setInfo(boost::optional<mongo::ListCollectionsReplyInfo> value) & {  _info = std::move(value);  }

    /**
     * Provides information on the _id index for the collection.
     */
    const boost::optional<mongo::BSONObj>& getIdIndex() const& { return _idIndex; }
    void getIdIndex() && = delete;
    void setIdIndex(boost::optional<mongo::BSONObj> value) & {  _idIndex = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    std::string _name;
    std::string _type;
    boost::optional<mongo::BSONObj> _options;
    boost::optional<mongo::ListCollectionsReplyInfo> _info;
    boost::optional<mongo::BSONObj> _idIndex;
    bool _hasName : 1;
    bool _hasType : 1;
};

/**
 * Cursor object
 */
class ListCollectionsReplyCursor {
public:
    static constexpr auto kFirstBatchFieldName = "firstBatch"_sd;
    static constexpr auto kIdFieldName = "id"_sd;
    static constexpr auto kNsFieldName = "ns"_sd;

    ListCollectionsReplyCursor();
    ListCollectionsReplyCursor(std::int64_t id, mongo::NamespaceString ns, std::vector<mongo::ListCollectionsReplyItem> firstBatch);

    static ListCollectionsReplyCursor parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    std::int64_t getId() const { return _id; }
    void setId(std::int64_t value) & {  _id = std::move(value); _hasId = true; }

    const mongo::NamespaceString& getNs() const { return _ns; }
    void setNs(mongo::NamespaceString value) & {  _ns = std::move(value); _hasNs = true; }

    const std::vector<mongo::ListCollectionsReplyItem>& getFirstBatch() const& { return _firstBatch; }
    void getFirstBatch() && = delete;
    void setFirstBatch(std::vector<mongo::ListCollectionsReplyItem> value) & {  _firstBatch = std::move(value); _hasFirstBatch = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    std::int64_t _id;
    mongo::NamespaceString _ns;
    std::vector<mongo::ListCollectionsReplyItem> _firstBatch;
    bool _hasId : 1;
    bool _hasNs : 1;
    bool _hasFirstBatch : 1;
};

/**
 * The listCollection command's reply.
 */
class ListCollectionsReply {
public:
    static constexpr auto kCursorFieldName = "cursor"_sd;

    ListCollectionsReply();
    ListCollectionsReply(mongo::ListCollectionsReplyCursor cursor);

    static ListCollectionsReply parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    const mongo::ListCollectionsReplyCursor& getCursor() const { return _cursor; }
    mongo::ListCollectionsReplyCursor& getCursor() { return _cursor; }
    void setCursor(mongo::ListCollectionsReplyCursor value) & {  _cursor = std::move(value); _hasCursor = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::ListCollectionsReplyCursor _cursor;
    bool _hasCursor : 1;
};

/**
 * Parser for the listCollections command
 */
class ListCollections {
public:
    using Reply = mongo::ListCollectionsReply;
    static constexpr auto kAuthorizedCollectionsFieldName = "authorizedCollections"_sd;
    static constexpr auto kCursorFieldName = "cursor"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kFilterFieldName = "filter"_sd;
    static constexpr auto kIncludePendingDropsFieldName = "includePendingDrops"_sd;
    static constexpr auto kNameOnlyFieldName = "nameOnly"_sd;
    static constexpr auto kCommandName = "listCollections"_sd;

    static AuthorizationContract kAuthorizationContract;

    ListCollections();

    static ListCollections parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static ListCollections parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;


    const boost::optional<mongo::SimpleCursorOptions>& getCursor() const& { return _cursor; }
    void getCursor() && = delete;
    void setCursor(boost::optional<mongo::SimpleCursorOptions> value) & {  _cursor = std::move(value);  }

    const boost::optional<mongo::BSONObj>& getFilter() const& { return _filter; }
    void getFilter() && = delete;
    void setFilter(boost::optional<mongo::BSONObj> value) & {  _filter = std::move(value);  }

    bool getNameOnly() const { return _nameOnly; }
    void setNameOnly(bool value) & {  _nameOnly = std::move(value);  }

    bool getAuthorizedCollections() const { return _authorizedCollections; }
    void setAuthorizedCollections(bool value) & {  _authorizedCollections = std::move(value);  }

    const boost::optional<bool> getIncludePendingDrops() const& { return _includePendingDrops; }
    void getIncludePendingDrops() && = delete;
    void setIncludePendingDrops(boost::optional<bool> value) & {  _includePendingDrops = std::move(value);  }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;



    boost::optional<mongo::SimpleCursorOptions> _cursor;
    boost::optional<mongo::BSONObj> _filter;
    bool _nameOnly{false};
    bool _authorizedCollections{false};
    boost::optional<bool> _includePendingDrops;
    std::string _dbName;
    bool _hasDbName : 1;
};


template <typename Derived>
class ListCollectionsCmdVersion1Gen : public TypedCommand<Derived> {
    using _TypedCommandInvocationBase = typename TypedCommand<Derived>::InvocationBase;

public:
    using Request = ListCollections;
    using Reply = mongo::ListCollectionsReply;

    virtual ~ListCollectionsCmdVersion1Gen() = default;

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
