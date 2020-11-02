#include <bits/stdc++.h>
using namespace std;


int dp[12][12][2][2];

int dfs(int pos, int st, int zero, int limit, vector<int> dim) {
    if (pos == 0) {
        return 1;
    }
    if (dp[pos][st][zero][limit] != -1) {
        return dp[pos][st][zero][limit];
    }

    int mx = limit ? dim[pos] : 9;
    int res = 0;
    for (int i = 0; i <= mx; ++i) {
        if (!zero && abs(st - i) < 2) {
            continue;
        }
        if (zero) {
            res += dfs(pos - 1, i, i == 0 ? 1 : 0, limit && (i == mx), dim);
        } else {
            res += dfs(pos - 1, i, 0, limit && (i == mx), dim);
        }
    }
    dp[pos][st][zero][limit] = res;
    return res;
}

int solve(int x) {
    memset(dp, -1, sizeof(dp));
    vector<int> dim;
    dim.push_back(-1);
    while (x) {
        dim.push_back(x % 10);
        x /= 10;
    }
    return dfs(dim.size() - 1, 0, 1, 1, dim);
}

int main() {
    int a, b;
    cin >> a >> b;
    // cout << solve(b) << endl;
    cout << solve(b) - solve(a - 1) << endl;
    
}
