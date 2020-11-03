#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <bitset>
#include <vector>
using namespace std;
 
const int N = 5e5 + 10;
int a[N], b[N], c[N], d[N];
int n;
int graph[222][222];                                   //图的大小
                                             //节点数
int visit[222];                                       //是否访问
int matched[222];                                     //是否已经匹配，对应的匹配点
 
int dfs_solve(int x){
    for(int i = 1; i <= n * 2; i++){
        if(graph[x][i] && !visit[i]){
                visit[i] = 1;                         //标记为匹配过
           
            if(matched[i] == -1 || dfs_solve(matched[i]) == 1){
                matched[x] = i;
                matched[i] = x;
        
                return 1;
            }
        }
    }
    return 0;
}
 
 
int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> c[i] >> d[i];
    }
 
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i] < c[j] && b[i] < d[j]) {
                graph[i][n+j] = 1;
                graph[n+j][i] = 1;
            }
        }
    }
 
    memset(matched, -1, sizeof(matched));
    int sum = 0;
    for (int i = 1; i <= 2 * n; ++i) {
        if (matched[i] == -1) {
            memset(visit, 0, sizeof(visit));
            sum += dfs_solve(i);
        }
    }
    cout << sum << endl;
    return 0;
}
