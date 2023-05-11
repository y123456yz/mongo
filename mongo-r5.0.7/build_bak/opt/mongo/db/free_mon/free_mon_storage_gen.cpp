/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/free_mon/free_mon_storage_gen.h --output build/opt/mongo/db/free_mon/free_mon_storage_gen.cpp src/mongo/db/free_mon/free_mon_storage.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/free_mon/free_mon_storage_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

/**
 * Action types
 */
namespace  {
constexpr StringData kStorageState_disabled = "disabled"_sd;
constexpr StringData kStorageState_enabled = "enabled"_sd;
constexpr StringData kStorageState_pending = "pending"_sd;
}  // namespace 

StorageStateEnum StorageState_parse(const IDLParserErrorContext& ctxt, StringData value) {
    if (value == kStorageState_disabled) {
        return StorageStateEnum::disabled;
    }
    if (value == kStorageState_enabled) {
        return StorageStateEnum::enabled;
    }
    if (value == kStorageState_pending) {
        return StorageStateEnum::pending;
    }
    ctxt.throwBadEnumValue(value);
}

StringData StorageState_serializer(StorageStateEnum value) {
    if (value == StorageStateEnum::disabled) {
        return kStorageState_disabled;
    }
    if (value == StorageStateEnum::enabled) {
        return kStorageState_enabled;
    }
    if (value == StorageStateEnum::pending) {
        return kStorageState_pending;
    }
    MONGO_UNREACHABLE;
    return StringData();
}

constexpr StringData FreeMonStorageState::k_idFieldName;
constexpr StringData FreeMonStorageState::kInformationalURLFieldName;
constexpr StringData FreeMonStorageState::kMessageFieldName;
constexpr StringData FreeMonStorageState::kRegistrationIdFieldName;
constexpr StringData FreeMonStorageState::kStateFieldName;
constexpr StringData FreeMonStorageState::kUserReminderFieldName;
constexpr StringData FreeMonStorageState::kVersionFieldName;


FreeMonStorageState::FreeMonStorageState() : _version(mongo::idl::preparsedValue<decltype(_version)>()), _registrationId(mongo::idl::preparsedValue<decltype(_registrationId)>()), _informationalURL(mongo::idl::preparsedValue<decltype(_informationalURL)>()), _message(mongo::idl::preparsedValue<decltype(_message)>()), _userReminder(mongo::idl::preparsedValue<decltype(_userReminder)>()), _hasVersion(false), _hasRegistrationId(false), _hasInformationalURL(false), _hasMessage(false), _hasUserReminder(false) {
    // Used for initialization only
}
FreeMonStorageState::FreeMonStorageState(std::int64_t version, std::string registrationId, std::string informationalURL, std::string message, std::string userReminder) : _version(std::move(version)), _registrationId(std::move(registrationId)), _informationalURL(std::move(informationalURL)), _message(std::move(message)), _userReminder(std::move(userReminder)), _hasVersion(true), _hasRegistrationId(true), _hasInformationalURL(true), _hasMessage(true), _hasUserReminder(true) {
    // Used for initialization only
}


FreeMonStorageState FreeMonStorageState::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<FreeMonStorageState>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void FreeMonStorageState::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<7> usedFields;
    const size_t k_idBit = 0;
    const size_t kVersionBit = 1;
    const size_t kStateBit = 2;
    const size_t kRegistrationIdBit = 3;
    const size_t kInformationalURLBit = 4;
    const size_t kMessageBit = 5;
    const size_t kUserReminderBit = 6;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == k_idFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[k_idBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(k_idBit);

                __id = element.str();
            }
        }
        else if (fieldName == kVersionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberLong))) {
                if (MONGO_unlikely(usedFields[kVersionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kVersionBit);

                _hasVersion = true;
                _version = element._numberLong();
            }
        }
        else if (fieldName == kStateFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kStateBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kStateBit);

                IDLParserErrorContext tempContext(kStateFieldName, &ctxt);
                _state = StorageState_parse(tempContext, element.valueStringData());
            }
        }
        else if (fieldName == kRegistrationIdFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kRegistrationIdBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRegistrationIdBit);

                _hasRegistrationId = true;
                _registrationId = element.str();
            }
        }
        else if (fieldName == kInformationalURLFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kInformationalURLBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kInformationalURLBit);

                _hasInformationalURL = true;
                _informationalURL = element.str();
            }
        }
        else if (fieldName == kMessageFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kMessageBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMessageBit);

                _hasMessage = true;
                _message = element.str();
            }
        }
        else if (fieldName == kUserReminderFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kUserReminderBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUserReminderBit);

                _hasUserReminder = true;
                _userReminder = element.str();
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
            __id = "free_monitoring";
        }
        if (!usedFields[kVersionBit]) {
            ctxt.throwMissingField(kVersionFieldName);
        }
        if (!usedFields[kStateBit]) {
            _state = mongo::StorageStateEnum::disabled;
        }
        if (!usedFields[kRegistrationIdBit]) {
            ctxt.throwMissingField(kRegistrationIdFieldName);
        }
        if (!usedFields[kInformationalURLBit]) {
            ctxt.throwMissingField(kInformationalURLFieldName);
        }
        if (!usedFields[kMessageBit]) {
            ctxt.throwMissingField(kMessageFieldName);
        }
        if (!usedFields[kUserReminderBit]) {
            ctxt.throwMissingField(kUserReminderFieldName);
        }
    }

}


void FreeMonStorageState::serialize(BSONObjBuilder* builder) const {
    invariant(_hasVersion && _hasRegistrationId && _hasInformationalURL && _hasMessage && _hasUserReminder);

    builder->append(k_idFieldName, __id);

    builder->append(kVersionFieldName, _version);

    {
        builder->append(kStateFieldName, ::mongo::StorageState_serializer(_state));
    }

    builder->append(kRegistrationIdFieldName, _registrationId);

    builder->append(kInformationalURLFieldName, _informationalURL);

    builder->append(kMessageFieldName, _message);

    builder->append(kUserReminderFieldName, _userReminder);

}


BSONObj FreeMonStorageState::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
