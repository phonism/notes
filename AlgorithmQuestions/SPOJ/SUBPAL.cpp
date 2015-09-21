#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int maxn = 100100;
int test, n;
char str[maxn];
map<int, vector<int> > mp;

int main() {
    scanf("%d", &test);
    for (int cas = 1; cas <= test; cas++) {
        mp.clear();
        scanf("%s", str + 1);
        n = strlen(str + 1);
        int mask = 0;
        mp[mask].push_back(0);
        for (int i = 1; i <= n; i++) {
            mask ^= (1 << (str[i] - 'a'));
            mp[mask].push_back(i);
        }
        int ans = 0;
        map<int, vector<int> >::iterator it = mp.begin();
        for ( ; it != mp.end(); it++) {
            mask = it->first;
            ans = std::max(ans, mp[mask].back() - mp[mask].front());
            for (int i = 0; i < 26; i++) {
                int fmask = mask ^ (1 << i);
                if (mp.find(fmask) != mp.end()) {
                    ans = std::max(ans, mp[mask].back() - mp[fmask].front());
                    ans = std::max(ans, mp[fmask].back() - mp[mask].front());
                }
            }
        }
        printf("Case %d: %d\n", cas, ans);
    }
}
