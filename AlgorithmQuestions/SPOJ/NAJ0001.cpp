#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

const int maxn = 100100;
const int maxm = 50010;

inline int read() {
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	int x = 0;
	while (isdigit(c)) {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x;
}

int a[maxn], v[maxn*2], x[maxn*2], y[maxn*2];
vector<int> pos[1111];
vector<long long> sum[1111];
int has[1111], is[1111];
int prime[maxm];
bool check[maxm];
int cnt = 0;


void getPrime() {
    for (int i = 2; i < maxm; i++) {
        if (check[i] == false)
            prime[cnt++] = i;
        for (int j = 0; j < cnt; j++) {
            if (i * prime[j] > maxm)
                break;
            check[i * prime[j]] = true;
        }
    }
}

int p[maxm], c[maxm], tem;

void getPrimeDivisor(int x) {
    tem = 0;
    for (int i = 0; prime[i] * prime[i] <= x; i++) {
        int tmp = 0;
        while (x % prime[i] == 0) {
            tmp++;
            x /= prime[i];
        }
        if (tmp > 0) {
            p[++tem] = prime[i];
            c[tem] = tmp;
        }
    }
    if (x > 1) {
        p[++tem] = x;
        c[tem] = 1;
    }
}

int divisor[2000];
vector<int> di;

void getDivisor( int x ) {
    getPrimeDivisor(x);
    divisor[0] = 1;
    divisor[1] = 1;
    for (int i = 1; i <= tem; ++i ) {
        int nowNum = divisor[0];
        int base = 1;
        for (int j = 1; j <= c[i]; ++j) {
            base *= p[i];
            for (int k = 1; k <= divisor[0]; ++k) {
                divisor[++nowNum] = divisor[k] * base;
            }
        }
        divisor[0] = nowNum;
    }
    di.clear();
    for (int i = 1; i <= divisor[0]; i++) {
        if (divisor[i] <= 1100)
            di.push_back(divisor[i]);
    }
}

int main() {
    getPrime();
    int test = read();
    for (int cas = 1; cas <= test; cas++) {
        if (cas > 1)
            puts("");
        printf("Case #%d\n", cas);
        for (int i = 0; i < 1111; i++) {
            pos[i].clear();
            sum[i].clear();
        }

        memset(has, 0, sizeof(has));
        memset(is, 0, sizeof(is));
        int n = read(); int m = read();
        for (int i = 1; i <= n; i++) {
            a[i] = read();
        }
        for (int i = 0; i < m; i++) {
            v[i] = read();
            x[i] = read();
            y[i] = read();
            is[v[i]] = 1;
        }
        int tot = 0;
        for (int i = 1; i <= 1000; i++) {
            if (is[i] == 1) {
                has[i] = ++tot;
            }
        }
        for (int i = 1; i <= n; i++) {
            getDivisor(a[i]);
            for (int j = 0; j < di.size(); j++) {
                if (has[di[j]] > 0) {
                    long long tmp = 0;
                    int len = sum[has[di[j]]].size();
                    if (len != 0) {
                        tmp = sum[has[di[j]]][len-1];
                    }
                    pos[has[di[j]]].push_back(i);
                    sum[has[di[j]]].push_back(tmp + a[i]);
                }
            }
        }
        int deb = 414;
        for (int i = 0; i < m; i++) {
            if (pos[has[v[i]]].size() == 0) {
                puts("0");
                continue;
            }
            int len = pos[has[v[i]]].size();
            if (pos[has[v[i]]][0] > y[i]) {
                puts("0");
                continue;
            }
             if (pos[has[v[i]]][len-1] < x[i]) {
                puts("0");
                continue;
            }
            long long l = sum[has[v[i]]][lower_bound(pos[has[v[i]]].begin(), pos[has[v[i]]].end(), x[i]) - pos[has[v[i]]].begin() - 1];
            if (lower_bound(pos[has[v[i]]].begin(), pos[has[v[i]]].end(), x[i]) - pos[has[v[i]]].begin() == 0)
                l = 0;
            long long r = sum[has[v[i]]][upper_bound(pos[has[v[i]]].begin(), pos[has[v[i]]].end(), y[i]) - pos[has[v[i]]].begin() - 1];
            printf("%lld\n", r - l);
        }

    }
    return 0;
}

