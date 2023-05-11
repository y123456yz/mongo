/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/commands/list_databases_gen.h --output build/opt/mongo/db/commands/list_databases_gen.cpp src/mongo/db/commands/list_databases.idl
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
 * Individual result
 */
class ListDatabasesReplyItem {
public:
    static constexpr auto kEmptyFieldName = "empty"_sd;
    static constexpr auto kNameFieldName = "name"_sd;
    static constexpr auto kShardsFieldName = "shards"_sd;
    static constexpr auto kSizeOnDiskFieldName = "sizeOnDisk"_sd;

    ListDatabasesReplyItem();
    ListDatabasesReplyItem(std::string name);

    static ListDatabasesReplyItem parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    const StringData getName() const& { return _name; }
    void getName() && = delete;
    void setName(StringData value) & { auto _tmpValue = value.toString();  _name = std::move(_tmpValue); _hasName = true; }

    const boost::optional<std::int64_t> getSizeOnDisk() const& { return _sizeOnDisk; }
    void getSizeOnDisk() && = delete;
    void setSizeOnDisk(boost::optional<std::int64_t> value) & {  _sizeOnDisk = std::move(value);  }

    const boost::optional<bool> getEmpty() const& { return _empty; }
    void getEmpty() && = delete;
    void setEmpty(boost::optional<bool> value) & {  _empty = std::move(value);  }

    const boost::optional<mongo::BSONObj>& getShards() const& { return _shards; }
    void getShards() && = delete;
    void setShards(boost::optional<mongo::BSONObj> value) & {  _shards = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    std::string _name;
    boost::optional<std::int64_t> _sizeOnDisk;
    boost::optional<bool> _empty;
    boost::optional<mongo::BSONObj> _shards;
    bool _hasName : 1;
};

/**
 * The listDatabases command's reply.
 */
class ListDatabasesReply {
public:
    static constexpr auto kDatabasesFieldName = "databases"_sd;
    static constexpr auto kTotalSizeFieldName = "totalSize"_sd;
    static constexpr auto kTotalSizeMbFieldName = "totalSizeMb"_sd;

    ListDatabasesReply();
    ListDatabasesReply(std::vector<mongo::ListDatabasesReplyItem> databases);

    static ListDatabasesReply parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    const std::vector<mongo::ListDatabasesReplyItem>& getDatabases() const& { return _databases; }
    void getDatabases() && = delete;
    void setDatabases(std::vector<mongo::ListDatabasesReplyItem> value) & {  _databases = std::move(value); _hasDatabases = true; }

    const boost::optional<std::int64_t> getTotalSize() const& { return _totalSize; }
    void getTotalSize() && = delete;
    void setTotalSize(boost::optional<std::int64_t> value) & {  _totalSize = std::move(value);  }

    const boost::optional<std::int64_t> getTotalSizeMb() const& { return _totalSizeMb; }
    void getTotalSizeMb() && = delete;
    void setTotalSizeMb(boost::optional<std::int64_t> value) & {  _totalSizeMb = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    std::vector<mongo::ListDatabasesReplyItem> _databases;
    boost::optional<std::int64_t> _totalSize;
    boost::optional<std::int64_t> _totalSizeMb;
    bool _hasDatabases : 1;
};

/**
 * listDatabases Command
 */
class ListDatabasesCommand {
public:
    using Reply = mongo::ListDatabasesReply;
    static constexpr auto kAuthorizedDatabasesFieldName = "authorizedDatabases"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kFilterFieldName = "filter"_sd;
    static constexpr auto kNameOnlyFieldName = "nameOnly"_sd;
    static constexpr auto kCommandName = "listDatabases"_sd;

    static AuthorizationContract kAuthorizationContract;

    ListDatabasesCommand();

    static ListDatabasesCommand parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static ListDatabasesCommand parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;


    /**
     * Return just the database name without metadata
     */
    bool getNameOnly() const { return _nameOnly; }
    void setNameOnly(bool value) & {  _nameOnly = std::move(value);  }

    /**
     * Only return those databases for which the user is authorized
     */
    const boost::optional<bool> getAuthorizedDatabases() const& { return _authorizedDatabases; }
    void getAuthorizedDatabases() && = delete;
    void setAuthorizedDatabases(boost::optional<bool> value) & {  _authorizedDatabases = std::move(value);  }

    /**
     * Filter description to limit results
     */
    const boost::optional<mongo::BSONObj>& getFilter() const& { return _filter; }
    void getFilter() && = delete;
    void setFilter(boost::optional<mongo::BSONObj> value) & {  _filter = std::move(value);  }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;



    bool _nameOnly{false};
    boost::optional<bool> _authorizedDatabases;
    boost::optional<mongo::BSONObj> _filter;
    std::string _dbName;
    bool _hasDbName : 1;
};


template <typename Derived>
class ListDatabasesCmdVersion1Gen : public TypedCommand<Derived> {
    using _TypedCommandInvocationBase = typename TypedCommand<Derived>::InvocationBase;

public:
    using Request = ListDatabasesCommand;
    using Reply = mongo::ListDatabasesReply;

    virtual ~ListDatabasesCmdVersion1Gen() = default;

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
