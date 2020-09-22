/*
 * 题目链接：https://cses.fi/problemset/task/1069
 * 题意：给出一个字符串，问最长连续一样的字母长度是多少。
 * 题解：记录当前重复的个数，遍历字符串，和前一个字母去比较，然后更新重复的个数
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int ans = 1, tmp = 1;
    for (int i = 1; i < s.length(); ++i) {
        if (s[i] == s[i - 1]) {
            tmp += 1;
            ans = max(ans, tmp);
        } else {
            tmp = 1;
        }
    }
    cout << ans << endl;
}
