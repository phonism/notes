/*
 * 题目链接：http://www.spoj.com/problems/ADACOINS/
 * 题意：给n个数，q个查询，每个查询有l，r，求n个数的子集和在[l,r]区间的不同和的个数。
 * 题解：因为这里限制了大小为1e5，所以可以维护1e5的bitset，那么对于前i个数所有能组成的子集和的状态为bs，那么前i+1个数的所有子集和为bs |= bs << a[i+1]，再维护个前缀和即可。
 */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <bitset>
using namespace std;
 
const int N = 1e5 + 10;
bitset<N> bs;
int sum[N] = {0};
 
int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    bs[0] = 1;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        bs |= bs << x;
    }
 
    for (int i = 1; i < N; ++i) {
        sum[i] = sum[i - 1] + bs[i];
    }
 
    for (int i = 0; i < q; ++i) {
        int b, e;
        scanf("%d %d", &b, &e);
        printf("%d\n", sum[e] - sum[b - 1]);
    }
 
    return 0;
}
