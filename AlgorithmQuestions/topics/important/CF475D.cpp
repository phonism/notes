#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}

map<int, long long> mp[N], ans;

int main() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; ++i) {
		mp[i][a[i]]++;
		for (auto it : mp[i - 1]) {
			mp[i][gcd(it.first, a[i])] += it.second;
		}
		for (auto it : mp[i]) {
			ans[it.first] += it.second;
		}
	}
	
	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		cout << ans[x] << endl;
	}

}