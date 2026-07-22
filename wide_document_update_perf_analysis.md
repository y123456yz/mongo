# Wide Document Multi-field Update Performance Analysis

## 背景

在 YCSB update workload 中，测试文档为超宽文档：

- `fieldcount=5000`
- `writeallfields=true`
- `updateproportion=1`
- `avgObjSize ~= 581KB`
- 每次 update 会对同一个文档中的大量字段执行 `$set`

测试现象：update 吞吐非常低，多个 `connXXX` 线程接近单核打满。

## 复现负载示例

```bash
./bin/ycsb.sh run mongodb -s -P workloads/workloada \
  -p mongodb.url='mongodb://root:***@host1:port1,host2:port2,host3:port3/admin?authSource=admin&replicaSet=rs0' \
  -p table=test \
  -p recordcount=100000 \
  -p readproportion=0 \
  -p updateproportion=1 \
  -p insertproportion=0 \
  -p operationcount=50000111 \
  -threads 4 \
  -p fieldcount=5000 \
  -p writeallfields=true
```

集合状态示例：

```javascript
db.test.stats().avgObjSize  // ~= 581260
db.test.count()             // 100000
```

## perf 结果摘要

采样线程：执行 update 的连接线程，如 `conn203`。

关键热点路径：

```text
write_ops_exec::performUpdates
  -> PlanExecutor::executeUpdate
    -> update::transformDocument
      -> UpdateDriver::update
        -> UpdateTreeExecutor::applyUpdate
          -> UpdateObjectNode::apply                ~89%
            -> UpdateObjectNode::getChild           ~89%
              -> mutablebson::Element::findFirstChildNamed   ~52%
                 -> Document::Impl::resolveRightSibling       ~18%
              -> __memcmp_avx2_movbe                         ~30%
```

典型 perf 数据：

```text
~89%  mongo::UpdateObjectNode::apply
~89%  mongo::UpdateObjectNode::getChild
~52%  mongo::mutablebson::Element::findFirstChildNamed
~30%  __memcmp_avx2_movbe
~18%  mongo::mutablebson::Document::Impl::resolveRightSibling
```

非主要热点：

```text
~1.6% mongo::SetNode::updateExistingElement / setValue
~1.5% mongo::v2_log_builder::V2LogBuilder::logUpdatedField
~2.0% collection_internal::updateDocumentWithDamages
<1%   WiredTiger commit / log write
```

结论：瓶颈不是 WiredTiger 写入、不是 oplog diff、不是 setValue、不是网络或压缩，而是 update 执行阶段在 mutableBSON 中重复按字段名查找子节点。

## 根因分析

update 请求只携带需要更新的字段及其新值，但 MongoDB 仍需要先从存储引擎读取修改前的整文档，然后在该文档中定位每个待更新字段。

流程如下：

```text
1. WiredTiger 读出修改前整文档（pre-image, BSON）
2. 将 BSON 包装/载入为 mutableBSON Document
3. update 引擎按 `$set` 中的字段逐个定位目标字段
4. 找到字段后，在 mutableBSON 树中修改对应 Element 的值
5. 从修改后的 mutableBSON 生成 post-image，并通过 logBuilder 记录 oplog diff
6. 写回存储引擎 / oplog
```

瓶颈发生在第 3 步。

`Element::operator[](std::string_view)` 会调用 `findFirstChildNamed()`：

```cpp
inline Element Element::operator[](std::string_view name) const {
    return findFirstChildNamed(name);
}
```

`findFirstChildNamed()` 当前是线性扫描：

```cpp
Element Element::findFirstChildNamed(std::string_view name) const {
    current = impl.resolveLeftChild(current);
    while ((current != kInvalidRepIdx) &&
           (impl.getFieldName(impl.getElementRep(current)) != name)) {
        current = impl.resolveRightSibling(current);
    }
    return Element(_doc, current);
}
```

对于 5000 个字段的文档，如果 `$set` 也包含 5000 个字段，则每个字段都需要从 parent object 的第一个 child 开始线性查找：

```text
find field0    -> 比较约 1 次
find field1    -> 比较约 2 次
...
find field4999 -> 比较约 5000 次
```

总字段名比较次数约为：

```text
1 + 2 + ... + 5000 = 5000 * 5001 / 2 ~= 12.5M comparisons / document update
```

因此该场景从单次 O(n) 查找被放大为 O(n²) 多字段更新成本。

## 实际调用链与比较对象

从 update 命令到 `findFirstChildNamed()` 的实际调用链如下：

```text
update command
  -> write_ops_exec::performUpdates
    -> PlanExecutor::executeUpdate
      -> update::transformDocument
        -> UpdateDriver::update
          -> UpdateTreeExecutor::applyUpdate
            -> UpdateObjectNode::apply
              -> applyChild(...)
                -> getChild(applyParams->element, field)
                  -> element[field]
                    -> Element::operator[](std::string_view)
                      -> Element::findFirstChildNamed(field)
```

比较发生在 `findFirstChildNamed(field)` 内部：

```text
impl.getFieldName(current child)  vs  update spec 中当前要更新的 field name
```

也就是说：

- 左边是从 WiredTiger 读出的修改前整文档（pre-image）被包装成 mutableBSON 后，当前遍历到的原文档字段名，例如 `field0`、`field1`、...、`field4999`。
- 右边是 update 请求中当前 modifier 要更新的目标字段名，例如 `$set.field2500`。

虽然 update 请求只携带“要更新的字段及新值”，但执行 update 时必须先在原文档中定位这些字段。对于宽文档多字段更新，每个目标字段都要在同一个 parent object 的 child 链表中查找，因此会形成重复线性扫描。

