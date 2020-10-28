#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

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

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] -= k;
    }

    vector<long long> sum(n + 1);
    vector<long long> id;
    sum[0] = 0;
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + a[i];
        id.push_back(sum[i]);
    }

    sort(id.begin(), id.end());
    auto last = unique(id.begin(), id.end());
    id.erase(last, id.end());

    bit.init(N * 2);
    long long ans = 0;
    for (int i = 0; i <= n; ++i) {
        // cout << bit.ask(order[i] + 1) << endl;
        int w = lower_bound(id.begin(), id.end(), sum[i]) - id.begin() + 1;
        ans += bit.ask(w);
        bit.add(w, 1);
    }
    cout << ans << endl;
    return 0;
}
