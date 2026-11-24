/**
 * Checks startup/runtime optimization switches and replication across all eight combinations.
 * @tags: [requires_replication]
 */
import {ReplSetTest} from "jstests/libs/replsettest.js";

const rst = new ReplSetTest({
    name: jsTestName(),
    nodes: [
        {},
        {
            rsConfig: {priority: 0},
            setParameter: {
                enableBsonValidateShortFieldNameScan: false,
                enableExhaustSingleChecksum: false,
                wiredTigerCRC32CThreeStreamEnabled: false,
            },
        },
    ],
});
rst.startSet({networkMessageCompressors: "snappy"});
try {
    rst.initiate();
    const primary = rst.getPrimary();
    const secondary = rst.getSecondary();
    const query = {
        getParameter: 1,
        enableBsonValidateShortFieldNameScan: 1,
        enableExhaustSingleChecksum: 1,
        wiredTigerCRC32CThreeStreamEnabled: 1,
    };
    for (const [node, expected] of [[primary, true], [secondary, false]]) {
        const params = assert.commandWorked(node.adminCommand(query));
        assert.eq(expected, params.enableBsonValidateShortFieldNameScan, tojson(params));
        assert.eq(expected, params.enableExhaustSingleChecksum, tojson(params));
        assert.eq(expected, params.wiredTigerCRC32CThreeStreamEnabled, tojson(params));
    }
    secondary.setSecondaryOk();
    const coll = primary.getDB(jsTestName()).switches;
    let count = 0;
    for (const bsonScan of [false, true]) {
        for (const singleChecksum of [false, true]) {
            for (const crcThreeStream of [false, true]) {
                for (const node of [primary, secondary]) {
                    assert.commandWorked(node.adminCommand({
                        setParameter: 1,
                        enableBsonValidateShortFieldNameScan: bsonScan,
                        enableExhaustSingleChecksum: singleChecksum,
                        wiredTigerCRC32CThreeStreamEnabled: crcThreeStream,
                    }));
                    const params = assert.commandWorked(node.adminCommand(query));
                    assert.eq(bsonScan, params.enableBsonValidateShortFieldNameScan, tojson(params));
                    assert.eq(singleChecksum, params.enableExhaustSingleChecksum, tojson(params));
                    assert.eq(crcThreeStream, params.wiredTigerCRC32CThreeStreamEnabled, tojson(params));
                }
                const docs = [];
                for (let i = 0; i < 32; ++i) {
                    docs.push({
                        _id: count + i,
                        short: i,
                        abcdefghijklmnopqrstuvwxyz: {nested: i},
                        payload: "x".repeat(16384),
                    });
                }
                assert.commandWorked(coll.insertMany(docs, {writeConcern: {w: 2, wtimeout: 60000}}));
                count += docs.length;
                rst.awaitReplication();
                assert.eq(count, secondary.getDB(jsTestName()).switches.find().itcount());
                assert.docEq(docs[0], secondary.getDB(jsTestName()).switches.findOne({_id: docs[0]._id}));
            }
        }
    }
    for (const node of [primary, secondary]) {
        assert.commandWorked(node.adminCommand({
            setParameter: 1,
            enableBsonValidateShortFieldNameScan: true,
            enableExhaustSingleChecksum: true,
            wiredTigerCRC32CThreeStreamEnabled: true,
        }));
        const params = assert.commandWorked(node.adminCommand(query));
        assert.eq(true, params.enableBsonValidateShortFieldNameScan);
        assert.eq(true, params.enableExhaustSingleChecksum);
        assert.eq(true, params.wiredTigerCRC32CThreeStreamEnabled);
    }
    rst.checkReplicatedDataHashes(jsTestName());
    jsTestLog("PERF_OPTIMIZATION_SWITCHES_PASS combinations=8 documents=" + count);
} finally {
    rst.stopSet();
}
