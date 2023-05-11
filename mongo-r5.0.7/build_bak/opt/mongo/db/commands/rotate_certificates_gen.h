/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/commands/rotate_certificates_gen.h --output build/opt/mongo/db/commands/rotate_certificates_gen.cpp src/mongo/db/commands/rotate_certificates.idl
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
 * An administrative command which rotates the certificates to be used by new SSL connections
 */
class RotateCertificates {
public:
    using Reply = void;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kMessageFieldName = "message"_sd;
    static constexpr auto kCommandName = "rotateCertificates"_sd;

    RotateCertificates();

    static RotateCertificates parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static RotateCertificates parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;


    /**
     * Message to be logged upon successful rotation
     */
    const boost::optional<StringData> getMessage() const& { return boost::optional<StringData>{_message}; }
    void getMessage() && = delete;
    void setMessage(boost::optional<StringData> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get().toString();
        
        _message = std::move(_tmpValue);
    } else {
        _message = boost::none;
    }
      }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;



    boost::optional<std::string> _message;
    std::string _dbName;
    bool _hasDbName : 1;
};

}  // namespace mongo
