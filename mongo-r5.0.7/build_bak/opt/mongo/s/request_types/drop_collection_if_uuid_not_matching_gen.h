/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/s/request_types/drop_collection_if_uuid_not_matching_gen.h --output build/opt/mongo/s/request_types/drop_collection_if_uuid_not_matching_gen.cpp src/mongo/s/request_types/drop_collection_if_uuid_not_matching.idl
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
 * Internal dropCollectionIfUUIDNotMatching request.
 */
class ShardsvrDropCollectionIfUUIDNotMatchingRequest {
public:
    using Reply = void;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kExpectedCollectionUUIDFieldName = "expectedCollectionUUID"_sd;
    static constexpr auto kCommandName = "_shardsvrDropCollectionIfUUIDNotMatching"_sd;

    explicit ShardsvrDropCollectionIfUUIDNotMatchingRequest(const NamespaceString nss);
    ShardsvrDropCollectionIfUUIDNotMatchingRequest(const NamespaceString nss, mongo::UUID expectedCollectionUUID);

    static ShardsvrDropCollectionIfUUIDNotMatchingRequest parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static ShardsvrDropCollectionIfUUIDNotMatchingRequest parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const NamespaceString& getNamespace() const { return _nss; }

    /**
     * The expected collection UUID: if the local catalog has a different uuid associated to the namespace, the collection will be dropped.
     */
    const mongo::UUID& getExpectedCollectionUUID() const { return _expectedCollectionUUID; }
    void setExpectedCollectionUUID(mongo::UUID value) & {  _expectedCollectionUUID = std::move(value); _hasExpectedCollectionUUID = true; }

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

    mongo::UUID _expectedCollectionUUID;
    std::string _dbName;
    bool _hasExpectedCollectionUUID : 1;
    bool _hasDbName : 1;
};

}  // namespace mongo
