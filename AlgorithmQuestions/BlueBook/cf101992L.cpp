/*
 * 题目链接：https://codeforces.com/gym/101992/problem/L
 * 题意：直角坐标系给一个y=x的直线，现在每次操作可以对某个点做以这个点的水平直线的镜面反射，以及查询某个点的y值
 * 题解：维护相邻两个点的差值，要么是1要么是-1，每次操作，相当于这个差值取反，每个点的y值相当于0到这个点的差值和。线段树维护即可
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
const int mxN = 1e6 + 2;

struct SegNode {
    int l, r;
    int sum;
    int op;
} tree[N * 4];

void pushup(int p) {
    tree[p].sum = tree[p * 2].sum + tree[p * 2 + 1].sum;
}

void pushdown(int p) {
    if (tree[p].op) {
        tree[p * 2].op = 1 - tree[p * 2].op;
        tree[p * 2].sum = tree[p * 2].sum * -1;
        tree[p * 2 + 1].op = 1 - tree[p * 2 + 1].op;
        tree[p * 2 + 1].sum = tree[p * 2 + 1].sum * -1;
    
        tree[p].op = 1 - tree[p].op;
    }
}

void build(int p, int l, int r) {
    tree[p].l = l;
    tree[p].r = r;
    tree[p].op = 0;
    if (tree[p].l == tree[p].r) {
        tree[p].op = 0;
        tree[p].sum = (l == 1 ? 0 : 1);
        return ;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    pushup(p);
}

void update(int p, int l, int r) {
    if (l <= tree[p].l && r >= tree[p].r) {
        tree[p].op = 1 - tree[p].op;
        tree[p].sum = tree[p].sum * -1;
        // cout << l << " " << r << " " << tree[p].sum << endl;
        return ;
    }
    pushdown(p);
    int mid = (tree[p].l + tree[p].r) / 2;
    if (l <= mid) {
        update(p * 2, l, r);
    } 
    if (r > mid) {
        update(p * 2 + 1, l, r);
    }
    pushup(p);
}

int query(int p, int l, int r) {
    if (l <= tree[p].l && r >= tree[p].r) {
        // cout << l << " " << r << " " << tree[p].sum << endl;
        return tree[p].sum;
    }
    pushdown(p);
    int mid = (tree[p].l + tree[p].r) / 2;
    int res = 0;
    if (l <= mid) {
        res += query(p * 2, l, r);
    }
    if (r > mid) {
        res += query(p * 2 + 1, l, r);
    }
    return res;
}

int main() {
    freopen("reflection.in", "r", stdin);
    int tests;
    scanf("%d", &tests);
    for (int t = 0; t < tests; ++t) {
        int n;
        scanf("%d", &n);
        build(1, 1, mxN);
        for (int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            printf("%d\n", query(1, 1, x + 1));
            update(1, x + 2, mxN);
        }
    }
    return 0;
}
