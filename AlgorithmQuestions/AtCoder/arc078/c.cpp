#include <bits/stdc++.h>
using namespace std;

long long fabs(long long x) {
    return x < 0 ? -x : x;
}

int main() {
    int n;
    cin >> n;
    vector<int> num;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        num.push_back(x);
        sum += x;
    }

    long long tmp = 0;
    long long ans = 1e18;
    for (int i = 0; i < n - 1; ++i) {
        tmp += num[i];
        ans = min(ans, fabs(sum - tmp * 2));
    }
    cout << ans << endl;

}
