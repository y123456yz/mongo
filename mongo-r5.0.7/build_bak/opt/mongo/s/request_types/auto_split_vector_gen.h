/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/s/request_types/auto_split_vector_gen.h --output build/opt/mongo/s/request_types/auto_split_vector_gen.cpp src/mongo/s/request_types/auto_split_vector.idl
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
#include "mongo/db/s/auto_split_vector.h"
#include "mongo/idl/basic_types.h"
#include "mongo/idl/basic_types_gen.h"
#include "mongo/idl/idl_parser.h"
#include "mongo/rpc/op_msg.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/util/uuid.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {

/**
 * The reply of an autoSplitVector command.
 */
class AutoSplitVectorResponse {
public:
    static constexpr auto kSplitKeysFieldName = "splitKeys"_sd;

    AutoSplitVectorResponse();
    AutoSplitVectorResponse(std::vector<mongo::BSONObj> splitKeys);

    static AutoSplitVectorResponse parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    const std::vector<mongo::BSONObj>& getSplitKeys() const { return _splitKeys; }
    void setSplitKeys(std::vector<mongo::BSONObj> value) & {  _splitKeys = std::move(value); _hasSplitKeys = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    std::vector<mongo::BSONObj> _splitKeys;
    bool _hasSplitKeys : 1;
};

/**
 * Internal autoSplitVector command
 */
class AutoSplitVectorRequest {
public:
    using Reply = void;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kKeyPatternFieldName = "keyPattern"_sd;
    static constexpr auto kMaxFieldName = "max"_sd;
    static constexpr auto kMaxChunkSizeBytesFieldName = "maxChunkSizeBytes"_sd;
    static constexpr auto kMinFieldName = "min"_sd;
    static constexpr auto kCommandName = "autoSplitVector"_sd;

    explicit AutoSplitVectorRequest(const NamespaceString nss);
    AutoSplitVectorRequest(const NamespaceString nss, mongo::BSONObj keyPattern, mongo::BSONObj min, mongo::BSONObj max, std::int64_t maxChunkSizeBytes);

    static AutoSplitVectorRequest parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static AutoSplitVectorRequest parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const NamespaceString& getNamespace() const { return _nss; }

    /**
     * Shard key pattern of the collection
     */
    const mongo::BSONObj& getKeyPattern() const { return _keyPattern; }
    void setKeyPattern(mongo::BSONObj value) & {  _keyPattern = std::move(value); _hasKeyPattern = true; }

    /**
     * Min key of the chunk
     */
    const mongo::BSONObj& getMin() const { return _min; }
    void setMin(mongo::BSONObj value) & {  _min = std::move(value); _hasMin = true; }

    /**
     * Max key of the chunk
     */
    const mongo::BSONObj& getMax() const { return _max; }
    void setMax(mongo::BSONObj value) & {  _max = std::move(value); _hasMax = true; }

    /**
     * Max chunk size of the collection expressed in bytes
     */
    std::int64_t getMaxChunkSizeBytes() const { return _maxChunkSizeBytes; }
    void setMaxChunkSizeBytes(std::int64_t value) & {  _maxChunkSizeBytes = std::move(value); _hasMaxChunkSizeBytes = true; }

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

    mongo::BSONObj _keyPattern;
    mongo::BSONObj _min;
    mongo::BSONObj _max;
    std::int64_t _maxChunkSizeBytes;
    std::string _dbName;
    bool _hasKeyPattern : 1;
    bool _hasMin : 1;
    bool _hasMax : 1;
    bool _hasMaxChunkSizeBytes : 1;
    bool _hasDbName : 1;
};

}  // namespace mongo
