#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <bitset>
#include <unordered_map>
#include <vector>
using namespace std;
 
 
long long fast_mod(long long a, long long b, long long p) {
    long long ans = 1 % p;
    long long tmp = a;
    for (; b > 0; b /= 2) {
        if (b % 2 == 1) {
            ans = ans * tmp % p;
        }
        tmp = tmp * tmp % p;
    }
    return ans;
}
 
unordered_map<int, int> mp;
vector<int> re;
 
int main() {
    long long n, x, m;
    cin >> n >> x >> m;
    long long tmp = x;
    int left = -1, right = -1;
    re.push_back(0);
    re.push_back(x % m);
    mp[x % m] = 1;
    for (int i = 2; i <= n; i++) {
        tmp = (tmp * tmp) % m;
        auto it = mp.find(tmp);
        if (it != mp.end()) {
            left = it->second;
            right = i - 1;
            break;
        } else {
            re.push_back(tmp);
            mp[tmp] = i;
        }
    }
    long long sum = 0, one_sum = 0;
    if (left != -1) {
        // cout << left << " " << right << endl;
        for (int i = 1; i < left; ++i) {
            sum += re[i];
        }
        for (int i = left; i <= right; ++i) {
            one_sum += re[i];
        }
        long long len = right - left + 1;
        long long new_n = n - (left - 1);
        long long s = new_n / len;
        sum += s * one_sum;
        // cout << one_sum << " " << s << endl;
        for (int i = 1; i <= new_n - s * len; i++) {
            sum += re[left + i - 1];
        }
    } else {
        for (int i = 1; i <= n; ++i) {
            sum += re[i];
        }
    }
    cout << sum << endl;
}
