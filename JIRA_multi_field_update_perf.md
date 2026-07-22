# [SERVER-XXXXX] Optimize multi-field updates on wide documents: avoid repeated linear child lookups in UpdateObjectNode

> Draft MongoDB Jira report. Fill in `SERVER-XXXXX` after the ticket is created.

- **Issue Type:** Improvement / Performance
- **Component/s:** Write Ops / Update
- **Affects area:** `src/mongo/db/update/update_object_node.cpp` (`UpdateObjectNode::apply`)
- **Reporter:** (you)
- **Related:** SERVER-130410 (replication wire-compression for large-document replication). That ticket targets *whole-document replacement*; this ticket targets the *complementary* real-world pattern: **multi-field random updates on wide documents.**

---

## Background

In gaming workloads, most user data is stored as large documents (a single per-player document
holding hundreds to thousands of attributes), and the dominant access pattern is **updates** —
player state is continuously modified during play. In practice these updates take two shapes: some
users implement them as whole-document replacements, while others update the individual fields
directly. This makes the cost of locating fields inside a wide document a first-order factor for such
deployments, which is exactly what this ticket addresses.

---

## Summary

Updating many fields of a wide document (an object with a large number of sibling fields) is
`O(n^2)` in the number of fields, because each targeted field is located with an independent linear
`mutablebson::Element::findFirstChildNamed()` scan over the same sibling chain.

This proposal adds a per-`apply()`, target-only field-name index so those repeated lookups become
`O(1)`, reducing the overall cost from `O(n^2)` to `O(n)`. It is guarded by a runtime-tunable
threshold (default off), only applies to object nodes, and does not change update semantics.

Measured on a 3-node replica set with YCSB (100k docs, 5000 fields/doc), throughput improves by
roughly **1.5x–11x** across the tested lookup-cost-equivalent scenarios (larger updates benefit
more), and the dominant CPU symbol `findFirstChildNamed` disappears from the profile.

---

## Motivation / Real-world workload

Game and user-profile workloads on MongoDB commonly store a large per-user document and update it in
two shapes:

1. **Whole-document replacement** — addressed by SERVER-130410 (and the replication path).
2. **Multi-field random update** — a single `update` with a `$set` (or `$inc`/`$mul`/...) touching
   many fields of the same wide document, e.g.

For the second pattern, the server must first load the pre-image into a `mutablebson::Document` and
then locate each target field before modifying it. On a wide document these lookups dominate CPU.

---

## Root cause

`UpdateObjectNode::apply()` resolves each child field via:

```text
UpdateObjectNode::apply
  -> applyChild
    -> getChild(parent, field)
      -> Element::operator[](field)
        -> Element::findFirstChildNamed(field)   // linear scan over the sibling chain
```

`findFirstChildNamed()` is a linear walk over the object's child/sibling list, comparing field names
(`memcmp`). When one update touches many fields of the same parent object, the same chain is
re-scanned from the head once per field:

```text
find field @ pos 1   -> ~1 comparison
find field @ pos 2   -> ~2 comparisons
...
find field @ pos n   -> ~n comparisons
Total ~ n(n+1)/2  =>  O(n^2)
```

`perf` on the un-optimized build (5000-field doc, full update) shows the linear lookup as the clear
hotspot:

```text
~34.75%  mongo::mutablebson::Element::findFirstChildNamed
~31.33%  __memcmp_avx2_movbe
~19.70%  mongo::mutablebson::Document::Impl::resolveRightSibling
 -----   (i.e. ~85% of CPU is spent locating fields, not modifying them)
```

`setValue`, oplog diff (`V2LogBuilder`), and WiredTiger write are all <3% — the bottleneck is field
location, not the write itself.

---

## Proposed change

In `UpdateObjectNode::apply()`, before iterating the children to update, optionally build a
**target-only** field-name index over the parent object's children:

- The index is seeded from exactly the fields this node updates at this level (its `_children`, plus
  the positional `matchedField` if present). Its size is bounded by the **number of updated fields**,
  not by the document's fan-out.
- A single pass over the object's children fills in each target's `Element`; the scan stops early
  once every target has been located.
- Subsequent `getChild()` calls consult the index (`O(1)`) instead of `findFirstChildNamed()`.

Complexity: `O(document-fields-scanned + updated-fields)` ≈ `O(n)` instead of `O(n^2)`.

### Correctness properties

- **Same semantics.** The index only changes *how* an existing field is located. A field that is not
  a target, or a parent that is an array, falls back to the original linear path. A target that does
  not exist is recorded as "absent" (equivalent to a `findFirstChildNamed()` miss), so field creation
  is unchanged.
