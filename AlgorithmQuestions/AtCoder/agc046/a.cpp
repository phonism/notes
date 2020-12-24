#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cin >> x;
    int sum = x;
    int cnt = 1;
    while (sum % 360 != 0) {
        cnt += 1;
        sum += x;
    }

    cout << cnt << endl;
}
