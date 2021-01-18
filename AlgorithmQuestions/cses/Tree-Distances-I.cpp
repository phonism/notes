#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 100;

vector<int> edge[N];
int d[N], dd[N];

void dfs(int u, int p) {
	for (auto v : edge[u]) {
		if (v != p) {
			d[v] = d[u] + 1;
			dfs(v, u);
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}

	d[0] = 0;
	dfs(1, -1);

	int st = -1, mx = -1;
	for (int i = 1; i <= n; ++i) {
		if (d[i] > mx) {
			mx = d[i];
			st = i;
		}
	}

	d[st] = 0;
	dfs(st, -1);

	mx = - 1;
	int ed = -1;
	for (int i = 1; i <= n; ++i) {
		dd[i] = d[i];
		if (d[i] > mx) {
			mx = d[i];
			ed = i;
		}
	}

	d[ed] = 0;
	dfs(ed, -1);

	for (int i = 1; i <= n; ++i) {
		cout << max(dd[i], d[i]) << endl;
	}
}