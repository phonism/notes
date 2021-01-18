#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<int> h(n), t(m);

	multiset<int, greater<int>> st;

	for (int i = 0; i < n; ++i) {
		cin >> h[i];
		st.insert(h[i]);
	}
	for (int i = 0; i < m; ++i) {
		cin >> t[i];
		auto it = st.lower_bound(t[i]);
		if (it != st.end()) {
			cout << (*it) << endl;
			st.erase(it);
		} else {
			cout << -1 << endl;
		}
	}

}