#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 400100;
const int mod = 1000000007;

long long fac[maxn], ifac[maxn];

long long power(long long x, int n) {
    long long res = 1;
    for ( ; n; n >>= 1) {
        if (n & 1)
            res = res * x % mod;
        x = x * x % mod;
    }
    return res;
}

long long c(int n, int m) {
    return fac[n] * ifac[m] % mod * ifac[n-m] % mod;
}

void pre() {
    fac[0] = 1;
    ifac[0] = power(1, mod - 2);
    for (int i = 1; i < maxn; i++) {
        fac[i] = fac[i-1] * i % mod;
        ifac[i] = power(fac[i], mod - 2);
    }
}

pair<int, int> blk[2222];
long long dp[maxn];

int main() {
    pre();
    int h, w, n;
    scanf("%d %d %d", &h, &w, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &blk[i].first, &blk[i].second);
    }
    blk[n++] = make_pair(h, w);
    sort(blk, blk + n);
    for (int i = 0; i < n; i++) {
        dp[i] = c(blk[i].first + blk[i].second - 2, blk[i].first - 1);
        for (int j = 0; j < i; j++) {
            if (blk[j].second <= blk[i].second) {
                dp[i] = (dp[i] - dp[j] * c(blk[i].first + blk[i].second - blk[j].first - blk[j].second, blk[i].first - blk[j].first) % mod + mod) % mod;
            }
        }
    }
    printf("%lld\n", dp[n-1]);
    return 0;
}
