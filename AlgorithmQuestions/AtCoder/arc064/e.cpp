#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
const int M = 1e6 + 10000;

int head[N], ver[M], nxt[M];
long double edge[M], d[N];
bool v[N];
int tot = 0;

void add(int x, int y, long double z) {
    ver[++tot] = y;
    edge[tot] = z;
    nxt[tot] = head[x];
    head[x] = tot;
}

priority_queue<pair<long double, int>> q;

void dijkstra() {
    for (int i = 0; i < N; ++i) {
        d[i] = 1.0 * 100000000000000LL;
    }
    memset(v, 0, sizeof(v));
    d[1] = 0;
    q.push(make_pair(0, 1));
    while (q.size()) {
        int x = q.top().second;
        q.pop();
        if (v[x]) {
            continue;
        }
        v[x] = 1;
        for (int i = head[x]; i; i = nxt[i]) {
            int y = ver[i];
            long double z = edge[i];
            if (d[y] > d[x] + z) {
                d[y] = d[x] + z;
                q.push(make_pair(-d[y], y));
            }
        }
    }
}

int x[N], y[N], r[N];

int main() {
    int xs, ys, xt, yt;
    cin >> x[1] >> y[1] >> x[2] >> y[2];
    r[1] = 0;
    r[2] = 0;

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i + 3] >> y[i + 3] >> r[i + 3];
    }

    n = n + 2;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) {
                continue;
            }
            long double xx = 1.0 * (x[i] - x[j]) * (x[i] - x[j]);
            long double yy = 1.0 * (y[i] - y[j]) * (y[i] - y[j]);
            long double zero = 0.0;
            long double dis = max(zero, sqrt(xx + yy) - (r[i] + r[j]));
            // cout << i << " " << j << " " << dis << endl;
            add(i, j, dis);
        }
    }

    dijkstra();
    cout<<fixed<<setprecision(20)<<d[2]<<endl;
}
