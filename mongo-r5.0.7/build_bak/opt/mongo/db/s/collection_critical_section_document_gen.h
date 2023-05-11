/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/s/collection_critical_section_document_gen.h --output build/opt/mongo/db/s/collection_critical_section_document_gen.cpp src/mongo/db/s/collection_critical_section_document.idl
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
 * Represents that a collection is under an operation that holds the collection critical section.
 */
class CollectionCriticalSectionDocument {
public:
    static constexpr auto kAdditionalInfoFieldName = "additionalInfo"_sd;
    static constexpr auto kBlockReadsFieldName = "blockReads"_sd;
    static constexpr auto kNssFieldName = "_id"_sd;
    static constexpr auto kReasonFieldName = "reason"_sd;

    CollectionCriticalSectionDocument();
    CollectionCriticalSectionDocument(mongo::NamespaceString nss, mongo::BSONObj reason, bool blockReads);

    static CollectionCriticalSectionDocument parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * The namespace of the collection that is under the collection critical section.
     */
    const mongo::NamespaceString& getNss() const { return _nss; }
    void setNss(mongo::NamespaceString value) & {  _nss = std::move(value); _hasNss = true; }

            /**
             * An identifier of the operation that is holding the critical section.
    Only used for diagnostic purposes.
             */
    const mongo::BSONObj& getReason() const { return _reason; }
    void setReason(mongo::BSONObj value) & {  _reason = std::move(value); _hasReason = true; }

    /**
     * It states whether this critical section should block reads (CS in commit phase) or not (CS in catch up phase).
     */
    bool getBlockReads() const { return _blockReads; }
    void setBlockReads(bool value) & {  _blockReads = std::move(value); _hasBlockReads = true; }

            /**
             * Additional information associated to the operation that is holding the critical section.
    Only used for diagnostic purposes.
             */
    const boost::optional<mongo::BSONObj>& getAdditionalInfo() const& { return _additionalInfo; }
    void getAdditionalInfo() && = delete;
    void setAdditionalInfo(boost::optional<mongo::BSONObj> value) & {  _additionalInfo = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::NamespaceString _nss;
    mongo::BSONObj _reason;
    bool _blockReads;
    boost::optional<mongo::BSONObj> _additionalInfo;
    bool _hasNss : 1;
    bool _hasReason : 1;
    bool _hasBlockReads : 1;
};

}  // namespace mongo
