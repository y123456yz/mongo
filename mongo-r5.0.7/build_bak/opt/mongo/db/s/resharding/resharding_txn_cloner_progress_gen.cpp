/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/s/resharding/resharding_txn_cloner_progress_gen.h --output build/opt/mongo/db/s/resharding/resharding_txn_cloner_progress_gen.cpp src/mongo/db/s/resharding/resharding_txn_cloner_progress.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/s/resharding/resharding_txn_cloner_progress_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData ReshardingTxnClonerProgress::kProgressFieldName;
constexpr StringData ReshardingTxnClonerProgress::kSourceIdFieldName;


ReshardingTxnClonerProgress::ReshardingTxnClonerProgress() : _sourceId(mongo::idl::preparsedValue<decltype(_sourceId)>()), _progress(mongo::idl::preparsedValue<decltype(_progress)>()), _hasSourceId(false), _hasProgress(false) {
    // Used for initialization only
}
ReshardingTxnClonerProgress::ReshardingTxnClonerProgress(mongo::ReshardingSourceId sourceId, mongo::LogicalSessionId progress) : _sourceId(std::move(sourceId)), _progress(std::move(progress)), _hasSourceId(true), _hasProgress(true) {
    // Used for initialization only
}


ReshardingTxnClonerProgress ReshardingTxnClonerProgress::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ReshardingTxnClonerProgress>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ReshardingTxnClonerProgress::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kSourceIdBit = 0;
    const size_t kProgressBit = 1;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kSourceIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kSourceIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kSourceIdBit);

                _hasSourceId = true;
                IDLParserErrorContext tempContext(kSourceIdFieldName, &ctxt);
                const auto localObject = element.Obj();
                _sourceId = mongo::ReshardingSourceId::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kProgressFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kProgressBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kProgressBit);

                _hasProgress = true;
                IDLParserErrorContext tempContext(kProgressFieldName, &ctxt);
                const auto localObject = element.Obj();
                _progress = mongo::LogicalSessionId::parse(tempContext, localObject);
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
        if (!usedFields[kSourceIdBit]) {
            ctxt.throwMissingField(kSourceIdFieldName);
        }
        if (!usedFields[kProgressBit]) {
            ctxt.throwMissingField(kProgressFieldName);
        }
    }

}


void ReshardingTxnClonerProgress::serialize(BSONObjBuilder* builder) const {
    invariant(_hasSourceId && _hasProgress);

    {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kSourceIdFieldName));
        _sourceId.serialize(&subObjBuilder);
    }

    {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kProgressFieldName));
        _progress.serialize(&subObjBuilder);
    }

}


BSONObj ReshardingTxnClonerProgress::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
