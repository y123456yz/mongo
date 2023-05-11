
/**
 *    Copyright (C) 2018-present MongoDB, Inc.
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the Server Side Public License, version 1,
 *    as published by MongoDB, Inc.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    Server Side Public License for more details.
 *
 *    You should have received a copy of the Server Side Public License
 *    along with this program. If not, see
 *    <http://www.mongodb.com/licensing/server-side-public-license>.
 *
 *    As a special exception, the copyright holders give permission to link the
 *    code of portions of this program with the OpenSSL library under certain
 *    conditions as described in each individual source file and distribute
 *    linked combinations including the program with the OpenSSL library. You
 *    must comply with the Server Side Public License in all respects for
 *    all of the code used other than as permitted herein. If you modify file(s)
 *    with this exception, you may extend this exception to your version of the
 *    file(s), but you are not obligated to do so. If you do not wish to do so,
 *    delete this exception statement from your version. If you delete this
 *    exception statement from all source files in the program, then also delete
 *    it in the license file.
 */

var {ErrorCodes, ErrorCodeStrings} = (function() {
    const handler = {
        get: function(obj, prop) {
            if (typeof prop !== "symbol" && prop in obj === false && prop in Object === false) {
                throw new Error('Unknown Error Code: ' + prop.toString());
            }

            return obj[prop];
        }
    };

    const ErrorCodesObject = {
        'OK': 0,
        'InternalError': 1,
        'BadValue': 2,
        'OBSOLETE_DuplicateKey': 3,
        'NoSuchKey': 4,
        'GraphContainsCycle': 5,
        'HostUnreachable': 6,
        'HostNotFound': 7,
        'UnknownError': 8,
        'FailedToParse': 9,
        'CannotMutateObject': 10,
        'UserNotFound': 11,
        'UnsupportedFormat': 12,
        'Unauthorized': 13,
        'TypeMismatch': 14,
        'Overflow': 15,
        'InvalidLength': 16,
        'ProtocolError': 17,
        'AuthenticationFailed': 18,
        'CannotReuseObject': 19,
        'IllegalOperation': 20,
        'EmptyArrayOperation': 21,
        'InvalidBSON': 22,
        'AlreadyInitialized': 23,
        'LockTimeout': 24,
        'RemoteValidationError': 25,
        'NamespaceNotFound': 26,
        'IndexNotFound': 27,
        'PathNotViable': 28,
        'NonExistentPath': 29,
        'InvalidPath': 30,
        'RoleNotFound': 31,
        'RolesNotRelated': 32,
        'PrivilegeNotFound': 33,
        'CannotBackfillArray': 34,
        'UserModificationFailed': 35,
        'RemoteChangeDetected': 36,
        'FileRenameFailed': 37,
        'FileNotOpen': 38,
        'FileStreamFailed': 39,
        'ConflictingUpdateOperators': 40,
        'FileAlreadyOpen': 41,
        'LogWriteFailed': 42,
        'CursorNotFound': 43,
        'UserDataInconsistent': 45,
        'LockBusy': 46,
        'NoMatchingDocument': 47,
        'NamespaceExists': 48,
        'InvalidRoleModification': 49,
        'MaxTimeMSExpired': 50,
        'ManualInterventionRequired': 51,
        'DollarPrefixedFieldName': 52,
        'InvalidIdField': 53,
        'NotSingleValueField': 54,
        'InvalidDBRef': 55,
        'EmptyFieldName': 56,
        'DottedFieldName': 57,
        'RoleModificationFailed': 58,
        'CommandNotFound': 59,
        'OBSOLETE_DatabaseNotFound': 60,
        'ShardKeyNotFound': 61,
        'OplogOperationUnsupported': 62,
        'StaleShardVersion': 63,
        'WriteConcernFailed': 64,
        'MultipleErrorsOccurred': 65,
        'ImmutableField': 66,
        'CannotCreateIndex': 67,
        'IndexAlreadyExists': 68,
        'AuthSchemaIncompatible': 69,
        'ShardNotFound': 70,
        'ReplicaSetNotFound': 71,
        'InvalidOptions': 72,
        'InvalidNamespace': 73,
        'NodeNotFound': 74,
        'WriteConcernLegacyOK': 75,
        'NoReplicationEnabled': 76,
        'OperationIncomplete': 77,
        'CommandResultSchemaViolation': 78,
        'UnknownReplWriteConcern': 79,
        'RoleDataInconsistent': 80,
        'NoMatchParseContext': 81,
        'NoProgressMade': 82,
        'RemoteResultsUnavailable': 83,
        'OBSOLETE_DuplicateKeyValue': 84,
        'IndexOptionsConflict': 85,
        'IndexKeySpecsConflict': 86,
        'CannotSplit': 87,
        'OBSOLETE_SplitFailed': 88,
        'NetworkTimeout': 89,
        'CallbackCanceled': 90,
        'ShutdownInProgress': 91,
        'SecondaryAheadOfPrimary': 92,
        'InvalidReplicaSetConfig': 93,
        'NotYetInitialized': 94,
        'NotSecondary': 95,
        'OperationFailed': 96,
        'NoProjectionFound': 97,
        'DBPathInUse': 98,
        'UnsatisfiableWriteConcern': 100,
        'OutdatedClient': 101,
        'IncompatibleAuditMetadata': 102,
        'NewReplicaSetConfigurationIncompatible': 103,
        'NodeNotElectable': 104,
        'IncompatibleShardingMetadata': 105,
        'DistributedClockSkewed': 106,
        'LockFailed': 107,
        'InconsistentReplicaSetNames': 108,
        'ConfigurationInProgress': 109,
        'CannotInitializeNodeWithData': 110,
        'NotExactValueField': 111,
        'WriteConflict': 112,
        'InitialSyncFailure': 113,
        'InitialSyncOplogSourceMissing': 114,
        'CommandNotSupported': 115,
        'DocTooLargeForCapped': 116,
        'ConflictingOperationInProgress': 117,
        'NamespaceNotSharded': 118,
        'InvalidSyncSource': 119,
        'OplogStartMissing': 120,
        'DocumentValidationFailure': 121,
        'OBSOLETE_ReadAfterOptimeTimeout': 122,
        'NotAReplicaSet': 123,
        'IncompatibleElectionProtocol': 124,
        'CommandFailed': 125,
        'RPCProtocolNegotiationFailed': 126,
        'UnrecoverableRollbackError': 127,
        'LockNotFound': 128,
        'LockStateChangeFailed': 129,
        'SymbolNotFound': 130,
        'OBSOLETE_ConfigServersInconsistent': 132,
        'FailedToSatisfyReadPreference': 133,
        'ReadConcernMajorityNotAvailableYet': 134,
        'StaleTerm': 135,
        'CappedPositionLost': 136,
        'IncompatibleShardingConfigVersion': 137,
        'RemoteOplogStale': 138,
        'JSInterpreterFailure': 139,
        'InvalidSSLConfiguration': 140,
        'SSLHandshakeFailed': 141,
        'JSUncatchableError': 142,
        'CursorInUse': 143,
        'IncompatibleCatalogManager': 144,
        'PooledConnectionsDropped': 145,
        'ExceededMemoryLimit': 146,
        'ZLibError': 147,
        'ReadConcernMajorityNotEnabled': 148,
        'NoConfigPrimary': 149,
        'StaleEpoch': 150,
        'OperationCannotBeBatched': 151,
        'OplogOutOfOrder': 152,
        'ChunkTooBig': 153,
        'InconsistentShardIdentity': 154,
        'CannotApplyOplogWhilePrimary': 155,
        'OBSOLETE_NeedsDocumentMove': 156,
        'CanRepairToDowngrade': 157,
        'MustUpgrade': 158,
        'DurationOverflow': 159,
        'MaxStalenessOutOfRange': 160,
        'IncompatibleCollationVersion': 161,
        'CollectionIsEmpty': 162,
        'ZoneStillInUse': 163,
        'InitialSyncActive': 164,
        'ViewDepthLimitExceeded': 165,
        'CommandNotSupportedOnView': 166,
        'OptionNotSupportedOnView': 167,
        'InvalidPipelineOperator': 168,
        'CommandOnShardedViewNotSupportedOnMongod': 169,
        'TooManyMatchingDocuments': 170,
        'CannotIndexParallelArrays': 171,
        'TransportSessionClosed': 172,
        'TransportSessionNotFound': 173,
        'TransportSessionUnknown': 174,
        'QueryPlanKilled': 175,
        'FileOpenFailed': 176,
        'ZoneNotFound': 177,
        'RangeOverlapConflict': 178,
        'WindowsPdhError': 179,
        'BadPerfCounterPath': 180,
        'AmbiguousIndexKeyPattern': 181,
        'InvalidViewDefinition': 182,
        'ClientMetadataMissingField': 183,
        'ClientMetadataAppNameTooLarge': 184,
        'ClientMetadataDocumentTooLarge': 185,
        'ClientMetadataCannotBeMutated': 186,
        'LinearizableReadConcernError': 187,
        'IncompatibleServerVersion': 188,
        'PrimarySteppedDown': 189,
        'MasterSlaveConnectionFailure': 190,
        'OBSOLETE_BalancerLostDistributedLock': 191,
        'FailPointEnabled': 192,
        'NoShardingEnabled': 193,
        'BalancerInterrupted': 194,
        'ViewPipelineMaxSizeExceeded': 195,
        'InvalidIndexSpecificationOption': 197,
        'OBSOLETE_ReceivedOpReplyMessage': 198,
        'ReplicaSetMonitorRemoved': 199,
        'ChunkRangeCleanupPending': 200,
        'CannotBuildIndexKeys': 201,
        'NetworkInterfaceExceededTimeLimit': 202,
        'ShardingStateNotInitialized': 203,
        'TimeProofMismatch': 204,
        'ClusterTimeFailsRateLimiter': 205,
        'NoSuchSession': 206,
        'InvalidUUID': 207,
        'TooManyLocks': 208,
        'StaleClusterTime': 209,
        'CannotVerifyAndSignLogicalTime': 210,
        'KeyNotFound': 211,
        'IncompatibleRollbackAlgorithm': 212,
        'DuplicateSession': 213,
        'AuthenticationRestrictionUnmet': 214,
        'DatabaseDropPending': 215,
        'ElectionInProgress': 216,
        'IncompleteTransactionHistory': 217,
        'UpdateOperationFailed': 218,
        'FTDCPathNotSet': 219,
        'FTDCPathAlreadySet': 220,
        'IndexModified': 221,
        'CloseChangeStream': 222,
        'IllegalOpMsgFlag': 223,
        'QueryFeatureNotAllowed': 224,
        'TransactionTooOld': 225,
        'AtomicityFailure': 226,
        'CannotImplicitlyCreateCollection': 227,
        'SessionTransferIncomplete': 228,
        'MustDowngrade': 229,
        'DNSHostNotFound': 230,
        'DNSProtocolError': 231,
        'MaxSubPipelineDepthExceeded': 232,
        'TooManyDocumentSequences': 233,
        'RetryChangeStream': 234,
        'InternalErrorNotSupported': 235,
        'ForTestingErrorExtraInfo': 236,
        'CursorKilled': 237,
        'NotImplemented': 238,
        'SnapshotTooOld': 239,
        'DNSRecordTypeMismatch': 240,
        'ConversionFailure': 241,
        'CannotCreateCollection': 242,
        'IncompatibleWithUpgradedServer': 243,
        'NOT_YET_AVAILABLE_TransactionAborted': 244,
        'BrokenPromise': 245,
        'SnapshotUnavailable': 246,
        'ProducerConsumerQueueBatchTooLarge': 247,
        'ProducerConsumerQueueEndClosed': 248,
        'StaleDbVersion': 249,
        'StaleChunkHistory': 250,
        'NoSuchTransaction': 251,
        'ReentrancyNotAllowed': 252,
        'FreeMonHttpInFlight': 253,
        'FreeMonHttpTemporaryFailure': 254,
        'FreeMonHttpPermanentFailure': 255,
        'TransactionCommitted': 256,
        'TransactionTooLarge': 257,
        'UnknownFeatureCompatibilityVersion': 258,
        'KeyedExecutorRetry': 259,
        'InvalidResumeToken': 260,
        'TooManyLogicalSessions': 261,
        'ExceededTimeLimit': 262,
        'OperationNotSupportedInTransaction': 263,
        'TooManyFilesOpen': 264,
        'OrphanedRangeCleanUpFailed': 265,
        'FailPointSetFailed': 266,
        'PreparedTransactionInProgress': 267,
        'CannotBackup': 268,
        'DataModifiedByRepair': 269,
        'RepairedReplicaSetNode': 270,
        'JSInterpreterFailureWithStack': 271,
        'MigrationConflict': 272,
        'ProducerConsumerQueueProducerQueueDepthExceeded': 273,
        'ProducerConsumerQueueConsumed': 274,
        'ExchangePassthrough': 275,
        'IndexBuildAborted': 276,
        'AlarmAlreadyFulfilled': 277,
        'UnsatisfiableCommitQuorum': 278,
        'ClientDisconnect': 279,
        'ChangeStreamFatalError': 280,
        'TransactionCoordinatorSteppingDown': 281,
        'TransactionCoordinatorReachedAbortDecision': 282,
        'WouldChangeOwningShard': 283,
        'ForTestingErrorExtraInfoWithExtraInfoInNamespace': 284,
        'IndexBuildAlreadyInProgress': 285,
        'ChangeStreamHistoryLost': 286,
        'TransactionCoordinatorDeadlineTaskCanceled': 287,
        'ChecksumMismatch': 288,
        'WaitForMajorityServiceEarlierOpTimeAvailable': 289,
        'TransactionExceededLifetimeLimitSeconds': 290,
        'NoQueryExecutionPlans': 291,
        'QueryExceededMemoryLimitNoDiskUseAllowed': 292,
        'InvalidSeedList': 293,
        'InvalidTopologyType': 294,
        'InvalidHeartBeatFrequency': 295,
        'TopologySetNameRequired': 296,
        'HierarchicalAcquisitionLevelViolation': 297,
        'InvalidServerType': 298,
        'OCSPCertificateStatusRevoked': 299,
        'RangeDeletionAbandonedBecauseCollectionWithUUIDDoesNotExist': 300,
        'DataCorruptionDetected': 301,
        'OCSPCertificateStatusUnknown': 302,
        'SplitHorizonChange': 303,
        'ShardInvalidatedForTargeting': 304,
        'ReadThroughCacheLookupCanceled': 306,
        'RangeDeletionAbandonedBecauseTaskDocumentDoesNotExist': 307,
        'CurrentConfigNotCommittedYet': 308,
        'ExhaustCommandFinished': 309,
        'PeriodicJobIsStopped': 310,
        'TransactionCoordinatorCanceled': 311,
        'OperationIsKilledAndDelisted': 312,
        'ResumableRangeDeleterDisabled': 313,
        'ObjectIsBusy': 314,
        'TooStaleToSyncFromSource': 315,
        'QueryTrialRunCompleted': 316,
        'ConnectionPoolExpired': 317,
        'ForTestingOptionalErrorExtraInfo': 318,
        'MovePrimaryInProgress': 319,
        'TenantMigrationConflict': 320,
        'TenantMigrationCommitted': 321,
        'APIVersionError': 322,
        'APIStrictError': 323,
        'APIDeprecationError': 324,
        'TenantMigrationAborted': 325,
        'OplogQueryMinTsMissing': 326,
        'NoSuchTenantMigration': 327,
        'TenantMigrationAccessBlockerShuttingDown': 328,
        'TenantMigrationInProgress': 329,
        'SkipCommandExecution': 330,
        'FailedToRunWithReplyBuilder': 331,
        'CannotDowngrade': 332,
        'ServiceExecutorInShutdown': 333,
        'MechanismUnavailable': 334,
        'TenantMigrationForgotten': 335,
        'TimeseriesBucketCleared': 336,
        'AuthenticationAbandoned': 337,
        'ReshardCollectionInProgress': 338,
        'NoSuchReshardCollection': 339,
        'ReshardCollectionCommitted': 340,
        'ReshardCollectionAborted': 341,
        'ReshardingCriticalSectionTimeout': 342,
        'ShardCannotRefreshDueToLocksHeld': 343,
        'AuditingNotEnabled': 344,
        'RuntimeAuditConfigurationNotEnabled': 345,
        'ChangeStreamInvalidated': 346,
        'APIMismatchError': 347,
        'KeyPatternShorterThanBound': 349,
        'ReshardCollectionTruncatedError': 350,
        'NonRetryableTenantMigrationConflict': 353,
        'LoadBalancerSupportMismatch': 354,
        'InvalidBSONType': 357,
        'SocketException': 9001,
        'OBSOLETE_RecvStaleConfig': 9996,
        'CannotGrowDocumentInCappedNamespace': 10003,
        'LegacyNotPrimary': 10058,
        'NotWritablePrimary': 10107,
        'BSONObjectTooLarge': 10334,
        'DuplicateKey': 11000,
        'InterruptedAtShutdown': 11600,
        'Interrupted': 11601,
        'InterruptedDueToReplStateChange': 11602,
        'BackgroundOperationInProgressForDatabase': 12586,
        'BackgroundOperationInProgressForNamespace': 12587,
        'OBSOLETE_PrepareConfigsFailed': 13104,
        'MergeStageNoMatchingDocument': 13113,
        'DatabaseDifferCase': 13297,
        'StaleConfig': 13388,
        'NotPrimaryNoSecondaryOk': 13435,
        'NotPrimaryOrSecondary': 13436,
        'OutOfDiskSpace': 14031,
        'OBSOLETE_KeyTooLong': 17280,
        'ClientMarkedKilled': 46841,
        'NotARetryableWriteCommand': 50768,
        'ConfigServerUnreachable': 56846,
    };

    const ErrorCodeStringsObject = {
        0: 'OK',
        1: 'InternalError',
        2: 'BadValue',
        3: 'OBSOLETE_DuplicateKey',
        4: 'NoSuchKey',
        5: 'GraphContainsCycle',
        6: 'HostUnreachable',
        7: 'HostNotFound',
        8: 'UnknownError',
        9: 'FailedToParse',
        10: 'CannotMutateObject',
        11: 'UserNotFound',
        12: 'UnsupportedFormat',
        13: 'Unauthorized',
        14: 'TypeMismatch',
        15: 'Overflow',
        16: 'InvalidLength',
        17: 'ProtocolError',
        18: 'AuthenticationFailed',
        19: 'CannotReuseObject',
        20: 'IllegalOperation',
        21: 'EmptyArrayOperation',
        22: 'InvalidBSON',
        23: 'AlreadyInitialized',
        24: 'LockTimeout',
        25: 'RemoteValidationError',
        26: 'NamespaceNotFound',
        27: 'IndexNotFound',
        28: 'PathNotViable',
        29: 'NonExistentPath',
        30: 'InvalidPath',
        31: 'RoleNotFound',
        32: 'RolesNotRelated',
        33: 'PrivilegeNotFound',
        34: 'CannotBackfillArray',
        35: 'UserModificationFailed',
        36: 'RemoteChangeDetected',
        37: 'FileRenameFailed',
        38: 'FileNotOpen',
        39: 'FileStreamFailed',
        40: 'ConflictingUpdateOperators',
        41: 'FileAlreadyOpen',
        42: 'LogWriteFailed',
        43: 'CursorNotFound',
        45: 'UserDataInconsistent',
        46: 'LockBusy',
        47: 'NoMatchingDocument',
        48: 'NamespaceExists',
        49: 'InvalidRoleModification',
        50: 'MaxTimeMSExpired',
        51: 'ManualInterventionRequired',
        52: 'DollarPrefixedFieldName',
        53: 'InvalidIdField',
        54: 'NotSingleValueField',
        55: 'InvalidDBRef',
        56: 'EmptyFieldName',
        57: 'DottedFieldName',
        58: 'RoleModificationFailed',
        59: 'CommandNotFound',
        60: 'OBSOLETE_DatabaseNotFound',
        61: 'ShardKeyNotFound',
        62: 'OplogOperationUnsupported',
        63: 'StaleShardVersion',
        64: 'WriteConcernFailed',
        65: 'MultipleErrorsOccurred',
        66: 'ImmutableField',
        67: 'CannotCreateIndex',
        68: 'IndexAlreadyExists',
        69: 'AuthSchemaIncompatible',
        70: 'ShardNotFound',
        71: 'ReplicaSetNotFound',
        72: 'InvalidOptions',
        73: 'InvalidNamespace',
        74: 'NodeNotFound',
        75: 'WriteConcernLegacyOK',
        76: 'NoReplicationEnabled',
        77: 'OperationIncomplete',
        78: 'CommandResultSchemaViolation',
        79: 'UnknownReplWriteConcern',
        80: 'RoleDataInconsistent',
        81: 'NoMatchParseContext',
        82: 'NoProgressMade',
        83: 'RemoteResultsUnavailable',
        84: 'OBSOLETE_DuplicateKeyValue',
        85: 'IndexOptionsConflict',
        86: 'IndexKeySpecsConflict',
        87: 'CannotSplit',
        88: 'OBSOLETE_SplitFailed',
        89: 'NetworkTimeout',
        90: 'CallbackCanceled',
        91: 'ShutdownInProgress',
        92: 'SecondaryAheadOfPrimary',
        93: 'InvalidReplicaSetConfig',
        94: 'NotYetInitialized',
        95: 'NotSecondary',
        96: 'OperationFailed',
        97: 'NoProjectionFound',
        98: 'DBPathInUse',
        100: 'UnsatisfiableWriteConcern',
        101: 'OutdatedClient',
        102: 'IncompatibleAuditMetadata',
        103: 'NewReplicaSetConfigurationIncompatible',
        104: 'NodeNotElectable',
        105: 'IncompatibleShardingMetadata',
        106: 'DistributedClockSkewed',
        107: 'LockFailed',
        108: 'InconsistentReplicaSetNames',
        109: 'ConfigurationInProgress',
        110: 'CannotInitializeNodeWithData',
        111: 'NotExactValueField',
        112: 'WriteConflict',
        113: 'InitialSyncFailure',
        114: 'InitialSyncOplogSourceMissing',
        115: 'CommandNotSupported',
        116: 'DocTooLargeForCapped',
        117: 'ConflictingOperationInProgress',
        118: 'NamespaceNotSharded',
        119: 'InvalidSyncSource',
        120: 'OplogStartMissing',
        121: 'DocumentValidationFailure',
        122: 'OBSOLETE_ReadAfterOptimeTimeout',
        123: 'NotAReplicaSet',
        124: 'IncompatibleElectionProtocol',
        125: 'CommandFailed',
        126: 'RPCProtocolNegotiationFailed',
        127: 'UnrecoverableRollbackError',
        128: 'LockNotFound',
        129: 'LockStateChangeFailed',
        130: 'SymbolNotFound',
        132: 'OBSOLETE_ConfigServersInconsistent',
        133: 'FailedToSatisfyReadPreference',
        134: 'ReadConcernMajorityNotAvailableYet',
        135: 'StaleTerm',
        136: 'CappedPositionLost',
        137: 'IncompatibleShardingConfigVersion',
        138: 'RemoteOplogStale',
        139: 'JSInterpreterFailure',
        140: 'InvalidSSLConfiguration',
        141: 'SSLHandshakeFailed',
        142: 'JSUncatchableError',
        143: 'CursorInUse',
        144: 'IncompatibleCatalogManager',
        145: 'PooledConnectionsDropped',
        146: 'ExceededMemoryLimit',
        147: 'ZLibError',
        148: 'ReadConcernMajorityNotEnabled',
        149: 'NoConfigPrimary',
        150: 'StaleEpoch',
        151: 'OperationCannotBeBatched',
        152: 'OplogOutOfOrder',
        153: 'ChunkTooBig',
        154: 'InconsistentShardIdentity',
        155: 'CannotApplyOplogWhilePrimary',
        156: 'OBSOLETE_NeedsDocumentMove',
        157: 'CanRepairToDowngrade',
        158: 'MustUpgrade',
        159: 'DurationOverflow',
        160: 'MaxStalenessOutOfRange',
        161: 'IncompatibleCollationVersion',
        162: 'CollectionIsEmpty',
        163: 'ZoneStillInUse',
        164: 'InitialSyncActive',
        165: 'ViewDepthLimitExceeded',
        166: 'CommandNotSupportedOnView',
        167: 'OptionNotSupportedOnView',
        168: 'InvalidPipelineOperator',
        169: 'CommandOnShardedViewNotSupportedOnMongod',
        170: 'TooManyMatchingDocuments',
        171: 'CannotIndexParallelArrays',
        172: 'TransportSessionClosed',
        173: 'TransportSessionNotFound',
        174: 'TransportSessionUnknown',
        175: 'QueryPlanKilled',
        176: 'FileOpenFailed',
        177: 'ZoneNotFound',
        178: 'RangeOverlapConflict',
        179: 'WindowsPdhError',
        180: 'BadPerfCounterPath',
        181: 'AmbiguousIndexKeyPattern',
        182: 'InvalidViewDefinition',
        183: 'ClientMetadataMissingField',
        184: 'ClientMetadataAppNameTooLarge',
        185: 'ClientMetadataDocumentTooLarge',
        186: 'ClientMetadataCannotBeMutated',
        187: 'LinearizableReadConcernError',
        188: 'IncompatibleServerVersion',
        189: 'PrimarySteppedDown',
        190: 'MasterSlaveConnectionFailure',
        191: 'OBSOLETE_BalancerLostDistributedLock',
        192: 'FailPointEnabled',
        193: 'NoShardingEnabled',
        194: 'BalancerInterrupted',
        195: 'ViewPipelineMaxSizeExceeded',
        197: 'InvalidIndexSpecificationOption',
        198: 'OBSOLETE_ReceivedOpReplyMessage',
        199: 'ReplicaSetMonitorRemoved',
        200: 'ChunkRangeCleanupPending',
        201: 'CannotBuildIndexKeys',
        202: 'NetworkInterfaceExceededTimeLimit',
        203: 'ShardingStateNotInitialized',
        204: 'TimeProofMismatch',
        205: 'ClusterTimeFailsRateLimiter',
        206: 'NoSuchSession',
        207: 'InvalidUUID',
        208: 'TooManyLocks',
        209: 'StaleClusterTime',
        210: 'CannotVerifyAndSignLogicalTime',
        211: 'KeyNotFound',
        212: 'IncompatibleRollbackAlgorithm',
        213: 'DuplicateSession',
        214: 'AuthenticationRestrictionUnmet',
        215: 'DatabaseDropPending',
        216: 'ElectionInProgress',
        217: 'IncompleteTransactionHistory',
        218: 'UpdateOperationFailed',
        219: 'FTDCPathNotSet',
        220: 'FTDCPathAlreadySet',
        221: 'IndexModified',
        222: 'CloseChangeStream',
        223: 'IllegalOpMsgFlag',
        224: 'QueryFeatureNotAllowed',
        225: 'TransactionTooOld',
        226: 'AtomicityFailure',
        227: 'CannotImplicitlyCreateCollection',
        228: 'SessionTransferIncomplete',
        229: 'MustDowngrade',
        230: 'DNSHostNotFound',
        231: 'DNSProtocolError',
        232: 'MaxSubPipelineDepthExceeded',
        233: 'TooManyDocumentSequences',
        234: 'RetryChangeStream',
        235: 'InternalErrorNotSupported',
        236: 'ForTestingErrorExtraInfo',
        237: 'CursorKilled',
        238: 'NotImplemented',
        239: 'SnapshotTooOld',
        240: 'DNSRecordTypeMismatch',
        241: 'ConversionFailure',
        242: 'CannotCreateCollection',
        243: 'IncompatibleWithUpgradedServer',
        244: 'NOT_YET_AVAILABLE_TransactionAborted',
        245: 'BrokenPromise',
        246: 'SnapshotUnavailable',
        247: 'ProducerConsumerQueueBatchTooLarge',
        248: 'ProducerConsumerQueueEndClosed',
        249: 'StaleDbVersion',
        250: 'StaleChunkHistory',
        251: 'NoSuchTransaction',
        252: 'ReentrancyNotAllowed',
        253: 'FreeMonHttpInFlight',
        254: 'FreeMonHttpTemporaryFailure',
        255: 'FreeMonHttpPermanentFailure',
        256: 'TransactionCommitted',
        257: 'TransactionTooLarge',
        258: 'UnknownFeatureCompatibilityVersion',
        259: 'KeyedExecutorRetry',
        260: 'InvalidResumeToken',
        261: 'TooManyLogicalSessions',
        262: 'ExceededTimeLimit',
        263: 'OperationNotSupportedInTransaction',
        264: 'TooManyFilesOpen',
        265: 'OrphanedRangeCleanUpFailed',
        266: 'FailPointSetFailed',
        267: 'PreparedTransactionInProgress',
        268: 'CannotBackup',
        269: 'DataModifiedByRepair',
        270: 'RepairedReplicaSetNode',
        271: 'JSInterpreterFailureWithStack',
        272: 'MigrationConflict',
        273: 'ProducerConsumerQueueProducerQueueDepthExceeded',
        274: 'ProducerConsumerQueueConsumed',
        275: 'ExchangePassthrough',
        276: 'IndexBuildAborted',
        277: 'AlarmAlreadyFulfilled',
        278: 'UnsatisfiableCommitQuorum',
        279: 'ClientDisconnect',
        280: 'ChangeStreamFatalError',
        281: 'TransactionCoordinatorSteppingDown',
        282: 'TransactionCoordinatorReachedAbortDecision',
        283: 'WouldChangeOwningShard',
        284: 'ForTestingErrorExtraInfoWithExtraInfoInNamespace',
        285: 'IndexBuildAlreadyInProgress',
        286: 'ChangeStreamHistoryLost',
        287: 'TransactionCoordinatorDeadlineTaskCanceled',
        288: 'ChecksumMismatch',
        289: 'WaitForMajorityServiceEarlierOpTimeAvailable',
        290: 'TransactionExceededLifetimeLimitSeconds',
        291: 'NoQueryExecutionPlans',
        292: 'QueryExceededMemoryLimitNoDiskUseAllowed',
        293: 'InvalidSeedList',
        294: 'InvalidTopologyType',
        295: 'InvalidHeartBeatFrequency',
        296: 'TopologySetNameRequired',
        297: 'HierarchicalAcquisitionLevelViolation',
        298: 'InvalidServerType',
        299: 'OCSPCertificateStatusRevoked',
        300: 'RangeDeletionAbandonedBecauseCollectionWithUUIDDoesNotExist',
        301: 'DataCorruptionDetected',
        302: 'OCSPCertificateStatusUnknown',
        303: 'SplitHorizonChange',
        304: 'ShardInvalidatedForTargeting',
        306: 'ReadThroughCacheLookupCanceled',
        307: 'RangeDeletionAbandonedBecauseTaskDocumentDoesNotExist',
        308: 'CurrentConfigNotCommittedYet',
        309: 'ExhaustCommandFinished',
        310: 'PeriodicJobIsStopped',
        311: 'TransactionCoordinatorCanceled',
        312: 'OperationIsKilledAndDelisted',
        313: 'ResumableRangeDeleterDisabled',
        314: 'ObjectIsBusy',
        315: 'TooStaleToSyncFromSource',
        316: 'QueryTrialRunCompleted',
        317: 'ConnectionPoolExpired',
        318: 'ForTestingOptionalErrorExtraInfo',
        319: 'MovePrimaryInProgress',
        320: 'TenantMigrationConflict',
        321: 'TenantMigrationCommitted',
        322: 'APIVersionError',
        323: 'APIStrictError',
        324: 'APIDeprecationError',
        325: 'TenantMigrationAborted',
        326: 'OplogQueryMinTsMissing',
        327: 'NoSuchTenantMigration',
        328: 'TenantMigrationAccessBlockerShuttingDown',
        329: 'TenantMigrationInProgress',
        330: 'SkipCommandExecution',
        331: 'FailedToRunWithReplyBuilder',
        332: 'CannotDowngrade',
        333: 'ServiceExecutorInShutdown',
        334: 'MechanismUnavailable',
        335: 'TenantMigrationForgotten',
        336: 'TimeseriesBucketCleared',
        337: 'AuthenticationAbandoned',
        338: 'ReshardCollectionInProgress',
        339: 'NoSuchReshardCollection',
        340: 'ReshardCollectionCommitted',
        341: 'ReshardCollectionAborted',
        342: 'ReshardingCriticalSectionTimeout',
        343: 'ShardCannotRefreshDueToLocksHeld',
        344: 'AuditingNotEnabled',
        345: 'RuntimeAuditConfigurationNotEnabled',
        346: 'ChangeStreamInvalidated',
        347: 'APIMismatchError',
        349: 'KeyPatternShorterThanBound',
        350: 'ReshardCollectionTruncatedError',
        353: 'NonRetryableTenantMigrationConflict',
        354: 'LoadBalancerSupportMismatch',
        357: 'InvalidBSONType',
        9001: 'SocketException',
        9996: 'OBSOLETE_RecvStaleConfig',
        10003: 'CannotGrowDocumentInCappedNamespace',
        10058: 'LegacyNotPrimary',
        10107: 'NotWritablePrimary',
        10334: 'BSONObjectTooLarge',
        11000: 'DuplicateKey',
        11600: 'InterruptedAtShutdown',
        11601: 'Interrupted',
        11602: 'InterruptedDueToReplStateChange',
        12586: 'BackgroundOperationInProgressForDatabase',
        12587: 'BackgroundOperationInProgressForNamespace',
        13104: 'OBSOLETE_PrepareConfigsFailed',
        13113: 'MergeStageNoMatchingDocument',
        13297: 'DatabaseDifferCase',
        13388: 'StaleConfig',
        13435: 'NotPrimaryNoSecondaryOk',
        13436: 'NotPrimaryOrSecondary',
        14031: 'OutOfDiskSpace',
        17280: 'OBSOLETE_KeyTooLong',
        46841: 'ClientMarkedKilled',
        50768: 'NotARetryableWriteCommand',
        56846: 'ConfigServerUnreachable',
    };

    return {
        ErrorCodes: new Proxy(ErrorCodesObject, handler),
        ErrorCodeStrings: new Proxy(ErrorCodeStringsObject, handler),
    };
})();