例如查找 `field2500` 时，mutableBSON 需要从第一个 child 开始比较：

```text
field0 != field2500
field1 != field2500
...
field2500 == field2500
```

如果一次 update 要更新 `field0` 到 `field4999`，就会重复执行上述过程 5000 次，从而形成 O(n²) 成本。

## update 替换过程图形化细化

下面把「读原文档 → 定位字段 → 改值 → 生成新文档/oplog → 写回」这一整条替换链路展开成图，重点标出瓶颈发生在哪一步。

### 端到端五步总览

```text
 ┌──────────────────────────────────────────────────────────────────────┐
 │ 客户端 update: db.test.updateOne({_id}, {$set:{field0:.., .., field4999:..}}) │
 └───────────────────────────────┬──────────────────────────────────────┘
                                 │  请求只带「要改的字段 + 新值」
                                 ▼
 ┌── Step 1 ── WiredTiger 读出修改前整文档（pre-image, 原始 BSON）────────────┐
 │   { _id, field0, field1, field2, ..., field4999 }   ~581KB               │
 └───────────────────────────────┬──────────────────────────────────────┘
                                 ▼
 ┌── Step 2 ── 载入成一棵 mutableBSON 树（Document）────────────────────────┐
 │            root                                                          │
 │             ├─ _id                                                       │
 │             ├─ field0                                                    │
 │             ├─ field1                                                    │
 │             ├─ ...                                                       │
 │             └─ field4999          （root 下挂 5000+ 个 sibling 子节点）     │
 └───────────────────────────────┬──────────────────────────────────────┘
                                 ▼
 ┌── Step 3 ── 按 $set 里的字段逐个「在树里找到它」★瓶颈★───────────────────┐
 │   for 每个目标字段 f:                                                     │
 │       getChild(root, f) -> findFirstChildNamed(f)  → 从第一个 child 线扫  │
 └───────────────────────────────┬──────────────────────────────────────┘
                                 ▼
 ┌── Step 4 ── 找到后修改该节点的值────────────────────────────────────────┐
 │   SetNode::updateExistingElement -> Element::setValue(newVal)            │
 │   （只改 value，节点 RepIdx 不变；perf 占比 <2%）                          │
 └───────────────────────────────┬──────────────────────────────────────┘
                                 ▼
 ┌── Step 5 ── 生成新文档 + oplog diff，写回──────────────────────────────┐
 │   post-image  +  V2LogBuilder 记录 {$v:2, diff:{u:{...}}}  ->  WT / oplog │
 │   （logBuilder / updateDocumentWithDamages / WT 写回 perf 占比均 <3%）     │
 └──────────────────────────────────────────────────────────────────────┘
```

### Step 3 放大：一次 update 里「重复线性查找」如何形成 O(n²)

Step 3 是唯一的热点。它对 `$set` 里的**每一个**字段都在 root 的 sibling 链表上从头扫一遍：

```text
root 的 child/sibling 链：
   _id ─▶ field0 ─▶ field1 ─▶ field2 ─▶ ... ─▶ field4999 ─▶ (end)

查 field0    : _id→field0                                    比较 ~2 次
查 field1    : _id→field0→field1                             比较 ~3 次
查 field2    : _id→field0→field1→field2                      比较 ~4 次
   ...        （每次都从 _id 重新开始，不记得上次扫到哪）
查 field4999 : _id→field0→ ... ─────────────▶ field4999      比较 ~5000 次

累计 ≈ 1 + 2 + ... + 5000 = 5000×5001/2 ≈ 12.5M 次字段名比较 / 单文档
                                              └─▶ 每次比较 = 一次 memcmp
```

对应的 perf 归属：

```text
Step 3 findFirstChildNamed 的链表游走  ─▶ resolveRightSibling  ~18%
Step 3 每步的字段名字符串比较          ─▶ __memcmp_avx2_movbe   ~30%
Step 3 合计（getChild / apply）                                ~89%
Step 4 改值 setValue                                          ~1.6%
Step 5 oplog diff logUpdatedField                             ~1.5%
Step 5 写回 updateDocumentWithDamages                          ~2.0%
```

一句话：**Step 1/2/4/5 都是 O(n) 且占比很低；成本几乎全部集中在 Step 3 的「同一条 sibling 链被反复从头扫描」，把单次 O(n) 定位放大成一次 update 的 O(n²)。**

### 优化后 Step 3 的形态（target-only 一次索引）

第一阶段 cache 只改造 Step 3，其余四步不变：

```text
Step 3'（阈值达成时）:
   ① 只对本次 $set 的目标字段名建一张 target-only 索引（field-name -> Element）
   ② 单次扫描 root 的 child 链，命中一个目标就填一个，全部命中即提前停止
   ③ 之后每个 getChild(f) 直接 O(1) 查索引

复杂度：O(文档字段数 + 目标字段数)  ≈ O(n)   （原来是 O(n²)）
```

## mutableBSON 修改和写回流程

找到目标字段后，update modifier 修改的是 mutableBSON 树中的对应 `Element` 节点。例如 `$set` 最终会调用 `Element::setValue...()`，把该节点的 value 替换为新值。

更新完成后，会从修改后的 mutableBSON 生成 post-image，并写回存储层。同时 oplog diff 通常通过 update 过程中的 `logBuilder` 增量记录修改路径和值；在某些场景下也可能通过 pre-image / post-image 计算 diff。当前 perf 显示 `setValue`、`V2LogBuilder::logUpdatedField`、`updateDocumentWithDamages` 都不是主热点，说明主要瓶颈在字段定位阶段，而不是值修改、diff 生成或 WiredTiger 写回阶段。

