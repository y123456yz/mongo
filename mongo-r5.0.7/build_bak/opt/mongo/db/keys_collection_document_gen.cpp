/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/keys_collection_document_gen.h --output build/opt/mongo/db/keys_collection_document_gen.cpp src/mongo/db/keys_collection_document.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/keys_collection_document_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData KeysCollectionDocumentBase::kExpiresAtFieldName;
constexpr StringData KeysCollectionDocumentBase::kKeyFieldName;
constexpr StringData KeysCollectionDocumentBase::kPurposeFieldName;


KeysCollectionDocumentBase::KeysCollectionDocumentBase() : _purpose(mongo::idl::preparsedValue<decltype(_purpose)>()), _key(mongo::idl::preparsedValue<decltype(_key)>()), _expiresAt(mongo::idl::preparsedValue<decltype(_expiresAt)>()), _hasPurpose(false), _hasKey(false), _hasExpiresAt(false) {
    // Used for initialization only
}
KeysCollectionDocumentBase::KeysCollectionDocumentBase(std::string purpose, mongo::SHA1Block key, mongo::LogicalTime expiresAt) : _purpose(std::move(purpose)), _key(std::move(key)), _expiresAt(std::move(expiresAt)), _hasPurpose(true), _hasKey(true), _hasExpiresAt(true) {
    // Used for initialization only
}


KeysCollectionDocumentBase KeysCollectionDocumentBase::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<KeysCollectionDocumentBase>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void KeysCollectionDocumentBase::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<3> usedFields;
    const size_t kPurposeBit = 0;
    const size_t kKeyBit = 1;
    const size_t kExpiresAtBit = 2;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kPurposeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kPurposeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPurposeBit);

                _hasPurpose = true;
                _purpose = element.str();
            }
        }
        else if (fieldName == kKeyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, BinDataGeneral))) {
                if (MONGO_unlikely(usedFields[kKeyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kKeyBit);

                _hasKey = true;
                _key = SHA1Block::fromBinData(element._binDataVector());
            }
        }
        else if (fieldName == kExpiresAtFieldName) {
            if (MONGO_unlikely(usedFields[kExpiresAtBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kExpiresAtBit);

            _hasExpiresAt = true;
            _expiresAt = LogicalTime::parseFromBSON(element);
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kPurposeBit]) {
            ctxt.throwMissingField(kPurposeFieldName);
        }
        if (!usedFields[kKeyBit]) {
            ctxt.throwMissingField(kKeyFieldName);
        }
        if (!usedFields[kExpiresAtBit]) {
            ctxt.throwMissingField(kExpiresAtFieldName);
        }
    }

}


void KeysCollectionDocumentBase::serialize(BSONObjBuilder* builder) const {
    invariant(_hasPurpose && _hasKey && _hasExpiresAt);

    builder->append(kPurposeFieldName, _purpose);

    {
        ConstDataRange tempCDR = _key.toCDR();
        builder->append(kKeyFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), BinDataGeneral));
    }

    {
        _expiresAt.serializeToBSON(kExpiresAtFieldName, builder);
    }

}


BSONObj KeysCollectionDocumentBase::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData KeysCollectionDocument::kExpiresAtFieldName;
constexpr StringData KeysCollectionDocument::kKeyFieldName;
constexpr StringData KeysCollectionDocument::kKeyIdFieldName;
constexpr StringData KeysCollectionDocument::kKeysCollectionDocumentBaseFieldName;
constexpr StringData KeysCollectionDocument::kPurposeFieldName;


KeysCollectionDocument::KeysCollectionDocument() : _keyId(mongo::idl::preparsedValue<decltype(_keyId)>()), _hasKeyId(false) {
    // Used for initialization only
}
KeysCollectionDocument::KeysCollectionDocument(std::int64_t keyId) : _keyId(std::move(keyId)), _hasKeyId(true) {
    // Used for initialization only
}


KeysCollectionDocument KeysCollectionDocument::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<KeysCollectionDocument>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void KeysCollectionDocument::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<5> usedFields;
    const size_t kPurposeBit = 0;
    const size_t kKeyBit = 1;
    const size_t kExpiresAtBit = 2;
    const size_t kKeyIdBit = 3;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kPurposeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kPurposeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPurposeBit);

                _keysCollectionDocumentBase.setPurpose(element.str());
            }
        }
        else if (fieldName == kKeyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, BinDataGeneral))) {
                if (MONGO_unlikely(usedFields[kKeyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kKeyBit);

                _keysCollectionDocumentBase.setKey(SHA1Block::fromBinData(element._binDataVector()));
            }
        }
        else if (fieldName == kExpiresAtFieldName) {
            if (MONGO_unlikely(usedFields[kExpiresAtBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kExpiresAtBit);

            _keysCollectionDocumentBase.setExpiresAt(LogicalTime::parseFromBSON(element));
        }
        else if (fieldName == kKeyIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kKeyIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kKeyIdBit);

                _hasKeyId = true;
                _keyId = element.safeNumberLong();
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kPurposeBit]) {
            ctxt.throwMissingField(kPurposeFieldName);
        }
        if (!usedFields[kKeyBit]) {
            ctxt.throwMissingField(kKeyFieldName);
        }
        if (!usedFields[kExpiresAtBit]) {
            ctxt.throwMissingField(kExpiresAtFieldName);
        }
        if (!usedFields[kKeyIdBit]) {
            ctxt.throwMissingField(kKeyIdFieldName);
        }
    }

}


