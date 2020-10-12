#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <bitset>
#include <unordered_map>
#include <vector>
#include <unordered_map>
using namespace std;
 
const int N = 2e5 + 7;
 
long long min_x[N], min_y[N];
 
int main() {
    long long n, q;
    scanf("%lld %lld", &n, &q);
    int xx = n, yy = n;
    for (int i = 1; i <= n; ++i) {
        min_x[i] = n;
        min_y[i] = n;
    }
    long long sum = 0;
    for (int t = 0; t < q; ++t) {
        int op, x;
        scanf("%d %d", &op, &x);
        if (op == 1) {
            if (x < xx) {
                sum += yy - 2;
                for (int i = x; i <= xx; ++i) {
                    min_x[i] = yy;
                }
                xx = x;
            } else {
                sum += min_x[x] - 2;
            }
        } else {
            if (x < yy) {
                sum += xx - 2;
                for (int i = x; i <= yy; ++i) {
                    min_y[i] = xx;
                }
                yy = x;
            } else {
                sum += min_y[x] - 2;
            }
        }
    }
    cout << (n - 2) * (n - 2) - sum << endl;
}
