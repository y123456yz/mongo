/**
 * Integration test for the wide-document multi-field update optimization
 * (target-only per-apply child lookup cache), controlled by the server parameter
 * `internalUpdateObjectNodeChildLookupCacheThreshold`.
 *
 * The optimization must only affect performance, never update semantics. This test drives a real
 * mongod through wide-document multi-field updates ($set / $inc / $unset / $rename over wide top
 * level and wide nested objects, plus field creation) and asserts that results are IDENTICAL
 * whether the cache is disabled (threshold = 0), enabled with a small threshold, or enabled most
 * aggressively (threshold = 1), and that they match independently computed expected values.
 *
 * All modifiers target disjoint field paths so a single combined update is legal (no conflicting
 * update operators on the same path).
 *
 * @tags: [requires_replication]
 */
import {ReplSetTest} from "jstests/libs/replsettest.js";

const PARAM = "internalUpdateObjectNodeChildLookupCacheThreshold";
const NFIELDS = 400;   // wide top-level object: f0..f399
const NNESTED = 300;   // wide nested object under profile.features: n0..n299
const NDEL = 60;       // dedicated $unset group: delGroup.g0..g59
const NRENAME = 60;    // dedicated $rename group: renameSrc.r0..r59 -> renameDst.d0..d59
const NNEWTOP = 50;    // created top-level fields: newTop0..newTop49

function setThreshold(db, v) {
    assert.commandWorked(db.adminCommand({setParameter: 1, [PARAM]: v}),
                         `failed to set ${PARAM}=${v}`);
}
function getThreshold(db) {
    const res = assert.commandWorked(db.adminCommand({getParameter: 1, [PARAM]: 1}));
    return res[PARAM];
}

// Build the baseline wide document deterministically.
function makeBaselineDoc(id) {
    const doc = {_id: id};
    for (let i = 0; i < NFIELDS; i++) {
        doc["f" + i] = i;                 // numeric so $inc applies
    }
    const features = {};
    for (let i = 0; i < NNESTED; i++) {
        features["n" + i] = i;
    }
    doc.profile = {features: features, tag: "base"};

    doc.delGroup = {};
    for (let i = 0; i < NDEL; i++) {
        doc.delGroup["g" + i] = i;        // to be $unset
    }
    doc.renameSrc = {};
    for (let i = 0; i < NRENAME; i++) {
        doc.renameSrc["r" + i] = i * 10;  // to be $rename'd
    }
    return doc;
}

// A representative, semantics-rich multi-field update. Every modifier touches a DISJOINT set of
// paths, so the whole thing is one legal update command exercising wide parents at once.
function buildUpdateOps() {
    const setSpec = {};
    const incSpec = {};
    // Top-level: even -> $set, odd -> $inc (disjoint leaves under the same wide parent).
    for (let i = 0; i < NFIELDS; i++) {
        if (i % 2 === 0)
            setSpec["f" + i] = "set-" + i;
        else
            incSpec["f" + i] = 100;
    }
    // Create many brand-new top-level fields.
    for (let i = 0; i < NNEWTOP; i++) {
        setSpec["newTop" + i] = i;
    }
    // Wide nested parent: even -> $set, odd -> $inc.
    for (let i = 0; i < NNESTED; i++) {
        if (i % 2 === 0)
            setSpec["profile.features.n" + i] = "nset-" + i;
        else
            incSpec["profile.features.n" + i] = 7;
    }

    const unsetSpec = {};
    for (let i = 0; i < NDEL; i++) {
        unsetSpec["delGroup.g" + i] = "";
    }

    const renameSpec = {};
    for (let i = 0; i < NRENAME; i++) {
        renameSpec["renameSrc.r" + i] = "renameDst.d" + i;
    }

    return {$set: setSpec, $inc: incSpec, $unset: unsetSpec, $rename: renameSpec};
}

