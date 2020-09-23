#include <bits/stdc++.h>
using namespace std;

int main() {
    int tests;
    scanf("%d", &tests);
    for (int t = 0; t < tests; ++t) {
        int n;
        scanf("%d", &n);
        unordered_map<int, int> mp;
        mp[n] = 1;
        int on = n;

        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                mp[i] = 1;
                if (n / i != 1) {
                    mp[n / i] = 1;
                }
            }
        }

        vector<int> p;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                p.push_back(i);
                while (n % i == 0) {
                    n /= i;
                }
            }
        }
        if (n > 1) {
            p.push_back(n);
        }

        unordered_map<int, int> mmp;
        vector<int> pp[100];
        for (auto it : mp) {
            int tmp = it.first;
            for (int i = 0; i < p.size(); ++i) {
                if (tmp % p[i] == 0) {
                    pp[i].push_back(tmp);
                    break;
                }
            }
        }

        unordered_map<int, int> visit;
        vector<int> ans;
        ans.push_back(on);
        visit[on] = 1;
        if (p[0] != on) {
            ans.push_back(p[0]);
            visit[p[0]] = 1;
        }
        bool ok = true;
        for (int i = 1; i < p.size(); ++i) {
            visit[p[i] * p[i - 1]] = 1;
        }
        for (int i = 0; i < p.size(); ++i) {
            if (i > 0) {
                if (p[i] * p[i - 1] == on) {
                    ok = false;
                } else {
                    ans.push_back(p[i] * p[i - 1]);
                }
            }
            for (int j = 0; j < pp[i].size(); ++j) {
                int tmp = pp[i][j];
                auto it = visit.find(tmp);
                if (it != visit.end()) {
                    continue;
                }
                visit[tmp] = 1;
                ans.push_back(tmp);
            }
        }
        for (int i = 0; i < ans.size(); ++i) {
            if (i == 0) {
                printf("%d", ans[i]);
            } else {
                printf(" %d", ans[i]);
            }
        }
        puts("");
        if (!ok) {
            puts("1");
        } else {
            puts("0");
        }
    }
}
