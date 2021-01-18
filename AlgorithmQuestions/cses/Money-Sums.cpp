#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	vector<int> dp(sum + 1);
	dp[0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = sum; j >= a[i]; --j) {
			dp[j] = max(dp[j], dp[j - a[i]]);
		}
	}

	vector<int> ans;
	for (int i = 1; i <= sum; ++i) {
		if (dp[i]) {
			ans.push_back(i);
		}
	}
	cout << ans.size() << endl;
	for (auto u : ans) {
		cout << u << " ";
	}
	cout << endl;
}
