#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 111;

vector<pair<int, int>> edge[N], edge_rev[N];


vector<long long> dij(int u, int flag) {
	vector<long long> d(N, 2e18);
	vector<int> vis(N, 0);

	priority_queue<pair<long long, int>> q;
	q.push(make_pair(0, u));
	d[u] = 0;
	while (!q.empty()) {
		int x = q.top().second;
		q.pop();
		if (vis[x]) {
			continue;
		}
		vis[x] = 1;
		if (flag) {
			for (auto y : edge[x]) {
				if (d[y.first] > d[x] + y.second) {
					d[y.first] = d[x] + y.second;
					q.push(make_pair(-d[y.first], y.first));
				}
			}
		} else {
			for (auto y : edge_rev[x]) {
				if (d[y.first] > d[x] + y.second) {
					d[y.first] = d[x] + y.second;
					q.push(make_pair(-d[y.first], y.first));
				}
			}
		}

	}
	return d;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		edge[x].push_back(make_pair(y, z));
		edge_rev[y].push_back(make_pair(x, z));
	}

	vector<long long> d1 = dij(1, true);
	vector<long long> d2 = dij(n, false);
	
	/*
	for (int i = 1; i <= n; ++i) {
		cout << d1[i] << " " << d2[i] << endl;
	}
	*/

	long long ans = 2e18;
	for (int u = 1; u <= n; ++u) {
		for (auto v : edge[u]) {
			ans = min(ans, d1[u] + v.second / 2 + d2[v.first]);
		}
	}
	cout << ans << endl;

}