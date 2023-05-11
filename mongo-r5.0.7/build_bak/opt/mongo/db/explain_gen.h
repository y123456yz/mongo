/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/explain_gen.h --output build/opt/mongo/db/explain_gen.cpp src/mongo/db/explain.idl
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
#include "mongo/db/commands.h"
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
 * Parser for the explain command
 */
class ExplainCommandRequest {
public:
    using Reply = mongo::OkReply;
    static constexpr auto kCommandParameterFieldName = "explain"_sd;
    static constexpr auto kCollationFieldName = "collation"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kUse44SortKeysFieldName = "use44SortKeys"_sd;
    static constexpr auto kUseNewUpsertFieldName = "useNewUpsert"_sd;
    static constexpr auto kVerbosityFieldName = "verbosity"_sd;
    static constexpr auto kCommandName = "explain"_sd;

    explicit ExplainCommandRequest(const mongo::BSONObj commandParameter);

    static ExplainCommandRequest parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static ExplainCommandRequest parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const mongo::BSONObj& getCommandParameter() const { return _commandParameter; }

    /**
     * The verbosity for explain command.
     */
    mongo::explain::VerbosityEnum getVerbosity() const { return _verbosity; }
    void setVerbosity(mongo::explain::VerbosityEnum value) & {  _verbosity = std::move(value);  }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;


    mongo::BSONObj _commandParameter;

    mongo::explain::VerbosityEnum _verbosity{mongo::explain::VerbosityEnum::kExecAllPlans};
    std::string _dbName;
    bool _hasDbName : 1;
};


template <typename Derived>
class ExplainCmdVersion1Gen : public TypedCommand<Derived> {
    using _TypedCommandInvocationBase = typename TypedCommand<Derived>::InvocationBase;

public:
    using Request = ExplainCommandRequest;
    using Reply = mongo::OkReply;

    virtual ~ExplainCmdVersion1Gen() = default;

    virtual const std::set<std::string>& apiVersions() const final {
        return kApiVersions1;
    }
    virtual const std::set<std::string>& deprecatedApiVersions() const final {
        return kNoApiVersions;
    }
    class InvocationBaseGen : public _TypedCommandInvocationBase {
    public:
        using _TypedCommandInvocationBase::_TypedCommandInvocationBase;
        virtual Reply typedRun(OperationContext* opCtx) = 0;
    };
};
}  // namespace mongo
