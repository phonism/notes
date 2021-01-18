#include <bits/stdc++.h>
using namespace std;

const int N = 1111;

int f[4] = {1, 0, -1, 0};
int g[4] = {0, 1, 0, -1};
char op[4] = {'D', 'R', 'U', 'L'};

bool vis[N][N];
int n, m, a[N][N];	
pair<int, int> st, ed;

vector<char> ans;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			if (s[j] == 'A') {
				st = make_pair(i + 1, j + 1);
			}
			if (s[j] == 'B') {
				ed = make_pair(i + 1, j + 1);
			}
			if (s[j] == '#') {
				a[i + 1][j + 1] = 1;
			} else {
				a[i + 1][j + 1] = 0;
			}
		}
	}

	queue<pair<int, int>> q;
	q.push(st);

	map<pair<int, int>, pair<int, int>> pre;
	map<pair<int, int>, char> mp;

	vis[st.first][st.second] = true;
	while (!q.empty()) {
		auto u = q.front();
		q.pop();
		int x = u.first;
		int y = u.second;
		if (u == ed) {
			while (u != st) {
				ans.push_back(mp[u]);
				u = pre[u];
			}
			break;
		}
		for (int i = 0; i < 4; ++i) {
			int nx = x + f[i];
			int ny = y + g[i];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
				if (a[nx][ny] == 1 || vis[nx][ny]) {
					continue;
				}
				auto v = make_pair(nx, ny);
				vis[nx][ny] = true;
				pre[v] = u;
				mp[v] = op[i];
				q.push(v);
			}
		}
	}

	reverse(ans.begin(), ans.end());

	if (ans.size() > 0) {
		cout << "YES" << endl;
		cout << ans.size() << endl;
		for (auto ch : ans) {
			cout << ch;
		}
		cout << endl;
	} else {
		cout << "NO" << endl;
	}
}