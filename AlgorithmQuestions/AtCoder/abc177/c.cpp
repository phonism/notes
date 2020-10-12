#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
const int MOD = 1e9 + 7;

int a[N];
long long sum[N];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = n; i >= 1; --i) {
        sum[i] = sum[i + 1] + a[i];
        sum[i] %= MOD;
    }

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += (a[i] * sum[i + 1]) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}
