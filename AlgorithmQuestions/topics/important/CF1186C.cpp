#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 10;
 
int main() {
    string a, b;
    cin >> a >> b;
    vector<int> pre(a.length() + 1);
 
    for (int i = 0; i < a.length(); ++i) {
        pre[i + 1] = pre[i] + (a[i] == '1' ? 1 : 0);
    }
 
    int cntb = 0;
    for (int i = 0; i < b.length(); ++i) {
        cntb += (b[i] == '1' ? 1 : 0);
    }
    cntb %= 2;
 
    int ans = 0;
    for (int i = b.length(); i <= a.length(); ++i) {
        if ((pre[i] - pre[i - b.length()]) % 2 == cntb) {
            ans++;
        }
    }
    cout << ans << endl;
}
