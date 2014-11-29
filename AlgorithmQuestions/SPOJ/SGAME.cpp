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

const int maxn = 1333;

int n, deg[maxn];

int main() {
    int test; scanf("%d", &test);
    for (int cas = 1; cas <= test; cas++) {
        scanf("%d", &n);
        int x, y;
        memset(deg, 0, sizeof(deg));
        while (scanf("%d %d", &x, &y)) {
            if (x == -1 && y == -1)
                break;
            deg[x] ^= 1;
            deg[y] ^= 1;
        }
        bool ok = true;
        for (int i = 0; i < maxn; i++) {
            if (deg[i]) {
                ok = false;
                break;
            }
        }
        puts(ok ? "YES" : "NO");
    }
    return 0;
}