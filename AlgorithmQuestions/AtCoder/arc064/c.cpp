#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

long long a[N], p[N];

int main() {
    int n, x;
    cin >> n >> x;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[i] = a[i] + a[i - 1];
        p[i] -= x;
        // cout << p[i] << endl;
    }

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (p[i] > 0) {
            ans += p[i];
            p[i + 1] -= p[i];
        }
    }

    cout << ans << endl;
}
