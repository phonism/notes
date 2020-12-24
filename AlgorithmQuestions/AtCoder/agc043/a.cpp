#include <bits/stdc++.h>
using namespace std;

const int N = 111;
int a[N][N] = {0};
int dp[N][N];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == '#') {
                a[i+1][j+1] = 1;
            }
            dp[i+1][j+1] = 1e9;
            dp[i][j] = 1e9;
        }
    }

    dp[1][1] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i > 1) {
                dp[i][j] = min(dp[i][j], dp[i-1][j] + a[i][j]);
            }
            if (j > 1) {
                dp[i][j] = min(dp[i][j], dp[i][j-1] + a[i][j]);
            }
        }
    }
    cout << dp[n][n] << endl;
}

