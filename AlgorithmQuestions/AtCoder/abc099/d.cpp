#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
const int C = 33;

int c[N][N], d[N][N];
int s[N][C];
int cnt[3][C];

int main() {
    int n, color;
    cin >> n >> color;
    for (int i = 1; i <= color; ++i) {
        for (int j = 1; j <= color; ++j) {
            cin >> d[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> c[i][j];
        }
    }


    for (int i = 1; i <= n - 1; ++i) {
        int idx = (i + 1) % 3;
        for (int j = 1; j <= i; ++j) {
            cnt[idx][c[i+1-j][j]]++;
        }
        
        idx = (2 * n - i + 1) % 3;
        for (int j = 1; j <= i; ++j) {
            cnt[idx][c[n+1-j][n-i+j]]++;
        }
    }

    int idx = (n + 1) % 3;
    for (int j = 1; j <= n; ++j) {
        cnt[idx][c[n+1-j][j]]++;
    }

    int ans = 1e9;
    for (int i = 1; i <= color; ++i) {
        for (int j = 1; j <= color; ++j) {
            if (i == j) {
                continue;
            }
            for (int k = 1; k <= color; ++k) {
                if (j == k || i == k) {
                    continue;
                }
                int sum = 0;
                for (int l = 1; l <= color; ++l) {
                    if (l != i) {
                        sum += cnt[0][l] * d[l][i];
                    }
                    if (l != j) {
                        sum += cnt[1][l] * d[l][j];
                    }
                    if (l != k) {
                        sum += cnt[2][l] * d[l][k];
                    }
                }
                // cout << sum << endl;
                ans = min(ans, sum);
            }
        }
    }
    cout << ans << endl;
}
