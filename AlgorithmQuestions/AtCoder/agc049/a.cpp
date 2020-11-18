#include <bits/stdc++.h>
using namespace std;

const int N = 111;

int edge[N][N];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        for (int j = 1; j <= n; ++j) {
            if (s[j - 1] == '1') {
                edge[i][j] = 1;
            }
        }
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                edge[i][j] |= edge[i][k] & edge[k][j];
            }
        }
    }

    long double ans = 0;

    for (int i = 1; i <= n; ++i) {
        int cnt = 1;
        for (int j = 1; j <= n; ++j) {
            if (i == j) {
                continue;
            }
            cnt += edge[j][i];
        }
        ans += (long double) 1.0 / cnt;

    }
    cout << setprecision(12) << ans << endl;
}
