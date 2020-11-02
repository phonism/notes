#include <bits/stdc++.h>
using namespace std;

const int ST = 4;
const int LEN = 4;
const int PRE = 11;
// st=0 无8无4,st=1 有8无4,st=2 有4无8,st=3有8有4
long long dp[12][ST][PRE][LEN][2][2];
vector<int> dim;

long long dfs(int pos, int st, int pre, int len, int already, int limit) {
    if (dp[pos][st][pre][len][already][limit] != -1) {
        return dp[pos][st][pre][len][already][limit];
    }
    if (pos == 0) {
        return (st != 3 && (len == 3 || already == 1)) ? 1 : 0;
    }
    long long res = 0;
    int mx = limit ? dim[pos] : 9;
    for (int i = 0; i <= mx; ++i) {
        int new_len = len, new_st = st, new_pre = pre, new_already = already;
        if (i == pre) {
            new_len = min(len + 1, 3);
        } else {
            new_len = 1;
            new_pre = i;
        }
        if (new_len == 3) {
            new_already = 1;
        }
        if (i == 4) {
            if (st == 0) {
                new_st = 2;
            } else if (st == 1) {
                new_st = 3;
            }
        }
        if (i == 8) {
            if (st == 0) {
                new_st = 1;
            } else if (st == 2) {
                new_st = 3;
            }
        }
        long long tmp = dfs(pos - 1, new_st, new_pre, new_len, new_already, (i == mx) && limit);
        // cout << pos << " " << ((i == 0) && limit) << " " <<  << " " << new_st << " " << new_pre << " " << new_len << " " << tmp << endl;
        res += tmp;
    }
    // cout << res << endl;
    dp[pos][st][pre][len][already][limit] = res;
    return res;
}

long long solve(long long x) {
    memset(dp, -1, sizeof(dp));
    dim.clear();
    dim.push_back(-1);
    while (x) {
        dim.push_back(x % 10);
        x /= 10;
    }
    if (dim.size() != 12) {
        return 0;
    }
    long long res = 0;
    for (int i = 1; i <= dim[11]; ++i) {
        int st = 0;
        if (i == 4) {
            st = 2;
        }
        if (i == 8) {
            st = 1;
        }
        res += dfs(dim.size() - 2, st, i, 1, 0, i == dim[11]);
    }
    return res;
}


int main() {
    long long x, y;
    cin >> x >> y;
    // cout << solve(y) << endl;
    cout << solve(y) - solve(x - 1) << endl;
}
