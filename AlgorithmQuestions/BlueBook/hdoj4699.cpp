/*
 * 题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=4699
 * 题意：模拟打字操作，有insert，left，right，delete操作，然后query x，问前x数中最大的前项和是多少，x小于当前光标所在处
 * 题解：维护两个栈，表示当前光标左边的数和右边的数有哪些，同时维护当前光标之前前项和和最大前项和
 *
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int ans[N], sum[N];

stack<int> s, ss;

int main() {
    int q, x;
    char ch[10];
    ans[0] = -1e9;
    while (scanf("%d", &q) == 1) {
        while (!s.empty()) {
            s.pop();
        }
        while (!ss.empty()) {
            ss.pop();
        }
        for (int t = 0; t < q; ++t) {
            scanf("%s", ch);
            if (ch[0] == 'I') {
                scanf("%d", &x);
                s.push(x);
                sum[s.size()] = sum[s.size() - 1] + s.top();
                ans[s.size()] = max(ans[s.size() - 1], sum[s.size()]);
            } else if (ch[0] == 'D') {
                if (s.empty()) {
                    continue;
                }
                s.pop();
            } else if (ch[0] == 'L') {
                if (s.empty()) {
                    continue;
                }
                ss.push(s.top());
                s.pop();
            } else if (ch[0] == 'R') {
                if (ss.empty()) {
                    continue;
                }
                s.push(ss.top());
                ss.pop();
                sum[s.size()] = sum[s.size() - 1] + s.top();
                ans[s.size()] = max(ans[s.size() - 1], sum[s.size()]);
            } else if (ch[0] == 'Q') {
                scanf("%d", &x);
                printf("%d\n", ans[x]);
            }
        }
    }
}
