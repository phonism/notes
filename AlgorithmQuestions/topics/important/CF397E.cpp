#include <bits/stdc++.h>
#pragma GCC optimize("-Ofast","-funroll-all-loops")
using namespace std;

const int N = 3e5 + 333;
const int MOD = 1e9 + 7;

int st[N], ed[N], id[N], dep[N];

struct SegNode {
	int l, r;
	long long x, k, v;
} tree[N * 4];

void push_down(int p) {
	if (tree[p].x || tree[p].k) {
		tree[p * 2].x = (tree[p].x + tree[p * 2].x) % MOD;
		tree[p * 2].k = (tree[p].k + tree[p * 2].k) % MOD;
		tree[p * 2 + 1].x = (tree[p].x + tree[p * 2 + 1].x) % MOD;
		tree[p * 2 + 1].k = (tree[p].k + tree[p * 2 + 1].k) % MOD;
		tree[p].x = tree[p].k = 0;
	}
}

void build(int p, int l, int r) {
	tree[p].l = l;
	tree[p].r = r;
	if (tree[p].l == tree[p].r) {
		tree[p].x = tree[p].k = tree[p].v = 0;
		return ;
	}
	int mid = (tree[p].l + tree[p].r) / 2;
	build(p * 2, l, mid);
	build(p * 2 + 1, mid + 1, r);
}

void update(int p, int l, int r, long long x, long long k) {
	if (l <= tree[p].l && tree[p].r <= r) {
		tree[p].x = (tree[p].x + x) % MOD;
		tree[p].k = (tree[p].k + k) % MOD;
		return ;
	}
	push_down(p);
	int mid = (tree[p].l + tree[p].r) / 2;
	if (l <= mid) {
		update(p * 2, l, r, x, k);
	}
	if (r > mid) {
		update(p * 2 + 1, l, r, x, k);
	}
}

long long query(int p, int x) {
	if (tree[p].l == tree[p].r) {
		return (tree[p].x - dep[id[x]] * tree[p].k % MOD + MOD) % MOD;
	}
	push_down(p);
	int mid = (tree[p].l + tree[p].r) / 2;
	if (x <= mid) {
		return query(p * 2, x);
	}
	if (x > mid) {
		return query(p * 2 + 1, x);
	}
	return -1;
}

int idx = 0;
vector<int> edge[N];

void dfs(int u, int p) {
	st[u] = ++idx;
	id[idx] = u;
	for (auto v : edge[u]) {
		if (v != p) {
			dep[v] = dep[u] + 1;
			dfs(v, u);
		}
	}
	ed[u] = idx;
}


int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		int x;
		cin >> x;
		edge[i].push_back(x);
		edge[x].push_back(i);
	}
	dep[1] = 1;
	dfs(1, -1);
	build(1, 1, idx);

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int op;
		cin >> op;
		if (op == 1) {
			long long v, x, k;
			cin >> v >> x >> k;
			update(1, st[v], ed[v], x + dep[v] * k, k);
		} else {
			int v;
			cin >> v;
			cout << query(1, st[v]) << endl;
		}
	}
}