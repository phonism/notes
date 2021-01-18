#include <bits/stdc++.h>
using namespace std;

int main() {
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; ++t) {
        int a, b;
        cin >> a >> b;
        int tmp = min(a, b) - abs(a - b);
        if (tmp < 0 || tmp % 3 != 0) {
            puts("NO");
        } else {
            puts("YES");
        }
    }
    return 0;
}
