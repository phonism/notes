#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    int ans = 0;
    if (max(x, y) < 0 || min(x, y) > 0) {
        if (x < y) {
            ans = y - x;
        } else {
            ans = x - y + 2;
        }
    } else {
        ans = abs(y + x) + 1;
    }
    if (x == 0 || y == 0) {
        if (x < y) {
            ans = y - x;
        } else {
            ans = abs(y + x) + 1;
        }
    }
    cout << ans << endl;
}
