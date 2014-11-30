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

int main() {
    int n;
    while (~scanf("%d", &n)) {
        if (n == 0)
            break;
        int answer = 0;
        for (int i = 1; i <= n; i++) {
            int l = n + 1 - i;
            answer += l * l;
        }
        printf("%d\n", answer);
    }
}
