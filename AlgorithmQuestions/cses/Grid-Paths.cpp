#include <bits/stdc++.h>
using namespace std;

const int N = 8;
bool vis[N][N] = {false};
string s;

int fx[4] = {1, 0, -1, 0};
int fy[4] = {0, 1, 0, -1};

bool is_valid(int x, int y) {
    if (x < 1 || x > 7 || y < 1 || y > 7) {
        return false;
    }
    return true;
}

int cnt = 0;

void dfs(int x, int y, int num) {
    if (num == 48) {
        if (x == 7 && y == 1) {
            cnt += 1;
        }
        // cout << cnt << endl;
        return ;
    }
    for (int i = 0; i < 4; ++i) {
        int nx = x + fx[i];
        int ny = y + fy[i];
        if (vis[nx][ny]) {
            continue;
        }
        /*
        if (s[num - 1] == 'D') {
            if (i != 3) {
                continue;
            }
        }
        if (s[num - 1] == 'U') {
            if (i != 1) {
                continue;
            }
        }
        if (s[num - 1] == 'L') {
            if (i != 2) {
                continue;
            }
        }
        if (s[num - 1] == 'R') {
            if (i != 0) {
                continue;
            }
        }
        */
        if (is_valid(nx, ny)) {
            vis[nx][ny] = true;
            num += 1;
            dfs(nx, ny, num);
            num -= 1;
            vis[nx][ny] = false;
        }
    }
}

int main() {
    cin >> s;
    vis[1][1] = true;
    dfs(1, 1, 0);
}
