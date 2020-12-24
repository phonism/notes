#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int cnt = 0;
    int sum = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = K - i; j <= N; j += K) {
            if (j <= 0) {
                sum += 1;
                continue;
            }
            for (int k = K - j; k <= N; k += K) {
                if (k <= 0) {
                    sum += 1;
                    continue;
                }
                sum += 1;
                if ((i + j) % K == 0 && (j + k) % K == 0 && (i + k) % K == 0) {
                    cnt += 1;
                }
            }
        }
    }
    cout << cnt << endl;
}
