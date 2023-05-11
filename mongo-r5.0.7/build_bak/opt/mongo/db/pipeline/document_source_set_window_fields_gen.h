/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/pipeline/document_source_set_window_fields_gen.h --output build/opt/mongo/db/pipeline/document_source_set_window_fields_gen.cpp src/mongo/db/pipeline/document_source_set_window_fields.idl
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
 * Specification for a $setWindowFields stage given in the full, explicit format.
 */
class SetWindowFieldsSpec {
public:
    static constexpr auto kOutputFieldName = "output"_sd;
    static constexpr auto kPartitionByFieldName = "partitionBy"_sd;
    static constexpr auto kSortByFieldName = "sortBy"_sd;

    SetWindowFieldsSpec();
    SetWindowFieldsSpec(mongo::BSONObj output);

    static SetWindowFieldsSpec parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * An expression used to partition the data.
     */
    const boost::optional<mongo::IDLAnyType>& getPartitionBy() const& { return _partitionBy; }
    void getPartitionBy() && = delete;
    void setPartitionBy(boost::optional<mongo::IDLAnyType> value) & {  _partitionBy = std::move(value);  }

    /**
     * Order for the documents within each partition, identical to sort spec.
     */
    const boost::optional<mongo::BSONObj>& getSortBy() const& { return _sortBy; }
    void getSortBy() && = delete;
    void setSortBy(boost::optional<mongo::BSONObj> value) & {  _sortBy = std::move(value);  }

    /**
     * Set of fields to project the results of the window function computations.
     */
    const mongo::BSONObj& getOutput() const { return _output; }
    void setOutput(mongo::BSONObj value) & {  _output = std::move(value); _hasOutput = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    boost::optional<mongo::IDLAnyType> _partitionBy;
    boost::optional<mongo::BSONObj> _sortBy;
    mongo::BSONObj _output;
    bool _hasOutput : 1;
};

}  // namespace mongo
