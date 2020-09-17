/*
 * 题目链接：http://www.spoj.com/problems/KOMPICI/
 * 题意：给n个数，求有多少个pair至少有一个数字是一样的。
 * 题解：对于每个数，用10位的二进制表示0-9每个数字是否出现，然后遍历n个数字，对于新加的数字，
 *       枚举1<<10所有的状态，如果s&i>0，表示两个状态有相同数据，pal += cnt[i]。复杂度O(n * (1 << 10))
 */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
 
long long cnt[1 << 10] = {0};
 
int main() {
    int n;
    scanf("%d", &n);
    long long pal = 0;
    for (int t = 0; t < n; ++t) {
        long long x;
        long long tmp[10] = {0};
        scanf("%lld", &x);
        while (x) {
            tmp[x % 10] += 1;
            x /= 10;
        }
        int s = 0;
        for (int i = 0; i < 10; ++i) {
            if (tmp[i]) {
                s += 1 << i;
            }
        }
        for (int i = 0; i < 1 << 10; ++i) {
            if (i & s) {
                pal += cnt[i];
            }
        }
        cnt[s] += 1;
    }
    printf("%lld\n", pal);
    return 0;
}
