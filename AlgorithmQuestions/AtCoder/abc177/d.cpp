#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int par[N];
int c[N];

int find(int x) {
    if (par[x] != x) {
        par[x] = find(par[x]);
    }
    return par[x];
}


int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        par[i] = i;
    }
    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        int fa = find(a);
        int fb = find(b);
        if (fa != fb) {
            par[fa] = fb;
        }
    }
    for (int i = 1; i <= n; ++i) {
        c[find(i)]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, c[i]);
    }
    cout << ans << endl;
}
