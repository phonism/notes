#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // sort(a[i].begin(), a[i].end());
    
    int answer = 2e9;
    for (int bound : a) {
        vector<int> b;
        vector<int> c;
        for (int i = 0; i <= n; ++i) {
            if (i == n || a[i] < bound) {
                sort(b.begin(), b.end());
                for (int j = 0; j <= (int) b.size() - k; ++j) {
                    c.push_back(b[j]);
                }
                b.clear();
            } else {
                b.push_back(a[i]);
            }
        }
        sort(c.begin(), c.end());
        if (c.size() < q) {
            continue;
        }
        // cout << c[c.size() - 1] << " " << c[0] << " " << bound << endl;
        answer = min(answer, c[q - 1] - c[0]);
    }
    cout << answer << endl;
}

