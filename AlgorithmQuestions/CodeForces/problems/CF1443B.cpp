#include <bits/stdc++.h>
using namespace std;

int main() {
    int tests;
    cin >> tests;
    for (int test = 0; test < tests; ++test) {
        int a, b;
        cin >> a >> b;
        string s;
        cin >> s;

        vector<pair<int, int>> boom;
        int l = -1, r = -1;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '1') {
                if (r == -1) {
                    l = i;
                    r = i;
                } else {
                    r = i;
                }
            } else {
                if (l != -1 && r != -1) {
                    boom.push_back(make_pair(l, r));
                }
                l = -1;
                r = -1;
            }
        }
        if (l != -1 && r != -1) {
            boom.push_back(make_pair(l, r));
        }

        if (boom.size() == 0) {
            cout << 0 << endl;
            continue;
        }
        int ans = a;
        for (int i = 1; i < boom.size(); ++i) {
            int len = boom[i].first - boom[i - 1].second - 1;
            if (b * len < a) {
                ans += b * len;
            } else {
                ans += a;
            }
        }
        cout << ans << endl;
    }
}

