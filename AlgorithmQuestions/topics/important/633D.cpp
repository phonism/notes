#include <bits/stdc++.h>
using namespace std;


int main() {
	#define int long long
	int n;
	cin >> n;
	vector<int> a(n);
	int mx = -1;
	map<int, int> mp;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		mx = max(mx, a[i]);
		mp[a[i]]++;
	}

	map<pair<int, int>, int> already;
	int ans = -1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) {
				continue;
			}
			auto it = make_pair(a[i], a[j]);
			if (already.count(it)) {
				continue;
			}
			already[it] = 1;
			map<int, int> nmp;
			int x = a[i], y = a[j];
			nmp[x]++;
			nmp[y]++;
			int tmp = 2;
			while (y <= mx) {
				int nx = x + y;
				if (mp.count(nx) && mp[nx] > nmp[nx]) {
					nmp[nx]++;
					x = y;
					y = nx;
					tmp++;
				} else {
					break;
				}
			}
			ans = max(ans, tmp);
		}
	}
	cout << ans << endl;
}