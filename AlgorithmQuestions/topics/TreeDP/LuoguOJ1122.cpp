#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 10;

vector<int> a(N);
vector<int> edge[N];
vector<int> dp(N, 0);

void dfs(int u, int p) {
    dp[u] = a[u];
    for (int v : edge[u]) {
        if (v == p) {
            continue;
        }
        dfs(v, u);
        dp[u] += max(0, dp[v]);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    dfs(1, -1);

    int answer = -2147483647;
    for (int i = 1; i <= n; ++i) {
        answer = max(answer, dp[i]);
    }

    cout << answer << endl;
}
