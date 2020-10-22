#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;

long long a[N];
vector<long long> sum;
int n;

long long get(int x, int y, int z) {
    long long one = sum[x];
    long long two = sum[y] - sum[x];
    long long three = sum[z] - sum[y];
    long long four = sum[n - 1] - sum[z];
    long long minx = min(one, min(two, min(three, four)));
    long long maxx = max(one, max(two, max(three, four)));
    return maxx - minx;
}

int main() {
    cin >> n;
    long long s = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s += a[i];
        sum.push_back(s);
    }

    long long ans = 1e18;
    for (int i = 1; i < n - 2; ++i) {
        long long tmp = sum[i] / 2;
        // cout << tmp << endl;
        int r1 = lower_bound(sum.begin(), sum.begin() + i + 1, tmp) - sum.begin();
        int l1 = r1;
        if (r1 > 0) {
            l1 = r1 - 1;
        }

        tmp = (sum[n - 1] - sum[i]) / 2 + sum[i];
        int r2 = lower_bound(sum.begin() + i + 1, sum.end(), tmp) - sum.begin();
        // cout << i << " " << r1 << " " <<  r2 << endl;
        int l2 = r2;
        if (r2 > i + 1) {
            l2 = r2 - 1;
        }


        // cout << i << " " << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
        ans = min(ans, get(l1, i, l2));
        ans = min(ans, get(r1, i, l2));
        ans = min(ans, get(l1, i, r2));
        ans = min(ans, get(r1, i, r2));
    }
    cout << ans << endl;


}
