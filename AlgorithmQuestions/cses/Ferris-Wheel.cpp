#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n), vis(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int ans = 0;
	sort(a.begin(), a.end());
	int j = n - 1;
	for (int i = 0; i < n; ++i) {
		if (vis[i]) {
			continue;
		}
		while (j > i && a[i] + a[j] > x) {
			j--;
		}
		if (j > i) {
			vis[j] = true;
			j--;
		}
		ans += 1;
	}
	cout << ans << endl;

}