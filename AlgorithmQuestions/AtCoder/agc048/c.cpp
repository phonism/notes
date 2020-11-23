#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <bitset>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;
 
const int N = 1e5 + 100;
 
int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    int n, l;
    cin >> n >> l;
    vector<int> a(N), b(N);
    a[n + 1] = b[n + 1] = l + 1;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    n = n + 2;
    for (int i = 0; i < n; ++i) {
        a[i] -= i;
        b[i] -= i;
    }
 
    unordered_map<int, pair<int, int>> mp1, mp2;
 
    for (int i = 0; i < n; ++i) {
        if (mp1.count(a[i]) == 0) {
            mp1[a[i]] = make_pair(i, i);
        } else {
            mp1[a[i]].second = i;
        }
    }
 
    for (int i = 0; i < n; ++i) {
        if (mp1.count(b[i]) == 0) {
            cout << -1 << endl;
            return 0;
        }
        if (mp2.count(b[i]) == 0) {
            mp2[b[i]] = make_pair(i, i);
        } else {
            mp2[b[i]].second = i;
        }
    }
 
    long long ans = 0;
    for (auto it : mp2) {
        auto A = mp1[it.first];
        auto B = mp2[it.first];
        ans += max(0, A.first - B.first) + max(0, B.second - A.second);
    }
 
    cout << ans << endl;
}
