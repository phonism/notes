/* 
 * 题目链接：https://cses.fi/problemset/task/1130/
 * 题意：给出n个点的树，问没有公共端点的边的集合最多可以有多少边
 * 题解：dp[u][0]表示顶点u的子树且u和u的父节点的边没被选中的情况下可以选择的最大的边数，dp[u][1]表示顶点u的子树且u和u的父节点的边被选中的情况下最大的边数。
 *       设v为u的所有自己点，显然dp[u][1] = sum(dp[v][0])，对于dp[u][0]，表示顶点u未被选中，在子节点v里可以且只能选择一个和u当做边，那么怎么选择v呢，显然选择
 *       dp[v][1] - dp[v][0]最大的那个v是价值最高的。队规求解，回溯的时候更新dp
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
vector<int> adj[N];

int dp[N][2] = {0};

void dfs(int u, int p) {
    if (p != -1) {
        dp[u][0] = 0;
        dp[u][1] = 1;
    }
    int mx = -1e5, pos = -1;
    for (auto v : adj[u]) {
        if (v == p) {
            continue;
        }
        dfs(v, u);
        dp[u][0] += dp[v][0];
        if (dp[v][1] - dp[v][0] > mx) {
            mx = max(mx, dp[v][1] - dp[v][0]);
            pos = v;
        }
        dp[u][1] += dp[v][0];
    }
    dp[u][0] = dp[u][0] - dp[pos][0] + dp[pos][1];
}

int main() {
    int n;
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 1; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    dfs(1, -1);
    // for (int i = 1; i <= n; ++i) {
        // cout << dp[i][0] << " " << dp[i][1] << endl; 
    // }
    printf("%d\n", max(dp[1][0], dp[1][1]));
}
