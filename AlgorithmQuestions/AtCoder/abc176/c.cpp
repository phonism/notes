#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
 
const int N = 2e5 + 10;
int a[N];
 
int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
 
    int n;
    cin >> n;
    int pre = 0;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (i == 0) {
            pre = x;
            continue;
        }
        if (x >= pre) {
            pre = x;
        } else {
            sum += pre - x;
        }
    }
    cout << sum << endl;
}
