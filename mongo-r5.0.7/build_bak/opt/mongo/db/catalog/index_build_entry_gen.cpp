/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/catalog/index_build_entry_gen.h --output build/opt/mongo/db/catalog/index_build_entry_gen.cpp src/mongo/db/catalog/index_build_entry.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/catalog/index_build_entry_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData IndexBuildEntry::kBuildUUIDFieldName;
constexpr StringData IndexBuildEntry::kCollectionUUIDFieldName;
constexpr StringData IndexBuildEntry::kCommitQuorumFieldName;
constexpr StringData IndexBuildEntry::kCommitReadyMembersFieldName;
constexpr StringData IndexBuildEntry::kIndexNamesFieldName;


IndexBuildEntry::IndexBuildEntry() : _buildUUID(mongo::idl::preparsedValue<decltype(_buildUUID)>()), _collectionUUID(mongo::idl::preparsedValue<decltype(_collectionUUID)>()), _commitQuorum(mongo::idl::preparsedValue<decltype(_commitQuorum)>()), _hasBuildUUID(false), _hasCollectionUUID(false), _hasCommitQuorum(false), _hasIndexNames(false) {
    // Used for initialization only
}
IndexBuildEntry::IndexBuildEntry(mongo::UUID buildUUID, mongo::UUID collectionUUID, mongo::CommitQuorumOptions commitQuorum, std::vector<std::string> indexNames) : _buildUUID(std::move(buildUUID)), _collectionUUID(std::move(collectionUUID)), _commitQuorum(std::move(commitQuorum)), _indexNames(std::move(indexNames)), _hasBuildUUID(true), _hasCollectionUUID(true), _hasCommitQuorum(true), _hasIndexNames(true) {
    // Used for initialization only
}


IndexBuildEntry IndexBuildEntry::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<IndexBuildEntry>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void IndexBuildEntry::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<5> usedFields;
    const size_t kBuildUUIDBit = 0;
    const size_t kCollectionUUIDBit = 1;
    const size_t kCommitQuorumBit = 2;
    const size_t kIndexNamesBit = 3;
    const size_t kCommitReadyMembersBit = 4;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kBuildUUIDFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kBuildUUIDBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kBuildUUIDBit);

                _hasBuildUUID = true;
                _buildUUID = UUID(uassertStatusOK(UUID::parse(element)));
            }
        }
        else if (fieldName == kCollectionUUIDFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kCollectionUUIDBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollectionUUIDBit);

                _hasCollectionUUID = true;
                _collectionUUID = UUID(uassertStatusOK(UUID::parse(element)));
            }
        }
        else if (fieldName == kCommitQuorumFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble, String}))) {
                if (MONGO_unlikely(usedFields[kCommitQuorumBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCommitQuorumBit);

                _hasCommitQuorum = true;
                _commitQuorum = CommitQuorumOptions::deserializerForIDL(element);
            }
        }
        else if (fieldName == kIndexNamesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kIndexNamesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kIndexNamesBit);

                _hasIndexNames = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kIndexNamesFieldName, &ctxt);
            std::vector<std::string> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, String)) {
                        values.emplace_back(arrayElement.str());
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _indexNames = std::move(values);
        }
        else if (fieldName == kCommitReadyMembersFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kCommitReadyMembersBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCommitReadyMembersBit);

            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kCommitReadyMembersFieldName, &ctxt);
            std::vector<mongo::HostAndPort> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    if (arrayCtxt.checkAndAssertType(arrayElement, String)) {
                        values.emplace_back(HostAndPort::parseThrowing(arrayElement.valueStringData()));
                    }
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _commitReadyMembers = std::move(values);
        }
        else {
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kBuildUUIDBit]) {
            ctxt.throwMissingField(kBuildUUIDFieldName);
        }
        if (!usedFields[kCollectionUUIDBit]) {
            ctxt.throwMissingField(kCollectionUUIDFieldName);
        }
        if (!usedFields[kCommitQuorumBit]) {
            ctxt.throwMissingField(kCommitQuorumFieldName);
        }
        if (!usedFields[kIndexNamesBit]) {
            ctxt.throwMissingField(kIndexNamesFieldName);
        }
    }

}


void IndexBuildEntry::serialize(BSONObjBuilder* builder) const {
    invariant(_hasBuildUUID && _hasCollectionUUID && _hasCommitQuorum && _hasIndexNames);

    {
        ConstDataRange tempCDR = _buildUUID.toCDR();
        builder->append(kBuildUUIDFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    {
        ConstDataRange tempCDR = _collectionUUID.toCDR();
        builder->append(kCollectionUUIDFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    {
        _commitQuorum.appendToBuilder(kCommitQuorumFieldName, builder);
    }

    {
        builder->append(kIndexNamesFieldName, _indexNames);
    }

    if (_commitReadyMembers.is_initialized()) {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kCommitReadyMembersFieldName));
        for (const auto& item : _commitReadyMembers.get()) {
            arrayBuilder.append(item.toString());
        }
    }

}


BSONObj IndexBuildEntry::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
