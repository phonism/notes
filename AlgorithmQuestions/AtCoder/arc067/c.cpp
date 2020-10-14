#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <bitset>
#include <vector>
using namespace std;
 
const int N = 1e3 + 10;
const int MOD = 1e9 + 7;
 
int cnt[N];
bool vis[N];
vector<int> prime;
 
void get_prime() {
    for (int i = 2; i < N; ++i) {
        if (!vis[i]) {
            prime.push_back(i);
            for (int j = 2; i * j < N; ++j) {
                vis[i * j] = 1;
            }
        }
    }
}
 
void get_fac(int x) {
    vector<int> p;
    int tmp = x;
    for (int i = 0; prime[i] * prime[i] <= tmp; ++i) {
        while (x % prime[i] == 0) {
            x /= prime[i];
            cnt[prime[i]]++;
        }
    }
    if (x != 1) {
        cnt[x]++;
    }
}
 
int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    get_prime();
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        get_fac(i);
    }
    long long ans = 1;
    for (int i = 2; i <= n; ++i) {
        ans *= (cnt[i] + 1);
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
