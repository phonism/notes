#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 33;

int par[N];

int find(int x) {
	if (par[x] != x) {
		par[x] = find(par[x]);
	}
	return par[x];
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		par[i] = i;
	}
	for (int i = 0; i < m; ++i) {
		int u, v; 
		cin >> u >> v;
		int fu = find(u);
		int fv = find(v);
		if (fu != fv) {
			par[fu] = fv;
		}
	}

	int pre = -1;
	map<int, int> mp;
	vector<pair<int, int>> ans;
	for (int i = 1; i <= n; ++i) {
		int u = find(i);
		if (!mp.count(u)) {
			mp[u] = 1;
			if (pre != -1) {
				ans.push_back(make_pair(u, pre));
			}
			pre = u;
		}
	}

	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}
}
