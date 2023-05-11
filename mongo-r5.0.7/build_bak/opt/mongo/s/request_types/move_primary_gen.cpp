/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/s/request_types/move_primary_gen.h --output build/opt/mongo/s/request_types/move_primary_gen.cpp src/mongo/s/request_types/move_primary.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/s/request_types/move_primary_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData MovePrimary::kMovePrimaryFieldName;
constexpr StringData MovePrimary::kMoveprimaryFieldName;
constexpr StringData MovePrimary::kToFieldName;


MovePrimary::MovePrimary() : _to(mongo::idl::preparsedValue<decltype(_to)>()), _hasTo(false) {
    // Used for initialization only
}
MovePrimary::MovePrimary(std::string to) : _to(std::move(to)), _hasTo(true) {
    // Used for initialization only
}


MovePrimary MovePrimary::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<MovePrimary>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void MovePrimary::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<3> usedFields;
    const size_t kMovePrimaryBit = 0;
    const size_t kMoveprimaryBit = 1;
    const size_t kToBit = 2;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kMovePrimaryFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kMovePrimaryBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMovePrimaryBit);

                _movePrimary = NamespaceString(element.valueStringData());
            }
        }
        else if (fieldName == kMoveprimaryFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kMoveprimaryBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMoveprimaryBit);

                _moveprimary = NamespaceString(element.valueStringData());
            }
        }
        else if (fieldName == kToFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kToBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kToBit);

                _hasTo = true;
                _to = element.str();
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
        if (!usedFields[kToBit]) {
            ctxt.throwMissingField(kToFieldName);
        }
    }

}


void MovePrimary::serialize(BSONObjBuilder* builder) const {
    invariant(_hasTo);

    if (_movePrimary.is_initialized()) {
        builder->append(kMovePrimaryFieldName, _movePrimary.get().toString());
    }

    if (_moveprimary.is_initialized()) {
        builder->append(kMoveprimaryFieldName, _moveprimary.get().toString());
    }

    builder->append(kToFieldName, _to);

}


BSONObj MovePrimary::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData ShardMovePrimary::k_shardsvrMovePrimaryFieldName;
constexpr StringData ShardMovePrimary::kCommandIsFromRouterFieldName;
constexpr StringData ShardMovePrimary::kToFieldName;


ShardMovePrimary::ShardMovePrimary() : __shardsvrMovePrimary(mongo::idl::preparsedValue<decltype(__shardsvrMovePrimary)>()), _to(mongo::idl::preparsedValue<decltype(_to)>()), _has_shardsvrMovePrimary(false), _hasTo(false) {
    // Used for initialization only
}
ShardMovePrimary::ShardMovePrimary(mongo::NamespaceString _shardsvrMovePrimary, std::string to) : __shardsvrMovePrimary(std::move(_shardsvrMovePrimary)), _to(std::move(to)), _has_shardsvrMovePrimary(true), _hasTo(true) {
    // Used for initialization only
}


ShardMovePrimary ShardMovePrimary::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ShardMovePrimary>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ShardMovePrimary::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<3> usedFields;
    const size_t k_shardsvrMovePrimaryBit = 0;
    const size_t kToBit = 1;
    const size_t kCommandIsFromRouterBit = 2;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == k_shardsvrMovePrimaryFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[k_shardsvrMovePrimaryBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(k_shardsvrMovePrimaryBit);

                _has_shardsvrMovePrimary = true;
                __shardsvrMovePrimary = NamespaceString(element.valueStringData());
            }
        }
        else if (fieldName == kToFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kToBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kToBit);

                _hasTo = true;
                _to = element.str();
            }
        }
        else if (fieldName == kCommandIsFromRouterFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kCommandIsFromRouterBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCommandIsFromRouterBit);

                _commandIsFromRouter = element.boolean();
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
        if (!usedFields[k_shardsvrMovePrimaryBit]) {
            ctxt.throwMissingField(k_shardsvrMovePrimaryFieldName);
        }
        if (!usedFields[kToBit]) {
            ctxt.throwMissingField(kToFieldName);
        }
        if (!usedFields[kCommandIsFromRouterBit]) {
            _commandIsFromRouter = false;
        }
    }

}


void ShardMovePrimary::serialize(BSONObjBuilder* builder) const {
    invariant(_has_shardsvrMovePrimary && _hasTo);

    {
        builder->append(k_shardsvrMovePrimaryFieldName, __shardsvrMovePrimary.toString());
    }

    builder->append(kToFieldName, _to);

    builder->append(kCommandIsFromRouterFieldName, _commandIsFromRouter);

}


