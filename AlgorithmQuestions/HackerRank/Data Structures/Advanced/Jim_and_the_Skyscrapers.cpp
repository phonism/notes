#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int maxn = 300100;

int N, a[maxn], v[maxn], m[maxn];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    long long answer = 0;
    int size = 0;
    for (int i = 0; i < N; i++) {
        int h = a[i];
        while (size > 0 && v[size-1] < h) {
            size--;
        }
        if (size < 1 || v[size-1] > h) {
            v[size] = h;
            m[size] = 0;
            size++;
        }
        answer += m[size-1];
        m[size-1]++;
    }
    printf("%lld\n", answer << 1);
}
    
