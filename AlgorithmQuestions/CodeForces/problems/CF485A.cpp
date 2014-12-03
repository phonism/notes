#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, m;
	scanf("%d %d", &a, &m);
	bool ok = false;
	for (int i = 0; i <= m; i++) {
		if (a == 0) {
			ok = true;
			break;
		}
		a += a % m;
		a %= m;
	}
	if (ok == true)
		puts("Yes");
	else
		puts("No");
	return 0;
}

