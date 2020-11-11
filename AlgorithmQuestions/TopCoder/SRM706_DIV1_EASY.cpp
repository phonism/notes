#include <bits/stdc++.h>
using namespace std;

class MovingCandies {
public:
    int a[22][22] = {{0}}, dp[21][21][402][44] = {{{{0}}}};
    int f[4] = {1, 0, -1, 0};
    int g[4] = {0, 1, 0, -1};
    int n, m;

    void dfs(int x, int y, int len, int ones) {
        dp[x][y][len][ones] = 1;
        for (int i = 0; i < 4; ++i) {
            int fx = x + f[i];
            int fy = y + g[i];
            if (fx >= 1 && fx <= n && fy >= 1 && fy <= m) {
                if (dp[fx][fy][len + 1][ones + a[fx][fy]]) {
                    continue;
                }
                if (len + 1 > n * m || ones + a[fx][fy] > n + m) {
                    continue;
                }
                dfs(fx, fy, len + 1, ones + a[fx][fy]);
            }
        }
    }
public:
    int minMoved(vector<string> t) {
        n = t.size(), m = t[0].size();
        int cnt = 0;
        for (int i = 0; i < t.size(); ++i) {
            for (int j = 0; j < t[i].length(); ++j) {
                if (t[i][j] == '#') {
                    cnt++;
                } else {
                    a[i + 1][j + 1] = 1;
                }
            }
        }

        if (cnt < n + m - 1) {
            return -1;
        }

        dfs(1, 1, 1, a[1][1]);

        int ans = 1e9;
        for (int i = 0; i <= cnt; ++i) {
            for (int j = 0; j < n + m; ++j) {
                if (dp[n][m][i][j]) {
                    ans = min(ans, j);
                }
            }
        }
        
        return ans;
    }
};

int main() {
    auto sol = new MovingCandies();
    // vector<string> t = {".#...#.###.#","#.#.##......",".#.#......#.","..#.......#.","##.........."};
    vector<string> t = 
    {
        "###.#########..#####",
        ".#######.###########"
    };

    cout << sol->minMoved(t) << endl;
}
