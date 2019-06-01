#include <stdio.h>
#include <string.h>

int arr[50005];
int tree[200005];

void push_up(int node)
{
    tree[node] = tree[node<<1] + tree[node<<1|1];
}

void build_tree(int l, int r, int node)
{
    if (l == r) {
        tree[node] = arr[l]; 
        return;
    }
    int m = (l + r) / 2;
    build_tree(l, m, node<<1);
    build_tree(m+1, r, node<<1|1);
    push_up(node);
}

void update_tree(int val, int idx, int l, int r, int node)
{
    if (l == r) {
        tree[node] += val;
        return;
    }

    int m = (l + r) / 2;
    if (idx <= m) {
        update_tree(val, idx, l, m, node<<1);
    }
    else {
        update_tree(val, idx, m+1, r, node<<1|1);
    }
    push_up(node);
}

int query(int ql, int qr, int l, int r, int node)
{
    if (ql <= l && r <= qr) {
        return tree[node];
    }

    int res = 0;
    int m = (l + r) / 2;
    if (m >= ql) {
        res += query(ql, qr, l, m, node<<1);
    }
    if (m+1 <= qr) {
        res += query(ql, qr, m+1, r, node<<1|1);
    }
    return res;
}

int main()
{
    int t, n;
    scanf("%d", &t);
    for (int _case=1; _case<=t; ++_case) {
        scanf("%d", &n);
        for (int i=1; i<=n; ++i) {
            scanf("%d", &arr[i]);
        }
        build_tree(1, n, 1);

        printf("Case %d:\n", _case);

        char query_str[6];
        int l, r;
        while (1) {
            scanf("%s", query_str);
            if (strcmp(query_str, "End") == 0) {
                break;
            }
            scanf("%d %d", &l, &r);
            if (strcmp(query_str, "Query") == 0) {
                printf("%d\n", query(l, r, 1, n, 1));
            }
            else if (strcmp(query_str, "Add") == 0) {
                update_tree(r, l, 1, n, 1);
            }
            else if (strcmp(query_str, "Sub") == 0) {
                update_tree(-r, l, 1, n, 1);
            }
        }
    }
    return 0;
}