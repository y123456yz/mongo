/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/keys_collection_document_gen.h --output build/opt/mongo/db/keys_collection_document_gen.cpp src/mongo/db/keys_collection_document.idl
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
#include "mongo/crypto/sha1_block.h"
#include "mongo/db/logical_time.h"
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
 * Contains the fields shared by key documents stored in admin.system.keys and config.external_validation_keys.
 */
class KeysCollectionDocumentBase {
public:
    static constexpr auto kExpiresAtFieldName = "expiresAt"_sd;
    static constexpr auto kKeyFieldName = "key"_sd;
    static constexpr auto kPurposeFieldName = "purpose"_sd;

    KeysCollectionDocumentBase();
    KeysCollectionDocumentBase(std::string purpose, mongo::SHA1Block key, mongo::LogicalTime expiresAt);

    static KeysCollectionDocumentBase parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * The purpose of the key.
     */
    const StringData getPurpose() const& { return _purpose; }
    void getPurpose() && = delete;
    void setPurpose(StringData value) & { auto _tmpValue = value.toString();  _purpose = std::move(_tmpValue); _hasPurpose = true; }

    /**
     * 20 byte key generated with secure PRNG in BinData.
     */
    const mongo::SHA1Block& getKey() const { return _key; }
    void setKey(mongo::SHA1Block value) & {  _key = std::move(value); _hasKey = true; }

    /**
     * The logical time at which the key will expire.
     */
    const mongo::LogicalTime& getExpiresAt() const { return _expiresAt; }
    void setExpiresAt(mongo::LogicalTime value) & {  _expiresAt = std::move(value); _hasExpiresAt = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    std::string _purpose;
    mongo::SHA1Block _key;
    mongo::LogicalTime _expiresAt;
    bool _hasPurpose : 1;
    bool _hasKey : 1;
    bool _hasExpiresAt : 1;
};

/**
 * Represents a key document stored in admin.system.keys.
 */
class KeysCollectionDocument {
public:
    static constexpr auto kExpiresAtFieldName = "expiresAt"_sd;
    static constexpr auto kKeyFieldName = "key"_sd;
    static constexpr auto kKeyIdFieldName = "_id"_sd;
    static constexpr auto kKeysCollectionDocumentBaseFieldName = "keysCollectionDocumentBase"_sd;
    static constexpr auto kPurposeFieldName = "purpose"_sd;

    KeysCollectionDocument();
    KeysCollectionDocument(std::int64_t keyId);

    static KeysCollectionDocument parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Contains the fields shared by key documents stored in admin.system.keys and config.external_validation_keys.
     */
    const mongo::KeysCollectionDocumentBase& getKeysCollectionDocumentBase() const { return _keysCollectionDocumentBase; }
    mongo::KeysCollectionDocumentBase& getKeysCollectionDocumentBase() { return _keysCollectionDocumentBase; }
    void setKeysCollectionDocumentBase(mongo::KeysCollectionDocumentBase value) & {  _keysCollectionDocumentBase = std::move(value);  }

    /**
     * The purpose of the key.
     */
    const  StringData getPurpose() const { return _keysCollectionDocumentBase.getPurpose(); }
    /**
     * 20 byte key generated with secure PRNG in BinData.
     */
    const  mongo::SHA1Block& getKey() const { return _keysCollectionDocumentBase.getKey(); }
    /**
     * The logical time at which the key will expire.
     */
    const  mongo::LogicalTime& getExpiresAt() const { return _keysCollectionDocumentBase.getExpiresAt(); }
    /**
     * NumberLong representation of the cluster time at which the key was created.
     */
    std::int64_t getKeyId() const { return _keyId; }
    void setKeyId(std::int64_t value) & {  _keyId = std::move(value); _hasKeyId = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::KeysCollectionDocumentBase _keysCollectionDocumentBase;
    std::int64_t _keyId;
    bool _hasKeyId : 1;
};

/**
 * Represents a key document stored in config.external_validation_keys.
 */
class ExternalKeysCollectionDocument {
public:
    static constexpr auto kTTLExpiresAtFieldName = "ttlExpiresAt"_sd;
    static constexpr auto kExpiresAtFieldName = "expiresAt"_sd;
    static constexpr auto kIdFieldName = "_id"_sd;
    static constexpr auto kKeyFieldName = "key"_sd;
    static constexpr auto kKeyIdFieldName = "keyId"_sd;
    static constexpr auto kKeysCollectionDocumentBaseFieldName = "keysCollectionDocumentBase"_sd;
    static constexpr auto kMigrationIdFieldName = "migrationId"_sd;
    static constexpr auto kPurposeFieldName = "purpose"_sd;

    ExternalKeysCollectionDocument();
    ExternalKeysCollectionDocument(mongo::OID id, std::int64_t keyId, mongo::UUID migrationId);

    static ExternalKeysCollectionDocument parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Contains the fields shared by key documents stored in admin.system.keys and config.external_validation_keys.
     */
    const mongo::KeysCollectionDocumentBase& getKeysCollectionDocumentBase() const { return _keysCollectionDocumentBase; }
    mongo::KeysCollectionDocumentBase& getKeysCollectionDocumentBase() { return _keysCollectionDocumentBase; }
    void setKeysCollectionDocumentBase(mongo::KeysCollectionDocumentBase value) & {  _keysCollectionDocumentBase = std::move(value);  }

    /**
     * The purpose of the key.
     */
    const  StringData getPurpose() const { return _keysCollectionDocumentBase.getPurpose(); }
    /**
     * 20 byte key generated with secure PRNG in BinData.
     */
    const  mongo::SHA1Block& getKey() const { return _keysCollectionDocumentBase.getKey(); }
    /**
     * The logical time at which the key will expire.
     */
    const  mongo::LogicalTime& getExpiresAt() const { return _keysCollectionDocumentBase.getExpiresAt(); }
    /**
     * Unique identifier for this key document.
     */
    const mongo::OID& getId() const { return _id; }
    void setId(mongo::OID value) & {  _id = std::move(value); _hasId = true; }

    /**
     * NumberLong representation of the cluster time at which the key was created. Corresponds to the _id of the admin.system.keys document for this key.
     */
    std::int64_t getKeyId() const { return _keyId; }
    void setKeyId(std::int64_t value) & {  _keyId = std::move(value); _hasKeyId = true; }

    /**
     * The id of the tenant migration that inserted this key.
     */
    const mongo::UUID& getMigrationId() const { return _migrationId; }
    void setMigrationId(mongo::UUID value) & {  _migrationId = std::move(value); _hasMigrationId = true; }

    /**
     * The wall-clock time at which this key document should be removed by the TTL monitor.
     */
    const boost::optional<mongo::Date_t>& getTTLExpiresAt() const& { return _tTLExpiresAt; }
    void getTTLExpiresAt() && = delete;
    void setTTLExpiresAt(boost::optional<mongo::Date_t> value) & {  _tTLExpiresAt = std::move(value);  }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::KeysCollectionDocumentBase _keysCollectionDocumentBase;
    mongo::OID _id;
    std::int64_t _keyId;
    mongo::UUID _migrationId;
    boost::optional<mongo::Date_t> _tTLExpiresAt;
    bool _hasId : 1;
    bool _hasKeyId : 1;
    bool _hasMigrationId : 1;
};

}  // namespace mongo
