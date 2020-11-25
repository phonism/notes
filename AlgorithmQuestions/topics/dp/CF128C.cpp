#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
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

int main() {
    init();
    int n, m, k;
    cin >> n >> m >> k;
    cout << cab(n - 1, 2 * k) * cab(m - 1, 2 * k) % MOD << endl;
}
