#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N], b[N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (i & 1) {
            a[x]++;
        } else {
            b[x]++;
        }
    }

    int mx = -1e9, sec, pos, ans;
    for (int i = 1; i < N; ++i) {
        if (a[i] > mx) {
            sec = mx;
            mx = a[i];
            pos = i;
        } else {
            sec = max(sec, a[i]);
        }
    }

    for (int i = 1; i < N; ++i) {
        ans = max(ans, b[i] + (i == pos ? sec : mx));
    }
    cout << n - ans << endl;
}
