#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int a[N];

int main() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        mp[a[i]]++;
    }

    int cnt = 0;
    int other = 0;
    for (auto it : mp) {
        int tmp = it.second + other;
        while (tmp >= 3) {
            tmp -= 2;
            cnt += 1;
        }
        if (tmp == 2) {
            other = 1;
        } else {
            other = 0;
        }
    }
    if (other > 0) {
        cnt += 1;
    }
    cout << n - 2 * cnt << endl;
    return 0;
}
