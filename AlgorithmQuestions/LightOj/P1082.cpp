#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 100010;

int test, n, q;
int Log[maxn], f[17][maxn];

void init() {
	Log[1] = 0;
	for (int i = 2; i < maxn; i++) {
		Log[i] = Log[i-1];
		if (i & i - 1)
			continue;
		Log[i]++;
	}
}

void build() {
	for (int i = 1; i <= Log[n]; i++) {
		for (int j = 1; j <= n; j++) {
			if (j + (1<<i) - 1 > n) {
				break;
			}
			f[i][j] = min(f[i-1][j], f[i-1][j+(1<<i-1)]);
		}
	}
}


int main() {
	init();
	scanf("%d", &test);
	for (int cas = 1; cas <= test; cas++) {
		scanf("%d %d", &n, &q);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &f[0][i]);
		}
		build();
		printf("Case %d:\n", cas);
		for (int i = 0; i < q; i++) {
			int l, r; scanf("%d %d", &l, &r);
			int t = Log[r-l+1];
			printf("%d\n", min(f[t][l], f[t][r-(1<<t)+1]));
		}
	}
	return 0;
}
