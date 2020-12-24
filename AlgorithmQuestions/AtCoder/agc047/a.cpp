#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

long long a[N];

int get_fac(long long x, int y) {
    int cnt = 0;
    while (x % y == 0) {
        cnt += 1;
        x /= y;
    }
    return cnt;
}

int c2[N], c5[N];
int s2[100], s5[100];

map<pair<int, int>, int> mp;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        double x;
        cin >> x;
        a[i] = (long long) (x * 1e9);
        c2[i] = get_fac(a[i], 2);
        c5[i] = get_fac(a[i], 5);
        mp[make_pair(c2[i], c5[i])]++;
    }

    for (int i = 1; i < 100; ++i) {
        for (int j = 1; j < 100; ++j) {
            if (s2[i] + s2[j] >= 18 && s5[i] + s5[j] >= 18) {

            }
        }
    }

    return 0;
}
