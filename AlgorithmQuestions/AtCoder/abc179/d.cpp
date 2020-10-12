#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <bitset>
#include <vector>
using namespace std;
 
const int N = 2e5 + 5;
const int MOD = 998244353;
int l[N], r[N], a[N] = {0};
 
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
    tree[p].sum = (tree[p * 2].sum + tree[p * 2 + 1].sum) % MOD;
}
 
void update(int p, int x, int c) {
    if (tree[p].l == tree[p].r) {
        tree[p].sum = c;
        return ;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    if (x <= mid) {
        update(p * 2, x, c);
    } else {
        update(p * 2 + 1, x, c);
    }
    tree[p].sum = (tree[p * 2].sum + tree[p * 2 + 1].sum) % MOD;
}
 
long long query(int p, int l, int r) {
    if (l <= tree[p].l && r >= tree[p].r) {
        return tree[p].sum;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    long long sum = 0;
    if (l <= mid) {
        sum += query(p * 2, l, r);
        sum %= MOD;
    }
    if (r > mid) {
        sum += query(p * 2 + 1, l, r);
        sum %= MOD;
    }
    return sum;
}
 
bool judge(const pair<int, int> a, const pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}
 
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<pair<int, int> > seg;
    for (int i = 0; i < k; ++i) {
        scanf("%d %d", &l[i], &r[i]);
        seg.push_back(make_pair(l[i], r[i]));
    }
    sort(seg.begin(), seg.end(), judge);
 
    a[1] = 1;
    build(1, 1, n);
    for (int i = 2; i <= n; ++i) {
        long long tmp = 0;
        for (int j = 0; j < seg.size(); ++j) {
            if (seg[j].first >= i) {
                continue;
            }
            int ll = i - seg[j].second;
            int rr = i - seg[j].first;
            // printf("%d %d %d\n", i, ll, rr);
            tmp += query(1, ll, rr);
            tmp %= MOD;
        }
        update(1, i, tmp);
    }
    printf("%lld\n", query(1, n, n));
    return 0;
}
