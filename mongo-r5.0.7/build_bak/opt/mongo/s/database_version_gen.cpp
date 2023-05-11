/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/s/database_version_gen.h --output build/opt/mongo/s/database_version_gen.cpp src/mongo/s/database_version.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/s/database_version_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData DatabaseVersionBase::kLastModFieldName;
constexpr StringData DatabaseVersionBase::kTimestampFieldName;
constexpr StringData DatabaseVersionBase::kUuidFieldName;


DatabaseVersionBase::DatabaseVersionBase() : _lastMod(mongo::idl::preparsedValue<decltype(_lastMod)>()), _hasLastMod(false) {
    // Used for initialization only
}
DatabaseVersionBase::DatabaseVersionBase(std::int32_t lastMod) : _lastMod(std::move(lastMod)), _hasLastMod(true) {
    // Used for initialization only
}


DatabaseVersionBase DatabaseVersionBase::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<DatabaseVersionBase>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void DatabaseVersionBase::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<3> usedFields;
    const size_t kUuidBit = 0;
    const size_t kTimestampBit = 1;
    const size_t kLastModBit = 2;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kUuidFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertBinDataType(element, newUUID))) {
                if (MONGO_unlikely(usedFields[kUuidBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUuidBit);

                _uuid = UUID(uassertStatusOK(UUID::parse(element)));
            }
        }
        else if (fieldName == kTimestampFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, bsonTimestamp))) {
                if (MONGO_unlikely(usedFields[kTimestampBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTimestampBit);

                _timestamp = element.timestamp();
            }
        }
        else if (fieldName == kLastModFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberInt))) {
                if (MONGO_unlikely(usedFields[kLastModBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kLastModBit);

                _hasLastMod = true;
                _lastMod = element._numberInt();
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
        if (!usedFields[kLastModBit]) {
            ctxt.throwMissingField(kLastModFieldName);
        }
    }

}


void DatabaseVersionBase::serialize(BSONObjBuilder* builder) const {
    invariant(_hasLastMod);

    if (_uuid.is_initialized()) {
        ConstDataRange tempCDR = _uuid.get().toCDR();
        builder->append(kUuidFieldName, BSONBinData(tempCDR.data(), tempCDR.length(), newUUID));
    }

    if (_timestamp.is_initialized()) {
        builder->append(kTimestampFieldName, _timestamp.get());
    }

    builder->append(kLastModFieldName, _lastMod);

}


BSONObj DatabaseVersionBase::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
