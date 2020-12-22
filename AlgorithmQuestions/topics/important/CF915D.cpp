#include <bits/stdc++.h>
using namespace std;

const int N = 555;

vector<int> edge[N];
int cnt[N], cnt2[N];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		cnt[v]++;
	}

	bool ok = false;
	for (int i = 1; i <= n; ++i) {
		cnt[i]--;
		for (int j = 1; j <= n; ++j) {
			cnt2[j] = cnt[j];
		}
		queue<int> q;
		for (int j = 1; j <= n; ++j) {
			if (cnt2[j] == 0) {
				q.push(j);
			}
		}
		// cout << q.size() << endl;
		int num = 0;
		while (!q.empty()) {
			int u = q.front(); 	
			num++;
			q.pop();
			for (auto v : edge[u]) {
				cnt2[v]--;
				if (cnt2[v] == 0) {
					q.push(v); 
				}
			}
		}
		if (num == n) {
			ok = true;
			break;
		}
		cnt[i]++;
	}
	puts(ok ? "YES" : "NO");
}