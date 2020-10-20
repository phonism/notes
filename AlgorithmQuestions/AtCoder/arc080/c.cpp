#include <bits/stdc++.h>
using namespace std;

int get(int x) {
    int cnt = 0;
    while (x % 2 == 0) {
        cnt += 1;
        x /= 2;
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        int c = get(x);
        if (c >= 2) {
            cnt2++;
        } else if (c == 1) {
            cnt1++;
        }
    }
    bool ok = false;
    if (cnt2 > 0) {
        if (cnt2 * 2 + 1 >= n) {
            ok = true;
        }
        if (cnt2 * 2 + cnt1 >= n) {
            ok = true;
        }
    } else {
        if (cnt1 >= n) {
            ok = true;
        }
    }
    puts(ok ? "Yes" : "No");

}
