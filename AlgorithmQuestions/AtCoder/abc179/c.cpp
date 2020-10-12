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
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i * j >= n) {
                break;
            }
            int k = n - i * j;
            sum += 1;
        }
    }
    printf("%d\n", sum);
    return 0;
}
