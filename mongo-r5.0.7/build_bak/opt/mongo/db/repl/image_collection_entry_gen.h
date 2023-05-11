/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/repl/image_collection_entry_gen.h --output build/opt/mongo/db/repl/image_collection_entry_gen.cpp src/mongo/db/repl/image_collection_entry.idl
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
#include "mongo/crypto/sha256_block.h"
#include "mongo/db/exec/document_value/value.h"
#include "mongo/db/logical_session_id_gen.h"
#include "mongo/db/namespace_string.h"
#include "mongo/db/repl/oplog_entry_gen.h"
#include "mongo/db/repl/optime.h"
#include "mongo/idl/basic_types.h"
#include "mongo/idl/basic_types_gen.h"
#include "mongo/idl/idl_parser.h"
#include "mongo/rpc/op_msg.h"
#include "mongo/s/shard_id.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/util/uuid.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {
namespace repl {

/**
 * Represents either a pre-image or post-image necessary for satisfying a retryable findAndModify.
 */
class ImageEntry {
public:
    static constexpr auto k_idFieldName = "_id"_sd;
    static constexpr auto kImageFieldName = "image"_sd;
    static constexpr auto kImageKindFieldName = "imageKind"_sd;
    static constexpr auto kInvalidatedFieldName = "invalidated"_sd;
    static constexpr auto kInvalidatedReasonFieldName = "invalidatedReason"_sd;
    static constexpr auto kTsFieldName = "ts"_sd;
    static constexpr auto kTxnNumberFieldName = "txnNum"_sd;

    ImageEntry();
    ImageEntry(mongo::LogicalSessionId _id, std::int64_t txnNumber, mongo::Timestamp ts, mongo::repl::RetryImageEnum imageKind, mongo::BSONObj image);

    static ImageEntry parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    const mongo::LogicalSessionId& get_id() const { return __id; }
    mongo::LogicalSessionId& get_id() { return __id; }
    void set_id(mongo::LogicalSessionId value) & {  __id = std::move(value); _has_id = true; }

    std::int64_t getTxnNumber() const { return _txnNumber; }
    void setTxnNumber(std::int64_t value) & {  _txnNumber = std::move(value); _hasTxnNumber = true; }

    const mongo::Timestamp& getTs() const { return _ts; }
    void setTs(mongo::Timestamp value) & {  _ts = std::move(value); _hasTs = true; }

    mongo::repl::RetryImageEnum getImageKind() const { return _imageKind; }
    void setImageKind(mongo::repl::RetryImageEnum value) & {  _imageKind = std::move(value); _hasImageKind = true; }

    const mongo::BSONObj& getImage() const { return _image; }
    void setImage(mongo::BSONObj value) & {  _image = std::move(value); _hasImage = true; }

    bool getInvalidated() const { return _invalidated; }
    void setInvalidated(bool value) & {  _invalidated = std::move(value);  }

    const boost::optional<StringData> getInvalidatedReason() const& { return boost::optional<StringData>{_invalidatedReason}; }
    void getInvalidatedReason() && = delete;
    void setInvalidatedReason(boost::optional<StringData> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get().toString();
        
        _invalidatedReason = std::move(_tmpValue);
    } else {
        _invalidatedReason = boost::none;
    }
      }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::LogicalSessionId __id;
    std::int64_t _txnNumber;
    mongo::Timestamp _ts;
    mongo::repl::RetryImageEnum _imageKind;
    mongo::BSONObj _image;
    bool _invalidated{false};
    boost::optional<std::string> _invalidatedReason;
    bool _has_id : 1;
    bool _hasTxnNumber : 1;
    bool _hasTs : 1;
    bool _hasImageKind : 1;
    bool _hasImage : 1;
};

}  // namespace repl
}  // namespace mongo
