/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/query/kill_cursors_gen.h --output build/opt/mongo/db/query/kill_cursors_gen.cpp src/mongo/db/query/kill_cursors.idl
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
#include "mongo/db/cursor_id.h"
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
 * Response from killCursors command
 */
class KillCursorsCommandReply {
public:
    static constexpr auto kCursorsAliveFieldName = "cursorsAlive"_sd;
    static constexpr auto kCursorsKilledFieldName = "cursorsKilled"_sd;
    static constexpr auto kCursorsNotFoundFieldName = "cursorsNotFound"_sd;
    static constexpr auto kCursorsUnknownFieldName = "cursorsUnknown"_sd;

    KillCursorsCommandReply();
    KillCursorsCommandReply(std::vector<mongo::CursorId> cursorsKilled, std::vector<mongo::CursorId> cursorsNotFound, std::vector<mongo::CursorId> cursorsAlive, std::vector<mongo::CursorId> cursorsUnknown);

    static KillCursorsCommandReply parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Cursors successfully killed
     */
    const std::vector<mongo::CursorId>& getCursorsKilled() const& { return _cursorsKilled; }
    void getCursorsKilled() && = delete;
    void setCursorsKilled(std::vector<mongo::CursorId> value) & {  _cursorsKilled = std::move(value); _hasCursorsKilled = true; }

    /**
     * Cursors not found
     */
    const std::vector<mongo::CursorId>& getCursorsNotFound() const& { return _cursorsNotFound; }
    void getCursorsNotFound() && = delete;
    void setCursorsNotFound(std::vector<mongo::CursorId> value) & {  _cursorsNotFound = std::move(value); _hasCursorsNotFound = true; }

    /**
     * Cursors still alive
     */
    const std::vector<mongo::CursorId>& getCursorsAlive() const& { return _cursorsAlive; }
    void getCursorsAlive() && = delete;
    void setCursorsAlive(std::vector<mongo::CursorId> value) & {  _cursorsAlive = std::move(value); _hasCursorsAlive = true; }

    /**
     * Unknown cursors
     */
    const std::vector<mongo::CursorId>& getCursorsUnknown() const& { return _cursorsUnknown; }
    void getCursorsUnknown() && = delete;
    void setCursorsUnknown(std::vector<mongo::CursorId> value) & {  _cursorsUnknown = std::move(value); _hasCursorsUnknown = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    std::vector<mongo::CursorId> _cursorsKilled;
    std::vector<mongo::CursorId> _cursorsNotFound;
    std::vector<mongo::CursorId> _cursorsAlive;
    std::vector<mongo::CursorId> _cursorsUnknown;
    bool _hasCursorsKilled : 1;
    bool _hasCursorsNotFound : 1;
    bool _hasCursorsAlive : 1;
    bool _hasCursorsUnknown : 1;
};

/**
 * Kills a specified set of cursors by ID.
 */
class KillCursorsCommandRequest {
public:
    using Reply = mongo::KillCursorsCommandReply;
    static constexpr auto kCursorIdsFieldName = "cursors"_sd;
    static constexpr auto kDbNameFieldName = "$db"_sd;
    static constexpr auto kCommandName = "killCursors"_sd;

    static AuthorizationContract kAuthorizationContract;

    explicit KillCursorsCommandRequest(const NamespaceString nss);
    KillCursorsCommandRequest(const NamespaceString nss, std::vector<mongo::CursorId> cursorIds);

    static KillCursorsCommandRequest parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    static KillCursorsCommandRequest parse(const IDLParserErrorContext& ctxt, const OpMsgRequest& request);
    void serialize(const BSONObj& commandPassthroughFields, BSONObjBuilder* builder) const;
    OpMsgRequest serialize(const BSONObj& commandPassthroughFields) const;
    BSONObj toBSON(const BSONObj& commandPassthroughFields) const;

    const NamespaceString& getNamespace() const { return _nss; }

    /**
     * An array of cursor IDs to be killed.
     */
    const std::vector<mongo::CursorId>& getCursorIds() const& { return _cursorIds; }
    void getCursorIds() && = delete;
    void setCursorIds(std::vector<mongo::CursorId> value) & {  _cursorIds = std::move(value); _hasCursorIds = true; }

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

    std::vector<mongo::CursorId> _cursorIds;
    std::string _dbName;
    bool _hasCursorIds : 1;
    bool _hasDbName : 1;
};


template <typename Derived>
class KillCursorsCmdVersion1Gen : public TypedCommand<Derived> {
    using _TypedCommandInvocationBase = typename TypedCommand<Derived>::InvocationBase;

public:
    using Request = KillCursorsCommandRequest;
    using Reply = mongo::KillCursorsCommandReply;

    virtual ~KillCursorsCmdVersion1Gen() = default;

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
