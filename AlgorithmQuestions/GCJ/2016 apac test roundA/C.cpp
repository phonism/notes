#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int inf = -112345679;
const int maxn = 5500;
int cnt = 0;
double x[maxn], b[maxn];
char aa[100], bb[100];
map<string, int> mp;
vector<int> adj[maxn];
int add[maxn][maxn];
bool ok = false;
int is_ok[maxn];
double X;
bool vis[maxn];
double xx[maxn];
double zi[maxn];
char ss[maxn];

void dfs(int u) {
    vis[u] = true;
    //printf("%d %d xxxx\n", x[1], x[2]);
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (vis[v]) {
            if (x[u] == x[v]) {
                // puts("WOCAONIMA");
                //printf("%d %d x\n", x[u], x[v]);
                X = 1.0 * (add[u][v] - b[u] - b[v]) / (x[u] + x[v]);
                //cout << X << endl;
                ok = true;
            }
        } else {
            x[v] = -x[u];
            b[v] = add[u][v] - b[u];
            dfs(v);
        }
    }
}
        
double mk[maxn];

void dfs2(int u, double m) {
    vis[u] = true;
    mk[u] = x[u] * m + b[u];
    zi[u] = m;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (!vis[v]) {
            dfs2(v, m);
        }
    }
}


int main() {
    int test; cin >> test;
    for (int cas = 1; cas <= test; cas++) {
        int n; cin >> n;
        int c;
        cnt = 0;
        for (int i = 0; i < maxn; i++) {
            for (int j = 0; j < maxn; j++) {
                add[i][j] = inf;
            }
        }
        for (int i = 0; i < maxn; i++) {
            adj[i].clear();
        }
        mp.clear();
        for (int i = 0; i < n; i++) {
            scanf("%s", ss); 
            sscanf(ss, "%[^+]+%[^=]=%d", aa, bb, &c);
            string cc = string(aa);
            string dd = string(bb);
            //cout << cc << " " << dd << " " << c << endl;
            if (!mp[cc])
                mp[cc] = ++cnt;
            if (!mp[dd])
                mp[dd] = ++cnt;
            //cout << mp[cc] << " " << mp[dd] << endl;
            add[mp[cc]][mp[dd]] = c;
            add[mp[dd]][mp[cc]] = c;
            adj[mp[cc]].push_back(mp[dd]);
            adj[mp[dd]].push_back(mp[cc]);
        }
        memset(vis, false, sizeof(vis));
        memset(x, 0, sizeof(x));
        memset(is_ok, 0, sizeof(is_ok));
        memset(b, 0, sizeof(b));
        memset(xx, 0, sizeof(xx));
        for (int i = 0; i < maxn; i++) {
            mk[i] = inf;
            zi[i] = inf;
        }
        
        for (int i = 1; i <= cnt; i++) {
            if (!vis[i]) {
                // printf("%d YYYYY\n", i);
                x[i] = 1.0;
                b[i] = 0.0;
                X = 0.0;
                ok = false;
                dfs(i);
                //puts(ok ? "WTF?" : "HEHE");
                if (ok == true) {
                    // puts("WTF");
                    is_ok[i] = 1;
                    xx[i] = X;
                } else {
                    is_ok[i] = 2;
                }
            }
        }
        //printf("%d is_ok\n", is_ok[1]);
        memset(vis, false, sizeof(vis));
        for (int i = 1; i <= cnt; i++) {
            if (is_ok[i] == 1) {
                //printf("%d\n", i);
                // puts("FUCK");
                dfs2(i, xx[i]);
            }
        }
        // cout << mk[1] << " HEHEHEHEHEHEHHEHEHE" << endl;
        int q; cin >> q;
        for (int i = 0; i < cnt; i++) {
           // printf("%d %d %d\n",xx[i], x[i], b[i]);
        }
        printf("Case #%d:\n", cas);
        for (int i = 0; i < q; i++) {
            scanf("%s", ss);
            sscanf(ss, "%[^+]+%s", aa, bb);
            string cc = string(aa);
            string dd = string(bb);
            if (mp[cc] && mp[dd] && zi[mp[cc]] == zi[mp[dd]]) {
                // cout << aa << " "<< bb << endl;
                if (x[mp[cc]] == -x[mp[dd]]) {
                    printf("%s+%s=%d\n", aa, bb, int(b[mp[cc]] + b[mp[dd]]));
                    continue;
                }
            }
            if (mp[cc] && mp[dd] && add[mp[cc]][mp[dd]] != inf) {
                printf("%s+%s=%d\n", aa, bb, add[mp[cc]][mp[dd]]);
            } else if (mp[cc] && mp[dd] && mk[mp[cc]] != inf && mk[mp[dd]] != inf) {
                printf("%s+%s=%d\n", aa, bb, int(mk[mp[cc]] + mk[mp[dd]]));
            }
        }
    }
}

