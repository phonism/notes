#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <bitset>
#include <vector>
using namespace std;
 
const int N = 5e5 + 10;
 
 
int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    int sum = 0;
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.push_back(x);
        sum += a[i];
    }
    sort(a.begin(), a.end());
    if (sum % 10 == 0) {
        bool ok = false;
        for (int i = 0; i < n; ++i) {
            if (a[i] % 10 != 0) {
                sum -= a[i];
                ok = true;
                break;
            }
        }
        if (!ok) {
            sum = 0;
        }
    }
    cout << sum << endl;
    return 0;
}
