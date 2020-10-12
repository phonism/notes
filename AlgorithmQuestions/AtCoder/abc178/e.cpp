#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> num, num2, num3;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        num.push_back(x + y);
        num2.push_back(y - x);
        num3.push_back(x - y);
    }
    sort(num.begin(), num.end());
    sort(num2.begin(), num2.end());
    sort(num3.begin(), num3.end());
    int ans = max(num[num.size() - 1] - num[0], num2[num.size() - 1] - num2[0]);
    ans = max(ans, num3[num3.size() - 1] - num3[0]);
    cout << ans << endl;
}

