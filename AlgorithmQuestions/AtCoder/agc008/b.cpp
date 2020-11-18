#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    vector<long long> s(n + 1), t(n + 1);
    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i] > 0 ? a[i] : 0;
        s[i] = s[i - 1] + (a[i] > 0 ? a[i] : 0);
        t[i] = t[i - 1] + (a[i] < 0 ? a[i] : 0);
    }
    long long ans = -1e18;
    for (int i = 1; i <= n - k + 1; ++i) {
        ans = max(ans, sum - (s[i + k - 1] - s[i - 1]));
    }

    for (int i = 1; i <= n - k + 1; ++i) {
        ans = max(ans, sum + (t[i + k - 1] - t[i - 1]));
    }

    cout << ans << endl;
}
