#include <cstdio>
#include <map>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int test, n;
    scanf("%d", &test);
    for (int cas = 1; cas <= test; cas++) {
        map<int, priority_queue<int, vector<int>, greater<int> > > team;
        map<int, priority_queue<int, vector<int>, greater<int> > >::iterator it;
        scanf("%d", &n);
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            int tmp = a[i], cur = 0;
            it = team.find(tmp-1);
            if (it != team.end()) {
                if (it->second.size()) {
                    cur = it->second.top();
                    it->second.pop();
                }
            }
            cur += 1;
            team[tmp].push(cur);
        }
        int ans = 1000000010;
        for (it = team.begin(); it != team.end(); it++) {
            if (it->second.size()) {
                ans = min(ans, it->second.top());
            }
        }
        if (ans >= 1000000010)
            ans = 0;
        printf("%d\n", ans);
    }
}
