// Copyright (c) MongoDB, Inc.
// SPDX-License-Identifier: SSPL-1.0

#include "mongo/db/update/update_tree_executor.h"

#include "mongo/db/pipeline/expression_context_for_test.h"
#include "mongo/db/query/collation/collator_factory_icu.h"
#include "mongo/db/query/query_fcv_environment_for_test.h"
#include "mongo/db/query/query_test_service_context.h"
#include "mongo/logv2/log.h"
#include "mongo/logv2/log_domain_global.h"

#include <string_view>

#include <benchmark/benchmark.h>

#define MONGO_LOGV2_DEFAULT_COMPONENT ::mongo::logv2::LogComponent::kTest

namespace mongo {
namespace {

static const NamespaceString kNss = NamespaceString::createNamespaceString_forTest("test.bm");
static const std::map<std::string_view, std::unique_ptr<ExpressionWithPlaceholder>> kArrayFilters =
    {};


void configureLogging(bool disable) {
    auto& lv2Manager = logv2::LogManager::global();
    logv2::LogDomainGlobal::ConfigurationOptions lv2Config;
    if (disable)
        lv2Config.makeDisabled();
    uassertStatusOK(lv2Manager.getGlobalDomainInternal().configure(lv2Config));
}

class UpdateTreeExecutorBenchmark : public benchmark::Fixture {
private:
    static constexpr int32_t kSeed = 1;

protected:
    void benchmarkUpdate(UpdateTreeExecutor executor, BSONObj input, benchmark::State& state) {
        for (auto _ : state) {
            mutablebson::Document document{input};
            UpdateExecutor::ApplyParams params{document.root(), FieldRefSet{}};
            benchmark::DoNotOptimize(executor.applyUpdate(std::move(params)));
            benchmark::ClobberMemory();
        }
    }

    void benchmarkAddToSet(BSONObj inputDoc,
                           BSONObj addToSetSpec,
                           std::shared_ptr<CollatorInterface> collator,
                           benchmark::State& state) {
        _expCtx->setCollator(std::move(collator));
        std::set<std::string> foundIdentifiers;
        auto updateTree = std::make_unique<UpdateObjectNode>();
        tassert(11788501,
                "Failed to parse $addToSet",
                UpdateObjectNode::parseAndMerge(updateTree.get(),
                                                modifiertable::ModifierType::MOD_ADD_TO_SET,
                                                addToSetSpec.firstElement(),
                                                _expCtx,
                                                kArrayFilters,
                                                foundIdentifiers)
                    .isOK());

        UpdateTreeExecutor executor(std::move(updateTree));
        benchmarkUpdate(std::move(executor), inputDoc, state);
    }

    void benchmarkSet(BSONObj inputDoc, BSONObj setSpec, benchmark::State& state) {
        std::set<std::string> foundIdentifiers;
        auto updateTree = std::make_unique<UpdateObjectNode>();
        for (auto&& elem : setSpec["$set"].Obj()) {
            tassert(11788502,
                    "Failed to parse $set",
                    UpdateObjectNode::parseAndMerge(updateTree.get(),
                                                    modifiertable::ModifierType::MOD_SET,
                                                    elem,
                                                    _expCtx,
                                                    kArrayFilters,
                                                    foundIdentifiers)
                        .isOK());
        }

        UpdateTreeExecutor executor(std::move(updateTree));
        benchmarkUpdate(std::move(executor), inputDoc, state);
    }

    ServiceContext::UniqueOperationContext _opCtx;
    boost::intrusive_ptr<ExpressionContext> _expCtx;

    std::mt19937 _random{kSeed};

private:
    void SetUp(benchmark::State& state) final {
        QueryFCVEnvironmentForTest::setUp();
        // Temporarily disable logging because we don't want logs from service context
        // initialization to clutter the benchmark results table.
        configureLogging(true);
        ON_BLOCK_EXIT([&] { configureLogging(false); });
        _scopedGlobalServiceContext = std::make_unique<QueryTestScopedGlobalServiceContext>();

        _opCtx = _scopedGlobalServiceContext->makeOperationContext();
        _expCtx = make_intrusive<ExpressionContextForTest>(_opCtx.get(), kNss);
    }

