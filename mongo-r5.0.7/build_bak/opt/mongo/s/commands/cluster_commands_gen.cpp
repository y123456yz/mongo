/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/s/commands/cluster_commands_gen.h --output build/opt/mongo/s/commands/cluster_commands_gen.cpp src/mongo/s/commands/cluster_commands.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/s/commands/cluster_commands_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"
#include "mongo/idl/server_parameter.h"
#include "mongo/idl/server_parameter_with_storage.h"

namespace mongo {

constexpr StringData ClusterMulticast::kConcurrencyFieldName;
constexpr StringData ClusterMulticast::kDbFieldName;
constexpr StringData ClusterMulticast::kMulticastFieldName;
constexpr StringData ClusterMulticast::kTimeoutFieldName;


ClusterMulticast::ClusterMulticast() : _multicast(mongo::idl::preparsedValue<decltype(_multicast)>()), _db(mongo::idl::preparsedValue<decltype(_db)>()), _hasMulticast(false), _hasDb(false) {
    // Used for initialization only
}
ClusterMulticast::ClusterMulticast(mongo::BSONObj multicast, std::string db) : _multicast(std::move(multicast)), _db(std::move(db)), _hasMulticast(true), _hasDb(true) {
    // Used for initialization only
}


ClusterMulticast ClusterMulticast::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ClusterMulticast>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ClusterMulticast::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<4> usedFields;
    const size_t kMulticastBit = 0;
    const size_t kDbBit = 1;
    const size_t kConcurrencyBit = 2;
    const size_t kTimeoutBit = 3;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kMulticastFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kMulticastBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kMulticastBit);

                _hasMulticast = true;
                _multicast = element.Obj();
            }
        }
        else if (fieldName == kDbFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kDbBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kDbBit);

                _hasDb = true;
                _db = element.str();
            }
        }
        else if (fieldName == kConcurrencyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberInt))) {
                if (MONGO_unlikely(usedFields[kConcurrencyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kConcurrencyBit);

                _concurrency = element._numberInt();
            }
        }
        else if (fieldName == kTimeoutFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, NumberInt))) {
                if (MONGO_unlikely(usedFields[kTimeoutBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTimeoutBit);

                _timeout = element._numberInt();
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
        if (!usedFields[kMulticastBit]) {
            ctxt.throwMissingField(kMulticastFieldName);
        }
        if (!usedFields[kDbBit]) {
            ctxt.throwMissingField(kDbFieldName);
        }
    }

}


void ClusterMulticast::serialize(BSONObjBuilder* builder) const {
    invariant(_hasMulticast && _hasDb);

    builder->append(kMulticastFieldName, _multicast);

    builder->append(kDbFieldName, _db);

    if (_concurrency.is_initialized()) {
        builder->append(kConcurrencyFieldName, _concurrency.get());
    }

    if (_timeout.is_initialized()) {
        builder->append(kTimeoutFieldName, _timeout.get());
    }

}


BSONObj ClusterMulticast::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

constexpr StringData ShardCollection::kCollationFieldName;
constexpr StringData ShardCollection::kKeyFieldName;
constexpr StringData ShardCollection::kNumInitialChunksFieldName;
constexpr StringData ShardCollection::kPresplitHashedZonesFieldName;
constexpr StringData ShardCollection::kShardCollectionFieldName;
constexpr StringData ShardCollection::kShardcollectionFieldName;
constexpr StringData ShardCollection::kTimeseriesFieldName;
constexpr StringData ShardCollection::kUniqueFieldName;


ShardCollection::ShardCollection() : _key(mongo::idl::preparsedValue<decltype(_key)>()), _hasKey(false) {
    // Used for initialization only
}
ShardCollection::ShardCollection(mongo::BSONObj key) : _key(std::move(key)), _hasKey(true) {
    // Used for initialization only
}


ShardCollection ShardCollection::parse(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    auto object = mongo::idl::preparsedValue<ShardCollection>();
    object.parseProtected(ctxt, bsonObject);
    return object;
}
void ShardCollection::parseProtected(const IDLParserErrorContext& ctxt, const BSONObj& bsonObject) {
    std::bitset<8> usedFields;
    const size_t kShardCollectionBit = 0;
    const size_t kShardcollectionBit = 1;
    const size_t kKeyBit = 2;
    const size_t kUniqueBit = 3;
    const size_t kNumInitialChunksBit = 4;
    const size_t kPresplitHashedZonesBit = 5;
    const size_t kCollationBit = 6;
    const size_t kTimeseriesBit = 7;
    std::set<StringData> usedFieldSet;

    for (const auto& element :bsonObject) {
        const auto fieldName = element.fieldNameStringData();


        if (fieldName == kShardCollectionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kShardCollectionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kShardCollectionBit);

                _shardCollection = NamespaceString(element.valueStringData());
            }
        }
        else if (fieldName == kShardcollectionFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, String))) {
                if (MONGO_unlikely(usedFields[kShardcollectionBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kShardcollectionBit);

                _shardcollection = NamespaceString(element.valueStringData());
            }
        }
        else if (fieldName == kKeyFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kKeyBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kKeyBit);

                _hasKey = true;
                _key = element.Obj();
            }
        }
        else if (fieldName == kUniqueFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kUniqueBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kUniqueBit);

                _unique = element.boolean();
            }
        }
        else if (fieldName == kNumInitialChunksFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertTypes(element, {NumberLong, NumberInt, NumberDecimal, NumberDouble}))) {
                if (MONGO_unlikely(usedFields[kNumInitialChunksBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kNumInitialChunksBit);

                _numInitialChunks = element.safeNumberLong();
            }
        }
        else if (fieldName == kPresplitHashedZonesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Bool))) {
                if (MONGO_unlikely(usedFields[kPresplitHashedZonesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kPresplitHashedZonesBit);

                _presplitHashedZones = element.boolean();
            }
        }
        else if (fieldName == kCollationFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kCollationBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kCollationBit);

                _collation = element.Obj();
            }
        }
        else if (fieldName == kTimeseriesFieldName) {
            if (MONGO_likely(ctxt.checkAndAssertType(element, Object))) {
                if (MONGO_unlikely(usedFields[kTimeseriesBit])) {
                    ctxt.throwDuplicateField(element);
                }

                usedFields.set(kTimeseriesBit);

                IDLParserErrorContext tempContext(kTimeseriesFieldName, &ctxt);
                const auto localObject = element.Obj();
                _timeseries = mongo::TimeseriesOptions::parse(tempContext, localObject);
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
        if (!usedFields[kKeyBit]) {
            ctxt.throwMissingField(kKeyFieldName);
        }
        if (!usedFields[kUniqueBit]) {
            _unique = false;
        }
        if (!usedFields[kNumInitialChunksBit]) {
            _numInitialChunks = 0;
        }
        if (!usedFields[kPresplitHashedZonesBit]) {
            _presplitHashedZones = false;
        }
    }

}


