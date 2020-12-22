#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 100;

long long n, k, m;

pair<int, int> vec[N];

long long solve(vector<int> a) {
	int top = 0;
	for (int i = 0; i < a.size(); ++i) {
		if (!top || vec[top].first != a[i]) {
			vec[++top] = make_pair(a[i], 1);
		} else {
			vec[top].second++;
			vec[top].second %= k;
		}
		if (vec[top].second == 0) {
			top--;
		}
	}

	long long tmp = 0;
	for (int i = 1; i <= top; ++i) {
		tmp += vec[i].second;
	}

	long long tmp2 = 0;
	int l = 1, r = top;
	while (l < r && vec[l].first == vec[r].first) {
		if ((vec[l].second + vec[r].second) % k == 0) {
			tmp2 += vec[l].second + vec[r].second;
			l++;
			r--;
		} else {
			break;
		}
	}
	long long ans = 0;
	if (l == r) {
		ans = m * tmp - tmp2 * (m - 1) - (vec[l].second * m / k * k);
		if (vec[l].second * m % k == 0) {
			ans -= tmp2;
		}
	} else {
		if (vec[l].first == vec[r].first) {
			tmp2 += (vec[l].second + vec[r].second) / k * k;
		}
		ans = m * tmp - tmp2 * (m - 1);
	}
	return ans;
}

int main() {
	cin >> n >> k >> m;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	cout << solve(a) << endl;
}