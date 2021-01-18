#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int a[N];

struct SegNode {
	int l, r;
	long long lsum, rsum, sum;
	long long mx;
} tree[N * 4];

void pushup(int p) {
	tree[p].lsum = max(tree[p * 2].lsum, tree[p * 2].sum + tree[p * 2 + 1].lsum);
	tree[p].rsum = max(tree[p * 2 + 1].rsum, tree[p * 2].rsum + tree[p * 2 + 1].sum);
	tree[p].sum = tree[p * 2].sum + tree[p * 2 + 1].sum;
	tree[p].mx = max(tree[p * 2].mx, tree[p * 2 + 1].mx);
	tree[p].mx = max(tree[p].mx, tree[p * 2].rsum + tree[p * 2 + 1].lsum);
}

void build(int p, int l, int r) {
	tree[p].l = l;
	tree[p].r = r;
	if (tree[p].l == tree[p].r) {
		tree[p].lsum = tree[p].rsum = tree[p].sum = a[l];
		tree[p].mx = a[l];
		return ;
	}
	int mid = (tree[p].l + tree[p].r) / 2;
	build(p * 2, l, mid);
	build(p * 2 + 1, mid + 1, r);
	pushup(p);
}

void update(int p, int x, int v) {
	if (tree[p].l == tree[p].r) {
		tree[p].lsum = v;
		tree[p].rsum = v;
		tree[p].sum = v;
		tree[p].mx = v;
		return ;
	}
	int mid = (tree[p].l + tree[p].r) / 2;
	if (x <= mid) {
		update(p * 2, x, v);
	}
	if (x > mid) {
		update(p * 2 + 1, x, v);
	}
	pushup(p);
}

SegNode query(int p, int l, int r) {
	if (l <= tree[p].l && tree[p].r <= r) {
		return tree[p];
	}
	int mid = (tree[p].l + tree[p].r) / 2;
	SegNode lr, rr, res;
	if (l <= mid) {
		lr = query(p * 2, l, r);
	}
	if (r > mid) {
		rr = query(p * 2 + 1, l, r);
	}
	if (l > mid) {
		return rr;
	}
	if (r <= mid) {
		return lr;
	}
	res.lsum = max(lr.lsum, lr.sum + rr.lsum);
	res.rsum = max(rr.rsum, lr.rsum + rr.sum);
	res.sum = lr.sum + rr.sum;
	res.mx = max(lr.mx, rr.mx);
	res.mx = max(res.mx, lr.rsum + rr.lsum);
	return res;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	build(1, 1, n);
	for (int i = 0; i < m; ++i) {
		int x, v;
		cin >> x >> v;
		update(1, x, v);
		SegNode res = query(1, 1, n);
		cout << max(0LL, res.mx) << endl;
	}
}