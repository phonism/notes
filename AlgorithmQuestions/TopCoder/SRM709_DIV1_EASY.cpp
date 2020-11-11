#include <bits/stdc++.h>
using namespace std;

class Xscoregame {
public:
    int dp[1 << 16][65];
    int getscore(vector<int> A) {
        int n = A.size();
        memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;
        for (int s = 0; s < 1 << n; ++s) {
            for (int i = 0; i < n; ++i) {
                if ((1 << i) & s) {
                    for (int j = 0; j < 64; ++j) {
                        int new_j = (j + (j ^ A[i])) & 63;
                        if (dp[s ^ (1 << i)][j] >= 0) {
                            dp[s][new_j] = max(dp[s][new_j], dp[s ^ (1 << i)][j] + (dp[s ^ (1 << i)][j] ^ A[i]));
                        }
                    }
                }
            }
        }
        int mx = -1;
        for (int i = 0; i < 64; ++i) {
            mx = max(mx, dp[(1 << n) - 1][i]);
        }
        return mx;
    }
};

int main() {
    auto sol = new Xscoregame();
    vector<int> A = {50,0,1,0,1,0,1,0,1,0,1,0,1,0,1};
    cout << sol->getscore(A) << endl;
}
