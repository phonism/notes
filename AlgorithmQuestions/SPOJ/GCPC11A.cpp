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

const int maxn = 2101000;
const long long inf = (long long)1 << (long long)63 - 1;
bool check[maxn];
int prime[maxn];
int cnt = 0;

void getPrime() {
    for (int i = 2; i < maxn; i++) {
        if (check[i] == false) {
            prime[cnt++] = i;
        }
        for (int j = 0; j < cnt; j++) {
            if (i * prime[j] >= maxn)
                break;
            check[i*prime[j]] = true;
        }
    }
}

int main() {
    getPrime();
    int test; scanf("%d", &test);
    for (int cas = 1; cas <= test; cas++) {
        long long n, k; scanf("%lld %lld", &n, &k);
        long long tmp = 0, ans2 = inf, ans = 4000000000000000000LL, haha = k;
        for (int i = 0; (long long) prime[i] * prime[i] <= haha; i++) {
            if (k % prime[i] == 0) {
                tmp = prime[i];
                long long tem = tmp, hehe = 0;
                while (n >= tem) {
                    hehe += n / tem;
                    if (tem > (inf / tmp))
                        break;
                    if (n / tem >= tmp)
                        tem *= tmp;
                    else
                        break;
                }
                long long hehe1 = 0;
                while (k % prime[i] == 0) {
                    k /= prime[i];
                    hehe1++;
                }
                if (hehe / hehe1 < ans) {
                    ans = hehe / hehe1;
                }
            }
        }
        if (k > 1) {
            long long tem = k, hehe = 0;
            while (n >= tem) {
                hehe += n / tem;
                if (tem > (inf / k))
                    break;
                if (tem * k < 0)
                    break;
                if (n / tem >= k)
                    tem *= k;
                else
                    break;
            }
            long long hehe1 = 1;
            if (hehe / hehe1 < ans) {
                ans = hehe / hehe1;
            }
        }
        printf("%lld\n", ans);
    }
}
