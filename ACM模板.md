# ACM模板

Chiang Yin-tso

[TOC]

## 数据结构

### 线段树

```C++
/**
 * luogu3372
 *
 */
#include <cstdio>

long long seq[100008];
long long seg_tree[400008];
long long add_tag[400008] = {0};

/**
 * 建立线段树
 * @param l 区间左端点
 * @param r 区间右端点
 * @param num 序号
 */
void build(int l, int r, int num) {
    if (l == r) {
        seg_tree[num] = seq[l];
        return;
    }

    build(l, (l + r) / 2, num << 1);
    build((l + r) / 2 + 1, r, num << 1 | 1);

    seg_tree[num] = seg_tree[num << 1] + seg_tree[num << 1 | 1];
}

/**
 * 下推懒惰标记
 * @param l 左区间端点
 * @param r 右区间端点
 * @param num 序号
 */
void push_down(int l, int r, int num) {

    if (add_tag[num]) {
        int mid = (r + l) / 2;
        seg_tree[num << 1] += add_tag[num] * (mid - l + 1);
        seg_tree[num << 1 | 1] += add_tag[num] * (r - mid);
        add_tag[num << 1] += add_tag[num];
        add_tag[num << 1 | 1] += add_tag[num];
        add_tag[num] = 0;
    }
}

/**
 * 区间更新
 * @param update_l 更新区间左端点
 * @param update_r 更新区间右端点
 * @param value 更新的值
 * @param l 当前搜索区间左端点
 * @param r 当前搜索区间右端点
 * @param num 线段树序号
 */
void update(int update_l, int update_r, long long value, int l, int r, int num) {
    if (update_l <= l && r <= update_r) {
        seg_tree[num] += (r - l + 1) * value;
        add_tag[num] += value;
        return;
    }

    push_down(l, r, num);

    int mid = (l + r) / 2;
    if (update_l <= mid) {
        update(update_l, update_r, value, l, mid, num << 1);
    }
    if (mid + 1 <= update_r) {
        update(update_l, update_r, value, mid + 1, r, num << 1 | 1);
    }
    seg_tree[num] = seg_tree[num << 1] + seg_tree[num << 1 | 1];
}

/**
 * 区间查询
 * @param query_l 查询区间左端点
 * @param query_r 查询区间右端点
 * @param l 当前搜索区间左端点
 * @param r 当前搜索区间右端点
 * @param num 线段树序号
 * @return 区间查询结果（求区间和）
 */
long long query(int query_l, int query_r, int l, int r, int num) {

    if (query_l <= l && r <= query_r) {
        return seg_tree[num];
    }

    push_down(l, r, num);

    long long result = 0;
    int mid = (l + r) / 2;
    if (query_l <= mid) {
        result += query(query_l, query_r, l, mid, num << 1);
    }
    if (mid + 1 <= query_r) {
        result += query(query_l, query_r, mid + 1, r, num << 1 | 1);
    }
    return result;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &seq[i]);
    }
    build(1, n, 1);
    int op;
    long long x, y, k;
    for (int i = 0; i < m; ++i) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%lld %lld %lld", &x, &y, &k);
            update(x, y, k, 1, n, 1);
        } else {
            scanf("%lld %lld", &x, &y);
            printf("%lld\n", query(x, y, 1, n, 1));
        }
    }
    return 0;
}
```



## 图论

### 树

#### LCA

倍增求LCA

```C++
/**
 * luogu3379
 */

#include <cstdio>
#include <algorithm>

using namespace std;

struct Edge {
    int v;
    int next;
} edges[500002 << 1];
int heads[500002];
int total = 0;

int depth[500002] = {0};
int ancestors[500002][22] = {0};

int LOG_2[500002];

void add_edge(int u, int v) {
    edges[++total] = {v, heads[u]};
    heads[u] = total;
}

void dfs(int cur_v, int parent) {
    ancestors[cur_v][0] = parent;
    depth[cur_v] = depth[parent] + 1;

    for (int i = 1; i <= LOG_2[depth[cur_v]]; ++i) {
        ancestors[cur_v][i] = ancestors[ancestors[cur_v][i-1]][i-1];
    }

    for (int i = heads[cur_v]; i; i = edges[i].next) {
        if (edges[i].v != parent) {
            dfs(edges[i].v, cur_v);
        }
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    while (depth[a] > depth[b]) {
        a = ancestors[a][LOG_2[depth[a]-depth[b]]];
    }
    if (a == b) {
        return a;
    }
    for (int i = LOG_2[depth[a]]; i >= 0; --i) {
        if (ancestors[a][i] != ancestors[b][i]) {
            a = ancestors[a][i];
            b = ancestors[b][i];
        }
    }
    return ancestors[a][0];
}

void get_log_2() {
    LOG_2[1] = 0;
    for (int i = 2; i <= 500001; ++i) {
        LOG_2[i] = LOG_2[i>>1] + 1;
    }
}

int main() {
    get_log_2();

    int n, m, s;
    scanf("%d %d %d", &n, &m, &s);

    int x, y;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d %d", &x, &y);
        add_edge(x, y);
        add_edge(y, x);
    }

    dfs(s, 0);

    int a, b;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &a, &b);
        printf("%d\n", lca(a, b));
    }

    return 0;
}
```









