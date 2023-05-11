/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/s/resharding/resume_token_gen.h --output build/opt/mongo/s/resharding/resume_token_gen.cpp src/mongo/s/resharding/resume_token.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/s/resharding/resume_token_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData ResumeTokenOplogTimestamp::kTsFieldName;


ResumeTokenOplogTimestamp::ResumeTokenOplogTimestamp() : _ts(mongo::idl::preparsedValue<decltype(_ts)>()), _hasTs(false) {
    // Used for initialization only
}
ResumeTokenOplogTimestamp::ResumeTokenOplogTimestamp(mongo::Timestamp ts) : _ts(std::move(ts)), _hasTs(true) {
    // Used for initialization only
}


ResumeTokenOplogTimestamp ResumeTokenOplogTimestamp::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ResumeTokenOplogTimestamp>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ResumeTokenOplogTimestamp::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<1> usedFields;
    const size_t kTsBit = 0;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kTsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, bsonTimestamp))) {
                if (MONGO_unlikely(usedFields[kTsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTsBit);

                _hasTs = true;
                _ts = element.timestamp();
            }
        }
        else {
            ctxt.throwUnknownField(fieldName);
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kTsBit]) {
            ctxt.throwMissingField(kTsFieldName);
        }
    }

}


void ResumeTokenOplogTimestamp::serialize(BSONObjBuilder* builder) const {
    invariant(_hasTs);

    builder->append(kTsFieldName, _ts);

}


BSONObj ResumeTokenOplogTimestamp::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
