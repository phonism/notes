/*
 * 题目链接：https://cses.fi/problemset/task/1633/
 * 题意：给一个骰子和一个数n，问有多少种掷法使得最终结果和为n
 * 题解：dp[i] = dp[i - {1,6}] + 1，直接递推即可
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
 
const int N = 1e6 + 10;
const int MOD = 1e9 + 7;
long long dp[N];
 
int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    int n;
    scanf("%d", &n);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 6; ++j) {
            if (i - j < 0) {
                continue;
            }
            dp[i] += dp[i - j];
            dp[i] %= MOD;
        }
    }
    printf("%d\n", dp[n]);
}
