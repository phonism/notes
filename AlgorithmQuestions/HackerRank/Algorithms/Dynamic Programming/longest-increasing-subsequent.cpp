#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 1000100;

int a[maxn], f[maxn], s[maxn];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	s[0] = -1;
	int tmp = 0, top = 0;
	for (int i = 0; i < n; i++) {
		tmp = a[i];
		if (tmp > s[top]) {
			s[++top] = tmp;
		} else {
			int left = 1, right = top;
			while (left <= right) {
				int mid = (left + right) >> 1;
				if (tmp > s[mid]) {
					left = mid + 1;
				} else {
					right = mid - 1;
				}
			}
			s[left] = tmp;
		}
	}

	printf("%d\n", top);
	return 0;
}
