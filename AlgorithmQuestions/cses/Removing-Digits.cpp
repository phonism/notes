#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 111;

int dp[N];

int dfs(int n) {
	if (n == 0) {
		return 0;
	}
	if (dp[n] != -1) {
		return dp[n];
	}
	int x = n;
	vector<int> v;
	while (x) {
		v.push_back(x % 10);
		x /= 10;
	}
	int res = 1e9;
	for (auto i : v) {
		if (i == 0) {
			continue;
		}
		int tmp = dfs(n - i);
		res = min(res, tmp);
	}
	dp[n] = res + 1;
	return dp[n];
}

int main() {
	int n;
	cin >> n;
	memset(dp, -1, sizeof(dp));
	cout << dfs(n) << endl;
}