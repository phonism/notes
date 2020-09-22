/*
 * 题目链接：https://cses.fi/problemset/task/1068
 * 题意：输入n，如果n是偶数n=n/2，如果n是奇数n=n*3+1，输出一直执行这个操作，直至n=1的序列
 * 题解：按着操作模拟即可，注意爆int
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<long long> res;
    long long tmp = n;
    res.push_back(tmp);
    while (tmp != 1) {
        if (tmp & 1) {
            tmp = tmp * 3 + 1;
        } else {
            tmp = tmp / 2;
        }
        res.push_back(tmp);
    }
    for (int i = 0; i < res.size(); ++i) {
        if (i == 0) {
            printf("%lld", res[i]);
        } else {
            printf(" %lld", res[i]);
        }
    }
    puts("");
}
