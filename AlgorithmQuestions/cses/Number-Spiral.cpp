/* 
 * 题目链接：https://cses.fi/problemset/task/1071
 * 题意：蛇形矩阵，第[x,y]位数是多少
 * 题解：观察规律即可
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int tests;
    scanf("%d", &tests);
    for (int t = 0; t < tests; ++t) {
        long long x, y;
        scanf("%lld %lld", &x, &y);
        long long ans = 0;
        if (x >= y) {
            if (x & 1) {
                ans = (x - 1) * (x - 1) + y;;
            } else {
                ans = x * x + 1 - y;
            }
        } else {
            if (y & 1) {
                ans = y * y + 1 - x;
            } else {
                ans = (y - 1) * (y - 1) + x;
            }
        }
        printf("%lld\n", ans);
    }
}
