#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <bitset>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;

const int N = 3e3 + 3;
const int MOD = 998244353;

long long dp[N][N];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    dp[a][b] = 1;
    for (int i = a; i <= c; ++i) {
        for (int j = b; j <= d; ++j) {
            if (i == a && j == b) {
                continue;
            }
            if (i == a) {
                dp[i][j] = dp[i][j - 1] * i % MOD;
            } else if (j == b) {
                dp[i][j] = dp[i - 1][j] * j % MOD;
            } else {
                dp[i][j] = (dp[i - 1][j] * j % MOD + dp[i][j - 1] * i % MOD) % MOD;
                dp[i][j] = (dp[i][j] + MOD - (dp[i - 1][j - 1] * (i - 1) % MOD * (j - 1) % MOD)) % MOD;
            }
        }
    }
    cout << dp[c][d] << endl;
}
