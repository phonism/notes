#include <bits/stdc++.h>
using namespace std;

int main() {
    int tests;
    cin >> tests;
    for (int test = 0; test < tests; ++test) {
        int n;
        cin >> n;
        vector<pair<int, int>> a(n);
        long long sum = 0;
        long long mx = -1e9;
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            mx = max(mx, 1LL * a[i].first);
        }
        for (int i = 0; i < n; ++i) {
            cin >> a[i].second;
            sum += a[i].second;
        }
        sort(a.begin(), a.end());
        // reverse(a.begin(), a.end());

        long long ans = min(mx, sum);
        long long tmp = 0;
        for (int i = 0; i < n; ++i) {
            tmp += a[i].second;
            // cout << a[i].first << " " << tmp << endl;
            ans = min(ans, max(1LL * a[i].first, sum - tmp));
        }
        cout << ans << endl;
    }
}

