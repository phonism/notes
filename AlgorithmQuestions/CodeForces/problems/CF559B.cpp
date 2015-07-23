#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

const int maxn = 200200;
char cha[maxn], chb[maxn];

bool isOk(int a1, int a2, int b1, int b2) {
    bool ok = true;
    for (int i = a1; i <= a2; i++) {
        if (cha[i] != chb[i-a1+b1])
            ok = false;
    }
    if (ok == true)
        return ok;
    int len = a2 - a1 + 1;
    if (len % 2 == 1)
        return false;
    if (isOk(a1, a1+len/2-1, b1, b1+len/2-1)) {
        if (isOk(a1+len/2, a2, b1+len/2, b2)) {
            return true;
        }
    }
    if (isOk(a1, a1+len/2-1, b1+len/2, b2)) {
        if (isOk(a1+len/2, a2, b1, b2+len/2-1)) {
            return true;
        }
    }
    return false;
}

int main() {
    scanf("%s %s", cha, chb);
    puts(isOk(0, strlen(cha)-1, 0, strlen(chb)-1) ? "YES" : "NO");
    return 0;
}
