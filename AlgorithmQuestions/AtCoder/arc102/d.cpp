#include <bits/stdc++.h>
using namespace std;

int get(int x) {
    int cnt = 0;
    while (x) {
        cnt += 1;
        x /= 2;
    }
    return cnt;
}

int main() {
    int l;
    cin >> l;
    cout << 20 << " " << 40 << endl;

    int tmp = 1;
    int cnt = get(l - 1);
    for (int i = 1; i <= cnt; ++i) {
        cout << i << " " << i + 1 << " " << 0 << endl;
        cout << i << " " << i + 1 << " " << tmp << endl;
        tmp *= 2;
    }

    cout << (1 << (cnt - 1)) << endl;
    if (l - (1 << (cnt - 1)) > 0) {
        cout << "FUCK" << endl;
        cout << 1 << " " << cnt + 1 << " " << l << endl;
    }
}
