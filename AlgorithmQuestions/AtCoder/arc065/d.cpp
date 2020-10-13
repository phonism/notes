#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int par[N];

int find(int x) {
    if (x != par[x]) {
        par[x] = find(par[x]);
    }
    return par[x];
}

long long s[N];

int main() {
    int n, k, l;
    cin >> n >> k >> l;
    
    for (int i = 1; i <= n; ++i) {
        par[i] = i;
    }
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        int rx = find(x);
        int ry = find(y);
        if (rx != ry) {
            par[rx] = ry;
        }
    }
    for (int i = 1; i <= n; ++i) {
        s[i] = find(i);
    }

    for (int i = 1; i <= n; ++i) {
        par[i] = i;
    }
    for (int i = 0; i < l; ++i) {
        int x, y;
        cin >> x >> y;
        int rx = find(x);
        int ry = find(y);
        if (rx != ry) {
            par[rx] = ry;
        }
    }

    for (int i = 1; i <= n; ++i) {
        s[i] += (long long) find(i) * N;
        // cout << s[i] << endl;
    }

    map<long long, int> mp;
    for (int i = 1; i <= n; ++i) {
        mp[s[i]]++;
    }

    for (int i = 1; i <= n; ++i) {
        if (i == 1) {
            cout << mp[s[i]];
        } else {
            cout << " " << mp[s[i]];
        }
    }
    cout << endl;
}
