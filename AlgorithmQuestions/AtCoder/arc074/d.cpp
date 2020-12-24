#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;


long long a[N];
priority_queue<long long, vector<long long>, greater<long long>> q;
priority_queue<long long> q2;
long long ls[N], rs[N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < 3 * n; ++i) {
        cin >> a[i];
    }

    long long sum = 0;
    for (int i = 0; i < 3 * n; ++i) {
        q.push(a[i]);
        sum += a[i];
        if (i >= n - 1) {
            while (q.size() > n) {
                sum -= q.top();
                q.pop();
            }
            ls[i] = sum;
        }
    }

    sum = 0;
    for (int i = 3 * n - 1; i >= 0; --i) {
        q2.push(a[i]);
        sum += a[i];
        if (i <= 2 * n) {
            while (q2.size() > n) {
                sum -= q2.top();
                q2.pop();
            }
            rs[i] = sum;
        }

    }

    long long ans = -1 * (long long)1e9 * 1e9;
    for (int i = n - 1; i < 2 * n; ++i) {
        ans = max(ans, ls[i] - rs[i + 1]);
        // cout << ls[i] << " " << rs[i + 1] << endl;
    }
    cout << ans << endl;

}
