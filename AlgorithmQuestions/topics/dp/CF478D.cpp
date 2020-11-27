#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 100;
const int MOD = 1e9 + 7;

long long dp[2][N] = {{0}};

int main() {
    int r, g;
    cin >> r >> g;
    int n = 0, tmp = 0;
    while (tmp + n + 1 <= r + g) {
        n++;
        tmp += n;
    }

    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= r; ++j) {
            dp[i & 1][j] = dp[(i - 1) & 1][j];
            if (j >= i) {
                dp[i & 1][j] = (dp[(i - 1) & 1][j] + dp[(i - 1) & 1][j - i]) % MOD;
            }
        }
    }

    long long ans = 0;
    for (int i = max(0, n * (n + 1) / 2 - g); i <= r; ++i) {
        ans = (ans + dp[n & 1][i]) % MOD;
    }
    cout << ans << endl;
}
