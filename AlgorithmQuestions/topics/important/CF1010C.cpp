#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		a[i] = x % k;
		if (a[i] == 0) {
			a[i] = k;
		}
	}
	bool ok = false;
	int tmp = k;
	for (int i = 0; i < n; ++i) {
		if (gcd(a[i], k) == 1) {
			ok = true;
			break;
		} else {
			tmp = gcd(tmp, a[i]);
		}
	}

	if (ok) {
		cout << k << endl;
		for (int i = 0; i < k; ++i) {
			cout << i << " ";
		}
		cout << endl;
	} else {
		vector<int> ans;
		for (int i = 0; i < k; ++i) {
			if (i % tmp == 0) {
				ans.push_back(i);
			}
		}
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); ++i) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}

}