#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int main() {
    int test; scanf("%d", &test);
    for (int cas = 1; cas <= test; cas++) {
        int n; scanf("%d", &n);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long x; scanf("%lld", &x);
            sum += (x % n);
            sum %= n;
        }
        if (sum % n == 0) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
}
