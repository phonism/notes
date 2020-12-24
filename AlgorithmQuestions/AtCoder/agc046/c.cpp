#include <bits/stdc++.h>
using namespace std;

const int N = 303;
const int MOD = 998244353;

int dp[N][N][N];

int main() {
    string s;
    int K;
    cin >> s >> K;

    vector<int> a;
    a.push_back(0);
    int pre = 0;
    for (int i = s.length() - 1; i >= 0; --i) {
        if (s[i] == '1') {
            pre++;
        } else {
            a.push_back(pre);
        }
    }
    a.push_back(pre);
    K = min(K, pre);

    int n = a.size();

    dp[0][0][0] = 1;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j <= a[i]; ++j) {
            for (int k = 0; k <= j; ++k) {
                if (dp[i][j][k] == 0) {
                    continue;
                }
                for (int l = 0; j + l <= a[i + 1]; ++l) {
                    int nk = k + max(0, l - (a[i + 1] - a[i]));
                    // cout << i << " " << j << " " << k << " " << l << " " << nk << " " << dp[i][j][k] << endl;
                    dp[i + 1][j + l][nk] = (dp[i + 1][j + l][nk] + dp[i][j][k]) % MOD;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= K; ++i) {
        ans += dp[n - 1][a[n - 1]][i];
        ans %= MOD;
    }
    cout << ans << endl;
}
