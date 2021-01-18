#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

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

	vector<long long> dp(n + 1, 0);
	dp[1] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto v : edge[u]) {
			degree[v]--;
			if (degree[v] == 0) {
				q.push(v);
			}
			dp[v] += dp[u];
			dp[v] %= MOD;
		}
	}

	cout << dp[n] << endl;
}
