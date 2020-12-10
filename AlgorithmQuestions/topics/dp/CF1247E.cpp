#include <bits/stdc++.h>
using namespace std;

const int N = 2222;
const int MOD = 1e9 + 7;

int a[N][N], r[N][N], d[N][N], pre[N][N][2], dp[N][N][2];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            a[i + 1][j + 1] = s[j] == '.' ? 1 : 0;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= 1; --j) {
            r[i][j] = r[i][j + 1] + a[i][j];
        }
    }

    for (int j = 1; j <= m; ++j) {
        for (int i = n; i >= 1; --i) {
            d[i][j] = d[i + 1][j] + a[i][j];
        }
    }

    if (a[n][m] == 0) {
        cout << 0 << endl;
        return 0;
    }

    dp[n][m][0] = dp[n][m][1] = 1;
    pre[n][m][0] = pre[n][m][1] = 1;

    for (int i = n; i >= 1; --i) {
        for (int j = m; j >= 1; --j) {
            if (i == n && j == m) {
                continue;
            }
            int delta = r[i][j + 1];
            dp[i][j][0] = (pre[i][j + 1][1] - pre[i][j + 1 + delta][1] + MOD) % MOD;
            delta = d[i + 1][j];
            dp[i][j][1] = (pre[i + 1][j][0] - pre[i + 1 + delta][j][0] + MOD) % MOD;

            pre[i][j][0] = (pre[i + 1][j][0] + dp[i][j][0]) % MOD;
            pre[i][j][1] = (pre[i][j + 1][1] + dp[i][j][1]) % MOD;
            // cout << i << " " << j << " " << pre[i][j][0] << endl;
        }
    }

    cout << (dp[1][1][0] + dp[1][1][1]) % MOD << endl;
}