ErrorCodes.isNetworkError = function(err) {
    'use strict';

    var error;
    if (typeof err === 'string') {
        error = err;
    } else if (typeof err === 'number') {
        if (Object.prototype.hasOwnProperty.call(ErrorCodeStrings, err)) {
            error = ErrorCodeStrings[err];
        } else {
            return false;
        }
    }
    switch (error) {
        case 'HostUnreachable':
            return true;
        case 'HostNotFound':
            return true;
        case 'NetworkTimeout':
            return true;
        case 'ConnectionPoolExpired':
            return true;
        case 'SocketException':
            return true;
        default:
            return false;
    }
};
ErrorCodes.isNetworkTimeoutError = function(err) {
    'use strict';

    var error;
    if (typeof err === 'string') {
        error = err;
    } else if (typeof err === 'number') {
        if (Object.prototype.hasOwnProperty.call(ErrorCodeStrings, err)) {
            error = ErrorCodeStrings[err];
        } else {
            return false;
        }
    }
    switch (error) {
        case 'NetworkTimeout':
            return true;
        case 'NetworkInterfaceExceededTimeLimit':
            return true;
        default:
            return false;
    }
};
ErrorCodes.isInterruption = function(err) {
    'use strict';

    var error;
    if (typeof err === 'string') {
        error = err;
    } else if (typeof err === 'number') {
        if (Object.prototype.hasOwnProperty.call(ErrorCodeStrings, err)) {
            error = ErrorCodeStrings[err];
        } else {
            return false;
        }
    }
    switch (error) {
        case 'LockTimeout':
            return true;
        case 'MaxTimeMSExpired':
            return true;
        case 'CursorKilled':
            return true;
        case 'ExceededTimeLimit':
            return true;
        case 'ClientDisconnect':
            return true;
        case 'TransactionCoordinatorSteppingDown':
            return true;
        case 'TransactionCoordinatorReachedAbortDecision':
            return true;
        case 'TransactionExceededLifetimeLimitSeconds':
            return true;
        case 'InterruptedAtShutdown':
            return true;
        case 'Interrupted':
            return true;
        case 'InterruptedDueToReplStateChange':
            return true;
        case 'ClientMarkedKilled':
            return true;
        default:
            return false;
    }
};
ErrorCodes.isNotPrimaryError = function(err) {
    'use strict';

    var error;
    if (typeof err === 'string') {
        error = err;
    } else if (typeof err === 'number') {
        if (Object.prototype.hasOwnProperty.call(ErrorCodeStrings, err)) {
            error = ErrorCodeStrings[err];
        } else {
            return false;
        }
    }
    switch (error) {
        case 'PrimarySteppedDown':
            return true;
        case 'NotWritablePrimary':
            return true;
        case 'InterruptedDueToReplStateChange':
            return true;
        case 'NotPrimaryNoSecondaryOk':
            return true;
        case 'NotPrimaryOrSecondary':
            return true;
        default:
            return false;
    }
};
ErrorCodes.isStaleShardVersionError = function(err) {
    'use strict';

    var error;
    if (typeof err === 'string') {
        error = err;
    } else if (typeof err === 'number') {
        if (Object.prototype.hasOwnProperty.call(ErrorCodeStrings, err)) {
            error = ErrorCodeStrings[err];
        } else {
            return false;
        }
    }
    switch (error) {
        case 'StaleShardVersion':
            return true;
        case 'StaleEpoch':
            return true;
        case 'StaleConfig':
            return true;
        default:
            return false;
    }
};
ErrorCodes.isNeedRetargettingError = function(err) {
    'use strict';

    var error;
    if (typeof err === 'string') {
        error = err;
    } else if (typeof err === 'number') {
        if (Object.prototype.hasOwnProperty.call(ErrorCodeStrings, err)) {
            error = ErrorCodeStrings[err];
        } else {
            return false;
        }
    }
    switch (error) {
        case 'StaleShardVersion':
            return true;
        case 'StaleEpoch':
            return true;
        case 'StaleConfig':
            return true;
        default:
            return false;
    }
};
ErrorCodes.isWriteConcernError = function(err) {
    'use strict';

    var error;
    if (typeof err === 'string') {
        error = err;
    } else if (typeof err === 'number') {
        if (Object.prototype.hasOwnProperty.call(ErrorCodeStrings, err)) {
            error = ErrorCodeStrings[err];
        } else {
            return false;
        }
    }
    switch (error) {
        case 'WriteConcernFailed':
            return true;
        case 'WriteConcernLegacyOK':
            return true;
        case 'UnknownReplWriteConcern':
            return true;
        case 'UnsatisfiableWriteConcern':
            return true;
        default:
            return false;
    }
};
ErrorCodes.isShutdownError = function(err) {
    'use strict';

    var error;
    if (typeof err === 'string') {
        error = err;
    } else if (typeof err === 'number') {
        if (Object.prototype.hasOwnProperty.call(ErrorCodeStrings, err)) {
            error = ErrorCodeStrings[err];
        } else {
            return false;
        }
    }
    switch (error) {
        case 'ShutdownInProgress':
            return true;
        case 'ServiceExecutorInShutdown':
            return true;
        case 'InterruptedAtShutdown':
            return true;
        default:
            return false;
    }
};
ErrorCodes.isCancellationError = function(err) {
    'use strict';

    var error;
    if (typeof err === 'string') {
        error = err;
    } else if (typeof err === 'number') {
        if (Object.prototype.hasOwnProperty.call(ErrorCodeStrings, err)) {
            error = ErrorCodeStrings[err];
        } else {
            return false;
        }
    }
    switch (error) {
        case 'CallbackCanceled':
            return true;
        case 'ShutdownInProgress':
            return true;
        case 'PeriodicJobIsStopped':
            return true;
        case 'OperationIsKilledAndDelisted':
            return true;
        case 'ServiceExecutorInShutdown':
            return true;
        case 'InterruptedAtShutdown':
            return true;
        case 'ClientMarkedKilled':
            return true;
        default:
            return false;
    }
};
ErrorCodes.isConnectionFatalMessageParseError = function(err) {
    'use strict';

    var error;
    if (typeof err === 'string') {
        error = err;
    } else if (typeof err === 'number') {
        if (Object.prototype.hasOwnProperty.call(ErrorCodeStrings, err)) {
            error = ErrorCodeStrings[err];
        } else {
            return false;
        }
    }
    switch (error) {
        case 'IllegalOpMsgFlag':
            return true;
        case 'TooManyDocumentSequences':
            return true;
        case 'ChecksumMismatch':
            return true;
        default:
            return false;
    }
};
ErrorCodes.isExceededTimeLimitError = function(err) {
    'use strict';

    var error;
    if (typeof err === 'string') {
        error = err;
    } else if (typeof err === 'number') {
        if (Object.prototype.hasOwnProperty.call(ErrorCodeStrings, err)) {
            error = ErrorCodeStrings[err];
        } else {
            return false;
        }
    }
    switch (error) {
        case 'MaxTimeMSExpired':
            return true;
        case 'NetworkInterfaceExceededTimeLimit':
            return true;
        case 'ExceededTimeLimit':
            return true;
        case 'TransactionExceededLifetimeLimitSeconds':
            return true;
        default:
            return false;
    }
};
ErrorCodes.isSnapshotError = function(err) {
    'use strict';

    var error;
    if (typeof err === 'string') {
        error = err;
    } else if (typeof err === 'number') {
        if (Object.prototype.hasOwnProperty.call(ErrorCodeStrings, err)) {
            error = ErrorCodeStrings[err];
        } else {
            return false;
        }
    }
    switch (error) {
        case 'SnapshotTooOld':
            return true;
        case 'SnapshotUnavailable':
            return true;
        case 'StaleChunkHistory':
            return true;
        case 'MigrationConflict':
            return true;
        default:
            return false;
    }
};
ErrorCodes.isVoteAbortError = function(err) {
    'use strict';

    var error;
    if (typeof err === 'string') {
        error = err;
    } else if (typeof err === 'number') {
        if (Object.prototype.hasOwnProperty.call(ErrorCodeStrings, err)) {
            error = ErrorCodeStrings[err];
        } else {
            return false;
        }
    }
    switch (error) {
        case 'ReadConcernMajorityNotEnabled':
            return true;
        case 'TransactionTooOld':
            return true;
        case 'NoSuchTransaction':
            return true;
        case 'OperationNotSupportedInTransaction':
            return true;
        case 'APIMismatchError':
            return true;
        default:
            return false;
    }
};
ErrorCodes.isNonResumableChangeStreamError = function(err) {
    'use strict';

    var error;
    if (typeof err === 'string') {
        error = err;
    } else if (typeof err === 'number') {
        if (Object.prototype.hasOwnProperty.call(ErrorCodeStrings, err)) {
            error = ErrorCodeStrings[err];
        } else {
            return false;
        }
    }
    switch (error) {
        case 'ChangeStreamFatalError':
            return true;
        case 'ChangeStreamHistoryLost':
            return true;
        default:
            return false;
    }
};
ErrorCodes.isRetriableError = function(err) {
    'use strict';

    var error;
    if (typeof err === 'string') {
        error = err;
    } else if (typeof err === 'number') {
        if (Object.prototype.hasOwnProperty.call(ErrorCodeStrings, err)) {
            error = ErrorCodeStrings[err];
        } else {
            return false;
        }
    }
    switch (error) {
        case 'HostUnreachable':
            return true;
        case 'HostNotFound':
            return true;
        case 'NetworkTimeout':
            return true;
        case 'ShutdownInProgress':
            return true;
        case 'PrimarySteppedDown':
            return true;
        case 'ExceededTimeLimit':
            return true;
        case 'ConnectionPoolExpired':
            return true;
        case 'SocketException':
            return true;
        case 'NotWritablePrimary':
            return true;
        case 'InterruptedAtShutdown':
            return true;
        case 'InterruptedDueToReplStateChange':
            return true;
        case 'NotPrimaryNoSecondaryOk':
            return true;
        case 'NotPrimaryOrSecondary':
            return true;
        default:
            return false;
    }
};
ErrorCodes.isCloseConnectionError = function(err) {
    'use strict';

    var error;
    if (typeof err === 'string') {
        error = err;
    } else if (typeof err === 'number') {
        if (Object.prototype.hasOwnProperty.call(ErrorCodeStrings, err)) {
            error = ErrorCodeStrings[err];
        } else {
            return false;
        }
    }
    switch (error) {
        case 'SplitHorizonChange':
            return true;
        case 'LoadBalancerSupportMismatch':
            return true;
        default:
            return false;
    }
};
ErrorCodes.isVersionedAPIError = function(err) {
    'use strict';

    var error;
    if (typeof err === 'string') {
        error = err;
    } else if (typeof err === 'number') {
        if (Object.prototype.hasOwnProperty.call(ErrorCodeStrings, err)) {
            error = ErrorCodeStrings[err];
        } else {
            return false;
        }
    }
    switch (error) {
        case 'APIVersionError':
            return true;
        case 'APIStrictError':
            return true;
        case 'APIDeprecationError':
            return true;
        case 'APIMismatchError':
            return true;
        default:
            return false;
    }
};
ErrorCodes.isValidationError = function(err) {
    'use strict';

    var error;
    if (typeof err === 'string') {
        error = err;
    } else if (typeof err === 'number') {
        if (Object.prototype.hasOwnProperty.call(ErrorCodeStrings, err)) {
            error = ErrorCodeStrings[err];
        } else {
            return false;
        }
    }
    switch (error) {
        case 'Overflow':
            return true;
        case 'InvalidBSON':
            return true;
        default:
            return false;
    }
};
ErrorCodes.isInternalOnly = function(err) {
    'use strict';

    var error;
    if (typeof err === 'string') {
        error = err;
    } else if (typeof err === 'number') {
        if (Object.prototype.hasOwnProperty.call(ErrorCodeStrings, err)) {
            error = ErrorCodeStrings[err];
        } else {
            return false;
        }
    }
    switch (error) {
        case 'TransactionCoordinatorSteppingDown':
            return true;
        case 'TransactionCoordinatorReachedAbortDecision':
            return true;
        case 'TransactionCoordinatorDeadlineTaskCanceled':
            return true;
        case 'WaitForMajorityServiceEarlierOpTimeAvailable':
            return true;
        case 'ReadThroughCacheLookupCanceled':
            return true;
        case 'TransactionCoordinatorCanceled':
            return true;
        case 'OperationIsKilledAndDelisted':
            return true;
        case 'TooStaleToSyncFromSource':
            return true;
        case 'QueryTrialRunCompleted':
            return true;
        case 'ConnectionPoolExpired':
            return true;
        case 'TenantMigrationAccessBlockerShuttingDown':
            return true;
        case 'ServiceExecutorInShutdown':
            return true;
        case 'TimeseriesBucketCleared':
            return true;
        case 'AuthenticationAbandoned':
            return true;
        default:
            return false;
    }
};
ErrorCodes.isTenantMigrationError = function(err) {
    'use strict';

    var error;
    if (typeof err === 'string') {
        error = err;
    } else if (typeof err === 'number') {
        if (Object.prototype.hasOwnProperty.call(ErrorCodeStrings, err)) {
            error = ErrorCodeStrings[err];
        } else {
            return false;
        }
    }
    switch (error) {
        case 'TenantMigrationConflict':
            return true;
        case 'TenantMigrationCommitted':
            return true;
        case 'TenantMigrationAborted':
            return true;
        case 'NonRetryableTenantMigrationConflict':
            return true;
        default:
            return false;
    }
};
ErrorCodes.isTenantMigrationConflictError = function(err) {
    'use strict';

    var error;
    if (typeof err === 'string') {
        error = err;
    } else if (typeof err === 'number') {
        if (Object.prototype.hasOwnProperty.call(ErrorCodeStrings, err)) {
            error = ErrorCodeStrings[err];
        } else {
            return false;
        }
    }
    switch (error) {
        case 'TenantMigrationConflict':
            return true;
        case 'NonRetryableTenantMigrationConflict':
            return true;
        default:
            return false;
    }
};
ErrorCodes.isCursorInvalidatedError = function(err) {
    'use strict';

    var error;
    if (typeof err === 'string') {
        error = err;
    } else if (typeof err === 'number') {
        if (Object.prototype.hasOwnProperty.call(ErrorCodeStrings, err)) {
            error = ErrorCodeStrings[err];
        } else {
            return false;
        }
    }
    switch (error) {
        case 'CursorNotFound':
            return true;
        case 'OperationFailed':
            return true;
        case 'QueryPlanKilled':
            return true;
        case 'CursorKilled':
            return true;
        default:
            return false;
    }
};

