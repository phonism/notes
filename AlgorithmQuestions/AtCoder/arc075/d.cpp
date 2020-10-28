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
 
int n;
long long a, b;
 
long long h[N];
 
bool judge(long long x) {
    long long cnt = 0;
    for (int i = 0; i < n; ++i) {
        long long tmp = h[i] - x * b;
        // cout << ceil(tmp / (a - b)) << " " << a - b << endl;
        if (tmp > 0) {
            cnt += ceil(1.0 * tmp / (a - b));
        }
    }
    // cout << x << " " << cnt << endl;
    if (cnt > x) {
        return false;
    }
    return true;
}
 
 
int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    cin >> n >> a >> b;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    long long left = 0, right = 1e9, mid = 0;
    while (left < right) {
        mid = (left + right) / 2;
        if (judge(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << left << endl;
 
    
    return 0;
}
