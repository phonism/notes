#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int a[N];
int ans[111][111];

int main() {
    int h, w;
    cin >> h >> w;
    int n;
    cin >> n;
    vector<int> color;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < a[i]; ++j) {
            color.push_back(i + 1);
        }
    }

    int cnt = 0;
    int op = 0;
    for (int i = 0; i < h; ++i) {
        if (op) {
            for (int j = 0; j < w; ++j) {
                ans[i][j] = color[cnt++];
            }
        } else {
            for (int j = w - 1; j >= 0; --j) {
                ans[i][j] = color[cnt++];
            }
        }
        op = 1 - op;
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (j == 0) {
                cout << ans[i][j];
            } else {
                cout << " " << ans[i][j];
            }
        }
        cout << endl;
    }

    return 0;
}
