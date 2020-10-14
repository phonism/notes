#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <bitset>
#include <vector>
#include <queue>
using namespace std;
 
const int N = 1e5 + 10;
 
long long x[N];
 
int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    int n;
    long long a, b;
    cin >> n >> a >> b;
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
        if (i > 1) {
            if (a * (x[i] - x[i - 1]) > b) {
                ans += b;
            } else {
                ans += a * (x[i] - x[i-1]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
