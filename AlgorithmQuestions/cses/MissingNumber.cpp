/*
 * 题目链接：https://cses.fi/problemset/task/1083
 * 题意：给出n，然后n-1个[1,n]不同的数，问缺少的那个是多少
 * 题解：sum[1,n]减去n-1个数的和
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    long long sum = 0;
    for (int i = 1; i < n; ++i) {
        int x;
        scanf("%d", &x);
        sum += x;
    }
    printf("%lld\n", (long long)n * (n + 1) / 2 - sum);
}
