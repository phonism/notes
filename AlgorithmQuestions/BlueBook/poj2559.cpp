/*
 * 题目链接：http://poj.org/problem?id=2559
 * 题意：给出n个宽度为1的矩阵，顺序摆放，问能组成的最大的矩阵面积是多少
 * 题解：先思考一个问题，如果矩阵的高度是单调递增，那么最大的矩阵面积就是尝试以每个矩阵的高度作为最终矩形的高度，
 *       那么如果由一个比上一个小怎么办，如果比上一个小，那之前高的那些都没用了，因为即便后面有更高的，也因为
 *       当前这个短板，无法使用。所以中间那部分压缩一下就行，直接跳过。维护一个单调递增的栈。
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
long long s[N], w[N], a[N];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            break;
        }
        long long ans = 0;
        int cur = 0;
        for (int i = 0; i <= n; ++i) {
            s[i] = 0;
            w[i] = 0;
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        a[n] = 0;
        for (int i = 0; i <= n; ++i) {
            if (a[i] > s[cur]) {
                s[++cur] = a[i];
                w[cur] = 1;
            } else {
                long long width = 0;
                while (s[cur] > a[i]) {
                    width += w[cur];
                    ans = max(ans, width * s[cur]);
                    cur--;
                }
                s[++cur] = a[i];
                w[cur] = width + 1;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
