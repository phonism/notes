#include <bits/stdc++.h>
using namespace std;

const int SIZE = 2e5 + 10;

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

UnionFind s, t;

int main() {
    int n, k, l;
    cin >> n >> k >> l;

    s.init(n);
    t.init(n);


    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        s.unite(x, y);
    }

    for (int i = 0; i < l; ++i) {
        int x, y;
        cin >> x >> y;
        t.unite(x, y);
    }

    map<pair<int, int>, int> mp;

    for (int i = 1; i <= n; ++i) {
        mp[make_pair(s.find(i), t.find(i))]++;
    }

    for (int i = 1; i <= n; ++i) {
        if (i == 1) {
            cout << mp[make_pair(s.find(i), t.find(i))];
        } else {
            cout << " " << mp[make_pair(s.find(i), t.find(i))];
        }
    }
    cout << endl;
}
