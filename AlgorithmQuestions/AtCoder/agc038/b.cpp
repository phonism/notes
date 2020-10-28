#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int nodiff = 0;
    stack<int> stk;
    set<int> was;
    for (int i = 0; i < n; ++i) {
        if (stk.empty()) {
            stk.push(a[i]);
        }
        if (stk.top() < a[i]) {
            stk.push(a[i]);
        } else {
            while (!stk.empty()) {
                stk.pop();
            }
            stk.push(a[i]);
        }
        if (stk.size() >= k) {
            was.insert(i);
            nodiff++;
        }
    }

    set<int> s;
    for (int i = 0; i < k; ++i) {
        s.insert(a[i]);
    }
    int ans = 0;
    if (was.find(k - 1) == was.end()) {
        ans = 1;
    }
    for (int i = k; i < n; ++i) {
        // cout << *s.begin() << " " << *s.rbegin() << " " << a[i - k] << endl;
        if (a[i - k] == *s.begin() && a[i] > *s.rbegin()) {
        } else {
            if (was.find(i) == was.end()) {
                ans ++;
            }
        }
        s.erase(a[i - k]);
        s.insert(a[i]);
    }
    cout << ans + (nodiff > 0 ? 1 : 0) << endl;
}
