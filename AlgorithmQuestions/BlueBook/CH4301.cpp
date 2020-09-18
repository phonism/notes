/*
 * 题目链接：https://www.acwing.com/problem/content/246/
 * 题意：给出n个数，和m个操作，一个操作是问l到r区间最大的连续字段和是多少，另一个操作是单点修改。
 * 题解：使用线段数维护区间的sum，lmax，rmax，max。那么p.sum = l.sum + r.sum, p.lmax = max(l.lmax, l.sum + r.lmax),
 *       p.rmax = max(r.rmax, r.sum + l.rmax), p.max = max(max(l.max, r.max), l.rmax + r.lmax)。画一下线段树图，很容易理解
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 7;

int a[N];

struct SegNode {
    int l, r;
    int sum, max, lmax, rmax;
} tree[N * 4];

void build(int p, int l, int r) {
    tree[p].l = l;
    tree[p].r = r;

    if (l == r) {
        tree[p].sum = a[l];
        tree[p].max = a[l];
        tree[p].lmax = a[l];
        tree[p].rmax = a[l];
        return ;
    }
    int mid = (l + r) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    tree[p].sum = tree[p * 2].sum + tree[p * 2 + 1].sum;
    tree[p].lmax = max(tree[p * 2].lmax, tree[p * 2].sum + tree[p * 2 + 1].lmax);
    tree[p].rmax = max(tree[p * 2 + 1].rmax, tree[p * 2 + 1].sum + tree[p * 2].rmax);
    tree[p].max = max(tree[p * 2].max, tree[p * 2 + 1].max);
    tree[p].max = max(tree[p].max, tree[p * 2].rmax + tree[p * 2 + 1].lmax);
}

void update(int p, int x, int v) {
    if (tree[p].l == tree[p].r) {
        tree[p].sum = v;
        tree[p].max = v;
        tree[p].lmax = v;
        tree[p].rmax = v;
        return ;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    if (x <= mid) {
        update(p * 2, x, v);
    } else {
        update(p * 2 + 1, x, v);
    }
    tree[p].sum = tree[p * 2].sum + tree[p * 2 + 1].sum;
    tree[p].lmax = max(tree[p * 2].lmax, tree[p * 2].sum + tree[p * 2 + 1].lmax);
    tree[p].rmax = max(tree[p * 2 + 1].rmax, tree[p * 2 + 1].sum + tree[p * 2].rmax);
    tree[p].max = max(max(tree[p * 2].max, tree[p * 2 + 1].max), tree[p * 2].rmax + tree[p * 2 + 1].lmax);
}

SegNode query(int p, int l, int r) {
    if (l <= tree[p].l && r >= tree[p].r) {
        return tree[p];
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    SegNode lnode, rnode;
    if (r <= mid) {
        // lnode = query(p * 2, l, r);
        // return lnode;
        return query(p * 2, l, r);
    }
    if (l > mid) {
        // rnode = query(p * 2 + 1, l, r);
        // return rnode;
        return query(p * 2 + 1, l, r);
    }
    lnode = query(p * 2, l, r);
    rnode = query(p * 2 + 1, l, r);
    SegNode res;
    res.sum = lnode.sum + rnode.sum;
    res.lmax = max(lnode.lmax, lnode.sum + rnode.lmax);
    res.rmax = max(rnode.rmax, lnode.rmax + rnode.sum);
    res.max = max(max(lnode.max, rnode.max), lnode.rmax + rnode.lmax);
    return res;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i + 1]);
    }
    build(1, 1, n);
    for (int i = 0; i < m; ++i) {
        int k, x, y;
        scanf("%d %d %d", &k, &x, &y);
        if (k == 1) {
            if (x > y) {
                swap(x, y);
            }
            printf("%d\n", query(1, x, y).max);
        } else {
            update(1, x, y);
        }
    }
    return 0;
}