- **Duplicate field names.** The first `Element` seen for a name is kept, preserving the
  "first match wins" semantics of `findFirstChildNamed()`.
- **Stable entries.** Values are `mutablebson::Element` (`Document* + RepIdx`). `RepIdx` stays valid
  across element-vector reallocation, and in-place value changes do not move elements, so cached
  entries remain valid across sibling updates.
- **Bound to one parent.** The index is validated against the exact object it was built from before
  use, and only lives on the `apply()` stack frame — no locks, no cross-request state.
- **Array nodes untouched.** Arrays are addressed by numeric index (`findNthChild`), so they keep the
  original path.

### Tunable (default off)

A runtime server parameter controls the feature:

```text
internalUpdateObjectNodeChildLookupCacheThreshold   (Atomic<int>, set_at: [startup, runtime])
  default: 0        -> disabled (identical to today's behavior)
  N > 0             -> build the index when a node updates >= N fields
```

- `0` disables the optimization entirely (safe rollback with no restart).
- A positive threshold guards small updates so narrow documents pay zero extra cost.

This lets operators enable/tune/disable it online per node.

---

## Benchmark results (YCSB, replica set)

- Cluster: 3-node replica set (`rs0`), 100 threads.
- Data: `recordcount=100000`, `fieldcount=5000` (each doc has `field0..field4999`).
- Workload: 100% update, `operationcount=50000`.
- "Update K fields (random)" is emulated with an equivalent `writeallfields=true fieldcount=M`, where
  `M` is chosen so the **linear-lookup cost** matches a random-K update on a 5000-field document
  (`M(M+1)/2 ≈ K*(N+1)/2`, `N=5000`). See the equivalence table below.

Two-phase method (note the two different meanings of `fieldcount`):

1. **Load once with `fieldcount=5000`** — this defines the real document width (`field0..field4999`)
   and is fixed for every scenario:

   ```bash
   ./bin/ycsb.sh load mongodb -s -P workloads/workloada \
     -p mongodb.url='mongodb://<user>:<pass>@host1:port1,host2:port2,host3:port3/admin' \
     -p table=test -threads 100 -p recordcount=100000 -p fieldcount=5000
   ```

2. **Run the update workload with the equivalent `fieldcount=M`** — here `fieldcount` is *not* the
   document width; it is the equivalence value from the table for the random-K scenario being
   emulated (example below is `fieldcount=1581`, i.e. random-500-fields):

   ```bash
   ./bin/ycsb.sh run mongodb -s -P workloads/workloada \
     -p mongodb.url='mongodb://<user>:<pass>@host1:port1,host2:port2,host3:port3/admin?authSource=admin&replicaSet=rs0' \
     -p table=test -threads 100 -p recordcount=100000 \
     -p readproportion=0 -p updateproportion=1 -p insertproportion=0 \
     -p operationcount=50000 -p fieldcount=1581 -p writeallfields=true
   ```

   For other scenarios, only change `-p fieldcount=` to the matching `M` (e.g. `707` for random-100,
   `2236` for random-1000); everything else stays the same. Baseline vs optimized is toggled online
   via `setParameter: internalUpdateObjectNodeChildLookupCacheThreshold` (0 = off, 50 = on).

All "before" numbers are with the optimization disabled (`threshold=0`, original linear
`findFirstChildNamed` lookup); all "after" numbers are with the per-`apply()` target-only index
enabled (`threshold=50`). Nothing else changes between the two runs — same build, same data, same
YCSB parameters — so each row isolates the effect of this optimization.

| Random-K scenario (emulated, lookup-cost equivalent) | % of 5000 | Equivalent YCSB `fieldcount` | Throughput before (ops/s) | Throughput after (ops/s) | Speedup | UPDATE avg latency before | after |
|---:|---:|---:|---:|---:|---:|---:|---:|
| 5000 | 100% | 5000 | 23.68 | 260.57 | ~11.0x | 3899 ms | 381 ms |
| 2000 | 40% | 3162 | 51.12 | 392.55 | ~7.7x | 1831 ms | 253 ms |
| 1000 | 20% | 2236 | 56.36 | 488.49 | ~8.7x | 1648 ms | 203 ms |
| 500 | 10% | 1581 | 83.00 | 601.81 | ~7.3x | 1134 ms | 165 ms |
| 100 | 2% | 707 | 294.66 | 595.03 | ~2.0x | 334 ms | 166 ms |
| 50 | 1% | 500 | 458.28 | 824.27 | ~1.8x | 216 ms | 120 ms |
| 10 | 0.2% | 223 | 595.03 | 911.23 | ~1.5x | 166 ms | 109 ms |

