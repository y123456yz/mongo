/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/drop_indexes_gen.h --output build/opt/mongo/db/drop_indexes_gen.cpp src/mongo/db/drop_indexes.idl
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
 * Reply to the dropIndexes command
 */
class DropIndexesReply {
public:
    static constexpr auto kMsgFieldName = "msg"_sd;
    static constexpr auto kNIndexesWasFieldName = "nIndexesWas"_sd;

    DropIndexesReply();

    static DropIndexesReply parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Number of indexes on the collection at start of dropIndexes command (mongod only)
     */
    const boost::optional<std::int32_t> getNIndexesWas() const& { return _nIndexesWas; }
    void getNIndexesWas() && = delete;
    void setNIndexesWas(boost::optional<std::int32_t> value) & {  _nIndexesWas = std::move(value);  }

    /**
     * Optional message (mongod only)
     */
    const boost::optional<StringData> getMsg() const& { return boost::optional<StringData>{_msg}; }
    void getMsg() && = delete;
    void setMsg(boost::optional<StringData> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get().toString();
        
        _msg = std::move(_tmpValue);
    } else {
        _msg = boost::none;
    }
      }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    boost::optional<std::int32_t> _nIndexesWas;
    boost::optional<std::string> _msg;
};

/**
 * Parser for the dropIndexes command
 */
class DropIndexes {
public:
    using Reply = mongo::DropIndexesReply;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kIndexFieldName = "index"_sd;
    static constexpr auto kIsTimeseriesNamespaceFieldName = "isTimeseriesNamespace"_sd;
    static constexpr auto kCommandName = "dropIndexes"_sd;
    static constexpr auto kCommandAlias = "deleteIndexes"_sd;

    static AuthorizationContract kAuthorizationContract;

    explicit DropIndexes(const NamespaceString nss);
    DropIndexes(const NamespaceString nss, stdx::variant<std::string, std::vector<std::string>, mongo::BSONObj> index);

    static DropIndexes parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static DropIndexes parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const NamespaceString& getNamespace() const { return _nss; }

    /**
     * An index name, or array of names, or "*" for all indexes, or an index spec (an object).
     */
    const stdx::variant<std::string, std::vector<std::string>, mongo::BSONObj>& getIndex() const { return _index; }
    void setIndex(stdx::variant<std::string, std::vector<std::string>, mongo::BSONObj> value) & {  _index = std::move(value); _hasIndex = true; }

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

    stdx::variant<std::string, std::vector<std::string>, mongo::BSONObj> _index;
    boost::optional<bool> _isTimeseriesNamespace;
    std::string _dbName;
    bool _hasIndex : 1;
    bool _hasDbName : 1;
};


template <typename Derived>
class DropIndexesCmdVersion1Gen : public TypedCommand<Derived> {
    using _TypedCommandInvocationBase = typename TypedCommand<Derived>::InvocationBase;

public:
    using Request = DropIndexes;
    using Reply = mongo::DropIndexesReply;

    DropIndexesCmdVersion1Gen(): TypedCommand<Derived>(Request::kCommandName, Request::kCommandAlias) {}

    virtual ~DropIndexesCmdVersion1Gen() = default;

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
