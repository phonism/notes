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

char ch[10000];

bool check(int len) {
    for (int i = 0; i < len; i++) {
        if (ch[i] == 'm')
            return true;
    }
    return false;
}

int main() {
    int test; scanf("%d", &test);
    for (int cas = 1; cas <= test; cas++) {
        vector<int> tmp;
        int pos = 0;
        for (int i = 0; i < 5; i++) {
            scanf("%s", ch);
           // printf("fuck %s\n", ch);
            if (check(strlen(ch))) {
                pos = i;
              //  printf("%d\n", pos);
              //  puts("FUCKFUCKFUCK");
            } else {
                if (ch[0] >= '0' && ch[0] <= '9') {
                    int tem = 0, len = strlen(ch);
                 //   printf("%d\n", len);
                    for (int j = 0; j < len; j++) {
                        if (j > 0)
                            tem *= 10;
                        tem += ch[j] - '0';
                    }
                    tmp.push_back(tem);
                }
            }
        }
      //  printf("%d\n", tmp.size());
      //  printf("%d %d\n", tmp[0], tmp[1]);
        if (pos == 0) {
            printf("%d + %d = %d\n", tmp[1] - tmp[0], tmp[0], tmp[1]);
        }
        if (pos == 2) {
            printf("%d + %d = %d\n", tmp[0], tmp[1] - tmp[0], tmp[1]);
        }
        if (pos == 4) {
            printf("%d + %d = %d\n", tmp[0], tmp[1], tmp[0] + tmp[1]);
        }
    }
}
