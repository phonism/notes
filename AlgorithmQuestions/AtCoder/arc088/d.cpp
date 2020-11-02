#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    set<int> st;
    int ans = s.length() / 2;
    for (int k = s.length() / 2 + 1; k <= s.length(); ++k) {
        int i = s.length() - k;
        int j = k - 1;
        // cout << k << " " << i << " " << j << endl;
        // for (int l = i; l <= j; ++l) {
        st.insert(s[i] - '0');
        st.insert(s[j] - '0');
        // }
        if (st.size() <= 1) {
            ans = k;
        } else {
            break;
        }
    }
    cout << ans << endl;
}