BSONObj ShardMovePrimary::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData ConfigsvrMovePrimary::k_configsvrMovePrimaryFieldName;
constexpr StringData ConfigsvrMovePrimary::kToFieldName;


ConfigsvrMovePrimary::ConfigsvrMovePrimary() : __configsvrMovePrimary(mongo::idl::preparsedValue<decltype(__configsvrMovePrimary)>()), _to(mongo::idl::preparsedValue<decltype(_to)>()), _has_configsvrMovePrimary(false), _hasTo(false) {
    // Used for initialization only
}
ConfigsvrMovePrimary::ConfigsvrMovePrimary(mongo::NamespaceString _configsvrMovePrimary, std::string to) : __configsvrMovePrimary(std::move(_configsvrMovePrimary)), _to(std::move(to)), _has_configsvrMovePrimary(true), _hasTo(true) {
    // Used for initialization only
}


ConfigsvrMovePrimary ConfigsvrMovePrimary::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ConfigsvrMovePrimary>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ConfigsvrMovePrimary::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t k_configsvrMovePrimaryBit = 0;
    const size_t kToBit = 1;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == k_configsvrMovePrimaryFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[k_configsvrMovePrimaryBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(k_configsvrMovePrimaryBit);

                _has_configsvrMovePrimary = true;
                __configsvrMovePrimary = NamespaceString(element.valueStringData());
            }
        }
        else if (fieldName == kToFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kToBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kToBit);

                _hasTo = true;
                _to = element.str();
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
        if (!usedFields[k_configsvrMovePrimaryBit]) {
            ctxt.throwMissingField(k_configsvrMovePrimaryFieldName);
        }
        if (!usedFields[kToBit]) {
            ctxt.throwMissingField(kToFieldName);
        }
    }

}


void ConfigsvrMovePrimary::serialize(BSONObjBuilder* builder) const {
    invariant(_has_configsvrMovePrimary && _hasTo);

    {
        builder->append(k_configsvrMovePrimaryFieldName, __configsvrMovePrimary.toString());
    }

    builder->append(kToFieldName, _to);

}


BSONObj ConfigsvrMovePrimary::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData ConfigsvrCommitMovePrimary::k_configsvrCommitMovePrimaryFieldName;
constexpr StringData ConfigsvrCommitMovePrimary::kToFieldName;


ConfigsvrCommitMovePrimary::ConfigsvrCommitMovePrimary() : __configsvrCommitMovePrimary(mongo::idl::preparsedValue<decltype(__configsvrCommitMovePrimary)>()), _to(mongo::idl::preparsedValue<decltype(_to)>()), _has_configsvrCommitMovePrimary(false), _hasTo(false) {
    // Used for initialization only
}
ConfigsvrCommitMovePrimary::ConfigsvrCommitMovePrimary(std::string _configsvrCommitMovePrimary, std::string to) : __configsvrCommitMovePrimary(std::move(_configsvrCommitMovePrimary)), _to(std::move(to)), _has_configsvrCommitMovePrimary(true), _hasTo(true) {
    // Used for initialization only
}


ConfigsvrCommitMovePrimary ConfigsvrCommitMovePrimary::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ConfigsvrCommitMovePrimary>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ConfigsvrCommitMovePrimary::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t k_configsvrCommitMovePrimaryBit = 0;
    const size_t kToBit = 1;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == k_configsvrCommitMovePrimaryFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[k_configsvrCommitMovePrimaryBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(k_configsvrCommitMovePrimaryBit);

                _has_configsvrCommitMovePrimary = true;
                __configsvrCommitMovePrimary = element.str();
            }
        }
        else if (fieldName == kToFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kToBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kToBit);

                _hasTo = true;
                _to = element.str();
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
        if (!usedFields[k_configsvrCommitMovePrimaryBit]) {
            ctxt.throwMissingField(k_configsvrCommitMovePrimaryFieldName);
        }
        if (!usedFields[kToBit]) {
            ctxt.throwMissingField(kToFieldName);
        }
    }

}


void ConfigsvrCommitMovePrimary::serialize(BSONObjBuilder* builder) const {
    invariant(_has_configsvrCommitMovePrimary && _hasTo);

    builder->append(k_configsvrCommitMovePrimaryFieldName, __configsvrCommitMovePrimary);

    builder->append(kToFieldName, _to);

}


BSONObj ConfigsvrCommitMovePrimary::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
