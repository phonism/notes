#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    queue<int> stk;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            stk.push(i);
        }
    }
    long long ans = 0;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            stk.pop();
            if (t[i] == '0') {
                if (stk.empty()) {
                    ok = false;
                    break;
                }
                ans += stk.front() - i;
                s[stk.front()] = '0';
                stk.pop();
            }
        } else {
            if (t[i] == '1') {
                if (stk.empty()) {
                    ok = false;
                    break;
                }
                ans += stk.front() - i;
                s[stk.front()] = '0';
                stk.pop();
            }
        }
    }
    if (!stk.empty()) {
        ok = false;
    }
    cout << (ok ? ans : -1) << endl;
}
