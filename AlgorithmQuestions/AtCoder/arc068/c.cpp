#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x;
    cin >> x;
    long long ans = ((x - 1) / 11) * 2;
    long long y = x - 1 - 11 * ((x - 1) / 11);
    if (y > 5) {
        ans += 2;
    } else {
        ans += 1;
    }
    if (x == 0) {
        ans = 0;
    }
    cout << ans << endl;
}
