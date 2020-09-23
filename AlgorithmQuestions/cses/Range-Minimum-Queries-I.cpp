/*
 * 题目链接：https://cses.fi/problemset/task/1647
 * 题意：n个点，q个查询，查询区间最小值
 * 题解：裸线段树
 */


#include <cstdio>
#include <iostream>
using namespace std;
 
const int N = 2e5 + 7;
 
int a[N];
 
struct SegNode {
    int l, r;
    int min;
} tree[N * 4];
 
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
 
int query(int p, int l, int r) {
    if (l <= tree[p].l && r >= tree[p].r) {
        return tree[p].min;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    int ans = 1e9 + 8;
    if (l <= mid) {
        ans = min(ans, query(p * 2, l, r));
    }
    if (r > mid) {
        ans = min(ans, query(p * 2 + 1, l, r));
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
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", query(1, l, r));
    }
    return 0;
 
}
