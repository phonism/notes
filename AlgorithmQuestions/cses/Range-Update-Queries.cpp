/*
 * 题目链接：https://cses.fi/problemset/task/1651
 * 题意：区间更新
 * 题解：lazy更新的线段树
 */

#include <cstdio>
#include <iostream>
using namespace std;
 
const int N = 2e5 + 7;
 
int a[N];
 
struct SegNode {
    int l, r;
    long long sum;
    long long add;
} tree[N * 4];
 
void pushup(int p) {
    tree[p].sum = tree[p * 2].sum + tree[p * 2 + 1].sum;
}
 
void pushdown(int p) {
    if (tree[p].add) {
        tree[p * 2].add += tree[p].add;
        tree[p * 2].sum += tree[p].add * (tree[p * 2].r - tree[p * 2].l + 1);
        tree[p * 2 + 1].add += tree[p].add;
        tree[p * 2 + 1].sum += tree[p].add * (tree[p * 2 + 1].r - tree[p * 2 + 1].l + 1);
        tree[p].add = 0;
    }
}
 
void build(int p, int l, int r) {
    tree[p].l = l;
    tree[p].r = r;
    tree[p].add = 0;
    if (tree[p].l == tree[p].r) {
        tree[p].sum = a[l];
        return ;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    pushup(p);
}
 
void update(int p, int l, int r, long long v) {
    if (l <= tree[p].l && r >= tree[p].r) {
        tree[p].add += v;
        tree[p].sum += v * (tree[p].r - tree[p].l + 1);
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
 
long long query(int p, int l, int r) {
    if (l <= tree[p].l && r >= tree[p].r) {
        return tree[p].sum;
    }
    pushdown(p);
    int mid = (tree[p].l + tree[p].r) / 2;
    long long ans = 0;
    if (l <= mid) {
        ans += query(p * 2, l, r);
    }
    if (r > mid) {
        ans += query(p * 2 + 1, l, r);
    }
    return ans;
}
 
int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    build(1, 1, n);
    for (int i = 1; i <= q; ++i) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int l, r;
            long long v;
            scanf("%d %d %lld", &l, &r, &v);
            update(1, l, r, v);
        } else {
            int x;
            scanf("%d", &x);
            printf("%lld\n", query(1, x, x));
        }
    }
}