## mutableBSON 树结构示例

`mutableBSON Document` 可以理解为一棵可修改的 BSON 树。对象字段是父节点的 child；同一层字段之间是 sibling。`findFirstChildNamed()` 就是在某个 parent object 的 child/sibling 链表中按字段名查找目标字段。

### 1. YCSB 扁平宽文档

YCSB `fieldcount=5000` 生成的文档通常类似：

```javascript
{
  _id: "user123",
  field0: "...",
  field1: "...",
  field2: "...",
  ...,
  field4999: "..."
}
```

这些 `field0` 到 `field4999` 都是 root 下的同一层字段。

逻辑树结构：

```text
Document
└── root
    ├── _id
    ├── field0
    ├── field1
    ├── field2
    ├── ...
    └── field4999
```

更接近 mutableBSON 内部 sibling 链表的形式：

```text
root
 |
 v
_id -> field0 -> field1 -> field2 -> ... -> field4999 -> end
```

因此，更新大量顶层字段时，瓶颈发生在 root 这个 parent object 下的 child lookup。

### 2. 普通扁平文档

```javascript
{
  _id: 1,
  name: "alice",
  age: 20,
  city: "shenzhen"
}
```

```text
Document
└── root
    ├── _id
    ├── name
    ├── age
    └── city
```

内部 sibling 结构：

```text
root
 |
 v
_id -> name -> age -> city -> end
```

字段数较少时，线性查找成本很低，通常不是瓶颈。

### 3. 嵌套对象文档

```javascript
{
  _id: 1,
  user: {
    name: "alice",
    age: 20
  },
  address: {
    city: "shenzhen",
    zip: "518000"
  }
}
```

逻辑树结构：

```text
Document
└── root
    ├── _id
    ├── user
    │   ├── name
    │   └── age
    └── address
        ├── city
        └── zip
```

内部 sibling 结构：

```text
root
 |
 v
_id -> user -> address -> end
       |       |
       |       v
       |       city -> zip -> end
       v
       name -> age -> end
```

查找 `user.name` 时，会先在 root 下找 `user`，再在 `user` 下找 `name`。

### 4. 嵌套宽对象文档

```javascript
{
  _id: 1,
  profile: {
    features: {
      f0: "...",
      f1: "...",
      ...,
      f4999: "..."
    }
  }
}
```

逻辑树结构：

```text
Document
└── root
    ├── _id
    └── profile
        └── features
            ├── f0
            ├── f1
            ├── ...
            └── f4999
```

内部 sibling 结构：

```text
root
 |
 v
_id -> profile -> end
        |
        v
        features -> end
        |
        v
        f0 -> f1 -> f2 -> ... -> f4999 -> end
```

如果 update 为：

```javascript
{
  $set: {
    "profile.features.f0": "...",
    "profile.features.f1": "...",
    ...,
    "profile.features.f4999": "..."
  }
}
```

则瓶颈发生在 `features` 这个 parent object 下，而不是 root 下。因此第一阶段 cache 不能只针对 root，应按 parent object 建立。

### 5. 对象数组文档

```javascript
{
  _id: 1,
  items: [
    {sku: "a", qty: 1},
    {sku: "b", qty: 2}
  ]
}
```

逻辑树结构：

```text
Document
└── root
    ├── _id
    └── items
        ├── [0]
        │   ├── sku
        │   └── qty
        └── [1]
            ├── sku
            └── qty
```

数组 child 名字通常对应字符串索引：

```text
items array
 |
 v
"0" -> "1" -> end
       |
       v
       sku -> qty -> end
```

例如更新 `items.0.qty`，会先在 root 下找 `items`，再定位数组下标 `0`，再在第 0 个对象下找 `qty`。数组路径通常有专门的数字下标解析逻辑，和普通 object 字段查找不完全相同。

### 6. 深层嵌套文档

```javascript
{
  _id: 1,
  a: {
    b: {
      c: {
        d: {
          e: 1
        }
      }
    }
  }
}
```

```text
Document
└── root
    ├── _id
    └── a
        └── b
            └── c
                └── d
                    └── e
```

查找 `a.b.c.d.e` 时，每层只查一个字段。如果每层字段数很少，即使路径较深，也不会形成明显瓶颈。真正的问题是某一层非常宽，并且同一次 update 在这一层反复查找大量 sibling 字段。

### 7. 混合宽 + 深文档

```javascript
{
  _id: 1,
  tenant: "t1",
  metrics: {
    cpu: {
      m0: 1,
      m1: 2,
      ...,
      m999: 999
    },
    mem: {
      m0: 1,
      m1: 2,
      ...,
      m999: 999
    }
  }
}
```

树结构：

```text
Document
└── root
    ├── _id
    ├── tenant
    └── metrics
        ├── cpu
        │   ├── m0
        │   ├── m1
        │   ├── ...
        │   └── m999
        └── mem
            ├── m0
            ├── m1
            ├── ...
            └── m999
```

如果 update 同时更新 `metrics.cpu.*` 和 `metrics.mem.*`，则应分别针对 `metrics.cpu` 和 `metrics.mem` 这两个 parent object 建立 child lookup cache。

### 判断是否容易触发瓶颈的规则

不管文档形态如何，判断规则是：

```text
同一个 parent object 下是否有很多 child 字段；
同一次 update 是否要更新这个 parent 下的很多 child 字段。
```

如果答案是 yes，就容易触发重复线性查找导致的 O(n²) 成本。例如：

