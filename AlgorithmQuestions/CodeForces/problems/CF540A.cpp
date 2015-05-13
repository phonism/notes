#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

char ch1[1111], ch2[1111];
int n, sum = 0;

int main() {
    scanf("%d %s %s", &n, ch1, ch2);
    for (int i = 0; i < n; i++) {
        int l = ch1[i] - '0';
        int r = ch2[i] - '0';
        int tmp = max(l - r, r - l);
        sum += min(tmp, 10 - tmp);
    }
    printf("%d\n", sum);
    return 0;
}
