#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 100;

vector<int> edge[N];
int st[N], ed[N], dep[N];
int pre[N];
int cnt = 0;
bool vis[N];

void dfs(int u, int p) {
	st[u] = ++cnt;
	for (auto v : edge[u]) {
		if (v != p) {
			pre[v] = u;
			dep[v] = dep[u] + 1;
			dfs(v, u);
		}
	}
	ed[u] = cnt;
}



struct SegNode {
	int l, r;
	int sum;
	int lazy;

	int len() {
		return r - l + 1;
	}
} tree[N * 4];

void push_up(int p) {
	tree[p].sum = tree[p * 2].sum + tree[p * 2 + 1].sum;
}

void push_down(int p) {
	if (tree[p].lazy) {
		tree[p * 2].lazy += tree[p].lazy;
		tree[p * 2 + 1].lazy += tree[p].lazy;
		tree[p * 2].sum += tree[p].lazy * tree[p * 2].len();
		tree[p * 2 + 1].sum += tree[p].lazy * tree[p * 2 + 1].len();
		tree[p].lazy = 0;
	}
}

void build(int p, int l, int r) {
	tree[p].l = l;
	tree[p].r = r;
	if (tree[p].l == tree[p].r) {
		tree[p].sum = 0;
		return ;
	}
	int mid = (tree[p].l + tree[p].r) / 2;
	build(p * 2, l, mid);
	build(p * 2 + 1, mid + 1, r);
	push_up(p);
}

void update(int p, int l, int r, int x) {
	if (l <= tree[p].l && tree[p].r <= r) {
		tree[p].lazy += x;
		tree[p].sum += x * tree[p].len();
		return ;
	}
	push_down(p);
	int mid = (tree[p].l + tree[p].r) / 2;
	if (l <= mid) {
		update(p * 2, l, r, x);
	}
	if (r > mid) {
		update(p * 2 + 1, l, r, x);
	}
	push_up(p);
}

int query(int p, int x) {
	if (tree[p].l == tree[p].r) {
		return tree[p].sum;
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

int query(int p, int l, int r) {
	if (l <= tree[p].l && tree[p].r <= r) {
		return tree[p].sum;
	}
	push_down(p);
	int mid = (tree[p].l + tree[p].r) / 2;
	int ans = 0;
	if (l <= mid) {
		ans += query(p * 2, l, r);
	}
	if (r > mid) {
		ans += query(p * 2 + 1, l, r);
	}
	return ans;
}


int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}

	dep[n] = 1;
	dfs(n, -1);

	build(1, 1, n);
	update(1, st[n], ed[n], 1);

	int tmp = 1;
	map<int, int> ans;
	k = n - k;
	ans[n] = 1;
	for (int i = n - 1; i >= 1; --i) {
		if (ans.count(i)) {
			continue;
		}
		// cout << dep[i] - query(1, st[i]) << endl;
		if (tmp + dep[i] - query(1, st[i]) > k) {
			continue;
		}

		int x = i;

		for (; x != n; x = pre[x]) {
			if (ans.count(x)) {
				break;
			}
			ans[x] = 1;
			update(1, st[x], ed[x], 1);
			tmp++;
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (!ans.count(i)) {
			cout << i << " ";
		}
	}
	cout << endl;
}
