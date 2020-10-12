#include <cstdio>
#include <iostream>
using namespace std;
 
int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
 
    int n, x, t;
    cin >> n >> x >> t;
    cout << t * ((n - 1) / x + 1) << endl;
}
