#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <bitset>
#include <vector>
#include <queue>
#include <map>
using namespace std;
 
const int N = 5e5 + 10;
const int MOD = 1e9 + 7;
 
int m, d, n;
int dp[2002][2002][2][2];
string a, b;
 
int dfs(int pos, int mod, int lima, int limb) {
    if (dp[pos][mod][lima][limb] != -1) {
        return dp[pos][mod][lima][limb];
    }
 
    if (pos == n) {
        if (mod == 0) {
            return 1;
        }
        return 0;
    }
    long long res = 0;
    for (int i = 0; i <= 9; ++i) {
        if (lima && i < a[pos] - '0') {
            continue;
        }
        if (limb && i > b[pos] - '0') {
            continue;
        }
        if (pos % 2 == 0 && i == d) {
            continue;
        }
        if (pos % 2 == 1 && i != d) {
            continue;
        }
        // cout << pos << " " << i << " " << lima << " " << limb << endl;
        int new_lima = lima && (i == a[pos] - '0');
        int new_limb = limb && (i == b[pos] - '0');
        // cout << pos << " " << i << " " << lima << " " << limb << endl;
        res += dfs(pos + 1, (mod * 10 + i) % m, new_lima, new_limb);
        res %= MOD;
    }
    dp[pos][mod][lima][limb] = res;
    return res;
}
 
 
int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    cin >> m >> d;
    cin >> a >> b;
    n = a.length();
    memset(dp, -1, sizeof(dp));
    // cout << solve(b) << endl;
    cout << dfs(0, 0, 1, 1) << endl;
}
