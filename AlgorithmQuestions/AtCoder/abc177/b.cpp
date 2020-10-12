#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int ans = 1e9;
    for (int i = 0; i < s.length() - t.length() + 1; ++i) {
        int count = 0;
        for (int j = 0; j < t.length(); ++j) {
            if (s[i + j] != t[j]) {
                count += 1;
            }
        }
        ans = min(ans, count);
    }
    cout << ans << endl;
}
