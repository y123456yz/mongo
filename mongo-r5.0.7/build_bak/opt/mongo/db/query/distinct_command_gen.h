/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/query/distinct_command_gen.h --output build/opt/mongo/db/query/distinct_command_gen.cpp src/mongo/db/query/distinct_command.idl
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
#include "mongo/idl/basic_types.h"
#include "mongo/idl/basic_types_gen.h"
#include "mongo/idl/idl_parser.h"
#include "mongo/rpc/op_msg.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/util/uuid.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {

/**
 * Parser for the 'distinct' command.
 */
class DistinctCommandRequest {
public:
    using Reply = void;
    static constexpr auto kCollationFieldName = "collation"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kKeyFieldName = "key"_sd;
    static constexpr auto kQueryFieldName = "query"_sd;
    static constexpr auto kCommandName = "distinct"_sd;

    explicit DistinctCommandRequest(const NamespaceStringOrUUID nssOrUUID);
    DistinctCommandRequest(const NamespaceStringOrUUID nssOrUUID, std::string key);

    static DistinctCommandRequest parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static DistinctCommandRequest parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const NamespaceStringOrUUID& getNamespaceOrUUID() const { return _nssOrUUID; }

    /**
     * The field path for which to return distinct values.
     */
    const StringData getKey() const& { return _key; }
    void getKey() && = delete;
    void setKey(StringData value) & { auto _tmpValue = value.toString();  _key = std::move(_tmpValue); _hasKey = true; }

    /**
     * Optional query that filters the documents from which to retrieve the distinct values.
     */
    const boost::optional<mongo::BSONObj>& getQuery() const& { return _query; }
    void getQuery() && = delete;
    void setQuery(boost::optional<mongo::BSONObj> value) & {  _query = std::move(value);  }

    /**
     * Optional collation for the command.
     */
    const boost::optional<mongo::BSONObj>& getCollation() const& { return _collation; }
    void getCollation() && = delete;
    void setCollation(boost::optional<mongo::BSONObj> value) & {  _collation = std::move(value);  }

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

    std::string _key;
    boost::optional<mongo::BSONObj> _query;
    boost::optional<mongo::BSONObj> _collation;
    std::string _dbName;
    bool _hasKey : 1;
    bool _hasDbName : 1;
};

}  // namespace mongo
