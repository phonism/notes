#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int color[N];
vector<int> edge[N];
vector<int> vec[N];
int sz[N];
long long ans[N], res[N];
int cnt[N];

void get_size(int u, int p) {
    sz[u] = 1;
    for (auto v : edge[u]) {
        if (v != p) {
            get_size(v, u);
            sz[u] += sz[v];
        }
    }
}

int update(int mx, int u, int x) {
    ans[cnt[color[u]]] -= color[u];
    cnt[color[u]] += x;
    ans[cnt[color[u]]] += color[u];
    mx = max(mx, cnt[color[u]]);
    return mx;
}

int dfs(int u, int p, bool keep = 0) {
    int big = -1, mx_sz = 0;
    for (auto v : edge[u]) {
        if (v == p) {
            continue;
        }
        if (sz[v] > mx_sz) {
            mx_sz = sz[v];
            big = v;
        }
    }

    for (auto v : edge[u]) {
        if (v != p && v != big) {
            dfs(v, u, 0);
        }
    }

    int mx = 0;
    if (big != -1) {
        mx = max(mx, dfs(big, u, 1));
        swap(vec[u], vec[big]);
    }

    vec[u].push_back(u);
    mx = update(mx, u, 1);

    for (auto v : edge[u]) {
        if (v == p || v == big) {
            continue;
        }
        for (auto x : vec[v]) {
            mx = update(mx, x, 1);
            vec[u].push_back(x);
        }
    }

    res[u] = ans[mx];
    if (keep == 0) {
        for (auto v : vec[u]) {
            mx = update(mx, v, -1);
        }
    }
    return mx;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> color[i];
    }
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    get_size(1, -1);
    dfs(1, -1, 0);
    for (int i = 1; i <= n; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
}
































/*
int color[N];
int id[N];
int mx[N];
long long cnt[N];
long long ans[N];
vector<int> edge[N];
map<int, int> mp[N];

void merge(int u, int v) {
    if (mp[id[u]].size() < mp[id[v]].size()) {
        swap(id[u], id[v]);
    }

    u = id[u];
    v = id[v];

    for (auto it : mp[v]) {
        mp[u][it.first] += it.second;
        if (mp[u][it.first] > mx[u]) {
            mx[u] = mp[u][it.first];
            cnt[u] = 0;
        }
        if (mp[u][it.first] == mx[u]) {
            cnt[u] += it.first;
        }
    }
}

void dfs(int u, int p) {
    int mx = -1, big = -1;
    for (auto v : edge[u]) {
        if (v == p) {
            continue;
        }
        dfs(v, u);
        merge(u, v);
    }
    ans[u] = cnt[id[u]];
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> color[i];
        id[i] = i;
        mp[i][color[i]] = 1;
        mx[i] = 1;
        cnt[i] = color[i];
    }

    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    dfs(1, -1);

    for (int i = 1; i <= n; ++i) {
        if (i == 1) {
            cout << ans[i];
        } else {
            cout << " " << ans[i];
        }
    }
    cout << endl;

}
*/
