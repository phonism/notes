#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 100;

struct SegNode {
    int l, r;
    long long sum;
} tree[N * 4];
 
void build(int p, int l, int r) {
    tree[p].l = l;
    tree[p].r = r;
    if (tree[p].l == tree[p].r) {
        tree[p].sum = 1;
        return ;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    tree[p].sum = tree[p * 2].sum + tree[p * 2 + 1].sum;
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
    tree[p].sum = tree[p * 2].sum + tree[p * 2 + 1].sum;
}
 
long long query(int p, int l, int r) {
    if (l <= tree[p].l && r >= tree[p].r) {
        return tree[p].sum;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    long long sum = 0;
    if (l <= mid) {
        sum += query(p * 2, l, r);
    }
    if (r > mid) {
        sum += query(p * 2 + 1, l, r);
    }
    return sum;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<set<int>> pos(26);
    for (int i = 0; i < n; ++i) {
        pos[s[i] - 'a'].insert(i + 1);
    }
    build(1, 1, n);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int need = s[n - i - 1] - 'a';
        int p = *pos[need].begin();
        update(1, p, 0);
        ans += query(1, 1, p);
        pos[need].erase(pos[need].begin());
    }
    cout << ans << endl;
}
