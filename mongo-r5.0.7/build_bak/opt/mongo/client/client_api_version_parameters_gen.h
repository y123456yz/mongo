/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/client/client_api_version_parameters_gen.h --output build/opt/mongo/client/client_api_version_parameters_gen.cpp src/mongo/client/client_api_version_parameters.idl
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
 * Parser for Versioned API parameters passed to 'new Mongo()' in the mongo shell
 */
class ClientAPIVersionParameters {
public:
    static constexpr auto kDeprecationErrorsFieldName = "deprecationErrors"_sd;
    static constexpr auto kStrictFieldName = "strict"_sd;
    static constexpr auto kVersionFieldName = "version"_sd;

    ClientAPIVersionParameters();

    static ClientAPIVersionParameters parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * The requested API version
     */
    const boost::optional<StringData> getVersion() const& { return boost::optional<StringData>{_version}; }
    void getVersion() && = delete;
    void setVersion(boost::optional<StringData> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get().toString();
        
        _version = std::move(_tmpValue);
    } else {
        _version = boost::none;
    }
      }

    /**
     * Whether to restrict the connection to behaviors in the requested API version
     */
    const boost::optional<bool> getStrict() const& { return _strict; }
    void getStrict() && = delete;
    void setStrict(boost::optional<bool> value) & {  _strict = std::move(value);  }

    /**
     * Whether to restrict the connection to non-deprecated behaviors in the requested API version
     */
    const boost::optional<bool> getDeprecationErrors() const& { return _deprecationErrors; }
    void getDeprecationErrors() && = delete;
    void setDeprecationErrors(boost::optional<bool> value) & {  _deprecationErrors = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    boost::optional<std::string> _version;
    boost::optional<bool> _strict;
    boost::optional<bool> _deprecationErrors;
};

}  // namespace mongo
