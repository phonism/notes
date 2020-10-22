#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int a[N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int sum = 0;
    int pre = 0;
    int prex = 0;
    int r = -1;
    int l = 0;
    while (l < n) {
        while (r + 1 < n) {
            if (pre + a[r + 1] == (prex ^ a[r + 1])) {
                pre += a[r + 1];
                prex ^= a[r + 1];
                r += 1;
                // cout << l << " " << r << endl;
                sum += 1;
            } else {
                break;
            }
        }
        pre -= a[l];
        prex ^= a[l];
        sum += r - l;
        l += 1;
    }
    cout << sum << endl;
}
