#include <bits/stdc++.h>
using namespace std;

const int N = 111;
int a[N][N];
bool used[N][N];

int main() {
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; ++t) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> a[i][j];
                used[i][j] = false;
            }
        }

        long long cost = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (used[i][j]) continue;
                int oi = n - i + 1;
                int oj = m - j + 1;
                vector<int> ai = {i, i, oi, oi};
                vector<int> aj = {j, oj, oj, j};
                vector<int> tmp;
                for (int o = 0; o < 4; ++o) {
                    int ni = ai[o];
                    int nj = aj[o];
                    if (!used[ni][nj]) {
                        tmp.push_back(a[ni][nj]);
                    }
                    used[ni][nj] = true;
                }
                sort(tmp.begin(), tmp.end());
                for (auto tt : tmp) {
                    cost += abs(tt - tmp[tmp.size() / 2]);
                }
            }
        }
        cout << cost << endl;
    }
    return 0;
}
