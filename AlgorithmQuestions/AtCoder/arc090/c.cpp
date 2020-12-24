#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;

long long a[N], b[N];
long long sa[N], sb[N];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sa[i] = sa[i - 1] + a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        sb[i] = sb[i - 1] + b[i];
    }

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        long long tmp = sa[i] + sb[n] - sb[i - 1];
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}



