#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

const int maxn = 111;
int a[maxn][maxn], dp[maxn][maxn];

int main() {
    int test; scanf("%d", &test);
    for (int cas = 1; cas <= test; cas++) {
        memset(dp, 0, sizeof(dp));
        int h, w; scanf("%d %d", &h, &w);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        for (int j = 0; j < w; j++) {
            dp[0][j] = a[0][j];
        }
        for (int i = 1; i < h; i++) {
            for (int j = 0; j < w; j++) {
                int tmp = 0;
                tmp = max(dp[i-1][j], tmp);
                if (j > 0)
                    tmp = max(dp[i-1][j-1], tmp);
                if (j < w - 1)
                    tmp = max(dp[i-1][j+1], tmp);
                dp[i][j] = tmp + a[i][j];
            }
        }
        int ans = 0;
        for (int j = 0; j < w; j++) {
            if (dp[h-1][j] > ans)
                ans = dp[h-1][j];
        }
        printf("%d\n", ans);
    }
}
