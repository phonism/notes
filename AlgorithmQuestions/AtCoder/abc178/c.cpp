#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
const int MOD = 1e9 + 7;

long long dp[N][4];

int main() {
    int n;
    cin >> n;
    dp[1][0] = 8;
    dp[1][1] = 1;
    dp[1][2] = 1;
    dp[1][3] = 0;
    for (int i = 2; i <= n; ++i) {
        dp[i][0] = dp[i - 1][0] * 8;
        dp[i][1] = dp[i - 1][1] * 9 + dp[i - 1][0];
        dp[i][2] = dp[i - 1][2] * 9 + dp[i - 1][0];
        dp[i][3] = dp[i - 1][3] * 10 + dp[i - 1][1] + dp[i - 1][2];
        for (int j = 0; j < 4; ++j) {
            dp[i][j] %= MOD;
        }
    }
    cout << dp[n][3] << endl;
}