```text
root 下 5000 个字段，更新 root 下 5000 个字段           -> 会
features 下 5000 个字段，更新 features 下 5000 个字段   -> 会
cpu 下 1000 个字段，更新 cpu 下 1000 个字段             -> 会
```

反之：

```text
root 下只有 10 个字段            -> 不明显
每次只更新 1~2 个字段            -> 不明显
深度很深但每层字段很少            -> 不明显
```

## 慢日志裁剪是否是主因

慢日志 / 命令日志裁剪也会调用 `findFirstChildNamed()`，例如 update command 的日志裁剪：

```cpp
void snipForLogging(mutablebson::Document* cmdObj) const final {
    redactTooLongLog(cmdObj, "updates");
}
```

`redactTooLongLog()` 会在命令 BSON 顶层查找 `updates`：

```cpp
mmb::Element root = cmdObj->root();
mmb::Element field = root.findFirstChildNamed("updates");
```

但这里查找的是命令对象顶层字段，例如：

```javascript
{ update: "test", updates: [ ... ], ordered: true }
```

顶层字段数量很少，且该逻辑不会对 `$set` 内部的 5000 个字段逐个调用 `findFirstChildNamed()`。因此慢日志裁剪可能有日志序列化开销，但不是当前 perf 显示的主要 CPU 瓶颈。

## 可能受影响的业务场景

该问题主要影响“宽文档 + 多字段更新”的业务模型。

### 高风险场景

1. **宽文档多字段更新**
   - 单文档包含几百到几千个顶层字段。
   - 单次 update 修改大量字段。
   - 例如 YCSB `fieldcount=5000` + `writeallfields=true`。

2. **大 JSON / 宽表模型迁移到 MongoDB**
   - 原关系型宽表或动态属性表直接映射为一个大 BSON 文档。
   - 每次更新大量属性字段。

3. **IoT / 监控 / 指标类宽文档**
   - 一个设备/实体文档内存储大量指标字段。
   - 周期性批量刷新多个指标。

4. **用户画像 / 特征向量类文档**
   - 一个用户文档包含大量 feature 字段。
   - 批量更新多维特征。

5. **配置中心 / 状态快照类文档**
   - 单文档保存大量配置项或状态项。
   - 每次刷新大批字段。

### 较低风险场景

1. 普通 OLTP 文档，字段数量较少。
2. 只更新少量字段的 update。
3. append-only insert workload。
4. replacement update / pipeline update 中不走同样的多字段 modifier 定位路径时，影响可能不同。

## `findFirstChildNamed()` 调用影响面与优化优先级

`findFirstChildNamed()` 不只在 update 主路径中使用，也会出现在日志脱敏、命令改写、错误信息构造等路径。但从性能优先级看，只有多字段 update 字段定位会把单次 O(n) 查找放大为 O(n²)。其他调用大多是单次或少量字段查找，即使单次查找是 O(n)，也通常不会形成主路径瓶颈。

| 场景 | 是否高频 | 是否可能 O(n²) 放大 | 是否值得优先优化 | 说明 |
|---|---:|---:|---:|---|
| 多字段 update 字段定位 | 高 | 是 | 最值得 | `UpdateObjectNode::apply()` 对同一个 parent object 下的多个字段重复调用 `getChild()` / `findFirstChildNamed()`，是当前 perf 中的主热点。 |
| update 错误路径查 `_id` | 低 | 否 | 不重要 | `$inc`、`$bit`、`$push`、`$rename` 等错误路径为了构造报错信息查 `_id`，不是正常高频主路径。 |
| 命令日志脱敏 | 中低 | 一般否 | 不优先 | `Command::snipForLogging()` 会查敏感字段并脱敏，通常只处理命令顶层少量字段。 |
| write command 日志裁剪 | 低 | 否 | 不优先 | `redactTooLongLog()` 对 update 只查命令顶层 `updates` 字段，不遍历 `$set` 内的 5000 个业务字段。 |
| `listCollections` 命令改写 | 低 | 否 | 不优先 | 只查 `authorizedCollections`、`filter` 等少量命令字段。 |
| `setParameter` / log component 构造 | 低 | 否 | 不优先 | 主要用于参数命令和日志组件 BSON 树构造，频率低。 |
| time-series `$jsonSchema` 改写 | 低/中 | 一般否 | 不优先 | 查 `$jsonSchema` 下的 `required`、`properties`，通常不形成重复 O(n²) 查找。 |

因此，第一阶段 PR 不建议全局修改 `Element::findFirstChildNamed()` 的行为，而应优先针对 `update apply` 的多字段定位做局部优化。这样可以精准覆盖当前 perf 证明的热点，同时避免影响日志、命令改写、参数处理等低频路径。

## 解决方案建议

### 方案 A：Update 层临时 child lookup cache（推荐作为第一版 PR）

核心思路：在一次 update apply 期间，对同一个 parent object 的多个字段查找建立临时索引，避免对每个字段都调用 `findFirstChildNamed()` 从头线性扫描。

当前逻辑：

```text
for each field in $set:
    child = parent.findFirstChildNamed(field)  // O(n)
```

优化后：

```text
if this parent has many update children:
    build temporary map: fieldName -> mutablebson::Element  // O(n)

for each field in $set:
    child = map[field]  // O(1)
```

复杂度变化：

```text
Before: O(number_of_updated_fields * number_of_document_fields)
After:  O(number_of_document_fields + number_of_updated_fields)
```

对 5000 字段全量更新：

```text
Before: ~12.5M field-name comparisons per document update
After:  ~5K scan + 5K hash lookups
```

建议设计：

1. cache 生命周期限制在一次 update apply 内。
2. 只对 object parent 生效，array 路径保持原逻辑。
3. 使用阈值保护小文档，例如：
   - 当前层 update child 数量超过 32；或
   - parent object 子字段数超过 128。
