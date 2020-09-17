/*
 * 题目链接：http://codeforces.com/contest/914/problem/F
 * 题意：给一个长度1e5的string，然后有1e5次操作，操作1修改某一位的字符，操作2，输入l，r，x，问l到r中substring是x的个数。注意所有的查询x的长度和<1e5。
 * 题解：所有的查询x的长度和<1e5是个关键信息，那么我们可以维护26个bitset，表示每个字母在string的位置。
 *       操作1直接修改bitset就行，对于操作2，要查询的x比如是abcb的话，那其实就是
 *       (bs[a] >> 0) & (bs[b] >> 1) & (bs[c] >> 2) & (bs[b] >> 3)后在l到r-(y.size()-1)中1个个数，
 *       这个等价于l到末尾1的个数减去r - l + 1 - (y.size() - 1)到末尾1的个数。复杂度：1e5 * (1e5 / 32)。
 */

nclude <cstdio>
#include <iostream>
#include <cstring>
#include <bitset>
using namespace std;
 
const int N = 1e5 + 5;
//const int N = 10;
char s[N];
bitset<N> bs[26];
 
int main() {
    int q;
    cin >> s >> q;
    int len = strlen(s);
    for (int i = 0; i < len; ++i) {
        int ch = s[i] - 'a';
        bs[ch][i] = 1;
    }
 
    for (int t = 0; t < q; ++t) {
        int op, x, l, r;
        string y;
        cin >> op;
        if (op == 1) {
            cin >> x >> y;
            bs[s[x - 1] - 'a'][x - 1] = 0;
            bs[y[0] - 'a'][x - 1] = 1;
            s[x - 1] = y[0];
        } else {
            cin >> l >> r >> y;
            if (r - l + 1 < y.size()) {
                puts("0");
                continue;
            }
            bitset<N> nbs;
            nbs.reset();
            nbs = ~nbs;
            for (int i = 0; i < y.size(); ++i) {
                nbs &= (bs[y[i] - 'a'] >> i);
            }
            // cout << nbs << endl;
            nbs >>= (l - 1);
            int ans = nbs.count();
            nbs >>= (r - l + 1 - (y.size() - 1));
            // cout << nbs << endl;
            ans = ans - nbs.count();
            cout << ans << endl;
        }
    }
    return 0;
}
