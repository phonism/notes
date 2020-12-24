#include <bits/stdc++.h>
using namespace std;

const int L = 64;

class LinearBasis {
public:
    long long a[L + 1];

    void insert(long long x) {
        for (int i = L; i-- && x;) {
            if ((x >> i) & 1) {
                x ^= a[i];
            }
            if ((x >> i) & 1) {
                a[i] = x;
                break;
            }
        }
    }

    bool query(long long x) {
        for (int i = L; i-- && x;) {
            if ((x >> i) & 1) {
                x ^= a[i];
            }
        }
        return !x;
    }

    void reset() {
        memset(a, 0, sizeof(a));
    }
};

int main() {
    int tests;
    cin >> tests;
    LinearBasis lb;
    for (int cas = 1; cas <= tests; ++cas) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        string s;
        cin >> s;

        lb.reset();

        bool ok = false;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') {
                lb.insert(a[i]);
            } else {
                if (!lb.query(a[i])) {
                    ok = true;
                }
            }
        }
        puts(ok ? "1" : "0");
    }
}
