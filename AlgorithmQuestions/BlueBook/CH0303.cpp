/*
 * 题目链接：https://www.acwing.com/problem/content/96/
 * 题意：求1-n个数的全排列
 * 题解：递归，我们尝试把每个可用的数作为数列中的下一个数，求解"把剩余n-1个整数按照任意次序排列"这个子问题
 *
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 22;

int n, order[N];
bool chosen[N];

void calc(int k) {
    if (k == n + 1) {
        for (int i = 1; i <= n; ++i) {
            printf("%d ", order[i]);
        }
        puts("");
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (chosen[i]) {
            continue;
        }
        order[k] = i;
        chosen[i] = true;
        calc(k + 1);
        chosen[i] = false;
    }
}

int main() {
    scanf("%d", &n);
    memset(chosen, false, sizeof(chosen));
    calc(1);
}
