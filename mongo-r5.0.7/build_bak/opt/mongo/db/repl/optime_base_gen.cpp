/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/repl/optime_base_gen.h --output build/opt/mongo/db/repl/optime_base_gen.cpp src/mongo/db/repl/optime_base.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/repl/optime_base_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {
namespace repl {

constexpr StringData OpTimeBase::kTermFieldName;
constexpr StringData OpTimeBase::kTimestampFieldName;


OpTimeBase::OpTimeBase() : _timestamp(mongo::idl::preparsedValue<decltype(_timestamp)>()), _hasTimestamp(false) {
    // Used for initialization only
}
OpTimeBase::OpTimeBase(mongo::Timestamp timestamp) : _timestamp(std::move(timestamp)), _hasTimestamp(true) {
    // Used for initialization only
}


OpTimeBase OpTimeBase::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<OpTimeBase>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void OpTimeBase::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kTimestampBit = 0;
    const size_t kTermBit = 1;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kTimestampFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, bsonTimestamp))) {
                if (MONGO_unlikely(usedFields[kTimestampBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTimestampBit);

                _hasTimestamp = true;
                _timestamp = element.timestamp();
            }
        }
        else if (fieldName == kTermFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kTermBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTermBit);

                _term = element._numberLong();
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
        if (!usedFields[kTimestampBit]) {
            ctxt.throwMissingField(kTimestampFieldName);
        }
    }

}


void OpTimeBase::serialize(BSONObjBuilder* builder) const {
    invariant(_hasTimestamp);

    builder->append(kTimestampFieldName, _timestamp);

    if (_term.is_initialized()) {
        builder->append(kTermFieldName, _term.get());
    }

}


BSONObj OpTimeBase::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace repl
}  // namespace mongo
