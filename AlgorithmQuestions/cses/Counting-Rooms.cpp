/*
 * 题目链接：https://cses.fi/problemset/task/1192/
 * 题意：给n*m的地图，有些地方不能走，问联通的区域有多少个
 * 题解：dfs即可
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;

int a[N][N];
char ch[N];

int f0[4] = {0, 0, 1, -1};
int f1[4] = {1, -1, 0, 0};
int n, m;

void dfs(int x, int y) {
    a[x][y] = 0;

    for (int i = 0; i < 4; ++i) {
        int fx = x + f0[i];
        int fy = y + f1[i];
        if (fx >= 1 && fx <= n && fy >= 1 && fy <= m) {
            if (a[fx][fy]) {
                dfs(fx, fy);
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", ch);
        for (int j = 0; j < m; ++j) {
            if (ch[j] == '#') {
                a[i + 1][j + 1] = 0;
            } else {
                a[i + 1][j + 1] = 1;
            }
        }
    }

    int count = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == 1) {
                dfs(i, j);
                count++;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}
