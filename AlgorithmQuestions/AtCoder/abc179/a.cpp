#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <bitset>
#include <vector>
using namespace std;
 
const int N = 1e5;
char s[N];
 
int main() {
    scanf("%s", s);
    int len = strlen(s);
    if (s[len - 1] != 's') {
        s[len] = 's';
        s[++len] = '\0';
    } else {
        s[len] = 'e';
        s[++len] = 's';
        s[++len] = '\0';
    }
    printf("%s\n", s);
    return 0;
}
