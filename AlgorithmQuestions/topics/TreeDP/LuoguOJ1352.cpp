#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 100;

int a[N];
vector<int> edge[N];

int dp[N][2];

void dfs(int u, int p) {
    dp[u][0] = 0;
    dp[u][1] = a[u];
    for (int v : edge[u]) {
        if (v == p) {
            continue;
        }
        dfs(v, u);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    dfs(1, -1);

    cout << max(dp[1][0], dp[1][1]) << endl;
}
