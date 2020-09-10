/*
 * 题目链接：https://www.acwing.com/problem/content/91/
 * 题意：求a的b次方对p取模的值，其中1<=a,b,p<=10^9
 * 题解：将b用二进制表示，然后根据a^(d+e)=a^d * a^e，这样对b的二进制从右到左遍历即可，判断每一位是否是1
 */

#include <bits/stdc++.h>
using namespace std;

long long fast_mod(int a, int b, int p) {
	long long ans = 1 % p;
	long long tmp = a;
	for (; b > 0; b /= 2) {
		if (b % 2 == 1) {
			ans = ans * tmp % p;
		}
		tmp = tmp * tmp % p;
	}
	return ans;
}

int main() {
	int a, b, p;
	cin >> a >> b >> p;
	cout << fast_mod(a, b, p) << endl;
}
