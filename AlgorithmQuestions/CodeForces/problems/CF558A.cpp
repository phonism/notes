#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

struct Tree {
    int x, num;
    bool friend operator<(Tree a, Tree b) {
        return a.x < b.x;
    }
};

Tree t[1111];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &t[i].x, &t[i].num);
    }
    sort(t, t + n);
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        if (t[i].x < 0) {
            l += 1;
        } else {
            r += 1;
        }
    }
    int ans = 0;
    if (l < r) {
        for (int i = 0; i < l * 2 + 1; i++) {
            ans += t[i].num;
        }
    } else if (l == r) {
        for (int i = 0; i < n; i++) {
            ans += t[i].num;
        }
    } else {
        for (int i = n - 1; i > n - 1 - r * 2 - 1; i--) {
            ans += t[i].num;
        }
    }
    printf("%d\n", ans);
}
