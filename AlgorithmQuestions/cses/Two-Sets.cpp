#include <bits/stdc++.h>
using namespace std;

vector<int> a, b;

int main() {
    int n;
    scanf("%d", &n);
    long long sum = (long long) n * (n + 1) / 2;
    if (sum % 2 == 0) {
        sum = sum / 2;
        while (n) {
            if (sum >= n) {
                a.push_back(n);
                sum -= n;
            } else {
                b.push_back(n);
            }
            n -= 1;
        }
        puts("YES");
        printf("%d\n", a.size());
        for (int i = 0; i < a.size(); ++i) {
            if (i == 0) {
                printf("%d", a[i]);
            } else {
                printf(" %d", a[i]);
            }
        }
        puts("");
        printf("%d\n", b.size());
        for (int i = 0; i < b.size(); ++i) {
            if (i == 0) {
                printf("%d", b[i]);
            } else {
                printf(" %d", b[i]);
            }
        }
        puts("");
    } else {
        puts("NO");
    }
} 

