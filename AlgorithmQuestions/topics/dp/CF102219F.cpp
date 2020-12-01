#include <bits/stdc++.h>
using namespace std;

const int N = 2050;
const int MOD = 1e9 + 7;

long long dp[N][N];
int vis[N][N];

int main() {
    int n, e, k;
    cin >> n >> e >> k;
    for (int i = 0; i < k; ++i) {
        int u, v;
        cin >> u >> v;
        vis[u][v] = 1;
    }

    int state = 1 << (2 * e + 1);

    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int s = 0; s < state; ++s) {
            for (int diff = -e; diff <= e; ++diff) {
                int j = i + diff;
                if (j < 1 || j > n || vis[i][j]) {
                    continue;
                }
                if ((s >> 1) & (1 << (diff + e))) {
                    continue;
                }
                dp[i][(s >> 1) | (1 << (diff + e))] = (dp[i][(s >> 1) | (1 << (diff + e))] + dp[i - 1][s]) % MOD;
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < state; ++i) {
        ans = (ans + dp[n][i]) % MOD;
    }
    cout << ans << endl;
}
