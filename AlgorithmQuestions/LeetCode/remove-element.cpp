#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int removeElement(int A[], int n, int elem) {
		int len = 0;
		for (int i = 0; i < n; ) {
			if (A[i] == elem) {
				i++;
			} else {
				A[len] = A[i];
				i++; len++;
			}
		}
		return len;
	}
};

Solution sol;

int main() {
	int A[] = {1, 3, 3, 5, 4, 2, 4, 6};
	int n = 8;
	printf("%d\n", sol.removeElement(A, 8, 3));
}