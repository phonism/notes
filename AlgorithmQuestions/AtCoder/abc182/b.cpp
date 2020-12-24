#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int mx = 0, ans = a[0];
    for (int i = 2; i < 1001; i++) {
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (a[j] % i == 0) {
                cnt++;
            }
        }
        if (cnt > mx) {
            mx = cnt;
            ans = i;
        }
    }
    cout << ans << endl;
}
