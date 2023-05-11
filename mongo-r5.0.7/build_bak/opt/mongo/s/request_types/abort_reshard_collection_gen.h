/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/s/request_types/abort_reshard_collection_gen.h --output build/opt/mongo/s/request_types/abort_reshard_collection_gen.cpp src/mongo/s/request_types/abort_reshard_collection.idl
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
 * The public abortReshardCollection command on mongos.
 */
class AbortReshardCollection {
public:
    using Reply = void;
    static constexpr auto kCommandParameterFieldName = "abortReshardCollection"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kCommandName = "abortReshardCollection"_sd;

    explicit AbortReshardCollection(const mongo::NamespaceString commandParameter);

    static AbortReshardCollection parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static AbortReshardCollection parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const mongo::NamespaceString& getCommandParameter() const { return _commandParameter; }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;


    mongo::NamespaceString _commandParameter;

    std::string _dbName;
    bool _hasDbName : 1;
};

/**
 * The internal abortReshardCollection command on the config server.
 */
class ConfigsvrAbortReshardCollection {
public:
    using Reply = void;
    static constexpr auto kCommandParameterFieldName = "_configsvrAbortReshardCollection"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kCommandName = "_configsvrAbortReshardCollection"_sd;

    explicit ConfigsvrAbortReshardCollection(const mongo::NamespaceString commandParameter);

    static ConfigsvrAbortReshardCollection parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static ConfigsvrAbortReshardCollection parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const mongo::NamespaceString& getCommandParameter() const { return _commandParameter; }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;


    mongo::NamespaceString _commandParameter;

    std::string _dbName;
    bool _hasDbName : 1;
};

/**
 * The internal command used by resharding coordinator to abort participants.
 */
class ShardsvrAbortReshardCollection {
public:
    using Reply = void;
    static constexpr auto kCommandParameterFieldName = "_shardsvrAbortReshardCollection"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kUserCanceledFieldName = "userCanceled"_sd;
    static constexpr auto kCommandName = "_shardsvrAbortReshardCollection"_sd;

    explicit ShardsvrAbortReshardCollection(const mongo::UUID commandParameter);
    explicit ShardsvrAbortReshardCollection(const mongo::UUID commandParameter, bool userCanceled);

    static ShardsvrAbortReshardCollection parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static ShardsvrAbortReshardCollection parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const mongo::UUID& getCommandParameter() const { return _commandParameter; }

    /**
     * Determines whether the resharding opertion was user aborted.
     */
    bool getUserCanceled() const { return _userCanceled; }
    void setUserCanceled(bool value) & {  _userCanceled = std::move(value); _hasUserCanceled = true; }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;


    mongo::UUID _commandParameter;

    bool _userCanceled;
    std::string _dbName;
    bool _hasUserCanceled : 1;
    bool _hasDbName : 1;
};

}  // namespace mongo
