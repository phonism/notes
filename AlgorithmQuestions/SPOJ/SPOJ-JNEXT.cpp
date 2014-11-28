#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

const int maxn = 1000010;
int a[maxn];

int main() {
    int test; scanf("%d", &test);
    for (int cas = 1; cas <= test; cas++) {
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        int pos = 0;
        for (int i = n; i > 1; i--) {
            if (a[i] > a[i-1]) {
                pos = i - 1;
                break;
            }
        }
        if (pos == 0) {
            puts("-1");
            continue;
        } else {
            for (int i = 1; i < pos; i++) {
                printf("%d", a[i]);
            }
            int tmp = -1;
            for (int i = n; i > pos; i--) {
                if (a[pos] < a[i]) {
                    tmp = a[i];
                    a[i] = a[pos];
                    break;
                }
            }
            if (tmp == -1) {
                while (true) {

                }
            }
            printf("%d", tmp);
            for (int i = n; i > pos; i--) {
                printf("%d", a[i]);
            }
            puts("");
        }
    }
    return 0;
}
