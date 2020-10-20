#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int a[N], c[N];

int main() {
    int n;
    cin >> n;
    int pre = 0;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] == i) {
            pre += 1;
        } else {
            ans += ceil(1.0 * pre / 2);
            pre = 0;
            // cout << ans << endl;
        }
    }

    if (pre) {
        ans += ceil(1.0 * pre / 2);
    }
    cout << ans << endl;

}
