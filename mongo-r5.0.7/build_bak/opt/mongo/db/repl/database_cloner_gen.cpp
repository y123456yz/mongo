/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/repl/database_cloner_gen.h --output build/opt/mongo/db/repl/database_cloner_gen.cpp src/mongo/db/repl/database_cloner.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/repl/database_cloner_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {
namespace repl {

constexpr StringData CollectionInfo::kReadOnlyFieldName;
constexpr StringData CollectionInfo::kUuidFieldName;


CollectionInfo::CollectionInfo() : _uuid(mongo::idl::preparsedValue<decltype(_uuid)>()), _hasUuid(false) {
    // Used for initialization only
}
CollectionInfo::CollectionInfo(mongo::UUID uuid) : _uuid(std::move(uuid)), _hasUuid(true) {
    // Used for initialization only
}


CollectionInfo CollectionInfo::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<CollectionInfo>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void CollectionInfo::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kReadOnlyBit = 0;
    const size_t kUuidBit = 1;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kReadOnlyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kReadOnlyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kReadOnlyBit);

                _readOnly = element.boolean();
            }
        }
        else if (fieldName == kUuidFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kUuidBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUuidBit);

                _hasUuid = true;
                _uuid = UUID(uassertStatusOK(UUID::parse(element)));
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
        if (!usedFields[kUuidBit]) {
            ctxt.throwMissingField(kUuidFieldName);
        }
    }

}


void CollectionInfo::serialize(BSONObjBuilder* builder) const {
    invariant(_hasUuid);

    if (_readOnly.is_initialized()) {
        builder->append(kReadOnlyFieldName, _readOnly.get());
    }

    {
        ConstDataRange tempCDR = _uuid.toCDR();
        builder->append(kUuidFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

}


BSONObj CollectionInfo::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData ListCollectionResult::kInfoFieldName;
constexpr StringData ListCollectionResult::kNameFieldName;
constexpr StringData ListCollectionResult::kOptionsFieldName;
constexpr StringData ListCollectionResult::kTypeFieldName;


ListCollectionResult::ListCollectionResult() : _name(mongo::idl::preparsedValue<decltype(_name)>()), _type(mongo::idl::preparsedValue<decltype(_type)>()), _options(mongo::idl::preparsedValue<decltype(_options)>()), _info(mongo::idl::preparsedValue<decltype(_info)>()), _hasName(false), _hasType(false), _hasOptions(false), _hasInfo(false) {
    // Used for initialization only
}
ListCollectionResult::ListCollectionResult(std::string name, std::string type, mongo::CollectionOptions options, mongo::repl::CollectionInfo info) : _name(std::move(name)), _type(std::move(type)), _options(std::move(options)), _info(std::move(info)), _hasName(true), _hasType(true), _hasOptions(true), _hasInfo(true) {
    // Used for initialization only
}


ListCollectionResult ListCollectionResult::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ListCollectionResult>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ListCollectionResult::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<4> usedFields;
    const size_t kNameBit = 0;
    const size_t kTypeBit = 1;
    const size_t kOptionsBit = 2;
    const size_t kInfoBit = 3;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kNameFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kNameBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNameBit);

                _hasName = true;
                _name = element.str();
            }
        }
        else if (fieldName == kTypeFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kTypeBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTypeBit);

                _hasType = true;
                _type = element.str();
            }
        }
        else if (fieldName == kOptionsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kOptionsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kOptionsBit);

                _hasOptions = true;
                const BSONObj localObject = element.Obj();
                _options = repl::parseCollectionOptionsForDatabaseCloner(localObject);
            }
        }
        else if (fieldName == kInfoFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kInfoBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kInfoBit);

                _hasInfo = true;
                IDLParserErrorContext tempContext(kInfoFieldName, &ctxt);
                const auto localObject = element.Obj();
                _info = mongo::repl::CollectionInfo::parse(tempContext, localObject);
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
        if (!usedFields[kNameBit]) {
            ctxt.throwMissingField(kNameFieldName);
        }
        if (!usedFields[kTypeBit]) {
            ctxt.throwMissingField(kTypeFieldName);
        }
        if (!usedFields[kOptionsBit]) {
            ctxt.throwMissingField(kOptionsFieldName);
        }
        if (!usedFields[kInfoBit]) {
            ctxt.throwMissingField(kInfoFieldName);
        }
    }

}


void ListCollectionResult::serialize(BSONObjBuilder* builder) const {
    invariant(_hasName && _hasType && _hasOptions && _hasInfo);

    builder->append(kNameFieldName, _name);

    builder->append(kTypeFieldName, _type);

    {
        const BSONObj localObject = _options.toBSON();
        builder->append(kOptionsFieldName, localObject);
    }

    {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kInfoFieldName));
        _info.serialize(&subObjBuilder);
    }

}


BSONObj ListCollectionResult::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace repl
}  // namespace mongo
