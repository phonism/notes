#include <bits/stdc++.h>
using namespace std;

const int N = 111 * 111;

int aa[N];

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    int tmp = -1;
    for (int i = 0; i < 333; ++i) {
        if (cnt.count(i) != 0) {
            tmp = max(tmp, cnt[i]);
        }
    }

    tmp = tmp * max(0, t - n);

    int nn = t > n ? n * n : t * n;

    for (int i = 0; i < nn; ++i) {
        aa[i] = a[i % n];
    }

    vector<int> dp;
    dp.push_back(aa[0]);
    for (int i = 1; i < nn; ++i) {
        if (aa[i] >= dp[dp.size() - 1]) {
            dp.push_back(aa[i]);
        } else {
            dp[upper_bound(dp.begin(), dp.end(), aa[i]) - dp.begin()] = aa[i];
        }
    }

    cout << dp.size() + tmp << endl;

}
