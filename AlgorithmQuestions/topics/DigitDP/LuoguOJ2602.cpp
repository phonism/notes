#include <bits/stdc++.h>
using namespace std;

long long dp[15][15][2][2];
vector<int> dim;

long long dfs(int pos, int len, int zero, int k, int limit) {
    if (dp[pos][len][zero][limit] != -1) {
        return dp[pos][len][zero][limit];
    }
    if (pos == 0) {
        return len;
    }

    long long res = 0;
    int mx = limit ? dim[pos] : 9;
    for (int i = 0; i <= mx; ++i) {
        if (k == 0) {
            if (!zero) {
                res += dfs(pos - 1, (i == 0) ? (len + 1) : len, 0, k, (i == mx) && limit);
            } else {
                if (i == 0) {
                    res += dfs(pos - 1, len, 1, k, (i == mx) && limit);
                } else {
                    res += dfs(pos - 1, len, 0, k, (i == mx) && limit);
                }
            }
        } else {
            res += dfs(pos - 1, (i == k) ? (len + 1) : len, 1, k, (i == mx) && limit);
        }
    }
    dp[pos][len][zero][limit] = res;
    return res;
}

long long solve(long long x, int k) {
    memset(dp, -1, sizeof(dp));
    dim.clear();
    dim.push_back(-1);
    while (x) {
        dim.push_back(x % 10);
        x /= 10;
    }
    if (dim.size() == 1) {
        return 0;
    }
    return dfs(dim.size() - 1, 0, 1, k, 1);
}

int main() {
    long long a, b;
    cin >> a >> b;
    for (int i = 0; i <= 9; ++i) {
        if (i == 0) {
            cout << solve(b, i) - solve(a - 1, i);
        } else {
            cout << " " << solve(b, i) - solve(a - 1, i);
        }
    }
    cout << endl;
}
