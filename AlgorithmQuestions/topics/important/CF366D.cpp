#include <bits/stdc++.h>
using namespace std;

const int N = 1111;

struct Node {
	int v, l, r;

	Node(int _v, int _l, int _r) {
		v = _v, l = _l, r = _r;
	}

};

vector<Node> edge[N];
pair<int, int> lst[N];

bool vis[N];

int n, m;

int ans = 0;

void dfs(int u, int p, pair<int, int> res) {
	if (u == n) {
		ans = max(ans, res.second - res.first + 1);
		return ;
	}

	for (auto v : edge[u]) {
		if (vis[v.v]) {
			continue;
		}
		int l = max(res.first, v.l);
		int r = min(res.second, v.r);
		int d = r - l + 1;
		if (d < ans) {
			continue;
		}
		if (l >= lst[v.v].first && lst[v.v].second >= r) {
			continue;
		}
		lst[v.v].first = l;
		lst[v.v].second = r;
		vis[v.v] = true;
		pair<int, int> tmp_res = make_pair(l, r);
		dfs(v.v, u, tmp_res);
		vis[v.v] = false;
	}
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b, l, r;
		cin >> a >> b >> l >> r;
		edge[a].push_back(Node(b, l, r));
		edge[b].push_back(Node(a, l, r));
	}
	pair<int, int> res = make_pair(-1, 1e9);
	dfs(1, -1, res);

	if (ans > 0) {
		cout << ans << endl;
	} else {
		cout << "Nice work, Dima!" << endl;
	}
}