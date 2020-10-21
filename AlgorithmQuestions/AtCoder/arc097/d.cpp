#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <bitset>
#include <vector>
#include <queue>
#include <map>
using namespace std;
 
const int N = 1e5 + 10;

int n, m;
int p[N], x[N], y[N];

struct UnionFind {
    int par[N], rank[N];

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

UnionFind uf;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    uf.init(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        uf.unite(x, y);
    }

    map<int, vector<int>> mp, mq;

    for (int i = 1; i <= n; ++i) {
        mp[uf.find(i)].push_back(i);
        mq[uf.find(i)].push_back(p[i]);
    }

    int cnt = 0;
    for (auto it : mp) {
        sort(it.second.begin(), it.second.end());
        sort(mq[it.first].begin(), mq[it.first].end());

        auto& a = it.second;
        auto& b = mq[it.first];

        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (i >= a.size()) {
                break;
            }
            if (a[i] == b[j]) {
                cnt++;
                i++;
                j++;
            } else if (a[i] < b[j]) {
                i++;
            } else {
                j++;
            }
            
        }
    }
    cout << cnt << endl;
    
    return 0;
}
