#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int main() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        mp[x]++;
    }

    int ans = 0;
    for (auto it : mp) {
        if (it.first <= it.second) {
            ans += it.second - it.first;
        } else {
            ans += it.second;
        }
    }
    cout << ans << endl;
}

