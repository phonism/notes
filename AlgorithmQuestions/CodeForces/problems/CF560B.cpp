#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int ca1, ca2, ca3, cb1, cb2, cb3;
    cin >> ca1 >> cb1 >> ca2 >> cb2 >> ca3 >> cb3;
    int a1 = min(ca1, cb1);
    int b1 = max(ca1, cb1);
    int a2 = min(ca2, cb2);
    int b2 = max(ca2, cb2);
    int a3 = min(ca3, cb3);
    int b3 = max(ca3, cb3);
    bool ok = false;
    if (a2 + a3 <= a1 && max(b2, b3) <= b1) 
        ok = true;
    if (a2 + b3 <= a1 && max(b2, a3) <= b1)
        ok = true;
    if (b2 + a3 <= a1 && max(a2, b3) <= b1)
        ok = true;
    if (b2 + b3 <= a1 && max(a2, a3) <= b1)
        ok = true;
    if (b2 + a3 <= b1 && max(a2, b3) <= a1)
        ok = true;
    if (b2 + b3 <= b1 && max(a2, a3) <= a1)
        ok = true;
    if (a2 + a3 <= b1 && max(b2, a3) <= a1)
        ok = true;
    if (a2 + b3 <= b1 && max(b2, a3) <= a1)
        ok = true;
    puts(ok ? "YES" : "NO");
    return 0;
}
    
