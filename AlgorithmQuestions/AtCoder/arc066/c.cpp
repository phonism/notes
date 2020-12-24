#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long fast_mod(int x, int y) {
    long long ans = 1;
    long long tmp = x;
    for (; y; y /= 2) {
        if (y & 1) {
            ans = ans * tmp % MOD;
        }
        tmp = tmp * tmp % MOD;
    }
    return ans;
}

int fabs(int a) {
    return a > 0 ? a : -a;
}

int main() {
    int n;
    cin >> n;
    vector<int> a;
    vector<int> pos;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        a.push_back(x);
        pos.push_back(fabs(n - i - (i - 1)));
    }
    sort(a.begin(), a.end());
    sort(pos.begin(), pos.end());

    bool ok = true;
    for (int i = 0; i < n; ++i) {
        if (a[i] != pos[i]) {
            ok = false;
            break;
        }
    }

    if (!ok) {
        puts("0");
    } else {
        cout << fast_mod(2, n / 2) << endl;
    }
}
