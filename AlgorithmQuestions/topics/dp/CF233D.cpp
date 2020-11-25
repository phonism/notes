#include <bits/stdc++.h>
using namespace std;

const int N = 111;
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

long long fast_pow(long long a, long long b) {
    long long ans = 1;
    for (; b; b >>= 1) {
        if (b & 1) {
            ans = ans * a % MOD;
        }
        a = a * a % MOD;
    }
    return ans;
}

long long dp[N][N * N] = {{0}}, c[N][N] = {{0}};

int main() {
    init();
    long long n, m, K;
    cin >> n >> m >> K;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            c[i][j] = fast_pow(cab(n, j), m / n + (m % n >= i));
        }
    }

    dp[0][0] = 1;
    for (long long i = 1; i <= n; ++i) {
        for (long long j = 0; j <= min(K, n * i); ++j) {
            for (long long k = 0; k <= min(j, n); ++k) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - k] * c[i][k] % MOD) % MOD;
            }
        }
    }
    cout << dp[n][K] << endl;
}
