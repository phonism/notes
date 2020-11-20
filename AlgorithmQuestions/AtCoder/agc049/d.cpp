#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int LIM = 500;
const int MOD = 1e9 + 7;

int f[LIM][N] = {{0}}, g[LIM][N] = {{0}}, dp[LIM][N] = {{0}};

int main() {
    int n, m;
    cin >> n >> m;

    int lim = 1;
    while (lim * (lim + 1) / 2 <= m) {
        lim++;
    }

    dp[1][0] = f[1][0] = g[1][0] = 1;

    for (int i = 1; i <= lim; ++i) {
        int delta = i * (i - 1) / 2;
        for (int j = 0; j <= m; ++j) {
            if (j >= delta) {
                dp[i][j] = (dp[i - 1][j - delta] + dp[i][j - delta]) % MOD;
            }
            f[i][j] = dp[i][j];
        }

        for (int j = 0; j <= m; ++j) {
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            g[i][j] = dp[i][j];
            if (j >= n) {
                g[i][j] = (g[i][j] + g[i][j - n]) % MOD;
            }
        }
    }
    
    long long ans = 0;
    for (int i = 1; i <= min(n, lim); ++i) {
        int l = i, r = n + 1 - i;
        r = min(r, lim);
        for (int j = 0; j <= m; ++j) {
            ans = (ans + 1LL * f[l][j] * g[r][m - j] % MOD) % MOD;
        }
    }
    cout << ans << endl;

}
