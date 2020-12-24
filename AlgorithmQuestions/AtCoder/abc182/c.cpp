#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int sum = 0;
    int cnt[3] = {0};
    for (int i = 0; i < s.length(); ++i) {
        sum += s[i] - '0';
        cnt[(s[i] - '0') % 3]++;
    }
    if (sum % 3 == 0) {
        cout << 0 << endl;
    } else if (sum % 3 == 1) {
        if (cnt[1] > 0) {
            if (s.length() == 1) {
                cout << -1 << endl;
            } else {
                cout << 1 << endl;
            }
        } else if (cnt[2] > 1) {
            if (s.length() == 2) {
                cout << -1 << endl;
            } else {
                cout << 2 << endl;
            }
        } else {
            cout << -1 << endl;
        }
    } else {
        if (cnt[2] > 0) {
            if (s.length() == 1) {
                cout << -1 << endl;
            } else {
                cout << 1 << endl;
            }
        } else if (cnt[1] > 1) {
            if (s.length() == 2) {
                cout << -1 << endl;
            } else {
                cout << 2 << endl;
            }
        } else {
            cout << -1 << endl;
        }
    }
}
