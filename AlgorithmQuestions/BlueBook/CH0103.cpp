/*
 * 题目链接：https://www.acwing.com/problem/content/93/
 * 题意：给定n个点的带权无向图，求0到n-1的最短hamilton路径。n<=20（hamilton路径定义是0到n-1不重不漏的恰好经过每一个点）
 * 题解：朴素做法复杂度O(n!)，可以用状态压缩dp来求解，用二进制表示当前状态已经经过哪些点，然后转移的时候，就遍历所有可以再次经过的点？
 *     dp[i][j]，i是二进制表示当前经历了哪些点，j是最后一个经历的点。那么dp[i][j] = min(dp[i][j], dp[i ^ (1 << j)][k] + weight[j][k])
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 20;
const int S = 2 << 20;
int a[N][N];
int dp[S][N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    memset(dp, 0x3f, sizeof(dp));
    dp[1][0] = 0;
    for (int i = 0; i < 1 << n; ++i) { 
        for (int j = 0; j < n; ++j) {
            if (i >> j & 1) {
                for (int k = 0; k < n; k++) {
                    if ((i ^ (1 << j)) >> k & 1) {
                        dp[i][j] = min(dp[i][j], dp[i ^ (1 << j)][k] + a[j][k]);
                    }
                }
            }
        }
    }

    cout << dp[(1 << n) - 1][n - 1] << endl;
}
