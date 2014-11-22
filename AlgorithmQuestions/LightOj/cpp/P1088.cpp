#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

const int maxn = 100010;

int a[maxn];

int main() {
	int test;
	scanf("%d", &test);
	for (int cas = 1; cas <= test; cas++) {
		int n, q; scanf("%d %d", &n, &q);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		printf("Case %d:\n", cas);
		for (int i = 0; i < q; i++) {
			int l, r; scanf("%d %d", &l, &r);
			l = lower_bound(a, a + n, l) - a;
			r = upper_bound(a, a + n, r) - a - 1;
			printf("%d\n", r - l + 1);
		}
	}
}

