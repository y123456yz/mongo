/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/stats/read_concern_stats_gen.h --output build/opt/mongo/db/stats/read_concern_stats_gen.cpp src/mongo/db/stats/read_concern_stats.idl
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
 * A struct representing the number of operations used with snapshot readConcern
 */
class SnapshotOps {
public:
    static constexpr auto kWithClusterTimeFieldName = "withClusterTime"_sd;
    static constexpr auto kWithoutClusterTimeFieldName = "withoutClusterTime"_sd;

    SnapshotOps();

    static SnapshotOps parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    std::int64_t getWithClusterTime() const { return _withClusterTime; }
    void setWithClusterTime(std::int64_t value) & {  _withClusterTime = std::move(value);  }

    std::int64_t getWithoutClusterTime() const { return _withoutClusterTime; }
    void setWithoutClusterTime(std::int64_t value) & {  _withoutClusterTime = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    std::int64_t _withClusterTime{0};
    std::int64_t _withoutClusterTime{0};
};

/**
 * A struct representing CWRC readConcern level usages by read operations
 */
class CWRCReadConcernOps {
public:
    static constexpr auto kAvailableFieldName = "available"_sd;
    static constexpr auto kLocalFieldName = "local"_sd;
    static constexpr auto kMajorityFieldName = "majority"_sd;

    CWRCReadConcernOps();

    static CWRCReadConcernOps parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    std::int64_t getLocal() const { return _local; }
    void setLocal(std::int64_t value) & {  _local = std::move(value);  }

    const boost::optional<std::int64_t> getAvailable() const& { return _available; }
    void getAvailable() && = delete;
    void setAvailable(boost::optional<std::int64_t> value) & {  _available = std::move(value);  }

    std::int64_t getMajority() const { return _majority; }
    void setMajority(std::int64_t value) & {  _majority = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    std::int64_t _local{0};
    boost::optional<std::int64_t> _available;
    std::int64_t _majority{0};
};

/**
 * A struct representing implict-default readConcern level usages by read operations
 */
class ImplicitDefaultReadConcernOps {
public:
    static constexpr auto kAvailableFieldName = "available"_sd;
    static constexpr auto kLocalFieldName = "local"_sd;

    ImplicitDefaultReadConcernOps();

    static ImplicitDefaultReadConcernOps parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    std::int64_t getLocal() const { return _local; }
    void setLocal(std::int64_t value) & {  _local = std::move(value);  }

    const boost::optional<std::int64_t> getAvailable() const& { return _available; }
    void getAvailable() && = delete;
    void setAvailable(boost::optional<std::int64_t> value) & {  _available = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    std::int64_t _local{0};
    boost::optional<std::int64_t> _available;
};

/**
 * A struct representing non-explicit readConcern level counters breakdown
 */
class NoneInfo {
public:
    static constexpr auto kCWRCFieldName = "CWRC"_sd;
    static constexpr auto kImplicitDefaultFieldName = "implicitDefault"_sd;

    NoneInfo();
    NoneInfo(mongo::CWRCReadConcernOps cWRC, mongo::ImplicitDefaultReadConcernOps implicitDefault);

    static NoneInfo parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    const mongo::CWRCReadConcernOps& getCWRC() const { return _cWRC; }
    mongo::CWRCReadConcernOps& getCWRC() { return _cWRC; }
    void setCWRC(mongo::CWRCReadConcernOps value) & {  _cWRC = std::move(value); _hasCWRC = true; }

