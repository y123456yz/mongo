/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/s/forwardable_operation_metadata_gen.h --output build/opt/mongo/db/s/forwardable_operation_metadata_gen.cpp src/mongo/db/s/forwardable_operation_metadata.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/s/forwardable_operation_metadata_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"

namespace mongo {

constexpr StringData AuthenticationMetadata::kRolesFieldName;
constexpr StringData AuthenticationMetadata::kUsersFieldName;


AuthenticationMetadata::AuthenticationMetadata() : _hasUsers(false), _hasRoles(false) {
    // Used for initialization only
}
AuthenticationMetadata::AuthenticationMetadata(std::vector<mongo::UserName> users, std::vector<mongo::RoleName> roles) : _users(std::move(users)), _roles(std::move(roles)), _hasUsers(true), _hasRoles(true) {
    // Used for initialization only
}


AuthenticationMetadata AuthenticationMetadata::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<AuthenticationMetadata>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void AuthenticationMetadata::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kUsersBit = 0;
    const size_t kRolesBit = 1;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kUsersFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kUsersBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUsersBit);

                _hasUsers = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kUsersFieldName, &ctxt);
            std::vector<mongo::UserName> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    values.emplace_back(UserName::parseFromBSON(arrayElement));
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _users = std::move(values);
        }
        else if (fieldName == kRolesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Array))) {
                if (MONGO_unlikely(usedFields[kRolesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kRolesBit);

                _hasRoles = true;
            }
            std::uint32_t expectedFieldNumber{0};
            const IDLParserErrorContext arrayCtxt(kRolesFieldName, &ctxt);
            std::vector<mongo::RoleName> values;

            const BSONObj arrayObject = element.Obj();
            for (const auto& arrayElement : arrayObject) {
                const auto arrayFieldName = arrayElement.fieldNameStringData();
                std::uint32_t fieldNumber;

                Status status = NumberParser{}(arrayFieldName, &fieldNumber);
                if (status.isOK()) {
                    if (fieldNumber != expectedFieldNumber) {
                        arrayCtxt.throwBadArrayFieldNumberSequence(fieldNumber, expectedFieldNumber);
                    }

                    values.emplace_back(RoleName::parseFromBSON(arrayElement));
                }
                else {
                    arrayCtxt.throwBadArrayFieldNumberValue(arrayFieldName);
                }
                ++expectedFieldNumber;
            }
            _roles = std::move(values);
        }
        else {
            auto push_result = usedFieldSet.insert(fieldName);
            if (MONGO_unlikely(push_result.second == false)) {
                ctxt.throwDuplicateField(fieldName);
            }
        }
    }

    if (MONGO_unlikely(!usedFields.all())) {
        if (!usedFields[kUsersBit]) {
            ctxt.throwMissingField(kUsersFieldName);
        }
        if (!usedFields[kRolesBit]) {
            ctxt.throwMissingField(kRolesFieldName);
        }
    }

}


void AuthenticationMetadata::serialize(BSONObjBuilder* builder) const {
    invariant(_hasUsers && _hasRoles);

    {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kUsersFieldName));
        for (const auto& item : _users) {
            item.serializeToBSON(&arrayBuilder);
        }
    }

    {
        BSONArrayBuilder arrayBuilder(builder->subarrayStart(kRolesFieldName));
        for (const auto& item : _roles) {
            item.serializeToBSON(&arrayBuilder);
        }
    }

}


BSONObj AuthenticationMetadata::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData ForwardableOperationMetadataBase::kCommentFieldName;
constexpr StringData ForwardableOperationMetadataBase::kImpersonatedUserMetadataFieldName;


ForwardableOperationMetadataBase::ForwardableOperationMetadataBase()  {
    // Used for initialization only
}


ForwardableOperationMetadataBase ForwardableOperationMetadataBase::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ForwardableOperationMetadataBase>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ForwardableOperationMetadataBase::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<2> usedFields;
    const size_t kCommentBit = 0;
    const size_t kImpersonatedUserMetadataBit = 1;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kCommentFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCommentBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCommentBit);

                const BSONObj localObject = element.Obj();
                _comment = BSONObj::getOwned(localObject);
            }
        }
        else if (fieldName == kImpersonatedUserMetadataFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kImpersonatedUserMetadataBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kImpersonatedUserMetadataBit);

                IDLParserErrorContext tempContext(kImpersonatedUserMetadataFieldName, &ctxt);
                const auto localObject = element.Obj();
                _impersonatedUserMetadata = mongo::AuthenticationMetadata::parse(tempContext, localObject);
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
    }

}


void ForwardableOperationMetadataBase::serialize(BSONObjBuilder* builder) const {
    if (_comment.is_initialized()) {
        builder->append(kCommentFieldName, _comment.get());
    }

    if (_impersonatedUserMetadata.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kImpersonatedUserMetadataFieldName));
        _impersonatedUserMetadata.get().serialize(&subObjBuilder);
    }

}


BSONObj ForwardableOperationMetadataBase::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

}  // namespace mongo
