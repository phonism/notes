#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        mp[x]++;
    }

    vector<int> num;
    for (auto it : mp) {
        num.push_back(it.second);
    }
    sort(num.begin(), num.end());

    int ans = 0;
    for (int i = 0; i < (int)num.size() - k; ++i) {
        ans += num[i];
    }
    cout << ans << endl;
}
