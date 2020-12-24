#include <bits/stdc++.h>
using namespace std;

const int N = 2e3;
vector<int> row[N];
vector<int> col[N];

int color_row[N][N];
int color_col[N][N];
int color_x[N];
int color_y[N];
int color[N][N];
int vis_col[N][N];
int vis_row[N][N];
int ans[N][N];

int f[2] = {0, 0};
int g[2] = {1, -1};

int h, w, n, m;
void dfs_row(int a, int b) {
    for (int i = 0; i < 2; ++i) {
        vis_row[a][b] = 1;
        int fa = a + f[i];
        int fb = b + g[i];
        while (fa >= 1 && fa <= h && fb >= 1 && fb <= w) {
            if (vis_row[fa][fb]) {
                break;
            }
            if (color[fa][fb]) {
                break;
            }
            vis_row[fa][fb] = 1;
            fa += f[i];
            fb += g[i];
        }
    }
}

void dfs_col(int a, int b) {
    for (int i = 0; i < 2; ++i) {
        vis_col[a][b] = 1;
        int fa = a + g[i];
        int fb = b + f[i];
        while (fa >= 1 && fa <= h && fb >= 1 && fb <= w) {
            // cout << fa << " " << fb << endl;
            if (vis_col[fa][fb]) {
                break;
            }
            if (color[fa][fb]) {
                break;
            }
            vis_col[fa][fb] = 1;
            fa += g[i];
            fb += f[i];
        }
    }
}

int main() {
    cin >> h >> w >> n >> m;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        color[a][b] = 1;
        row[a].push_back(b);
        col[b].push_back(a);
    }

    for (int i = 0; i < n; ++i) {
        dfs_row(x[i], y[i]);
        dfs_col(x[i], y[i]);
    }

    int ans = 0;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if (vis_col[i][j] || vis_row[i][j]) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
