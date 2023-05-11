/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/vector_clock_document_gen.h --output build/opt/mongo/db/vector_clock_document_gen.cpp src/mongo/db/vector_clock_document.idl
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
 * Represents the vector clock persistent state.
 */
class VectorClockDocument {
public:
    static constexpr auto k_idFieldName = "_id"_sd;
    static constexpr auto kConfigTimeFieldName = "configTime"_sd;
    static constexpr auto kTopologyTimeFieldName = "topologyTime"_sd;

    VectorClockDocument();

    static VectorClockDocument parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Key of the VectorClock state singleton document
     */
    const StringData get_id() const& { return __id; }
    void get_id() && = delete;
    void set_id(StringData value) & { auto _tmpValue = value.toString();  __id = std::move(_tmpValue);  }

    /**
     * Persists the configTime component of the vector clock
     */
    const mongo::Timestamp& getConfigTime() const { return _configTime; }
    void setConfigTime(mongo::Timestamp value) & {  _configTime = std::move(value);  }

    /**
     * Persists the topologyTime component of the vector clock
     */
    const mongo::Timestamp& getTopologyTime() const { return _topologyTime; }
    void setTopologyTime(mongo::Timestamp value) & {  _topologyTime = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    std::string __id{"vectorClockState"};
    mongo::Timestamp _configTime{Timestamp(0, 1)};
    mongo::Timestamp _topologyTime{Timestamp(0, 1)};
};

}  // namespace mongo
