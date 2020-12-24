#include <bits/stdc++.h>
using namespace std;

long long m(int x) {
    long long cnt = 1;
    while (x) {
        x /= 10;
        cnt *= 10;
    }
    return cnt;
}

int get(long long x) {
    int sum = 0;
    while (x) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}


int main() {
    long long k;
    cin >> k;
    int ans = 1e9;
    for (int i = 1; i < m(k); ++i) {
        ans = min(ans, get(k * i));
    }
    cout << ans << endl;
    

}
