/*
 * 题目链接：https://www.acwing.com/problem/content/94/
 * 题意：从1-n(n<20)个整数中，随机取任意多个，求所有可能的选择方案。
 * 题解：典型递归，自身调用自身 && 回溯时还原现场
 */
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> chosen;

void calc(int x) {
    if (x == n + 1) {
        for (int i = 0; i < chosen.size(); ++i) {
            printf("%d ", chosen[i]);
        }
        puts("");
        return ;
    }

    // not chose x
    calc(x + 1);

    // chose x
    chosen.push_back(x);
    calc(x + 1);
    chosen.pop_back();
}

int main() {
    cin >> n;
    calc(1);
}
