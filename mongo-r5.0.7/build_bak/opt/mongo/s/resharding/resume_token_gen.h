/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/s/resharding/resume_token_gen.h --output build/opt/mongo/s/resharding/resume_token_gen.cpp src/mongo/s/resharding/resume_token.idl
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
 * Token format which facilitates resuming from the most recently-observed timestamp in the oplog
 */
class ResumeTokenOplogTimestamp {
public:
    static constexpr auto kTsFieldName = "ts"_sd;

    ResumeTokenOplogTimestamp();
    ResumeTokenOplogTimestamp(mongo::Timestamp ts);

    static ResumeTokenOplogTimestamp parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * The latest oplog timestamp.
     */
    const mongo::Timestamp& getTs() const { return _ts; }
    void setTs(mongo::Timestamp value) & {  _ts = std::move(value); _hasTs = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::Timestamp _ts;
    bool _hasTs : 1;
};

}  // namespace mongo
