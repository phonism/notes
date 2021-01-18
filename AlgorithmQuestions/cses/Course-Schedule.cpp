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
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		ans.push_back(u);
		for (auto v : edge[u]) {
			degree[v]--;
			if (degree[v] == 0) {
				q.push(v);
			}
		}
	}

	if (ans.size() < n) {
		cout << "IMPOSSIBLE" << endl;
	} else {
		for (auto u : ans) {
			cout << u << " ";
		}
		cout << endl;
	}
}
