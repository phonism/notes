#include <bits/stdc++.h>
using namespace std;

vector<int> get_bit(int x) {
	vector<int> bit(32);
	for (int i = 0; i < 32; ++i) {
		if (x & (1 << i)) {
			bit[i] = 1;
		}
	}
	return bit;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	stack<int> s;

	vector<int> l(n + 1), r(n + 1);
	int idx = 1;
	while (idx <= n) {
		if (!s.empty() && a[idx] > a[s.top()]) {
			r[s.top()] = idx;
			s.pop();
		} else {
			s.push(idx);
			idx++;
		}
	}
	while (!s.empty()) {
		r[s.top()] = n + 1;
		s.pop();
	}

	idx = n;
	while (idx >= 1) {
		if (!s.empty() && a[idx] >= a[s.top()]) {
			l[s.top()] = idx;
			s.pop();
		} else {
			s.push(idx);
			idx--;
		}
	}
	while (!s.empty()) {
		l[s.top()] = 0;
		s.pop();
	}


	vector<long long> lst[32];
	vector<long long> rst[32];
	for (int i = 0; i < 32; ++i) {
		lst[i].resize(n + 1);
		rst[i].resize(n + 1);
	}

	vector<int> pre(32, -1);

	for (int i = 1; i <= n; ++i) {
		vector<int> bit = get_bit(a[i]);
		for (int j = 0; j < 32; ++j) {
			lst[j][i] = pre[j];
			if (bit[j]) {
				pre[j] = i;
			}
		}
	}

	fill(pre.begin(), pre.end(), n + 1);

	for (int i = n; i >= 1; --i) {
		vector<int> bit = get_bit(a[i]);
		for (int j = 0; j < 32; ++j) {
			rst[j][i] = pre[j];
			if (bit[j]) {
				pre[j] = i;
			}
		}
	}
	// cout << "FUCK " << r[1] << endl;

	long long ans = 0;

	for (int i = 1; i <= n; ++i) {
		long long ll = l[i] + 1;
		long long rr = r[i] - 1;
		long long l1 = -1;
		long long r1 = n + 1;

		for (int j = 0; j < 32; ++j) {
			if (a[i] & (1 << j)) {
				continue;
			}
			l1 = max(l1, lst[j][i]);
			r1 = min(r1, rst[j][i]);
		}


		long long tmp = ans;
		if (l1 < ll) {
			if (r1 > rr) {
				continue;
			} else {
				ans += (i - ll + 1) * (rr - r1 + 1);
			}
		} else {
			if (r1 > rr) {
				ans += (l1 - ll + 1) * (rr - i + 1);
			} else {
				ans += (l1 - ll + 1) * (rr - i + 1) + (rr - r1 + 1) * (i - ll + 1) - (l1 - ll + 1) * (rr - r1 + 1);
			}
		}
		// cout << i << " " << ll << " " << rr << " " << l1 << " " << r1 << " " << ans - tmp << endl;
	}
	cout << ans << endl;
}
