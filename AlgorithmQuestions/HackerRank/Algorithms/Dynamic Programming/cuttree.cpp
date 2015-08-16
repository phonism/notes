#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 55;
int n, k;
int deg[maxn];
bool vis[maxn];
long long ans = 0;
vector<int> adj[maxn];

long long pow(int n) {
    long long ans = 1;
    for (int i = 0; i < n; i++)
        ans *= 2;
    return ans;
}

void dfs(int u) {
    vis[u] = true;
    ans += pow(deg[u]-1);
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (!vis[v]) {
            dfs(v);
        }
    }
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
        deg[x]++; deg[y]++;
    }
    dfs(1);
    printf("%lld\n", ans+2);
    return 0;
}
