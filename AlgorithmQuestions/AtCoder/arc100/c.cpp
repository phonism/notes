#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
vector<int> num;
long long sum[N];

int fabs(int x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        num.push_back(x - i);
    }
    sort(num.begin(), num.end());
    sum[0] = num[0];
    for (int i = 1; i < num.size(); ++i) {
        sum[i] = sum[i - 1] + num[i];
    }

    long long ans = (long long)1e9 * 1e9;
    for (int i = 0; i < n; ++i) {
        int b = num[i];
        long long tmp = (long long)b * (i + 1) - sum[i];
        tmp += sum[n - 1] - sum[i] - (long long)b * (n - i - 1);
        // cout << i << " " << b << " " << n - i - 1 << " " << tmp << endl;
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}
