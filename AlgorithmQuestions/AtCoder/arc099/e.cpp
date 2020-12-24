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