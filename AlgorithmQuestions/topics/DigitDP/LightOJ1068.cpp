#include <bits/stdc++.h>
using namespace std;

const int K = 95;

int dp[33][K][K][2];
vector<int> dim;

int dfs(int pos, int summod, int mulmod, int limit, int k) {
    if (dp[pos][summod][mulmod][limit] != -1) {
        return dp[pos][summod][mulmod][limit];
    }
    if (pos == 0) {
        if (summod == 0 && mulmod == 0) {
            return 1;
        } else {
            return 0;
        }
    }

    // cout << pos << " " << summod << " " << mulmod << endl;
    int res = 0;
    int mx = limit ? dim[pos] : 9;
    for (int i = 0; i <= mx; ++i) {
        res += dfs(pos - 1, (summod + i) % k, (mulmod * 10 + i) % k, limit && (i == mx), k);
    }
    dp[pos][summod][mulmod][limit] = res;
    return res;
}

int solve(int x, int k) {
    dim.clear();
    dim.push_back(-1);
    memset(dp, -1, sizeof(dp));
    while (x) {
        dim.push_back(x % 10);
        x /= 10;
    }
    return dfs(dim.size() - 1, 0, 0, 1, k);
}

int main() {
    int tests;
    cin >> tests;
    for (int test = 0; test < tests; ++test) {
        int a, b, k;
        cin >> a >> b >> k;
        cout << "Case " << test + 1 << ": ";
        if (k > 90) {
            cout << 0 << endl;
        } else {
            cout << solve(b, k) - solve(a - 1, k) << endl;
        }
    }
}
