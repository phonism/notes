/*
 * 题目链接：https://cses.fi/problemset/task/1648
 * 题意：带修改的区间和
 * 题解：裸线段树
 */

#include <cstdio>
#include <iostream>
using namespace std;
 
const int N = 2e5 + 7;
 
int a[N];
 
struct SegNode {
    int l, r;
    long long sum;
} tree[N * 4];
 
 
void build(int p, int l, int r) {
    tree[p].l = l;
    tree[p].r = r;
    if (tree[p].l == tree[p].r) {
        tree[p].sum = a[l];
        return ;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    tree[p].sum = tree[p * 2].sum + tree[p * 2 + 1].sum;
}
 
void update(int p, int x, int v) {
    if (tree[p].l == tree[p].r) {
        tree[p].sum = v;
        return ;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    if (x <= mid) {
        update(p * 2, x, v);
    } else {
        update(p * 2 + 1, x, v);
    }
    tree[p].sum = tree[p * 2].sum + tree[p * 2 + 1].sum;
}
 
long long query(int p, int l, int r) {
    if (l <= tree[p].l && r >= tree[p].r) {
        return tree[p].sum;
    }
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
        int op, l, r;
        scanf("%d %d %d", &op, &l, &r);
        if (op == 1) {
            update(1, l, r);
        } else {
            printf("%lld\n", query(1, l, r));
        }
    }
    return 0;
 
}
