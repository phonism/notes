#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	long long ans = 1;
	if (k == 1 || k > n) {
		for (int i = 1; i <= n; ++i) {
			ans = ans * m;
			ans %= MOD;
		}
	} else if (k == n) {
		for (int i = 1; i <= (n + 1) / 2; ++i) {
			ans = ans * m;
			ans %= MOD;
		}
	} else if (k % 2) {
		ans = m * m % MOD;
	} else {
		ans = m;
	}
	cout << ans << endl;
}
