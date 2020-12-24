#include <bits/stdc++.h>
using namespace std;

const int N = 17;

int x[N], y[N], z[N];

int dp[1<<N][N];

int n;

int f(int i, int j) {
    return abs(x[i] - x[j]) + abs(y[i] - y[j]) + max(0, z[j] - z[i]);
}

int solve(int s, int e) {
    int res = 1e9;
    for (int i = 0; i < n; ++i) {
        if (s >> i & 1) {
            res = min(res, f(i, e));
        }
    }
    return res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> z[i];
    }

    for (int i = 0; i < 1 << n; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j] = 1e9;
        }
    }
    dp[0][0] = 0;
    dp[1][0] = 0;
    /*
    int cnt = 0;
    while (cnt < 2) {
        for (int s = 0; s < 1 << n; ++s) {
            for (int i = 0; i < n; ++i) {
                if (s >> i & 1) {
                    // cout << s << " " << (s ^ (1 << i)) << " " << i << endl;
                    for (int j = 0; j < n; ++j) {
                        if (s >> j & 1) {
                            dp[s][i] = min(dp[s][i], dp[s ^ (1 << i)][j] + f(j, i));
                            dp[s][i] = min(dp[s][i], dp[s][j] + f(j, i));
                        }
                    }
                }
            }
        }
        cnt+=1;
    }
    */
    for (int s = 0; s < 1 << n; ++s) {
        for (int i = 0; i < n; ++i) {
            if (s >> i & 1) {
                for (int j = 0; j < n; ++j) {
                    if (i != j && (s >> j & 1) == 0) {
                        dp[s | (1 << j)][j] = min(dp[s | (1 << j)][j], dp[s][i] + f(i, j));
                    }
                }
            }
        }
    }
    int ans = 1e9;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, dp[(1 << n) - 1][i] + f(i, 0));
    }
    cout << ans << endl;
    return 0;
}

