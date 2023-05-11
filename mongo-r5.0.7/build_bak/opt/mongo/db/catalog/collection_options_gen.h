/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/catalog/collection_options_gen.h --output build/opt/mongo/db/catalog/collection_options_gen.cpp src/mongo/db/catalog/collection_options.idl
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
#include "mongo/db/catalog/collection_options_validation.h"
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
 * Determines how strictly MongoDB applies the validation rules to existing documents during an update.
 */
enum class ValidationLevelEnum : std::int32_t {
    off ,
    strict ,
    moderate ,
};
static constexpr uint32_t kNumValidationLevelEnum = 3;

ValidationLevelEnum ValidationLevel_parse(const IDLParserErrorContext& ctxt, StringData value);
StringData ValidationLevel_serializer(ValidationLevelEnum value);

/**
 * Determines whether to error on invalid documents or just warn about the violations but allow invalid documents to be inserted.
 */
enum class ValidationActionEnum : std::int32_t {
    error ,
    warn ,
};
static constexpr uint32_t kNumValidationActionEnum = 2;

ValidationActionEnum ValidationAction_parse(const IDLParserErrorContext& ctxt, StringData value);
StringData ValidationAction_serializer(ValidationActionEnum value);

/**
 * The default configuration for indexes per storage engine.
 */
class IndexOptionDefaults {
public:
    static constexpr auto kStorageEngineFieldName = "storageEngine"_sd;

    IndexOptionDefaults();

    static IndexOptionDefaults parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * The index options for the specified storage engines.
     */
    const boost::optional<mongo::BSONObj>& getStorageEngine() const& { return _storageEngine; }
    void getStorageEngine() && = delete;
    void setStorageEngine(boost::optional<mongo::BSONObj> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get();
        validateStorageEngine(_tmpValue);
        _storageEngine = std::move(_tmpValue);
    } else {
        _storageEngine = boost::none;
    }
      }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    void validateStorageEngine(const mongo::BSONObj& value);
    void validateStorageEngine(IDLParserErrorContext& ctxt, const mongo::BSONObj& value);

private:
    boost::optional<mongo::BSONObj> _storageEngine;
};

}  // namespace mongo
