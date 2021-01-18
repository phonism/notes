#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 111;

vector<int> edge[N];

bool vis[N];
int d[N], pre[N];

void dij(int u) {
	memset(d, 0x3f3f3f3f, sizeof(d));
	priority_queue<pair<int, int>> q;
	q.push(make_pair(0, u));
	d[u] = 0;
	while (!q.empty()) {
		int x = q.top().second;
		q.pop();
		if (vis[x]) {
			continue;
		}
		vis[x] = true;
		for (auto y : edge[x]) {
			if (d[y] > d[x] + 1) {
				d[y] = d[x] + 1;
				pre[y] = x;
				q.push(make_pair(-d[y], y));
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	dij(1);
	if (d[n] > n) {
		cout << "IMPOSSIBLE" << endl;
	} else {
		cout << d[n] + 1 << endl;
		int u = n;
		vector<int> ans;
		while (u != 1) {
			ans.push_back(u);
			u = pre[u];
		}
		ans.push_back(1);
		reverse(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); ++i) {
			if (i == 0) {
				cout << ans[i];
			} else {
				cout << " " << ans[i];
			}
		}
		cout << endl;
	}
}