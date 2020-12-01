#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int color[N];
vector<int> edge[N];

int dis[N], d2[N];

void dfs(int u, int p) {
    for (auto v : edge[u]) {
        if (v != p) {
            dis[v] = dis[u] + 1;
            dfs(v, u);
        }
    }
}

int main() {
    int n, m, d;
    cin >> n >> m >> d;
    int t;
    for (int i = 1; i <= m; ++i) {
        cin >> t;
        color[t] = 1;
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    dfs(t, -1);

    int mx = -1, st = -1;
    for (int i = 1; i <= n; ++i) {
        if (dis[i] > mx && color[i]) {
            mx = dis[i];
            st = i;
        }
    }

    vector<int> d1(n + 1), d2(n + 1);
    dis[st] = 0;
    dfs(st, -1);
    mx = -1;
    int ed = -1;
    for (int i = 1; i <= n; ++i) {
        d1[i] = dis[i];
        if (dis[i] > mx && color[i]) {
            mx = dis[i];
            ed = i;
        }
    }

    dis[ed] = 0;
    dfs(ed, -1);
    for (int i = 1; i <= n; ++i) {
        d2[i] = dis[i];
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (d1[i] <= d && d2[i] <= d) {
            ans++;
        }
    }
    cout << ans << endl;
}
