#include <bits/stdc++.h>
using namespace std;

const int N = 333;

int a[N];
vector<int> edge[N];
int dp[N][N];
int n, m;

void dfs(int u, int p) {
    dp[u][0] = 0;
    for (int v : edge[u]) {
        if (v == p) {
            continue;
        }
        dfs(v, u);
        for (int i = m; i >= 0; --i) {
            for (int j = i; j >= 0; --j) {
                if (i - j >= 0) {
                    dp[u][i] = max(dp[u][i], dp[u][i - j] + dp[v][j]);
                }
            }
        }
    }
    if (u != 0) {
        for (int i = m; i > 0; --i) {
            dp[u][i] = dp[u][i - 1] + a[u];
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int s, k;
        cin >> s >> a[i];
        edge[i].push_back(s);
        edge[s].push_back(i);
    }
    dfs(0, -1);
    cout << dp[0][m] << endl;
}
