/*
 * 题目链接：http://codeforces.com/contest/879/problem/C
 * 题意：给n个二进制操作，让构造小于等于5个二进制操作，使得无论输入是多少，经过这些操作后，结果是一样的。
 * 题解：按位去枚举0或者1的情况，根据n个操作后每一个是0还是1来决定这一位用什么操作。注意&|^的操作顺序。
 */

#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    int zero = 0, one = 1023;
    for (int i = 0; i < n; ++i) {
        char ch;
        int x;
        cin >> ch >> x;
        if (ch == '|') {
            zero |= x;
            one |= x;
        } else if (ch == '&') {
            zero &= x;
            one &= x;
        } else {
            zero ^= x;
            one ^= x;
        }
    }
 
    int AND = 0, OR = 0, XOR = 0;
    // cout << (1 << 0) << endl;
    // cout << (1 ^ 1) << endl;
 
    for (int i = 0; i < 10; ++i) {
        int tmp_zero = zero & 1;
        int tmp_one = one & 1;
 
        if (tmp_zero == 0) {
            if (tmp_one == 1) {
                // cout << i << endl;
                AND += 1 << i;
            } else {
                
            }
        } else {
            if (tmp_one == 0) {
                XOR += 1 << i;
                AND += 1 << i;
            } else {
                OR += 1 << i;
                AND += 1 << i;
            }
        }
        zero >>= 1;
        one >>= 1;
    }
    
    // cout << (((5 & 1021) ^ 0) | 1) << endl;
    // cout << (((5 | 3) ^ 2) | 1) << endl;
 
    cout << 3 << endl;
    cout << "& " << AND << endl;
    cout << "| " << OR << endl;
    cout << "^ " << XOR << endl;
    return 0;
}
