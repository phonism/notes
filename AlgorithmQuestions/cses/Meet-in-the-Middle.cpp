#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int mid = n / 2;
	map<int, int> mp;
	for (int mask = 0; mask < (1 << mid); ++mask) {
		long long tmp = 0;
		for (int i = 0; i < mid; ++i) {
			if (mask & (1 << i)) {
				tmp += a[i];
			}
		}
		if (tmp > x) {
			continue;
		}
		mp[tmp]++;
		// mp[tmp]++;
	}

	long long ans = 0;
	int cnt = n - mid;
	for (int mask = 0; mask < (1 << cnt); ++mask) {
		long long tmp = 0;
		for (int i = mid; i < n; ++i) {
			if (mask & (1 << (i - mid))) {
				tmp += a[i];
			}
		}
		if (tmp <= x) {
			auto it = mp.find(x - tmp);
			if (it != mp.end()) {
				ans += mp[x - tmp];
			}
		}
	}
	cout << ans << endl;
}