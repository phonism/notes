/*
 * 题目链接：https://cses.fi/problemset/task/1131/
 * 题意：给n个点的树，求树的直径
 * 题解：两次dfs，第一次找最远的点，然后从这个点再dfs到最远的点，即为树的直径，证明google一下吧。
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

vector<int> adj[N];
int d[N];

void dfs(int u, int p) {
    for (auto v : adj[u]) {
        if (v == p) {
            continue;
        }
        d[v] = d[u] + 1;
        dfs(v, u);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    d[1] = 0;
    dfs(1, -1);
    int mx = -1, pos = -1;
    for (int i = 1; i <= n; ++i) {
        if (d[i] > mx) {
            mx = d[i];
            pos = i;
        }
    }
    d[pos] = 0;
    dfs(pos, -1);
    int ans = -1;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, d[i]);
    }
    printf("%d\n", ans);

}
