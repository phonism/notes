#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

int dp[N][N][2];

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    a[0] = -1e9;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int m = (n + 1) / 2;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            dp[i][j][0] = dp[i][j][1] = 1e9;
        }
    }

    dp[0][0][0] = 0;
    dp[1][1][1] = 0;
    dp[1][0][0] = 0;
    for (int i = 2; i <= n; ++i) {
        dp[i][0][0] = 0;
        for (int j = 0; j <= m; ++j) {
            dp[i][j][0] = min(dp[i - 1][j][0], dp[i - 1][j][1] + max(a[i] - a[i - 1] + 1, 0));
            int tmp = dp[i - 2][j - 1][0] + max(a[i - 1] - a[i] + 1, 0);
            int tem = dp[i - 2][j - 1][1] + max(0, max(a[i - 1] - a[i - 2] + 1, a[i - 1] - a[i] + 1));
            dp[i][j][1] = min(tmp, tem);
        }
    }

    for (int i = 1; i <= m; ++i) {
        cout << min(dp[n][i][0], dp[n][i][1]) << endl;
    }
}
