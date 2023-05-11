/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/catalog/import_collection_oplog_entry_gen.h --output build/opt/mongo/db/catalog/import_collection_oplog_entry_gen.cpp src/mongo/db/catalog/import_collection_oplog_entry.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/catalog/import_collection_oplog_entry_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData ImportCollectionOplogEntry::kCatalogEntryFieldName;
constexpr StringData ImportCollectionOplogEntry::kDataSizeFieldName;
constexpr StringData ImportCollectionOplogEntry::kDryRunFieldName;
constexpr StringData ImportCollectionOplogEntry::kImportCollectionFieldName;
constexpr StringData ImportCollectionOplogEntry::kImportUUIDFieldName;
constexpr StringData ImportCollectionOplogEntry::kNumRecordsFieldName;
constexpr StringData ImportCollectionOplogEntry::kStorageMetadataFieldName;


ImportCollectionOplogEntry::ImportCollectionOplogEntry() : _importCollection(mongo::idl::preparsedValue<decltype(_importCollection)>()), _importUUID(mongo::idl::preparsedValue<decltype(_importUUID)>()), _numRecords(mongo::idl::preparsedValue<decltype(_numRecords)>()), _dataSize(mongo::idl::preparsedValue<decltype(_dataSize)>()), _catalogEntry(mongo::idl::preparsedValue<decltype(_catalogEntry)>()), _storageMetadata(mongo::idl::preparsedValue<decltype(_storageMetadata)>()), _dryRun(mongo::idl::preparsedValue<decltype(_dryRun)>()), _hasImportCollection(false), _hasImportUUID(false), _hasNumRecords(false), _hasDataSize(false), _hasCatalogEntry(false), _hasStorageMetadata(false), _hasDryRun(false) {
    // Used for initialization only
}
ImportCollectionOplogEntry::ImportCollectionOplogEntry(mongo::NamespaceString importCollection, mongo::UUID importUUID, std::int64_t numRecords, std::int64_t dataSize, mongo::BSONObj catalogEntry, mongo::BSONObj storageMetadata, bool dryRun) : _importCollection(std::move(importCollection)), _importUUID(std::move(importUUID)), _numRecords(std::move(numRecords)), _dataSize(std::move(dataSize)), _catalogEntry(std::move(catalogEntry)), _storageMetadata(std::move(storageMetadata)), _dryRun(std::move(dryRun)), _hasImportCollection(true), _hasImportUUID(true), _hasNumRecords(true), _hasDataSize(true), _hasCatalogEntry(true), _hasStorageMetadata(true), _hasDryRun(true) {
    // Used for initialization only
}


ImportCollectionOplogEntry ImportCollectionOplogEntry::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ImportCollectionOplogEntry>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ImportCollectionOplogEntry::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<7> usedFields;
    const size_t kImportCollectionBit = 0;
    const size_t kImportUUIDBit = 1;
    const size_t kNumRecordsBit = 2;
    const size_t kDataSizeBit = 3;
    const size_t kCatalogEntryBit = 4;
    const size_t kStorageMetadataBit = 5;
    const size_t kDryRunBit = 6;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kImportCollectionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kImportCollectionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kImportCollectionBit);

                _hasImportCollection = true;
                _importCollection = NamespaceString(element.valueStringData());
            }
        }
        else if (fieldName == kImportUUIDFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kImportUUIDBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kImportUUIDBit);

                _hasImportUUID = true;
                _importUUID = UUID(uassertStatusOK(UUID::parse(element)));
            }
        }
        else if (fieldName == kNumRecordsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kNumRecordsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNumRecordsBit);

                _hasNumRecords = true;
                _numRecords = element._numberLong();
            }
        }
        else if (fieldName == kDataSizeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kDataSizeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDataSizeBit);

                _hasDataSize = true;
                _dataSize = element._numberLong();
            }
        }
        else if (fieldName == kCatalogEntryFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCatalogEntryBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCatalogEntryBit);

                _hasCatalogEntry = true;
                _catalogEntry = element.Obj();
            }
        }
        else if (fieldName == kStorageMetadataFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kStorageMetadataBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStorageMetadataBit);

                _hasStorageMetadata = true;
                _storageMetadata = element.Obj();
            }
        }
        else if (fieldName == kDryRunFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kDryRunBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDryRunBit);

                _hasDryRun = true;
                _dryRun = element.boolean();
            }
        }
        else {
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kImportCollectionBit]) {
            ctxt.throwMissingField(kImportCollectionFieldName);
        }
        if (!usedFields[kImportUUIDBit]) {
            ctxt.throwMissingField(kImportUUIDFieldName);
        }
        if (!usedFields[kNumRecordsBit]) {
            ctxt.throwMissingField(kNumRecordsFieldName);
        }
        if (!usedFields[kDataSizeBit]) {
            ctxt.throwMissingField(kDataSizeFieldName);
        }
        if (!usedFields[kCatalogEntryBit]) {
            ctxt.throwMissingField(kCatalogEntryFieldName);
        }
        if (!usedFields[kStorageMetadataBit]) {
            ctxt.throwMissingField(kStorageMetadataFieldName);
        }
        if (!usedFields[kDryRunBit]) {
            ctxt.throwMissingField(kDryRunFieldName);
        }
    }

}


void ImportCollectionOplogEntry::serialize(BSONObjBuilder* builder) const {
    invariant(_hasImportCollection && _hasImportUUID && _hasNumRecords && _hasDataSize && _hasCatalogEntry && _hasStorageMetadata && _hasDryRun);

    {
        builder->append(kImportCollectionFieldName, _importCollection.toString());
    }

    {
        ConstDataRange tempCDR = _importUUID.toCDR();
        builder->append(kImportUUIDFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    builder->append(kNumRecordsFieldName, _numRecords);

    builder->append(kDataSizeFieldName, _dataSize);

    builder->append(kCatalogEntryFieldName, _catalogEntry);

    builder->append(kStorageMetadataFieldName, _storageMetadata);

    builder->append(kDryRunFieldName, _dryRun);

}


BSONObj ImportCollectionOplogEntry::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
