/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/repl/image_collection_entry_gen.h --output build/opt/mongo/db/repl/image_collection_entry_gen.cpp src/mongo/db/repl/image_collection_entry.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/repl/image_collection_entry_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {
namespace repl {

constexpr StringData ImageEntry::k_idFieldName;
constexpr StringData ImageEntry::kImageFieldName;
constexpr StringData ImageEntry::kImageKindFieldName;
constexpr StringData ImageEntry::kInvalidatedFieldName;
constexpr StringData ImageEntry::kInvalidatedReasonFieldName;
constexpr StringData ImageEntry::kTsFieldName;
constexpr StringData ImageEntry::kTxnNumberFieldName;


ImageEntry::ImageEntry() : __id(mongo::idl::preparsedValue<decltype(__id)>()), _txnNumber(mongo::idl::preparsedValue<decltype(_txnNumber)>()), _ts(mongo::idl::preparsedValue<decltype(_ts)>()), _imageKind(mongo::idl::preparsedValue<decltype(_imageKind)>()), _image(mongo::idl::preparsedValue<decltype(_image)>()), _has_id(false), _hasTxnNumber(false), _hasTs(false), _hasImageKind(false), _hasImage(false) {
    // Used for initialization only
}
ImageEntry::ImageEntry(mongo::LogicalSessionId _id, std::int64_t txnNumber, mongo::Timestamp ts, mongo::repl::RetryImageEnum imageKind, mongo::BSONObj image) : __id(std::move(_id)), _txnNumber(std::move(txnNumber)), _ts(std::move(ts)), _imageKind(std::move(imageKind)), _image(std::move(image)), _has_id(true), _hasTxnNumber(true), _hasTs(true), _hasImageKind(true), _hasImage(true) {
    // Used for initialization only
}


ImageEntry ImageEntry::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ImageEntry>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ImageEntry::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<7> usedFields;
    const size_t k_idBit = 0;
    const size_t kTxnNumberBit = 1;
    const size_t kTsBit = 2;
    const size_t kImageKindBit = 3;
    const size_t kImageBit = 4;
    const size_t kInvalidatedBit = 5;
    const size_t kInvalidatedReasonBit = 6;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == k_idFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[k_idBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(k_idBit);

                _has_id = true;
                IDLParserErrorContext tempContext(k_idFieldName, &ctxt);
                const auto localObject = element.Obj();
                __id = mongo::LogicalSessionId::parse(tempContext, localObject);
            }
        }
        else if (fieldName == kTxnNumberFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kTxnNumberBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTxnNumberBit);

                _hasTxnNumber = true;
                _txnNumber = element._numberLong();
            }
        }
        else if (fieldName == kTsFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, bsonTimestamp))) {
                if (MONGO_unlikely(usedFields[kTsBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTsBit);

                _hasTs = true;
                _ts = element.timestamp();
            }
        }
        else if (fieldName == kImageKindFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kImageKindBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kImageKindBit);

                _hasImageKind = true;
                IDLParserErrorContext tempContext(kImageKindFieldName, &ctxt);
                _imageKind = repl::RetryImage_parse(tempContext, element.valueStringData());
            }
        }
        else if (fieldName == kImageFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kImageBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kImageBit);

                _hasImage = true;
                const BSONObj localObject = element.Obj();
                _image = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kInvalidatedFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kInvalidatedBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kInvalidatedBit);

                _invalidated = element.boolean();
            }
        }
        else if (fieldName == kInvalidatedReasonFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kInvalidatedReasonBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kInvalidatedReasonBit);

                _invalidatedReason = element.str();
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
        if (!usedFields[k_idBit]) {
            ctxt.throwMissingField(k_idFieldName);
        }
        if (!usedFields[kTxnNumberBit]) {
            ctxt.throwMissingField(kTxnNumberFieldName);
        }
        if (!usedFields[kTsBit]) {
            ctxt.throwMissingField(kTsFieldName);
        }
        if (!usedFields[kImageKindBit]) {
            ctxt.throwMissingField(kImageKindFieldName);
        }
        if (!usedFields[kImageBit]) {
            ctxt.throwMissingField(kImageFieldName);
        }
        if (!usedFields[kInvalidatedBit]) {
            _invalidated = false;
        }
    }

}


void ImageEntry::serialize(BSONObjBuilder* builder) const {
    invariant(_has_id && _hasTxnNumber && _hasTs && _hasImageKind && _hasImage);

    {
        BSONObjBuilder subObjBuilder(builder->subobjStart(k_idFieldName));
        __id.serialize(&subObjBuilder);
    }

    builder->append(kTxnNumberFieldName, _txnNumber);

    builder->append(kTsFieldName, _ts);

    {
        builder->append(kImageKindFieldName, ::mongo::repl::RetryImage_serializer(_imageKind));
    }

    builder->append(kImageFieldName, _image);

    builder->append(kInvalidatedFieldName, _invalidated);

    if (_invalidatedReason.is_initialized()) {
        builder->append(kInvalidatedReasonFieldName, _invalidatedReason.get());
    }

}


BSONObj ImageEntry::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace repl
}  // namespace mongo
