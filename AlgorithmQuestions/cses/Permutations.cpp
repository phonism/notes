/*
 * 题目链接：https://cses.fi/problemset/task/1070/
 * 题意：给1-n个数，构造一个序列，使得相邻两个数差的大于1
 * 题解：n<=4的情况，枚举一下，n>5后很容易发现跳着去构造序列就好
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    if (n == 2 || n == 3) {
        puts("NO SOLUTION");
    } else if (n == 4) {
        puts("3 1 4 2");
    } else if (n == 1) {
        puts("1");
    } else {
        vector<int> ans;
        for (int i = 1; i <= n; i += 2) {
            ans.push_back(i);
        }
        for (int i = 2; i <= n; i += 2) {
            ans.push_back(i);
        }
        for (int i = 0; i < ans.size(); ++i) {
            if (i == 0) {
                printf("%d", ans[i]);
            } else {
                printf(" %d", ans[i]);
            }
        }
        puts("");
    }
}
