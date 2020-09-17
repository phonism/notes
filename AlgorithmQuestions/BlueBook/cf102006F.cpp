/*
 * 题目链接：https://codeforces.com/gym/102006/problem/F
 * 资料：SOS Dynamic Programming [Tutorial] https://codeforces.com/blog/entry/45223
 * 题意：给你t个测试样例，n道题目，给出每道题目对于每个测试用例是否会通过，求测试样例的顺序，
 *       使得n个题目测试的次数最少。（题目测试遇到失败后就不会向后测试）。
 * 题解：将t个测试用例用二进制表示，定义dp[s]是当前测了s的状态的测试样例，最少需要的测试次数，
 *       那么对于所有s & i != i的情况（即所有没测试过的状态），dp[s ^ (1 << i) = min(dp[s] + cnt[s])，
 *       其中cnt[s]，表示至少可以通过状态为s的题目个数。这个cnt需要通过上述资料处理出来。
 */


#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
 
const int S = (1 << 20);
const long long INF = 1e18;
 
long long cnt[S], dp[S];
string pre[S];
char s[33];
 
int main() {
    freopen("tests.in", "r", stdin);
    int tests;
    scanf("%d", &tests);
    for (int _ = 0; _ < tests; ++_) {
        int t, n;
        scanf("%d %d", &t, &n);
        for (int i = 0; i < (1 << t); ++i) {
            dp[i] = INF;
            pre[i] = "";
            cnt[i] = 0;
        }
        for (int i = 0; i < n; ++i) {
            scanf("%s", s);
            int state = 0;
            for (int j = 0; j < t; ++j) {
                state += (1 << j) * (s[j] - '0');
            }
            cnt[state]++;
        }
 
        for (int i = t - 1; i >= 0; --i) {
            for (int mask = (1 << t) - 1; mask >= 0; --mask) {
                if ((1 << i) & mask) { 
                    cnt[mask ^ (1 << i)] += cnt[mask];
                }
            }
        }
 
        dp[0] = 0;
 
        for (int mask = 0; mask < (1 << t); ++mask) {
            // cout << mask << " " << cnt[mask] << endl;
            for (int i = 0; i < t; ++i) {
                if (mask & (1 << i)) {
                    continue;
                }
 
                if (dp[mask] + cnt[mask] < dp[mask ^ (1 << i)]) {
                    dp[mask ^ (1 << i)] = dp[mask] + cnt[mask];
                    pre[mask ^ (1 << i)] = pre[mask];
                    pre[mask ^ (1 << i)] += i + 1 + '0';
                    // cout << mask << " " << (mask ^ (1 << i)) << " " << pre[mask ^ (1 << i)] << endl;
                } else if (dp[mask] + cnt[mask] == dp[mask ^ (1 << i)]) {
                    string a = pre[mask];
                    a += i + 1 + '0';
                    if (a < pre[mask ^ (1 << i)]) {
                        pre[mask ^ (1 << i)] = a;
                    }
                }
            }
        }
 
        cout << dp[(1 << t) - 1] << endl;
        for (int i = 0; i < t; ++i) {
            if (i == 0) {
                cout << pre[(1 << t) - 1][i] - '0';
            } else {
                cout << " " << pre[(1 << t) - 1][i] - '0';
            }
        }
        cout << endl;
    }
    return 0;
}
