#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int a[N];

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

vector<int> get_fac(int x) {
    vector<int> p;
    int tmp = x;
    for (int i = 0; prime[i] * prime[i] <= tmp; ++i) {
        if (x % prime[i] == 0) {
            p.push_back(prime[i]);
        }
        while (x % prime[i] == 0) {
            x /= prime[i];
        }
    }
    if (x != 1) {
        p.push_back(x);
    }
    return p;
}

int cnt[N];

int main() {
    get_prime();
    int n;
    cin >> n;
    int del = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] == 1) {
            del += 1;
            continue;
        }
        vector<int> p = get_fac(a[i]);
        for (auto _ : p) {
            cnt[_] += 1;
        }
    }
    if (del == n) {
        puts("pairwise coprime");
        return 0;
    }
    int mn = N, mx = -N;
    for (int i = 1; i < N; ++i) {
        if (cnt[i] == 0) {
            continue;
        }
        mn = min(mn, cnt[i]);
        mx = max(mx, cnt[i]);
    }
    if (mx == 1) {
        puts("pairwise coprime");
    } else if (mx < n) {
        puts("setwise coprime");
    } else {
        puts("not coprime");
    }
    return 0;

}
