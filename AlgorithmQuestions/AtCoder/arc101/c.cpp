#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> a, ll, rr;

int main() {
    int n, k;
    cin >> n >> k;
    rr.push_back(0);
    ll.push_back(0);
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        a.push_back(x);
        if (x >= 0) {
            rr.push_back(x);
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        if (a[i] < 0) {
            ll.push_back(-a[i]);
        }
    }

    int lmax = 0, rmax = 0;
    int l = 1;
    if (rr.size() >= k + 1) {
        rmax = rr[k];
        lmax = 0;
        l = 1;
    } else {
        rmax = rr[rr.size() - 1];
        lmax = ll[k - rr.size() + 1];
        l = k - rr.size() + 1;
    }
    int ans = lmax + rmax + min(lmax, rmax);
    for (;l <= k && l < ll.size(); ++l) {
        int r = k - l;
        lmax = ll[l];
        rmax = rr[r];
        // cout << l << " " << r << " " << lmax << " " << rmax << endl;
        ans = min(ans, lmax + rmax + min(lmax, rmax));
    }
    cout << ans << endl;
}
