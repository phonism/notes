#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 3e5;

vector<int> edge[N];
bool color[N];

void dfs_tree(int u, int p) {
    bool flag = color[u];
    for (auto v : edge[u]) {
        if (v == p) {
            continue;
        }
        dfs_tree(v, u);
        // cout << v << " " << color[v] << endl;
        flag = flag | color[v];
    }
    color[u] = flag;
}

int dis[N];

void dfs(int u, int p) {
    for (auto v : edge[u]) {
        if (v != p && color[v] && dis[v] == -1) {
            dis[v] = dis[u] + 1;
            dfs(v, u);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    int u;
    for (int i = 0; i < m; ++i) {
        cin >> u;
        color[u] = 1;
    }
    dfs_tree(u, -1);

    memset(dis, -1, sizeof(dis));
    dis[u] = 0;
    dfs(u, -1);

    int mx = -1, start = -1;
    for (int i = 1; i <= n; ++i) {
        if (dis[i] > mx) {
            mx = dis[i];
            start = i;
        }
    }

    memset(dis, -1, sizeof(dis));

    dis[start] = 0;
    dfs(start, -1);

    mx = -1;
    int ans = 0, end = -1;
    for (int i = 1; i <= n; ++i) {
        // cout << color[i] << " " << dis[i] << endl;
        ans += color[i];
        if (dis[i] > mx) {
            mx = max(dis[i], mx);
            end = i;
        }
    }

    ans = (ans - 1) * 2 - mx;
    cout << min(start, end) << endl;
    cout << ans << endl;
}
