#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <bitset>
#include <vector>
using namespace std;

const int N = 5e5 + 10;
int a[N], cnt[2][N];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'W') {
            a[i] = 0;
        } else {
            a[i] = 1;
        }
    }
    for (int i = 0; i < s.length(); ++i) {
        cnt[a[i] == 1][i + 1] = cnt[a[i] == 1][i] + 1;
        cnt[a[i] == 0][i + 1] = cnt[a[i] == 0][i];
    }
    int ans = 1e9;
    for (int i = 1; i <= n; ++i) {
        // cout << cnt[0][i] << " " << cnt[1][i] << endl;
        int tmp = cnt[1][n] - cnt[1][i];
        tmp += cnt[0][i - 1];
        // cout << tmp << endl;
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
