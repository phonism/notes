/*
 * 题目链接：https://codeforces.com/contest/1194/problem/E
 * 题意：给n个垂直或者水平的线段，问所有井字形的4元组有多少个。
 * 题解：预处理每条垂直的线段和哪些有交集，用bitset存储，然后枚举左右垂直的线段l，r，
 *       那么和l和r有交集的水平线段个数为bitset[i] & bitset[j]。这题用树状数组也行，
 *       也是枚举l，r，然后维护个树状数组，扫的过程中扫到每个水平的线段i左端点，
 *       第i位+1，扫到右端点第i位-1。需要提前排好序，一边遍历水平，一边遍历垂直。
 */

nclude <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <vector>
using namespace std;
 
const int N = 5000;
 
vector<int> v, h;
int x1[N], x2[N], _y[N], y2[N];
 
bitset<N> adj[N];
 
bool is_intersect(int i, int j) {
    if (x1[i] != x2[i]) {
        swap(i, j);
    }
    if (x1[i] >= min(x1[j], x2[j]) && x1[i] <= max(x1[j], x2[j])) {
        if (_y[j] >= min(_y[i], y2[i]) && _y[j] <= max(_y[i], y2[i])) {
            return true;
        }
    }
    return false;
}
 
/*
int cache[N][N];
 
int count_one(int i, int j) {
    if (cache[i][j]) {
        return cache[i][j];
    }
    cache[i][j] = (adj[i] & adj[j]).count();
    return cache[i][j];
}
*/
 
int main() {
    int n;
    scanf("%d", &n); 
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d %d", &x1[i], &_y[i], &x2[i], &y2[i]);
        if (x1[i] == x2[i]) {
            v.push_back(i);
        } else {
            h.push_back(i);
        }
    }
 
    if (v.size() > h.size()) {
        swap(v, h);
    }
 
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < h.size(); ++j) {
            if (is_intersect(v[i], h[j])) {
                adj[v[i]][j] = 1;
            }
        }
    }
    
 
    long long sum = 0;
    for (int i = 0; i < v.size(); ++i) {
        int v1 = v[i];
        for (int j = i + 1; j < v.size(); ++j) {
            int v2 = v[j];
            int tmp = (adj[v1] & adj[v2]).count();
            // int tmp = count_one(v1, v2);
            // cout << (adj[v1] & adj[v2]) << endl;
            sum += tmp * (tmp - 1) / 2;
        }
    }
    printf("%lld\n", sum);
    return 0;
}
