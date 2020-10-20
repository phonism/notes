#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
using namespace std;

const int N = 5e5 + 10;
const int MOD = 1e9 + 7;

long long a[N];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    map<int, int> mp;
    vector<int> r;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mp[a[i]]++;
    }
    for (auto it : mp) {
        if (it.second >= 2) {
            r.push_back(it.first);
            if (it.second >= 4) {
                r.push_back(it.first);
            }
        }
    }
    sort(r.begin(), r.end());

    long long ans = 0;
    if (r.size() >= 2) {
        ans = (long long)r[r.size() - 1] * r[r.size() - 2];
    }

    cout << ans << endl;
    
    return 0;
}
