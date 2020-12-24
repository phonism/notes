#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

/*
struct SegNode {
    int l, r;
    int diff;
} tree[N * 4];

void pushup(int p) {
    tree[p].diff = tree[p * 2].diff

void build(int p, int l, int r) {
    tree[p].l = l;
    tree[p].r = r;
    if (tree[p].l == tree[p].r) {
        tree[p].diff = 1;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    pushup(p);
}
*/

int a[N], b[N];

int main() {
    int h, w;
    cin >> h >> w;
    for (int i = 0; i < h; ++i) {
        cin >> a[i] >> b[i];
    }

    int cur = 1, k = 1, start;
    bool ok = true;
    vector<int> ans;
    int pre = 1e9;
    while (start < w) {
        int cur = start;
        for (int i = 0; i < k; ++i) {
            if (cur < a) {
            } else {
                cur = b + 1;
            }
        }
        if (cur > w) {
            ok = false;
            break;
        }
        if (cur < pre) {
            pre = cur;
            start += 1;
        } else {
            ans.push_back(
            k += 1;
            pre = 1e9;
        }
    }
}
