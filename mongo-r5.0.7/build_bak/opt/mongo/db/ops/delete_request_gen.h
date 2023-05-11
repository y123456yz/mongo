/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/ops/delete_request_gen.h --output build/opt/mongo/db/ops/delete_request_gen.cpp src/mongo/db/ops/delete_request.idl
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
#include "mongo/db/logical_session_id.h"
#include "mongo/db/logical_session_id_gen.h"
#include "mongo/db/namespace_string.h"
#include "mongo/db/pipeline/legacy_runtime_constants_gen.h"
#include "mongo/db/query/hint_parser.h"
#include "mongo/db/query/plan_executor.h"
#include "mongo/idl/basic_types.h"
#include "mongo/idl/basic_types_gen.h"
#include "mongo/idl/idl_parser.h"
#include "mongo/rpc/op_msg.h"
#include "mongo/stdx/unordered_map.h"
#include "mongo/util/uuid.h"

namespace mongo { class AuthorizationContract; }

namespace mongo {

/**
 * Specifies a delete command.
 */
class DeleteRequest {
public:
    static constexpr auto kCollationFieldName = "collation"_sd;
    static constexpr auto kFromMigrateFieldName = "fromMigrate"_sd;
    static constexpr auto kGodFieldName = "god"_sd;
    static constexpr auto kHintFieldName = "hint"_sd;
    static constexpr auto kIsExplainFieldName = "isExplain"_sd;
    static constexpr auto kLegacyRuntimeConstantsFieldName = "runtimeConstants"_sd;
    static constexpr auto kLetFieldName = "let"_sd;
    static constexpr auto kMultiFieldName = "multi"_sd;
    static constexpr auto kNsStringFieldName = "nsString"_sd;
    static constexpr auto kProjFieldName = "proj"_sd;
    static constexpr auto kQueryFieldName = "query"_sd;
    static constexpr auto kReturnDeletedFieldName = "returnDeleted"_sd;
    static constexpr auto kSortFieldName = "sort"_sd;
    static constexpr auto kStmtIdFieldName = "stmtId"_sd;
    static constexpr auto kYieldPolicyFieldName = "yieldPolicy"_sd;

    DeleteRequest();
    DeleteRequest(mongo::NamespaceString nsString, mongo::BSONObj hint, mongo::BSONObj query, mongo::BSONObj proj, mongo::BSONObj sort, mongo::BSONObj collation);

    static DeleteRequest parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Specifies the namespace string for the delete.
     */
    const mongo::NamespaceString& getNsString() const { return _nsString; }
    void setNsString(mongo::NamespaceString value) & {  _nsString = std::move(value); _hasNsString = true; }

    /**
     * Specifies the hint to use for the delete.
     */
    const mongo::BSONObj& getHint() const { return _hint; }
    void setHint(mongo::BSONObj value) & {  _hint = std::move(value); _hasHint = true; }

    /**
     * Specifies the query to use for the delete.
     */
    const mongo::BSONObj& getQuery() const { return _query; }
    void setQuery(mongo::BSONObj value) & {  _query = std::move(value); _hasQuery = true; }

    /**
     * Specifies the projection to use for the delete.
     */
    const mongo::BSONObj& getProj() const { return _proj; }
    void setProj(mongo::BSONObj value) & {  _proj = std::move(value); _hasProj = true; }

    /**
     * Specifies the sort to use for the delete.
     */
    const mongo::BSONObj& getSort() const { return _sort; }
    void setSort(mongo::BSONObj value) & {  _sort = std::move(value); _hasSort = true; }

    /**
     * Specifies the collation to use for the delete.
     */
    const mongo::BSONObj& getCollation() const { return _collation; }
    void setCollation(mongo::BSONObj value) & {  _collation = std::move(value); _hasCollation = true; }

    /**
     * User-defined constant values to be used within $expr. These can be specified by the user for each individual element of the 'deletes' array.
     */
    const boost::optional<mongo::BSONObj>& getLet() const& { return _let; }
    void getLet() && = delete;
    void setLet(boost::optional<mongo::BSONObj> value) & {  _let = std::move(value);  }

    /**
     * A legacy way to specify constant variables available during execution. 'let' is now preferred.
     */
    const boost::optional<mongo::LegacyRuntimeConstants>& getLegacyRuntimeConstants() const& { return _legacyRuntimeConstants; }
    void getLegacyRuntimeConstants() && = delete;
    void setLegacyRuntimeConstants(boost::optional<mongo::LegacyRuntimeConstants> value) & {  _legacyRuntimeConstants = std::move(value);  }

    /**
     * The statement ID for the delete.
     */
    const mongo::StmtId& getStmtId() const { return _stmtId; }
    void setStmtId(mongo::StmtId value) & {  _stmtId = std::move(value);  }

    /**
     * If true, deletes all documents that meet the query criteria. If false, limits the delete to one document which meets the query criteria.
     */
    bool getMulti() const { return _multi; }
    void setMulti(bool value) & {  _multi = std::move(value);  }

    /**
     * If true, execute the delete in GodMode.
     */
    bool getGod() const { return _god; }
    void setGod(bool value) & {  _god = std::move(value);  }

    bool getFromMigrate() const { return _fromMigrate; }
    void setFromMigrate(bool value) & {  _fromMigrate = std::move(value);  }

    /**
     * If true, running an explain of the delete command.
     */
    bool getIsExplain() const { return _isExplain; }
    void setIsExplain(bool value) & {  _isExplain = std::move(value);  }

    /**
     * If true, return the deleted documents.
     */
    bool getReturnDeleted() const { return _returnDeleted; }
    void setReturnDeleted(bool value) & {  _returnDeleted = std::move(value);  }

    /**
     * The yielding policy of the plan executor.
     */
    const PlanYieldPolicy::YieldPolicy& getYieldPolicy() const { return _yieldPolicy; }
    void setYieldPolicy(PlanYieldPolicy::YieldPolicy value) & {  _yieldPolicy = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::NamespaceString _nsString;
    mongo::BSONObj _hint;
    mongo::BSONObj _query;
    mongo::BSONObj _proj;
    mongo::BSONObj _sort;
    mongo::BSONObj _collation;
    boost::optional<mongo::BSONObj> _let;
    boost::optional<mongo::LegacyRuntimeConstants> _legacyRuntimeConstants;
    mongo::StmtId _stmtId{kUninitializedStmtId};
    bool _multi{false};
    bool _god{false};
    bool _fromMigrate{false};
    bool _isExplain{false};
    bool _returnDeleted{false};
    PlanYieldPolicy::YieldPolicy _yieldPolicy{PlanYieldPolicy::YieldPolicy::NO_YIELD};
    bool _hasNsString : 1;
    bool _hasHint : 1;
    bool _hasQuery : 1;
    bool _hasProj : 1;
    bool _hasSort : 1;
    bool _hasCollation : 1;
};

}  // namespace mongo
