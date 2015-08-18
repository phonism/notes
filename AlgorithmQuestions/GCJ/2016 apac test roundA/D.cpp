#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

const int maxn = 5050;
int a[maxn];

struct Area {
    int w, h;
    Area() {}
    Area(int ww, int hh) {
        w = ww;
        h = hh;
    }
    bool operator<(const Area &t) const {
        if (w == t.w)
            return h < t.h;
        return w < t.w;
    }
};

int main() {
    int test; scanf("%d", &test);
    for (int cas = 1; cas <= test; cas++) {
        int n, m; scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            a[i] = 1 << a[i];
        }
        multiset<Area> ms;
        sort(a, a + n, greater<int>());
        for (int i = 0; i < n; i++) {
            // printf("%d ", a[i]);
        }
        // puts("");
        int result = 0;
        for (int i = 0; i < n; i++) {
            // for (multiset<Area>::iterator it = ms.begin(); it != ms.end(); it++) {
                // printf("%d %d   ", it->w, it->h);
            //}
            bool ok = false;
            for (multiset<Area>::iterator it = ms.begin(); it != ms.end(); it++) {
                if (it->w >= a[i]) {
                    ok = true;
                    Area t = *it;
                    if (t.w - a[i] != 0 && t.h - a[i] != 0) {
                        ms.insert(Area(t.w - a[i], t.h - a[i]));
                        if (t.w - a[i] > a[i])
                            ms.insert(Area(a[i], t.w - a[i]));
                        else
                            ms.insert(Area(t.w - a[i], a[i]));
                    }
                    if (t.h - a[i] != 0) {
                        if (t.h - a[i] > a[i])
                            ms.insert(Area(a[i], t.h - a[i]));
                        else
                            ms.insert(Area(t.h - a[i], a[i]));
                    }
                    ms.erase(it);
                    break;
                }
            }
          //  puts("");
            if (ok == false) {
                result++;
                if (m - a[i] > 0) {
                    ms.insert(Area(m - a[i], m - a[i]));
                    if (m - a[i] > a[i]) {
                        ms.insert(Area(a[i], m - a[i]));
                        ms.insert(Area(a[i], m - a[i]));
                    } else {
                        ms.insert(Area(m - a[i], a[i]));
                        ms.insert(Area(m - a[i], a[i]));
                    }
                }
            }
        }
        //printf("%d\n", m);
        printf("Case #%d: %d\n", cas, result);
    }
    return 0;
}
