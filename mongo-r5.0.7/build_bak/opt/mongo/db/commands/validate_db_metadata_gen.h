/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/commands/validate_db_metadata_gen.h --output build/opt/mongo/db/commands/validate_db_metadata_gen.cpp src/mongo/db/commands/validate_db_metadata.idl
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
 * Error reply element of validateDBMetadata command's reply.
 */
class ErrorReplyElement {
public:
    static constexpr auto kCodeFieldName = "code"_sd;
    static constexpr auto kCodeNameFieldName = "codeName"_sd;
    static constexpr auto kErrmsgFieldName = "errmsg"_sd;
    static constexpr auto kNsFieldName = "ns"_sd;
    static constexpr auto kShardFieldName = "shard"_sd;

    ErrorReplyElement();
    ErrorReplyElement(std::string ns, std::int32_t code, std::string codeName, std::string errmsg);

    static ErrorReplyElement parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    const boost::optional<StringData> getShard() const& { return boost::optional<StringData>{_shard}; }
    void getShard() && = delete;
    void setShard(boost::optional<StringData> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get().toString();
        
        _shard = std::move(_tmpValue);
    } else {
        _shard = boost::none;
    }
      }

    const StringData getNs() const& { return _ns; }
    void getNs() && = delete;
    void setNs(StringData value) & { auto _tmpValue = value.toString();  _ns = std::move(_tmpValue); _hasNs = true; }

    std::int32_t getCode() const { return _code; }
    void setCode(std::int32_t value) & {  _code = std::move(value); _hasCode = true; }

    const StringData getCodeName() const& { return _codeName; }
    void getCodeName() && = delete;
    void setCodeName(StringData value) & { auto _tmpValue = value.toString();  _codeName = std::move(_tmpValue); _hasCodeName = true; }

    const StringData getErrmsg() const& { return _errmsg; }
    void getErrmsg() && = delete;
    void setErrmsg(StringData value) & { auto _tmpValue = value.toString();  _errmsg = std::move(_tmpValue); _hasErrmsg = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    boost::optional<std::string> _shard;
    std::string _ns;
    std::int32_t _code;
    std::string _codeName;
    std::string _errmsg;
    bool _hasNs : 1;
    bool _hasCode : 1;
    bool _hasCodeName : 1;
    bool _hasErrmsg : 1;
};

/**
 * The validateDBMetadata command's reply.
 */
class ValidateDBMetadataCommandReply {
public:
    static constexpr auto kApiVersionErrorsFieldName = "apiVersionErrors"_sd;
    static constexpr auto kHasMoreErrorsFieldName = "hasMoreErrors"_sd;

    ValidateDBMetadataCommandReply();

    static ValidateDBMetadataCommandReply parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    const boost::optional<std::vector<mongo::ErrorReplyElement>>& getApiVersionErrors() const& { return _apiVersionErrors; }
    void getApiVersionErrors() && = delete;
    void setApiVersionErrors(boost::optional<std::vector<mongo::ErrorReplyElement>> value) & {  _apiVersionErrors = std::move(value);  }

    const mongo::OptionalBool& getHasMoreErrors() const { return _hasMoreErrors; }
    void setHasMoreErrors(mongo::OptionalBool value) & {  _hasMoreErrors = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    boost::optional<std::vector<mongo::ErrorReplyElement>> _apiVersionErrors;
    mongo::OptionalBool _hasMoreErrors{mongo::OptionalBool()};
};

/**
 * Structure defining the API parameters for validateDBMetadata.
 */
class APIParamsForCmd {
public:
    static constexpr auto kDeprecationErrorsFieldName = "deprecationErrors"_sd;
    static constexpr auto kStrictFieldName = "strict"_sd;
    static constexpr auto kVersionFieldName = "version"_sd;

    APIParamsForCmd();
    APIParamsForCmd(std::string version);

    static APIParamsForCmd parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    const StringData getVersion() const& { return _version; }
    void getVersion() && = delete;
    void setVersion(StringData value) & { auto _tmpValue = value.toString();  _version = std::move(_tmpValue); _hasVersion = true; }

    const mongo::OptionalBool& getStrict() const { return _strict; }
    void setStrict(mongo::OptionalBool value) & {  _strict = std::move(value);  }

    const mongo::OptionalBool& getDeprecationErrors() const { return _deprecationErrors; }
    void setDeprecationErrors(mongo::OptionalBool value) & {  _deprecationErrors = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    std::string _version;
    mongo::OptionalBool _strict{mongo::OptionalBool()};
    mongo::OptionalBool _deprecationErrors{mongo::OptionalBool()};
    bool _hasVersion : 1;
};

/**
 * Input request for validateDBMetadata command.
 */
class ValidateDBMetadataCommandRequest {
public:
    using Reply = mongo::ValidateDBMetadataCommandReply;
    static constexpr auto kApiParametersFieldName = "apiParameters"_sd;
    static constexpr auto kCollectionFieldName = "collection"_sd;
    static constexpr auto kDbFieldName = "db"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kCommandName = "validateDBMetadata"_sd;

    ValidateDBMetadataCommandRequest();
    ValidateDBMetadataCommandRequest(mongo::APIParamsForCmd apiParameters);

    static ValidateDBMetadataCommandRequest parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static ValidateDBMetadataCommandRequest parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;


    const boost::optional<StringData> getDb() const& { return boost::optional<StringData>{_db}; }
    void getDb() && = delete;
    void setDb(boost::optional<StringData> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get().toString();
        
        _db = std::move(_tmpValue);
    } else {
        _db = boost::none;
    }
      }

    const boost::optional<StringData> getCollection() const& { return boost::optional<StringData>{_collection}; }
    void getCollection() && = delete;
    void setCollection(boost::optional<StringData> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get().toString();
        
        _collection = std::move(_tmpValue);
    } else {
        _collection = boost::none;
    }
      }

    const mongo::APIParamsForCmd& getApiParameters() const { return _apiParameters; }
    mongo::APIParamsForCmd& getApiParameters() { return _apiParameters; }
    void setApiParameters(mongo::APIParamsForCmd value) & {  _apiParameters = std::move(value); _hasApiParameters = true; }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;



    boost::optional<std::string> _db;
    boost::optional<std::string> _collection;
    mongo::APIParamsForCmd _apiParameters;
    std::string _dbName;
    bool _hasApiParameters : 1;
    bool _hasDbName : 1;
};

}  // namespace mongo