// Independently compute the expected document (not just cache-on == cache-off).
function computeExpected() {
    const doc = makeBaselineDoc(0);
    const ops = buildUpdateOps();
    for (const path in ops.$set)
        setByPath(doc, path, ops.$set[path]);
    for (const path in ops.$inc) {
        const cur = getByPath(doc, path);
        setByPath(doc, path, (cur === undefined ? 0 : cur) + ops.$inc[path]);
    }
    for (const path in ops.$unset)
        unsetByPath(doc, path);
    for (const path in ops.$rename) {
        const val = getByPath(doc, path);
        unsetByPath(doc, path);
        if (val !== undefined)
            setByPath(doc, ops.$rename[path], val);
    }
    return doc;
}

function getByPath(obj, path) {
    let cur = obj;
    for (const p of path.split(".")) {
        if (cur === undefined || cur === null || typeof cur !== "object")
            return undefined;
        cur = cur[p];
    }
    return cur;
}
function setByPath(obj, path, val) {
    const parts = path.split(".");
    let cur = obj;
    for (let i = 0; i < parts.length - 1; i++) {
        if (typeof cur[parts[i]] !== "object" || cur[parts[i]] === null)
            cur[parts[i]] = {};
        cur = cur[parts[i]];
    }
    cur[parts[parts.length - 1]] = val;
}
function unsetByPath(obj, path) {
    const parts = path.split(".");
    let cur = obj;
    for (let i = 0; i < parts.length - 1; i++) {
        if (typeof cur[parts[i]] !== "object" || cur[parts[i]] === null)
            return;
        cur = cur[parts[i]];
    }
    delete cur[parts[parts.length - 1]];
}

function runAtThreshold(coll, adminDb, threshold) {
    setThreshold(adminDb, threshold);
    assert.eq(getThreshold(adminDb), threshold, "threshold did not take effect");

    coll.drop();
    assert.commandWorked(coll.insert(makeBaselineDoc(0)));
    assert.commandWorked(coll.update({_id: 0}, buildUpdateOps()));

    const got = coll.findOne({_id: 0});
    assert.neq(null, got, "document disappeared after update");
    return got;
}

function assertDocsEqual(a, b, msg) {
    assert(bsonUnorderedFieldsCompare(a, b) === 0,
           msg + "\n a=" + tojson(a) + "\n b=" + tojson(b));
}

const rst = new ReplSetTest({nodes: 1});
rst.startSet();
rst.initiate();

const primary = rst.getPrimary();
const testDb = primary.getDB("wide_doc_update");
const adminDb = primary.getDB("admin");
const coll = testDb.coll;

jsTestLog("Default value of " + PARAM + " = " + getThreshold(adminDb));

const resOff = runAtThreshold(coll, adminDb, 0);          // cache disabled (linear path)
const resOn = runAtThreshold(coll, adminDb, 8);           // cache enabled (small threshold)
const resAggressive = runAtThreshold(coll, adminDb, 1);   // cache enabled (most aggressive)
const expected = computeExpected();                        // independent ground truth

assertDocsEqual(resOff, resOn, "cache-on (threshold=8) differs from cache-off (threshold=0)");
assertDocsEqual(resOff, resAggressive,
                "cache-on (threshold=1) differs from cache-off (threshold=0)");
assertDocsEqual(resOff, expected, "cache-off result differs from independently computed expected");

// Representative spot checks.
assert.eq(resOn.f0, "set-0");                          // top-level even $set
assert.eq(resOn.f1, 1 + 100);                          // top-level odd $inc
assert.eq(resOn.newTop0, 0);                           // created field
assert.eq(resOn.profile.features.n0, "nset-0");        // nested even $set
assert.eq(resOn.profile.features.n1, 1 + 7);           // nested odd $inc
assert.eq(resOn.delGroup, {});                         // $unset removed all
assert.eq(resOn.renameDst.d0, 0);                      // $rename dest (r0 = 0)
assert.eq(resOn.renameDst.d5, 50);                     // $rename dest (r5 = 50)
assert.eq(resOn.renameSrc, {});                        // rename sources gone

jsTestLog("wide-document-update-perf integration test PASSED: cache off/on/aggressive all match " +
          "the independently computed expected result.");

rst.stopSet();
