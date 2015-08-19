#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

const int maxn = 5050;
int ispal[maxn][maxn], dp[maxn][maxn];
char ch[maxn];

int main() {
    scanf("%s", ch);
    int n = strlen(ch);
    for (int i = 0; i < n; i++) {
        ispal[i][i] = 1;
        dp[i][i] = 1;
        ispal[i+1][i] = 1;
    }
    for (int l = 2; l <= n; l++) {
        for (int i = 0; i < n; i++) {
            int j = i + l - 1;
            ispal[i][j] = ispal[i+1][j-1] & (ch[i] == ch[j]);
            dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1] + ispal[i][j];
        }
    }
    int q; scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int l, r; scanf("%d %d", &l, &r);
        printf("%d\n", dp[l-1][r-1]);
    }
    return 0;
}


