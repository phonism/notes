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
        int tmp = 0, i;
        for (i = 1; i < 10000; i++) {
            tmp += i;
            if (tmp >= n) {
                tmp = n - (tmp - i);
                break;
            }
        }
        if (i % 2 == 0) {
            printf("TERM %d IS %d/%d\n", n, tmp, i + 1 - tmp);
        } else {
            printf("TERM %d IS %d/%d\n", n, i + 1 - tmp, tmp);
        }
    }
}
