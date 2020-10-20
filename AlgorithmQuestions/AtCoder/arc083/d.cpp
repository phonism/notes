#include <bits/stdc++.h>
using namespace std;

const int N = 333;
long long a[N][N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            long long w = a[i][j] + 1;
            for (int k = 0; k < n; ++k) {
                if (i == k || j == k) {
                    continue;
                }
                w = min(w, (long long)a[i][k] + a[k][j]);
            }
            if (w < a[i][j]) {
                cout << "-1" << endl;
                return 0;
            }
            if (w > a[i][j]) {
                ans += a[i][j];
            }
        }
    }
    cout << ans << endl;
}
