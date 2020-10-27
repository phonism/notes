#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

long long a[N], sum[N];

struct BIT {
    int n;
    int c[N * 2];

    void init(int _n) {
        n = _n;
        memset(c, 0, sizeof(c));
    }

    void add(int x, int v) {
        for (; x <= n; x += x & -x) {
            c[x] += v;
        }
    }

    int ask(int x) {
        int ans = 0;
        for (; x; x -= x & -x) {
            ans += c[x];
        }
        return ans;
    }
};

BIT bit;

int n;

bool check(int k) {
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + (a[i] >= k ? 1 : -1);
    }

    bit.init(n * 2 + 1);

    long long ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans += bit.ask(sum[i] + n + 1);
        bit.add(sum[i] + n + 1, 1);
    }
    return ans >= ((1LL * n * (n + 1) / 2) + 1) / 2;
}


int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    int l = 1, r = 1e9, mid = 0;
    while (l < r) {
        mid = (l + r + 1) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l << endl;
}
