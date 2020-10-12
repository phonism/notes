#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <bitset>
#include <vector>
using namespace std;
 
const int N = 1e5;
int l[N], r[N], s[N];
 
int main() {
    int n;
    scanf("%d", &n);
    bool ok = false;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &l[i], &r[i]);
        if (l[i] == r[i]) {
            s[i] = 1;
        }
        if (i < 2) {
            continue;
        }
        if (s[i] + s[i - 1] + s[i - 2] == 3) {
            ok = true;
        }
    }
    if (ok) {
        puts("Yes");
    } else {
        puts("No");
    }
    return 0;
}
