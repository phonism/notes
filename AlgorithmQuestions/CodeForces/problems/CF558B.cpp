#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 100100;

int a[maxn];
map<int, int> mp;
map<int, int> first, last;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (mp.find(a[i]) == mp.end()) {
            mp[a[i]] = 1;
        } else {
            mp[a[i]] += 1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (first.find(a[i]) == first.end())
            first[a[i]] = i;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (last.find(a[i]) == last.end())
            last[a[i]] = i;
    }
    map<int, int>::iterator it;
    int maxNum = 0;
    vector<int> num;
    for (it = mp.begin(); it != mp.end(); it++) {
        if (maxNum < it->second) {
            maxNum = it->second;
            num.clear();
            num.push_back(it->first);
        } else if (maxNum == it->second) {
            num.push_back(it->first);
        }
    }
    int ans = maxn;
    int ansl = 0, ansr = 0;
    for (int i = 0; i < num.size(); i++) {
        if (last[num[i]] - first[num[i]] < ans) {
            ans = last[num[i]] - first[num[i]];
            ansl = first[num[i]];
            ansr = last[num[i]];
        }
    }
    printf("%d %d\n", ansl + 1, ansr + 1);
}
