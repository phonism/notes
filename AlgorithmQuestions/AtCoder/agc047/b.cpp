#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int child[N][26];
bool is_end[N];
int nxt = 1;

int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    vector<vector<int>> paths(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        reverse(a[i].begin(), a[i].end());
        int node = 0;
        for (char ch : a[i]) {
            paths[i].push_back(node);
            if (child[node][ch - 'a'] == 0) {
                child[node][ch - 'a' ] = nxt++;
            }
            node = child[node][ch - 'a'];
        }
        is_end[node] = true;
    }

    long long ans = 0;

    for (int i = 0; i < n; ++i) {
        set<char> suf;
        for (int j = (int)a[i].length() - 1; j >= 0; --j) {
            suf.insert(a[i][j]);
            int node = paths[i][j];
            for (char ch : suf) {
                ans += is_end[child[node][ch - 'a']];
            }
        }
    }

    cout << ans - n << endl;
}