    void TearDown(benchmark::State& state) final {
        _opCtx.reset();
        _scopedGlobalServiceContext.reset();
    }

    std::unique_ptr<QueryTestScopedGlobalServiceContext> _scopedGlobalServiceContext;
};

template <typename T>
BSONArray toBsonArray(std::vector<T> array) {
    BSONArrayBuilder builder;
    for (auto& v : array) {
        builder.append(std::move(v));
    }
    return builder.arr();
}

template <typename Generator>
BSONArray generateArray(
    std::mt19937& random, int64_t from, int64_t to, int64_t step, Generator generator) {
    std::vector<std::invoke_result_t<Generator, int64_t>> array;
    for (int64_t i = from; i < to; i += step) {
        array.push_back(generator(i));
    }
    std::shuffle(array.begin(), array.end(), random);
    return toBsonArray(std::move(array));
}

BSONArray generateNumberArray(std::mt19937& random, int64_t from, int64_t to, int64_t step = 1) {
    return generateArray(random, from, to, step, [](auto i) { return i; });
}

BENCHMARK_DEFINE_F(UpdateTreeExecutorBenchmark, AddToSetNumbers)(benchmark::State& state) {
    int64_t inputSize = state.range(0);
    int64_t updateSize = state.range(1);
    BSONObj inputDoc = BSON("a" << generateNumberArray(_random, 0, inputSize));
    // Create array with step 2 to have some overlap between input and update
    BSONObj addToSetSpec =
        BSON("a" << BSON("$each" << generateNumberArray(
                             _random, inputSize - updateSize, inputSize + updateSize, 2)));
    benchmarkAddToSet(inputDoc, addToSetSpec, nullptr /*collator*/, state);
}

BSONArray generateObjectWithStringArray(std::mt19937& random,
                                        int64_t from,
                                        int64_t to,
                                        int64_t step = 1) {
    static constexpr size_t kStringPrefixSize = 64;
    std::string prefix{kStringPrefixSize, '0'};
    return generateArray(random, from, to, step, [&](int64_t index) {
        BSONObjBuilder builder;
        std::stringstream payload;
        payload << prefix << std::hex << index;
        builder.append("payload", payload.str());
        return builder.obj();
    });
}

BENCHMARK_DEFINE_F(UpdateTreeExecutorBenchmark,
                   AddToSetObjectWithStrings)(benchmark::State& state) {
    int64_t inputSize = state.range(0);
    int64_t updateSize = state.range(1);
    BSONObj inputDoc = BSON("a" << generateObjectWithStringArray(_random, 0, inputSize));
    // Create array with step 2 to have some overlap between input and update
    BSONObj addToSetSpec =
        BSON("a" << BSON("$each" << generateObjectWithStringArray(
                             _random, inputSize - updateSize, inputSize + updateSize, 2)));
    benchmarkAddToSet(inputDoc, addToSetSpec, nullptr /*collator*/, state);
}

BENCHMARK_DEFINE_F(UpdateTreeExecutorBenchmark,
                   AddToSetObjectWithStringsCollator)(benchmark::State& state) {
    int64_t inputSize = state.range(0);
    int64_t updateSize = state.range(1);
    BSONObj inputDoc = BSON("a" << generateObjectWithStringArray(_random, 0, inputSize));
    // Create array with step 2 to have some overlap between input and update
    BSONObj addToSetSpec =
        BSON("a" << BSON("$each" << generateObjectWithStringArray(
                             _random, inputSize - updateSize, inputSize + updateSize, 2)));

    CollatorFactoryICU _collatorFactory;
    auto statusWithCollator =
        _collatorFactory.makeFromBSON(BSON("locale" << "en" << "strength" << 2));
    tassert(11788500, "Could not create collator", statusWithCollator.isOK());
    benchmarkAddToSet(inputDoc, addToSetSpec, statusWithCollator.getValue()->cloneShared(), state);
}

static void configureAddToSetBenchmark(benchmark::internal::Benchmark* bm) {
    static const std::vector<int64_t> kSizes = {10, 1000};
    bm->ArgsProduct({kSizes, kSizes});
}

BENCHMARK_REGISTER_F(UpdateTreeExecutorBenchmark, AddToSetNumbers)
    ->Apply(configureAddToSetBenchmark);

BENCHMARK_REGISTER_F(UpdateTreeExecutorBenchmark, AddToSetObjectWithStrings)
    ->Apply(configureAddToSetBenchmark);

BENCHMARK_REGISTER_F(UpdateTreeExecutorBenchmark, AddToSetObjectWithStringsCollator)
    ->Apply(configureAddToSetBenchmark);

// Builds a flat object {field0: 0, field1: 1, ..., field(n-1): n-1}.
BSONObj generateWideObject(int64_t numFields) {
    BSONObjBuilder builder;
    for (int64_t i = 0; i < numFields; ++i) {
        builder.append("field" + std::to_string(i), i);
    }
    return builder.obj();
}

// Builds a {$set: {field0: 1, field1: 2, ..., field(n-1): n}} spec targeting every field.
BSONObj generateWideSetSpec(int64_t numFields) {
    BSONObjBuilder builder;
    BSONObjBuilder inner(builder.subobjStart("$set"));
    for (int64_t i = 0; i < numFields; ++i) {
        inner.append("field" + std::to_string(i), i + 1);
    }
    inner.done();
    return builder.obj();
}

// Builds a $set spec that updates 'numUpdated' fields chosen from a document with 'docFields' total
// fields, picking indexes '0, step, 2*step, ...'. With step==1 the updated fields are clustered at
// the front of the object; with a larger step they are spread across the whole object. This is the
// workload that distinguishes a target-only index (bounded by 'numUpdated') from one that scans and
// caches the whole object.
BSONObj generatePartialSetSpec(int64_t docFields, int64_t numUpdated, int64_t step) {
    BSONObjBuilder builder;
    BSONObjBuilder inner(builder.subobjStart("$set"));
    for (int64_t i = 0; i < numUpdated; ++i) {
        int64_t index = (i * step) % docFields;
        inner.append("field" + std::to_string(index), index + 1);
    }
    inner.done();
    return builder.obj();
}

// Measures a $set that updates every field of a wide object. This is the workload the wide-object
// child lookup cache targets: without it the repeated findFirstChildNamed() scans are O(n^2) in the
// number of fields; with it they are O(n). The small field counts also guard against regressions on
// narrow documents.
BENCHMARK_DEFINE_F(UpdateTreeExecutorBenchmark, SetAllFieldsOnWideObject)(benchmark::State& state) {
    int64_t numFields = state.range(0);
    BSONObj inputDoc = generateWideObject(numFields);
    BSONObj setSpec = generateWideSetSpec(numFields);
    benchmarkSet(inputDoc, setSpec, state);
}

BENCHMARK_REGISTER_F(UpdateTreeExecutorBenchmark, SetAllFieldsOnWideObject)
    ->Arg(10)
    ->Arg(100)
    ->Arg(1000)
    ->Arg(5000);

// Measures a $set that updates only a subset of the fields of a large (5000-field) object. This is
// the case that motivates a target-only index: the index (and its setup work) should scale with the
// number of updated fields, not the document's fan out. Arg(0) is the number of updated fields and
// Arg(1) is the stride between updated field indexes (1 = clustered at the front, larger = spread
// across the whole object).
BENCHMARK_DEFINE_F(UpdateTreeExecutorBenchmark, SetPartialFieldsOnWideObject)
(benchmark::State& state) {
    static constexpr int64_t kDocFields = 5000;
    int64_t numUpdated = state.range(0);
    int64_t step = state.range(1);
    BSONObj inputDoc = generateWideObject(kDocFields);
    BSONObj setSpec = generatePartialSetSpec(kDocFields, numUpdated, step);
    benchmarkSet(inputDoc, setSpec, state);
}

BENCHMARK_REGISTER_F(UpdateTreeExecutorBenchmark, SetPartialFieldsOnWideObject)
    // Clustered at the front (small stride) and spread across the object (large stride), for a few
    // update sizes around and above the cache threshold.
    ->Args({10, 1})
    ->Args({100, 1})
    ->Args({100, 50})
    ->Args({1000, 5});

}  // namespace
}  // namespace mongo
