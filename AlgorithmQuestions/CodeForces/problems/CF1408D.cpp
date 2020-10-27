#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 100;

int a[N], b[N], c[N], d[N];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> c[i] >> d[i];
    }

    vector<int> v(N);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i] <= c[j]) {
                v[c[j] - a[i]] = max(v[c[j] - a[i]], d[j] - b[i] + 1);
            }
        }
    }

    int mx = 0;
    int ans = 2 * N;
    for (int i = N - 1; i >= 0; i--) {
        mx = max(mx, v[i]);
        ans = min(ans, mx + i);
    }
    cout << ans << endl;
    
}
