#include <bits/stdc++.h>
using namespace std;

const int N = 33;
const int M = 55;

int dp[N][N][M];

void init() {
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < N; ++j) {
            for (int k = 0; k < M; ++k) {
                dp[i][j][k] = 1e9;
                if (i * j == k || k == 0) {
                    dp[i][j][k] = 0;
                    continue;
                }
                for (int nk = 0; nk <= k; ++nk) {
                    for (int h = 1; h < j; ++h) {
                        dp[i][j][k] = min(dp[i][j][k], dp[i][h][nk] + dp[i][j - h][k - nk] + i * i);
                    }
                    for (int w = 1; w < i; ++w) {
                        dp[i][j][k] = min(dp[i][j][k], dp[w][j][nk] + dp[i - w][j][k - nk] + j * j);
                    }
                }
            }
        }
    }
}

int main() {
    init();
    int tests;
    cin >> tests;
    for (int tes = 0; tes < tests; ++tes) {
        int n, m, k;
        cin >> n >> m >> k;
        cout << dp[n][m][k] << endl;
    }
}
