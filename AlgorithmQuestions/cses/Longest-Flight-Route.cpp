#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> degree(n + 1);
	vector<int> edge[n + 1];
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		degree[b]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		if (degree[i] == 0) {
			q.push(i);
		}
	}

	vector<int> ans;
	vector<int> dp(n + 1, -1e9);
	vector<int> pre(n + 1);
	dp[1] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto v : edge[u]) {
			degree[v]--;
			if (degree[v] == 0) {
				q.push(v);
			}

			if (dp[v] < dp[u] + 1) {
				dp[v] = dp[u] + 1;
				pre[v] = u;
			}
		}
	}

	int u = n;
	while (u != 1 && u != 0) {
		ans.push_back(u);
		u = pre[u];
	}
	ans.push_back(1);
	reverse(ans.begin(), ans.end());
	if (u == 0) {
		cout << "IMPOSSIBLE" << endl;
	} else {
		cout << ans.size() << endl;
		for (auto u : ans) {
			cout << u << " ";
		}
		cout << endl;
	}
}
