/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/rpc/write_concern_error_gen.h --output build/opt/mongo/rpc/write_concern_error_gen.cpp src/mongo/rpc/write_concern_error.idl
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
 * WriteConcernError structure shared by all commands
 */
class WriteConcernError {
public:
    static constexpr auto kCodeFieldName = "code"_sd;
    static constexpr auto kCodeNameFieldName = "codeName"_sd;
    static constexpr auto kErrInfoFieldName = "errInfo"_sd;
    static constexpr auto kErrmsgFieldName = "errmsg"_sd;

    WriteConcernError();
    WriteConcernError(std::int32_t code, std::string errmsg);

    static WriteConcernError parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    std::int32_t getCode() const { return _code; }
    void setCode(std::int32_t value) & {  _code = std::move(value); _hasCode = true; }

    const boost::optional<StringData> getCodeName() const& { return boost::optional<StringData>{_codeName}; }
    void getCodeName() && = delete;
    void setCodeName(boost::optional<StringData> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get().toString();
        
        _codeName = std::move(_tmpValue);
    } else {
        _codeName = boost::none;
    }
      }

    const StringData getErrmsg() const& { return _errmsg; }
    void getErrmsg() && = delete;
    void setErrmsg(StringData value) & { auto _tmpValue = value.toString();  _errmsg = std::move(_tmpValue); _hasErrmsg = true; }

    const boost::optional<mongo::BSONObj>& getErrInfo() const& { return _errInfo; }
    void getErrInfo() && = delete;
    void setErrInfo(boost::optional<mongo::BSONObj> value) & {  _errInfo = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    std::int32_t _code;
    boost::optional<std::string> _codeName;
    std::string _errmsg;
    boost::optional<mongo::BSONObj> _errInfo;
    bool _hasCode : 1;
    bool _hasErrmsg : 1;
};

}  // namespace mongo
