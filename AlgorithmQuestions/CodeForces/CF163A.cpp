#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

const int maxn = 5050;

char s[maxn], t[maxn];
int f[maxn][maxn];

int main() {

	scanf("%s %s", s + 1, t + 1);
	int lenS = strlen(s + 1);
	int lenT = strlen(t + 1);
	int answer = 0;

	for (int i = 1; i <= lenS; i++) {
		for (int j = 1; j <= lenT; j++) {
			if (s[i] == t[j]) {
				f[i][j] += f[i-1][j-1] + 1;
				f[i][j] %= 1000000007;
			}
			f[i][j+1] = f[i][j];
		}
		answer += f[i][lenT];
		answer %= 1000000007;
	}
	printf("%d\n", answer);
	return 0;

}