4. 小文档完全走旧路径，避免回归。
5. 对结构性修改（插入、删除、rename）可保守地失效对应 parent 的 cache。
6. 第一版优先覆盖 `$set` / 多字段 modifier 更新主路径。

优点：

- 改动范围局限在 update 模块。
- 不改变 mutableBSON 核心数据结构。
- 风险低，易 review。
- 精准命中当前 perf 证据中的热点。

缺点：

- 只覆盖 update apply 路径。
- 不覆盖其他直接调用 `findFirstChildNamed()` 的场景，如命令日志脱敏、listCollections 改写等。

### 第一阶段 PR 的覆盖范围

如果 cache 实现在 `UpdateObjectNode::apply()` / `getChild()` 路径内，则覆盖范围如下：

| 场景 | 是否被 Update 层 cache 覆盖 | 原因 |
|---|---:|---|
| 多字段 update 字段定位 | 覆盖 | 发生在 `UpdateObjectNode::apply()` / `getChild()` 路径内，cache 就加在这里。 |
| `$set` 大量字段 | 覆盖 | `$set` 需要先定位 existing element，再调用 `setValue`。 |
| `$inc` / `$mul` 大量字段 | 覆盖 | arithmetic modifier 同样先通过 update tree 定位字段，再执行数值修改。 |
| `$min` / `$max` 大量字段 | 覆盖 | compare modifier 同样依赖 existing element lookup。 |
| `$currentDate` 大量字段 | 覆盖 | 需要定位字段后写入当前时间值。 |
| 嵌套宽对象下的大量字段更新 | 覆盖，但要求 cache 按 parent object 建立 | 例如 `profile.features.f0` 到 `profile.features.f4999`，瓶颈发生在 `features` 这个 parent 下的 child lookup。 |
| `$unset` 大量字段 | 可覆盖，但需要处理结构性修改 | `$unset` 会 remove element，cache 需要在 remove 后失效或谨慎维护。 |
| `$rename` 大量字段 | 只能部分覆盖，第一版不建议重点承诺 | `$rename` 同时涉及 source/destination lookup、remove、insert、overwrite、路径合法性检查，cache 一致性更复杂。 |
| update 错误路径查 `_id` | 不覆盖 | 这些是在 `$inc` / `$bit` / `$push` / `$rename` 的错误处理路径里直接调用 `findFirstChildNamed(root, "_id")`。 |
| 命令日志脱敏 | 不覆盖 | 在 `Command::snipForLogging()` 中执行，不走 update apply。 |
| write command 日志裁剪 | 不覆盖 | 在 `write_commands.cpp::redactTooLongLog()` 中执行，不走 update apply。 |
| `listCollections` 命令改写 | 不覆盖 | 在 `cluster_list_collections_cmd.cpp` 中执行，不走 update apply。 |
| `setParameter` / log component BSON 构造 | 不覆盖 | 在 `commands/parameters.cpp` 中执行，不走 update apply。 |
| time-series `$jsonSchema` 改写 | 不覆盖 | 在 `timeseries_update_delete_util.cpp` 中执行，不走 update apply。 |

因此，第一阶段 PR 主要解决 update 主路径中“同一个 parent object 下大量字段定位”的 O(n²) 问题。它不会覆盖所有 `findFirstChildNamed()` 调用，但这正是其风险较低、scope 清晰的原因。

### 方案 B：mutableBSON 通用 lazy field-name index（可作为第二阶段 PR）

核心思路：在 mutableBSON 层为宽 object 节点懒构建字段名索引，使所有 `findFirstChildNamed()` 调用受益。

设计方向：

```text
object ElementRep -> optional field-name index
fieldName -> first child RepIdx
```

关键点：

1. 只在 child 数量超过阈值时构建索引。
2. 第一次查找时懒构建。
3. 对重复字段保留 “first child named” 语义，即索引只记录第一个同名字段。
4. 插入、删除、rename、detach、move 等结构性 mutation 需要维护或失效索引。
5. 小文档必须不退化。

优点：

- 覆盖所有 `findFirstChildNamed()` 调用点。
- 从底层解决宽文档字段查找问题。

缺点：

- 改动 mutableBSON 核心，风险较高。
- 需要处理 lazy materialization、重复字段和 mutation 一致性。
- 回归测试范围更大。
- 不适合作为第一版小范围 PR。

### 方案 C：顺序扫描游标优化（可作为补充，不推荐作为主方案）

如果 update 字段顺序与文档字段顺序一致，可以记住上一次找到的位置，下次从右兄弟继续查找，而不是每次从第一个 child 开始。

优点：实现较轻。

缺点：依赖字段顺序；乱序 update 效果不稳定；不如临时 map 通用。

## 推荐实施路线

建议分两阶段：

### 第一阶段

提交 update 层临时 child lookup cache。

目标：

```text
Optimize multi-field updates on wide documents by avoiding repeated linear mutableBSON child lookups.
```

原因：

- 当前 perf 已明确证明 update 主路径是瓶颈。
- 该方案改动小、风险低、收益明确。
- 适合作为社区第一版 PR。

### 第二阶段（可选）

如果社区认可该问题并希望更通用地解决，再考虑 mutableBSON 通用 lazy field-name index。

目标：

```text
Generalize fast child lookup for wide BSON objects across mutableBSON users.
```

## Benchmark 建议

PR 中建议补充 microbenchmark：

1. 字段数维度：
   - 10
   - 50
   - 100
   - 500
   - 1000
   - 5000
   - 10000

