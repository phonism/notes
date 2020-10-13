#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int dp[N];

int main() {
    string s;
    cin >> s;
    dp[0] = 1;
    for (int i = 1; i <= s.length(); ++i) {
        // dream, dreamer, erase and eraser
        if (i >= 5 && s.substr(i - 5, 5) == "dream") {
            dp[i] = max(dp[i], dp[i - 5]);
        } else if (i >= 7 && s.substr(i - 7, 7) == "dreamer") {
            dp[i] = max(dp[i], dp[i - 7]);
        } else if (i >= 5 && s.substr(i - 5, 5) == "erase") {
            dp[i] = max(dp[i], dp[i - 5]);
        } else if (i >= 6 && s.substr(i - 6, 6) == "eraser") {
            dp[i] = max(dp[i], dp[i - 6]);
        } else {
            dp[i] = 0;
        }
    }

    if (dp[s.length()]) {
        puts("YES");
    } else {
        puts("NO");
    }
}
