#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> edge[N];
int dep[N];

double ans = 0.0;

void dfs(int u, int p) {
    ans += 1.0 / dep[u];
    for (auto v : edge[u]) {
        if (v != p) {
            dep[v] = dep[u] + 1;
            dfs(v, u);
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dep[1] = 1;
    dfs(1, -1);
    printf("%.10f\n", ans);
}
