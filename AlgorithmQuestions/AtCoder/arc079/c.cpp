#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;

vector<int> adj[N];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool ok = false;
    for (auto u : adj[1]) {
        for (auto v : adj[u]) {
            if (v == n) {
                ok = true;
                break;
            }
        }
    }

    puts(ok ? "POSSIBLE" : "IMPOSSIBLE");

}
