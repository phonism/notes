#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

struct SegNode {
    int l, r;
    int v;
} tree[N * 4];

int main() {
    int tests;
    cin >> tests;
    for (int tes = 0; tes < tests; ++tes) {
        int n;
        cin >> n;
        int N = n + 10;
        vector<int> a(N);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        vector<int> ml(N), mr(N);
        ml[0] = 1e9;
        mr[n + 1] = 1e9;
        for (int i = 1; i <= n; ++i) {
            ml[i] = min(ml[i - 1], a[i]);
        }
        for (int i = n; i >= 1; --i) {
            mr[i] = min(mr[i + 1], a[i]);
        }

        bool ok = true;
        long long need_r = 0;
        long long pre = 1e9;
        for (int i = 1; i <= n; ++i) {
            if (need_r > a[i]) {
                ok = false;
                break;
            }
            pre = min(pre, a[i] - need_r);

            if (a[i] > pre + need_r) {
                need_r += a[i] - pre - need_r;
            }
        }
        /*
        long long need_l = 0;
        for (int i = n - 1; i >= 2; --i) {
            if (a[i] > mr[i + 1]) {
                need_l += a[i] - mr[i + 1];
            }
            // cout << need_r << endl;
            if (need_l > ml[i - 1]) {
                ok = false;
                break;
            }
        }
        */
        puts(ok ? "YES" : "NO");
    }
}

