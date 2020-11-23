#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5;
 
int main() {
    int t;
    cin >> t;
    string atcoder = "atcoder";
    for (int tests = 0; tests < t; ++tests) {
        string s;
        cin >> s;
        if (s > atcoder) {
            puts("0");
            continue;
        }
 
        bool ok = false;
        int ans = 1e9;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] > 'a') {
                ok = true;
                ans = min(ans, i);
            }
            if (s[i] > 't') {
                ans = min(ans, i - 1);
            }
        }
        if (!ok) {
            puts("-1");
            continue;
        }
        cout << ans << endl;
    }
    return 0;
}
