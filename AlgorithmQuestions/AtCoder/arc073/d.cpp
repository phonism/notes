#include <bits/stdc++.h>
using namespace std;

const int N = 111;

long long dp[N][3 * N];

int main() {
    int n, W;
    cin >> n >> W;
    vector<long long> w(n + 1), v(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> v[i];
    }

    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; ++i) {
        for (int j = i; j >= 0; --j) {
            for (int k = 3 * j; k >= 0; --k) {
                if (j * w[1] + k + w[i] <= W) {
                    dp[j + 1][k + w[i] - w[1]] = max(dp[j + 1][k + w[i] - w[1]], dp[j][k] + v[i]);
                }
            }
        }
    }

    long long ans = -1;
    for (int j = 0; j <= n; ++j) {
        for (int k = 0; k <= 3 * n; ++k) {
            ans = max(ans, dp[j][k]);
        }
    }
    cout << ans << endl;

}
