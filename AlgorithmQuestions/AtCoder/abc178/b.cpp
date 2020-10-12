#include <bits/stdc++.h>
using namespace std;
 
int main() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    long long ans = max(-1000000000000000009LL, a * c);
    ans = max(ans, a * d);
    ans = max(ans, b * c);
    ans = max(ans, b * d);
    cout << ans << endl;
}
