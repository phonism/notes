#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 11;

vector<int> edge[N];
int vis[N], color[N];
bool ok = true;

int dfs(int u, int col) {
	color[u] = col;
	for (auto v : edge[u]) {
		if (vis[v]) {
			if (color[v] != 3 - col) {
				ok = false;
			}
			continue;
		}
		vis[v] = true;
		dfs(v, 3 - col);
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			dfs(i, 1);
		}
	}
	if (!ok) {
		cout << "IMPOSSIBLE" << endl;
	} else {
		for (int i = 1; i <= n; ++i) {
			if (i == 1) {
				cout << color[i];
			} else {
				cout << " " << color[i];
			}
		}
	}
	cout << endl;
}