#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 7;
int n, q, a[N];
int s[N], e[N];
vector<int> adj[N];
char op[10];
 
int tot = 0;
void dfs(int u, int p) {
    s[u] = ++tot;
    for (auto v : adj[u]) {
        if (v == p) {
            continue;
        }
        dfs(v, u);
    }
    e[u] = tot;
}
 
struct SegNode {
    int l, r;
    int s0;
    int s1;
    bool mark;
} tree[N * 4];
 
void build(int p, int l, int r) {
    tree[p].l = l;
    tree[p].r = r;
    if (tree[p].l == tree[p].r) {
        if (a[l]) {
            tree[p].s1 = 1;
            tree[p].s0 = 0;
        } else {
            tree[p].s0 = 1;
            tree[p].s1 = 0;
        }
        return ;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    tree[p].s0 = tree[p * 2].s0 + tree[p * 2 + 1].s0;
    tree[p].s1 = tree[p * 2].s1 + tree[p * 2 + 1].s1;
}
 
void spread(int p) {
    if (tree[p].mark) {
        tree[p * 2].mark ^= 1;
        swap(tree[p * 2].s0, tree[p * 2].s1);
        tree[p * 2 + 1].mark ^= 1;
        swap(tree[p * 2 + 1].s0, tree[p * 2 + 1].s1);
        tree[p].mark = false;
    }
}
 
 
void update(int p, int l, int r) {
    // cout << p << " " << l << " " << r << endl;
    if (l <= tree[p].l && r >= tree[p].r) {
        tree[p].mark ^= 1;
        swap(tree[p].s0, tree[p].s1);
        return ;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    spread(p);
    if (l <= mid) {
        update(p * 2, l, r);
    }
    if (r > mid) {
        update(p * 2 + 1, l, r);
    }
    tree[p].s0 = tree[p * 2].s0 + tree[p * 2 + 1].s0;
    tree[p].s1 = tree[p * 2].s1 + tree[p * 2 + 1].s1;
}
 
int query(int p, int l, int r) {
    // cout << "QUERY: " << p << " " << l << " " << r << endl;
    if (l <= tree[p].l && r >= tree[p].r) {
        return tree[p].s1;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    spread(p);
    int sum = 0;
    if (l <= mid) {
        sum += query(p * 2, l, r);
    }
    if (r > mid) {
        sum += query(p * 2 + 1, l, r);
    }
    return sum;
}
 
int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; ++i) {
        int p;
        scanf("%d", &p);
        adj[p].push_back(i);
        adj[i].push_back(p);
    }
    dfs(1, -1);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[s[i]]);
    }
    build(1, 1, n);
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int x;
        scanf("%s %d", op, &x);
        if (op[0] == 'g') {
            printf("%d\n", query(1, s[x], e[x]));
        } else {
            update(1, s[x], e[x]);
        }
    }
}