/**
 * Returns true if the mongos `s` is expected to rewrite state change errors.
 * This is determined by a `getParameter` of the "rewriteStateChangeErrors" option.
 * Failure would indicate a mongos that doesn't support the rewrite feature.
 */
ErrorCodes.probeMongosRewrite = function(s) {
    const param = "rewriteStateChangeErrors";
    const res = s.adminCommand({getParameter: 1, [param]: 1});
    if (!(param in res)) {
        print("Mongos did not return a " + param + " server parameter: " + tojson(res));
        return false;
    }
    return res[param];
};

/**
 * Returns the ErrorCode to which the specified mongos `s` would remap the
 * specified `err`. Mongos normally rewrites connection state change errors,
 * unless it is shutting down or the code was injected by a mongos failpoint.
 *
 * The optional `doesRewrite` bool parameter provides a mechanism to bypass the
 * probe, which may be useful if the probe would interfere with a test's
 * operation.
 */
ErrorCodes.doMongosRewrite = function(s, err, doesRewrite) {
    if (doesRewrite === undefined)
        doesRewrite = ErrorCodes.probeMongosRewrite(s);
    if (doesRewrite) {
        if (ErrorCodes.isNotPrimaryError(err) || ErrorCodes.isShutdownError(err)) {
            return ErrorCodes.HostUnreachable;
        }
    }
    return err;
};