void ShardCollection::serialize(BSONObjBuilder* builder) const {
    invariant(_hasKey);

    if (_shardCollection.is_initialized()) {
        builder->append(kShardCollectionFieldName, _shardCollection.get().toString());
    }

    if (_shardcollection.is_initialized()) {
        builder->append(kShardcollectionFieldName, _shardcollection.get().toString());
    }

    builder->append(kKeyFieldName, _key);

    builder->append(kUniqueFieldName, _unique);

    builder->append(kNumInitialChunksFieldName, _numInitialChunks);

    builder->append(kPresplitHashedZonesFieldName, _presplitHashedZones);

    if (_collation.is_initialized()) {
        builder->append(kCollationFieldName, _collation.get());
    }

    if (_timeseries.is_initialized()) {
        BSONObjBuilder subObjBuilder(builder->subobjStart(kTimeseriesFieldName));
        _timeseries.get().serialize(&subObjBuilder);
    }

}


BSONObj ShardCollection::toBSON() const {
    BSONObjBuilder builder;
    serialize(&builder);
    return builder.obj();
}

int gKillSessionsMaxConcurrency{100};
int gKillSessionsPerHostTimeoutMS{60000};
MONGO_SERVER_PARAMETER_REGISTER(idl_22c12bd846ee4e3da3fa549cc6058e6f5b958bcb)(InitializerContext*) {
    /**
     * The maximum number of hosts to for killSessionsRemote to kill sessions on at the same time.
     */
    [[maybe_unused]] auto* scp_0 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("KillSessionsMaxConcurrency", gKillSessionsMaxConcurrency);
        return ret;
    })();

    /**
     * The maximum number of miliseconds for killSessionsRemote to wait for host to respond.
     */
    [[maybe_unused]] auto* scp_1 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("KillSessionsPerHostTimeoutMS", gKillSessionsPerHostTimeoutMS);
        return ret;
    })();

}
}  // namespace mongo
