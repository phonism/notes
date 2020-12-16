#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	map<int, int> mp;
	for (int i = 0; i < n - 1; ++i) {
		int l, r;
		cin >> l >> r;
		mp[l]++;
		mp[r]++;
	}


	vector<pair<int, int>> ans;

	vector<int> not_show;
	for (int i = 1; i <= n; ++i) {
		if (!mp.count(i)) {
			not_show.push_back(i);
		}
	}
	reverse(not_show.begin(), not_show.end());
	int pos = 0;

	bool ok = true;
	int pre = n;
	for (int i = n - 1; i >= 1; --i) {
		if (!mp.count(i)) {
			continue;
		}
		for (int j = 1; j < mp[i]; ++j) {
			if (pos >= not_show.size() || not_show[pos] > i) {
				ok = false;
				break;
			}
			ans.push_back(make_pair(pre, not_show[pos]));
			pre = not_show[pos];
			pos++;
		}
		ans.push_back(make_pair(pre, i));
		pre = i;
	}

	if (ok) {
		puts("YES");
		for (int i = 0; i < ans.size(); ++i) {
			cout << ans[i].first << " " << ans[i].second << endl;
		}
	} else {
		puts("NO");
	}
}
