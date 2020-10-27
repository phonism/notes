#include <bits/stdc++.h>
using namespace std;

class Matching {
public:
    vector<vector<int>> g;
    vector<int> pa;
    vector<int> pb;
    vector<int> was;
    int n, m;
    int res;
    int iter;

    Matching(int _n, int _m) : n(_n), m(_m) {
        pa = vector<int>(n, -1);
        pb = vector<int>(m, -1);
        was = vector<int>(n, 0);
        g.resize(n);
        res = 0;
        iter = 0;
    }

    void add(int from, int to) {
        g[from].push_back(to);
    }

    bool dfs(int v) {
        was[v] = iter;
        for (int u : g[v]) {
            if (pb[u] == -1) {
                pa[v] = u;
                pb[u] = v;
                return true;
            }
        }
        for (int u : g[v]) {
            if (was[pb[u]] != iter && dfs(pb[u])) {
                pa[v] = u;
                pb[u] = v;
                return true;
            }
        }
        return false;
    }

    int solve() {
        while (true) {
            iter++;
            int add = 0;
            for (int i = 0; i < n; ++i) {
                if (pa[i] == -1 && dfs(i)) {
                    add++;
                }
            }
            if (add == 0) {
                break;
            }
            res += add;
        }
        return res;
    }

};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> u(m);
    vector<int> v(m);
    vector<int> d(m);
    for (int i = 0; i < m; ++i) {
        cin >> u[i] >> v[i] >> d[i];
        --u[i];
        --v[i];
    }

    vector<int> order(m);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
        return d[i] < d[j];
    });

    int low = n, high = m + 1;
    while (low < high) {
        int mid = (low + high) >> 1;
        Matching mat(n, m);
        for (int i = 0; i < m; ++i) {
            if (d[i] <= d[order[mid - 1]]) {
                mat.add(u[i], v[i]);
            }
        }
        if (mat.solve() == n) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << (low <= m ? d[order[low - 1]] : -1) << endl;
}
