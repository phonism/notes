#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
 
int l[N], r[N], a[N];
 
int main() {
    int n, k, q;
    cin >> n >> k >> q;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        l[x]++;
        r[y + 1]++;
    }
 
    int cur = 0;
    for (int i = 1; i < N; ++i) {
        if (l[i]) {
            cur += l[i];
        }
        if (r[i]) {
            cur -= r[i];
        }
        a[i] = cur >= k ? 1 : 0;
        a[i] += a[i - 1];
    }
 
    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        cout << a[y] - a[x - 1] << endl;
    }
}

