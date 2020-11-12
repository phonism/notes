#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 100;

struct Node {
    int x, y, z;
    bool operator <(Node b) {
        return z < b.z;
    }
} edge[N];


int par[N];

int find(int x) {
    if (x == par[x]) {
        return x;
    }
    return par[x] = find(par[x]);
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> x;
    vector<pair<int, int>> y;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        x.push_back(make_pair(l, i + 1));
        y.push_back(make_pair(r, i + 1));
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int cnt = 0;
    for (int i = 0; i < n - 1; ++i) {
        // cout << x[i].first << " " << x[i].second << endl;
        edge[cnt].x = x[i].second;
        edge[cnt].y = x[i + 1].second;
        edge[cnt].z = x[i + 1].first - x[i].first;

        cnt ++;
        edge[cnt].x = y[i].second;
        edge[cnt].y = y[i + 1].second;
        edge[cnt].z = y[i + 1].first - y[i].first;
        cnt++;
    }

    sort(edge, edge + cnt);
    for (int i = 1; i <= n; ++i) {
        par[i] = i;
    }

    long long ans = 0;
    for (int i = 0; i < cnt; ++i) {
        int l = find(edge[i].x);
        int r = find(edge[i].y);
        // cout << l << " " << r << " " << edge[i].z << endl;
        if (l == r) {
            continue;
        }
        par[l] = r;
        ans += edge[i].z;
    }
    cout << ans << endl;

}
