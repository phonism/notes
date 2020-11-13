#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 10;
const int M = 222;

long long v[N][M];
long long a[N];
int l[N], r[N], stk[N];
long long sum[N][N];
int n, m;

int main() {
    cin >> n >> m;
    for (int i = 2; i <= n; ++i) {
        cin >> a[i];
        a[i] = a[i - 1] + a[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> v[i][j];
        }
    }

    for (int j = 1; j <= m; ++j) {
        int pos = 0;
        for (int i = 1; i <= n; ++i) {
            while (pos && v[stk[pos]][j] < v[i][j]) {
                r[stk[pos--]] = i - 1;
            }
            stk[++pos] = i;
        }
        while (pos) {
            r[stk[pos--]] = n;
        }
        pos = 0;
        for (int i = n; i; --i) {
            while (pos && v[stk[pos]][j] <= v[i][j]) {
                l[stk[pos--]] = i + 1;
            }
            stk[++pos] = i;
        }
        while (pos) {
            l[stk[pos--]] = 1;
        }

        for (int i = 1; i <= n; ++i) {
            sum[i + 1][r[i] + 1] += v[i][j];
            sum[l[i]][i] += v[i][j];
            sum[l[i]][r[i] + 1] -= v[i][j];
            sum[i + 1][i] -= v[i][j];
        }
    }

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            if (i <= j) {
                ans = max(ans, sum[i][j] - (a[j] - a[i]));
            }
        }
    }
    cout << ans << endl;
}
