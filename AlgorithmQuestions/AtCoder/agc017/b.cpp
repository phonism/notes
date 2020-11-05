#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    bool ok = false;
    n = n - 1;
    for (int i = 0; i < n; ++i) {
        long long high = d * (n - i) + a - (c * i);
        long long low = c * (n - i) + a - (d * i);
        if (b >= low && b <= high) {
            ok = true;
        }
    }

    puts(ok ? "YES" : "NO");
}
