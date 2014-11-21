#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
	int n;
	scanf("%d", &n);
	int lm = INF, rm = -INF, um = -INF, dm = INF;
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		lm = min(lm, x);
		rm = max(rm, x);
		um = max(um, y);
		dm = min(dm, y);
	}
	long long d = max((rm - lm), (um - dm));
	long long answer = d * d;
	printf("%lld\n", answer);
	return 0;
}
