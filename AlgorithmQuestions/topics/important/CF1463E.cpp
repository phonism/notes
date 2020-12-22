#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 111;

int p[N];
int in[N], to[N];
bool vis[N];
vector<vector<int>> chain;
int id[N], rnk[N], degree[N];
vector<int> edge[N];

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
	}

	for (int i = 0; i < k; ++i) {
		int x, y;
		cin >> x >> y;
		in[y] = x;
		to[x] = y;
	}

	bool ok = true;

	for (int i = 1; i <= n; ++i) {
		if (in[i]) {
			continue;
		}
		if (to[i]) {
			if (vis[i]) {
				continue;
			}
			int x = i;
			vis[x] = true;
			vector<int> c = {x};
			while (to[x]) {
				if (vis[to[x]]) {
					ok = false;
					break;
				}
				c.push_back(to[x]);
				vis[to[x]] = true;
				x = to[x];
			}
			for (int i = 0; i < c.size(); ++i) {
				int u = c[i];
				id[u] = chain.size();
				rnk[u] = i + 1;
			}
			chain.push_back(c);
		} else {
			vector<int> c = {i};
			id[i] = chain.size();
			chain.push_back(c);
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (p[i] == 0) {
			continue;
		}

		edge[p[i]].push_back(i);
		if (id[i] != id[p[i]]) {
			degree[id[i]]++;
		}
		if (id[i] == id[p[i]] && rnk[i] < rnk[p[i]]) {
			ok = false;
			break;
		}
	}

	if (!ok) {
		cout << 0 << endl;
		return 0;
	}

	queue<int> q;
	for (int i = 0; i < chain.size(); ++i) {
		if (degree[i] == 0) {
			q.push(i);
		}
	}
	vector<int> ans;


/*
	for (int i = 0; i < chain.size(); ++i) {
		for (auto u : chain[i]) {
			cout << u << " ";
		}
		cout << endl;
	}

	for (int i = 1; i <= n; ++i) {
		cout << degree[id[i]] << " ";
	}
	cout << endl;
	*/

	while (!q.empty()) {
		int cid = q.front();
		q.pop();
		for (auto u : chain[cid]) {
			ans.push_back(u);
			for (auto v : edge[u]) {
				if (id[v] == id[u]) {
					continue;
				}
				degree[id[v]]--;
				if (degree[id[v]] == 0) {
					q.push(id[v]);
				}
			}
		}
	}


	if (ans.size() < n) {
		cout << 0 << endl;
	} else {
		for (auto u : ans) {
			cout << u << " ";
		}
		cout << endl;
	}
}