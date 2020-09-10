/*
 * 题目链接：https://www.acwing.com/problem/content/92/
 * 题意：求a乘b对p取模的值，其中1<=a,b,p<=10^18
 * 题解：可以将b表示成二进制，那么对于每个2^k的系数要么是0，要么是a，类似于快速幂思想，a*2^k-1 -> a*2^k递推
 */

#include <bits/stdc++.h>
using namespace std;

long long fast_mul(long long a, long long b, long long p) {
    long long ans = 0;
    for (; b; b >>= 1) {
        if (b & 1) {
            ans = (ans + a) % p;
        } 
        a = a * 2 % p; 
    }
    return ans;
}

int main() {
    long long a, b, p;
    cin >> a >> b >> p;
    cout << fast_mul(a, b, p) << endl;
}