2. 更新字段数维度：
   - 1 个字段
   - 10 个字段
   - 100 个字段
   - 全字段更新

3. 字段顺序：
   - 与文档顺序一致
   - 随机顺序
   - 逆序

4. 需要证明：
   - 宽文档多字段 update 从 O(n²) 降到接近 O(n)。
   - 小文档无明显性能回退。
   - 单字段 update 无明显回退。
   - oplog diff / WT 写入不是主要影响项。

## YCSB 压测方法与随机字段等价换算

### 背景：为什么需要换算

标准 YCSB 的 `writeallfields=true` 不是「从 5000 个字段里随机挑 N 个字段更新」，而是更新当前 workload 配置里定义的**全部字段**：

```text
-p fieldcount=M -p writeallfields=true
```

等价于每次 update：

```javascript
{$set: {field0: ..., field1: ..., ..., field(M-1): ...}}
```

也就是说，YCSB 多字段 update 默认更新的是**前 M 个字段**，不是随机 M 个字段。

而真实「随机更新 K 个字段」的查找成本更高，因为目标字段平均分布在 `field0..field4999` 中间位置；查一个随机字段平均要扫约一半 sibling 链。为了用标准 YCSB 模拟随机 K 字段的**线性查找成本**，需要把随机 K 字段换算成一个等价的 YCSB `fieldcount=M`。

### 换算公式

假设：

- 文档实际有 `N = 5000` 个字段：`field0..field4999`
- 随机更新 `K` 个字段，字段在 `[0, N-1]` 中均匀分布
- YCSB `writeallfields=true` 更新前 `M` 个字段：`field0..field(M-1)`
- 忽略 `_id` 带来的 1 次额外扫描（对 5000 字段场景影响很小）

随机更新 `K` 个字段的期望比较次数：

```text
Cost_random(K) ≈ K * (N + 1) / 2
               = K * 5001 / 2
```

YCSB 更新前 `M` 个字段的比较次数：

```text
Cost_ycsb(M) ≈ 1 + 2 + ... + M
             = M * (M + 1) / 2
```

令两者相等：

```text
M * (M + 1) / 2 ≈ K * 5001 / 2

M² + M - K * 5001 ≈ 0

M ≈ (sqrt(1 + 4 * K * 5001) - 1) / 2
```

### 等价换算表（文档固定 5000 字段）

| 随机更新字段数 K | 占 5000 字段比例 | 随机 K 字段期望比较次数 | 等价 YCSB `fieldcount=M` | 等价 YCSB 配置 |
|---:|---:|---:|---:|---|
| 10 | 0.20% | ~25,005 | **223** | `-p fieldcount=223 -p writeallfields=true` |
| 50 | 1.00% | ~125,025 | **500** | `-p fieldcount=500 -p writeallfields=true` |
| 100 | 2.00% | ~250,050 | **707** | `-p fieldcount=707 -p writeallfields=true` |
| 500 | 10.00% | ~1,250,250 | **1581** | `-p fieldcount=1581 -p writeallfields=true` |
| 1000 | 20.00% | ~2,500,500 | **2236** | `-p fieldcount=2236 -p writeallfields=true` |
| 2000 | 40.00% | ~5,001,000 | **3162** | `-p fieldcount=3162 -p writeallfields=true` |
| 5000 | 100.00% | ~12,502,500 | **5000** | `-p fieldcount=5000 -p writeallfields=true` |

注意：这个表是**优化前线性查找成本等价**，不是「更新字段数量等价」。例如：

```text
随机更新 100 个字段
≈ YCSB 更新前 707 个字段的 findFirstChildNamed 查找成本
```

原因是随机 100 个字段平均落在 5000 字段文档的中间位置；而 YCSB 更新前 100 个字段只集中在链表前段，查找成本远低于随机 100 个。

### 推荐压测步骤

测试方法总览（两阶段）：

1. **load 阶段：先写数据。** 固定用 `fieldcount=5000` 写入 10 万条宽文档，让每条文档真实包含 `field0..field4999`。这一步的 `fieldcount` 决定的是**文档实际宽度**，必须是 `5000`，不随场景变化。
2. **run 阶段：再做 update 测试。** run 阶段的 `fieldcount` **不是文档宽度**，而是「随机更新 K 个字段」换算出来的**等价 `fieldcount=M`**（见上方等价换算表）。配合 `writeallfields=true`，即模拟对应随机 K 字段更新的线性查找成本。

也就是说：`load` 用 `fieldcount=5000`（真实宽度），`run` 用等价 `fieldcount=M`（随机 K 字段的成本等价值），这是两个含义不同的 `fieldcount`，不要混淆。

#### 1. 数据准备（load，fieldcount 固定为 5000）

先用 `fieldcount=5000` load 出 10 万条宽文档，确保每条文档真实包含 `field0..field4999`：

```bash
./bin/ycsb.sh load mongodb -s -P workloads/workloada \
  -p mongodb.url='mongodb://root:***@host1:port1,host2:port2,host3:port3/admin' \
  -p table=test \
  -threads 100 \
  -p recordcount=100000 \
  -p fieldcount=5000
```

#### 2. 关闭优化，测 baseline

当前优化参数默认 `0`，表示关闭。也可以显式关闭：

```javascript
db.adminCommand({
  setParameter: 1,
  internalUpdateObjectNodeChildLookupCacheThreshold: 0
})
```

然后按上表的等价 `fieldcount=M` 跑 YCSB，例如模拟「随机更新 100 字段」的查找成本：

