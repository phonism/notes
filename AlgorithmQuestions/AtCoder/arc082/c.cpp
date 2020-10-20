#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <bitset>
#include <vector>
using namespace std;

const int N = 5e5 + 10;

int a[N], cnt[N];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
        cnt[a[i] + 1]++;
        if (a[i] > 0) {
            cnt[a[i] - 1]++;
        }
    }
    int ans = 0;
    for (int i = 0; i <= 1e5 + 10; ++i) {
        ans = max(ans, cnt[i]);
    }
    cout << ans << endl;
    return 0;
}
