#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	map<int, int> mp;

	for (int i = 0; i < (1 << n); ++i) {
		mp[i] = 1;
	}

	vector<string> ans;
	mp.erase(0);
	string s;
	for (int i = 0; i < n; ++i) {
		s += "0";
	}
	ans.push_back(s);
	int pre = 0;
	while (!mp.empty()) {
		int x = pre;
		vector<int> bit(n, 0);
		for (int i = 0; i < n; ++i) {
			if (x & (1 << i)) {
				bit[i] = 1;
			}
		}

		for (int i = 0; i < n; ++i) {
			vector<int> new_bit = bit;
			new_bit[i] = 1 - new_bit[i];
			string s = "";
			for (int j = 0; j < new_bit.size(); ++j) {
				s += char('0' + new_bit[j]);
			}
			int tmp = 0;
			for (int j = 0; j < n; ++j) {
				tmp += (1 << j) * new_bit[j];
			}
			if (mp.count(tmp)) {
				pre = tmp;
				mp.erase(tmp);
				ans.push_back(s);
				break;
			}
		}
	}

	for (auto s : ans) {
		cout << s << endl;
	}
}