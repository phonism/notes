#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

const int maxn = 111;
int n, k;
int a[maxn], b[maxn], dp[maxn][200 * maxn];

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);

	memset(dp, -1, sizeof(dp));
	dp[0][10000] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= 20000; j++) {
			if (dp[i][j] == -1)
				continue;
			dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
			int x = j + a[i+1] - k * b[i+1];
			if (x >= 0 && x <= 20000)
				dp[i+1][x] = max(dp[i][j] + a[i+1], dp[i+1][x]);
		}
	}

	printf("%d\n", dp[n][10000] == 0 ? -1 : dp[n][10000]);
	return 0;
}
