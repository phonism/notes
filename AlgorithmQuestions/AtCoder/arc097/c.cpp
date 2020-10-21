#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;
    set<string> subs;
    for (int i = 0; i < s.length(); ++i) {
        for (int j = 1; j <= k; ++j) {
            if (i + j - 1 < s.length()) {
                subs.insert(s.substr(i, j));
            }
        }
    }

    for (auto it : subs) {
        k--;
        if (k == 0) {
            cout << it << endl;
        }
    }
}
