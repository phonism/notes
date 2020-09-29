/*
 * 题目链接：https://cses.fi/problemset/task/1634
 * 题意：给出n个硬币，每个硬币有不同的面值，每个硬币可以使用多次，问最少的硬币个数使得面值等于x
 * 题解：dp[i] = min(dp[i - c[j]])，直接dp即可
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
 
const int N = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;
int a[N];
long long dp[N];
 
int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    int n, x;
    scanf("%d %d", &n, &x);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    dp[0] = 0;
    for (int i = 1; i <= x; ++i) {
        dp[i] = INF;
    }
    for (int i = 1; i <= x; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i >= a[j]) {
                dp[i] = min(dp[i], dp[i - a[j]] + 1);
            }
        }
    }
    if (dp[x] == INF) {
        puts("-1");
    } else {
        printf("%d\n", dp[x]);
    }
}
