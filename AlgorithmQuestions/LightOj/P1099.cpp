#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

const int maxn = 5050;
const int maxm = 100100;

int a[maxm*2][3], b[maxn], d[maxn][2];
bool in[maxn];

int main() {
	int test, n, m;
	scanf("%d", &test);
	for (int cas = 1; cas <= test; cas++) {
		scanf("%d %d", &n, &m);
		memset(b, 0, sizeof(b));
		for (int i = 1; i <= m; i++) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			a[i][0] = v; a[i][1] = w; a[i][2] = b[u]; b[u] = i;
			a[i+m][0] = u; a[i+m][1] = w; a[i+m][2] = b[v]; b[v] = i + m;
		}

		memset(d, 63, sizeof(d));
		d[1][0] = 0;
		queue<int> Q;
		Q.push(1);
		in[1] = true;
		while(!Q.empty()) {
			int u = Q.front();
			Q.pop();
			in[u] = false;
			for (int i = b[u]; i; i = a[i][2]) {
				int v = a[i][0];
				for (int j = 0; j < 2; j++) {
					if (d[u][j] + a[i][1] < d[v][0]) {
						d[v][1] = d[v][0];
						d[v][0] = d[u][j] + a[i][1];
						if (!in[v]) {
							in[v] = true;
							Q.push(v);
						}
					}
					if (d[u][j] + a[i][1] > d[v][0] && d[u][j] + a[i][1] < d[v][1]) {
						d[v][1] = d[u][j] + a[i][1];
						if (!in[v]) {
							in[v] = true;
							Q.push(v);
						}
					}
				}
			}
		}
		printf("Case %d: %d\n", cas, d[n][1]);
	}
	return 0;
}
