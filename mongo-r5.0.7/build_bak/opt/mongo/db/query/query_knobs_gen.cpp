/**
 * WARNING: This is a generated file. Do not modify.
 *
 * Source: buildscripts/idl/idlc.py --include src --base_dir build/opt --target_arch x86_64 --header build/opt/mongo/db/query/query_knobs_gen.h --output build/opt/mongo/db/query/query_knobs_gen.cpp src/mongo/db/query/query_knobs.idl
 */

#include "mongo/platform/basic.h"

#include "mongo/db/query/query_knobs_gen.h"

#include <bitset>
#include <set>

#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/auth/authorization_contract.h"
#include "mongo/db/commands.h"
#include "mongo/idl/command_generic_argument.h"
#include "mongo/idl/server_parameter.h"
#include "mongo/idl/server_parameter_with_storage.h"

namespace mongo {

AtomicWord<int> internalQueryPlanEvaluationWorks{10000};
AtomicDouble internalQueryPlanEvaluationCollFraction{0.3};
AtomicWord<int> internalQueryPlanEvaluationMaxResults{101};
AtomicWord<bool> internalQueryForceIntersectionPlans{false};
AtomicWord<bool> internalQueryPlannerEnableIndexIntersection{true};
AtomicWord<bool> internalQueryPlannerEnableHashIntersection{false};
AtomicWord<int> internalQueryCacheMaxEntriesPerCollection{5000};
AtomicWord<long long> internalQueryCacheMaxSizeBytesBeforeStripDebugInfo{512 * 1024 * 1024};
AtomicDouble internalQueryCacheEvictionRatio{10.0};
AtomicDouble internalQueryCacheWorksGrowthCoefficient{2.0};
AtomicWord<bool> internalQueryCacheDisableInactiveEntries{false};
int internalPipelineLengthLimit{kDebugBuild ? 200 : 1000};
AtomicWord<int> internalQueryPlannerMaxIndexedSolutions{64};
AtomicWord<bool> internalQueryEnumerationPreferLockstepOrEnumeration{false};
AtomicWord<int> internalQueryEnumerationMaxOrSolutions{10};
AtomicWord<int> internalQueryEnumerationMaxIntersectPerAnd{3};
AtomicWord<bool> internalQueryPlanOrChildrenIndependently{true};
AtomicWord<int> internalQueryMaxScansToExplode{200};
AtomicWord<bool> internalQueryPlannerGenerateCoveredWholeIndexScans{false};
AtomicWord<bool> internalQueryIgnoreUnknownJSONSchemaKeywords{false};
AtomicWord<int> internalQueryMaxBlockingSortMemoryUsageBytes{100 * 1024 * 1024};
AtomicWord<int> internalQueryExecYieldIterations{1000};
AtomicWord<int> internalQueryExecYieldPeriodMS{10};
AtomicWord<int> internalQueryFacetBufferSizeBytes{100 * 1024 * 1024};
AtomicWord<long long> internalQueryFacetMaxOutputDocSizeBytes{100 * 1024 * 1024};
AtomicWord<long long> internalLookupStageIntermediateDocumentMaxSizeBytes{100 * 1024 * 1024};
AtomicWord<long long> internalDocumentSourceGroupMaxMemoryBytes{100 * 1024 * 1024};
AtomicWord<long long> internalDocumentSourceSetWindowFieldsMaxMemoryBytes{100 * 1024 * 1024};
AtomicWord<int> internalInsertMaxBatchSize{internalQueryExecYieldIterations.load() / 2};
AtomicWord<int> internalDocumentSourceCursorBatchSizeBytes{4 * 1024 * 1024};
AtomicWord<int> internalDocumentSourceLookupCacheSizeBytes{100 * 1024 * 1024};
AtomicWord<bool> internalQueryProhibitBlockingMergeOnMongoS{false};
AtomicWord<bool> internalQueryAllowShardedLookup{false};
AtomicWord<int> internalQueryMaxJsEmitBytes{100 * 1024 * 1024};
AtomicWord<int> internalQueryMaxPushBytes{100 * 1024 * 1024};
AtomicWord<int> internalQueryMaxRangeBytes{100 * 1024 * 1024};
AtomicWord<int> internalQueryMaxAddToSetBytes{100 * 1024 * 1024};
AtomicWord<int> internalQueryJavaScriptHeapSizeLimitMB{100};
AtomicWord<int> internalQueryJavaScriptFnTimeoutMillis{60 * 1000};
AtomicWord<bool> internalQueryDesugarWhereToFunction{false};
AtomicWord<int> internalQueryDefaultDOP{1};
AtomicWord<bool> internalQueryEnableLoggingV2OplogEntries{true};
AtomicWord<int> internalQuerySlotBasedExecutionMaxStaticIndexScanIntervals{1000};
AtomicWord<bool> internalQueryEnableCSTParser{false};
AtomicWord<int> internalQueryMaxDocValidationErrorConsideredValues{10};
AtomicWord<int> internalQueryExplainSizeThresholdBytes{10 * 1024 * 1024};
AtomicWord<bool> internalQueryEnableSlotBasedExecutionEngine{false};
AtomicWord<bool> internalQueryAppendIdToSetWindowFieldsSort{false};
AtomicWord<bool> enableSearchMeta{true};
AtomicWord<bool> enableTimeoutOfInactiveSessionCursors{false};
MONGO_SERVER_PARAMETER_REGISTER(idl_aa629c1d5e7ce5614728bd1d4f3e04442ceffe4e)(InitializerContext*) {
    /**
     * Max number of times we call work() on plans before comparing them, for small collections.
     */
    [[maybe_unused]] auto* scp_0 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQueryPlanEvaluationWorks", internalQueryPlanEvaluationWorks);
        ret->addBound<idl_server_parameter_detail::GT>(0);
        return ret;
    })();

    /**
     * For large collections, the number times we work() candidate plans is taken as this fraction of the collection size.
     */
    [[maybe_unused]] auto* scp_1 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQueryPlanEvaluationCollFraction", internalQueryPlanEvaluationCollFraction);
        ret->addBound<idl_server_parameter_detail::LTE>(1.0);
        ret->addBound<idl_server_parameter_detail::GTE>(0.0);
        return ret;
    })();

    /**
     * Stop working plans once a plan returns this many results.
     */
    [[maybe_unused]] auto* scp_2 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQueryPlanEvaluationMaxResults", internalQueryPlanEvaluationMaxResults);
        ret->addBound<idl_server_parameter_detail::GTE>(0);
        return ret;
    })();

    /**
     * Do we give a big ranking bonus to intersection plans?
     */
    [[maybe_unused]] auto* scp_3 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQueryForceIntersectionPlans", internalQueryForceIntersectionPlans);
        return ret;
    })();

    /**
     * Do we have ixisect on at all?
     */
    [[maybe_unused]] auto* scp_4 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQueryPlannerEnableIndexIntersection", internalQueryPlannerEnableIndexIntersection);
        return ret;
    })();

    /**
     * Do we use hash-based intersection for rooted $and queries?
     */
    [[maybe_unused]] auto* scp_5 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQueryPlannerEnableHashIntersection", internalQueryPlannerEnableHashIntersection);
        return ret;
    })();

    /**
     * The maximum number of entries allowed in a given collection's plan cache.
     */
    auto* scp_6 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQueryCacheMaxEntriesPerCollection", internalQueryCacheMaxEntriesPerCollection);
        ret->addBound<idl_server_parameter_detail::GTE>(0);
        return ret;
    })();
    [[maybe_unused]] auto* scp_6_0 = new IDLServerParameterDeprecatedAlias("internalQueryCacheSize", scp_6);

    /**
     * Limits the amount of debug info stored across all plan caches in the system. Once the estimate of the number of bytes used across all plan caches exceeds this threshold, then debug info is not stored alongside new cache entries, in order to limit plan cache memory consumption. If plan cache entries are freed and the estimate once again dips below this threshold, then new cache entries will once again have debug info associated with them.
     */
    [[maybe_unused]] auto* scp_7 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQueryCacheMaxSizeBytesBeforeStripDebugInfo", internalQueryCacheMaxSizeBytesBeforeStripDebugInfo);
        ret->addBound<idl_server_parameter_detail::GTE>(0);
        return ret;
    })();

    /**
     * How many times more works must we perform in order to justify plan cache eviction and replanning?
     */
    [[maybe_unused]] auto* scp_8 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQueryCacheEvictionRatio", internalQueryCacheEvictionRatio);
        ret->addBound<idl_server_parameter_detail::GTE>(0.0);
        return ret;
    })();

    /**
     * How quickly the the 'works' value in an inactive cache entry will grow. It grows exponentially. The value of this server parameter is the base.
     */
    [[maybe_unused]] auto* scp_9 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQueryCacheWorksGrowthCoefficient", internalQueryCacheWorksGrowthCoefficient);
        ret->addBound<idl_server_parameter_detail::GT>(1.0);
        return ret;
    })();

    /**
     * Whether or not cache entries can be marked as 'inactive'.
     */
    [[maybe_unused]] auto* scp_10 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQueryCacheDisableInactiveEntries", internalQueryCacheDisableInactiveEntries);
        return ret;
    })();

    /**
     * The maximum length allowed for an an aggregation pipeline.
     */
    [[maybe_unused]] auto* scp_11 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupOnly>("internalPipelineLengthLimit", internalPipelineLengthLimit);
        ret->addBound<idl_server_parameter_detail::GT>(0);
        return ret;
    })();

    /**
     * How many indexed solutions will QueryPlanner::plan output?
     */
    [[maybe_unused]] auto* scp_12 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQueryPlannerMaxIndexedSolutions", internalQueryPlannerMaxIndexedSolutions);
        ret->addBound<idl_server_parameter_detail::GTE>(0);
        return ret;
    })();

    /**
     * If set to true, instructs the plan enumerator to enumerate contained $ors in a special order. $or enumeration can generate an exponential number of plans, and is therefore limited at some arbitrary cutoff controlled by a parameter. When this limit is hit, the order of enumeration is important. For example, a query like the following has a 'contained $or' (within an $and): {a: 1, $or: [{b: 1, c: 1}, {b: 2, c: 2}]} For this query if there are indexes a_b={a: 1, b: 1} and a_c={a: 1, c: 1}, the normal enumeration order would output assignments [a_b, a_b], [a_c, a_b], [a_b, a_c], then [a_c, a_c]. This flag will instruct the enumerator to instead prefer a different order. It's hard to summarize, but perhaps the phrases 'lockstep enumeration', 'simultaneous advancement', or 'parallel iteration' will help the reader. The effect is to give earlier enumeration to plans which use the same choice across all branches. In this order, we would get assignments [a_b, a_b], [a_c, a_c], [a_c, a_b], then [a_b, a_c]. This is thought to be helpful in general, but particularly in cases where all children of the $or use the same fields and have the same indexes available, as in this example.
     */
    [[maybe_unused]] auto* scp_13 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQueryEnumerationPreferLockstepOrEnumeration", internalQueryEnumerationPreferLockstepOrEnumeration);
        return ret;
    })();

    /**
     * How many solutions will the enumerator consider at each OR?
     */
    [[maybe_unused]] auto* scp_14 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQueryEnumerationMaxOrSolutions", internalQueryEnumerationMaxOrSolutions);
        ret->addBound<idl_server_parameter_detail::GTE>(0);
        return ret;
    })();

    /**
     * How many intersections will the enumerator consider at each AND?
     */
    [[maybe_unused]] auto* scp_15 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQueryEnumerationMaxIntersectPerAnd", internalQueryEnumerationMaxIntersectPerAnd);
        ret->addBound<idl_server_parameter_detail::GTE>(0);
        return ret;
    })();

    /**
     * Do we want to plan each child of the OR independently?
     */
    [[maybe_unused]] auto* scp_16 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQueryPlanOrChildrenIndependently", internalQueryPlanOrChildrenIndependently);
        return ret;
    })();

    /**
     * How many index scans are we willing to produce in order to obtain a sort order during explodeForSort?
     */
    [[maybe_unused]] auto* scp_17 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQueryMaxScansToExplode", internalQueryMaxScansToExplode);
        ret->addBound<idl_server_parameter_detail::GTE>(0);
        return ret;
    })();

    /**
     * Allow the planner to generate covered whole index scans, rather than falling back to a COLLSCAN.
     */
    [[maybe_unused]] auto* scp_18 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQueryPlannerGenerateCoveredWholeIndexScans", internalQueryPlannerGenerateCoveredWholeIndexScans);
        return ret;
    })();

    /**
     * Ignore unknown JSON Schema keywords.
     */
    [[maybe_unused]] auto* scp_19 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQueryIgnoreUnknownJSONSchemaKeywords", internalQueryIgnoreUnknownJSONSchemaKeywords);
        return ret;
    })();

    /**
     * The maximum amount of memory a query (e.g. a find or aggregate command) is willing to use to execute a blocking sort, measured in bytes. If disk use is allowed, then it may be possible to sort more data, but this limit will still constrain the memory consumption.
     */
    [[maybe_unused]] auto* scp_20 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQueryMaxBlockingSortMemoryUsageBytes", internalQueryMaxBlockingSortMemoryUsageBytes);
        ret->addBound<idl_server_parameter_detail::GTE>(0);
        return ret;
    })();

    /**
     * Yield after this many "should yield?" checks.
     */
    [[maybe_unused]] auto* scp_21 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQueryExecYieldIterations", internalQueryExecYieldIterations);
        return ret;
    })();

    /**
     * Yield if it's been at least this many milliseconds since we last yielded.
     */
    [[maybe_unused]] auto* scp_22 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQueryExecYieldPeriodMS", internalQueryExecYieldPeriodMS);
        ret->addBound<idl_server_parameter_detail::GTE>(0);
        return ret;
    })();

    /**
     * The number of bytes to buffer at once during a $facet stage.
     */
    [[maybe_unused]] auto* scp_23 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQueryFacetBufferSizeBytes", internalQueryFacetBufferSizeBytes);
        ret->addBound<idl_server_parameter_detail::GT>(0);
        return ret;
    })();

    /**
     * The number of bytes to buffer at once during a $facet stage.
     */
    [[maybe_unused]] auto* scp_24 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQueryFacetMaxOutputDocSizeBytes", internalQueryFacetMaxOutputDocSizeBytes);
        ret->addBound<idl_server_parameter_detail::GT>(0);
        return ret;
    })();

    /**
     * Maximum size of the result set that we cache from the foreign collection during a $lookup.
     */
    [[maybe_unused]] auto* scp_25 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalLookupStageIntermediateDocumentMaxSizeBytes", internalLookupStageIntermediateDocumentMaxSizeBytes);
        ret->addBound<idl_server_parameter_detail::GTE>(([]{ constexpr auto value = BSONObjMaxInternalSize; return value; })());
        return ret;
    })();

    /**
     * Maximum size of the data that the $group aggregation stage will cache in-memory before spilling to disk.
     */
    [[maybe_unused]] auto* scp_26 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalDocumentSourceGroupMaxMemoryBytes", internalDocumentSourceGroupMaxMemoryBytes);
        ret->addBound<idl_server_parameter_detail::GT>(0);
        return ret;
    })();

    /**
     * Maximum size of the data that the $setWindowFields aggregation stage will cache in-memory before throwing an error.
     */
    [[maybe_unused]] auto* scp_27 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalDocumentSourceSetWindowFieldsMaxMemoryBytes", internalDocumentSourceSetWindowFieldsMaxMemoryBytes);
        ret->addBound<idl_server_parameter_detail::GT>(0);
        return ret;
    })();

    /**
     * Maximum number of documents that we will insert in a single batch.
     */
    [[maybe_unused]] auto* scp_28 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalInsertMaxBatchSize", internalInsertMaxBatchSize);
        ret->addBound<idl_server_parameter_detail::GT>(0);
        return ret;
    })();

    /**
     * Maximum amount of data that DocumentSourceCursor will cache from the underlying PlanExecutor before pipeline processing.
     */
    [[maybe_unused]] auto* scp_29 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalDocumentSourceCursorBatchSizeBytes", internalDocumentSourceCursorBatchSizeBytes);
        ret->addBound<idl_server_parameter_detail::GTE>(0);
        return ret;
    })();

    /**
     * Maximum amount of non-correlated foreign-collection data that the $lookup stage will cache before abandoning the cache and executing the full pipeline on each iteration.
     */
    [[maybe_unused]] auto* scp_30 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalDocumentSourceLookupCacheSizeBytes", internalDocumentSourceLookupCacheSizeBytes);
        ret->addBound<idl_server_parameter_detail::GTE>(0);
        return ret;
    })();

    /**
     * If true, blocking stages such as $group or non-merging $sort will be prohibited from running on mongoS.
     */
    [[maybe_unused]] auto* scp_31 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQueryProhibitBlockingMergeOnMongoS", internalQueryProhibitBlockingMergeOnMongoS);
        return ret;
    })();

    /**
     * If true, activates the incomplete sharded $lookup feature.
     */
    [[maybe_unused]] auto* scp_32 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQueryAllowShardedLookup", internalQueryAllowShardedLookup);
        return ret;
    })();

    /**
     * Limits the vector of values emitted from a single document's call to JsEmit to the given size in bytes.
     */
    [[maybe_unused]] auto* scp_33 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQueryMaxJsEmitBytes", internalQueryMaxJsEmitBytes);
        ret->addBound<idl_server_parameter_detail::GT>(0);
        return ret;
    })();

    /**
     * Limits the vector of values pushed into a single array while grouping with the $push accumulator.
     */
    [[maybe_unused]] auto* scp_34 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQueryMaxPushBytes", internalQueryMaxPushBytes);
        ret->addBound<idl_server_parameter_detail::GT>(0);
        return ret;
    })();

    /**
     * Limits the vector of values pushed into a single array while generating $range result.
     */
    [[maybe_unused]] auto* scp_35 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQueryMaxRangeBytes", internalQueryMaxRangeBytes);
        ret->addBound<idl_server_parameter_detail::GT>(0);
        return ret;
    })();

    /**
     * Limits the vector of values pushed into a single array while grouping with the $addToSet accumulator.
     */
    [[maybe_unused]] auto* scp_36 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQueryMaxAddToSetBytes", internalQueryMaxAddToSetBytes);
        ret->addBound<idl_server_parameter_detail::GT>(0);
        return ret;
    })();

    /**
     * Limits the JavaScript heap size used in aggregation. Will defer to the global 'jsHeapLimitMB' limit if the global limit is smaller.
     */
    [[maybe_unused]] auto* scp_37 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQueryJavaScriptHeapSizeLimitMB", internalQueryJavaScriptHeapSizeLimitMB);
        return ret;
    })();

    /**
     * Limits the maximum allowed time a user-defined javascript function can run in a query.
     */
    [[maybe_unused]] auto* scp_38 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQueryJavaScriptFnTimeoutMillis", internalQueryJavaScriptFnTimeoutMillis);
        ret->addBound<idl_server_parameter_detail::GT>(0);
        return ret;
    })();

    /**
     * When true, desugars $where to $expr/$function.
     */
    [[maybe_unused]] auto* scp_39 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQueryDesugarWhereToFunction", internalQueryDesugarWhereToFunction);
        return ret;
    })();

    /**
     * Default degree of parallelism. This an internal experimental parameter and should not be changed on live systems.
     */
    auto* scp_40 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQueryDefaultDOP", internalQueryDefaultDOP);
        ret->addBound<idl_server_parameter_detail::GT>(0);
        return ret;
    })();
    scp_40->setTestOnly();

    /**
     * If true, this node may log $v:2 delta-style oplog entries.
     */
    [[maybe_unused]] auto* scp_41 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQueryEnableLoggingV2OplogEntries", internalQueryEnableLoggingV2OplogEntries);
        return ret;
    })();

    /**
     * Limits the number of statically known intervals that SBE can decompose index bounds into when possible.
     */
    [[maybe_unused]] auto* scp_42 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQuerySlotBasedExecutionMaxStaticIndexScanIntervals", internalQuerySlotBasedExecutionMaxStaticIndexScanIntervals);
        ret->addBound<idl_server_parameter_detail::GT>(0);
        return ret;
    })();

    /**
     * If true, use the grammar-based parser and CST to parse queries.
     */
    [[maybe_unused]] auto* scp_43 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQueryEnableCSTParser", internalQueryEnableCSTParser);
        return ret;
    })();

    /**
     * Limits the number of values reported in the 'consideredValues' array when generating a descriptive document validation error.
     */
    [[maybe_unused]] auto* scp_44 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQueryMaxDocValidationErrorConsideredValues", internalQueryMaxDocValidationErrorConsideredValues);
        ret->addBound<idl_server_parameter_detail::GT>(0);
        return ret;
    })();

    /**
     * Number of bytes after which explain should start truncating portions of its output.
     */
    [[maybe_unused]] auto* scp_45 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQueryExplainSizeThresholdBytes", internalQueryExplainSizeThresholdBytes);
        ret->addBound<idl_server_parameter_detail::GT>(0);
        ret->addBound<idl_server_parameter_detail::LTE>(([]{ constexpr auto value = BSONObjMaxInternalSize; return value; })());
        return ret;
    })();

    /**
     * If true, the system will use the SBE execution engine for eligible queries, otherwise all queries will execute using the classic execution engine.
     */
    [[maybe_unused]] auto* scp_46 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQueryEnableSlotBasedExecutionEngine", internalQueryEnableSlotBasedExecutionEngine);
        return ret;
    })();

    /**
     * If true, appends _id to the sort stage generated by desugaring $setWindowFields to ensure deterministic sort order.
     */
    [[maybe_unused]] auto* scp_47 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("internalQueryAppendIdToSetWindowFieldsSort", internalQueryAppendIdToSetWindowFieldsSort);
        return ret;
    })();

    /**
     * Exists for backwards compatibility in startup parameters, enabling this was required on 4.4 to access SEARCH_META variables. Does not do anything.
     */
    [[maybe_unused]] auto* scp_48 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("enableSearchMeta", enableSearchMeta);
        return ret;
    })();

    /**
     * If true, cursors opened within sessions are eligible for inactive cursor timeout.
     */
    [[maybe_unused]] auto* scp_49 = ([]() -> ServerParameter* {
        auto* ret = makeIDLServerParameterWithStorage<ServerParameterType::kStartupAndRuntime>("enableTimeoutOfInactiveSessionCursors", enableTimeoutOfInactiveSessionCursors);
        return ret;
    })();

}
}  // namespace mongo
