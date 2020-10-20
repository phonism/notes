#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    string s1, s2;
    cin >> n;
    cin >> s1;
    cin >> s2;

    long long ans = 1;
    int flag = 0;
    if (s1[0] == s2[0]) {
        ans = 3;
    } else {
        ans = 6;
        flag = 1;
    }
    for (int i = 1; i < n; ++i) {
        if (flag == 1) {
            flag = 2;
            continue;
        }
        if (s1[i] == s2[i]) {
            if (flag == 2) {
            } else {
                ans *= 2;
                ans %= MOD;
            }
            flag = 0;
        } else {
            if (flag == 2) {
                ans *= 3;
                ans %= MOD;
            } else {
                ans *= 2;
                ans %= MOD;
            }
            flag = 1;
        }
    }
    cout << ans << endl;
}
