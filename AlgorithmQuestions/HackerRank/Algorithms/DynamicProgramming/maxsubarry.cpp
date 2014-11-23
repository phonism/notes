#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int maxn = 100100;
int a[maxn];

int main() {
	int test; scanf("%d", &test);
	for (int cas = 1; cas <= test; cas++) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		int answer1 = -1000000007;
		int tmp = 0, answer2 = 0;
		for (int i = 0; i < n; i++) {
			tmp += a[i];
			answer1 = max(answer1, tmp);
			if (tmp < 0)
				tmp = 0;
			if (a[i] > 0)
				answer2 += a[i];
		}
		if (answer2 == 0) {
			answer2 = -1000000007;
			for (int i = 0; i < n; i++) {
				answer2 = max(answer2, a[i]);
			}
		}
		printf("%d %d\n", answer1, answer2);
	}
	return 0;
}
			
