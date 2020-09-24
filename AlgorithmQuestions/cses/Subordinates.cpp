/*
 * 题目链接：https://cses.fi/problemset/task/1674/
 * 题意：给出一棵树，问每个节点的所有子节点个数
 * 题解：递归求解即可
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

vector<int> adj[N];
int sum[N];

void dfs(int u, int p) {
    sum[u] = 0;
    for (auto v : adj[u]) {
        if (v == p) {
            continue;
        }
        sum[u] += 1;
        dfs(v, u);
        sum[u] += sum[v];
    }
}
    

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    dfs(1, -1);
    for (int i = 1; i<= n; ++i) {
        if (i == 1) {
            printf("%d", sum[i]);
        } else {
            printf(" %d", sum[i]);
        }
    }
    puts("");
}
