/*
 * 题目链接：https://www.acwing.com/problem/content/95/
 * 题意：从1-n(n<20)个整数中，随机取m个，求所有可能的选择方案。
 * 题解：典型递归，自身调用自身 && 回溯时还原现场，及时剪枝
 */
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> chosen;

void calc(int x) {
    if (chosen.size() > m || chosen.size() + n - x + 1 < m) {
        return ;
    }
    if (x == n + 1) {
        if (chosen.size() == m) {
            for (int i = 0; i < chosen.size(); ++i) {
                printf("%d ", chosen[i]);
            }
            puts("");
        }
        return ;
    }


    // chose x
    chosen.push_back(x);
    calc(x + 1);
    chosen.pop_back();
    // not chose x
    calc(x + 1);
}

int main() {
    cin >> n >> m;
    calc(1);
}
