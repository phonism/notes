#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

char str[111];

int main() {
    int n;
    scanf("%d %s", &n, str);
    int len = strlen(str);
    int hash[100], tot = 0;
    memset(hash, 0, sizeof(hash));
    for (int i = 0; i < len; i++) {
        if (hash[str[i]-'a'] == 0) {
            tot += 1;
        }
        hash[str[i]-'a'] = 1;
    }
    if (tot < n) {
        puts("NO");
        return 0;
    }
    memset(hash, 0, sizeof(hash));
    printf("YES");
    for (int i = 0; i < len; i++) {
        if (hash[str[i]-'a'] == 0 && n > 0) {
            puts("");
            n -= 1;
        }
        printf("%c", str[i]);
        hash[str[i]-'a'] = 1;
    }
    puts("");
    return 0;
}
