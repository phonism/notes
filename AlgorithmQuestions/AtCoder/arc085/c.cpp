#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    long long sum = m * 1900 + (n - m) * 100;
    for (int i = 0; i < m; ++i) {
        sum = sum * 2;
    }
    cout << sum << endl;

}