```bash
./bin/ycsb.sh run mongodb -s -P workloads/workloada \
  -p mongodb.url='mongodb://root:***@host1:port1,host2:port2,host3:port3/admin?authSource=admin&replicaSet=rs0' \
  -p table=test \
  -p recordcount=100000 \
  -p readproportion=0 \
  -p updateproportion=1 \
  -p insertproportion=0 \
  -p operationcount=500000 \
  -threads 4 \
  -p fieldcount=707 \
  -p writeallfields=true
```

#### 3. 在线启用优化，测 optimized

```javascript
db.adminCommand({
  setParameter: 1,
  internalUpdateObjectNodeChildLookupCacheThreshold: 50
})
```

保持相同 YCSB 参数再次运行，对比 throughput / average latency / p95 / p99。

#### 4. 结果记录建议

建议每个等价场景都记录两组数据：

| 场景 | YCSB fieldcount | threshold=0 吞吐 | threshold=50 吞吐 | 提升比例 | baseline p99 | optimized p99 |
|---|---:|---:|---:|---:|---:|---:|
| 随机 10 字段等价 | 223 |  |  |  |  |  |
| 随机 50 字段等价 | 500 |  |  |  |  |  |
| 随机 100 字段等价 | 707 |  |  |  |  |  |
| 随机 500 字段等价 | 1581 |  |  |  |  |  |
| 随机 1000 字段等价 | 2236 |  |  |  |  |  |
| 随机 2000 字段等价 | 3162 |  |  |  |  |  |
| 随机 5000 字段等价 | 5000 |  |  |  |  |  |

### 压测解释注意事项

1. 这个换算只模拟「字段定位查找成本」，并不等价于真实随机 K 字段 update 的所有行为。
2. 真实随机 K 字段 update 只有 K 个 target；而等价 YCSB `fieldcount=M` 会实际更新 M 个字段，因此会多产生一些 `setValue` / oplog diff 成本。
3. 对当前 perf 证据而言，`findFirstChildNamed` 是绝对主热点，所以该换算可用于近似评估优化前后的查找成本变化。
4. 如果要严格验证真实随机 K 字段场景，最好修改 YCSB workload，使其支持「每次从 5000 个字段中随机选择 K 个不重复字段更新」。
5. 若 `threshold=50`，真实随机 10 字段不会触发 cache；而等价 YCSB `fieldcount=223` 会触发 cache。因此该表主要用于**查找成本等价压测**，不是触发条件等价压测。

## 总结

当前 YCSB 5000 字段 update 慢的根因是 update 执行阶段在 mutableBSON 中重复执行线性字段查找：

```text
UpdateObjectNode::getChild -> Element::findFirstChildNamed -> memcmp / resolveRightSibling
```

该问题在宽文档多字段更新场景中会形成 O(n²) 成本。第一版建议在 update 层实现临时 child lookup cache，以较小改动消除主路径瓶颈；后续如有需要，再考虑在 mutableBSON 层实现通用 lazy field-name index。

## 多字段 update 优化原理（图形化）

本节用图形化方式，完整描述已落地的第一阶段优化（target-only per-apply child lookup cache）的工作原理。

### 一、优化前 vs 优化后：核心对比

```text
                     ┌───────────────────────── 优化前（线性 O(n²)）─────────────────────────┐
                     │                                                                      │
 $set 目标字段        │   root child 链: _id ▶ f0 ▶ f1 ▶ f2 ▶ ... ▶ f4999                    │
   f0   ────────────▶│   查 f0    : 从 _id 从头扫 ─────▶ f0                                  │
   f1   ────────────▶│   查 f1    : 从 _id 从头扫 ──────────▶ f1                             │
   f2   ────────────▶│   查 f2    : 从 _id 从头扫 ───────────────▶ f2                        │
   ...               │   ...        每次都「从头」，同一条链被反复扫                            │
   f4999 ───────────▶│   查 f4999 : 从 _id 从头扫 ─────────────────────────▶ f4999           │
                     │   Σ ≈ 12.5M 次 memcmp                                                 │
                     └──────────────────────────────────────────────────────────────────────┘

                     ┌───────────────────────── 优化后（一次索引 O(n)）─────────────────────┐
                     │                                                                      │
                     │   ① 建 target-only 索引（只扫一遍 child 链）:                          │
                     │        _id ▶ f0 ▶ f1 ▶ ... ▶ f4999   ── 单趟扫描 ──▶  index{         │
                     │                                            f0    -> Element(f0),      │
                     │                                            f1    -> Element(f1),      │
                     │                                            ...                        │
                     │                                            f4999 -> Element(f4999) }  │
 $set 目标字段        │   ② 逐字段查：                                                        │
   f0   ────────────▶│        getChild(f0)    ─▶ index[f0]    O(1)                          │
   f1   ────────────▶│        getChild(f1)    ─▶ index[f1]    O(1)                          │
   ...               │        ...                                                           │
   f4999 ───────────▶│        getChild(f4999) ─▶ index[f4999] O(1)                          │
                     │   Σ ≈ 一趟扫描(n) + n 次 O(1) 查 = O(n)                                │
                     └──────────────────────────────────────────────────────────────────────┘
```

### 二、"target-only"的关键：索引只装「要改的字段」，不装整篇文档

这是与朴素 full-cache 的本质区别，也是防止「宽文档小更新反而变慢」的关键。

```text
文档很宽（5000 字段），但本次只改其中少数字段时：

  full-cache（不采用）:                    target-only（已采用）:
  ┌────────────────────────┐            ┌────────────────────────┐
  │ 把 f0..f4999 全部       │            │ 只把本次 $set 的目标     │
  │ 塞进索引（5000 条）      │            │ 字段塞进索引            │
  │ 内存/构建随「文档宽度」   │            │ 内存/构建随「更新字段数」 │
  │ 增长 → 小更新也吃亏      │            │ 增长 → 小更新零负担      │
  └────────────────────────┘            └────────────────────────┘

  索引大小 = O(文档字段数)                索引大小 = O(目标字段数)  ✔
```

