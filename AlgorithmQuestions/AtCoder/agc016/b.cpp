#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    int color = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (mp.find(a[i]) == mp.end()) {
            mp[a[i]] = ++color;
        }
    }

    for (int i = 0; i < n; ++i) {
        a[i]
    }
