#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <bitset>
#include <vector>
using namespace std;

const int N = 5e5 + 10;
const int MOD = 1e9 + 7;

long long fabs(long long x) {
    return x < 0 ? -x : x;
}

long long A(long long x) {
    long long res = 1;
    for (int i = 1; i <= x; ++i) {
        res *= i;
        res %= MOD;
    }
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    long long n, m;
    cin >> n >> m;
    if (fabs(n - m) > 1) {
        puts("0");
        return 0;
    }
    if (n == m) {
        cout << 2 * A(n) * A(m) % MOD << endl;
    } else {
        cout << A(n) * A(m) % MOD << endl;
    }
    return 0;
}
