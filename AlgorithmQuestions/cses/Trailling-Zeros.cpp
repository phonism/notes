#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long tmp = 5;
    long long ans = 0;
    while (tmp <= n) {
        ans += n / tmp;
        tmp *= 5;
    }
    cout << ans << endl;

}
