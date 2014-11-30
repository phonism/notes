#include <stdio.h>

int main() {
    long long n; scanf("%lld", &n);
    if ((n & n - 1) == 0)
        puts("TAK");
    else
        puts("NIE");
}