/*
 * 题目链接：https://codeforces.com/gym/101962/problem/I
 * 题意：给n个房屋，高度是h[]，第i个房屋可以去第i-1和第i+1个房屋，单点修改房屋高度，
 *       查询操作，输入i，h，问第i个房屋可以去那些房屋（满足相邻的房屋高度差小于h即可去)
 * 题解：线段树维护差分序列，对于查询操作其实就是问从i房屋向左向右序列一直小于等于h的个数。
 *       我们可以维护差分序列的区间最大值，然后二分查找向左向右扩展的距离。
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int n, q;
int a[N], d[N];

struct SegNode {
    int l, r;
    int v;
} tree[N * 4];

void build(int p, int l, int r) {
    tree[p].l = l;
    tree[p].r = r;

    if (l == r) {
        tree[p].v = d[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    tree[p].v = max(tree[p << 1].v, tree[p << 1 | 1].v);
}

void update(int p, int x, int v) {
    if (tree[p].l == tree[p].r) {
        tree[p].v = v;
        return ;
    }
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (x <= mid) {
        update(p << 1, x, v);
    } else {
        update(p << 1 | 1, x, v);
    }
    tree[p].v = max(tree[p << 1].v, tree[p << 1 | 1].v);
}

int query(int p, int l, int r) {
    if (l <= tree[p].l && r >= tree[p].r) {
        return tree[p].v;
    }

    int mid = (tree[p].l + tree[p].r) / 2;
    int val = -(1 << 30);
    if (l <= mid) {
        val = max(val, query(p * 2, l, r));
    }
    if (r > mid) {
        val = max(val, query(p * 2 + 1, l, r));
    }
    return val;
}

int abs(int x, int y) {
    if (x < y) {
        swap(x, y);
    }
    return x - y;
}

int solve(int x, int h) {
    int l = x + 1, r = n;
    int mid = 0, ans = 1, res = -1;
    while (l <= r) {
        mid = (l + r) / 2;
        int tmp = query(1, x + 1, mid);
        if (tmp <= h) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    if (res != -1) {
        ans += res - x;
    }

    l = 1, r = x;
    res = -1;
    while (l <= r) {
        mid = (l + r) / 2;
        int tmp = query(1, mid, x);
        if (tmp <= h) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    if (res != -1) {
        ans += x - (res - 1);
    }
    return ans;
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    a[0] = 1 << 30;
    for (int i = 1; i <= n; ++i) {
        d[i] = abs(a[i], a[i - 1]);
    }

    build(1, 1, n);

    for (int i = 0; i < q; ++i) {
        int op, x, h;
        scanf("%d %d %d", &op, &x, &h);
        if (op == 1) {
            a[x] = h;
            update(1, x, abs(a[x] - a[x - 1]));
            if (x + 1 <= n) {
                update(1, x + 1, abs(a[x + 1] - a[x]));
            }
        } else {
            printf("%d\n", solve(x, h));
        }
    }
}
