#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int maxn = 100100;
const int INF = 100100;
int a[maxn], f[maxn];
set<pair<int, int> > v, fv;

int main() {
    int n, s, l;
    scanf("%d %d %d", &n, &s, &l);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    f[0] = 0;
    for (int i = 0, j = 0; i < n; i++) {
        v.insert(make_pair(a[i], i));
        if (j <= i - l + 1) {
            fv.insert(make_pair(f[i-l+1], i-l+1));
        }
        while (v.rbegin()->first - v.begin()->first > s) {
            v.erase(make_pair(a[j], j));
            fv.erase(make_pair(f[j], j));
            j++;
        }
        f[i+1] = INF;
        if (j <= i - l + 1 && !fv.empty()) {
            f[i+1] = fv.begin()->first + 1;
        }
    }
    printf("%d\n", f[n] >= INF ? -1 : f[n]);
}
