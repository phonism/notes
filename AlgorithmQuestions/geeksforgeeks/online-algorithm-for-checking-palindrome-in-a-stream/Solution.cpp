#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MOD = 103;
const int BASE = 256;
const int maxn = 100010;

void checkPalindromes(char str[]) {
    int len = strlen(str);
    printf("%c Yes\n", str[0]);
    if (len == 1)
        return ;
    int first = str[0] % MOD;
    int second = str[1] % MOD;
    int tmp = 1;
    for (int i = 1, j = 0; i < len; i++) {
        if (first == second) {
            for (j = 0; j < i / 2; j++) {
                if (str[j] != str[i-j])
                    break;
            }
            if (j == i / 2) {
                printf("%c Yes\n", str[i]);
            } else {
                printf("%c No\n", str[i]);
            }
        } else {
            printf("%c No\n", str[i]);
        }
        if (i != len - 1) {
            if (i % 2 == 0) {
                tmp = (tmp * BASE) % MOD;
                first = (first + tmp * str[i/2]) % MOD;
                second = (second * BASE + str[i+1]) % MOD;
            } else {
                second = (BASE*(second+MOD-str[(i+1)/2]*tmp)%MOD+str[i+1])%MOD;
            }
        }
    }
}

char ch[maxn];

int main() {
    scanf("%s", ch);
    checkPalindromes(ch);
    return 0;
}
