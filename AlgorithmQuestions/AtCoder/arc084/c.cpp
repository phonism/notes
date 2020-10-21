#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 100;
long long sum[N];

int main() {
    int n;
    cin >> n;
    vector<int> a, b, c;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        b.push_back(x);
    }
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        c.push_back(x);
    }

    sort(c.begin(), c.end());
    sort(b.begin(), b.end());
    for (int i = b.size() - 1; i >= 0; i--) {
        int cnt = c.size() - (upper_bound(c.begin(), c.end(), b[i]) - c.begin());
        sum[i] = sum[i + 1] + cnt;
    }

    long long ans = 0;
    for (int i = 0; i < a.size(); ++i) {
        int idx = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
        ans += sum[idx];
    }
    cout << ans << endl;
        
}
