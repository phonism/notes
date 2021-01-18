#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int a[N];

int main() {
    int n;
    cin >> n;
    long long sum = 0, ans = (long long) 1e12;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    for (int i = 0; i < (1 << n); ++i) {
        long long res = 0;
        for (int j = 0; j < n; ++j) {
            if (i >> j & 1) {
                res += a[j];
            }
        }
        // cout << res << endl;
        ans = min(ans, abs(sum - 2 * res));
    }
    cout << ans << endl;
}
