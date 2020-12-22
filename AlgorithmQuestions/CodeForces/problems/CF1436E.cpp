#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 100;

struct SegNode {
    int l, r;
    int min;
} tree[N * 4];

void build(int p, int l, int r) {
    tree[p].l = l;
    tree[p].r = r;
    if (tree[p].l == tree[p].r) {
        tree[p].min = 0;
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
    if (tree[p].l >= l && tree[p].r <= r) {
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

int last[N];
int a[N];

int main() {
    int n;
    cin >> n;
    build(1, 1, n);
    map<int, int> mex;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] != 1) {
            mex[1] = 1;
        }
        if (a[i] > 1 && query(1, 1, a[i] - 1) > last[a[i]]) {
            mex[a[i]] = 1;
        }
        update(1, a[i], i);
        last[a[i]] = i;
    }
    for (int i = 2; i <= n + 1; ++i) {
        if (query(1, 1, i - 1) > last[i]) {
            mex[i] = 1;
        }
    }
    for (int i = 1; i <= n + 2; ++i) {
        if (mex.find(i) == mex.end()) {
            cout << i << endl;
            return 0;
        }
    }
}
