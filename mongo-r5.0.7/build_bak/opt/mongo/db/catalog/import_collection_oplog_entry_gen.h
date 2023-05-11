/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/catalog/import_collection_oplog_entry_gen.h --output build/opt/mongo/db/catalog/import_collection_oplog_entry_gen.cpp src/mongo/db/catalog/import_collection_oplog_entry.idl
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
 * The object field of an importCollection oplog entry
 */
class ImportCollectionOplogEntry {
public:
    static constexpr auto kCatalogEntryFieldName = "catalogEntry"_sd;
    static constexpr auto kDataSizeFieldName = "dataSize"_sd;
    static constexpr auto kDryRunFieldName = "dryRun"_sd;
    static constexpr auto kImportCollectionFieldName = "importCollection"_sd;
    static constexpr auto kImportUUIDFieldName = "importUUID"_sd;
    static constexpr auto kNumRecordsFieldName = "numRecords"_sd;
    static constexpr auto kStorageMetadataFieldName = "storageMetadata"_sd;

    ImportCollectionOplogEntry();
    ImportCollectionOplogEntry(mongo::NamespaceString importCollection, mongo::UUID importUUID, std::int64_t numRecords, std::int64_t dataSize, mongo::BSONObj catalogEntry, mongo::BSONObj storageMetadata, bool dryRun);

    static ImportCollectionOplogEntry parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);
    void serialize(BSONObjBuilder* builder) const;
    BSONObj toBSON() const;

    /**
     * Namespace of the collection being imported
     */
    const mongo::NamespaceString& getImportCollection() const { return _importCollection; }
    void setImportCollection(mongo::NamespaceString value) & {  _importCollection = std::move(value); _hasImportCollection = true; }

    /**
     * Identifies the import operation
     */
    const mongo::UUID& getImportUUID() const { return _importUUID; }
    void setImportUUID(mongo::UUID value) & {  _importUUID = std::move(value); _hasImportUUID = true; }

    /**
     * Number of records in the collection
     */
    std::int64_t getNumRecords() const { return _numRecords; }
    void setNumRecords(std::int64_t value) & {  _numRecords = std::move(value); _hasNumRecords = true; }

    /**
     * Date size of the collection
     */
    std::int64_t getDataSize() const { return _dataSize; }
    void setDataSize(std::int64_t value) & {  _dataSize = std::move(value); _hasDataSize = true; }

    /**
     * Catalog entry corresponding to the collection
     */
    const mongo::BSONObj& getCatalogEntry() const { return _catalogEntry; }
    void setCatalogEntry(mongo::BSONObj value) & {  _catalogEntry = std::move(value); _hasCatalogEntry = true; }

    /**
     * Contains the storage engines file and table metadata for each ident
     */
    const mongo::BSONObj& getStorageMetadata() const { return _storageMetadata; }
    void setStorageMetadata(mongo::BSONObj value) & {  _storageMetadata = std::move(value); _hasStorageMetadata = true; }

    /**
     * Import as a dryRun when true
     */
    bool getDryRun() const { return _dryRun; }
    void setDryRun(bool value) & {  _dryRun = std::move(value); _hasDryRun = true; }

protected:
    void parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject);

private:
    mongo::NamespaceString _importCollection;
    mongo::UUID _importUUID;
    std::int64_t _numRecords;
    std::int64_t _dataSize;
    mongo::BSONObj _catalogEntry;
    mongo::BSONObj _storageMetadata;
    bool _dryRun;
    bool _hasImportCollection : 1;
    bool _hasImportUUID : 1;
    bool _hasNumRecords : 1;
    bool _hasDataSize : 1;
    bool _hasCatalogEntry : 1;
    bool _hasStorageMetadata : 1;
    bool _hasDryRun : 1;
};

}  // namespace mongo
