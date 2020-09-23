/*
 * 题目链接：https://cses.fi/problemset/task/1646/
 * 题意：给n个数，q个查询，查询l到r区间和
 * 题解：预处理维护前项和数组即可
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
 
const int N = 2e5 + 8;
int a[N];
long long s[N] = {0};
 
int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        s[i] = s[i - 1] + a[i];
 
    }
    for (int i = 0; i < q; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%lld\n", s[y] - s[x - 1]);
    }
    return 0;
}
