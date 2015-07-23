#include <cstdio>
#include <iostream>

using namespace std;

int A[7];

int main() {
    for (int i = 1; i <= 6; i++)
        scanf("%d", A + i);

    int res = (A[1] + A[2] + A[3]) * (A[1] + A[2] + A[3]) - A[1] * A[1] - A[3] * A[3] - A[5] * A[5];

    cout << res << endl;
    return 0;
}