构建时还带「找齐即停」：

```text
seed: 用目标字段名初始化索引，值先标记为 absent(非ok Element)
scan: 沿 child 链单趟遍历
        命中一个目标 → 填入其 Element，remaining--
        remaining==0 → 立即停止（不再扫剩余的 child）
结果: 存在的目标一定被找到；不存在的目标保持 absent（= 权威「缺失」，等价线性未命中）
```

### 三、查找决策流程（getChild 的三条路径）

```text
                 getChild(element, field, cache)
                              │
              ┌───────────────┴───────────────┐
        element 是 object?                element 是 array?
              │ 是                              │ 是
              ▼                                 ▼
   cache != null 且                     findNthChild(index)
   element == cache.parent() ?          （按下标，cache 不参与，行为不变）
        │ 是            │ 否
        ▼               ▼
  tryGetChild(field)   element[field]        （原始线性 findFirstChildNamed）
        │                    ▲
   ┌────┴─────┐               │
命中目标?    非目标? ──▶ boost::none ──▶ 回退线性 element[field]
   │
   ├─ 存在 → 返回该 Element (O(1))
   └─ 缺失 → 返回 non-ok Element（= 权威「不存在」）
```

三条路径保证：**cache 只加速「本次目标字段在 object parent 上的定位」，其它一切情况都原样走老逻辑** —— 这就是"只改性能、不改语义"。

### 四、触发条件（什么时候才建索引）

```text
if ( _children.size() >= threshold    // 本层「要改的字段数」达到阈值
     && applyParams.element.ok()      // parent 元素有效
     && parent 是 BSONType::object )  // 只对 object（array 走下标，不适用）
     → 建 target-only 索引
否则 → 完全走原始线性路径（与优化前逐字节一致）
```

注意判断依据是 `_children.size()`（本次要改多少字段），**不是文档里 parent 有多少子字段**。

#### 阈值可在线配置（server parameter）

阈值不再是硬编码常量，而是运行时可调的 server parameter：

- 名称：`internalUpdateObjectNodeChildLookupCacheThreshold`
- 默认值：`0`（默认关闭该优化）
- 取值范围：`>= 0`（validator 限制）
- `0`：关闭 target-only child lookup cache，完全走原始线性查找路径
- `>0`：当本层 `_children.size() >= threshold` 时启用索引
- `set_at: [startup, runtime]`：既可启动时设，也可运行时**在线修改**，无需重启
- 类型：`Atomic<int>`，`apply()` 内一次性 `load()` 读快照，避免同一次 apply 中被并发改动影响决策
- 语义保证：只影响「是否走 cache 快路径」，**不改变更新结果**；调成 `0` 即关闭该优化

在线查看/修改示例（mongo shell）：

```javascript
// 查看当前值
db.adminCommand({ getParameter: 1, internalUpdateObjectNodeChildLookupCacheThreshold: 1 })

// 在线调小（更激进，更多 update 走索引）
db.adminCommand({ setParameter: 1, internalUpdateObjectNodeChildLookupCacheThreshold: 20 })

// 在线关闭优化
db.adminCommand({ setParameter: 1, internalUpdateObjectNodeChildLookupCacheThreshold: 0 })
```

启动时设置示例：

```bash
mongod --setParameter internalUpdateObjectNodeChildLookupCacheThreshold=64
```

这样便于压测调参（扫出最优拐点）以及线上出现异常时应急回退，均无需重新编译或重启。

### 五、天然覆盖嵌套宽对象（每层独立决策）

因为 `UpdateObjectNode::apply()` 是逐层递归的，每一层各自按自己的 `_children.size()` 决定是否建 cache：

```text
{ a: { b: { f0..f4999 } } }   +   $set:{ "a.b.f0":.., ..., "a.b.f4999":.. }

apply(root)      : root 只有 1 个 child(a)      → 不建（<阈值）
  apply(a)       : a 只有 1 个 child(b)         → 不建（<阈值）
    apply(b)     : b 有 5000 个目标 child       → 建 target-only 索引 ✔  ← 瓶颈就在这层
```

无需任何跨层特殊逻辑，宽对象在哪层，索引就在哪层生效。

### 六、为什么正确性安全（一图记住）

```text
Element = (Document*, RepIdx=整数索引)  ── 不是裸指针
   │
   ├─ 改值($set/$inc/..)     : 只改 value，RepIdx 不变      → 索引条目仍有效 ✔
   ├─ 底层 vector realloc     : 存的是 RepIdx 不是指针        → 不受影响     ✔
   ├─ 重复字段名             : try_emplace 只留第一个        → first-match 语义 ✔
   ├─ 结构性修改($unset/$rename): 各字段名唯一、删完不再查    → 不失效       ✔
   └─ 生命周期              : 只活在一次 apply() 栈帧内        → 无并发/无泄漏 ✔
```

一句话原理总结：**在一次 `apply()` 内，对「本次要改的字段」做一趟扫描建立 field-name→Element 的临时索引，把 Step 3 里对同一条 sibling 链的 N 次「从头线扫」压缩成「1 次扫描 + N 次 O(1) 查」，从而把宽文档多字段 update 的定位成本从 O(n²) 降到 O(n)；并通过 target-only（索引只装目标字段）+ 阈值 + 严格回退，保证小文档零退化、语义完全不变。**
