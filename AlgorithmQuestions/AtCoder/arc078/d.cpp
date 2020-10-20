#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> adj[N];

int pre[N];
int sum[N];

int dfs(int u, int p) {
    sum[u] = 1;
    for (auto v : adj[u]) {
        if (v == p) {
            continue;
        }
        pre[v] = u;
        sum[u] += dfs(v, u);
    }
    return sum[u];
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, -1);
    vector<int> road;
    int tmp = n;
    while (tmp != 0) {
        road.push_back(tmp);
        tmp = pre[tmp];
    }
    reverse(road.begin(), road.end());
    int snuke = sum[road[ceil(road.size() / 2.0)]];
    int fennce = n - snuke;
    if (snuke >= fennce) {
        cout << "Snuke" << endl;
    } else {
        cout << "Fennec" << endl;
    }
}
