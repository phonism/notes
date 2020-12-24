#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<vector<int>> g(N);
vector<int> h(N);
vector<int> vis(N, 0);

bool ok = true;

void dfs(int u, int p) {
    vis[u] = 1;
    for (int v : g[u]) {
        if (v == p) {
            continue;
        }
        if (vis[v]) {
            ok = false;
        } else {
            h[v] = h[u] + 1;
            dfs(v, u);
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < i; ++j) {
            if (s[j] == '1') {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            dfs(i, -1);
        }
    }

    if (ok) {
        cout << *max_element(h.begin(), h.end()) + 1 << endl;
    } else {
        cout << "-1" << endl;
    }
    return 0;
}
