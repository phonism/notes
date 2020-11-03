#include <bits/stdc++.h>
using namespace std;

int main() {
    int tests;
    cin >> tests;
    for (int tes = 0; tes < tests; ++ tes) {
        int n;
        cin >> n;
        vector<int> num;
        for (int i = 0; i < n; ++i) {
            num.push_back(n * 2 + 2 * i);
        }
        for (int i = 0; i < num.size(); ++i) {
            if (i == 0) {
                cout << num[i];
            } else {
                cout << " " << num[i];
            }
        }
        cout << endl;
    }
    return 0;
}

