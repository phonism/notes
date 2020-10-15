#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;
    int g = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (i == 0) {
            g = x;
        } else {
            g = gcd(g, x);
        }
    }
    cout << g << endl;
}
