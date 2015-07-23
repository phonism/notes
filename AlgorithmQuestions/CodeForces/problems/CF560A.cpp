#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 3000000;
int a[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        for (int j = x; j <= maxn; j += x) {
            a[j] = 1;
        }
    }
    for (int i = 1; i < maxn; i++) {
        if (a[i] == 0) {
            printf("%d\n", i);
            return 0;
        }
    }
    puts("-1");
}
