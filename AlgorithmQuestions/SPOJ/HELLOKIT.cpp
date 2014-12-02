#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

char ch[11111];

int main() {
    while (scanf("%s", ch) != EOF) {
        if (ch[0] == '.')
            break;
        int n; scanf("%d", &n);
        int len = strlen(ch);
        int len2 = len * n;
        for (int i = 0; i < len; i++) {
            for (int j = i; j < len; j++) {
                putchar(ch[j]);
            }
            for (int j = len - i + 1; j <= len2; j++) {
                putchar(ch[(j-len+i-1) % len]);
            }
            puts("");
        }
    }
    return 0;
}
