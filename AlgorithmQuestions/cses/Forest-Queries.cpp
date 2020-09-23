/*
 * 题目链接：https://cses.fi/problemset/task/1652
 * 题意：给一个二维数组，查询x1,y1,x2,y2的区间和
 * 题解：预处理[1,1,x,y]的和，那么[x1,y1,x2,y2] = [1,1,x2,y2] - [1,1,x2,y1-1] - [1,1,x1-1,y2] + [1,1,x1-1,y1-1]
 */

#include <cstdio>
#include <iostream>
using namespace std;
 
const int N = 1e3 + 10;
 
int a[N][N], sum[N][N] = {0};
char ch[N];
 
int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", ch);
        for (int j = 1; j <= n; ++j) {
            if (ch[j - 1] == '*') {
                a[i][j] = 1;
            } else {
                a[i][j] = 0;
            }
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j -1] + a[i][j];
        }
    }
    for (int i = 1; i <= q; ++i) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1]);
    }
}
