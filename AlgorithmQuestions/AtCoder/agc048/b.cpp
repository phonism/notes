#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }


    vector<int> c, d;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        if (i & 1) {
            c.push_back(b[i] - a[i]);
        } else {
            d.push_back(b[i] - a[i]);
        }
    }

    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    for (int i = 0; i < n / 2; ++i) {
        if (c[i] + d[i] > 0) {
            sum += c[i] + d[i];
        }
    }
    cout << sum << endl;
}
