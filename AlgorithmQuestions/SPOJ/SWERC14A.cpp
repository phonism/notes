#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <map>
using namespace std;

void DameIt() {
    while (true) {
        puts("FUCK");
    }
}

int n; char ch[15][15];
map<char, int> mp;
vector<int> num(10);
int answer = 0;

long long getNum(char c[]) {
    int len = strlen(c);
    long long ans = 0;
    for (int i = 0; i < len; i++) {
        ans *= 10;
        ans += num[mp[c[i]]];
    }
    return ans;
}

bool use[100];

void dfs(int idx) {
    if (idx == mp.size() + 1) {
        long long tmp = 0;
        for (int i = 0; i < n; i++) {
            if (num[mp[ch[i][0]]] == 0)
                return ;
        }
        for (int i = 0; i < n - 1; i++) {
            tmp += getNum(ch[i]);
        }
        if (tmp == getNum(ch[n-1])) {
            answer++;
        }
        return ;
    }
    for (int i = 0; i <= 9; i++) {
        if (use[i] == false) {
            use[i] = true;
            num[idx] = i;
            dfs(idx + 1);
            use[i] = false;
            num[idx] = 0;
        }
    }
}

int main() {
    while (scanf("%d", &n) != EOF) {
        // c.clear();
        int idx = 0;
        for (int i = 0; i < n; i++) {
            scanf("%s", ch[i]);
            int len = strlen(ch[i]);
            for (int j = 0; j < len; j++) {
                if (!mp[ch[i][j]]) {
                    mp[ch[i][j]] = ++idx;
                }
            }
            // DameIt();
        }
        if (mp.size() > 10) {
            DameIt();
        }
        dfs(1);
        printf("%d\n", answer);
    }
}
