#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>

const int maxn = 1001000;
char str[maxn], buf[maxn];
int nxt[10100];

void get_next() {
    for (int i = 1, j = 0; str[i]; i++) {
        while (j && str[j] != str[i])
            j = nxt[j-1];
        nxt[i] = j += (str[j] == str[i]);
    }
}

int solve() {
    int cnt = 0;
    for (int i = 0, j = 0; buf[i]; i++) {
        while (j && str[j] != buf[i])
            j = nxt[j-1];
        j += (str[j] == buf[i]);
        if (j == strlen(str))
            cnt++;
    }
    return cnt;
}

int main() {
    int test;
    scanf("%d", &test);
    for (int cas = 1; cas <= test; cas++) {
        scanf("%s %s", str, buf);
        get_next();
        printf("%d\n", solve());
    }
    return 0;
}
