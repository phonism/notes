#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int SIZE = 1e5 + 10;

set<int> p[N];

struct UnionFind {
    int par[SIZE], rank[SIZE];

    void init(int n) {
        for (int i = 0; i <= n; ++i) {
            par[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (x != par[x]) {
            par[x] = find(par[x]);
        }
        return par[x];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return ;
        }
        if (rank[x] < rank[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
        }
    }
};

UnionFind s;

int main() {
    int n, k;
    cin >> n >> k;
    for (int s = 1; s <= n * 2; ++s) {
        if (s % k != 0) {
            continue;
        }
        for (int a = 1; a <= n; ++a) {
            int b = s - a;
            if (b <= n && b > 0 && a <= b) {
                p[a].insert(b);
            }
        }
    }
    s.init(n);

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        // cout << i << " " << p[i].size() << endl;
        // ans += p[i].size() * (p[i].size() - 1) / 2;
        for (auto j : p[i]) {
            cout << i << " " << j << endl;
            s.unite(i, j);
        }
    }

    map<int, int> mp;
    for (int i = 1; i <= n; ++i) {
        mp[s.find(i)]++;
    }
    for (int i = 1; i <= n; ++i) {
        if (mp.find(i) != mp.end()) {
            ans += (long long)mp[i] * mp[i] * mp[i];
        }
    }
    cout << ans << endl;
}
