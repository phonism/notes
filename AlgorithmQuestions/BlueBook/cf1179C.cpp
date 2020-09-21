/*
 * 题目链接：https://codeforces.com/contest/1179/problem/C
 * 题意：给出n个物品，每个物品价值a[i]，给出m个人，每个人有b[i]块钱，每个人只能买一个物品，每个物品只能被一个人买，
 *       从钱多的人开始买，每个人买物品的时候，会选择当前可以买的物品里价值最大的。问所有人都买过物品后，
 *       剩余价值最大的物品是多少。单点修改，可以修改某个物品的价值，或者某个人所有的钱。
 * 题解：因为所有的价值一共1e6，所以可以预处理出数组c，数组的下标表示价值，数组的值表示有i块钱的人-价值为i的物品个数，
 *       那么假设没有查询的话，就是从1e6开始枚举计算前向和，遇到第一个前项和<0的时候，
 *       说明那个价值的物品没法被买(拥有>=i块钱的人小于价值>=i的物品)。那么我们可以用线段树维护这个前项和，来完成修改和查询，
 *       原来的单点修改这里变成了区间修改。对于查询区间第一个<0的下标的方式是因为维护的是权值线段树，
 *       同时每个节点维护最小值就ok，如果当前线段最小值>=0，那么直接return不用继续找了，复杂度是O(logn)
 */

#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e6 + 7;
const int N = 1e6;

int n, m, _[mxN], __[mxN], a[mxN], s[mxN];

struct SegNode {
    int l, r;
    int min;
    int add;
} tree[mxN * 4];

void up(int p) {
    tree[p].min = min(tree[p * 2].min, tree[p * 2 + 1].min);
}

void down(int p) {
    if (tree[p].add) {
        tree[p * 2].add += tree[p].add;
        tree[p * 2].min += tree[p].add;
        tree[p * 2 + 1].add += tree[p].add;
        tree[p * 2 + 1].min += tree[p].add;
        tree[p].add = 0;
    }
}

void build(int p, int l, int r) {
    tree[p].l = l;
    tree[p].r = r;
    if (tree[p].l == tree[p].r) {
        tree[p].min = s[l];
        return ;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    up(p);
}

void update(int p, int l, int r, int v) {
    if (l <= tree[p].l && r >= tree[p].r) {
        tree[p].min += v;
        tree[p].add += v;
        return ;
    }
    down(p);
    int mid = (tree[p].l + tree[p].r) / 2;
    if (l <= mid) {
        update(p * 2, l, r, v);
    }
    if (r > mid) {
        update(p * 2 + 1, l, r, v);
    }
    up(p);
}

int query(int p, int l, int r) {
    if (tree[p].l == tree[p].r) {
        if (tree[p].min <= -1) {
            return tree[p].l;
        } else {
            return -1;
        }
    }
    if (l <= tree[p].l && r >= tree[p].r) {
        if (tree[p].min > -1) {
            return -1;
        }
    }
    down(p);
    int mid = (tree[p].l + tree[p].r) / 2;
    if (r <= mid) {
        return query(p * 2, l, r);
    }
    if (l > mid) {
        return query(p * 2 + 1, l, r);
    }
    int res = query(p * 2, l, r);
    if (res != -1) {
        return res;
    }
    return query(p * 2 + 1, l, r);
}


int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &_[i]);
        a[_[i]] -= 1;
    }
    for (int i = 1; i <= m; ++i) {
        int x;
        scanf("%d", &__[i]);
        a[__[i]] += 1;
    }
    s[1] = a[N];
    for (int i = N - 1; i >= 1; i--) {
        s[N - i + 1] = s[N - i] + a[i];
    }
    build(1, 1, N);
    int q;
    scanf("%d", &q);
    for (int t = 0; t < q; ++t) {
        int op, x, y;
        scanf("%d %d %d", &op, &x, &y);
        if (op == 1) {
            update(1, N - _[x] + 1, N, 1);
            update(1, N - y + 1, N, -1);
            _[x] = y;
            int res = query(1, 1, N);
            if (res == -1) {
                puts("-1");
            } else {
                printf("%d\n", N - res + 1);
            }
        } else {
            update(1, N - __[x] + 1, N, -1);
            update(1, N - y + 1, N, 1);
            __[x] = y;
            int res = query(1, 1, N);
            if (res == -1) {
                puts("-1");
            } else {
                printf("%d\n", N - res + 1);
            }
        }
    }
    return 0;
}
