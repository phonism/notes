#include <bits/stdc++.h>
using namespace std;

vector<int> cnt[4];

int main() {
    int n;
    string s;
    cin >> n >> s;
    int a = 0, t = 0, c = 0, g = 0;
    for (int i = 0; i < 4; ++i) {
        cnt[i].push_back(0);
    }
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'A') {
            a++;
        }
        if (s[i] == 'T') {
            t++;
        }
        if (s[i] == 'C') {
            c++;
        }
        if (s[i] == 'G') {
            g++;
        }
        cnt[0].push_back(a);
        cnt[1].push_back(t);
        cnt[2].push_back(c);
        cnt[3].push_back(g);
    }
    
    int answer = 0;
    for (int i = 1; i <= s.length(); ++i) {
        for (int j = i; j <= s.length(); ++j) {
            if (cnt[0][j] - cnt[0][i - 1] == cnt[1][j] - cnt[1][i - 1]) {
                if (cnt[2][j] - cnt[2][i - 1] == cnt[3][j] - cnt[3][i - 1]) {
                    answer += 1;
                }
            }
        }
    }
    cout << answer << endl;
}
