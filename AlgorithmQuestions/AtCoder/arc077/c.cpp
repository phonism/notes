#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int a[N], b[N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int i = 0, j = n - 1, t = n - 1;
    while (t >= 0) {
        if ((n - t) & 1) {
            b[i] = a[t];
            i++;
        } else {
            b[j] = a[t];
            j--;
        }
        t--;
    }
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            cout << b[i];
        } else {
            cout << " " << b[i];
        }
    }
    cout << endl;
}
