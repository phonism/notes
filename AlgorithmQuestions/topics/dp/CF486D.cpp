#include <bits/stdc++.h>
using namespace std;

const int N = 2222;
const int MOD = 1e9 + 7;

vector<int> edge[N];
long long dp[N];
int a[N], l, r;

bool vis[N];

void dfs(int u, int p) {
    vector<long long> vec;
    dp[u] = 1;
    for (auto v : edge[u]) {
        if (v == p) {
            continue;
        }
        if (!vis[v] && a[v] >= l && a[v] <= r) {
            dfs(v, u);
            vec.push_back(dp[v]);
        }
    }
    for (int i = 0; i < vec.size(); ++i) {
        dp[u] *= (vec[i] + 1);
        dp[u] %= MOD;
    }
}

int main() {
    int n, d;
    cin >> d >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
 
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
 
    long long ans = 0;
    for (l = 1; l < N; ++l) {
        r = l + d;
        memset(dp, 0, sizeof(dp));
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; ++i) {
            if (a[i] == l) {
                vis[i] = 1;
                dfs(i, -1);
                ans += dp[i];
                ans %= MOD;
            }
        }
    }
    cout << ans << endl;
}
