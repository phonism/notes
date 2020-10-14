#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

struct SegNode {
    int l, r;
    int add;
    int sum;

    int len() {
        return r - l + 1;
    }
} tree[N * 4];

void pushup(int p) {
    tree[p].sum = tree[p * 2].sum + tree[p * 2 + 1].sum;
}

void pushdown(int p) {
    if (tree[p].add) {
        tree[p * 2].add += tree[p].add;
        tree[p * 2].sum = tree[p].add * tree[p * 2].len();
        tree[p * 2 + 1].add += tree[p].add;
        tree[p * 2 + 1].sum += tree[p].add * tree[p * 2 + 1].len();
        tree[p].add = 0;
    }
}

void build(int p, int l, int r) {
    tree[p].l = l;
    tree[p].r = r;
    if (tree[p].l == tree[p].r) {
        tree[p].add = 0;
        tree[p].sum = 0;
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
        tree[p].sum += v * tree[p].len();
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
        return tree[p].sum;
    }
    pushdown(p);
    int mid = (tree[p].l + tree[p].r) / 2;
    int ans = 0;
    if (l <= mid) {
        ans += query(p * 2, l, r);
    }
    if (r > mid) {
        ans += query(p * 2 + 1, l, r);
    }
    return ans;
}

vector<int> d[N];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        d[r - l + 1].push_back(l);
    }

    build(1, 1, m + 1);
    
    int cnt = n;
    for (int i = 1; i <= m; ++i) {
        int ans = cnt;
        for (int j = i; j <= m; j += i) {
            ans += query(1, 1, j);
        }
        for (auto it = d[i].begin(); it != d[i].end(); ++it) {
            update(1, *it, *it, 1);
            update(1, (*it) + i, (*it) + i, -1);
            cnt -= 1;
        }
        cout << ans << endl;
    }
}
