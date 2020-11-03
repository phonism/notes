#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    int tests;
    cin >> tests;
    for (int tes = 0; tes < tests; ++tes) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        vector<int> b(n);
        map<int, int> mp;
        map<int, int> pos;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            pos[a[i]] = i;
        }
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
            mp[b[i]] = i;
        }

        long long ans = 1;
        for (int i = 0; i < m; ++i) {
            int p = pos[b[i]];
            int l = p - 1;
            int r = p + 1;
            int tmp = 0;
            if (l >= 0 && l < n) {
                if (mp.find(a[l]) == mp.end()) {
                    tmp ++;
                } else if (mp[a[l]] < i) {
                    tmp++;
                }
            }
            if (r >= 0 && r < n) {
                if (mp.find(a[r]) == mp.end()) {
                    tmp ++;
                } else if (mp[a[r]] < i) {
                    tmp++;
                }
            }

            ans *= tmp;
            ans %= MOD;
        }
        cout << ans << endl;
    }
}

