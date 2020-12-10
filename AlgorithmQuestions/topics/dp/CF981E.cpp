#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 111;

struct Node {
    int l, r, x;

    bool operator<(Node a) {
        return l < a.l;
    }
};

int dp[N];

int main() {
    int n, q;
    cin >> n >> q;

    vector<Node> a(q);

    for (int i = 0; i < q; ++i) {
        cin >> a[i].l >> a[i].r >> a[i].x;
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < q; ++i) {
        int l = a[i].l;
        int r = a[i].r;
        int x = a[i].x;
        for (int j = n - x; j >= 1; j--) {
            if (dp[j] >= l) {
                dp[j + x] = max(dp[j + x], dp[j]);
            }
        }
        dp[x] = r;
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += dp[i] ? 1 : 0;
    }
    cout << ans << endl;
    for (int i = 1; i <= n; ++i) {
        if (dp[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}
