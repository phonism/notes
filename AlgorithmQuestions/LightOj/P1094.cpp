#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

const int maxn = 30030;
vector<pair<int, int> > edge[maxn];
int dep[maxn];

int dfs(int u, int fa) {
	for (int i = 0; i < edge[u].size(); i++) {
		int v = edge[u][i].second;
		if (v == fa)
			continue;
		dep[v] = dep[u] + edge[u][i].first;
		dfs(v, u);
	}
}

int main() {
	int test; scanf("%d", &test);
	for (int cas = 1; cas <= test; cas++) {
		for (int i = 0; i < maxn; i++) {
			edge[i].clear();
		}
		int n; scanf("%d", &n);
		for (int i = 1; i < n; i++) {
			int u, v, w; scanf("%d %d %d", &u, &v, &w);
			u++; v++;
			edge[u].push_back(make_pair(w, v));
			edge[v].push_back(make_pair(w, u));
		}
		memset(dep, 0, sizeof(dep));
		dep[1] = 0;
		dfs(1, -1);
		int k = max_element(dep + 1, dep + n + 1) - dep;
		dep[k] = 0;
		dfs(k, -1);
		printf("Case %d: %d\n", cas, *max_element(dep + 1, dep + n + 1));
	}
}
