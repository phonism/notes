#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<string> ans(n, "");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int op = (i + j) & 1;
            if (op == 0 && k > 0) {
                k -= 1;
                ans[i] += "L";
            } else {
                ans[i] += "S";
            }
        }
    }
    if (k == 0) {
        puts("YES");
        for (int i = 0; i < n; i++)
            puts(ans[i].c_str());
    } else {
        puts("NO");
    }
    return 0;
}