    const mongo::ImplicitDefaultReadConcernOps& getImplicitDefault() const { return _implicitDefault; }
    mongo::ImplicitDefaultReadConcernOps& getImplicitDefault() { return _implicitDefault; }
    void setImplicitDefault(mongo::ImplicitDefaultReadConcernOps value) & {  _implicitDefault = std::move(value); _hasImplicitDefault = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::CWRCReadConcernOps _cWRC;
    mongo::ImplicitDefaultReadConcernOps _implicitDefault;
    bool _hasCWRC : 1;
    bool _hasImplicitDefault : 1;
};

/**
 * A struct representing readConcern level usages by read operations
 */
class ReadConcernOps {
public:
    static constexpr auto kAvailableFieldName = "available"_sd;
    static constexpr auto kLinearizableFieldName = "linearizable"_sd;
    static constexpr auto kLocalFieldName = "local"_sd;
    static constexpr auto kMajorityFieldName = "majority"_sd;
    static constexpr auto kNoneFieldName = "none"_sd;
    static constexpr auto kNoneInfoFieldName = "noneInfo"_sd;
    static constexpr auto kSnapshotFieldName = "snapshot"_sd;

    ReadConcernOps();
    ReadConcernOps(mongo::NoneInfo noneInfo, mongo::SnapshotOps snapshot);

    static ReadConcernOps parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    std::int64_t getNone() const { return _none; }
    void setNone(std::int64_t value) & {  _none = std::move(value);  }

    const mongo::NoneInfo& getNoneInfo() const { return _noneInfo; }
    mongo::NoneInfo& getNoneInfo() { return _noneInfo; }
    void setNoneInfo(mongo::NoneInfo value) & {  _noneInfo = std::move(value); _hasNoneInfo = true; }

    std::int64_t getLocal() const { return _local; }
    void setLocal(std::int64_t value) & {  _local = std::move(value);  }

    const boost::optional<std::int64_t> getAvailable() const& { return _available; }
    void getAvailable() && = delete;
    void setAvailable(boost::optional<std::int64_t> value) & {  _available = std::move(value);  }

    std::int64_t getMajority() const { return _majority; }
    void setMajority(std::int64_t value) & {  _majority = std::move(value);  }

    const mongo::SnapshotOps& getSnapshot() const { return _snapshot; }
    mongo::SnapshotOps& getSnapshot() { return _snapshot; }
    void setSnapshot(mongo::SnapshotOps value) & {  _snapshot = std::move(value); _hasSnapshot = true; }

    const boost::optional<std::int64_t> getLinearizable() const& { return _linearizable; }
    void getLinearizable() && = delete;
    void setLinearizable(boost::optional<std::int64_t> value) & {  _linearizable = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    std::int64_t _none{0};
    mongo::NoneInfo _noneInfo;
    std::int64_t _local{0};
    boost::optional<std::int64_t> _available;
    std::int64_t _majority{0};
    mongo::SnapshotOps _snapshot;
    boost::optional<std::int64_t> _linearizable;
    bool _hasNoneInfo : 1;
    bool _hasSnapshot : 1;
};

/**
 * A struct representing the section of the server status command with information about readConcern levels used by operations
 */
class ReadConcernStats {
public:
    static constexpr auto kNonTransactionOpsFieldName = "nonTransactionOps"_sd;
    static constexpr auto kTransactionOpsFieldName = "transactionOps"_sd;

    ReadConcernStats();
    ReadConcernStats(mongo::ReadConcernOps nonTransactionOps, mongo::ReadConcernOps transactionOps);

    static ReadConcernStats parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    const mongo::ReadConcernOps& getNonTransactionOps() const { return _nonTransactionOps; }
    mongo::ReadConcernOps& getNonTransactionOps() { return _nonTransactionOps; }
    void setNonTransactionOps(mongo::ReadConcernOps value) & {  _nonTransactionOps = std::move(value); _hasNonTransactionOps = true; }

    const mongo::ReadConcernOps& getTransactionOps() const { return _transactionOps; }
    mongo::ReadConcernOps& getTransactionOps() { return _transactionOps; }
    void setTransactionOps(mongo::ReadConcernOps value) & {  _transactionOps = std::move(value); _hasTransactionOps = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::ReadConcernOps _nonTransactionOps;
    mongo::ReadConcernOps _transactionOps;
    bool _hasNonTransactionOps : 1;
    bool _hasTransactionOps : 1;
};

}  // namespace mongo
