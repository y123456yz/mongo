/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/drop_gen.h --output build/opt/mongo/db/drop_gen.cpp src/mongo/db/drop.idl
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
 * The drop command's reply.
 */
class DropReply {
public:
    static constexpr auto kInfoFieldName = "info"_sd;
    static constexpr auto kNIndexesWasFieldName = "nIndexesWas"_sd;
    static constexpr auto kNsFieldName = "ns"_sd;
    static constexpr auto kOkFieldName = "ok"_sd;

    DropReply();

    static DropReply parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    const boost::optional<std::int32_t> getNIndexesWas() const& { return _nIndexesWas; }
    void getNIndexesWas() && = delete;
    void setNIndexesWas(boost::optional<std::int32_t> value) & {  _nIndexesWas = std::move(value);  }

    const boost::optional<mongo::NamespaceString>& getNs() const& { return _ns; }
    void getNs() && = delete;
    void setNs(boost::optional<mongo::NamespaceString> value) & {  _ns = std::move(value);  }

    const boost::optional<StringData> getInfo() const& { return boost::optional<StringData>{_info}; }
    void getInfo() && = delete;
    void setInfo(boost::optional<StringData> value) & { if (value.is_initialized()) {
        auto _tmpValue = value.get().toString();
        
        _info = std::move(_tmpValue);
    } else {
        _info = boost::none;
    }
      }

    const boost::optional<double> getOk() const& { return _ok; }
    void getOk() && = delete;
    void setOk(boost::optional<double> value) & {  _ok = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    boost::optional<std::int32_t> _nIndexesWas;
    boost::optional<mongo::NamespaceString> _ns;
    boost::optional<std::string> _info;
    boost::optional<double> _ok;
};

/**
 * Parser for the drop command
 */
class Drop {
public:
    using Reply = mongo::DropReply;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kCommandName = "drop"_sd;

    static AuthorizationContract kAuthorizationContract;

    explicit Drop(const NamespaceString nss);

    static Drop parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static Drop parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const NamespaceString& getNamespace() const { return _nss; }

    const StringData getDbName() const& { return _dbName; }
    void getDbName() && = delete;
    void setDbName(StringData value) & { auto _tmpValue = value.toString();  _dbName = std::move(_tmpValue); _hasDbName = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void parseProtected(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);

private:
    static const std::vector<StringData> _knownBSONFields;
    static const std::vector<StringData> _knownOP_MSGFields;


    NamespaceString _nss;

    std::string _dbName;
    bool _hasDbName : 1;
};


template <typename Derived>
class DropCmdVersion1Gen : public TypedCommand<Derived> {
    using _TypedCommandInvocationBase = typename TypedCommand<Derived>::InvocationBase;

public:
    using Request = Drop;
    using Reply = mongo::DropReply;

    virtual ~DropCmdVersion1Gen() = default;

    virtual const std::set<std::string>& apiVersions() const final {
        return kApiVersions1;
    }
    virtual const std::set<std::string>& deprecatedApiVersions() const final {
        return kNoApiVersions;
    }
    const AuthorizationContract* getAuthorizationContract() const final { return &Request::kAuthorizationContract; } 

    class InvocationBaseGen : public _TypedCommandInvocationBase {
    public:
        using _TypedCommandInvocationBase::_TypedCommandInvocationBase;
        virtual Reply typedRun(OperationContext* opCtx) = 0;
    };
};
}  // namespace mongo
