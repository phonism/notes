#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
const int M = 1e6 + 10;
const int SIZE = 20;
const long long MOD = 998244353;

long long cnt[M] = {0}, inv[M] = {0}, ans[M] = {0};

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 10);
    int maxx = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
        maxx = max(maxx, a[i]);
    }

    inv[1] = 1;
    for (int i = 2; i <= maxx; ++i) {
        inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    }

    for (int i = maxx; i > 0; --i) {
        long long s1 = 0, s2 = 0;
        for (int j = i; j <= maxx; j += i) {
            s1 = (s1 + cnt[j] * j % MOD) % MOD;
            s2 = (s2 + cnt[j] * j % MOD * j % MOD) % MOD;
        }
        ans[i] = (s1 * s1 % MOD - s2 + MOD) % MOD;
        for (int j = i + i; j <= maxx; j += i) {
            ans[i] = (ans[i] - ans[j] + MOD) % MOD;
        }
    }

    long long answer = 0;
    for (int i = 1; i <= maxx; ++i) {
        answer = (answer + ans[i] * inv[i] % MOD) % MOD;
    }
    cout << answer * inv[2] % MOD << endl;
}
