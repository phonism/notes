/*
 * 基础题，dp[i][0]表示结尾是a的个数，dp[i][1]表示结尾是b的个数，那么s[i]=='a' => dp[i][0] = dp[i-1][0] + dp[i-1][1] + 1，s[i]=='b' => dp[i][1] = dp[i - 1][0]。
 */

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

long long dp[N][2];

int main() {
    string s;
    cin >> s;
    int n = s.length();
    dp[0][0] = s[0] == 'a' ? 1 : 0;
    for (int i = 1; i < n; ++i) {
        if (s[i] == 'a') {
            // cout << i << " " << dp[i - 1][0] << " " << dp[i - 1][1] << endl;
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + 1;
            dp[i][1] = dp[i - 1][1];
        } else if (s[i] == 'b') {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][0];
        } else {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1];
        }
        dp[i][0] %= MOD;
        dp[i][1] %= MOD;
    }
    cout << dp[n - 1][0] << endl;
}
