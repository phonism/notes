/*
 * 题目链接：https://cses.fi/problemset/task/1094
 * 题意：给出n个数，可以对n个数做+1操作，问需要加多少可以让整个数组变成不降序列
 * 题解：和上一个比，少了就补齐
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int prev = 0;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        if (i == 0) {
            prev = x;
            continue;
        }
        if (x < prev) {
            ans += prev - x;
        } else {
            prev = x;
        }
    }
    printf("%lld\n", ans);
}
