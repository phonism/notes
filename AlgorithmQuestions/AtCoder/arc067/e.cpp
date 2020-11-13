#include <bits/stdc++.h>
using namespace std;

const int N = 1111;
const int MOD = 1e9 + 7;

long long fac[N], inv[N], finv[N];

void init() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < N; ++i) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long cab(int a, int b) {
    if (a < b) {
        return 0;
    }
    return fac[a] * (finv[b] * finv[a - b] % MOD) % MOD;
}

long long pow(long long a, int b) {
    long long ans = 1;
    for (; b; b >>= 1) {
        if (b & 1) {
            ans = ans * a % MOD;
        }
        a = a * a % MOD;
    }
    return ans;
}

long long dp[N][N];

int main() {
    init();
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    for (int i = 0; i <= b; ++i) {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = a; j <= b; ++j) {
            dp[i][j] = dp[i][j - 1];
            for (int k = c; k <= d; ++k) {
                if (i - j * k < 0) {
                    break;
                }
                long long tmp = dp[i - j * k][j - 1] * cab(n - i + j * k, j * k) % MOD;
                tmp = tmp * fac[j * k] % MOD * finv[k] % MOD * pow(finv[j], k) % MOD;
                dp[i][j] = (dp[i][j] + tmp) % MOD;
            }
        }
    }
    cout << dp[n][b] << endl;
}
