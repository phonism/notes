#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 222;

int color[N], dis[N];
bool vis[N];
vector<int> edge[N];

void dfs(int u, int p) {
    vis[u] = true;
    for (auto v : edge[u]) {
        if (v != p && !vis[v]) {
            if (color[v] == color[u]) {
                dis[v] = dis[u];
                dfs(v, u);
            } else {
                dis[v] = dis[u] + 1;
                dfs(v, u);
            }
        }
    }
}


int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> color[i];
    }

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    dis[1] = 0;
    dfs(1, -1);
    
    int mx = -1, st = -1;
    for (int i = 1; i <= n; ++i) {
        if (dis[i] > mx) {
            mx = dis[i];
            st = i;
        }
    }

    dis[st] = 0;
    memset(vis, 0, sizeof(vis));
    dfs(st, -1);
    for (int i = 1; i <= n; ++i) {
        mx = max(mx, dis[i]);
    }
    cout << (mx + 1) / 2 << endl;
}
