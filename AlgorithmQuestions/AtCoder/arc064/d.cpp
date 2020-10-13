#include <bits/stdc++.h>
using namespace std;


int main() {
    string s;
    cin >> s;

    int pre_b = 0;
    int pre_e = -1;
    int cnt = 1;
    for (int i = 1; i < s.length(); ++i) {
        if (s[i] == s[0]) {
            if (pre_b > pre_e) {
                cnt += 1;
            }
            pre_b = i;
            cnt += 1;
        } else if (s[i] == s[s.length() - 1]) {
            if (pre_e > pre_b) {
                cnt += 1;
            }
            pre_e = i;
            cnt += 1;
        }
    }
    // cout << cnt << endl;

    string ans = (s.length() - cnt) % 2 ? "First" : "Second";

    cout << ans << endl;
    
}
