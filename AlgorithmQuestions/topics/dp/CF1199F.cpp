#include <bits/stdc++.h>
using namespace std;

const int N = 55;

int a[N][N];
int dp[N][N][N][N];

int dfs(int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 == y2) {
        dp[x1][y1][x2][y2] = a[x1][y1];
        return dp[x1][y1][x2][y2];
    }
    if (dp[x1][y1][x2][y2] != -1) {
        return dp[x1][y1][x2][y2];
    }
    dp[x1][y1][x2][y2] = max(y2 - y1 + 1, x2 - x1 + 1);
    for (int i = x1; i < x2; ++i) {
        dp[x1][y1][x2][y2] = min(dp[x1][y1][x2][y2], dfs(x1, y1, i, y2) + dfs(i + 1, y1, x2, y2));
    }
    for (int i = y1; i < y2; ++i) {
        dp[x1][y1][x2][y2] = min(dp[x1][y1][x2][y2], dfs(x1, y1, x2, i) + dfs(x1, i + 1, x2, y2));
    }
    return dp[x1][y1][x2][y2];

}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            a[i + 1][j + 1] = s[j] == '#' ? 1 : 0;
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(1, 1, n, n) << endl;
}