Even the smaller cases still improve (~1.5x–1.8x): the gain shrinks with fewer fields because the
`O(n^2)` linear-lookup cost is smaller there (before-profile shows `findFirstChildNamed` at ~20–29%
for these, vs ~34%+ for the widest cases), but the linear hotspot still disappears after the change.

### Profile before vs after

- **Before:** `findFirstChildNamed` ~34–37%, `__memcmp_avx2_movbe` ~24–31%,
  `resolveRightSibling` ~20% — together ~80–85% of CPU.
- **After:** `findFirstChildNamed` drops off the hot path entirely; remaining time shifts to expected
  work (`parseAndMerge`, `createUpdateNodeByMerging`, snappy compression on the replication path,
  WiredTiger checksums), i.e. the `O(n^2)` field-location hotspot is gone.

### Why the equivalence (and not a raw random-K workload)

Stock YCSB with `writeallfields=true` does **not** pick K random fields out of the document — it
rewrites the fields defined by the workload, i.e. the **first M fields** `field0..field(M-1)`:

```javascript
{$set: {field0: ..., field1: ..., ..., field(M-1): ...}}
```

Because the update path locates each field by walking the object's sibling chain from the head,
*where* the target fields sit on that chain determines the cost:

- **Real random-K update:** the K targets are spread uniformly across `field0..field4999`, so each
  lookup walks on average ~half the chain (~`(N+1)/2` comparisons). K such lookups cost
  `K * (N+1)/2`.
- **YCSB first-M update:** the M targets are packed at the front of the chain, so lookup i costs ~i
  comparisons. M such lookups cost only `M(M+1)/2`.

For the same K, these two are **not** equal — a front-packed update is much cheaper to locate than a
uniformly-random one. To reproduce the *linear-lookup cost* of a random-K update with unmodified
YCSB, we therefore pick an M whose front-packed cost equals the random-K cost (equating the two
expressions below). This is why, e.g., "random 100 fields" maps to `fieldcount=707`, not 100.

### Equivalence formula (random-K ↔ YCSB fieldcount)

```text
Cost_random(K) ≈ K * (N + 1) / 2          # random K fields over N=5000
Cost_ycsb(M)   ≈ M * (M + 1) / 2          # YCSB updates the first M fields
=> M ≈ (sqrt(1 + 4*K*(N+1)) - 1) / 2
```

This models field-location cost only; it is a good proxy here because `findFirstChildNamed` is the
dominant cost. Strict validation of true random-K updates would require a YCSB workload that selects
K random distinct fields per update.

---

## Scope and non-goals

- **In scope:** object-node multi-field updates for value-modifying and structural modifiers
  (`$set`/`$inc`/`$mul`/`$min`/`$max`/`$currentDate`/`$unset`/`$rename`), with unit-test coverage.
- **Out of scope:** array-node fan-out (kept on the original path), and any change to mutableBSON
  core data structures. A general mutableBSON lazy field-name index could be a follow-up, but is
  intentionally not part of this change to keep the blast radius small.

## Testing

- Unit tests are added for wide-object multi-field updates: value modifiers, `$unset`, `$rename`,
  nested wide objects, duplicate field names, threshold boundary, positional operator, and
  target-only subset/all-missing cases. Each test asserts the output is identical to the
  non-cached path (i.e. the optimization is expected to be behavior-preserving).
- Microbenchmarks are added in `update_tree_executor_bm.cpp` for all-fields and partial/spread
  updates across field counts.
- YCSB before/after on a replica set (above), using lookup-cost-equivalent `fieldcount` values
  rather than a true random-K workload (see the equivalence section for why).

## Risk / rollback

- Default `0` = disabled, so the change is inert until explicitly enabled.
- Enable/disable at runtime via `setParameter` (no restart), so rollback is immediate.
- Semantics are unchanged regardless of threshold; only the field-location path differs.

## Open questions for reviewers

1. Is a per-`apply()` target-only index acceptable, or would you prefer a general mutableBSON
   field-name index (larger blast radius)?
2. Preferred default: keep `0` (opt-in) or ship with a conservative positive default (e.g. 64/128)?
3. Any additional correctness cases you want covered for `$rename`/positional under the index?

---

## Contribution

If this ticket is accepted, I would be happy to contribute the implementation. I have already signed
the MongoDB Contributor Agreement. I also have a working prototype (the per-`apply()` target-only
index, the runtime server parameter, unit tests, and the microbenchmarks referenced above), and I'm
glad to iterate on it to match the direction and conventions the team prefers.
