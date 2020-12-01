#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 21;

struct Node {
    long long x, k, mask;

    bool operator<(Node o) {
        return k < o.k;
    }
};

int main() {
    long long n, m, b;
    cin >> n >> m >> b;
    vector<Node> node(n);
    for (int i = 0; i < n; ++i) {
        int nm;
        cin >> node[i].x >> node[i].k >> nm;
        for (int j = 0; j < nm; ++j) {
            int t;
            cin >> t;
            t--;
            node[i].mask += (1 << t);
        }
    }

    sort(node.begin(), node.end());

    vector<long long> dp(N, 2e18);
    long long ans = 2e18;
    dp[0] = 0;
    for (auto it : node) {
        for (int s = 0; s < 1 << m; ++s) {
            dp[s | it.mask] = min(dp[s | it.mask], dp[s] + it.x);
        }
        ans = std::min(ans, dp[(1 << m) - 1] + b * it.k);
    }
    if (ans == 2e18) {
        ans = -1;
    }
    cout << ans << endl;
}
