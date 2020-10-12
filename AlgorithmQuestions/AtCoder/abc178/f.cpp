#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int a[N], b[N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != a[i - 1]) {
            j = 0;
        }
        if (a[i] == b[i]) {
            for ( ; j < n; ++j) {
                if (a[j] != a[i] && b[j] != a[i]) {
                    swap(b[i], b[j]);
                    break;
                }
            }
            if (a[i] == b[i]) {
                puts("No");
                return 0;
            }
        }
    }

    puts("Yes");
    for (int i = 0; i < n; ++i) {
        if (i) {
            cout << " ";
        }
        cout << b[i];
    }
    cout << endl;
}
