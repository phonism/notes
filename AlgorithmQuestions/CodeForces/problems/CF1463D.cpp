#include <bits/stdc++.h>
using namespace std;

int main() {
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		vector<int> a(n + 2);
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}

		a[0] = 0;

		int pre = 0;
		int min_res = 0;
		for (int i = 1; i <= n; ++i) {
			if (a[i] - a[i - 1] > 1) {
				pre += a[i] - a[i - 1] - 1;
			}
			if (pre > 0) {
				pre--;
			} else {
				min_res++;
			}

		}

		a[n + 1] = 2 * n + 1;
		pre = 0;
		int max_res = 0;
		for (int i = n; i >= 1; --i) {
			if (a[i + 1] - a[i] > 1) {
				pre += a[i + 1] - a[i] - 1;
			}
			if (pre > 0) {
				pre--;
			} else {
				max_res++;
			}
		}

		// cout << min_res << " " << max_res << endl;


		max_res = n - max_res;

		cout << max_res - min_res + 1 << endl;

	}
}