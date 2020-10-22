#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    long long sum = 0;
    for (int i = k + 1; i <= n; ++i) {
        sum += (n / i) * (i - k);
        int cnt = max(0LL, k - 1);
        sum += max(0LL, (n % i) - cnt);
    }
    cout << sum << endl;
}
