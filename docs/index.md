# LuckyQueen 学习笔记

+ [CF1463E: Plan of Lectures](https://codeforces.com/contest/1463/problem/E)
	+ 题意：要求构造一个1~n的排列，满足：1. p[i]出现在i之前。2. k个特殊pair(x,y)，在最终的排列中是紧挨着的。
	+ 题解：对于特殊pair，先进行缩点，缩点要记录每个点内的序，用于判断点内是否有环或者和原有的序有冲突。然后进行拓扑排序，如果不是拓扑序，代表不OK，如果是拓扑序就输出拓扑序即可。
	+ 标签：拓扑序，P4，L6
+ [ARC099E: Independence](https://atcoder.jp/contests/arc099/tasks/arc099_c)
    + 题意：n(<700)个点，m条边，n个点划分为两个完全子图并且子图的边数最少的个数是多少。
    + 题解：正着求比较难求，考虑建反图，那么某些点是完全子图的条件是这些点都是孤立的点，可以发现是要做二分图划分，那么这题就转变成判断反图里的每个连通块是否是二分图。判断完之后，如果找最小值呢，可以将每个二分图0 1的个数当做物品，做分组背包，得到哪些组合是ok的，最终求出这些可行方案里的最小值。
    + 代码：
```cpp
#include <bits/stdc++.h>
using namespace std;
 
const int N = 777;
 
int n, m;
int edge[N][N];
 
vector<int> color(N, -1);
vector<int> cnt(2, 0);
 
void dfs(int u, int p) {
    cnt[color[u]]++;
    for (int v = 1; v <= n; ++v) {
        if (edge[u][v] || u == v) {
            continue;
        }
        if (color[v] != -1 && color[v] != 1 - color[u]) {
            puts("-1");
            exit(0);
        }
        if (color[v] == 1 - color[u]) {
            continue;
        }
        color[v] = 1 - color[u];
        dfs(v, u);
    }
}
 
vector<int> dp(N, 0);
 
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edge[u][v] = 1;
        edge[v][u] = 1;
    }
 
    dp[0] = 1;
    int s = 0;
    for (int i = 1; i <= n; ++i) {
        if (color[i] == -1) {
            color[i] = 0;
            cnt[0] = 0;
            cnt[1] = 0;
            dfs(i, -1);
            s += cnt[0] + cnt[1];
            // cout << cnt[0] << " " << cnt[1] << endl;
            for (int j = n; j >= 0; j--) {
                int tmp = 0;
                if (j >= cnt[0]) {
                    tmp = max(tmp, dp[j - cnt[0]]);
                }
                if (j >= cnt[1]) {
                    tmp = max(tmp, dp[j - cnt[1]]);
                }
                dp[j] = tmp;
            }
        }
    }
    assert(s == n);
 
    int ans = 1e9;
    for (int i = 0; i <= n; ++i) {
        if (dp[i]) {
            ans = min(ans, i * (i - 1) / 2 + (n - i) * (n - i - 1) / 2);
        }
    }
    cout << ans << endl;
}
```
