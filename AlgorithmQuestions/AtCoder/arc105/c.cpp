#include <bits/stdc++.h>
using namespace std;

const int N = 10;
const int M = 1e5 + 10;

int a[N], l[M], v[M];
int d[N];
int mx[M];
vector<pair<int, int>> bri;
vector<int> val;

int main() {
    int n, m;
    cin >> n >> m;
    int max_a = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        max_a = max(max_a, a[i]);
    }
    bool ok = true;
    for (int i = 0; i < m; ++i) {
        cin >> l[i] >> v[i];
        if (max_a > v[i]) {
            ok = false;
        }
        bri.push_back(make_pair(v[i], l[i]));
        val.push_back(v[i]);
    }

    if (ok == false) {
        puts("-1");
        return 0;
    }

    sort(bri.begin(), bri.end());
    sort(val.begin(), val.end());

    mx[0] = bri[0].second;
    for (int i = 1; i < m; ++i) {
        mx[i] = max(mx[i - 1], bri[i].second);
    }

    int ans = 1e9;
    do {
        int adj[N][N];
        for (int i = 0; i < n; ++i) {
            int tmp = 0;
            for (int j = i; j < n; ++j) {
                tmp += a[j];
                int pos = lower_bound(val.begin(), val.end(), tmp) - val.begin() - 1;
                if (pos < 0) {
                    adj[i][j] = 0;
                } else {
                    adj[i][j] = mx[pos];
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                for (int k = i + 1; k < j; ++k) {
                    adj[i][j] = max(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
        ans = min(ans, adj[0][n-1]);
    } while (next_permutation(a, a + n));
    cout << ans << endl;
}
