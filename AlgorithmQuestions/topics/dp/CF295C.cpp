#include <bits/stdc++.h>
using namespace std;

const int N = 55;
const int MOD = 1e9 + 7;

long long fac[N], inv[N], finv[N];

void init() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < N; ++i) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long cab(int a, int b) {
    if (a < b) {
        return 0;
    }
    return fac[a] * (finv[b] * finv[a - b] % MOD) % MOD;
}

struct Node {
    int x, y, z;
};

long long dp[N][N][2], dis[N][N][2];

int main() {
    init();
    int n, k; 
    cin >> n >> k;
    vector<int> a(n);
    int c0 = 0, c1 = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 50) {
            c0++;
        } else {
            c1++;
        }
    }

    memset(dp, 0, sizeof(dp));
    memset(dis, -1, sizeof(dis));

    dis[c0][c1][0] = 0;
    dp[c0][c1][0] = 1;
    queue<Node> q;
    q.push((Node) {c0, c1, 0});
    while (!q.empty()) {
        Node cur = q.front();
        q.pop();
        int x = cur.x, y = cur.y, z = cur.z;
        for (int i = 0; i <= x; ++i) {
            if (i % 50 > k) {
                break;
            }
            for (int j = 0; j <= y; ++j) {
                if (i + j == 0) {
                    continue;
                }
                if (i * 50 + j * 100 > k) {
                    break;
                }
                int nx = c0 - x + i, ny = c1 - y + j, nz = 1 - z;
                if (dis[nx][ny][nz] == -1) {
                    dis[nx][ny][nz] = dis[x][y][z] + 1;
                    dp[nx][ny][nz] = dp[x][y][z] * cab(x, i) % MOD * cab(y, j) % MOD;
                    q.push((Node){nx, ny, nz});
                } else if (dis[nx][ny][nz] == dis[x][y][z] + 1) {
                    dp[nx][ny][nz] = (dp[nx][ny][nz] + dp[x][y][z] * cab(x, i) % MOD * cab(y, j) % MOD) % MOD;
                }
            }
        }
    }
    cout << dis[c0][c1][1] << endl;
    cout << dp[c0][c1][1] << endl;
}
