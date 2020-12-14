#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x, y, id;
    bool operator<(Node a) {
        return x < a.x;
    }
};

int main() {
    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        cin >> n;
        vector<Node> a(2 * n - 1);
        long long x, y;
        for (int i = 0; i < 2 * n - 1; ++i) {
            cin >> a[i].x >> a[i].y;
            a[i].id = i + 1;
        }

        vector<int> ans;
        sort(a.begin(), a.end());
        for (int i = 0; i < 2 * n - 2; i += 2) {
            if (a[i].y > a[i + 1].y) {
                ans.push_back(a[i].id);
            } else {
                ans.push_back(a[i + 1].id);
            }
        }
        puts("YES");
        ans.push_back(a[2 * n - 2].id);
        for (int i = 0; i < ans.size(); ++i) {
            if (i == 0) {
                cout << ans[i];
            } else {
                cout << " " << ans[i];
            }
        }
        cout << endl;
    }
}
