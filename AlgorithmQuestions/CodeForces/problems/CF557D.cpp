#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 100100;
int n, m, col[maxn], cnt[3];
bool fuck = false;
vector<int> adj[maxn];

void dfs(int u, int c) {
    col[u] = c;
    cnt[c]++;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (col[v] == col[u]) {
            fuck = true;
        }
        if (!col[v]) {
            dfs(v, 3 - c);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    long long ans = 0;
    if (m == 0) {
        printf("2 %lld\n", (long long)n * (n - 1) * (n - 2) / 6);
        return 0;
    }
    bool isTwo = true;
    for (int i = 1; i <= n; i++) {
        if (!col[i]) {
            memset(cnt, 0, sizeof(cnt));
            dfs(i, 1);
            if (cnt[1] >= 2)
                ans += (long long)cnt[1] * (cnt[1] - 1) / 2;
            if (cnt[2] >= 2)
                ans += (long long)cnt[2] * (cnt[2] - 1) / 2;
            if (cnt[1] + cnt[2] > 2)
                isTwo = false;
        }
    }
    if (isTwo == true) {
        printf("2 %lld\n", (long long)(n - 2) * m);
    } else if (fuck == true) {
        printf("0 1\n");
    } else {
        printf("1 %lld\n", ans);
    }
    return 0;
}
