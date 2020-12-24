#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n + 1), sum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    long long ans = -1LL * 1e18;
    int pos = -1;
    long long pre = 0;
    long long max_pre = 0;
    sum[0] = 0;
    for (int i = 0; i <= n; ++i) {
        // ans = max(ans, max_pre + pre);
        max_pre = max(max_pre, sum[i]);
        pre = pre + sum[i];
        if (i == n) {
            ans = max(ans, pre);
        } else {
            ans = max(ans, max_pre + pre);
        }
    }
    cout << ans << endl;
}
