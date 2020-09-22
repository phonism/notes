/*
 * 题目链接：https://codeforces.com/contest/1187/problem/D
 * 题意：给两个数组，问数组b是否可以由数组a通过任意个区间sort操作变换得到。
 * 题解：我们考虑那些情况会导致失败，对于数组b的每一个数，如果数组a中这个数前面的数有比这个数小的，那说明有问题
 *       每次排除一个旧把那个值置为最大值。用线段树维护就好。
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 7;

struct SegNode {
    int l, r;
    int min;
}tree[N * 4];

int a[N], b[N];

void build(int p, int l, int r) {
    tree[p].l = l;
    tree[p].r = r;
    if (tree[p].l == tree[p].r) {
        tree[p].min = a[l];
        return ;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    tree[p].min = min(tree[p * 2].min, tree[p * 2 + 1].min);
}

void update(int p, int x, int v) {
    if (tree[p].l == tree[p].r) {
        tree[p].min = v;
        return ;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    if (x <= mid) {
        update(p * 2, x, v);
    } else {
        update(p * 2 + 1, x, v);
    }
    tree[p].min = min(tree[p * 2].min, tree[p * 2 + 1].min);
}

int query(int p, int l, int r) {
    if (l <= tree[p].l && r >= tree[p].r) {
        return tree[p].min;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    int res = 1e9;
    if (l <= mid) {
        res = min(res, query(p * 2, l, r));
    }
    if (r > mid) {
        res = min(res, query(p * 2 + 1, l, r));
    }
    return res;
}

queue<int> adj[N];

int main() {
    int tests;
    scanf("%d", &tests);
    for (int t = 0; t < tests; ++t) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i <= n; ++i) {
            while (!adj[i].empty()) {
                adj[i].pop();
            }
        }
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            adj[a[i]].push(i);
        }
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &b[i]);
        }
        build(1, 1, n);
        bool ok = true;
        for (int i = 1; i <= n; ++i) {
            if (adj[b[i]].empty()) {
                ok = false;
                break;
            }
            int m = query(1, 1, adj[b[i]].front());
            if (m == b[i]) {
                update(1, adj[b[i]].front(), 1e9);
            } else {
                ok = false;
                break;
            }
            adj[b[i]].pop();
        }
        if (ok) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
}
