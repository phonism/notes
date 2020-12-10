#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 111;
const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> pow(n + 1);
    pow[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pow[i] = pow[i - 1] * 2 % MOD;
    }
    vector<int> a(N);
    vector<int> f(N);
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        a[x]++;
    }
    long long ans = 0;
    for (int i = N - 1; i > 1; --i) {
        int sum = 0;
        for (int j = i; j < N; j += i) {
            sum += a[j];
        }
        if (sum) {
            f[i] = 1LL * sum * pow[sum - 1] % MOD;
            for (int j = i + i; j < N; j += i) {
                f[i] = (f[i] - f[j] + MOD) % MOD;
            }
            ans = (ans + 1LL * f[i] * i) % MOD;
        }
    }
    cout << ans << endl;
}
