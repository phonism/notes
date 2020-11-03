#include <bits/stdc++.h>
using namespace std;

const int BIT = 29;

int find(vector<long long>& a, int i, vector<long long>& nb, int val) {
    int low = 0, high = a.size();
    while (low < high) {
        int mid = (low + high) >> 1;
        if (nb[mid] + a[i] >= val) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<long long> na(n), nb(n);
    long long ans = 0;
    for (int bit = 1; bit <= BIT; ++bit) {
        for (int i = 0; i < n; ++i) {
            na[i] = a[i] % (1 << bit);
        }
        for (int i = 0; i < n; ++i) {
            nb[i] = b[i] % (1 << bit);
        }
        sort(nb.begin(), nb.end());
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += n - find(na, i, nb, 1 << (bit - 1));
        }
        for (int i = 0; i < n; ++i) {
            cnt -= find(na, i, nb, (1 << bit) + (1 << (bit - 1))) - find(na, i, nb, (1 << bit));
        }
        if (cnt & 1) {
            ans += (1 << (bit - 1));
        }
    }
    cout << ans << endl;
}
