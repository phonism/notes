#include <bits/stdc++.h>
using namespace std;

int a[10];

int main() {
    int sum = 0;
    for (int i = 0; i < 4; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    for (int s = 0; s < 2 << 4; ++s) {
        int tmp = 0;
        for (int i = 0; i < 4; ++i) {
            if (s >> i & 1) {
                tmp += a[i];
            }
        }
        if (tmp * 2 == sum) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}
