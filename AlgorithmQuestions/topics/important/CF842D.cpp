#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
const int B = 20;

int delta = 0;

struct TrieNode {
	TrieNode* son[2];
	int cnt;
	bool change;

	TrieNode() {
		cnt = 0;
		son[0] = NULL;
		son[1] = NULL;
	}
};

void insert(TrieNode* root, int x) {
	TrieNode* p = root;
	for (int i = B; i >= 0; --i) {
		int tmp = (x >> i) & 1;
		if (p->son[tmp] == NULL) {
			p->son[tmp] = new TrieNode();
		}
		p = p->son[tmp];
		p->cnt += 1;
	}
}

int query(TrieNode* p) {
	int ans = 0;
	for (int i = B; i >= 0; --i) {
		int l = 0;
		int r = 1;
		if (delta & (1 << i)) {
			r = 0;
			l = 1;
		}
		if (!p->son[l]) {
			p = p->son[l];
		} else {
			if (p->son[l]->cnt < (1 << i)) {
				p = p->son[l];
			} else {
				p = p->son[r];
				ans += (1 << i);
			}
		}
		if (p == NULL) {
			return ans;
		}
	}
	return ans;
}


int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	TrieNode* root = new TrieNode();

	for (int i = 0; i < n; ++i) {
		if (i > 0 && a[i] == a[i - 1]) {
			continue;
		}
		insert(root, a[i]);
	}

	for (int i = 0; i < m; ++i) {
		int x;
		cin >> x;
		delta ^= x;
		cout << query(root) << endl;
	}
}