#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 101000;
const int mod = 1000000007;

int n, a[maxn], c[maxn];

void modify(int x, int v) {
	for (int i = x; i <= n; i += i & -i)
		c[i] = (c[i] + v) % mod;
}

int query(int x) {
	int res = 0;
	for (int i = x; i; i -= i & -i)
		res = (res + c[i]) % mod;
	return res;
}


int main() {
	int test; scanf("%d", &test);
	for (int cas = 1; cas <= test; cas++) {
		scanf("%d", &n);
		vector<int> value;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			value.push_back(a[i]);
		}
		sort(value.begin(), value.end());
		value.erase(unique(value.begin(), value.end()), value.end());
		for (int i = 1; i <= n; i++) 
			a[i] = lower_bound(value.begin(), value.end(), a[i]) - value.begin() + 1;
		memset(c, 0, sizeof(c));
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int cur = (query(a[i] - 1) + 1) % mod;
			ans = (ans + cur) % mod;
			modify(a[i], cur);
		}
		printf("Case %d: %d\n", cas, ans);
	}
	return 0;
}
