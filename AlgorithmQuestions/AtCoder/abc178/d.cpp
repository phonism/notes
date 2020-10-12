#include <bits/stdc++.h>
using namespace std;

const int N = 2222;
const int MOD = 1e9 + 7;

long long dp[N];

int main() {
    int s;
    cin >> s;

    for (int i = 3; i < N; ++i) {
        dp[i] = 1;
    }

    for (int i = 6; i <= s; ++i) {
        for (int j = 3; j <= i - 3; ++j) {
            dp[i] += dp[i - j];
            dp[i] %= MOD;
        }
    }
    cout << dp[s] << endl;

}
