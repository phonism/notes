#include <bits/stdc++.h>
using namespace std;

const int N = 555;

long long d[N][N];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> d[i][j];
		}
	}

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	reverse(a.begin(), a.end());
	vector<long long> ans;
	for (int i = 0; i < n; ++i) {
		long long tmp = 0;
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				d[a[j]][a[k]] = min(d[a[j]][a[k]], d[a[j]][a[i]] + d[a[i]][a[k]]);
			}
		}
		for (int j = 0; j <= i; ++j) {
			for (int k = 0; k <= i; ++k) {
				tmp += d[a[j]][a[k]];
			}
		}
		ans.push_back(tmp);
	}

	for (int i = ans.size() - 1; i >= 0; --i) {
		if (i == 0) {
			cout << ans[i] << endl;
		} else {
			cout << ans[i] << " ";
		}
	}
}
