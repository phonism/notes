#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 100;

int main() {
    int n;
    cin >> n;
    vector<int> a(N), b(N);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }

    int left = 1e9 + 10;
    long long ans = 1e18, cur = 0;
    for (int i = n; i >= 1; i--) {
        if (a[i] > b[i]) {
            left = min(left, a[i] - b[i]);
        } else {
            ans = min(ans, max(cur, (long long) b[i] - a[i] + 1));
            if (a[i] < left) {
                cur++;
                left = a[i];
            }
        }
    }
    ans = min(ans, cur);
    cout << ans << endl;
}
