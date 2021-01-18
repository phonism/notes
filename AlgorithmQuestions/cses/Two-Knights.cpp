#include <bits/stdc++.h>
using namespace std;

int main() {

    int k;
    scanf("%d", &k);
    for (int i = 1; i <= k; ++i) {
        long long tmp = (long long) i * i;
        long long ans = tmp * (tmp - 1) / 2;
        long long ans2 = (i - 1) * (i - 2) * 4;
        cout << ans - ans2<< endl;

    }

}