void KeysCollectionDocument::serialize(BSONObjBuilder* builder) const {
    invariant(_hasKeyId);

    {
        _keysCollectionDocumentBase.serialize(builder);
    }

    builder->append(kKeyIdFieldName, _keyId);

}


BSONObj KeysCollectionDocument::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData ExternalKeysCollectionDocument::kTTLExpiresAtFieldName;
constexpr StringData ExternalKeysCollectionDocument::kExpiresAtFieldName;
constexpr StringData ExternalKeysCollectionDocument::kIdFieldName;
constexpr StringData ExternalKeysCollectionDocument::kKeyFieldName;
constexpr StringData ExternalKeysCollectionDocument::kKeyIdFieldName;
constexpr StringData ExternalKeysCollectionDocument::kKeysCollectionDocumentBaseFieldName;
constexpr StringData ExternalKeysCollectionDocument::kMigrationIdFieldName;
constexpr StringData ExternalKeysCollectionDocument::kPurposeFieldName;


ExternalKeysCollectionDocument::ExternalKeysCollectionDocument() : _id(mongo::idl::preparsedValue<decltype(_id)>()), _keyId(mongo::idl::preparsedValue<decltype(_keyId)>()), _migrationId(mongo::idl::preparsedValue<decltype(_migrationId)>()), _hasId(false), _hasKeyId(false), _hasMigrationId(false) {
    // Used for initialization only
}
ExternalKeysCollectionDocument::ExternalKeysCollectionDocument(mongo::OID id, std::int64_t keyId, mongo::UUID migrationId) : _id(std::move(id)), _keyId(std::move(keyId)), _migrationId(std::move(migrationId)), _hasId(true), _hasKeyId(true), _hasMigrationId(true) {
    // Used for initialization only
}


ExternalKeysCollectionDocument ExternalKeysCollectionDocument::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ExternalKeysCollectionDocument>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ExternalKeysCollectionDocument::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<8> usedFields;
    const size_t kPurposeBit = 0;
    const size_t kKeyBit = 1;
    const size_t kExpiresAtBit = 2;
    const size_t kIdBit = 3;
    const size_t kKeyIdBit = 4;
    const size_t kMigrationIdBit = 5;
    const size_t kTTLExpiresAtBit = 6;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kPurposeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kPurposeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPurposeBit);

                _keysCollectionDocumentBase.setPurpose(element.str());
            }
        }
        else if (fieldName == kKeyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, BinDataGeneral))) {
                if (MONGO_unlikely(usedFields[kKeyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kKeyBit);

                _keysCollectionDocumentBase.setKey(SHA1Block::fromBinData(element._binDataVector()));
            }
        }
        else if (fieldName == kExpiresAtFieldName) {
            if (MONGO_unlikely(usedFields[kExpiresAtBit])) {
                ctxt.throwDuplicateField(element);
            }

            usedFields.set(kExpiresAtBit);

            _keysCollectionDocumentBase.setExpiresAt(LogicalTime::parseFromBSON(element));
        }
        else if (fieldName == kIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, jstOID))) {
                if (MONGO_unlikely(usedFields[kIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIdBit);

                _hasId = true;
                _id = element.OID();
            }
        }
        else if (fieldName == kKeyIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kKeyIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kKeyIdBit);

                _hasKeyId = true;
                _keyId = element.safeNumberLong();
            }
        }
        else if (fieldName == kMigrationIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kMigrationIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMigrationIdBit);

                _hasMigrationId = true;
                _migrationId = UUID(uassertStatusOK(UUID::parse(element)));
            }
        }
        else if (fieldName == kTTLExpiresAtFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Date))) {
                if (MONGO_unlikely(usedFields[kTTLExpiresAtBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTTLExpiresAtBit);

                _tTLExpiresAt = element.date();
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kPurposeBit]) {
            ctxt.throwMissingField(kPurposeFieldName);
        }
        if (!usedFields[kKeyBit]) {
            ctxt.throwMissingField(kKeyFieldName);
        }
        if (!usedFields[kExpiresAtBit]) {
            ctxt.throwMissingField(kExpiresAtFieldName);
        }
        if (!usedFields[kIdBit]) {
            ctxt.throwMissingField(kIdFieldName);
        }
        if (!usedFields[kKeyIdBit]) {
            ctxt.throwMissingField(kKeyIdFieldName);
        }
        if (!usedFields[kMigrationIdBit]) {
            ctxt.throwMissingField(kMigrationIdFieldName);
        }
    }

}


void ExternalKeysCollectionDocument::serialize(BSONObjBuilder* builder) const {
    invariant(_hasId && _hasKeyId && _hasMigrationId);

    {
        _keysCollectionDocumentBase.serialize(builder);
    }

    builder->append(kIdFieldName, _id);

    builder->append(kKeyIdFieldName, _keyId);

    {
        ConstDataRange tempCDR = _migrationId.toCDR();
        builder->append(kMigrationIdFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    if (_tTLExpiresAt.is_initialized()) {
        builder->append(kTTLExpiresAtFieldName, _tTLExpiresAt.get());
    }

}


BSONObj ExternalKeysCollectionDocument::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
