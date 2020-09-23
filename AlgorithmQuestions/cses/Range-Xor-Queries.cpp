/*
 * 题目链接：https://cses.fi/problemset/task/1650
 * 题意：查询区间异或
 * 题解：因为异或满足区间可加性，直接线段树维护即可。
 */

#include <cstdio>
#include <iostream>
using namespace std;
 
const int N = 2e5 + 7;
 
int a[N];
 
struct SegNode {
    int l, r;
    long long x;
} tree[N * 4];
 
void build(int p, int l, int r) {
    tree[p].l = l;
    tree[p].r = r;
    if (tree[p].l == tree[p].r) {
        tree[p].x = a[l];
        return ;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    tree[p].x = tree[p * 2].x ^ tree[p * 2 + 1].x;
}
 
long long query(int p, int l, int r) {
    if (l <= tree[p].l && r >= tree[p].r) {
        return tree[p].x;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    long long ans = 0;
    if (l <= mid) {
        ans ^= query(p * 2, l, r);
    }
    if (r > mid) {
        ans ^= query(p * 2 + 1, l, r);
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
        printf("%lld\n", query(1, l, r));
        
    }
    return 0;
 
}
