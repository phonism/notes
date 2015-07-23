#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 100100;

struct SegNode {
    int left, right;
    int sum, lazy;

    int mid() {
        return (left + right) >> 1;
    }

    int len() {
        return (right - left + 1);
    }
};

struct SegTree {
    SegNode tree[maxn*4];

    void pushUp(int idx) {
        tree[idx].sum = tree[idx<<1].sum + tree[idx<<1|1].sum;
    }

    void pushDown(int idx) {
        if (tree[idx].lazy != -1) {
            tree[idx<<1].lazy = tree[idx<<1|1].lazy = tree[idx].lazy;
            tree[idx<<1].sum = tree[idx<<1].len() * tree[idx].lazy;
            tree[idx<<1|1].sum = tree[idx<<1|1].len() * tree[idx].lazy;
            tree[idx].lazy = -1;
        }
    }

    void build(int left, int right, int idx) {
        tree[idx].left = left;
        tree[idx].right = right;
        tree[idx].sum = 0;
        tree[idx].lazy = -1;
        if (left == right) {
            return ;
        }
        int mid = tree[idx].mid();
        build(left, mid, idx<<1);
        build(mid+1, right, idx<<1|1);
    }

    void update(int left, int right, int idx, int val) {
        if (tree[idx].left == left && tree[idx].right == right) {
            tree[idx].lazy = val;
            tree[idx].sum = val * tree[idx].len();
            return ;
        }
        pushDown(idx);
        int mid = tree[idx].mid();
        if (right <= mid)
            update(left, right, idx<<1, val);
        else if (left > mid)
            update(left, right, idx<<1|1, val);
        else {
            update(left, mid, idx<<1, val);
            update(mid+1, right, idx<<1|1, val);
        }
        pushUp(idx);
    }

    int query(int left, int right, int idx) {
        if (tree[idx].left == left && tree[idx].right == right) {
            return tree[idx].sum;
        }
        pushDown(idx);
        int mid = tree[idx].mid();
        if (right <= mid)
            return query(left, right, idx<<1);
        else if (left > mid)
            return query(left, right, idx<<1|1);
        else
            return query(left, mid, idx<<1) + query(mid+1, right, idx<<1|1);
    }

};

SegTree seg[26];

int n, q, l, r, op;
char str[maxn];
int num[maxn];

void init() {
    scanf("%d %d", &n, &q);
    for (int i = 0 ; i < 26; i++) {
        seg[i].build(1, n, 1);
    }
    scanf("%s", str+1);
    for (int i = 1; i <= n; i++) {
        seg[str[i]-'a'].update(i, i, 1, 1);
    }

    // printf("FUCK %d\n", seg[0].query(1, n, 1));
    for (int i = 1; i <= q; i++) {
        scanf("%d %d %d", &l, &r, &op);
        for (int j = 0; j < 26; j++) {
            num[j] = seg[j].query(l, r, 1);
            seg[j].update(l, r, 1, 0);
        }
        if (op == 1) {
            int idx = l;
            for (int j = 0; j < 26; j++) {
                if (num[j] > 0) {
                    seg[j].update(idx, idx+num[j]-1, 1, 1);
                    idx += num[j];
                }
            }
        } else {
            int idx = l;
            for (int j = 25; j >= 0; j--) {
                if (num[j] > 0) {
                    seg[j].update(idx, idx+num[j]-1, 1, 1);
                    idx += num[j];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            if (seg[j].query(i, i, 1)) {
                printf("%c", ('a' + j));
                break;
            }
        }
    }
    puts("");
}

int main() {
    init();
    return 0;
}
