#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <bitset>
#include <vector>
using namespace std;

const int N = 5e5 + 10;



int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    long long n, m;
    cin >> n >> m;
    long long ans = 0;
    if (n > m) {
        swap(n, m);
    }
    if (n > 2 && m > 2) {
        ans = (n - 2) * (m - 2);
    } else {
        if (n == 1) {
            if (m == 1) {
                ans = 1;
            } else if (m == 2) {
                ans = 0;
            } else {
                ans = m - 2;
            }
        } else if (n == 2) {
            ans = 0;
        }
    }
    cout << ans << endl;
    return 0;
}
