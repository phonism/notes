#include <bits/stdc++.h>
using namespace std;

int main() {
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; ++t) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << (long long) a + b + c - 1 << endl;
    }
}
