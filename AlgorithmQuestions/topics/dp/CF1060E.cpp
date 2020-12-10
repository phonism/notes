#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 111;

vector<int> edge[N];
int dep[N];
long long sum[N], dp[N];
int n;

void dfs(int u, int p) {
    sum[u] = 1;
    for (auto v : edge[u]) {
        if (v != p) {
            dep[v] = dep[u] + 1;
            dfs(v, u);
            sum[u] += sum[v];
            dp[u] += dp[v] + (n - sum[v]) * sum[v];
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1, -1);
    vector<long long> cnt(2);
    for (int i = 1; i <= n; ++i) {
        cnt[dep[i] % 2]++;
    }
    // cout << dp[1] + (cnt[0] * cnt[1]) << endl;
    cout << (dp[1] + (cnt[0] * cnt[1])) / 2 << endl;
}
