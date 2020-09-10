/*
 * 题目链接：https://www.acwing.com/problem/content/1000/
 * 题意：给定n个位运算操作，每个有op（操作类型）和t，然后给一个m，问0-m的所有数中经过这n个操作后最大值是多少
 * 题解：显然，按二进制去枚举每一位0或者1，在经历n次操作后，这一位变成多少，然后从高位去贪心就行。
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int ans0[32], ans1[32], ans[32];
    for (int i = 0; i < 31; ++i) {
        ans0[i] = 0;
        ans1[i] = 1;
    }

    for (int i = 0; i < n; ++i) {
        string op;
        int t;
        cin >> op >> t;
        for (int j = 0; j < 31; ++j) {
            int tem = (t >> j) & 1;
            if (op == "AND") {
                ans0[j] = ans0[j] & ((t >> j) & 1);
                ans1[j] = ans1[j] & ((t >> j) & 1);
            } else if (op == "OR") {
                ans0[j] = ans0[j] | ((t >> j) & 1);
                ans1[j] = ans1[j] | ((t >> j) & 1);
            } else if (op == "XOR") {
                ans0[j] = ans0[j] ^ ((t >> j) & 1);
                ans1[j] = ans1[j] ^ ((t >> j) & 1);
            }
        }
    }
    for (int i = 0; i < 31; ++i) {
        ans[i] = max(ans0[i], ans1[i]);
    }
    int cur = 0;
    int final_ans = 0;
    for (int i = 30; i >= 0; --i) {
        if (max(ans0[i], ans1[i]) == 0) {
            continue;
        } else {
            if (ans0[i] == 1) {
                final_ans += 1 << i;
            } else {
                if ((cur + (1 << i)) > m) {
                    continue;
                } else {
                    cur += 1 << i;
                    final_ans += 1 << i;
                }
            }
        }
    }
    cout << final_ans << endl;
}
