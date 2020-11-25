#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int MOD = 1e9 + 7;

int sum[N];

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

int solve(int x) {
    vector<int> frac;
    for (int i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            frac.push_back(i);
            if (i * i != x) {
                frac.push_back(x / i);
            }
        }
    }
    frac.push_back(N - 1);
    sort(frac.begin(), frac.end());

    long long res = 1;
    for (int i = 0; i + 1 < frac.size(); ++i) {
        res = res * fast_pow(i + 1, sum[frac[i + 1] - 1] - sum[frac[i] - 1]) % MOD;
    }

    long long diff = 1;
    frac[frac.size() - 2] = N - 1;
    for (int i = 0; i + 2 < frac.size(); ++i) {
        diff = diff * fast_pow(i + 1, sum[frac[i + 1] - 1] - sum[frac[i] - 1]) % MOD;
    }
    return (res - diff + MOD) % MOD;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum[a[i]]++;
    }

    for (int i = 1; i < N; ++i) {
        sum[i] += sum[i - 1];
    }

    long long ans = 1;
    for (int i = 2; i < N; ++i) {
        ans = (ans + solve(i)) % MOD;
    }
    cout << ans << endl;

}
