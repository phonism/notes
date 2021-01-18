#include <bits/stdc++.h>
using namespace std;

int c[26] = {0};
char ss[1000006];

int main() {
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.length(); ++i) {
        c[s[i] - 'A'] += 1;
        ans += 1;
    }

    int odd = 0, pos = -1;
    for (int i = 0; i < 26; ++i) {
        if (c[i] & 1) {
            odd += 1;
            pos = i;
        }
    }

    if (odd > 1) {
        puts("NO SOLUTION");
        return 0;
    }
    int cnt = 0;
    int len = s.length();
    if (pos == -1) {
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < c[i] / 2; ++j) {
                ss[cnt] = 'A' + i;
                ss[len - cnt - 1] = 'A' + i;
                cnt += 1;
            }
        }
        ss[len] = '\0';
    } else {
        for (int i = 0; i < 26; ++i) {
            if (i == pos) {
                continue;
            }
            for (int j = 0; j < c[i] / 2; ++j) {
                ss[cnt] = 'A' + i;
                ss[len - cnt - 1] = 'A' + i;
                cnt += 1;
            }
        }

        for (int j = 0; j < c[pos] / 2; ++j) {
            ss[cnt] = 'A' + pos;
            ss[len - cnt - 1] = 'A' + pos;
            cnt += 1;
        }
        ss[cnt] = 'A' + pos;
        ss[len] = '\0';
    }
    cout << ss << endl;
    return 0;
}
