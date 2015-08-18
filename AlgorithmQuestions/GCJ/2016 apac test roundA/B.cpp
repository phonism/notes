#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int maxn = 22;
int grid[maxn][maxn];

int main() {
    int test; cin >> test;
    for (int cas = 1; cas <= test; cas++) {
        int n; char op[10];
        scanf("%d %s", &n, op);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &grid[i][j]);
            }
        }
        vector<int> ans[maxn];
        int res[maxn][maxn];
        if (op[0] == 'l') {
            for (int i = 0; i < n; i++) {
                int tmp = 0;
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] > 0 && tmp == 0) {
                        tmp = grid[i][j];
                        continue;
                    }
                    if (grid[i][j] > 0 && tmp > 0) {
                        if (grid[i][j] == tmp) {
                            ans[i].push_back(grid[i][j] * 2);
                            tmp = 0;
                        } else {
                            ans[i].push_back(tmp);
                            tmp = grid[i][j];
                        }
                    }
                }
                if (tmp > 0)
                    ans[i].push_back(tmp);
                for (int j = 0; j < ans[i].size(); j++) {
                    res[i][j] = ans[i][j];
                }
                for (int j = ans[i].size(); j < n; j++) {
                    res[i][j] = 0;
                }
            }
        } else if (op[0] == 'r') {
            for (int i = 0; i < n; i++) {
                int tmp = 0;
                for (int j = n - 1; j >= 0; j--) {
                    if (grid[i][j] > 0 && tmp == 0) {
                        tmp = grid[i][j];
                        continue;
                    }
                    if (grid[i][j] > 0 && tmp > 0) {
                        if (grid[i][j] == tmp) {
                            ans[i].push_back(grid[i][j] * 2);
                            tmp = 0;
                        } else {
                            ans[i].push_back(tmp);
                            tmp = grid[i][j];
                        }
                    }
                }
                if (tmp > 0)
                    ans[i].push_back(tmp);
                for (int j = 0; j < ans[i].size(); j++) {
                    res[i][n-1-j] = ans[i][j];
                }
                for (int j = ans[i].size(); j < n; j++) {
                    res[i][n-1-j] = 0;
                }
            }
        } else if (op[0] == 'u') {
            for (int j = 0; j < n; j++) {
                int tmp = 0;
                for (int i = 0; i < n; i++) {
                    if (grid[i][j] > 0 && tmp == 0) {
                        tmp = grid[i][j];
                        continue;
                    }
                    if (grid[i][j] > 0 && tmp > 0) {
                        if (grid[i][j] == tmp) {
                            ans[j].push_back(grid[i][j] * 2);
                            tmp = 0;
                        } else {
                            ans[j].push_back(tmp);
                            tmp = grid[i][j];
                        }
                    }
                }
                if (tmp > 0)
                    ans[j].push_back(tmp);
                for (int i = 0; i < ans[j].size(); i++) {
                    res[i][j] = ans[j][i];
                }
                for (int i = ans[j].size(); i < n; i++) {
                    res[i][j] = 0;
                }
            }
        } else {
            for (int j = 0; j < n; j++) {
                int tmp = 0;
                for (int i = n - 1; i >= 0; i--) {
                    if (grid[i][j] > 0 && tmp == 0) {
                        tmp = grid[i][j];
                        continue;
                    }
                    if (grid[i][j] > 0 && tmp > 0) {
                        if (grid[i][j] == tmp) {
                            ans[j].push_back(grid[i][j] * 2);
                            tmp = 0;
                        } else {
                            ans[j].push_back(tmp);
                            tmp = grid[i][j];
                        }
                    }
                }
                if (tmp > 0)
                    ans[j].push_back(tmp);
                for (int i = 0; i < ans[j].size(); i++) {
                    res[n-1-i][j] = ans[j][i];
                }
                for (int i = ans[j].size(); i < n; i++) {
                    res[n-1-i][j] = 0;
                }
            }
        }
        printf("Case #%d:\n", cas);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0)
                    printf("%d", res[i][j]);
                else
                    printf(" %d", res[i][j]);
            }
            puts("");
        }
    }
    return 0;
}

