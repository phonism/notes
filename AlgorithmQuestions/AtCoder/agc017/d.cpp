#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

vector<int> edge[N];
int sg[N];

void dfs(int u, int p) {
    sg[u] = 0;
    for (int v : edge[u]) {
        if (v == p) {
            continue;
        }
        dfs(v, u);
        sg[u] ^= (sg[v] + 1);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    dfs(1, -1);
    puts(sg[1] ? "Alice" : "Bob");
}
