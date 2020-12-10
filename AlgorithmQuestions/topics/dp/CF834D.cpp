#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int a[N], dp[N] = {0};

struct SegNode {
    int l, r;
    int mx;
    int add;
} tree[N * 4];


void pushup(int p) {
    tree[p].mx = max(tree[p * 2].mx, tree[p * 2 + 1].mx);
}

void pushdown(int p) {
    if (tree[p].add) {
        tree[p * 2].add += tree[p].add;
        tree[p * 2].mx += tree[p].add;
        tree[p * 2 + 1].add += tree[p].add;
        tree[p * 2 + 1].mx += tree[p].add;
        tree[p].add = 0;
    }
}

void build(int p, int l, int r) {
    tree[p].l = l;
    tree[p].r = r;
    tree[p].add = 0;
    tree[p].mx = 0;
    if (l == r) {
        tree[p].mx = dp[l - 1];
        return ;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    pushup(p);
}

void update(int p, int l, int r, int v) {
    if (l <= tree[p].l && tree[p].r <= r) {
        tree[p].add += v;
        tree[p].mx += v;
        return ;
    }
    pushdown(p);
    int mid = (tree[p].l + tree[p].r) / 2;
    if (l <= mid) {
        update(p * 2, l, r, v);
    }
    if (r > mid) {
        update(p * 2 + 1, l, r, v);
    }
    pushup(p);
}

int query(int p, int l, int r) {
    if (l <= tree[p].l && tree[p].r <= r) {
        return tree[p].mx;
    }
    pushdown(p);
    int mid = (tree[p].l + tree[p].r) / 2;
    int res = -1e9;
    if (l <= mid) {
        res = max(res, query(p * 2, l, r));
    }
    if (r > mid) {
        res = max(res, query(p * 2 + 1, l, r));
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    map<int, int> pos;
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (pos.find(a[i]) == pos.end()) {
            pos[a[i]] = 0;
        }
        pre[i] = pos[a[i]] + 1;
        pos[a[i]] = i;
    }
    for (int j = 1; j <= k; ++j) {
        build(1, 1, n);
        for (int i = 1; i <= n; ++i) {
            update(1, pre[i], i, 1);
            dp[i] = query(1, 1, i);
        }
    }
    cout << dp[n] << endl;
}
