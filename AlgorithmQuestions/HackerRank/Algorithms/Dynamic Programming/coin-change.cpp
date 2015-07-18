#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, a[55];
long long f[255];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
        scanf("%d", &a[i]);
    f[0] = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            if (j >= a[i])
                f[j] += f[j-a[i]];
        }
    }
    printf("%lld\n", f[n]);
    return 0;
}
